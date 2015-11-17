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
#define YYLAST   7752

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  433
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  894

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
     234,   239,   246,   252,   260,   266,   273,   276,   283,   288,
     294,   300,   310,   317,   327,   330,   336,   337,   338,   339,
     347,   348,   354,   357,   360,   366,   369,   399,   418,   425,
     433,   446,   453,   460,   467,   474,   481,   488,   495,   502,
     507,   512,   517,   521,   525,   529,   535,   553,   570,   576,
     580,   598,   606,   617,   618,   624,   627,   637,   641,   648,
     660,   664,   671,   675,   679,   683,   686,   692,   707,   719,
     734,   738,   745,   752,   759,   762,   768,   772,   775,   783,
     786,   794,   797,   803,   806,   812,   813,   821,   822,   830,
     831,   839,   840,   848,   854,   865,   868,   878,   883,   895,
     898,   906,   916,   917,   921,   922,   930,   933,   943,   946,
     956,   959,   967,   970,   978,   979,   985,   993,  1002,  1011,
    1019,  1027,  1036,  1046,  1058,  1061,  1064,  1067,  1073,  1074,
    1080,  1083,  1086,  1091,  1094,  1097,  1105,  1109,  1116,  1119,
    1123,  1130,  1138,  1146,  1154,  1165,  1168,  1174,  1182,  1186,
    1189,  1189,  1206,  1214,  1217,  1223,  1226,  1232,  1235,  1241,
    1245,  1252,  1255,  1261,  1269,  1273,  1280,  1284,  1290,  1298,
    1304,  1313,  1316,  1324,  1327,  1333,  1334,  1341,  1344,  1351,
    1355,  1361,  1362,  1363,  1364,  1365,  1366,  1370,  1377,  1384,
    1391,  1401,  1410,  1422,  1425,  1432,  1435,  1440,  1443,  1450,
    1458,  1464,  1474,  1488,  1493,  1499,  1505,  1511,  1517,  1523,
    1529,  1535,  1541,  1547,  1553,  1559,  1564,  1569,  1574,  1579,
    1585,  1591,  1597,  1603,  1609,  1615,  1621,  1627,  1653,  1659,
    1665,  1671,  1677,  1683,  1689,  1695,  1700,  1705,  1710,  1715,
    1721,  1727,  1733,  1739,  1745,  1751,  1757,  1763,  1769,  1770,
    1771,  1779,  1787,  1788,  1793,  1798,  1803,  1808,  1813,  1818,
    1823,  1828,  1833,  1837,  1838,  1839,  1840,  1845,  1851,  1865,
    1888,  1894,  1900,  1906,  1915,  1919,  1922,  1930,  1933,  1938,
    1942,  1951,  1956,  1963,  1969,  1978,  1987,  1996,  2005,  2013,
    2016,  2019,  2023,  2030,  2033,  2037,  2044,  2045,  2049,  2064,
    2068,  2071,  2077,  2083,  2086,  2090,  2098,  2101,  2107,  2110,
    2113,  2116,  2119,  2122,  2125,  2128,  2131,  2134,  2137,  2140,
    2146,  2147,  2148,  2152,  2156,  2161,  2166,  2171,  2176,  2180,
    2188,  2189,  2190,  2191,  2194,  2197,  2201,  2204,  2210,  2213,
    2217,  2228,  2235,  2242,  2252,  2253,  2257,  2261,  2265,  2269,
    2295,  2299,  2302,  2308,  2318,  2324,  2333,  2339,  2340,  2341,
    2347,  2348,  2363,  2368,  2376,  2380,  2386,  2395,  2396,  2397,
    2401,  2402,  2405,  2417,  2421,  2427,  2433,  2437,  2440,  2448,
    2451,  2457,  2458,  2462,  2468,  2474,  2478,  2482,  2488,  2491,
    2506,  2509,  2516,  2517,  2521,  2527,  2530,  2536,  2543,  2550,
    2557,  2564,  2571,  2578,  2585,  2595,  2605,  2615,  2618,  2621,
    2631,  2634,  2640,  2644,  2650,  2655,  2661,  2667,  2673,  2682,
    2687,  2695,  2704,  2709
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
  "statement", "unticked_statement", "additional_catches",
  "finally_statement", "non_empty_additional_catches", "additional_catch",
  "unset_variables", "unset_variable", "function_declaration_statement",
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
    -678,    66,  1803,  -678,  6315,  6315,  -109,  6315,  6315,  6315,
    6315,  6315,  6315,  6315,   552,   552,  6315,  6315,  6315,  6315,
    6315,  6315,  6315,  6315,  4743,   574,  6315,   -87,   -79,  -678,
    -678,    55,  -678,  -678,  -678,    50,  -678,  6315,  4603,     3,
      83,    96,   100,   109,  4874,  5005,   114,  -678,   140,  5136,
     102,  6315,   -40,   -31,   -34,   154,   166,   133,   152,   161,
     165,  -678,  -678,   170,   187,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,    87,  -678,  -678,   275,  -678,  -678,
    6315,  6446,  -678,  -678,   190,   -83,  -678,    16,  -678,  -678,
    -678,  -678,  -678,  -678,   289,   293,  -678,   218,   350,   324,
     245,  -678,  -678,  6725,  -678,   174,  1321,   238,  -678,   252,
     338,   278,  -678,    53,  -678,    39,  -678,  -678,   341,   346,
    -678,  -678,  -678,   310,   262,  -678,   350,  7537,  7537,  6315,
    7537,  7537,  7637,  -678,  -678,   371,  -678,  -678,   268,   275,
     357,   -88,   277,  -678,  -678,   283,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,   552,  7301,   266,   425,   285,
     275,   286,   295,   276,  -678,   300,   314,   -28,    39,  -678,
    5267,  -678,  6315,  -678,  6315,    17,  7537,   362,  6315,  6315,
    6315,   378,  6315,  -678,  6766,  -678,  6807,   306,   440,  -678,
     307,  7537,  1197,  -678,  6859,   275,   -45,    18,  -678,  -678,
     436,    19,  -678,   441,    21,   350,  -678,  -678,   552,   552,
     552,   296,   368,  4743,   275,  -678,    92,   158,    86,  7342,
     934,   309,  6900,   313,  1943,  6315,   400,  5398,   403,  -678,
     364,   365,  -678,  -678,   -23,  6315,    52,  6315,  6315,  6315,
    5529,  6315,  6315,  6315,  6315,  6315,  6315,  6315,  6315,  6315,
    6315,  6315,  6315,  6315,  6315,  6315,  6315,  6315,  6315,  6315,
    6315,  6315,   574,  -678,  -678,  -678,  5660,  6315,  6315,  6315,
    6315,  6315,  6315,  6315,  6315,  6315,  6315,  6315,  5398,    76,
    6315,    49,  6315,  6315,   190,   -35,  6315,  6315,   326,  6941,
     275,    70,   313,    84,   126,  -678,  -678,  5791,  -678,  5922,
    -678,   275,   286,    43,  5398,  -678,    43,    49,    -9,  -678,
    6993,  7035,  7537,   327,  6315,  -678,   335,  7076,   340,   487,
    7537,   405,  3920,   488,     6,  7126,  -678,  -678,  -678,  7408,
    -678,  -678,  2083,  -678,   -36,   430,   -40,  -678,  6315,  -678,
    -678,   -31,  -678,  7408,   432,  -678,   352,    29,  -678,  -678,
    -678,    30,   354,   355,   366,  -678,    32,  -678,   361,   167,
    1502,  1803,  -678,  5398,  6315,  -678,  -678,  -678,   381,  -678,
    -678,  -678,  -678,  -678,  1235,  -678,   552,   369,   532,    34,
      77,   528,     5,   419,     5,   382,   389,   291,   385,   392,
     393,    -9,    39,  7577,  7614,  7637,  6315,  7465,  7682,  7703,
    4796,  4927,  1795,  1935,  1935,  1935,  1935,  1652,  1652,  1652,
    1652,   717,   717,   294,   294,   294,   371,   371,   371,  -678,
     247,  7637,  7637,  7637,  7637,  7637,  7637,  7637,  7637,  7637,
    7637,  7637,  7637,   394,   397,   399,   388,  -678,  6315,  -678,
     404,    -7,  -678,   401,  1278,   406,   413,  -678,   111,   392,
     397,   552,  7537,   552,  7400,   286,  -678,   408,  -678,  -678,
    -678,  3903,  -678,  7537,  6315,  4043,  6315,  6315,   552,   186,
    7408,   495,  4183,    -3,  7408,  7408,  7408,  -678,   420,   429,
     275,    22,   443,  -678,  -678,  -678,   476,   518,  -678,  -678,
    6589,  -678,  -678,   579,   291,   552,   438,   552,  -678,  -678,
    -678,   368,   368,   583,  -678,  5398,  -678,  -678,  1663,   449,
     148,   999,   451,  -678,  -678,  -678,  6053,  7408,   461,   275,
     286,  -678,     5,   454,   608,  -678,  -678,   291,  -678,  -678,
     458,   610,     1,  -678,  -678,  5398,  5398,    -9,  7660,  6315,
     574,  -678,  -678,  5398,  5398,  -678,  6630,  5398,   557,   558,
    -678,  6315,  6315,  -678,  -678,  -678,  -678,  -678,  -678,  6184,
    -678,   498,  -678,  -678,  7168,  -678,  -678,  -678,   464,  7537,
     501,   552,   501,  -678,  -678,   615,  -678,  -678,  -678,   471,
     472,  -678,  -678,  -678,   508,   470,   627,  7408,   275,   147,
     567,   483,  -678,  -678,  7408,   484,  -678,  -678,  -678,    35,
    -678,  6315,   485,  -678,  -678,   491,   552,    37,   123,  -678,
     275,   286,   608,  -678,     5,   640,   493,   547,   199,   582,
     645,   500,   503,  7660,   276,   504,   505,  -678,   506,  6315,
    6315,   536,   502,  6671,   552,  7537,    49,  -678,  3763,   202,
     509,  2223,  6315,   186,   512,  -678,   513,  7408,  2363,  -678,
     182,  -678,     7,  7408,  -678,  7408,  -678,   514,   176,  -678,
       5,  -678,   547,  -678,  7637,  -678,  -678,  -678,   286,   680,
    -678,   601,     5,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,   600,   310,   348,  -678,    23,   516,   520,
     519,   141,   666,  7408,  -678,  -678,  -678,  -678,  -678,  -678,
     526,   530,    49,  -678,  -678,  -678,  -678,  -678,   267,   537,
    4603,  -678,  -678,   524,   538,  -678,  4323,  4323,  -678,   541,
     273,   544,  6315,     4,   122,  -678,  -678,   573,  -678,   630,
     545,  -678,   694,    10,  -678,   695,    26,  -678,  -678,   643,
    -678,  -678,   169,  -678,   638,   704,  7408,  -678,  -678,  -678,
     404,   562,   698,   651,  6315,  -678,  -678,  4463,  -678,  -678,
    -678,  -678,  -678,   566,  -678,  1434,  -678,  -678,  -678,  -678,
    7408,   568,  -678,  7408,     5,  -678,   151,  -678,  7408,   653,
    -678,   350,   718,  2503,   658,  -678,    38,  2643,   722,  7408,
    -678,  -678,  6315,  -678,   576,  7209,  -678,  -678,  -678,  2783,
    -678,  -678,  3763,  -678,   577,  2923,  -678,  -678,   647,   581,
     151,  -678,   584,   652,   594,   596,   613,  -678,   754,   699,
    7408,  -678,  -678,   189,  -678,  -678,  7408,  -678,  7259,  3763,
    -678,  4603,  3063,   620,  3763,  -678,  -678,  -678,  -678,  -678,
     665,     5,  -678,   710,  7408,   628,  -678,   721,  -678,  -678,
     772,  -678,   639,  -678,  3203,   728,   733,   799,  -678,  -678,
    -678,   291,  -678,  -678,  -678,   703,  -678,     5,   650,  3763,
     654,   656,   703,  -678,  -678,   194,     5,   649,  -678,  -678,
    -678,  -678,  -678,   739,  -678,  3343,   657,  3483,  -678,   659,
    -678,  -678,  3623,  -678
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
     208,   355,   356,     0,     0,     0,    43,    45,    62,     0,
      47,    48,     0,    61,    20,     0,     0,    14,     0,   149,
     356,     0,    49,     0,     0,    50,     0,     0,    70,    72,
     422,     0,     0,     0,     0,   402,     0,   401,     0,   343,
       0,     0,     4,   139,     0,   425,   424,   381,     0,    35,
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
      10,   404,   404,     0,   429,   139,    13,    11,     0,     0,
     355,   356,     0,   388,   142,   291,     0,     0,     0,     0,
     303,    85,     0,     0,    88,    91,   156,   134,   136,   137,
       0,   124,     0,   135,   376,   139,   139,   371,   261,     0,
       0,   211,   298,   139,   139,   375,     0,   139,   368,   367,
     362,   389,     0,   384,   385,   427,   426,   413,   412,     0,
     317,   308,    25,   116,     0,    25,   114,    38,     0,   207,
      93,     0,    93,    95,   103,     0,    25,   101,    58,   109,
     109,    41,   334,   335,   353,     0,   348,   346,     0,   333,
       0,     0,    21,   150,     0,     0,    71,    55,   423,     0,
     400,     0,     0,    12,   293,     0,     0,   355,   356,    22,
       0,   305,    90,   156,     0,   187,     0,   285,   134,     0,
     126,     0,     0,   260,   316,     0,     0,   397,     0,   389,
     389,   359,     0,     0,     0,   407,     0,   310,   118,   120,
       0,     0,   205,     0,     0,    96,     0,     0,     0,   109,
       0,   109,     0,     0,   337,   349,   347,     0,   332,   339,
       0,   152,   285,   403,   209,   292,    29,   145,   304,   187,
      92,     0,     0,   194,   195,   196,   193,   192,   191,   186,
      79,   155,   159,     0,     0,   185,   189,     0,     0,     0,
       0,     0,   127,     0,   294,   297,   212,   295,   296,   366,
       0,     0,     0,   361,   393,   394,   411,   312,   122,     0,
       0,    36,    39,     0,     0,    94,     0,     0,   104,     0,
       0,     0,     0,     0,     0,   105,   352,   351,   336,     0,
       0,    78,     0,     0,   163,   199,     0,   160,   190,     0,
     158,    25,     0,    25,     0,   130,     0,   129,   364,   365,
     369,     0,     0,     0,     0,   121,   115,     0,    25,    99,
      57,    56,   102,     0,   107,     0,   112,   113,    25,   106,
       0,     0,    25,     0,     0,   165,   167,   162,     0,     0,
     157,    75,     0,     0,     0,   289,     0,     0,   131,     0,
     128,   363,     0,    25,     0,     0,    25,    97,    40,     0,
     108,    25,   111,   350,     0,     0,   202,   164,     5,     0,
     168,   169,     0,     0,   177,     0,     0,   200,   197,     0,
       0,    77,   290,     0,   286,   278,     0,   133,     0,   123,
      37,     0,     0,     0,   110,    25,   279,   166,   170,   171,
     181,     0,   172,     0,     0,     0,   201,     0,   287,   132,
       0,   117,     0,   100,     0,     0,   180,   173,   174,   178,
     198,   134,   288,    25,    98,    64,   179,     0,     0,   119,
       0,    65,    63,    67,   175,     0,     0,     0,    60,    68,
     183,    25,   161,     0,    25,     0,     0,     0,   184,     0,
      66,    25,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -678,  -678,  -194,    -5,   456,  -678,   482,  -678,  -182,  -678,
      13,  -678,  -678,  -678,  -678,   -53,  -678,   329,     0,    15,
    -125,  -678,  -678,  -678,  -678,  -678,  -678,  -678,   303,   250,
     183,  -678,   112,  -678,  -678,  -678,  -544,    63,  -678,  -678,
    -678,  -678,  -678,  -472,  -678,   213,  -112,  -678,  -678,   492,
    -678,   221,  -678,  -678,  -678,  -678,  -678,  -678,  -678,    25,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -677,  -678,  -678,  -678,  -460,  -678,    28,   756,    -2,   178,
    -678,  -678,   217,  -272,  -257,  -678,  -678,  -678,  -678,   214,
    -241,  -290,  -678,  -678,   254,   257,  -678,   895,   646,  -369,
     370,   879,  -678,  -678,  -678,  -678,    95,  -220,  -678,   105,
    -678,  -678,   -22,    -6,  -678,  -222,  -303,  -678,  -678,   -13,
     347,   345,   636,  -678,  -678,  -678,  -678,  -678,  -678,     8,
    -678
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   197,   198,    87,   224,   370,
     371,    89,   871,   878,   872,   873,   347,   348,   372,   373,
     234,    92,    93,    94,   383,    95,   385,   523,   524,   644,
     572,   798,   760,   578,   324,   581,   650,   768,   567,   639,
     708,   711,   753,   530,   531,   532,   377,   378,   201,   202,
     204,   615,   681,   781,   682,   733,   777,   809,   810,   811,
     812,   857,   813,   814,   815,   855,   882,   683,   684,   685,
     686,   736,   687,   175,   318,   319,    96,    97,   126,   690,
     786,    99,   100,   533,   163,   164,   561,   637,   171,   305,
     101,   584,   485,   102,   585,   300,   586,   103,   104,   295,
     105,   106,   631,   703,   548,   549,   550,   107,   108,   109,
     110,   111,   112,   113,   114,   313,   440,   441,   442,   115,
     356,   357,   157,   158,   116,   351,   117,   118,   119,   120,
     121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   288,    90,   166,   459,   419,   568,   514,   738,   141,
     141,   332,   168,   388,   471,    88,   390,    91,   774,   167,
     161,   360,   595,   579,   228,   314,   336,   341,   282,   344,
     766,   739,   619,   122,   779,   282,   652,   495,   497,   484,
     502,   203,  -140,   502,   199,  -143,   823,   196,   335,   129,
     386,   177,   205,   492,   282,   616,   551,   487,   436,   435,
     443,   439,  -300,   226,   445,   446,     3,    47,   226,   216,
     227,   170,   217,   390,   435,   227,   620,   190,   122,   172,
     346,   173,   557,   456,   558,  -141,   458,   439,   483,   223,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   483,   722,   723,   720,   226,   724,   218,   285,
     521,   195,   525,   174,    33,   226,   282,  -374,    33,   145,
     145,   205,   437,  -371,    33,   389,   283,    33,  -358,  -358,
     165,  -144,   200,   283,   291,   387,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   292,   434,
     141,    33,   283,   518,   552,   302,   519,   449,   580,    33,
     122,   178,   308,   856,   767,   472,   433,  -300,   508,   725,
     775,   776,   744,   226,  -358,  -358,   229,   315,   337,   342,
     574,   345,   714,   740,   582,   583,   780,   187,   496,   498,
     334,   503,   457,  -140,   663,   141,  -143,   824,  -374,   450,
     784,    33,   284,   141,   141,   141,    84,   141,   321,   359,
     438,  -370,    84,   188,   283,    84,   745,   571,   722,   723,
     847,   226,    98,   392,   808,   264,   265,   609,   363,   483,
     391,   142,   142,   483,   483,   483,  -141,   667,   214,    84,
     166,   179,   162,   226,   785,  -280,  -280,    84,   215,   168,
     525,   509,   361,   362,   180,   379,   167,   161,   181,   122,
     145,    33,   226,   193,   848,   706,   392,   182,   392,   505,
     709,   710,   122,   391,   206,   391,   483,   721,   722,   723,
     392,   392,  -144,   624,   769,   448,   207,   391,   391,    84,
     392,   208,  -302,   392,   392,   137,   455,   391,   226,   518,
     391,   391,   519,  -302,   661,   145,   379,  -282,  -282,   226,
     209,   540,  -301,   145,   145,   145,   363,   145,   226,   210,
     122,  -301,    33,   211,   481,   505,   528,   226,   212,   632,
      98,   196,   379,   707,   138,   751,   752,   139,   481,   259,
     260,   261,   670,   262,   140,   213,   483,   518,   122,    84,
     519,   225,   529,   483,   880,   881,   137,   718,    98,    98,
      90,    90,   230,   726,   122,   727,   231,   165,   763,   722,
     723,   141,   142,    88,    88,    91,    91,   520,   232,   520,
     638,   233,   520,   641,   143,   146,   537,   235,   729,   868,
     236,   379,   510,   602,   648,   138,   278,   279,   139,   750,
     734,   280,   281,   747,   286,   140,   483,   700,   701,   287,
      84,    47,   483,   214,   483,   141,   439,   142,   528,   290,
     262,    25,   293,   621,   622,   142,   142,   142,   294,   142,
     298,   625,   626,   299,   304,   628,   301,   226,   307,   518,
     303,   122,   519,    33,   529,   306,   141,   316,   141,  -188,
    -125,   323,   483,   329,   343,   353,   790,   673,   674,   675,
     676,   677,   678,   141,   141,   481,   328,   330,   365,   481,
     481,   481,   367,   375,   563,   589,   381,   137,   566,   162,
     803,   145,   439,   806,   387,   577,   382,   384,   817,   520,
     141,   462,   141,   464,   354,   467,   141,   141,   468,   827,
     466,   470,   807,   488,   816,   483,    98,   493,    90,   122,
     494,    33,   481,   499,   611,   500,   138,   520,   166,   139,
     504,    88,   520,    91,   501,   145,   140,   168,   515,   483,
     846,    84,   483,   379,   167,   161,   849,   483,   816,   512,
     516,   517,   522,   526,   607,   137,   482,   527,   483,   534,
     535,   536,   545,   542,   860,   543,   145,   544,   145,   783,
     482,   787,   547,   379,   379,   553,   141,   560,   575,   858,
     555,   379,   379,   145,   145,   379,   799,   556,   587,   483,
     588,   591,   481,   658,   138,   483,   802,   139,   590,   481,
     805,   592,   594,   142,   140,   874,   601,   338,   597,    84,
     145,   141,   145,   483,   883,   668,   145,   145,   604,   520,
     605,   829,   610,   520,   832,   613,   614,   617,   618,   834,
     629,   630,   636,   392,   642,   122,   643,    33,   647,   141,
     391,   649,   651,   653,   654,   655,    98,   142,   141,    98,
     659,   660,   481,   662,   665,   165,    98,   122,   481,    33,
     481,   666,   688,   854,   689,   520,   819,   692,   693,   694,
     702,   137,   695,   697,   698,   699,   704,   520,   142,   712,
     142,   716,   717,   728,   732,   735,   145,   741,   742,   746,
     743,   869,   737,   137,   756,   142,   142,   482,   481,   392,
     748,   482,   482,   482,   749,   754,   391,   757,   770,   885,
     138,   762,   887,   139,   764,   771,   772,   773,   778,   892,
     140,   145,   142,   788,   142,    84,   782,   789,   142,   142,
     792,   794,   159,   755,   793,   160,   800,   804,   818,   759,
     759,   820,   140,   822,   482,   826,   830,    84,   835,   145,
    -176,   481,   671,   837,   839,   840,   841,   672,   145,   673,
     674,   675,   676,   677,   678,   679,   842,   162,   843,   256,
     257,   258,   259,   260,   261,   481,   262,   844,   481,   520,
     797,   520,   845,   481,   673,   674,   675,   676,   677,   678,
     853,    98,   671,   859,   481,    98,   861,   672,   142,   673,
     674,   675,   676,   677,   678,   679,   862,    98,   863,   864,
      98,   866,   680,    98,   482,   520,  -182,   867,   870,   875,
     884,   482,   876,   877,   886,   481,   889,   507,   489,   879,
     891,   481,   646,   142,   596,   612,   715,    98,   801,   761,
      98,   691,    98,   491,   669,   838,   520,   221,   696,   481,
     730,   657,   731,   656,   851,   791,   339,   600,   599,   358,
       0,   142,    98,     0,     0,     0,   520,     0,     0,     0,
     142,     0,   520,     0,   482,     0,     0,    98,     0,     0,
     482,   520,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,    98,     0,     0,     0,     0,
      98,     0,     0,   144,   144,     0,     0,     0,     0,   127,
     128,     0,   130,   131,   132,   133,   134,   135,   136,     0,
     482,   147,   148,   149,   150,   151,   152,   153,   154,   156,
       0,   169,     0,     0,     0,     0,     0,     0,   192,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,   184,
     186,     0,     0,     0,   191,     0,   194,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   220,
       0,     0,     0,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   222,     0,     0,     0,
       0,     0,     0,     0,     0,  -358,  -358,   482,     0,     0,
     482,     0,     0,     0,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   482,     0,     0,     0,
       0,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,   482,     0,     0,
       0,     0,     0,   482,     0,     0,     0,     0,     0,     0,
    -358,  -358,     0,     0,     0,     0,     0,     0,     0,   322,
       0,   482,     0,     0,     0,   310,     0,   311,     0,   312,
       0,     0,     0,   317,   320,   191,     0,   325,     0,   340,
       0,     0,     0,     0,     0,     0,     0,   349,   350,   352,
       0,   355,     0,  -281,  -281,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     374,     0,   191,     0,     0,     0,     0,     0,     0,     0,
     312,     0,   393,   394,   395,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   380,  -283,  -283,
       0,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   191,     0,   312,     0,   312,   444,     0,
       0,   312,   312,   380,     0,     0,     0,     0,     0,     0,
       0,     0,   452,     0,   454,     0,     0,     0,     0,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,   380,   511,   237,   238,   239,     0,  -358,  -358,
       0,     0,     0,     0,     0,   296,     0,     0,   191,   191,
     240,     0,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,     0,     0,   237,   238,   239,
       0,   538,     0,     0,     0,     0,     0,     0,     0,   541,
       0,     0,     0,   240,     0,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,     0,     0,
     296,     0,   296,   546,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,   570,   573,     0,
       0,     0,     0,     0,     0,     0,     0,   331,     0,   564,
       0,   320,   569,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -358,  -358,   349,     0,   598,     0,     0,     0,
     355,   355,     0,     0,   380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,     0,   513,     0,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,     0,     0,   380,   380,     0,     0,     0,     0,
       0,     0,   380,   380,     0,     0,   380,     0,     0,     0,
     191,   191,     0,     0,   623,     0,     0,     0,   191,   191,
     554,     0,   191,   237,   238,   239,   312,   633,     0,     0,
     645,     0,     0,     0,   635,     0,     0,     0,     0,   240,
     766,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   664,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       0,     0,     0,   296,     9,     0,     0,     0,     0,     0,
       0,     0,   573,     0,   312,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   320,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,     0,    34,
       0,     0,     0,    35,    36,    37,    38,    39,     0,    40,
       0,    41,     0,    42,   767,     0,    43,     0,     0,     0,
      44,    45,    46,    47,    48,    49,    50,     0,    51,    52,
      53,    54,    55,    56,     0,     0,     0,   765,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,    70,    71,     0,
      72,     0,     0,     0,    73,     0,     0,     0,     0,   795,
      74,    75,    76,    77,     0,     0,    78,    79,    80,     0,
      81,     0,    82,    83,   506,    84,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   828,  -375,  -375,
    -375,  -375,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,     0,     0,     0,    10,    11,     0,     0,     0,
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
       0,    81,     0,    82,    83,   603,    84,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,    10,    11,     0,     0,     0,
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
       0,    81,     0,    82,    83,     0,    84,  -375,  -375,  -375,
    -375,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   369,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   486,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,   713,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,   719,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   821,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   825,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,   833,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   836,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,   852,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   865,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   888,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   890,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,   893,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,   368,    61,    62,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,    78,    79,    80,
       0,    81,     0,    82,    83,     0,    84,     0,     0,   562,
       0,     0,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,  -358,  -358,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,    49,    50,     0,    51,
       0,    53,    54,   469,     0,     0,     0,     0,     0,    57,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     4,     5,     6,     7,
       8,   124,    75,    76,    77,     9,     0,     0,    79,    80,
       0,    81,     0,    82,    83,     0,    84,     0,     0,   565,
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
       0,    81,     0,    82,    83,     0,    84,     0,     0,   576,
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
       0,    81,     0,    82,    83,     0,    84,     0,     0,   758,
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
       0,    81,     0,    82,    83,     0,    84,     0,     0,   796,
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
       0,    81,     0,    82,    83,     0,    84,     0,     0,     0,
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
       0,    81,     0,    82,    83,     0,    84,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,    29,    30,   122,    32,    33,     0,
       0,     0,     0,     0,    35,    36,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,    47,   262,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    73,     9,     0,     0,     0,
       0,   124,    75,    76,    77,     0,     0,     0,    79,   125,
       0,    81,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    29,    30,   122,    32,    33,
       0,     0,     0,     0,     0,    35,    36,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,    47,   262,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     4,     5,
       6,     7,     8,     0,     0,     0,    73,     9,     0,     0,
       0,     0,   124,    75,    76,    77,     0,     0,     0,    79,
     125,     0,    81,     0,   183,     0,     0,    84,     0,     0,
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
      79,   125,     0,    81,     0,   185,     0,     0,    84,     0,
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
       0,    79,   125,     0,    81,     0,   189,     0,     0,    84,
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
       0,     0,    79,   125,     0,    81,   309,     0,     0,   376,
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
       0,     0,     0,    79,   125,   396,    81,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   420,    84,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,   451,    84,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   453,    84,     0,     0,     0,     0,     0,
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
      81,     0,     0,     0,   606,    84,     0,     0,     0,     0,
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
       0,    81,     0,     0,     0,   634,    84,     0,     0,     0,
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
     125,     0,    81,     0,     0,     0,     0,    84,     0,     0,
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
      79,   125,     0,    81,     0,     0,     0,     0,    84,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,   124,    75,    76,    77,   237,   238,
     239,    79,    80,     0,    81,     0,     0,     0,     0,    84,
       0,     0,     0,     0,   240,     0,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,     0,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   593,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   627,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   705,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   263,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   326,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   327,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   333,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,     0,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   366,
     240,     0,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,   240,     0,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   460,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,     0,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   461,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   465,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   473,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   640,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   831,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,   850,     0,
       0,     0,     0,     0,     0,   240,   297,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     474,   475,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,     0,     0,
       0,   476,     0,     0,   237,   238,   239,     0,     0,    29,
      30,   122,     0,     0,     0,     0,     0,     0,     0,   477,
     240,   539,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,     0,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   559,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   478,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,   237,   238,   239,     0,
      73,     0,     0,     0,     0,     0,   479,    75,    76,   480,
       0,     0,   240,    79,   241,   242,   243,   244,   245,   246,
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
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262
};

static const yytype_int16 yycheck[] =
{
       2,   126,     2,    25,   307,   262,   466,   376,   685,    14,
      15,   193,    25,   235,     8,     2,   236,     2,     8,    25,
      25,   215,   494,    26,     8,     8,     8,     8,    63,     8,
      26,     8,    31,    73,     8,    63,   580,     8,     8,   329,
       8,    75,     8,     8,    75,     8,     8,    52,    93,   158,
      73,    38,    54,   343,    63,   527,    63,    93,   280,   279,
     282,   281,   145,   151,   286,   287,     0,   101,   151,    74,
     158,   158,    77,   293,   294,   158,    75,    49,    73,   158,
     205,    26,   451,   303,   453,     8,   306,   307,   329,    81,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   343,    96,    97,   649,   151,   651,    80,   115,
     382,   151,   384,    63,    75,   151,    63,   145,    75,    14,
      15,   123,    73,   158,    75,    73,   161,    75,    51,    52,
      25,     8,   163,   161,   139,   158,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   140,    73,
     155,    75,   161,   148,   161,   160,   151,    73,   161,    75,
      73,   158,   168,   840,   160,   159,   278,   145,   362,   162,
     160,   161,    31,   151,    51,    52,   160,   160,   160,   160,
     470,   160,   642,   160,   474,   475,   160,    73,   159,   159,
     195,   159,   304,   159,   159,   200,   159,   159,   145,    73,
      31,    75,   163,   208,   209,   210,   163,   212,   180,   214,
     161,   158,   163,    73,   161,   163,    75,    31,    96,    97,
      31,   151,   224,   236,    73,    51,    52,   517,   158,   470,
     236,    14,    15,   474,   475,   476,   159,   606,   151,   163,
     262,   158,    25,   151,    75,   159,   160,   163,   161,   262,
     522,   363,   160,   161,   158,   227,   262,   262,   158,    73,
     155,    75,   151,   161,    75,   634,   279,   158,   281,   158,
      68,    69,    73,   279,   120,   281,   517,    95,    96,    97,
     293,   294,   159,   540,   162,   290,   120,   293,   294,   163,
     303,   158,   145,   306,   307,   109,   301,   303,   151,   148,
     306,   307,   151,   145,   594,   200,   278,   159,   160,   151,
     158,    64,   145,   208,   209,   210,   158,   212,   151,   158,
      73,   145,    75,   158,   329,   158,   127,   151,   158,   551,
     332,   336,   304,   636,   148,    68,    69,   151,   343,    45,
      46,    47,   614,    49,   158,   158,   587,   148,    73,   163,
     151,   161,   153,   594,   160,   161,   109,   647,   360,   361,
     360,   361,    73,   653,    73,   655,    73,   262,    95,    96,
      97,   376,   155,   360,   361,   360,   361,   382,   160,   384,
     562,    31,   387,   565,    14,    15,   392,    63,   660,   861,
     145,   363,   364,   505,   576,   148,   158,   145,   151,   702,
     672,    63,   124,   693,    63,   158,   647,   629,   630,    63,
     163,   101,   653,   151,   655,   420,   636,   200,   127,   151,
      49,    64,   145,   535,   536,   208,   209,   210,   145,   212,
     164,   543,   544,     8,   158,   547,   151,   151,   124,   148,
     145,    73,   151,    75,   153,   145,   451,    85,   453,   101,
     159,    73,   693,    13,    13,   159,   746,   109,   110,   111,
     112,   113,   114,   468,   469,   470,   160,   160,   159,   474,
     475,   476,   159,    73,   461,   480,    73,   109,   465,   262,
     770,   376,   702,   773,   158,   472,   122,   122,   778,   494,
     495,   164,   497,   158,   126,     8,   501,   502,    93,   789,
     160,    13,   774,    73,   776,   746,   508,    75,   508,    73,
     158,    75,   517,   159,   519,   160,   148,   522,   540,   151,
     159,   508,   527,   508,   158,   420,   158,   540,   159,   770,
     820,   163,   773,   505,   540,   540,   826,   778,   810,   158,
       8,    13,   123,   161,   516,   109,   329,   158,   789,   164,
     158,   158,   164,   159,   844,   158,   451,   158,   453,   741,
     343,   743,   158,   535,   536,   164,   571,   159,    73,   841,
     164,   543,   544,   468,   469,   547,   758,   164,   158,   820,
     151,   105,   587,   588,   148,   826,   768,   151,   145,   594,
     772,    73,    13,   376,   158,   867,    13,   161,   160,   163,
     495,   606,   497,   844,   876,   610,   501,   502,   159,   614,
     159,   793,   151,   618,   796,   161,     8,   159,     8,   801,
      63,    63,   124,   636,   160,    73,   125,    75,    13,   634,
     636,   160,   160,   125,   164,     8,   638,   420,   643,   641,
      73,   158,   647,   159,   159,   540,   648,    73,   653,    75,
     655,   160,   159,   835,   107,   660,   781,    75,    13,   159,
     124,   109,   159,   159,   159,   159,   164,   672,   451,   160,
     453,   159,   159,   159,    73,    75,   571,   161,   158,    13,
     161,   863,   684,   109,   160,   468,   469,   470,   693,   702,
     164,   474,   475,   476,   164,   158,   702,   159,   125,   881,
     148,   160,   884,   151,   160,    75,   161,    13,    13,   891,
     158,   606,   495,    75,   497,   163,    73,    13,   501,   502,
     158,    70,   148,   710,    26,   151,   160,   159,    75,   716,
     717,    13,   158,    75,   517,    13,   160,   163,   161,   634,
      93,   746,   102,   162,   160,    93,   152,   107,   643,   109,
     110,   111,   112,   113,   114,   115,   160,   540,   145,    42,
      43,    44,    45,    46,    47,   770,    49,    13,   773,   774,
     757,   776,    73,   778,   109,   110,   111,   112,   113,   114,
     160,   783,   102,    73,   789,   787,   158,   107,   571,   109,
     110,   111,   112,   113,   114,   115,    75,   799,    26,   160,
     802,    73,   162,   805,   587,   810,    73,     8,   105,   159,
     161,   594,   158,   157,    75,   820,   159,   361,   336,   872,
     161,   826,   572,   606,   495,   522,   643,   829,   765,   717,
     832,   618,   834,   341,   613,   810,   841,    81,   624,   844,
     662,   587,   162,   586,   831,   750,   200,   502,   501,   213,
      -1,   634,   854,    -1,    -1,    -1,   861,    -1,    -1,    -1,
     643,    -1,   867,    -1,   647,    -1,    -1,   869,    -1,    -1,
     653,   876,   655,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   885,    -1,   887,    -1,    -1,    -1,    -1,
     892,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
     693,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    49,    -1,    51,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    80,
      -1,    -1,    -1,   746,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,   770,    -1,    -1,
     773,    -1,    -1,    -1,    -1,   778,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,    -1,   820,    -1,    -1,
      -1,    -1,    -1,   826,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
      -1,   844,    -1,    -1,    -1,   170,    -1,   172,    -1,   174,
      -1,    -1,    -1,   178,   179,   180,    -1,   182,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,
      -1,   212,    -1,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   278,   159,   160,
      -1,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    -1,   280,    -1,   282,   283,    -1,
      -1,   286,   287,   304,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,   299,    -1,    -1,    -1,    -1,   304,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   363,   364,     9,    10,    11,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,   363,   364,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,     9,    10,    11,
      -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
     451,    -1,   453,   438,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,   468,   469,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,   464,
      -1,   466,   467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,   495,    -1,   497,    -1,    -1,    -1,
     501,   502,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,   162,    -1,    -1,
     505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   516,    -1,    -1,   535,   536,    -1,    -1,    -1,    -1,
      -1,    -1,   543,   544,    -1,    -1,   547,    -1,    -1,    -1,
     535,   536,    -1,    -1,   539,    -1,    -1,    -1,   543,   544,
     162,    -1,   547,     9,    10,    11,   551,   552,    -1,    -1,
     571,    -1,    -1,    -1,   559,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,   606,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   634,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,    -1,   629,   630,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   642,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    77,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,    87,
      -1,    89,    -1,    91,   160,    -1,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,   722,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,   135,   136,    -1,
     138,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   754,
     148,   149,   150,   151,    -1,    -1,   154,   155,   156,    -1,
     158,    -1,   160,   161,   162,   163,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   792,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    92,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    90,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    88,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,   154,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    26,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    51,    52,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    93,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,    -1,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,    -1,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,    -1,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,    -1,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,    -1,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,     6,
       7,   148,   149,   150,   151,    12,    -1,    -1,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   101,    49,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
      -1,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   101,    49,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,    -1,   158,    -1,   160,    -1,    -1,   163,    -1,    -1,
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
     155,   156,    -1,   158,    -1,   160,    -1,    -1,   163,    -1,
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
      -1,   155,   156,    -1,   158,    -1,   160,    -1,    -1,   163,
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
      -1,    -1,   155,   156,    -1,   158,   159,    -1,    -1,    31,
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
      -1,    -1,    -1,   155,   156,    26,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    31,   163,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    31,   163,    -1,    -1,    -1,    -1,    -1,
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
     158,    -1,    -1,    -1,    31,   163,    -1,    -1,    -1,    -1,
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
      -1,   158,    -1,    -1,    -1,    31,   163,    -1,    -1,    -1,
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
     156,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
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
     155,   156,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,     9,    10,
      11,   155,   156,    -1,   158,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   162,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   162,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   162,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   160,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   160,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   159,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   159,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   159,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   159,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   159,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   159,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   125,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      -1,    63,    -1,    -1,     9,    10,    11,    -1,    -1,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
     142,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,    25,   155,    27,    28,    29,    30,    31,    32,
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
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49
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
     160,   158,     8,   159,   159,   158,   162,   169,   167,   211,
     241,   266,   158,   162,   264,   159,     8,    13,   148,   151,
     168,   248,   123,   192,   193,   248,   161,   158,   127,   153,
     208,   209,   210,   248,   164,   158,   158,   278,   262,    26,
      64,   266,   159,   158,   158,   164,   262,   158,   269,   270,
     271,    63,   161,   164,   162,   164,   164,   264,   264,   125,
     159,   251,    26,   175,   262,    26,   175,   203,   239,   262,
     266,    31,   195,   266,   256,    73,    26,   175,   198,    26,
     161,   200,   256,   256,   256,   259,   261,   158,   151,   168,
     145,   105,    73,   162,    13,   208,   182,   160,   266,   285,
     286,    13,   211,   162,   159,   159,    31,   241,   266,   256,
     151,   168,   193,   161,     8,   216,   208,   159,     8,    31,
      75,   211,   211,   262,   249,   211,   211,   162,   211,    63,
      63,   267,   280,   262,    31,   262,   124,   252,   173,   204,
     159,   173,   160,   125,   194,   266,   194,    13,   173,   160,
     201,   160,   201,   125,   164,     8,   260,   259,   168,    73,
     158,   256,   159,   159,   262,   159,   160,   264,   168,   216,
     248,   102,   107,   109,   110,   111,   112,   113,   114,   115,
     162,   217,   219,   232,   233,   234,   235,   237,   159,   107,
     244,   210,    75,    13,   159,   159,   254,   159,   159,   159,
     280,   280,   124,   268,   164,   162,   264,   281,   205,    68,
      69,   206,   160,    86,   239,   195,   159,   159,   256,    92,
     201,    95,    96,    97,   201,   162,   256,   256,   159,   248,
     244,   162,    73,   220,   248,    75,   236,   243,   235,     8,
     160,   161,   158,   161,    31,    75,    13,   256,   164,   164,
     281,    68,    69,   207,   158,   175,   160,   159,    26,   175,
     197,   197,   160,    95,   160,   262,    26,   160,   202,   162,
     125,    75,   161,    13,     8,   160,   161,   221,    13,     8,
     160,   218,    73,   173,    31,    75,   245,   173,    75,    13,
     256,   271,   158,    26,    70,   262,    26,   175,   196,   173,
     160,   202,   173,   256,   159,   173,   256,   248,    73,   222,
     223,   224,   225,   227,   228,   229,   248,   256,    75,   185,
      13,   162,    75,     8,   159,   162,    13,   256,   262,   173,
     160,   159,   173,    90,   173,   161,   162,   162,   224,   160,
      93,   152,   160,   145,    13,    73,   256,    31,    75,   256,
     159,   175,    88,   160,   173,   230,   235,   226,   248,    73,
     256,   158,    75,    26,   160,   162,    73,     8,   208,   173,
     105,   177,   179,   180,   248,   159,   158,   157,   178,   180,
     160,   161,   231,   248,   161,   173,    75,   173,   162,   159,
     162,   161,   173,   162
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
     176,   176,   176,   177,   177,   178,   178,   179,   179,   180,
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
       4,     4,     5,     4,     3,     2,     3,     1,     1,     3,
       2,     4,     5,     4,     2,     0,     1,     1,     1,     4,
       1,     2,     1,     1,     1,     3,     7,    10,     5,     7,
       9,     5,     2,     3,     2,     3,     2,     3,     3,     3,
       3,     3,     1,     2,     2,     5,     8,     8,     5,     1,
      14,     3,     3,     1,     0,     0,     4,     1,     2,     8,
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
#line 3469 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 213 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3477 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 216 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3485 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 222 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_SYMBOL_NAME);
  }
#line 3493 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 225 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-2]), (yyvsp[0]));
  }
#line 3501 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 234 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3511 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 239 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-3]), n_NAMESPACE, (yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
    NMORE((yyval), (yyvsp[-1]));
  }
#line 3523 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 246 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-4]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-4])->appendChild((yyvsp[-3]));
  (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3534 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3547 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 260 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-2]), n_USE, (yyvsp[-1]));
  (yyvsp[-2])->appendChild((yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3558 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 266 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3567 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 273 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 3575 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 276 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3584 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 283 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3594 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 288 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3605 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 294 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3616 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 300 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3628 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 310 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyval), (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3640 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 317 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3652 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 327 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3660 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 330 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3668 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 339 "parser.y" /* yacc.c:1646  */
    {
  (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3678 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 348 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3689 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 354 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3697 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 357 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3705 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 360 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLOSE_TAG);
  }
#line 3713 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 366 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 3721 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 369 "parser.y" /* yacc.c:1646  */
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
#line 3756 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 403 "parser.y" /* yacc.c:1646  */
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
#line 3776 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 418 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_WHILE);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3788 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 425 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-6]), n_DO_WHILE);
    (yyvsp[-6])->appendChild((yyvsp[-5]));
    (yyvsp[-6])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-6]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3801 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 433 "parser.y" /* yacc.c:1646  */
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
#line 3819 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 446 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_SWITCH);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3831 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 453 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_BREAK);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3843 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 460 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_BREAK);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3855 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 467 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_CONTINUE);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3867 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 474 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_CONTINUE);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3879 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 481 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_RETURN);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3891 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 488 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3903 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 495 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3915 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 502 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3925 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 507 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3935 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 512 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3945 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 517 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_INLINE_HTML);
    (yyval) = (yyvsp[0]);
  }
#line 3954 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 521 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3963 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 525 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3972 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 529 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[-1]));
    NMORE((yyvsp[-2]), (yyvsp[-4]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3983 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 536 "parser.y" /* yacc.c:1646  */
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
#line 4005 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 554 "parser.y" /* yacc.c:1646  */
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
#line 4026 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 570 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_DECLARE);
    (yyvsp[-4])->appendChild((yyvsp[-2]));
    (yyvsp[-4])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4037 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 576 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4046 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 584 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-13]), n_TRY);
    (yyvsp[-13])->appendChild(NEXPAND((yyvsp[-12]), (yyvsp[-11]), (yyvsp[-10])));

    NTYPE((yyvsp[-9]), n_CATCH);
    (yyvsp[-9])->appendChild((yyvsp[-7]));
    (yyvsp[-9])->appendChild(NTYPE((yyvsp[-6]), n_VARIABLE));
    (yyvsp[-9])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));

    (yyvsp[-13])->appendChild(NNEW(n_CATCH_LIST)->appendChild((yyvsp[-9]))->appendChildren((yyvsp[-1])));
    (yyvsp[-13])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-13]));
  }
#line 4065 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 598 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_THROW);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));

  }
#line 4078 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 606 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_GOTO);
  NTYPE((yyvsp[-1]), n_STRING);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 4091 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 618 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4099 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 624 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4107 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 627 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_FINALLY);
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    NMORE((yyvsp[-3]), (yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 4118 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 637 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CATCH_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4127 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 641 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 649 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-7]), n_CATCH);
    (yyvsp[-7])->appendChild((yyvsp[-5]));
    (yyvsp[-7])->appendChild(NTYPE((yyvsp[-4]), n_VARIABLE));
    (yyvsp[-7])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyvsp[-7]), (yyvsp[0]));
    (yyval) = (yyvsp[-7]);
  }
#line 4149 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 660 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4158 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 664 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4167 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 683 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4175 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 686 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_REFERENCE);
  }
#line 4183 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 693 "parser.y" /* yacc.c:1646  */
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
#line 4199 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 708 "parser.y" /* yacc.c:1646  */
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
#line 4215 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 719 "parser.y" /* yacc.c:1646  */
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
#line 4232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 734 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[0]);
  }
#line 4241 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 738 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4253 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 745 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4265 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 752 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 4274 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 759 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4282 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 762 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_EXTENDS_LIST)->appendChild((yyvsp[0]));
  }
#line 4290 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 772 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4298 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 775 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_EXTENDS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4308 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 783 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4316 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 786 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_IMPLEMENTS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4326 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 794 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[0]));
  }
#line 4334 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 797 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4342 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 803 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4350 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 806 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4358 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 813 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4368 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 822 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4378 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 831 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4388 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 840 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4398 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 848 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4409 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 854 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));
    (yyval) = (yyvsp[-4]);
  }
#line 4422 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 865 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4430 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 868 "parser.y" /* yacc.c:1646  */
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[-2]), n_STATEMENT);
    (yyvsp[-3])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));
    NEXPAND((yyvsp[-3]), (yyval), (yyvsp[0]));
  }
#line 4445 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 878 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[0]));
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval) = (yyvsp[-2]);
  }
#line 4455 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 883 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_STATEMENT);
    (yyvsp[-4])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-3]));
    (yyval)->appendChildren((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
    NMORE((yyval), (yyvsp[-4]));
  }
#line 4469 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 895 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4477 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 898 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CASE);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyvsp[-3]));
    (yyval) = (yyvsp[-4]);
  }
#line 4490 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 906 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_DEFAULT);
    (yyvsp[-2])->appendChild((yyvsp[0]));

    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval) = (yyvsp[-3]);
  }
#line 4502 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 922 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[0]));
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  (yyval) = (yyvsp[-2]);
  }
#line 4512 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 930 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4520 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 933 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_ELSEIF);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyvsp[-4]));
  }
#line 4532 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 943 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4540 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 946 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_ELSEIF);
    (yyvsp[-5])->appendChild((yyvsp[-3]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyvsp[-5]));
  }
#line 4552 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 956 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4560 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 959 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_ELSE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4570 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 967 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4578 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 970 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ELSE);
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4588 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 979 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
#line 4596 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 985 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4609 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 993 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4623 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1002 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4637 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1011 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4650 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1019 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 4663 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1027 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4677 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1037 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyval));
  }
#line 4691 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1047 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 4704 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1058 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4712 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1061 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4720 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1064 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4728 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1067 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4736 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1074 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
#line 4744 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1080 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4752 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4760 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1086 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[-1]));
  }
#line 4770 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1091 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4778 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1094 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4786 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1097 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 4796 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1105 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4805 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1109 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4814 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1116 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4822 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1119 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4831 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-3]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 4840 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1130 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 4853 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1138 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4866 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1146 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4879 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1154 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4892 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1165 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4900 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1168 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4908 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1174 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4921 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1182 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4930 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1186 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4938 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1189 "parser.y" /* yacc.c:1646  */
    {
    /* empty */
  }
#line 4946 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1191 "parser.y" /* yacc.c:1646  */
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
#line 4963 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1206 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-2]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4973 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1214 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[0]));
  }
#line 4981 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1217 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4989 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1223 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4997 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1226 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5005 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1232 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
#line 5013 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1235 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5021 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1241 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5030 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1245 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 5039 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1252 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5047 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1255 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5055 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1261 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5065 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1269 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5074 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1273 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 5083 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1280 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5092 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1284 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5100 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1290 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[-2]), (yyvsp[-1]), NTYPE((yyvsp[0]), n_STRING));
    (yyval) = (yyvsp[-1]);
  }
#line 5110 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1298 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5121 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1304 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 5132 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1313 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5140 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1316 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5149 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1324 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5157 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1327 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5165 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1334 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5174 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1341 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
#line 5182 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1344 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[0]);
  }
#line 5191 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1351 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5200 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1355 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5208 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1370 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 5220 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1377 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 5232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1384 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5244 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1391 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5256 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1401 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));

    (yyval) = (yyvsp[-4]);
  }
#line 5270 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1410 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyvsp[-3])->appendChild((yyval));

    (yyval) = (yyvsp[-3]);
  }
#line 5284 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1422 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5292 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1425 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5301 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1432 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5309 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1440 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5317 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1443 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5326 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1450 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_LIST);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5339 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1458 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5350 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1464 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));

    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));

    (yyval)->appendChild((yyvsp[-1]));
  }
#line 5365 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1474 "parser.y" /* yacc.c:1646  */
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
#line 5384 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1488 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5394 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1493 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5405 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1499 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5416 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1505 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5427 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1511 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5438 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1517 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5449 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1523 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5460 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1529 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5471 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1535 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5482 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1541 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5493 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1547 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5504 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1553 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5515 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1559 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5525 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1564 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5535 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1569 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5545 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1574 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5555 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1579 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5566 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1585 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5577 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1591 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5588 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1597 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5599 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1603 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5610 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1609 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5621 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1615 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5632 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1621 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5643 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1627 "parser.y" /* yacc.c:1646  */
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
#line 5674 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1653 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5685 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1659 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5696 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1665 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5707 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1671 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5718 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1677 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5729 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1683 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5740 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1689 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5751 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1695 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5761 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1700 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5771 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1705 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5781 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1710 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5791 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1715 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5802 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1721 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5813 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1727 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5824 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1733 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5835 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1739 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5846 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1745 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5857 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1751 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5868 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1757 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5879 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1763 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5890 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1771 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5903 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1779 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5916 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1788 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5926 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1793 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5936 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1798 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5946 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1803 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5956 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1808 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5966 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1813 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5976 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1818 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5986 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1823 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5996 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1828 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6006 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1833 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[0]);
  }
#line 6015 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1840 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6025 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1845 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[0]);
  }
#line 6036 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1854 "parser.y" /* yacc.c:1646  */
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
#line 6052 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1868 "parser.y" /* yacc.c:1646  */
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
#line 6074 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1888 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6085 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1894 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6096 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1900 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6107 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1906 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6118 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1919 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6126 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1922 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[-3])->appendChildren((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1930 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6144 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1933 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 6154 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1938 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6163 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1942 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 6174 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1951 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6184 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1957 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-5]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6195 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1963 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-4]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6206 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1970 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6219 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1979 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1988 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6245 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1997 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6258 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 2005 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6268 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 2013 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6276 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 2016 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6284 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 2019 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6293 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 2023 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6302 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 2030 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6310 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 2033 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6319 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2037 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6328 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 2052 "parser.y" /* yacc.c:1646  */
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
#line 6345 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 2068 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 6353 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2071 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6361 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2077 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6369 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 2083 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6377 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 2086 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-1]), n_EMPTY, (yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6386 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 2090 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 6396 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 2098 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6404 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2101 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6412 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2107 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6420 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2110 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6428 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2113 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_STRING_SCALAR);
  }
#line 6436 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2116 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6444 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2119 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6452 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2122 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6460 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2125 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6468 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2128 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6476 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2131 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6484 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2134 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6492 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2137 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6500 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2140 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_HEREDOC);
  }
#line 6508 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2148 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = (yyvsp[0]);
  }
#line 6517 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2152 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = (yyvsp[0]);
  }
#line 6526 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2156 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6536 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2161 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6546 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2166 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 6556 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 2171 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 6566 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2180 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 6576 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2191 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-2]));
  }
#line 6584 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2194 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-1]));
  }
#line 6592 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2201 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6600 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2204 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6608 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 2210 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6616 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2221 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6628 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2228 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6640 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2235 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6652 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2242 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6664 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2272 "parser.y" /* yacc.c:1646  */
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
#line 6692 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2299 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChildren((yyvsp[0]));
  }
#line 6700 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2302 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6708 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2308 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[-1]));
    if ((yyvsp[0])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[0]));
    }
  }
#line 6720 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2318 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6731 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2324 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6742 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2333 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6750 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2341 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6758 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2348 "parser.y" /* yacc.c:1646  */
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
#line 6775 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2363 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6785 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2368 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6795 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2380 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6806 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2386 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6817 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2402 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6825 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2405 "parser.y" /* yacc.c:1646  */
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
#line 6842 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2421 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6853 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2427 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6864 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2437 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 6872 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2440 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-3]), n_VARIABLE_EXPRESSION, (yyvsp[0]));
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6882 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2448 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6890 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2451 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6898 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2462 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6909 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2468 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6920 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2478 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_STRING);
    (yyval) = (yyvsp[0]);
  }
#line 6929 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2482 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6937 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2488 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);
  }
#line 6945 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2491 "parser.y" /* yacc.c:1646  */
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
#line 6962 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2506 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 6970 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2509 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6979 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2517 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6988 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2521 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6996 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2527 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 7004 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2530 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 7012 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2536 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 7024 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2543 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 7036 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2550 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7048 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2557 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7060 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2564 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 7072 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2571 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 7084 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2578 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7096 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2585 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7108 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2595 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7123 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2605 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7138 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2615 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7146 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2618 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7154 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2621 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7169 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2631 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7177 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2634 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7185 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2640 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7194 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2644 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7202 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2650 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 7212 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2655 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 7220 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2661 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7231 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2667 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7242 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2673 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7253 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2682 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 7263 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2687 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 7273 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2695 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 7284 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2704 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7294 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2709 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7304 "parser.yacc.cpp" /* yacc.c:1646  */
    break;


#line 7308 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 2716 "parser.y" /* yacc.c:1906  */


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
/* @generated */
