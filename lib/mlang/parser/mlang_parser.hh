// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison GLR parsers in C++

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

// C++ GLR parser skeleton written by Akim Demaille.

#ifndef YY_YY_USERS_MARIO_PROJECTS_MLANG_SRC_LIB_MLANG_PARSER_MLANG_PARSER_HH_INCLUDED
# define YY_YY_USERS_MARIO_PROJECTS_MLANG_SRC_LIB_MLANG_PARSER_MLANG_PARSER_HH_INCLUDED
// //                    "%code requires" blocks.
#line 5 "/Users/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.cc:339

# include <string>
# include <vector>
# include <codedom.hh>

class mlang_driver;

#line 47 "/Users/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.hh" // glr.cc:339


#include <stdexcept>
#include <string>
#include <iostream>
#include "location.hh"

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 62 "/Users/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.hh" // glr.cc:339


  /// A Bison parser.
  class mlang_parser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 24 "/Users/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.yy" // glr.cc:339

  int          	integerVal;
  float			doubleVal;
  std::string 	*stringVal;
  mlang::CodeObject* node;
  mlang::CodeObjectCollection* node_collection;

#line 81 "/Users/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.hh" // glr.cc:339
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        EOL = 258,
        NEW = 259,
        DEF = 260,
        LEFT_BRACKET = 261,
        RIGHT_BRACKET = 262,
        END_STATEMENT = 263,
        INDENT = 264,
        DEDENT = 265,
        BLOCK_END = 266,
        IF = 267,
        ELSE = 268,
        WHILE = 269,
        NAMESPACE = 270,
        CLASS = 271,
        STRUCT = 272,
        ASSIGN = 273,
        TOK_RETURN = 274,
        INCLUDE = 275,
        IR = 276,
        SIZEOF = 277,
        ASM = 278,
        OP_LESS_THAN_OR_EQUAL = 279,
        OP_GREATER_THAN_OR_EQUAL = 280,
        OP_EQUALS = 281,
        OP_NOT_EQUALS = 282,
        OP_OROR = 283,
        OP_ANDAND = 284,
        OP_SHIFT_RIGHT = 285,
        OP_SHIFT_LEFT = 286,
        RANK = 287,
        BLOCKCONTENT = 288,
        EXTERNAL = 289,
        IDENTIFIER = 290,
        INTEGER = 291,
        DOUBLE = 292,
        STRING_LITERAL = 293
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    const location_type& l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;



    /// Build a parser object.
    mlang_parser (mlang_driver& driver_yyarg);
    virtual ~mlang_parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);

  public:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

# if YYDEBUG
  public:
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
                                         const semantic_type* yyvaluep,
                                         const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
                                   const semantic_type* yyvaluep,
                                   const location_type* yylocationp);
  private:
    // Debugging.
    std::ostream* yycdebug_;
#endif


    // User arguments.
    mlang_driver& driver;
  };



#ifndef YYSTYPE
# define YYSTYPE yy::mlang_parser::semantic_type
#endif
#ifndef YYLTYPE
# define YYLTYPE yy::mlang_parser::location_type
#endif


} // yy
#line 305 "/Users/mario/Projects/mlang.src/lib/mlang/parser/mlang_parser.hh" // glr.cc:339


#endif // !YY_YY_USERS_MARIO_PROJECTS_MLANG_SRC_LIB_MLANG_PARSER_MLANG_PARSER_HH_INCLUDED
