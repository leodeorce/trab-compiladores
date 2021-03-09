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

int yylex(void);
void yyerror(char const*);
void debug(char*, int);

int yylineno;


#line 79 "parser.c" /* yacc.c:339  */

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

/* Copy the second part of user declarations.  */

#line 261 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   536

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  131
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   385

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
     125,   126,   127,   128,   129,   130
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    30,    34,    35,    39,    40,    41,    42,
      43,    44,    45,    49,    50,    51,    52,    53,    54,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    72,    76,
      77,    78,    82,    83,    84,    85,    89,    90,    91,    92,
      93,    94,    95,    99,   103,   104,   105,   106,   111,   112,
     117,   118,   119,   123,   124,   128,   129,   130,   134,   135,
     136,   140,   141,   142,   146,   147,   148,   149,   153,   154,
     155,   156,   157,   158,   164,   165,   169,   174,   175,   176,
     177,   178,   182,   186,   190,   191,   192,   196,   197,   201,
     205,   206,   207,   211,   215,   216,   217,   218,   219,   220,
     221,   226,   227,   228,   229,   230
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
  "$accept", "line", "stmt-list", "stmt", "let-stmt", "var-type",
  "var-stmt", "expr", "obj-declr", "var-val", "array-expr", "elmts-list",
  "scope-box", "expression-stmt", "expre-var", "expre-ari", "expre-logic",
  "expre-conditio", "operator-ari", "operator-logic", "loop-stmt",
  "for-declr", "for-expres", "while-declr", "while-header", "atribuition",
  "function-stmt", "function-declr", "function-use", "function-expres",
  "params-list", "broken-finish", YY_NULLPTR
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
     385
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     246,    17,   349,   -68,   -68,   -68,     8,   -68,   -68,   -38,
     -33,   -23,   -28,   -68,   302,   -68,   -19,   -14,   -68,    58,
     246,   -68,   -68,   -68,   -68,   -68,   196,   118,   488,   -26,
     -68,   -68,   -68,     3,   -68,   -68,   -68,   -68,   -68,    49,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   205,   -68,   -68,
     114,    43,   277,   362,     1,    37,    93,   353,   144,    53,
     -68,   -68,   -68,   121,   353,   -68,   -68,   -68,   -68,   -68,
     -68,   205,   353,   -30,   246,   -68,   -68,   -68,   -68,    35,
     -21,    57,   122,   -68,   123,   -68,   136,   -68,   108,   133,
     -68,    88,   119,   152,    92,   101,   362,   374,   488,   -68,
     184,   396,   -68,   374,   396,   464,   118,   488,   353,   -68,
     132,    35,   154,   102,   374,    16,   -20,   -68,   -68,   362,
     374,    35,   362,   155,   353,   257,   -53,   162,     3,   110,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,     3,
       3,   -16,   161,    13,   163,   -68,   476,   -68,   246,   -68,
      35,   -68,   125,   154,   112,   374,    35,   -68,   168,   -68,
     -68,   488,   353,   170,   -53,   -68,   -68,   -68,   -68,   -68,
     396,   -68,   117,   -68,     3,   191,   -68,   129,   -68,   131,
     135,   362,   488,   353,   179,   182,    61,   -68,   -68,    35,
     137,   -68,   -68,   271,   353,   -68,   396,   -68,   145,    35,
     205,   421,   197,   -68,   148,   118,   205,   -68,   -68,   118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    36,    37,    38,    54,   101,    40,     0,
       0,     0,     0,    41,   105,    39,     0,     0,    42,     0,
       2,     5,     6,     7,    53,     8,    55,    50,    51,    52,
       9,    74,    75,     0,    10,    11,    87,    88,    12,     0,
      92,    68,    71,    69,    72,    70,    73,     0,    54,    55,
       0,     0,     0,   100,     0,     0,     0,     0,     0,    54,
      53,   104,   103,     0,     0,     1,     4,    65,    64,    66,
      67,     0,     0,     0,     0,    82,    91,    57,    60,    47,
      54,     0,     0,    31,    53,    29,     0,    86,    95,    94,
      30,     0,     0,     0,     0,     0,   100,     0,     0,    58,
       0,     0,    13,     0,     0,     0,    56,    59,     0,    63,
       0,    47,    46,     0,     0,    47,     0,    85,    84,   100,
       0,    47,   100,     0,    77,     0,     0,     0,     0,     0,
      25,    24,    23,    22,    27,    19,    20,    26,    21,     0,
       0,     0,     0,     0,     0,    83,     0,    48,   101,    44,
      47,    43,     0,    30,     0,     0,    47,    98,    96,    97,
      90,    78,     0,     0,     0,    76,    93,    89,    61,    14,
       0,    15,     0,    28,     0,     0,    45,     0,    32,     0,
       0,   100,    79,     0,     0,     0,     0,    62,    49,    47,
       0,    34,    99,     0,     0,    16,     0,    17,     0,    47,
       0,     0,     0,    33,     0,    80,     0,    18,    35,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -61,   -17,   -68,   -52,   -68,   -47,   -68,   -10,
     -68,   -67,   -55,     9,     0,    -1,   -42,   -68,   -68,     4,
     -68,   -68,   -68,   -68,   -68,   -68,   193,   -68,    36,   -68,
     -63,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,   139,    23,    89,    83,    24,
      85,   154,    75,    25,    99,    27,    28,    29,    71,    72,
      30,    31,    95,    32,    33,    34,    35,    36,    37,    56,
      91,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    50,    49,    66,    60,    82,    51,    92,     3,     4,
       5,    52,   113,   110,    26,   100,   170,    54,   109,   171,
      26,   111,   105,    61,   114,   155,     8,    74,     1,   114,
     107,    55,    57,   129,   115,   156,    58,    40,    13,   121,
     111,    64,    84,    90,   149,    63,    50,    49,    15,    73,
     125,   143,    26,   108,   142,    76,   157,   144,    65,   159,
      74,    86,   152,    53,   196,    93,   146,   197,   158,   112,
     106,    49,   172,   165,    26,    79,    18,     3,     4,     5,
      88,    39,   161,   176,   167,   168,    90,   175,    87,   180,
      94,    90,    96,    66,    90,     8,     3,     4,     5,    78,
      97,   112,    51,   179,    53,   153,    81,    13,    53,    90,
      26,   112,    90,   119,     8,   120,   163,    15,   192,   187,
     182,   116,   198,   185,   104,   124,    13,    67,   117,   -30,
      68,    67,   204,    69,    68,    70,    15,    69,   122,    70,
     112,   193,   118,     1,   123,    18,   112,   101,    26,   202,
     102,   103,   201,   114,   184,   126,   127,   128,    66,   150,
      90,   160,   151,   121,    18,   164,   166,   169,   178,   173,
      77,    90,   177,   181,    98,    26,   183,   186,   190,   112,
       3,     4,     5,    48,   189,   194,    90,     2,   195,   112,
     147,   191,   199,     3,     4,     5,     6,   148,     8,   205,
      49,   203,     1,   207,   208,   209,    49,    62,     0,     0,
      13,     8,     0,     9,    10,    11,     0,     0,     0,     0,
      15,    12,     0,    13,     0,    41,     0,    42,    14,    43,
      44,    45,    46,    15,     0,     0,    16,   -58,    17,   -58,
     140,   -58,   -58,   -58,   -58,     0,     2,     0,    18,   188,
       0,     0,     3,     4,     5,     6,     7,     1,     0,     0,
      47,    18,     0,   162,     0,     0,     3,     4,     5,    48,
       8,     0,     9,    10,    11,     0,     0,   200,     0,     0,
      12,     0,    13,     0,     8,     0,     0,    14,     1,     0,
       0,     0,    15,     0,     0,    16,    13,    17,    41,     0,
      42,     2,    43,    44,    45,    46,    15,     3,     4,     5,
       6,     7,    41,     1,    42,     0,    43,    44,    45,    46,
      18,     0,     0,     0,     0,     8,     0,     9,    10,    11,
       0,     0,     2,     0,    18,    12,    79,    13,     3,     4,
       5,    80,    14,     0,     0,     0,     0,    15,     0,     0,
      16,     0,    17,     0,     0,     0,     8,     2,     0,     0,
      11,     0,     0,     3,     4,     5,    59,    81,    13,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    15,     0,
       0,     8,     0,     0,    10,    11,     0,     0,     0,     0,
      41,     0,    42,    13,    43,    44,    45,    46,     0,     0,
       0,     0,     0,    15,    47,     0,    18,     0,    98,     0,
       3,     4,     5,    48,     3,     4,     5,    48,     0,     0,
       0,    79,     0,     3,     4,     5,    88,   206,     8,     0,
       0,    18,     8,     0,     0,     0,     0,     0,     0,     0,
      13,     8,     0,     0,    13,     0,     0,     0,     0,     0,
      15,     0,    81,    13,    15,    79,     0,     3,     4,     5,
     141,     0,    41,    15,    42,   130,    43,    44,    45,    46,
       0,     0,     0,     0,     0,     8,     0,     0,    18,   131,
       0,     0,    18,     0,     0,     0,    81,    13,     0,     0,
       0,    18,   132,   133,     0,     0,     0,    15,   134,   135,
     136,     0,     0,   137,   138,    41,     0,    42,     0,    43,
      44,    45,    46,     0,     0,     0,     0,    41,     0,    42,
     145,    43,    44,    45,    46,    18,     0,     0,     0,    41,
       0,    42,   174,    43,    44,    45,    46
};

static const yytype_int16 yycheck[] =
{
       0,     2,     2,    20,    14,    52,     2,     6,    61,    62,
      63,     3,    79,    74,    14,    57,     3,    55,    73,     6,
      20,     5,    64,    14,    45,    45,    79,    57,    11,    45,
      72,    64,    55,    96,    55,    55,    64,     1,    91,    55,
       5,    55,    52,    53,   111,    64,    47,    47,   101,    75,
      92,   103,    52,    83,   101,     6,   119,   104,     0,   122,
      57,    52,   114,    55,     3,    64,   108,     6,   120,    79,
      71,    71,    59,   128,    74,    59,   129,    61,    62,    63,
      64,    64,   124,   150,   139,   140,    96,   148,    52,   156,
      89,   101,    55,   110,   104,    79,    61,    62,    63,    56,
       7,   111,    98,   155,    55,   115,    90,    91,    55,   119,
     110,   121,   122,     5,    79,     7,   126,   101,   181,   174,
     162,    64,   189,   170,     3,     6,    91,    13,     6,     6,
      16,    13,   199,    19,    16,    21,   101,    19,     5,    21,
     150,   183,     6,    11,    56,   129,   156,     3,   148,   196,
       6,     7,   194,    45,   164,     3,    64,    56,   175,     5,
     170,     6,    60,    55,   129,     3,    56,     6,    56,     6,
      56,   181,    47,     5,    55,   175,     6,    60,    47,   189,
      61,    62,    63,    64,    55,     6,   196,    55,     6,   199,
      58,    56,    55,    61,    62,    63,    64,    65,    79,   200,
     200,    56,    11,     6,    56,   206,   206,    14,    -1,    -1,
      91,    79,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
     101,    89,    -1,    91,    -1,    41,    -1,    43,    96,    45,
      46,    47,    48,   101,    -1,    -1,   104,    41,   106,    43,
      56,    45,    46,    47,    48,    -1,    55,    -1,   129,    58,
      -1,    -1,    61,    62,    63,    64,    65,    11,    -1,    -1,
      55,   129,    -1,     6,    -1,    -1,    61,    62,    63,    64,
      79,    -1,    81,    82,    83,    -1,    -1,     6,    -1,    -1,
      89,    -1,    91,    -1,    79,    -1,    -1,    96,    11,    -1,
      -1,    -1,   101,    -1,    -1,   104,    91,   106,    41,    -1,
      43,    55,    45,    46,    47,    48,   101,    61,    62,    63,
      64,    65,    41,    11,    43,    -1,    45,    46,    47,    48,
     129,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,
      -1,    -1,    55,    -1,   129,    89,    59,    91,    61,    62,
      63,    64,    96,    -1,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    79,    55,    -1,    -1,
      83,    -1,    -1,    61,    62,    63,    64,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,   101,    -1,
      -1,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      41,    -1,    43,    91,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,   101,    55,    -1,   129,    -1,    55,    -1,
      61,    62,    63,    64,    61,    62,    63,    64,    -1,    -1,
      -1,    59,    -1,    61,    62,    63,    64,     6,    79,    -1,
      -1,   129,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    79,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    90,    91,   101,    59,    -1,    61,    62,    63,
      64,    -1,    41,   101,    43,    91,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,   129,   105,
      -1,    -1,   129,    -1,    -1,    -1,    90,    91,    -1,    -1,
      -1,   129,   118,   119,    -1,    -1,    -1,   101,   124,   125,
     126,    -1,    -1,   129,   130,    41,    -1,    43,    -1,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    41,    -1,    43,
      56,    45,    46,    47,    48,   129,    -1,    -1,    -1,    41,
      -1,    43,    56,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    55,    61,    62,    63,    64,    65,    79,    81,
      82,    83,    89,    91,    96,   101,   104,   106,   129,   132,
     133,   134,   135,   137,   140,   144,   145,   146,   147,   148,
     151,   152,   154,   155,   156,   157,   158,   159,   162,    64,
     159,    41,    43,    45,    46,    47,    48,    55,    64,   145,
     146,   150,     3,    55,    55,    64,   160,    55,    64,    64,
     140,   144,   157,    64,    55,     0,   134,    13,    16,    19,
      21,   149,   150,    75,    57,   143,     6,    56,    56,    59,
      64,    90,   138,   139,   140,   141,   144,   159,    64,   138,
     140,   161,     6,    64,    89,   153,    55,     7,    55,   145,
     147,     3,     6,     7,     3,   147,   146,   147,    83,   143,
     133,     5,   140,   142,    45,    55,    64,     6,     6,     5,
       7,    55,     5,    56,     6,   147,     3,    64,    56,   161,
      91,   105,   118,   119,   124,   125,   126,   129,   130,   136,
      56,    64,   138,   136,   138,    56,   147,    58,    65,   142,
       5,    60,   136,   140,   142,    45,    55,   161,   136,   161,
       6,   147,     6,   140,     3,   143,    56,   143,   143,     6,
       3,     6,    59,     6,    56,   133,   142,    47,    56,   136,
     142,     5,   147,     6,   140,   138,    60,   143,    58,    55,
      47,    56,   161,   147,     6,     6,     3,     6,   142,    55,
       6,   147,   138,    56,   142,   146,     6,     6,    56,   146
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   131,   132,   132,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   135,   135,   135,   135,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   138,
     138,   138,   139,   139,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   141,   142,   142,   142,   142,   143,   143,
     144,   144,   144,   145,   145,   146,   146,   146,   147,   147,
     147,   148,   148,   148,   149,   149,   149,   149,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   153,   153,   153,
     153,   153,   154,   155,   156,   156,   156,   157,   157,   158,
     159,   159,   159,   160,   161,   161,   161,   161,   161,   161,
     161,   162,   162,   162,   162,   162
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     5,     7,     7,     9,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     4,     7,     5,     8,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     1,     0,     3,     5,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     5,     6,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     2,     3,     4,
       7,     8,     2,     4,     4,     4,     3,     1,     1,     5,
       5,     3,     2,     4,     1,     1,     3,     3,     3,     5,
       0,     1,     2,     2,     2,     1
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
          case 2:
#line 29 "parser.y" /* yacc.c:1646  */
    { debug("line", 1); }
#line 1813 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 30 "parser.y" /* yacc.c:1646  */
    { debug("line", 2); }
#line 1819 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 34 "parser.y" /* yacc.c:1646  */
    { debug("stmt-list", 1); }
#line 1825 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 35 "parser.y" /* yacc.c:1646  */
    { debug("stmt-list", 2); }
#line 1831 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 39 "parser.y" /* yacc.c:1646  */
    { debug("stmt", 1); }
#line 1837 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 40 "parser.y" /* yacc.c:1646  */
    { debug("stmt", 2); }
#line 1843 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 41 "parser.y" /* yacc.c:1646  */
    { debug("stmt", 3); }
#line 1849 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 42 "parser.y" /* yacc.c:1646  */
    { debug("stm" , 4); }
#line 1855 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 43 "parser.y" /* yacc.c:1646  */
    { debug("stm" , 5); }
#line 1861 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 44 "parser.y" /* yacc.c:1646  */
    { debug("stm" , 6); }
#line 1867 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 45 "parser.y" /* yacc.c:1646  */
    { debug("stm",  7); }
#line 1873 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 49 "parser.y" /* yacc.c:1646  */
    { debug("let-stmt", 1); }
#line 1879 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 50 "parser.y" /* yacc.c:1646  */
    { debug("let-stmt", 2); }
#line 1885 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 51 "parser.y" /* yacc.c:1646  */
    { debug("let-stmt", 3); }
#line 1891 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 52 "parser.y" /* yacc.c:1646  */
    { debug("let-stmt", 4); }
#line 1897 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 53 "parser.y" /* yacc.c:1646  */
    { debug("let-stmt", 5); }
#line 1903 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 54 "parser.y" /* yacc.c:1646  */
    { debug("let-stmt", 6); }
#line 1909 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 60 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 1); }
#line 1915 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 61 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 2); }
#line 1921 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 62 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 3); }
#line 1927 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 63 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 4); }
#line 1933 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 64 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 5); }
#line 1939 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 65 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 6); }
#line 1945 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 66 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 7); }
#line 1951 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 67 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 8); }
#line 1957 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 68 "parser.y" /* yacc.c:1646  */
    { debug("var-type", 9); }
#line 1963 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 72 "parser.y" /* yacc.c:1646  */
    { debug("var-stmt", 1); }
#line 1969 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 76 "parser.y" /* yacc.c:1646  */
    { debug("expr", 1); }
#line 1975 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 77 "parser.y" /* yacc.c:1646  */
    { debug("expr", 2); }
#line 1981 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 78 "parser.y" /* yacc.c:1646  */
    { debug("expr", 3); }
#line 1987 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 82 "parser.y" /* yacc.c:1646  */
    { debug("obj-declr", 1); }
#line 1993 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 83 "parser.y" /* yacc.c:1646  */
    { debug("obj-declr", 2); }
#line 1999 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 84 "parser.y" /* yacc.c:1646  */
    { debug("obj-declr", 3); }
#line 2005 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 85 "parser.y" /* yacc.c:1646  */
    { debug("obj-declr", 4); }
#line 2011 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 89 "parser.y" /* yacc.c:1646  */
    { debug("var-val", 1); }
#line 2017 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 90 "parser.y" /* yacc.c:1646  */
    { debug("var-val", 2); }
#line 2023 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 91 "parser.y" /* yacc.c:1646  */
    { debug("var-val", 3); }
#line 2029 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 92 "parser.y" /* yacc.c:1646  */
    { debug("var-val", 4); }
#line 2035 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 93 "parser.y" /* yacc.c:1646  */
    { debug("var-val", 5); }
#line 2041 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 94 "parser.y" /* yacc.c:1646  */
    { debug("var-val", 6); }
#line 2047 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 95 "parser.y" /* yacc.c:1646  */
    { debug("var-val", 7); }
#line 2053 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 99 "parser.y" /* yacc.c:1646  */
    { debug("array-expr", 1); }
#line 2059 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 103 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list", 1); }
#line 2065 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 104 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list", 2); }
#line 2071 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 105 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list", 3); }
#line 2077 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 106 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list", 4); }
#line 2083 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 111 "parser.y" /* yacc.c:1646  */
    { debug("scope-box", 1); }
#line 2089 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 112 "parser.y" /* yacc.c:1646  */
    { debug("scope-box", 2); }
#line 2095 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 117 "parser.y" /* yacc.c:1646  */
    { debug("expression-stmt", 1); }
#line 2101 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 118 "parser.y" /* yacc.c:1646  */
    { debug("expression-stmt", 2); }
#line 2107 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 119 "parser.y" /* yacc.c:1646  */
    { debug("expression-stmt", 3); }
#line 2113 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 129 "parser.y" /* yacc.c:1646  */
    { debug("expre-ari", 1); }
#line 2119 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 130 "parser.y" /* yacc.c:1646  */
    { debug("expre-ari", 2); }
#line 2125 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 135 "parser.y" /* yacc.c:1646  */
    { debug("expre-ari", 1); }
#line 2131 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 136 "parser.y" /* yacc.c:1646  */
    { debug("expre-ari", 2); }
#line 2137 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 146 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 1); }
#line 2143 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 147 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 2); }
#line 2149 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 148 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 3); }
#line 2155 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 149 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 4); }
#line 2161 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 153 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 1); }
#line 2167 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 154 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 2); }
#line 2173 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 155 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 3); }
#line 2179 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 156 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 4); }
#line 2185 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 157 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 5); }
#line 2191 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 158 "parser.y" /* yacc.c:1646  */
    { debug("operator-ari", 6); }
#line 2197 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 164 "parser.y" /* yacc.c:1646  */
    { debug("loop-stmt", 1); }
#line 2203 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 165 "parser.y" /* yacc.c:1646  */
    { debug("loop-stmt", 2); }
#line 2209 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 169 "parser.y" /* yacc.c:1646  */
    { debug("for-declr", 1); }
#line 2215 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 174 "parser.y" /* yacc.c:1646  */
    { debug("for-expres", 1); }
#line 2221 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 175 "parser.y" /* yacc.c:1646  */
    { debug("for-expres", 1); }
#line 2227 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 176 "parser.y" /* yacc.c:1646  */
    { debug("for-expres", 1); }
#line 2233 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 177 "parser.y" /* yacc.c:1646  */
    { debug("for-expres", 1); }
#line 2239 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 178 "parser.y" /* yacc.c:1646  */
    { debug("for-expres", 1); }
#line 2245 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 182 "parser.y" /* yacc.c:1646  */
    { debug("while-declr", 1); }
#line 2251 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 186 "parser.y" /* yacc.c:1646  */
    { debug("while-header", 1); }
#line 2257 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 215 "parser.y" /* yacc.c:1646  */
    { debug("params-list", 1); }
#line 2263 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 216 "parser.y" /* yacc.c:1646  */
    { debug("params-list", 2); }
#line 2269 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 217 "parser.y" /* yacc.c:1646  */
    { debug("params-list", 3); }
#line 2275 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 218 "parser.y" /* yacc.c:1646  */
    { debug("params-list", 4); }
#line 2281 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 219 "parser.y" /* yacc.c:1646  */
    { debug("params-list", 5); }
#line 2287 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 220 "parser.y" /* yacc.c:1646  */
    { debug("params-list", 6); }
#line 2293 "parser.c" /* yacc.c:1646  */
    break;


#line 2297 "parser.c" /* yacc.c:1646  */
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
#line 235 "parser.y" /* yacc.c:1906  */


void debug(char* nonT, int item)
{
	printf("Linha %d Non-T \"%s\" item %d\n", yylineno, nonT, item);
}

void yyerror(char const* s)
{
	printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
	exit(EXIT_FAILURE);
}

int main(void)
{
	if (yyparse() == 0)
		printf("Parse successful\n");

	return 0;
}
