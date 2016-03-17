/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
    T_BOOLEAN_OR = 278,
    T_BOOLEAN_AND = 279,
    T_IS_EQUAL = 280,
    T_IS_NOT_EQUAL = 281,
    T_IS_IDENTICAL = 282,
    T_IS_NOT_IDENTICAL = 283,
    T_IS_SMALLER_OR_EQUAL = 284,
    T_IS_GREATER_OR_EQUAL = 285,
    T_SL = 286,
    T_SR = 287,
    T_INSTANCEOF = 288,
    T_INC = 289,
    T_DEC = 290,
    T_INT_CAST = 291,
    T_DOUBLE_CAST = 292,
    T_STRING_CAST = 293,
    T_UNICODE_CAST = 294,
    T_BINARY_CAST = 295,
    T_ARRAY_CAST = 296,
    T_OBJECT_CAST = 297,
    T_BOOL_CAST = 298,
    T_UNSET_CAST = 299,
    T_NEW = 300,
    T_CLONE = 301,
    T_EXIT = 302,
    T_IF = 303,
    T_ELSEIF = 304,
    T_ELSE = 305,
    T_ENDIF = 306,
    T_LNUMBER = 307,
    T_DNUMBER = 308,
    T_STRING = 309,
    T_STRING_VARNAME = 310,
    T_VARIABLE = 311,
    T_NUM_STRING = 312,
    T_INLINE_HTML = 313,
    T_CHARACTER = 314,
    T_BAD_CHARACTER = 315,
    T_ENCAPSED_AND_WHITESPACE = 316,
    T_CONSTANT_ENCAPSED_STRING = 317,
    T_BACKTICKS_EXPR = 318,
    T_ECHO = 319,
    T_DO = 320,
    T_WHILE = 321,
    T_ENDWHILE = 322,
    T_FOR = 323,
    T_ENDFOR = 324,
    T_FOREACH = 325,
    T_ENDFOREACH = 326,
    T_DECLARE = 327,
    T_ENDDECLARE = 328,
    T_AS = 329,
    T_SWITCH = 330,
    T_ENDSWITCH = 331,
    T_CASE = 332,
    T_DEFAULT = 333,
    T_BREAK = 334,
    T_CONTINUE = 335,
    T_GOTO = 336,
    T_FUNCTION = 337,
    T_CONST = 338,
    T_RETURN = 339,
    T_TRY = 340,
    T_CATCH = 341,
    T_THROW = 342,
    T_USE = 343,
    T_GLOBAL = 344,
    T_STATIC = 345,
    T_ABSTRACT = 346,
    T_FINAL = 347,
    T_PRIVATE = 348,
    T_PROTECTED = 349,
    T_PUBLIC = 350,
    T_VAR = 351,
    T_UNSET = 352,
    T_ISSET = 353,
    T_EMPTY = 354,
    T_HALT_COMPILER = 355,
    T_CLASS = 356,
    T_INTERFACE = 357,
    T_EXTENDS = 358,
    T_IMPLEMENTS = 359,
    T_OBJECT_OPERATOR = 360,
    T_DOUBLE_ARROW = 361,
    T_LIST = 362,
    T_ARRAY = 363,
    T_CLASS_C = 364,
    T_METHOD_C = 365,
    T_FUNC_C = 366,
    T_LINE = 367,
    T_FILE = 368,
    T_COMMENT = 369,
    T_DOC_COMMENT = 370,
    T_OPEN_TAG = 371,
    T_OPEN_TAG_WITH_ECHO = 372,
    T_OPEN_TAG_FAKE = 373,
    T_CLOSE_TAG = 374,
    T_WHITESPACE = 375,
    T_START_HEREDOC = 376,
    T_END_HEREDOC = 377,
    T_HEREDOC = 378,
    T_DOLLAR_OPEN_CURLY_BRACES = 379,
    T_CURLY_OPEN = 380,
    T_PAAMAYIM_NEKUDOTAYIM = 381,
    T_BINARY_DOUBLE = 382,
    T_BINARY_HEREDOC = 383,
    T_NAMESPACE = 384,
    T_NS_C = 385,
    T_DIR = 386,
    T_NS_SEPARATOR = 387,
    T_INSTEADOF = 388,
    T_CALLABLE = 389,
    T_TRAIT = 390,
    T_TRAIT_C = 391,
    T_YIELD = 392,
    T_FINALLY = 393
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

#line 316 "parser.yacc.cpp" /* yacc.c:358  */

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
#define YYLAST   7669

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  433
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  886

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   393

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,   163,    47,    31,     2,
     158,   159,    45,    42,     8,    43,    44,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   160,
      36,    13,    38,    25,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,   164,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   161,    29,   162,    50,     2,     2,     2,
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
      32,    33,    34,    35,    37,    39,    40,    41,    49,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   207,   207,   213,   216,   222,   225,   231,   232,   233,
     234,   239,   246,   252,   260,   265,   272,   275,   282,   287,
     293,   299,   309,   316,   326,   329,   335,   336,   337,   338,
     346,   347,   353,   356,   359,   365,   368,   398,   417,   424,
     432,   445,   452,   459,   466,   473,   480,   487,   494,   501,
     506,   511,   516,   520,   524,   528,   534,   552,   569,   575,
     579,   588,   597,   605,   616,   620,   626,   638,   641,   645,
     654,   658,   665,   669,   673,   677,   680,   686,   701,   713,
     728,   732,   739,   746,   753,   756,   762,   766,   769,   777,
     780,   788,   791,   797,   800,   806,   807,   815,   816,   824,
     825,   833,   834,   842,   848,   859,   862,   872,   877,   889,
     892,   900,   910,   911,   915,   916,   924,   927,   937,   940,
     950,   953,   961,   964,   972,   973,   979,   987,   996,  1005,
    1013,  1021,  1030,  1040,  1052,  1055,  1058,  1061,  1067,  1068,
    1074,  1077,  1080,  1085,  1088,  1091,  1099,  1103,  1110,  1113,
    1117,  1124,  1132,  1140,  1148,  1159,  1162,  1168,  1176,  1180,
    1183,  1183,  1200,  1208,  1211,  1217,  1220,  1226,  1229,  1235,
    1239,  1246,  1249,  1255,  1263,  1267,  1274,  1278,  1284,  1292,
    1298,  1307,  1310,  1318,  1321,  1327,  1328,  1335,  1338,  1345,
    1349,  1355,  1356,  1357,  1358,  1359,  1360,  1364,  1371,  1378,
    1385,  1395,  1404,  1416,  1419,  1426,  1429,  1434,  1437,  1444,
    1452,  1458,  1468,  1482,  1487,  1493,  1499,  1505,  1511,  1517,
    1523,  1529,  1535,  1541,  1547,  1553,  1558,  1563,  1568,  1573,
    1579,  1585,  1591,  1597,  1603,  1609,  1615,  1621,  1647,  1653,
    1659,  1665,  1671,  1677,  1683,  1689,  1694,  1699,  1704,  1709,
    1715,  1721,  1727,  1733,  1739,  1745,  1751,  1757,  1763,  1764,
    1765,  1773,  1781,  1782,  1787,  1792,  1797,  1802,  1807,  1812,
    1817,  1822,  1827,  1831,  1832,  1833,  1834,  1839,  1845,  1859,
    1882,  1888,  1894,  1900,  1909,  1913,  1916,  1924,  1927,  1932,
    1936,  1945,  1950,  1957,  1963,  1972,  1981,  1990,  1999,  2007,
    2010,  2013,  2017,  2024,  2027,  2031,  2038,  2039,  2043,  2058,
    2062,  2065,  2071,  2077,  2080,  2084,  2092,  2095,  2101,  2104,
    2107,  2110,  2113,  2116,  2119,  2122,  2125,  2128,  2131,  2134,
    2140,  2141,  2142,  2146,  2150,  2155,  2160,  2165,  2170,  2174,
    2182,  2183,  2184,  2185,  2188,  2191,  2195,  2198,  2204,  2207,
    2211,  2222,  2229,  2236,  2246,  2247,  2251,  2255,  2259,  2263,
    2289,  2293,  2296,  2302,  2312,  2318,  2327,  2333,  2334,  2335,
    2341,  2342,  2357,  2362,  2370,  2374,  2380,  2389,  2390,  2391,
    2395,  2396,  2399,  2411,  2415,  2421,  2427,  2431,  2434,  2442,
    2445,  2451,  2452,  2456,  2462,  2468,  2472,  2476,  2482,  2485,
    2500,  2503,  2510,  2511,  2515,  2521,  2524,  2530,  2537,  2544,
    2551,  2558,  2565,  2572,  2579,  2589,  2599,  2609,  2612,  2615,
    2625,  2628,  2634,  2638,  2644,  2649,  2655,  2661,  2667,  2676,
    2681,  2689,  2698,  2703
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
  "'?'", "':'", "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'", "'^'", "'&'",
  "T_IS_EQUAL", "T_IS_NOT_EQUAL", "T_IS_IDENTICAL", "T_IS_NOT_IDENTICAL",
  "'<'", "T_IS_SMALLER_OR_EQUAL", "'>'", "T_IS_GREATER_OR_EQUAL", "T_SL",
  "T_SR", "'+'", "'-'", "'.'", "'*'", "'/'", "'%'", "'!'", "T_INSTANCEOF",
  "'~'", "T_INC", "T_DEC", "T_INT_CAST", "T_DOUBLE_CAST", "T_STRING_CAST",
  "T_UNICODE_CAST", "T_BINARY_CAST", "T_ARRAY_CAST", "T_OBJECT_CAST",
  "T_BOOL_CAST", "T_UNSET_CAST", "'@'", "'['", "T_NEW", "T_CLONE",
  "T_EXIT", "T_IF", "T_ELSEIF", "T_ELSE", "T_ENDIF", "T_LNUMBER",
  "T_DNUMBER", "T_STRING", "T_STRING_VARNAME", "T_VARIABLE",
  "T_NUM_STRING", "T_INLINE_HTML", "T_CHARACTER", "T_BAD_CHARACTER",
  "T_ENCAPSED_AND_WHITESPACE", "T_CONSTANT_ENCAPSED_STRING",
  "T_BACKTICKS_EXPR", "T_ECHO", "T_DO", "T_WHILE", "T_ENDWHILE", "T_FOR",
  "T_ENDFOR", "T_FOREACH", "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE",
  "T_AS", "T_SWITCH", "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK",
  "T_CONTINUE", "T_GOTO", "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY",
  "T_CATCH", "T_THROW", "T_USE", "T_GLOBAL", "T_STATIC", "T_ABSTRACT",
  "T_FINAL", "T_PRIVATE", "T_PROTECTED", "T_PUBLIC", "T_VAR", "T_UNSET",
  "T_ISSET", "T_EMPTY", "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE",
  "T_EXTENDS", "T_IMPLEMENTS", "T_OBJECT_OPERATOR", "T_DOUBLE_ARROW",
  "T_LIST", "T_ARRAY", "T_CLASS_C", "T_METHOD_C", "T_FUNC_C", "T_LINE",
  "T_FILE", "T_COMMENT", "T_DOC_COMMENT", "T_OPEN_TAG",
  "T_OPEN_TAG_WITH_ECHO", "T_OPEN_TAG_FAKE", "T_CLOSE_TAG", "T_WHITESPACE",
  "T_START_HEREDOC", "T_END_HEREDOC", "T_HEREDOC",
  "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN", "T_PAAMAYIM_NEKUDOTAYIM",
  "T_BINARY_DOUBLE", "T_BINARY_HEREDOC", "T_NAMESPACE", "T_NS_C", "T_DIR",
  "T_NS_SEPARATOR", "T_INSTEADOF", "T_CALLABLE", "T_TRAIT", "T_TRAIT_C",
  "T_YIELD", "T_FINALLY", "'('", "')'", "';'", "'{'", "'}'", "'$'", "']'",
  "$accept", "start", "top_statement_list", "namespace_name",
  "top_statement", "use_declarations", "use_declaration",
  "constant_declaration", "inner_statement_list", "inner_statement",
  "statement", "unticked_statement", "catch_list", "catch",
  "finally_statement", "non_empty_finally_statement", "unset_variables",
  "unset_variable", "function_declaration_statement",
  "class_declaration_statement", "is_reference",
  "unticked_function_declaration_statement",
  "unticked_class_declaration_statement", "class_entry_type",
  "extends_from", "interface_entry", "interface_extends_list",
  "implements_list", "interface_list", "foreach_optional_arg",
  "foreach_variable", "for_statement", "foreach_statement",
  "declare_statement", "declare_list", "switch_case_list", "case_list",
  "case_separator", "while_statement", "elseif_list", "new_elseif_list",
  "else_single", "new_else_single", "parameter_list",
  "non_empty_parameter_list", "optional_class_type",
  "function_call_parameter_list", "non_empty_function_call_parameter_list",
  "global_var_list", "global_var", "static_var_list",
  "class_statement_list", "class_statement", "$@1", "trait_use_statement",
  "trait_list", "trait_adaptations", "trait_adaptation_list",
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
     273,   274,   275,   276,   277,    63,    58,   278,   279,   124,
      94,    38,   280,   281,   282,   283,    60,   284,    62,   285,
     286,   287,    43,    45,    46,    42,    47,    37,    33,   288,
     126,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    64,    91,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,    40,    41,
      59,   123,   125,    36,    93
};
# endif

#define YYPACT_NINF -678

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-678)))

#define YYTABLE_NINF -375

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-375)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -678,    83,  1979,  -678,  6351,  6351,   -54,  6351,  6351,  6351,
    6351,  6351,  6351,  6351,   403,   403,  6351,  6351,  6351,  6351,
    6351,  6351,  6351,  6351,  4779,   463,  6351,   -38,     7,  -678,
    -678,   119,  -678,  -678,  -678,    90,  -678,  6351,  4639,    18,
      39,    48,    52,    63,  4910,  5041,    88,  -678,   145,  5172,
      73,  6351,   -10,   -27,   -15,   134,   159,   116,   125,   140,
     153,  -678,  -678,   157,   164,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,     9,  -678,  -678,   240,  -678,  -678,
    6351,  6482,  -678,  -678,   171,    57,  -678,    11,  -678,  -678,
    -678,  -678,  -678,  -678,   277,   279,  -678,   194,   324,   296,
     212,  -678,  -678,  1406,  -678,   178,   904,   202,  -678,   219,
     307,   249,  -678,   -28,  -678,    -7,  -678,  -678,   311,   315,
    -678,  -678,  -678,   280,   229,  -678,   324,  7497,  7497,  6351,
    7497,  7497,  7597,  -678,  -678,   353,  -678,  -678,   254,   240,
     342,   -74,   265,  -678,  -678,   266,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,   403,  7297,   248,   406,   268,
     240,   269,   271,   263,  -678,   272,   298,   -14,    -7,  -678,
    5303,  -678,  6351,  -678,  6351,    13,  7497,   344,  6351,  6351,
    6351,   364,  6351,  -678,  6804,  -678,  6845,   278,   426,  -678,
     281,  7497,   686,  -678,  6897,   240,   -23,    19,  -678,  -678,
     205,    20,  -678,   429,    21,   324,  -678,  -678,   403,   403,
     403,   286,   292,  4779,   240,  -678,    95,   102,    89,  7339,
     703,   293,  1620,   295,  2119,  6351,   374,  5434,   380,  -678,
     334,   335,  -678,  -678,   -31,  6351,     0,  6351,  6351,  6351,
    5565,  6351,  6351,  6351,  6351,  6351,  6351,  6351,  6351,  6351,
    6351,  6351,  6351,  6351,  6351,  6351,  6351,  6351,  6351,  6351,
    6351,  6351,   463,  -678,  -678,  -678,  5696,  6351,  6351,  6351,
    6351,  6351,  6351,  6351,  6351,  6351,  6351,  6351,  5434,     3,
    6351,    -9,  6351,  6351,   171,   -39,  6351,  6351,   300,  6938,
     240,   115,   295,    15,    51,  -678,  -678,  5827,  -678,  5958,
    -678,   240,   269,    -4,  5434,  -678,    -4,    -9,   -24,  -678,
    6979,  7031,  7497,   297,  6351,  -678,   301,  7073,   302,   458,
    7497,   375,   891,   454,    25,  7114,  -678,  -678,  -678,  1234,
    -678,  -678,  2259,  -678,   -19,   400,   -10,  -678,  6351,  -678,
    -678,   -27,  -678,  1234,   399,  -678,   321,    26,  -678,  -678,
    -678,    28,   326,   320,   325,  -678,    29,  -678,   327,   154,
    1699,  -678,  -678,  5434,  6351,  -678,  -678,  -678,   329,  -678,
    -678,  -678,  -678,  -678,   979,  -678,   403,   339,   485,    30,
      92,   488,    50,   384,    50,   349,   356,    85,   351,   360,
     362,   -24,    -7,  7537,  7574,  7597,  6351,  7440,  1501,  1689,
    4832,  1119,  1652,  1831,  1831,  1831,  1831,  1967,  1967,  1967,
    1967,   497,   497,   288,   288,   288,   353,   353,   353,  -678,
     188,  7597,  7597,  7597,  7597,  7597,  7597,  7597,  7597,  7597,
    7597,  7597,  7597,   365,   367,   371,   366,  -678,  6351,  -678,
     373,   -13,  -678,   381,  1022,   383,   385,  -678,   117,   360,
     367,   403,  7497,   403,  7398,   269,  -678,   378,  -678,  -678,
    -678,  3939,  -678,  7497,  6351,  4079,  6351,  6351,   403,    65,
    1234,   475,  4219,     6,  1234,  1234,  1234,  -678,   394,   402,
     240,   155,   410,  -678,  -678,  -678,    -8,   489,  -678,  -678,
    6625,  -678,  -678,   545,    85,   403,   404,   403,  -678,  -678,
    -678,   292,   292,   550,  -678,  5434,  -678,  1839,   408,   111,
    1318,   409,  -678,  -678,  -678,  6089,  1234,   418,   240,   269,
    -678,    50,   412,   570,  -678,  -678,    85,  -678,  -678,   424,
     577,    24,  -678,  -678,  5434,  5434,   -24,  7620,  6351,   463,
    -678,  -678,  5434,  5434,  -678,  6666,  5434,   523,   527,  -678,
    6351,  6351,  -678,  -678,  -678,  -678,  -678,  -678,  6220,  -678,
     476,  -678,  -678,  7164,  -678,  -678,  -678,   439,  7497,   477,
     403,   477,  -678,  -678,   590,  -678,  -678,  -678,   445,   446,
    -678,  -678,  -678,   482,   451,   601,  1234,   240,   156,   546,
     462,   464,    -8,  -678,  -678,  -678,  -678,  1234,   465,  -678,
    -678,  -678,    32,  -678,  6351,   469,  -678,  -678,   470,   403,
      33,   376,  -678,   240,   269,   570,  -678,    50,   706,   472,
     522,    84,   558,   621,   479,   487,  7620,   263,   491,   495,
    -678,   496,  6351,  6351,   511,   480,  6707,   403,  7497,    -9,
    -678,  3799,   234,   483,  2399,  6351,    65,   498,  -678,   500,
    1234,  2539,  -678,   245,  -678,   103,  1234,  -678,  1234,  -678,
     501,   165,  -678,    50,  -678,  -678,  -678,  -678,  -678,   522,
    -678,  7597,  -678,  -678,  -678,   269,   783,  -678,   563,    50,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
     572,   280,   322,  -678,    22,   502,   490,   503,    54,   643,
    1234,  -678,  -678,  -678,  -678,  -678,  -678,   505,   507,    -9,
    -678,  -678,  -678,  -678,  -678,   259,   504,  4639,  -678,  -678,
     512,   506,  -678,  4359,  4359,  -678,   513,   290,   515,  6351,
      36,   130,  -678,  -678,   536,  -678,   592,  2679,   517,  -678,
     663,     8,  -678,   666,    23,  -678,  -678,   608,  -678,  -678,
      60,  -678,   607,   670,  1234,  -678,  -678,  -678,   373,   526,
     659,   616,  6351,  -678,  -678,  4499,  -678,  -678,  -678,  -678,
    -678,   528,  -678,  6763,  -678,  -678,  -678,  -678,  1234,   532,
    -678,  -678,  1234,    50,  -678,    69,  -678,  1234,   618,  -678,
     324,   681,  2819,   636,  -678,    35,  2959,   683,  1234,  -678,
    -678,  6351,  -678,   552,  7206,  -678,  -678,  -678,  3099,  -678,
    -678,  3799,  -678,   554,  3239,  -678,  -678,   620,   566,    69,
    -678,   569,   637,   579,   574,   587,  -678,   723,   668,  1234,
    -678,  -678,    64,  -678,  -678,  1234,  -678,  7247,  3799,  -678,
    4639,  3379,   582,  3799,  -678,  -678,  -678,  -678,  -678,   484,
      50,  -678,   671,  1234,   585,  -678,   673,  -678,  -678,   720,
    -678,   593,  -678,  3519,   677,   679,   748,  -678,  -678,  -678,
      85,  -678,  -678,  -678,  -678,  -678,    50,   599,  3799,  -678,
     184,  -678,  -678,  -678,  3659,  -678
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,     0,     0,   313,     0,   318,
     319,     5,   340,   387,    52,   320,   272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,    80,    86,     0,     0,   324,   325,   327,   321,   322,
      32,    33,    34,   329,     0,   328,   323,     0,    83,   326,
     277,     0,    59,    25,   398,   342,     3,     0,     7,    30,
       8,     9,    73,    74,     0,     0,   355,     0,    75,   379,
       0,   345,   273,     0,   354,     0,   356,     0,   383,     0,
     378,   360,   377,   380,   386,     0,   262,   258,   274,   275,
     259,   341,     5,   299,     0,   277,    75,   417,   418,     0,
     420,   421,   276,   245,   246,   247,   248,   299,     0,     0,
       0,   300,     0,   226,   358,     0,   228,   263,   264,   265,
     266,   267,   268,   269,   271,     0,   410,     0,   348,     0,
       0,   300,   306,   316,   307,     0,   309,   380,     0,   213,
       0,   270,     0,    31,   389,     0,   204,     0,     0,   205,
       0,     0,     0,    42,     0,    44,     0,     0,     0,    46,
     355,     0,   356,    25,     0,     0,    18,     0,    17,   148,
       0,     0,   147,   153,     0,    75,    81,    82,     0,     0,
       0,     0,   404,   405,     0,     4,     0,   344,   355,     0,
     356,     0,     0,   259,     0,     0,     0,   139,     0,    15,
      84,    87,    54,    76,     0,   389,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,   225,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
     389,     0,   389,     0,   399,   382,   389,   389,     0,     0,
       0,   302,     0,     0,     0,   414,   357,     0,   430,   349,
     406,     0,   302,     0,   139,   431,     0,     0,   382,   314,
       0,     0,   390,     0,     0,    51,     0,     0,     0,   206,
     208,   355,   356,     0,     0,     0,    43,    45,    63,     0,
      47,    48,     0,    62,    20,     0,     0,    14,     0,   149,
     356,     0,    49,     0,     0,    50,     0,     0,    70,    72,
     422,     0,     0,     0,     0,   402,     0,   401,     0,   343,
       0,    11,     4,   139,     0,   425,   424,   381,     0,    35,
      24,    26,    27,    28,     0,     6,     0,     0,   138,   355,
     356,     0,     0,    89,     0,     0,     0,   134,     0,   432,
     372,   370,     0,   231,   233,   232,     0,     0,   229,   230,
     234,   236,   235,   251,   252,   249,   250,   253,   254,   255,
     256,   243,   244,   238,   239,   237,   240,   241,   242,   257,
       0,   210,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,   433,   373,     0,   396,     0,   392,
     369,   391,   395,     0,     0,     0,     0,   419,   301,     0,
       0,     0,   409,     0,   408,   301,   372,     0,   373,   311,
     315,     0,   428,   203,     0,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   346,   320,     0,     0,
       0,   331,     0,   330,    23,   338,     0,     0,    19,    16,
       0,   146,   154,   151,   134,     0,     0,     0,   415,   416,
      10,   404,   404,     0,   429,   139,    13,     0,     0,   355,
     356,     0,   388,   142,   291,     0,     0,     0,     0,   303,
      85,     0,     0,    88,    91,   156,   134,   136,   137,     0,
     124,     0,   135,   376,   139,   139,   371,   261,     0,     0,
     211,   298,   139,   139,   375,     0,   139,   368,   367,   362,
     389,     0,   384,   385,   427,   426,   413,   412,     0,   317,
     308,    25,   116,     0,    25,   114,    38,     0,   207,    93,
       0,    93,    95,   103,     0,    25,   101,    58,   109,   109,
      41,   334,   335,   353,     0,   348,   346,     0,   333,     0,
       0,     0,    67,    65,    61,    21,   150,     0,     0,    71,
      55,   423,     0,   400,     0,     0,    12,   293,     0,     0,
     355,   356,    22,     0,   305,    90,   156,     0,   187,     0,
     285,   134,     0,   126,     0,     0,   260,   316,     0,     0,
     397,     0,   389,   389,   359,     0,     0,     0,   407,     0,
     310,   118,   120,     0,     0,   205,     0,     0,    96,     0,
       0,     0,   109,     0,   109,     0,     0,   337,   349,   347,
       0,   332,   339,     0,    25,    64,    60,    68,   152,   285,
     403,   209,   292,    29,   145,   304,   187,    92,     0,     0,
     194,   195,   196,   193,   192,   191,   186,    79,   155,   159,
       0,     0,   185,   189,     0,     0,     0,     0,     0,   127,
       0,   294,   297,   212,   295,   296,   366,     0,     0,     0,
     361,   393,   394,   411,   312,   122,     0,     0,    36,    39,
       0,     0,    94,     0,     0,   104,     0,     0,     0,     0,
       0,     0,   105,   352,   351,   336,     0,     0,     0,    78,
       0,     0,   163,   199,     0,   160,   190,     0,   158,    25,
       0,    25,     0,   130,     0,   129,   364,   365,   369,     0,
       0,     0,     0,   121,   115,     0,    25,    99,    57,    56,
     102,     0,   107,     0,   112,   113,    25,   106,     0,     0,
      69,    25,     0,     0,   165,   167,   162,     0,     0,   157,
      75,     0,     0,     0,   289,     0,     0,   131,     0,   128,
     363,     0,    25,     0,     0,    25,    97,    40,     0,   108,
      25,   111,   350,     0,     0,   202,   164,     5,     0,   168,
     169,     0,     0,   177,     0,     0,   200,   197,     0,     0,
      77,   290,     0,   286,   278,     0,   133,     0,   123,    37,
       0,     0,     0,   110,    25,   279,   166,   170,   171,   181,
       0,   172,     0,     0,     0,   201,     0,   287,   132,     0,
     117,     0,   100,     0,     0,   180,   173,   174,   178,   198,
     134,   288,    25,    98,    66,   179,     0,     0,   119,   175,
       0,   183,    25,   161,     0,   184
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -678,  -678,  -198,    -5,  -678,  -678,   425,  -678,  -192,  -678,
      16,  -678,  -678,   168,  -678,   173,  -678,   276,     1,     2,
    -124,  -678,  -678,  -678,  -678,  -678,  -678,  -678,   246,   195,
     126,  -678,    55,  -678,  -678,  -678,  -477,    10,  -678,  -678,
    -678,  -678,  -678,  -482,  -678,   163,  -217,  -678,  -678,   433,
    -678,   160,  -678,  -678,  -678,  -678,  -678,  -678,  -678,   -44,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -677,  -678,  -678,  -678,  -452,  -678,    45,   704,    -2,   118,
    -678,  -678,   294,  -359,  -255,  -678,  -678,  -678,  -678,   161,
     101,   774,  -678,  -678,   200,   207,  -678,   954,   597,  -350,
     333,  1100,  -678,  -678,  -678,  -678,    40,  -214,  -678,    31,
    -678,  -678,   -20,   -17,  -678,  -229,  -296,  -678,  -678,   -12,
     299,   303,   586,  -678,  -678,  -678,  -678,  -678,  -678,   -22,
    -678
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   197,   198,    87,   224,   370,
     371,    89,   592,   593,   666,   594,   347,   348,   372,   373,
     234,    92,    93,    94,   383,    95,   385,   522,   523,   647,
     571,   807,   768,   577,   324,   580,   653,   776,   566,   642,
     715,   718,   761,   529,   530,   531,   377,   378,   201,   202,
     204,   618,   688,   790,   689,   741,   786,   818,   819,   820,
     821,   866,   822,   823,   824,   864,   883,   690,   691,   692,
     693,   744,   694,   175,   318,   319,    96,    97,   126,   697,
     795,    99,   100,   532,   163,   164,   560,   640,   171,   305,
     101,   583,   485,   102,   584,   300,   585,   103,   104,   295,
     105,   106,   634,   710,   547,   548,   549,   107,   108,   109,
     110,   111,   112,   113,   114,   313,   440,   441,   442,   115,
     356,   357,   157,   158,   116,   351,   117,   118,   119,   120,
     121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   332,   288,    90,    91,   166,   388,   419,   167,   141,
     141,   459,   598,   168,   567,   746,   783,   360,    88,   228,
     161,   314,   390,   520,   282,   524,   513,   336,   341,   344,
     747,   788,   578,   471,   495,   282,   497,   502,  -140,   282,
     502,  -143,   386,   832,   619,   145,   145,   196,   199,   282,
     550,   436,   205,   443,   177,   622,   165,   445,   446,   223,
     203,   433,   774,   122,   437,   435,    33,   439,    33,   216,
     335,    33,   217,   389,   487,    33,   434,   226,    33,   390,
     435,   346,   122,     3,   227,   752,    47,   457,   449,   456,
      33,   793,   458,   439,   190,   856,   570,   590,   285,   623,
    -141,   556,   655,   557,   129,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,  -374,   292,  -371,
     170,   205,   283,   122,   450,   218,    33,   387,   226,   753,
    -370,  -374,   226,   283,   291,   794,   200,   283,   122,   857,
      33,   195,   817,  -358,  -358,   173,   508,   283,   551,   591,
     141,   308,   438,   174,    84,   302,   284,   122,   122,    84,
     214,   187,   524,    84,   507,   172,    84,   579,   784,   785,
     215,   229,   865,   315,   137,   727,   178,   731,    84,   337,
     342,   345,   748,   789,   472,   496,   145,   498,   503,  -140,
     334,   670,  -143,   721,   833,   141,   775,   179,   517,   729,
     730,   518,  -300,   141,   141,   141,   180,   141,   226,   359,
     181,   527,   527,   138,    84,   227,   139,   517,   188,   391,
     518,   182,    98,   140,   392,   321,   729,   730,    84,   264,
     265,   145,   517,   517,   193,   518,   518,   528,   528,   145,
     145,   145,   166,   145,  -125,   167,   226,  -302,  -280,  -280,
     168,  -141,   539,   226,   206,   361,   362,   161,   677,   674,
     363,   122,   391,    33,   391,   732,   226,   392,   226,   392,
    -282,  -282,   379,   363,   208,   505,   391,   391,   122,   207,
      33,   392,   392,   209,   627,   448,   391,   713,   605,   391,
     391,   392,   777,   165,   392,   392,   455,   137,   210,  -301,
    -300,  -302,   716,   717,   736,   226,   226,   226,   142,   142,
    -301,   211,   505,   122,   137,   212,   226,   624,   625,   162,
     742,   635,   213,   379,   481,   628,   629,   759,   760,   631,
      98,   196,   225,   259,   260,   261,   138,   262,   481,   139,
     728,   729,   730,   714,   881,   882,   140,   143,   146,   379,
     230,    84,   231,   138,   232,   233,   139,   236,    98,   235,
     278,    90,    91,   140,   279,   122,   338,    33,    84,   641,
     280,   141,   644,   281,   286,   536,    88,   519,   287,   519,
     214,    47,   519,   651,  -144,   771,   729,   730,   877,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   137,   262,   707,   708,   290,    25,   145,   379,   509,
     293,   294,   298,   758,   299,   141,   303,   306,   354,   301,
     226,   304,   307,  -188,   816,   439,   825,  -358,  -358,   316,
     483,   680,   681,   682,   683,   684,   685,   323,   328,   329,
     138,   330,   343,   139,   483,   353,   141,   375,   141,   142,
     140,   145,   365,   381,   367,    84,   382,   384,   387,   464,
     825,   462,   466,   141,   141,   481,   467,   470,   468,   481,
     481,   481,   737,   488,   493,   588,   122,   562,    33,   494,
     500,   565,   145,   501,   145,   499,   504,   511,   576,   519,
     141,   867,   141,   515,   142,   439,   141,   141,   514,   145,
     145,   516,   142,   142,   142,    98,   142,   521,    90,    91,
     525,   481,   137,   614,   526,   533,   519,   879,   534,   166,
     535,   519,   167,    88,   541,   542,   145,   168,   145,   543,
     544,   546,   145,   145,   161,  -144,   122,   559,    33,   256,
     257,   258,   259,   260,   261,   552,   262,   554,   574,   555,
     379,   138,   586,   587,   139,   589,   162,   792,   597,   796,
     610,   140,   595,   604,   600,   141,    84,   607,   608,   613,
     165,   483,   137,   616,   808,   483,   483,   483,   617,   379,
     379,   481,   661,   620,   811,   621,   632,   379,   379,   814,
     633,   379,   481,   680,   681,   682,   683,   684,   685,   645,
     639,   145,   646,   650,   141,   652,   654,   656,   675,   658,
     838,   159,   519,   841,   160,   657,   519,   483,   843,   662,
     663,   140,   391,   482,   669,   664,    84,   392,   672,   696,
     673,   695,   141,   699,   700,   709,   740,   482,   701,    98,
     145,   141,    98,   719,   711,   481,   702,   743,   750,    98,
     704,   481,   863,   481,   705,   706,   754,   723,   519,   724,
     735,   778,   762,   749,   751,   765,   828,   779,   145,   756,
     142,   757,   764,   770,   519,   772,   782,   145,   781,   787,
     878,   791,   797,   798,   801,   802,   803,   483,   809,   745,
     884,   813,   391,   827,   829,   481,   835,   392,   483,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   831,   839,  -176,   142,   844,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   846,   848,
     849,   850,   852,   763,   851,    98,   853,  -358,  -358,   767,
     767,   854,   862,   870,   868,   142,   872,   142,   871,   481,
     875,   483,  -182,   873,  -358,  -358,   876,   483,   880,   483,
     665,   489,   142,   142,   482,   667,   649,   615,   482,   482,
     482,   599,   722,   481,   491,   847,   676,   481,   519,   769,
     519,   806,   481,   810,   698,   221,   660,   738,   703,   142,
      98,   142,   659,   481,    98,   142,   142,   339,   800,   358,
     602,   483,     0,     0,     0,   603,    98,     0,   678,    98,
     482,     0,    98,   679,   519,   680,   681,   682,   683,   684,
     685,   686,     0,     0,   481,     0,     0,     0,     0,     0,
     481,     0,     0,   162,     0,     0,    98,     0,     0,    98,
       0,    98,     0,     0,     0,   519,   331,     0,   481,     0,
       0,     0,     0,     0,     0,   483,   860,     0,     0,     0,
       0,    98,  -281,  -281,   142,   519,     0,     0,   687,     0,
       0,   519,     0,     0,     0,     0,    98,     0,     0,   483,
     482,     0,    98,   483,     0,   678,     0,     0,   483,     0,
     679,   482,   680,   681,   682,   683,   684,   685,   686,   483,
       0,     0,     0,   142,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
     483,   142,     0,     0,     0,     0,   483,     0,     0,     0,
     142,     0,  -358,  -358,   482,   739,     0,     0,     0,     0,
     482,     0,   482,     0,   483,  -358,  -358,     0,   127,   128,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   156,     0,
     169,     0,     0,     0,   469,     0,     0,     0,   237,   238,
     239,   176,     0,     0,   482,     0,     0,     0,   184,   186,
       0,     0,     0,   191,   240,   194,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
       0,   237,   238,   239,   219,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   482,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   482,     0,     0,     0,   482,     0,     0,     0,
       0,   482,     0,   289,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   144,     0,   492,     0,     0,
       0,     0,     0,   482,   310,     0,   311,     0,   312,   482,
       0,     0,   317,   320,   191,     0,   325,     0,     0,     0,
       0,   512,     0,     0,     0,     0,     0,   482,     0,   192,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   156,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   374,
     220,   191,     0,     0,   553,     0,     0,     0,     0,   312,
       0,   393,   394,   395,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,     0,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   191,     0,   312,     0,   312,   444,     0,     0,
     312,   312,     0,     0,   573,     0,     0,     0,   581,   582,
       0,   452,     0,   454,     0,   296,     0,     0,   191,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,     0,     0,     0,     0,     0,   474,   475,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     612,     0,   490,     0,     0,     0,     0,   476,     0,     0,
     340,     0,     0,     0,     0,    29,    30,   122,   349,   350,
     352,     0,   355,     0,     0,   477,     0,   191,   191,     0,
       0,     0,     0,     0,     0,     0,     0,   380,     0,     0,
       0,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   137,     0,     0,     0,     0,     0,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,    65,    66,    67,    68,    69,     0,     0,  -358,
    -358,   668,     0,     0,     0,     0,    73,     0,   380,     0,
       0,     0,   479,    75,    76,   480,     0,     0,     0,    79,
       0,     0,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,   563,     0,
     320,   568,     0,     0,   725,     0,     0,     0,     0,     0,
     733,   240,   734,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,     0,     0,     0,   191,
       0,     0,     0,   380,   510,     0,     0,     0,     0,   191,
       0,     0,     0,     0,   755,     0,   296,  -283,  -283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   191,
       0,     0,   626,     0,     0,     0,   191,   191,     0,     0,
     191,     0,     0,     0,   312,   636,     0,     0,     0,     0,
       0,     0,   638,     0,     0,     0,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,   799,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,   296,   812,   296,     0,     0,   815,     0,   671,     0,
       0,   826,     0,     0,     0,     0,   263,     0,   569,   572,
       0,     0,   836,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   312,   312,     0,     0,
       0,     0,     0,     0,     0,   349,     0,   601,     0,   320,
       0,   355,   355,   855,     0,   380,     0,     0,     0,   858,
       0,     0,     0,     0,     0,   611,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   869,     0,   237,
     238,   239,     0,     0,   380,   380,     0,     0,     0,     0,
       0,     0,   380,   380,     0,   240,   380,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   773,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,     4,     5,     6,     7,     8,     0,     0,   296,
       0,     9,     0,     0,     0,     0,   804,     0,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   296,   262,     0,
       0,    10,    11,     0,     0,     0,   572,    12,     0,    13,
      14,    15,    16,    17,    18,   837,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,   366,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,    74,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   506,    84,  -375,  -375,  -375,  -375,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,    74,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   606,    84,  -375,  -375,  -375,  -375,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,    74,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   369,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   486,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,   720,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,   726,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   780,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   830,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   834,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,   842,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   845,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,   861,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   874,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,   885,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,    49,    50,     0,    51,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,    58,    59,   368,    61,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,    70,    71,     0,    72,     0,     0,
       0,    73,     4,     5,     6,     7,     8,   124,    75,    76,
      77,     9,     0,    78,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,   561,     0,     0,     0,     0,
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
      77,     9,     0,     0,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,   564,     0,     0,     0,     0,
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
      77,     9,     0,     0,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,   575,     0,     0,     0,     0,
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
      77,     9,     0,     0,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,   766,     0,     0,     0,     0,
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
      77,     9,     0,     0,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,   805,     0,     0,     0,     0,
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
      77,     9,     0,     0,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
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
      77,     9,     0,     0,    79,    80,     0,    81,     0,    82,
      83,     0,    84,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      29,    30,   122,    32,    33,     0,     0,     0,     0,     0,
      35,    36,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
      47,   262,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     4,     5,     6,     7,     8,     0,     0,
       0,    73,     9,     0,     0,     0,     0,   124,    75,    76,
      77,     0,     0,     0,    79,   125,     0,    81,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
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
      76,    77,     0,     0,     0,    79,   125,     0,    81,     0,
     183,     0,     0,    84,     0,     0,     0,     0,     0,     0,
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
      75,    76,    77,     0,     0,     0,    79,   125,     0,    81,
       0,   185,     0,     0,    84,     0,     0,     0,     0,     0,
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
      81,     0,   189,     0,     0,    84,     0,     0,     0,     0,
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
       0,    81,   309,     0,     0,   376,    84,     0,     0,     0,
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
     125,   396,    81,     0,     0,     0,     0,    84,     0,     0,
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
      79,   125,     0,    81,     0,     0,     0,   420,    84,     0,
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
       0,    79,   125,     0,    81,     0,     0,     0,   451,    84,
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
       0,     0,    79,   125,     0,    81,     0,     0,     0,   453,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,    79,   125,     0,    81,     0,     0,     0,
     609,    84,     0,     0,     0,     0,     0,     0,     0,     0,
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
      77,     0,     0,     0,    79,   125,     0,    81,     0,     0,
       0,   637,    84,     0,     0,     0,     0,     0,     0,     0,
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
      76,    77,     0,     0,     0,    79,   125,     0,    81,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
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
      75,    76,    77,     0,     0,     0,    79,   125,     0,    81,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    29,    30,   122,    32,    33,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,     0,
     124,    75,    76,    77,   237,   238,   239,    79,    80,     0,
      81,     0,     0,     0,     0,    84,     0,     0,     0,     0,
     240,     0,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596,   240,   774,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,   240,
       0,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   712,
     240,     0,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   775,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   326,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   327,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   333,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,     0,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   447,   240,     0,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,   240,
       0,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     461,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,     0,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   465,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   473,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   643,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   840,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   859,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,   240,     0,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   364,   240,   538,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   558,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   239,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
       0,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   240,   262,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262
};

static const yytype_int16 yycheck[] =
{
       2,   193,   126,     2,     2,    25,   235,   262,    25,    14,
      15,   307,   494,    25,   466,   692,     8,   215,     2,     8,
      25,     8,   236,   382,    63,   384,   376,     8,     8,     8,
       8,     8,    26,     8,     8,    63,     8,     8,     8,    63,
       8,     8,    73,     8,   526,    14,    15,    52,    75,    63,
      63,   280,    54,   282,    38,    31,    25,   286,   287,    81,
      75,   278,    26,    73,    73,   279,    75,   281,    75,    74,
      93,    75,    77,    73,    93,    75,    73,   151,    75,   293,
     294,   205,    73,     0,   158,    31,   101,   304,    73,   303,
      75,    31,   306,   307,    49,    31,    31,   105,   115,    75,
       8,   451,   579,   453,   158,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   145,   140,   158,
     158,   123,   161,    73,    73,    80,    75,   158,   151,    75,
     158,   145,   151,   161,   139,    75,   163,   161,    73,    75,
      75,   151,    73,    51,    52,    26,   363,   161,   161,   157,
     155,   168,   161,    63,   163,   160,   163,    73,    73,   163,
     151,    73,   521,   163,   362,   158,   163,   161,   160,   161,
     161,   160,   849,   160,   109,   652,   158,   654,   163,   160,
     160,   160,   160,   160,   159,   159,   155,   159,   159,   159,
     195,   159,   159,   645,   159,   200,   160,   158,   148,    96,
      97,   151,   145,   208,   209,   210,   158,   212,   151,   214,
     158,   127,   127,   148,   163,   158,   151,   148,    73,   236,
     151,   158,   224,   158,   236,   180,    96,    97,   163,    51,
      52,   200,   148,   148,   161,   151,   151,   153,   153,   208,
     209,   210,   262,   212,   159,   262,   151,   145,   159,   160,
     262,   159,    64,   151,   120,   160,   161,   262,   617,   609,
     158,    73,   279,    75,   281,   162,   151,   279,   151,   281,
     159,   160,   227,   158,   158,   158,   293,   294,    73,   120,
      75,   293,   294,   158,   539,   290,   303,   637,   505,   306,
     307,   303,   162,   262,   306,   307,   301,   109,   158,   145,
     145,   145,    68,    69,   663,   151,   151,   151,    14,    15,
     145,   158,   158,    73,   109,   158,   151,   534,   535,    25,
     679,   550,   158,   278,   329,   542,   543,    68,    69,   546,
     332,   336,   161,    45,    46,    47,   148,    49,   343,   151,
      95,    96,    97,   639,   160,   161,   158,    14,    15,   304,
      73,   163,    73,   148,   160,    31,   151,   145,   360,    63,
     158,   360,   360,   158,   145,    73,   161,    75,   163,   561,
      63,   376,   564,   124,    63,   392,   360,   382,    63,   384,
     151,   101,   387,   575,     8,    95,    96,    97,   870,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   109,    49,   632,   633,   151,    64,   376,   363,   364,
     145,   145,   164,   709,     8,   420,   145,   145,   126,   151,
     151,   158,   124,   101,   783,   639,   785,    51,    52,    85,
     329,   109,   110,   111,   112,   113,   114,    73,   160,    13,
     148,   160,    13,   151,   343,   159,   451,    73,   453,   155,
     158,   420,   159,    73,   159,   163,   122,   122,   158,   158,
     819,   164,   160,   468,   469,   470,     8,    13,    93,   474,
     475,   476,   664,    73,    75,   480,    73,   461,    75,   158,
     160,   465,   451,   158,   453,   159,   159,   158,   472,   494,
     495,   850,   497,     8,   200,   709,   501,   502,   159,   468,
     469,    13,   208,   209,   210,   507,   212,   123,   507,   507,
     161,   516,   109,   518,   158,   164,   521,   876,   158,   539,
     158,   526,   539,   507,   159,   158,   495,   539,   497,   158,
     164,   158,   501,   502,   539,   159,    73,   159,    75,    42,
      43,    44,    45,    46,    47,   164,    49,   164,    73,   164,
     505,   148,   158,   151,   151,   145,   262,   749,    13,   751,
     515,   158,    73,    13,   160,   570,   163,   159,   159,   151,
     539,   470,   109,   161,   766,   474,   475,   476,     8,   534,
     535,   586,   587,   159,   776,     8,    63,   542,   543,   781,
      63,   546,   597,   109,   110,   111,   112,   113,   114,   160,
     124,   570,   125,    13,   609,   160,   160,   125,   613,     8,
     802,   148,   617,   805,   151,   164,   621,   516,   810,    73,
     158,   158,   639,   329,   159,   161,   163,   639,   159,   107,
     160,   159,   637,    75,    13,   124,    73,   343,   159,   641,
     609,   646,   644,   160,   164,   650,   159,    75,   158,   651,
     159,   656,   844,   658,   159,   159,    13,   159,   663,   159,
     159,   125,   158,   161,   161,   159,   790,    75,   637,   164,
     376,   164,   160,   160,   679,   160,    13,   646,   161,    13,
     872,    73,    75,    13,   158,    26,    70,   586,   160,   691,
     882,   159,   709,    75,    13,   700,    13,   709,   597,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    75,   160,    93,   420,   161,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   162,   160,
      93,   152,   145,   717,   160,   737,    13,    51,    52,   723,
     724,    73,   160,   158,    73,   451,    26,   453,    75,   754,
      73,   650,    73,   160,    51,    52,     8,   656,   159,   658,
     592,   336,   468,   469,   470,   592,   571,   521,   474,   475,
     476,   495,   646,   778,   341,   819,   616,   782,   783,   724,
     785,   765,   787,   773,   621,    81,   586,   669,   627,   495,
     792,   497,   585,   798,   796,   501,   502,   200,   758,   213,
     501,   700,    -1,    -1,    -1,   502,   808,    -1,   102,   811,
     516,    -1,   814,   107,   819,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,   829,    -1,    -1,    -1,    -1,    -1,
     835,    -1,    -1,   539,    -1,    -1,   838,    -1,    -1,   841,
      -1,   843,    -1,    -1,    -1,   850,   160,    -1,   853,    -1,
      -1,    -1,    -1,    -1,    -1,   754,   840,    -1,    -1,    -1,
      -1,   863,   159,   160,   570,   870,    -1,    -1,   162,    -1,
      -1,   876,    -1,    -1,    -1,    -1,   878,    -1,    -1,   778,
     586,    -1,   884,   782,    -1,   102,    -1,    -1,   787,    -1,
     107,   597,   109,   110,   111,   112,   113,   114,   115,   798,
      -1,    -1,    -1,   609,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
     829,   637,    -1,    -1,    -1,    -1,   835,    -1,    -1,    -1,
     646,    -1,    51,    52,   650,   162,    -1,    -1,    -1,    -1,
     656,    -1,   658,    -1,   853,    51,    52,    -1,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    -1,    -1,    -1,    93,    -1,    -1,    -1,     9,    10,
      11,    37,    -1,    -1,   700,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    49,    25,    51,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,     9,    10,    11,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   754,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,   778,    -1,    -1,    -1,   782,    -1,    -1,    -1,
      -1,   787,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    -1,   343,    -1,    -1,
      -1,    -1,    -1,   829,   170,    -1,   172,    -1,   174,   835,
      -1,    -1,   178,   179,   180,    -1,   182,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,   853,    -1,    49,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,   213,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      80,   227,    -1,    -1,   162,    -1,    -1,    -1,    -1,   235,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,    -1,    -1,    -1,    -1,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,    -1,   280,    -1,   282,   283,    -1,    -1,
     286,   287,    -1,    -1,   470,    -1,    -1,    -1,   474,   475,
      -1,   297,    -1,   299,    -1,   155,    -1,    -1,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     516,    -1,   338,    -1,    -1,    -1,    -1,    63,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    71,    72,    73,   208,   209,
     210,    -1,   212,    -1,    -1,    81,    -1,   363,   364,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,   132,    -1,    -1,    51,
      52,   597,    -1,    -1,    -1,    -1,   142,    -1,   278,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,   464,    -1,
     466,   467,    -1,    -1,   650,    -1,    -1,    -1,    -1,    -1,
     656,    25,   658,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,   505,
      -1,    -1,    -1,   363,   364,    -1,    -1,    -1,    -1,   515,
      -1,    -1,    -1,    -1,   700,    -1,   376,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   534,   535,
      -1,    -1,   538,    -1,    -1,    -1,   542,   543,    -1,    -1,
     546,    -1,    -1,    -1,   550,   551,    -1,    -1,    -1,    -1,
      -1,    -1,   558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   754,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,   451,   778,   453,    -1,    -1,   782,    -1,   604,    -1,
      -1,   787,    -1,    -1,    -1,    -1,   160,    -1,   468,   469,
      -1,    -1,   798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   632,   633,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   495,    -1,   497,    -1,   645,
      -1,   501,   502,   829,    -1,   505,    -1,    -1,    -1,   835,
      -1,    -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   853,    -1,     9,
      10,    11,    -1,    -1,   534,   535,    -1,    -1,    -1,    -1,
      -1,    -1,   542,   543,    -1,    25,   546,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
     570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   729,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     3,     4,     5,     6,     7,    -1,    -1,   609,
      -1,    12,    -1,    -1,    -1,    -1,   762,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,   637,    49,    -1,
      -1,    42,    43,    -1,    -1,    -1,   646,    48,    -1,    50,
      51,    52,    53,    54,    55,   801,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,   159,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    90,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,   154,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     101,    49,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,    -1,   158,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   142,    12,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,    -1,   158,    -1,
     160,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   142,    12,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,   158,
      -1,   160,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   142,    12,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,
     158,    -1,   160,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
      -1,   158,   159,    -1,    -1,    31,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,    26,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,
     155,   156,    -1,   158,    -1,    -1,    -1,    31,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   142,    12,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,    -1,   158,    -1,    -1,    -1,    31,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,   131,   132,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   142,
      12,    -1,    -1,    -1,    -1,   148,   149,   150,   151,    -1,
      -1,    -1,   155,   156,    -1,   158,    -1,    -1,    -1,    31,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,    -1,   158,    -1,    -1,    -1,
      31,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,    -1,   158,    -1,    -1,
      -1,    31,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   142,    12,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,    -1,   158,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   142,    12,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,     9,    10,    11,   155,   156,    -1,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   160,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   160,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   160,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     159,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   159,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   159,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   159,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   159,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   125,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    11,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    25,    49,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   166,   167,     0,     3,     4,     5,     6,     7,    12,
      42,    43,    48,    50,    51,    52,    53,    54,    55,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    71,
      72,    73,    74,    75,    77,    81,    82,    83,    84,    85,
      87,    89,    91,    94,    98,    99,   100,   101,   102,   103,
     104,   106,   107,   108,   109,   110,   111,   116,   117,   118,
     119,   120,   121,   126,   127,   128,   129,   130,   131,   132,
     135,   136,   138,   142,   148,   149,   150,   151,   154,   155,
     156,   158,   160,   161,   163,   168,   169,   172,   175,   176,
     183,   184,   186,   187,   188,   190,   241,   242,   243,   246,
     247,   255,   258,   262,   263,   265,   266,   272,   273,   274,
     275,   276,   277,   278,   279,   284,   289,   291,   292,   293,
     294,   295,    73,   109,   148,   156,   243,   262,   262,   158,
     262,   262,   262,   262,   262,   262,   262,   109,   148,   151,
     158,   168,   247,   265,   266,   274,   265,   262,   262,   262,
     262,   262,   262,   262,   262,    31,   262,   287,   288,   148,
     151,   168,   247,   249,   250,   274,   277,   278,   284,   262,
     158,   253,   158,    26,    63,   238,   262,   175,   158,   158,
     158,   158,   158,   160,   262,   160,   262,    73,    73,   160,
     241,   262,   266,   161,   262,   151,   168,   170,   171,    75,
     163,   213,   214,    75,   215,   243,   120,   120,   158,   158,
     158,   158,   158,   158,   151,   161,   168,   168,   241,   262,
     266,   242,   262,   294,   173,   161,   151,   158,     8,   160,
      73,    73,   160,    31,   185,    63,   145,     9,    10,    11,
      25,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,   160,    51,    52,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   158,   145,
      63,   124,    63,   161,   163,   278,    63,    63,   185,   262,
     151,   168,   294,   145,   145,   264,   266,   125,   164,     8,
     260,   151,   168,   145,   158,   254,   145,   124,   278,   159,
     262,   262,   262,   280,     8,   160,    85,   262,   239,   240,
     262,   241,   266,    73,   199,   262,   160,   160,   160,    13,
     160,   160,   173,   160,   168,    93,     8,   160,   161,   263,
     266,     8,   160,    13,     8,   160,   185,   181,   182,   266,
     266,   290,   266,   159,   126,   266,   285,   286,   287,   168,
     167,   160,   161,   158,   125,   159,   159,   159,   119,   162,
     174,   175,   183,   184,   262,    73,    31,   211,   212,   241,
     266,    73,   122,   189,   122,   191,    73,   158,   280,    73,
     272,   278,   284,   262,   262,   262,    26,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   249,
      31,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   211,    73,   272,   280,    73,   161,   272,
     281,   282,   283,   280,   262,   280,   280,   159,   168,    73,
      73,    31,   262,    31,   262,   168,   272,   211,   272,   281,
     159,   159,   164,   262,   158,   159,   160,     8,    93,    93,
      13,     8,   159,   159,    42,    43,    63,    81,   127,   148,
     151,   168,   247,   255,   256,   257,   162,    93,    73,   171,
     262,   214,   256,    75,   158,     8,   159,     8,   159,   159,
     160,   158,     8,   159,   159,   158,   162,   167,   211,   241,
     266,   158,   162,   264,   159,     8,    13,   148,   151,   168,
     248,   123,   192,   193,   248,   161,   158,   127,   153,   208,
     209,   210,   248,   164,   158,   158,   278,   262,    26,    64,
     266,   159,   158,   158,   164,   262,   158,   269,   270,   271,
      63,   161,   164,   162,   164,   164,   264,   264,   125,   159,
     251,    26,   175,   262,    26,   175,   203,   239,   262,   266,
      31,   195,   266,   256,    73,    26,   175,   198,    26,   161,
     200,   256,   256,   256,   259,   261,   158,   151,   168,   145,
     105,   157,   177,   178,   180,    73,   162,    13,   208,   182,
     160,   266,   285,   286,    13,   211,   162,   159,   159,    31,
     241,   266,   256,   151,   168,   193,   161,     8,   216,   208,
     159,     8,    31,    75,   211,   211,   262,   249,   211,   211,
     162,   211,    63,    63,   267,   280,   262,    31,   262,   124,
     252,   173,   204,   159,   173,   160,   125,   194,   266,   194,
      13,   173,   160,   201,   160,   201,   125,   164,     8,   260,
     259,   168,    73,   158,   161,   178,   179,   180,   256,   159,
     159,   262,   159,   160,   264,   168,   216,   248,   102,   107,
     109,   110,   111,   112,   113,   114,   115,   162,   217,   219,
     232,   233,   234,   235,   237,   159,   107,   244,   210,    75,
      13,   159,   159,   254,   159,   159,   159,   280,   280,   124,
     268,   164,   162,   264,   281,   205,    68,    69,   206,   160,
      86,   239,   195,   159,   159,   256,    92,   201,    95,    96,
      97,   201,   162,   256,   256,   159,   248,   173,   244,   162,
      73,   220,   248,    75,   236,   243,   235,     8,   160,   161,
     158,   161,    31,    75,    13,   256,   164,   164,   281,    68,
      69,   207,   158,   175,   160,   159,    26,   175,   197,   197,
     160,    95,   160,   262,    26,   160,   202,   162,   125,    75,
     162,   161,    13,     8,   160,   161,   221,    13,     8,   160,
     218,    73,   173,    31,    75,   245,   173,    75,    13,   256,
     271,   158,    26,    70,   262,    26,   175,   196,   173,   160,
     202,   173,   256,   159,   173,   256,   248,    73,   222,   223,
     224,   225,   227,   228,   229,   248,   256,    75,   185,    13,
     162,    75,     8,   159,   162,    13,   256,   262,   173,   160,
     159,   173,    90,   173,   161,   162,   162,   224,   160,    93,
     152,   160,   145,    13,    73,   256,    31,    75,   256,   159,
     175,    88,   160,   173,   230,   235,   226,   248,    73,   256,
     158,    75,    26,   160,   162,    73,     8,   208,   173,   248,
     159,   160,   161,   231,   173,   162
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   165,   166,   167,   167,   168,   168,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   170,   171,   171,
     171,   171,   172,   172,   173,   173,   174,   174,   174,   174,
     175,   175,   175,   175,   175,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   177,   177,   178,   179,   179,   180,
     181,   181,   182,   183,   184,   185,   185,   186,   187,   187,
     188,   188,   188,   188,   189,   189,   190,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195,   196,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   200,   200,   201,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   209,   209,
     209,   209,   209,   209,   210,   210,   210,   210,   211,   211,
     212,   212,   212,   212,   212,   212,   213,   213,   214,   214,
     214,   215,   215,   215,   215,   216,   216,   217,   217,   217,
     218,   217,   219,   220,   220,   221,   221,   222,   222,   223,
     223,   224,   224,   225,   226,   226,   227,   227,   228,   229,
     229,   230,   230,   231,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   235,   235,   235,   235,   236,   236,   236,
     236,   237,   237,   238,   238,   239,   239,   240,   240,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     242,   242,   242,   242,   243,   244,   244,   245,   245,   245,
     245,   246,   246,   246,   246,   246,   246,   246,   246,   247,
     247,   247,   247,   248,   248,   248,   249,   249,   250,   250,
     251,   251,   252,   253,   253,   253,   254,   254,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   257,
     258,   258,   258,   258,   258,   258,   259,   259,   260,   260,
     261,   261,   261,   261,   262,   262,   263,   264,   265,   266,
     266,   267,   267,   268,   269,   269,   270,   271,   271,   271,
     272,   272,   273,   273,   274,   275,   275,   276,   276,   276,
     277,   277,   277,   277,   278,   278,   278,   279,   279,   280,
     280,   281,   281,   282,   282,   282,   283,   283,   284,   284,
     285,   285,   286,   286,   286,   287,   287,   288,   288,   288,
     288,   288,   288,   288,   288,   289,   289,   289,   289,   289,
     289,   289,   290,   290,   291,   291,   292,   292,   292,   293,
     293,   294,   295,   295
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
       1,     3,     1,     1,     1,     0,     1,     9,     7,     6,
       1,     2,     2,     1,     0,     2,     1,     0,     2,     0,
       2,     1,     3,     0,     2,     1,     2,     1,     4,     1,
       4,     1,     4,     3,     5,     3,     4,     4,     5,     0,
       5,     4,     1,     1,     1,     4,     0,     6,     0,     7,
       0,     2,     0,     3,     1,     0,     2,     3,     5,     4,
       4,     5,     7,     6,     0,     1,     1,     1,     1,     0,
       1,     1,     2,     3,     3,     4,     3,     1,     1,     2,
       4,     3,     5,     1,     3,     2,     0,     3,     2,     1,
       0,     9,     3,     1,     3,     1,     3,     0,     1,     1,
       2,     2,     2,     3,     1,     3,     1,     1,     3,     4,
       3,     0,     1,     1,     3,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     5,     1,
       3,     5,     4,     3,     1,     0,     1,     3,     1,     6,
       3,     4,     6,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       5,     4,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     1,     9,    10,
       2,     2,     4,     4,     1,     0,     4,     3,     4,     1,
       2,     4,     6,     5,     6,     6,     6,     6,     4,     1,
       1,     3,     2,     1,     3,     2,     1,     1,     4,     1,
       2,     0,     2,     0,     2,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     2,     4,     3,     1,     3,
       1,     1,     1,     3,     2,     1,     0,     2,     0,     1,
       5,     3,     3,     1,     1,     1,     1,     1,     1,     5,
       1,     2,     0,     3,     4,     4,     3,     1,     1,     0,
       1,     2,     3,     3,     1,     4,     4,     1,     1,     1,
       1,     3,     2,     1,     4,     4,     1,     1,     4,     0,
       1,     1,     1,     4,     4,     1,     1,     3,     1,     2,
       3,     1,     1,     4,     0,     0,     2,     5,     3,     3,
       1,     6,     4,     4,     2,     4,     4,     2,     2,     4,
       2,     2,     1,     3,     3,     3,     4,     4,     4,     4,
       3,     3,     3,     3
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
#line 207 "parser.y" /* yacc.c:1646  */
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[0]));
  }
#line 3448 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 213 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3456 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 216 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3464 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 222 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_SYMBOL_NAME);
  }
#line 3472 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 225 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-2]), (yyvsp[0]));
  }
#line 3480 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 234 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3490 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 239 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_NAMESPACE, (yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3502 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 246 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-4]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-4])->appendChild((yyvsp[-3]));
  (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3513 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 252 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-3]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-3])->appendChild(NNEW(n_EMPTY));
  NMORE((yyvsp[-1]), (yyvsp[0]));
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyvsp[-3])->appendChild((yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  }
#line 3526 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 260 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3536 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 265 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3545 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 272 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 3553 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 275 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3562 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 282 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3572 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 287 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3583 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 293 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3594 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 299 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3606 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 309 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyval), (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3618 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 316 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3630 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 326 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3638 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 329 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3646 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 338 "parser.y" /* yacc.c:1646  */
    {
  (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3656 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 347 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3667 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 353 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3675 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 356 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3683 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 359 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLOSE_TAG);
  }
#line 3691 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 365 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 3699 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 368 "parser.y" /* yacc.c:1646  */
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
#line 3734 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 402 "parser.y" /* yacc.c:1646  */
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
#line 3754 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 417 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_WHILE);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3766 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 424 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-6]), n_DO_WHILE);
    (yyvsp[-6])->appendChild((yyvsp[-5]));
    (yyvsp[-6])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-6]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3779 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 432 "parser.y" /* yacc.c:1646  */
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
#line 3797 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 445 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_SWITCH);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3809 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 452 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_BREAK);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3821 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 459 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_BREAK);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3833 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 466 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_CONTINUE);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3845 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 473 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_CONTINUE);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3857 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 480 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_RETURN);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3869 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 487 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3881 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 494 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3893 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 501 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3903 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 506 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3913 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 511 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3923 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 516 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_INLINE_HTML);
    (yyval) = (yyvsp[0]);
  }
#line 3932 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 520 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3941 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 524 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3950 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 528 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[-1]));
    NMORE((yyvsp[-2]), (yyvsp[-4]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3961 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 535 "parser.y" /* yacc.c:1646  */
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
#line 3983 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 553 "parser.y" /* yacc.c:1646  */
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
#line 4004 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 569 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_DECLARE);
    (yyvsp[-4])->appendChild((yyvsp[-2]));
    (yyvsp[-4])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4015 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 575 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4024 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 579 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_TRY);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));

    (yyvsp[-5])->appendChild((yyvsp[-1]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-5]));
  }
#line 4038 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 588 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_TRY);
    (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1])));

    (yyvsp[-4])->appendChild(NNEW(n_CATCH_LIST));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4052 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 597 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_THROW);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));

  }
#line 4065 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 605 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_GOTO);
  NTYPE((yyvsp[-1]), n_STRING);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 4078 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 616 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4087 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 620 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_CATCH_LIST);
  (yyval)->appendChild((yyvsp[0]));
}
#line 4096 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 627 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-7]), n_CATCH);
    (yyvsp[-7])->appendChild((yyvsp[-5]));
    (yyvsp[-7])->appendChild(NTYPE((yyvsp[-4]), n_VARIABLE));
    (yyvsp[-7])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyvsp[-7]), (yyvsp[0]));
    (yyval) = (yyvsp[-7]);
  }
#line 4109 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 638 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4117 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 645 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_FINALLY);
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    NMORE((yyvsp[-3]), (yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 4128 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 654 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4137 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 658 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4146 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 677 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4154 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 680 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_REFERENCE);
  }
#line 4162 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 687 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-8]), n_FUNCTION_DECLARATION, (yyvsp[0]));
    (yyvsp[-8])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-8])->appendChild((yyvsp[-7]));
    (yyvsp[-8])->appendChild(NTYPE((yyvsp[-6]), n_STRING));
    (yyvsp[-8])->appendChild(NEXPAND((yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3])));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyvsp[-8])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-8]));
  }
#line 4178 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 702 "parser.y" /* yacc.c:1646  */
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
#line 4194 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 713 "parser.y" /* yacc.c:1646  */
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
#line 4211 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 728 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[0]);
  }
#line 4220 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 732 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 739 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4244 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 746 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 4253 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 753 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4261 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 756 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_EXTENDS_LIST)->appendChild((yyvsp[0]));
  }
#line 4269 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 766 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4277 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 769 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_EXTENDS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4287 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 777 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4295 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 780 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_IMPLEMENTS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 788 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[0]));
  }
#line 4313 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 791 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4321 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 797 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4329 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 800 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4337 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 807 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4347 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 816 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4357 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 825 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4367 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 834 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4377 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 842 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4388 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 848 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));
    (yyval) = (yyvsp[-4]);
  }
#line 4401 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 859 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4409 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 862 "parser.y" /* yacc.c:1646  */
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[-2]), n_STATEMENT);
    (yyvsp[-3])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));
    NEXPAND((yyvsp[-3]), (yyval), (yyvsp[0]));
  }
#line 4424 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 872 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[0]));
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval) = (yyvsp[-2]);
  }
#line 4434 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 877 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_STATEMENT);
    (yyvsp[-4])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-3]));
    (yyval)->appendChildren((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
    NMORE((yyval), (yyvsp[-4]));
  }
#line 4448 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 889 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4456 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 892 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CASE);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyvsp[-3]));
    (yyval) = (yyvsp[-4]);
  }
#line 4469 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 900 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_DEFAULT);
    (yyvsp[-2])->appendChild((yyvsp[0]));

    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval) = (yyvsp[-3]);
  }
#line 4481 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 916 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[0]));
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  (yyval) = (yyvsp[-2]);
  }
#line 4491 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 924 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4499 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 927 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_ELSEIF);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyvsp[-4]));
  }
#line 4511 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 937 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4519 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 940 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_ELSEIF);
    (yyvsp[-5])->appendChild((yyvsp[-3]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyvsp[-5]));
  }
#line 4531 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 950 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4539 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 953 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_ELSE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4549 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 961 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4557 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 964 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ELSE);
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4567 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 973 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
#line 4575 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 979 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4588 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 987 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4602 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 996 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4616 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1005 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4629 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1013 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 4642 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1021 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4656 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1031 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyval));
  }
#line 4670 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1041 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 4683 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1052 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4691 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1055 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4699 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1058 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4707 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1061 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4715 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1068 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
#line 4723 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1074 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4731 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1077 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4739 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1080 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[-1]));
  }
#line 4749 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1085 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4757 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1088 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4765 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1091 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 4775 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1099 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4784 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1103 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4793 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1110 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4801 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1113 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4810 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1117 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-3]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 4819 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1124 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 4832 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1132 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4845 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1140 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4858 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1148 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4871 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1159 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4879 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1162 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4887 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1168 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4900 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1176 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4909 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1180 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4917 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1183 "parser.y" /* yacc.c:1646  */
    {
    /* empty */
  }
#line 4925 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1185 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_DECLARATION);
    NMORE((yyval), (yyvsp[-7]));
    (yyval)->appendChild((yyvsp[-8]));
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-4]), n_STRING));
    (yyval)->appendChild(NEXPAND((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1])));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
#line 4942 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1200 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-2]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4952 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1208 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[0]));
  }
#line 4960 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1211 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4968 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1217 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4976 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1220 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4984 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1226 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
#line 4992 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1229 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5000 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1235 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5009 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1239 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 5018 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1246 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5026 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1249 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5034 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1255 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5044 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1263 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5053 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1267 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 5062 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1274 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5071 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1278 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5079 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1284 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[-2]), (yyvsp[-1]), NTYPE((yyvsp[0]), n_STRING));
    (yyval) = (yyvsp[-1]);
  }
#line 5089 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1292 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5100 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1298 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 5111 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1307 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5119 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1310 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5128 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1318 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1321 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5144 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1328 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5153 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1335 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
#line 5161 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1338 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[0]);
  }
#line 5170 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1345 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5179 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1349 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5187 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1364 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 5199 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1371 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 5211 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1378 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5223 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1385 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5235 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1395 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));

    (yyval) = (yyvsp[-4]);
  }
#line 5249 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1404 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyvsp[-3])->appendChild((yyval));

    (yyval) = (yyvsp[-3]);
  }
#line 5263 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1416 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5271 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1419 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5280 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1426 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5288 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1434 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5296 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1437 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5305 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1444 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_LIST);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5318 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1452 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5329 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1458 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));

    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));

    (yyval)->appendChild((yyvsp[-1]));
  }
#line 5344 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1468 "parser.y" /* yacc.c:1646  */
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
#line 5363 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1482 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5373 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1487 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5384 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1493 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5395 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1499 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5406 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1505 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5417 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1511 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5428 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1517 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5439 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1523 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5450 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1529 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5461 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1535 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5472 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1541 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5483 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1547 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5494 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1553 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5504 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1558 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5514 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1563 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5524 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1568 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5534 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1573 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5545 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1579 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5556 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1585 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5567 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1591 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5578 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1597 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5589 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1603 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5600 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1609 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5611 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1615 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5622 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1621 "parser.y" /* yacc.c:1646  */
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
#line 5653 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1647 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5664 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1653 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5675 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1659 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5686 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1665 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5697 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1671 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5708 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1677 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5719 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1683 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5730 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1689 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5740 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1694 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5750 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1699 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5760 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1704 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5770 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1709 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5781 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1715 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5792 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1721 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5803 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1727 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5814 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1733 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5825 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1739 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5836 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1745 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5847 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1751 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5858 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1757 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5869 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1765 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5882 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1773 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5895 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1782 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5905 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1787 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5915 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1792 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5925 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1797 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5935 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1802 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5945 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1807 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5955 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1812 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5965 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1817 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5975 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1822 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5985 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1827 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[0]);
  }
#line 5994 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1834 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6004 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1839 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[0]);
  }
#line 6015 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1848 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-8]), n_FUNCTION_DECLARATION, (yyvsp[0]));
    (yyvsp[-8])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-8])->appendChild((yyvsp[-7]));
    (yyvsp[-8])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-8])->appendChild(NEXPAND((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4])));
    (yyval)->appendChild((yyvsp[-3]));
    (yyvsp[-8])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));

    (yyval) = (yyvsp[-8]);
  }
#line 6031 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1862 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-8]), n_FUNCTION_DECLARATION, (yyvsp[0]));
    NMORE((yyvsp[-8]), (yyvsp[-9]));

    (yyval) = NNEW(n_FUNCTION_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[-9]), n_STRING));
    (yyvsp[-8])->appendChild((yyvsp[-9]));

    (yyvsp[-8])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-8])->appendChild((yyvsp[-7]));
    (yyvsp[-8])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-8])->appendChild(NEXPAND((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4])));
    (yyvsp[-8])->appendChild((yyvsp[-3]));
    (yyvsp[-8])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));

    (yyval) = (yyvsp[-8]);
  }
#line 6053 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1882 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6064 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1888 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6075 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1894 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6086 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1900 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6097 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1913 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6105 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1916 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[-3])->appendChildren((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6115 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1924 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6123 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1927 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 6133 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1932 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6142 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1936 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 6153 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1945 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6163 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1951 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-5]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6174 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1957 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-4]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6185 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1964 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6198 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1973 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6211 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1982 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6224 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1991 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6237 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1999 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6247 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 2007 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6255 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 2010 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6263 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 2013 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6272 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 2017 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6281 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 2024 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6289 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 2027 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6298 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2031 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6307 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 2046 "parser.y" /* yacc.c:1646  */
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
#line 6324 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 2062 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 6332 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2065 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6340 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2071 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6348 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 2077 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6356 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 2080 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-1]), n_EMPTY, (yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6365 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 2084 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 6375 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 2092 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6383 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2095 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6391 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2101 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6399 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2104 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6407 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2107 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_STRING_SCALAR);
  }
#line 6415 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2110 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6423 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2113 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6431 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2116 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6439 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2119 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6447 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2122 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6455 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2125 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6463 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2128 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6471 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2131 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6479 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2134 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_HEREDOC);
  }
#line 6487 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2142 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = (yyvsp[0]);
  }
#line 6496 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2146 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = (yyvsp[0]);
  }
#line 6505 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2150 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6515 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2155 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6525 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2160 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 6535 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 2165 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 6545 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2174 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 6555 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2185 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-2]));
  }
#line 6563 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2188 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-1]));
  }
#line 6571 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2195 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6579 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2198 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6587 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 2204 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6595 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2215 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6607 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2222 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6619 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2229 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6631 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2236 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6643 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2266 "parser.y" /* yacc.c:1646  */
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
#line 6671 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2293 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChildren((yyvsp[0]));
  }
#line 6679 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2296 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6687 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2302 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[-1]));
    if ((yyvsp[0])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[0]));
    }
  }
#line 6699 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2312 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6710 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2318 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6721 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2327 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6729 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2335 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6737 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2342 "parser.y" /* yacc.c:1646  */
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
#line 6754 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2357 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6764 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2362 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6774 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2374 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6785 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2380 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6796 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2396 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6804 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2399 "parser.y" /* yacc.c:1646  */
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
#line 6821 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2415 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6832 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2421 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6843 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2431 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 6851 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2434 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-3]), n_VARIABLE_EXPRESSION, (yyvsp[0]));
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6861 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2442 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6869 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2445 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6877 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2456 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6888 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2462 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6899 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2472 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_STRING);
    (yyval) = (yyvsp[0]);
  }
#line 6908 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2476 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6916 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2482 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);
  }
#line 6924 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2485 "parser.y" /* yacc.c:1646  */
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
#line 6941 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2500 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 6949 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2503 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6958 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2511 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6967 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2515 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6975 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2521 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6983 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2524 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6991 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2530 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 7003 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2537 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 7015 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2544 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7027 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2551 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7039 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2558 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 7051 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2565 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 7063 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2572 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7075 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2579 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7087 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2589 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7102 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2599 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7117 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2609 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7125 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2612 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7133 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2615 "parser.y" /* yacc.c:1646  */
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

  case 420:
#line 2625 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7156 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2628 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7164 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2634 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7173 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2638 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7181 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2644 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 7191 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2649 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 7199 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2655 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7210 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2661 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7221 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2667 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2676 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 7242 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2681 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 7252 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2689 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 7263 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2698 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7273 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2703 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7283 "parser.yacc.cpp" /* yacc.c:1646  */
    break;


#line 7287 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 2710 "parser.y" /* yacc.c:1906  */


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
/* @generated */
