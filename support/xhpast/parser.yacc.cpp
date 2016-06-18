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
#define YYLAST   7553

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  441
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  906

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
    1017,  1025,  1034,  1044,  1056,  1060,  1066,  1069,  1073,  1076,
    1079,  1085,  1088,  1094,  1095,  1101,  1104,  1110,  1111,  1114,
    1121,  1125,  1132,  1135,  1139,  1146,  1154,  1162,  1170,  1181,
    1184,  1190,  1198,  1202,  1205,  1205,  1223,  1231,  1234,  1240,
    1243,  1249,  1252,  1258,  1262,  1269,  1272,  1278,  1286,  1290,
    1297,  1301,  1307,  1315,  1321,  1330,  1333,  1341,  1344,  1350,
    1351,  1358,  1361,  1368,  1372,  1378,  1379,  1380,  1381,  1382,
    1383,  1387,  1394,  1401,  1408,  1418,  1427,  1439,  1442,  1449,
    1452,  1457,  1460,  1467,  1475,  1481,  1491,  1505,  1510,  1516,
    1522,  1528,  1534,  1540,  1546,  1552,  1558,  1564,  1570,  1576,
    1581,  1586,  1591,  1596,  1602,  1608,  1614,  1620,  1626,  1632,
    1638,  1644,  1670,  1676,  1682,  1688,  1694,  1700,  1706,  1712,
    1717,  1722,  1727,  1732,  1738,  1744,  1750,  1756,  1762,  1768,
    1774,  1780,  1786,  1792,  1793,  1794,  1802,  1810,  1816,  1817,
    1822,  1827,  1832,  1837,  1842,  1847,  1852,  1857,  1862,  1866,
    1867,  1868,  1869,  1874,  1880,  1895,  1919,  1925,  1931,  1937,
    1946,  1950,  1953,  1961,  1964,  1969,  1973,  1982,  1987,  1994,
    2000,  2009,  2018,  2027,  2036,  2044,  2047,  2050,  2054,  2061,
    2064,  2068,  2075,  2076,  2080,  2095,  2099,  2102,  2108,  2114,
    2117,  2121,  2129,  2132,  2138,  2141,  2144,  2147,  2150,  2153,
    2156,  2159,  2162,  2165,  2168,  2171,  2177,  2178,  2179,  2183,
    2187,  2192,  2197,  2202,  2207,  2211,  2219,  2220,  2221,  2222,
    2225,  2228,  2232,  2235,  2241,  2244,  2248,  2259,  2266,  2273,
    2283,  2284,  2288,  2292,  2296,  2300,  2326,  2330,  2333,  2339,
    2349,  2355,  2364,  2370,  2371,  2372,  2378,  2379,  2394,  2399,
    2407,  2411,  2417,  2426,  2427,  2428,  2432,  2433,  2436,  2448,
    2452,  2458,  2464,  2468,  2471,  2479,  2482,  2488,  2489,  2493,
    2499,  2505,  2509,  2513,  2519,  2522,  2537,  2540,  2547,  2548,
    2552,  2558,  2561,  2567,  2574,  2581,  2588,  2595,  2602,  2609,
    2616,  2626,  2636,  2646,  2649,  2652,  2662,  2665,  2671,  2675,
    2681,  2686,  2692,  2698,  2704,  2710,  2716,  2725,  2730,  2738,
    2747,  2752
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

#define YYPACT_NINF -690

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-690)))

#define YYTABLE_NINF -381

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-381)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -690,    76,  1810,  -690,  5980,  5980,  -106,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,   173,   173,  5980,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,  4650,   387,  5980,  -104,   -81,  -690,
    -690,    62,  -690,  -690,  -690,    93,  -690,  5980,  4508,   -39,
     -32,    61,    79,    81,  4783,  4916,    99,  -690,   128,  5049,
      48,  5980,    -8,    51,    -6,   123,   140,    98,   110,   114,
     132,  -690,  -690,   143,   147,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,     0,  -690,  -690,   214,  -690,  -690,
    5980,  6113,  -690,  -690,   154,   -60,  -690,    21,  -690,  -690,
    -690,  -690,  -690,  -690,   256,   260,  -690,   187,   325,   300,
     222,  -690,  -690,  6536,  -690,    45,  1218,   224,  -690,   253,
     344,   287,  -690,    55,  -690,   137,  -690,  -690,   349,   351,
    -690,   355,   356,   320,   274,  -690,   325,  7328,  7328,  5980,
    7328,  7328,  7434,  -690,  -690,   377,  -690,  -690,  -690,   277,
     214,   378,   103,   306,  -690,  -690,   307,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,   173,  7126,   276,   449,
     308,   214,   313,   316,   318,  -690,   321,   334,   -22,   137,
    -690,  5182,  -690,  5980,  -690,  5980,  5980,    22,  7328,   380,
    5980,  5980,  5980,   408,  5980,  -690,  6579,  -690,  6622,   322,
     471,  -690,   332,  7328,   761,  -690,  6673,   214,   -45,    23,
    -690,  -690,   238,    24,  -690,   475,    25,   325,  -690,  -690,
     173,   173,   173,   335,   172,  4650,   214,  -690,   -74,   -47,
     199,  7169,   213,   342,  6716,   347,  1952,  5980,   421,  1262,
     431,  -690,   393,   395,  -690,  -690,   -31,  5980,     6,  5980,
    5980,  5980,  5315,  5980,  5980,  5980,  5980,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,
    5980,  5980,  5980,  5980,  5980,  5980,   387,  -690,  -690,  -690,
    5448,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,  5980,
    5980,  5980,  1262,    42,  5980,    49,  5980,  5980,   154,    -9,
    5980,  5980,  5980,   359,  6759,   214,   107,   347,    57,    73,
    -690,  -690,  5581,  -690,  5714,  -690,   214,   313,   144,  1262,
    -690,   144,    49,   -17,  -690,  6810,  6854,  7328,   369,   374,
    5980,  -690,   361,  6897,   363,   534,  7328,   448,  1082,   531,
      14,  6946,  -690,  -690,  -690,   898,  -690,  -690,  2094,  -690,
     -37,   474,    -8,  -690,  5980,  -690,  -690,    51,  -690,   898,
     469,  -690,   389,    18,  -690,  -690,  -690,    29,   390,   388,
     394,  -690,    33,  -690,   398,    91,  1498,  -690,  -690,  1262,
    5980,  -690,  -690,  -690,   396,  -690,  -690,  -690,  -690,  -690,
    6258,  -690,   173,  5980,   406,   561,  -690,  7328,   557,    40,
     446,    40,   413,   425,   297,   415,   426,   427,   -17,   137,
    7370,  7409,  7434,  5980,  7272,  7459,  1659,  7481,  7502,  4703,
    1405,  1478,  1478,  1478,  1478,  1478,  1073,  1073,  1073,  1073,
     679,   679,   294,   294,   294,   377,   377,   377,  -690,    -7,
    7434,  7434,  7434,  7434,  7434,  7434,  7434,  7434,  7434,  7434,
    7434,  7434,   429,   428,   432,   430,  -690,  5980,  -690,   433,
      -4,  -690,   435,  6301,   437,   438,   442,  -690,   120,   426,
     428,   173,  7328,   173,  7227,   313,  -690,   436,  -690,  -690,
    -690,  3798,  -690,  -690,  7328,  5980,  3940,  5980,  5980,   173,
     242,   898,   524,  4082,    36,   898,   898,   898,  -690,   439,
     457,   214,   -87,   464,  -690,  -690,  -690,   -54,   537,  -690,
    -690,  6344,  -690,  -690,   601,   297,   173,   453,   173,  -690,
    -690,  -690,   172,   172,   605,  -690,  1262,  -690,  1668,   460,
     211,   418,   461,  -690,  -690,  7328,  -690,  1262,   898,   472,
     214,   313,  -690,    40,   462,   619,  -690,  -690,   297,  -690,
    -690,   467,   622,     8,  -690,  -690,  -690,  1262,  1262,   -17,
    7459,  5980,   387,  -690,  -690,  1262,  1262,  -690,  6397,  1262,
     567,   573,  -690,  5980,  5980,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  5847,  -690,   513,  -690,  -690,  6990,  -690,  -690,
    -690,   482,  7328,   520,   173,   520,  -690,  -690,   636,  -690,
    -690,  -690,   487,   488,  -690,  -690,  -690,   527,   490,   652,
     898,   214,   149,   596,   514,   510,   -54,  -690,  -690,  -690,
    -690,   898,   515,  -690,  -690,  -690,    34,  -690,  5980,   516,
    -690,  -690,   518,  -690,  -690,   214,   313,   619,  -690,    40,
     450,   523,   577,   296,   -53,  -690,   599,   669,   535,   536,
    7459,   318,   539,   542,  -690,   543,  5980,  5980,   580,   532,
    6440,   173,  7328,    49,  -690,  3656,    32,   544,  2236,  5980,
     242,   549,  -690,   550,   898,  2378,  -690,   257,  -690,    13,
     898,  -690,   898,  -690,   553,   174,  -690,    40,  -690,  -690,
    -690,  -690,  -690,   577,  -690,  7434,  -690,  -690,   313,   579,
    -690,   641,    40,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,   642,   320,   399,  -690,    26,   692,   559,
     692,    41,   708,  -690,   898,  -690,  -690,  -690,  -690,  -690,
    -690,   562,   565,    49,  -690,  -690,  -690,  -690,  -690,   310,
     572,  4508,  -690,  -690,   574,   576,  -690,  4224,  4224,  -690,
     578,   299,   582,  5980,     2,   159,  -690,  -690,   608,  -690,
     659,  2520,   692,  -690,   726,    19,  -690,   730,    31,  -690,
    -690,   673,  -690,   296,   586,    59,   587,   -53,   739,   898,
    -690,  -690,  -690,   433,   598,   731,   689,  5980,  -690,  -690,
    4366,  -690,  -690,  -690,  -690,  -690,   600,  -690,  6485,  -690,
    -690,  -690,  -690,   898,   604,  -690,   609,   898,    40,  -690,
     179,  -690,   898,   685,  -690,   325,   773,  -690,  -690,   710,
    -690,    37,  -690,   777,   898,  -690,  -690,  5980,  -690,   628,
    7033,  -690,  -690,  -690,  2662,  -690,  -690,  3656,  -690,   630,
    -690,  -690,  -690,   709,   640,   179,  -690,   643,   713,   656,
     648,   665,  -690,   800,   742,   898,  2804,  -690,    64,  -690,
    2946,   898,  -690,  7082,  3656,  -690,  4508,  3088,   655,  3656,
    -690,  3230,  -690,  -690,  -690,   687,    40,  -690,   744,   898,
     660,  -690,  -690,   746,  -690,  -690,  -690,   801,  -690,   666,
    -690,  3372,  -690,   756,   757,   825,  -690,  -690,  -690,   297,
    -690,  -690,  -690,  -690,  -690,    40,   672,  3656,  -690,   692,
     230,  -690,  -690,  -690,  3514,  -690
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,     0,     0,   319,     0,   324,
     325,     5,   346,   393,    52,   326,   278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,    80,    86,     0,     0,   330,   331,   333,   327,   328,
      32,    33,    34,   335,     0,   334,   329,     0,    83,   332,
     283,     0,    59,    25,   404,   348,     3,     0,     7,    30,
       8,     9,    73,    74,     0,     0,   361,     0,    75,   385,
       0,   351,   279,     0,   360,     0,   362,     0,   389,     0,
     384,   366,   383,   386,   392,     0,   268,   263,   280,   281,
     264,   347,     5,   305,     0,   283,    75,   423,   424,     0,
     426,   427,   282,   249,   250,   251,   252,     5,   305,     0,
       0,     0,   306,     0,   230,   364,     0,   232,   269,   270,
     271,   272,   273,   274,   275,   277,     0,   416,     0,   354,
       0,     0,   306,   312,   322,   313,     0,   315,   386,     0,
     217,     0,   276,     0,    31,   395,   395,     0,   208,     0,
       0,   209,     0,     0,     0,    42,     0,    44,     0,     0,
       0,    46,   361,     0,   362,    25,     0,     0,    18,     0,
      17,   152,     0,     0,   151,   157,     0,    75,    81,    82,
       0,     0,     0,     0,   410,   411,     0,     4,     0,   350,
     361,     0,   362,     0,     0,   264,     0,     0,     0,   144,
       0,    15,    84,    87,    54,    76,     0,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,   229,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,   395,     0,   395,     0,   405,   388,
     395,   395,   395,     0,     0,     0,   308,     0,     0,     0,
     420,   363,     0,   438,   355,   412,     0,   308,     0,   144,
     439,     0,     0,   388,   320,     0,     0,   396,     0,     0,
       0,    51,     0,     0,     0,   210,   212,   361,   362,     0,
       0,     0,    43,    45,    63,     0,    47,    48,     0,    62,
      20,     0,     0,    14,     0,   153,   362,     0,    49,     0,
       0,    50,     0,     0,    70,    72,   428,     0,     0,     0,
       0,   408,     0,   407,     0,   349,     0,    11,     4,   144,
       0,   431,   430,   387,     0,    35,    24,    26,    27,    28,
       0,     6,     0,     0,     0,   143,   145,   147,     0,     0,
      89,     0,     0,     0,   136,     0,   440,   378,   376,     0,
     235,   237,   236,     0,     0,   267,   233,   234,   238,   240,
     239,   255,   256,   253,   254,   261,   257,   258,   259,   260,
     247,   248,   242,   243,   241,   244,   245,   246,   262,     0,
     214,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,   441,   379,     0,   402,     0,   398,   375,
     397,   401,     0,     0,     0,     0,     0,   425,   307,     0,
       0,     0,   415,     0,   414,   307,   378,     0,   379,   317,
     321,     0,   436,   434,   207,     0,     0,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,   326,     0,
       0,     0,   337,     0,   336,    23,   344,     0,     0,    19,
      16,     0,   150,   158,   155,   136,     0,     0,     0,   421,
     422,    10,   410,   410,     0,   437,   144,    13,     0,     0,
     361,   362,     0,   394,   149,   148,   297,     0,     0,     0,
       0,   309,    85,     0,     0,    88,    91,   160,   136,   139,
     140,     0,   124,     0,   137,   138,   382,   144,   144,   377,
     266,     0,     0,   215,   304,   144,   144,   381,     0,   144,
     374,   373,   368,   395,     0,   390,   391,   433,   432,   435,
     419,   418,     0,   323,   314,    25,   116,     0,    25,   114,
      38,     0,   211,    93,     0,    93,    95,   103,     0,    25,
     101,    58,   109,   109,    41,   340,   341,   359,     0,   354,
     352,     0,   339,     0,     0,     0,    67,    65,    61,    21,
     154,     0,     0,    71,    55,   429,     0,   406,     0,     0,
      12,   299,     0,   146,    22,     0,   311,    90,   160,     0,
     191,     0,   291,   136,     0,   135,     0,   126,     0,     0,
     265,   322,     0,     0,   403,     0,   395,   395,   365,     0,
       0,     0,   413,     0,   316,   118,   120,     0,     0,   209,
       0,     0,    96,     0,     0,     0,   109,     0,   109,     0,
       0,   343,   355,   353,     0,   338,   345,     0,    25,    64,
      60,    68,   156,   291,   409,   213,   298,    29,   310,   191,
      92,     0,     0,   198,   199,   200,   197,   196,   195,   190,
      79,   159,   163,     0,     0,   189,   193,     0,   141,     0,
     141,     0,   127,   134,     0,   300,   303,   216,   301,   302,
     372,     0,     0,     0,   367,   399,   400,   417,   318,   122,
       0,     0,    36,    39,     0,     0,    94,     0,     0,   104,
       0,     0,     0,     0,     0,     0,   105,   358,   357,   342,
       0,     0,   141,    78,     0,     0,   167,   203,     0,   164,
     194,     0,   162,     0,     0,     0,     0,     0,   130,     0,
     129,   370,   371,   375,     0,     0,     0,     0,   121,   115,
       0,    25,    99,    57,    56,   102,     0,   107,     0,   112,
     113,    25,   106,     0,     0,    69,     0,     0,     0,   169,
     171,   166,     0,     0,   161,    75,     0,   142,    25,     0,
     295,     0,    25,   131,     0,   128,   369,     0,    25,     0,
       0,    25,    97,    40,     0,   108,    25,   111,   356,     0,
      25,   206,   168,     5,     0,   172,   173,     0,     0,   181,
       0,     0,   204,   201,     0,     0,     0,   296,     0,   292,
       0,     0,   133,     0,   123,    37,     0,     0,     0,   110,
      25,     0,   170,   174,   175,   185,     0,   176,     0,     0,
       0,   205,    77,     0,   293,   284,   132,     0,   117,     0,
     100,     0,   285,     0,   184,   177,   178,   182,   202,   136,
     294,    25,    98,    66,   183,     0,     0,   119,   179,   141,
       0,   187,    25,   165,     0,   188
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -690,  -690,  -202,    -5,  -690,  -690,   493,  -690,  -160,  -690,
      16,  -690,  -690,   231,  -690,   232,  -690,   330,    12,    17,
    -125,  -690,  -690,  -690,  -690,  -690,  -690,  -690,   309,   254,
     181,  -690,   105,  -690,  -690,  -690,  -352,    63,  -690,  -690,
    -690,  -690,  -690,  -502,  -690,  -588,   212,    84,  -689,  -196,
    -690,   323,  -690,   502,  -690,   225,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,    27,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -688,  -690,  -690,  -690,  -461,  -690,
     -42,   775,    -2,   171,  -690,  -690,   156,  -222,  -258,  -690,
    -690,  -690,  -690,   217,  -324,   -80,  -690,  -690,   263,   261,
    -690,   910,   663,  -369,   397,    95,  -690,  -690,  -690,  -690,
      94,  -234,  -690,   558,  -690,  -690,   -23,   -20,  -690,  -153,
    -306,  -690,  -690,   -13,   354,   358,   653,  -690,  -690,  -690,
    -690,  -690,  -690,   139,  -690
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   199,   200,    87,   226,   376,
     377,    89,   606,   607,   680,   608,   353,   354,   378,   379,
     236,    92,    93,    94,   390,    95,   392,   534,   535,   661,
     585,   823,   783,   591,   330,   594,   667,   791,   580,   656,
     729,   732,   776,   541,   542,   637,   543,   544,   764,   384,
     385,   386,   203,   204,   206,   630,   701,   805,   702,   755,
     801,   834,   835,   836,   837,   885,   838,   839,   840,   883,
     903,   703,   704,   705,   706,   758,   707,   177,   324,   325,
      96,    97,   126,   710,   811,    99,   100,   545,   164,   165,
     574,   654,   172,   310,   101,   597,   496,   102,   598,   305,
     599,   103,   104,   300,   105,   106,   648,   724,   560,   561,
     562,   107,   108,   109,   110,   111,   112,   113,   114,   318,
     449,   450,   451,   115,   362,   363,   158,   159,   116,   357,
     117,   118,   119,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   293,   167,   612,   397,   168,   469,   192,   428,   142,
     142,   494,   169,   524,    90,   366,   581,   760,    88,    91,
     162,   766,   482,   319,   635,   494,   506,   798,   789,   230,
     320,   342,   347,   350,   761,   338,   631,   508,   220,   803,
     634,   513,   513,   286,   393,   848,   712,   198,   286,   444,
     341,   448,   207,   604,   179,   129,   286,   171,   498,   552,
    -306,   563,   592,   796,   397,   444,   228,   137,   137,   218,
      33,   205,   219,   767,   466,   137,     3,   468,   448,   228,
     173,   396,   352,    33,   395,   635,   442,  -306,   174,   367,
     368,   809,   570,   228,   571,   289,   873,    47,   268,   269,
    -308,   229,   730,   731,   138,   605,   228,   636,   228,   145,
     145,   743,   744,   467,   369,   137,   228,   443,   635,    33,
     286,   207,   180,   768,   446,  -380,    33,   175,   201,   181,
     394,   445,   459,   452,    33,   296,   810,   454,   455,   456,
     327,   874,   287,   139,   194,   197,   140,   287,   460,   313,
      33,   142,  -377,   216,   141,   287,   307,   494,   176,    84,
     564,   494,   494,   494,   217,   790,   518,   532,   636,   536,
     143,   143,    84,   519,   189,   222,   483,   884,   746,   813,
     507,   163,   799,   800,   231,   321,   343,   348,   351,   762,
     529,   509,   340,   530,   804,   514,   684,   142,   735,   849,
     593,   636,  -380,   190,   494,   142,   142,   142,    84,   142,
     900,   365,   195,   447,    33,    84,  -376,   202,   398,   287,
     225,    33,   182,    84,    98,   399,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,  -307,    84,
     183,   669,   184,   167,   228,   208,   168,   137,   137,    33,
      33,   301,   516,   169,   833,   495,   228,   743,   744,   210,
     228,   162,   209,   398,   229,   398,  -364,  -364,   369,   503,
     399,   211,   399,   228,   584,   212,   494,   328,   398,   398,
     297,   516,   727,   138,   138,   399,   399,   494,   398,   137,
     458,   398,   398,   213,   641,   399,  -308,   346,   399,   399,
     360,   465,   228,   288,   214,   355,   356,   358,   215,   361,
      84,   536,   143,   137,   741,    33,   745,   137,   227,    33,
     619,  -307,   139,   139,   792,   140,   140,   228,   520,   529,
     492,   232,   530,   141,   141,   233,    98,   198,    84,    84,
     494,   263,   264,   265,   492,   266,   494,   728,   494,   138,
     234,   638,   639,   138,   742,   743,   744,   235,   143,   642,
     643,  -286,  -286,   645,    98,   237,   143,   143,   143,   238,
     143,   137,   137,  -288,  -288,  -287,  -287,   142,    90,   549,
     774,   775,    88,    91,   531,   282,   531,   896,   139,   531,
     494,   140,   139,   901,   902,   140,   786,   743,   744,   141,
     283,   587,   344,   141,    84,   595,   596,   690,    84,   284,
     649,   144,   147,   285,   290,   655,   291,   773,   658,   448,
     292,   175,   163,    47,   142,   539,   539,   216,   266,   665,
     295,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   303,    25,   494,   529,   529,   624,   530,
     530,   540,   540,   298,   299,   750,   142,   304,   142,  -125,
     312,   306,   137,   308,    33,   521,   228,   322,   311,   494,
     756,  -364,  -364,   494,   142,   142,   492,   301,   494,   309,
     492,   492,   492,   329,   335,   334,   602,   576,   349,   448,
     494,   493,   579,   721,   722,   336,   381,   359,   138,   590,
     531,   142,  -192,   142,   371,   493,   388,   142,   142,   373,
     693,   694,   695,   696,   697,   698,    98,   389,   751,   391,
     394,   494,   475,   492,   553,   626,   477,   494,   531,   167,
      90,   682,   168,   531,    88,    91,   472,   160,   143,   169,
     161,   473,   478,   479,   481,   494,   504,   162,   141,   499,
     505,   511,   510,    84,   691,   512,   301,   522,   301,   692,
     515,   693,   694,   695,   696,   697,   698,   699,   526,   527,
     528,   533,   146,   146,   583,   586,   832,   537,   841,   142,
    -289,  -289,   546,   166,   739,   143,   538,   547,   548,   555,
     747,   554,   748,   556,   559,   492,   675,   557,   573,   588,
     600,   355,   565,   615,   567,   568,   492,   361,   361,   569,
     601,   603,   609,   841,   611,   700,   614,   143,   618,   143,
     688,   824,   621,   622,   531,   625,   628,   629,   531,   632,
     633,   827,   646,   398,   770,   143,   143,   493,   647,   653,
     399,   493,   493,   493,   886,   659,   142,   660,   846,   664,
     666,   668,   850,    98,   670,   142,    98,   671,   854,   492,
     672,   857,   143,    98,   143,   492,   859,   492,   143,   143,
     861,   676,   531,   898,   678,   677,   713,   683,   686,   662,
     844,   687,   714,   691,   493,   708,   709,   531,   692,   815,
     693,   694,   695,   696,   697,   698,   699,   715,   716,   725,
     881,   718,   759,   398,   719,   720,   723,   733,   163,   492,
     399,   737,   738,   828,   146,   749,   754,   831,   763,   757,
     765,   769,   842,   260,   261,   262,   263,   264,   265,   771,
     266,   897,   772,   777,   852,   793,   794,   779,   780,   797,
     143,   785,   904,   802,   753,   787,   301,   778,   806,    98,
     808,   812,   814,   782,   782,   586,   493,   818,   531,   817,
     146,   819,   843,   825,   492,   871,   829,   493,   146,   146,
     146,   876,   146,   830,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   845,   847,   492,   888,
     851,   855,   492,   531,   860,   531,   822,   492,   693,   694,
     695,   696,   697,   698,  -180,   862,   864,   143,   865,   492,
     866,   867,   868,   869,  -364,  -364,   143,   870,   880,   887,
     493,   889,    98,   890,   166,    98,   493,   891,   493,   892,
     531,   894,  -186,   895,   899,   500,   613,   679,   681,   663,
     492,   736,   627,   784,    98,   711,   492,   807,    98,   502,
     623,   826,    98,   689,   752,    98,   223,    98,   717,    98,
     673,   531,   863,   674,   492,   345,   616,   816,   364,     0,
     493,   617,   878,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,   531,     0,     0,     0,     0,     0,
     531,     0,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,   130,   131,   132,
     133,   134,   135,   136,   337,   493,   148,   149,   150,   151,
     152,   153,   154,   155,   157,     0,   170,     0,     0,     0,
     146,     0,   485,   486,     0,     0,     0,   178,     0,   493,
       0,     0,     0,   493,   186,   188,     0,     0,   493,   193,
       0,   196,     0,   487,     0,     0,     0,     0,     0,     0,
     493,    29,    30,   137,     0,     0,     0,     0,     0,     0,
       0,   488,     0,     0,     0,     0,     0,   146,     0,     0,
     221,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,     0,     0,     0,     0,     0,   493,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,   146,     0,     0,     0,   493,     0,   489,    65,    66,
      67,    68,    69,     0,     0,     0,     0,   146,   146,   294,
       0,     0,    73,     0,     0,     0,     0,     0,   490,    75,
      76,   491,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,   146,     0,   146,     0,     0,     0,
     146,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,   316,     0,   317,   317,     0,     0,     0,
     323,   326,   193,     0,   331,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,     0,
     166,  -381,  -381,  -381,  -381,   258,   259,   260,   261,   262,
     263,   264,   265,     0,   266,   157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -364,  -364,   380,     0,   387,
       0,     0,   146,     0,     0,     0,     0,   317,     0,   400,
     401,   402,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,     0,   480,     0,     0,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   387,     0,   317,     0,   317,   453,     0,     0,
     317,   317,   317,     0,     0,     0,     0,     0,     0,   146,
       0,     0,   462,     0,   464,     0,     0,     0,   146,   387,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       0,  -364,  -364,     0,     9,     0,     0,     0,     0,   387,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   525,   382,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,   550,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    29,    30,   122,    32,    33,
       0,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,    58,    59,     0,     0,   577,     0,   326,   582,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     0,     0,     0,
       0,     0,   124,    75,    76,    77,     0,     0,     0,    79,
     125,     0,   383,    81,     0,     0,   387,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,   387,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,     0,   266,   387,   387,     0,
       0,   640,     0,     0,     0,   387,   387,     0,     0,   387,
       0,     0,     0,   317,   650,     0,     0,     0,     0,     0,
       0,     0,   652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,  -381,  -381,  -381,  -381,  -381,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   685,   266,
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
      76,    77,     0,   788,    78,    79,    80,     0,     0,    81,
       0,    82,    83,   517,    84,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,   820,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,   853,    19,    20,
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
       0,    82,    83,   620,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
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
      36,    37,    38,    39,   734,    40,     0,    41,     0,    42,
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
       0,    42,   740,     0,    43,     0,     0,     0,    44,    45,
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
       0,    81,     0,    82,    83,   795,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,   858,    42,     0,     0,    43,     0,
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
      78,    79,    80,     0,     0,    81,     0,    82,    83,   872,
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
      83,   875,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,    39,     0,    40,   879,    41,
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
       0,    81,     0,    82,    83,   882,    84,     0,     0,     0,
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
      80,     0,     0,    81,     0,    82,    83,   893,    84,     0,
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
      78,    79,    80,     0,     0,    81,     0,    82,    83,   905,
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
      83,     0,    84,     0,   575,     0,     0,     0,     0,     0,
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
       0,    82,    83,     0,    84,     0,   578,     0,     0,     0,
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
       0,    81,     0,    82,    83,     0,    84,     0,   589,     0,
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
     781,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      84,     0,   821,     0,     0,     0,     0,     0,     0,     0,
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
       0,    79,   125,     0,     0,    81,     0,     0,     0,   651,
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
       0,     0,     0,     0,     0,   242,   566,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
       0,   266,     0,     0,   239,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     242,   789,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   644,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   266,   239,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   726,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   790,   243,
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
       0,   242,   657,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,   266,   239,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   856,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,     0,
       0,     0,     0,     0,   877,     0,     0,     0,     0,     0,
       0,     0,   242,   302,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,     0,   266,     0,
       0,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,   242,   551,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   240,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,   572,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,     0,   266,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,     0,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     241,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,     0,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   242,
     266,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,     0,   266,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,     0,
     266,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,     0,   266,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,     0,   266
};

static const yytype_int16 yycheck[] =
{
       2,   126,    25,   505,   238,    25,   312,    49,   266,    14,
      15,   335,    25,   382,     2,   217,   477,   705,     2,     2,
      25,   710,     8,   176,    77,   349,     8,     8,    26,     8,
       8,     8,     8,     8,     8,   195,   538,     8,    80,     8,
      32,     8,     8,    65,    75,     8,   634,    52,    65,   283,
      95,   285,    54,   107,    38,   161,    65,   161,    95,    66,
     147,    65,    26,   752,   298,   299,   153,    75,    75,    74,
      77,    77,    77,    32,   308,    75,     0,   311,   312,   153,
     161,    75,   207,    77,   237,    77,   282,   147,    26,   163,
     164,    32,   461,   153,   463,   115,    32,   103,    53,    54,
     147,   161,    70,    71,   111,   159,   153,   160,   153,    14,
      15,    98,    99,   309,   161,    75,   153,    75,    77,    77,
      65,   123,   161,   711,    75,   147,    77,    65,    77,   161,
     161,   284,    75,   286,    77,   140,    77,   290,   291,   292,
     182,    77,   164,   150,    49,   153,   153,   164,    75,   169,
      77,   156,   161,   153,   161,   164,   161,   481,    65,   166,
     164,   485,   486,   487,   164,   163,   368,   389,   160,   391,
      14,    15,   166,   369,    75,    80,   162,   865,   165,   767,
     162,    25,   163,   164,   163,   163,   163,   163,   163,   163,
     150,   162,   197,   153,   163,   162,   162,   202,   659,   162,
     164,   160,   147,    75,   528,   210,   211,   212,   166,   214,
     899,   216,   164,   164,    77,   166,   161,   166,   238,   164,
      81,    77,   161,   166,   226,   238,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   147,   166,
     161,   593,   161,   266,   153,   122,   266,    75,    75,    77,
      77,   156,   161,   266,    75,   335,   153,    98,    99,   161,
     153,   266,   122,   283,   161,   285,    53,    54,   161,   349,
     283,   161,   285,   153,    32,   161,   600,   182,   298,   299,
     141,   161,   651,   111,   111,   298,   299,   611,   308,    75,
     295,   311,   312,   161,   552,   308,   147,   202,   311,   312,
     128,   306,   153,   166,   161,   210,   211,   212,   161,   214,
     166,   533,   156,    75,   666,    77,   668,    75,   164,    77,
     516,   147,   150,   150,   165,   153,   153,   153,   370,   150,
     335,    75,   153,   161,   161,    75,   338,   342,   166,   166,
     664,    47,    48,    49,   349,    51,   670,   653,   672,   111,
     163,   547,   548,   111,    97,    98,    99,    32,   202,   555,
     556,   162,   163,   559,   366,    65,   210,   211,   212,   147,
     214,    75,    75,   162,   163,   162,   163,   382,   366,   399,
      70,    71,   366,   366,   389,   161,   391,   889,   150,   394,
     714,   153,   150,   163,   164,   153,    97,    98,    99,   161,
     147,   481,   164,   161,   166,   485,   486,   629,   166,    65,
     563,    14,    15,   126,    65,   575,    65,   723,   578,   653,
      65,    65,   266,   103,   429,   129,   129,   153,    51,   589,
     153,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   167,    66,   769,   150,   150,   528,   153,
     153,   155,   155,   147,   147,   677,   461,     8,   463,   162,
     126,   153,    75,   147,    77,   370,   153,    87,   147,   793,
     692,    53,    54,   797,   479,   480,   481,   382,   802,   161,
     485,   486,   487,    75,    13,   163,   491,   471,    13,   723,
     814,   335,   476,   646,   647,   163,    75,   162,   111,   483,
     505,   506,   103,   508,   162,   349,    75,   512,   513,   162,
     111,   112,   113,   114,   115,   116,   518,   124,   678,   124,
     161,   845,   161,   528,   429,   530,   163,   851,   533,   552,
     518,   611,   552,   538,   518,   518,   167,   150,   382,   552,
     153,   167,     8,    95,    13,   869,    77,   552,   161,    75,
     161,   163,   162,   166,   104,   161,   461,   161,   463,   109,
     162,   111,   112,   113,   114,   115,   116,   117,   162,     8,
      13,   125,    14,    15,   479,   480,   798,   164,   800,   584,
     162,   163,   167,    25,   664,   429,   161,   161,   161,   161,
     670,   162,   672,   161,   161,   600,   601,   167,   162,    75,
     161,   506,   167,   508,   167,   167,   611,   512,   513,   167,
     153,   147,    75,   835,    13,   165,   163,   461,    13,   463,
     625,   781,   162,   162,   629,   153,   164,     8,   633,   162,
       8,   791,    65,   653,   714,   479,   480,   481,    65,   126,
     653,   485,   486,   487,   866,   163,   651,   127,   808,    13,
     163,   163,   812,   655,   127,   660,   658,   167,   818,   664,
       8,   821,   506,   665,   508,   670,   826,   672,   512,   513,
     830,    75,   677,   895,   164,   161,    77,   162,   162,   584,
     805,   163,    13,   104,   528,   162,   109,   692,   109,   769,
     111,   112,   113,   114,   115,   116,   117,   162,   162,   167,
     860,   162,   704,   723,   162,   162,   126,   163,   552,   714,
     723,   162,   162,   793,   156,   162,    75,   797,    26,    77,
     161,    13,   802,    44,    45,    46,    47,    48,    49,   167,
      51,   891,   167,   161,   814,   127,    77,   163,   162,    13,
     584,   163,   902,    13,   165,   163,   651,   731,    75,   751,
     164,   164,    13,   737,   738,   660,   600,    26,   763,   161,
     202,    72,    77,   163,   769,   845,   162,   611,   210,   211,
     212,   851,   214,   164,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    13,    77,   793,   869,
      13,   163,   797,   798,   164,   800,   780,   802,   111,   112,
     113,   114,   115,   116,    95,   165,   163,   651,    95,   814,
     154,   163,   147,    13,    53,    54,   660,    75,   163,    75,
     664,   161,   824,    77,   266,   827,   670,    26,   672,   163,
     835,    75,    75,     8,   162,   342,   506,   606,   606,   585,
     845,   660,   533,   738,   846,   633,   851,   763,   850,   347,
     527,   788,   854,   628,   683,   857,    81,   859,   641,   861,
     599,   866,   835,   600,   869,   202,   512,   773,   215,    -1,
     714,   513,   856,    -1,    -1,    -1,    -1,    -1,    -1,   881,
      -1,    -1,    -1,    -1,   889,    -1,    -1,    -1,    -1,    -1,
     895,    -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,    -1,
      -1,    -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,   163,   769,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    -1,    -1,    -1,
     382,    -1,    44,    45,    -1,    -1,    -1,    37,    -1,   793,
      -1,    -1,    -1,   797,    44,    45,    -1,    -1,   802,    49,
      -1,    51,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
     814,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   845,    -1,    -1,    -1,    -1,    -1,   851,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   461,
      -1,   463,    -1,    -1,    -1,   869,    -1,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,   479,   480,   129,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   506,    -1,   508,    -1,    -1,    -1,
     512,   513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,   173,    -1,   175,   176,    -1,    -1,    -1,
     180,   181,   182,    -1,   184,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
     552,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,   215,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,   227,    -1,   229,
      -1,    -1,   584,    -1,    -1,    -1,    -1,   237,    -1,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,    95,    -1,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    -1,   284,    -1,   286,   287,    -1,    -1,
     290,   291,   292,    -1,    -1,    -1,    -1,    -1,    -1,   651,
      -1,    -1,   302,    -1,   304,    -1,    -1,    -1,   660,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     320,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    53,    54,    -1,    12,    -1,    -1,    -1,    -1,   369,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   383,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,   403,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,    -1,    -1,   475,    -1,   477,   478,    -1,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,    -1,    -1,    -1,   157,
     158,    -1,   160,   161,    -1,    -1,   516,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,   547,   548,    -1,
      -1,   551,    -1,    -1,    -1,   555,   556,    -1,    -1,   559,
      -1,    -1,    -1,   563,   564,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,   618,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,   646,   647,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,   659,
      -1,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    -1,    89,    -1,    91,
      -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,    -1,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,    -1,   743,   156,   157,   158,    -1,    -1,   161,
      -1,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,   777,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    -1,   817,    60,    61,
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
      -1,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
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
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   127,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      11,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    25,
      51,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51
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
     153,   171,   255,   125,   195,   196,   255,   164,   161,   129,
     155,   211,   212,   214,   215,   255,   167,   161,   161,   285,
     269,    26,    66,   273,   162,   161,   161,   167,   269,   161,
     276,   277,   278,    65,   164,   167,   165,   167,   167,   167,
     271,   271,   127,   162,   258,    26,   178,   269,    26,   178,
     206,   246,   269,   273,    32,   198,   273,   263,    75,    26,
     178,   201,    26,   164,   203,   263,   263,   263,   266,   268,
     161,   153,   171,   147,   107,   159,   180,   181,   183,    75,
     165,    13,   211,   185,   163,   273,   292,   293,    13,   217,
     165,   162,   162,   219,   263,   153,   171,   196,   164,     8,
     223,   211,   162,     8,    32,    77,   160,   213,   217,   217,
     269,   256,   217,   217,   165,   217,    65,    65,   274,   287,
     269,    32,   269,   126,   259,   176,   207,   162,   176,   163,
     127,   197,   273,   197,    13,   176,   163,   204,   163,   204,
     127,   167,     8,   267,   266,   171,    75,   161,   164,   181,
     182,   183,   263,   162,   162,   269,   162,   163,   171,   223,
     255,   104,   109,   111,   112,   113,   114,   115,   116,   117,
     165,   224,   226,   239,   240,   241,   242,   244,   162,   109,
     251,   214,   213,    77,    13,   162,   162,   261,   162,   162,
     162,   287,   287,   126,   275,   167,   165,   271,   288,   208,
      70,    71,   209,   163,    88,   246,   198,   162,   162,   263,
      94,   204,    97,    98,    99,   204,   165,   263,   263,   162,
     255,   176,   251,   165,    75,   227,   255,    77,   243,   250,
     242,     8,   163,    26,   216,   161,   216,    32,   213,    13,
     263,   167,   167,   288,    70,    71,   210,   161,   178,   163,
     162,    26,   178,   200,   200,   163,    97,   163,   269,    26,
     163,   205,   165,   127,    77,   165,   216,    13,     8,   163,
     164,   228,    13,     8,   163,   225,    75,   215,   164,    32,
      77,   252,   164,   213,    13,   263,   278,   161,    26,    72,
     269,    26,   178,   199,   176,   163,   205,   176,   263,   162,
     164,   263,   255,    75,   229,   230,   231,   232,   234,   235,
     236,   255,   263,    77,   188,    13,   176,    77,     8,   162,
     176,    13,   263,   269,   176,   163,   162,   176,    92,   176,
     164,   176,   165,   231,   163,    95,   154,   163,   147,    13,
      75,   263,   165,    32,    77,   165,   263,   162,   178,    90,
     163,   176,   165,   237,   242,   233,   255,    75,   263,   161,
      77,    26,   163,   165,    75,     8,   211,   176,   255,   162,
     216,   163,   164,   238,   176,   165
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
     212,   212,   212,   212,   213,   213,   214,   214,   215,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   219,
     220,   220,   221,   221,   221,   222,   222,   222,   222,   223,
     223,   224,   224,   224,   225,   224,   226,   227,   227,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   233,   233,
     234,   234,   235,   236,   236,   237,   237,   238,   238,   239,
     239,   240,   240,   241,   241,   242,   242,   242,   242,   242,
     242,   243,   243,   243,   243,   244,   244,   245,   245,   246,
     246,   247,   247,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   249,   249,   249,   249,
     250,   251,   251,   252,   252,   252,   252,   253,   253,   253,
     253,   253,   253,   253,   253,   254,   254,   254,   254,   255,
     255,   255,   256,   256,   257,   257,   258,   258,   259,   260,
     260,   260,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   264,   265,   265,   265,   265,
     265,   265,   266,   266,   267,   267,   268,   268,   268,   268,
     269,   269,   270,   271,   272,   273,   273,   274,   274,   275,
     276,   276,   277,   278,   278,   278,   279,   279,   280,   280,
     281,   282,   282,   283,   283,   283,   284,   284,   284,   284,
     285,   285,   285,   286,   286,   287,   287,   288,   288,   289,
     289,   289,   290,   290,   291,   291,   292,   292,   293,   293,
     293,   294,   294,   295,   295,   295,   295,   295,   295,   295,
     295,   296,   296,   296,   296,   296,   296,   296,   297,   297,
     298,   298,   299,   299,   299,   299,   299,   300,   300,   301,
     302,   302
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
       4,     5,     7,     6,     2,     1,     0,     1,     1,     1,
       1,     0,     2,     1,     0,     1,     3,     1,     2,     2,
       3,     1,     1,     2,     4,     3,     5,     1,     3,     2,
       0,     3,     2,     1,     0,    10,     3,     1,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     3,     1,     3,
       1,     1,     3,     4,     3,     0,     1,     1,     3,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     3,     5,     4,     3,     1,     0,
       1,     3,     1,     6,     3,     4,     6,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     5,     4,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     1,    10,    11,     2,     2,     4,     4,
       1,     0,     4,     3,     4,     1,     2,     4,     6,     5,
       6,     6,     6,     6,     4,     1,     1,     3,     2,     1,
       3,     2,     1,     1,     4,     1,     2,     0,     2,     0,
       2,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     2,     4,     3,     1,     3,     1,     1,     1,     3,
       2,     1,     0,     2,     0,     1,     5,     3,     3,     1,
       1,     1,     1,     1,     1,     5,     1,     2,     0,     3,
       4,     4,     3,     1,     1,     0,     1,     2,     3,     3,
       1,     4,     4,     1,     1,     1,     1,     3,     2,     1,
       4,     4,     1,     1,     4,     0,     1,     1,     1,     4,
       4,     1,     1,     3,     1,     2,     3,     1,     1,     4,
       0,     0,     2,     5,     3,     3,     1,     6,     4,     4,
       2,     4,     4,     2,     2,     4,     2,     2,     1,     3,
       3,     3,     4,     4,     4,     4,     4,     4,     3,     3,
       3,     3
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
#line 1073 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4708 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1076 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4716 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1079 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4724 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1085 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4732 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1088 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4740 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1095 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
#line 4748 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1101 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4756 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1104 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4764 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1111 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNPACK)->appendChild((yyvsp[-1]));
  }
#line 4772 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1114 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4781 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1121 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4790 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1125 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4799 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1132 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4807 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1135 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4816 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1139 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-3]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 4825 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1146 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 4838 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1154 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4851 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1162 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4864 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1170 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4877 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1181 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4885 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1184 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4893 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1190 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4906 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1198 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4915 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1202 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4923 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1205 "parser.y" /* yacc.c:1646  */
    {
    /* empty */
  }
#line 4931 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1207 "parser.y" /* yacc.c:1646  */
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
#line 4949 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1223 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-2]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4959 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1231 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[0]));
  }
#line 4967 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1234 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4975 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1240 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4983 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1243 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4991 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1249 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
#line 4999 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1252 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5007 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1258 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5016 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1262 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 5025 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1269 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5033 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1272 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5041 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1278 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5051 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1286 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5060 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1290 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 5069 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1297 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5078 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1301 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5086 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1307 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[-2]), (yyvsp[-1]), NTYPE((yyvsp[0]), n_STRING));
    (yyval) = (yyvsp[-1]);
  }
#line 5096 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1315 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5107 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1321 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 5118 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1330 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5126 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1333 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5135 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1341 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5143 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1344 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5151 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1351 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5160 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1358 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
#line 5168 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1361 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[0]);
  }
#line 5177 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1368 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5186 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1372 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5194 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1387 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 5206 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1394 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 5218 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1401 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5230 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1408 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5242 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1418 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));

    (yyval) = (yyvsp[-4]);
  }
#line 5256 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1427 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyvsp[-3])->appendChild((yyval));

    (yyval) = (yyvsp[-3]);
  }
#line 5270 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1439 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5278 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1442 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5287 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1449 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5295 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1457 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5303 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1460 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5312 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1467 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_LIST);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5325 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1475 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5336 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1481 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));

    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));

    (yyval)->appendChild((yyvsp[-1]));
  }
#line 5351 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1491 "parser.y" /* yacc.c:1646  */
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
#line 5370 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1505 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5380 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1510 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5391 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1516 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5402 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1522 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5413 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1528 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5424 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1534 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5435 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1540 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5446 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1546 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5457 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1552 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5468 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1558 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5479 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1564 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5490 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1570 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5501 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1576 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5511 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1581 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5521 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1586 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5531 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1591 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5541 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1596 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5552 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1602 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5563 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1608 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5574 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1614 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5585 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1620 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5596 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1626 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5607 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1632 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5618 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1638 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5629 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1644 "parser.y" /* yacc.c:1646  */
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
#line 5660 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1670 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5671 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1676 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5682 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1682 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5693 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1688 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5704 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1694 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5715 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1700 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5726 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1706 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5737 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1712 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
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
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5788 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1738 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5799 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1744 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5810 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1750 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5821 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1756 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5832 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1762 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5843 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1768 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5854 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1774 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5865 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1780 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5876 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1786 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5887 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1794 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5900 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1802 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5913 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1810 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5924 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1817 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
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
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
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
    NTYPE((yyvsp[0]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[0]);
  }
#line 6023 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1869 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6033 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1874 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[0]);
  }
#line 6044 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1883 "parser.y" /* yacc.c:1646  */
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
#line 6061 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1898 "parser.y" /* yacc.c:1646  */
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
#line 6084 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1919 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6095 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1925 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6106 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1931 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6117 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1937 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6128 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1950 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1953 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[-3])->appendChildren((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6146 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1961 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6154 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1964 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 6164 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1969 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6173 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1973 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 6184 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1982 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6194 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1988 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-5]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6205 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1994 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-4]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6216 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 2001 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6229 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 2010 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6242 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 2019 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6255 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 2028 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6268 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 2036 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6278 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2044 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6286 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 2047 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6294 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 2050 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6303 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 2054 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6312 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 2061 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6320 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 2064 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6329 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2068 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6338 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 2083 "parser.y" /* yacc.c:1646  */
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
#line 6355 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 2099 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 6363 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2102 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6371 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2108 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6379 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2114 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6387 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2117 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-1]), n_EMPTY, (yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6396 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2121 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 6406 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2129 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6414 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2132 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6422 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2138 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6430 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2141 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6438 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2144 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_STRING_SCALAR);
  }
#line 6446 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2147 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6454 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2150 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6462 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2153 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6470 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2156 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6478 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2159 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6486 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2162 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6494 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2165 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6502 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2168 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6510 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2171 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_HEREDOC);
  }
#line 6518 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 2179 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = (yyvsp[0]);
  }
#line 6527 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2183 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = (yyvsp[0]);
  }
#line 6536 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 2187 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
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
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 6566 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2202 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 6576 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 2211 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 6586 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 2222 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-2]));
  }
#line 6594 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2225 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-1]));
  }
#line 6602 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2232 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6610 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2235 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6618 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2241 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6626 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 2252 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6638 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 2259 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6650 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 2266 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6662 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2273 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6674 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2303 "parser.y" /* yacc.c:1646  */
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
#line 6702 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2330 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChildren((yyvsp[0]));
  }
#line 6710 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2333 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6718 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2339 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[-1]));
    if ((yyvsp[0])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[0]));
    }
  }
#line 6730 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2349 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6741 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2355 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6752 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2364 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6760 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2372 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6768 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2379 "parser.y" /* yacc.c:1646  */
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
#line 6785 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2394 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
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

  case 381:
#line 2411 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6816 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2417 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6827 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2433 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6835 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2436 "parser.y" /* yacc.c:1646  */
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
#line 6852 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2452 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6863 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2458 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6874 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2468 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 6882 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2471 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-3]), n_VARIABLE_EXPRESSION, (yyvsp[0]));
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6892 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2479 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6900 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2482 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6908 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2493 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6919 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2499 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6930 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2509 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_STRING);
    (yyval) = (yyvsp[0]);
  }
#line 6939 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2513 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6947 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2519 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);
  }
#line 6955 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2522 "parser.y" /* yacc.c:1646  */
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
#line 6972 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2537 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 6980 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2540 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6989 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2548 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6998 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2552 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 7006 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2558 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 7014 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2561 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 7022 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2567 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 7034 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2574 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 7046 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2581 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7058 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2588 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7070 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2595 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 7082 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2602 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 7094 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2609 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7106 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2616 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7118 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2626 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7133 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2636 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7148 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2646 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7156 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2649 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7164 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2652 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7179 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2662 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7187 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2665 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7195 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2671 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7204 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2675 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7212 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2681 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 7222 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2686 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 7230 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2692 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7241 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2698 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7252 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2704 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7263 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2710 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7274 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2716 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7285 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2725 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 7295 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2730 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 7305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 2738 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 7316 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2747 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
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


#line 7340 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 2759 "parser.y" /* yacc.c:1906  */


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
/* @generated */
