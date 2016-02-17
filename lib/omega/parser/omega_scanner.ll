%{ /* -*- C++ -*- */
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <iomanip>
# include <string>
# include "omega_scanner.hh"
# include "omega_parser.hh"


//
// This should be removed when this is fixed in flex
//
#if __cplusplus > 199711L
#define register      // Deprecated in C++11.
#endif  // #if __cplusplus > 199711L

/* By default yylex returns int, we use token_type.
   Unfortunately yyterminate by default returns 0, which is
   not of token_type.  */ 
#define yyterminate() return token::END

// Flex expects the signature of yylex to be defined in the macro YY_DECL, and
// the C++ parser expects it to be declared. We can factor both as follows.
#ifndef YY_DECL

#define	YY_DECL									\
    yy::omega_parser::token_type				\
    yy::Scanner::lex(							\
	yy::omega_parser::semantic_type* yylval,	\
	yy::omega_parser::location_type* yylloc		\
    )
#endif

%}

%x INDENTSTATE BLOCK

%option prefix="MLang"
%option stack noyywrap nounput batch debug c++

hex_digit              				[0-9A-Fa-f]

uni_esc_seq1        			   	\\u{hex_digit}{4}
uni_esc_seq2           				\\U{hex_digit}{8}
uni_esc_seq            				{uni_esc_seq1}|{uni_esc_seq2}

simple_esc_seq         				\\[\'\"\\0abfnrtv]
hex_esc_seq            				\\x{hex_digit}{1,4}

single_string_char     				[^\\\"]
reg_string_char        				{single_string_char}|{simple_esc_seq}|{hex_esc_seq}|{uni_esc_seq}
regular_string         				\"{reg_string_char}*\"
single_verbatim_char   				[^\"]
quote_esc_seq          				\"\"
verb_string_char       				{single_verbatim_char}|{quote_esc_seq}
verbatim_string        				@\"{verb_string_char}*\"
string_literal         				{regular_string}|{verbatim_string}

%{
# define YY_USER_ACTION  yylloc->columns (yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
  	yylloc->step ();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/
%{
  typedef yy::omega_parser::token token;
  typedef yy::omega_parser::token_type token_type;
%}

{string_literal} {
	//auto res = new std::string(yytext, yyleng);
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::STRING_LITERAL;
}

"==" {
	return token::OP_EQUALS;
}

"!=" {
	return token::OP_NOT_EQUALS;
}

[0-9]+ {
    yylval->integerVal = atoi(yytext);
    return token::INTEGER;
}

[0-9]*"."[0-9]+ 					{
									    yylval->doubleVal = atof(yytext);
									    return token::DOUBLE;
									}
[A-Za-z_][A-Za-z0-9_]* 				{
									    yylval->stringVal = new std::string(yytext, yyleng);
									    std::string s = *yylval->stringVal;
									    return token_for(s);
									}
">"          						{
                                        std::stack<char> mybuffer;
										int c;
										do {
										    c = yyinput();
										    mybuffer.push(c);
										}
										while (c == ' ');

										if (c == '(') {
											while (!mybuffer.empty()) {
                                                 unput(mybuffer.top());
                                                 mybuffer.pop();
                                            }
											return(token::END_GENERIC);
										}
										else {
							    			while (!mybuffer.empty()) {
                                                unput(mybuffer.top());
                                                mybuffer.pop();
                                            }
											return static_cast<token_type>(*yytext);
										}
                                    }
"<"									{
										std::stack<char> mybuffer;
										int c;
										for (;;) {
											c = yyinput();
											mybuffer.push(c);

											if (c == '>') {
												do {
    											    c = yyinput();
    											    mybuffer.push(c);
    											}
    											while (c == ' ');

												if (c == '(') {
													while (!mybuffer.empty())
                                                    {
                                                         unput(mybuffer.top());
                                                         mybuffer.pop();
                                                    }
													return(token::BEGIN_GENERIC);
												}
											}

											if (c == ')' || c == EOF) {
							    				while (!mybuffer.empty())
                                                {
                                                    unput(mybuffer.top());
                                                    mybuffer.pop();
                                                }
												return static_cast<token_type>(*yytext);
											}
										}
									}
\[\] 								{
										yylval->integerVal = 1;
										return token::RANK;
									}
"[" 								{
										return token::LEFT_BRACKET;
									}
"]" 								{
										return token::RIGHT_BRACKET;
									}

<INITIAL>[ \t\r]+ 					{
										/* gobble up white-spaces */
    									yylloc->step();
									}
<INITIAL>\n                			{
										yyless(0);
										yylloc->columns(-1);
                                        BEGIN(INDENTSTATE);
                                       	// return (token::EOL);
                                    }

<INITIAL><<EOF>>           			{
										if (indent.size() > 0)
                                        {
                                            indent.pop();
                                            unput(0);
                                            return(token::DEDENT);
                                            
                                        }
                                        else
                                        {
                                        	yyterminate();
                                        }
                                    }
<INITIAL>. 							{
										/* pass all other characters up to bison */
									    return static_cast<token_type>(*yytext);
									}
<INDENTSTATE>[ ]+ 					{
										current_line_indent+=yyleng;
									}
<INDENTSTATE>\n 					{
										yylloc->lines(yyleng); 
										yylloc->step();
										current_line_indent = 0;
										
									}
<INDENTSTATE><<EOF>>       			{
										if (indent.size() > 0)
                                        {
                                            indent.pop();
                                            unput(0);
                                            return(token::DEDENT);
                                            
                                        }
                                        else
                                        {
                                        	yyterminate();
                                        }
                                    }
<INDENTSTATE>.                      {
										yyless(0);
										yylloc->columns(-1);
                                        int current_indent = current_line_indent;
                                        int previous_indent = indent.size() > 0 ? indent.top() : 0;

                                        if (current_indent > previous_indent) {
                                        	indent.push(current_line_indent);
	                                        return(token::INDENT);
                                        }

                                        if (current_indent < previous_indent) {
                                        	indent.pop();
	                                        return (token::DEDENT);
                                        }

                                        BEGIN(INITIAL);
                                    }
<BLOCK>[ ]+ 						{
										current_line_indent+=yyleng;
									    yylloc->step();
									    m_block_content.append(std::string(yytext, yyleng));	
									}
<BLOCK>[\t\r]+ 						{
									    yylloc->step();
									    m_block_content.append(std::string(yytext, yyleng));	
									}
<BLOCK>\n 							{
										current_line_indent = 0;
									    yylloc->lines(yyleng); 
									    yylloc->step();
									    m_block_content.append(std::string(yytext, yyleng));	
									}
<BLOCK><<EOF>>       				{
                                        unput(0);
                                        return token::BLOCKCONTENT;
                                    }
<BLOCK>. 							{
										/*
										If a dedent was detected we consider this blockcontent complete
										push back the last char and return the content token.
										*/
                                        int current_indent = current_line_indent;
                                        int previous_indent = indent.size() > 0 ? indent.top() : 0;
                                        
                                        if (current_indent < previous_indent) 
                                        {
                                        	/*
											You can use yyless(x) to subtract one or more characters from yytext and push those 
											characters back onto the input stream. Counterintuitively, the argument to yyless is
											the number of characters from yytext that you wish to keep, and the remainder will
											be pushed back onto the input stream. yyleng keeps track of the current length of
											yytext, so the command: 
											*/
	                                        yyless(0);
											yylloc->columns(-1);
                                        	// BEGIN(INITIAL); this get done by the parser
                                        	yylval->stringVal = new std::string(m_block_content);
                                        	return token::BLOCKCONTENT;
                                        }

                                       	m_block_content.append(std::string(yytext, yyleng));
									}

 /*** END EXAMPLE - Change the example lexer rules above ***/

%% /*** Additional Code ***/


namespace yy {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : MLangFlexLexer(in, out)
{
	this->current_line_indent = 0;
 	this->keywords = std::map<std::string, omega_parser::token_type>();
 	this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("def", omega_parser::token::DEF));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("return", omega_parser::token::TOK_RETURN));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("sizeof", omega_parser::token::SIZEOF));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("end", omega_parser::token::BLOCK_END));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("if", omega_parser::token::IF));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("else", omega_parser::token::ELSE));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("while", omega_parser::token::WHILE));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("namespace", omega_parser::token::NAMESPACE));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("class", omega_parser::token::CLASS));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("struct", omega_parser::token::STRUCT));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("include", omega_parser::token::INCLUDE));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("ir", omega_parser::token::IR));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("asm", omega_parser::token::ASM));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("new", omega_parser::token::NEW));
    this->keywords.insert(std::map<std::string, omega_parser::token_type>::value_type("external", omega_parser::token::EXTERNAL));
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}
void
Scanner::end_block() {
	yy_pop_state();
	m_block_content = "";
}

void
Scanner::begin_block() {
	m_block_content = "";
	yy_push_state(BLOCK);
}

omega_parser::token_type 
Scanner::token_for(const std::string lexeme)
{
  std::map<std::string, omega_parser::token_type>::const_iterator ret = this->keywords.find(lexeme);
  if (ret == this->keywords.end())
  {
    return omega_parser::token::IDENTIFIER;
  }
  return ret->second;
}


/*
int line_nr = 0;
std::string current_line = "";
void DumpRow(bool end_of_file = false) {
  if (  line_nr == 0  ) 
  {
    int i;
    std::cout << "       |";
    for (i=1; i<71; i++)
      if (  i % 10 == 0  )
        std::cout << ":"; 
      else if (  i % 5 == 0  )
        std::cout << "+"; 
      else
        std::cout << ".";
      std::cout << std::endl;	
  }
  else 
  {
  	std::cout << std::setfill(' ') << std::setw(6) << line_nr << " |" << current_line;
  	if (end_of_file)
  		std::cout << "$-EOF";
  	std::cout << std::endl;	
  }
}

int Scanner::LexerInput( char* buf, int max_size )
{
	if ( yyin->eof() || yyin->fail() )
		return 0;

	int position = 0;
	while(position < max_size)
	{	
		yyin->get(buf[position]); 	// reading one character from file to array
		position++;					// we read 1 char
		
		if (buf[position - 1] == '\n')
		{
			break;
		}
		else if (yyin->eof())
		{
			buf[position - 1] = EOF;
			break;
		}
	}

	if ( yyin->bad() )
		return -1;
	else
	{
		int backup_char = buf[position - 1];
		buf[position - 1] = '\0';
		current_line = std::string(buf);
		buf[position - 1] = backup_char;
		
		if (line_nr == 0)
			DumpRow();
		line_nr++;
		DumpRow(buf[position - 1] == EOF);
			
		return position;
	}
}
*/

}

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */
#ifdef yylex
#undef yylex
#endif

int MLangFlexLexer::yylex()
{
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}
