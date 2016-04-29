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
#define YYLAST   7711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  438
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  896

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
    1077,  1083,  1086,  1092,  1093,  1099,  1102,  1105,  1110,  1113,
    1116,  1124,  1128,  1135,  1138,  1142,  1149,  1157,  1165,  1173,
    1184,  1187,  1193,  1201,  1205,  1208,  1208,  1226,  1234,  1237,
    1243,  1246,  1252,  1255,  1261,  1265,  1272,  1275,  1281,  1289,
    1293,  1300,  1304,  1310,  1318,  1324,  1333,  1336,  1344,  1347,
    1353,  1354,  1361,  1364,  1371,  1375,  1381,  1382,  1383,  1384,
    1385,  1386,  1390,  1397,  1404,  1411,  1421,  1430,  1442,  1445,
    1452,  1455,  1460,  1463,  1470,  1478,  1484,  1494,  1508,  1513,
    1519,  1525,  1531,  1537,  1543,  1549,  1555,  1561,  1567,  1573,
    1579,  1584,  1589,  1594,  1599,  1605,  1611,  1617,  1623,  1629,
    1635,  1641,  1647,  1673,  1679,  1685,  1691,  1697,  1703,  1709,
    1715,  1720,  1725,  1730,  1735,  1741,  1747,  1753,  1759,  1765,
    1771,  1777,  1783,  1789,  1790,  1791,  1799,  1807,  1808,  1813,
    1818,  1823,  1828,  1833,  1838,  1843,  1848,  1853,  1857,  1858,
    1859,  1860,  1865,  1871,  1886,  1910,  1916,  1922,  1928,  1937,
    1941,  1944,  1952,  1955,  1960,  1964,  1973,  1978,  1985,  1991,
    2000,  2009,  2018,  2027,  2035,  2038,  2041,  2045,  2052,  2055,
    2059,  2066,  2067,  2071,  2086,  2090,  2093,  2099,  2105,  2108,
    2112,  2120,  2123,  2129,  2132,  2135,  2138,  2141,  2144,  2147,
    2150,  2153,  2156,  2159,  2162,  2168,  2169,  2170,  2174,  2178,
    2183,  2188,  2193,  2198,  2202,  2210,  2211,  2212,  2213,  2216,
    2219,  2223,  2226,  2232,  2235,  2239,  2250,  2257,  2264,  2274,
    2275,  2279,  2283,  2287,  2291,  2317,  2321,  2324,  2330,  2340,
    2346,  2355,  2361,  2362,  2363,  2369,  2370,  2385,  2390,  2398,
    2402,  2408,  2417,  2418,  2419,  2423,  2424,  2427,  2439,  2443,
    2449,  2455,  2459,  2462,  2470,  2473,  2479,  2480,  2484,  2490,
    2496,  2500,  2504,  2510,  2513,  2528,  2531,  2538,  2539,  2543,
    2549,  2552,  2558,  2565,  2572,  2579,  2586,  2593,  2600,  2607,
    2617,  2627,  2637,  2640,  2643,  2653,  2656,  2662,  2666,  2672,
    2677,  2683,  2689,  2695,  2704,  2709,  2717,  2726,  2731
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

#define YYPACT_NINF -694

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-694)))

#define YYTABLE_NINF -380

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-380)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -694,    84,  1875,  -694,  6247,  6247,   -62,  6247,  6247,  6247,
    6247,  6247,  6247,  6247,   202,   202,  6247,  6247,  6247,  6247,
    6247,  6247,  6247,  6247,  4675,   386,  6247,   -50,   -22,  -694,
    -694,   101,  -694,  -694,  -694,    67,  -694,  6247,  4535,     7,
      12,    58,    78,    87,  4806,  4937,   180,  -694,   191,  5068,
     106,  6247,    79,    -7,     6,   179,   185,   131,   143,   157,
     163,  -694,  -694,   192,   196,  -694,  -694,  -694,  -694,  -694,
    -694,  -694,  -694,  -694,   -29,  -694,  -694,   284,  -694,  -694,
    6247,  6378,  -694,  -694,   197,   -46,  -694,    17,  -694,  -694,
    -694,  -694,  -694,  -694,   289,   291,  -694,   206,   337,   307,
     227,  -694,  -694,  6701,  -694,   209,  1892,   215,  -694,   230,
     318,   254,  -694,   -20,  -694,    48,  -694,  -694,   323,   324,
    -694,  -694,  -694,   292,   238,  -694,   337,  7517,  7517,  6247,
    7517,  7517,  7617,  -694,  -694,   349,  -694,  -694,   249,   284,
     339,   -58,   256,  -694,  -694,   273,  -694,  -694,  -694,  -694,
    -694,  -694,  -694,  -694,  -694,   202,  7281,   265,   411,   281,
     284,   282,   299,   275,  -694,   302,   325,   -42,    48,  -694,
    5199,  -694,  6247,  -694,  6247,    18,  7517,   365,  6247,  6247,
    6247,   378,  6247,  -694,  6742,  -694,  6795,   296,   439,  -694,
     301,  7517,  1368,  -694,  6836,   284,   -32,    19,  -694,  -694,
     201,    22,  -694,   440,    24,   337,  -694,  -694,   202,   202,
     202,   306,   153,  4675,   284,  -694,   158,   -45,   112,  7332,
    1018,   308,  6877,   313,  2015,  6247,   383,  5330,   387,  -694,
     345,   352,  -694,  -694,   -11,  6247,   -17,  6247,  6247,  6247,
    5461,  6247,  6247,  6247,  6247,  6247,  6247,  6247,  6247,  6247,
    6247,  6247,  6247,  6247,  6247,  6247,  6247,  6247,  6247,  6247,
    6247,  6247,   386,  -694,  -694,  -694,  5592,  6247,  6247,  6247,
    6247,  6247,  6247,  6247,  6247,  6247,  6247,  6247,  5330,    10,
    6247,    56,  6247,  6247,   197,    -8,  6247,  6247,   317,  6930,
     284,   -47,   313,    65,    71,  -694,  -694,  5723,  -694,  5854,
    -694,   284,   282,    61,  5330,  -694,    61,    56,   -27,  -694,
    6971,  7013,  7517,   314,  6247,  -694,   321,  7064,   322,   476,
    7517,   393,  1058,   478,    15,  7105,  -694,  -694,  -694,  7388,
    -694,  -694,  2155,  -694,    89,   420,    79,  -694,  6247,  -694,
    -694,    -7,  -694,  7388,   419,  -694,   342,    29,  -694,  -694,
    -694,    31,   338,   341,   347,  -694,    32,  -694,   344,    93,
    1573,  -694,  -694,  5330,  6247,  -694,  -694,  -694,   355,  -694,
    -694,  -694,  -694,  -694,  1305,  -694,   202,   364,   507,    33,
     900,   512,    83,   403,    83,   367,   372,    94,   373,   380,
     381,   -27,    48,  7557,  7594,  7617,  6247,  7445,  7662,  7403,
    4728,  4859,  4988,  5119,  5119,  5119,  5119,  1252,  1252,  1252,
    1252,   396,   396,   290,   290,   290,   349,   349,   349,  -694,
      68,  7617,  7617,  7617,  7617,  7617,  7617,  7617,  7617,  7617,
    7617,  7617,  7617,   382,   385,   388,   376,  -694,  6247,  -694,
     389,    -3,  -694,   384,  1503,   400,   402,  -694,   100,   380,
     385,   202,  7517,   202,  7380,   282,  -694,   391,  -694,  -694,
    -694,  3835,  -694,  7517,  6247,  3975,  6247,  6247,   202,    51,
    7388,   473,  4115,    44,  7388,  7388,  7388,  -694,   394,   401,
     284,   -57,   416,  -694,  -694,  -694,   109,   495,  -694,  -694,
    6521,  -694,  -694,   556,    94,   202,   409,   202,  -694,  -694,
    -694,   153,   153,   561,  -694,  5330,  -694,  1735,   417,   127,
    1740,   418,  -694,  -694,  -694,  5985,  7388,   425,   284,   282,
    -694,    83,   422,   572,  -694,  -694,    94,  -694,  -694,   426,
     577,    42,  -694,  -694,  -694,  5330,  5330,   -27,  7640,  6247,
     386,  -694,  -694,  5330,  5330,  -694,  6562,  5330,   524,   525,
    -694,  6247,  6247,  -694,  -694,  -694,  -694,  -694,  -694,  6116,
    -694,   466,  -694,  -694,  7147,  -694,  -694,  -694,   430,  7517,
     467,   202,   467,  -694,  -694,   582,  -694,  -694,  -694,   442,
     443,  -694,  -694,  -694,   481,   445,   599,  7388,   284,   -35,
     535,   452,   450,   109,  -694,  -694,  -694,  -694,  7388,   454,
    -694,  -694,  -694,    34,  -694,  6247,   455,  -694,  -694,   457,
     202,    37,  1003,  -694,   284,   282,   572,  -694,    83,   295,
     456,   513,   170,    23,  -694,   546,   609,   463,   465,  7640,
     275,   468,   471,  -694,   472,  6247,  6247,   503,   469,  6603,
     202,  7517,    56,  -694,  3695,   239,   477,  2295,  6247,    51,
     479,  -694,   480,  7388,  2435,  -694,   288,  -694,   -10,  7388,
    -694,  7388,  -694,   486,   141,  -694,    83,  -694,  -694,  -694,
    -694,  -694,   513,  -694,  7617,  -694,  -694,  -694,   282,   487,
    -694,   560,    83,  -694,  -694,  -694,  -694,  -694,  -694,  -694,
    -694,  -694,  -694,   562,   292,   315,  -694,    25,   615,   488,
     615,    43,   636,  -694,  7388,  -694,  -694,  -694,  -694,  -694,
    -694,   490,   493,    56,  -694,  -694,  -694,  -694,  -694,   258,
     492,  4535,  -694,  -694,   498,   500,  -694,  4255,  4255,  -694,
     501,   326,   504,  6247,     2,    -1,  -694,  -694,   539,  -694,
     592,  2575,   615,  -694,   655,    11,  -694,   656,    26,  -694,
    -694,   600,  -694,   170,   510,    36,   516,    23,   661,  7388,
    -694,  -694,  -694,   389,   521,   657,   611,  6247,  -694,  -694,
    4395,  -694,  -694,  -694,  -694,  -694,   523,  -694,  6660,  -694,
    -694,  -694,  -694,  7388,   522,  -694,   526,  7388,    83,  -694,
      85,  -694,  7388,   610,  -694,   337,   673,  -694,  -694,   612,
    -694,    38,  -694,   676,  7388,  -694,  -694,  6247,  -694,   530,
    7198,  -694,  -694,  -694,  2715,  -694,  -694,  3695,  -694,   531,
    -694,  -694,  -694,   601,   532,    85,  -694,   536,   603,   548,
     537,   557,  -694,   691,   633,  7388,  2855,  -694,    40,  -694,
    2995,  7388,  -694,  7239,  3695,  -694,  4535,  3135,   547,  3695,
    -694,  3275,  -694,  -694,  -694,   446,    83,  -694,   637,  7388,
     550,  -694,  -694,   638,  -694,  -694,  -694,   685,  -694,   553,
    -694,  3415,  -694,   642,   643,   709,  -694,  -694,  -694,    94,
    -694,  -694,  -694,  -694,  -694,    83,   558,  3695,  -694,   615,
     182,  -694,  -694,  -694,  3555,  -694
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,     0,     0,   318,     0,   323,
     324,     5,   345,   392,    52,   325,   277,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,    80,    86,     0,     0,   329,   330,   332,   326,   327,
      32,    33,    34,   334,     0,   333,   328,     0,    83,   331,
     282,     0,    59,    25,   403,   347,     3,     0,     7,    30,
       8,     9,    73,    74,     0,     0,   360,     0,    75,   384,
       0,   350,   278,     0,   359,     0,   361,     0,   388,     0,
     383,   365,   382,   385,   391,     0,   267,   263,   279,   280,
     264,   346,     5,   304,     0,   282,    75,   422,   423,     0,
     425,   426,   281,   250,   251,   252,   253,   304,     0,     0,
       0,   305,     0,   231,   363,     0,   233,   268,   269,   270,
     271,   272,   273,   274,   276,     0,   415,     0,   353,     0,
       0,   305,   311,   321,   312,     0,   314,   385,     0,   218,
       0,   275,     0,    31,   394,     0,   209,     0,     0,   210,
       0,     0,     0,    42,     0,    44,     0,     0,     0,    46,
     360,     0,   361,    25,     0,     0,    18,     0,    17,   153,
       0,     0,   152,   158,     0,    75,    81,    82,     0,     0,
       0,     0,   409,   410,     0,     4,     0,   349,   360,     0,
     361,     0,     0,   264,     0,     0,     0,   144,     0,    15,
      84,    87,    54,    76,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,   230,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     394,     0,   394,     0,   404,   387,   394,   394,     0,     0,
       0,   307,     0,     0,     0,   419,   362,     0,   435,   354,
     411,     0,   307,     0,   144,   436,     0,     0,   387,   319,
       0,     0,   395,     0,     0,    51,     0,     0,     0,   211,
     213,   360,   361,     0,     0,     0,    43,    45,    63,     0,
      47,    48,     0,    62,    20,     0,     0,    14,     0,   154,
     361,     0,    49,     0,     0,    50,     0,     0,    70,    72,
     427,     0,     0,     0,     0,   407,     0,   406,     0,   348,
       0,    11,     4,   144,     0,   430,   429,   386,     0,    35,
      24,    26,    27,    28,     0,     6,     0,     0,   143,   360,
     361,     0,     0,    89,     0,     0,     0,   136,     0,   437,
     377,   375,     0,   236,   238,   237,     0,     0,   234,   235,
     239,   241,   240,   256,   257,   254,   255,   258,   259,   260,
     261,   248,   249,   243,   244,   242,   245,   246,   247,   262,
       0,   215,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   438,   378,     0,   401,     0,   397,
     374,   396,   400,     0,     0,     0,     0,   424,   306,     0,
       0,     0,   414,     0,   413,   306,   377,     0,   378,   316,
     320,     0,   433,   208,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   351,   325,     0,     0,
       0,   336,     0,   335,    23,   343,     0,     0,    19,    16,
       0,   151,   159,   156,   136,     0,     0,     0,   420,   421,
      10,   409,   409,     0,   434,   144,    13,     0,     0,   360,
     361,     0,   393,   147,   296,     0,     0,     0,     0,   308,
      85,     0,     0,    88,    91,   161,   136,   139,   140,     0,
     124,     0,   137,   138,   381,   144,   144,   376,   266,     0,
       0,   216,   303,   144,   144,   380,     0,   144,   373,   372,
     367,   394,     0,   389,   390,   432,   431,   418,   417,     0,
     322,   313,    25,   116,     0,    25,   114,    38,     0,   212,
      93,     0,    93,    95,   103,     0,    25,   101,    58,   109,
     109,    41,   339,   340,   358,     0,   353,   351,     0,   338,
       0,     0,     0,    67,    65,    61,    21,   155,     0,     0,
      71,    55,   428,     0,   405,     0,     0,    12,   298,     0,
       0,   360,   361,    22,     0,   310,    90,   161,     0,   192,
       0,   290,   136,     0,   135,     0,   126,     0,     0,   265,
     321,     0,     0,   402,     0,   394,   394,   364,     0,     0,
       0,   412,     0,   315,   118,   120,     0,     0,   210,     0,
       0,    96,     0,     0,     0,   109,     0,   109,     0,     0,
     342,   354,   352,     0,   337,   344,     0,    25,    64,    60,
      68,   157,   290,   408,   214,   297,    29,   150,   309,   192,
      92,     0,     0,   199,   200,   201,   198,   197,   196,   191,
      79,   160,   164,     0,     0,   190,   194,     0,   141,     0,
     141,     0,   127,   134,     0,   299,   302,   217,   300,   301,
     371,     0,     0,     0,   366,   398,   399,   416,   317,   122,
       0,     0,    36,    39,     0,     0,    94,     0,     0,   104,
       0,     0,     0,     0,     0,     0,   105,   357,   356,   341,
       0,     0,   141,    78,     0,     0,   168,   204,     0,   165,
     195,     0,   163,     0,     0,     0,     0,     0,   130,     0,
     129,   369,   370,   374,     0,     0,     0,     0,   121,   115,
       0,    25,    99,    57,    56,   102,     0,   107,     0,   112,
     113,    25,   106,     0,     0,    69,     0,     0,     0,   170,
     172,   167,     0,     0,   162,    75,     0,   142,    25,     0,
     294,     0,    25,   131,     0,   128,   368,     0,    25,     0,
       0,    25,    97,    40,     0,   108,    25,   111,   355,     0,
      25,   207,   169,     5,     0,   173,   174,     0,     0,   182,
       0,     0,   205,   202,     0,     0,     0,   295,     0,   291,
       0,     0,   133,     0,   123,    37,     0,     0,     0,   110,
      25,     0,   171,   175,   176,   186,     0,   177,     0,     0,
       0,   206,    77,     0,   292,   283,   132,     0,   117,     0,
     100,     0,   284,     0,   185,   178,   179,   183,   203,   136,
     293,    25,    98,    66,   184,     0,     0,   119,   180,   141,
       0,   188,    25,   166,     0,   189
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -694,  -694,  -198,    -5,  -694,  -694,   390,  -694,  -145,  -694,
      16,  -694,  -694,   126,  -694,   128,  -694,   228,    13,    20,
    -125,  -694,  -694,  -694,  -694,  -694,  -694,  -694,   204,   150,
      80,  -694,     0,  -694,  -694,  -694,  -357,   -51,  -694,  -694,
    -694,  -694,  -694,  -491,  -694,  -573,   108,   -19,  -693,  -202,
    -694,  -694,   392,  -694,   114,  -694,  -694,  -694,  -694,  -694,
    -694,  -694,   -93,  -694,  -694,  -694,  -694,  -694,  -694,  -694,
    -694,  -694,  -694,  -679,  -694,  -694,  -694,  -460,  -694,    28,
     654,    -2,    66,  -694,  -694,   300,  -353,  -251,  -694,  -694,
    -694,  -694,   110,   -80,  -305,  -694,  -694,   154,   156,  -694,
     964,   545,  -362,   332,   948,  -694,  -694,  -694,  -694,   -14,
    -228,  -694,   911,  -694,  -694,   -21,   -23,  -694,  -223,  -302,
    -694,  -694,   -12,   245,   248,   543,  -694,  -694,  -694,  -694,
    -694,  -694,     9,  -694
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   197,   198,    87,   224,   370,
     371,    89,   593,   594,   669,   595,   347,   348,   372,   373,
     234,    92,    93,    94,   383,    95,   385,   522,   523,   650,
     572,   813,   773,   578,   324,   581,   656,   781,   567,   645,
     719,   722,   766,   529,   530,   626,   531,   532,   754,   377,
     378,   201,   202,   204,   619,   691,   795,   692,   745,   791,
     824,   825,   826,   827,   875,   828,   829,   830,   873,   893,
     693,   694,   695,   696,   748,   697,   175,   318,   319,    96,
      97,   126,   700,   801,    99,   100,   533,   163,   164,   561,
     643,   171,   305,   101,   584,   485,   102,   585,   300,   586,
     103,   104,   295,   105,   106,   637,   714,   548,   549,   550,
     107,   108,   109,   110,   111,   112,   113,   114,   313,   440,
     441,   442,   115,   356,   357,   157,   158,   116,   351,   117,
     118,   119,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   288,   167,   599,   166,   459,   568,   756,   390,   141,
     141,   419,   388,   168,   513,    90,   750,   360,    88,   788,
     161,   282,    91,   471,   484,   228,   314,   336,   779,   520,
     341,   524,   344,   751,   793,   620,   282,   495,   492,   497,
     502,  -145,   502,   282,   122,  -148,   838,   196,   332,   786,
     702,   435,   205,   439,   177,   282,   389,   436,    33,   443,
     551,   335,   386,   445,   446,   390,   435,   799,   199,   216,
     579,   863,   217,   623,   757,   456,   433,   190,   458,   439,
     346,   203,   571,   434,     3,    33,   733,   734,  -305,   557,
     223,   558,   285,   226,   226,   733,   734,   129,   624,  -305,
    -307,   227,   457,  -379,   226,   226,   226,    47,   218,   170,
    -307,   800,   363,   227,   363,   864,   226,   624,   624,   226,
     283,   205,   214,    33,   122,  -379,    33,   173,   758,   437,
     174,    33,   540,   215,   291,   283,    33,   172,   449,  -375,
      33,   122,   283,    33,   450,   308,    33,    84,   387,   292,
     141,  -376,   122,   736,   283,   302,   122,   200,   823,   552,
     137,   508,   782,   780,   507,   574,   178,   122,   524,   582,
     583,   179,   789,   790,    84,   472,   874,   137,   229,   315,
     337,   625,   487,   342,   803,   345,   752,   794,   725,   496,
     334,   498,   503,  -145,   673,   141,   890,  -148,   839,   138,
     625,   625,   139,   141,   141,   141,   580,   141,   321,   359,
     140,   613,   284,   391,   591,    84,   138,   180,   438,   139,
      84,   527,    98,   658,   392,    84,   122,   140,    33,    84,
     195,   517,    84,   517,   518,    84,   518,   181,  -306,   167,
     226,   166,   517,   122,   226,   518,   182,   528,   677,   483,
     168,   226,   505,   187,  -125,   379,   391,   161,   391,   505,
     264,   265,   137,   483,   188,   680,   592,   392,   193,   392,
     391,   391,  -285,  -285,   122,   122,    33,    33,   717,   354,
     391,   392,   392,   391,   391,   448,  -306,  -287,  -287,   630,
     208,   392,   226,   671,   392,   392,   455,   527,   731,   206,
     735,   138,   209,   606,   139,   207,   379,   720,   721,   226,
     137,   137,   140,   740,   142,   142,   210,    84,   517,   361,
     362,   518,   211,   528,   481,   162,   764,   765,   638,   746,
      98,   196,   379,   627,   628,   259,   260,   261,   481,   262,
     718,   631,   632,   891,   892,   634,   143,   146,   729,   138,
     138,   212,   139,   139,   737,   213,   738,   122,    98,   225,
     140,   140,   230,   338,   231,    84,    84,   232,   233,   537,
     235,   141,   236,    90,   278,   279,    88,   519,   281,   519,
      91,   280,   519,   732,   733,   734,   286,   287,   886,   214,
     483,   379,   509,    47,   483,   483,   483,   681,   262,   760,
     290,   293,   682,    25,   683,   684,   685,   686,   687,   688,
     689,   763,   711,   712,   439,   141,  -193,   644,   294,   299,
     647,   776,   733,   734,   683,   684,   685,   686,   687,   688,
     298,   654,   301,   226,   304,   822,   483,   831,   256,   257,
     258,   259,   260,   261,   303,   262,   141,   306,   141,   307,
     316,   323,   329,   343,   805,   142,   375,   328,   690,   122,
     381,    33,   330,   141,   141,   481,   353,   382,   365,   481,
     481,   481,   831,   367,   384,   589,   387,   563,   818,   462,
     464,   566,   821,   466,   467,   439,   468,   832,   577,   519,
     141,   470,   141,   488,   493,   137,   141,   141,   499,   842,
     142,   494,   500,   876,   504,    98,   501,   483,   142,   142,
     142,   481,   142,   615,   511,   515,   519,   167,   483,   166,
      90,   519,   741,    88,   514,   516,   521,    91,   168,   525,
     861,   526,   888,   379,   159,   161,   866,   160,   534,   535,
     536,   545,   542,   611,   543,   140,   575,   544,   547,   553,
      84,   560,   588,   587,   878,   683,   684,   685,   686,   687,
     688,   590,   162,   379,   379,   555,   141,   556,   596,   598,
     601,   379,   379,   483,   605,   379,   614,   608,   609,   483,
     618,   483,   481,   664,   617,   622,   621,   635,   636,   681,
     642,   648,   649,   481,   682,   653,   683,   684,   685,   686,
     687,   688,   689,   655,   657,   141,   659,   661,   665,   678,
     660,   666,   667,   519,   672,   675,   698,   519,   676,   391,
     699,   703,   704,   705,   483,   706,   814,   713,   708,   482,
     392,   709,   710,   744,   715,   141,   817,   747,   723,   727,
     728,   753,    98,   482,   141,    98,   739,   755,   481,   759,
     743,   767,    98,   836,   481,   761,   481,   840,   762,   769,
     770,   519,   775,   844,   783,   777,   847,   784,   787,   792,
     834,   849,   798,   796,   804,   851,   142,   519,   802,   483,
     807,   809,   819,   808,   815,   833,   835,   837,   820,   841,
     391,   845,   749,   850,  -181,   852,   855,   854,   857,   481,
     856,   392,   858,   483,   859,   871,   860,   483,   870,   879,
     877,   881,   483,   880,   882,   884,  -187,   885,   889,   668,
     142,   670,   652,   600,   483,   616,   489,   816,   774,   726,
     701,   679,   853,   491,   797,   221,   887,   768,   742,    98,
     707,   663,   662,   772,   772,   339,   603,   894,   519,   806,
     604,   142,     0,   142,   481,   483,   358,     0,     0,     0,
       0,   483,     0,     0,     0,     0,     0,     0,   142,   142,
     482,     0,     0,     0,   482,   482,   482,     0,   481,   483,
       0,     0,   481,   519,     0,   519,   812,   481,     0,     0,
       0,     0,     0,     0,     0,   142,     0,   142,     0,   481,
       0,   142,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,    98,   482,     0,     0,     0,
     519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,     0,     0,     0,    98,     0,   481,     0,    98,     0,
     162,     0,    98,     0,     0,    98,     0,    98,     0,    98,
       0,   519,     0,     0,   481,     0,     0,     0,     0,     0,
       0,     0,   868,     0,     0,     0,     0,     0,     0,    98,
       0,   142,     0,     0,   519,     0,     0,     0,     0,     0,
     519,     0,     0,     0,     0,    98,     0,   482,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,   482,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -146,     0,
     142,     0,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   145,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,  -363,  -363,   482,     0,     0,     0,     0,     0,   482,
       0,   482,   144,   144,     0,     0,     0,     0,   127,   128,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   156,     0,
     169,     0,     0,     0,     0,     0,     0,   192,     0,     0,
       0,   176,     0,     0,   482,     0,     0,     0,   184,   186,
       0,  -149,     0,   191,     0,   194,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   220,     0,
       0,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,   219,   222,     0,     0,     0,     0,
       0,     0,     0,     0,  -363,  -363,     0,     0,     0,   482,
    -146,     0,     0,     0,     0,     0,   145,     0,     0,  -363,
    -363,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   482,     0,     0,     0,   482,     0,     0,
       0,     0,   482,   289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   296,   482,     0,     0,     0,     0,  -363,
    -363,   145,     0,     0,     0,     0,     0,     0,     0,   145,
     145,   145,     0,   145,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,   310,   482,   311,     0,   312,     0,
       0,   482,   317,   320,   191,     0,   325,     0,   340,     0,
       0,   469,     0,     0,     0,     0,   349,   350,   352,   482,
     355,     0,     0,  -149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,   380,     0,   156,  -286,  -286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   374,
       0,   191,     0,     0,     0,     0,     0,     0,     0,   312,
       0,   393,   394,   395,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   380,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   191,     0,   312,     0,   312,   444,     0,     0,
     312,   312,   380,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,   454,     0,     0,     0,     0,   191,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,     0,     0,     0,     0,     0,     0,   145,  -380,  -380,
    -380,  -380,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   490,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   510,     0,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,   191,   191,     0,
     240,   145,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,     0,     0,     0,     0,     0,
     538,     0,   145,     0,   145,     0,     0,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     145,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,     0,   296,
       0,   296,   546,     0,     0,     0,   145,     0,   145,     0,
       0,     0,   145,   145,     0,     0,   570,   573,     0,  -363,
    -363,     0,     0,     0,     0,     0,     0,     0,   564,     0,
     320,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,     0,   602,     0,     0,     0,   355,
     355,   165,     0,   380,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,     0,     0,     0,     0,   512,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
       0,     0,   145,   380,   380,     0,     0,     0,     0,     0,
       0,   380,   380,     0,     0,   380,     0,     0,     0,   191,
     191,     0,     0,   629,     0,     0,     0,   191,   191,     0,
       0,   191,   237,   238,   239,   312,   639,     0,     0,   651,
       0,   145,     0,   641,     0,     0,     0,     0,   240,   331,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   145,   262,     0,     0,     0,     0,     0,   296,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,   674,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,   573,     0,   312,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    41,     0,    42,     0,   554,    43,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,     0,     0,   778,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     0,    70,    71,
       0,    72,     0,     0,     0,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,     0,     0,    78,    79,    80,
       0,   810,    81,     0,    82,    83,   506,    84,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
       0,   843,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,  -363,  -363,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,    74,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   607,    84,
    -288,  -288,     0,     0,     0,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,  -363,  -363,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,    74,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   369,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   486,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,   724,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,   730,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   785,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,   848,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   862,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   865,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,   869,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   872,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   883,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,   895,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,    58,    59,   368,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,     0,    72,     0,     0,     0,    73,     4,     5,
       6,     7,     8,   124,    75,    76,    77,     9,     0,    78,
      79,    80,     0,     0,    81,     0,    82,    83,     0,    84,
       0,   562,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   565,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   771,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   811,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,    29,    30,   122,    32,
      33,     0,     0,     0,     0,     0,    35,    36,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,    47,   262,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     4,
       5,     6,     7,     8,     0,     0,     0,    73,     9,     0,
       0,     0,     0,   124,    75,    76,    77,     0,     0,     0,
      79,   125,     0,     0,    81,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    29,    30,   122,
      32,    33,     0,     0,     0,     0,     0,    35,    36,     0,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,    47,   262,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       4,     5,     6,     7,     8,     0,     0,     0,    73,     9,
       0,     0,     0,     0,   124,    75,    76,    77,     0,     0,
       0,    79,   125,     0,     0,    81,     0,   183,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,    29,    30,
     122,    32,    33,     0,     0,     0,     0,     0,    35,    36,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,    47,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    73,
       9,     0,     0,     0,     0,   124,    75,    76,    77,     0,
       0,     0,    79,   125,     0,     0,    81,     0,   185,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,    29,
      30,   122,    32,    33,     0,     0,     0,     0,     0,    35,
      36,  -380,  -380,  -380,  -380,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,    47,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      73,     9,     0,     0,     0,     0,   124,    75,    76,    77,
       0,     0,     0,    79,   125,     0,     0,    81,     0,   189,
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
      77,     0,     0,     0,    79,   125,     0,     0,    81,   309,
       0,   376,     0,    84,     0,     0,     0,     0,     0,     0,
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
      76,    77,     0,     0,     0,    79,   125,   396,     0,    81,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
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
      81,     0,     0,   420,     0,    84,     0,     0,     0,     0,
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
       0,    81,     0,     0,   451,     0,    84,     0,     0,     0,
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
       0,     0,    81,     0,     0,   453,     0,    84,     0,     0,
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
     125,     0,     0,    81,     0,     0,   610,     0,    84,     0,
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
      79,   125,     0,     0,    81,     0,     0,   640,     0,    84,
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
      84,     0,     0,     0,     0,     0,     0,     0,     0,    10,
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
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,     0,   124,    75,    76,    77,
     237,   238,   239,    79,    80,     0,     0,    81,     0,     0,
       0,     0,    84,     0,     0,     0,   240,     0,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,     0,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   597,   240,   779,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   633,   240,     0,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   716,   240,     0,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   780,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   263,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   326,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   327,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   333,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,     0,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   366,   240,     0,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     447,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   460,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,     0,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   461,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   465,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   473,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,     0,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   646,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   846,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,   867,
       0,     0,     0,     0,     0,   240,   297,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     474,   475,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   476,   262,     0,   237,   238,   239,   364,     0,    29,
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
       0,   262
};

static const yytype_int16 yycheck[] =
{
       2,   126,    25,   494,    25,   307,   466,   700,   236,    14,
      15,   262,   235,    25,   376,     2,   695,   215,     2,     8,
      25,    63,     2,     8,   329,     8,     8,     8,    26,   382,
       8,   384,     8,     8,     8,   526,    63,     8,   343,     8,
       8,     8,     8,    63,    73,     8,     8,    52,   193,   742,
     623,   279,    54,   281,    38,    63,    73,   280,    75,   282,
      63,    93,    73,   286,   287,   293,   294,    31,    75,    74,
      26,    31,    77,    31,    31,   303,   278,    49,   306,   307,
     205,    75,    31,    73,     0,    75,    96,    97,   145,   451,
      81,   453,   115,   151,   151,    96,    97,   159,    75,   145,
     145,   159,   304,   145,   151,   151,   151,   101,    80,   159,
     145,    75,   159,   159,   159,    75,   151,    75,    75,   151,
     162,   123,   151,    75,    73,   145,    75,    26,   701,    73,
      63,    75,    64,   162,   139,   162,    75,   159,    73,   159,
      75,    73,   162,    75,    73,   168,    75,   164,   159,   140,
     155,   159,    73,   163,   162,   160,    73,   164,    73,   162,
     109,   363,   163,   161,   362,   470,   159,    73,   521,   474,
     475,   159,   161,   162,   164,   160,   855,   109,   161,   161,
     161,   158,    93,   161,   757,   161,   161,   161,   648,   160,
     195,   160,   160,   160,   160,   200,   889,   160,   160,   148,
     158,   158,   151,   208,   209,   210,   162,   212,   180,   214,
     159,   516,   164,   236,   105,   164,   148,   159,   162,   151,
     164,   127,   224,   580,   236,   164,    73,   159,    75,   164,
     151,   148,   164,   148,   151,   164,   151,   159,   145,   262,
     151,   262,   148,    73,   151,   151,   159,   153,   610,   329,
     262,   151,   159,    73,   160,   227,   279,   262,   281,   159,
      51,    52,   109,   343,    73,   618,   157,   279,   162,   281,
     293,   294,   160,   161,    73,    73,    75,    75,   640,   126,
     303,   293,   294,   306,   307,   290,   145,   160,   161,   540,
     159,   303,   151,   598,   306,   307,   301,   127,   655,   120,
     657,   148,   159,   505,   151,   120,   278,    68,    69,   151,
     109,   109,   159,   666,    14,    15,   159,   164,   148,   161,
     162,   151,   159,   153,   329,    25,    68,    69,   551,   682,
     332,   336,   304,   535,   536,    45,    46,    47,   343,    49,
     642,   543,   544,   161,   162,   547,    14,    15,   653,   148,
     148,   159,   151,   151,   659,   159,   661,    73,   360,   162,
     159,   159,    73,   162,    73,   164,   164,   161,    31,   392,
      63,   376,   145,   360,   159,   145,   360,   382,   124,   384,
     360,    63,   387,    95,    96,    97,    63,    63,   879,   151,
     470,   363,   364,   101,   474,   475,   476,   102,    49,   704,
     151,   145,   107,    64,   109,   110,   111,   112,   113,   114,
     115,   713,   635,   636,   642,   420,   101,   562,   145,     8,
     565,    95,    96,    97,   109,   110,   111,   112,   113,   114,
     165,   576,   151,   151,   159,   788,   516,   790,    42,    43,
      44,    45,    46,    47,   145,    49,   451,   145,   453,   124,
      85,    73,    13,    13,   759,   155,    73,   161,   163,    73,
      73,    75,   161,   468,   469,   470,   160,   122,   160,   474,
     475,   476,   825,   160,   122,   480,   159,   461,   783,   165,
     159,   465,   787,   161,     8,   713,    93,   792,   472,   494,
     495,    13,   497,    73,    75,   109,   501,   502,   160,   804,
     200,   159,   161,   856,   160,   507,   159,   587,   208,   209,
     210,   516,   212,   518,   159,     8,   521,   540,   598,   540,
     507,   526,   667,   507,   160,    13,   123,   507,   540,   162,
     835,   159,   885,   505,   148,   540,   841,   151,   165,   159,
     159,   165,   160,   515,   159,   159,    73,   159,   159,   165,
     164,   160,   151,   159,   859,   109,   110,   111,   112,   113,
     114,   145,   262,   535,   536,   165,   571,   165,    73,    13,
     161,   543,   544,   653,    13,   547,   151,   160,   160,   659,
       8,   661,   587,   588,   162,     8,   160,    63,    63,   102,
     124,   161,   125,   598,   107,    13,   109,   110,   111,   112,
     113,   114,   115,   161,   161,   610,   125,     8,    73,   614,
     165,   159,   162,   618,   160,   160,   160,   622,   161,   642,
     107,    75,    13,   160,   704,   160,   771,   124,   160,   329,
     642,   160,   160,    73,   165,   640,   781,    75,   161,   160,
     160,    26,   644,   343,   649,   647,   160,   159,   653,    13,
     163,   159,   654,   798,   659,   165,   661,   802,   165,   161,
     160,   666,   161,   808,   125,   161,   811,    75,    13,    13,
     795,   816,   162,    73,    13,   820,   376,   682,   162,   759,
     159,    70,   160,    26,   161,    75,    13,    75,   162,    13,
     713,   161,   694,   162,    93,   163,    93,   161,   161,   704,
     152,   713,   145,   783,    13,   850,    73,   787,   161,   159,
      73,    26,   792,    75,   161,    73,    73,     8,   160,   593,
     420,   593,   572,   495,   804,   521,   336,   778,   728,   649,
     622,   617,   825,   341,   753,    81,   881,   721,   672,   741,
     630,   587,   586,   727,   728,   200,   501,   892,   753,   763,
     502,   451,    -1,   453,   759,   835,   213,    -1,    -1,    -1,
      -1,   841,    -1,    -1,    -1,    -1,    -1,    -1,   468,   469,
     470,    -1,    -1,    -1,   474,   475,   476,    -1,   783,   859,
      -1,    -1,   787,   788,    -1,   790,   770,   792,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   495,    -1,   497,    -1,   804,
      -1,   501,   502,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   814,    -1,    -1,   817,   516,    -1,    -1,    -1,
     825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     835,    -1,    -1,    -1,   836,    -1,   841,    -1,   840,    -1,
     540,    -1,   844,    -1,    -1,   847,    -1,   849,    -1,   851,
      -1,   856,    -1,    -1,   859,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   846,    -1,    -1,    -1,    -1,    -1,    -1,   871,
      -1,   571,    -1,    -1,   879,    -1,    -1,    -1,    -1,    -1,
     885,    -1,    -1,    -1,    -1,   887,    -1,   587,    -1,    -1,
      -1,    -1,   894,    -1,    -1,    -1,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
     610,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
     640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   649,
      -1,    51,    52,   653,    -1,    -1,    -1,    -1,    -1,   659,
      -1,   661,    14,    15,    -1,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    37,    -1,    -1,   704,    -1,    -1,    -1,    44,    45,
      -1,     8,    -1,    49,    -1,    51,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    80,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,   759,
     160,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,    51,
      52,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   783,    -1,    -1,    -1,   787,    -1,    -1,
      -1,    -1,   792,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   804,    -1,    -1,    -1,    -1,    51,
      52,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,    -1,   212,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,   170,   835,   172,    -1,   174,    -1,
      -1,   841,   178,   179,   180,    -1,   182,    -1,   200,    -1,
      -1,    93,    -1,    -1,    -1,    -1,   208,   209,   210,   859,
     212,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    -1,   227,    -1,   213,   160,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   278,    -1,    -1,    -1,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,    -1,   280,    -1,   282,   283,    -1,    -1,
     286,   287,   304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   297,    -1,   299,    -1,    -1,    -1,    -1,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   363,   364,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   376,    -1,    -1,   363,   364,    -1,
      25,   420,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
     396,    -1,   451,    -1,   453,    -1,    -1,    -1,   420,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
     469,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,   451,
      -1,   453,   438,    -1,    -1,    -1,   495,    -1,   497,    -1,
      -1,    -1,   501,   502,    -1,    -1,   468,   469,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,    -1,
     466,   467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   495,    -1,   497,    -1,    -1,    -1,   501,
     502,   540,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,   163,   505,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   515,
      -1,    -1,   571,   535,   536,    -1,    -1,    -1,    -1,    -1,
      -1,   543,   544,    -1,    -1,   547,    -1,    -1,    -1,   535,
     536,    -1,    -1,   539,    -1,    -1,    -1,   543,   544,    -1,
      -1,   547,     9,    10,    11,   551,   552,    -1,    -1,   571,
      -1,   610,    -1,   559,    -1,    -1,    -1,    -1,    25,   161,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   640,    49,    -1,    -1,    -1,    -1,    -1,   610,    -1,
     649,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,   640,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   649,    -1,   635,
     636,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   648,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      77,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      87,    -1,    89,    -1,    91,    -1,   163,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,    -1,    -1,   733,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,    -1,    -1,   154,   155,   156,
      -1,   767,   159,    -1,   161,   162,   163,   164,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,   807,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    51,    52,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
     160,   161,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    51,    52,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    92,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    90,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,   154,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    -1,    89,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,   104,
      -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,   142,     3,     4,
       5,     6,     7,   148,   149,   150,   151,    12,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,   162,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,   101,    49,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,
     155,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,   101,    49,    -1,
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
      82,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,    -1,    -1,   159,    -1,   161,
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
     151,    -1,    -1,    -1,   155,   156,    -1,    -1,   159,   160,
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
     150,   151,    -1,    -1,    -1,   155,   156,    26,    -1,   159,
      -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   159,    -1,    -1,    31,    -1,   164,    -1,    -1,
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
     156,    -1,    -1,   159,    -1,    -1,    31,    -1,   164,    -1,
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
     155,   156,    -1,    -1,   159,    -1,    -1,    31,    -1,   164,
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
      -1,   155,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
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
      -1,    -1,   155,   156,    -1,    -1,   159,    -1,    -1,    -1,
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
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
       9,    10,    11,   155,   156,    -1,    -1,   159,    -1,    -1,
      -1,    -1,   164,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   161,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   161,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   161,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   161,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   161,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     160,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   160,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   160,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   160,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   160,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    25,   125,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      42,    43,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    63,    49,    -1,     9,    10,    11,   125,    -1,    71,
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
      -1,    49
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
     175,   176,   184,   185,   266,    73,    31,   215,   216,   245,
     270,    73,   122,   190,   122,   192,    73,   159,   284,    73,
     276,   282,   288,   266,   266,   266,    26,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   253,
      31,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   215,    73,   276,   284,    73,   162,   276,
     285,   286,   287,   284,   266,   284,   284,   160,   169,    73,
      73,    31,   266,    31,   266,   169,   276,   215,   276,   285,
     160,   160,   165,   266,   159,   160,   161,     8,    93,    93,
      13,     8,   160,   160,    42,    43,    63,    81,   127,   148,
     151,   169,   251,   259,   260,   261,   163,    93,    73,   172,
     266,   218,   260,    75,   159,     8,   160,     8,   160,   160,
     161,   159,     8,   160,   160,   159,   163,   168,   215,   245,
     270,   159,   163,   268,   160,     8,    13,   148,   151,   169,
     252,   123,   193,   194,   252,   162,   159,   127,   153,   209,
     210,   212,   213,   252,   165,   159,   159,   282,   266,    26,
      64,   270,   160,   159,   159,   165,   266,   159,   273,   274,
     275,    63,   162,   165,   163,   165,   165,   268,   268,   125,
     160,   255,    26,   176,   266,    26,   176,   204,   243,   266,
     270,    31,   196,   270,   260,    73,    26,   176,   199,    26,
     162,   201,   260,   260,   260,   263,   265,   159,   151,   169,
     145,   105,   157,   178,   179,   181,    73,   163,    13,   209,
     183,   161,   270,   289,   290,    13,   215,   163,   160,   160,
      31,   245,   270,   260,   151,   169,   194,   162,     8,   220,
     209,   160,     8,    31,    75,   158,   211,   215,   215,   266,
     253,   215,   215,   163,   215,    63,    63,   271,   284,   266,
      31,   266,   124,   256,   174,   205,   160,   174,   161,   125,
     195,   270,   195,    13,   174,   161,   202,   161,   202,   125,
     165,     8,   264,   263,   169,    73,   159,   162,   179,   180,
     181,   260,   160,   160,   266,   160,   161,   268,   169,   220,
     252,   102,   107,   109,   110,   111,   112,   113,   114,   115,
     163,   221,   223,   236,   237,   238,   239,   241,   160,   107,
     248,   212,   211,    75,    13,   160,   160,   258,   160,   160,
     160,   284,   284,   124,   272,   165,   163,   268,   285,   206,
      68,    69,   207,   161,    86,   243,   196,   160,   160,   260,
      92,   202,    95,    96,    97,   202,   163,   260,   260,   160,
     252,   174,   248,   163,    73,   224,   252,    75,   240,   247,
     239,     8,   161,    26,   214,   159,   214,    31,   211,    13,
     260,   165,   165,   285,    68,    69,   208,   159,   176,   161,
     160,    26,   176,   198,   198,   161,    95,   161,   266,    26,
     161,   203,   163,   125,    75,   163,   214,    13,     8,   161,
     162,   225,    13,     8,   161,   222,    73,   213,   162,    31,
      75,   249,   162,   211,    13,   260,   275,   159,    26,    70,
     266,    26,   176,   197,   174,   161,   203,   174,   260,   160,
     162,   260,   252,    73,   226,   227,   228,   229,   231,   232,
     233,   252,   260,    75,   186,    13,   174,    75,     8,   160,
     174,    13,   260,   266,   174,   161,   160,   174,    90,   174,
     162,   174,   163,   228,   161,    93,   152,   161,   145,    13,
      73,   260,   163,    31,    75,   163,   260,   160,   176,    88,
     161,   174,   163,   234,   239,   230,   252,    73,   260,   159,
      75,    26,   161,   163,    73,     8,   209,   174,   252,   160,
     214,   161,   162,   235,   174,   163
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
     213,   214,   214,   215,   215,   216,   216,   216,   216,   216,
     216,   217,   217,   218,   218,   218,   219,   219,   219,   219,
     220,   220,   221,   221,   221,   222,   221,   223,   224,   224,
     225,   225,   226,   226,   227,   227,   228,   228,   229,   230,
     230,   231,   231,   232,   233,   233,   234,   234,   235,   235,
     236,   236,   237,   237,   238,   238,   239,   239,   239,   239,
     239,   239,   240,   240,   240,   240,   241,   241,   242,   242,
     243,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   246,   246,   246,   246,   247,
     248,   248,   249,   249,   249,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   251,   251,   251,   251,   252,   252,
     252,   253,   253,   254,   254,   255,   255,   256,   257,   257,
     257,   258,   258,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   261,   262,   262,   262,   262,   262,
     262,   263,   263,   264,   264,   265,   265,   265,   265,   266,
     266,   267,   268,   269,   270,   270,   271,   271,   272,   273,
     273,   274,   275,   275,   275,   276,   276,   277,   277,   278,
     279,   279,   280,   280,   280,   281,   281,   281,   281,   282,
     282,   282,   283,   283,   284,   284,   285,   285,   286,   286,
     286,   287,   287,   288,   288,   289,   289,   290,   290,   290,
     291,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     293,   293,   293,   293,   293,   293,   293,   294,   294,   295,
     295,   296,   296,   296,   297,   297,   298,   299,   299
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
       1,     0,     2,     1,     0,     1,     1,     2,     3,     3,
       4,     3,     1,     1,     2,     4,     3,     5,     1,     3,
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
       3,     3,     3,     1,     1,     5,     4,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     1,    10,    11,     2,     2,     4,     4,     1,
       0,     4,     3,     4,     1,     2,     4,     6,     5,     6,
       6,     6,     6,     4,     1,     1,     3,     2,     1,     3,
       2,     1,     1,     4,     1,     2,     0,     2,     0,     2,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     2,
       2,     4,     3,     1,     3,     1,     1,     1,     3,     2,
       1,     0,     2,     0,     1,     5,     3,     3,     1,     1,
       1,     1,     1,     1,     5,     1,     2,     0,     3,     4,
       4,     3,     1,     1,     0,     1,     2,     3,     3,     1,
       4,     4,     1,     1,     1,     1,     3,     2,     1,     4,
       4,     1,     1,     4,     0,     1,     1,     1,     4,     4,
       1,     1,     3,     1,     2,     3,     1,     1,     4,     0,
       0,     2,     5,     3,     3,     1,     6,     4,     4,     2,
       4,     4,     2,     2,     4,     2,     2,     1,     3,     3,
       3,     4,     4,     4,     4,     3,     3,     3,     3
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
#line 208 "parser.y" /* yacc.c:1661  */
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[0]));
  }
#line 3463 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 214 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3471 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 217 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3479 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 223 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_SYMBOL_NAME);
  }
#line 3487 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 226 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NMORE((yyvsp[-2]), (yyvsp[0]));
  }
#line 3495 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 235 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3505 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 240 "parser.y" /* yacc.c:1661  */
    {
    NSPAN((yyvsp[-2]), n_NAMESPACE, (yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3517 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 247 "parser.y" /* yacc.c:1661  */
    {
  NSPAN((yyvsp[-4]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-4])->appendChild((yyvsp[-3]));
  (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3528 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 253 "parser.y" /* yacc.c:1661  */
    {
  NSPAN((yyvsp[-3]), n_NAMESPACE, (yyvsp[0]));
  (yyvsp[-3])->appendChild(NNEW(n_EMPTY));
  NMORE((yyvsp[-1]), (yyvsp[0]));
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyvsp[-3])->appendChild((yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  }
#line 3541 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 261 "parser.y" /* yacc.c:1661  */
    {
  NMORE((yyvsp[-1]), (yyvsp[-2]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3551 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 266 "parser.y" /* yacc.c:1661  */
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3560 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 273 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 3568 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 276 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3577 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 283 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3587 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 288 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3598 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 294 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 3609 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 300 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_USE);
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    NTYPE((yyvsp[0]), n_STRING);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 3621 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 310 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyval), (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3633 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 317 "parser.y" /* yacc.c:1661  */
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[0]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[-2]), n_STRING))
        ->appendChild((yyvsp[0])));
  }
#line 3645 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 327 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 3653 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 330 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 3661 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 339 "parser.y" /* yacc.c:1661  */
    {
  (yyvsp[-3]) = NSPAN((yyvsp[-3]), n_HALT_COMPILER, (yyvsp[-1]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-3]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 3671 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 348 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3682 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 354 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3690 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 357 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_OPEN_TAG);
  }
#line 3698 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 360 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLOSE_TAG);
  }
#line 3706 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 366 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 3714 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 369 "parser.y" /* yacc.c:1661  */
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
#line 3749 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 403 "parser.y" /* yacc.c:1661  */
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
#line 3769 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 418 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-4]), n_WHILE);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3781 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 425 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-6]), n_DO_WHILE);
    (yyvsp[-6])->appendChild((yyvsp[-5]));
    (yyvsp[-6])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-6]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3794 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 433 "parser.y" /* yacc.c:1661  */
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
#line 3812 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 446 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-4]), n_SWITCH);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 3824 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 453 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_BREAK);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3836 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 460 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_BREAK);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3848 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 467 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_CONTINUE);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3860 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 474 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_CONTINUE);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3872 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 481 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_RETURN);
    (yyvsp[-1])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3884 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 488 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3896 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 495 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_RETURN);
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3908 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 502 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3918 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 507 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3928 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 512 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[-1]), (yyvsp[-2]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3938 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 517 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_INLINE_HTML);
    (yyval) = (yyvsp[0]);
  }
#line 3947 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 521 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3956 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 525 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3965 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 529 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[-2]), (yyvsp[-1]));
    NMORE((yyvsp[-2]), (yyvsp[-4]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 3976 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 536 "parser.y" /* yacc.c:1661  */
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
#line 3998 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 554 "parser.y" /* yacc.c:1661  */
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
#line 4019 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 570 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-4]), n_DECLARE);
    (yyvsp[-4])->appendChild((yyvsp[-2]));
    (yyvsp[-4])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4030 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 576 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4039 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 580 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-5]), n_TRY);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));

    (yyvsp[-5])->appendChild((yyvsp[-1]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-5]));
  }
#line 4053 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 589 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-4]), n_TRY);
    (yyvsp[-4])->appendChild(NEXPAND((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1])));

    (yyvsp[-4])->appendChild(NNEW(n_CATCH_LIST));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-4]));
  }
#line 4067 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 598 "parser.y" /* yacc.c:1661  */
    {
  NTYPE((yyvsp[-2]), n_THROW);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));

  }
#line 4080 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 606 "parser.y" /* yacc.c:1661  */
    {
  NTYPE((yyvsp[-2]), n_GOTO);
  NTYPE((yyvsp[-1]), n_STRING);
  (yyvsp[-2])->appendChild((yyvsp[-1]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-2]));
  NMORE((yyval), (yyvsp[0]));
  }
#line 4093 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 617 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4102 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 621 "parser.y" /* yacc.c:1661  */
    {
  (yyval) = NNEW(n_CATCH_LIST);
  (yyval)->appendChild((yyvsp[0]));
}
#line 4111 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 628 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-7]), n_CATCH);
    (yyvsp[-7])->appendChild((yyvsp[-5]));
    (yyvsp[-7])->appendChild(NTYPE((yyvsp[-4]), n_VARIABLE));
    (yyvsp[-7])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    NMORE((yyvsp[-7]), (yyvsp[0]));
    (yyval) = (yyvsp[-7]);
  }
#line 4124 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 639 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4132 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 646 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_FINALLY);
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    NMORE((yyvsp[-3]), (yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 4143 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 655 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4152 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 659 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4161 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 678 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4169 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 681 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_REFERENCE);
  }
#line 4177 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 688 "parser.y" /* yacc.c:1661  */
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
#line 4194 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 704 "parser.y" /* yacc.c:1661  */
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
#line 4210 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 715 "parser.y" /* yacc.c:1661  */
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
#line 4227 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 730 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[0]);
  }
#line 4236 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 734 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4248 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 741 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_CLASS_ATTRIBUTES);
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyvsp[0])->appendChild(NTYPE((yyvsp[-1]), n_STRING));

    (yyval) = (yyvsp[0]);
  }
#line 4260 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 748 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 4269 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 755 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4277 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 758 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_EXTENDS_LIST)->appendChild((yyvsp[0]));
  }
#line 4285 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 768 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4293 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 771 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_EXTENDS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4303 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 779 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4311 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 782 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_IMPLEMENTS_LIST);
    (yyvsp[-1])->appendChildren((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4321 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 790 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[0]));
  }
#line 4329 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 793 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4337 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 799 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4345 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 802 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4353 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 809 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4363 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 818 "parser.y" /* yacc.c:1661  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4373 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 827 "parser.y" /* yacc.c:1661  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4383 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 836 "parser.y" /* yacc.c:1661  */
    {
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  NMORE((yyvsp[-2]), (yyvsp[0]));
  (yyval) = (yyvsp[-2]);
  }
#line 4393 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 844 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4404 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 850 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));
    (yyval) = (yyvsp[-4]);
  }
#line 4417 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 861 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 4425 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 864 "parser.y" /* yacc.c:1661  */
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[-2]), n_STATEMENT);
    (yyvsp[-3])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));
    NEXPAND((yyvsp[-3]), (yyval), (yyvsp[0]));
  }
#line 4440 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 874 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[-2]), (yyvsp[0]));
    NMORE((yyvsp[-2]), (yyvsp[-3]));
    (yyval) = (yyvsp[-2]);
  }
#line 4450 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 879 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_STATEMENT);
    (yyvsp[-4])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[-3]));
    (yyval)->appendChildren((yyvsp[-2]));
    NMORE((yyval), (yyvsp[0]));
    NMORE((yyval), (yyvsp[-4]));
  }
#line 4464 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 891 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4472 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 894 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_CASE);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyvsp[-3]));
    (yyval) = (yyvsp[-4]);
  }
#line 4485 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 902 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_DEFAULT);
    (yyvsp[-2])->appendChild((yyvsp[0]));

    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval) = (yyvsp[-3]);
  }
#line 4497 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 918 "parser.y" /* yacc.c:1661  */
    {
  NMORE((yyvsp[-2]), (yyvsp[0]));
  NMORE((yyvsp[-2]), (yyvsp[-3]));
  (yyval) = (yyvsp[-2]);
  }
#line 4507 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 926 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4515 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 929 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-4]), n_ELSEIF);
    (yyvsp[-4])->appendChild(NSPAN((yyvsp[-3]), n_CONTROL_CONDITION, (yyvsp[-1]))->appendChild((yyvsp[-2])));
    (yyvsp[-4])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyvsp[-4]));
  }
#line 4527 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 939 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
#line 4535 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 942 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-5]), n_ELSEIF);
    (yyvsp[-5])->appendChild((yyvsp[-3]));
    (yyvsp[-5])->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyvsp[-5]));
  }
#line 4547 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 952 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4555 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 955 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_ELSE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 4565 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 963 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4573 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 966 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_ELSE);
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4583 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 975 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
#line 4591 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 981 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4604 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 989 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4618 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 998 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4632 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 1007 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
#line 4645 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 1015 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 4658 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 1023 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE));
      (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4672 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 1033 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_VARIABLE_REFERENCE));
      (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-6])->appendChild((yyval));
  }
#line 4686 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 1043 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 4699 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 1054 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_UNPACK);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 4708 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 1058 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4716 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 1064 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4724 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 1071 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4732 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 1074 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4740 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 1077 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_TYPE_NAME);
  }
#line 4748 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 1083 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 4756 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 1086 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4764 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 1093 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
#line 4772 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 1099 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4780 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 1102 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[0]));
  }
#line 4788 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 1105 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[-1]));
  }
#line 4798 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 1110 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4806 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 1113 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 4814 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 1116 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 4824 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 1124 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 4833 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 1128 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4842 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 1135 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 4850 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 1138 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 4859 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 1142 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-3]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 4868 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 1149 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 4881 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 1157 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 4894 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 1165 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4907 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 1173 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
#line 4920 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 1184 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 4928 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 1187 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
#line 4936 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 1193 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4949 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 1201 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 4958 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 1205 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 4966 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 1208 "parser.y" /* yacc.c:1661  */
    {
    /* empty */
  }
#line 4974 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 1210 "parser.y" /* yacc.c:1661  */
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
#line 4992 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 1226 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-2]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[-1]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5002 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 1234 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[0]));
  }
#line 5010 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 1237 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5018 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 1243 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5026 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 1246 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5034 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 1252 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
#line 5042 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 1255 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5050 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 1261 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5059 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 1265 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 5068 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 1272 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5076 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 1275 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 5084 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 1281 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5094 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 1289 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5103 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 1293 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 5112 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 1300 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5121 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 1304 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 5129 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 1310 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[-2]), (yyvsp[-1]), NTYPE((yyvsp[0]), n_STRING));
    (yyval) = (yyvsp[-1]);
  }
#line 5139 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 1318 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5150 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 1324 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
#line 5161 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 1333 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5169 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 1336 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5178 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 1344 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5186 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 1347 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 5194 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 1354 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5203 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 192:
#line 1361 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
#line 5211 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 193:
#line 1364 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[0]);
  }
#line 5220 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 194:
#line 1371 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5229 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 195:
#line 1375 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 5237 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 202:
#line 1390 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 5249 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 203:
#line 1397 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 5261 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 204:
#line 1404 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5273 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 205:
#line 1411 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
#line 5285 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 206:
#line 1421 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));

    (yyvsp[-4])->appendChild((yyval));

    (yyval) = (yyvsp[-4]);
  }
#line 5299 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 207:
#line 1430 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_STRING));
    (yyval)->appendChild((yyvsp[0]));
    (yyvsp[-3])->appendChild((yyval));

    (yyval) = (yyvsp[-3]);
  }
#line 5313 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 208:
#line 1442 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5321 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 209:
#line 1445 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5330 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 210:
#line 1452 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 5338 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 212:
#line 1460 "parser.y" /* yacc.c:1661  */
    {
    (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 5346 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 213:
#line 1463 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5355 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 214:
#line 1470 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-5]), n_LIST);
    (yyvsp[-5])->appendChild(NEXPAND((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5368 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 215:
#line 1478 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5379 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 216:
#line 1484 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));

    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild((yyvsp[0]));

    (yyval)->appendChild((yyvsp[-1]));
  }
#line 5394 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 217:
#line 1494 "parser.y" /* yacc.c:1661  */
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
#line 5413 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 218:
#line 1508 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5423 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 219:
#line 1513 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5434 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 220:
#line 1519 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5445 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 221:
#line 1525 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5456 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 222:
#line 1531 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5467 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 223:
#line 1537 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5478 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 224:
#line 1543 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5489 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 225:
#line 1549 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5500 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 226:
#line 1555 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5511 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 227:
#line 1561 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5522 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 228:
#line 1567 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5533 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 229:
#line 1573 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5544 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 230:
#line 1579 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5554 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 231:
#line 1584 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5564 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 232:
#line 1589 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[-1]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_OPERATOR));
  }
#line 5574 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 233:
#line 1594 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5584 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 234:
#line 1599 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5595 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 235:
#line 1605 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5606 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 236:
#line 1611 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5617 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 237:
#line 1617 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5628 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 238:
#line 1623 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5639 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 239:
#line 1629 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5650 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 240:
#line 1635 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5661 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 241:
#line 1641 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5672 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 242:
#line 1647 "parser.y" /* yacc.c:1661  */
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
#line 5703 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 243:
#line 1673 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5714 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 244:
#line 1679 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5725 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 245:
#line 1685 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5736 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 246:
#line 1691 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5747 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 247:
#line 1697 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5758 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 248:
#line 1703 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5769 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 249:
#line 1709 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5780 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 250:
#line 1715 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5790 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 251:
#line 1720 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5800 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 252:
#line 1725 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5810 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 253:
#line 1730 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5820 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 254:
#line 1735 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5831 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 255:
#line 1741 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5842 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 256:
#line 1747 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5853 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 257:
#line 1753 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5864 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 258:
#line 1759 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5875 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 259:
#line 1765 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5886 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 260:
#line 1771 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5897 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 261:
#line 1777 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5908 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 262:
#line 1783 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5919 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 265:
#line 1791 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-4]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5932 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 266:
#line 1799 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-2]), n_OPERATOR));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5945 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 268:
#line 1808 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5955 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 269:
#line 1813 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5965 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 270:
#line 1818 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5975 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 271:
#line 1823 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5985 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 272:
#line 1828 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 5995 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 273:
#line 1833 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6005 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 274:
#line 1838 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_CAST));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6015 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 275:
#line 1843 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6025 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 276:
#line 1848 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6035 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 277:
#line 1853 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[0]);
  }
#line 6044 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 281:
#line 1860 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6054 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 282:
#line 1865 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[0]);
  }
#line 6065 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 283:
#line 1874 "parser.y" /* yacc.c:1661  */
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
#line 6082 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 284:
#line 1889 "parser.y" /* yacc.c:1661  */
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
#line 6105 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 285:
#line 1910 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6116 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 286:
#line 1916 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_YIELD);
    (yyvsp[0])->appendChild(NNEW(n_EMPTY));
    (yyvsp[-1])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6127 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 287:
#line 1922 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6138 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 288:
#line 1928 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_YIELD);
    (yyvsp[-3])->appendChild((yyvsp[-2]));
    (yyvsp[-3])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-3]);
  }
#line 6149 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 290:
#line 1941 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6157 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 291:
#line 1944 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[-3])->appendChildren((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6167 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 292:
#line 1952 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6175 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 293:
#line 1955 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = (yyvsp[-3])->appendChild((yyvsp[-1]));
  }
#line 6185 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 294:
#line 1960 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
  }
#line 6194 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 295:
#line 1964 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE);
    (yyvsp[-1])->appendChild(NTYPE((yyvsp[0]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[-1]));
  }
#line 6205 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 296:
#line 1973 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6215 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 297:
#line 1979 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-5]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6226 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 298:
#line 1985 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[-3]), (yyvsp[-4]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6237 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 299:
#line 1992 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6250 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 300:
#line 2001 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6263 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 301:
#line 2010 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6276 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 302:
#line 2019 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-5]));
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6289 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 303:
#line 2027 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 6299 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 304:
#line 2035 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6307 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 305:
#line 2038 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6315 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 306:
#line 2041 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6324 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 307:
#line 2045 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6333 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 308:
#line 2052 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6341 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 309:
#line 2055 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6350 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 310:
#line 2059 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = NTYPE((yyvsp[0]), n_CLASS_NAME);
  }
#line 6359 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 313:
#line 2074 "parser.y" /* yacc.c:1661  */
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
#line 6376 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 315:
#line 2090 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-1])->appendChild((yyvsp[0]));
  }
#line 6384 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 316:
#line 2093 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6392 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 317:
#line 2099 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6400 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 318:
#line 2105 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6408 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 319:
#line 2108 "parser.y" /* yacc.c:1661  */
    {
    NSPAN((yyvsp[-1]), n_EMPTY, (yyvsp[0]));
    (yyval) = (yyvsp[-1]);
  }
#line 6417 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 320:
#line 2112 "parser.y" /* yacc.c:1661  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 6427 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 321:
#line 2120 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6435 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 322:
#line 2123 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6443 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 323:
#line 2129 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6451 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 324:
#line 2132 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_NUMERIC_SCALAR);
  }
#line 6459 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 325:
#line 2135 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_STRING_SCALAR);
  }
#line 6467 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 326:
#line 2138 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6475 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 327:
#line 2141 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6483 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 328:
#line 2144 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6491 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 329:
#line 2147 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6499 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 330:
#line 2150 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6507 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 331:
#line 2153 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6515 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 332:
#line 2156 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6523 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 333:
#line 2159 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_MAGIC_SCALAR);
  }
#line 6531 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 334:
#line 2162 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_HEREDOC);
  }
#line 6539 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 337:
#line 2170 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[0]), (yyvsp[-2]));
    (yyval) = (yyvsp[0]);
  }
#line 6548 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 338:
#line 2174 "parser.y" /* yacc.c:1661  */
    {
    NMORE((yyvsp[0]), (yyvsp[-1]));
    (yyval) = (yyvsp[0]);
  }
#line 6557 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 339:
#line 2178 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6567 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 340:
#line 2183 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6577 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 341:
#line 2188 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 6587 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 342:
#line 2193 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 6597 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 344:
#line 2202 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 6607 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 348:
#line 2213 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-2]));
  }
#line 6615 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 349:
#line 2216 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NMORE((yyvsp[0]), (yyvsp[-1]));
  }
#line 6623 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 351:
#line 2223 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 6631 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 352:
#line 2226 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 6639 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 353:
#line 2232 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6647 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 355:
#line 2243 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 6659 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 356:
#line 2250 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 6671 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 357:
#line 2257 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6683 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 358:
#line 2264 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 6695 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 364:
#line 2294 "parser.y" /* yacc.c:1661  */
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
#line 6723 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 366:
#line 2321 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-1])->appendChildren((yyvsp[0]));
  }
#line 6731 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 367:
#line 2324 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6739 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 368:
#line 2330 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[-1]));
    if ((yyvsp[0])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[0]));
    }
  }
#line 6751 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 369:
#line 2340 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6762 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 370:
#line 2346 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6773 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 371:
#line 2355 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6781 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 374:
#line 2363 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6789 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 376:
#line 2370 "parser.y" /* yacc.c:1661  */
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
#line 6806 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 377:
#line 2385 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6816 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 378:
#line 2390 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));
  }
#line 6826 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 380:
#line 2402 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6837 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 381:
#line 2408 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6848 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 386:
#line 2424 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6856 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 387:
#line 2427 "parser.y" /* yacc.c:1661  */
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
#line 6873 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 389:
#line 2443 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6884 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 390:
#line 2449 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6895 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 392:
#line 2459 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_VARIABLE);
  }
#line 6903 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 393:
#line 2462 "parser.y" /* yacc.c:1661  */
    {
    NSPAN((yyvsp[-3]), n_VARIABLE_EXPRESSION, (yyvsp[0]));
    (yyvsp[-3])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-3]);
  }
#line 6913 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 394:
#line 2470 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 6921 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 395:
#line 2473 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 6929 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 398:
#line 2484 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6940 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 399:
#line 2490 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 6951 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 401:
#line 2500 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[0]), n_STRING);
    (yyval) = (yyvsp[0]);
  }
#line 6960 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 402:
#line 2504 "parser.y" /* yacc.c:1661  */
    {
  (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 6968 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 403:
#line 2510 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[0]), n_VARIABLE_VARIABLE);
  }
#line 6976 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 404:
#line 2513 "parser.y" /* yacc.c:1661  */
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
#line 6993 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 405:
#line 2528 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7001 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 406:
#line 2531 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7010 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 408:
#line 2539 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
  }
#line 7019 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 409:
#line 2543 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
  }
#line 7027 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 410:
#line 2549 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
#line 7035 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 411:
#line 2552 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NMORE((yyvsp[-1]), (yyvsp[0]));
  }
#line 7043 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 412:
#line 2558 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-4])->appendChild((yyval));
  }
#line 7055 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 413:
#line 2565 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = (yyvsp[-2])->appendChild((yyval));
  }
#line 7067 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 414:
#line 2572 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7079 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 415:
#line 2579 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[0]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7091 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 416:
#line 2586 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-5])->appendChild((yyval));
  }
#line 7103 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 417:
#line 2593 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = (yyvsp[-3])->appendChild((yyval));
  }
#line 7115 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 418:
#line 2600 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7127 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 419:
#line 2607 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[-1]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[0])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
#line 7139 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 420:
#line 2617 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChildren((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7154 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 421:
#line 2627 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7169 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 422:
#line 2637 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7177 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 423:
#line 2640 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7185 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 424:
#line 2643 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_SYMBOL_NAME);

    NSPAN((yyvsp[-2]), n_CALL_PARAMETER_LIST, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-2]));
  }
#line 7200 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 425:
#line 2653 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7208 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 426:
#line 2656 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NTYPE((yyvsp[-1]), n_INCLUDE_FILE)->appendChild((yyvsp[0]));
  }
#line 7216 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 427:
#line 2662 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[0]));
  }
#line 7225 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 428:
#line 2666 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = (yyvsp[-2])->appendChild((yyvsp[0]));
  }
#line 7233 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 429:
#line 2672 "parser.y" /* yacc.c:1661  */
    {
    NSPAN((yyvsp[-2]), n_PARENTHETICAL_EXPRESSION, (yyvsp[0]));
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
  }
#line 7243 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 430:
#line 2677 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));
  }
#line 7251 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 431:
#line 2683 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7262 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 432:
#line 2689 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[-3]));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7273 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 433:
#line 2695 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[-3]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[-1]));
    NMORE((yyval), (yyvsp[0]));
  }
#line 7284 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 434:
#line 2704 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-3]), n_ARRAY_LITERAL);
    (yyvsp[-3])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-3]);
  }
#line 7294 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 435:
#line 2709 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_ARRAY_LITERAL);
    (yyvsp[-2])->appendChild(NEXPAND((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));
    (yyval) = (yyvsp[-2]);
  }
#line 7304 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 436:
#line 2717 "parser.y" /* yacc.c:1661  */
    {
    NTYPE((yyvsp[-2]), n_NEW);
    (yyvsp[-2])->appendChild((yyvsp[-1]));
    (yyvsp[-2])->appendChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
  }
#line 7315 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 437:
#line 2726 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7325 "parser.yacc.cpp" /* yacc.c:1661  */
    break;

  case 438:
#line 2731 "parser.y" /* yacc.c:1661  */
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[-2]));
    (yyval)->appendChild(NTYPE((yyvsp[0]), n_STRING));
  }
#line 7335 "parser.yacc.cpp" /* yacc.c:1661  */
    break;


#line 7339 "parser.yacc.cpp" /* yacc.c:1661  */
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
#line 2738 "parser.y" /* yacc.c:1906  */


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
/* @generated */
