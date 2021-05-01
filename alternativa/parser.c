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
#include "types.h"
#include "list.h"
#include "tupla.h"
#include "ast.h"
#include "parser.h"

int  yylex(void);
void yyerror(const char* s);
int  yylex_destroy(void);

void debug(char*);

AST* check_var(Tupla* tupla);
AST* new_var(Tupla* tupla, Type type);

AST* unify_bin_op(Type left, Type right, const char*, Type (*unify)(Type, Type));
AST* check_assign(Type left, Type right);
AST* change_type(Tupla* tupla, Type type);

void type_error(const char*, Type, Type);

extern char *yytext;
extern int  yylineno;

Var_table *vt;
Str_table *st;

AST *root;


#line 101 "parser.c" /* yacc.c:339  */

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
typedef Tupla* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 284 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  113
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  465

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
       0,    74,    74,    83,    84,    88,    94,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     121,   123,   131,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   175,   176,   180,
     181,   185,   186,   187,   188,   189,   190,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   209,
     213,   214,   215,   216,   220,   221,   222,   223,   227,   228,
     229,   234,   239,   246,   247,   248,   249,   250,   251,   252,
     253,   258,   265,   271,   276,   282,   288,   293,   298,   304,
     310,   315,   321,   327,   332,   337,   343,   349,   354,   361,
     362,   370,   374,   375,   376,   377,   381,   385,   386,   387,
     388,   389,   390,   391,   395,   396,   397,   401,   402,   403,
     407,   408,   409,   410,   411,   412,   413,   414,   423,   428,
     434,   436,   442,   444,   450,   452,   458,   460,   462,   467,
     473,   478,   479,   480,   481,   485,   486,   487,   491,   492,
     493,   497,   498,   499,   500,   501,   502,   503,   507,   511,
     512,   513,   514,   515,   516,   520,   521,   522,   523,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   542,   546,   547,   548,   549
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
  "E_ID", "$accept", "begin", "line", "stmt-list", "stmt", "assign-expr",
  "for-stmt", "assignment", "do-while-stmt", "while-stmt", "if-stmt",
  "logic-expr", "class-def", "class-att-list", "class-att", "access-modif",
  "func-def", "params", "var-declr", "id-list", "obj-def", "obj-att-list",
  "obj-att", "var-type", "expr", "idx-unsafe-expr", "idx-safe-expr",
  "vet-idx", "unary-expr", "arit-expr", "bitw-expr", "shift-expr",
  "var-att", "var-met", "args-list", "var-obj", "var-val", "array-expr",
  "elmts-list", YY_NULLPTR
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

#define YYPACT_NINF -249

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-249)))

#define YYTABLE_NINF -179

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     955,   -27,   -38,   -11,  1278,  1278,  1278,   280,  -249,  -249,
    -249,  1375,    39,    -7,    -6,    55,    11,  -249,     7,    20,
      33,    26,    32,  -249,   574,  -249,    38,    36,  -249,    69,
    -249,   955,  -249,    97,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,   105,  1591,  -249,  -249,  1517,  -249,  -249,  -249,  -249,
    1459,   101,  -249,  -249,  -249,     5,   104,  -249,  -249,  -249,
    -249,  -249,     5,   104,   188,  -249,  -249,    21,  -249,  1806,
     280,   111,    57,  -249,    54,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,   734,
    -249,  -249,  -249,   460,  1278,  1278,  -249,    96,    35,   143,
    -249,   955,    83,   100,  1297,    47,   156,   -19,  -249,  1635,
      80,   158,  1297,  -249,  -249,  -249,  -249,  -249,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,    99,  -249,  -249,  1278,   103,   460,  -249,  -249,
     280,  -249,     5,   104,   101,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,   118,   467,   460,   163,  1547,   113,  2196,   110,
    2196,     6,   107,   -75,  1014,   115,   633,  1413,   169,   170,
    1517,  1490,     8,   124,  1845,   -75,  1014,   -75,   460,  -249,
     -75,  1014,   125,  1884,    85,    85,   162,   162,   162,   162,
     533,   515,   638,   467,   467,   467,   467,   467,   467,   467,
     467,   467,   467,   467,   141,   141,   141,  2196,   135,  -249,
    2196,     5,   104,   136,  -249,   140,  -249,   460,   460,   185,
    -249,     6,    27,  -249,  -249,  -249,   139,   192,   142,   195,
    -249,    15,     9,  -249,  2196,    98,  1033,  1679,   656,   715,
     168,   102,   147,   178,   180,    16,  -249,  2196,   191,   183,
      19,  -249,  2196,   184,   187,  -249,   460,  -249,  -249,  -249,
     -75,     8,  -249,     6,   233,  1278,   182,     9,   238,   190,
     241,   194,   193,   198,  1923,  1086,  1105,  1723,  1119,  1767,
     248,   200,   -75,    14,   955,   955,  1278,   196,   202,  -249,
    1278,   199,   955,   955,   206,  -249,   210,  -249,   -75,  2196,
     255,  -249,   -15,  -249,     9,  1297,   955,   213,   215,   216,
     211,  1962,   217,   220,  2001,  1174,   222,   225,  2040,  1225,
     -75,   276,   279,   -75,   955,   228,   229,  2196,   285,   460,
    2196,   286,   232,   234,  -249,    24,  -249,  1278,  -249,  -249,
     235,  2079,   236,   955,   955,   955,   240,   244,   955,   245,
     247,   249,   239,  2118,   955,   251,   253,   254,   242,  2157,
    -249,   -75,   250,   256,   257,   230,   237,  1278,   262,  1278,
    -249,  -249,   -75,   955,  2196,  -249,  -249,  -249,   264,   265,
     267,   955,   955,   271,   955,   955,   955,   275,   282,   278,
     955,   955,   955,   283,   287,  -249,   326,   955,  -249,   813,
     884,  2196,  -249,  2196,   288,   289,  -249,  -249,  -249,   290,
     293,  -249,   294,   295,   296,   955,   955,  -249,   298,   305,
     307,   955,   955,   -75,   311,   955,  -249,   955,  -249,   955,
    -249,  -249,  -249,  -249,  -249,  -249,   312,   318,  -249,  -249,
    -249,   328,   329,  -249,  -249,   330,   332,   335,  -249,  -249,
    -249,  -249,  -249,  -249,  -249
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,   205,   189,   190,
     191,   147,     0,     0,     0,     0,     0,   193,     0,     0,
       0,     0,     0,   199,     0,   192,     0,     0,   200,     0,
       2,     3,     6,     0,    15,    14,    13,    12,   138,     9,
       8,     0,     0,   135,   134,   146,   145,   142,   143,   144,
     141,     0,   139,   140,   137,   149,   150,   194,   195,   196,
     198,   197,   151,   152,   147,   158,   146,   141,   157,     0,
     205,   204,     0,    41,     0,   153,    45,   155,    46,    47,
      48,    49,    50,    51,    52,    53,    42,    43,    44,     0,
      54,    55,    56,   184,     0,     0,    18,     0,   120,     0,
      19,     4,     0,     0,     0,   120,   101,     0,    16,     0,
     120,   108,     0,     1,     5,    11,     7,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   156,     0,     0,   184,   136,   202,
     205,   201,   177,   171,   173,   132,   131,   130,   133,   127,
     128,   129,     0,    72,   184,   183,   182,     0,     0,   134,
      21,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,   184,    17,
       0,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    76,    77,    78,    67,    68,    69,    70,
      71,    73,    74,    75,   168,   169,   170,    22,   172,   176,
      20,   174,   175,     0,   203,     0,   179,   184,   184,   185,
     148,    83,     0,    89,    90,    88,     0,    82,     0,   120,
     119,     0,   125,   118,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   103,   102,     0,     0,
     111,   110,   109,     0,     0,   178,   184,   181,   180,    80,
       0,   100,    79,    83,     0,     0,     0,   125,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     4,     4,     0,     0,     0,   187,
       0,     0,     4,     4,     0,    84,     0,    81,     0,   116,
       0,   122,     0,   121,   125,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    98,     0,     4,     0,     0,   105,   106,   184,
     112,   113,     0,     0,   186,     0,    85,     0,   126,   123,
       0,     0,     0,     4,     4,     4,     0,     0,     4,     0,
       0,     0,     0,     0,     4,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,    64,    61,     0,     0,     0,
      60,    59,     0,     4,   117,    58,    57,    40,     0,     0,
       0,     4,     4,     0,     4,     4,     4,     0,     0,     0,
       4,     4,     4,     0,     0,    99,    97,     4,    91,     0,
       0,   107,   188,   114,     0,     0,    39,    38,    37,     0,
       0,    28,     0,     0,     0,     4,     4,    34,     0,     0,
       0,     4,     4,     0,     0,     4,    66,     4,    63,     4,
      86,    36,    35,    27,    26,    25,     0,     0,    33,    32,
      31,     0,     0,    96,    92,     0,     0,     0,    24,    23,
      30,    29,    65,    62,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -249,  -249,   -34,  -249,   -31,   317,  -249,   -30,  -249,  -249,
    -249,  -249,  -249,  -214,  -249,  -249,  -249,   123,   297,   -16,
    -158,  -248,  -249,     1,    89,  -249,   301,   322,  -249,  -249,
    -249,  -249,     3,   -63,  -108,  -249,    -5,  -249,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,    33,    34,    95,    35,    36,
      37,    38,    39,   236,   237,   238,    40,   252,    41,    99,
     243,   279,   280,   162,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,   167,    52,    53,    54,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,     2,    71,   149,    56,   106,    63,    67,    67,    67,
     111,   154,   231,   250,   277,   141,    74,   269,   275,   296,
     145,   333,   300,    57,    58,    59,   187,    67,   256,   311,
     155,   382,   142,   261,   270,   143,   188,    55,   144,   223,
     172,    60,   173,   156,   157,    96,     8,     9,    10,   158,
     159,   160,   172,    62,   185,   161,   226,    97,    98,   307,
     147,   100,   102,    61,    17,    71,   349,   175,   101,   113,
     232,   334,   251,   278,   276,   297,    23,   153,   301,   219,
     259,   383,   271,   224,   103,   172,    25,   190,   104,   176,
     105,   112,    67,    65,    68,    69,   107,    67,    67,   233,
     234,   235,   110,   115,   120,   181,   121,   291,   122,   292,
     123,   116,   146,   109,    28,   142,   150,   151,   152,   267,
     268,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    71,   174,   177,    67,   222,
     141,   145,    14,   171,   118,   182,   240,   119,   304,   186,
     120,   191,   121,   218,   122,   225,   123,   221,   227,   229,
     230,   239,    21,   245,   241,   248,   249,    67,   163,    67,
     253,   263,   166,   168,   170,   122,   255,    26,   258,    67,
     147,   260,   265,   184,    67,   266,  -178,   272,   273,    74,
     172,   193,    75,   293,   281,    77,   274,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   378,   290,    89,   220,   294,   166,   295,   298,   299,
     308,   302,   310,    93,   303,   312,   314,    94,   313,   315,
     316,    67,    67,   166,   317,   330,   338,   339,   347,   341,
     335,   336,   344,   244,   331,   247,   345,   356,   342,   343,
     353,   305,   354,   355,   358,   257,   359,   166,    67,   364,
     262,   365,   352,   371,   372,    70,   375,   376,   377,   379,
     380,   385,   381,   332,   387,   397,     2,   391,   403,    67,
     374,   392,   394,    67,   395,   409,   396,   348,   400,   346,
     401,   402,   410,   407,   406,   408,   166,   166,   412,   388,
     389,   390,   416,   417,   393,   418,    66,    66,    66,   421,
     399,   370,   425,   433,   373,   284,   427,   287,   289,   426,
     431,     8,     9,    10,   432,   439,    66,   440,   441,   415,
      67,   442,   443,   444,   445,   166,   448,   419,   420,    17,
     422,   423,   424,   449,   309,   450,   428,   429,   430,   454,
     458,    23,   405,   434,   321,   324,   459,   328,   436,   438,
      67,    25,    67,   414,     0,   337,   460,   461,   462,   340,
     463,   446,   447,   464,   306,   169,     0,   451,   452,   179,
       0,   455,     0,   456,   351,   457,     0,     0,     0,    28,
     165,    66,     0,     0,   363,     0,    66,    66,   369,   178,
       0,   183,     0,     0,   180,     0,     0,     0,   166,   192,
       0,     0,     0,     0,   453,     0,   384,     0,     0,     0,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,   165,   164,   411,    66,   413,     0,
       0,     0,     0,     0,     1,     0,     2,     3,     0,     0,
     118,   165,     0,   119,     0,     0,   120,     4,   121,     0,
     122,     0,   123,     0,     5,   124,    66,   125,    66,   126,
       0,     0,     0,     0,     0,   165,     0,     0,    66,     0,
       0,     0,     0,    66,     0,     6,   138,     0,   139,     7,
     140,     8,     9,    10,    11,     0,     0,     0,   118,     0,
       0,   119,     0,     0,   120,     0,   121,     0,   122,    17,
     123,     0,     0,   124,   165,   165,   118,   126,     0,   119,
      22,    23,   120,     0,   121,     0,   122,     0,   123,     0,
       0,    25,     0,   283,   138,     0,   139,     0,   140,     0,
      66,    66,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,   138,   165,   139,     0,   140,     0,     1,    28,
       2,     3,     0,     0,     0,     0,     0,    66,     0,     0,
       0,     4,   320,   323,     0,   327,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     6,
       0,     0,   350,     7,     0,     8,     9,    10,    64,   246,
       0,     0,   362,     0,     0,     0,   368,     1,     0,     2,
       3,   118,     0,    17,   119,     0,   165,   120,     0,   121,
       4,   122,   286,   123,    22,    23,   124,     5,     0,    66,
       1,     0,     2,     3,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,   138,     6,   139,
       5,   140,     7,     0,     8,     9,    10,    64,     0,    66,
       0,    66,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     6,    17,     0,     0,     7,     0,     8,     9,    10,
      64,   288,     0,    22,    23,     0,     0,     0,     0,     1,
       0,     2,     3,     0,    25,    17,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     0,    22,    23,     1,     5,
       2,     3,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     4,    28,     0,     0,     0,     0,     0,     5,     0,
       6,     0,     0,     0,     7,     0,     8,     9,    10,    64,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     6,
       0,     0,     0,     7,    17,     8,     9,    10,    64,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,    17,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     1,     0,     2,
       3,     0,     0,     0,     0,    25,     0,     0,     0,   155,
       4,     0,     0,     0,    28,     0,     0,     5,     0,     0,
       0,     0,   156,   157,     0,     0,     0,     0,   158,   159,
     160,     0,     0,    28,   161,     0,     0,     0,     6,     0,
     435,     0,     7,     0,     8,     9,    10,    11,    12,     0,
       0,    13,    14,    15,     0,     0,     0,    16,     0,     0,
       0,     0,    17,     0,    18,    19,    20,     0,     1,     0,
       2,     3,    21,    22,    23,     0,     0,     0,     0,    24,
       0,     4,     0,     0,    25,     0,     0,    26,     5,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,   437,    28,     7,     0,     8,     9,    10,    11,    12,
       0,     0,    13,    14,    15,     0,     0,     0,    16,     0,
       0,     0,     0,    17,     0,    18,    19,    20,     0,     1,
       0,     2,     3,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     4,     0,     0,    25,     0,     0,    26,     5,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     0,    28,     7,     0,     8,     9,    10,    11,
      12,     0,     0,    13,    14,    15,     0,     0,     1,    16,
       2,     3,     0,     0,    17,     0,    18,    19,    20,     0,
       0,     4,     0,     0,    21,    22,    23,     1,     5,     2,
       3,    24,     0,     0,     0,     0,    25,     0,     0,    26,
       4,    27,     0,     0,     0,     0,     0,     5,     0,     6,
       0,   242,     0,     7,     0,     8,     9,    10,    64,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     6,   282,
       0,     0,     7,    17,     8,     9,    10,    11,     0,     0,
       1,     0,     2,     3,    22,    23,     0,     0,     0,     0,
       0,     0,    17,     4,     0,    25,     0,     0,     0,     1,
       5,     2,     3,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     4,     1,    25,     2,     3,     0,     0,     5,
       0,     6,   319,    28,     0,     7,     4,     8,     9,    10,
      11,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       6,   322,    28,     0,     7,    17,     8,     9,    10,    11,
       0,     0,     0,     0,     6,   326,    22,    23,     7,     0,
       8,     9,    10,    11,    17,     0,     0,    25,     1,     0,
       2,     3,     0,     0,     0,    22,    23,     0,    17,     0,
       0,     4,     0,     0,     0,     0,    25,     0,     5,    22,
      23,     0,     0,     0,     0,    28,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     6,
     361,     0,     0,     7,    28,     8,     9,    10,    11,     1,
       0,     2,     3,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     4,    17,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       6,   367,     0,     0,     7,     0,     8,     9,    10,    11,
       0,     0,     1,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,    28,    17,     4,     0,     0,     0,     0,
       0,     1,     5,     2,     3,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     4,     0,    25,     0,     0,     0,
       0,     5,     0,     6,     0,     0,     0,     7,     0,     8,
       9,    10,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,    28,     0,     7,    17,     8,     9,
      10,    11,     0,     0,     0,     0,     0,     0,    22,    23,
       0,     0,     0,     0,     0,     0,    17,     0,    73,    25,
       0,     0,     0,     0,     0,     0,    74,    22,    23,    75,
      76,     0,    77,    78,     0,    79,     0,    80,    25,    81,
       0,    82,     0,     0,    83,     0,    84,    28,    85,     0,
       0,    86,     0,    87,     0,    88,    73,     0,     0,     0,
      89,     0,     0,     0,    74,    90,    28,    91,    76,    92,
      93,    78,     0,    79,    94,    80,     0,    81,     0,    82,
       0,     0,    83,     0,    84,     0,    85,     0,     0,    86,
       0,    87,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    90,     0,    91,     0,    92,   147,     0,
     142,     0,    94,   143,    76,     0,   144,    78,     0,    79,
       0,    80,     0,    81,     0,    82,     0,     0,    83,     0,
      84,     0,    85,    73,     0,    86,     0,    87,     0,    88,
       0,   142,     0,     0,     0,    76,     0,     0,    78,    90,
      79,    91,    80,    92,    81,     0,    82,     0,     0,    83,
      73,    84,     0,    85,     0,     0,    86,     0,    87,     0,
      88,     0,    76,     0,     0,    78,     0,    79,     0,    80,
      90,    81,    91,    82,    92,     0,    83,     0,    84,     0,
      85,     0,   228,    86,     0,    87,     0,    88,     0,     0,
     118,     0,     0,   119,     0,     0,   120,    90,   121,    91,
     122,    92,   123,     0,     0,   124,     0,   125,     0,   126,
       0,     0,   127,     0,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   117,   139,     0,
     140,     0,     0,     0,   118,     0,     0,   119,     0,     0,
     120,     0,   121,     0,   122,     0,   123,     0,     0,   124,
       0,   125,     0,   126,     0,     0,   127,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   189,   139,     0,   140,     0,     0,     0,   118,     0,
       0,   119,     0,     0,   120,     0,   121,     0,   122,     0,
     123,     0,     0,   124,     0,   125,     0,   126,     0,     0,
     127,     0,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   285,   139,     0,   140,     0,
       0,     0,   118,     0,     0,   119,     0,     0,   120,     0,
     121,     0,   122,     0,   123,     0,     0,   124,     0,   125,
       0,   126,     0,     0,   127,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   325,
     139,     0,   140,     0,     0,     0,   118,     0,     0,   119,
       0,     0,   120,     0,   121,     0,   122,     0,   123,     0,
       0,   124,     0,   125,     0,   126,     0,     0,   127,     0,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   329,   139,     0,   140,     0,     0,     0,
     118,     0,     0,   119,     0,     0,   120,     0,   121,     0,
     122,     0,   123,     0,     0,   124,     0,   125,     0,   126,
       0,     0,   127,     0,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,   139,   118,
     140,     0,   119,     0,     0,   120,     0,   121,     0,   122,
       0,   123,     0,     0,   124,     0,   125,     0,   126,     0,
       0,   127,     0,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,   139,   118,   140,
       0,   119,   148,     0,   120,     0,   121,     0,   122,     0,
     123,     0,     0,   124,     0,   125,     0,   126,     0,     0,
     127,     0,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,   139,   118,   140,     0,
     119,   254,     0,   120,     0,   121,     0,   122,     0,   123,
       0,     0,   124,     0,   125,     0,   126,     0,     0,   127,
       0,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,   139,   118,   140,     0,   119,
     264,     0,   120,     0,   121,     0,   122,     0,   123,     0,
       0,   124,     0,   125,     0,   126,     0,     0,   127,     0,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,   139,   118,   140,     0,   119,   318,
       0,   120,     0,   121,     0,   122,     0,   123,     0,     0,
     124,     0,   125,     0,   126,     0,     0,   127,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,   139,   118,   140,     0,   119,   357,     0,
     120,     0,   121,     0,   122,     0,   123,     0,     0,   124,
       0,   125,     0,   126,     0,     0,   127,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,   139,   118,   140,     0,   119,   360,     0,   120,
       0,   121,     0,   122,     0,   123,     0,     0,   124,     0,
     125,     0,   126,     0,     0,   127,     0,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,   139,   118,   140,     0,   119,   366,     0,   120,     0,
     121,     0,   122,     0,   123,     0,     0,   124,     0,   125,
       0,   126,     0,     0,   127,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
     139,   118,   140,     0,   119,   386,     0,   120,     0,   121,
       0,   122,     0,   123,     0,     0,   124,     0,   125,     0,
     126,     0,     0,   127,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,   139,
     118,   140,     0,   119,   398,     0,   120,     0,   121,     0,
     122,     0,   123,     0,     0,   124,     0,   125,     0,   126,
       0,     0,   127,     0,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,   139,   118,
     140,     0,   119,   404,     0,   120,     0,   121,     0,   122,
       0,   123,     0,     0,   124,     0,   125,     0,   126,     0,
       0,   127,     0,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,   139,     0,   140
};

static const yytype_int16 yycheck[] =
{
      31,    16,     7,    70,     1,    21,     3,     4,     5,     6,
      26,    74,     6,     5,     5,    45,    11,   231,     3,     3,
      50,     7,     3,    61,    62,    63,    45,    24,   186,   277,
     105,     7,    11,   191,     7,    14,    55,    64,    17,   147,
       5,    79,     7,   118,   119,     6,    61,    62,    63,   124,
     125,   126,     5,    64,     7,   130,   164,    64,    64,   273,
      55,     6,    55,   101,    79,    70,   314,   101,    57,     0,
      64,    57,    64,    64,    59,    59,    91,    74,    59,   142,
     188,    57,    55,   150,    64,     5,   101,     7,    55,     6,
      64,    55,    89,     4,     5,     6,    64,    94,    95,    93,
      94,    95,    64,     6,    19,   102,    21,     5,    23,     7,
      25,     6,    11,    24,   129,    11,     5,    60,    64,   227,
     228,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   150,     3,    64,   145,   146,
     180,   181,    69,    57,    13,    55,   172,    16,   266,     3,
      19,     3,    21,    64,    23,    47,    25,    64,     5,    56,
      60,    64,    89,    58,   173,     6,     6,   174,    89,   176,
      56,    56,    93,    94,    95,    23,   185,   104,   187,   186,
      55,   190,    56,   104,   191,    55,    11,    58,     6,    11,
       5,   112,    14,    56,   106,    17,    64,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   339,    64,    45,   145,    57,   147,    57,    47,    56,
       7,    57,    60,    55,    57,     7,     5,    59,    58,    55,
      57,   248,   249,   164,    56,     7,    60,    55,     3,    60,
     294,   295,    56,   174,    64,   176,    56,    56,   302,   303,
      57,   270,    57,    57,    57,   186,    56,   188,   275,    57,
     191,    56,   316,     7,     5,     5,    58,    58,     3,     3,
      58,    56,    58,   292,    58,    56,    16,    57,    56,   296,
     334,    57,    57,   300,    57,    75,    57,   312,    57,   308,
      57,    57,    75,    57,    64,    58,   227,   228,    56,   353,
     354,   355,    58,    58,   358,    58,     4,     5,     6,    58,
     364,   330,    57,     7,   333,   246,    58,   248,   249,    57,
      57,    61,    62,    63,    57,    57,    24,    58,    58,   383,
     347,    58,    58,    58,    58,   266,    58,   391,   392,    79,
     394,   395,   396,    58,   275,    58,   400,   401,   402,    58,
      58,    91,   371,   407,   285,   286,    58,   288,   409,   410,
     377,   101,   379,   382,    -1,   296,    58,    58,    58,   300,
      58,   425,   426,    58,   271,    94,    -1,   431,   432,   102,
      -1,   435,    -1,   437,   315,   439,    -1,    -1,    -1,   129,
      93,    89,    -1,    -1,   325,    -1,    94,    95,   329,   102,
      -1,   104,    -1,    -1,   102,    -1,    -1,    -1,   339,   112,
      -1,    -1,    -1,    -1,   433,    -1,   347,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   147,     5,   377,   145,   379,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    16,    17,    -1,    -1,
      13,   164,    -1,    16,    -1,    -1,    19,    27,    21,    -1,
      23,    -1,    25,    -1,    34,    28,   174,    30,   176,    32,
      -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,   186,    -1,
      -1,    -1,    -1,   191,    -1,    55,    49,    -1,    51,    59,
      53,    61,    62,    63,    64,    -1,    -1,    -1,    13,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,    79,
      25,    -1,    -1,    28,   227,   228,    13,    32,    -1,    16,
      90,    91,    19,    -1,    21,    -1,    23,    -1,    25,    -1,
      -1,   101,    -1,   246,    49,    -1,    51,    -1,    53,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    49,   266,    51,    -1,    53,    -1,    14,   129,
      16,    17,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    27,   285,   286,    -1,   288,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,
      -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,   315,    59,    -1,    61,    62,    63,    64,     6,
      -1,    -1,   325,    -1,    -1,    -1,   329,    14,    -1,    16,
      17,    13,    -1,    79,    16,    -1,   339,    19,    -1,    21,
      27,    23,     6,    25,    90,    91,    28,    34,    -1,   347,
      14,    -1,    16,    17,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    49,    55,    51,
      34,    53,    59,    -1,    61,    62,    63,    64,    -1,   377,
      -1,   379,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    79,    -1,    -1,    59,    -1,    61,    62,    63,
      64,     6,    -1,    90,    91,    -1,    -1,    -1,    -1,    14,
      -1,    16,    17,    -1,   101,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    90,    91,    14,    34,
      16,    17,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    27,   129,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      55,    -1,    -1,    -1,    59,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    79,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    14,    -1,    16,
      17,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,
      27,    -1,    -1,    -1,   129,    -1,    -1,    34,    -1,    -1,
      -1,    -1,   118,   119,    -1,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,   130,    -1,    -1,    -1,    55,    -1,
      57,    -1,    59,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    -1,    14,    -1,
      16,    17,    89,    90,    91,    -1,    -1,    -1,    -1,    96,
      -1,    27,    -1,    -1,   101,    -1,    -1,   104,    34,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    57,   129,    59,    -1,    61,    62,    63,    64,    65,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    79,    -1,    81,    82,    83,    -1,    14,
      -1,    16,    17,    89,    90,    91,    -1,    -1,    -1,    -1,
      96,    -1,    27,    -1,    -1,   101,    -1,    -1,   104,    34,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,   129,    59,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    68,    69,    70,    -1,    -1,    14,    74,
      16,    17,    -1,    -1,    79,    -1,    81,    82,    83,    -1,
      -1,    27,    -1,    -1,    89,    90,    91,    14,    34,    16,
      17,    96,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,
      27,   106,    -1,    -1,    -1,    -1,    -1,    34,    -1,    55,
      -1,    57,    -1,    59,    -1,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    55,    56,
      -1,    -1,    59,    79,    61,    62,    63,    64,    -1,    -1,
      14,    -1,    16,    17,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    27,    -1,   101,    -1,    -1,    -1,    14,
      34,    16,    17,    90,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    14,   101,    16,    17,    -1,    -1,    34,
      -1,    55,    56,   129,    -1,    59,    27,    61,    62,    63,
      64,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,   129,    -1,    59,    79,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    55,    56,    90,    91,    59,    -1,
      61,    62,    63,    64,    79,    -1,    -1,   101,    14,    -1,
      16,    17,    -1,    -1,    -1,    90,    91,    -1,    79,    -1,
      -1,    27,    -1,    -1,    -1,    -1,   101,    -1,    34,    90,
      91,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    -1,    -1,    59,   129,    61,    62,    63,    64,    14,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    27,    79,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    59,    -1,    61,    62,    63,    64,
      -1,    -1,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    79,    27,    -1,    -1,    -1,    -1,
      -1,    14,    34,    16,    17,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,   101,    -1,    -1,    -1,
      -1,    34,    -1,    55,    -1,    -1,    -1,    59,    -1,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,   129,    -1,    59,    79,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,     3,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    90,    91,    14,
      15,    -1,    17,    18,    -1,    20,    -1,    22,   101,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,   129,    33,    -1,
      -1,    36,    -1,    38,    -1,    40,     3,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    11,    50,   129,    52,    15,    54,
      55,    18,    -1,    20,    59,    22,    -1,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    33,    -1,    -1,    36,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    50,    -1,    52,    -1,    54,    55,    -1,
      11,    -1,    59,    14,    15,    -1,    17,    18,    -1,    20,
      -1,    22,    -1,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    33,     3,    -1,    36,    -1,    38,    -1,    40,
      -1,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,    50,
      20,    52,    22,    54,    24,    -1,    26,    -1,    -1,    29,
       3,    31,    -1,    33,    -1,    -1,    36,    -1,    38,    -1,
      40,    -1,    15,    -1,    -1,    18,    -1,    20,    -1,    22,
      50,    24,    52,    26,    54,    -1,    29,    -1,    31,    -1,
      33,    -1,     5,    36,    -1,    38,    -1,    40,    -1,    -1,
      13,    -1,    -1,    16,    -1,    -1,    19,    50,    21,    52,
      23,    54,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     6,    51,    -1,
      53,    -1,    -1,    -1,    13,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    23,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    -1,    -1,    35,    -1,    37,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     6,    51,    -1,    53,    -1,    -1,    -1,    13,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,    -1,
      35,    -1,    37,    -1,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     6,    51,    -1,    53,    -1,
      -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     6,
      51,    -1,    53,    -1,    -1,    -1,    13,    -1,    -1,    16,
      -1,    -1,    19,    -1,    21,    -1,    23,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    -1,    -1,    35,    -1,
      37,    -1,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,     6,    51,    -1,    53,    -1,    -1,    -1,
      13,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,
      23,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    13,
      53,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    13,    53,
      -1,    16,    56,    -1,    19,    -1,    21,    -1,    23,    -1,
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
      44,    45,    46,    47,    48,    49,    -1,    51,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    16,    17,    27,    34,    55,    59,    61,    62,
      63,    64,    65,    68,    69,    70,    74,    79,    81,    82,
      83,    89,    90,    91,    96,   101,   104,   106,   129,   133,
     134,   135,   136,   137,   138,   140,   141,   142,   143,   144,
     148,   150,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   167,   168,   169,    64,   164,    61,    62,    63,
      79,   101,    64,   164,    64,   156,   159,   164,   156,   156,
       5,   168,   170,     3,    11,    14,    15,    17,    18,    20,
      22,    24,    26,    29,    31,    33,    36,    38,    40,    45,
      50,    52,    54,    55,    59,   139,     6,    64,    64,   151,
       6,    57,    55,    64,    55,    64,   151,    64,     6,   156,
      64,   151,    55,     0,   136,     6,     6,     6,    13,    16,
      19,    21,    23,    25,    28,    30,    32,    35,    37,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    51,
      53,   139,    11,    14,    17,   139,    11,    55,    56,   170,
       5,    60,    64,   164,   165,   105,   118,   119,   124,   125,
     126,   130,   155,   156,     5,   137,   156,   166,   156,   158,
     156,    57,     5,     7,     3,   134,     6,    64,   137,   150,
     159,   164,    55,   137,   156,     7,     3,    45,    55,     6,
       7,     3,   137,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,    64,   165,
     156,    64,   164,   166,   170,    47,   166,     5,     5,    56,
      60,     6,    64,    93,    94,    95,   145,   146,   147,    64,
     151,   155,    57,   152,   156,    58,     6,   156,     6,     6,
       5,    64,   149,    56,    56,   155,   152,   156,   155,   166,
     155,   152,   156,    56,    56,    56,    55,   166,   166,   145,
       7,    55,    58,     6,    64,     3,    59,     5,    64,   153,
     154,   106,    56,   137,   156,     6,     6,   156,     6,   156,
      64,     5,     7,    56,    57,    57,     3,    59,    47,    56,
       3,    59,    57,    57,   166,   155,   149,   145,     7,   156,
      60,   153,     7,    58,     5,    55,    57,    56,    56,    56,
     137,   156,    56,   137,   156,     6,    56,   137,   156,     6,
       7,    64,   155,     7,    57,   134,   134,   156,    60,    55,
     156,    60,   134,   134,    56,    56,   155,     3,   168,   153,
     137,   156,   134,    57,    57,    57,    56,    56,    57,    56,
      56,    56,   137,   156,    57,    56,    56,    56,   137,   156,
     155,     7,     5,   155,   134,    58,    58,     3,   166,     3,
      58,    58,     7,    57,   156,    56,    56,    58,   134,   134,
     134,    57,    57,   134,    57,    57,    57,    56,    56,   134,
      57,    57,    57,    56,    56,   155,    64,    57,    58,    75,
      75,   156,    56,   156,   155,   134,    58,    58,    58,   134,
     134,    58,   134,   134,   134,    57,    57,    58,   134,   134,
     134,    57,    57,     7,   134,    57,   136,    57,   136,    57,
      58,    58,    58,    58,    58,    58,   134,   134,    58,    58,
      58,   134,   134,   155,    58,   134,   134,   134,    58,    58,
      58,    58,    58,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   132,   133,   134,   134,   135,   135,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   142,   142,   142,   142,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     145,   145,   145,   145,   146,   146,   146,   146,   147,   147,
     147,   148,   148,   149,   149,   149,   149,   149,   149,   149,
     149,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   151,
     151,   152,   153,   153,   153,   153,   154,   155,   155,   155,
     155,   155,   155,   155,   156,   156,   156,   157,   157,   157,
     158,   158,   158,   158,   158,   158,   158,   158,   159,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   161,
     161,   161,   161,   161,   161,   162,   162,   162,   163,   163,
     163,   164,   164,   164,   164,   164,   164,   164,   165,   166,
     166,   166,   166,   166,   166,   167,   167,   167,   167,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   169,   170,   170,   170,   170
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     2,     1,     1,
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
       4,     4,     6,     6,     8,     4,     6,     8,     4,     3,
       1,     3,     2,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       3,     3,     1,     1,     0,     4,     7,     5,     8,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       1,     3,     2,     3,     1,     0
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
#line 75 "parser.y" /* yacc.c:1646  */
    {
        debug("begin-1");
        root = new_node(BEGIN_NODE, 0, NO_TYPE);
        add_child(root, getAST((yyvsp[0])));
    }
#line 2291 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "parser.y" /* yacc.c:1646  */
    { debug("line-1"); (yyval) = (yyvsp[0]); }
#line 2297 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 84 "parser.y" /* yacc.c:1646  */
    { debug("line-2"); (yyval) = new_tupla(NULL, 0, NULL); }
#line 2303 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 89 "parser.y" /* yacc.c:1646  */
    {
        debug("stmt-list-1");
        tupla_add_child((yyvsp[-1]), (yyvsp[0]));
        (yyval) = (yyvsp[-1]);
    }
#line 2313 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "parser.y" /* yacc.c:1646  */
    {
        debug("stmt-list-2");
        (yyval) = (yyvsp[0]);
        //$$ = new_tupla(NULL, 0, new_node(BLOCK_NODE, 0, NO_TYPE));
        //tupla_add_child($$, $1);
    }
#line 2324 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "parser.y" /* yacc.c:1646  */
    { debug("stmt-1"); (yyval) = (yyvsp[-1]); }
#line 2330 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "parser.y" /* yacc.c:1646  */
    { debug("stmt-2"); }
#line 2336 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "parser.y" /* yacc.c:1646  */
    { debug("stmt-4"); }
#line 2342 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "parser.y" /* yacc.c:1646  */
    { debug("stmt-5"); }
#line 2348 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 124 "parser.y" /* yacc.c:1646  */
    {
        debug("assign-expr-2");
        //check_var($1);
        //check_assign( get_type($1), $3 );
        //change_type($1, $3);
    }
#line 2359 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 235 "parser.y" /* yacc.c:1646  */
    {
        debug("func-def-1");
    }
#line 2367 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 240 "parser.y" /* yacc.c:1646  */
    {
        debug("func-def-2");
    }
#line 2375 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 259 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-1");
        (yyval) = (yyvsp[0]);
        change_node((yyval), new_var((yyvsp[0]), UNKNOWN_TYPE));
    }
#line 2385 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 266 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-2");
        //new_var($2, $4);
    }
#line 2394 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 272 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-3");
    }
#line 2402 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 277 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-4");
        //new_var($2, $4);
    }
#line 2411 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 283 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-5");
        //new_var($2, $4);
    }
#line 2420 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 289 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-6");
    }
#line 2428 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 294 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-7");
    }
#line 2436 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 299 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-8");
        //new_var($2, UNKNOWN_TYPE);
    }
#line 2445 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 305 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-9");
        //new_var($2, $4);
    }
#line 2454 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 311 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-10");
    }
#line 2462 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 316 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-11");
        //new_var($2, $4);
    }
#line 2471 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 322 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-12");
        //new_var($2, $4);
    }
#line 2480 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 328 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-13");
    }
#line 2488 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 333 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-14");
    }
#line 2496 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 338 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-15");
        //new_var($2, $4);
    }
#line 2505 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 344 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-16");
        //new_var($2, $4);
    }
#line 2514 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 350 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-17");
    }
#line 2522 "parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 355 "parser.y" /* yacc.c:1646  */
    {
        debug("var-declr-18");
    }
#line 2530 "parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 363 "parser.y" /* yacc.c:1646  */
    {
        debug("id-list-2");
        (yyval) = (yyvsp[0]);
    }
#line 2539 "parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 385 "parser.y" /* yacc.c:1646  */
    { debug("var-type-1"); /* $$ = NUMBER_TYPE;  */}
#line 2545 "parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 386 "parser.y" /* yacc.c:1646  */
    { debug("var-type-2"); /* $$ = STRING_TYPE;  */}
#line 2551 "parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 387 "parser.y" /* yacc.c:1646  */
    { debug("var-type-3"); /* $$ = UNKNOWN_TYPE; */}
#line 2557 "parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 388 "parser.y" /* yacc.c:1646  */
    { debug("var-type-4"); /* $$ = BOOLEAN_TYPE; */}
#line 2563 "parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 389 "parser.y" /* yacc.c:1646  */
    { debug("var-type-5"); /* $$ = ANY_TYPE;     */}
#line 2569 "parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 390 "parser.y" /* yacc.c:1646  */
    { debug("var-type-6"); /* $$ = VOID_TYPE;    */}
#line 2575 "parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 391 "parser.y" /* yacc.c:1646  */
    { debug("var-type-7"); /* $$ = NEVER_TYPE;   */}
#line 2581 "parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 395 "parser.y" /* yacc.c:1646  */
    { debug("expr-1"); }
#line 2587 "parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 396 "parser.y" /* yacc.c:1646  */
    { debug("expr-2"); }
#line 2593 "parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 397 "parser.y" /* yacc.c:1646  */
    { debug("expr-3"); (yyval) = (yyvsp[-1]); }
#line 2599 "parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 401 "parser.y" /* yacc.c:1646  */
    { debug("idx-unsafe-expr-1"); }
#line 2605 "parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 402 "parser.y" /* yacc.c:1646  */
    { debug("idx-unsafe-expr-2"); }
#line 2611 "parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 403 "parser.y" /* yacc.c:1646  */
    { debug("idx-unsafe-expr-3"); }
#line 2617 "parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 407 "parser.y" /* yacc.c:1646  */
    { debug("idx-safe-expr-1"); }
#line 2623 "parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 408 "parser.y" /* yacc.c:1646  */
    { debug("idx-safe-expr-2"); }
#line 2629 "parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 409 "parser.y" /* yacc.c:1646  */
    { debug("idx-safe-expr-3"); }
#line 2635 "parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 410 "parser.y" /* yacc.c:1646  */
    { debug("idx-safe-expr-4"); }
#line 2641 "parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 411 "parser.y" /* yacc.c:1646  */
    { debug("idx-safe-expr-5"); }
#line 2647 "parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 412 "parser.y" /* yacc.c:1646  */
    { debug("idx-safe-expr-6"); }
#line 2653 "parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 413 "parser.y" /* yacc.c:1646  */
    { debug("idx-safe-expr-7"); }
#line 2659 "parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 415 "parser.y" /* yacc.c:1646  */
    {
        debug("idx-safe-expr-8");
        //check_var($1);
        //$$ = get_type($1);
    }
#line 2669 "parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 429 "parser.y" /* yacc.c:1646  */
    {
        debug("unary-expr-1");
        //check_var($2);
    }
#line 2678 "parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 437 "parser.y" /* yacc.c:1646  */
    {
        debug("unary-expr-3");
        //check_var($2);
    }
#line 2687 "parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 445 "parser.y" /* yacc.c:1646  */
    {
        debug("unary-expr-5");
        //check_var($1);
    }
#line 2696 "parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 453 "parser.y" /* yacc.c:1646  */
    {
        debug("unary-expr-7");
        //check_var($1);
    }
#line 2705 "parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 468 "parser.y" /* yacc.c:1646  */
    {
        debug("arit-expr-1");
        //$$ = unify_bin_op($1, $3, "+", unify_plus);
    }
#line 2714 "parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 474 "parser.y" /* yacc.c:1646  */
    {
        debug("arit-expr-2");
    }
#line 2722 "parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 511 "parser.y" /* yacc.c:1646  */
    { debug("args-list-1"); (yyval) = (yyvsp[0]); }
#line 2728 "parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 512 "parser.y" /* yacc.c:1646  */
    { debug("args-list-2"); }
#line 2734 "parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 513 "parser.y" /* yacc.c:1646  */
    { debug("args-list-3"); }
#line 2740 "parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 514 "parser.y" /* yacc.c:1646  */
    { debug("args-list-4"); }
#line 2746 "parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 515 "parser.y" /* yacc.c:1646  */
    { debug("args-list-5"); }
#line 2752 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 516 "parser.y" /* yacc.c:1646  */
    { debug("args-list-6"); }
#line 2758 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 527 "parser.y" /* yacc.c:1646  */
    { debug("var-val-1");  /*$$ = NUMBER_TYPE;  */}
#line 2764 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 528 "parser.y" /* yacc.c:1646  */
    { debug("var-val-2");  /*$$ = NUMBER_TYPE;  */}
#line 2770 "parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 529 "parser.y" /* yacc.c:1646  */
    { debug("var-val-3");  /*$$ = STRING_TYPE;  */}
#line 2776 "parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 530 "parser.y" /* yacc.c:1646  */
    { debug("var-val-4");  /*$$ = BOOLEAN_TYPE; */}
#line 2782 "parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 531 "parser.y" /* yacc.c:1646  */
    { debug("var-val-5");  /*$$ = BOOLEAN_TYPE; */}
#line 2788 "parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 532 "parser.y" /* yacc.c:1646  */
    { debug("var-val-6");  /*$$ = NUMBER_TYPE;  */}
#line 2794 "parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 533 "parser.y" /* yacc.c:1646  */
    { debug("var-val-7");  /*$$ = NUMBER_TYPE;  */}
#line 2800 "parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 534 "parser.y" /* yacc.c:1646  */
    { debug("var-val-8");  /*$$ = STRING_TYPE;  */}
#line 2806 "parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 535 "parser.y" /* yacc.c:1646  */
    { debug("var-val-9");  /*$$ = BOOLEAN_TYPE; */}
#line 2812 "parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 536 "parser.y" /* yacc.c:1646  */
    { debug("var-val-10"); /*$$ = BOOLEAN_TYPE; */}
#line 2818 "parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 546 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list-1"); (yyval) = (yyvsp[0]); }
#line 2824 "parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 547 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list-2"); }
#line 2830 "parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 548 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list-3"); }
#line 2836 "parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 549 "parser.y" /* yacc.c:1646  */
    { debug("elmts-list-4"); }
#line 2842 "parser.c" /* yacc.c:1646  */
    break;


#line 2846 "parser.c" /* yacc.c:1646  */
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
#line 552 "parser.y" /* yacc.c:1906  */


void debug(char *text) {
    printf("DEBUG\t%s\n", text);
}

// -----------------------------------------------------------------------

AST* check_var(Tupla* tupla) {

    struct node *item = findVar(vt, tupla_get_name(tupla));

    printf("CHECK_VAR\tyylineno: %d,\tname: %s\n", yylineno, tupla_get_name(tupla));

    if (item == NULL) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", yylineno, tupla_get_name(tupla));
        exit(EXIT_FAILURE);
    }

    return NULL;
}

AST* new_var(Tupla* tupla, Type type) {

    printf("NEW_VAR\t\tyylineno: %d,\tname: %s,\tline: %d,\ttype: %s\n",
            yylineno, tupla_get_name(tupla), tupla_get_line(tupla), get_text(type));

    struct node *item = findVar(vt, tupla_get_name(tupla));

    if (item != NULL) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                tupla_get_line(tupla), tupla_get_name(tupla), getLine(item));
        exit(EXIT_FAILURE);
    }

    int idx = addVar(&vt, tupla_get_line(tupla), tupla_get_name(tupla), type);

    return new_node(VAR_DECL_NODE, idx, type);
}

// -----------------------------------------------------------------------

AST* unify_bin_op(Type left, Type right, const char* op, Type (*unify)(Type, Type)) {

    printf("UNIFY\t\tyylineno: %d,\tleft: %s,\tright: %s,\top: %s\n",
            yylineno, get_text(left), get_text(right), op);

    Type unif = unify(left, right);

    if (unif == NO_TYPE) {
        type_error(op, left, right);
    }

    return NULL;
}

AST* check_assign(Type left, Type right) {

    printf("CHECK_ASSIGN\tyylineno: %d,\tleft: %s,\tright: %s\n",
            yylineno, get_text(left), get_text(right));

    switch(left) {

        case NUMBER_TYPE:
            switch(right) {
                case NUMBER_TYPE:  break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case STRING_TYPE:
            switch(right) {
                case STRING_TYPE:  break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case BOOLEAN_TYPE:
            switch(right) {
                case BOOLEAN_TYPE: break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case VOID_TYPE:
            switch(right) {
                case VOID_TYPE:    break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case NEVER_TYPE:
            switch(right) {
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        default: break;
    }

    return NULL;
}

AST* change_type(Tupla* tupla, Type type) {
    printf("ADD_TYPE\t\tname: %s,\ttype: %s\n", get_text(type), tupla_get_name(tupla));
    changeVarType(vt, tupla_get_name(tupla), type);
    return NULL;
}

// -----------------------------------------------------------------------

void type_error(const char *op, Type left, Type right) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
            yylineno, op, get_text(left), get_text(right));
    exit(EXIT_FAILURE);
}

void yyerror(const char *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

// -----------------------------------------------------------------------

int main(void) {

    st = createStrTable();
    vt = createVarTable();

    yyparse();
    printf("Parse successful\n");
    
    printVars(vt);
    printStrs(st);

    print_dot(root);

    freeVars(&vt);
    freeStrs(&st);
    free_tree(root);

    yylex_destroy();

    return 0;
}
