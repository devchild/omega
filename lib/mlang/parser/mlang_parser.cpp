// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison GLR parsers in C

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.cc"

/* Pure parsers.  */
#define YYPURE 1






/* First part of user declarations.  */

#line 55 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:207

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "mlang_parser.hh"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;

/* Copy the second part of user declarations.  */
#line 87 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:230
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
static void yyerror (const yy::mlang_parser::location_type *yylocationp, yy::mlang_parser& yyparser, mlang_driver& driver, const char* msg);
#line 109 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:230
// Unqualified %code blocks.
#line 31 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:231

# include "mlang_driver.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.scanner()->lex


#line 122 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:231

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify clang.  */
# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNRULES -- Number of states.  */
#define YYNSTATES  219
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,    46,    49,     2,
      33,    34,    44,    37,    36,    38,    41,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,     2,
      47,    35,    48,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    51,     2,    40,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    87,    87,    87,   137,   138,   142,   147,   156,   164,
     165,   169,   173,   181,   182,   183,   187,   214,   215,   219,
     223,   231,   232,   233,   237,   238,   242,   260,   278,   279,
     283,   288,   296,   300,   306,   311,   322,   323,   324,   325,
     326,   327,   332,   337,   341,   337,   352,   397,   420,   425,
     430,   435,   443,   462,   495,   502,   513,   514,   520,   531,
     540,   545,   554,   555,   559,   560,   565,   575,   579,   580,
     581,   590,   591,   592,   596,   597,   598,   599,   600,   601,
     602,   603,   607,   617,   636,   646,   647,   655,   663,   674,
     675,   683,   694,   695,   703,   714,   715,   723,   731,   739,
     750,   751,   759,   770,   771,   782,   783,   794,   795,   806,
     807,   818,   819,   830,   831,   838,   847,   856,   874,   890,
     912,   913,   917,   925,   937,   946,   962,   992,   998,  1009,
    1074,  1075,  1079,  1084
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"end of line\"", "\"new\"",
  "\"end\"", "\"if\"", "\"else\"", "\"while\"", "\"namespace\"",
  "\"class\"", "\"struct\"", "\"=\"", "\"return\"", "\"import\"", "\"ir\"",
  "\"asm\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "\"||\"", "\"&&\"",
  "\">>\"", "\"<<\"", "\"[]\"", "\"block content\"", "\"external\"",
  "\"identifier\"", "\"integer\"", "\"double\"", "\"string\"", "':'",
  "'('", "')'", "'='", "','", "'+'", "'-'", "'!'", "'~'", "'.'", "'['",
  "']'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'", "'?'",
  "$accept", "compile_unit", "$@1", "file_import_list_opt",
  "file_import_list", "file_import", "compile_unit_member_list_opt",
  "compile_unit_member_list", "compile_unit_member", "namespace",
  "namespace_member_list_opt", "namespace_member_list", "namespace_member",
  "type_declaration", "class_declaration", "struct_declaration",
  "type_member_list_opt", "type_member_list", "type_member",
  "statement_list", "statement", "ir_block_statement", "$@2", "$@3",
  "assembly_call_expression", "iteration_statement",
  "expression_statement", "condition_statement",
  "variable_declaration_statement", "expression_opt",
  "method_return_statement", "parameter_declaration_expression",
  "parameter_declaration_expression_list",
  "parameter_declaration_expression_list_opt", "expression",
  "assign_expression", "non_assign_expression", "unary_expression",
  "primary_expression", "field_reference_expression",
  "array_indexer_expression", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "conditional_and_expression", "binary_operator_expression",
  "conditional_expression", "primitive_expression",
  "array_create_expression", "object_create_expression", "type_reference",
  "non_array_type_reference", "array_type_reference",
  "variable_reference_expression", "method", "member_field",
  "method_invoke_expression", "expression_list_opt", "expression_list", YY_NULLPTR
};
#endif

#define YYPACT_NINF -193
#define YYTABLE_NINF -123

  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
static const short int yypact[] =
{
    -193,     9,     6,  -193,    -5,    52,     6,  -193,  -193,     2,
      32,    37,    50,  -193,  -193,    52,  -193,  -193,  -193,  -193,
    -193,    56,    66,  -193,  -193,  -193,    52,    20,    20,    58,
    -193,    63,  -193,  -193,   111,    52,  -193,  -193,  -193,   120,
      20,  -193,    73,  -193,  -193,   136,   114,    50,  -193,  -193,
    -193,  -193,    33,  -193,    50,  -193,   123,    60,   122,    84,
     131,    50,    27,  -193,    50,   133,  -193,  -193,  -193,  -193,
      50,    84,    84,    84,    84,  -193,  -193,  -193,  -193,  -193,
      11,  -193,  -193,  -193,    91,    61,    96,   -11,    89,   118,
     124,   117,   155,   -20,  -193,  -193,  -193,  -193,   148,  -193,
    -193,  -193,  -193,   151,   153,    84,   165,    -1,   269,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,    11,    41,    48,
     170,    85,    -8,    84,   166,  -193,  -193,  -193,  -193,  -193,
      84,   171,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,  -193,  -193,  -193,  -193,  -193,
     169,    84,    84,  -193,    36,    84,   167,   173,  -193,   -24,
    -193,  -193,  -193,    91,    91,    61,    61,    96,    96,    96,
      96,   -11,   -11,    89,   118,   124,   117,   155,   178,  -193,
     -17,   177,   186,    84,   182,   174,  -193,    84,  -193,  -193,
    -193,    84,    27,    27,  -193,  -193,  -193,  -193,  -193,  -193,
     250,   288,   209,  -193,    27,  -193,  -193,   307,  -193
};

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
static const unsigned char yydefact[] =
{
       2,     0,     4,     1,     0,     9,     5,     6,     8,     0,
       0,     0,     0,   122,     3,    10,    11,    13,    14,    24,
      25,     0,   120,   121,    15,     7,    17,    28,    28,     0,
      12,     0,   123,    21,     0,    18,    19,    22,    23,     0,
      29,    30,     0,    32,    33,     0,     0,    62,    16,    20,
      26,    31,   127,    27,    62,    60,    63,     0,     0,     0,
       0,     0,     0,    59,     0,     0,   124,   115,   116,   117,
       0,     0,     0,     0,     0,    80,   128,    65,    64,    85,
      68,    75,    78,    73,    89,    92,    95,   100,   103,   105,
     107,   109,   111,   113,    67,    74,    81,    79,    77,    76,
     125,    61,    42,     0,     0,    56,     0,   124,     0,    34,
      39,    38,    36,    37,    40,    41,    51,     0,    50,    49,
       0,    48,     0,     0,     0,    69,    77,    70,    71,    72,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    57,    43,   126,    35,
      54,   130,     0,   132,     0,     0,     0,   131,    82,     0,
      86,    87,    88,    90,    91,    94,    93,    98,    99,    96,
      97,   101,   102,   104,   106,   108,   110,   112,     0,    66,
       0,     0,     0,     0,     0,     0,    46,     0,    84,   129,
      83,     0,     0,     0,    44,    55,   119,   118,   133,   114,
       0,     0,     0,    52,     0,    47,    45,     0,    53
};

  // YYPGOTO[NTERM-NUM].
static const short int yypgoto[] =
{
    -193,  -193,  -193,  -193,  -193,   212,  -193,  -193,   204,    19,
    -193,  -193,   187,    24,  -193,  -193,   193,  -193,   183,  -192,
    -106,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,   163,  -193,   172,    51,   -57,  -193,   -58,   -41,  -193,
    -193,  -193,    -4,     1,   -12,     4,    79,    81,    82,    80,
      83,    78,  -193,  -193,   -39,   -23,   180,   168,  -193,   -59,
       3,  -193,   -21,    74,   -26
};

  // YYDEFGOTO[NTERM-NUM].
static const short int yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    14,    15,    16,    17,
      34,    35,    36,    18,    19,    20,    39,    40,    41,   108,
     109,   110,   192,   212,    75,   111,   112,   113,   114,   155,
     115,    55,    56,    57,   163,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   120,    22,    23,   126,
      43,    44,    99,   166,   167
};

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
static const short int yytable[] =
{
      98,   150,   159,    98,   150,   116,   140,   141,    24,     3,
     210,   211,   197,   125,   127,   128,   129,   202,    24,   200,
       4,   117,   217,   118,  -122,   161,     8,  -122,   102,    38,
      26,    64,   151,   103,   162,   104,   142,   143,    38,   119,
     105,   121,   106,    65,   130,    33,    98,    12,    13,    98,
      37,   116,   131,   132,    33,   107,    67,    68,    69,    37,
      27,     9,    10,    11,    98,    28,    47,   117,    59,   118,
     196,    98,   197,    98,   -81,   170,   171,   172,    13,    12,
      13,   -79,   -81,   -81,    31,   119,    46,   121,    64,   -79,
     -79,    32,    98,    98,    62,    98,    47,   164,   136,   137,
      65,    52,    98,    98,   159,   159,   169,   198,   144,   145,
      76,   159,    66,    67,    68,    69,    48,    70,   -76,   138,
     139,    71,    72,    73,    74,    50,   -76,   -76,   177,   178,
     179,   180,   173,   174,    98,   133,   134,   135,    98,   175,
     176,    53,    98,    98,    98,   116,   116,    54,   181,   182,
      63,    98,    98,   116,   116,    98,   156,   116,    98,    61,
     116,   117,   117,   118,   118,   100,   123,   146,   148,   117,
     117,   118,   118,   117,   147,   118,   117,   149,   118,   119,
     119,   121,   121,   152,   153,    21,   154,   119,   119,   121,
     121,   119,    29,   121,   119,    21,   121,   157,   160,   168,
     165,   199,   188,   189,   193,   191,    21,    42,    42,   197,
     201,   203,   204,   195,   216,    21,   206,   207,    25,    30,
      42,    45,    49,    51,   101,   183,    60,    58,   184,   186,
     185,   190,   122,   187,    58,   194,     0,     0,     0,     0,
       0,    58,     0,     0,   205,     0,     0,     0,   208,     0,
     124,   102,   209,     0,    64,   213,   103,   214,   104,     0,
       0,     0,     0,   105,     0,   106,    65,     0,     0,     0,
     102,     0,     0,    64,   158,   103,     0,   104,   107,    67,
      68,    69,   105,     0,   106,    65,     0,     0,     0,   102,
       0,     0,    64,   215,   103,     0,   104,   107,    67,    68,
      69,   105,     0,   106,    65,     0,     0,     0,   102,     0,
       0,    64,   218,   103,     0,   104,   107,    67,    68,    69,
     105,     0,   106,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,    67,    68,    69
};

static const short int yycheck[] =
{
      59,    21,   108,    62,    21,    62,    17,    18,     5,     0,
     202,   203,    36,    71,    72,    73,    74,    34,    15,    43,
      14,    62,   214,    62,    25,    33,    31,    28,     1,    26,
      28,     4,    52,     6,    42,     8,    47,    48,    35,    62,
      13,    62,    15,    16,    33,    26,   105,    27,    28,   108,
      26,   108,    41,    42,    35,    28,    29,    30,    31,    35,
      28,     9,    10,    11,   123,    28,    33,   108,    35,   108,
      34,   130,    36,   132,    33,   133,   134,   135,    28,    27,
      28,    33,    41,    42,    28,   108,    28,   108,     4,    41,
      42,    25,   151,   152,    34,   154,    33,   123,    37,    38,
      16,    28,   161,   162,   210,   211,   132,   165,    19,    20,
      59,   217,    28,    29,    30,    31,     5,    33,    33,    23,
      24,    37,    38,    39,    40,     5,    41,    42,   140,   141,
     142,   143,   136,   137,   193,    44,    45,    46,   197,   138,
     139,     5,   201,   202,   203,   202,   203,    33,   144,   145,
      28,   210,   211,   210,   211,   214,   105,   214,   217,    36,
     217,   202,   203,   202,   203,    34,    33,    49,    51,   210,
     211,   210,   211,   214,    50,   214,   217,    22,   217,   202,
     203,   202,   203,    35,    33,     5,    33,   210,   211,   210,
     211,   214,    12,   214,   217,    15,   217,    32,    28,    28,
      34,    34,   151,   152,    35,   154,    26,    27,    28,    36,
      32,    34,    26,   162,     5,    35,    34,    43,     6,    15,
      40,    28,    35,    40,    61,   146,    54,    47,   147,   149,
     148,   153,    64,   150,    54,   161,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,   193,    -1,    -1,    -1,   197,    -1,
      70,     1,   201,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    13,    -1,    15,    16,    -1,    -1,    -1,
       1,    -1,    -1,     4,     5,     6,    -1,     8,    28,    29,
      30,    31,    13,    -1,    15,    16,    -1,    -1,    -1,     1,
      -1,    -1,     4,     5,     6,    -1,     8,    28,    29,    30,
      31,    13,    -1,    15,    16,    -1,    -1,    -1,     1,    -1,
      -1,     4,     5,     6,    -1,     8,    28,    29,    30,    31,
      13,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31
};

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
static const unsigned char yystos[] =
{
       0,    54,    55,     0,    14,    56,    57,    58,    31,     9,
      10,    11,    27,    28,    59,    60,    61,    62,    66,    67,
      68,   109,   110,   111,   113,    58,    28,    28,    28,   109,
      61,    28,    25,    62,    63,    64,    65,    66,   113,    69,
      70,    71,   109,   113,   114,    69,    28,    33,     5,    65,
       5,    71,    28,     5,    33,    84,    85,    86,   109,    35,
      86,    36,    34,    28,     4,    16,    28,    29,    30,    31,
      33,    37,    38,    39,    40,    77,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   112,   115,
      34,    84,     1,     6,     8,    13,    15,    28,    72,    73,
      74,    78,    79,    80,    81,    83,    88,    91,   107,   108,
     109,   115,   110,    33,   109,    90,   112,    90,    90,    90,
      33,    41,    42,    44,    45,    46,    37,    38,    23,    24,
      17,    18,    47,    48,    19,    20,    49,    50,    51,    22,
      21,    52,    35,    33,    33,    82,    87,    32,     5,    73,
      28,    33,    42,    87,   117,    34,   116,   117,    28,   117,
      90,    90,    90,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    99,   100,   101,   102,   103,    87,    87,
     104,    87,    75,    35,   116,    87,    34,    36,    90,    34,
      43,    32,    34,    34,    26,    87,    34,    43,    87,    87,
      72,    72,    76,     5,     7,     5,     5,    72,     5
};

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
static const unsigned char yyr1[] =
{
       0,    53,    55,    54,    56,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    65,    66,    66,    67,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    75,    76,    74,    77,    78,    79,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    84,
      85,    85,    86,    86,    87,    87,    88,    89,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    93,    94,    95,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    98,    98,
      99,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   106,   107,   108,
     109,   109,   110,   111,   112,   113,   113,   114,   114,   115,
     116,   116,   117,   117
};

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
static const unsigned char yyr2[] =
{
       0,     2,     0,     3,     0,     1,     1,     2,     2,     0,
       1,     1,     2,     1,     1,     1,     4,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     4,     4,     0,     1,
       1,     2,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     6,     4,     6,     1,     1,
       1,     1,     6,     8,     2,     4,     0,     1,     2,     2,
       1,     3,     0,     1,     1,     1,     3,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     1,     1,     5,     5,
       1,     1,     1,     2,     1,     6,     7,     2,     4,     4,
       0,     1,     1,     3
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0
};

/* Error token number */
#define YYTERROR 1


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YYDPRINTF(Args)                        \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
  } while (0)


/*--------------------.
| Print this symbol.  |
`--------------------*/

static void
yy_symbol_print (FILE *, int yytype, const yy::mlang_parser::semantic_type *yyvaluep, const yy::mlang_parser::location_type *yylocationp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  YYUSE (yyparser);
  YYUSE (driver);
  yyparser.yy_symbol_print_ (yytype, yyvaluep, yylocationp);
}


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YYFPRINTF (stderr, "%s ", Title);                               \
        yy_symbol_print (stderr, Type, Value, Location, yyparser, driver);        \
        YYFPRINTF (stderr, "\n");                                       \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static _Noreturn void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, yy::mlang_parser& yyparser, mlang_driver& driver, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, yyparser, driver, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static _Noreturn void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULLPTR);
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYUSE (yyparser);
  YYUSE (driver);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, yyparser, driver, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;

  switch (yyn)
    {
        case 2:
#line 87 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
									if (driver.root() == nullptr)
									{
										auto nd = new mlang::CodeCompileUnit();
										driver.root(nd);
									}
									driver.success(false);
								}
#line 1168 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 3:
#line 97 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
									if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
									{
										for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
										{
											auto file_import_nd = static_cast<mlang::CodeFileImport*>(child_nd);
											auto search_str = file_import_nd->file_name().substr(1, file_import_nd->file_name().size() - 2);
											driver.import(search_str);
										}
									}
								
									if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection) != nullptr)
									{
										for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection))
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
									((*yyvalp).node) = driver.root();
									driver.success(true);
								}
#line 1210 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 4:
#line 137 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = nullptr;	}
#line 1216 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 5:
#line 138 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 1222 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 6:
#line 142 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
									auto nd = new mlang::CodeObjectCollection();
									nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
									((*yyvalp).node_collection) = nd;
								}
#line 1232 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 7:
#line 148 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
									auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
									nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
									((*yyvalp).node_collection) = nd;
								}
#line 1242 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 8:
#line 156 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
									auto nd = new mlang::CodeFileImport();
									nd->file_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
									((*yyvalp).node) = nd;
								}
#line 1252 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 9:
#line 164 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = nullptr; }
#line 1258 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 10:
#line 165 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection); }
#line 1264 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 11:
#line 169 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
									((*yyvalp).node_collection) = new mlang::CodeObjectCollection();
									((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
								}
#line 1273 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 12:
#line 174 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
									((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
									((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
								}
#line 1282 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 13:
#line 181 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1288 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 14:
#line 182 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1294 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 15:
#line 183 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1300 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 16:
#line 188 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeNamespace();
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
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
												
												((*yyvalp).node) = nd;
											}
#line 1328 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 17:
#line 214 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = nullptr; 	}
#line 1334 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 18:
#line 215 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 1340 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 19:
#line 219 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												((*yyvalp).node_collection) = new mlang::CodeObjectCollection();
												((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));	
											}
#line 1349 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 20:
#line 224 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
												((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
											}
#line 1358 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 21:
#line 231 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1364 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 22:
#line 232 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1370 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 23:
#line 233 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1376 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 24:
#line 237 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1382 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 25:
#line 238 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1388 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 26:
#line 243 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeTypeDeclaration();
												nd->is_class(true);
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														nd->members()->push_back(static_cast<mlang::CodeTypeMember*>(child_nd));
														child_nd->parent(nd);
													}
												}
												((*yyvalp).node) = nd;
											}
#line 1407 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 27:
#line 261 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeTypeDeclaration();
												nd->is_struct(true);
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														nd->members()->push_back(static_cast<mlang::CodeTypeMember*>(child_nd));
														child_nd->parent(nd);
													}
												}
												((*yyvalp).node) = nd;
											}
#line 1426 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 28:
#line 278 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = nullptr;	}
#line 1432 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 29:
#line 279 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 1438 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 30:
#line 283 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1448 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 31:
#line 288 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1458 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 32:
#line 297 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);
											}
#line 1466 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 33:
#line 300 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);
											}
#line 1474 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 34:
#line 306 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1484 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 35:
#line 311 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);	
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) != nullptr)
												{
													nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												}
												((*yyvalp).node_collection) = nd;
											}
#line 1497 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 36:
#line 322 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1503 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 37:
#line 323 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1509 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 38:
#line 324 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1515 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 39:
#line 325 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1521 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 40:
#line 326 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1527 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 41:
#line 327 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												// this one causes 6 shift/reduce conflicts.
												// adding an extra term could help eg. ';'
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	
											}
#line 1537 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 42:
#line 332 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = nullptr; }
#line 1543 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 43:
#line 337 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												driver.scanner()->begin_block();	
											}
#line 1551 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 44:
#line 341 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												driver.scanner()->end_block();
											}
#line 1559 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 45:
#line 344 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeIrBlockStatement();
												nd->content(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 1569 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 46:
#line 352 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeAssemblyCallExpression();
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													int i = 0;
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															if (i == 0)
															{
																if (!child_nd->type_of(mlang::CodeObjectKind::CodePrimitiveExpression))
																	yyerror(&yylloc, yyparser, driver, "string literal expected");
																auto stringliteral = static_cast<mlang::CodePrimitiveExpression*>(child_nd);
																if (stringliteral->type()->base_type() != "Char[]")
																	yyerror(&yylloc,yyparser, driver, "string literal expected");
																		
																nd->content(stringliteral->value_as_string());
															}
															else if (i == 1)
															{
																if (!child_nd->type_of(mlang::CodeObjectKind::CodePrimitiveExpression))
																	yyerror(&yylloc,yyparser, driver, "string literal expected");
																auto stringliteral = static_cast<mlang::CodePrimitiveExpression*>(child_nd);
																if (stringliteral->type()->base_type() != "Char[]")
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
												
												
												((*yyvalp).node) = nd;
											}
#line 1616 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 47:
#line 398 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeIterationStatement();
												nd->test_expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															nd->statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												((*yyvalp).node) = nd;
											}
#line 1639 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 48:
#line 420 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1649 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 49:
#line 425 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1659 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 50:
#line 430 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1669 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 51:
#line 435 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1679 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 52:
#line 444 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeConditionStatement();
												nd->condition(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															nd->true_statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												((*yyvalp).node) = nd;
											}
#line 1702 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 53:
#line 463 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeConditionStatement();
												nd->condition(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node)));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															nd->true_statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															nd->false_statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												
												((*yyvalp).node) = nd;
											}
#line 1736 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 54:
#line 495 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeVariableDeclarationStatement();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												nd->init_expression(nullptr);
												((*yyvalp).node) = nd;
											}
#line 1748 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 55:
#line 503 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeVariableDeclarationStatement();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												nd->init_expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1760 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 56:
#line 513 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = nullptr;	}
#line 1766 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 57:
#line 514 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);
											}
#line 1774 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 58:
#line 520 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeMethodReturnStatement();
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) != nullptr)
												{
													nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												}
												((*yyvalp).node) = nd;
											}
#line 1787 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 59:
#line 531 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeParameterDeclarationExpression();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 1798 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 60:
#line 540 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1808 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 61:
#line 546 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node_collection);	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1818 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 62:
#line 554 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = nullptr;}
#line 1824 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 63:
#line 555 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);	}
#line 1830 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 64:
#line 559 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1836 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 65:
#line 560 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1842 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 66:
#line 566 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeAssignExpression();
												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1853 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 67:
#line 575 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1859 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 68:
#line 579 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1865 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 69:
#line 580 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1871 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 70:
#line 581 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeBinaryOperatorExpression();
												auto m_left = new mlang::CodePrimitiveExpression();
												m_left->value(new int(1));
												nd->left(m_left);
												nd->operator_(mlang::CodeBinaryOperatorType::Multiply);
												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1885 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 71:
#line 590 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1891 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 72:
#line 591 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1897 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 73:
#line 592 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1903 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 74:
#line 596 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1909 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 75:
#line 597 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1915 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 76:
#line 598 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1921 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 77:
#line 599 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1927 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 78:
#line 600 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1933 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 79:
#line 601 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1939 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 80:
#line 602 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1945 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 81:
#line 603 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1951 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 82:
#line 608 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeFieldReferenceExpression();
												nd->target_object(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												nd->field_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 1962 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 83:
#line 618 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeArrayIndexerExpression();
												nd->target_object(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												
												for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
												{
													if (child_nd != nullptr)
													{
														nd->indices()->push_back(static_cast<mlang::CodeExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												
												((*yyvalp).node) = nd;
											}
#line 1982 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 84:
#line 637 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												 auto nd = new mlang::CodeCastExpression();
												 nd->target_type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												 nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												 ((*yyvalp).node) = nd;
											}
#line 1993 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 85:
#line 646 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1999 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 86:
#line 648 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Multiply);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2011 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 87:
#line 656 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Divide);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2023 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 88:
#line 664 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Modulus);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2035 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 89:
#line 674 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2041 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 90:
#line 676 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Add);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2053 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 91:
#line 684 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Subtract);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2065 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 92:
#line 694 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2071 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 93:
#line 696 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::ShiftLeft);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2083 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 94:
#line 704 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::ShiftRight);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2095 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 95:
#line 714 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2101 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 96:
#line 716 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::LessThan);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2113 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 97:
#line 724 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::GreaterThan);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2125 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 98:
#line 732 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::LessThanOrEqual);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2137 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 99:
#line 740 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::GreaterThanOrEqual);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2149 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 100:
#line 750 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2155 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 101:
#line 752 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::IdentityEquality);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2167 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 102:
#line 760 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::IdentityInEquality);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2179 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 103:
#line 770 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2185 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 104:
#line 772 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BitwiseAnd);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2197 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 105:
#line 782 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2203 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 106:
#line 784 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Add);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2215 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 107:
#line 794 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2221 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 108:
#line 796 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BitwiseOr);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2233 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 109:
#line 806 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2239 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 110:
#line 808 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BooleanAnd);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2251 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 111:
#line 818 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2257 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 112:
#line 820 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BooleanOr);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2269 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 113:
#line 830 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2275 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 114:
#line 832 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
  												((*yyvalp).node) = nullptr;
  											}
#line 2283 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 115:
#line 838 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												tp->base_type("Int32");
												
												nd->type(tp);
												nd->value((void*)(uint64_t*)(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integerVal));
												((*yyvalp).node) = nd;
											}
#line 2297 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 116:
#line 847 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												tp->base_type("Double");
												
												nd->type(tp);
												nd->value(const_cast<float*>(&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.doubleVal)));
												((*yyvalp).node) = nd;
											}
#line 2311 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 117:
#line 856 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												
												auto array_element_type = new mlang::CodeTypeReference();
												array_element_type->base_type("Char");
												tp->base_type("Char[]");
												tp->array_rank(1);
												tp->array_element_type(array_element_type);
												
												
												nd->value((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												nd->type(tp);
												((*yyvalp).node) = nd;
											}
#line 2331 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 118:
#line 875 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeArrayCreateExpression();
												
												auto create_type = new mlang::CodeTypeReference();
												create_type->array_element_type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												create_type->array_rank(1);
												create_type->base_type(create_type->array_element_type()->base_type() + "[]");
												
												nd->create_type(create_type);
												nd->size_expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 2348 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 119:
#line 891 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeObjectCreateExpression();
												
												auto create_type = static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node));
												nd->create_type(create_type);
												
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for (auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														nd->parameters()->push_back(static_cast<mlang::CodeExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												
												((*yyvalp).node) = nd;
												
											}
#line 2371 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 120:
#line 912 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2377 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 121:
#line 913 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2383 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 122:
#line 917 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeTypeReference();
												nd->base_type(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2393 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 123:
#line 926 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeTypeReference();
												auto array_element_type = static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
												nd->array_element_type(array_element_type);
												nd->array_rank((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integerVal));
												nd->base_type(array_element_type->base_type() + "[]");
												((*yyvalp).node) = nd;
											}
#line 2406 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 124:
#line 938 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeVariableReferenceExpression();
												nd->variable_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2416 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 125:
#line 947 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeMemberMethod();
												nd->return_type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for (auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														nd->parameters()->push_back(static_cast<mlang::CodeParameterDeclarationExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												nd->attributes(mlang::MemberAttributes::External);
												((*yyvalp).node) = nd;
											}
#line 2436 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 126:
#line 963 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {
												auto nd = new mlang::CodeMemberMethod();
												nd->return_type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for (auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node_collection))
													{
														nd->parameters()->push_back(static_cast<mlang::CodeParameterDeclarationExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for (auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															nd->statements()->push_back(static_cast<mlang::CodeStatement*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												((*yyvalp).node) = nd;
											}
#line 2467 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 127:
#line 992 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeMemberField();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2478 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 128:
#line 999 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeMemberField();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												nd->init_expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 2490 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 129:
#line 1010 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeMethodInvokeExpression();
												
												auto method_reference_expression = new mlang::CodeMethodReferenceExpression();
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)->type_of(mlang::CodeObjectKind::CodeVariableReferenceExpression))
												{
													auto tmp = static_cast<mlang::CodeVariableReferenceExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node));
													method_reference_expression->method_name(tmp->variable_name());
												}
												else if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)->type_of(mlang::CodeObjectKind::CodeFieldReferenceExpression))
												{
													auto tmp = static_cast<mlang::CodeFieldReferenceExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node));
													method_reference_expression->method_name(tmp->field_name());
													method_reference_expression->target_object(tmp->target_object());
												}
												nd->method(method_reference_expression);
												
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for (auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														nd->parameters()->push_back(static_cast<mlang::CodeExpression*>(child_nd));
														child_nd->parent(nd);
													}
												}
												((*yyvalp).node) = nd;
											}
#line 2522 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 130:
#line 1074 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = nullptr;	}
#line 2528 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 131:
#line 1075 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 2534 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 132:
#line 1079 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 2544 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;

  case 133:
#line 1084 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:783
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node_collection);	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 2554 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
    break;


#line 2558 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:783
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (yyparser);
  YYUSE (driver);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 28: // "identifier"
#line 81 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:813
      { delete ((*yyvaluep).stringVal); }
#line 2609 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:813
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, &yys->yyloc, yyparser, driver);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete", yymsg);
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, yyparser, driver);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-193)))

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) \
  0

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YYASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YYASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                 yyRuleNum yyrule, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
                       , &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , yyparser, driver);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YYFPRINTF (stderr, " (unresolved)");
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule, yyparser, driver));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp, yylocp, yyparser, driver);
    }
  else
    {
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule, yyparser, driver));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, yyparser, driver);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, &yyloc, yyparser, driver);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        {
          YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                     (unsigned long int) yyk, yyrule - 1));
        }
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  "
                  "Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULLPTR;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp, yy::mlang_parser& yyparser, mlang_driver& driver);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, yyparser, driver));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, yyparser, driver));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, yyparser, driver);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, yyparser, driver);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, yyparser, driver);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]),
                       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (yylocp, yyparser, driver, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState* yys1, int yyn1,
                    yyGLRStack *yystackp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, yyparser, driver);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YYASSERT (yyoption != YY_NULLPTR);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (yynrhs > 0)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, yyparser, driver);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          {
            int yychar_current = yychar;
            YYSTYPE yylval_current = yylval;
            YYLTYPE yylloc_current = yylloc;
            yychar = yyoption->yyrawchar;
            yylval = yyoption->yyval;
            yylloc = yyoption->yyloc;
            YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
            yychar = yychar_current;
            yylval = yylval_current;
            yylloc = yylloc_current;
          }
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, yyparser, driver);
              return yyreportAmbiguity (yybest, yyp, yylocp, yyparser, driver);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, yyparser, driver);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, &yydummy, yyparser, driver);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, yylocp, yyparser, driver);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, yyparser, driver);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , yyparser, driver));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn, YYLTYPE *yylocp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], yyparser, driver);
          if (yyflag == yyerr)
            {
              YYDPRINTF ((stderr,
                          "Stack %lu dies "
                          "(predicate failure or explicit user error).\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken;
          int yyaction;
          const short int* yyconflicts;

          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
          if (yychar == YYEMPTY)
            {
              YYDPRINTF ((stderr, "Reading a token: "));
              yychar = yylex (&yylval, &yylloc);
            }

          if (yychar <= YYEOF)
            {
              yychar = yytoken = YYEOF;
              YYDPRINTF ((stderr, "Now at end of input.\n"));
            }
          else
            {
              yytoken = YYTRANSLATE (yychar);
              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
            }

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], yyparser, driver);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, yyparser, driver));
              else if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr, "Stack %lu dies.\n",
                              (unsigned long int) yynewStack));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], yyparser, driver);
              if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr,
                              "Stack %lu dies "
                              "(predicate failure or explicit user error).\n",
                              (unsigned long int) yyk));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (&yylloc, yyparser, driver, YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
  size_t yysize = yysize0;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                {
                  size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  yysize_overflow |= yysz < yysize;
                  yysize = yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    size_t yysz = yysize + strlen (yyformat);
    yysize_overflow |= yysz < yysize;
    yysize = yysz;
  }

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              yyp++;
              yyformat++;
            }
        }
      yyerror (&yylloc, yyparser, driver, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, yyparser, driver, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, yy::mlang_parser& yyparser, mlang_driver& driver)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, yyparser, driver, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, yyparser, driver);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = yylex (&yylval, &yylloc);
        if (yychar <= YYEOF)
          {
            yychar = yytoken = YYEOF;
            YYDPRINTF ((stderr, "Now at end of input.\n"));
          }
        else
          {
            yytoken = YYTRANSLATE (yychar);
            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
          }
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, &yylloc, yyparser, driver, YY_NULLPTR);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, yyparser, driver);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, yyparser, driver, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (yy::mlang_parser& yyparser, mlang_driver& driver)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  /* User initialization code.  */
  yylloc.initialize ();
#line 16 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2237
{
  // Initialize the initial location.
  yylloc.begin.filename = yylloc.end.filename = driver.streamname();
}

#line 4050 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2237

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
               yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, yyparser, driver);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, yyparser, driver));
            }
          else
            {
              yySymbol yytoken;
              if (yychar == YYEMPTY)
                {
                  YYDPRINTF ((stderr, "Reading a token: "));
                  yychar = yylex (&yylval, &yylloc);
                }

              if (yychar <= YYEOF)
                {
                  yychar = yytoken = YYEOF;
                  YYDPRINTF ((stderr, "Now at end of input.\n"));
                }
              else
                {
                  yytoken = YYTRANSLATE (yychar);
                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
                }

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
               yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, yyparser, driver);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, yyparser, driver));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, yyparser, driver));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, yyparser, driver, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, yyparser, driver));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
           yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, yyparser, driver);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, yyparser, driver));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, yyparser, driver);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (&yylloc, yyparser, driver, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, yyparser, driver);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                 yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                  if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, yyparser, driver);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULLPTR ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYASSERT (yyp->yystate.yyisState);
          YYASSERT (yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYASSERT (!yyp->yystate.yyisState);
          YYASSERT (!yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc



#line 1091 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2551


void
yy::mlang_parser::error (const yy::mlang_parser::location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
#line 4360 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2551

/*------------------.
| Report an error.  |
`------------------*/

static void
yyerror (const yy::mlang_parser::location_type *yylocationp, yy::mlang_parser& yyparser, mlang_driver& driver, const char* msg)
{
  YYUSE (yyparser);
  YYUSE (driver);
  yyparser.error (*yylocationp, msg);
}



namespace yy {
#line 4377 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2551
  /// Build a parser object.
  mlang_parser::mlang_parser (mlang_driver& driver_yyarg)
    :
#if YYDEBUG
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  mlang_parser::~mlang_parser ()
  {
  }

  int
  mlang_parser::parse ()
  {
    return ::yyparse (*this, driver);
  }

#if YYDEBUG
  /*--------------------.
  | Print this symbol.  |
  `--------------------*/

  inline void
  mlang_parser::yy_symbol_value_print_ (int yytype,
                           const semantic_type* yyvaluep,
                           const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyoutput = debug_stream ();
    std::ostream& yyo = yyoutput;
    YYUSE (yyo);
    switch (yytype)
    {
          case 25: // "[]"
#line 82 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2551
      { yyoutput << ((*yyvaluep).integerVal); }
#line 4418 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2551
        break;

    case 28: // "identifier"
#line 80 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2551
      { yyoutput << *((*yyvaluep).stringVal); }
#line 4424 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2551
        break;

    case 29: // "integer"
#line 82 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2551
      { yyoutput << ((*yyvaluep).integerVal); }
#line 4430 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2551
        break;


      default:
        break;
    }
  }


  void
  mlang_parser::yy_symbol_print_ (int yytype,
                           const semantic_type* yyvaluep,
                           const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < YYNTOKENS ? "token" : "nterm")
               << ' ' << yytname[yytype] << " ("
               << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }

  std::ostream&
  mlang_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  mlang_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  mlang_parser::debug_level_type
  mlang_parser::debug_level () const
  {
    return yydebug;
  }

  void
  mlang_parser::set_debug_level (debug_level_type l)
  {
    // Actually, it is yydebug which is really used.
    yydebug = l;
  }

#endif

} // yy
#line 4481 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2551
