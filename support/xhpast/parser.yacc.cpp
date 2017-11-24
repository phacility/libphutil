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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         xhpastparse
#define yylex           xhpastlex
#define yyerror         xhpasterror
#define yydebug         xhpastdebug
#define yynerrs         xhpastnerrs


/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

/*
 * If you modify this grammar, please update the version number in
 * ./xhpast.cpp and libphutil/src/parser/xhpast/bin/xhpast_parse.php
 */

#include "ast.hpp"
#include "node_names.hpp"
// PHP's if/else rules use right reduction rather than left reduction which
// means while parsing nested if/else's the stack grows until it the last
// statement is read. This is annoying, particularly because of a quirk in
// bison.
// http://www.gnu.org/software/bison/manual/html_node/Memory-Management.html
// Apparently if you compile a bison parser with g++ it can no longer grow
// the stack. The work around is to just make your initial stack ridiculously
// large. Unfortunately that increases memory usage while parsing which is
// dumb. Anyway, putting a TODO here to fix PHP's if/else grammar.
#define YYINITDEPTH 500
#line 21 "parser.y" /* yacc.c:339  */

#undef yyextra
#define yyextra static_cast<yy_extra_type*>(xhpastget_extra(yyscanner))
#undef yylineno
#define yylineno yyextra->first_lineno
#define push_state(s) xhp_new_push_state(s, (struct yyguts_t*) yyscanner)
#define pop_state() xhp_new_pop_state((struct yyguts_t*) yyscanner)
#define set_state(s) xhp_set_state(s, (struct yyguts_t*) yyscanner)

#define NNEW(t) \
  (new xhpast::Node(t))

#define NTYPE(n, type) \
  ((n)->setType(type))

#define NMORE(n, end) \
  ((n)->expandRange(end))

#define NSPAN(n, type, end) \
  (NMORE(NTYPE((n), type), end))

#define NEXPAND(l, n, r) \
  ((n)->expandRange(l)->expandRange(r))

using namespace std;

static void yyerror(void* yyscanner, void* _, const char* error) {
  if (yyextra->terminated) {
    return;
  }
  yyextra->terminated = true;
  yyextra->error = error;
}


#line 127 "parser.yacc.cpp" /* yacc.c:339  */

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
   by #include "parser.yacc.hpp".  */
#ifndef YY_XHPAST_PARSER_YACC_HPP_INCLUDED
# define YY_XHPAST_PARSER_YACC_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int xhpastdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INCLUDE = 258,
    T_INCLUDE_ONCE = 259,
    T_EVAL = 260,
    T_REQUIRE = 261,
    T_REQUIRE_ONCE = 262,
    T_LOGICAL_OR = 263,
    T_LOGICAL_XOR = 264,
    T_LOGICAL_AND = 265,
    T_PRINT = 266,
    T_PLUS_EQUAL = 267,
    T_MINUS_EQUAL = 268,
    T_MUL_EQUAL = 269,
    T_DIV_EQUAL = 270,
    T_CONCAT_EQUAL = 271,
    T_MOD_EQUAL = 272,
    T_AND_EQUAL = 273,
    T_OR_EQUAL = 274,
    T_XOR_EQUAL = 275,
    T_SL_EQUAL = 276,
    T_SR_EQUAL = 277,
    T_COALESCE = 278,
    T_BOOLEAN_OR = 279,
    T_BOOLEAN_AND = 280,
    T_IS_EQUAL = 281,
    T_IS_NOT_EQUAL = 282,
    T_IS_IDENTICAL = 283,
    T_IS_NOT_IDENTICAL = 284,
    T_SPACESHIP = 285,
    T_IS_SMALLER_OR_EQUAL = 286,
    T_IS_GREATER_OR_EQUAL = 287,
    T_SL = 288,
    T_SR = 289,
    T_INSTANCEOF = 290,
    T_INC = 291,
    T_DEC = 292,
    T_INT_CAST = 293,
    T_DOUBLE_CAST = 294,
    T_STRING_CAST = 295,
    T_UNICODE_CAST = 296,
    T_BINARY_CAST = 297,
    T_ARRAY_CAST = 298,
    T_OBJECT_CAST = 299,
    T_BOOL_CAST = 300,
    T_UNSET_CAST = 301,
    T_NEW = 302,
    T_CLONE = 303,
    T_EXIT = 304,
    T_IF = 305,
    T_ELSEIF = 306,
    T_ELSE = 307,
    T_ENDIF = 308,
    T_LNUMBER = 309,
    T_DNUMBER = 310,
    T_STRING = 311,
    T_STRING_VARNAME = 312,
    T_VARIABLE = 313,
    T_NUM_STRING = 314,
    T_INLINE_HTML = 315,
    T_CHARACTER = 316,
    T_BAD_CHARACTER = 317,
    T_ENCAPSED_AND_WHITESPACE = 318,
    T_CONSTANT_ENCAPSED_STRING = 319,
    T_BACKTICKS_EXPR = 320,
    T_ECHO = 321,
    T_DO = 322,
    T_WHILE = 323,
    T_ENDWHILE = 324,
    T_FOR = 325,
    T_ENDFOR = 326,
    T_FOREACH = 327,
    T_ENDFOREACH = 328,
    T_DECLARE = 329,
    T_ENDDECLARE = 330,
    T_AS = 331,
    T_SWITCH = 332,
    T_ENDSWITCH = 333,
    T_CASE = 334,
    T_DEFAULT = 335,
    T_BREAK = 336,
    T_CONTINUE = 337,
    T_GOTO = 338,
    T_FUNCTION = 339,
    T_CONST = 340,
    T_RETURN = 341,
    T_TRY = 342,
    T_CATCH = 343,
    T_THROW = 344,
    T_USE = 345,
    T_GLOBAL = 346,
    T_STATIC = 347,
    T_ABSTRACT = 348,
    T_FINAL = 349,
    T_PRIVATE = 350,
    T_PROTECTED = 351,
    T_PUBLIC = 352,
    T_VAR = 353,
    T_UNSET = 354,
    T_ISSET = 355,
    T_EMPTY = 356,
    T_HALT_COMPILER = 357,
    T_CLASS = 358,
    T_INTERFACE = 359,
    T_EXTENDS = 360,
    T_IMPLEMENTS = 361,
    T_OBJECT_OPERATOR = 362,
    T_DOUBLE_ARROW = 363,
    T_LIST = 364,
    T_ARRAY = 365,
    T_CLASS_C = 366,
    T_METHOD_C = 367,
    T_FUNC_C = 368,
    T_LINE = 369,
    T_FILE = 370,
    T_COMMENT = 371,
    T_DOC_COMMENT = 372,
    T_OPEN_TAG = 373,
    T_OPEN_TAG_WITH_ECHO = 374,
    T_OPEN_TAG_FAKE = 375,
    T_CLOSE_TAG = 376,
    T_WHITESPACE = 377,
    T_START_HEREDOC = 378,
    T_END_HEREDOC = 379,
    T_HEREDOC = 380,
    T_DOLLAR_OPEN_CURLY_BRACES = 381,
    T_CURLY_OPEN = 382,
    T_PAAMAYIM_NEKUDOTAYIM = 383,
    T_BINARY_DOUBLE = 384,
    T_BINARY_HEREDOC = 385,
    T_NAMESPACE = 386,
    T_NS_C = 387,
    T_DIR = 388,
    T_NS_SEPARATOR = 389,
    T_INSTEADOF = 390,
    T_CALLABLE = 391,
    T_TRAIT = 392,
    T_TRAIT_C = 393,
    T_YIELD = 394,
    T_FINALLY = 395,
    T_ELLIPSIS = 396
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int xhpastparse (void* yyscanner, xhpast::Node** root);

#endif /* !YY_XHPAST_PARSER_YACC_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 319 "parser.yacc.cpp" /* yacc.c:358  */

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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7552

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  442
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  908

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   396

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,   166,    49,    32,     2,
     161,   162,    47,    44,     8,    45,    46,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   163,
      38,    13,    40,    25,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,   167,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   164,    30,   165,    52,     2,     2,     2,
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
       5,     6,     7,     9,    10,    11,    12,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    27,    28,
      29,    33,    34,    35,    36,    37,    39,    41,    42,    43,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   216,   219,   225,   228,   234,   235,   236,
     237,   242,   249,   255,   263,   268,   275,   278,   285,   290,
     296,   302,   312,   319,   329,   332,   338,   339,   340,   341,
     349,   350,   356,   359,   362,   368,   371,   401,   420,   427,
     435,   448,   455,   462,   469,   476,   483,   490,   497,   504,
     509,   514,   519,   523,   527,   531,   537,   555,   572,   578,
     582,   591,   600,   608,   619,   623,   629,   641,   644,   648,
     657,   661,   668,   672,   676,   680,   683,   689,   705,   717,
     732,   736,   743,   750,   757,   760,   766,   770,   773,   781,
     784,   792,   795,   801,   804,   810,   811,   819,   820,   828,
     829,   837,   838,   846,   852,   863,   866,   876,   881,   893,
     896,   904,   914,   915,   919,   920,   928,   931,   941,   944,
     954,   957,   965,   968,   976,   977,   983,   991,  1000,  1009,
    1017,  1025,  1034,  1044,  1056,  1060,  1066,  1069,  1070,  1077,
    1080,  1083,  1089,  1092,  1099,  1100,  1106,  1109,  1115,  1116,
    1119,  1126,  1130,  1137,  1140,  1144,  1151,  1159,  1167,  1175,
    1186,  1189,  1195,  1203,  1207,  1210,  1210,  1228,  1236,  1239,
    1245,  1248,  1254,  1257,  1263,  1267,  1274,  1277,  1283,  1291,
    1295,  1302,  1306,  1312,  1320,  1326,  1335,  1338,  1346,  1349,
    1355,  1356,  1363,  1366,  1373,  1377,  1383,  1384,  1385,  1386,
    1387,  1388,  1392,  1399,  1406,  1413,  1423,  1432,  1444,  1447,
    1454,  1457,  1462,  1465,  1472,  1480,  1486,  1496,  1510,  1515,
    1521,  1527,  1533,  1539,  1545,  1551,  1557,  1563,  1569,  1575,
    1581,  1586,  1591,  1596,  1601,  1607,  1613,  1619,  1625,  1631,
    1637,  1643,  1649,  1675,  1681,  1687,  1693,  1699,  1705,  1711,
    1717,  1722,  1727,  1732,  1737,  1743,  1749,  1755,  1761,  1767,
    1773,  1779,  1785,  1791,  1797,  1798,  1799,  1807,  1815,  1821,
    1822,  1827,  1832,  1837,  1842,  1847,  1852,  1857,  1862,  1867,
    1871,  1872,  1873,  1874,  1879,  1885,  1900,  1924,  1930,  1936,
    1942,  1951,  1955,  1958,  1966,  1969,  1974,  1978,  1987,  1992,
    1999,  2005,  2014,  2023,  2032,  2041,  2049,  2052,  2055,  2059,
    2066,  2069,  2073,  2080,  2081,  2085,  2100,  2104,  2107,  2113,
    2119,  2122,  2126,  2134,  2137,  2143,  2146,  2149,  2152,  2155,
    2158,  2161,  2164,  2167,  2170,  2173,  2176,  2182,  2183,  2184,
    2188,  2192,  2197,  2202,  2207,  2212,  2216,  2224,  2225,  2226,
    2227,  2230,  2233,  2237,  2240,  2246,  2249,  2253,  2264,  2271,
    2278,  2288,  2289,  2293,  2297,  2301,  2305,  2331,  2335,  2338,
    2344,  2354,  2360,  2369,  2375,  2376,  2377,  2383,  2384,  2399,
    2404,  2412,  2416,  2422,  2431,  2432,  2433,  2437,  2438,  2441,
    2453,  2457,  2463,  2469,  2473,  2476,  2484,  2487,  2493,  2494,
    2498,  2504,  2510,  2514,  2518,  2524,  2527,  2542,  2545,  2552,
    2553,  2557,  2563,  2566,  2572,  2579,  2586,  2593,  2600,  2607,
    2614,  2621,  2631,  2641,  2651,  2654,  2657,  2667,  2670,  2676,
    2680,  2686,  2691,  2697,  2703,  2709,  2715,  2721,  2730,  2735,
    2743,  2752,  2757
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INCLUDE", "T_INCLUDE_ONCE", "T_EVAL",
  "T_REQUIRE", "T_REQUIRE_ONCE", "','", "T_LOGICAL_OR", "T_LOGICAL_XOR",
  "T_LOGICAL_AND", "T_PRINT", "'='", "T_PLUS_EQUAL", "T_MINUS_EQUAL",
  "T_MUL_EQUAL", "T_DIV_EQUAL", "T_CONCAT_EQUAL", "T_MOD_EQUAL",
  "T_AND_EQUAL", "T_OR_EQUAL", "T_XOR_EQUAL", "T_SL_EQUAL", "T_SR_EQUAL",
  "'?'", "':'", "T_COALESCE", "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'",
  "'^'", "'&'", "T_IS_EQUAL", "T_IS_NOT_EQUAL", "T_IS_IDENTICAL",
  "T_IS_NOT_IDENTICAL", "T_SPACESHIP", "'<'", "T_IS_SMALLER_OR_EQUAL",
  "'>'", "T_IS_GREATER_OR_EQUAL", "T_SL", "T_SR", "'+'", "'-'", "'.'",
  "'*'", "'/'", "'%'", "'!'", "T_INSTANCEOF", "'~'", "T_INC", "T_DEC",
  "T_INT_CAST", "T_DOUBLE_CAST", "T_STRING_CAST", "T_UNICODE_CAST",
  "T_BINARY_CAST", "T_ARRAY_CAST", "T_OBJECT_CAST", "T_BOOL_CAST",
  "T_UNSET_CAST", "'@'", "'['", "T_NEW", "T_CLONE", "T_EXIT", "T_IF",
  "T_ELSEIF", "T_ELSE", "T_ENDIF", "T_LNUMBER", "T_DNUMBER", "T_STRING",
  "T_STRING_VARNAME", "T_VARIABLE", "T_NUM_STRING", "T_INLINE_HTML",
  "T_CHARACTER", "T_BAD_CHARACTER", "T_ENCAPSED_AND_WHITESPACE",
  "T_CONSTANT_ENCAPSED_STRING", "T_BACKTICKS_EXPR", "T_ECHO", "T_DO",
  "T_WHILE", "T_ENDWHILE", "T_FOR", "T_ENDFOR", "T_FOREACH",
  "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE", "T_AS", "T_SWITCH",
  "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK", "T_CONTINUE", "T_GOTO",
  "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY", "T_CATCH", "T_THROW",
  "T_USE", "T_GLOBAL", "T_STATIC", "T_ABSTRACT", "T_FINAL", "T_PRIVATE",
  "T_PROTECTED", "T_PUBLIC", "T_VAR", "T_UNSET", "T_ISSET", "T_EMPTY",
  "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE", "T_EXTENDS", "T_IMPLEMENTS",
  "T_OBJECT_OPERATOR", "T_DOUBLE_ARROW", "T_LIST", "T_ARRAY", "T_CLASS_C",
  "T_METHOD_C", "T_FUNC_C", "T_LINE", "T_FILE", "T_COMMENT",
  "T_DOC_COMMENT", "T_OPEN_TAG", "T_OPEN_TAG_WITH_ECHO", "T_OPEN_TAG_FAKE",
  "T_CLOSE_TAG", "T_WHITESPACE", "T_START_HEREDOC", "T_END_HEREDOC",
  "T_HEREDOC", "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN",
  "T_PAAMAYIM_NEKUDOTAYIM", "T_BINARY_DOUBLE", "T_BINARY_HEREDOC",
  "T_NAMESPACE", "T_NS_C", "T_DIR", "T_NS_SEPARATOR", "T_INSTEADOF",
  "T_CALLABLE", "T_TRAIT", "T_TRAIT_C", "T_YIELD", "T_FINALLY",
  "T_ELLIPSIS", "'('", "')'", "';'", "'{'", "'}'", "'$'", "']'", "$accept",
  "start", "top_statement_list", "namespace_name", "top_statement",
  "use_declarations", "use_declaration", "constant_declaration",
  "inner_statement_list", "inner_statement", "statement",
  "unticked_statement", "catch_list", "catch", "finally_statement",
  "non_empty_finally_statement", "unset_variables", "unset_variable",
  "function_declaration_statement", "class_declaration_statement",
  "is_reference", "unticked_function_declaration_statement",
  "unticked_class_declaration_statement", "class_entry_type",
  "extends_from", "interface_entry", "interface_extends_list",
  "implements_list", "interface_list", "foreach_optional_arg",
  "foreach_variable", "for_statement", "foreach_statement",
  "declare_statement", "declare_list", "switch_case_list", "case_list",
  "case_separator", "while_statement", "elseif_list", "new_elseif_list",
  "else_single", "new_else_single", "parameter_list",
  "non_empty_parameter_list", "parameter", "optional_type", "type",
  "return_type", "function_call_parameter_list",
  "non_empty_function_call_parameter_list", "argument", "global_var_list",
  "global_var", "static_var_list", "class_statement_list",
  "class_statement", "$@1", "trait_use_statement", "trait_list",
  "trait_adaptations", "trait_adaptation_list",
  "non_empty_trait_adaptation_list", "trait_adaptation_statement",
  "trait_precedence", "trait_reference_list", "trait_method_reference",
  "trait_method_reference_fully_qualified", "trait_alias",
  "trait_modifiers", "method_body", "variable_modifiers",
  "method_modifiers", "non_empty_member_modifiers", "member_modifier",
  "class_variable_declaration", "class_constant_declaration",
  "echo_expr_list", "for_expr", "non_empty_for_expr",
  "expr_without_variable", "yield_expr", "function", "lexical_vars",
  "lexical_var_list", "function_call", "class_name",
  "fully_qualified_class_name", "class_name_reference",
  "dynamic_class_name_reference", "dynamic_class_name_variable_properties",
  "dynamic_class_name_variable_property", "exit_expr", "ctor_arguments",
  "common_scalar", "static_scalar", "static_class_constant", "scalar",
  "static_array_pair_list", "possible_comma",
  "non_empty_static_array_pair_list", "expr", "r_variable", "w_variable",
  "rw_variable", "variable", "variable_properties", "variable_property",
  "array_method_dereference", "method", "method_or_not",
  "variable_without_objects", "static_member", "variable_class_name",
  "array_function_dereference", "base_variable_with_function_calls",
  "base_variable", "reference_variable", "compound_variable", "dim_offset",
  "object_property", "object_dim_list", "variable_name",
  "simple_indirect_reference", "assignment_list",
  "assignment_list_element", "array_pair_list",
  "non_empty_array_pair_list", "internal_functions_in_yacc",
  "isset_variables", "parenthesis_expr", "combined_scalar_offset",
  "combined_scalar", "new_expr", "class_constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    44,   263,
     264,   265,   266,    61,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    63,    58,   278,   279,   280,
     124,    94,    38,   281,   282,   283,   284,   285,    60,   286,
      62,   287,   288,   289,    43,    45,    46,    42,    47,    37,
      33,   290,   126,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,    64,    91,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,    40,    41,    59,   123,   125,    36,    93
};
# endif

#define YYPACT_NINF -702

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-702)))

#define YYTABLE_NINF -382

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-382)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -702,    51,  1810,  -702,  5980,  5980,   -97,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,   394,   394,  5980,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,  4650,   440,  5980,   -95,   -85,  -702,
    -702,    33,  -702,  -702,  -702,    13,  -702,  5980,  4508,   -76,
     -71,   -62,    38,    64,  4783,  4916,   107,  -702,   155,  5049,
       7,  5980,   138,    48,   -17,   116,   184,    92,   143,   161,
     166,  -702,  -702,   174,   177,  -702,  -702,  -702,  -702,  -702,
    -702,  -702,  -702,  -702,    84,  -702,  -702,   275,  -702,  -702,
    5980,  6113,  -702,  -702,   194,   -73,  -702,     9,  -702,  -702,
    -702,  -702,  -702,  -702,   291,   299,  -702,   215,   347,   315,
     234,  -702,  -702,  6536,  -702,    41,  1047,   221,  -702,   240,
     323,   264,  -702,    -9,  -702,    56,  -702,  -702,   326,   327,
    -702,   330,   332,   295,   248,  -702,   347,  7366,  7366,  5980,
    7366,  7366,  7433,  -702,  -702,   352,  -702,  -702,  -702,   253,
     275,   342,   -98,   265,  -702,  -702,   269,  -702,  -702,  -702,
    -702,  -702,  -702,  -702,  -702,  -702,   394,  7126,   244,   409,
     267,   275,   268,   271,   262,  -702,   280,   302,   -11,    56,
    -702,  5182,  -702,  5980,  -702,  5980,  5980,    16,  7366,   363,
    5980,  5980,  5980,   377,  5980,  -702,  6579,  -702,  6622,   290,
     442,  -702,   294,  7366,   959,  -702,  6673,   275,   115,    17,
    -702,  -702,   249,    20,  -702,   448,    21,   347,  -702,  -702,
     394,   394,   394,   301,   298,  4650,   275,  -702,   150,   103,
     104,  7169,    96,   303,  6716,   304,  1952,  5980,   393,  1276,
     395,  -702,   348,   349,  -702,  -702,     6,  5980,   -27,  5980,
    5980,  5980,  5315,  5980,  5980,  5980,  5980,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,  5980,  5980,   440,  -702,  -702,  -702,
    5448,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,
    5980,  5980,  1276,    52,  5980,    91,  5980,  5980,   194,     0,
    5980,  5980,  5980,   316,  6759,   275,   -86,   304,    67,   126,
    -702,  -702,  5581,  -702,  5714,  -702,   275,   268,    81,  1276,
    -702,    81,    91,   -21,  -702,  6810,  6854,  7366,   311,   317,
    5980,  -702,   322,  6897,   328,   484,  7366,   399,  1032,   483,
      25,  6946,  -702,  -702,  -702,  7235,  -702,  -702,  2094,  -702,
     117,   423,   138,  -702,  5980,  -702,  -702,    48,  -702,  7235,
     422,  -702,   345,    26,  -702,  -702,  -702,    27,   351,   346,
     350,  -702,    28,  -702,   357,   118,  1498,  -702,  -702,  1276,
    5980,  -702,  -702,  -702,   353,  -702,  -702,  -702,  -702,  -702,
    6258,  -702,   394,  5980,   360,   510,  -702,  7366,   511,   165,
     401,   165,   368,   366,    66,   369,   374,   378,   -21,    56,
    7408,  1202,  7433,  5980,  7294,  7458,  1659,  7480,  7501,  4703,
    1449,  1802,  1802,  1802,  1802,  1802,  1219,  1219,  1219,  1219,
     398,   398,   314,   314,   314,   352,   352,   352,  -702,   206,
    7433,  7433,  7433,  7433,  7433,  7433,  7433,  7433,  7433,  7433,
    7433,  7433,   379,   381,   382,   373,  -702,  5980,  -702,   384,
      -7,  -702,   385,  6301,   386,   387,   389,  -702,   -82,   374,
     381,   394,  7366,   394,  7227,   268,  -702,   403,  -702,  -702,
    -702,  3798,  -702,  -702,  7366,  5980,  3940,  5980,  5980,   394,
      70,  7235,   471,  4082,     1,  7235,  7235,  7235,  -702,   388,
     404,   275,    49,   414,  -702,  -702,  -702,   -58,   488,  -702,
    -702,  6344,  -702,  -702,   556,    66,   394,   408,   394,  -702,
    -702,  -702,   298,   298,   559,  -702,  1276,  -702,  1668,   411,
     124,   947,   412,  -702,  -702,  7366,  -702,  1276,  7235,   424,
     275,   268,  -702,   165,   415,   567,  -702,  -702,    66,   202,
    -702,  -702,   416,   573,    10,  -702,  -702,  -702,  1276,  1276,
     -21,  7458,  5980,   440,  -702,  -702,  1276,  1276,  -702,  6397,
    1276,   517,   520,  -702,  5980,  5980,  -702,  -702,  -702,  -702,
    -702,  -702,  -702,  5847,  -702,   460,  -702,  -702,  6990,  -702,
    -702,  -702,   425,  7366,   462,   394,   462,  -702,  -702,   578,
    -702,  -702,  -702,   431,   432,  -702,  -702,  -702,   472,   435,
     590,  7235,   275,    98,   528,   444,   447,   -58,  -702,  -702,
    -702,  -702,  7235,   452,  -702,  -702,  -702,    29,  -702,  5980,
     453,  -702,  -702,   455,  -702,  -702,   275,   268,   567,  -702,
     165,   582,   454,  -702,   513,    79,    86,  -702,   542,   607,
     461,   464,  7458,   262,   474,   476,  -702,   477,  5980,  5980,
     498,   466,  6440,   394,  7366,    91,  -702,  3656,   263,   479,
    2236,  5980,    70,   481,  -702,   482,  7235,  2378,  -702,   213,
    -702,   -37,  7235,  -702,  7235,  -702,   485,   131,  -702,   165,
    -702,  -702,  -702,  -702,  -702,   513,  -702,  7433,  -702,  -702,
     268,   661,  -702,   571,   165,  -702,  -702,  -702,  -702,  -702,
    -702,  -702,  -702,  -702,  -702,   557,   295,   319,  -702,    22,
     624,   490,   624,    57,   640,  -702,  7235,  -702,  -702,  -702,
    -702,  -702,  -702,   487,   495,    91,  -702,  -702,  -702,  -702,
    -702,   272,   502,  4508,  -702,  -702,   501,   506,  -702,  4224,
    4224,  -702,   507,   222,   508,  5980,    14,   128,  -702,  -702,
     545,  -702,   596,  2520,   624,  -702,   662,    11,  -702,   663,
      23,  -702,  -702,   602,  -702,    79,   514,   162,   516,    86,
     668,  7235,  -702,  -702,  -702,   384,   522,   659,   615,  5980,
    -702,  -702,  4366,  -702,  -702,  -702,  -702,  -702,   529,  -702,
    6485,  -702,  -702,  -702,  -702,  7235,   538,  -702,   537,  7235,
     165,  -702,   179,  -702,  7235,   626,  -702,   347,   692,  -702,
    -702,   632,  -702,    31,  -702,   710,  7235,  -702,  -702,  5980,
    -702,   561,  7033,  -702,  -702,  -702,  2662,  -702,  -702,  3656,
    -702,   563,  -702,  -702,  -702,   630,   564,   179,  -702,   565,
     635,   577,   569,   594,  -702,   724,   667,  7235,  2804,  -702,
     172,  -702,  2946,  7235,  -702,  7082,  3656,  -702,  4508,  3088,
     580,  3656,  -702,  3230,  -702,  -702,  -702,   604,   165,  -702,
     669,  7235,   584,  -702,  -702,   671,  -702,  -702,  -702,   720,
    -702,   586,  -702,  3372,  -702,   675,   678,   746,  -702,  -702,
    -702,    66,  -702,  -702,  -702,  -702,  -702,   165,   595,  3656,
    -702,   624,   182,  -702,  -702,  -702,  3514,  -702
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,     0,     0,   320,     0,   325,
     326,     5,   347,   394,    52,   327,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,    80,    86,     0,     0,   331,   332,   334,   328,   329,
      32,    33,    34,   336,     0,   335,   330,     0,    83,   333,
     284,     0,    59,    25,   405,   349,     3,     0,     7,    30,
       8,     9,    73,    74,     0,     0,   362,     0,    75,   386,
       0,   352,   280,     0,   361,     0,   363,     0,   390,     0,
     385,   367,   384,   387,   393,     0,   269,   264,   281,   282,
     265,   348,     5,   306,     0,   284,    75,   424,   425,     0,
     427,   428,   283,   250,   251,   252,   253,     5,   306,     0,
       0,     0,   307,     0,   231,   365,     0,   233,   270,   271,
     272,   273,   274,   275,   276,   278,     0,   417,     0,   355,
       0,     0,   307,   313,   323,   314,     0,   316,   387,     0,
     218,     0,   277,     0,    31,   396,   396,     0,   209,     0,
       0,   210,     0,     0,     0,    42,     0,    44,     0,     0,
       0,    46,   362,     0,   363,    25,     0,     0,    18,     0,
      17,   153,     0,     0,   152,   158,     0,    75,    81,    82,
       0,     0,     0,     0,   411,   412,     0,     4,     0,   351,
     362,     0,   363,     0,     0,   265,     0,     0,     0,   145,
       0,    15,    84,    87,    54,    76,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,   230,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,   396,     0,   396,     0,   406,   389,
     396,   396,   396,     0,     0,     0,   309,     0,     0,     0,
     421,   364,     0,   439,   356,   413,     0,   309,     0,   145,
     440,     0,     0,   389,   321,     0,     0,   397,     0,     0,
       0,    51,     0,     0,     0,   211,   213,   362,   363,     0,
       0,     0,    43,    45,    63,     0,    47,    48,     0,    62,
      20,     0,     0,    14,     0,   154,   363,     0,    49,     0,
       0,    50,     0,     0,    70,    72,   429,     0,     0,     0,
       0,   409,     0,   408,     0,   350,     0,    11,     4,   145,
       0,   432,   431,   388,     0,    35,    24,    26,    27,    28,
       0,     6,     0,     0,     0,   144,   146,   148,     0,     0,
      89,     0,     0,     0,   136,     0,   441,   379,   377,     0,
     236,   238,   237,     0,     0,   268,   234,   235,   239,   241,
     240,   256,   257,   254,   255,   262,   258,   259,   260,   261,
     248,   249,   243,   244,   242,   245,   246,   247,   263,     0,
     215,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   442,   380,     0,   403,     0,   399,   376,
     398,   402,     0,     0,     0,     0,     0,   426,   308,     0,
       0,     0,   416,     0,   415,   308,   379,     0,   380,   318,
     322,     0,   437,   435,   208,     0,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   353,   327,     0,
       0,     0,   338,     0,   337,    23,   345,     0,     0,    19,
      16,     0,   151,   159,   156,   136,     0,     0,     0,   422,
     423,    10,   411,   411,     0,   438,   145,    13,     0,     0,
     362,   363,     0,   395,   150,   149,   298,     0,     0,     0,
       0,   310,    85,     0,     0,    88,    91,   161,   136,     0,
     140,   141,     0,   124,     0,   137,   139,   383,   145,   145,
     378,   267,     0,     0,   216,   305,   145,   145,   382,     0,
     145,   375,   374,   369,   396,     0,   391,   392,   434,   433,
     436,   420,   419,     0,   324,   315,    25,   116,     0,    25,
     114,    38,     0,   212,    93,     0,    93,    95,   103,     0,
      25,   101,    58,   109,   109,    41,   341,   342,   360,     0,
     355,   353,     0,   340,     0,     0,     0,    67,    65,    61,
      21,   155,     0,     0,    71,    55,   430,     0,   407,     0,
       0,    12,   300,     0,   147,    22,     0,   312,    90,   161,
       0,   192,     0,   138,   292,   136,     0,   135,     0,   126,
       0,     0,   266,   323,     0,     0,   404,     0,   396,   396,
     366,     0,     0,     0,   414,     0,   317,   118,   120,     0,
       0,   210,     0,     0,    96,     0,     0,     0,   109,     0,
     109,     0,     0,   344,   356,   354,     0,   339,   346,     0,
      25,    64,    60,    68,   157,   292,   410,   214,   299,    29,
     311,   192,    92,     0,     0,   199,   200,   201,   198,   197,
     196,   191,    79,   160,   164,     0,     0,   190,   194,     0,
     142,     0,   142,     0,   127,   134,     0,   301,   304,   217,
     302,   303,   373,     0,     0,     0,   368,   400,   401,   418,
     319,   122,     0,     0,    36,    39,     0,     0,    94,     0,
       0,   104,     0,     0,     0,     0,     0,     0,   105,   359,
     358,   343,     0,     0,   142,    78,     0,     0,   168,   204,
       0,   165,   195,     0,   163,   136,     0,     0,     0,     0,
     130,     0,   129,   371,   372,   376,     0,     0,     0,     0,
     121,   115,     0,    25,    99,    57,    56,   102,     0,   107,
       0,   112,   113,    25,   106,     0,     0,    69,     0,     0,
       0,   170,   172,   167,     0,     0,   162,    75,     0,   143,
      25,     0,   296,     0,    25,   131,     0,   128,   370,     0,
      25,     0,     0,    25,    97,    40,     0,   108,    25,   111,
     357,     0,    25,   207,   169,     5,     0,   173,   174,     0,
       0,   182,     0,     0,   205,   202,     0,     0,     0,   297,
       0,   293,     0,     0,   133,     0,   123,    37,     0,     0,
       0,   110,    25,     0,   171,   175,   176,   186,     0,   177,
       0,     0,     0,   206,    77,     0,   294,   285,   132,     0,
     117,     0,   100,     0,   286,     0,   185,   178,   179,   183,
     203,   136,   295,    25,    98,    66,   184,     0,     0,   119,
     180,   142,     0,   188,    25,   166,     0,   189
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -702,  -702,  -199,    -5,  -702,  -702,   419,  -702,  -183,  -702,
      19,  -702,  -702,   149,  -702,   156,  -702,   256,     2,     3,
    -125,  -702,  -702,  -702,  -702,  -702,  -702,  -702,   231,   181,
     106,  -702,    39,  -702,  -702,  -702,  -562,    -8,  -702,  -702,
    -702,  -702,  -702,  -497,  -702,  -591,  -589,   230,  -701,  -209,
    -702,   254,  -702,   436,  -702,   157,  -702,  -702,  -702,  -702,
    -702,  -702,  -702,   -53,  -702,  -702,  -702,  -702,  -702,  -702,
    -702,  -702,  -702,  -702,  -694,  -702,  -702,  -702,  -463,  -702,
     -42,   706,    -2,   108,  -702,  -702,   227,   -66,  -251,  -702,
    -702,  -702,  -702,   145,  -187,  -212,  -702,  -702,   188,   191,
    -702,   908,   598,  -356,   339,   356,  -702,  -702,  -702,  -702,
      30,  -215,  -702,   793,  -702,  -702,   -22,   -23,  -702,  -160,
    -306,  -702,  -702,    -3,   284,   279,   583,  -702,  -702,  -702,
    -702,  -702,  -702,   -38,  -702
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   199,   200,    87,   226,   376,
     377,    89,   607,   608,   682,   609,   353,   354,   378,   379,
     236,    92,    93,    94,   390,    95,   392,   534,   535,   663,
     586,   825,   785,   592,   330,   595,   669,   793,   581,   658,
     731,   734,   778,   542,   543,   639,   544,   545,   766,   384,
     385,   386,   203,   204,   206,   631,   703,   807,   704,   757,
     803,   836,   837,   838,   839,   887,   840,   841,   842,   885,
     905,   705,   706,   707,   708,   760,   709,   177,   324,   325,
      96,    97,   126,   712,   813,    99,   100,   546,   164,   165,
     575,   656,   172,   310,   101,   598,   496,   102,   599,   305,
     600,   103,   104,   300,   105,   106,   650,   726,   561,   562,
     563,   107,   108,   109,   110,   111,   112,   113,   114,   318,
     449,   450,   451,   115,   362,   363,   158,   159,   116,   357,
     117,   118,   119,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   293,   168,   167,    90,    91,   469,   192,   613,   142,
     142,   768,   338,   762,   582,   428,   319,   230,   366,   800,
     162,    88,   169,   397,   320,   342,   524,   593,   347,   350,
     763,   805,   671,   482,   506,   508,   513,   513,   220,   850,
     791,   632,   636,   225,   286,   714,   713,   198,   396,   605,
      33,     3,   207,   798,   286,   228,   286,   179,   564,   174,
     205,   745,   746,   229,   129,   286,   171,   228,   444,   218,
     448,   228,   219,   442,  -307,   369,   173,   395,   176,   516,
     228,   393,   352,   397,   444,   180,    47,   637,   229,   769,
     181,   539,   289,   466,   268,   269,   468,   448,   175,   182,
     467,   606,   585,   297,   539,   571,   743,   572,   747,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   207,   770,   495,   445,   201,   452,   443,   748,    33,
     454,   455,   456,    33,   637,   296,  -381,   503,  -381,    84,
     327,   137,   459,   287,    33,   137,   313,    33,   494,  -365,
    -365,   142,  -377,   287,   137,   287,   307,   565,    33,   137,
     519,  -378,   494,   637,   287,   594,   446,   394,    33,   518,
     638,   195,   231,   886,   801,   802,   809,   792,   815,   321,
     343,   138,   189,   348,   351,   764,   806,   483,   507,   509,
     514,   686,   340,   851,   811,   540,  -307,   142,   737,   183,
     902,   460,   228,    33,   875,   142,   142,   142,   540,   142,
     341,   365,   498,   137,   202,   398,   529,   638,    84,   530,
     139,   541,   288,   140,    98,   184,   745,   746,  -125,   529,
     190,   141,   530,    84,   541,   399,    84,   216,   208,   812,
     137,   143,   143,   168,   167,  -309,   638,    84,   217,   876,
    -309,   228,   163,   210,   835,   447,   228,    84,  -288,  -288,
     398,   162,   398,   169,   369,  -308,  -287,  -287,   228,   588,
     228,   228,   553,   596,   597,   398,   398,   137,  -308,   516,
     399,   137,   399,    33,   228,   398,  -289,  -289,   398,   398,
     458,   197,    84,   794,   494,   399,   399,   729,   494,   494,
     494,   465,   643,   228,   211,   399,   209,   620,   399,   399,
     744,   745,   746,   367,   368,   529,   625,   138,   530,   788,
     745,   746,   212,   532,   137,   536,    33,   213,   520,   529,
     492,   540,   530,   732,   733,   214,    98,   198,   215,   640,
     641,   494,   776,   777,   492,   903,   904,   644,   645,   730,
     137,   647,   529,   144,   147,   530,   139,   541,   227,   140,
     138,   263,   264,   265,    98,   266,   232,   141,    90,    91,
     145,   145,    84,   137,   233,    33,   550,   142,   234,   235,
     237,   238,   282,   143,   531,    88,   531,   283,   284,   531,
     285,   290,   291,   657,   898,   292,   660,   175,    47,   139,
     684,   216,   140,   266,   651,   194,   295,   667,    25,   138,
     141,   303,   298,   344,   494,    84,   299,   304,   308,   775,
     306,   228,  -193,   309,   142,   494,   360,   311,   312,   143,
     695,   696,   697,   698,   699,   700,   222,   143,   143,   143,
     448,   143,   260,   261,   262,   263,   264,   265,   139,   266,
     322,   140,   329,   334,   741,   335,   142,   336,   142,   141,
     749,   349,   750,   359,    84,   371,   373,   536,   381,   137,
     388,    33,   389,   391,   142,   142,   492,   394,   472,   494,
     492,   492,   492,   475,   473,   494,   603,   494,   723,   724,
     577,   477,   478,   163,   479,   580,   481,   753,   499,   504,
     531,   142,   591,   142,   772,   138,   505,   142,   142,   511,
     448,   512,   301,   510,   522,   137,    98,    33,   527,   515,
      90,    91,   526,   492,   528,   627,   533,   538,   531,   494,
     168,   167,   537,   531,   531,   548,   547,    88,   328,   549,
     558,   555,   556,   557,   139,   560,   589,   140,   162,   601,
     169,   138,   566,   568,   569,   141,   570,   602,   346,   817,
      84,   604,   493,   610,   692,   574,   355,   356,   358,   612,
     361,   615,   619,   622,   623,   630,   493,   626,   634,   629,
     142,   635,   648,   830,   494,   649,   655,   833,   661,   662,
     160,   666,   844,   161,   668,   670,   492,   677,   674,   672,
     826,   141,   673,   678,   854,   679,    84,   492,   494,   143,
     829,   680,   494,   752,   685,   688,   710,   494,   689,   715,
     716,   690,   711,   717,   725,   531,   718,   848,   758,   494,
     531,   852,   398,   727,   759,   873,   720,   856,   721,   722,
     859,   878,   735,   739,   740,   861,   756,   751,   142,   863,
     765,   767,   399,   771,   773,    98,   143,   142,    98,   890,
     494,   492,   774,   779,   781,    98,   494,   492,   782,   492,
     787,   789,   795,   796,   531,   799,   804,   808,   810,   883,
     814,   816,   846,   819,   494,   820,   693,   821,   143,   531,
     143,   694,   827,   695,   696,   697,   698,   699,   700,   701,
     831,   832,   398,   845,   761,   847,   143,   143,   493,   849,
     899,   492,   493,   493,   493,   695,   696,   697,   698,   699,
     700,   906,   399,   853,   857,  -181,   521,   862,   866,   864,
     867,   868,   869,   143,   834,   143,   843,   871,   301,   143,
     143,   870,   872,   882,   889,   891,   893,   702,   892,   894,
     896,    98,   780,  -187,   897,   493,   681,   901,   784,   784,
     531,   500,   614,   683,   628,   693,   492,   665,   738,   633,
     694,   843,   695,   696,   697,   698,   699,   700,   701,   786,
     163,   624,   828,   502,   865,   554,   691,   223,   719,   676,
     492,   675,   618,   754,   492,   531,   617,   531,   364,   492,
     345,   824,   888,     0,     0,   818,     0,   146,   146,     0,
       0,   492,   143,     0,     0,     0,     0,   301,   166,   301,
       0,     0,     0,     0,    98,     0,   755,    98,   493,     0,
       0,   900,   531,     0,     0,   584,   587,     0,     0,   493,
       0,     0,   492,     0,     0,     0,    98,     0,   492,     0,
      98,     0,     0,     0,    98,     0,     0,    98,     0,    98,
       0,    98,   355,   531,   616,     0,   492,     0,   361,   361,
       0,     0,     0,     0,     0,     0,     0,   880,     0,     0,
     143,    98,     0,     0,     0,     0,   531,     0,     0,   143,
       0,     0,   531,   493,     0,     0,     0,    98,     0,   493,
       0,   493,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   157,     0,   170,     0,     0,     0,     0,     0,
       0,   664,     0,   493,     0,   178,     0,     0,     0,   146,
       0,     0,   186,   188,     0,     0,     0,   193,     0,   196,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,     0,     0,     0,     0,   221,   224,
       0,     0,     0,     0,     0,   146,     0,     0,   493,     0,
    -365,  -365,     0,   146,   146,   146,     0,   146,     0,   301,
       0,     0,  -365,  -365,     0,     0,     0,     0,   587,     0,
       0,     0,   493,     0,     0,     0,   493,     0,     0,     0,
       0,   493,     0,     0,     0,     0,     0,   294,     0,     0,
       0,     0,     0,   493,     0,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,   166,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,     0,     0,   493,     0,     0,     0,     0,   315,
     493,   316,     0,   317,   317,  -365,  -365,     0,   323,   326,
     193,     0,   331,     0,     0,     0,     0,     0,   493,     0,
    -365,  -365,     0,     0,     0,     0,     0,     0,     0,  -290,
    -290,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,   157,     0,     0,     0,   480,     0,     0,
       0,     0,     0,     0,     0,   380,     0,   387,     0,     0,
       0,     0,     0,     0,     0,   317,     0,   400,   401,   402,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,     0,   146,     0,     0,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     387,     0,   317,     0,   317,   453,     0,     0,   317,   317,
     317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     462,     0,   464,   241,     0,     0,     0,   387,     0,     0,
       0,     0,   146,     0,     0,     0,     0,   242,   474,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   501,   266,   146,     0,   146,  -382,  -382,  -382,
    -382,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,     0,   146,   146,     0,     0,     0,   387,   193,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,   525,     0,     0,     0,     0,     0,     0,     0,   146,
       0,   146,     0,     0,     0,   146,   146,     0,   382,     0,
       0,   551,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,   166,     0,     0,    29,
      30,   122,    32,    33,     0,   559,     0,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,    47,
       0,     0,     0,   578,     0,   326,   583,   123,     0,     0,
       0,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,   387,     0,   124,    75,    76,    77,
       0,     0,     0,    79,   125,   387,   383,    81,     0,     0,
       0,     0,    84,     0,     0,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   387,   387,     0,     0,
     642,     0,     0,     0,   387,   387,     0,     0,   387,     0,
       0,     0,   317,   652,     0,     0,     0,     0,     0,     0,
       0,   654,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   687,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,   317,   317,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,   326,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,   790,    78,    79,    80,     0,     0,    81,
       0,    82,    83,   517,    84,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,   822,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,   855,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     4,     5,     6,     7,     8,    74,    75,
      76,    77,     9,     0,    78,    79,    80,     0,     0,    81,
       0,    82,    83,   621,    84,  -382,  -382,  -382,  -382,  -382,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,     0,   266,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,     0,    34,
       0,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,     0,    42,     0,     0,    43,     0,     0,     0,
      44,    45,    46,    47,    48,    49,    50,     0,    51,    52,
      53,    54,    55,    56,     0,     0,     0,     0,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     4,     5,     6,     7,     8,
      74,    75,    76,    77,     9,     0,    78,    79,    80,     0,
       0,    81,     0,    82,    83,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   374,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   375,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
      32,    33,     0,    34,     0,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,     0,    42,     0,     0,
      43,     0,     0,     0,    44,    45,    46,    47,     0,    49,
      50,     0,    51,     0,    53,    54,    55,    56,     0,     0,
       0,     0,    57,    58,    59,   374,    61,    62,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       0,    70,    71,     0,    72,     0,     0,     0,    73,     4,
       5,     6,     7,     8,   124,    75,    76,    77,     9,     0,
      78,    79,    80,     0,     0,    81,     0,    82,    83,   497,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,   736,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,    54,    55,    56,
       0,     0,     0,     0,    57,    58,    59,   374,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,   742,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,   374,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     4,     5,     6,     7,     8,   124,    75,
      76,    77,     9,     0,    78,    79,    80,     0,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,     0,    34,
       0,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,     0,    42,     0,     0,    43,     0,     0,     0,
      44,    45,    46,    47,     0,    49,    50,     0,    51,     0,
      53,    54,    55,    56,     0,     0,     0,     0,    57,    58,
      59,   374,    61,    62,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     4,     5,     6,     7,     8,
     124,    75,    76,    77,     9,     0,    78,    79,    80,     0,
       0,    81,     0,    82,    83,   797,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,   860,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   374,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
      32,    33,     0,    34,     0,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,     0,    42,     0,     0,
      43,     0,     0,     0,    44,    45,    46,    47,     0,    49,
      50,     0,    51,     0,    53,    54,    55,    56,     0,     0,
       0,     0,    57,    58,    59,   374,    61,    62,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       0,    70,    71,     0,    72,     0,     0,     0,    73,     4,
       5,     6,     7,     8,   124,    75,    76,    77,     9,     0,
      78,    79,    80,     0,     0,    81,     0,    82,    83,   874,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,    54,    55,    56,
       0,     0,     0,     0,    57,    58,    59,   374,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,     0,    81,     0,    82,
      83,   877,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,    39,     0,    40,   881,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,    54,
      55,    56,     0,     0,     0,     0,    57,    58,    59,   374,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     4,     5,     6,     7,     8,   124,    75,
      76,    77,     9,     0,    78,    79,    80,     0,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,     0,    34,
       0,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,     0,    42,     0,     0,    43,     0,     0,     0,
      44,    45,    46,    47,     0,    49,    50,     0,    51,     0,
      53,    54,    55,    56,     0,     0,     0,     0,    57,    58,
      59,   374,    61,    62,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     4,     5,     6,     7,     8,
     124,    75,    76,    77,     9,     0,    78,    79,    80,     0,
       0,    81,     0,    82,    83,   884,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   374,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   895,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
      32,    33,     0,    34,     0,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,     0,    42,     0,     0,
      43,     0,     0,     0,    44,    45,    46,    47,     0,    49,
      50,     0,    51,     0,    53,    54,    55,    56,     0,     0,
       0,     0,    57,    58,    59,   374,    61,    62,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       0,    70,    71,     0,    72,     0,     0,     0,    73,     4,
       5,     6,     7,     8,   124,    75,    76,    77,     9,     0,
      78,    79,    80,     0,     0,    81,     0,    82,    83,   907,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,    54,    55,    56,
       0,     0,     0,     0,    57,    58,    59,   374,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,     0,    81,     0,    82,
      83,     0,    84,     0,   576,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,    54,
       0,     0,     0,     0,     0,     0,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     4,     5,     6,     7,     8,   124,    75,
      76,    77,     9,     0,     0,    79,    80,     0,     0,    81,
       0,    82,    83,     0,    84,     0,   579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,     0,    34,
       0,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,     0,    42,     0,     0,    43,     0,     0,     0,
      44,    45,    46,    47,     0,    49,    50,     0,    51,     0,
      53,    54,     0,     0,     0,     0,     0,     0,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     4,     5,     6,     7,     8,
     124,    75,    76,    77,     9,     0,     0,    79,    80,     0,
       0,    81,     0,    82,    83,     0,    84,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,     0,     0,     0,     0,     0,     0,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,     0,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
     783,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
      32,    33,     0,    34,     0,     0,     0,    35,    36,    37,
      38,    39,     0,    40,     0,    41,     0,    42,     0,     0,
      43,     0,     0,     0,    44,    45,    46,    47,     0,    49,
      50,     0,    51,     0,    53,    54,     0,     0,     0,     0,
       0,     0,    57,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       0,    70,    71,     0,    72,     0,     0,     0,    73,     4,
       5,     6,     7,     8,   124,    75,    76,    77,     9,     0,
       0,    79,    80,     0,     0,    81,     0,    82,    83,     0,
      84,     0,   823,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,    54,     0,     0,
       0,     0,     0,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,     0,    79,    80,     0,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,    54,
       0,     0,     0,     0,     0,     0,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     4,     5,     6,     7,     8,   124,    75,
      76,    77,     9,     0,     0,    79,    80,     0,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    29,    30,   122,    32,    33,     0,     0,
       0,     0,     0,    35,    36,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    47,   266,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    73,     9,     0,     0,     0,     0,
     124,    75,    76,    77,     0,     0,     0,    79,   125,     0,
       0,    81,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,    29,    30,   122,    32,
      33,     0,     0,     0,     0,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     4,
       5,     6,     7,     8,     0,     0,     0,    73,     9,     0,
       0,     0,     0,   124,    75,    76,    77,     0,     0,     0,
      79,   125,     0,     0,    81,     0,   185,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,    29,
      30,   122,    32,    33,     0,     0,     0,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      73,     9,     0,     0,     0,     0,   124,    75,    76,    77,
       0,     0,     0,    79,   125,     0,     0,    81,     0,   187,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,    29,    30,   122,    32,    33,     0,     0,     0,
       0,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     4,     5,     6,     7,     8,
       0,     0,     0,    73,     9,     0,     0,     0,     0,   124,
      75,    76,    77,     0,     0,     0,    79,   125,     0,     0,
      81,     0,   191,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    29,    30,   122,    32,    33,
       0,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     4,     5,
       6,     7,     8,     0,     0,     0,    73,     9,     0,     0,
       0,     0,   124,    75,    76,    77,     0,     0,     0,    79,
     125,   403,     0,    81,   314,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,    29,    30,
     122,    32,    33,     0,     0,     0,     0,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    73,
       9,     0,     0,     0,     0,   124,    75,    76,    77,     0,
       0,     0,    79,   125,     0,     0,    81,     0,     0,     0,
     429,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,     0,     0,
       0,    29,    30,   122,    32,    33,     0,     0,     0,     0,
       0,    35,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     4,     5,     6,     7,     8,     0,
       0,     0,    73,     9,     0,     0,     0,     0,   124,    75,
      76,    77,     0,     0,     0,    79,   125,     0,     0,    81,
       0,     0,     0,   461,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,    29,    30,   122,    32,    33,     0,
       0,     0,     0,     0,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    73,     9,     0,     0,     0,
       0,   124,    75,    76,    77,     0,     0,     0,    79,   125,
       0,     0,    81,     0,     0,     0,   463,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    29,    30,   122,
      32,    33,     0,     0,     0,     0,     0,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       4,     5,     6,     7,     8,     0,     0,     0,    73,     9,
       0,     0,     0,     0,   124,    75,    76,    77,     0,     0,
       0,    79,   125,     0,     0,    81,     0,     0,     0,   653,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      29,    30,   122,    32,    33,     0,     0,     0,     0,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     4,     5,     6,     7,     8,     0,     0,
       0,    73,     9,     0,     0,     0,     0,   124,    75,    76,
      77,     0,     0,     0,    79,   125,     0,     0,    81,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    29,    30,   122,    32,    33,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    73,     9,     0,     0,     0,     0,
     124,    75,    76,    77,     0,     0,     0,    79,   125,     0,
       0,    81,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,    29,    30,   122,    32,
      33,     0,     0,     0,     0,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,   124,    75,    76,    77,   239,   240,   241,
      79,    80,     0,     0,    81,     0,     0,     0,     0,    84,
       0,     0,     0,   242,     0,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,     0,   266,
     239,   240,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,     0,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,     0,   266,   239,   240,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   523,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,     0,   266,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,   567,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
       0,   266,     0,     0,   239,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   611,
     242,   791,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   646,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   266,   239,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   728,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   792,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   242,   267,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,     0,   266,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   332,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   266,   239,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   333,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,   339,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
       0,   266,     0,   239,   240,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   372,   242,
       0,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,     0,   266,   239,   240,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   457,   242,     0,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,     0,   266,     0,
       0,     0,     0,     0,     0,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   470,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   266,     0,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,   471,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
       0,   266,   239,   240,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   242,   476,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,     0,   266,     0,     0,     0,     0,     0,
       0,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   484,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,     0,   266,     0,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   659,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   266,   239,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   858,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,     0,
       0,     0,     0,     0,   879,     0,     0,     0,     0,     0,
       0,     0,   242,   302,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,     0,   266,   485,
     486,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,     0,     0,     0,
     487,     0,     0,   239,   240,   241,     0,     0,    29,    30,
     137,     0,     0,     0,     0,     0,     0,     0,   488,   242,
     552,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,     0,   266,   138,     0,     0,     0,
       0,     0,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,    65,    66,    67,    68,    69,
       0,     0,     0,     0,     0,   239,   240,   241,     0,    73,
       0,     0,     0,     0,     0,   490,    75,    76,   491,     0,
       0,   242,    79,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   266,   240,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,     0,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   242,   266,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,     0,   266,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,     0,   266,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
       0,   266,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,     0,   266
};

static const yytype_int16 yycheck[] =
{
       2,   126,    25,    25,     2,     2,   312,    49,   505,    14,
      15,   712,   195,   707,   477,   266,   176,     8,   217,     8,
      25,     2,    25,   238,     8,     8,   382,    26,     8,     8,
       8,     8,   594,     8,     8,     8,     8,     8,    80,     8,
      26,   538,    32,    81,    65,   636,   635,    52,    75,   107,
      77,     0,    54,   754,    65,   153,    65,    38,    65,    26,
      77,    98,    99,   161,   161,    65,   161,   153,   283,    74,
     285,   153,    77,   282,   147,   161,   161,   237,    65,   161,
     153,    75,   207,   298,   299,   161,   103,    77,   161,    32,
     161,    25,   115,   308,    53,    54,   311,   312,    65,   161,
     309,   159,    32,   141,    25,   461,   668,   463,   670,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   123,   713,   335,   284,    77,   286,    75,   165,    77,
     290,   291,   292,    77,    77,   140,   147,   349,   147,   166,
     182,    75,    75,   164,    77,    75,   169,    77,   335,    53,
      54,   156,   161,   164,    75,   164,   161,   164,    77,    75,
     369,   161,   349,    77,   164,   164,    75,   161,    77,   368,
     160,   164,   163,   867,   163,   164,   765,   163,   769,   163,
     163,   111,    75,   163,   163,   163,   163,   162,   162,   162,
     162,   162,   197,   162,    32,   129,   147,   202,   661,   161,
     901,    75,   153,    77,    32,   210,   211,   212,   129,   214,
      95,   216,    95,    75,   166,   238,   150,   160,   166,   153,
     150,   155,   166,   153,   226,   161,    98,    99,   162,   150,
      75,   161,   153,   166,   155,   238,   166,   153,   122,    77,
      75,    14,    15,   266,   266,   147,   160,   166,   164,    77,
     147,   153,    25,   161,    75,   164,   153,   166,   162,   163,
     283,   266,   285,   266,   161,   147,   162,   163,   153,   481,
     153,   153,    66,   485,   486,   298,   299,    75,   147,   161,
     283,    75,   285,    77,   153,   308,   162,   163,   311,   312,
     295,   153,   166,   165,   481,   298,   299,   653,   485,   486,
     487,   306,   553,   153,   161,   308,   122,   516,   311,   312,
      97,    98,    99,   163,   164,   150,   528,   111,   153,    97,
      98,    99,   161,   389,    75,   391,    77,   161,   370,   150,
     335,   129,   153,    70,    71,   161,   338,   342,   161,   548,
     549,   528,    70,    71,   349,   163,   164,   556,   557,   655,
      75,   560,   150,    14,    15,   153,   150,   155,   164,   153,
     111,    47,    48,    49,   366,    51,    75,   161,   366,   366,
      14,    15,   166,    75,    75,    77,   399,   382,   163,    32,
      65,   147,   161,   156,   389,   366,   391,   147,    65,   394,
     126,    65,    65,   576,   891,    65,   579,    65,   103,   150,
     612,   153,   153,    51,   564,    49,   153,   590,    66,   111,
     161,   167,   147,   164,   601,   166,   147,     8,   147,   725,
     153,   153,   103,   161,   429,   612,   128,   147,   126,   202,
     111,   112,   113,   114,   115,   116,    80,   210,   211,   212,
     655,   214,    44,    45,    46,    47,    48,    49,   150,    51,
      87,   153,    75,   163,   666,    13,   461,   163,   463,   161,
     672,    13,   674,   162,   166,   162,   162,   533,    75,    75,
      75,    77,   124,   124,   479,   480,   481,   161,   167,   666,
     485,   486,   487,   161,   167,   672,   491,   674,   648,   649,
     471,   163,     8,   266,    95,   476,    13,   680,    75,    77,
     505,   506,   483,   508,   716,   111,   161,   512,   513,   163,
     725,   161,   156,   162,   161,    75,   518,    77,     8,   162,
     518,   518,   162,   528,    13,   530,   125,   161,   533,   716,
     553,   553,   164,   538,   539,   161,   167,   518,   182,   161,
     167,   162,   161,   161,   150,   161,    75,   153,   553,   161,
     553,   111,   167,   167,   167,   161,   167,   153,   202,   771,
     166,   147,   335,    75,   630,   162,   210,   211,   212,    13,
     214,   163,    13,   162,   162,     8,   349,   153,   162,   164,
     585,     8,    65,   795,   771,    65,   126,   799,   163,   127,
     150,    13,   804,   153,   163,   163,   601,   602,     8,   127,
     783,   161,   167,    75,   816,   161,   166,   612,   795,   382,
     793,   164,   799,   679,   162,   162,   162,   804,   163,    77,
      13,   626,   109,   162,   126,   630,   162,   810,   694,   816,
     635,   814,   655,   167,    77,   847,   162,   820,   162,   162,
     823,   853,   163,   162,   162,   828,    75,   162,   653,   832,
      26,   161,   655,    13,   167,   657,   429,   662,   660,   871,
     847,   666,   167,   161,   163,   667,   853,   672,   162,   674,
     163,   163,   127,    77,   679,    13,    13,    75,   164,   862,
     164,    13,   807,   161,   871,    26,   104,    72,   461,   694,
     463,   109,   163,   111,   112,   113,   114,   115,   116,   117,
     162,   164,   725,    77,   706,    13,   479,   480,   481,    77,
     893,   716,   485,   486,   487,   111,   112,   113,   114,   115,
     116,   904,   725,    13,   163,    95,   370,   164,   163,   165,
      95,   154,   163,   506,   800,   508,   802,    13,   382,   512,
     513,   147,    75,   163,    75,   161,    26,   165,    77,   163,
      75,   753,   733,    75,     8,   528,   607,   162,   739,   740,
     765,   342,   506,   607,   533,   104,   771,   586,   662,   539,
     109,   837,   111,   112,   113,   114,   115,   116,   117,   740,
     553,   527,   790,   347,   837,   429,   629,    81,   643,   601,
     795,   600,   513,   685,   799,   800,   512,   802,   215,   804,
     202,   782,   868,    -1,    -1,   775,    -1,    14,    15,    -1,
      -1,   816,   585,    -1,    -1,    -1,    -1,   461,    25,   463,
      -1,    -1,    -1,    -1,   826,    -1,   165,   829,   601,    -1,
      -1,   897,   837,    -1,    -1,   479,   480,    -1,    -1,   612,
      -1,    -1,   847,    -1,    -1,    -1,   848,    -1,   853,    -1,
     852,    -1,    -1,    -1,   856,    -1,    -1,   859,    -1,   861,
      -1,   863,   506,   868,   508,    -1,   871,    -1,   512,   513,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   858,    -1,    -1,
     653,   883,    -1,    -1,    -1,    -1,   891,    -1,    -1,   662,
      -1,    -1,   897,   666,    -1,    -1,    -1,   899,    -1,   672,
      -1,   674,    -1,    -1,   906,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,   585,    -1,   716,    -1,    37,    -1,    -1,    -1,   156,
      -1,    -1,    44,    45,    -1,    -1,    -1,    49,    -1,    51,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,   771,    -1,
      53,    54,    -1,   210,   211,   212,    -1,   214,    -1,   653,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,   662,    -1,
      -1,    -1,   795,    -1,    -1,    -1,   799,    -1,    -1,    -1,
      -1,   804,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,   816,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,   266,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,   847,    -1,    -1,    -1,    -1,   171,
     853,   173,    -1,   175,   176,    53,    54,    -1,   180,   181,
     182,    -1,   184,    -1,    -1,    -1,    -1,    -1,   871,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   215,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   382,    -1,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,    -1,   284,    -1,   286,   287,    -1,    -1,   290,   291,
     292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     302,    -1,   304,    11,    -1,    -1,    -1,   309,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    -1,    -1,    25,   320,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   344,    51,   461,    -1,   463,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,   479,   480,    -1,    -1,    -1,   369,   370,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      -1,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   506,
      -1,   508,    -1,    -1,    -1,   512,   513,    -1,    32,    -1,
      -1,   403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,   553,    -1,    -1,    73,
      74,    75,    76,    77,    -1,   447,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,   103,
      -1,    -1,    -1,   475,    -1,   477,   478,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,    -1,   516,    -1,   150,   151,   152,   153,
      -1,    -1,    -1,   157,   158,   527,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,   653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   662,   548,   549,    -1,    -1,
     552,    -1,    -1,    -1,   556,   557,    -1,    -1,   560,    -1,
      -1,    -1,   564,   565,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   573,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,   648,   649,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,   661,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    -1,    89,    -1,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,    -1,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,    -1,   745,   156,   157,   158,    -1,    -1,   161,
      -1,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,   779,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    -1,   819,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    -1,    89,    -1,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,    -1,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,     3,     4,     5,     6,     7,   150,   151,
     152,   153,    12,    -1,   156,   157,   158,    -1,    -1,   161,
      -1,   163,   164,   165,   166,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,    89,
      -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,    -1,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,   144,     3,     4,     5,     6,     7,
     150,   151,   152,   153,    12,    -1,   156,   157,   158,    -1,
      -1,   161,    -1,   163,   164,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,   101,   102,   103,    -1,   105,   106,    -1,
     108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,   137,
     138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,
       6,     7,   150,   151,   152,   153,    12,    -1,   156,   157,
     158,    -1,    -1,   161,    -1,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,
      96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,
     106,    -1,   108,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,
       4,     5,     6,     7,   150,   151,   152,   153,    12,    -1,
     156,   157,   158,    -1,    -1,   161,    -1,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    -1,    93,
      -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,
      -1,   105,   106,    -1,   108,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,
     144,     3,     4,     5,     6,     7,   150,   151,   152,   153,
      12,    -1,   156,   157,   158,    -1,    -1,   161,    -1,   163,
     164,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    -1,    89,    -1,    91,
      -1,    93,    94,    -1,    96,    -1,    -1,    -1,   100,   101,
     102,   103,    -1,   105,   106,    -1,   108,    -1,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,     3,     4,     5,     6,     7,   150,   151,
     152,   153,    12,    -1,   156,   157,   158,    -1,    -1,   161,
      -1,   163,   164,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,    89,
      -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,   105,   106,    -1,   108,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,   144,     3,     4,     5,     6,     7,
     150,   151,   152,   153,    12,    -1,   156,   157,   158,    -1,
      -1,   161,    -1,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      -1,    89,    -1,    91,    92,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,   101,   102,   103,    -1,   105,   106,    -1,
     108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,   137,
     138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,
       6,     7,   150,   151,   152,   153,    12,    -1,   156,   157,
     158,    -1,    -1,   161,    -1,   163,   164,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,
      96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,
     106,    -1,   108,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,
       4,     5,     6,     7,   150,   151,   152,   153,    12,    -1,
     156,   157,   158,    -1,    -1,   161,    -1,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    -1,    89,    -1,    91,    -1,    93,
      -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,
      -1,   105,   106,    -1,   108,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,
     144,     3,     4,     5,     6,     7,   150,   151,   152,   153,
      12,    -1,   156,   157,   158,    -1,    -1,   161,    -1,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
     102,   103,    -1,   105,   106,    -1,   108,    -1,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,     3,     4,     5,     6,     7,   150,   151,
     152,   153,    12,    -1,   156,   157,   158,    -1,    -1,   161,
      -1,   163,   164,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,    89,
      -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,   105,   106,    -1,   108,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,   144,     3,     4,     5,     6,     7,
     150,   151,   152,   153,    12,    -1,   156,   157,   158,    -1,
      -1,   161,    -1,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,   101,   102,   103,    -1,   105,   106,    -1,
     108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,   137,
     138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,
       6,     7,   150,   151,   152,   153,    12,    -1,   156,   157,
     158,    -1,    -1,   161,    -1,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,
      96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,
     106,    -1,   108,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,
       4,     5,     6,     7,   150,   151,   152,   153,    12,    -1,
     156,   157,   158,    -1,    -1,   161,    -1,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    -1,    89,    -1,    91,    -1,    93,
      -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,
      -1,   105,   106,    -1,   108,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,
     144,     3,     4,     5,     6,     7,   150,   151,   152,   153,
      12,    -1,   156,   157,   158,    -1,    -1,   161,    -1,   163,
     164,    -1,   166,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    -1,    89,    -1,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
     102,   103,    -1,   105,   106,    -1,   108,    -1,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,     3,     4,     5,     6,     7,   150,   151,
     152,   153,    12,    -1,    -1,   157,   158,    -1,    -1,   161,
      -1,   163,   164,    -1,   166,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,    89,
      -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,   105,   106,    -1,   108,    -1,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,   144,     3,     4,     5,     6,     7,
     150,   151,   152,   153,    12,    -1,    -1,   157,   158,    -1,
      -1,   161,    -1,   163,   164,    -1,   166,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,
      -1,    -1,   100,   101,   102,   103,    -1,   105,   106,    -1,
     108,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,   137,
     138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,
       6,     7,   150,   151,   152,   153,    12,    -1,    -1,   157,
     158,    -1,    -1,   161,    -1,   163,   164,    -1,   166,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,
      96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,
     106,    -1,   108,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,
       4,     5,     6,     7,   150,   151,   152,   153,    12,    -1,
      -1,   157,   158,    -1,    -1,   161,    -1,   163,   164,    -1,
     166,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    -1,    89,    -1,    91,    -1,    93,
      -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,
      -1,   105,   106,    -1,   108,    -1,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,
     144,     3,     4,     5,     6,     7,   150,   151,   152,   153,
      12,    -1,    -1,   157,   158,    -1,    -1,   161,    -1,   163,
     164,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    -1,    89,    -1,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
     102,   103,    -1,   105,   106,    -1,   108,    -1,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,     3,     4,     5,     6,     7,   150,   151,
     152,   153,    12,    -1,    -1,   157,   158,    -1,    -1,   161,
      -1,   163,   164,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   103,    51,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   144,    12,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,
      -1,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   144,    12,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,    -1,    -1,    -1,
     157,   158,    -1,    -1,   161,    -1,   163,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     144,    12,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
      -1,    -1,    -1,   157,   158,    -1,    -1,   161,    -1,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   144,    12,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,    -1,
     161,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,   144,    12,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,    -1,    -1,    -1,   157,
     158,    26,    -1,   161,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   144,
      12,    -1,    -1,    -1,    -1,   150,   151,   152,   153,    -1,
      -1,    -1,   157,   158,    -1,    -1,   161,    -1,    -1,    -1,
      32,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   144,    12,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,    -1,    -1,    -1,   157,   158,    -1,    -1,   161,
      -1,    -1,    -1,    32,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   144,    12,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,    -1,    -1,    -1,   157,   158,
      -1,    -1,   161,    -1,    -1,    -1,    32,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   144,    12,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,    -1,    -1,
      -1,   157,   158,    -1,    -1,   161,    -1,    -1,    -1,    32,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   144,    12,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,    -1,    -1,    -1,   157,   158,    -1,    -1,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   144,    12,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,    -1,    -1,    -1,   157,   158,    -1,
      -1,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,     9,    10,    11,
     157,   158,    -1,    -1,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   165,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   165,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   165,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   165,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   163,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   163,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   163,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   163,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   163,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   162,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   162,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   162,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   162,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   162,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   162,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   127,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      65,    -1,    -1,     9,    10,    11,    -1,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,   144,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,    -1,
      -1,    25,   157,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    25,    51,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   169,   170,     0,     3,     4,     5,     6,     7,    12,
      44,    45,    50,    52,    53,    54,    55,    56,    57,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    73,
      74,    75,    76,    77,    79,    83,    84,    85,    86,    87,
      89,    91,    93,    96,   100,   101,   102,   103,   104,   105,
     106,   108,   109,   110,   111,   112,   113,   118,   119,   120,
     121,   122,   123,   128,   129,   130,   131,   132,   133,   134,
     137,   138,   140,   144,   150,   151,   152,   153,   156,   157,
     158,   161,   163,   164,   166,   171,   172,   175,   178,   179,
     186,   187,   189,   190,   191,   193,   248,   249,   250,   253,
     254,   262,   265,   269,   270,   272,   273,   279,   280,   281,
     282,   283,   284,   285,   286,   291,   296,   298,   299,   300,
     301,   302,    75,   111,   150,   158,   250,   269,   269,   161,
     269,   269,   269,   269,   269,   269,   269,    75,   111,   150,
     153,   161,   171,   254,   272,   273,   281,   272,   269,   269,
     269,   269,   269,   269,   269,   269,    32,   269,   294,   295,
     150,   153,   171,   254,   256,   257,   281,   284,   285,   291,
     269,   161,   260,   161,    26,    65,    65,   245,   269,   178,
     161,   161,   161,   161,   161,   163,   269,   163,   269,    75,
      75,   163,   248,   269,   273,   164,   269,   153,   171,   173,
     174,    77,   166,   220,   221,    77,   222,   250,   122,   122,
     161,   161,   161,   161,   161,   161,   153,   164,   171,   171,
     248,   269,   273,   249,   269,   301,   176,   164,   153,   161,
       8,   163,    75,    75,   163,    32,   188,    65,   147,     9,
      10,    11,    25,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    51,   163,    53,    54,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   161,   147,    65,   126,    65,   164,   166,   285,
      65,    65,    65,   188,   269,   153,   171,   301,   147,   147,
     271,   273,   127,   167,     8,   267,   153,   171,   147,   161,
     261,   147,   126,   285,   162,   269,   269,   269,   287,   287,
       8,   163,    87,   269,   246,   247,   269,   248,   273,    75,
     202,   269,   163,   163,   163,    13,   163,   163,   176,   163,
     171,    95,     8,   163,   164,   270,   273,     8,   163,    13,
       8,   163,   188,   184,   185,   273,   273,   297,   273,   162,
     128,   273,   292,   293,   294,   171,   170,   163,   164,   161,
     127,   162,   162,   162,   121,   165,   177,   178,   186,   187,
     269,    75,    32,   160,   217,   218,   219,   269,    75,   124,
     192,   124,   194,    75,   161,   287,    75,   279,   285,   291,
     269,   269,   269,    26,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   256,    32,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   217,    75,   279,   287,    75,   164,   279,   288,
     289,   290,   287,   269,   287,   287,   287,   162,   171,    75,
      75,    32,   269,    32,   269,   171,   279,   217,   279,   288,
     162,   162,   167,   167,   269,   161,   162,   163,     8,    95,
      95,    13,     8,   162,   162,    44,    45,    65,    83,   129,
     150,   153,   171,   254,   262,   263,   264,   165,    95,    75,
     174,   269,   221,   263,    77,   161,     8,   162,     8,   162,
     162,   163,   161,     8,   162,   162,   161,   165,   170,   217,
     248,   273,   161,   165,   271,   269,   162,     8,    13,   150,
     153,   171,   255,   125,   195,   196,   255,   164,   161,    25,
     129,   155,   211,   212,   214,   215,   255,   167,   161,   161,
     285,   269,    26,    66,   273,   162,   161,   161,   167,   269,
     161,   276,   277,   278,    65,   164,   167,   165,   167,   167,
     167,   271,   271,   127,   162,   258,    26,   178,   269,    26,
     178,   206,   246,   269,   273,    32,   198,   273,   263,    75,
      26,   178,   201,    26,   164,   203,   263,   263,   263,   266,
     268,   161,   153,   171,   147,   107,   159,   180,   181,   183,
      75,   165,    13,   211,   185,   163,   273,   292,   293,    13,
     217,   165,   162,   162,   219,   263,   153,   171,   196,   164,
       8,   223,   211,   215,   162,     8,    32,    77,   160,   213,
     217,   217,   269,   256,   217,   217,   165,   217,    65,    65,
     274,   287,   269,    32,   269,   126,   259,   176,   207,   162,
     176,   163,   127,   197,   273,   197,    13,   176,   163,   204,
     163,   204,   127,   167,     8,   267,   266,   171,    75,   161,
     164,   181,   182,   183,   263,   162,   162,   269,   162,   163,
     171,   223,   255,   104,   109,   111,   112,   113,   114,   115,
     116,   117,   165,   224,   226,   239,   240,   241,   242,   244,
     162,   109,   251,   214,   213,    77,    13,   162,   162,   261,
     162,   162,   162,   287,   287,   126,   275,   167,   165,   271,
     288,   208,    70,    71,   209,   163,    88,   246,   198,   162,
     162,   263,    94,   204,    97,    98,    99,   204,   165,   263,
     263,   162,   255,   176,   251,   165,    75,   227,   255,    77,
     243,   250,   242,     8,   163,    26,   216,   161,   216,    32,
     213,    13,   263,   167,   167,   288,    70,    71,   210,   161,
     178,   163,   162,    26,   178,   200,   200,   163,    97,   163,
     269,    26,   163,   205,   165,   127,    77,   165,   216,    13,
       8,   163,   164,   228,    13,     8,   163,   225,    75,   214,
     164,    32,    77,   252,   164,   213,    13,   263,   278,   161,
      26,    72,   269,    26,   178,   199,   176,   163,   205,   176,
     263,   162,   164,   263,   255,    75,   229,   230,   231,   232,
     234,   235,   236,   255,   263,    77,   188,    13,   176,    77,
       8,   162,   176,    13,   263,   269,   176,   163,   162,   176,
      92,   176,   164,   176,   165,   231,   163,    95,   154,   163,
     147,    13,    75,   263,   165,    32,    77,   165,   263,   162,
     178,    90,   163,   176,   165,   237,   242,   233,   255,    75,
     263,   161,    77,    26,   163,   165,    75,     8,   211,   176,
     255,   162,   216,   163,   164,   238,   176,   165
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   168,   169,   170,   170,   171,   171,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   173,   173,   174,   174,
     174,   174,   175,   175,   176,   176,   177,   177,   177,   177,
     178,   178,   178,   178,   178,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   180,   180,   181,   182,   182,   183,
     184,   184,   185,   186,   187,   188,   188,   189,   190,   190,
     191,   191,   191,   191,   192,   192,   193,   194,   194,   195,
     195,   196,   196,   197,   197,   198,   198,   199,   199,   200,
     200,   201,   201,   202,   202,   203,   203,   203,   203,   204,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   212,   212,   212,
     212,   212,   212,   212,   213,   213,   214,   214,   214,   215,
     215,   215,   216,   216,   217,   217,   218,   218,   219,   219,
     219,   220,   220,   221,   221,   221,   222,   222,   222,   222,
     223,   223,   224,   224,   224,   225,   224,   226,   227,   227,
     228,   228,   229,   229,   230,   230,   231,   231,   232,   233,
     233,   234,   234,   235,   236,   236,   237,   237,   238,   238,
     239,   239,   240,   240,   241,   241,   242,   242,   242,   242,
     242,   242,   243,   243,   243,   243,   244,   244,   245,   245,
     246,   246,   247,   247,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   249,   249,   249,
     249,   250,   251,   251,   252,   252,   252,   252,   253,   253,
     253,   253,   253,   253,   253,   253,   254,   254,   254,   254,
     255,   255,   255,   256,   256,   257,   257,   258,   258,   259,
     260,   260,   260,   261,   261,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   264,   265,   265,   265,
     265,   265,   265,   266,   266,   267,   267,   268,   268,   268,
     268,   269,   269,   270,   271,   272,   273,   273,   274,   274,
     275,   276,   276,   277,   278,   278,   278,   279,   279,   280,
     280,   281,   282,   282,   283,   283,   283,   284,   284,   284,
     284,   285,   285,   285,   286,   286,   287,   287,   288,   288,
     289,   289,   289,   290,   290,   291,   291,   292,   292,   293,
     293,   293,   294,   294,   295,   295,   295,   295,   295,   295,
     295,   295,   296,   296,   296,   296,   296,   296,   296,   297,
     297,   298,   298,   299,   299,   299,   299,   299,   300,   300,
     301,   302,   302
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     1,     1,     1,
       4,     3,     5,     4,     3,     2,     3,     1,     1,     3,
       2,     4,     5,     4,     2,     0,     1,     1,     1,     4,
       1,     2,     1,     1,     1,     3,     7,    10,     5,     7,
       9,     5,     2,     3,     2,     3,     2,     3,     3,     3,
       3,     3,     1,     2,     2,     5,     8,     8,     5,     1,
       6,     5,     3,     3,     2,     1,     8,     0,     1,     4,
       1,     3,     1,     1,     1,     0,     1,    10,     7,     6,
       1,     2,     2,     1,     0,     2,     1,     0,     2,     0,
       2,     1,     3,     0,     2,     1,     2,     1,     4,     1,
       4,     1,     4,     3,     5,     3,     4,     4,     5,     0,
       5,     4,     1,     1,     1,     4,     0,     6,     0,     7,
       0,     2,     0,     3,     1,     0,     2,     3,     5,     4,
       4,     5,     7,     6,     2,     1,     0,     1,     2,     1,
       1,     1,     0,     2,     1,     0,     1,     3,     1,     2,
       2,     3,     1,     1,     2,     4,     3,     5,     1,     3,
       2,     0,     3,     2,     1,     0,    10,     3,     1,     3,
       1,     3,     0,     1,     1,     2,     2,     2,     3,     1,
       3,     1,     1,     3,     4,     3,     0,     1,     1,     3,
       1,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     5,     1,     3,     5,     4,     3,     1,
       0,     1,     3,     1,     6,     3,     4,     6,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     5,     4,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     1,    10,    11,     2,     2,     4,
       4,     1,     0,     4,     3,     4,     1,     2,     4,     6,
       5,     6,     6,     6,     6,     4,     1,     1,     3,     2,
       1,     3,     2,     1,     1,     4,     1,     2,     0,     2,
       0,     2,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     2,     4,     3,     1,     3,     1,     1,     1,
       3,     2,     1,     0,     2,     0,     1,     5,     3,     3,
       1,     1,     1,     1,     1,     1,     5,     1,     2,     0,
       3,     4,     4,     3,     1,     1,     0,     1,     2,     3,
       3,     1,     4,     4,     1,     1,     1,     1,     3,     2,
       1,     4,     4,     1,     1,     4,     0,     1,     1,     1,
       4,     4,     1,     1,     3,     1,     2,     3,     1,     1,
       4,     0,     0,     2,     5,     3,     3,     1,     6,     4,
       4,     2,     4,     4,     2,     2,     4,     2,     2,     1,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     3,
       3,     3,     3
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
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (yyscanner, root, YY_("syntax error: cannot back up")); \
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
                  Type, Value, yyscanner, root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void* yyscanner, xhpast::Node** root)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yyscanner);
  YYUSE (root);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void* yyscanner, xhpast::Node** root)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, root);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, void* yyscanner, xhpast::Node** root)
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
                                              , yyscanner, root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, yyscanner, root); \
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
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
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
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void* yyscanner, xhpast::Node** root)
{
  YYUSE (yyvaluep);
  YYUSE (yyscanner);
  YYUSE (root);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void* yyscanner, xhpast::Node** root)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, yyscanner);
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
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
  switch (yyn)
    {
        case 2:
#line 210 "parser.y" /* yacc.c:1646  */
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[0]));
  }
#line 3439 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 216 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3447 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 219 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3455 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 225 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_SYMBOL_NAME);
  }
#line 3463 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 228 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-2]), (yyvsp[0]));
  }
#line 3471 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 237 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3481 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 242 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_NAMESPACE, (yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3493 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 249 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-4]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-4])->appendChild((yyvsp[-3]));
  (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3504 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 255 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-3]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-3])->appendChild(NNEW(n_EMPTY));
  NMORE((yyvsp[-1]), (yyvsp[0]));
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyvsp[-3])->appendChild((yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  }
#line 3517 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 263 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3527 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 268 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3536 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 275 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 3544 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 278 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3553 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 285 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3563 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 290 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3574 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 296 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3585 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 302 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3597 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 312 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyval), (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3609 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 319 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3621 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 329 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3629 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 332 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3637 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 341 "parser.y" /* yacc.c:1646  */
    {
  (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3647 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 350 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3658 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 356 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3666 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 359 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3674 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 362 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLOSE_TAG);
  }
#line 3682 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 368 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 3690 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 371 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);

    (yyvsp[-6]) = NTYPE((yyvsp[-6]), n_IF);
    (yyvsp[-6])->appendChild(NSPAN((yyvsp[-5]), n_CONTROL_CONDITION, (yyvsp[-3]))->appendChild((yyvsp[-4])));
    (yyvsp[-6])->appendChild((yyvsp[-2]));

    (yyval)->appendChild((yyvsp[-6]));
    (yyval)->appendChildren((yyvsp[-1]));

    // Hacks: merge a list of if (x) { } else if (y) { } into a single condition
    // list instead of a condition tree.

    if ((yyvsp[0])->type == n_EMPTY) {
      // Ignore.
    } else if ((yyvsp[0])->type == n_ELSE) {
      xhpast::Node *stype = (yyvsp[0])->firstChild()->firstChild();
      if (stype && stype->type == n_CONDITION_LIST) {
        NTYPE(stype->firstChild(), n_ELSEIF);
        stype->firstChild()->l_tok = (yyvsp[0])->l_tok;
        (yyval)->appendChildren(stype);
      } else {
        (yyval)->appendChild((yyvsp[0]));
      }
    } else {
      (yyval)->appendChild((yyvsp[0]));
    }

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
#line 3725 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 405 "parser.y" /* yacc.c:1646  */
    {

    (yyval) = NNEW(n_CONDITION_LIST);
    NTYPE((yyvsp[-9]), n_IF);
    (yyvsp[-9])->appendChild(NSPAN((yyvsp[-8]), n_CONTROL_CONDITION, (yyvsp[-6]))->appendChild((yyvsp[-7])));
    (yyvsp[-9])->appendChild((yyvsp[-4]));

    (yyval)->appendChild((yyvsp[-9]));
    (yyval)->appendChildren((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3745 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 420 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_WHILE);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3757 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 427 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-6]), n_DO_WHILE);
    (yyvsp[-6])->appendChild((yyvsp[-5]));
    (yyvsp[-6])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-6]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3770 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 435 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-8]), n_FOR);

    NSPAN((yyvsp[-7]), n_FOR_EXPRESSION, (yyvsp[-1]))
      ->appendChild((yyvsp[-6]))
      ->appendChild((yyvsp[-4]))
      ->appendChild((yyvsp[-2]));

    (yyvsp[-8])->appendChild((yyvsp[-7]));
    (yyvsp[-8])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-8]));
  }
#line 3788 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 448 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_SWITCH);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3800 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 455 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_BREAK);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3812 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 462 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_BREAK);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3824 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 469 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_CONTINUE);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3836 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 476 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_CONTINUE);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3848 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 483 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_RETURN);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3860 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 490 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3872 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 497 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3884 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 504 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3894 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 509 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3904 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 514 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3914 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 519 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_INLINE_HTML);
    (yyval) = (yyvsp[0]);
  }
#line 3923 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 523 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3932 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 527 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3941 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 531 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[-1]));
    NMORE((yyvsp[-2]), (yyvsp[-4]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3952 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 538 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-7]), n_FOREACH);
    NSPAN((yyvsp[-6]), n_FOREACH_EXPRESSION, (yyvsp[-1]));
    (yyvsp[-6])->appendChild((yyvsp[-5]));
    if ((yyvsp[-2])->type == n_EMPTY) {
      (yyvsp[-6])->appendChild((yyvsp[-2]));
      (yyvsp[-6])->appendChild((yyvsp[-3]));
    } else {
      (yyvsp[-6])->appendChild((yyvsp[-3]));
      (yyvsp[-6])->appendChild((yyvsp[-2]));
    }
    (yyvsp[-7])->appendChild((yyvsp[-6]));

    (yyvsp[-7])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-7]));
  }
#line 3974 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 556 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-7]), n_FOREACH);
    NSPAN((yyvsp[-6]), n_FOREACH_EXPRESSION, (yyvsp[-1]));
    (yyvsp[-6])->appendChild((yyvsp[-5]));
    if ((yyvsp[-2])->type == n_EMPTY) {
      (yyvsp[-6])->appendChild((yyvsp[-2]));
      (yyvsp[-6])->appendChild((yyvsp[-3]));
    } else {
      (yyvsp[-6])->appendChild((yyvsp[-3]));
      (yyvsp[-6])->appendChild((yyvsp[-2]));
    }
    (yyvsp[-7])->appendChild((yyvsp[-6]));
    (yyvsp[-7])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-7]));
  }
#line 3995 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 572 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_DECLARE);
    (yyvsp[-4])->appendChild((yyvsp[-2]));
    (yyvsp[-4])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4006 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 578 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4015 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 582 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_TRY);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));

    (yyvsp[-5])->appendChild((yyvsp[-1]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-5]));
  }
#line 4029 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 591 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_TRY);
    (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1])));

    (yyvsp[-4])->appendChild(NNEW(n_CATCH_LIST));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4043 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 600 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_THROW);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));

  }
#line 4056 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 608 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_GOTO);
  NTYPE((yyvsp[-1]), n_STRING);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 4069 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 619 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4078 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 623 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_CATCH_LIST);
  (yyval)->appendChild((yyvsp[0]));
}
#line 4087 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 630 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-7]), n_CATCH);
    (yyvsp[-7])->appendChild((yyvsp[-5]));
    (yyvsp[-7])->appendChild(NTYPE((yyvsp[-4]), n_VARIABLE));
    (yyvsp[-7])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyvsp[-7]), (yyvsp[0]));
    (yyval) = (yyvsp[-7]);
  }
#line 4100 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 641 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4108 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 648 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_FINALLY);
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    NMORE((yyvsp[-3]), (yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 4119 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 657 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4128 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 661 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4137 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 680 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4145 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 683 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_REFERENCE);
  }
#line 4153 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 690 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-9]), n_FUNCTION_DECLARATION, (yyvsp[-1]));
    (yyvsp[-9])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-9])->appendChild((yyvsp[-8]));
    (yyvsp[-9])->appendChild(NTYPE((yyvsp[-7]), n_STRING));
    (yyvsp[-9])->appendChild(NEXPAND((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4])));
    (yyvsp[-9])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-9])->appendChild((yyvsp[-3]));
    (yyvsp[-9])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-9]));
  }
#line 4170 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 706 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_DECLARATION);
    (yyval)->appendChild((yyvsp[-6]));
    (yyval)->appendChild(NTYPE((yyvsp[-5]), n_CLASS_NAME));
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyval), (yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
#line 4186 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 717 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INTERFACE_DECLARATION);
    (yyval)->appendChild(NNEW(n_CLASS_ATTRIBUTES));
    NMORE((yyval), (yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-4]), n_CLASS_NAME));
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyval), (yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
#line 4203 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 732 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[0]);
  }
#line 4212 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 736 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4224 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 743 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4236 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 750 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 4245 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 757 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4253 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 760 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_EXTENDS_LIST)->appendChild((yyvsp[0]));
  }
#line 4261 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 770 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4269 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 773 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_EXTENDS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4279 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 781 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4287 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 784 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_IMPLEMENTS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4297 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 792 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[0]));
  }
#line 4305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 795 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4313 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 801 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4321 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 804 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4329 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 811 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4339 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 820 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4349 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 829 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4359 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 838 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4369 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 846 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4380 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 852 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));
    (yyval) = (yyvsp[-4]);
  }
#line 4393 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 863 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4401 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 866 "parser.y" /* yacc.c:1646  */
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[-2]), n_STATEMENT);
    (yyvsp[-3])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));
    NEXPAND((yyvsp[-3]), (yyval), (yyvsp[0]));
  }
#line 4416 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 876 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[0]));
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval) = (yyvsp[-2]);
  }
#line 4426 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 881 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_STATEMENT);
    (yyvsp[-4])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-3]));
    (yyval)->appendChildren((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
    NMORE((yyval), (yyvsp[-4]));
  }
#line 4440 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 893 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4448 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 896 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CASE);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyvsp[-3]));
    (yyval) = (yyvsp[-4]);
  }
#line 4461 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 904 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_DEFAULT);
    (yyvsp[-2])->appendChild((yyvsp[0]));

    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval) = (yyvsp[-3]);
  }
#line 4473 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 920 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[0]));
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  (yyval) = (yyvsp[-2]);
  }
#line 4483 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 928 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4491 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 931 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_ELSEIF);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyvsp[-4]));
  }
#line 4503 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 941 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4511 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 944 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_ELSEIF);
    (yyvsp[-5])->appendChild((yyvsp[-3]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyvsp[-5]));
  }
#line 4523 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 954 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4531 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 957 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_ELSE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4541 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 965 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4549 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 968 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ELSE);
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4559 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 977 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
#line 4567 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 983 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4580 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 991 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4594 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1000 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4608 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1009 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4621 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1017 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 4634 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1025 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4648 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1035 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyval));
  }
#line 4662 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1045 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 4675 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1056 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_UNPACK);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 4684 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1060 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4692 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1066 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4700 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1070 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_NULLABLE_TYPE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4709 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1077 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4717 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1080 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4725 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4733 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1089 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4741 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1092 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_RETURN);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4750 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1100 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
#line 4758 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1106 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4766 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1109 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4774 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1116 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNPACK)->appendChild((yyvsp[-1]));
  }
#line 4782 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1119 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4791 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1126 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4800 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1130 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4809 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1137 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4817 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1140 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4826 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1144 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-3]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 4835 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1151 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 4848 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1159 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4861 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1167 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4874 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1175 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4887 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1186 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4895 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1189 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4903 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1195 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4916 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1203 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4925 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1207 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4933 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1210 "parser.y" /* yacc.c:1646  */
    {
    /* empty */
  }
#line 4941 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1212 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_DECLARATION);
    NMORE((yyval), (yyvsp[-8]));
    (yyval)->appendChild((yyvsp[-9]));
    (yyval)->appendChild((yyvsp[-6]));
    (yyval)->appendChild(NTYPE((yyvsp[-5]), n_STRING));
    (yyval)->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
#line 4959 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1228 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-2]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4969 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1236 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[0]));
  }
#line 4977 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1239 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4985 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1245 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4993 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1248 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5001 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1254 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
#line 5009 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1257 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5017 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1263 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5026 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1267 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 5035 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1274 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5043 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1277 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5051 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1283 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5061 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1291 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5070 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1295 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 5079 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1302 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5088 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1306 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5096 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1312 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[-2]), (yyvsp[-1]), NTYPE((yyvsp[0]), n_STRING));
    (yyval) = (yyvsp[-1]);
  }
#line 5106 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1320 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5117 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1326 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 5128 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1335 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1338 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5145 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1346 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5153 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1349 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5161 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1356 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5170 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1363 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
#line 5178 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1366 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[0]);
  }
#line 5187 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1373 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5196 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1377 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5204 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1392 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 5216 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1399 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 5228 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1406 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5240 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1413 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5252 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1423 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));

    (yyval) = (yyvsp[-4]);
  }
#line 5266 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1432 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyvsp[-3])->appendChild((yyval));

    (yyval) = (yyvsp[-3]);
  }
#line 5280 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1444 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5288 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1447 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5297 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1454 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1462 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5313 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1465 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5322 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1472 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_LIST);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5335 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1480 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5346 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1486 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));

    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));

    (yyval)->appendChild((yyvsp[-1]));
  }
#line 5361 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1496 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-4]), n_OPERATOR));

    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));

    NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE);
    (yyvsp[-3])->appendChild((yyvsp[-2]));

    (yyval)->appendChild((yyvsp[-3]));
  }
#line 5380 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1510 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5390 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1515 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5401 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1521 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5412 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1527 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5423 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1533 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5434 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1539 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5445 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1545 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5456 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1551 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5467 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1557 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5478 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1563 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5489 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1569 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5500 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1575 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5511 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1581 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5521 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1586 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5531 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1591 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5541 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1596 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5551 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1601 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5562 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1607 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5573 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1613 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5584 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1619 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5595 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1625 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5606 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1631 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5617 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1637 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5628 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1643 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5639 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1649 "parser.y" /* yacc.c:1646  */
    {

    /* The concatenation operator generates n_CONCATENATION_LIST instead of
       n_BINARY_EXPRESSION because we tend to run into stack depth issues in a
       lot of real-world cases otherwise (e.g., in PHP and JSON decoders). */

    if ((yyvsp[-2])->type == n_CONCATENATION_LIST && (yyvsp[0])->type == n_CONCATENATION_LIST) {
      (yyvsp[-2])->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
      (yyvsp[-2])->appendChildren((yyvsp[0]));
      (yyval) = (yyvsp[-2]);
    } else if ((yyvsp[-2])->type == n_CONCATENATION_LIST) {
      (yyvsp[-2])->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
      (yyvsp[-2])->appendChild((yyvsp[0]));
      (yyval) = (yyvsp[-2]);
    } else if ((yyvsp[0])->type == n_CONCATENATION_LIST) {
      (yyval) = NNEW(n_CONCATENATION_LIST);
      (yyval)->appendChild((yyvsp[-2]));
      (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
      (yyval)->appendChildren((yyvsp[0]));
    } else {
      (yyval) = NNEW(n_CONCATENATION_LIST);
      (yyval)->appendChild((yyvsp[-2]));
      (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
      (yyval)->appendChild((yyvsp[0]));
    }
  }
#line 5670 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1675 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5681 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1681 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5692 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1687 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5703 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1693 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5714 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1699 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5725 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1705 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5736 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1711 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5747 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1717 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5757 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1722 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5767 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1727 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5777 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1732 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5787 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1737 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5798 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1743 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5809 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1749 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5820 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1755 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5831 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1761 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5842 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1767 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5853 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1773 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5864 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1779 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5875 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1785 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5886 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1791 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5897 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1799 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5910 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1807 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5923 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1815 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5934 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1822 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5944 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1827 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5954 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1832 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5964 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1837 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5974 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1842 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5984 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 1847 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5994 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1852 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6004 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1857 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6014 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1862 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6024 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1867 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[0]);
  }
#line 6033 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1874 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6043 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1879 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[0]);
  }
#line 6054 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1888 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-9]), n_FUNCTION_DECLARATION, (yyvsp[-1]));
    (yyvsp[-9])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-9])->appendChild((yyvsp[-8]));
    (yyvsp[-9])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-9])->appendChild(NEXPAND((yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5])));
    (yyvsp[-9])->appendChild((yyvsp[-4]));
    (yyvsp[-9])->appendChild((yyvsp[-3]));
    (yyvsp[-9])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));

    (yyval) = (yyvsp[-9]);
  }
#line 6071 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1903 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-9]), n_FUNCTION_DECLARATION, (yyvsp[-1]));
    NMORE((yyvsp[-9]), (yyvsp[-10]));

    (yyval) = NNEW(n_FUNCTION_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[-10]), n_STRING));
    (yyvsp[-9])->appendChild((yyvsp[-10]));

    (yyvsp[-9])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-9])->appendChild((yyvsp[-8]));
    (yyvsp[-9])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-9])->appendChild(NEXPAND((yyvsp[-7]), (yyvsp[-6]), (yyvsp[-5])));
    (yyvsp[-9])->appendChild((yyvsp[-4]));
    (yyvsp[-9])->appendChild((yyvsp[-3]));
    (yyvsp[-9])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));

    (yyval) = (yyvsp[-9]);
  }
#line 6094 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1924 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6105 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1930 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6116 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1936 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6127 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1942 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6138 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1955 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6146 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1958 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[-3])->appendChildren((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6156 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1966 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6164 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1969 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 6174 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1974 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6183 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1978 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 6194 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1987 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6204 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1993 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-5]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6215 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1999 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-4]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6226 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 2006 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6239 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 2015 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6252 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 2024 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6265 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 2033 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6278 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2041 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6288 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 2049 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6296 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 2052 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6304 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 2055 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6313 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 2059 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6322 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 2066 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6330 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2069 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6339 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2073 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6348 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 2088 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    for (xhpast::node_list_t::iterator ii = (yyvsp[0])->children.begin();
      ii != (yyvsp[0])->children.end();
      ++ii) {

      (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS)->appendChild((yyval));
      (yyval)->appendChild(*ii);
    }
  }
#line 6365 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2104 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 6373 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2107 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6381 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2113 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6389 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2119 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6397 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2122 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-1]), n_EMPTY, (yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6406 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2126 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 6416 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2134 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6424 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2137 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6432 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2143 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6440 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2146 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6448 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2149 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_STRING_SCALAR);
  }
#line 6456 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2152 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6464 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2155 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6472 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2158 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6480 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2161 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6488 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2164 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6496 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2167 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6504 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2170 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6512 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2173 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6520 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2176 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_HEREDOC);
  }
#line 6528 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2184 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = (yyvsp[0]);
  }
#line 6537 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 2188 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = (yyvsp[0]);
  }
#line 6546 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 2192 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6556 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 2197 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6566 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2202 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 6576 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2207 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 6586 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2216 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 6596 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2227 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-2]));
  }
#line 6604 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2230 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-1]));
  }
#line 6612 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2237 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6620 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2240 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6628 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 2246 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6636 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 2257 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6648 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 2264 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6660 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2271 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6672 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2278 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6684 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2308 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild((yyvsp[-2]));

    if ((yyvsp[-1])->type != n_EMPTY) {
      (yyval) = NNEW(n_METHOD_CALL)->appendChild((yyval));
      (yyval)->appendChild((yyvsp[-1]));
    }

    for (xhpast::node_list_t::iterator ii = (yyvsp[0])->children.begin();
      ii != (yyvsp[0])->children.end();
      ++ii) {

      if ((*ii)->type == n_CALL_PARAMETER_LIST) {
        (yyval) = NNEW(n_METHOD_CALL)->appendChild((yyval));
        (yyval)->appendChild((*ii));
      } else {
        (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS)->appendChild((yyval));
        (yyval)->appendChild((*ii));
      }
    }
  }
#line 6712 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2335 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChildren((yyvsp[0]));
  }
#line 6720 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2338 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6728 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2344 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[-1]));
    if ((yyvsp[0])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[0]));
    }
  }
#line 6740 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2354 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6751 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2360 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6762 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2369 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6770 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2377 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6778 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2384 "parser.y" /* yacc.c:1646  */
    {
    xhpast::Node *last = (yyvsp[-1]);
    NMORE((yyvsp[-1]), (yyvsp[0]));
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      NMORE(last, (yyvsp[0]));
      last = last->firstChild();
    }
    last->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-1]);
  }
#line 6795 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2399 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6805 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2404 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6815 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2416 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6826 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2422 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6837 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2438 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6845 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2441 "parser.y" /* yacc.c:1646  */
    {
    xhpast::Node *last = (yyvsp[-1]);
    NMORE((yyvsp[-1]), (yyvsp[0]));
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      NMORE(last, (yyvsp[0]));
      last = last->firstChild();
    }
    last->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-1]);
  }
#line 6862 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2457 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6873 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2463 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6884 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2473 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 6892 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2476 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-3]), n_VARIABLE_EXPRESSION, (yyvsp[0]));
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6902 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2484 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6910 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2487 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6918 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2498 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6929 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2504 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6940 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2514 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_STRING);
    (yyval) = (yyvsp[0]);
  }
#line 6949 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2518 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6957 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2524 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);
  }
#line 6965 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2527 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[0]) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);

    xhpast::Node *last = (yyvsp[-1]);
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      last = last->firstChild();
    }
    last->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-1]);
  }
#line 6982 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2542 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 6990 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2545 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6999 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2553 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 7008 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2557 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 7016 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2563 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 7024 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2566 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 7032 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2572 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 7044 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2579 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 7056 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2586 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7068 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2593 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7080 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2600 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 7092 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2607 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 7104 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2614 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7116 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2621 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7128 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2631 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7143 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2641 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7158 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2651 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7166 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2654 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7174 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2657 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7189 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2667 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7197 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2670 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7205 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2676 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7214 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2680 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7222 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2686 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 7232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2691 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 7240 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2697 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7251 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2703 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7262 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2709 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7273 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2715 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7284 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2721 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7295 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2730 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 7305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 2735 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 7315 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2743 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 7326 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 2752 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7336 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 2757 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7346 "parser.yacc.cpp" /* yacc.c:1646  */
    break;


#line 7350 "parser.yacc.cpp" /* yacc.c:1646  */
      default: break;
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
      yyerror (yyscanner, root, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
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
        yyerror (yyscanner, root, yymsgp);
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
                      yytoken, &yylval, yyscanner, root);
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
                  yystos[yystate], yyvsp, yyscanner, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (yyscanner, root, YY_("memory exhausted"));
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
                  yytoken, &yylval, yyscanner, root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yyscanner, root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2764 "parser.y" /* yacc.c:1906  */


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
/* @generated */
