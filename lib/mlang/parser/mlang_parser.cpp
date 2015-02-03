// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison GLR parsers in C

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.cc"

/* Pure parsers.  */
#define YYPURE 1






/* First part of user declarations.  */

#line 55 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:240

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
#line 87 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:263
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
#line 109 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:263
// Unqualified %code blocks.
#line 31 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:264

# include "mlang_driver.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.scanner()->lex


#line 122 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:264

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
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNRULES -- Number of states.  */
#define YYNSTATES  272
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 13
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    51,    54,     2,
      40,    42,    49,    44,    41,    45,    48,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      52,    43,    53,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    56,     2,    47,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    94,    94,    94,   144,   145,   149,   155,   164,   173,
     174,   178,   183,   192,   193,   196,   210,   237,   241,   249,
     250,   251,   255,   256,   260,   283,   304,   309,   318,   330,
     345,   350,   361,   362,   363,   364,   365,   366,   371,   375,
     378,   375,   389,   438,   461,   467,   472,   477,   482,   490,
     509,   542,   549,   560,   561,   567,   580,   589,   594,   603,
     604,   608,   609,   613,   620,   630,   634,   635,   636,   645,
     646,   647,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   663,   671,   681,   700,   710,   711,   719,   727,   738,
     739,   747,   758,   759,   767,   778,   779,   787,   795,   803,
     814,   815,   823,   834,   835,   846,   847,   858,   859,   870,
     871,   882,   883,   894,   895,   902,   911,   920,   938,   954,
     975,   976,   980,   989,  1002,  1011,  1027,  1054,  1084,  1090,
    1101,  1125,  1130,  1168,  1169,  1173,  1178,  1186,  1187,  1191,
    1195,  1206,  1221,  1228,  1233,  1240,  1255,  1256,  1262,  1268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"end of line\"", "\"new\"",
  "\"def\"", "\"[\"", "\"]\"", "\"end of statement\"", "\"indent\"",
  "\"dedent\"", "\"end\"", "\"if\"", "\"else\"", "\"while\"",
  "\"namespace\"", "\"class\"", "\"struct\"", "\"=\"", "\"return\"",
  "\"include\"", "\"ir\"", "\"sizeof\"", "\"asm\"", "\"<=\"", "\">=\"",
  "\"==\"", "\"!=\"", "\"||\"", "\"&&\"", "\">>\"", "\"<<\"", "\"[]\"",
  "\"block content\"", "\"external\"", "\"identifier\"", "\"integer\"",
  "\"double\"", "\"string\"", "':'", "'('", "','", "')'", "'='", "'+'",
  "'-'", "'!'", "'~'", "'.'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'",
  "'^'", "'|'", "'?'", "$accept", "compile_unit", "$@1",
  "file_include_list_opt", "file_include_list", "file_include",
  "compile_unit_member_list_opt", "compile_unit_member_list",
  "compile_unit_member", "namespace", "namespace_member_list",
  "namespace_member", "type_declaration", "class_declaration",
  "struct_declaration", "type_member_list", "type_member",
  "statement_list", "statement", "ir_block_statement", "$@2", "$@3",
  "assembly_call_expression", "iteration_statement",
  "expression_statement", "statement_expression", "condition_statement",
  "variable_declaration_statement", "expression_opt",
  "method_return_statement", "parameter_declaration_expression",
  "parameter_declaration_expression_list",
  "parameter_declaration_expression_list_opt", "expression",
  "assign_expression", "non_assign_expression", "unary_expression",
  "primary_expression", "sizeof_expression", "field_reference_expression",
  "array_indexer_expression", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "conditional_and_expression", "binary_operator_expression",
  "conditional_expression", "primitive_expression",
  "array_create_expression", "object_create_expression", "type_reference",
  "non_array_type_reference", "array_type_reference",
  "variable_reference_expression", "method", "member_field",
  "method_invoke_expression", "method_reference_expression",
  "expression_list_opt", "expression_list", "attributes_opt", "attributes",
  "attributes_sections", "attributes_section", "attribute_list",
  "attribute", "attribute_arguments_opt", "attribute_name",
  "attribute_arguments", YY_NULLPTR
};
#endif

#define YYPACT_NINF -173
#define YYTABLE_NINF -133

  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
static const short int yypact[] =
{
    -173,    15,    76,  -173,    -3,    16,    76,  -173,  -173,    83,
      85,  -173,   108,  -173,  -173,   193,  -173,   116,  -173,  -173,
    -173,    -1,  -173,    90,   107,  -173,   129,   132,   134,   136,
    -173,  -173,  -173,  -173,   139,   111,  -173,  -173,  -173,  -173,
      83,   228,  -173,  -173,   104,    95,   137,   142,   148,   159,
    -173,  -173,   136,   181,   189,   197,  -173,  -173,  -173,   136,
     228,   228,   228,   228,  -173,  -173,  -173,  -173,  -173,     3,
    -173,   145,  -173,  -173,   167,    -6,   110,   190,   122,   194,
     192,   188,   220,    -5,  -173,  -173,  -173,  -173,   209,  -173,
     213,   165,  -173,    19,  -173,   193,   136,   245,   246,   216,
     136,     1,   136,   136,   217,  -173,  -173,  -173,  -173,  -173,
    -173,   228,   225,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,  -173,  -173,  -173,  -173,
    -173,  -173,   229,   235,   247,   116,   116,   136,   239,   228,
     228,   241,   243,   228,    84,   248,  -173,  -173,  -173,  -173,
     167,   167,    -6,    -6,   110,   110,   110,   110,   190,   190,
     122,   194,   192,   188,   220,   250,  -173,   244,   256,  -173,
     136,   252,  -173,    26,  -173,     8,    27,   259,   260,   278,
     261,  -173,   228,  -173,  -173,   228,  -173,  -173,   293,  -173,
    -173,   269,  -173,  -173,  -173,  -173,   297,  -173,  -173,   170,
    -173,   400,    86,   400,  -173,  -173,   270,   271,   228,   273,
      92,   257,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,     3,    97,    99,   279,   109,   228,   286,   228,   228,
    -173,  -173,   304,  -173,  -173,   272,  -173,  -173,   -16,   275,
    -173,   228,   281,   287,   285,  -173,   319,   321,  -173,   400,
     400,   322,   315,   344,  -173,   318,  -173,   294,   326,   400,
     373,  -173
};

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
static const unsigned char yydefact[] =
{
       2,     0,     4,     1,     0,   137,     5,     6,     8,     0,
       0,     3,   137,    11,    13,     0,   138,   139,   140,     7,
     148,     0,   143,   146,     0,    12,     0,     0,     0,     0,
     122,    14,    22,    23,     0,   120,   121,    15,   141,   142,
       0,     0,   145,   147,   137,     0,     0,     0,     0,     0,
     123,   144,     0,     0,     0,   124,   115,   116,   117,     0,
       0,     0,     0,     0,    78,   135,    62,    61,    85,    66,
      80,    73,    76,    71,    89,    92,    95,   100,   103,   105,
     107,   109,   111,   113,    65,    72,    79,    77,    75,    74,
       0,     0,    19,   137,    17,     0,    59,     0,     0,     0,
      59,     0,     0,     0,     0,    67,    73,    75,    68,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,   149,    16,    18,    20,
      21,    57,    60,     0,     0,   137,   137,    59,     0,     0,
     133,     0,     0,     0,     0,    82,    64,    86,    87,    88,
      90,    91,    94,    93,    98,    99,    96,    97,   101,   102,
     104,   106,   108,   110,   112,     0,    63,     0,   134,   136,
       0,     0,    56,   137,    26,     0,   137,     0,     0,     0,
       0,    81,     0,    84,    83,     0,   130,    58,     0,    24,
      27,     0,    28,    29,    25,   125,     0,   118,   119,     0,
     114,     0,   128,     0,    42,    38,     0,     0,    53,     0,
     124,     0,    30,    35,    34,    32,    44,    33,    36,    37,
      48,     0,    47,    46,     0,    45,     0,     0,     0,     0,
      55,    54,     0,   127,    31,    51,   129,   126,     0,     0,
      39,     0,     0,     0,     0,    52,     0,     0,    40,     0,
       0,     0,     0,     0,    41,    49,    43,     0,     0,     0,
       0,    50
};

  // YYPGOTO[NTERM-NUM].
static const short int yypgoto[] =
{
    -173,  -173,  -173,  -173,  -173,   333,  -173,  -173,   328,   -40,
    -173,   249,   251,  -173,  -173,   195,  -172,   -74,  -100,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
     163,  -173,   -50,  -105,  -109,  -173,   -15,  -104,  -173,   -60,
    -173,  -173,   102,   103,    81,   100,   222,   219,   215,   227,
     224,   121,  -173,  -173,   -69,   -29,    77,   308,  -173,   -42,
     -90,  -173,   -24,  -173,   211,   -17,     5,  -173,  -173,   345,
    -173,   324,  -173,  -173,  -173
};

  // YYDEFGOTO[NTERM-NUM].
static const short int yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    11,    12,    13,    14,
      93,    94,    31,    32,    33,   183,   184,   221,   222,   223,
     254,   261,    64,   224,   225,   226,   227,   228,   240,   229,
     141,   142,   143,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   234,    35,    36,    88,
      37,   203,    89,    90,   177,   178,   185,    16,    17,    18,
      21,    22,    42,    23,    43
};

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
static const short int yytable[] =
{
     106,   106,   106,   106,    92,   140,    39,   149,   156,   111,
      15,   200,   131,    26,   200,     3,    -9,    15,   107,   107,
     107,   107,     9,   131,    91,     9,   252,   175,   176,   137,
     179,    10,     9,     9,    10,     8,   199,   204,   117,   118,
      40,   150,    29,    30,   189,   105,   108,   109,   110,    95,
     148,   112,   132,    92,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     210,   194,    34,   106,   154,   202,     4,   187,    95,   157,
     158,   159,   230,   -79,   230,   -77,    48,   231,   -10,   231,
       9,   107,   230,   241,     9,   -74,    44,   231,    20,    10,
      24,   244,     9,    10,  -122,   135,   100,  -122,   230,   236,
      41,   246,  -131,   231,   249,    96,   104,   244,   193,   237,
     119,   120,   232,    50,   232,   -79,   255,   -77,   125,   126,
     230,   230,   232,   230,   230,   231,   231,   -74,   231,   231,
     230,   230,   244,   244,    45,   231,   231,    46,   232,    47,
     244,    30,    34,   144,    49,   209,    97,   144,   106,   151,
     152,    98,   233,    99,   233,   262,   263,   235,   113,   235,
     232,   232,   233,   232,   232,   270,   107,   235,    26,   100,
     232,   232,   164,   165,   166,   167,   135,   136,   233,    27,
      28,   135,   214,   235,   121,   122,   114,   115,   116,   160,
     161,   102,   162,   163,   144,   168,   169,    29,    30,   103,
     233,   233,    52,   233,   233,   235,   235,  -131,   235,   235,
     233,   233,   123,   124,   129,   235,   235,   128,   127,   130,
      53,    54,   133,   134,   145,   146,   147,   144,   215,   153,
     155,    52,   201,    55,    56,    57,    58,   243,    59,   216,
     180,   217,    60,    61,    62,    63,   218,   181,   219,    53,
      54,   188,   182,   191,   192,   207,   196,   215,  -132,   195,
      52,   198,   220,    56,    57,    58,   247,   135,   216,   206,
     217,   205,   211,   208,   212,   218,   213,   219,    53,    54,
     238,   239,   242,   250,   245,   251,   215,   253,   258,    52,
     256,   220,    56,    57,    58,   265,   257,   216,   259,   217,
     260,   267,   264,   268,   218,   269,   219,    53,    54,    19,
      25,   186,   138,   197,   172,   215,   139,   171,    52,   170,
     220,    56,    57,    58,   266,   174,   216,   173,   217,   248,
     101,   190,    38,   218,    51,   219,    53,    54,     0,     0,
       0,     0,     0,     0,   215,     0,     0,    52,     0,   220,
      56,    57,    58,   271,     0,   216,     0,   217,     0,     0,
       0,     0,   218,     0,   219,    53,    54,     0,     0,     0,
       0,   215,     0,     0,    52,     0,     0,     0,   220,    56,
      57,    58,   216,     0,   217,     0,     0,     0,     0,   218,
       0,   219,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,    56,    57,    58
};

static const short int yycheck[] =
{
      60,    61,    62,    63,    44,    95,     7,     6,   113,     6,
       5,   183,    28,     5,   186,     0,     0,    12,    60,    61,
      62,    63,     6,    28,    41,     6,    42,   132,   133,    10,
     135,    15,     6,     6,    15,    38,    10,    10,    44,    45,
      41,    40,    34,    35,   149,    60,    61,    62,    63,    44,
     100,    48,    57,    93,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     195,     7,    15,   153,   111,   185,    20,   147,    93,   114,
     115,   116,   211,     6,   213,     6,    29,   211,     0,   213,
       6,   153,   221,   218,     6,     6,     9,   221,    35,    15,
      35,   221,     6,    15,    32,    41,    40,    35,   237,    43,
      40,   236,    40,   237,   239,    40,    59,   237,   153,   213,
      30,    31,   211,    32,   213,    48,   251,    48,    26,    27,
     259,   260,   221,   262,   263,   259,   260,    48,   262,   263,
     269,   270,   262,   263,    35,   269,   270,    35,   237,    35,
     270,    35,    95,    96,    35,   192,    39,   100,   238,   102,
     103,    39,   211,    35,   213,   259,   260,   211,    43,   213,
     259,   260,   221,   262,   263,   269,   238,   221,     5,    40,
     269,   270,   121,   122,   123,   124,    41,    42,   237,    16,
      17,    41,    42,   237,    24,    25,    49,    50,    51,   117,
     118,    40,   119,   120,   147,   125,   126,    34,    35,    40,
     259,   260,     4,   262,   263,   259,   260,    40,   262,   263,
     269,   270,    52,    53,    56,   269,   270,    55,    54,    29,
      22,    23,    43,    40,     9,     9,    40,   180,     1,    42,
      35,     4,   185,    35,    36,    37,    38,    10,    40,    12,
      41,    14,    44,    45,    46,    47,    19,    42,    21,    22,
      23,    42,    35,    42,    41,     7,    42,     1,    40,    39,
       4,    39,    35,    36,    37,    38,    10,    41,    12,    39,
      14,    42,     9,    42,    35,    19,     9,    21,    22,    23,
      40,    40,    39,     9,    35,    43,     1,    42,    33,     4,
      39,    35,    36,    37,    38,    10,    39,    12,     9,    14,
       9,    13,    10,    39,    19,     9,    21,    22,    23,     6,
      12,   146,    93,   180,   129,     1,    95,   128,     4,   127,
      35,    36,    37,    38,    10,   131,    12,   130,    14,   238,
      52,   150,    17,    19,    40,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,    -1,    35,
      36,    37,    38,    10,    -1,    12,    -1,    14,    -1,    -1,
      -1,    -1,    19,    -1,    21,    22,    23,    -1,    -1,    -1,
      -1,     1,    -1,    -1,     4,    -1,    -1,    -1,    35,    36,
      37,    38,    12,    -1,    14,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38
};

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
static const unsigned char yystos[] =
{
       0,    59,    60,     0,    20,    61,    62,    63,    38,     6,
      15,    64,    65,    66,    67,   124,   125,   126,   127,    63,
      35,   128,   129,   131,    35,    66,     5,    16,    17,    34,
      35,    70,    71,    72,   114,   115,   116,   118,   127,     7,
      41,    40,   130,   132,     9,    35,    35,    35,   114,    35,
      32,   129,     4,    22,    23,    35,    36,    37,    38,    40,
      44,    45,    46,    47,    80,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   117,   120,
     121,   123,    67,    68,    69,   124,    40,    39,    39,    35,
      40,   115,    40,    40,   114,    94,    97,   117,    94,    94,
      94,     6,    48,    43,    49,    50,    51,    44,    45,    30,
      31,    24,    25,    52,    53,    26,    27,    54,    55,    56,
      29,    28,    57,    43,    40,    41,    42,    10,    69,    70,
     118,    88,    89,    90,   114,     9,     9,    40,    90,     6,
      40,   114,   114,    42,   123,    35,    91,    94,    94,    94,
     100,   100,   101,   101,   102,   102,   102,   102,   103,   103,
     104,   105,   106,   107,   108,    91,    91,   122,   123,    91,
      41,    42,    35,    73,    74,   124,    73,    90,    42,    91,
     122,    42,    41,    94,     7,    39,    42,    88,    39,    10,
      74,   114,   118,   119,    10,    42,    39,     7,    42,   123,
      91,     9,    35,     9,    42,     1,    12,    14,    19,    21,
      35,    75,    76,    77,    81,    82,    83,    84,    85,    87,
      92,    95,   112,   113,   114,   120,    43,    75,    40,    40,
      86,    91,    39,    10,    76,    35,    91,    10,   109,    91,
       9,    43,    42,    42,    78,    91,    39,    39,    33,     9,
       9,    79,    75,    75,    10,    10,    10,    13,    39,     9,
      75,    10
};

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
static const unsigned char yyr1[] =
{
       0,    58,    60,    59,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    68,    68,    69,
      69,    69,    70,    70,    71,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    78,
      79,    77,    80,    81,    82,    83,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    97,    98,    99,   100,   100,   100,   100,   101,
     101,   101,   102,   102,   102,   103,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   111,   111,   112,   113,
     114,   114,   115,   116,   117,   118,   118,   118,   119,   119,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     126,   126,   127,   128,   128,   129,   130,   130,   131,   132
};

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
static const unsigned char yyr2[] =
{
       0,     2,     0,     3,     0,     1,     1,     2,     2,     0,
       1,     1,     2,     1,     2,     2,     5,     1,     2,     1,
       2,     2,     1,     1,     6,     6,     1,     2,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     7,     6,     8,     1,     1,     1,     1,     1,     8,
      13,     2,     4,     0,     1,     2,     2,     1,     3,     0,
       1,     1,     1,     3,     3,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     4,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     1,     1,     5,     5,
       1,     1,     1,     2,     1,     6,     9,     9,     2,     4,
       4,     1,     3,     0,     1,     1,     3,     0,     1,     1,
       1,     2,     3,     1,     3,     2,     0,     1,     1,     3
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
#line 94 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
									if (driver.root() == nullptr)
									{
										auto nd = new mlang::CodeCompileUnit();
										driver.root(nd);
									}
									driver.success(false);
								}
#line 1230 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 3:
#line 104 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
									if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
									{
										for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
										{
											auto file_include_nd = static_cast<mlang::CodeFileInclude*>(child_nd);
											auto search_str = file_include_nd->file_name().substr(1, file_include_nd->file_name().size() - 2);
											driver.include(search_str);
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
#line 1272 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 4:
#line 144 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = nullptr;	}
#line 1278 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 5:
#line 145 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 1284 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 6:
#line 150 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
									auto nd = new mlang::CodeObjectCollection();
									nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
									((*yyvalp).node_collection) = nd;
								}
#line 1294 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 7:
#line 156 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
									auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
									nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
									((*yyvalp).node_collection) = nd;
								}
#line 1304 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 8:
#line 165 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeFileInclude();
												nd->file_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 1314 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 9:
#line 173 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = nullptr; }
#line 1320 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 10:
#line 174 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection); }
#line 1326 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 11:
#line 178 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												((*yyvalp).node_collection) = new mlang::CodeObjectCollection();
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) != nullptr)
													((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
											}
#line 1336 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 12:
#line 184 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) != nullptr)
													((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
											}
#line 1346 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 13:
#line 192 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1352 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 14:
#line 193 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); 
											}
#line 1360 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 15:
#line 196 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto method = static_cast<mlang::CodeMemberMethod*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto x:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														method->custom_attributes().push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												((*yyvalp).node) = method;
											}
#line 1376 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 16:
#line 211 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeNamespace();
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.stringVal));
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
#line 1404 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 17:
#line 237 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												((*yyvalp).node_collection) = new mlang::CodeObjectCollection();
												((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));	
											}
#line 1413 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 18:
#line 242 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
												((*yyvalp).node_collection)->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
											}
#line 1422 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 19:
#line 249 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1428 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 20:
#line 250 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1434 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 21:
#line 251 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1440 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 22:
#line 255 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1446 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 23:
#line 256 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1452 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 24:
#line 261 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeTypeDeclaration();
												nd->location(driver.get_location((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yyloc)));
												
												nd->is_class(true);
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															nd->members()->push_back(static_cast<mlang::CodeTypeMember*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												((*yyvalp).node) = nd;
											}
#line 1476 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 25:
#line 284 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeTypeDeclaration();
												nd->is_struct(true);
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														if (child_nd != nullptr)
														{
															nd->members()->push_back(static_cast<mlang::CodeTypeMember*>(child_nd));
															child_nd->parent(nd);
														}
													}
												}
												((*yyvalp).node) = nd;
											}
#line 1498 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 26:
#line 304 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1508 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 27:
#line 310 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1518 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 28:
#line 319 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto method = static_cast<mlang::CodeMemberMethod*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto x:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														method->custom_attributes().push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												((*yyvalp).node) = method;
											}
#line 1534 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 29:
#line 330 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												// this generates 1 conflict
												auto field = static_cast<mlang::CodeMemberMethod*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto x:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection))
													{
														field->custom_attributes().push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												((*yyvalp).node) = field;
											}
#line 1551 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 30:
#line 345 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1561 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 31:
#line 350 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);	
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) != nullptr)
												{
													nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												}
												((*yyvalp).node_collection) = nd;
											}
#line 1574 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 32:
#line 361 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1580 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 33:
#line 362 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1586 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 34:
#line 363 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1592 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 35:
#line 364 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1598 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 36:
#line 365 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1604 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 37:
#line 366 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												// this one causes 6 shift/reduce conflicts.
												// adding an extra term could help eg. ';'
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	
											}
#line 1614 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 38:
#line 371 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = nullptr; }
#line 1620 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 39:
#line 375 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												driver.scanner()->begin_block();	
											}
#line 1628 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 40:
#line 378 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												driver.scanner()->end_block();
											}
#line 1636 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 41:
#line 381 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeIrBlockStatement();
												nd->content(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 1646 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 42:
#line 390 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeAssemblyCallExpression();
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node) != nullptr)
													nd->return_type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												
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
#line 1696 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 43:
#line 439 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeIterationStatement();
												nd->test_expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node)));
												
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
#line 1719 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 44:
#line 461 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);
											}
#line 1727 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 45:
#line 467 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1737 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 46:
#line 472 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1747 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 47:
#line 477 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1757 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 48:
#line 482 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeExpressionStatement();
												nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1767 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 49:
#line 491 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeConditionStatement();
												nd->condition(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node)));
												
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
#line 1790 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 50:
#line 510 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeConditionStatement();
												nd->condition(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval.node)));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.node_collection))
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
#line 1824 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 51:
#line 542 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeVariableDeclarationStatement();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												nd->init_expression(nullptr);
												((*yyvalp).node) = nd;
											}
#line 1836 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 52:
#line 550 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeVariableDeclarationStatement();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												nd->init_expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1848 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 53:
#line 560 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = nullptr;	}
#line 1854 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 54:
#line 561 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);
											}
#line 1862 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 55:
#line 568 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												// this generates 7 conflicts
												auto nd = new mlang::CodeMethodReturnStatement();
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) != nullptr)
												{
													nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												}
												((*yyvalp).node) = nd;
											}
#line 1876 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 56:
#line 580 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeParameterDeclarationExpression();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 1887 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 57:
#line 589 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeObjectCollection();	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1897 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 58:
#line 595 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node_collection);	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 1907 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 59:
#line 603 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = nullptr;}
#line 1913 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 60:
#line 604 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);	}
#line 1919 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 61:
#line 608 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1925 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 62:
#line 609 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1931 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 63:
#line 614 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeAssignExpression();
												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1942 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 64:
#line 621 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeAssignExpression();
												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1953 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 65:
#line 630 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1959 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 66:
#line 634 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1965 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 67:
#line 635 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1971 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 68:
#line 636 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeBinaryOperatorExpression();
												auto m_left = new mlang::CodePrimitiveExpression();
												m_left->value(new int(1));
												nd->left(m_left);
												nd->operator_(mlang::CodeBinaryOperatorType::Multiply);
												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 1985 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 69:
#line 645 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1991 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 70:
#line 646 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 1997 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 71:
#line 647 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2003 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 72:
#line 651 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2009 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 73:
#line 652 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2015 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 74:
#line 653 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2021 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 75:
#line 654 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2027 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 76:
#line 655 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2033 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 77:
#line 656 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2039 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 78:
#line 657 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2045 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 79:
#line 658 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2051 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 80:
#line 659 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2057 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 81:
#line 663 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeSizeOfExpression();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 2067 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 82:
#line 672 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeFieldReferenceExpression();
												nd->target_object(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												nd->field_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2078 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 83:
#line 682 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
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
#line 2098 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 84:
#line 701 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												 auto nd = new mlang::CodeCastExpression();
												 nd->target_type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												 nd->expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												 ((*yyvalp).node) = nd;
											}
#line 2109 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 85:
#line 710 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2115 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 86:
#line 712 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Multiply);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2127 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 87:
#line 720 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Divide);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2139 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 88:
#line 728 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Modulus);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2151 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 89:
#line 738 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2157 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 90:
#line 740 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Add);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2169 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 91:
#line 748 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Subtract);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2181 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 92:
#line 758 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2187 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 93:
#line 760 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::ShiftLeft);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2199 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 94:
#line 768 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::ShiftRight);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2211 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 95:
#line 778 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2217 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 96:
#line 780 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::LessThan);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2229 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 97:
#line 788 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::GreaterThan);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2241 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 98:
#line 796 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::LessThanOrEqual);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2253 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 99:
#line 804 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
  												auto nd = new mlang::CodeBinaryOperatorExpression();
  												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
  												nd->operator_(mlang::CodeBinaryOperatorType::GreaterThanOrEqual);
  												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
  												((*yyvalp).node) = nd;	
  											}
#line 2265 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 100:
#line 814 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2271 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 101:
#line 816 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::IdentityEquality);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2283 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 102:
#line 824 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::IdentityInEquality);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2295 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 103:
#line 834 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2301 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 104:
#line 836 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BitwiseAnd);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2313 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 105:
#line 846 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2319 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 106:
#line 848 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::Add);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2331 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 107:
#line 858 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2337 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 108:
#line 860 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BitwiseOr);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2349 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 109:
#line 870 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2355 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 110:
#line 872 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BooleanAnd);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2367 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 111:
#line 882 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2373 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 112:
#line 884 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
   												auto nd = new mlang::CodeBinaryOperatorExpression();
   												nd->left(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
   												nd->operator_(mlang::CodeBinaryOperatorType::BooleanOr);
   												nd->right(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
   												((*yyvalp).node) = nd;
   											}
#line 2385 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 113:
#line 894 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2391 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 114:
#line 896 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
  												((*yyvalp).node) = nullptr;
  											}
#line 2399 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 115:
#line 902 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												tp->base_type("Int32");
												
												nd->type(tp);
												nd->value((void*)(uint64_t*)(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integerVal));
												((*yyvalp).node) = nd;
											}
#line 2413 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 116:
#line 911 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodePrimitiveExpression();
												auto tp = new mlang::CodeTypeReference();
												tp->base_type("Double");
												
												nd->type(tp);
												nd->value(const_cast<float*>(&(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.doubleVal)));
												((*yyvalp).node) = nd;
											}
#line 2427 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 117:
#line 920 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
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
#line 2447 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 118:
#line 939 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
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
#line 2464 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 119:
#line 955 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
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
#line 2486 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 120:
#line 975 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2492 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 121:
#line 976 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node);	}
#line 2498 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 122:
#line 980 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeTypeReference();
												nd->location(driver.get_location((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc)));
												nd->base_type(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2509 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 123:
#line 990 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeTypeReference();
												nd->location(driver.get_location((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yyloc), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yyloc)));
												auto array_element_type = static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
												nd->array_element_type(array_element_type);
												nd->array_rank((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integerVal));
												nd->base_type(array_element_type->base_type() + "[]");
												((*yyvalp).node) = nd;
											}
#line 2523 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 124:
#line 1003 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeVariableReferenceExpression();
												nd->variable_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2533 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 125:
#line 1012 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
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
#line 2553 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 126:
#line 1028 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeMemberMethod();
												nd->return_type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for (auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node_collection))
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
#line 2584 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 127:
#line 1055 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeMemberMethod();
												nd->return_type(nullptr);
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for (auto child_nd:*(((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node_collection))
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
#line 2615 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 128:
#line 1084 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeMemberField();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2626 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 129:
#line 1091 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeMemberField();
												nd->type(static_cast<mlang::CodeTypeReference*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)));
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.stringVal));
												nd->init_expression(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 2638 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 130:
#line 1102 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeMethodInvokeExpression();
												
												mlang::CodeMethodReferenceExpression* method_reference_expression = nullptr;
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)->type_of(mlang::CodeObjectKind::CodeMethodReferenceExpression))
												{
													method_reference_expression = static_cast<mlang::CodeMethodReferenceExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node));
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
#line 2663 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 131:
#line 1125 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeMethodReferenceExpression();
												nd->method_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												((*yyvalp).node) = nd;
											}
#line 2673 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 132:
#line 1130 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeMethodReferenceExpression();
												nd->method_name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal));
												nd->target_object(static_cast<mlang::CodeExpression*>((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node) = nd;
											}
#line 2684 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 133:
#line 1168 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = nullptr;	}
#line 2690 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 134:
#line 1169 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 2696 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 135:
#line 1173 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = new mlang::CodeObjectCollection();
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 2706 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 136:
#line 1178 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node_collection);	
												nd->push_back((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
												((*yyvalp).node_collection) = nd;
											}
#line 2716 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 137:
#line 1186 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = nullptr;	}
#line 2722 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 138:
#line 1187 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 2728 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 139:
#line 1191 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);		}
#line 2734 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 140:
#line 1195 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeObjectCollection();
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto x:*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection))
													{
														nd->push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												((*yyvalp).node_collection) = nd;
											}
#line 2750 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 141:
#line 1207 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto x:*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection))
													{
														nd->push_back(static_cast<mlang::CodeAttributeDeclaration*>(x));
													}
												}
												((*yyvalp).node_collection) = nd;
											}
#line 2766 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 142:
#line 1222 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
											}
#line 2774 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 143:
#line 1228 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeObjectCollection();
												nd->push_back(static_cast<mlang::CodeAttributeDeclaration*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node_collection) = nd;
											}
#line 2784 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 144:
#line 1233 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												(((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node_collection)->push_back(static_cast<mlang::CodeAttributeDeclaration*>((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)));
												((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node_collection);
											}
#line 2793 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 145:
#line 1240 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												auto nd = new mlang::CodeAttributeDeclaration();
												nd->name(*(((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.stringVal));
												if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection) != nullptr)
												{
													for(auto x:*(((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection))
													{
														nd->arguments().push_back(static_cast<mlang::CodeAttributeArgument*>(x));
													}
												}
												((*yyvalp).node) = nd;
											}
#line 2810 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 146:
#line 1255 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {	((*yyvalp).node_collection) = nullptr;	}
#line 2816 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 147:
#line 1256 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node_collection);
											}
#line 2824 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 148:
#line 1262 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												((*yyvalp).stringVal) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.stringVal);
											}
#line 2832 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;

  case 149:
#line 1268 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:816
    {
												((*yyvalp).node_collection) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node_collection);
											}
#line 2840 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
    break;


#line 2844 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:816
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
          case 35: // "identifier"
#line 88 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:846
      { delete ((*yyvaluep).stringVal); }
#line 2895 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:846
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
  (!!((Yystate) == (-173)))

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
#line 16 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2270
{
  // Initialize the initial location.
  yylloc.begin.filename = yylloc.end.filename = driver.streamname();
}

#line 4336 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2270

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



#line 1273 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2584


void
yy::mlang_parser::error (const yy::mlang_parser::location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
#line 4646 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2584

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
#line 4663 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2584
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
          case 32: // "[]"
#line 89 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2584
      { yyoutput << ((*yyvaluep).integerVal); }
#line 4704 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2584
        break;

    case 35: // "identifier"
#line 87 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2584
      { yyoutput << *((*yyvaluep).stringVal); }
#line 4710 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2584
        break;

    case 36: // "integer"
#line 89 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.c:2584
      { yyoutput << ((*yyvaluep).integerVal); }
#line 4716 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2584
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
#line 4767 "/home/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.cpp" // glr.c:2584
