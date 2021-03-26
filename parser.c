/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "parser.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int yylex(void);
void yyerror(char const*);

void check_var();
void new_var();
void debug(char* text);

extern char *yytext;
int yylineno;


Var_table* vt;



#line 89 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
    UNKNOWN = 385,
    E_ID = 386
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

/* Copy the second part of user declarations.  */

#line 272 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  112
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  466

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   386

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    48,    52,    53,    57,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      73,    74,    75,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   119,   120,   124,
     125,   129,   130,   131,   132,   133,   134,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   153,
     157,   158,   159,   160,   164,   165,   166,   167,   171,   172,
     173,   177,   178,   182,   183,   184,   185,   186,   187,   188,
     189,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   214,
     214,   215,   219,   223,   224,   225,   226,   230,   234,   235,
     236,   237,   238,   239,   240,   244,   245,   246,   250,   251,
     252,   256,   257,   258,   259,   260,   261,   262,   263,   267,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     284,   285,   286,   287,   288,   289,   293,   294,   295,   299,
     300,   301,   305,   306,   307,   308,   309,   310,   311,   315,
     319,   320,   321,   322,   323,   324,   328,   329,   330,   331,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   350,   354,   355,   356,   357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "ARROW", "COMMA", "SEMI",
  "COLON", "TERNARY", "CHAIN", "PIPELINE", "DOT", "SPREAD", "PLUS",
  "INCREMENT", "PLUS_ASSIGN", "SUB", "DECREMENT", "SUB_ASSIGN", "MULT",
  "MULT_ASSIGN", "DIV", "DIV_ASSIGN", "EXP", "EXP_ASSIGN", "REM",
  "REM_ASSIGN", "BITWISE_NOT", "BITWISE_AND", "BITWISE_AND_ASSIGN",
  "BITWISE_OR", "BITWISE_OR_ASSIGN", "BITWISE_XOR", "BITWISE_XOR_ASSIGN",
  "LOGICAL_NOT", "LOGICAL_NULL", "LOGICAL_NULL_ASSIGN", "LOGICAL_AND",
  "LOGICAL_AND_ASSIGN", "LOGICAL_OR", "LOGICAL_OR_ASSIGN", "EQ",
  "EQ_STRICT", "INEQ", "INEQ_STRICT", "LT", "LT_EQ", "GT", "GT_EQ",
  "LSHIFT", "LSHIFT_ASSIGN", "RSHIFT", "RSHIFT_ASSIGN", "RSHIFT_UNSIGNED",
  "RSHIFT_UNSIGNED_ASSIGN", "LPAR", "RPAR", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "INT_VAL", "REAL_VAL", "STR_VAL", "ID", "BREAK", "CASE",
  "CATCH", "CLASS", "CONST_RW", "CONTINUE", "DEBUGGER", "DEFAULT",
  "DELETE", "DO", "ELSE", "ENUM", "EXPORT", "EXTENDS", "FALSE_RW",
  "FINALLY", "FOR", "FUNCTION", "IF", "IMPLEMENTS", "IMPORT", "IN",
  "INSTANCEOF", "INTERFACE", "LET", "NEW", "NULL_RW", "PACKAGE", "PRIVATE",
  "PROTECTED", "PUBLIC", "RETURN", "SUPER", "SWITCH", "THIS", "THROW",
  "TRUE_RW", "TRY", "TYPEOF", "VAR", "VOID_RW", "WHILE", "WITH", "AWAIT",
  "YIELD", "STATIC", "AS", "ASYNC", "FROM", "GET", "OF", "SET", "TARGET",
  "ANY", "BOOLTYPE", "CONSTRUCTOR", "DECLARE", "MODULE", "REQUIRE",
  "NEVER", "NUMBER", "STRING", "SYMBOL", "TYPE", "UNDEFINED", "UNKNOWN",
  "E_ID", "$accept", "line", "stmt-list", "stmt", "$@1", "assign-expr",
  "for-stmt", "assignment", "do-while-stmt", "while-stmt", "if-stmt",
  "logic-expr", "class-def", "class-att-list", "class-att", "access-modif",
  "func-def", "params", "var-declr", "id-list", "$@2", "obj-def",
  "obj-att-list", "obj-att", "var-type", "expr", "idx-unsafe-expr",
  "idx-safe-expr", "vet-idx", "unary-expr", "arit-expr", "bitw-expr",
  "shift-expr", "var-att", "var-met", "args-list", "var-obj", "var-val",
  "array-expr", "elmts-list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386
};
# endif

#define YYPACT_NINF -254

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-254)))

#define YYTABLE_NINF -180

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     931,   -41,   179,   -35,  1254,  1254,  1254,   233,  -254,  -254,
    -254,  1351,    24,   -25,   -12,    53,    38,  -254,    15,    37,
      54,    46,    47,  -254,   492,  -254,    48,    61,  -254,   117,
     931,  -254,   113,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  1540,  -254,  -254,   631,  -254,  -254,  -254,  -254,  1435,
     134,  -254,  -254,  -254,    13,   136,  -254,  -254,  -254,  -254,
    -254,    13,   136,    44,  -254,  -254,    39,  -254,  1755,   233,
     148,    96,  -254,    93,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,   710,  -254,
    -254,  -254,    17,  1254,  1254,  -254,   102,    29,   158,  -254,
     931,    -4,   108,  1273,    41,   163,   -18,  -254,  1584,    59,
     165,  1273,  -254,  -254,  -254,   166,  -254,  1254,  1254,  1254,
    1254,  1254,  1254,  1254,  1254,  1254,  1254,  1254,  1254,  1254,
    1254,  1254,  1254,  1254,  1254,  1254,  1254,  1254,  1254,  1254,
    1254,   109,  -254,  -254,  1254,   118,    17,  -254,  -254,   233,
    -254,    13,   136,   134,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,   137,   139,    17,   176,  1496,   130,  2145,   127,  2145,
      20,   214,   186,   990,   138,   613,  1389,   191,   192,   631,
    1466,    -1,   167,  1794,   214,   990,   214,    17,  -254,   214,
     990,   175,  1833,  -254,    22,    22,   210,   210,   210,   210,
     472,   211,   342,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   408,   408,   408,  2145,   180,  -254,
    2145,    13,   136,   181,  -254,   189,  -254,    17,    17,   235,
    -254,    20,    14,  -254,  -254,  -254,   190,   241,   195,    16,
     197,     9,  -254,  2145,   144,  1009,  1628,   627,   696,   201,
      97,   198,   196,   199,    32,  -254,  2145,   219,   212,    35,
    -254,  2145,   216,   222,  -254,    17,  -254,  -254,  -254,   214,
      -1,  -254,    20,   263,  1254,   221,   266,  -254,     9,   275,
     225,   279,   230,   229,   232,  1872,  1062,  1081,  1672,  1095,
    1716,   282,   226,   214,    10,   931,   931,  1254,   231,   238,
    -254,  1254,   237,   931,   931,   242,  -254,   243,  -254,   214,
    2145,   297,  -254,   213,  -254,     9,  1273,   931,   245,   249,
     250,   252,  1911,   254,   257,  1950,  1150,   258,   260,  1989,
    1201,   214,   310,   315,   214,   931,   268,   273,  2145,   332,
      17,  2145,   333,   285,   287,  -254,    33,  -254,  1254,  -254,
    -254,   281,  2028,   288,   931,   931,   931,   291,   292,   931,
     293,   294,   296,   298,  2067,   931,   300,   302,   303,   308,
    2106,  -254,   214,   309,   318,   314,   299,   301,  1254,   322,
    1254,  -254,  -254,   214,   931,  2145,  -254,  -254,  -254,   327,
     328,   329,   931,   931,   330,   931,   931,   931,   335,   337,
     331,   931,   931,   931,   339,   340,  -254,   383,   931,  -254,
     789,   860,  2145,  -254,  2145,   343,   341,  -254,  -254,  -254,
     344,   345,  -254,   348,   349,   351,   931,   931,  -254,   356,
     358,   359,   931,   931,   214,   361,   931,  -254,   931,  -254,
     931,  -254,  -254,  -254,  -254,  -254,  -254,   362,   367,  -254,
    -254,  -254,   368,   374,  -254,  -254,   401,   405,   406,  -254,
    -254,  -254,  -254,  -254,  -254,  -254
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,   206,   190,   191,
     192,   148,     0,     0,     0,     0,     0,   194,     0,     0,
       0,     0,     0,   200,     0,   193,     0,     0,   201,     0,
       2,     5,     0,    15,    14,    13,    12,   139,     9,     8,
       6,     0,   136,   135,   147,   146,   143,   144,   145,   142,
       0,   140,   141,   138,   150,   151,   195,   196,   197,   199,
     198,   152,   153,   148,   159,   147,   142,   158,     0,   206,
     205,     0,    41,     0,   154,    45,   156,    46,    47,    48,
      49,    50,    51,    52,    53,    42,    43,    44,     0,    54,
      55,    56,   185,     0,     0,    18,     0,   119,     0,    19,
       3,     0,     0,     0,   121,   101,     0,    16,     0,   121,
     108,     0,     1,     4,    11,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   157,     0,     0,   185,   137,   203,   206,
     202,   178,   172,   174,   133,   132,   131,   134,   128,   129,
     130,     0,    72,   185,   184,   183,     0,     0,   135,    21,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,     0,     0,     0,     0,   185,    17,     0,
       0,     0,     0,     7,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    76,    77,    78,    67,    68,    69,    70,
      71,    73,    74,    75,   169,   170,   171,    22,   173,   177,
      20,   175,   176,     0,   204,     0,   180,   185,   185,   186,
     149,    83,     0,    89,    90,    88,     0,    82,     0,     0,
       0,   126,   118,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   103,   102,     0,     0,   111,
     110,   109,     0,     0,   179,   185,   182,   181,    80,     0,
     100,    79,    83,     0,     0,     0,   121,   120,   126,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     3,     3,     0,     0,     0,
     188,     0,     0,     3,     3,     0,    84,     0,    81,     0,
     116,     0,   123,     0,   122,   126,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    98,     0,     3,     0,     0,   105,   106,
     185,   112,   113,     0,     0,   187,     0,    85,     0,   127,
     124,     0,     0,     0,     3,     3,     3,     0,     0,     3,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,    64,    61,     0,     0,
       0,    60,    59,     0,     3,   117,    58,    57,    40,     0,
       0,     0,     3,     3,     0,     3,     3,     3,     0,     0,
       0,     3,     3,     3,     0,     0,    99,    97,     3,    91,
       0,     0,   107,   189,   114,     0,     0,    39,    38,    37,
       0,     0,    28,     0,     0,     0,     3,     3,    34,     0,
       0,     0,     3,     3,     0,     0,     3,    66,     3,    63,
       3,    86,    36,    35,    27,    26,    25,     0,     0,    33,
      32,    31,     0,     0,    96,    92,     0,     0,     0,    24,
      23,    30,    29,    65,    62,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -254,   177,  -254,   -30,  -254,   312,  -254,   -29,  -254,  -254,
    -254,  -254,  -254,  -215,  -254,  -254,  -254,   131,   364,   -15,
    -254,  -136,  -253,  -254,    -6,    82,  -254,   373,   317,  -254,
    -254,  -254,  -254,     4,   -70,  -145,  -254,     5,  -254,   -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,   115,    32,    33,    94,    34,    35,
      36,    37,    38,   236,   237,   238,    39,   251,    40,    98,
     172,   242,   280,   281,   161,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   166,    51,    52,    53,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,   223,   175,   153,   249,    55,   105,    62,    66,    66,
      66,   110,    70,   148,   278,   140,   268,   334,   226,   274,
     144,   269,   163,    54,    73,   312,   231,   186,    66,    61,
      95,     1,  -121,     2,     3,   297,   171,   187,   301,    96,
     383,   119,   258,   120,     4,   121,  -119,   122,   184,   255,
     141,     5,    97,   142,   260,    73,   143,   308,    74,    99,
     176,    76,   350,   250,  -119,    14,   189,   335,   146,   270,
     101,   219,     6,   279,    70,   275,     7,   152,     8,     9,
      10,    11,   266,   267,   232,    21,    64,    67,    68,    88,
     384,   298,    66,   224,   302,   100,    17,    66,    66,    92,
      26,   102,   292,    93,   293,   180,   108,    22,    23,   103,
     104,   106,   109,   233,   234,   235,   111,   112,    25,   114,
     305,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,   145,    28,   141,    66,   222,
     140,   144,   117,   149,    70,   118,   150,   151,   119,   170,
     120,   173,   121,   181,   122,   239,   185,   123,   190,   124,
     162,   125,   193,   218,   165,   167,   169,    66,   254,    66,
     257,   227,   221,   259,   225,   183,   229,   230,   137,    66,
     138,   240,   139,   192,    66,   379,   244,   247,   248,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   252,   117,   277,   220,   118,   165,     2,
     119,   262,   120,   121,   121,   146,   122,   264,    69,   123,
      56,    57,    58,   125,   265,   165,  -179,   272,   271,     2,
     282,    66,    66,   295,   294,   243,   296,   246,    59,   273,
     137,   276,   138,   306,   139,   291,   299,   256,   300,   165,
     309,  -119,   261,   303,     8,     9,    10,   174,    66,   304,
      60,   311,   313,   314,   315,   316,   317,   333,   318,   331,
     332,   339,    17,   340,     8,     9,    10,   342,   345,   346,
     348,    66,   354,   347,    23,    66,   355,   356,   357,   165,
     165,   359,    17,   360,    25,   365,   366,   372,   349,   154,
     373,    65,    65,    65,    23,   371,   376,   285,   374,   288,
     290,   377,   155,   156,    25,   378,   380,   386,   157,   158,
     159,    65,    28,   381,   160,   382,   388,   165,   392,   393,
     395,   396,    66,   397,   398,   117,   310,   401,   118,   402,
     403,   119,    28,   120,   404,   121,   406,   122,   322,   325,
     123,   329,   409,   407,   410,   408,   411,   415,   413,   338,
     437,   439,    66,   341,    66,   417,   418,   419,   422,   428,
     434,   137,   426,   138,   427,   139,   432,   433,   352,   441,
     440,   307,   442,   443,   164,    65,   444,   445,   364,   446,
      65,    65,   370,   177,   449,   182,   450,   451,   179,   455,
     459,   117,   165,   191,   118,   460,   461,   119,   454,   120,
     385,   121,   462,   122,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,   164,   463,
     412,    65,   414,   464,   465,   178,   168,     0,     0,     0,
       0,     0,   336,   337,     0,   164,     0,     0,     0,     0,
     343,   344,     0,     0,     0,   117,     0,     0,   118,     0,
      65,   119,    65,   120,   353,   121,     0,   122,   107,   164,
       0,     0,    65,     0,     0,     0,     1,    65,     2,     3,
       0,     0,   375,     0,     0,     0,     0,     0,     0,     4,
       0,   137,     0,   138,     0,   139,     5,     0,     0,     0,
       0,   389,   390,   391,     0,     0,   394,     0,     0,   164,
     164,     0,   400,     0,     0,     0,     0,     6,     0,     0,
       0,     7,     0,     8,     9,    10,    63,   284,     0,     0,
       0,   416,     0,     0,    65,    65,     0,     0,     0,   420,
     421,    17,   423,   424,   425,     0,     0,   164,   429,   430,
     431,     0,    22,    23,     0,   435,     0,     0,     0,     0,
       0,    65,     0,    25,     0,     0,     0,     0,   321,   324,
       0,   328,     0,   447,   448,     0,     0,     0,     0,   452,
     453,     0,     0,   456,    65,   457,     0,   458,    65,   245,
       0,    28,     0,     0,     0,     0,     0,     1,   351,     2,
       3,     0,     0,   287,    72,     0,     0,     0,   363,     0,
       4,     1,   369,     2,     3,     0,    75,     5,     0,    77,
       0,    78,   164,    79,     4,    80,     0,    81,     0,     0,
      82,     5,    83,     0,    84,    65,     0,    85,     6,    86,
       0,    87,     7,     0,     8,     9,    10,    63,     0,     0,
       0,    89,     6,    90,     0,    91,     7,     0,     8,     9,
      10,    63,    17,     0,     0,    65,     0,    65,     0,     0,
       0,     0,   289,    22,    23,     0,    17,     0,     0,     0,
       1,     0,     2,     3,    25,     0,     0,    22,    23,     0,
       0,     0,     0,     4,     1,     0,     2,     3,    25,     0,
       5,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,    28,     0,     5,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     7,    28,     8,     9,    10,
      63,     0,     0,     0,     0,     6,     0,     0,     0,     7,
       0,     8,     9,    10,    63,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,    17,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
      22,    23,     0,     1,     0,     2,     3,     0,     0,     0,
       0,    25,     0,     0,     0,   154,     4,     0,     0,     0,
       0,     0,     0,     5,     0,    28,     0,     0,   155,   156,
       0,     0,     0,     0,   157,   158,   159,     0,     0,    28,
     160,     0,     0,     0,     6,     0,   436,     0,     7,     0,
       8,     9,    10,    11,    12,     0,     0,    13,    14,    15,
       0,     0,     0,    16,     0,     0,     0,     0,    17,     0,
      18,    19,    20,     0,     1,     0,     2,     3,    21,    22,
      23,     0,     0,     0,     0,    24,     0,     4,     0,     0,
      25,     0,     0,    26,     5,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,   438,    28,     7,
       0,     8,     9,    10,    11,    12,     0,     0,    13,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,    17,
       0,    18,    19,    20,     0,     1,     0,     2,     3,    21,
      22,    23,     0,     0,     0,     0,    24,     0,     4,     0,
       0,    25,     0,     0,    26,     5,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     0,    28,
       7,     0,     8,     9,    10,    11,    12,     0,     0,    13,
      14,    15,     0,     0,     1,    16,     2,     3,     0,     0,
      17,     0,    18,    19,    20,     0,     0,     4,     0,     0,
      21,    22,    23,     1,     5,     2,     3,    24,     0,     0,
       0,     0,    25,     0,     0,    26,     4,    27,     0,     0,
       0,     0,     0,     5,     0,     6,     0,   241,     0,     7,
       0,     8,     9,    10,    63,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     6,   283,     0,     0,     7,    17,
       8,     9,    10,    11,     0,     0,     1,     0,     2,     3,
      22,    23,     0,     0,     0,     0,     0,     0,    17,     4,
       0,    25,     0,     0,     0,     1,     5,     2,     3,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     4,     1,
      25,     2,     3,     0,     0,     5,     0,     6,   320,    28,
       0,     7,     4,     8,     9,    10,    11,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     6,   323,    28,     0,
       7,    17,     8,     9,    10,    11,     0,     0,     0,     0,
       6,   327,    22,    23,     7,     0,     8,     9,    10,    11,
      17,     0,     0,    25,     1,     0,     2,     3,     0,     0,
       0,    22,    23,     0,    17,     0,     0,     4,     0,     0,
       0,     0,    25,     0,     5,    22,    23,     0,     0,     0,
       0,    28,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     6,   362,     0,     0,     7,
      28,     8,     9,    10,    11,     1,     0,     2,     3,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     4,    17,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     6,   368,     0,     0,
       7,     0,     8,     9,    10,    11,     0,     0,     1,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     0,    28,
      17,     4,     0,     0,     0,     0,     0,     1,     5,     2,
       3,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    25,     0,     0,     0,     0,     5,     0,     6,
       0,     0,     0,     7,     0,     8,     9,    10,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
      28,     0,     7,    17,     8,     9,    10,    11,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,    17,     0,    72,    25,     0,     0,     0,     0,
       0,     0,    73,    22,    23,    74,    75,     0,    76,    77,
       0,    78,     0,    79,    25,    80,     0,    81,     0,     0,
      82,     0,    83,    28,    84,     0,     0,    85,     0,    86,
       0,    87,    72,     0,     0,     0,    88,     0,     0,     0,
      73,    89,    28,    90,    75,    91,    92,    77,     0,    78,
      93,    79,     0,    80,     0,    81,     0,     0,    82,     0,
      83,     0,    84,     0,     0,    85,     0,    86,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    89,
       0,    90,     0,    91,   146,     0,   141,     0,    93,   142,
      75,     0,   143,    77,     0,    78,     0,    79,     0,    80,
       0,    81,     0,     0,    82,     0,    83,     0,    84,    72,
       0,    85,     0,    86,     0,    87,     0,   141,     0,     0,
       0,    75,     0,     0,    77,    89,    78,    90,    79,    91,
      80,     0,    81,     0,     0,    82,     0,    83,     0,    84,
       0,   228,    85,     0,    86,     0,    87,     0,     0,   117,
       0,     0,   118,     0,     0,   119,    89,   120,    90,   121,
      91,   122,     0,     0,   123,     0,   124,     0,   125,     0,
       0,   126,     0,   127,     0,   128,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   116,   138,     0,   139,
       0,     0,     0,   117,     0,     0,   118,     0,     0,   119,
       0,   120,     0,   121,     0,   122,     0,     0,   123,     0,
     124,     0,   125,     0,     0,   126,     0,   127,     0,   128,
       0,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     188,   138,     0,   139,     0,     0,     0,   117,     0,     0,
     118,     0,     0,   119,     0,   120,     0,   121,     0,   122,
       0,     0,   123,     0,   124,     0,   125,     0,     0,   126,
       0,   127,     0,   128,     0,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   286,   138,     0,   139,     0,     0,
       0,   117,     0,     0,   118,     0,     0,   119,     0,   120,
       0,   121,     0,   122,     0,     0,   123,     0,   124,     0,
     125,     0,     0,   126,     0,   127,     0,   128,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   326,   138,
       0,   139,     0,     0,     0,   117,     0,     0,   118,     0,
       0,   119,     0,   120,     0,   121,     0,   122,     0,     0,
     123,     0,   124,     0,   125,     0,     0,   126,     0,   127,
       0,   128,     0,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   330,   138,     0,   139,     0,     0,     0,   117,
       0,     0,   118,     0,     0,   119,     0,   120,     0,   121,
       0,   122,     0,     0,   123,     0,   124,     0,   125,     0,
       0,   126,     0,   127,     0,   128,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,   138,   117,   139,
       0,   118,     0,     0,   119,     0,   120,     0,   121,     0,
     122,     0,     0,   123,     0,   124,     0,   125,     0,     0,
     126,     0,   127,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,   138,   117,   139,     0,
     118,   147,     0,   119,     0,   120,     0,   121,     0,   122,
       0,     0,   123,     0,   124,     0,   125,     0,     0,   126,
       0,   127,     0,   128,     0,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,   138,   117,   139,     0,   118,
     253,     0,   119,     0,   120,     0,   121,     0,   122,     0,
       0,   123,     0,   124,     0,   125,     0,     0,   126,     0,
     127,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,   138,   117,   139,     0,   118,   263,
       0,   119,     0,   120,     0,   121,     0,   122,     0,     0,
     123,     0,   124,     0,   125,     0,     0,   126,     0,   127,
       0,   128,     0,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,   138,   117,   139,     0,   118,   319,     0,
     119,     0,   120,     0,   121,     0,   122,     0,     0,   123,
       0,   124,     0,   125,     0,     0,   126,     0,   127,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,   138,   117,   139,     0,   118,   358,     0,   119,
       0,   120,     0,   121,     0,   122,     0,     0,   123,     0,
     124,     0,   125,     0,     0,   126,     0,   127,     0,   128,
       0,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,   138,   117,   139,     0,   118,   361,     0,   119,     0,
     120,     0,   121,     0,   122,     0,     0,   123,     0,   124,
       0,   125,     0,     0,   126,     0,   127,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
     138,   117,   139,     0,   118,   367,     0,   119,     0,   120,
       0,   121,     0,   122,     0,     0,   123,     0,   124,     0,
     125,     0,     0,   126,     0,   127,     0,   128,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,   138,
     117,   139,     0,   118,   387,     0,   119,     0,   120,     0,
     121,     0,   122,     0,     0,   123,     0,   124,     0,   125,
       0,     0,   126,     0,   127,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,   138,   117,
     139,     0,   118,   399,     0,   119,     0,   120,     0,   121,
       0,   122,     0,     0,   123,     0,   124,     0,   125,     0,
       0,   126,     0,   127,     0,   128,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,   138,   117,   139,
       0,   118,   405,     0,   119,     0,   120,     0,   121,     0,
     122,     0,     0,   123,     0,   124,     0,   125,     0,     0,
     126,     0,   127,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,   138,     0,   139
};

static const yytype_int16 yycheck[] =
{
      30,   146,     6,    73,     5,     1,    21,     3,     4,     5,
       6,    26,     7,    69,     5,    44,   231,     7,   163,     3,
      49,     7,     5,    64,    11,   278,     6,    45,    24,    64,
       6,    14,     3,    16,    17,     3,     7,    55,     3,    64,
       7,    19,   187,    21,    27,    23,     5,    25,     7,   185,
      11,    34,    64,    14,   190,    11,    17,   272,    14,     6,
      64,    17,   315,    64,     5,    69,     7,    57,    55,    55,
      55,   141,    55,    64,    69,    59,    59,    73,    61,    62,
      63,    64,   227,   228,    64,    89,     4,     5,     6,    45,
      57,    59,    88,   149,    59,    57,    79,    93,    94,    55,
     104,    64,     5,    59,     7,   101,    24,    90,    91,    55,
      64,    64,    64,    93,    94,    95,    55,     0,   101,     6,
     265,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    11,   129,    11,   144,   145,
     179,   180,    13,     5,   149,    16,    60,    64,    19,    57,
      21,     3,    23,    55,    25,   171,     3,    28,     3,    30,
      88,    32,     6,    64,    92,    93,    94,   173,   184,   175,
     186,     5,    64,   189,    47,   103,    56,    60,    49,   185,
      51,     5,    53,   111,   190,   340,    58,     6,     6,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    56,    13,   240,   144,    16,   146,    16,
      19,    56,    21,    23,    23,    55,    25,    56,     5,    28,
      61,    62,    63,    32,    55,   163,    11,     6,    58,    16,
     106,   247,   248,    57,    56,   173,    57,   175,    79,    64,
      49,    64,    51,   269,    53,    64,    47,   185,    56,   187,
       7,     5,   190,    57,    61,    62,    63,   100,   274,    57,
     101,    60,     7,    58,     5,    55,    57,   293,    56,     7,
      64,    60,    79,    55,    61,    62,    63,    60,    56,    56,
       3,   297,    57,   309,    91,   301,    57,    57,    56,   227,
     228,    57,    79,    56,   101,    57,    56,     7,   313,   105,
       5,     4,     5,     6,    91,   331,    58,   245,   334,   247,
     248,    58,   118,   119,   101,     3,     3,    56,   124,   125,
     126,    24,   129,    58,   130,    58,    58,   265,    57,    57,
      57,    57,   348,    57,    56,    13,   274,    57,    16,    57,
      57,    19,   129,    21,    56,    23,   372,    25,   286,   287,
      28,   289,    58,    64,    75,    57,    75,   383,    56,   297,
     410,   411,   378,   301,   380,    58,    58,    58,    58,    58,
       7,    49,    57,    51,    57,    53,    57,    57,   316,    58,
      57,   270,    58,    58,    92,    88,    58,    58,   326,    58,
      93,    94,   330,   101,    58,   103,    58,    58,   101,    58,
      58,    13,   340,   111,    16,    58,    58,    19,   434,    21,
     348,    23,    58,    25,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   146,    58,
     378,   144,   380,    58,    58,   101,    93,    -1,    -1,    -1,
      -1,    -1,   295,   296,    -1,   163,    -1,    -1,    -1,    -1,
     303,   304,    -1,    -1,    -1,    13,    -1,    -1,    16,    -1,
     173,    19,   175,    21,   317,    23,    -1,    25,     6,   187,
      -1,    -1,   185,    -1,    -1,    -1,    14,   190,    16,    17,
      -1,    -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    49,    -1,    51,    -1,    53,    34,    -1,    -1,    -1,
      -1,   354,   355,   356,    -1,    -1,   359,    -1,    -1,   227,
     228,    -1,   365,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    59,    -1,    61,    62,    63,    64,   245,    -1,    -1,
      -1,   384,    -1,    -1,   247,   248,    -1,    -1,    -1,   392,
     393,    79,   395,   396,   397,    -1,    -1,   265,   401,   402,
     403,    -1,    90,    91,    -1,   408,    -1,    -1,    -1,    -1,
      -1,   274,    -1,   101,    -1,    -1,    -1,    -1,   286,   287,
      -1,   289,    -1,   426,   427,    -1,    -1,    -1,    -1,   432,
     433,    -1,    -1,   436,   297,   438,    -1,   440,   301,     6,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    14,   316,    16,
      17,    -1,    -1,     6,     3,    -1,    -1,    -1,   326,    -1,
      27,    14,   330,    16,    17,    -1,    15,    34,    -1,    18,
      -1,    20,   340,    22,    27,    24,    -1,    26,    -1,    -1,
      29,    34,    31,    -1,    33,   348,    -1,    36,    55,    38,
      -1,    40,    59,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    50,    55,    52,    -1,    54,    59,    -1,    61,    62,
      63,    64,    79,    -1,    -1,   378,    -1,   380,    -1,    -1,
      -1,    -1,     6,    90,    91,    -1,    79,    -1,    -1,    -1,
      14,    -1,    16,    17,   101,    -1,    -1,    90,    91,    -1,
      -1,    -1,    -1,    27,    14,    -1,    16,    17,   101,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,   129,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,   129,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      -1,    61,    62,    63,    64,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      90,    91,    -1,    14,    -1,    16,    17,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,   105,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,   129,    -1,    -1,   118,   119,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
     130,    -1,    -1,    -1,    55,    -1,    57,    -1,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    -1,    14,    -1,    16,    17,    89,    90,
      91,    -1,    -1,    -1,    -1,    96,    -1,    27,    -1,    -1,
     101,    -1,    -1,   104,    34,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    57,   129,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    79,
      -1,    81,    82,    83,    -1,    14,    -1,    16,    17,    89,
      90,    91,    -1,    -1,    -1,    -1,    96,    -1,    27,    -1,
      -1,   101,    -1,    -1,   104,    34,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,   129,
      59,    -1,    61,    62,    63,    64,    65,    -1,    -1,    68,
      69,    70,    -1,    -1,    14,    74,    16,    17,    -1,    -1,
      79,    -1,    81,    82,    83,    -1,    -1,    27,    -1,    -1,
      89,    90,    91,    14,    34,    16,    17,    96,    -1,    -1,
      -1,    -1,   101,    -1,    -1,   104,    27,   106,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    55,    -1,    57,    -1,    59,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    55,    56,    -1,    -1,    59,    79,
      61,    62,    63,    64,    -1,    -1,    14,    -1,    16,    17,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    79,    27,
      -1,   101,    -1,    -1,    -1,    14,    34,    16,    17,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    14,
     101,    16,    17,    -1,    -1,    34,    -1,    55,    56,   129,
      -1,    59,    27,    61,    62,    63,    64,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,   129,    -1,
      59,    79,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      55,    56,    90,    91,    59,    -1,    61,    62,    63,    64,
      79,    -1,    -1,   101,    14,    -1,    16,    17,    -1,    -1,
      -1,    90,    91,    -1,    79,    -1,    -1,    27,    -1,    -1,
      -1,    -1,   101,    -1,    34,    90,    91,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    59,
     129,    61,    62,    63,    64,    14,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    27,    79,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    -1,    -1,    14,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
      79,    27,    -1,    -1,    -1,    -1,    -1,    14,    34,    16,
      17,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,   101,    -1,    -1,    -1,    -1,    34,    -1,    55,
      -1,    -1,    -1,    59,    -1,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
     129,    -1,    59,    79,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,     3,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    90,    91,    14,    15,    -1,    17,    18,
      -1,    20,    -1,    22,   101,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,   129,    33,    -1,    -1,    36,    -1,    38,
      -1,    40,     3,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      11,    50,   129,    52,    15,    54,    55,    18,    -1,    20,
      59,    22,    -1,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    33,    -1,    -1,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    50,
      -1,    52,    -1,    54,    55,    -1,    11,    -1,    59,    14,
      15,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    33,     3,
      -1,    36,    -1,    38,    -1,    40,    -1,    11,    -1,    -1,
      -1,    15,    -1,    -1,    18,    50,    20,    52,    22,    54,
      24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,    33,
      -1,     5,    36,    -1,    38,    -1,    40,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    19,    50,    21,    52,    23,
      54,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     6,    51,    -1,    53,
      -1,    -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    -1,    -1,    35,    -1,    37,    -1,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       6,    51,    -1,    53,    -1,    -1,    -1,    13,    -1,    -1,
      16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    -1,    -1,    35,
      -1,    37,    -1,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     6,    51,    -1,    53,    -1,    -1,
      -1,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     6,    51,
      -1,    53,    -1,    -1,    -1,    13,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    -1,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    -1,    -1,    35,    -1,    37,
      -1,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     6,    51,    -1,    53,    -1,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    13,    53,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,    -1,
      35,    -1,    37,    -1,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    13,    53,    -1,
      16,    56,    -1,    19,    -1,    21,    -1,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    -1,    -1,    35,
      -1,    37,    -1,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    13,    53,    -1,    16,
      56,    -1,    19,    -1,    21,    -1,    23,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    -1,    -1,    35,    -1,
      37,    -1,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    13,    53,    -1,    16,    56,
      -1,    19,    -1,    21,    -1,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    -1,    -1,    35,    -1,    37,
      -1,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    13,    53,    -1,    16,    56,    -1,
      19,    -1,    21,    -1,    23,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    -1,    -1,    35,    -1,    37,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    13,    53,    -1,    16,    56,    -1,    19,
      -1,    21,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    -1,    -1,    35,    -1,    37,    -1,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    13,    53,    -1,    16,    56,    -1,    19,    -1,
      21,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    13,    53,    -1,    16,    56,    -1,    19,    -1,    21,
      -1,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      13,    53,    -1,    16,    56,    -1,    19,    -1,    21,    -1,
      23,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    13,
      53,    -1,    16,    56,    -1,    19,    -1,    21,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    13,    53,
      -1,    16,    56,    -1,    19,    -1,    21,    -1,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,    -1,
      35,    -1,    37,    -1,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    16,    17,    27,    34,    55,    59,    61,    62,
      63,    64,    65,    68,    69,    70,    74,    79,    81,    82,
      83,    89,    90,    91,    96,   101,   104,   106,   129,   133,
     134,   135,   137,   138,   140,   141,   142,   143,   144,   148,
     150,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   168,   169,   170,    64,   165,    61,    62,    63,    79,
     101,    64,   165,    64,   157,   160,   165,   157,   157,     5,
     169,   171,     3,    11,    14,    15,    17,    18,    20,    22,
      24,    26,    29,    31,    33,    36,    38,    40,    45,    50,
      52,    54,    55,    59,   139,     6,    64,    64,   151,     6,
      57,    55,    64,    55,    64,   151,    64,     6,   157,    64,
     151,    55,     0,   135,     6,   136,     6,    13,    16,    19,
      21,    23,    25,    28,    30,    32,    35,    37,    39,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    51,    53,
     139,    11,    14,    17,   139,    11,    55,    56,   171,     5,
      60,    64,   165,   166,   105,   118,   119,   124,   125,   126,
     130,   156,   157,     5,   137,   157,   167,   157,   159,   157,
      57,     7,   152,     3,   133,     6,    64,   137,   150,   160,
     165,    55,   137,   157,     7,     3,    45,    55,     6,     7,
       3,   137,   157,     6,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,    64,   166,
     157,    64,   165,   167,   171,    47,   167,     5,     5,    56,
      60,     6,    64,    93,    94,    95,   145,   146,   147,   156,
       5,    57,   153,   157,    58,     6,   157,     6,     6,     5,
      64,   149,    56,    56,   156,   153,   157,   156,   167,   156,
     153,   157,    56,    56,    56,    55,   167,   167,   145,     7,
      55,    58,     6,    64,     3,    59,    64,   151,     5,    64,
     154,   155,   106,    56,   137,   157,     6,     6,   157,     6,
     157,    64,     5,     7,    56,    57,    57,     3,    59,    47,
      56,     3,    59,    57,    57,   167,   156,   149,   145,     7,
     157,    60,   154,     7,    58,     5,    55,    57,    56,    56,
      56,   137,   157,    56,   137,   157,     6,    56,   137,   157,
       6,     7,    64,   156,     7,    57,   133,   133,   157,    60,
      55,   157,    60,   133,   133,    56,    56,   156,     3,   169,
     154,   137,   157,   133,    57,    57,    57,    56,    56,    57,
      56,    56,    56,   137,   157,    57,    56,    56,    56,   137,
     157,   156,     7,     5,   156,   133,    58,    58,     3,   167,
       3,    58,    58,     7,    57,   157,    56,    56,    58,   133,
     133,   133,    57,    57,   133,    57,    57,    57,    56,    56,
     133,    57,    57,    57,    56,    56,   156,    64,    57,    58,
      75,    75,   157,    56,   157,   156,   133,    58,    58,    58,
     133,   133,    58,   133,   133,   133,    57,    57,    58,   133,
     133,   133,    57,    57,     7,   133,    57,   135,    57,   135,
      57,    58,    58,    58,    58,    58,    58,   133,   133,    58,
      58,    58,   133,   133,   156,    58,   133,   133,   133,    58,
      58,    58,    58,    58,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   132,   133,   133,   134,   134,   136,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     137,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   142,   142,   142,   142,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     145,   145,   145,   145,   146,   146,   146,   146,   147,   147,
     147,   148,   148,   149,   149,   149,   149,   149,   149,   149,
     149,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   152,
     151,   151,   153,   154,   154,   154,   154,   155,   156,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   158,   158,
     158,   159,   159,   159,   159,   159,   159,   159,   159,   160,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     162,   162,   162,   162,   162,   162,   163,   163,   163,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   166,
     167,   167,   167,   167,   167,   167,   168,   168,   168,   168,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   171,   171,   171,   171
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     0,     3,     1,     1,
       2,     2,     1,     1,     1,     1,     2,     3,     2,     2,
       3,     3,     3,    11,    11,    10,    10,    10,     9,    11,
      11,    10,    10,    10,     9,    10,    10,     9,     9,     9,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     8,     8,     7,
       7,     7,    11,     9,     7,    11,     9,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       2,     3,     1,     0,     3,     4,     7,     9,     1,     1,
       1,     8,    10,     2,     4,     3,     7,     5,     3,     5,
       0,     2,     4,     4,     4,     6,     6,     8,     2,     4,
       4,     4,     6,     6,     8,     4,     6,     8,     4,     0,
       4,     1,     3,     2,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       2,     3,     3,     1,     1,     0,     4,     7,     5,     8,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     3,     2,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 6:
#line 57 "parser.y" /* yacc.c:1646  */
    { new_var(); }
#line 2265 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 57 "parser.y" /* yacc.c:1646  */
    { debug(yytext); }
#line 2271 "parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 214 "parser.y" /* yacc.c:1646  */
    { debug("id-list"); }
#line 2277 "parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 215 "parser.y" /* yacc.c:1646  */
    { debug("id-list"); }
#line 2283 "parser.c" /* yacc.c:1646  */
    break;


#line 2287 "parser.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 360 "parser.y" /* yacc.c:1906  */

void debug(char* text){
	printf("Lendo-> %s; Linha-> %d; debug-> %s;\n", yytext, yylineno, text);
}

void check_var() {
	printf("chamo o verifica (tesxto da vex ->> %s)\n", yytext);
    int idx = varExist(vt, yylineno);
    if (idx == 1) {
        printf("SEMANTIC ERROR (%d): variable '%s' (teste verificadao-> %d).\n",
                yylineno, yytext, idx);
        exit(EXIT_FAILURE);
    }
}

void new_var() {
	printf("chamo o add (tesxto da vex ->> %s)\n", yytext);

    int idx = varExist(vt, yylineno);
    if (idx != 0) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line   (teste verificadao-> %d).\n",
                yylineno, yytext, idx);
        exit(EXIT_FAILURE);
    }
    addVar(&vt,yylineno, yytext);
}

void yyerror(char const* s)
{
	printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
	exit(EXIT_FAILURE);
}

int main(void){

	// st = create_str_table();
    vt = createVarTable();


	if (yyparse() == 0)printf("Parse successful\n");

    printVars(vt); printf("\n\n");
    freeVars(&vt);


	return 0;
}
