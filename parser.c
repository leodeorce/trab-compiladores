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
#include <string.h>
#include "types.h"
#include "list.h"
#include "tupla.h"
#include "ast.h"
#include "parser.h"
#include "interpreter.h"

int  yylex(void);
void yyerror(const char* s);
int  yylex_destroy(void);

int  check_var(Tupla* tupla);
AST* new_var(Tupla* tupla, Type type);

Type unify(Type left, Type right, const char*, Type (*unify)(Type, Type));
Conv check_assign(Type left, Type right);
void check_bool_type(const char* cmd, Type type);
void check_name(Tupla* tupla, const char* name);
Conv check_string(Tupla* tupla);

void free_tupla_full(Tupla* t1, Tupla* t2);

void type_error(const char*, Type, Type);

extern char *yytext;
extern int  yylineno;

Var_table *vt;
Str_table *st;

AST *root;


#line 105 "parser.c" /* yacc.c:339  */

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

#line 288 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  108
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  451

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
       0,    79,    79,    88,    89,    94,   101,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     127,   129,   152,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   196,   197,   202,
     213,   218,   229,   242,   255,   256,   257,   262,   271,   273,
     282,   284,   293,   305,   314,   323,   332,   334,   343,   354,
     358,   359,   360,   361,   365,   366,   367,   368,   372,   373,
     374,   378,   379,   383,   384,   385,   386,   387,   388,   389,
     390,   395,   402,   411,   413,   421,   432,   433,   434,   435,
     436,   437,   441,   442,   446,   447,   451,   455,   456,   457,
     458,   462,   466,   467,   468,   469,   470,   471,   472,   476,
     477,   478,   482,   483,   484,   488,   489,   490,   491,   492,
     493,   494,   495,   506,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   524,   533,   542,   551,   560,   561,
     565,   566,   567,   571,   572,   573,   577,   578,   580,   588,
     589,   590,   591,   595,   605,   606,   607,   609,   625,   626,
     630,   631,   632,   633,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   650,   654,   655,   656,   657
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
  "func-def", "params", "var-declr", "var-declr-rw", "id-list", "obj-def",
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

#define YYPACT_NINF -247

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-247)))

#define YYTABLE_NINF -174

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     860,   -36,   119,   -34,  1129,  1129,  1129,    91,  -247,  -247,
    -247,  1250,    27,   -26,   -17,    53,   -14,  -247,    29,    -1,
      33,  -247,    18,   627,  -247,  -247,    38,    87,  -247,   860,
    -247,    84,  -247,  -247,  -247,  -247,  -247,  -247,  -247,    86,
      36,  1466,  -247,  -247,  1392,  -247,  -247,  -247,  -247,  1334,
      92,  -247,  -247,  -247,    23,    93,  -247,  -247,  -247,  -247,
    -247,    23,    93,   152,  -247,  -247,    35,  -247,  1681,    91,
     100,    46,  -247,    44,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,   513,  -247,
    -247,  -247,   566,  1129,  1129,  -247,    52,    20,   108,  -247,
     860,    -3,    57,  1183,   -19,  -247,  1510,  1183,  -247,  -247,
    -247,  -247,    37,   110,  -247,  1129,  1129,  1129,  1129,  1129,
    1129,  1129,  1129,  1129,  1129,  1129,  1129,  1129,  1129,  1129,
    1129,  1129,  1129,  1129,  1129,  1129,  1129,  1129,  1129,    50,
    -247,  -247,  1129,    76,   566,  -247,  -247,    91,  -247,    23,
      93,    92,  -247,  -247,  -247,  -247,  -247,  -247,  -247,   103,
    2149,   566,   136,  1422,    95,  2071,   101,  2071,     4,    83,
     285,   919,   104,   641,  1288,   159,   161,  1392,  1365,     9,
     112,  1720,   285,   566,  -247,   115,  1759,   285,   919,   183,
     183,   153,   153,   153,   153,   475,   203,    32,  2110,  2110,
    2110,  2149,  2149,  2149,  2149,  2149,  2149,  2149,  2149,    16,
      16,    16,  2071,   120,  -247,  2071,    23,    93,   123,  -247,
     128,  -247,   566,   566,   174,  -247,     4,    14,  -247,  -247,
    -247,   129,   180,   124,   185,  -247,     5,    11,  -247,  2071,
      85,   931,  1554,   660,   719,   130,    49,   137,   142,   144,
     158,   156,   157,   160,    17,  -247,  2071,  -247,   566,  -247,
    -247,  -247,   285,     9,  -247,     4,   202,  1129,   150,    11,
     206,   163,   210,   168,   170,   162,  1798,   985,   997,  1598,
    1051,  1642,   218,   165,   285,     8,   860,   860,   175,  -247,
     860,   860,  1129,   176,   181,  -247,   182,  -247,   285,  2071,
     237,  -247,    94,  -247,    11,  1183,   860,   184,   186,   193,
     197,  1837,   198,   204,  1876,  1063,   201,   207,  1915,  1117,
     285,   252,   257,   285,   860,   208,   209,   566,   236,   239,
    2071,   261,  -247,    15,  -247,  1129,  -247,  -247,   244,  1954,
     243,   860,   860,   860,   238,   245,   860,   246,   248,   249,
     251,  1993,   860,   253,   254,   255,   258,  2032,  -247,   285,
     256,   260,   250,   190,   234,   262,  -247,  -247,  1129,   285,
     860,  2071,  -247,  -247,  -247,   265,   266,   268,   860,   860,
     270,   860,   860,   860,   273,   274,   275,   860,   860,   860,
     277,   278,  -247,   306,   860,  -247,   742,   801,  -247,  2071,
     281,   282,  -247,  -247,  -247,   283,   313,  -247,   314,   315,
     316,   860,   860,  -247,   317,   320,   322,   860,   860,   285,
     323,   860,  -247,   860,  -247,   860,  -247,  -247,  -247,  -247,
    -247,  -247,   326,   327,  -247,  -247,  -247,   330,   331,  -247,
    -247,   333,   334,   335,  -247,  -247,  -247,  -247,  -247,  -247,
    -247
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,   198,   184,   185,
     186,   142,     0,     0,     0,     0,     0,   188,     0,     0,
       0,   112,     0,     0,   187,   113,     0,     0,     2,     3,
       6,     0,    15,    14,    13,    12,   133,     9,     8,     0,
       0,     0,   130,   129,   141,   140,   137,   138,   139,   136,
       0,   134,   135,   132,   144,   145,   189,   190,   191,   193,
     192,   146,   147,   142,   153,   141,   136,   152,     0,   198,
     197,     0,    41,     0,   148,    45,   150,    46,    47,    48,
      49,    50,    51,    52,    53,    42,    43,    44,     0,    54,
      55,    56,   179,     0,     0,    18,     0,   115,     0,    19,
       4,     0,     0,     0,     0,    16,     0,     0,     1,     5,
      11,     7,   115,   101,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,   151,     0,     0,   179,   131,   195,   198,   194,   172,
     166,   168,   127,   126,   124,   128,   122,   123,   125,     0,
      72,   179,   178,   177,     0,     0,   129,    21,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,     0,   179,    17,     0,     0,     0,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    76,    77,
      78,    67,    68,    69,    70,    71,    73,    74,    75,   163,
     164,   165,    22,   167,   171,    20,   169,   170,     0,   196,
       0,   174,   179,   179,   180,   143,    83,     0,    89,    90,
      88,     0,    82,     0,   115,   114,     0,   120,   111,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   103,   102,   173,   179,   176,
     175,    80,     0,   100,    79,    83,     0,     0,     0,   120,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     4,     4,     0,   182,
       4,     4,     0,     0,     0,    84,     0,    81,     0,   109,
       0,   117,     0,   116,   120,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    98,     0,     4,     0,     0,   179,     0,     0,
     105,   106,   181,     0,    85,     0,   121,   118,     0,     0,
       0,     4,     4,     4,     0,     0,     4,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,    64,    61,     0,    60,    59,     0,     0,
       4,   110,    58,    57,    40,     0,     0,     0,     4,     4,
       0,     4,     4,     4,     0,     0,     0,     4,     4,     4,
       0,     0,    99,    97,     4,    91,     0,     0,   183,   107,
       0,     0,    39,    38,    37,     0,     0,    28,     0,     0,
       0,     4,     4,    34,     0,     0,     0,     4,     4,     0,
       0,     4,    66,     4,    63,     4,    86,    36,    35,    27,
      26,    25,     0,     0,    33,    32,    31,     0,     0,    96,
      92,     0,     0,     0,    24,    23,    30,    29,    65,    62,
      87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,    96,  -247,   -29,   321,  -247,   -32,  -247,  -247,
    -247,  -247,  -247,  -195,  -247,  -247,  -247,    56,   231,  -247,
     -21,   151,  -246,  -247,  -120,   154,  -247,   286,   228,  -247,
    -247,  -247,  -247,     1,   -62,  -143,  -247,     2,  -247,   -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,    30,    31,    32,    94,    33,    34,
      35,    36,    37,   231,   232,   233,    38,   247,    39,    40,
      98,   238,   271,   272,   159,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   164,    51,    52,    53,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   218,    55,   173,    62,    66,    66,    66,   267,    70,
     226,   151,   138,   146,   245,   323,   269,   142,   221,   113,
     292,   262,   369,   301,    66,   169,   182,   170,    54,   115,
      61,   261,   116,    95,    73,   117,   183,   118,    96,   119,
     251,   120,   169,   100,   187,   115,   139,    97,   116,   140,
     236,   117,   141,   118,   283,   119,   284,   120,   337,    99,
     121,   174,   250,   102,   268,   324,    14,   254,   227,   263,
     297,    70,   370,   246,   150,   270,   293,   214,   144,   259,
     260,   135,   104,   136,   101,   137,    21,   108,   103,    66,
     110,   219,   111,   107,    66,    66,    69,   228,   229,   230,
     112,    25,   178,   143,   139,   147,   148,     2,   149,   168,
       2,   171,   179,   188,   213,   294,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
     216,   222,   295,    66,   217,   138,   142,   234,   235,    70,
     220,   224,     8,     9,    10,     8,     9,    10,    64,    67,
      68,   225,   240,    73,   322,   243,    74,   244,   248,    76,
      17,   252,    66,    17,    66,   144,   119,   106,   334,   257,
      56,    57,    58,   258,   365,  -173,   265,   264,   266,    66,
     169,   273,    24,   285,   282,    24,   172,    88,    59,   286,
     358,   287,   117,   361,   118,   288,   119,    92,   120,   298,
     300,    93,   289,   302,   290,   304,   115,   291,   307,   116,
      60,   303,   117,   305,   118,   320,   119,   306,   120,   321,
     327,   121,    65,    65,    65,   123,   331,   332,   333,   392,
     335,   341,   160,   342,    66,    66,   163,   165,   167,   400,
     343,    65,   135,   344,   136,   346,   137,   181,   352,   359,
     347,   186,   360,   353,   368,   396,   363,   364,    66,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    66,   366,   378,   215,   367,   163,   439,
     372,   374,   379,   381,   336,   382,   383,   384,   395,   397,
     387,   388,   389,   419,   390,   163,    65,   394,   398,   296,
     393,    65,    65,   402,   403,   239,   404,   242,   407,   177,
     411,   412,   176,   413,   417,   418,    66,   163,   425,   255,
     426,   427,   256,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,   422,   424,    66,
      65,   428,   429,   430,   431,   434,   163,   163,   435,   166,
     436,   440,   325,   326,   444,   445,   328,   329,   446,   447,
     152,   448,   449,   450,     0,   276,     0,   279,   281,    65,
       0,    65,   340,   153,   154,     0,     0,     0,     0,   155,
     156,   157,   163,   162,   158,     0,    65,     0,     0,     0,
     362,   299,   175,     0,   180,     0,     0,     0,   185,     0,
       0,   311,   314,     0,   318,     0,     0,   375,   376,   377,
       0,     0,   380,     0,     0,     0,   330,     0,   386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   339,
       0,     0,     0,     0,     0,   162,   401,     0,     0,   351,
       0,    65,    65,   357,   405,   406,     0,   408,   409,   410,
       0,   163,   162,   414,   415,   416,     0,     0,   115,   371,
     420,   116,     0,     0,   117,    65,   118,     0,   119,     0,
     120,     0,     0,     0,   162,     0,     0,   432,   433,     0,
       0,     0,     0,   437,   438,     0,     0,   441,     0,   442,
      65,   443,   399,     0,   135,     0,   136,     1,   137,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,   162,   162,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,    65,     0,     0,     0,     0,     6,     0,
       0,   161,     7,     0,     8,     9,    10,    63,     0,   162,
       1,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     4,     0,     0,    65,     0,   310,   313,
       5,   317,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,   152,     0,
       0,     6,     0,     0,     0,     7,   338,     8,     9,    10,
      11,   153,   154,   105,     0,     0,   350,   155,   156,   157,
     356,     1,   158,     2,     3,    17,     0,   241,   162,     0,
       0,     0,     0,     0,     4,     1,    22,     2,     3,     0,
       0,     5,     0,     0,     0,     0,   278,    24,     4,     0,
       0,     0,     0,     0,     1,     5,     2,     3,     0,     0,
       0,     0,     6,     0,     0,     0,     7,     4,     8,     9,
      10,    63,     0,     0,     5,     0,     6,     0,     0,     0,
       7,     0,     8,     9,    10,    63,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,    22,     0,     7,
      17,     8,     9,    10,    63,   280,     0,     0,    24,     0,
       0,    22,     0,     1,     0,     2,     3,     0,     0,    17,
       0,     0,    24,     0,     0,     0,     4,     0,     0,     0,
      22,     0,     0,     5,     0,     0,     1,     0,     2,     3,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     6,     0,     5,     0,     7,     0,
       8,     9,    10,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,    17,   421,
       0,     7,     0,     8,     9,    10,    11,    12,     0,    22,
      13,    14,    15,     0,     0,     1,    16,     2,     3,     0,
      24,    17,     0,    18,    19,    20,     0,     0,     4,     0,
       0,    21,    22,     0,     0,     5,     0,     0,    23,     0,
       0,     0,     0,    24,     0,     0,    25,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     6,     0,   423,     0,
       7,     0,     8,     9,    10,    11,    12,     0,     0,    13,
      14,    15,     0,     0,     1,    16,     2,     3,     0,     0,
      17,     0,    18,    19,    20,     0,     0,     4,     0,     0,
      21,    22,     0,     0,     5,     0,     0,    23,     0,     0,
       0,     0,    24,     0,     0,    25,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     7,
       0,     8,     9,    10,    11,    12,     0,     0,    13,    14,
      15,     0,     0,     1,    16,     2,     3,     0,     0,    17,
       0,    18,    19,    20,     0,     1,     4,     2,     3,    21,
      22,     0,     0,     5,     0,     0,    23,     0,     4,     0,
       0,    24,     0,     0,    25,     5,    26,     0,     0,     0,
       0,     0,     0,     0,     6,     0,   237,     0,     7,     0,
       8,     9,    10,    63,     0,     0,     6,   274,     0,     0,
       7,     0,     8,     9,    10,    11,     0,     0,    17,     1,
       0,     2,     3,     0,     0,     0,     0,     0,     0,    22,
      17,     1,     4,     2,     3,     0,     0,     0,     0,     5,
      24,    22,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     5,    24,     0,     0,     0,     0,     0,     0,     0,
       6,   309,     0,     0,     7,     0,     8,     9,    10,    11,
       0,     0,     6,   312,     0,     0,     7,     0,     8,     9,
      10,    11,     0,     0,    17,     1,     0,     2,     3,     0,
       0,     0,     0,     0,     0,    22,    17,     1,     4,     2,
       3,     0,     0,     0,     0,     5,    24,    22,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     5,    24,     0,
       0,     0,     0,     0,     0,     0,     6,   316,     0,     0,
       7,     0,     8,     9,    10,    11,     0,     0,     6,   349,
       0,     0,     7,     0,     8,     9,    10,    11,     0,     0,
      17,     1,     0,     2,     3,     0,     0,     0,     0,     0,
       0,    22,    17,     1,     4,     2,     3,     0,     0,     0,
       0,     5,    24,    22,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     5,    24,     0,     0,     0,     0,     0,
       0,     0,     6,   355,     0,     0,     7,     0,     8,     9,
      10,    11,     0,     0,     6,     0,     0,     0,     7,     0,
       8,     9,    10,    63,     0,     0,    17,     1,     0,     2,
       3,     0,     0,     0,     0,     0,     0,    22,    17,     0,
       4,     0,     0,     0,     0,     0,     0,     5,    24,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     7,     0,     8,     9,    10,    11,     0,     0,
       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,    73,    17,     0,    74,    75,     0,    76,    77,     0,
      78,     0,    79,    22,    80,     0,    81,     0,     0,    82,
       0,    83,     0,    84,    24,     0,    85,     0,    86,     0,
      87,    72,     0,     0,     0,    88,     0,     0,     0,    73,
      89,     0,    90,    75,    91,    92,    77,     0,    78,    93,
      79,     0,    80,     0,    81,     0,     0,    82,     0,    83,
       0,    84,     0,     0,    85,     0,    86,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    89,     0,
      90,     0,    91,   144,     0,   139,     0,    93,   140,    75,
       0,   141,    77,     0,    78,     0,    79,     0,    80,     0,
      81,     0,     0,    82,     0,    83,     0,    84,    72,     0,
      85,     0,    86,     0,    87,     0,   139,     0,     0,     0,
      75,     0,     0,    77,    89,    78,    90,    79,    91,    80,
       0,    81,     0,     0,    82,    72,    83,     0,    84,     0,
       0,    85,     0,    86,     0,    87,     0,    75,     0,     0,
      77,     0,    78,     0,    79,    89,    80,    90,    81,    91,
       0,    82,     0,    83,     0,    84,     0,   223,    85,     0,
      86,     0,    87,     0,     0,   115,     0,     0,   116,     0,
       0,   117,    89,   118,    90,   119,    91,   120,     0,     0,
     121,     0,   122,     0,   123,     0,     0,   124,     0,   125,
       0,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   114,   136,     0,   137,     0,     0,     0,   115,
       0,     0,   116,     0,     0,   117,     0,   118,     0,   119,
       0,   120,     0,     0,   121,     0,   122,     0,   123,     0,
       0,   124,     0,   125,     0,   126,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   184,   136,     0,   137,
       0,     0,     0,   115,     0,     0,   116,     0,     0,   117,
       0,   118,     0,   119,     0,   120,     0,     0,   121,     0,
     122,     0,   123,     0,     0,   124,     0,   125,     0,   126,
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     277,   136,     0,   137,     0,     0,     0,   115,     0,     0,
     116,     0,     0,   117,     0,   118,     0,   119,     0,   120,
       0,     0,   121,     0,   122,     0,   123,     0,     0,   124,
       0,   125,     0,   126,     0,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   315,   136,     0,   137,     0,     0,
       0,   115,     0,     0,   116,     0,     0,   117,     0,   118,
       0,   119,     0,   120,     0,     0,   121,     0,   122,     0,
     123,     0,     0,   124,     0,   125,     0,   126,     0,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   319,   136,
       0,   137,     0,     0,     0,   115,     0,     0,   116,     0,
       0,   117,     0,   118,     0,   119,     0,   120,     0,     0,
     121,     0,   122,     0,   123,     0,     0,   124,     0,   125,
       0,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   136,   115,   137,     0,   116,     0,     0,
     117,     0,   118,     0,   119,     0,   120,     0,     0,   121,
       0,   122,     0,   123,     0,     0,   124,     0,   125,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,   136,   115,   137,     0,   116,   145,     0,   117,
       0,   118,     0,   119,     0,   120,     0,     0,   121,     0,
     122,     0,   123,     0,     0,   124,     0,   125,     0,   126,
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,   136,   115,   137,     0,   116,   249,     0,   117,     0,
     118,     0,   119,     0,   120,     0,     0,   121,     0,   122,
       0,   123,     0,     0,   124,     0,   125,     0,   126,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
     136,   115,   137,     0,   116,   253,     0,   117,     0,   118,
       0,   119,     0,   120,     0,     0,   121,     0,   122,     0,
     123,     0,     0,   124,     0,   125,     0,   126,     0,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,   136,
     115,   137,     0,   116,   308,     0,   117,     0,   118,     0,
     119,     0,   120,     0,     0,   121,     0,   122,     0,   123,
       0,     0,   124,     0,   125,     0,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,   136,   115,
     137,     0,   116,   345,     0,   117,     0,   118,     0,   119,
       0,   120,     0,     0,   121,     0,   122,     0,   123,     0,
       0,   124,     0,   125,     0,   126,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,   136,   115,   137,
       0,   116,   348,     0,   117,     0,   118,     0,   119,     0,
     120,     0,     0,   121,     0,   122,     0,   123,     0,     0,
     124,     0,   125,     0,   126,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,   136,   115,   137,     0,
     116,   354,     0,   117,     0,   118,     0,   119,     0,   120,
       0,     0,   121,     0,   122,     0,   123,     0,     0,   124,
       0,   125,     0,   126,     0,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,   136,   115,   137,     0,   116,
     373,     0,   117,     0,   118,     0,   119,     0,   120,     0,
       0,   121,     0,   122,     0,   123,     0,     0,   124,     0,
     125,     0,   126,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,   136,   115,   137,     0,   116,   385,
       0,   117,     0,   118,     0,   119,     0,   120,     0,     0,
     121,     0,   122,     0,   123,     0,     0,   124,     0,   125,
       0,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   136,   115,   137,     0,   116,   391,     0,
     117,     0,   118,     0,   119,     0,   120,     0,     0,   121,
       0,   122,     0,   123,     0,     0,   124,     0,   125,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,   136,   115,   137,     0,   116,     0,     0,   117,
       0,   118,     0,   119,     0,   120,     0,     0,   121,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,   136,   115,   137,     0,   116,     0,     0,   117,     0,
     118,     0,   119,     0,   120,     0,     0,   121,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
     136,     0,   137
};

static const yytype_int16 yycheck[] =
{
      29,   144,     1,     6,     3,     4,     5,     6,     3,     7,
       6,    73,    44,    69,     5,     7,     5,    49,   161,    40,
       3,     7,     7,   269,    23,     5,    45,     7,    64,    13,
      64,   226,    16,     6,    11,    19,    55,    21,    64,    23,
     183,    25,     5,    57,     7,    13,    11,    64,    16,    14,
     170,    19,    17,    21,     5,    23,     7,    25,   304,     6,
      28,    64,   182,    64,    59,    57,    69,   187,    64,    55,
     265,    69,    57,    64,    73,    64,    59,   139,    55,   222,
     223,    49,    64,    51,    55,    53,    89,     0,    55,    88,
       6,   147,     6,    55,    93,    94,     5,    93,    94,    95,
      64,   104,   101,    11,    11,     5,    60,    16,    64,    57,
      16,     3,    55,     3,    64,   258,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      64,     5,   262,   142,   143,   177,   178,    64,   169,   147,
      47,    56,    61,    62,    63,    61,    62,    63,     4,     5,
       6,    60,    58,    11,   284,     6,    14,     6,    56,    17,
      79,    56,   171,    79,   173,    55,    23,    23,   298,    56,
      61,    62,    63,    55,   327,    11,     6,    58,    64,   188,
       5,   106,   101,    56,    64,   101,   100,    45,    79,    57,
     320,    57,    19,   323,    21,    47,    23,    55,    25,     7,
      60,    59,    56,     7,    57,     5,    13,    57,    56,    16,
     101,    58,    19,    55,    21,     7,    23,    57,    25,    64,
      55,    28,     4,     5,     6,    32,    60,    56,    56,   359,
       3,    57,    88,    57,   243,   244,    92,    93,    94,   369,
      57,    23,    49,    56,    51,    57,    53,   103,    57,     7,
      56,   107,     5,    56,     3,    75,    58,    58,   267,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   292,    58,    57,   142,    58,   144,   419,
      56,    58,    57,    57,   302,    57,    57,    56,    58,    75,
      57,    57,    57,     7,    56,   161,    88,    57,    56,   263,
      64,    93,    94,    58,    58,   171,    58,   173,    58,   101,
      57,    57,   101,    58,    57,    57,   335,   183,    57,   188,
      58,    58,   188,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   396,   397,   368,
     142,    58,    58,    58,    58,    58,   222,   223,    58,    93,
      58,    58,   286,   287,    58,    58,   290,   291,    58,    58,
     105,    58,    58,    58,    -1,   241,    -1,   243,   244,   171,
      -1,   173,   306,   118,   119,    -1,    -1,    -1,    -1,   124,
     125,   126,   258,    92,   129,    -1,   188,    -1,    -1,    -1,
     324,   267,   101,    -1,   103,    -1,    -1,    -1,   107,    -1,
      -1,   277,   278,    -1,   280,    -1,    -1,   341,   342,   343,
      -1,    -1,   346,    -1,    -1,    -1,   292,    -1,   352,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,
      -1,    -1,    -1,    -1,    -1,   144,   370,    -1,    -1,   315,
      -1,   243,   244,   319,   378,   379,    -1,   381,   382,   383,
      -1,   327,   161,   387,   388,   389,    -1,    -1,    13,   335,
     394,    16,    -1,    -1,    19,   267,    21,    -1,    23,    -1,
      25,    -1,    -1,    -1,   183,    -1,    -1,   411,   412,    -1,
      -1,    -1,    -1,   417,   418,    -1,    -1,   421,    -1,   423,
     292,   425,   368,    -1,    49,    -1,    51,    14,    53,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,   222,   223,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   335,    -1,    -1,    -1,    -1,    55,    -1,
      -1,     5,    59,    -1,    61,    62,    63,    64,    -1,   258,
      14,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    27,    -1,    -1,   368,    -1,   277,   278,
      34,   280,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,    55,    -1,    -1,    -1,    59,   305,    61,    62,    63,
      64,   118,   119,     6,    -1,    -1,   315,   124,   125,   126,
     319,    14,   129,    16,    17,    79,    -1,     6,   327,    -1,
      -1,    -1,    -1,    -1,    27,    14,    90,    16,    17,    -1,
      -1,    34,    -1,    -1,    -1,    -1,     6,   101,    27,    -1,
      -1,    -1,    -1,    -1,    14,    34,    16,    17,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    27,    61,    62,
      63,    64,    -1,    -1,    34,    -1,    55,    -1,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    90,    -1,    59,
      79,    61,    62,    63,    64,     6,    -1,    -1,   101,    -1,
      -1,    90,    -1,    14,    -1,    16,    17,    -1,    -1,    79,
      -1,    -1,   101,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      90,    -1,    -1,    34,    -1,    -1,    14,    -1,    16,    17,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    55,    -1,    34,    -1,    59,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    79,    57,
      -1,    59,    -1,    61,    62,    63,    64,    65,    -1,    90,
      68,    69,    70,    -1,    -1,    14,    74,    16,    17,    -1,
     101,    79,    -1,    81,    82,    83,    -1,    -1,    27,    -1,
      -1,    89,    90,    -1,    -1,    34,    -1,    -1,    96,    -1,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    57,    -1,
      59,    -1,    61,    62,    63,    64,    65,    -1,    -1,    68,
      69,    70,    -1,    -1,    14,    74,    16,    17,    -1,    -1,
      79,    -1,    81,    82,    83,    -1,    -1,    27,    -1,    -1,
      89,    90,    -1,    -1,    34,    -1,    -1,    96,    -1,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    68,    69,
      70,    -1,    -1,    14,    74,    16,    17,    -1,    -1,    79,
      -1,    81,    82,    83,    -1,    14,    27,    16,    17,    89,
      90,    -1,    -1,    34,    -1,    -1,    96,    -1,    27,    -1,
      -1,   101,    -1,    -1,   104,    34,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    57,    -1,    59,    -1,
      61,    62,    63,    64,    -1,    -1,    55,    56,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    -1,    -1,    79,    14,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      79,    14,    27,    16,    17,    -1,    -1,    -1,    -1,    34,
     101,    90,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    59,    -1,    61,    62,    63,    64,
      -1,    -1,    55,    56,    -1,    -1,    59,    -1,    61,    62,
      63,    64,    -1,    -1,    79,    14,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    79,    14,    27,    16,
      17,    -1,    -1,    -1,    -1,    34,   101,    90,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    -1,    -1,    55,    56,
      -1,    -1,    59,    -1,    61,    62,    63,    64,    -1,    -1,
      79,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    79,    14,    27,    16,    17,    -1,    -1,    -1,
      -1,    34,   101,    90,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    59,    -1,    61,    62,
      63,    64,    -1,    -1,    55,    -1,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    -1,    -1,    79,    14,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    90,    79,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,   101,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    79,    -1,    14,    15,    -1,    17,    18,    -1,
      20,    -1,    22,    90,    24,    -1,    26,    -1,    -1,    29,
      -1,    31,    -1,    33,   101,    -1,    36,    -1,    38,    -1,
      40,     3,    -1,    -1,    -1,    45,    -1,    -1,    -1,    11,
      50,    -1,    52,    15,    54,    55,    18,    -1,    20,    59,
      22,    -1,    24,    -1,    26,    -1,    -1,    29,    -1,    31,
      -1,    33,    -1,    -1,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    50,    -1,
      52,    -1,    54,    55,    -1,    11,    -1,    59,    14,    15,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    24,    -1,
      26,    -1,    -1,    29,    -1,    31,    -1,    33,     3,    -1,
      36,    -1,    38,    -1,    40,    -1,    11,    -1,    -1,    -1,
      15,    -1,    -1,    18,    50,    20,    52,    22,    54,    24,
      -1,    26,    -1,    -1,    29,     3,    31,    -1,    33,    -1,
      -1,    36,    -1,    38,    -1,    40,    -1,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    50,    24,    52,    26,    54,
      -1,    29,    -1,    31,    -1,    33,    -1,     5,    36,    -1,
      38,    -1,    40,    -1,    -1,    13,    -1,    -1,    16,    -1,
      -1,    19,    50,    21,    52,    23,    54,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    -1,    -1,    35,    -1,    37,
      -1,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     6,    51,    -1,    53,    -1,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,
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
      48,    49,    -1,    51,    13,    53,    -1,    16,    -1,    -1,
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
      49,    -1,    51,    13,    53,    -1,    16,    -1,    -1,    19,
      -1,    21,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    13,    53,    -1,    16,    -1,    -1,    19,    -1,
      21,    -1,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    16,    17,    27,    34,    55,    59,    61,    62,
      63,    64,    65,    68,    69,    70,    74,    79,    81,    82,
      83,    89,    90,    96,   101,   104,   106,   133,   134,   135,
     136,   137,   138,   140,   141,   142,   143,   144,   148,   150,
     151,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   168,   169,   170,    64,   165,    61,    62,    63,    79,
     101,    64,   165,    64,   157,   160,   165,   157,   157,     5,
     169,   171,     3,    11,    14,    15,    17,    18,    20,    22,
      24,    26,    29,    31,    33,    36,    38,    40,    45,    50,
      52,    54,    55,    59,   139,     6,    64,    64,   152,     6,
      57,    55,    64,    55,    64,     6,   157,    55,     0,   136,
       6,     6,    64,   152,     6,    13,    16,    19,    21,    23,
      25,    28,    30,    32,    35,    37,    39,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    51,    53,   139,    11,
      14,    17,   139,    11,    55,    56,   171,     5,    60,    64,
     165,   166,   105,   118,   119,   124,   125,   126,   129,   156,
     157,     5,   137,   157,   167,   157,   159,   157,    57,     5,
       7,     3,   134,     6,    64,   137,   150,   160,   165,    55,
     137,   157,    45,    55,     6,   137,   157,     7,     3,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,    64,   166,   157,    64,   165,   167,   171,
      47,   167,     5,     5,    56,    60,     6,    64,    93,    94,
      95,   145,   146,   147,    64,   152,   156,    57,   153,   157,
      58,     6,   157,     6,     6,     5,    64,   149,    56,    56,
     156,   167,    56,    56,   156,   153,   157,    56,    55,   167,
     167,   145,     7,    55,    58,     6,    64,     3,    59,     5,
      64,   154,   155,   106,    56,   137,   157,     6,     6,   157,
       6,   157,    64,     5,     7,    56,    57,    57,    47,    56,
      57,    57,     3,    59,   167,   156,   149,   145,     7,   157,
      60,   154,     7,    58,     5,    55,    57,    56,    56,    56,
     137,   157,    56,   137,   157,     6,    56,   137,   157,     6,
       7,    64,   156,     7,    57,   134,   134,    55,   134,   134,
     157,    60,    56,    56,   156,     3,   169,   154,   137,   157,
     134,    57,    57,    57,    56,    56,    57,    56,    56,    56,
     137,   157,    57,    56,    56,    56,   137,   157,   156,     7,
       5,   156,   134,    58,    58,   167,    58,    58,     3,     7,
      57,   157,    56,    56,    58,   134,   134,   134,    57,    57,
     134,    57,    57,    57,    56,    56,   134,    57,    57,    57,
      56,    56,   156,    64,    57,    58,    75,    75,    56,   157,
     156,   134,    58,    58,    58,   134,   134,    58,   134,   134,
     134,    57,    57,    58,   134,   134,   134,    57,    57,     7,
     134,    57,   136,    57,   136,    57,    58,    58,    58,    58,
      58,    58,   134,   134,    58,    58,    58,   134,   134,   156,
      58,   134,   134,   134,    58,    58,    58,    58,    58,    58,
      58
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
     150,   150,   151,   151,   152,   152,   153,   154,   154,   154,
     154,   155,   156,   156,   156,   156,   156,   156,   156,   157,
     157,   157,   158,   158,   158,   159,   159,   159,   159,   159,
     159,   159,   159,   160,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   162,   162,   162,   162,
     163,   163,   163,   164,   164,   164,   165,   165,   165,   165,
     165,   165,   165,   166,   167,   167,   167,   167,   167,   167,
     168,   168,   168,   168,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   170,   171,   171,   171,   171
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
       0,     2,     4,     4,     4,     6,     6,     8,     4,     6,
       8,     4,     1,     1,     3,     1,     3,     2,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     2,     3,     3,     1,     1,     0,
       4,     7,     5,     8,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     3,     2,     3,     1,     0
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
#line 80 "parser.y" /* yacc.c:1646  */
    {
        root = new_node(BEGIN_NODE, 0, NO_TYPE);
        add_child(root, tupla_get_node((yyvsp[0])));
        free((yyvsp[0]));
    }
#line 2281 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2287 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_tupla(NULL, 0, NO_TYPE, NULL); }
#line 2293 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "parser.y" /* yacc.c:1646  */
    {
        tupla_add_child((yyvsp[-1]), (yyvsp[0]));
        (yyval) = (yyvsp[-1]);
        free((yyvsp[0]));
    }
#line 2303 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(BLOCK_NODE, 0, NO_TYPE));
        tupla_add_child((yyval), (yyvsp[0]));
        free((yyvsp[0]));
    }
#line 2313 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2319 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "parser.y" /* yacc.c:1646  */
    { tupla_free_name((yyvsp[-1])); (yyval) = (yyvsp[-1]); }
#line 2325 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2331 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2337 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2343 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "parser.y" /* yacc.c:1646  */
    {
        int  idx = check_var((yyvsp[-2]));
        Type id_type = getType(vt, idx);

        tupla_change_node((yyvsp[-2]), new_node(VAR_USE_NODE, idx, id_type));
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(ASSIGN_NODE, 0, NO_TYPE));

        Conv conversion = check_assign( id_type, tupla_get_type((yyvsp[0])) );

        if(conversion != NONE) {
            NodeKind conversion_nodekind = conv2node(conversion);
            AST* type_conversion = new_node(conversion_nodekind, 0, tupla_get_type((yyvsp[0])));
            add_child(type_conversion, tupla_get_node((yyvsp[-2])));
            add_child(tupla_get_node((yyval)), type_conversion);
        } else {
            tupla_add_child((yyval), (yyvsp[-2]));
        }

        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2369 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 203 "parser.y" /* yacc.c:1646  */
    {
        check_bool_type("while", tupla_get_type((yyvsp[-4])));
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(WHILE_NODE, 0, NO_TYPE));
        tupla_add_child((yyval), (yyvsp[-4]));
        tupla_add_child((yyval), (yyvsp[-1]));
        tupla_free_name((yyvsp[-4]));
        free((yyvsp[-4]));
        free((yyvsp[-1]));
    }
#line 2383 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 219 "parser.y" /* yacc.c:1646  */
    {
        check_bool_type("if", tupla_get_type((yyvsp[-4])));
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(IF_NODE, 0, NO_TYPE));
        tupla_add_child((yyval), (yyvsp[-4]));
        tupla_add_child((yyval), (yyvsp[-1]));
        tupla_free_name((yyvsp[-4]));
        free((yyvsp[-4]));
        free((yyvsp[-1]));
    }
#line 2397 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 230 "parser.y" /* yacc.c:1646  */
    {
        check_bool_type("if", tupla_get_type((yyvsp[-8])));
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(IF_NODE, 0, NO_TYPE));
        tupla_add_child((yyval), (yyvsp[-8]));
        tupla_add_child((yyval), (yyvsp[-5]));
        tupla_add_child((yyval), (yyvsp[-1]));
        tupla_free_name((yyvsp[-8]));
        free((yyvsp[-8]));
        free((yyvsp[-5]));
        free((yyvsp[-1]));
    }
#line 2413 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 243 "parser.y" /* yacc.c:1646  */
    {
        check_bool_type("if", tupla_get_type((yyvsp[-6])));
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(IF_NODE, 0, NO_TYPE));
        tupla_add_child((yyval), (yyvsp[-6]));
        tupla_add_child((yyval), (yyvsp[-3]));
        tupla_add_child((yyval), (yyvsp[0]));
        tupla_free_name((yyvsp[-6]));
        free((yyvsp[-6]));
        free((yyvsp[-3]));
        free((yyvsp[0]));
    }
#line 2429 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 263 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "==", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2441 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 274 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "!=", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(INEQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2453 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 285 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "<", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2465 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 294 "parser.y" /* yacc.c:1646  */
    {
        int idx = check_var((yyvsp[-2]));
        Type id_type = getType(vt, idx);
        unify(id_type, tupla_get_type((yyvsp[0])), "<", unify_comp);
        tupla_change_node((yyvsp[-2]), new_node(VAR_USE_NODE, idx, id_type));
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2480 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 306 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "<=", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2492 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 315 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), ">", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(GT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2504 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 324 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), ">=", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(GT_EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2516 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 335 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "&&", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(AND_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2528 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 344 "parser.y" /* yacc.c:1646  */
    {
        unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "||", unify_comp);
        (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(OR_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2540 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 396 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        tupla_change_node((yyval), new_var((yyvsp[0]), UNDEFINED_TYPE));
        tupla_free_name((yyval));
    }
#line 2550 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 403 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(ASSIGN_NODE, 0, NO_TYPE));
        tupla_change_node((yyvsp[-2]), new_var((yyvsp[-2]), tupla_get_type((yyvsp[0]))));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2562 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 414 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-2]);
        tupla_change_node((yyval), new_var((yyvsp[-2]), tupla_get_type((yyvsp[0]))));
        tupla_free_name((yyval));
        free((yyvsp[0]));
    }
#line 2573 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 422 "parser.y" /* yacc.c:1646  */
    {
        check_assign(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])));
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(ASSIGN_NODE, 0, NO_TYPE));
        tupla_change_node((yyvsp[-4]), new_var((yyvsp[-4]), tupla_get_type((yyvsp[0]))));
        tupla_add_child((yyval), (yyvsp[-4]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-4]), (yyvsp[0]));
        free((yyvsp[-2]));
    }
#line 2587 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 447 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2593 "parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 466 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_tupla(NULL, 0, NUMBER_TYPE, NULL);    }
#line 2599 "parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 467 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_tupla(NULL, 0, STRING_TYPE, NULL);    }
#line 2605 "parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 468 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_tupla(NULL, 0, BOOLEAN_TYPE, NULL);   }
#line 2611 "parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_tupla(NULL, 0, UNDEFINED_TYPE, NULL); }
#line 2617 "parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 476 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2623 "parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 477 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2629 "parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 478 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2635 "parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 483 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2641 "parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 488 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2647 "parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 489 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2653 "parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 490 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2659 "parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 496 "parser.y" /* yacc.c:1646  */
    {
        int idx = check_var((yyvsp[0]));
        Type type = getType(vt, idx);
        tupla_change_type((yyvsp[0]), type);
        tupla_change_node((yyvsp[0]), new_node(VAR_USE_NODE, idx, type));
        (yyval) = (yyvsp[0]);
    }
#line 2671 "parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 525 "parser.y" /* yacc.c:1646  */
    {
        Type type_final = unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "+", unify_plus);
        (yyval) = new_tupla(NULL, 0, type_final, new_node(PLUS_NODE, 0, type_final));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2683 "parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 534 "parser.y" /* yacc.c:1646  */
    {
        Type type_final = unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "-", unify_other_arith);
        (yyval) = new_tupla(NULL, 0, type_final, new_node(SUB_NODE, 0, type_final));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2695 "parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 543 "parser.y" /* yacc.c:1646  */
    {
        Type type_final = unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "*", unify_other_arith);
        (yyval) = new_tupla(NULL, 0, type_final, new_node(MULT_NODE, 0, type_final));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2707 "parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 552 "parser.y" /* yacc.c:1646  */
    {
        Type type_final = unify(tupla_get_type((yyvsp[-2])), tupla_get_type((yyvsp[0])), "/", unify_other_arith);
        (yyval) = new_tupla(NULL, 0, type_final, new_node(DIV_NODE, 0, type_final));
        tupla_add_child((yyval), (yyvsp[-2]));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2719 "parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 581 "parser.y" /* yacc.c:1646  */
    {
        check_name((yyvsp[-2]), "console");
        (yyval) = new_tupla(NULL, 0, NO_TYPE, new_node(PRINT_NODE, 0, NO_TYPE));
        tupla_add_child((yyval), (yyvsp[0]));
        free_tupla_full((yyvsp[-2]), (yyvsp[0]));
    }
#line 2730 "parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 596 "parser.y" /* yacc.c:1646  */
    {
        check_name((yyvsp[-3]), "log");
        tupla_free_name((yyvsp[-3]));
        free((yyvsp[-3]));
        (yyval) = (yyvsp[-1]);
    }
#line 2741 "parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 610 "parser.y" /* yacc.c:1646  */
    {
        Conv conversion = check_string((yyvsp[0]));
        if(conversion == NONE) {
            tupla_free_name((yyvsp[0]));
            (yyval) = (yyvsp[0]);
        }
        else {
            NodeKind conversion_nodekind = conv2node(conversion);
            (yyval) = new_tupla(NULL, 0, STRING_TYPE, new_node(conversion_nodekind, 0, STRING_TYPE));
            tupla_add_child((yyval), (yyvsp[0]));
            tupla_free_name((yyvsp[0]));
            free((yyvsp[0]));
        }
    }
#line 2760 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 637 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2766 "parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 638 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2772 "parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 639 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2778 "parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 640 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2784 "parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 641 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2790 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 642 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2796 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 643 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2802 "parser.c" /* yacc.c:1646  */
    break;


#line 2806 "parser.c" /* yacc.c:1646  */
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
#line 660 "parser.y" /* yacc.c:1906  */


// -----------------------------------------------------------------------

int check_var(Tupla* tupla) {
    int idx = findVar(vt, tupla_get_name(tupla));
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
            yylineno, tupla_get_name(tupla));
        exit(EXIT_FAILURE);
    }
    return idx;
}

AST* new_var(Tupla* tupla, Type type) {
    int idx_check = findVar(vt, tupla_get_name(tupla));
    if (idx_check != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                tupla_get_line(tupla), tupla_get_name(tupla), getLine(vt, idx_check));
        exit(EXIT_FAILURE);
    }
    int idx = addVar(&vt, tupla_get_line(tupla), tupla_get_name(tupla), type);
    return new_node(VAR_DECL_NODE, idx, type);
}

// -----------------------------------------------------------------------

Type unify(Type left, Type right, const char* op, Type (*unify)(Type, Type)) {
    Type unif = unify(left, right);
    if (unif == NO_TYPE) {
        type_error(op, left, right);
    }
    return unif;
}

Conv check_assign(Type left, Type right) {

    switch(left) {

        case NUMBER_TYPE:
            switch(right) {
                case NUMBER_TYPE:     break;
                case UNDEFINED_TYPE:  return N2U;
                default:              type_error("=", left, right);
            }
            break;

        case STRING_TYPE:
            switch(right) {
                case STRING_TYPE:     break;
                case UNDEFINED_TYPE:  return S2U;
                default:              type_error("=", left, right);
            }
            break;

        case BOOLEAN_TYPE:
            switch(right) {
                case BOOLEAN_TYPE:    break;
                case UNDEFINED_TYPE:  return B2U;
                default:              type_error("=", left, right);
            }
            break;

        default: break;
    }

    return NONE;
}

void check_bool_type(const char* cmd, Type type) {
    if(type != BOOLEAN_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(type), get_text(BOOLEAN_TYPE));
        exit(EXIT_FAILURE);
    }
}

void check_name(Tupla* tupla, const char* name) {
    char* tupla_name = tupla_get_name(tupla);
    if(strcmp(tupla_name, name) != 0) {
        printf("SEMANTIC ERROR (%d): cannot find name '%s'.\n", yylineno, tupla_name);
        exit(EXIT_FAILURE);
    }
}

Conv check_string(Tupla* tupla) {
    switch(tupla_get_type(tupla)) {
        case NUMBER_TYPE:    return N2S;
        case BOOLEAN_TYPE:   return B2S;
        case UNDEFINED_TYPE: return U2S;
        default:             return NONE;
    }
}

void free_tupla_full(Tupla* t1, Tupla* t2) {
    tupla_free_name(t1);
    tupla_free_name(t2);
    free(t1);
    free(t2);
}

// -----------------------------------------------------------------------

void type_error(const char* op, Type left, Type right) {
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

    stdin = fopen(ctermid(NULL), "r");

    printf("+++++++++++++ VAI RODAR A AST ++++++++++++++ \n");
    run_ast(root);
    printf("+++++++++++++ TERMINO DE RODAR A AST ++++++++++++++\n");


    fclose(stdin);
    freeVars(&vt);
    freeStrs(&st);
    free_tree(root);

    yylex_destroy();

    return 0;
}
