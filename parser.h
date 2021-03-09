/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    ARROW = 259,
    COMMA = 260,
    SEMI = 261,
    COLON = 262,
    TERNARY = 263,
    CHAIN = 264,
    PIPELINE = 265,
    DOT = 266,
    SPREAD = 267,
    PLUS = 268,
    INCREMENT = 269,
    PLUS_ASSIGN = 270,
    SUB = 271,
    DECREMENT = 272,
    SUB_ASSIGN = 273,
    MULT = 274,
    MULT_ASSIGN = 275,
    DIV = 276,
    DIV_ASSIGN = 277,
    EXP = 278,
    EXP_ASSIGN = 279,
    REM = 280,
    REM_ASSIGN = 281,
    BITWISE_NOT = 282,
    BITWISE_AND = 283,
    BITWISE_AND_ASSIGN = 284,
    BITWISE_OR = 285,
    BITWISE_OR_ASSIGN = 286,
    BITWISE_XOR = 287,
    BITWISE_XOR_ASSIGN = 288,
    LOGICAL_NOT = 289,
    LOGICAL_NULL = 290,
    LOGICAL_NULL_ASSIGN = 291,
    LOGICAL_AND = 292,
    LOGICAL_AND_ASSIGN = 293,
    LOGICAL_OR = 294,
    LOGICAL_OR_ASSIGN = 295,
    EQ = 296,
    EQ_STRICT = 297,
    INEQ = 298,
    INEQ_STRICT = 299,
    LT = 300,
    LT_EQ = 301,
    GT = 302,
    GT_EQ = 303,
    LSHIFT = 304,
    LSHIFT_ASSIGN = 305,
    RSHIFT = 306,
    RSHIFT_ASSIGN = 307,
    RSHIFT_UNSIGNED = 308,
    RSHIFT_UNSIGNED_ASSIGN = 309,
    LPAR = 310,
    RPAR = 311,
    LBRACE = 312,
    RBRACE = 313,
    LBRACKET = 314,
    RBRACKET = 315,
    INT_VAL = 316,
    REAL_VAL = 317,
    STR_VAL = 318,
    ID = 319,
    BREAK = 320,
    CASE = 321,
    CATCH = 322,
    CLASS = 323,
    CONST_RW = 324,
    CONTINUE = 325,
    DEBUGGER = 326,
    DEFAULT = 327,
    DELETE = 328,
    DO = 329,
    ELSE = 330,
    ENUM = 331,
    EXPORT = 332,
    EXTENDS = 333,
    FALSE_RW = 334,
    FINALLY = 335,
    FOR = 336,
    FUNCTION = 337,
    IF = 338,
    IMPLEMENTS = 339,
    IMPORT = 340,
    IN = 341,
    INSTANCEOF = 342,
    INTERFACE = 343,
    LET = 344,
    NEW = 345,
    NULL_RW = 346,
    PACKAGE = 347,
    PRIVATE = 348,
    PROTECTED = 349,
    PUBLIC = 350,
    RETURN = 351,
    SUPER = 352,
    SWITCH = 353,
    THIS = 354,
    THROW = 355,
    TRUE_RW = 356,
    TRY = 357,
    TYPEOF = 358,
    VAR = 359,
    VOID_RW = 360,
    WHILE = 361,
    WITH = 362,
    AWAIT = 363,
    YIELD = 364,
    STATIC = 365,
    AS = 366,
    ASYNC = 367,
    FROM = 368,
    GET = 369,
    OF = 370,
    SET = 371,
    TARGET = 372,
    ANY = 373,
    BOOLTYPE = 374,
    CONSTRUCTOR = 375,
    DECLARE = 376,
    MODULE = 377,
    REQUIRE = 378,
    NEVER = 379,
    NUMBER = 380,
    STRING = 381,
    SYMBOL = 382,
    TYPE = 383,
    UNDEFINED = 384,
    UNKNOWN = 385
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
