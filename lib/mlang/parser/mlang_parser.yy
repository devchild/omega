%skeleton "glr.cc" /* -*- C++ -*- */
%require "2.6.90.8-d4fe"
%defines
%define parser_class_name {mlang_parser}
%code requires {
# include <string>
# include <vector>
# include <codedom.hh>

class mlang_driver;
}
// The parsing context.
%parse-param { mlang_driver& driver }
%locations
%initial-action 
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = driver.streamname();
};
%debug
%error-verbose
// Symbols.
%union
{
  int          	integerVal;
  float			doubleVal;
  std::string 	*stringVal;
  mlang::CodeObject* node;
  mlang::CodeObjectCollection* node_collection;
};
%code {
# include "mlang_driver.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.scanner()->lex

}
%token        				END      0 					"end of file"
%token						EOL							"end of line"
%token						NEW							"new"
%token						DEF							"def"
%token						LEFT_BRACKET				"["
%token						RIGHT_BRACKET				"]"
%token						END_STATEMENT				"end of statement"
%token						INDENT						"indent"
%token						DEDENT						"dedent"
%token						BLOCK_END   				"end"
%token						IF							"if"
%token						ELSE						"else"
%token						WHILE						"while"
%token						NAMESPACE					"namespace"
%token						CLASS						"class"
%token						STRUCT						"struct"
%token        				ASSIGN     					"="
%token        				TOK_RETURN  	   			"return"
%token						INCLUDE						"include"
%token						IR							"ir"
%token						SIZEOF						"sizeof"
%token						ASM							"asm"
%token						OP_LESS_THAN_OR_EQUAL		"<="
%token						OP_GREATER_THAN_OR_EQUAL	">="
%token						OP_EQUALS					"=="
%token						OP_NOT_EQUALS				"!="
%token						OP_OROR						"||"
%token						OP_ANDAND					"&&"
%token						OP_SHIFT_RIGHT  			">>"
%token						OP_SHIFT_LEFT				"<<"
%token <integerVal>			RANK						"[]"
%token <stringVal>			BLOCKCONTENT 				"block content"
%token <stringVal>			EXTERNAL					"external"
%token <stringVal> 			IDENTIFIER 					"identifier"
%token <integerVal> 		INTEGER    					"integer"
%token <doubleVal> 			DOUBLE    					"double"
%token <stringVal>			STRING_LITERAL 				"string"

%type  <stringVal>			attribute_name
%type  <node>				empty_statement statement_expression  bad_primary_expression bad_statement sizeof_expression
%type  <node> 				unary_expression non_assign_expression method_reference_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression conditional_and_expression conditional_expression primary_expression assembly_call_expression expression_opt object_create_expression field_reference_expression member_field assign_expression non_array_type_reference array_type_reference ir_block_statement type_reference compile_unit compile_unit_member namespace type_declaration method namespace_member class_declaration struct_declaration type_member
%type  <node> 				statement method_return_statement condition_statement expression_statement iteration_statement variable_declaration_statement
%type  <node> 				attribute array_indexer_expression array_create_expression file_include expression binary_operator_expression method_invoke_expression variable_reference_expression primitive_expression cast_expression parameter_declaration_expression
%type  <node_collection>	attribute_arguments_opt attribute_arguments attribute_list attributes_section attributes_sections attributes_opt attributes type_argument_list type_argument_list_opt type_reference_list compile_unit_member_list_opt compile_unit_member_list namespace_member_list_opt namespace_member_list type_member_list_opt type_member_list 
%type  <node_collection>	file_include_list_opt file_include_list expression_list expression_list_opt parameter_declaration_expression_list parameter_declaration_expression_list_opt statement_list

%printer    { yyoutput << *$$; } 		"identifier"
%destructor { delete $$; } 				"identifier"
%printer    { yyoutput << $$; } 		<integerVal>

%%
%start compile_unit;

compile_unit:					{	
									if (driver.root() == nullptr)
									{
										//auto nd = new mlang::CodeCompileUnit();
										//driver.root(nd);
									}
									driver.success(false);
								}
	file_include_list_opt
	compile_unit_member_list_opt
								{
									if ($2 != nullptr)
									{
										for(auto child_nd:*$2)
										{
											auto file_include_nd = static_cast<mlang::CodeFileInclude*>(child_nd);
											auto search_str = file_include_nd->file_name().substr(1, file_include_nd->file_name().size() - 2);
											driver.include(search_str);
										}
									}
								
									if ($3 != nullptr)
									{
										for(auto child_nd:*$3)
										{
											if (child_nd->type_of(mlang::CodeObjectKind::CodeNamespace))
											{
												driver.root()->namespaces()->push_back(static_cast<mlang::CodeNamespace*>(child_nd));
												child_nd->parent(driver.root());
											}
												
											if (child_nd->type_of(mlang::CodeObjectKind::CodeMemberMethod))
											{
												driver.root()->methods()->push_back(static_cast<mlang::CodeMemberMethod*>(child_nd));
												child_nd->parent(driver.root());
											}
											
											if (child_nd->type_of(mlang::CodeObjectKind::CodeTypeDeclaration))
											{
												driver.root()->types()->push_back(static_cast<mlang::CodeTypeDeclaration*>(child_nd));
												child_nd->parent(driver.root());
											}
										}
									}
									$$ = driver.root();
									driver.success(true);
								}
	;
	
file_include_list_opt:
	%empty						{	$$ = nullptr;	}
	| file_include_list			{	$$ = $1;		}
	;

file_include_list:
	file_include
								{	
									auto nd = new mlang::CodeObjectCollection();
									nd->push_back($1);
									$$ = nd;
								}
	| file_include_list file_include
								{
									auto nd = $1;
									nd->push_back($2);
									$$ = nd;
								}
	;

file_include:
	INCLUDE STRING_LITERAL 		
											{	
												auto nd = new mlang::CodeFileInclude();
												nd->file_name(*$2);
												$$ = nd;
											}
	;
	
compile_unit_member_list_opt:
	%empty									{	$$ = nullptr; }
	| compile_unit_member_list  			{	$$ = $1; }
	;

compile_unit_member_list:
	compile_unit_member						{	
												$$ = new mlang::CodeObjectCollection();
												if ($1 != nullptr)
													$$->push_back($1);
											}
	| compile_unit_member_list compile_unit_member
											{	
												$$ = $1;
												if ($2 != nullptr)
													$$->push_back($2);
											}
	;

compile_unit_member:
	namespace								{	$$ = $1; }
	| attributes_opt type_declaration		{	
												$$ = $2; 
											}
	| attributes_opt method					{
												auto method = static_cast<mlang::CodeMemberMethod*>($2);
												if ($1 != nullptr)
												{
													for(auto x:*$1)
													{
														method->custom_attributes().push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												$$ = method;
											}
	;

namespace:
	NAMESPACE IDENTIFIER INDENT namespace_member_list DEDENT
											{
												auto nd = new mlang::CodeNamespace();
												nd->name(*$2);
												if ($4 != nullptr)
												{
													for(auto child_nd:*$4)
													{
														if (child_nd->type_of(mlang::CodeObjectKind::CodeTypeDeclaration))
														{
															nd->types()->push_back(static_cast<mlang::CodeTypeDeclaration*>(child_nd));
															child_nd->parent(nd);
														}
														
														if (child_nd->type_of(mlang::CodeObjectKind::CodeMemberMethod))
														{
															nd->methods()->push_back(static_cast<mlang::CodeMemberMethod*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												$$ = nd;
											}
	;

namespace_member_list:
	namespace_member						{	
												$$ = new mlang::CodeObjectCollection();
												$$->push_back($1);	
											}
	| namespace_member_list namespace_member
											{	
												$$ = $1;
												$$->push_back($2);
											}
	;
	
namespace_member:
	namespace								{	$$ = $1;	}
	| attributes_opt type_declaration		{	$$ = $2;	}
	| attributes_opt method					{	$$ = $2;	}
	;

type_declaration:
	class_declaration						{	$$ = $1;	}
	| struct_declaration					{	$$ = $1;	}
	;

class_declaration:
	CLASS IDENTIFIER ':' INDENT type_member_list DEDENT
											{
												auto nd = new mlang::CodeTypeDeclaration();
												nd->location(driver.get_location(@2));
												
												nd->is_class(true);
												nd->name(*$2);
												if ($5 != nullptr)
												{
													for(auto child_nd:*$5)
													{
														if (child_nd != nullptr)
														{
															nd->members()->push_back(static_cast<mlang::CodeTypeMember*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												$$ = nd;
											}
	;

struct_declaration:
	STRUCT IDENTIFIER ':' INDENT type_member_list DEDENT
											{
												auto nd = new mlang::CodeTypeDeclaration();
												nd->is_struct(true);
												nd->name(*$2);
												if ($5 != nullptr)
												{
													for(auto child_nd:*$5)
													{
														if (child_nd != nullptr)
														{
															nd->members()->push_back(static_cast<mlang::CodeTypeMember*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												$$ = nd;
											}
	;

type_member_list:
	type_member								{	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back($1);
												$$ = nd;
											}
	| type_member_list type_member			
											{	
												auto nd = $1;	
												nd->push_back($2);
												$$ = nd;
											}
	;
	
type_member:
	attributes_opt method									
											{
												auto method = static_cast<mlang::CodeMemberMethod*>($2);
												if ($1 != nullptr)
												{
													for(auto x:*$1)
													{
														method->custom_attributes().push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												$$ = method;
											}
	| attributes_opt member_field			{
												// this generates 1 conflict
												auto field = static_cast<mlang::CodeMemberMethod*>($2);
												if ($1 != nullptr)
												{
													for(auto x:*$1)
													{
														field->custom_attributes().push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												$$ = field;
											}
	;
	
statement_list:
	statement								{	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back($1);
												$$ = nd;
											}
	| statement_list statement				{	
												auto nd = $1;	
												if ($2 != nullptr)
												{
													nd->push_back($2);
												}
												$$ = nd;
											}
	;

statement:
	expression_statement					{	$$ = $1;	}
	| condition_statement					{	$$ = $1;	}
	| iteration_statement					{	$$ = $1;	}
	| ir_block_statement					{	$$ = $1;	}
	| variable_declaration_statement		{	$$ = $1;	}
	| method_return_statement				{	
												// this one causes 6 shift/reduce conflicts.
												// adding an extra term could help eg. ';'
												$$ = $1;	
											}
	| error									{	$$ = nullptr; }
	;

ir_block_statement:
	IR ':' INDENT							{	
												driver.scanner()->begin_block();	
											}
	BLOCKCONTENT							{	
												driver.scanner()->end_block();
											}
	DEDENT  								{
												auto nd = new mlang::CodeIrBlockStatement();
												nd->content(*$5);
												$$ = nd;
											}
	;
	
assembly_call_expression:
	ASM '(' type_reference ',' expression_list ')'				
											{
												auto nd = new mlang::CodeAssemblyCallExpression();
												if ($3 != nullptr)
													nd->return_type(static_cast<mlang::CodeTypeReference*>($3));
												
												if ($5 != nullptr)
												{
													int i = 0;
													for(auto child_nd:*$5)
													{
														if (child_nd != nullptr)
														{ 
															if (i == 0)
															{
																if (!child_nd->type_of(mlang::CodeObjectKind::CodePrimitiveExpression))
																	yyerror(&yylloc, yyparser, driver, "string literal expected");
																auto stringliteral = static_cast<mlang::CodePrimitiveExpression*>(child_nd);
																if (stringliteral->type()->base_type() != "Array")
																	yyerror(&yylloc,yyparser, driver, "string literal expected");
																		
																nd->content(stringliteral->value_as_string());
															}
															else if (i == 1)
															{
																if (!child_nd->type_of(mlang::CodeObjectKind::CodePrimitiveExpression))
																	yyerror(&yylloc,yyparser, driver, "string literal expected");
																auto stringliteral = static_cast<mlang::CodePrimitiveExpression*>(child_nd);
																if (stringliteral->type()->base_type() != "Array")
																	yyerror(&yylloc,yyparser, driver, "string literal expected");
																		
																nd->constraints(stringliteral->value_as_string());
															}
															else
															{
																nd->parameters()->push_back(static_cast<mlang::CodeExpression*>(child_nd));
																child_nd->parent(nd);
															}
														}
														i++;
													}
												}
												
												
												$$ = nd;
											}
	;

iteration_statement:
	WHILE '(' expression ')' ':' INDENT statement_list DEDENT
											{
												auto nd = new mlang::CodeIterationStatement();
												nd->test_expression(static_cast<mlang::CodeExpression*>($3));
												
												if ($7 != nullptr)
												{
													for(auto child_nd:*$7)
													{
														if (child_nd != nullptr)
														{
															nd->statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												$$ = nd;
											}
	;
	

expression_statement:
	statement_expression 					{
												$$ = $1;
											}
	;

statement_expression:
	method_invoke_expression 				{
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>($1));
												nd->expression()->parent(nd);
												$$ = nd;
											}
	| object_create_expression				{
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>($1));
												nd->expression()->parent(nd);
												$$ = nd;
											}
	| array_create_expression				{
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>($1));
												nd->expression()->parent(nd);
												$$ = nd;
											}
	| assign_expression						{
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>($1));
												nd->expression()->parent(nd);
												$$ = nd;
											}
	;
	
condition_statement:
	IF '(' binary_operator_expression ')' ':' INDENT statement_list DEDENT
											{
												auto nd = new mlang::CodeConditionStatement();
												nd->condition(static_cast<mlang::CodeExpression*>($3));
												
												if ($7 != nullptr)
												{
													for(auto child_nd:*$7)
													{
														if (child_nd != nullptr)
														{
															nd->true_statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												$$ = nd;
											}
	| IF '(' binary_operator_expression ')' ':' INDENT statement_list DEDENT ELSE ':' INDENT statement_list DEDENT
											{
												auto nd = new mlang::CodeConditionStatement();
												nd->condition(static_cast<mlang::CodeExpression*>($3));
												if ($7 != nullptr)
												{
													for(auto child_nd:*$7)
													{
														if (child_nd != nullptr)
														{
															nd->true_statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												if ($12 != nullptr)
												{
													for(auto child_nd:*$12)
													{
														if (child_nd != nullptr)
														{
															nd->false_statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												$$ = nd;
											}
	;

variable_declaration_statement:
	type_reference IDENTIFIER 				{
												auto nd = new mlang::CodeVariableDeclarationStatement();
												nd->type(static_cast<mlang::CodeTypeReference*>($1));
												nd->name(*$2);
												nd->init_expression(nullptr);
												$$ = nd;
											}
	| type_reference IDENTIFIER '=' expression 
											{
												auto nd = new mlang::CodeVariableDeclarationStatement();
												nd->type(static_cast<mlang::CodeTypeReference*>($1));
												nd->name(*$2);
												nd->init_expression(static_cast<mlang::CodeExpression*>($4));
												nd->init_expression()->parent(nd);
												$$ = nd;
											}
	;
	
expression_opt:
	%empty									{	$$ = nullptr;	}
	| expression							{
												$$ = $1;
											}
	;

method_return_statement:
	TOK_RETURN 	expression_opt 
											{	
												// this generates 7 conflicts
												auto nd = new mlang::CodeMethodReturnStatement();
												if ($2 != nullptr)
												{
													nd->expression(static_cast<mlang::CodeExpression*>($2));
													nd->expression()->parent(nd);
												}
												$$ = nd;
											}		
	;

parameter_declaration_expression:
	type_reference IDENTIFIER				{
												auto nd = new mlang::CodeParameterDeclarationExpression();
												nd->type(static_cast<mlang::CodeTypeReference*>($1));
												nd->name(*$2);
												$$ = nd;
											}
	;
	
parameter_declaration_expression_list:
	parameter_declaration_expression		{	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back($1);
												$$ = nd;
											}
	| parameter_declaration_expression_list ',' parameter_declaration_expression
											{	
												auto nd = $1;	
												nd->push_back($3);
												$$ = nd;
											}
	;

parameter_declaration_expression_list_opt:
	%empty									{	$$ = nullptr;}
	| parameter_declaration_expression_list	{	$$ = $1;	}
	;
	
expression:
	non_assign_expression					{	$$ = $1;	}
	| assign_expression						{	$$ = $1;	}
	;
											
assign_expression:
	variable_reference_expression '=' expression
							 				{	
												auto nd = new mlang::CodeAssignExpression();
												nd->left(static_cast<mlang::CodeExpression*>($1));
												nd->right(static_cast<mlang::CodeExpression*>($3));
												$$ = nd;
											}
	| field_reference_expression '=' expression
							 				{	
												auto nd = new mlang::CodeAssignExpression();
												nd->left(static_cast<mlang::CodeExpression*>($1));
												nd->right(static_cast<mlang::CodeExpression*>($3));
												$$ = nd;
											}
	| array_indexer_expression '=' expression
							 				{	
												auto nd = new mlang::CodeAssignExpression();
												nd->left(static_cast<mlang::CodeExpression*>($1));
												nd->right(static_cast<mlang::CodeExpression*>($3));
												$$ = nd;
											}
	;

non_assign_expression:
	conditional_expression					{	$$ = $1;	}
	;
	
unary_expression:
	primary_expression						{	$$ = $1;	}
	| '+' unary_expression					{	$$ = $2;	}
	| '-' unary_expression					{	
												auto nd = new mlang::CodeBinaryOperatorExpression();
												auto m_left = new mlang::CodePrimitiveExpression();
												m_left->value(new int(1));
												nd->left(m_left);
												nd->operator_(mlang::CodeBinaryOperatorType::Multiply);
												nd->right(static_cast<mlang::CodeExpression*>($2));
												$$ = nd;
											}
	| '!' unary_expression					{	$$ = $2;	}
	| '~' unary_expression					{	$$ = $2;	}
	| cast_expression						{	$$ = $1;	}
	;

primary_expression:
    primitive_expression					{	$$ = $1;	}
    | field_reference_expression			{	$$ = $1;	}
    | method_invoke_expression				{	$$ = $1;	}
	| variable_reference_expression			{	$$ = $1;	}
	| array_indexer_expression				{	$$ = $1;	}
	| object_create_expression				{	$$ = $1;	}
	| assembly_call_expression				{	$$ = $1;	}
    | array_create_expression				{	$$ = $1;	}
    | sizeof_expression						{	$$ = $1;	}
    ;

sizeof_expression:
	SIZEOF '(' type_reference ')'			{
												auto nd = new mlang::CodeSizeOfExpression();
												nd->type(static_cast<mlang::CodeTypeReference*>($3));
												$$ = nd;
											}
	;
	
field_reference_expression:
	primary_expression '.' IDENTIFIER 
											{	
												auto nd = new mlang::CodeFieldReferenceExpression();
												nd->target_object(static_cast<mlang::CodeExpression*>($1));
												nd->field_name(*$3);
												$$ = nd;
											}
	;

array_indexer_expression:
	primary_expression LEFT_BRACKET expression_list RIGHT_BRACKET	
											{
												auto nd = new mlang::CodeArrayIndexerExpression();
												nd->target_object(static_cast<mlang::CodeExpression*>($1));
												
												for(auto child_nd:*$3)
												{
													if (child_nd != nullptr)
													{
														nd->indices()->push_back(static_cast<mlang::CodeExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												
												$$ = nd;
											}
	;

cast_expression:
	'(' type_reference ')' unary_expression	
											{
												 auto nd = new mlang::CodeCastExpression();
												 nd->target_type(static_cast<mlang::CodeTypeReference*>($2));
												 nd->expression(static_cast<mlang::CodeExpression*>($4));
												 $$ = nd;
											}
	;
		
multiplicative_expression:
	unary_expression						{	$$ = $1;	}
  	| multiplicative_expression '*' unary_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::Multiply);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	| multiplicative_expression '/' unary_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::Divide);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	| multiplicative_expression '%' unary_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::Modulus);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;
		
additive_expression: 
	multiplicative_expression				{	$$ = $1;	}
  	| additive_expression '+' multiplicative_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::Add);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	| additive_expression '-' multiplicative_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::Subtract);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;
  	
shift_expression: 
 	additive_expression 					{	$$ = $1;	}
  	| shift_expression OP_SHIFT_LEFT additive_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::ShiftLeft);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	| shift_expression OP_SHIFT_RIGHT additive_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::ShiftRight);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;

relational_expression: 
	shift_expression						{	$$ = $1;	}
  	| relational_expression '<' shift_expression
  											{	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
  												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
  												nd->operator_(mlang::CodeBinaryOperatorType::LessThan);
  												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
  												$$ = nd;	
  											}
  	| relational_expression '>' shift_expression
  											{	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
  												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
  												nd->operator_(mlang::CodeBinaryOperatorType::GreaterThan);
  												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
  												$$ = nd;	
  											}
  	| relational_expression OP_LESS_THAN_OR_EQUAL shift_expression
  											{	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
  												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
  												nd->operator_(mlang::CodeBinaryOperatorType::LessThanOrEqual);
  												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
  												$$ = nd;	
  											}
  	| relational_expression OP_GREATER_THAN_OR_EQUAL shift_expression
  											{	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
  												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
  												nd->operator_(mlang::CodeBinaryOperatorType::GreaterThanOrEqual);
  												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
  												$$ = nd;	
  											}
  	;

equality_expression: 
	relational_expression					{	$$ = $1;	}
  	| equality_expression OP_EQUALS relational_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::IdentityEquality);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	| equality_expression OP_NOT_EQUALS relational_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::IdentityInEquality);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;
  	
and_expression: 
	equality_expression						{	$$ = $1;	}
  	| and_expression '&' equality_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::BitwiseAnd);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;
  
exclusive_or_expression:
	and_expression							{	$$ = $1;	}
  	| exclusive_or_expression '^' and_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::Add);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;	
		
inclusive_or_expression: 
	exclusive_or_expression					{	$$ = $1;	}
  	| inclusive_or_expression '|' exclusive_or_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::BitwiseOr);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;

conditional_and_expression: 
	inclusive_or_expression					{	$$ = $1;	}
  	| conditional_and_expression OP_ANDAND inclusive_or_expression
  	  										{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												
   												nd->left()->parent(nd);
   												nd->operator_(mlang::CodeBinaryOperatorType::BooleanAnd);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;
		
binary_operator_expression:
	conditional_and_expression				{	$$ = $1;	}
  	| binary_operator_expression OP_OROR conditional_and_expression
  											{
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->location(driver.get_location(@2));
   												nd->left(static_cast<mlang::CodeExpression*>($1));
   												nd->left()->parent(nd);
   												
   												nd->operator_(mlang::CodeBinaryOperatorType::BooleanOr);
   												nd->right(static_cast<mlang::CodeExpression*>($3));
   												nd->right()->parent(nd);
   												$$ = nd;
   											}
  	;
  	
conditional_expression: 
	binary_operator_expression				{	$$ = $1;	}
  	| binary_operator_expression '?' expression ':' expression
  											{
  												$$ = nullptr;
  											}
  	;

primitive_expression:
	INTEGER									{	
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												tp->base_type("Int32");
												
												nd->type(tp);
												nd->value((void*)(uint64_t*)$1);
												$$ = nd;
											}
	| DOUBLE								{	
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												tp->base_type("Double");
												
												nd->type(tp);
												nd->value(const_cast<float*>(&$1));
												$$ = nd;
											}
	| STRING_LITERAL						{
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												
												auto array_element_type = new mlang::CodeTypeReference();
												array_element_type->base_type("Char");
												tp->base_type("Array");
												tp->array_rank(1);
												tp->array_element_type(array_element_type);
												
												
												nd->value($1);
												nd->type(tp);
												$$ = nd;
											}
	;

array_create_expression:
	NEW non_array_type_reference LEFT_BRACKET expression RIGHT_BRACKET
											{
												auto nd = new mlang::CodeArrayCreateExpression();
												
												auto create_type = new mlang::CodeTypeReference();
												create_type->array_element_type(static_cast<mlang::CodeTypeReference*>($2));
												create_type->array_rank(1);
												create_type->base_type("Array");
												
												nd->create_type(create_type);
												nd->size_expression(static_cast<mlang::CodeExpression*>($4));
												$$ = nd;
											}
	;

object_create_expression:
	NEW non_array_type_reference '(' expression_list_opt ')'
											{
												auto nd = new mlang::CodeObjectCreateExpression();
												
												auto create_type = static_cast<mlang::CodeTypeReference*>($2);
												nd->create_type(create_type);
												
												if ($4 != nullptr)
												{
													for (auto child_nd:*$4)
													{
														nd->parameters()->push_back(static_cast<mlang::CodeExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												
												$$ = nd;
											}
	;
	
type_reference:
	non_array_type_reference				{	$$ = $1;	}
	| array_type_reference					{	$$ = $1;	}
	;
	
non_array_type_reference:
	IDENTIFIER								{	
												auto nd = new mlang::CodeTypeReference();
												nd->location(driver.get_location(@1));
												nd->base_type(*$1);
												$$ = nd;
											}
	;

array_type_reference:
	non_array_type_reference RANK
											{	
												auto nd = new mlang::CodeTypeReference();
												nd->location(driver.get_location(@1, @2));
												auto array_element_type = static_cast<mlang::CodeTypeReference*>($1);
												nd->array_element_type(array_element_type);
												nd->array_rank($2);
												nd->base_type("Array");
												$$ = nd;
											}
	;

variable_reference_expression:
	IDENTIFIER
											{	
												auto nd = new mlang::CodeVariableReferenceExpression();
												nd->location(driver.get_location(@1));
												nd->variable_name(*$1);
												$$ = nd;
											}
	;

method:
	EXTERNAL type_reference IDENTIFIER '(' parameter_declaration_expression_list_opt ')'
											{
												auto nd = new mlang::CodeMemberMethod();
												nd->return_type(static_cast<mlang::CodeTypeReference*>($2));
												nd->name(*$3);
												if ($5 != nullptr)
												{
													for (auto child_nd:*$5)
													{
														nd->parameters()->push_back(static_cast<mlang::CodeParameterDeclarationExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												nd->attributes(mlang::MemberAttributes::External);
												$$ = nd;
											}
	| type_reference IDENTIFIER '(' parameter_declaration_expression_list_opt ')' ':'  INDENT statement_list DEDENT
											{
												auto nd = new mlang::CodeMemberMethod();
												nd->return_type(static_cast<mlang::CodeTypeReference*>($1));
												nd->name(*$2);
												if ($4 != nullptr)
												{
													for (auto child_nd:*$4)
													{
														nd->parameters()->push_back(static_cast<mlang::CodeParameterDeclarationExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												
												if ($8 != nullptr)
												{
													for (auto child_nd:*$8)
													{
														if (child_nd != nullptr)
														{
															nd->statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												$$ = nd;
											}
	| DEF IDENTIFIER '(' parameter_declaration_expression_list_opt ')' ':'  INDENT statement_list DEDENT
											{
												auto nd = new mlang::CodeMemberMethod();
												nd->return_type(nullptr);
												nd->name(*$2);
												if ($4 != nullptr)
												{
													for (auto child_nd:*$4)
													{
														nd->parameters()->push_back(static_cast<mlang::CodeParameterDeclarationExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												
												if ($8 != nullptr)
												{
													for (auto child_nd:*$8)
													{
														if (child_nd != nullptr)
														{
															nd->statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												$$ = nd;
											}
	;

member_field:
	type_reference IDENTIFIER				{	
												auto nd = new mlang::CodeMemberField();
												nd->location(driver.get_location(@2));
												nd->type(static_cast<mlang::CodeTypeReference*>($1));
												nd->name(*$2);
												$$ = nd;
											}
	| type_reference IDENTIFIER '=' expression
											{	
												auto nd = new mlang::CodeMemberField();
												nd->location(driver.get_location(@2));
												nd->type(static_cast<mlang::CodeTypeReference*>($1));
												nd->name(*$2);
												nd->init_expression(static_cast<mlang::CodeExpression*>($4));
												$$ = nd;
											}
	;
	
method_invoke_expression:
	method_reference_expression '(' expression_list_opt ')'
											{	
												auto nd = new mlang::CodeMethodInvokeExpression();
												nd->location(driver.get_location(@1));
												
												mlang::CodeMethodReferenceExpression* method_reference_expression = nullptr;
												if ($1->type_of(mlang::CodeObjectKind::CodeMethodReferenceExpression))
												{
													method_reference_expression = static_cast<mlang::CodeMethodReferenceExpression*>($1);
												}
												nd->method(method_reference_expression);
												method_reference_expression->parent(nd);
												
												if ($3 != nullptr)
												{
													for (auto child_nd:*$3)
													{
														nd->parameters()->push_back(static_cast<mlang::CodeExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												$$ = nd;
											}
	;

method_reference_expression:
	IDENTIFIER								{	
												auto nd = new mlang::CodeMethodReferenceExpression();
												nd->method_name(*$1);
												nd->location(driver.get_location(@1));
												$$ = nd;
											}
	| primary_expression '.' IDENTIFIER		{	
												auto nd = new mlang::CodeMethodReferenceExpression();
												nd->method_name(*$3);
												nd->target_object(static_cast<mlang::CodeExpression*>($1));
												nd->location(driver.get_location(@1));
												$$ = nd;
											}
	;

type_argument_list_opt:
	%empty									{
												$$ = nullptr;
											}
	| type_argument_list					{
												$$ = $1;
											}
	;

type_argument_list:
	'<' type_reference_list '>'				{
												$$ = $2;
											}
	;

type_reference_list:
	type_reference							{	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back($1);
												$$ = nd;
											}
	| type_reference_list ',' type_reference
											{	
												auto nd = $1;	
												nd->push_back($3);
												$$ = nd;
											}
	;
	
expression_list_opt:
	%empty									{	$$ = nullptr;	}
	| expression_list						{	$$ = $1;		}
	;

expression_list:
	expression								{	
												auto nd = new mlang::CodeObjectCollection();
												nd->push_back($1);
												$$ = nd;
											}
	| expression_list ',' expression		{	
												auto nd = $1;	
												nd->push_back($3);
												$$ = nd;
											}
	;
   	
attributes_opt:
	%empty									{	$$ = nullptr;	}
	| attributes							{	$$ = $1;		}
	;
	
attributes:
	attributes_sections						{	$$ = $1;		}
	;

attributes_sections:
	attributes_section						{
												auto nd = new mlang::CodeObjectCollection();
												if ($1 != nullptr)
												{
													for(auto x:*$1)
													{
														nd->push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												$$ = nd;
											}
	| attributes_sections attributes_section
											{
												auto nd = $1;
												if ($2 != nullptr)
												{
													for(auto x:*$2)
													{
														nd->push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												$$ = nd;
											}
	;

attributes_section:
	LEFT_BRACKET attribute_list RIGHT_BRACKET
											{
												$$ = $2;
											}
	;
	
attribute_list:
	attribute								{
												auto nd = new mlang::CodeObjectCollection();
												nd->push_back(static_cast<mlang::CodeAttributeDeclaration*>($1));
												$$ = nd;
											}
	| attribute_list ',' attribute			{
												$1->push_back(static_cast<mlang::CodeAttributeDeclaration*>($3));
												$$ = $1;
											}
	;

attribute:
	attribute_name attribute_arguments_opt	{
												auto nd = new mlang::CodeAttributeDeclaration();
												nd->name(*$1);
												if ($2 != nullptr)
												{
													for(auto x:*$2)
													{
														nd->arguments().push_back(static_cast<mlang::CodeAttributeArgument*>(x));
													}
												}
												$$ = nd;
											}
	;

attribute_arguments_opt:
	%empty									{	$$ = nullptr;	}
	| attribute_arguments					{
												$$ = $1;
											}
	;
	
attribute_name:
	IDENTIFIER								{
												$$ = $1;
											}
	;

attribute_arguments: 
	'(' expression_list ')'					{
												
												if ($2 != nullptr)
												{
													auto ret = new mlang::CodeObjectCollection();
													for(auto x:*$2)
													{
														mlang::CodeAttributeArgument* item = new mlang::CodeAttributeArgument();
														item->value(static_cast<mlang::CodeExpression*>(x));
														ret->push_back(item);
													}
													$$ = ret;
												}
												else
												{
													$$ = nullptr;
												}
											}
  	;
	
%%

void
yy::mlang_parser::error (const yy::mlang_parser::location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}