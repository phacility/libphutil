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
#define YYLAST   7627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  443
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  915

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
    2743,  2749,  2767,  2772
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

#define YYPACT_NINF -706

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-706)))

#define YYTABLE_NINF -382

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-382)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -706,    63,  1871,  -706,  6174,  6174,   -80,  6174,  6174,  6174,
    6174,  6174,  6174,  6174,   215,   215,  6174,  6174,  6174,  6174,
    6174,  6174,  6174,  6174,  4844,   274,  6174,   -62,   -57,  -706,
    -706,    44,  -706,  -706,  -706,    53,  -706,  6174,  4569,   -47,
     -16,   -13,    58,    67,  4977,  5110,    92,  -706,   125,  5243,
      76,  6174,    13,    -4,   128,   126,   130,    99,   102,   112,
     117,  -706,  -706,   122,   132,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,    -9,  -706,  -706,   211,  -706,  -706,
    6174,  6307,  -706,  -706,   136,   -71,  -706,    16,  -706,  -706,
    -706,  -706,  -706,  -706,   214,   235,  -706,   149,   286,   262,
     189,  -706,  -706,  6679,  -706,   294,  1229,   170,  -706,   194,
     279,   227,  -706,     0,  -706,    36,  -706,  -706,   299,   304,
    -706,   309,   319,   284,   224,  -706,   286,  7427,  7427,  6174,
    7427,  7427,  1579,  -706,  -706,   339,  -706,  -706,  -706,   244,
     211,   333,   -78,   261,  -706,  -706,   263,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,   215,  7225,   245,   403,
     252,   265,   211,   266,   270,   252,  -706,   273,   295,     9,
      36,  -706,  5376,  -706,  6174,  -706,  6174,  6174,    19,  7427,
     336,  6174,  6174,  6174,   350,  6174,  -706,  6730,  -706,  6773,
     271,   415,  -706,   276,  7427,   957,  -706,  6816,   211,   -38,
      20,  -706,  -706,   283,    22,  -706,   416,    23,   286,  -706,
    -706,   215,   215,   215,   275,   303,  4844,   211,  -706,   -67,
     123,   -68,  7275,   540,   280,   991,   281,  2013,  6174,   366,
    4711,   371,  -706,   324,   326,  -706,  -706,    -8,  6174,   -17,
    6174,  6174,  6174,  5509,  6174,  6174,  6174,  6174,  6174,  6174,
    6174,  6174,  6174,  6174,  6174,  6174,  6174,  6174,  6174,  6174,
    6174,  6174,  6174,  6174,  6174,  6174,  6174,   422,  -706,  -706,
    -706,  5642,  6174,  6174,  6174,  6174,  6174,  6174,  6174,  6174,
    6174,  6174,  6174,  4711,    35,  6174,    49,  6174,  6174,   136,
      65,  6174,  6174,  6174,   290,  6867,   211,   -55,   281,    54,
     158,  -706,  -706,  5775,  -706,  5908,  -706,  4711,   324,   211,
     266,    51,  -706,    51,    49,   -14,  -706,  6910,  6953,  7427,
     285,   287,  6174,  -706,   296,  7003,   292,   453,  7427,   368,
    1033,   452,    28,  7046,  -706,  -706,  -706,  1196,  -706,  -706,
    2155,  -706,    85,   391,    13,  -706,  6174,  -706,  -706,    -4,
    -706,  1196,   405,  -706,   307,    30,  -706,  -706,  -706,    33,
     318,   323,   330,  -706,    34,  -706,   325,   124,  1587,  -706,
    -706,  4711,  6174,  -706,  -706,  -706,   332,  -706,  -706,  -706,
    -706,  -706,  1341,  -706,   215,  6174,   343,   487,  -706,  7427,
     494,   101,   384,   101,   348,   354,    10,   349,   356,   357,
     -14,    36,  7469,  7508,  1579,  6174,  7378,  7533,  1479,  7555,
    7576,  4764,  1721,  1863,  1863,  1863,  1863,  1863,  1070,  1070,
    1070,  1070,   763,   763,   353,   353,   353,   339,   339,   339,
    -706,   164,  1579,  1579,  1579,  1579,  1579,  1579,  1579,  1579,
    1579,  1579,  1579,  1579,   360,   364,   369,   362,  -706,  6174,
    -706,   374,   -10,  -706,   365,  6452,   376,   378,   381,  -706,
      71,   356,   364,   215,  7427,   215,  7326,   379,   384,   266,
    -706,  -706,  -706,  -706,  3859,  -706,  -706,  7427,  6174,  4001,
    6174,  6174,   215,   184,  1196,   446,  4143,     6,  1196,  1196,
    1196,  -706,   377,   396,   211,   -28,   418,  -706,  -706,  -706,
     -39,   475,  -706,  -706,  6495,  -706,  -706,   539,    10,   215,
     404,   215,  -706,  -706,  -706,   303,   303,   553,  -706,  4711,
    -706,  1729,   406,   193,   714,   408,  -706,  -706,  7427,  -706,
    4711,  1196,   433,   211,   266,  -706,   101,   423,   581,  -706,
    -706,    10,   204,  -706,  -706,   437,   587,    24,  -706,  -706,
    -706,  4711,  4711,   -14,  7533,  6174,   422,  -706,  -706,  4711,
    4711,  -706,  6538,  4711,   537,   538,  -706,  6174,  6174,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  6041,  -706,   440,   480,
    -706,  -706,  7089,  -706,  -706,  -706,   444,  7427,   481,   215,
     481,  -706,  -706,   596,  -706,  -706,  -706,   447,   449,  -706,
    -706,  -706,   486,   451,   606,  1196,   211,   -15,   541,   460,
     458,   -39,  -706,  -706,  -706,  -706,  1196,   464,  -706,  -706,
    -706,    41,  -706,  6174,   466,  -706,  -706,   468,  -706,  -706,
     211,   266,   581,  -706,   101,   465,   471,  -706,   518,    68,
     -33,  -706,   558,   624,   476,   478,  7533,   252,   479,   482,
    -706,   484,  6174,  6174,   517,   488,  6591,   215,  7427,  -706,
      49,  -706,  3717,   302,   490,  2297,  6174,   184,   485,  -706,
     489,  1196,  2439,  -706,   183,  -706,   138,  1196,  -706,  1196,
    -706,   495,   100,  -706,   101,  -706,  -706,  -706,  -706,  -706,
     518,  -706,  1579,  -706,  -706,   266,   729,  -706,   574,   101,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     579,   284,   639,  -706,    25,   632,   498,   632,    39,   648,
    -706,  1196,  -706,  -706,  -706,  -706,  -706,  -706,   500,   501,
      49,  -706,  -706,  -706,  -706,   878,  -706,   312,   504,  4569,
    -706,  -706,   506,   509,  -706,  4285,  4285,  -706,   510,   264,
     512,  6174,    11,   151,  -706,  -706,   549,  -706,   600,  2581,
     632,  -706,   665,    14,  -706,   667,    26,  -706,  -706,   607,
    -706,    68,   519,    75,   521,   -33,   668,  1196,  -706,  -706,
    -706,   374,  -706,   525,   661,   619,  6174,  -706,  -706,  4427,
    -706,  -706,  -706,  -706,  -706,   529,  -706,  6636,  -706,  -706,
    -706,  -706,  1196,   531,  -706,   532,  1196,   101,  -706,   116,
    -706,  1196,   622,  -706,   286,   682,  -706,  -706,   623,  -706,
      42,  -706,   688,  1196,  -706,  -706,  6174,  -706,   542,  7139,
    -706,  -706,  -706,  2723,  -706,  -706,  3717,  -706,   543,  -706,
    -706,  -706,   609,   545,   116,  -706,   548,   611,   554,   551,
     565,  -706,   704,   644,  1196,  2865,  -706,   190,  -706,  3007,
    1196,  -706,  7182,  3717,  -706,  4569,  3149,   557,  3717,  -706,
    3291,  -706,  -706,  -706,   359,   101,  -706,   646,  1196,   561,
    -706,  -706,   662,  -706,  -706,  -706,   697,  -706,   562,  -706,
    3433,  -706,   669,   670,   732,  -706,  -706,  -706,    10,  -706,
    -706,  -706,  -706,  -706,   101,   584,  3717,  -706,   632,   229,
    -706,  -706,  -706,  3575,  -706
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
     323,     0,     0,   307,   313,   323,   314,     0,   316,   387,
       0,   218,     0,   277,     0,    31,   396,   396,     0,   209,
       0,     0,   210,     0,     0,     0,    42,     0,    44,     0,
       0,     0,    46,   362,     0,   363,    25,     0,     0,    18,
       0,    17,   153,     0,     0,   152,   158,     0,    75,    81,
      82,     0,     0,     0,     0,   411,   412,     0,     4,     0,
     351,   362,     0,   363,     0,     0,   265,     0,     0,     0,
     145,     0,    15,    84,    87,    54,    76,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,   230,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,   396,     0,   396,     0,   406,
     389,   396,   396,   396,     0,     0,     0,   309,     0,     0,
       0,   421,   364,     0,   439,   356,   413,   145,    84,     0,
     309,     0,   440,     0,     0,   389,   321,     0,     0,   397,
       0,     0,     0,    51,     0,     0,     0,   211,   213,   362,
     363,     0,     0,     0,    43,    45,    63,     0,    47,    48,
       0,    62,    20,     0,     0,    14,     0,   154,   363,     0,
      49,     0,     0,    50,     0,     0,    70,    72,   429,     0,
       0,     0,     0,   409,     0,   408,     0,   350,     0,    11,
       4,   145,     0,   432,   431,   388,     0,    35,    24,    26,
      27,    28,     0,     6,     0,     0,     0,   144,   146,   148,
       0,     0,    89,     0,     0,     0,   136,     0,   442,   379,
     377,     0,   236,   238,   237,     0,     0,   268,   234,   235,
     239,   241,   240,   256,   257,   254,   255,   262,   258,   259,
     260,   261,   248,   249,   243,   244,   242,   245,   246,   247,
     263,     0,   215,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,   443,   380,     0,   403,     0,
     399,   376,   398,   402,     0,     0,     0,     0,     0,   426,
     308,     0,     0,     0,   416,     0,   415,     0,    89,   308,
     379,   380,   318,   322,     0,   437,   435,   208,     0,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     353,   327,     0,     0,     0,   338,     0,   337,    23,   345,
       0,     0,    19,    16,     0,   151,   159,   156,   136,     0,
       0,     0,   422,   423,    10,   411,   411,     0,   438,   145,
      13,     0,     0,   362,   363,     0,   395,   150,   149,   298,
       0,     0,     0,     0,   310,    85,     0,     0,    88,    91,
     161,   136,     0,   140,   141,     0,   124,     0,   137,   139,
     383,   145,   145,   378,   267,     0,     0,   216,   305,   145,
     145,   382,     0,   145,   375,   374,   369,   396,     0,   391,
     392,   434,   433,   436,   420,   419,     0,   324,     0,   315,
      25,   116,     0,    25,   114,    38,     0,   212,    93,     0,
      93,    95,   103,     0,    25,   101,    58,   109,   109,    41,
     341,   342,   360,     0,   355,   353,     0,   340,     0,     0,
       0,    67,    65,    61,    21,   155,     0,     0,    71,    55,
     430,     0,   407,     0,     0,    12,   300,     0,   147,    22,
       0,   312,    90,   161,     0,   192,     0,   138,   292,   136,
       0,   135,     0,   126,     0,     0,   266,   323,     0,     0,
     404,     0,   396,   396,   366,     0,     0,     0,   414,   161,
       0,   317,   118,   120,     0,     0,   210,     0,     0,    96,
       0,     0,     0,   109,     0,   109,     0,     0,   344,   356,
     354,     0,   339,   346,     0,    25,    64,    60,    68,   157,
     292,   410,   214,   299,    29,   311,   192,    92,     0,     0,
     199,   200,   201,   198,   197,   196,   191,    79,   160,   164,
       0,     0,   190,   194,     0,   142,     0,   142,     0,   127,
     134,     0,   301,   304,   217,   302,   303,   373,     0,     0,
       0,   368,   400,   401,   418,   192,   319,   122,     0,     0,
      36,    39,     0,     0,    94,     0,     0,   104,     0,     0,
       0,     0,     0,     0,   105,   359,   358,   343,     0,     0,
     142,    78,     0,     0,   168,   204,     0,   165,   195,     0,
     163,   136,     0,     0,     0,     0,   130,     0,   129,   371,
     372,   376,   441,     0,     0,     0,     0,   121,   115,     0,
      25,    99,    57,    56,   102,     0,   107,     0,   112,   113,
      25,   106,     0,     0,    69,     0,     0,     0,   170,   172,
     167,     0,     0,   162,    75,     0,   143,    25,     0,   296,
       0,    25,   131,     0,   128,   370,     0,    25,     0,     0,
      25,    97,    40,     0,   108,    25,   111,   357,     0,    25,
     207,   169,     5,     0,   173,   174,     0,     0,   182,     0,
       0,   205,   202,     0,     0,     0,   297,     0,   293,     0,
       0,   133,     0,   123,    37,     0,     0,     0,   110,    25,
       0,   171,   175,   176,   186,     0,   177,     0,     0,     0,
     206,    77,     0,   294,   285,   132,     0,   117,     0,   100,
       0,   286,     0,   185,   178,   179,   183,   203,   136,   295,
      25,    98,    66,   184,     0,     0,   119,   180,   142,     0,
     188,    25,   166,     0,   189
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -706,  -706,  -195,    -5,  -706,  -706,   399,  -706,  -185,  -706,
       2,  -706,  -706,   145,  -706,   147,  -706,   240,    -1,     3,
    -124,  -706,  -706,  -706,   454,  -706,  -706,   293,   228,   173,
      93,  -706,    32,  -706,  -706,  -706,  -417,   -27,  -706,  -706,
    -706,  -706,  -706,  -493,  -706,  -581,  -600,   231,  -699,  -254,
    -706,   239,  -706,   425,  -706,  -554,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   -73,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -705,  -706,  -706,  -706,  -455,  -706,
     -37,   695,    -2,    87,  -706,  -706,   108,  -377,  -248,  -706,
    -706,  -706,  -706,  -157,   727,   618,  -706,  -706,   175,   177,
    -706,   916,   580,  -363,   392,    31,  -706,  -706,  -706,  -706,
       1,  -222,  -706,   802,  -706,  -706,   -22,   -12,  -706,  -151,
    -308,  -706,  -706,    29,   269,   272,   570,  -706,  -706,  -706,
    -706,  -706,  -706,    27,  -706
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   200,   201,    87,   227,   378,
     379,    89,   611,   612,   687,   613,   355,   356,   380,   381,
     237,    92,    93,    94,   392,    95,   394,   537,   538,   668,
     590,   832,   792,   596,   332,   599,   674,   800,   585,   663,
     737,   740,   785,   545,   546,   643,   547,   548,   772,   386,
     387,   388,   204,   205,   207,   635,   708,   814,   709,   763,
     810,   843,   844,   845,   846,   894,   847,   848,   849,   892,
     912,   710,   711,   712,   713,   766,   714,   178,   326,   327,
      96,    97,   126,   717,   820,    99,   100,   549,   165,   166,
     579,   661,   173,   308,   101,   602,   499,   102,   603,   306,
     604,   103,   104,   301,   105,   106,   654,   731,   564,   565,
     566,   107,   108,   109,   110,   111,   112,   113,   114,   320,
     451,   452,   453,   115,   364,   365,   158,   159,   116,   359,
     117,   118,   119,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    90,   294,   168,    88,    91,   472,   768,   312,   142,
     142,   340,   193,   169,   535,   617,   539,   399,   774,   430,
     163,   527,   807,   368,   231,   586,   321,   322,   344,   444,
     349,   352,   597,   769,   812,   542,   485,   798,   509,   718,
     180,   511,   516,   221,   641,   145,   145,   199,   636,   516,
     857,   287,   208,   467,   170,   567,   640,   343,   398,   719,
      33,   805,   446,     3,   450,   287,   137,   395,   609,   219,
     175,   775,   220,   202,   287,   229,  -307,   399,   446,   696,
     195,   129,   229,   230,   354,   137,   229,   397,   137,   470,
     230,   471,   450,   542,  -287,  -287,   369,   370,   229,   172,
     574,   641,   575,   290,   174,   735,   371,   818,   226,   176,
     445,   223,    33,    33,   181,   229,   641,   522,   177,  -307,
     610,   208,   143,   143,   448,   229,    33,   642,    33,   461,
     287,    33,  -309,   164,   447,   297,   454,   776,   229,   543,
     456,   457,   458,   137,   217,   182,   329,  -381,   183,    84,
     288,   142,   819,   396,   568,   218,  -381,   310,   315,   539,
     532,  -377,   203,   533,   288,   544,   198,   190,   298,   893,
     598,   816,  -125,   288,   799,   521,   137,   808,   809,   232,
     501,   676,   323,   345,   642,   350,   353,   302,   770,   813,
     486,   842,   510,   342,   822,   512,   517,   543,   142,   642,
     191,    84,   289,   691,   858,   206,   142,   142,   142,   909,
     142,   743,   367,   449,   330,    84,   589,    84,   532,   184,
      84,   533,   882,   544,   229,    98,  -378,   400,   185,   288,
     556,    47,   519,   462,   348,    33,   751,   752,   229,   137,
     196,    33,   357,   358,   360,   168,   363,  -308,   209,   751,
     752,   532,   210,   229,   533,   169,   749,   697,   753,   137,
     211,    33,   163,   212,   143,   624,   532,   883,   401,   533,
    -309,  -308,   400,   213,   400,   138,   229,   229,   214,   137,
     750,   751,   752,   215,   371,   519,   137,   400,   400,   233,
     137,   460,    33,   216,   734,   138,   170,   644,   645,   400,
     228,   400,   400,   754,   469,   648,   649,   758,   647,   651,
     234,   143,   235,   401,   139,   401,   801,   140,   236,   143,
     143,   143,   764,   143,    84,   141,   138,   238,   401,   401,
      84,   283,   495,   543,   139,   523,   239,   140,    98,   199,
     401,   284,   401,   401,   285,   141,   495,   269,   270,   137,
      84,    33,   736,   286,   532,  -289,  -289,   533,   137,   544,
      33,   795,   751,   752,   291,   139,    98,    90,   140,   292,
      88,    91,   738,   739,   293,   164,   141,   217,   137,   142,
      33,    84,   783,   784,   176,   138,   534,    47,   534,   553,
     267,   534,   910,   911,   138,   662,   160,   296,   665,    25,
     264,   265,   266,   524,   267,   905,   144,   147,   299,   672,
     300,   305,   304,   307,   138,   302,   655,   311,   309,   229,
     313,   314,   781,   324,   161,   331,   142,   162,   337,   351,
     841,   362,   850,   139,   336,   141,   140,   361,   450,   338,
      84,   383,   373,   375,   141,   496,   390,   346,   391,    84,
     393,   396,   475,   139,   476,   480,   140,   478,   142,   496,
     142,   481,   557,   482,   141,   484,   502,   850,   508,    84,
     700,   701,   702,   703,   704,   705,   581,   142,   142,   495,
     513,   584,   507,   495,   495,   495,   514,   518,   595,   607,
     724,   515,   143,   525,   302,   530,   302,   137,   895,    33,
     759,   728,   729,   534,   142,   529,   142,   531,   450,   536,
     142,   142,   540,   588,   591,   541,   550,   551,   552,    98,
      90,   593,   558,    88,    91,   559,   495,   907,   631,   561,
     560,   534,   569,   138,   168,   563,   534,   534,   605,   143,
     357,   577,   620,   571,   169,   572,   363,   363,   573,   606,
     614,   163,   616,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   608,   623,   619,   626,   698,
     627,   143,   161,   143,   699,   162,   700,   701,   702,   703,
     704,   705,   706,   141,   142,   170,   630,   633,    84,   634,
     143,   143,   496,  -365,  -365,   639,   496,   496,   496,   638,
     495,   682,   652,   653,   659,   833,   660,   666,   667,   671,
     673,   495,   675,   677,   679,   836,   683,   143,   678,   143,
     669,   684,   685,   143,   143,   695,   690,   716,   693,   534,
     707,   694,   855,   715,   534,   720,   859,   721,   722,   496,
     723,   725,   863,   730,   726,   866,   727,   745,   400,   762,
     868,   746,   142,   741,   870,   732,   765,   757,   771,   773,
      98,   777,   142,    98,   164,   786,   495,   779,   780,   788,
      98,   789,   495,   794,   495,   796,   802,   803,   806,   534,
     811,   823,   815,   817,   890,   821,   826,   827,   302,   401,
     853,   828,   834,   838,   534,   854,   839,   143,   591,   852,
     856,   860,  -288,  -288,  -181,   864,   874,   869,   875,   767,
     871,   873,   877,   496,   876,   906,   495,   878,   400,   879,
     889,   896,   898,   900,   496,   901,   913,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   899,
     904,   787,  -193,   503,   903,  -187,   908,   791,   791,   618,
     700,   701,   702,   703,   704,   705,   686,    98,   688,   401,
     744,   578,   468,   670,   632,   143,   534,  -365,  -365,   628,
     835,   872,   495,   637,   505,   143,   224,   760,   793,   496,
     681,   680,   825,   347,   621,   496,   366,   496,   622,     0,
       0,   831,     0,     0,     0,     0,     0,   495,     0,     0,
       0,   495,   534,     0,   534,     0,   495,   261,   262,   263,
     264,   265,   266,     0,   267,     0,   146,   146,   495,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,   496,
       0,    98,     0,   698,    98,     0,     0,     0,   699,   534,
     700,   701,   702,   703,   704,   705,   706,     0,     0,   495,
       0,     0,     0,    98,     0,   495,     0,    98,     0,     0,
       0,    98,     0,     0,    98,     0,    98,   887,    98,     0,
     534,     0,     0,   495,     0,     0,  -290,  -290,     0,     0,
       0,     0,     0,     0,     0,   496,     0,     0,    98,     0,
       0,     0,     0,   534,   761,     0,     0,     0,     0,   534,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
     496,    98,     0,     0,   496,     0,     0,     0,     0,   496,
     127,   128,     0,   130,   131,   132,   133,   134,   135,   136,
       0,   496,   148,   149,   150,   151,   152,   153,   154,   155,
     157,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,   498,     0,     0,   146,     0,
     187,   189,   496,     0,     0,   194,     0,   197,   496,   506,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   698,     0,     0,     0,   496,   699,     0,   700,
     701,   702,   703,   704,   705,   706,   222,   225,     0,     0,
     240,   241,   242,     0,     0,   146,     0,     0,     0,     0,
    -365,  -365,     0,   146,   146,   146,   243,   146,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   782,     0,   295,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,     0,     0,
       0,     0,     0,     0,   497,     0,     0,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
       0,     0,     0,     0,     0,     0,  -365,  -365,   317,     0,
     318,     0,   319,   319,     0,     0,     0,   325,   328,   194,
       0,   333,   592,     0,     0,     0,   600,   601,  -382,  -382,
    -382,  -382,   259,   260,   261,   262,   263,   264,   265,   266,
     339,   267,     0,     0,     0,     0,     0,     0,   483,     0,
       0,     0,   157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,     0,   389,     0,     0,   629,
       0,     0,     0,   374,   319,     0,   402,   403,   404,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,   146,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   389,
       0,   319,     0,   319,   455,     0,     0,   319,   319,   319,
       0,   497,     0,     0,     0,   497,   497,   497,     0,   464,
       0,   466,     0,   389,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   689,     0,     0,     0,   477,     0,
     488,   489,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,     0,     0,     0,     0,   497,     0,
       0,   490,   504,     0,     0,   146,     0,   146,     0,    29,
      30,   137,     0,     0,     0,     0,     0,     0,     0,   491,
       0,     0,  -365,  -365,   146,   146,     0,   389,   194,   747,
       0,     0,     0,     0,     0,   755,     0,   756,     0,     0,
       0,   528,     0,     0,     0,     0,     0,   138,     0,     0,
       0,   146,     0,   146,     0,     0,     0,   146,   146,     0,
       0,   554,     0,     0,     0,   492,    65,    66,    67,    68,
      69,     0,   497,     0,     0,     0,     0,     0,     0,   778,
      73,     0,     0,   497,     0,     0,   493,    75,    76,   494,
     240,   241,   242,    79,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,   562,   243,     0,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   146,   267,     0,   582,   824,   328,   587,   497,     0,
       0,     0,     0,     0,   497,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     837,     0,     0,     0,   840,     0,     0,     0,     0,   851,
       0,     0,     0,     0,     0,   389,     0,     0,     0,     0,
       0,   861,     0,     0,     0,     0,   389,     0,   497,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,     0,     0,     0,     0,     0,     0,   389,   389,   146,
       0,   646,   880,     0,     0,   389,   389,     0,   885,   389,
       0,     0,     0,   319,   656,     0,     0,     0,     0,     0,
       0,     0,   658,     0,     0,     0,   897,     0,     0,     0,
       0,     0,     0,     0,   497,     0,   526,     0,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   497,
     267,     0,     0,   497,     0,     0,     0,     0,   497,   692,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   319,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   497,   328,     0,     0,     0,     0,   497,     0,     0,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,     0,     0,   243,   497,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,     0,
     267,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,   797,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,     0,   829,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,    74,    75,    76,
      77,     9,   862,    78,    79,    80,     0,     0,    81,     0,
      82,    83,   520,    84,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,     0,   267,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,    74,
      75,    76,    77,     9,     0,    78,    79,    80,     0,     0,
      81,     0,    82,    83,   625,    84,  -382,  -382,  -382,  -382,
    -382,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,     0,   267,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,    74,    75,    76,    77,     9,     0,    78,    79,    80,
       0,     0,    81,     0,    82,    83,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   376,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   377,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,     0,     0,    35,    36,
      37,    38,    39,     0,    40,     0,    41,     0,    42,     0,
       0,    43,     0,     0,     0,    44,    45,    46,    47,     0,
      49,    50,     0,    51,     0,    53,    54,    55,    56,     0,
       0,     0,     0,    57,    58,    59,   376,    61,    62,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     0,    70,    71,     0,    72,     0,     0,     0,    73,
       4,     5,     6,     7,     8,   124,    75,    76,    77,     9,
       0,    78,    79,    80,     0,     0,    81,     0,    82,    83,
     500,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,   742,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   376,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,     0,    81,     0,
      82,    83,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,   748,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
      54,    55,    56,     0,     0,     0,     0,    57,    58,    59,
     376,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   124,
      75,    76,    77,     9,     0,    78,    79,    80,     0,     0,
      81,     0,    82,    83,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   376,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,     0,    81,     0,    82,    83,   804,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,   867,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   376,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,     0,     0,    35,    36,
      37,    38,    39,     0,    40,     0,    41,     0,    42,     0,
       0,    43,     0,     0,     0,    44,    45,    46,    47,     0,
      49,    50,     0,    51,     0,    53,    54,    55,    56,     0,
       0,     0,     0,    57,    58,    59,   376,    61,    62,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     0,    70,    71,     0,    72,     0,     0,     0,    73,
       4,     5,     6,     7,     8,   124,    75,    76,    77,     9,
       0,    78,    79,    80,     0,     0,    81,     0,    82,    83,
     881,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   376,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,     0,    81,     0,
      82,    83,   884,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,   888,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
      54,    55,    56,     0,     0,     0,     0,    57,    58,    59,
     376,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   124,
      75,    76,    77,     9,     0,    78,    79,    80,     0,     0,
      81,     0,    82,    83,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   376,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,     0,    81,     0,    82,    83,   891,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   376,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   902,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,     0,     0,    35,    36,
      37,    38,    39,     0,    40,     0,    41,     0,    42,     0,
       0,    43,     0,     0,     0,    44,    45,    46,    47,     0,
      49,    50,     0,    51,     0,    53,    54,    55,    56,     0,
       0,     0,     0,    57,    58,    59,   376,    61,    62,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     0,    70,    71,     0,    72,     0,     0,     0,    73,
       4,     5,     6,     7,     8,   124,    75,    76,    77,     9,
       0,    78,    79,    80,     0,     0,    81,     0,    82,    83,
     914,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   376,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,     0,    81,     0,
      82,    83,     0,    84,     0,   580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
      54,     0,     0,     0,     0,     0,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   124,
      75,    76,    77,     9,     0,     0,    79,    80,     0,     0,
      81,     0,    82,    83,     0,    84,     0,   583,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,     0,     0,     0,     0,     0,     0,    57,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,     0,    79,    80,
       0,     0,    81,     0,    82,    83,     0,    84,     0,   594,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,     0,     0,     0,     0,     0,
       0,    57,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,     0,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,   790,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,     0,     0,    35,    36,
      37,    38,    39,     0,    40,     0,    41,     0,    42,     0,
       0,    43,     0,     0,     0,    44,    45,    46,    47,     0,
      49,    50,     0,    51,     0,    53,    54,     0,     0,     0,
       0,     0,     0,    57,    58,    59,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     0,    70,    71,     0,    72,     0,     0,     0,    73,
       4,     5,     6,     7,     8,   124,    75,    76,    77,     9,
       0,     0,    79,    80,     0,     0,    81,     0,    82,    83,
       0,    84,     0,   830,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,     0,
       0,     0,     0,     0,     0,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,     0,    79,    80,     0,     0,    81,     0,
      82,    83,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
      54,     0,     0,     0,     0,     0,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   124,
      75,    76,    77,     9,     0,     0,    79,    80,     0,     0,
      81,     0,    82,    83,     0,    84,     0,     0,     0,     0,
       0,     0,     0,   384,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,    29,    30,   122,    32,    33,     0,
       0,     0,     0,     0,    35,    36,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,    47,   267,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    73,     9,     0,     0,     0,
       0,   124,    75,    76,    77,     0,     0,     0,    79,   125,
       0,   385,    81,     0,     0,     0,   156,    84,     0,     0,
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
       0,    79,   125,     0,     0,    81,     0,     0,     0,     0,
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
     186,     0,     0,    84,     0,     0,     0,     0,     0,     0,
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
       0,    81,     0,   188,     0,     0,    84,     0,     0,     0,
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
      79,   125,     0,     0,    81,     0,   192,     0,     0,    84,
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
       0,     0,     0,    79,   125,   405,     0,    81,   316,     0,
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
      81,     0,     0,     0,   431,    84,     0,     0,     0,     0,
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
     125,     0,     0,    81,     0,     0,     0,   463,    84,     0,
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
     465,    84,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   657,    84,     0,     0,     0,     0,     0,
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
       0,     0,    81,     0,     0,     0,     0,    84,     0,     0,
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
       0,    79,   125,     0,     0,    81,     0,     0,     0,     0,
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
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,     0,     0,     0,   124,    75,    76,
      77,   240,   241,   242,    79,    80,     0,     0,    81,     0,
       0,     0,     0,    84,     0,     0,     0,   243,     0,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,     0,   267,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,   570,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,     0,   267,     0,     0,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     615,   243,   798,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   650,   243,     0,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243,   733,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
       0,   267,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,   799,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,     0,   267,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,   268,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,   334,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,     0,   267,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243,   335,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
       0,   267,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,   341,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,     0,   267,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,   459,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,     0,   267,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,   473,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,   474,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,     0,
     267,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,   479,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,     0,
     267,   240,   241,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,   487,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,   664,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,   865,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,     0,     0,
       0,     0,     0,     0,   886,     0,     0,     0,     0,     0,
       0,   243,   303,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   372,   243,   555,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,     0,   267,
       0,     0,     0,     0,     0,     0,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,   576,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,     0,   267,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   242,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,     0,   267,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,     0,   267,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,     0,   267,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267
};

static const yytype_int16 yycheck[] =
{
       2,     2,   126,    25,     2,     2,   314,   712,   165,    14,
      15,   196,    49,    25,   391,   508,   393,   239,   717,   267,
      25,   384,     8,   218,     8,   480,   177,     8,     8,   283,
       8,     8,    26,     8,     8,    25,     8,    26,     8,   639,
      38,     8,     8,    80,    77,    14,    15,    52,   541,     8,
       8,    65,    54,   307,    25,    65,    32,    95,    75,   640,
      77,   760,   284,     0,   286,    65,    75,    75,   107,    74,
      26,    32,    77,    77,    65,   153,   147,   299,   300,   633,
      49,   161,   153,   161,   208,    75,   153,   238,    75,   311,
     161,   313,   314,    25,   162,   163,   163,   164,   153,   161,
     463,    77,   465,   115,   161,   659,   161,    32,    81,    65,
      75,    80,    77,    77,   161,   153,    77,   371,    65,   147,
     159,   123,    14,    15,    75,   153,    77,   160,    77,    75,
      65,    77,   147,    25,   285,   140,   287,   718,   153,   129,
     291,   292,   293,    75,   153,   161,   183,   147,   161,   166,
     164,   156,    77,   161,   164,   164,   147,   162,   170,   536,
     150,   161,   166,   153,   164,   155,   153,    75,   141,   874,
     164,   771,   162,   164,   163,   370,    75,   163,   164,   163,
      95,   598,   163,   163,   160,   163,   163,   156,   163,   163,
     162,    75,   162,   198,   775,   162,   162,   129,   203,   160,
      75,   166,   166,   162,   162,    77,   211,   212,   213,   908,
     215,   666,   217,   164,   183,   166,    32,   166,   150,   161,
     166,   153,    32,   155,   153,   227,   161,   239,   161,   164,
      66,   103,   161,    75,   203,    77,    98,    99,   153,    75,
     164,    77,   211,   212,   213,   267,   215,   147,   122,    98,
      99,   150,   122,   153,   153,   267,   673,   634,   675,    75,
     161,    77,   267,   161,   156,   519,   150,    77,   239,   153,
     147,   147,   284,   161,   286,   111,   153,   153,   161,    75,
      97,    98,    99,   161,   161,   161,    75,   299,   300,    75,
      75,   296,    77,   161,   657,   111,   267,   551,   552,   311,
     164,   313,   314,   165,   309,   559,   560,   684,   556,   563,
      75,   203,   163,   284,   150,   286,   165,   153,    32,   211,
     212,   213,   699,   215,   166,   161,   111,    65,   299,   300,
     166,   161,   337,   129,   150,   372,   147,   153,   340,   344,
     311,   147,   313,   314,    65,   161,   351,    53,    54,    75,
     166,    77,   660,   126,   150,   162,   163,   153,    75,   155,
      77,    97,    98,    99,    65,   150,   368,   368,   153,    65,
     368,   368,    70,    71,    65,   267,   161,   153,    75,   384,
      77,   166,    70,    71,    65,   111,   391,   103,   393,   401,
      51,   396,   163,   164,   111,   580,   122,   153,   583,    66,
      47,    48,    49,   372,    51,   898,    14,    15,   147,   594,
     147,     8,   167,   161,   111,   384,   567,   147,   153,   153,
     147,   126,   730,    87,   150,    75,   431,   153,    13,    13,
     807,   128,   809,   150,   163,   161,   153,   162,   660,   163,
     166,    75,   162,   162,   161,   337,    75,   164,   124,   166,
     124,   161,   167,   150,   167,   163,   153,   161,   463,   351,
     465,     8,   431,    95,   161,    13,    75,   844,   161,   166,
     111,   112,   113,   114,   115,   116,   474,   482,   483,   484,
     162,   479,    77,   488,   489,   490,   163,   162,   486,   494,
     647,   161,   384,   161,   463,     8,   465,    75,   875,    77,
     685,   652,   653,   508,   509,   162,   511,    13,   730,   125,
     515,   516,   164,   482,   483,   161,   167,   161,   161,   521,
     521,    75,   162,   521,   521,   161,   531,   904,   533,   167,
     161,   536,   167,   111,   556,   161,   541,   542,   161,   431,
     509,   162,   511,   167,   556,   167,   515,   516,   167,   153,
      75,   556,    13,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   147,    13,   163,   162,   104,
     162,   463,   150,   465,   109,   153,   111,   112,   113,   114,
     115,   116,   117,   161,   589,   556,   153,   164,   166,     8,
     482,   483,   484,    53,    54,     8,   488,   489,   490,   162,
     605,   606,    65,    65,   164,   790,   126,   163,   127,    13,
     163,   616,   163,   127,     8,   800,    75,   509,   167,   511,
     589,   161,   164,   515,   516,   630,   162,   109,   162,   634,
     165,   163,   817,   162,   639,    77,   821,    13,   162,   531,
     162,   162,   827,   126,   162,   830,   162,   162,   660,    75,
     835,   162,   657,   163,   839,   167,    77,   162,    26,   161,
     662,    13,   667,   665,   556,   161,   671,   167,   167,   163,
     672,   162,   677,   163,   679,   163,   127,    77,    13,   684,
      13,    13,    75,   164,   869,   164,   161,    26,   657,   660,
     814,    72,   163,   162,   699,    13,   164,   589,   667,    77,
      77,    13,   162,   163,    95,   163,    95,   164,   154,   711,
     165,   163,   147,   605,   163,   900,   721,    13,   730,    75,
     163,    75,   161,    26,   616,   163,   911,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    77,
       8,   739,   103,   344,    75,    75,   162,   745,   746,   509,
     111,   112,   113,   114,   115,   116,   611,   759,   611,   730,
     667,   468,   308,   590,   536,   657,   771,    53,    54,   530,
     797,   844,   777,   542,   349,   667,    81,   690,   746,   671,
     605,   604,   781,   203,   515,   677,   216,   679,   516,    -1,
      -1,   789,    -1,    -1,    -1,    -1,    -1,   802,    -1,    -1,
      -1,   806,   807,    -1,   809,    -1,   811,    44,    45,    46,
      47,    48,    49,    -1,    51,    -1,    14,    15,   823,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,   721,
      -1,   833,    -1,   104,   836,    -1,    -1,    -1,   109,   844,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,   854,
      -1,    -1,    -1,   855,    -1,   860,    -1,   859,    -1,    -1,
      -1,   863,    -1,    -1,   866,    -1,   868,   865,   870,    -1,
     875,    -1,    -1,   878,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   777,    -1,    -1,   890,    -1,
      -1,    -1,    -1,   898,   165,    -1,    -1,    -1,    -1,   904,
      -1,    -1,    -1,    -1,   906,    -1,    -1,    -1,    -1,    -1,
     802,   913,    -1,    -1,   806,    -1,    -1,    -1,    -1,   811,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      -1,   823,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,   337,    -1,    -1,   156,    -1,
      44,    45,   854,    -1,    -1,    49,    -1,    51,   860,   351,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   104,    -1,    -1,    -1,   878,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,    80,    81,    -1,    -1,
       9,    10,    11,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      53,    54,    -1,   211,   212,   213,    25,   215,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,   165,    -1,   129,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,   267,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,    -1,   181,   182,   183,
      -1,   185,   484,    -1,    -1,    -1,   488,   489,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
     163,    51,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,   230,    -1,    -1,   531,
      -1,    -1,    -1,   162,   238,    -1,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,    -1,    -1,    -1,   384,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
      -1,   285,    -1,   287,   288,    -1,    -1,   291,   292,   293,
      -1,   484,    -1,    -1,    -1,   488,   489,   490,    -1,   303,
      -1,   305,    -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   431,   616,    -1,    -1,    -1,   322,    -1,
      44,    45,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,   531,    -1,
      -1,    65,   346,    -1,    -1,   463,    -1,   465,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    53,    54,   482,   483,    -1,   371,   372,   671,
      -1,    -1,    -1,    -1,    -1,   677,    -1,   679,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,   509,    -1,   511,    -1,    -1,    -1,   515,   516,    -1,
      -1,   405,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,    -1,   605,    -1,    -1,    -1,    -1,    -1,    -1,   721,
     144,    -1,    -1,   616,    -1,    -1,   150,   151,   152,   153,
       9,    10,    11,   157,    -1,    -1,    -1,    -1,   556,    -1,
      -1,    -1,    -1,    -1,    -1,   449,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   589,    51,    -1,   478,   777,   480,   481,   671,    -1,
      -1,    -1,    -1,    -1,   677,    -1,   679,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     802,    -1,    -1,    -1,   806,    -1,    -1,    -1,    -1,   811,
      -1,    -1,    -1,    -1,    -1,   519,    -1,    -1,    -1,    -1,
      -1,   823,    -1,    -1,    -1,    -1,   530,    -1,   721,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   657,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,   552,   667,
      -1,   555,   854,    -1,    -1,   559,   560,    -1,   860,   563,
      -1,    -1,    -1,   567,   568,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   576,    -1,    -1,    -1,   878,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   777,    -1,   165,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,   802,
      51,    -1,    -1,   806,    -1,    -1,    -1,    -1,   811,   623,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     823,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,   653,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   854,   666,    -1,    -1,    -1,    -1,   860,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    25,   878,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,   751,    -1,    -1,
      83,    84,    85,    86,    87,    -1,    89,    -1,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,    -1,   108,   109,   110,   111,   112,
     113,    -1,   786,    -1,    -1,   118,   119,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,   144,     3,     4,     5,     6,     7,   150,   151,   152,
     153,    12,   826,   156,   157,   158,    -1,    -1,   161,    -1,
     163,   164,   165,   166,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    44,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    -1,    89,    -1,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,    -1,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,   144,     3,     4,     5,     6,     7,   150,
     151,   152,   153,    12,    -1,   156,   157,   158,    -1,    -1,
     161,    -1,   163,   164,   165,   166,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,
      89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,    -1,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,   137,   138,
      -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,     6,
       7,   150,   151,   152,   153,    12,    -1,   156,   157,   158,
      -1,    -1,   161,    -1,   163,   164,    -1,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,   106,
      -1,   108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,
       5,     6,     7,   150,   151,   152,   153,    12,    -1,   156,
     157,   158,    -1,    -1,   161,    -1,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,
     105,   106,    -1,   108,    -1,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   123,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,
       3,     4,     5,     6,     7,   150,   151,   152,   153,    12,
      -1,   156,   157,   158,    -1,    -1,   161,    -1,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,
     103,    -1,   105,   106,    -1,   108,    -1,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,   144,     3,     4,     5,     6,     7,   150,   151,   152,
     153,    12,    -1,   156,   157,   158,    -1,    -1,   161,    -1,
     163,   164,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    -1,    89,    -1,
      91,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,   105,   106,    -1,   108,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,   144,     3,     4,     5,     6,     7,   150,
     151,   152,   153,    12,    -1,   156,   157,   158,    -1,    -1,
     161,    -1,   163,   164,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,
      89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,   101,   102,   103,    -1,   105,   106,    -1,   108,
      -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,   137,   138,
      -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,     6,
       7,   150,   151,   152,   153,    12,    -1,   156,   157,   158,
      -1,    -1,   161,    -1,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    -1,    89,    -1,    91,    92,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,   106,
      -1,   108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,
       5,     6,     7,   150,   151,   152,   153,    12,    -1,   156,
     157,   158,    -1,    -1,   161,    -1,   163,   164,    -1,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,
     105,   106,    -1,   108,    -1,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   123,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,
       3,     4,     5,     6,     7,   150,   151,   152,   153,    12,
      -1,   156,   157,   158,    -1,    -1,   161,    -1,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    -1,    89,    -1,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,
     103,    -1,   105,   106,    -1,   108,    -1,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,   144,     3,     4,     5,     6,     7,   150,   151,   152,
     153,    12,    -1,   156,   157,   158,    -1,    -1,   161,    -1,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,   105,   106,    -1,   108,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,   144,     3,     4,     5,     6,     7,   150,
     151,   152,   153,    12,    -1,   156,   157,   158,    -1,    -1,
     161,    -1,   163,   164,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,
      89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,   101,   102,   103,    -1,   105,   106,    -1,   108,
      -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,   137,   138,
      -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,     6,
       7,   150,   151,   152,   153,    12,    -1,   156,   157,   158,
      -1,    -1,   161,    -1,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,   106,
      -1,   108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,
       5,     6,     7,   150,   151,   152,   153,    12,    -1,   156,
     157,   158,    -1,    -1,   161,    -1,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,
     105,   106,    -1,   108,    -1,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   123,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,
       3,     4,     5,     6,     7,   150,   151,   152,   153,    12,
      -1,   156,   157,   158,    -1,    -1,   161,    -1,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    -1,    89,    -1,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,
     103,    -1,   105,   106,    -1,   108,    -1,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,   144,     3,     4,     5,     6,     7,   150,   151,   152,
     153,    12,    -1,   156,   157,   158,    -1,    -1,   161,    -1,
     163,   164,    -1,   166,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    -1,    89,    -1,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,   105,   106,    -1,   108,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,   144,     3,     4,     5,     6,     7,   150,
     151,   152,   153,    12,    -1,    -1,   157,   158,    -1,    -1,
     161,    -1,   163,   164,    -1,   166,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,
      89,    -1,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,
      -1,   100,   101,   102,   103,    -1,   105,   106,    -1,   108,
      -1,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,   137,   138,
      -1,   140,    -1,    -1,    -1,   144,     3,     4,     5,     6,
       7,   150,   151,   152,   153,    12,    -1,    -1,   157,   158,
      -1,    -1,   161,    -1,   163,   164,    -1,   166,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    -1,    89,    -1,    91,    -1,    93,    -1,    -1,    96,
      -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,   106,
      -1,   108,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,   144,     3,     4,
       5,     6,     7,   150,   151,   152,   153,    12,    -1,    -1,
     157,   158,    -1,    -1,   161,    -1,   163,   164,    -1,   166,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    -1,    89,    -1,    91,    -1,    93,    -1,
      -1,    96,    -1,    -1,    -1,   100,   101,   102,   103,    -1,
     105,   106,    -1,   108,    -1,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,
       3,     4,     5,     6,     7,   150,   151,   152,   153,    12,
      -1,    -1,   157,   158,    -1,    -1,   161,    -1,   163,   164,
      -1,   166,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    -1,    89,    -1,    91,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,   102,
     103,    -1,   105,   106,    -1,   108,    -1,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,   144,     3,     4,     5,     6,     7,   150,   151,   152,
     153,    12,    -1,    -1,   157,   158,    -1,    -1,   161,    -1,
     163,   164,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    -1,    89,    -1,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,   105,   106,    -1,   108,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,   144,     3,     4,     5,     6,     7,   150,
     151,   152,   153,    12,    -1,    -1,   157,   158,    -1,    -1,
     161,    -1,   163,   164,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   103,    51,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   144,    12,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,    -1,    -1,    -1,   157,   158,
      -1,   160,   161,    -1,    -1,    -1,    32,   166,    -1,    -1,
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
      -1,   157,   158,    -1,    -1,   161,    -1,    -1,    -1,    -1,
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
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   161,    -1,   163,    -1,    -1,   166,    -1,    -1,    -1,
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
      -1,    -1,    -1,   157,   158,    26,    -1,   161,   162,    -1,
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
     161,    -1,    -1,    -1,    32,   166,    -1,    -1,    -1,    -1,
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
     158,    -1,    -1,   161,    -1,    -1,    -1,    32,   166,    -1,
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
      -1,    -1,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,
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
      -1,   157,   158,    -1,    -1,   161,    -1,    -1,    -1,    -1,
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
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,     9,    10,    11,   157,   158,    -1,    -1,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   165,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   165,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   163,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   163,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   163,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   163,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   163,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   162,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   162,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   162,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   162,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   162,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   162,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   162,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   127,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   127,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    11,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51
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
     122,   150,   153,   171,   254,   256,   257,   281,   284,   285,
     291,   269,   161,   260,   161,    26,    65,    65,   245,   269,
     178,   161,   161,   161,   161,   161,   163,   269,   163,   269,
      75,    75,   163,   248,   269,   273,   164,   269,   153,   171,
     173,   174,    77,   166,   220,   221,    77,   222,   250,   122,
     122,   161,   161,   161,   161,   161,   161,   153,   164,   171,
     171,   248,   269,   273,   249,   269,   301,   176,   164,   153,
     161,     8,   163,    75,    75,   163,    32,   188,    65,   147,
       9,    10,    11,    25,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    51,   163,    53,
      54,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   161,   147,    65,   126,    65,   164,   166,
     285,    65,    65,    65,   188,   269,   153,   171,   301,   147,
     147,   271,   273,   127,   167,     8,   267,   161,   261,   153,
     171,   147,   261,   147,   126,   285,   162,   269,   269,   269,
     287,   287,     8,   163,    87,   269,   246,   247,   269,   248,
     273,    75,   202,   269,   163,   163,   163,    13,   163,   163,
     176,   163,   171,    95,     8,   163,   164,   270,   273,     8,
     163,    13,     8,   163,   188,   184,   185,   273,   273,   297,
     273,   162,   128,   273,   292,   293,   294,   171,   170,   163,
     164,   161,   127,   162,   162,   162,   121,   165,   177,   178,
     186,   187,   269,    75,    32,   160,   217,   218,   219,   269,
      75,   124,   192,   124,   194,    75,   161,   287,    75,   279,
     285,   291,   269,   269,   269,    26,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     256,    32,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   217,    75,   279,   287,    75,   164,
     279,   288,   289,   290,   287,   269,   287,   287,   287,   162,
     171,    75,    75,    32,   269,    32,   269,   217,   192,   171,
     279,   279,   288,   162,   162,   167,   167,   269,   161,   162,
     163,     8,    95,    95,    13,     8,   162,   162,    44,    45,
      65,    83,   129,   150,   153,   171,   254,   262,   263,   264,
     165,    95,    75,   174,   269,   221,   263,    77,   161,     8,
     162,     8,   162,   162,   163,   161,     8,   162,   162,   161,
     165,   170,   217,   248,   273,   161,   165,   271,   269,   162,
       8,    13,   150,   153,   171,   255,   125,   195,   196,   255,
     164,   161,    25,   129,   155,   211,   212,   214,   215,   255,
     167,   161,   161,   285,   269,    26,    66,   273,   162,   161,
     161,   167,   269,   161,   276,   277,   278,    65,   164,   167,
     165,   167,   167,   167,   271,   271,   127,   162,   195,   258,
      26,   178,   269,    26,   178,   206,   246,   269,   273,    32,
     198,   273,   263,    75,    26,   178,   201,    26,   164,   203,
     263,   263,   263,   266,   268,   161,   153,   171,   147,   107,
     159,   180,   181,   183,    75,   165,    13,   211,   185,   163,
     273,   292,   293,    13,   217,   165,   162,   162,   219,   263,
     153,   171,   196,   164,     8,   223,   211,   215,   162,     8,
      32,    77,   160,   213,   217,   217,   269,   256,   217,   217,
     165,   217,    65,    65,   274,   287,   269,    32,   269,   164,
     126,   259,   176,   207,   162,   176,   163,   127,   197,   273,
     197,    13,   176,   163,   204,   163,   204,   127,   167,     8,
     267,   266,   171,    75,   161,   164,   181,   182,   183,   263,
     162,   162,   269,   162,   163,   171,   223,   255,   104,   109,
     111,   112,   113,   114,   115,   116,   117,   165,   224,   226,
     239,   240,   241,   242,   244,   162,   109,   251,   214,   213,
      77,    13,   162,   162,   261,   162,   162,   162,   287,   287,
     126,   275,   167,   165,   271,   223,   288,   208,    70,    71,
     209,   163,    88,   246,   198,   162,   162,   263,    94,   204,
      97,    98,    99,   204,   165,   263,   263,   162,   255,   176,
     251,   165,    75,   227,   255,    77,   243,   250,   242,     8,
     163,    26,   216,   161,   216,    32,   213,    13,   263,   167,
     167,   288,   165,    70,    71,   210,   161,   178,   163,   162,
      26,   178,   200,   200,   163,    97,   163,   269,    26,   163,
     205,   165,   127,    77,   165,   216,    13,     8,   163,   164,
     228,    13,     8,   163,   225,    75,   214,   164,    32,    77,
     252,   164,   213,    13,   263,   278,   161,    26,    72,   269,
      26,   178,   199,   176,   163,   205,   176,   263,   162,   164,
     263,   255,    75,   229,   230,   231,   232,   234,   235,   236,
     255,   263,    77,   188,    13,   176,    77,     8,   162,   176,
      13,   263,   269,   176,   163,   162,   176,    92,   176,   164,
     176,   165,   231,   163,    95,   154,   163,   147,    13,    75,
     263,   165,    32,    77,   165,   263,   162,   178,    90,   163,
     176,   165,   237,   242,   233,   255,    75,   263,   161,    77,
      26,   163,   165,    75,     8,   211,   176,   255,   162,   216,
     163,   164,   238,   176,   165
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
     301,   301,   302,   302
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
       3,     8,     3,     3
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
#line 3456 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 216 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3464 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 219 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3472 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 225 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_SYMBOL_NAME);
  }
#line 3480 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 228 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-2]), (yyvsp[0]));
  }
#line 3488 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 237 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3498 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3510 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 249 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-4]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-4])->appendChild((yyvsp[-3]));
  (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3521 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3534 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 263 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3544 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 268 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3553 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 275 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 3561 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 278 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3570 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 285 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3580 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 290 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3591 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 296 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3602 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3614 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3626 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3638 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 329 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3646 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 332 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3654 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 341 "parser.y" /* yacc.c:1646  */
    {
  (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3664 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 350 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3675 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 356 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3683 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 359 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3691 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 362 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLOSE_TAG);
  }
#line 3699 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 368 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 3707 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3742 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3762 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 420 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_WHILE);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3774 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3787 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3805 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 448 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_SWITCH);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3817 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 455 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_BREAK);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3829 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 462 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_BREAK);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3841 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 469 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_CONTINUE);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3853 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 476 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_CONTINUE);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3865 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 483 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_RETURN);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3877 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 490 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3889 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 497 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3901 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 504 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3911 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 509 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3921 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 514 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3931 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 519 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_INLINE_HTML);
    (yyval) = (yyvsp[0]);
  }
#line 3940 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 523 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3949 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 527 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3958 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 531 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[-1]));
    NMORE((yyvsp[-2]), (yyvsp[-4]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3969 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3991 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4012 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 572 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_DECLARE);
    (yyvsp[-4])->appendChild((yyvsp[-2]));
    (yyvsp[-4])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4023 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 578 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4032 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4046 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4060 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 600 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_THROW);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));

  }
#line 4073 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4086 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 619 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4095 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 623 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_CATCH_LIST);
  (yyval)->appendChild((yyvsp[0]));
}
#line 4104 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4117 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 641 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4125 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 648 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_FINALLY);
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    NMORE((yyvsp[-3]), (yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 4136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 657 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4145 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 661 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4154 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 680 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4162 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 683 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_REFERENCE);
  }
#line 4170 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4187 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4203 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4220 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 732 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[0]);
  }
#line 4229 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 736 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4241 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 743 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4253 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 750 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 4262 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 757 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4270 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 760 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_EXTENDS_LIST)->appendChild((yyvsp[0]));
  }
#line 4278 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 770 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4286 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 773 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_EXTENDS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4296 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 781 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4304 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 784 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_IMPLEMENTS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4314 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 792 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[0]));
  }
#line 4322 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 795 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4330 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 801 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4338 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 804 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4346 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 811 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4356 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 820 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4366 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 829 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4376 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 838 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4386 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 846 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4397 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4410 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 863 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4418 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4433 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 876 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[0]));
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval) = (yyvsp[-2]);
  }
#line 4443 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4457 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 893 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4465 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4478 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 904 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_DEFAULT);
    (yyvsp[-2])->appendChild((yyvsp[0]));

    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval) = (yyvsp[-3]);
  }
#line 4490 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 920 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[0]));
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  (yyval) = (yyvsp[-2]);
  }
#line 4500 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 928 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4508 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 931 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_ELSEIF);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyvsp[-4]));
  }
#line 4520 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 941 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4528 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 944 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_ELSEIF);
    (yyvsp[-5])->appendChild((yyvsp[-3]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyvsp[-5]));
  }
#line 4540 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 954 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4548 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 957 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_ELSE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4558 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 965 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4566 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 968 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ELSE);
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4576 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 977 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
#line 4584 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4597 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4611 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4625 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4638 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4651 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4665 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4679 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4692 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1056 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_UNPACK);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 4701 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1060 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4709 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1066 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4717 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1070 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_NULLABLE_TYPE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4726 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1077 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4734 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1080 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4742 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4750 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1089 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4758 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1092 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_RETURN);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4767 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1100 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
#line 4775 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1106 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4783 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1109 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4791 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1116 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNPACK)->appendChild((yyvsp[-1]));
  }
#line 4799 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1119 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4808 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1126 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4817 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1130 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4826 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1137 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4834 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1140 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4843 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1144 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-3]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 4852 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4865 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4878 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4891 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4904 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1186 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4912 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1189 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4920 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4933 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1203 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4942 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1207 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4950 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1210 "parser.y" /* yacc.c:1646  */
    {
    /* empty */
  }
#line 4958 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 4976 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1228 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-2]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4986 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1236 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[0]));
  }
#line 4994 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1239 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5002 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1245 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5010 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1248 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5018 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1254 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
#line 5026 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1257 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5034 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1263 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5043 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1267 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 5052 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1274 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5060 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1277 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5068 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1283 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5078 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1291 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5087 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1295 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 5096 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1302 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5105 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1306 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5113 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1312 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[-2]), (yyvsp[-1]), NTYPE((yyvsp[0]), n_STRING));
    (yyval) = (yyvsp[-1]);
  }
#line 5123 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1320 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5134 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1326 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 5145 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1335 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5153 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1338 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5162 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1346 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5170 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1349 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5178 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1356 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5187 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1363 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
#line 5195 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1366 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[0]);
  }
#line 5204 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1373 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5213 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1377 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5221 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1392 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 5233 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1399 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 5245 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1406 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5257 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1413 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5269 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5283 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5297 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1444 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1447 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5314 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1454 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5322 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1462 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5330 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1465 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5339 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5352 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1480 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5363 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5378 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5397 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1510 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5407 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1515 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5418 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1521 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5429 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1527 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5440 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1533 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5451 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1539 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5462 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1545 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5473 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1551 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5484 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1557 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5495 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1563 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5506 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1569 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5517 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1575 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5528 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1581 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5538 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1586 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5548 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1591 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5558 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1596 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5568 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1601 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5579 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1607 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5590 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1613 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5601 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1619 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5612 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1625 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5623 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1631 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5634 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1637 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5645 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1643 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5656 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5687 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1675 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5698 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1681 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5709 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1687 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5720 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1693 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5731 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1699 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5742 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1705 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5753 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1711 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5764 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1717 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5774 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1722 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5784 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1727 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5794 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1732 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5804 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1737 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5815 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1743 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5826 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1749 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5837 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1755 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5848 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1761 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5859 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1767 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5870 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1773 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5881 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1779 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5892 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1785 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5903 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1791 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5914 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5927 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 5940 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1815 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5951 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1822 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5961 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1827 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5971 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1832 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5981 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1837 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5991 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1842 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6001 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 1847 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6011 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1852 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6021 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1857 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6031 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1862 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6041 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1867 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[0]);
  }
#line 6050 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1874 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6060 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1879 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[0]);
  }
#line 6071 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6088 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6111 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1924 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6122 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1930 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6133 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1936 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6144 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1942 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6155 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1955 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6163 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1958 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[-3])->appendChildren((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6173 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1966 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6181 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1969 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 6191 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1974 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6200 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1978 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 6211 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1987 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6221 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1993 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-5]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1999 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-4]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6243 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6256 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6269 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6282 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6295 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2041 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 2049 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6313 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 2052 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6321 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 2055 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6330 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 2059 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6339 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 2066 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6347 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2069 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6356 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2073 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6365 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6382 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2104 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 6390 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2107 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6398 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2113 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6406 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2119 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6414 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2122 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-1]), n_EMPTY, (yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6423 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2126 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 6433 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2134 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6441 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2137 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6449 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2143 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6457 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2146 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6465 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2149 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_STRING_SCALAR);
  }
#line 6473 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2152 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6481 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2155 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6489 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2158 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6497 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2161 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6505 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2164 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6513 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2167 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6521 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2170 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6529 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2173 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6537 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2176 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_HEREDOC);
  }
#line 6545 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2184 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = (yyvsp[0]);
  }
#line 6554 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 2188 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = (yyvsp[0]);
  }
#line 6563 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 2192 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6573 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 2197 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6583 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2202 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 6593 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2207 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 6603 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2216 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 6613 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2227 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-2]));
  }
#line 6621 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2230 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-1]));
  }
#line 6629 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2237 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6637 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2240 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6645 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 2246 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6653 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 2257 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6665 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 2264 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6677 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2271 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6689 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2278 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6701 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6729 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2335 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChildren((yyvsp[0]));
  }
#line 6737 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2338 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6745 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6757 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2354 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6768 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2360 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6779 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2369 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6787 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2377 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6795 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6812 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2399 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6822 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2404 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6832 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2416 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6843 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2422 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6854 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2438 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6862 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6879 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2457 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6890 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2463 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6901 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2473 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 6909 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2476 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-3]), n_VARIABLE_EXPRESSION, (yyvsp[0]));
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6919 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2484 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6927 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2487 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6935 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2498 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6946 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2504 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6957 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2514 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_STRING);
    (yyval) = (yyvsp[0]);
  }
#line 6966 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2518 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6974 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2524 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);
  }
#line 6982 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 6999 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2542 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7007 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2545 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7016 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2553 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 7025 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2557 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 7033 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2563 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 7041 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2566 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 7049 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2572 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 7061 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2579 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 7073 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2586 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7085 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2593 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7097 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2600 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 7109 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2607 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 7121 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2614 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7133 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2621 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7145 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 7160 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 7175 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2651 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7183 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2654 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7191 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 7206 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2667 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7214 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2670 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7222 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2676 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7231 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2680 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7239 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2686 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 7249 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2691 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 7257 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2697 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7268 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2703 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7279 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2709 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7290 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2715 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7301 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2721 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7312 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2730 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 7322 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 2735 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 7332 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2743 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 7343 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 2750 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_DECLARATION);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyval), (yyvsp[0]));

    NTYPE((yyvsp[-7]), n_NEW);
    (yyvsp[-7])->appendChild((yyval));
    (yyvsp[-7])->appendChild((yyvsp[-5]));
    (yyval) = (yyvsp[-7]);
  }
#line 7362 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 2767 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7372 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 2772 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7382 "parser.yacc.cpp" /* yacc.c:1646  */
    break;


#line 7386 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 2779 "parser.y" /* yacc.c:1906  */


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
/* @generated */
