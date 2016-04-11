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
    T_FINALLY = 393,
    T_ELLIPSIS = 394
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

#line 317 "parser.yacc.cpp" /* yacc.c:358  */

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
#define YYLAST   7276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  434
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  890

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   394

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,   164,    47,    31,     2,
     159,   160,    45,    42,     8,    43,    44,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   161,
      36,    13,    38,    25,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,   165,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   162,    29,   163,    50,     2,     2,     2,
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
     154,   155,   156,   157,   158
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   208,   208,   214,   217,   223,   226,   232,   233,   234,
     235,   240,   247,   253,   261,   266,   273,   276,   283,   288,
     294,   300,   310,   317,   327,   330,   336,   337,   338,   339,
     347,   348,   354,   357,   360,   366,   369,   399,   418,   425,
     433,   446,   453,   460,   467,   474,   481,   488,   495,   502,
     507,   512,   517,   521,   525,   529,   535,   553,   570,   576,
     580,   589,   598,   606,   617,   621,   627,   639,   642,   646,
     655,   659,   666,   670,   674,   678,   681,   687,   703,   715,
     730,   734,   741,   748,   755,   758,   764,   768,   771,   779,
     782,   790,   793,   799,   802,   808,   809,   817,   818,   826,
     827,   835,   836,   844,   850,   861,   864,   874,   879,   891,
     894,   902,   912,   913,   917,   918,   926,   929,   939,   942,
     952,   955,   963,   966,   974,   975,   981,   989,   998,  1007,
    1015,  1023,  1032,  1042,  1054,  1058,  1064,  1067,  1071,  1074,
    1077,  1083,  1086,  1092,  1093,  1099,  1102,  1108,  1112,  1119,
    1122,  1126,  1133,  1141,  1149,  1157,  1168,  1171,  1177,  1185,
    1189,  1192,  1192,  1210,  1218,  1221,  1227,  1230,  1236,  1239,
    1245,  1249,  1256,  1259,  1265,  1273,  1277,  1284,  1288,  1294,
    1302,  1308,  1317,  1320,  1328,  1331,  1337,  1338,  1345,  1348,
    1355,  1359,  1365,  1366,  1367,  1368,  1369,  1370,  1374,  1381,
    1388,  1395,  1405,  1414,  1426,  1429,  1436,  1439,  1444,  1447,
    1454,  1462,  1468,  1478,  1492,  1497,  1503,  1509,  1515,  1521,
    1527,  1533,  1539,  1545,  1551,  1557,  1563,  1568,  1573,  1578,
    1583,  1589,  1595,  1601,  1607,  1613,  1619,  1625,  1631,  1657,
    1663,  1669,  1675,  1681,  1687,  1693,  1699,  1704,  1709,  1714,
    1719,  1725,  1731,  1737,  1743,  1749,  1755,  1761,  1767,  1773,
    1774,  1775,  1783,  1791,  1792,  1797,  1802,  1807,  1812,  1817,
    1822,  1827,  1832,  1837,  1841,  1842,  1843,  1844,  1849,  1855,
    1870,  1894,  1900,  1906,  1912,  1921,  1925,  1928,  1936,  1939,
    1944,  1948,  1957,  1962,  1969,  1975,  1984,  1993,  2002,  2011,
    2019,  2022,  2025,  2029,  2036,  2039,  2043,  2050,  2051,  2055,
    2070,  2074,  2077,  2083,  2089,  2092,  2096,  2104,  2107,  2113,
    2116,  2119,  2122,  2125,  2128,  2131,  2134,  2137,  2140,  2143,
    2146,  2152,  2153,  2154,  2158,  2162,  2167,  2172,  2177,  2182,
    2186,  2194,  2195,  2196,  2197,  2200,  2203,  2207,  2210,  2216,
    2219,  2223,  2234,  2241,  2248,  2258,  2259,  2263,  2267,  2271,
    2275,  2301,  2305,  2308,  2314,  2324,  2330,  2339,  2345,  2346,
    2347,  2353,  2354,  2369,  2374,  2382,  2386,  2392,  2401,  2402,
    2403,  2407,  2408,  2411,  2423,  2427,  2433,  2439,  2443,  2446,
    2454,  2457,  2463,  2464,  2468,  2474,  2480,  2484,  2488,  2494,
    2497,  2512,  2515,  2522,  2523,  2527,  2533,  2536,  2542,  2549,
    2556,  2563,  2570,  2577,  2584,  2591,  2601,  2611,  2621,  2624,
    2627,  2637,  2640,  2646,  2650,  2656,  2661,  2667,  2673,  2679,
    2688,  2693,  2701,  2710,  2715
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
  "T_YIELD", "T_FINALLY", "T_ELLIPSIS", "'('", "')'", "';'", "'{'", "'}'",
  "'$'", "']'", "$accept", "start", "top_statement_list", "namespace_name",
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
  "non_empty_parameter_list", "parameter", "optional_type", "type",
  "return_type", "function_call_parameter_list",
  "non_empty_function_call_parameter_list", "global_var_list",
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
     386,   387,   388,   389,   390,   391,   392,   393,   394,    40,
      41,    59,   123,   125,    36,    93
};
# endif

#define YYPACT_NINF -688

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-688)))

#define YYTABLE_NINF -376

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-376)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -688,    42,  1764,  -688,  5874,  5874,   -73,  5874,  5874,  5874,
    5874,  5874,  5874,  5874,   279,   279,  5874,  5874,  5874,  5874,
    5874,  5874,  5874,  5874,  4564,   294,  5874,   -71,   -66,  -688,
    -688,    87,  -688,  -688,  -688,    54,  -688,  5874,  4424,     9,
      55,    75,    97,   104,  4695,  4826,    76,  -688,   150,  4957,
       1,  5874,     8,   -17,   -24,   164,   180,   113,   156,   158,
     181,  -688,  -688,   186,   194,  -688,  -688,  -688,  -688,  -688,
    -688,  -688,  -688,  -688,   127,  -688,  -688,   274,  -688,  -688,
    5874,  6005,  -688,  -688,   197,   -80,  -688,    13,  -688,  -688,
    -688,  -688,  -688,  -688,   287,   290,  -688,   204,   335,   305,
     228,  -688,  -688,  6369,  -688,   167,  1061,   215,  -688,   238,
     316,   260,  -688,    90,  -688,   -13,  -688,  -688,   323,   324,
    -688,  -688,  -688,   289,   240,  -688,   335,  1615,  1615,  5874,
    1615,  1615,  7182,  -688,  -688,   346,  -688,  -688,   248,   274,
     336,     7,   257,  -688,  -688,   261,  -688,  -688,  -688,  -688,
    -688,  -688,  -688,  -688,  -688,   279,  6959,   243,   404,   263,
     274,   272,   292,   273,  -688,   295,   311,    93,   -13,  -688,
    5088,  -688,  5874,  -688,  5874,    17,  1615,   362,  5874,  5874,
    5874,   376,  5874,  -688,  6422,  -688,  6463,   291,   437,  -688,
     293,  1615,   109,  -688,  6504,   274,    78,    18,  -688,  -688,
     234,    20,  -688,   447,    22,   335,  -688,  -688,   279,   279,
     279,   304,   246,  4564,   274,  -688,   137,   -67,   116,  7000,
      85,   317,  6557,   320,  1904,  5874,   392,  5874,   403,  -688,
     363,   367,  -688,  -688,    73,  5874,    -7,  5874,  5874,  5874,
    5219,  5874,  5874,  5874,  5874,  5874,  5874,  5874,  5874,  5874,
    5874,  5874,  5874,  5874,  5874,  5874,  5874,  5874,  5874,  5874,
    5874,  5874,   294,  -688,  -688,  -688,  5350,  5874,  5874,  5874,
    5874,  5874,  5874,  5874,  5874,  5874,  5874,  5874,  5874,    69,
    5874,    37,  5874,  5874,   197,   -19,  5874,  5874,   332,  6598,
     274,    61,   320,    94,   138,  -688,  -688,  5481,  -688,  5612,
    -688,   274,   272,    64,  5874,  -688,    64,    37,   -10,  -688,
    6639,  6691,  1615,   327,  5874,  -688,   334,  6732,   337,   488,
    1615,   406,   551,   487,    15,  6773,  -688,  -688,  -688,   876,
    -688,  -688,  2044,  -688,   117,   428,     8,  -688,  5874,  -688,
    -688,   -17,  -688,   876,   427,  -688,   345,    26,  -688,  -688,
    -688,    27,   351,   344,   353,  -688,    28,  -688,   355,   175,
    1454,  -688,  -688,  5874,  5874,  -688,  -688,  -688,   357,  -688,
    -688,  -688,  -688,  -688,  1325,  -688,   359,   512,  1615,   509,
     163,   400,   163,   365,   369,   288,   364,   372,   374,   -10,
     -13,  1170,  7159,  7182,  5874,  7101,  7227,  7122,  4617,  4748,
    4877,  5008,  5008,  5008,  5008,  1187,  1187,  1187,  1187,   630,
     630,   410,   410,   410,   346,   346,   346,  -688,   142,  7182,
    7182,  7182,  7182,  7182,  7182,  7182,  7182,  7182,  7182,  7182,
    7182,   377,   379,   381,   370,  -688,  5874,  -688,   382,    -8,
    -688,   371,  6148,   378,   383,  -688,   103,   372,   379,   279,
    1615,   279,  7060,   272,  -688,   386,  -688,  -688,  -688,  3724,
    -688,  1615,  5874,  3864,  5874,  5874,   279,    89,   876,   451,
    4004,    31,   876,   876,   876,  -688,   388,   391,   274,   -54,
     405,  -688,  -688,  -688,   -42,   476,  -688,  -688,  6189,  -688,
    -688,   545,   288,   279,   399,   279,  -688,  -688,  -688,   246,
     246,   548,  -688,  5874,  -688,  1624,   402,   172,   747,   416,
    -688,  -688,  5874,   876,   426,   274,   272,  -688,   163,   419,
     570,  -688,  -688,   288,  -688,  -688,   423,   577,    12,  -688,
    -688,  -688,  5874,  5874,   -10,  7205,  5874,   294,  -688,  -688,
    5874,  5874,  -688,  6230,  5874,   523,   524,  -688,  5874,  5874,
    -688,  -688,  -688,  -688,  -688,  -688,  5743,  -688,   465,  -688,
    -688,  6825,  -688,  -688,  -688,   430,  1615,   467,   279,   467,
    -688,  -688,   580,  -688,  -688,  -688,   434,   435,  -688,  -688,
    -688,   472,   433,   591,   876,   274,   120,   527,   442,   445,
     -42,  -688,  -688,  -688,  -688,   876,   449,  -688,  -688,  -688,
      29,  -688,  5874,   450,  -688,  -688,   444,  1615,  -688,   274,
     272,   570,  -688,   163,   589,   453,   507,   191,    19,  -688,
     541,   605,   459,   460,  7205,   273,   462,   463,  -688,   466,
    5874,  5874,   503,   470,  6285,   279,  1615,    37,  -688,  3584,
     259,   471,  2184,  5874,    89,   468,  -688,   478,   876,  2324,
    -688,   375,  -688,   147,   876,  -688,   876,  -688,   481,   152,
    -688,   163,  -688,  -688,  -688,  -688,  -688,   507,  -688,  7182,
    -688,  -688,   272,   610,  -688,   558,   163,  -688,  -688,  -688,
    -688,  -688,  -688,  -688,  -688,  -688,  -688,   561,   289,   443,
    -688,    23,   616,   486,   616,    44,   633,  -688,   876,  -688,
    -688,  -688,  -688,  -688,  -688,   483,   485,    37,  -688,  -688,
    -688,  -688,  -688,   267,   493,  4424,  -688,  -688,   492,   494,
    -688,  4144,  4144,  -688,   496,   387,   497,  5874,    30,   183,
    -688,  -688,   530,  -688,   584,  2464,   616,  -688,   647,    11,
    -688,   648,    24,  -688,  -688,   593,  -688,   191,   500,    36,
     506,    19,   656,   876,  -688,  -688,  -688,   382,   511,   652,
     611,  5874,  -688,  -688,  4284,  -688,  -688,  -688,  -688,  -688,
     519,  -688,  6328,  -688,  -688,  -688,  -688,   876,   525,  -688,
     535,   876,   163,  -688,   174,  -688,   876,   617,  -688,   335,
     693,  -688,  -688,   632,  -688,    32,  -688,   695,   876,  -688,
    -688,  5874,  -688,   549,  6866,  -688,  -688,  -688,  2604,  -688,
    -688,  3584,  -688,   552,  -688,  -688,  -688,   620,   555,   174,
    -688,   565,   634,   576,   569,   587,  -688,   721,   662,   876,
    2744,  -688,   107,  -688,  2884,   876,  -688,  6907,  3584,  -688,
    4424,  3024,   575,  3584,  -688,  3164,  -688,  -688,  -688,   308,
     163,  -688,   666,   876,   581,  -688,  -688,   668,  -688,  -688,
    -688,   715,  -688,   583,  -688,  3304,  -688,   672,   673,   739,
    -688,  -688,  -688,   288,  -688,  -688,  -688,  -688,  -688,   163,
     590,  3584,  -688,   616,   188,  -688,  -688,  -688,  3444,  -688
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,     0,     0,   314,     0,   319,
     320,     5,   341,   388,    52,   321,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,     0,     0,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,    80,    86,     0,     0,   325,   326,   328,   322,   323,
      32,    33,    34,   330,     0,   329,   324,     0,    83,   327,
     278,     0,    59,    25,   399,   343,     3,     0,     7,    30,
       8,     9,    73,    74,     0,     0,   356,     0,    75,   380,
       0,   346,   274,     0,   355,     0,   357,     0,   384,     0,
     379,   361,   378,   381,   387,     0,   263,   259,   275,   276,
     260,   342,     5,   300,     0,   278,    75,   418,   419,     0,
     421,   422,   277,   246,   247,   248,   249,   300,     0,     0,
       0,   301,     0,   227,   359,     0,   229,   264,   265,   266,
     267,   268,   269,   270,   272,     0,   411,     0,   349,     0,
       0,   301,   307,   317,   308,     0,   310,   381,     0,   214,
       0,   271,     0,    31,   390,     0,   205,     0,     0,   206,
       0,     0,     0,    42,     0,    44,     0,     0,     0,    46,
     356,     0,   357,    25,     0,     0,    18,     0,    17,   149,
       0,     0,   148,   154,     0,    75,    81,    82,     0,     0,
       0,     0,   405,   406,     0,     4,     0,   345,   356,     0,
     357,     0,     0,   260,     0,     0,     0,   144,     0,    15,
      84,    87,    54,    76,     0,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,   226,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     390,     0,   390,     0,   400,   383,   390,   390,     0,     0,
       0,   303,     0,     0,     0,   415,   358,     0,   431,   350,
     407,     0,   303,     0,   144,   432,     0,     0,   383,   315,
       0,     0,   391,     0,     0,    51,     0,     0,     0,   207,
     209,   356,   357,     0,     0,     0,    43,    45,    63,     0,
      47,    48,     0,    62,    20,     0,     0,    14,     0,   150,
     357,     0,    49,     0,     0,    50,     0,     0,    70,    72,
     423,     0,     0,     0,     0,   403,     0,   402,     0,   344,
       0,    11,     4,   144,     0,   426,   425,   382,     0,    35,
      24,    26,    27,    28,     0,     6,     0,   143,   145,     0,
       0,    89,     0,     0,     0,   136,     0,   433,   373,   371,
       0,   232,   234,   233,     0,     0,   230,   231,   235,   237,
     236,   252,   253,   250,   251,   254,   255,   256,   257,   244,
     245,   239,   240,   238,   241,   242,   243,   258,     0,   211,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,     0,   434,   374,     0,   397,     0,   393,   370,   392,
     396,     0,     0,     0,     0,   420,   302,     0,     0,     0,
     410,     0,   409,   302,   373,     0,   374,   312,   316,     0,
     429,   204,     0,     0,   206,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   347,   321,     0,     0,     0,   332,
       0,   331,    23,   339,     0,     0,    19,    16,     0,   147,
     155,   152,   136,     0,     0,     0,   416,   417,    10,   405,
     405,     0,   430,   144,    13,     0,     0,   356,   357,     0,
     389,   292,     0,     0,     0,     0,   304,    85,     0,     0,
      88,    91,   157,   136,   139,   140,     0,   124,     0,   137,
     138,   377,   144,   144,   372,   262,     0,     0,   212,   299,
     144,   144,   376,     0,   144,   369,   368,   363,   390,     0,
     385,   386,   428,   427,   414,   413,     0,   318,   309,    25,
     116,     0,    25,   114,    38,     0,   208,    93,     0,    93,
      95,   103,     0,    25,   101,    58,   109,   109,    41,   335,
     336,   354,     0,   349,   347,     0,   334,     0,     0,     0,
      67,    65,    61,    21,   151,     0,     0,    71,    55,   424,
       0,   401,     0,     0,    12,   294,     0,   146,    22,     0,
     306,    90,   157,     0,   188,     0,   286,   136,     0,   135,
       0,   126,     0,     0,   261,   317,     0,     0,   398,     0,
     390,   390,   360,     0,     0,     0,   408,     0,   311,   118,
     120,     0,     0,   206,     0,     0,    96,     0,     0,     0,
     109,     0,   109,     0,     0,   338,   350,   348,     0,   333,
     340,     0,    25,    64,    60,    68,   153,   286,   404,   210,
     293,    29,   305,   188,    92,     0,     0,   195,   196,   197,
     194,   193,   192,   187,    79,   156,   160,     0,     0,   186,
     190,     0,   141,     0,   141,     0,   127,   134,     0,   295,
     298,   213,   296,   297,   367,     0,     0,     0,   362,   394,
     395,   412,   313,   122,     0,     0,    36,    39,     0,     0,
      94,     0,     0,   104,     0,     0,     0,     0,     0,     0,
     105,   353,   352,   337,     0,     0,   141,    78,     0,     0,
     164,   200,     0,   161,   191,     0,   159,     0,     0,     0,
       0,     0,   130,     0,   129,   365,   366,   370,     0,     0,
       0,     0,   121,   115,     0,    25,    99,    57,    56,   102,
       0,   107,     0,   112,   113,    25,   106,     0,     0,    69,
       0,     0,     0,   166,   168,   163,     0,     0,   158,    75,
       0,   142,    25,     0,   290,     0,    25,   131,     0,   128,
     364,     0,    25,     0,     0,    25,    97,    40,     0,   108,
      25,   111,   351,     0,    25,   203,   165,     5,     0,   169,
     170,     0,     0,   178,     0,     0,   201,   198,     0,     0,
       0,   291,     0,   287,     0,     0,   133,     0,   123,    37,
       0,     0,     0,   110,    25,     0,   167,   171,   172,   182,
       0,   173,     0,     0,     0,   202,    77,     0,   288,   279,
     132,     0,   117,     0,   100,     0,   280,     0,   181,   174,
     175,   179,   199,   136,   289,    25,    98,    66,   180,     0,
       0,   119,   176,   141,     0,   184,    25,   162,     0,   185
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -688,  -688,  -182,    -5,  -688,  -688,   413,  -688,  -181,  -688,
      16,  -688,  -688,   161,  -688,   165,  -688,   264,     2,     4,
    -125,  -688,  -688,  -688,  -688,  -688,  -688,  -688,   236,   187,
     114,  -688,    52,  -688,  -688,  -688,  -536,     3,  -688,  -688,
    -688,  -688,  -688,  -484,  -688,  -554,   166,    35,  -687,  -228,
    -688,  -688,   418,  -688,   176,  -688,  -688,  -688,  -688,  -688,
    -688,  -688,   -41,  -688,  -688,  -688,  -688,  -688,  -688,  -688,
    -688,  -688,  -688,  -673,  -688,  -688,  -688,  -449,  -688,   -35,
     706,    -2,   122,  -688,  -688,   216,  -353,  -245,  -688,  -688,
    -688,  -688,   169,  -247,   598,  -688,  -688,   206,   208,  -688,
     880,   592,  -427,   342,   832,  -688,  -688,  -688,  -688,    38,
    -233,  -688,   771,  -688,  -688,   -23,   -20,  -688,  -197,  -296,
    -688,  -688,   -12,   298,   301,   594,  -688,  -688,  -688,  -688,
    -688,  -688,   -22,  -688
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   197,   198,    87,   224,   370,
     371,    89,   590,   591,   664,   592,   347,   348,   372,   373,
     234,    92,    93,    94,   381,    95,   383,   519,   520,   645,
     569,   807,   767,   575,   324,   578,   651,   775,   564,   640,
     713,   716,   760,   526,   527,   621,   528,   529,   748,   376,
     377,   201,   202,   204,   614,   685,   789,   686,   739,   785,
     818,   819,   820,   821,   869,   822,   823,   824,   867,   887,
     687,   688,   689,   690,   742,   691,   175,   318,   319,    96,
      97,   126,   694,   795,    99,   100,   530,   163,   164,   558,
     638,   171,   305,   101,   581,   483,   102,   582,   300,   583,
     103,   104,   295,   105,   106,   632,   708,   545,   546,   547,
     107,   108,   109,   110,   111,   112,   113,   114,   313,   438,
     439,   440,   115,   356,   357,   157,   158,   116,   351,   117,
     118,   119,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   288,   166,   388,    90,   167,    91,   750,   596,   141,
     141,   457,   332,   168,   190,   565,   744,   417,    88,   782,
     161,   228,   554,   469,   555,   314,   336,   517,   341,   521,
     344,   745,   787,   360,   493,   495,   500,   500,   386,   615,
     832,   653,     3,   618,   282,   218,   433,   196,   437,   780,
     431,   203,   205,   282,   177,   548,   773,   576,   199,   223,
     388,   433,    33,   588,   696,  -301,   387,   793,    33,   216,
     454,   226,   217,   456,   437,   751,   455,    47,  -303,   227,
     346,   122,   481,   434,   226,   441,   129,   619,   170,   443,
     444,  -301,   363,   172,   619,   285,   481,   226,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     435,   794,    33,   173,   725,   589,   729,   174,   292,   619,
     568,   205,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   291,   506,  -359,  -359,   857,    33,
    -372,   752,   432,   283,    33,   321,   384,   200,   308,   187,
     141,   284,   283,   282,   549,   302,   282,    84,   226,   195,
    -359,  -359,   122,   193,    33,   521,   227,   447,   178,    33,
     620,   335,   783,   784,   229,   470,   868,   620,   315,   337,
     505,   342,   858,   345,   746,   788,   494,   496,   501,   668,
     334,   774,   833,   577,   719,   141,   884,   797,   137,   436,
     122,    84,   620,   141,   141,   141,   537,   141,   711,   359,
     485,   448,   226,    33,   179,   122,   389,    33,   264,   265,
     363,   481,    98,   188,   390,   481,   481,   481,    84,   226,
     142,   142,   385,    84,   180,  -375,   122,   138,  -375,   166,
     139,   162,   167,   727,   728,  -282,  -282,   817,   140,  -371,
     168,   137,   283,    84,   226,   283,   181,   161,    84,   389,
     674,   389,   503,   182,   122,  -303,   481,   390,   226,   390,
     331,   226,   208,   389,   389,   603,  -281,  -281,   214,   727,
     728,   390,   390,   389,   206,   446,   389,   389,   226,   215,
     138,   390,   625,   139,   390,   390,   453,  -302,   361,   362,
     207,   140,    84,   226,   622,   623,    84,   122,   734,    33,
     730,   514,   626,   627,   515,   209,   629,   210,   524,   122,
    -302,    33,   514,   740,   479,   515,   226,   714,   715,   507,
      98,   196,  -283,  -283,   503,   758,   759,   481,   479,   514,
     211,   712,   515,   137,   525,   212,   776,   122,   481,   885,
     886,   633,   122,   213,    33,   137,   143,   146,    98,   225,
     230,   122,    90,   231,    91,   232,   233,   122,   235,    33,
     534,   142,   354,   236,   278,   516,    88,   516,   639,   280,
     516,   642,   138,   279,   281,   139,   286,   287,   137,   880,
      47,   214,   649,   140,   138,   262,   338,   139,    84,   290,
      25,   481,   293,   137,   437,   140,   294,   481,   298,   481,
      84,   757,   299,   141,   301,   524,   142,   677,   678,   679,
     680,   681,   682,   226,   142,   142,   142,   138,   142,   816,
     139,   825,   304,   705,   706,   307,   514,   303,   140,   515,
     306,   525,   159,    84,   141,   160,   141,   316,  -125,   323,
     329,   481,   328,   140,   330,   259,   260,   261,    84,   262,
     343,   141,   141,   479,   353,   375,   825,   479,   479,   479,
     726,   727,   728,   586,   437,   560,   379,   365,   162,   563,
     367,   735,   770,   727,   728,   380,   574,   516,   141,   382,
     141,   385,   460,   462,   141,   141,   465,   870,   464,   466,
     468,   486,   491,    98,   492,   498,   481,    90,   479,    91,
     610,   497,   499,   516,   166,   502,   509,   167,   516,   511,
     512,    88,   513,   518,   572,   168,   882,   522,   523,   531,
     481,   532,   161,   533,   481,   542,   550,   539,   540,   481,
     541,   544,   585,   552,  -189,   480,   557,   584,   553,   593,
     587,   481,   677,   678,   679,   680,   681,   682,   595,   480,
     598,   602,   605,   141,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   606,   609,   613,   479,
     659,   612,   481,   616,   808,   617,   630,   631,   481,   637,
     479,   643,   644,   648,   811,   650,   652,   654,   655,   656,
     660,   661,  -359,  -359,   672,   671,   481,   662,   516,   667,
     670,   830,   516,   692,   693,   834,   697,   389,   698,   699,
     700,   838,   702,   703,   841,   390,   704,   707,   721,   843,
     141,   738,   717,   845,   142,   709,   741,    98,   722,   141,
      98,   733,   747,   479,   467,   749,   753,    98,   755,   479,
     756,   479,   761,   763,   764,   777,   516,   769,   771,   778,
     781,   786,   792,   865,   828,   142,   790,   142,   796,   798,
     801,   516,   256,   257,   258,   259,   260,   261,   802,   262,
     809,   803,   142,   142,   480,   813,   743,   389,   480,   480,
     480,   675,   827,   479,   881,   390,   676,   814,   677,   678,
     679,   680,   681,   682,   683,   888,   829,   831,   835,   142,
     839,   142,   675,  -177,   844,   142,   142,   676,   846,   677,
     678,   679,   680,   681,   682,   683,   848,   849,   850,   480,
     851,   762,   852,    98,   853,   854,   864,   766,   766,   871,
     873,   875,   516,   874,   876,   878,  -183,   879,   479,   487,
     883,   663,   684,   162,   611,   665,   647,   597,   720,   489,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   479,   737,   768,   810,   479,   516,   847,   516,
     806,   479,   791,   695,   142,   145,   145,   221,   673,   736,
     658,   657,   339,   479,   701,   800,   165,   600,  -359,  -359,
     480,   601,     0,     0,     0,     0,    98,   358,     0,    98,
       0,   480,     0,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,    98,     0,
     479,     0,    98,     0,     0,     0,    98,     0,     0,    98,
       0,    98,     0,    98,     0,   516,   144,   144,   479,     0,
       0,   142,     0,     0,     0,     0,   862,     0,     0,     0,
     142,     0,     0,    98,   480,     0,     0,     0,   516,     0,
     480,     0,   480,     0,   516,     0,     0,     0,     0,    98,
       0,   192,     0,     0,   127,   128,    98,   130,   131,   132,
     133,   134,   135,   136,     0,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   156,     0,   169,  -284,  -284,     0,
       0,     0,   220,     0,   480,     0,     0,   176,   472,   473,
       0,     0,     0,     0,   184,   186,   145,   482,     0,   191,
       0,   194,     0,     0,     0,     0,     0,     0,     0,   474,
       0,   490,     0,     0,     0,     0,     0,    29,    30,   122,
       0,     0,     0,     0,     0,     0,     0,   475,     0,     0,
     219,   222,     0,     0,     0,     0,     0,     0,     0,   480,
       0,   145,     0,     0,     0,     0,     0,     0,     0,   145,
     145,   145,     0,   145,     0,   137,     0,   296,     0,     0,
       0,     0,     0,   480,     0,     0,     0,   480,     0,     0,
       0,     0,   480,   476,    65,    66,    67,    68,    69,   289,
       0,     0,   322,     0,   480,     0,     0,     0,    73,     0,
       0,     0,     0,     0,   477,    75,    76,   478,     0,     0,
       0,    79,   340,   165,     0,     0,     0,     0,     0,     0,
     349,   350,   352,     0,   355,   480,     0,     0,     0,     0,
     310,   480,   311,     0,   312,     0,     0,     0,   317,   320,
     191,     0,   325,     0,     0,     0,   571,     0,     0,   480,
     579,   580,     0,     0,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,     0,   378,     0,     0,
       0,   608,  -359,  -359,     0,   312,     0,   391,   392,   393,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   378,     0,
     312,     0,   312,   442,     0,     0,   312,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   450,     0,   452,
     238,   239,     0,     0,   378,     0,     0,     0,     0,   145,
       0,     0,     0,   666,   461,   240,   508,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   488,   262,
     145,     0,   145,  -376,  -376,  -376,  -376,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,   145,   145,     0,
       0,     0,     0,   378,   191,     0,   723,     0,     0,     0,
     538,     0,   731,     0,   732,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,   145,     0,     0,     0,
     145,   145,     0,     0,   535,     0,     0,     0,     0,     0,
       0,   296,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,     0,   567,   570,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
       0,     0,     0,     0,     0,   349,     0,   599,     0,     0,
       0,   355,   355,     0,   237,   238,   239,     0,     0,   145,
       0,     0,   561,     0,   320,   566,     0,     0,     0,     0,
     240,   799,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   812,     0,     0,     0,   815,
       0,     0,     0,   378,   826,     0,     0,     0,     0,     0,
       0,     0,   607,     0,     0,     0,   836,     0,     0,     0,
     646,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,   378,   378,     0,   145,   624,     0,     0,     0,
     378,   378,     0,     0,   378,     0,     0,   855,   312,   634,
       0,     0,     0,   860,     0,     0,   636,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   872,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,   296,     0,     0,
       0,     0,     0,     0,     0,     0,   570,     0,     0,     0,
       0,     0,   669,     0,     0,     0,     0,     0,   510,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
     312,   312,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,   320,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     0,     0,     0,
       0,     0,    74,    75,    76,    77,     0,   772,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   504,    84,     0,
       0,     0,     0,     0,   237,   238,   239,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,     0,
     240,   804,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,   837,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,    74,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   604,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,    74,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   369,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   484,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
     718,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,   724,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   779,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,   842,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   856,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   859,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,   863,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   866,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   877,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,   889,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,    58,    59,   368,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,     0,    72,     0,     0,     0,    73,     4,     5,     6,
       7,     8,   124,    75,    76,    77,     9,     0,    78,    79,
      80,     0,     0,    81,     0,    82,    83,     0,    84,     0,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     562,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     765,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     805,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    29,    30,   122,    32,    33,
       0,     0,     0,     0,     0,    35,    36,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,    47,   262,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     4,     5,
       6,     7,     8,     0,     0,     0,    73,     9,     0,     0,
       0,     0,   124,    75,    76,    77,     0,     0,     0,    79,
     125,     0,     0,    81,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,    29,    30,   122,    32,
      33,     0,     0,     0,     0,     0,    35,    36,     0,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,    47,   262,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     4,
       5,     6,     7,     8,     0,     0,     0,    73,     9,     0,
       0,     0,     0,   124,    75,    76,    77,     0,     0,     0,
      79,   125,     0,     0,    81,     0,   183,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    29,    30,   122,
      32,    33,     0,     0,     0,     0,     0,    35,    36,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,    47,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       4,     5,     6,     7,     8,     0,     0,     0,    73,     9,
       0,     0,     0,     0,   124,    75,    76,    77,     0,     0,
       0,    79,   125,     0,     0,    81,     0,   185,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,    29,    30,
     122,    32,    33,     0,     0,     0,     0,     0,    35,    36,
    -376,  -376,  -376,  -376,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,    47,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    73,
       9,     0,     0,     0,     0,   124,    75,    76,    77,     0,
       0,     0,    79,   125,     0,     0,    81,     0,   189,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,    79,   125,   394,     0,    81,   309,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
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
       0,   418,     0,    84,     0,     0,     0,     0,     0,     0,
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
       0,     0,   449,     0,    84,     0,     0,     0,     0,     0,
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
      81,     0,     0,   451,     0,    84,     0,     0,     0,     0,
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
       0,    81,     0,     0,   635,     0,    84,     0,     0,     0,
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
     125,     0,     0,    81,     0,     0,     0,     0,    84,     0,
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
       0,     0,     0,   124,    75,    76,    77,   237,   238,   239,
      79,    80,     0,     0,    81,     0,     0,     0,     0,    84,
       0,     0,     0,   240,     0,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,     0,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   551,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,     0,     0,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   240,   773,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   628,   240,     0,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   710,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   774,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     263,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   326,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   327,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   333,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   366,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   445,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   458,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   459,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   463,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   471,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   641,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   840,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   861,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,   240,     0,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   240,   536,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     239,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   556,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   240,   262,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262
};

static const yytype_int16 yycheck[] =
{
       2,   126,    25,   236,     2,    25,     2,   694,   492,    14,
      15,   307,   193,    25,    49,   464,   689,   262,     2,     8,
      25,     8,   449,     8,   451,     8,     8,   380,     8,   382,
       8,     8,     8,   215,     8,     8,     8,     8,   235,   523,
       8,   577,     0,    31,    63,    80,   279,    52,   281,   736,
     278,    75,    54,    63,    38,    63,    26,    26,    75,    81,
     293,   294,    75,   105,   618,   145,    73,    31,    75,    74,
     303,   151,    77,   306,   307,    31,   304,   101,   145,   159,
     205,    73,   329,   280,   151,   282,   159,    75,   159,   286,
     287,   145,   159,   159,    75,   115,   343,   151,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      73,    75,    75,    26,   650,   157,   652,    63,   140,    75,
      31,   123,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   139,   363,    51,    52,    31,    75,
     159,   695,    73,   162,    75,   180,    73,   164,   168,    73,
     155,   164,   162,    63,   162,   160,    63,   164,   151,   151,
      51,    52,    73,   162,    75,   518,   159,    73,   159,    75,
     158,    93,   161,   162,   161,   160,   849,   158,   161,   161,
     362,   161,    75,   161,   161,   161,   160,   160,   160,   160,
     195,   161,   160,   162,   643,   200,   883,   751,   109,   162,
      73,   164,   158,   208,   209,   210,    64,   212,   635,   214,
      93,    73,   151,    75,   159,    73,   236,    75,    51,    52,
     159,   468,   224,    73,   236,   472,   473,   474,   164,   151,
      14,    15,   159,   164,   159,   145,    73,   148,   145,   262,
     151,    25,   262,    96,    97,   160,   161,    73,   159,   159,
     262,   109,   162,   164,   151,   162,   159,   262,   164,   279,
     613,   281,   159,   159,    73,   145,   513,   279,   151,   281,
     161,   151,   159,   293,   294,   503,   160,   161,   151,    96,
      97,   293,   294,   303,   120,   290,   306,   307,   151,   162,
     148,   303,   537,   151,   306,   307,   301,   145,   161,   162,
     120,   159,   164,   151,   532,   533,   164,    73,   661,    75,
     163,   148,   540,   541,   151,   159,   544,   159,   127,    73,
     145,    75,   148,   676,   329,   151,   151,    68,    69,   364,
     332,   336,   160,   161,   159,    68,    69,   584,   343,   148,
     159,   637,   151,   109,   153,   159,   163,    73,   595,   161,
     162,   548,    73,   159,    75,   109,    14,    15,   360,   162,
      73,    73,   360,    73,   360,   161,    31,    73,    63,    75,
     390,   155,   126,   145,   159,   380,   360,   382,   559,    63,
     385,   562,   148,   145,   124,   151,    63,    63,   109,   873,
     101,   151,   573,   159,   148,    49,   162,   151,   164,   151,
      64,   648,   145,   109,   637,   159,   145,   654,   165,   656,
     164,   707,     8,   418,   151,   127,   200,   109,   110,   111,
     112,   113,   114,   151,   208,   209,   210,   148,   212,   782,
     151,   784,   159,   630,   631,   124,   148,   145,   159,   151,
     145,   153,   148,   164,   449,   151,   451,    85,   160,    73,
      13,   698,   161,   159,   161,    45,    46,    47,   164,    49,
      13,   466,   467,   468,   160,    73,   819,   472,   473,   474,
      95,    96,    97,   478,   707,   459,    73,   160,   262,   463,
     160,   662,    95,    96,    97,   122,   470,   492,   493,   122,
     495,   159,   165,   159,   499,   500,     8,   850,   161,    93,
      13,    73,    75,   505,   159,   161,   753,   505,   513,   505,
     515,   160,   159,   518,   537,   160,   159,   537,   523,   160,
       8,   505,    13,   123,    73,   537,   879,   162,   159,   165,
     777,   159,   537,   159,   781,   165,   165,   160,   159,   786,
     159,   159,   151,   165,   101,   329,   160,   159,   165,    73,
     145,   798,   109,   110,   111,   112,   113,   114,    13,   343,
     161,    13,   160,   568,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   160,   151,     8,   584,
     585,   162,   829,   160,   765,     8,    63,    63,   835,   124,
     595,   161,   125,    13,   775,   161,   161,   125,   165,     8,
      73,   159,    51,    52,   609,   161,   853,   162,   613,   160,
     160,   792,   617,   160,   107,   796,    75,   637,    13,   160,
     160,   802,   160,   160,   805,   637,   160,   124,   160,   810,
     635,    73,   161,   814,   418,   165,    75,   639,   160,   644,
     642,   160,    26,   648,    93,   159,    13,   649,   165,   654,
     165,   656,   159,   161,   160,   125,   661,   161,   161,    75,
      13,    13,   162,   844,   789,   449,    73,   451,   162,    13,
     159,   676,    42,    43,    44,    45,    46,    47,    26,    49,
     161,    70,   466,   467,   468,   160,   688,   707,   472,   473,
     474,   102,    75,   698,   875,   707,   107,   162,   109,   110,
     111,   112,   113,   114,   115,   886,    13,    75,    13,   493,
     161,   495,   102,    93,   162,   499,   500,   107,   163,   109,
     110,   111,   112,   113,   114,   115,   161,    93,   152,   513,
     161,   715,   145,   735,    13,    73,   161,   721,   722,    73,
     159,    26,   747,    75,   161,    73,    73,     8,   753,   336,
     160,   590,   163,   537,   518,   590,   569,   493,   644,   341,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   777,   163,   722,   772,   781,   782,   819,   784,
     764,   786,   747,   617,   568,    14,    15,    81,   612,   667,
     584,   583,   200,   798,   625,   757,    25,   499,    51,    52,
     584,   500,    -1,    -1,    -1,    -1,   808,   213,    -1,   811,
      -1,   595,    -1,    -1,   819,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   829,    -1,    -1,    -1,   830,    -1,
     835,    -1,   834,    -1,    -1,    -1,   838,    -1,    -1,   841,
      -1,   843,    -1,   845,    -1,   850,    14,    15,   853,    -1,
      -1,   635,    -1,    -1,    -1,    -1,   840,    -1,    -1,    -1,
     644,    -1,    -1,   865,   648,    -1,    -1,    -1,   873,    -1,
     654,    -1,   656,    -1,   879,    -1,    -1,    -1,    -1,   881,
      -1,    49,    -1,    -1,     4,     5,   888,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,   160,   161,    -1,
      -1,    -1,    80,    -1,   698,    -1,    -1,    37,    42,    43,
      -1,    -1,    -1,    -1,    44,    45,   155,   329,    -1,    49,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,   343,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   753,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,    -1,   212,    -1,   109,    -1,   155,    -1,    -1,
      -1,    -1,    -1,   777,    -1,    -1,    -1,   781,    -1,    -1,
      -1,    -1,   786,   127,   128,   129,   130,   131,   132,   129,
      -1,    -1,   180,    -1,   798,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   200,   262,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,    -1,   212,   829,    -1,    -1,    -1,    -1,
     170,   835,   172,    -1,   174,    -1,    -1,    -1,   178,   179,
     180,    -1,   182,    -1,    -1,    -1,   468,    -1,    -1,   853,
     472,   473,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,   227,    -1,    -1,
      -1,   513,    51,    52,    -1,   235,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,    -1,    -1,    -1,    -1,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,    -1,
     280,    -1,   282,   283,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,   299,
      10,    11,    -1,    -1,   304,    -1,    -1,    -1,    -1,   418,
      -1,    -1,    -1,   595,   314,    25,   364,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,   338,    49,
     449,    -1,   451,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,   466,   467,    -1,
      -1,    -1,    -1,   363,   364,    -1,   648,    -1,    -1,    -1,
     418,    -1,   654,    -1,   656,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   493,    -1,   495,    -1,    -1,    -1,
     499,   500,    -1,    -1,   394,    -1,    -1,    -1,    -1,    -1,
      -1,   449,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   698,    -1,   466,   467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   493,    -1,   495,    -1,    -1,
      -1,   499,   500,    -1,     9,    10,    11,    -1,    -1,   568,
      -1,    -1,   462,    -1,   464,   465,    -1,    -1,    -1,    -1,
      25,   753,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,   777,    -1,    -1,    -1,   781,
      -1,    -1,    -1,   503,   786,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   512,    -1,    -1,    -1,   798,    -1,    -1,    -1,
     568,    -1,    -1,    -1,    -1,    -1,   635,    -1,    -1,    -1,
      -1,    -1,   532,   533,    -1,   644,   536,    -1,    -1,    -1,
     540,   541,    -1,    -1,   544,    -1,    -1,   829,   548,   549,
      -1,    -1,    -1,   835,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   853,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,   635,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   644,    -1,    -1,    -1,
      -1,    -1,   602,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
     630,   631,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,   643,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,   727,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      25,   761,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,   801,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    90,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    88,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,   154,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,    -1,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,    -1,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,    -1,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,    -1,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,    -1,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,     5,
       6,     7,   148,   149,   150,   151,    12,    -1,    -1,   155,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   101,    49,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,   101,    49,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,    -1,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   142,    12,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,    -1,    -1,   159,    -1,   161,    -1,    -1,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,   131,   132,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   142,
      12,    -1,    -1,    -1,    -1,   148,   149,   150,   151,    -1,
      -1,    -1,   155,   156,    -1,    -1,   159,    -1,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   155,   156,    26,    -1,   159,   160,    -1,
      -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     151,    -1,    -1,    -1,   155,   156,    -1,    -1,   159,    -1,
      -1,    31,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,    -1,    -1,    -1,   155,   156,    -1,    -1,   159,
      -1,    -1,    31,    -1,   164,    -1,    -1,    -1,    -1,    -1,
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
     149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,    -1,
     159,    -1,    -1,    31,    -1,   164,    -1,    -1,    -1,    -1,
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
      -1,   159,    -1,    -1,    31,    -1,   164,    -1,    -1,    -1,
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
      -1,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,    -1,
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
     156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,     9,    10,    11,
     155,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   163,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   163,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   161,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     161,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   161,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   161,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   161,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   160,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   160,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   160,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   160,    27,    28,    29,    30,    31,    32,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      11,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   125,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    25,    49,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   167,   168,     0,     3,     4,     5,     6,     7,    12,
      42,    43,    48,    50,    51,    52,    53,    54,    55,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    71,
      72,    73,    74,    75,    77,    81,    82,    83,    84,    85,
      87,    89,    91,    94,    98,    99,   100,   101,   102,   103,
     104,   106,   107,   108,   109,   110,   111,   116,   117,   118,
     119,   120,   121,   126,   127,   128,   129,   130,   131,   132,
     135,   136,   138,   142,   148,   149,   150,   151,   154,   155,
     156,   159,   161,   162,   164,   169,   170,   173,   176,   177,
     184,   185,   187,   188,   189,   191,   245,   246,   247,   250,
     251,   259,   262,   266,   267,   269,   270,   276,   277,   278,
     279,   280,   281,   282,   283,   288,   293,   295,   296,   297,
     298,   299,    73,   109,   148,   156,   247,   266,   266,   159,
     266,   266,   266,   266,   266,   266,   266,   109,   148,   151,
     159,   169,   251,   269,   270,   278,   269,   266,   266,   266,
     266,   266,   266,   266,   266,    31,   266,   291,   292,   148,
     151,   169,   251,   253,   254,   278,   281,   282,   288,   266,
     159,   257,   159,    26,    63,   242,   266,   176,   159,   159,
     159,   159,   159,   161,   266,   161,   266,    73,    73,   161,
     245,   266,   270,   162,   266,   151,   169,   171,   172,    75,
     164,   217,   218,    75,   219,   247,   120,   120,   159,   159,
     159,   159,   159,   159,   151,   162,   169,   169,   245,   266,
     270,   246,   266,   298,   174,   162,   151,   159,     8,   161,
      73,    73,   161,    31,   186,    63,   145,     9,    10,    11,
      25,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,   161,    51,    52,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   159,   145,
      63,   124,    63,   162,   164,   282,    63,    63,   186,   266,
     151,   169,   298,   145,   145,   268,   270,   125,   165,     8,
     264,   151,   169,   145,   159,   258,   145,   124,   282,   160,
     266,   266,   266,   284,     8,   161,    85,   266,   243,   244,
     266,   245,   270,    73,   200,   266,   161,   161,   161,    13,
     161,   161,   174,   161,   169,    93,     8,   161,   162,   267,
     270,     8,   161,    13,     8,   161,   186,   182,   183,   270,
     270,   294,   270,   160,   126,   270,   289,   290,   291,   169,
     168,   161,   162,   159,   125,   160,   160,   160,   119,   163,
     175,   176,   184,   185,   266,    73,   215,   216,   266,    73,
     122,   190,   122,   192,    73,   159,   284,    73,   276,   282,
     288,   266,   266,   266,    26,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   253,    31,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   215,    73,   276,   284,    73,   162,   276,   285,   286,
     287,   284,   266,   284,   284,   160,   169,    73,    73,    31,
     266,    31,   266,   169,   276,   215,   276,   285,   160,   160,
     165,   266,   159,   160,   161,     8,    93,    93,    13,     8,
     160,   160,    42,    43,    63,    81,   127,   148,   151,   169,
     251,   259,   260,   261,   163,    93,    73,   172,   266,   218,
     260,    75,   159,     8,   160,     8,   160,   160,   161,   159,
       8,   160,   160,   159,   163,   168,   215,   245,   270,   159,
     163,   160,     8,    13,   148,   151,   169,   252,   123,   193,
     194,   252,   162,   159,   127,   153,   209,   210,   212,   213,
     252,   165,   159,   159,   282,   266,    26,    64,   270,   160,
     159,   159,   165,   266,   159,   273,   274,   275,    63,   162,
     165,   163,   165,   165,   268,   268,   125,   160,   255,    26,
     176,   266,    26,   176,   204,   243,   266,   270,    31,   196,
     270,   260,    73,    26,   176,   199,    26,   162,   201,   260,
     260,   260,   263,   265,   159,   151,   169,   145,   105,   157,
     178,   179,   181,    73,   163,    13,   209,   183,   161,   270,
     289,   290,    13,   215,   163,   160,   160,   266,   260,   151,
     169,   194,   162,     8,   220,   209,   160,     8,    31,    75,
     158,   211,   215,   215,   266,   253,   215,   215,   163,   215,
      63,    63,   271,   284,   266,    31,   266,   124,   256,   174,
     205,   160,   174,   161,   125,   195,   270,   195,    13,   174,
     161,   202,   161,   202,   125,   165,     8,   264,   263,   169,
      73,   159,   162,   179,   180,   181,   260,   160,   160,   266,
     160,   161,   169,   220,   252,   102,   107,   109,   110,   111,
     112,   113,   114,   115,   163,   221,   223,   236,   237,   238,
     239,   241,   160,   107,   248,   212,   211,    75,    13,   160,
     160,   258,   160,   160,   160,   284,   284,   124,   272,   165,
     163,   268,   285,   206,    68,    69,   207,   161,    86,   243,
     196,   160,   160,   260,    92,   202,    95,    96,    97,   202,
     163,   260,   260,   160,   252,   174,   248,   163,    73,   224,
     252,    75,   240,   247,   239,     8,   161,    26,   214,   159,
     214,    31,   211,    13,   260,   165,   165,   285,    68,    69,
     208,   159,   176,   161,   160,    26,   176,   198,   198,   161,
      95,   161,   266,    26,   161,   203,   163,   125,    75,   163,
     214,    13,     8,   161,   162,   225,    13,     8,   161,   222,
      73,   213,   162,    31,    75,   249,   162,   211,    13,   260,
     275,   159,    26,    70,   266,    26,   176,   197,   174,   161,
     203,   174,   260,   160,   162,   260,   252,    73,   226,   227,
     228,   229,   231,   232,   233,   252,   260,    75,   186,    13,
     174,    75,     8,   160,   174,    13,   260,   266,   174,   161,
     160,   174,    90,   174,   162,   174,   163,   228,   161,    93,
     152,   161,   145,    13,    73,   260,   163,    31,    75,   163,
     260,   160,   176,    88,   161,   174,   163,   234,   239,   230,
     252,    73,   260,   159,    75,    26,   161,   163,    73,     8,
     209,   174,   252,   160,   214,   161,   162,   235,   174,   163
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   166,   167,   168,   168,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   171,   172,   172,
     172,   172,   173,   173,   174,   174,   175,   175,   175,   175,
     176,   176,   176,   176,   176,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   178,   178,   179,   180,   180,   181,
     182,   182,   183,   184,   185,   186,   186,   187,   188,   188,
     189,   189,   189,   189,   190,   190,   191,   192,   192,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     198,   199,   199,   200,   200,   201,   201,   201,   201,   202,
     202,   202,   203,   203,   204,   204,   205,   205,   206,   206,
     207,   207,   208,   208,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   211,   211,   212,   212,   213,   213,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   218,   219,   219,   219,   219,   220,   220,   221,   221,
     221,   222,   221,   223,   224,   224,   225,   225,   226,   226,
     227,   227,   228,   228,   229,   230,   230,   231,   231,   232,
     233,   233,   234,   234,   235,   235,   236,   236,   237,   237,
     238,   238,   239,   239,   239,   239,   239,   239,   240,   240,
     240,   240,   241,   241,   242,   242,   243,   243,   244,   244,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   246,   246,   246,   246,   247,   248,   248,   249,   249,
     249,   249,   250,   250,   250,   250,   250,   250,   250,   250,
     251,   251,   251,   251,   252,   252,   252,   253,   253,   254,
     254,   255,   255,   256,   257,   257,   257,   258,   258,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     261,   262,   262,   262,   262,   262,   262,   263,   263,   264,
     264,   265,   265,   265,   265,   266,   266,   267,   268,   269,
     270,   270,   271,   271,   272,   273,   273,   274,   275,   275,
     275,   276,   276,   277,   277,   278,   279,   279,   280,   280,
     280,   281,   281,   281,   281,   282,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   286,   287,   287,   288,
     288,   289,   289,   290,   290,   290,   291,   291,   292,   292,
     292,   292,   292,   292,   292,   292,   293,   293,   293,   293,
     293,   293,   293,   294,   294,   295,   295,   296,   296,   296,
     297,   297,   298,   299,   299
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
       1,     0,     2,     1,     0,     1,     3,     3,     1,     1,
       2,     4,     3,     5,     1,     3,     2,     0,     3,     2,
       1,     0,    10,     3,     1,     3,     1,     3,     0,     1,
       1,     2,     2,     2,     3,     1,     3,     1,     1,     3,
       4,     3,     0,     1,     1,     3,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     5,
       1,     3,     5,     4,     3,     1,     0,     1,     3,     1,
       6,     3,     4,     6,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     5,     4,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     2,     1,    10,
      11,     2,     2,     4,     4,     1,     0,     4,     3,     4,
       1,     2,     4,     6,     5,     6,     6,     6,     6,     4,
       1,     1,     3,     2,     1,     3,     2,     1,     1,     4,
       1,     2,     0,     2,     0,     2,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     4,     3,     1,
       3,     1,     1,     1,     3,     2,     1,     0,     2,     0,
       1,     5,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     1,     2,     0,     3,     4,     4,     3,     1,     1,
       0,     1,     2,     3,     3,     1,     4,     4,     1,     1,
       1,     1,     3,     2,     1,     4,     4,     1,     1,     4,
       0,     1,     1,     1,     4,     4,     1,     1,     3,     1,
       2,     3,     1,     1,     4,     0,     0,     2,     5,     3,
       3,     1,     6,     4,     4,     2,     4,     4,     2,     2,
       4,     2,     2,     1,     3,     3,     3,     4,     4,     4,
       4,     3,     3,     3,     3
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
#line 208 "parser.y" /* yacc.c:1646  */
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[0]));
  }
#line 3372 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 214 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3380 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 217 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3388 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 223 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_SYMBOL_NAME);
  }
#line 3396 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 226 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-2]), (yyvsp[0]));
  }
#line 3404 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 235 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3414 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 240 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_NAMESPACE, (yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3426 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 247 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-4]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-4])->appendChild((yyvsp[-3]));
  (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3437 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 253 "parser.y" /* yacc.c:1646  */
    {
  NSPAN((yyvsp[-3]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-3])->appendChild(NNEW(n_EMPTY));
  NMORE((yyvsp[-1]), (yyvsp[0]));
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyvsp[-3])->appendChild((yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  }
#line 3450 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 261 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3460 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 266 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3469 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 273 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 3477 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 276 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3486 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 283 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3496 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 288 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3507 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 294 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3518 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3530 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3542 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3554 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 327 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3562 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 330 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3570 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 339 "parser.y" /* yacc.c:1646  */
    {
  (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3580 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 348 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3591 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 354 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3599 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 357 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3607 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 360 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLOSE_TAG);
  }
#line 3615 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 366 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 3623 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3658 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3678 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 418 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_WHILE);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3690 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3703 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3721 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 446 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_SWITCH);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3733 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 453 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_BREAK);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3745 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 460 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_BREAK);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3757 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 467 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_CONTINUE);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3769 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 474 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_CONTINUE);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3781 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 481 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_RETURN);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3793 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 488 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3805 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 495 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3817 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 502 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3827 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 507 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3837 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 512 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3847 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 517 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_INLINE_HTML);
    (yyval) = (yyvsp[0]);
  }
#line 3856 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 521 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3865 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 525 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3874 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 529 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[-1]));
    NMORE((yyvsp[-2]), (yyvsp[-4]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3885 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3907 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 3928 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 570 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_DECLARE);
    (yyvsp[-4])->appendChild((yyvsp[-2]));
    (yyvsp[-4])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3939 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 576 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3948 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 580 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_TRY);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));

    (yyvsp[-5])->appendChild((yyvsp[-1]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-5]));
  }
#line 3962 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 589 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_TRY);
    (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1])));

    (yyvsp[-4])->appendChild(NNEW(n_CATCH_LIST));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3976 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 598 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_THROW);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));

  }
#line 3989 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 606 "parser.y" /* yacc.c:1646  */
    {
  NTYPE((yyvsp[-2]), n_GOTO);
  NTYPE((yyvsp[-1]), n_STRING);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 4002 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 617 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4011 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 621 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NNEW(n_CATCH_LIST);
  (yyval)->appendChild((yyvsp[0]));
}
#line 4020 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 628 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-7]), n_CATCH);
    (yyvsp[-7])->appendChild((yyvsp[-5]));
    (yyvsp[-7])->appendChild(NTYPE((yyvsp[-4]), n_VARIABLE));
    (yyvsp[-7])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyvsp[-7]), (yyvsp[0]));
    (yyval) = (yyvsp[-7]);
  }
#line 4033 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 639 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4041 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 646 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_FINALLY);
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    NMORE((yyvsp[-3]), (yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 4052 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 655 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4061 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 659 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4070 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 678 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4078 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 681 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_REFERENCE);
  }
#line 4086 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 688 "parser.y" /* yacc.c:1646  */
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
#line 4103 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 704 "parser.y" /* yacc.c:1646  */
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
#line 4119 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 715 "parser.y" /* yacc.c:1646  */
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
#line 4136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 730 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[0]);
  }
#line 4145 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 734 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4157 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 741 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4169 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 748 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 4178 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 755 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4186 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 758 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_EXTENDS_LIST)->appendChild((yyvsp[0]));
  }
#line 4194 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 768 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4202 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 771 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_EXTENDS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4212 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 779 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4220 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 782 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_IMPLEMENTS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4230 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 790 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[0]));
  }
#line 4238 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 793 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4246 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 799 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4254 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 802 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4262 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 809 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4272 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 818 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4282 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 827 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4292 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 836 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4302 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 844 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4313 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 850 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));
    (yyval) = (yyvsp[-4]);
  }
#line 4326 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 861 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4334 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 864 "parser.y" /* yacc.c:1646  */
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[-2]), n_STATEMENT);
    (yyvsp[-3])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));
    NEXPAND((yyvsp[-3]), (yyval), (yyvsp[0]));
  }
#line 4349 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 874 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-2]), (yyvsp[0]));
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval) = (yyvsp[-2]);
  }
#line 4359 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 879 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_STATEMENT);
    (yyvsp[-4])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-3]));
    (yyval)->appendChildren((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
    NMORE((yyval), (yyvsp[-4]));
  }
#line 4373 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 891 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4381 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 894 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CASE);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyvsp[-3]));
    (yyval) = (yyvsp[-4]);
  }
#line 4394 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 902 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_DEFAULT);
    (yyvsp[-2])->appendChild((yyvsp[0]));

    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval) = (yyvsp[-3]);
  }
#line 4406 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 918 "parser.y" /* yacc.c:1646  */
    {
  NMORE((yyvsp[-2]), (yyvsp[0]));
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  (yyval) = (yyvsp[-2]);
  }
#line 4416 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 926 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4424 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 929 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-4]), n_ELSEIF);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyvsp[-4]));
  }
#line 4436 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 939 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4444 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 942 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_ELSEIF);
    (yyvsp[-5])->appendChild((yyvsp[-3]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyvsp[-5]));
  }
#line 4456 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 952 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4464 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 955 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_ELSE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4474 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 963 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4482 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 966 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ELSE);
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4492 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 975 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
#line 4500 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 981 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4513 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 989 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4527 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 998 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4541 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1007 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4554 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1015 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 4567 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1023 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4581 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1033 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyval));
  }
#line 4595 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 4608 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1054 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_UNPACK);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 4617 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1058 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4625 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1064 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4633 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1071 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4641 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1074 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4649 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1077 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4657 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4665 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1086 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4673 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1093 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
#line 4681 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1099 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4689 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1102 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4697 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1108 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4706 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1112 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4715 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1119 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4723 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1122 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4732 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1126 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-3]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 4741 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1133 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 4754 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1141 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4767 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1149 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4780 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1157 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4793 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1168 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4801 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1171 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4809 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1177 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4822 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1185 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4831 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1189 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4839 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1192 "parser.y" /* yacc.c:1646  */
    {
    /* empty */
  }
#line 4847 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1194 "parser.y" /* yacc.c:1646  */
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
#line 4865 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1210 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-2]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4875 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1218 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[0]));
  }
#line 4883 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1221 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4891 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1227 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4899 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1230 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4907 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1236 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
#line 4915 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1239 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4923 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1245 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4932 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1249 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4941 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1256 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 4949 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1259 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 4957 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1265 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4967 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1273 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4976 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1277 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4985 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1284 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 4994 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1288 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5002 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1294 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[-2]), (yyvsp[-1]), NTYPE((yyvsp[0]), n_STRING));
    (yyval) = (yyvsp[-1]);
  }
#line 5012 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1302 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5023 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1308 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 5034 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1317 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5042 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1320 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5051 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1328 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5059 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1331 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5067 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1338 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5076 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1345 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
#line 5084 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1348 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[0]);
  }
#line 5093 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1355 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5102 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1359 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5110 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1374 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 5122 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1381 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 5134 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1388 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5146 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1395 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5158 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1405 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));

    (yyval) = (yyvsp[-4]);
  }
#line 5172 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1414 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyvsp[-3])->appendChild((yyval));

    (yyval) = (yyvsp[-3]);
  }
#line 5186 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1426 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5194 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1429 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5203 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1436 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5211 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1444 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5219 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1447 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5228 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1454 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-5]), n_LIST);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5241 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1462 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5252 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1468 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));

    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));

    (yyval)->appendChild((yyvsp[-1]));
  }
#line 5267 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1478 "parser.y" /* yacc.c:1646  */
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
#line 5286 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1492 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5296 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1497 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5307 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1503 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5318 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1509 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5329 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1515 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5340 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1521 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5351 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1527 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5362 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1533 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5373 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1539 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5384 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1545 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5395 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1551 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5406 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1557 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5417 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1563 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5427 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1568 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5437 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1573 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5447 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1578 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5457 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1583 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5468 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1589 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5479 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1595 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5490 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1601 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5501 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1607 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5512 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1613 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5523 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1619 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5534 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1625 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5545 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1631 "parser.y" /* yacc.c:1646  */
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
#line 5576 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1657 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5587 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1663 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5598 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1669 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5609 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1675 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5620 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1681 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5631 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1687 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5642 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1693 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5653 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1699 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5663 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1704 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5673 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1709 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5683 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1714 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5693 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1719 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5704 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1725 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5715 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1731 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5726 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1737 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5737 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1743 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5748 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1749 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5759 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1755 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5770 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1761 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5781 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1767 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5792 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1775 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5805 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1783 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5818 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1792 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5828 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1797 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5838 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1802 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5848 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1807 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5858 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1812 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5868 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1817 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5878 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1822 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5888 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1827 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5898 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1832 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5908 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1837 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[0]);
  }
#line 5917 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1844 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5927 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1849 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[0]);
  }
#line 5938 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1858 "parser.y" /* yacc.c:1646  */
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
#line 5955 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1873 "parser.y" /* yacc.c:1646  */
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
#line 5978 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1894 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 5989 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1900 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6000 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1906 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6011 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1912 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6022 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1925 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6030 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1928 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[-3])->appendChildren((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6040 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1936 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6048 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1939 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 6058 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1944 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6067 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1948 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 6078 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1957 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6088 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1963 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-5]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6099 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1969 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-4]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6110 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1976 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6123 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1985 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6136 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1994 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6149 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 2003 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6162 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 2011 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6172 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 2019 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6180 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 2022 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6188 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 2025 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6197 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 2029 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6206 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 2036 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6214 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 2039 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6223 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 2043 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6232 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 2058 "parser.y" /* yacc.c:1646  */
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
#line 6249 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 2074 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 6257 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2077 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6265 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 2083 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6273 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 2089 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6281 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 2092 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-1]), n_EMPTY, (yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6290 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 2096 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 6300 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 2104 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6308 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 2107 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6316 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2113 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6324 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2116 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6332 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2119 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_STRING_SCALAR);
  }
#line 6340 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2122 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6348 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2125 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6356 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2128 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6364 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2131 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6372 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2134 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6380 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2137 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6388 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2140 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6396 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2143 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6404 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2146 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_HEREDOC);
  }
#line 6412 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2154 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = (yyvsp[0]);
  }
#line 6421 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2158 "parser.y" /* yacc.c:1646  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = (yyvsp[0]);
  }
#line 6430 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2162 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6440 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2167 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6450 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 2172 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 6460 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 2177 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 6470 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 2186 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 6480 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2197 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-2]));
  }
#line 6488 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 2200 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-1]));
  }
#line 6496 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2207 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6504 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 2210 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6512 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 2216 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6520 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2227 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6532 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2234 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6544 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2241 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6556 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2248 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6568 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2278 "parser.y" /* yacc.c:1646  */
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
#line 6596 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2305 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1])->appendChildren((yyvsp[0]));
  }
#line 6604 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2308 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6612 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2314 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[-1]));
    if ((yyvsp[0])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[0]));
    }
  }
#line 6624 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2324 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6635 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2330 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6646 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2339 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6654 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2347 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6662 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2354 "parser.y" /* yacc.c:1646  */
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
#line 6679 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2369 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6689 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 2374 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6699 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2386 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6710 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2392 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6721 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2408 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6729 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2411 "parser.y" /* yacc.c:1646  */
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
#line 6746 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2427 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6757 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2433 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6768 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2443 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 6776 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2446 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-3]), n_VARIABLE_EXPRESSION, (yyvsp[0]));
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6786 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2454 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6794 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2457 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6802 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2468 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6813 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2474 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6824 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2484 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[0]), n_STRING);
    (yyval) = (yyvsp[0]);
  }
#line 6833 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2488 "parser.y" /* yacc.c:1646  */
    {
  (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6841 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2494 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);
  }
#line 6849 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2497 "parser.y" /* yacc.c:1646  */
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
#line 6866 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2512 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 6874 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2515 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6883 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2523 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6892 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2527 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6900 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2533 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6908 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2536 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6916 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2542 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6928 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2549 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6940 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2556 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6952 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2563 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6964 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2570 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 6976 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2577 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 6988 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2584 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7000 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2591 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7012 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2601 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7027 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2611 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7042 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2621 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7050 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2624 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7058 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2627 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7073 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2637 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7081 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2640 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7089 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2646 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7098 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2650 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7106 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2656 "parser.y" /* yacc.c:1646  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 7116 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2661 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 7124 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2667 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7135 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2673 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7146 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2679 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7157 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2688 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 7167 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2693 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 7177 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2701 "parser.y" /* yacc.c:1646  */
    {
    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 7188 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2710 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7198 "parser.yacc.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2715 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7208 "parser.yacc.cpp" /* yacc.c:1646  */
    break;


#line 7212 "parser.yacc.cpp" /* yacc.c:1646  */
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
#line 2722 "parser.y" /* yacc.c:1906  */


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
/* @generated */
