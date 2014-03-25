/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

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
#define yylval          xhpastlval
#define yychar          xhpastchar
#define yydebug         xhpastdebug
#define yynerrs         xhpastnerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

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
/* Line 371 of yacc.c  */
#line 21 "parser.y"

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
  ((n)->setEnd(end))

#define NSPAN(n, type, end) \
  (NMORE(NTYPE((n), type), end))

#define NLMORE(n, begin) \
  ((n)->setBegin(begin))

#define NEXPAND(l, n, r) \
  ((n)->setBegin(l)->setEnd(r))

using namespace std;

static void yyerror(void* yyscanner, void* _, const char* error) {
  if (yyextra->terminated) {
    return;
  }
  yyextra->terminated = true;
  yyextra->error = error;
}

/*

TODO: Restore this.

static void replacestr(string &source, const string &find, const string &rep) {
  size_t j;
  while ((j = source.find(find)) != std::string::npos) {
    source.replace(j, find.length(), rep);
  }
}
*/


/* Line 371 of yacc.c  */
#line 146 "parser.yacc.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int xhpastdebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_REQUIRE_ONCE = 258,
     T_REQUIRE = 259,
     T_EVAL = 260,
     T_INCLUDE_ONCE = 261,
     T_INCLUDE = 262,
     T_LOGICAL_OR = 263,
     T_LOGICAL_XOR = 264,
     T_LOGICAL_AND = 265,
     T_PRINT = 266,
     T_SR_EQUAL = 267,
     T_SL_EQUAL = 268,
     T_XOR_EQUAL = 269,
     T_OR_EQUAL = 270,
     T_AND_EQUAL = 271,
     T_MOD_EQUAL = 272,
     T_CONCAT_EQUAL = 273,
     T_DIV_EQUAL = 274,
     T_MUL_EQUAL = 275,
     T_MINUS_EQUAL = 276,
     T_PLUS_EQUAL = 277,
     T_BOOLEAN_OR = 278,
     T_BOOLEAN_AND = 279,
     T_IS_NOT_IDENTICAL = 280,
     T_IS_IDENTICAL = 281,
     T_IS_NOT_EQUAL = 282,
     T_IS_EQUAL = 283,
     T_IS_GREATER_OR_EQUAL = 284,
     T_IS_SMALLER_OR_EQUAL = 285,
     T_SR = 286,
     T_SL = 287,
     T_INSTANCEOF = 288,
     T_UNSET_CAST = 289,
     T_BOOL_CAST = 290,
     T_OBJECT_CAST = 291,
     T_ARRAY_CAST = 292,
     T_BINARY_CAST = 293,
     T_UNICODE_CAST = 294,
     T_STRING_CAST = 295,
     T_DOUBLE_CAST = 296,
     T_INT_CAST = 297,
     T_DEC = 298,
     T_INC = 299,
     T_CLONE = 300,
     T_NEW = 301,
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
     T_PUBLIC = 345,
     T_PROTECTED = 346,
     T_PRIVATE = 347,
     T_FINAL = 348,
     T_ABSTRACT = 349,
     T_STATIC = 350,
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


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int xhpastparse (void *YYPARSE_PARAM);
#else
int xhpastparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int xhpastparse (void* yyscanner, xhpast::Node** root);
#else
int xhpastparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_XHPAST_PARSER_YACC_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 349 "parser.yacc.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7825

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  433
/* YYNRULES -- Number of states.  */
#define YYNSTATES  893

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   393

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,   163,    47,    31,     2,
     158,   159,    45,    42,     8,    43,    44,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   160,
      36,    13,    37,    25,    51,     2,     2,     2,     2,     2,
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
      32,    33,    34,    35,    38,    39,    40,    41,    49,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    15,    17,    19,
      21,    26,    30,    36,    41,    45,    48,    52,    54,    56,
      60,    63,    68,    74,    79,    82,    83,    85,    87,    89,
      94,    96,    99,   101,   103,   105,   109,   117,   128,   134,
     142,   152,   158,   161,   165,   168,   172,   175,   179,   183,
     187,   191,   195,   197,   200,   203,   209,   218,   227,   233,
     235,   250,   254,   258,   260,   261,   262,   267,   269,   272,
     281,   283,   287,   289,   291,   293,   294,   296,   306,   314,
     321,   323,   326,   329,   331,   332,   335,   337,   338,   341,
     342,   345,   347,   351,   352,   355,   357,   360,   362,   367,
     369,   374,   376,   381,   385,   391,   395,   400,   405,   411,
     412,   418,   423,   425,   427,   429,   434,   435,   442,   443,
     451,   452,   455,   456,   460,   462,   463,   466,   470,   476,
     481,   486,   492,   500,   507,   508,   510,   512,   514,   516,
     517,   519,   521,   524,   528,   532,   537,   541,   543,   545,
     548,   553,   557,   563,   565,   569,   572,   573,   577,   580,
     582,   583,   593,   597,   599,   603,   605,   609,   610,   612,
     614,   617,   620,   623,   627,   629,   633,   635,   637,   641,
     646,   650,   651,   653,   655,   659,   661,   663,   664,   666,
     668,   671,   673,   675,   677,   679,   681,   683,   687,   693,
     695,   699,   705,   710,   714,   716,   717,   719,   723,   725,
     732,   736,   741,   748,   751,   755,   759,   763,   767,   771,
     775,   779,   783,   787,   791,   795,   798,   801,   804,   807,
     811,   815,   819,   823,   827,   831,   835,   839,   843,   847,
     851,   855,   859,   863,   867,   871,   874,   877,   880,   883,
     887,   891,   895,   899,   903,   907,   911,   915,   919,   921,
     923,   929,   934,   936,   939,   942,   945,   948,   951,   954,
     957,   960,   963,   965,   967,   969,   971,   974,   976,   986,
     997,  1000,  1003,  1008,  1013,  1015,  1016,  1021,  1025,  1030,
    1032,  1035,  1040,  1047,  1053,  1060,  1067,  1074,  1081,  1086,
    1088,  1090,  1094,  1097,  1099,  1103,  1106,  1108,  1110,  1115,
    1117,  1120,  1121,  1124,  1125,  1128,  1132,  1133,  1137,  1139,
    1141,  1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,  1159,
    1161,  1163,  1165,  1169,  1172,  1175,  1178,  1183,  1187,  1189,
    1193,  1195,  1197,  1199,  1203,  1206,  1208,  1209,  1212,  1213,
    1215,  1221,  1225,  1229,  1231,  1233,  1235,  1237,  1239,  1241,
    1247,  1249,  1252,  1253,  1257,  1262,  1267,  1271,  1273,  1275,
    1276,  1278,  1281,  1285,  1289,  1291,  1296,  1301,  1303,  1305,
    1307,  1309,  1313,  1316,  1318,  1323,  1328,  1330,  1332,  1337,
    1338,  1340,  1342,  1344,  1349,  1354,  1356,  1358,  1362,  1364,
    1367,  1371,  1373,  1375,  1380,  1381,  1382,  1385,  1391,  1395,
    1399,  1401,  1408,  1413,  1418,  1421,  1426,  1431,  1434,  1437,
    1442,  1445,  1448,  1450,  1454,  1458,  1462,  1467,  1472,  1477,
    1482,  1486,  1490,  1494
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,   167,    -1,   167,   169,    -1,    -1,    73,
      -1,   168,   151,    73,    -1,   175,    -1,   183,    -1,   184,
      -1,   119,   158,   159,   160,    -1,   148,   168,   160,    -1,
     148,   168,   161,   167,   162,    -1,   148,   161,   167,   162,
      -1,   107,   170,   160,    -1,   172,   160,    -1,   170,     8,
     171,    -1,   171,    -1,   168,    -1,   168,    93,    73,    -1,
     151,   168,    -1,   151,   168,    93,    73,    -1,   172,     8,
      73,    13,   256,    -1,   102,    73,    13,   256,    -1,   173,
     174,    -1,    -1,   175,    -1,   183,    -1,   184,    -1,   119,
     158,   159,   160,    -1,   176,    -1,    73,    26,    -1,   135,
      -1,   136,    -1,   138,    -1,   161,   173,   162,    -1,    67,
     158,   262,   159,   175,   204,   206,    -1,    67,   158,   262,
     159,    26,   173,   205,   207,    70,   160,    -1,    85,   158,
     262,   159,   203,    -1,    84,   175,    85,   158,   262,   159,
     160,    -1,    87,   158,   239,   160,   239,   160,   239,   159,
     196,    -1,    94,   158,   262,   159,   200,    -1,    98,   160,
      -1,    98,   262,   160,    -1,    99,   160,    -1,    99,   262,
     160,    -1,   103,   160,    -1,   103,   241,   160,    -1,   103,
     266,   160,    -1,   108,   213,   160,    -1,   114,   215,   160,
      -1,    83,   238,   160,    -1,    77,    -1,   262,   160,    -1,
     242,   160,    -1,   116,   158,   181,   159,   160,    -1,    89,
     158,   266,    93,   195,   194,   159,   197,    -1,    89,   158,
     241,    93,   266,   194,   159,   197,    -1,    91,   158,   199,
     159,   198,    -1,   160,    -1,   104,   161,   173,   162,   105,
     158,   248,    75,   159,   161,   173,   162,   177,   178,    -1,
     106,   262,   160,    -1,   100,    73,   160,    -1,   179,    -1,
      -1,    -1,   157,   161,   173,   162,    -1,   180,    -1,   179,
     180,    -1,   105,   158,   248,    75,   159,   161,   173,   162,
      -1,   182,    -1,   181,     8,   182,    -1,   266,    -1,   186,
      -1,   187,    -1,    -1,    31,    -1,   243,   185,    73,   158,
     208,   159,   161,   173,   162,    -1,   188,    73,   189,   192,
     161,   216,   162,    -1,   190,    73,   191,   161,   216,   162,
      -1,   120,    -1,   113,   120,    -1,   112,   120,    -1,   154,
      -1,    -1,   122,   248,    -1,   121,    -1,    -1,   122,   193,
      -1,    -1,   123,   193,    -1,   248,    -1,   193,     8,   248,
      -1,    -1,   125,   195,    -1,   266,    -1,    31,   266,    -1,
     175,    -1,    26,   173,    88,   160,    -1,   175,    -1,    26,
     173,    90,   160,    -1,   175,    -1,    26,   173,    92,   160,
      -1,    73,    13,   256,    -1,   199,     8,    73,    13,   256,
      -1,   161,   201,   162,    -1,   161,   160,   201,   162,    -1,
      26,   201,    95,   160,    -1,    26,   160,   201,    95,   160,
      -1,    -1,   201,    96,   262,   202,   173,    -1,   201,    97,
     202,   173,    -1,    26,    -1,   160,    -1,   175,    -1,    26,
     173,    86,   160,    -1,    -1,   204,    68,   158,   262,   159,
     175,    -1,    -1,   205,    68,   158,   262,   159,    26,   173,
      -1,    -1,    69,   175,    -1,    -1,    69,    26,   173,    -1,
     209,    -1,    -1,   210,    75,    -1,   210,    31,    75,    -1,
     210,    31,    75,    13,   256,    -1,   210,    75,    13,   256,
      -1,   209,     8,   210,    75,    -1,   209,     8,   210,    31,
      75,    -1,   209,     8,   210,    31,    75,    13,   256,    -1,
     209,     8,   210,    75,    13,   256,    -1,    -1,   248,    -1,
     127,    -1,   153,    -1,   212,    -1,    -1,   241,    -1,   266,
      -1,    31,   264,    -1,   212,     8,   241,    -1,   212,     8,
     266,    -1,   212,     8,    31,   264,    -1,   213,     8,   214,
      -1,   214,    -1,    75,    -1,   163,   263,    -1,   163,   161,
     262,   162,    -1,   215,     8,    75,    -1,   215,     8,    75,
      13,   256,    -1,    75,    -1,    75,    13,   256,    -1,   216,
     217,    -1,    -1,   232,   236,   160,    -1,   237,   160,    -1,
     219,    -1,    -1,   233,   243,   218,   185,    73,   158,   208,
     159,   231,    -1,   107,   220,   221,    -1,   248,    -1,   220,
       8,   248,    -1,   160,    -1,   161,   222,   162,    -1,    -1,
     223,    -1,   224,    -1,   223,   224,    -1,   225,   160,    -1,
     229,   160,    -1,   228,   152,   226,    -1,   248,    -1,   226,
       8,   248,    -1,    73,    -1,   228,    -1,   248,   145,    73,
      -1,   227,    93,   230,    73,    -1,   227,    93,   235,    -1,
      -1,   235,    -1,   160,    -1,   161,   173,   162,    -1,   234,
      -1,   115,    -1,    -1,   234,    -1,   235,    -1,   234,   235,
      -1,   109,    -1,   110,    -1,   111,    -1,   114,    -1,   113,
      -1,   112,    -1,   236,     8,    75,    -1,   236,     8,    75,
      13,   256,    -1,    75,    -1,    75,    13,   256,    -1,   237,
       8,    73,    13,   256,    -1,   102,    73,    13,   256,    -1,
     238,     8,   262,    -1,   262,    -1,    -1,   240,    -1,   240,
       8,   262,    -1,   262,    -1,   126,   158,   285,   159,    13,
     262,    -1,   266,    13,   262,    -1,   266,    13,    31,   266,
      -1,   266,    13,    31,    65,   249,   254,    -1,    64,   262,
      -1,   266,    24,   262,    -1,   266,    23,   262,    -1,   266,
      22,   262,    -1,   266,    21,   262,    -1,   266,    20,   262,
      -1,   266,    19,   262,    -1,   266,    18,   262,    -1,   266,
      17,   262,    -1,   266,    16,   262,    -1,   266,    15,   262,
      -1,   266,    14,   262,    -1,   265,    62,    -1,    62,   265,
      -1,   265,    61,    -1,    61,   265,    -1,   262,    27,   262,
      -1,   262,    28,   262,    -1,   262,     9,   262,    -1,   262,
      11,   262,    -1,   262,    10,   262,    -1,   262,    29,   262,
      -1,   262,    31,   262,    -1,   262,    30,   262,    -1,   262,
      44,   262,    -1,   262,    42,   262,    -1,   262,    43,   262,
      -1,   262,    45,   262,    -1,   262,    46,   262,    -1,   262,
      47,   262,    -1,   262,    41,   262,    -1,   262,    40,   262,
      -1,    42,   262,    -1,    43,   262,    -1,    48,   262,    -1,
      50,   262,    -1,   262,    33,   262,    -1,   262,    32,   262,
      -1,   262,    35,   262,    -1,   262,    34,   262,    -1,   262,
      36,   262,    -1,   262,    39,   262,    -1,   262,    37,   262,
      -1,   262,    38,   262,    -1,   262,    49,   249,    -1,   291,
      -1,   294,    -1,   262,    25,   262,    26,   262,    -1,   262,
      25,    26,   262,    -1,   289,    -1,    60,   262,    -1,    59,
     262,    -1,    58,   262,    -1,    55,   262,    -1,    54,   262,
      -1,    53,   262,    -1,    52,   262,    -1,    66,   253,    -1,
      51,   262,    -1,    82,    -1,   258,    -1,   292,    -1,   293,
      -1,    12,   262,    -1,   156,    -1,   243,   185,   158,   208,
     159,   244,   161,   173,   162,    -1,   114,   243,   185,   158,
     208,   159,   244,   161,   173,   162,    -1,   156,   241,    -1,
     156,   266,    -1,   156,   262,   125,   241,    -1,   156,   262,
     125,   266,    -1,   101,    -1,    -1,   107,   158,   245,   159,
      -1,   245,     8,    75,    -1,   245,     8,    31,    75,    -1,
      75,    -1,    31,    75,    -1,   168,   158,   211,   159,    -1,
     148,   151,   168,   158,   211,   159,    -1,   151,   168,   158,
     211,   159,    -1,   247,   145,    73,   158,   211,   159,    -1,
     274,   145,    73,   158,   211,   159,    -1,   274,   145,   272,
     158,   211,   159,    -1,   247,   145,   272,   158,   211,   159,
      -1,   272,   158,   211,   159,    -1,   114,    -1,   168,    -1,
     148,   151,   168,    -1,   151,   168,    -1,   168,    -1,   148,
     151,   168,    -1,   151,   168,    -1,   247,    -1,   250,    -1,
     277,   124,   281,   251,    -1,   277,    -1,   251,   252,    -1,
      -1,   124,   281,    -1,    -1,   158,   159,    -1,   158,   262,
     159,    -1,    -1,   158,   211,   159,    -1,    71,    -1,    72,
      -1,    81,    -1,   131,    -1,   132,    -1,   150,    -1,   128,
      -1,   129,    -1,   155,    -1,   130,    -1,   149,    -1,   142,
      -1,   255,    -1,   168,    -1,   148,   151,   168,    -1,   151,
     168,    -1,    42,   256,    -1,    43,   256,    -1,   127,   158,
     259,   159,    -1,    63,   259,   164,    -1,   257,    -1,   247,
     145,    73,    -1,    74,    -1,   295,    -1,   168,    -1,   148,
     151,   168,    -1,   151,   168,    -1,   255,    -1,    -1,   261,
     260,    -1,    -1,     8,    -1,   261,     8,   256,   125,   256,
      -1,   261,     8,   256,    -1,   256,   125,   256,    -1,   256,
      -1,   263,    -1,   241,    -1,   266,    -1,   266,    -1,   266,
      -1,   276,   124,   281,   271,   267,    -1,   276,    -1,   267,
     268,    -1,    -1,   124,   281,   271,    -1,   269,    63,   280,
     164,    -1,   270,    63,   280,   164,    -1,   158,   211,   159,
      -1,   270,    -1,   269,    -1,    -1,   278,    -1,   284,   278,
      -1,   247,   145,   272,    -1,   274,   145,   272,    -1,   278,
      -1,   275,    63,   280,   164,    -1,   246,    63,   280,   164,
      -1,   277,    -1,   275,    -1,   246,    -1,   278,    -1,   158,
     294,   159,    -1,   284,   278,    -1,   273,    -1,   278,    63,
     280,   164,    -1,   278,   161,   262,   162,    -1,   279,    -1,
      75,    -1,   163,   161,   262,   162,    -1,    -1,   262,    -1,
     282,    -1,   272,    -1,   282,    63,   280,   164,    -1,   282,
     161,   262,   162,    -1,   283,    -1,    73,    -1,   161,   262,
     162,    -1,   163,    -1,   284,   163,    -1,   285,     8,   286,
      -1,   286,    -1,   266,    -1,   126,   158,   285,   159,    -1,
      -1,    -1,   288,   260,    -1,   288,     8,   262,   125,   262,
      -1,   288,     8,   262,    -1,   262,   125,   262,    -1,   262,
      -1,   288,     8,   262,   125,    31,   264,    -1,   288,     8,
      31,   264,    -1,   262,   125,    31,   264,    -1,    31,   264,
      -1,   117,   158,   290,   159,    -1,   118,   158,   266,   159,
      -1,     7,   262,    -1,     6,   262,    -1,     5,   158,   262,
     159,    -1,     4,   262,    -1,     3,   262,    -1,   266,    -1,
     290,     8,   266,    -1,   158,   262,   159,    -1,   158,   242,
     159,    -1,   293,    63,   280,   164,    -1,   292,    63,   280,
     164,    -1,    81,    63,   280,   164,    -1,   127,   158,   287,
     159,    -1,    63,   287,   164,    -1,    65,   249,   254,    -1,
     247,   145,    73,    -1,   274,   145,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   203,   206,   212,   215,   221,   222,   223,
     224,   229,   236,   242,   250,   256,   263,   266,   273,   278,
     284,   290,   300,   307,   317,   320,   326,   327,   328,   329,
     337,   338,   344,   347,   350,   356,   359,   389,   404,   411,
     419,   432,   439,   446,   453,   460,   467,   474,   481,   488,
     493,   498,   503,   507,   511,   515,   521,   538,   554,   560,
     564,   578,   586,   597,   598,   604,   607,   617,   621,   628,
     639,   643,   650,   654,   658,   662,   665,   671,   685,   696,
     711,   715,   722,   729,   736,   739,   745,   749,   752,   760,
     763,   771,   774,   780,   783,   789,   790,   798,   799,   807,
     808,   816,   817,   825,   831,   842,   845,   855,   860,   872,
     875,   883,   893,   894,   898,   899,   907,   910,   920,   923,
     933,   936,   944,   947,   955,   956,   962,   970,   979,   988,
     996,  1004,  1013,  1022,  1033,  1036,  1039,  1042,  1048,  1049,
    1055,  1058,  1061,  1066,  1069,  1072,  1078,  1082,  1089,  1092,
    1096,  1103,  1111,  1119,  1127,  1138,  1141,  1147,  1155,  1159,
    1162,  1162,  1181,  1189,  1192,  1198,  1201,  1207,  1210,  1216,
    1220,  1227,  1230,  1236,  1244,  1248,  1255,  1259,  1265,  1273,
    1279,  1288,  1291,  1299,  1302,  1308,  1309,  1316,  1319,  1326,
    1330,  1336,  1337,  1338,  1339,  1340,  1341,  1345,  1352,  1359,
    1366,  1376,  1385,  1397,  1400,  1407,  1410,  1415,  1418,  1425,
    1433,  1439,  1449,  1463,  1468,  1474,  1480,  1486,  1492,  1498,
    1504,  1510,  1516,  1522,  1528,  1534,  1539,  1544,  1549,  1554,
    1560,  1566,  1572,  1578,  1584,  1590,  1596,  1602,  1628,  1634,
    1640,  1646,  1652,  1658,  1664,  1670,  1675,  1680,  1685,  1690,
    1696,  1702,  1708,  1714,  1720,  1726,  1732,  1738,  1744,  1745,
    1746,  1752,  1758,  1759,  1764,  1769,  1774,  1779,  1784,  1789,
    1794,  1799,  1804,  1808,  1809,  1810,  1811,  1816,  1822,  1833,
    1853,  1859,  1865,  1871,  1880,  1884,  1887,  1895,  1898,  1903,
    1907,  1916,  1921,  1927,  1933,  1941,  1949,  1957,  1965,  1973,
    1976,  1979,  1983,  1990,  1993,  1997,  2004,  2005,  2009,  2018,
    2022,  2025,  2031,  2037,  2040,  2044,  2052,  2055,  2061,  2064,
    2067,  2070,  2073,  2076,  2079,  2082,  2085,  2088,  2091,  2094,
    2100,  2101,  2102,  2106,  2110,  2115,  2120,  2126,  2132,  2136,
    2144,  2145,  2146,  2147,  2150,  2153,  2157,  2160,  2166,  2169,
    2173,  2180,  2187,  2194,  2204,  2205,  2209,  2213,  2217,  2221,
    2241,  2245,  2248,  2254,  2264,  2270,  2279,  2285,  2286,  2287,
    2293,  2294,  2309,  2314,  2322,  2326,  2332,  2341,  2342,  2343,
    2347,  2348,  2351,  2363,  2367,  2373,  2379,  2383,  2386,  2394,
    2397,  2403,  2404,  2408,  2414,  2420,  2424,  2428,  2434,  2437,
    2452,  2455,  2462,  2463,  2468,  2474,  2477,  2483,  2490,  2497,
    2504,  2511,  2518,  2525,  2532,  2542,  2552,  2562,  2565,  2568,
    2578,  2581,  2587,  2591,  2597,  2602,  2608,  2614,  2620,  2629,
    2635,  2644,  2653,  2658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_REQUIRE_ONCE", "T_REQUIRE", "T_EVAL",
  "T_INCLUDE_ONCE", "T_INCLUDE", "','", "T_LOGICAL_OR", "T_LOGICAL_XOR",
  "T_LOGICAL_AND", "T_PRINT", "'='", "T_SR_EQUAL", "T_SL_EQUAL",
  "T_XOR_EQUAL", "T_OR_EQUAL", "T_AND_EQUAL", "T_MOD_EQUAL",
  "T_CONCAT_EQUAL", "T_DIV_EQUAL", "T_MUL_EQUAL", "T_MINUS_EQUAL",
  "T_PLUS_EQUAL", "'?'", "':'", "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'",
  "'^'", "'&'", "T_IS_NOT_IDENTICAL", "T_IS_IDENTICAL", "T_IS_NOT_EQUAL",
  "T_IS_EQUAL", "'<'", "'>'", "T_IS_GREATER_OR_EQUAL",
  "T_IS_SMALLER_OR_EQUAL", "T_SR", "T_SL", "'+'", "'-'", "'.'", "'*'",
  "'/'", "'%'", "'!'", "T_INSTANCEOF", "'~'", "'@'", "T_UNSET_CAST",
  "T_BOOL_CAST", "T_OBJECT_CAST", "T_ARRAY_CAST", "T_BINARY_CAST",
  "T_UNICODE_CAST", "T_STRING_CAST", "T_DOUBLE_CAST", "T_INT_CAST",
  "T_DEC", "T_INC", "'['", "T_CLONE", "T_NEW", "T_EXIT", "T_IF",
  "T_ELSEIF", "T_ELSE", "T_ENDIF", "T_LNUMBER", "T_DNUMBER", "T_STRING",
  "T_STRING_VARNAME", "T_VARIABLE", "T_NUM_STRING", "T_INLINE_HTML",
  "T_CHARACTER", "T_BAD_CHARACTER", "T_ENCAPSED_AND_WHITESPACE",
  "T_CONSTANT_ENCAPSED_STRING", "T_BACKTICKS_EXPR", "T_ECHO", "T_DO",
  "T_WHILE", "T_ENDWHILE", "T_FOR", "T_ENDFOR", "T_FOREACH",
  "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE", "T_AS", "T_SWITCH",
  "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK", "T_CONTINUE", "T_GOTO",
  "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY", "T_CATCH", "T_THROW",
  "T_USE", "T_GLOBAL", "T_PUBLIC", "T_PROTECTED", "T_PRIVATE", "T_FINAL",
  "T_ABSTRACT", "T_STATIC", "T_VAR", "T_UNSET", "T_ISSET", "T_EMPTY",
  "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE", "T_EXTENDS", "T_IMPLEMENTS",
  "T_OBJECT_OPERATOR", "T_DOUBLE_ARROW", "T_LIST", "T_ARRAY", "T_CLASS_C",
  "T_METHOD_C", "T_FUNC_C", "T_LINE", "T_FILE", "T_COMMENT",
  "T_DOC_COMMENT", "T_OPEN_TAG", "T_OPEN_TAG_WITH_ECHO", "T_OPEN_TAG_FAKE",
  "T_CLOSE_TAG", "T_WHITESPACE", "T_START_HEREDOC", "T_END_HEREDOC",
  "T_HEREDOC", "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN",
  "T_PAAMAYIM_NEKUDOTAYIM", "T_BINARY_DOUBLE", "T_BINARY_HEREDOC",
  "T_NAMESPACE", "T_NS_C", "T_DIR", "T_NS_SEPARATOR", "T_INSTEADOF",
  "T_CALLABLE", "T_TRAIT", "T_TRAIT_C", "T_YIELD", "T_FINALLY", "'('",
  "')'", "';'", "'{'", "'}'", "'$'", "']'", "$accept", "start",
  "top_statement_list", "namespace_name", "top_statement",
  "use_declarations", "use_declaration", "constant_declaration",
  "inner_statement_list", "inner_statement", "statement",
  "unticked_statement", "additional_catches", "finally_statement",
  "non_empty_additional_catches", "additional_catch", "unset_variables",
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
  "combined_scalar", "new_expr", "class_constant", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    44,   263,
     264,   265,   266,    61,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    63,    58,   278,   279,   124,
      94,    38,   280,   281,   282,   283,    60,    62,   284,   285,
     286,   287,    43,    45,    46,    42,    47,    37,    33,   288,
     126,    64,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,    91,   300,   301,   302,   303,   304,   305,
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     1,     1,     1,
       4,     3,     5,     4,     3,     2,     3,     1,     1,     3,
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

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,     0,     0,   313,     0,   318,
     319,     5,   340,   387,    52,   320,   272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,     0,
       0,    80,    86,     0,     0,   324,   325,   327,   321,   322,
      32,    33,    34,   329,     0,   328,   323,     0,    83,   326,
     277,     0,    59,    25,   398,   342,     3,     0,     7,    30,
       8,     9,    73,    74,     0,     0,   355,     0,    75,   379,
       0,   345,   273,     0,   354,     0,   356,     0,   383,     0,
     378,   360,   377,   380,   386,     0,   262,   258,   274,   275,
     259,   341,     5,   299,     0,   277,    75,   421,   420,     0,
     418,   417,   276,   245,   246,   247,   248,   271,   269,   268,
     267,   266,   265,   264,   263,   299,     0,     0,     0,   300,
       0,   228,   358,     0,   226,     0,   410,     0,   348,   213,
       0,     0,   300,   306,   316,   307,     0,   309,   380,     0,
       0,   270,     0,    31,   389,     0,   204,     0,     0,   205,
       0,     0,     0,    42,     0,    44,     0,     0,     0,    46,
     355,     0,   356,    25,     0,     0,    18,     0,    17,   148,
       0,     0,   147,    82,    81,   153,     0,    75,     0,     0,
       0,     0,   404,   405,     0,     4,     0,   344,   355,     0,
     356,     0,     0,   259,     0,     0,     0,   139,     0,    15,
      84,    87,    54,    76,     0,   389,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,   227,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
     389,     0,   389,     0,   399,   382,   389,   389,     0,     0,
       0,   302,     0,     0,     0,   414,   357,     0,   430,   349,
     406,     0,   302,     0,   139,   431,     0,     0,   382,   314,
       0,     0,   390,     0,     0,    51,     0,     0,     0,   206,
     208,   355,   356,     0,     0,     0,    43,    45,    62,     0,
      47,    48,     0,    61,    20,     0,     0,    14,     0,   149,
     356,     0,    49,     0,     0,    50,     0,     0,    70,    72,
     422,     0,     0,     0,     0,   402,     0,   401,     0,   343,
       0,    11,     4,   139,     0,   425,   424,   381,     0,    35,
      24,    26,    27,    28,     0,     6,     0,     0,   138,   355,
     356,     0,     0,    89,     0,     0,     0,   134,     0,   432,
     372,   370,     0,   231,   233,   232,     0,     0,   229,   230,
     234,   236,   235,   250,   249,   252,   251,   253,   255,   256,
     254,   244,   243,   238,   239,   237,   240,   241,   242,   257,
       0,   210,   224,   223,   222,   221,   220,   219,   218,   217,
     216,   215,   214,     0,   433,   373,     0,   396,     0,   392,
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
       0,    21,   150,     0,     0,    71,    55,   423,     0,   400,
       0,     0,    12,   293,     0,     0,   355,   356,    22,     0,
     305,    90,   156,     0,   187,     0,   285,   134,     0,   126,
       0,     0,   260,   316,     0,     0,   397,     0,   389,   389,
     359,     0,     0,     0,   407,     0,   310,   118,   120,     0,
       0,   205,     0,     0,    96,     0,     0,     0,   109,     0,
     109,     0,     0,   337,   349,   347,     0,   332,   339,     0,
     152,   285,   403,   209,   292,    29,   145,   304,   187,    92,
       0,     0,   191,   192,   193,   196,   195,   194,   186,    79,
     155,   159,     0,     0,   185,   189,     0,     0,     0,     0,
       0,   127,     0,   294,   297,   212,   295,   296,   366,     0,
       0,     0,   361,   393,   394,   411,   312,   122,     0,     0,
      36,    39,     0,     0,    94,     0,     0,   104,     0,     0,
       0,     0,     0,     0,   105,   352,   351,   336,     0,     0,
      78,     0,     0,   163,   199,     0,   160,   190,     0,   158,
      25,     0,    25,     0,   130,     0,   129,   364,   365,   369,
       0,     0,     0,     0,   121,   115,     0,    25,    99,    57,
      56,   102,     0,   107,     0,   112,   113,    25,   106,     0,
       0,    25,     0,     0,   165,   167,   162,     0,     0,   157,
      75,     0,     0,     0,   289,     0,     0,   131,     0,   128,
     363,     0,    25,     0,     0,    25,    97,    40,     0,   108,
      25,   111,   350,     0,     0,   202,   164,     5,     0,   168,
     169,     0,     0,   177,     0,     0,   200,   197,     0,     0,
      77,   290,     0,   286,   278,     0,   133,     0,   123,    37,
       0,     0,     0,   110,    25,   279,   166,   170,   171,   181,
       0,   172,     0,     0,     0,   201,     0,   287,   132,     0,
     117,     0,   100,     0,     0,   180,   173,   174,   178,   198,
     134,   288,    25,    98,    64,   179,     0,     0,   119,     0,
      65,    63,    67,   175,     0,     0,     0,    60,    68,   183,
      25,   161,     0,    25,     0,     0,     0,   184,     0,    66,
      25,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   197,   198,    87,   224,   370,
     371,    89,   870,   877,   871,   872,   347,   348,   372,   373,
     234,    92,    93,    94,   383,    95,   385,   522,   523,   643,
     571,   797,   759,   577,   324,   580,   649,   767,   566,   638,
     707,   710,   752,   529,   530,   531,   377,   378,   201,   202,
     206,   614,   680,   780,   681,   732,   776,   808,   809,   810,
     811,   856,   812,   813,   814,   854,   881,   682,   683,   684,
     685,   735,   686,   175,   318,   319,    96,    97,   126,   689,
     785,    99,   100,   532,   164,   165,   560,   636,   171,   305,
     101,   583,   485,   102,   584,   300,   585,   103,   104,   295,
     105,   106,   630,   702,   547,   548,   549,   107,   108,   109,
     110,   111,   112,   113,   114,   313,   440,   441,   442,   115,
     356,   357,   157,   158,   116,   351,   117,   118,   119,   120,
     121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -672
static const yytype_int16 yypact[] =
{
    -672,    87,  1778,  -672,  6290,  6290,   -69,  6290,  6290,  6290,
    6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,
    6290,  6290,   -11,   -11,  4718,  6290,   254,   -66,   -61,  -672,
    -672,   139,  -672,  -672,  -672,   147,  -672,  6290,  4578,    44,
      69,    71,    73,    83,  4849,  4980,   172,  -672,   181,  5111,
      98,  6290,    -6,   -20,   154,   161,   -23,   135,   137,   170,
     175,  -672,  -672,   202,   212,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,    75,  -672,  -672,   224,  -672,  -672,
    6290,  6421,  -672,  -672,   144,    61,  -672,    11,  -672,  -672,
    -672,  -672,  -672,  -672,   253,   299,  -672,   213,   344,   315,
     236,  -672,  -672,  6836,  -672,    15,  1432,   225,  -672,   246,
     329,   270,  -672,   -27,  -672,   -19,  -672,  -672,   340,   341,
    -672,  -672,  -672,   305,   257,  -672,   344,  7610,  7610,  6290,
    7610,  7610,  7710,  -672,  -672,   360,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,   262,   224,   345,   -60,
     269,  -672,  -672,   279,  -672,   -11,  7412,   261,   418,  -672,
     276,   224,   281,   285,   282,  -672,   292,   317,    -4,   -19,
    5242,  -672,  6290,  -672,  6290,    12,  7610,   357,  6290,  6290,
    6290,   371,  6290,  -672,  6877,  -672,  6918,   287,   438,  -672,
     306,  7610,  1014,  -672,  6970,   224,    26,    14,  -672,  -672,
     -12,    16,  -672,  -672,  -672,   454,    18,   344,   -11,   -11,
     -11,   319,   381,  4718,   224,  -672,   -86,    66,    91,  7453,
      93,   321,  7011,   322,  1918,  6290,   411,  5373,   413,  -672,
     365,   369,  -672,  -672,   -29,  6290,    10,  6290,  6290,  6290,
    5504,  6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,
    6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,
    6290,  6290,   254,  -672,  -672,  -672,  5635,  6290,  6290,  6290,
    6290,  6290,  6290,  6290,  6290,  6290,  6290,  6290,  5373,    60,
    6290,   140,  6290,  6290,   144,   -34,  6290,  6290,   354,  7052,
     224,   -26,   322,   123,   141,  -672,  -672,  5766,  -672,  5897,
    -672,   224,   281,    45,  5373,  -672,    45,   140,   -31,  -672,
    7104,  7146,  7610,   334,  6290,  -672,   359,  7187,   362,   517,
    7610,   426,  1312,   514,    25,  7237,  -672,  -672,  -672,  1159,
    -672,  -672,  2058,  -672,    67,   460,    -6,  -672,  6290,  -672,
    -672,   -20,  -672,  1159,   462,  -672,   377,    27,  -672,  -672,
    -672,    29,   382,   385,   384,  -672,    30,  -672,   387,   115,
    1498,  -672,  -672,  5373,  6290,  -672,  -672,  -672,   391,  -672,
    -672,  -672,  -672,  -672,  6564,  -672,   -11,   388,   532,    34,
     326,   537,    96,   431,    96,   405,   414,   280,   407,   415,
     419,   -31,   -19,  7650,  7687,  7710,  6290,  7554,  7755,  7776,
    1433,  4771,  1770,  1910,  1910,  1910,  1910,  1042,  1042,  1042,
    1042,   457,   457,   389,   389,   389,   360,   360,   360,  -672,
     380,  7710,  7710,  7710,  7710,  7710,  7710,  7710,  7710,  7710,
    7710,  7710,  7710,   420,   422,   425,   421,  -672,  6290,  -672,
     428,    -3,  -672,   427,  6605,   429,   430,  -672,    81,   415,
     422,   -11,  7610,   -11,  7511,   281,  -672,   433,  -672,  -672,
    -672,  3878,  -672,  7610,  6290,  4018,  6290,  6290,   -11,   238,
    1159,   505,  4158,    24,  1159,  1159,  1159,  -672,   432,   445,
     224,   -72,   439,  -672,  -672,  -672,   484,   525,  -672,  -672,
    6646,  -672,  -672,   586,   280,   -11,   443,   -11,  -672,  -672,
    -672,   381,   381,   592,  -672,  5373,  -672,  1638,   447,   102,
    1196,   450,  -672,  -672,  -672,  6028,  1159,   456,   224,   281,
    -672,    96,   449,   603,  -672,  -672,   280,  -672,  -672,   455,
     607,    53,  -672,  -672,  5373,  5373,   -31,  7733,  6290,   254,
    -672,  -672,  5373,  5373,  -672,  6700,  5373,   554,   564,  -672,
    6290,  6290,  -672,  -672,  -672,  -672,  -672,  -672,  6159,  -672,
     506,  -672,  -672,  7279,  -672,  -672,  -672,   469,  7610,   507,
     -11,   507,  -672,  -672,   620,  -672,  -672,  -672,   474,   476,
    -672,  -672,  -672,   515,   478,   635,  1159,   224,   113,   571,
     488,  -672,  -672,  1159,   491,  -672,  -672,  -672,    35,  -672,
    6290,   492,  -672,  -672,   493,   -11,    38,   989,  -672,   224,
     281,   603,  -672,    96,   511,   497,   545,   242,   582,   645,
     500,   501,  7733,   282,   502,   504,  -672,   508,  6290,  6290,
     541,   510,  6741,   -11,  7610,   140,  -672,  3738,   220,   509,
    2198,  6290,   238,   512,  -672,   513,  1159,  2338,  -672,   240,
    -672,    -1,  1159,  -672,  1159,  -672,   516,   131,  -672,    96,
    -672,   545,  -672,  7710,  -672,  -672,  -672,   281,   587,  -672,
     595,    96,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,   601,   305,   348,  -672,    22,   521,   519,   522,
     150,   665,  1159,  -672,  -672,  -672,  -672,  -672,  -672,   520,
     524,   140,  -672,  -672,  -672,  -672,  -672,   249,   533,  4578,
    -672,  -672,   530,   536,  -672,  4298,  4298,  -672,   543,   259,
     544,  6290,     2,     8,  -672,  -672,   567,  -672,   632,   548,
    -672,   697,     6,  -672,   698,    23,  -672,  -672,   642,  -672,
    -672,   160,  -672,   643,   704,  1159,  -672,  -672,  -672,   428,
     561,   694,   651,  6290,  -672,  -672,  4438,  -672,  -672,  -672,
    -672,  -672,   565,  -672,  6784,  -672,  -672,  -672,  -672,  1159,
     568,  -672,  1159,    96,  -672,   119,  -672,  1159,   649,  -672,
     344,   713,  2478,   653,  -672,    41,  2618,   716,  1159,  -672,
    -672,  6290,  -672,   570,  7320,  -672,  -672,  -672,  2758,  -672,
    -672,  3738,  -672,   573,  2898,  -672,  -672,   638,   574,   119,
    -672,   572,   644,   583,   578,   594,  -672,   728,   670,  1159,
    -672,  -672,   168,  -672,  -672,  1159,  -672,  7370,  3738,  -672,
    4578,  3038,   584,  3738,  -672,  -672,  -672,  -672,  -672,   448,
      96,  -672,   672,  1159,   589,  -672,   678,  -672,  -672,   729,
    -672,   596,  -672,  3178,   684,   685,   751,  -672,  -672,  -672,
     280,  -672,  -672,  -672,   655,  -672,    96,   602,  3738,   608,
     612,   655,  -672,  -672,   162,    96,   604,  -672,  -672,  -672,
    -672,  -672,   696,  -672,  3318,   614,  3458,  -672,   613,  -672,
    -672,  3598,  -672
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -672,  -672,  -199,    -5,  -672,  -672,   440,  -672,   187,  -672,
       7,  -672,  -672,  -672,  -672,   -96,  -672,   283,     1,     3,
    -125,  -672,  -672,  -672,  -672,  -672,  -672,  -672,   256,   208,
     143,  -672,    70,  -672,  -672,  -672,  -420,    31,  -672,  -672,
    -672,  -672,  -672,  -486,  -672,   165,  -263,  -672,  -672,   446,
    -672,   176,  -672,  -672,  -672,  -672,  -672,  -672,  -672,   -18,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -671,  -672,  -672,  -672,  -454,  -672,    21,   708,    -2,   129,
    -672,  -672,   100,  -357,  -255,  -672,  -672,  -672,  -672,   171,
     712,  -295,  -672,  -672,   207,   215,  -672,   886,   597,  -365,
     342,   892,  -672,  -672,  -672,  -672,    49,  -213,  -672,   211,
    -672,  -672,   -24,   -16,  -672,  -229,  -303,  -672,  -672,    13,
     300,   301,   593,  -672,  -672,  -672,  -672,  -672,  -672,   -10,
    -672
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -375
static const yytype_int16 yytable[] =
{
      98,   288,   167,    90,   459,    91,   388,   419,   594,    88,
     168,   513,   567,   737,   773,   433,   360,   149,   149,   228,
     314,   162,   336,   390,   341,   520,   344,   524,   765,   282,
     738,   778,   282,   471,   484,   495,   282,   497,   502,   169,
     615,   457,  -140,   502,   386,   177,  -143,   196,   492,   822,
     578,   436,   205,   443,   207,   199,    33,   445,   446,   282,
     550,   122,   122,    33,    33,   226,   435,   122,   439,   216,
     190,   223,   217,  -300,   361,   362,   264,   265,    47,   226,
     390,   435,   346,   389,   618,    33,   556,     3,   557,   129,
     456,   226,   170,   458,   439,   721,   722,   172,   227,   285,
     508,   218,   145,   145,   721,   722,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,  -374,   335,
      33,   207,   150,   150,  -371,   226,   163,   283,   619,   387,
     283,  -370,   363,   434,   283,    33,   146,   146,   292,   147,
     147,  -374,   291,   200,   284,   195,   148,   148,   122,   338,
     149,    84,    84,   308,  -358,  -358,   302,   283,   551,   651,
     487,   724,   766,   507,   524,   173,   774,   775,   855,   122,
     768,   229,   315,    84,   337,   573,   342,   226,   345,   581,
     582,   743,   739,   779,   472,   579,   496,   713,   498,   503,
     334,   783,   807,  -140,   662,   149,   449,  -143,    33,   846,
     823,   321,   178,   149,   149,   149,  -300,   149,    84,   359,
     174,  -302,   226,   437,   450,    33,    33,   226,   226,   227,
     391,   608,    98,    84,   363,   744,   214,   179,   719,   180,
     723,   181,   226,   153,   153,   784,   215,   166,   167,   505,
     666,   182,   601,   847,   517,   187,   168,   518,   379,   392,
    -280,  -280,  -281,  -281,   188,   150,   669,   162,  -302,   193,
    -301,  -282,  -282,   391,   226,   391,   226,   517,   705,   570,
     518,   620,   621,   505,   203,   169,  -301,   391,   391,   624,
     625,   204,   226,   627,   623,   448,    84,   391,   708,   709,
     391,   391,   392,   208,   392,   209,   455,   122,   660,   379,
     150,   438,   728,    84,    84,   225,   392,   392,   150,   150,
     150,   122,   150,    33,   733,   122,   392,   750,   751,   392,
     392,   631,   879,   880,   481,   379,   230,   122,   210,    33,
      98,   196,   706,   211,  -141,   720,   721,   722,   481,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   717,   145,   122,   762,   721,   722,   725,    98,   726,
     212,    90,   163,    91,   151,   154,   153,    88,   145,   527,
     213,   149,   231,   232,   867,   233,   536,   519,   235,   519,
     332,   236,   519,   278,   379,   509,   146,  -358,  -358,   147,
     517,   279,   280,   518,   281,   528,   148,   746,   749,   699,
     700,    84,   160,   286,   287,   161,    47,   527,   214,   262,
      26,   153,   148,   290,   293,   149,   806,    84,   815,   153,
     153,   153,   439,   153,   294,   298,   299,   301,   517,   482,
     303,   518,   226,   528,   259,   260,   261,   306,   262,  -125,
     304,   307,   316,   482,   323,   539,   149,   328,   149,  -188,
     789,   329,   815,   122,   122,    33,    33,   672,   673,   674,
     675,   676,   677,   149,   149,   481,   330,   343,   562,   481,
     481,   481,   565,   166,   802,   588,   150,   805,   353,   576,
     365,   367,   816,   857,   375,  -141,   381,   382,   439,   519,
     149,   384,   149,   826,   145,   145,   149,   149,   462,   256,
     257,   258,   259,   260,   261,    98,   262,   354,    90,   873,
      91,   481,   387,   610,    88,   167,   519,   464,   882,   468,
     150,   519,   466,   168,   845,   467,   379,   470,   146,   146,
     848,   147,   147,   488,   162,   494,   606,   493,   148,   148,
     515,   499,   501,    84,    84,   500,   504,   514,   859,   511,
     516,   150,   169,   150,   521,   379,   379,   672,   673,   674,
     675,   676,   677,   379,   379,   149,   525,   379,   150,   150,
     482,   533,   526,   534,   482,   482,   482,   535,   574,   541,
     542,   481,   657,   543,   589,   544,   546,   153,   481,   590,
     586,   552,   559,   554,   555,   150,   587,   150,   591,   593,
     149,   150,   150,   596,   667,   600,   603,   609,   519,   604,
     612,   613,   519,   670,   616,   617,   482,   628,   671,   391,
     672,   673,   674,   675,   676,   677,   678,   629,   149,   641,
     635,   153,   642,   646,   648,    98,   650,   149,    98,   163,
     652,   481,   653,   654,   658,    98,   659,   481,   392,   481,
     661,   664,   688,   665,   519,   818,   687,   691,   692,   693,
     694,   696,   153,   697,   153,   701,   519,   698,   731,   711,
     150,   715,   716,   679,   703,   727,   734,   741,   745,   153,
     153,   736,   740,   742,   747,   391,   482,   481,   748,   670,
     755,   753,   769,   482,   671,   756,   672,   673,   674,   675,
     676,   677,   678,   761,   763,   150,   153,   770,   153,   771,
     772,   777,   153,   153,   392,   781,   754,   788,   787,   791,
     792,   793,   758,   758,   817,   799,   819,   803,   821,   825,
     829,  -176,   838,   150,   834,   840,   836,   839,   841,   842,
     481,   843,   150,   844,   852,   858,   482,   860,   637,   730,
     166,   640,   482,   861,   482,   862,   863,   865,  -182,   866,
     869,   874,   647,   796,   481,   883,   875,   481,   519,   876,
     519,   885,   481,   888,   890,   878,   489,   611,   595,   645,
      98,   153,   690,   481,    98,   714,   760,   491,   668,   221,
     729,   837,   482,   656,   695,   800,    98,   339,   790,    98,
     655,   598,    98,   599,   519,     0,   358,     0,     0,     0,
       0,     0,     0,     0,   481,     0,   153,     0,     0,     0,
     481,     0,     0,     0,     0,     0,    98,     0,     0,    98,
       0,    98,     0,     0,     0,   519,     0,   850,   481,     0,
       0,     0,     0,     0,   153,   482,     0,     0,     0,     0,
       0,    98,     0,   153,     0,   519,     0,     0,     0,     0,
       0,   519,     0,     0,     0,     0,    98,     0,     0,   482,
     519,     0,   482,     0,     0,     0,     0,   482,     0,     0,
       0,     0,    98,     0,    98,     0,     0,     0,   482,    98,
     127,   128,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     156,   159,     0,     0,   152,   152,     0,     0,     0,   482,
       0,     0,     0,   176,     0,   482,     0,   782,     0,   786,
     184,   186,     0,     0,     0,   191,     0,   194,     0,     0,
       0,   192,     0,   482,   798,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   801,     0,     0,     0,   804,     0,
       0,     0,     0,     0,     0,     0,   219,   222,     0,     0,
       0,     0,   220,     0,     0,     0,     0,     0,     0,   828,
       0,     0,   831,     0,     0,     0,     0,   833,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -144,     0,     0,
       0,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,   289,     0,     0,     0,     0,
       0,   853,     0,     0,     0,     0,     0,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,   483,     0,     0,     0,     0,     0,   296,     0,   868,
    -358,  -358,     0,     0,     0,   483,   310,     0,   311,     0,
     312,     0,     0,     0,   317,   320,   191,   884,   325,     0,
     886,     0,   322,     0,     0,  -358,  -358,   891,  -375,  -375,
    -375,  -375,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   340,     0,     0,     0,     0,     0,     0,   156,
     349,   350,   352,     0,   355,     0,     0,     0,     0,     0,
       0,   374,     0,   191,     0,     0,     0,     0,     0,   380,
       0,   312,     0,   393,   394,   395,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,  -144,     0,
       0,     0,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   191,     0,   312,     0,   312,   444,
     380,     0,   312,   312,   331,     0,     0,     0,     0,     0,
       0,     0,   483,   452,     0,   454,   483,   483,   483,     0,
     191,     0,     0,     0,     0,     0,   380,     0,     0,     0,
     463,   474,   475,     0,     0,     0,     0,     0,     0,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,     0,   476,     0,   490,     0,     0,     0,   483,     0,
      29,    30,   122,     0,     0,     0,     0,     0,     0,     0,
     477,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     191,     0,     0,     0,     0,   380,   510,  -358,  -358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,   537,     0,     0,     0,   478,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,   483,     0,
       0,    73,     0,     0,     0,   483,     0,   479,    75,    76,
     480,     0,   540,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,     0,   296,     0,   296,     0,     0,     0,     0,
     563,     0,   320,   568,     0,  -283,  -283,     0,   483,     0,
     569,   572,     0,     0,   483,     0,   483,     0,     0,     0,
       0,     0,     0,  -358,  -358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   349,     0,   597,
       0,   191,     0,   355,   355,     0,     0,   380,     0,     0,
       0,   191,     0,     0,   483,   469,     0,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   191,     0,     0,   622,     0,   380,   380,   191,   191,
       0,     0,   191,     0,   380,   380,   312,   632,   380,     0,
       0,     0,     0,     0,   634,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   483,     0,     0,
       0,     0,   644,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   483,   262,     0,   483,     0,   663,     0,     0,   483,
       0,     0,     0,  -358,  -358,     0,     0,   296,     0,     0,
     483,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,     0,   312,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   296,     0,   320,     0,     0,
       0,   483,     0,     0,   572,     0,     0,   483,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,   483,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,   764,     0,     0,
      54,    55,    56,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,   794,
      73,     4,     5,     6,     7,     8,    74,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     506,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   827,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,    74,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     602,    84,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,    74,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
       0,    84,  -375,  -375,  -375,  -375,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     369,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     486,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,   712,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
     718,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     820,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     824,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,   832,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     835,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,   851,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     864,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     887,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     889,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
     892,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,   368,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,    78,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,   561,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
       0,     0,    56,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,     0,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,   564,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
       0,     0,    56,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,     0,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
       0,     0,    56,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,     0,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
       0,     0,    56,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,     0,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,   795,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
       0,     0,    56,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,     0,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
       0,     0,    56,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    71,     0,    72,     0,     0,     0,
      73,     4,     5,     6,     7,     8,   124,    75,    76,    77,
       9,     0,     0,    79,    80,     0,    81,     0,    82,    83,
       0,    84,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,    29,
      30,   122,    32,    33,     0,     0,     0,     0,     0,    35,
      36,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,    47,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      73,     9,     0,     0,     0,     0,   124,    75,    76,    77,
       0,     0,     0,    79,   125,     0,    81,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      29,    30,   122,    32,    33,     0,     0,     0,     0,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     4,     5,     6,     7,     8,     0,     0,
       0,    73,     9,     0,     0,     0,     0,   124,    75,    76,
      77,     0,     0,     0,    79,   125,     0,    81,     0,   183,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,     0,     0,
       0,    29,    30,   122,    32,    33,     0,     0,     0,     0,
       0,    35,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     4,     5,     6,     7,     8,     0,
       0,     0,    73,     9,     0,     0,     0,     0,   124,    75,
      76,    77,     0,     0,     0,    79,   125,     0,    81,     0,
     185,     0,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,    29,    30,   122,    32,    33,     0,     0,     0,
       0,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     4,     5,     6,     7,     8,
       0,     0,     0,    73,     9,     0,     0,     0,     0,   124,
      75,    76,    77,     0,     0,     0,    79,   125,     0,    81,
       0,   189,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    29,    30,   122,    32,    33,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    73,     9,     0,     0,     0,     0,
     124,    75,    76,    77,     0,     0,     0,    79,   125,     0,
      81,   309,     0,     0,   376,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,    29,    30,   122,    32,    33,     0,
       0,     0,     0,     0,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    73,     9,     0,     0,     0,
       0,   124,    75,    76,    77,     0,     0,     0,    79,   125,
     396,    81,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    29,    30,   122,    32,    33,
       0,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     4,     5,
       6,     7,     8,     0,     0,     0,    73,     9,     0,     0,
       0,     0,   124,    75,    76,    77,     0,     0,     0,    79,
     125,     0,    81,     0,     0,     0,   420,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,    29,    30,   122,    32,
      33,     0,     0,     0,     0,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     4,
       5,     6,     7,     8,     0,     0,     0,    73,     9,     0,
       0,     0,     0,   124,    75,    76,    77,     0,     0,     0,
      79,   125,     0,    81,     0,     0,     0,   451,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    29,    30,   122,
      32,    33,     0,     0,     0,     0,     0,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       4,     5,     6,     7,     8,     0,     0,     0,    73,     9,
       0,     0,     0,     0,   124,    75,    76,    77,     0,     0,
       0,    79,   125,     0,    81,     0,     0,     0,   453,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,    29,    30,
     122,    32,    33,     0,     0,     0,     0,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    73,
       9,     0,     0,     0,     0,   124,    75,    76,    77,     0,
       0,     0,    79,   125,     0,    81,     0,     0,     0,   605,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,    29,
      30,   122,    32,    33,     0,     0,     0,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      73,     9,     0,     0,     0,     0,   124,    75,    76,    77,
       0,     0,     0,    79,   125,     0,    81,     0,     0,     0,
     633,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      29,    30,   122,    32,    33,     0,     0,     0,     0,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,    58,    59,     0,     0,
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
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,    58,    59,     0,
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
       0,     0,     0,     0,     0,   123,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,   124,
      75,    76,    77,   237,   238,   239,    79,    80,     0,    81,
       0,     0,     0,     0,    84,     0,     0,     0,     0,   240,
       0,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,     0,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   512,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   553,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,     0,     0,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,   240,
     765,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   626,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   704,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   766,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   263,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   326,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   327,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     333,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,     0,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     366,   240,     0,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   447,   240,     0,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   460,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,   262,     0,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   461,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     0,   262,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   465,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   473,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
       0,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   639,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
       0,   262,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   830,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,     0,     0,     0,     0,     0,     0,   849,
       0,     0,     0,     0,     0,     0,   240,   297,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
     262,     0,     0,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,   240,
     538,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   558,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   239,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   240,   262,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,     0,   262,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,   262,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     0,   262,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     0,   262
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-672)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-375)))

static const yytype_int16 yycheck[] =
{
       2,   126,    26,     2,   307,     2,   235,   262,   494,     2,
      26,   376,   466,   684,     8,   278,   215,    22,    23,     8,
       8,    26,     8,   236,     8,   382,     8,   384,    26,    63,
       8,     8,    63,     8,   329,     8,    63,     8,     8,    26,
     526,   304,     8,     8,    73,    38,     8,    52,   343,     8,
      26,   280,    75,   282,    56,    75,    75,   286,   287,    63,
      63,    73,    73,    75,    75,   151,   279,    73,   281,    74,
      49,    81,    77,   145,   160,   161,    61,    62,   101,   151,
     293,   294,   207,    73,    31,    75,   451,     0,   453,   158,
     303,   151,   158,   306,   307,    96,    97,   158,   158,   115,
     363,    80,   114,   114,    96,    97,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   145,    93,
      75,   123,    22,    23,   158,   151,    26,   161,    75,   158,
     161,   158,   158,    73,   161,    75,   148,   148,   148,   151,
     151,   145,   147,   163,   163,   151,   158,   158,    73,   161,
     155,   163,   163,   169,    61,    62,   161,   161,   161,   579,
      93,   162,   160,   362,   521,    26,   160,   161,   839,    73,
     162,   160,   160,   163,   160,   470,   160,   151,   160,   474,
     475,    31,   160,   160,   159,   161,   159,   641,   159,   159,
     195,    31,    73,   159,   159,   200,    73,   159,    75,    31,
     159,   180,   158,   208,   209,   210,   145,   212,   163,   214,
      63,   145,   151,    73,    73,    75,    75,   151,   151,   158,
     236,   516,   224,   163,   158,    75,   151,   158,   648,   158,
     650,   158,   151,    22,    23,    75,   161,    26,   262,   158,
     605,   158,   505,    75,   148,    73,   262,   151,   227,   236,
     159,   160,   159,   160,    73,   155,   613,   262,   145,   161,
     145,   159,   160,   279,   151,   281,   151,   148,   633,    31,
     151,   534,   535,   158,   120,   262,   145,   293,   294,   542,
     543,   120,   151,   546,   539,   290,   163,   303,    68,    69,
     306,   307,   279,   158,   281,   158,   301,    73,   593,   278,
     200,   161,   659,   163,   163,   161,   293,   294,   208,   209,
     210,    73,   212,    75,   671,    73,   303,    68,    69,   306,
     307,   550,   160,   161,   329,   304,    73,    73,   158,    75,
     332,   336,   635,   158,     8,    95,    96,    97,   343,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   646,   114,    73,    95,    96,    97,   652,   360,   654,
     158,   360,   262,   360,    22,    23,   155,   360,   114,   127,
     158,   376,    73,   160,   860,    31,   392,   382,    63,   384,
     193,   145,   387,   158,   363,   364,   148,    61,    62,   151,
     148,   145,    63,   151,   124,   153,   158,   692,   701,   628,
     629,   163,   148,    63,    63,   151,   101,   127,   151,    49,
      65,   200,   158,   151,   145,   420,   773,   163,   775,   208,
     209,   210,   635,   212,   145,   164,     8,   151,   148,   329,
     145,   151,   151,   153,    45,    46,    47,   145,    49,   159,
     158,   124,    85,   343,    73,    65,   451,   160,   453,   101,
     745,    13,   809,    73,    73,    75,    75,   109,   110,   111,
     112,   113,   114,   468,   469,   470,   160,    13,   461,   474,
     475,   476,   465,   262,   769,   480,   376,   772,   159,   472,
     159,   159,   777,   840,    73,   159,    73,   122,   701,   494,
     495,   122,   497,   788,   114,   114,   501,   502,   164,    42,
      43,    44,    45,    46,    47,   507,    49,   126,   507,   866,
     507,   516,   158,   518,   507,   539,   521,   158,   875,    93,
     420,   526,   160,   539,   819,     8,   505,    13,   148,   148,
     825,   151,   151,    73,   539,   158,   515,    75,   158,   158,
       8,   159,   158,   163,   163,   160,   159,   159,   843,   158,
      13,   451,   539,   453,   123,   534,   535,   109,   110,   111,
     112,   113,   114,   542,   543,   570,   161,   546,   468,   469,
     470,   164,   158,   158,   474,   475,   476,   158,    73,   159,
     158,   586,   587,   158,   145,   164,   158,   376,   593,   105,
     158,   164,   159,   164,   164,   495,   151,   497,    73,    13,
     605,   501,   502,   160,   609,    13,   159,   151,   613,   159,
     161,     8,   617,   102,   159,     8,   516,    63,   107,   635,
     109,   110,   111,   112,   113,   114,   115,    63,   633,   160,
     124,   420,   125,    13,   160,   637,   160,   642,   640,   539,
     125,   646,   164,     8,    73,   647,   158,   652,   635,   654,
     159,   159,   107,   160,   659,   780,   159,    75,    13,   159,
     159,   159,   451,   159,   453,   124,   671,   159,    73,   160,
     570,   159,   159,   162,   164,   159,    75,   158,    13,   468,
     469,   683,   161,   161,   164,   701,   586,   692,   164,   102,
     160,   158,   125,   593,   107,   159,   109,   110,   111,   112,
     113,   114,   115,   160,   160,   605,   495,    75,   497,   161,
      13,    13,   501,   502,   701,    73,   709,    13,    75,   158,
      26,    70,   715,   716,    75,   160,    13,   159,    75,    13,
     160,    93,   160,   633,   161,   152,   162,    93,   160,   145,
     745,    13,   642,    73,   160,    73,   646,   158,   561,   162,
     539,   564,   652,    75,   654,    26,   160,    73,    73,     8,
     105,   159,   575,   756,   769,   161,   158,   772,   773,   157,
     775,    75,   777,   159,   161,   871,   336,   521,   495,   571,
     782,   570,   617,   788,   786,   642,   716,   341,   612,    81,
     661,   809,   692,   586,   623,   764,   798,   200,   749,   801,
     585,   501,   804,   502,   809,    -1,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   819,    -1,   605,    -1,    -1,    -1,
     825,    -1,    -1,    -1,    -1,    -1,   828,    -1,    -1,   831,
      -1,   833,    -1,    -1,    -1,   840,    -1,   830,   843,    -1,
      -1,    -1,    -1,    -1,   633,   745,    -1,    -1,    -1,    -1,
      -1,   853,    -1,   642,    -1,   860,    -1,    -1,    -1,    -1,
      -1,   866,    -1,    -1,    -1,    -1,   868,    -1,    -1,   769,
     875,    -1,   772,    -1,    -1,    -1,    -1,   777,    -1,    -1,
      -1,    -1,   884,    -1,   886,    -1,    -1,    -1,   788,   891,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    -1,    22,    23,    -1,    -1,    -1,   819,
      -1,    -1,    -1,    37,    -1,   825,    -1,   740,    -1,   742,
      44,    45,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      -1,    49,    -1,   843,   757,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   767,    -1,    -1,    -1,   771,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,   792,
      -1,    -1,   795,    -1,    -1,    -1,    -1,   800,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,   129,    -1,    -1,    -1,    -1,
      -1,   834,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,   329,    -1,    -1,    -1,    -1,    -1,   155,    -1,   862,
      61,    62,    -1,    -1,    -1,   343,   170,    -1,   172,    -1,
     174,    -1,    -1,    -1,   178,   179,   180,   880,   182,    -1,
     883,    -1,   180,    -1,    -1,    61,    62,   890,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,   200,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     208,   209,   210,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,   227,
      -1,   235,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   159,    -1,
      -1,    -1,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,    -1,   280,    -1,   282,   283,
     278,    -1,   286,   287,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,   297,    -1,   299,   474,   475,   476,    -1,
     304,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,    -1,
     314,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    63,    -1,   338,    -1,    -1,    -1,   516,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,
     364,    -1,    -1,    -1,    -1,   363,   364,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   396,    -1,    -1,    -1,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,
      -1,   142,    -1,    -1,    -1,   593,    -1,   148,   149,   150,
     151,    -1,   420,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,   451,    -1,   453,    -1,    -1,    -1,    -1,
     464,    -1,   466,   467,    -1,   159,   160,    -1,   646,    -1,
     468,   469,    -1,    -1,   652,    -1,   654,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,    -1,   497,
      -1,   505,    -1,   501,   502,    -1,    -1,   505,    -1,    -1,
      -1,   515,    -1,    -1,   692,    93,    -1,   515,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     534,   535,    -1,    -1,   538,    -1,   534,   535,   542,   543,
      -1,    -1,   546,    -1,   542,   543,   550,   551,   546,    -1,
      -1,    -1,    -1,    -1,   558,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   745,    -1,    -1,
      -1,    -1,   570,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   769,    49,    -1,   772,    -1,   600,    -1,    -1,   777,
      -1,    -1,    -1,    61,    62,    -1,    -1,   605,    -1,    -1,
     788,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,   628,   629,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   633,    -1,   641,    -1,    -1,
      -1,   819,    -1,    -1,   642,    -1,    -1,   825,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,   843,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,   107,   108,   721,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,   753,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   791,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,   107,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,   107,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      92,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    90,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,   154,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    -1,    89,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
     142,     3,     4,     5,     6,     7,   148,   149,   150,   151,
      12,    -1,    -1,   155,   156,    -1,   158,    -1,   160,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   101,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,    -1,   158,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,    -1,   158,    -1,   160,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,    -1,
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
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,
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
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   142,    12,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,
     158,   159,    -1,    -1,    31,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
      26,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,    -1,   158,    -1,    -1,    -1,    31,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   118,    -1,    -1,    -1,
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
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,   118,    -1,    -1,
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
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,    -1,
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
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,     9,    10,    11,   155,   156,    -1,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   162,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   162,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   162,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   162,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   160,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     160,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    25,    -1,    27,    28,    29,    30,    31,    32,
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
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   159,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   159,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   159,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   159,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   125,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   125,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    11,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    25,    49,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49
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
     104,   106,   107,   108,   112,   113,   114,   116,   117,   118,
     119,   120,   121,   126,   127,   128,   129,   130,   131,   132,
     135,   136,   138,   142,   148,   149,   150,   151,   154,   155,
     156,   158,   160,   161,   163,   168,   169,   172,   175,   176,
     183,   184,   186,   187,   188,   190,   241,   242,   243,   246,
     247,   255,   258,   262,   263,   265,   266,   272,   273,   274,
     275,   276,   277,   278,   279,   284,   289,   291,   292,   293,
     294,   295,    73,   114,   148,   156,   243,   262,   262,   158,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   114,   148,   151,   158,   168,
     247,   265,   266,   274,   265,    31,   262,   287,   288,   262,
     148,   151,   168,   247,   249,   250,   274,   277,   278,   284,
     158,   253,   158,    26,    63,   238,   262,   175,   158,   158,
     158,   158,   158,   160,   262,   160,   262,    73,    73,   160,
     241,   262,   266,   161,   262,   151,   168,   170,   171,    75,
     163,   213,   214,   120,   120,    75,   215,   243,   158,   158,
     158,   158,   158,   158,   151,   161,   168,   168,   241,   262,
     266,   242,   262,   294,   173,   161,   151,   158,     8,   160,
      73,    73,   160,    31,   185,    63,   145,     9,    10,    11,
      25,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,   160,    61,    62,    13,    14,    15,    16,
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
     209,   210,   248,   164,   158,   158,   278,   262,    26,    65,
     266,   159,   158,   158,   164,   262,   158,   269,   270,   271,
      63,   161,   164,   162,   164,   164,   264,   264,   125,   159,
     251,    26,   175,   262,    26,   175,   203,   239,   262,   266,
      31,   195,   266,   256,    73,    26,   175,   198,    26,   161,
     200,   256,   256,   256,   259,   261,   158,   151,   168,   145,
     105,    73,   162,    13,   208,   182,   160,   266,   285,   286,
      13,   211,   162,   159,   159,    31,   241,   266,   256,   151,
     168,   193,   161,     8,   216,   208,   159,     8,    31,    75,
     211,   211,   262,   249,   211,   211,   162,   211,    63,    63,
     267,   280,   262,    31,   262,   124,   252,   173,   204,   159,
     173,   160,   125,   194,   266,   194,    13,   173,   160,   201,
     160,   201,   125,   164,     8,   260,   259,   168,    73,   158,
     256,   159,   159,   262,   159,   160,   264,   168,   216,   248,
     102,   107,   109,   110,   111,   112,   113,   114,   115,   162,
     217,   219,   232,   233,   234,   235,   237,   159,   107,   244,
     210,    75,    13,   159,   159,   254,   159,   159,   159,   280,
     280,   124,   268,   164,   162,   264,   281,   205,    68,    69,
     206,   160,    86,   239,   195,   159,   159,   256,    92,   201,
      95,    96,    97,   201,   162,   256,   256,   159,   248,   244,
     162,    73,   220,   248,    75,   236,   243,   235,     8,   160,
     161,   158,   161,    31,    75,    13,   256,   164,   164,   281,
      68,    69,   207,   158,   175,   160,   159,    26,   175,   197,
     197,   160,    95,   160,   262,    26,   160,   202,   162,   125,
      75,   161,    13,     8,   160,   161,   221,    13,     8,   160,
     218,    73,   173,    31,    75,   245,   173,    75,    13,   256,
     271,   158,    26,    70,   262,    26,   175,   196,   173,   160,
     202,   173,   256,   159,   173,   256,   248,    73,   222,   223,
     224,   225,   227,   228,   229,   248,   256,    75,   185,    13,
     162,    75,     8,   159,   162,    13,   256,   262,   173,   160,
     159,   173,    90,   173,   161,   162,   162,   224,   160,    93,
     152,   160,   145,    13,    73,   256,    31,    75,   256,   159,
     175,    88,   160,   173,   230,   235,   226,   248,    73,   256,
     158,    75,    26,   160,   162,    73,     8,   208,   173,   105,
     177,   179,   180,   248,   159,   158,   157,   178,   180,   160,
     161,   231,   248,   161,   173,    75,   173,   162,   159,   162,
     161,   173,   162
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, yyscanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, yyscanner, root); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void* yyscanner, xhpast::Node** root)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void* yyscanner;
    xhpast::Node** root;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yyscanner);
  YYUSE (root);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void* yyscanner, xhpast::Node** root)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yyscanner, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void* yyscanner;
    xhpast::Node** root;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, root);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, void* yyscanner, xhpast::Node** root)
#else
static void
yy_reduce_print (yyvsp, yyrule, yyscanner, root)
    YYSTYPE *yyvsp;
    int yyrule;
    void* yyscanner;
    xhpast::Node** root;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , yyscanner, root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, yyscanner, root); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void* yyscanner, xhpast::Node** root)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yyscanner, root)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    void* yyscanner;
    xhpast::Node** root;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yyscanner);
  YYUSE (root);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void* yyscanner, xhpast::Node** root)
#else
int
yyparse (yyscanner, root)
    void* yyscanner;
    xhpast::Node** root;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1787 of yacc.c  */
#line 197 "parser.y"
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 203 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 206 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_SYMBOL_NAME);
  }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 215 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 224 "parser.y"
    {
    (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 229 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_NAMESPACE, (yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    {
  NSPAN((yyvsp[(1) - (5)]), n_NAMESPACE, (yyvsp[(5) - (5)]));
  (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
  (yyvsp[(1) - (5)])->appendChild(NEXPAND((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 242 "parser.y"
    {
  NSPAN((yyvsp[(1) - (4)]), n_NAMESPACE, (yyvsp[(4) - (4)]));
  (yyvsp[(1) - (4)])->appendChild(NNEW(n_EMPTY));
  NMORE((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  NLMORE((yyvsp[(3) - (4)]), (yyvsp[(2) - (4)]));
  (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
  }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 250 "parser.y"
    {
  NSPAN((yyvsp[(1) - (3)]), n_USE, (yyvsp[(2) - (3)]));
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 256 "parser.y"
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
  NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 263 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 266 "parser.y"
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 273 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 278 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    NTYPE((yyvsp[(3) - (3)]), n_STRING);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 284 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 290 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
    NTYPE((yyvsp[(4) - (4)]), n_STRING);
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 300 "parser.y"
    {
    NMORE((yyval), (yyvsp[(5) - (5)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING))
        ->appendChild((yyvsp[(5) - (5)])));
  }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 307 "parser.y"
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[(4) - (4)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(2) - (4)]), n_STRING))
        ->appendChild((yyvsp[(4) - (4)])));
  }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 317 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 320 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 329 "parser.y"
    {
  (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
  NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 338 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 344 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 347 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 350 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLOSE_TAG);
  }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 356 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 359 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);

    (yyvsp[(1) - (7)]) = NTYPE((yyvsp[(1) - (7)]), n_IF);
    (yyvsp[(1) - (7)])->appendChild(NSPAN((yyvsp[(2) - (7)]), n_CONTROL_CONDITION, (yyvsp[(4) - (7)]))->appendChild((yyvsp[(3) - (7)])));
    (yyvsp[(1) - (7)])->appendChild((yyvsp[(5) - (7)]));

    (yyval)->appendChild((yyvsp[(1) - (7)]));
    (yyval)->appendChildren((yyvsp[(6) - (7)]));

    // Hacks: merge a list of if (x) { } else if (y) { } into a single condition
    // list instead of a condition tree.

    if ((yyvsp[(7) - (7)])->type == n_EMPTY) {
      // Ignore.
    } else if ((yyvsp[(7) - (7)])->type == n_ELSE) {
      xhpast::Node *stype = (yyvsp[(7) - (7)])->firstChild()->firstChild();
      if (stype && stype->type == n_CONDITION_LIST) {
        NTYPE(stype->firstChild(), n_ELSEIF);
        stype->firstChild()->l_tok = (yyvsp[(7) - (7)])->l_tok;
        (yyval)->appendChildren(stype);
      } else {
        (yyval)->appendChild((yyvsp[(7) - (7)]));
      }
    } else {
      (yyval)->appendChild((yyvsp[(7) - (7)]));
    }

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 389 "parser.y"
    {

    (yyval) = NNEW(n_CONDITION_LIST);
    NTYPE((yyvsp[(1) - (10)]), n_IF);
    (yyvsp[(1) - (10)])->appendChild(NSPAN((yyvsp[(2) - (10)]), n_CONTROL_CONDITION, (yyvsp[(4) - (10)]))->appendChild((yyvsp[(3) - (10)])));
    (yyvsp[(1) - (10)])->appendChild((yyvsp[(6) - (10)]));

    (yyval)->appendChild((yyvsp[(1) - (10)]));
    (yyval)->appendChildren((yyvsp[(7) - (10)]));
    (yyval)->appendChild((yyvsp[(8) - (10)]));
    NMORE((yyval), (yyvsp[(9) - (10)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[(10) - (10)]));
  }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 404 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_WHILE);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 411 "parser.y"
    {
    NTYPE((yyvsp[(1) - (7)]), n_DO_WHILE);
    (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
    (yyvsp[(1) - (7)])->appendChild(NSPAN((yyvsp[(4) - (7)]), n_CONTROL_CONDITION, (yyvsp[(6) - (7)]))->appendChild((yyvsp[(5) - (7)])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (7)]));
    NMORE((yyval), (yyvsp[(7) - (7)]));
  }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 419 "parser.y"
    {
    NTYPE((yyvsp[(1) - (9)]), n_FOR);

    NSPAN((yyvsp[(2) - (9)]), n_FOR_EXPRESSION, (yyvsp[(8) - (9)]))
      ->appendChild((yyvsp[(3) - (9)]))
      ->appendChild((yyvsp[(5) - (9)]))
      ->appendChild((yyvsp[(7) - (9)]));

    (yyvsp[(1) - (9)])->appendChild((yyvsp[(2) - (9)]));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(9) - (9)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (9)]));
  }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 432 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_SWITCH);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 439 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_BREAK);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 446 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_BREAK);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 453 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_CONTINUE);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 460 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_CONTINUE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 467 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_RETURN);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 474 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 481 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 488 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 493 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 498 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 503 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_INLINE_HTML);
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 507 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 511 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 515 "parser.y"
    {
    NMORE((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
    NLMORE((yyvsp[(3) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(3) - (5)]));
    NMORE((yyval), (yyvsp[(5) - (5)]));
  }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 521 "parser.y"
    {
    NTYPE((yyvsp[(1) - (8)]), n_FOREACH);
    NSPAN((yyvsp[(2) - (8)]), n_FOREACH_EXPRESSION, (yyvsp[(7) - (8)]));
    (yyvsp[(2) - (8)])->appendChild((yyvsp[(3) - (8)]));
    if ((yyvsp[(6) - (8)])->type == n_EMPTY) {
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(6) - (8)]));
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(5) - (8)]));
    } else {
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(5) - (8)]));
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(6) - (8)]));
    }
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(2) - (8)]));

    (yyvsp[(1) - (8)])->appendChild((yyvsp[(8) - (8)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (8)]));
  }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 538 "parser.y"
    {
    NTYPE((yyvsp[(1) - (8)]), n_FOREACH);
    NSPAN((yyvsp[(2) - (8)]), n_FOREACH_EXPRESSION, (yyvsp[(7) - (8)]));
    (yyvsp[(2) - (8)])->appendChild((yyvsp[(3) - (8)]));
    if ((yyvsp[(6) - (8)])->type == n_EMPTY) {
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(6) - (8)]));
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(5) - (8)]));
    } else {
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(5) - (8)]));
      (yyvsp[(2) - (8)])->appendChild((yyvsp[(6) - (8)]));
    }
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(2) - (8)]));
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(8) - (8)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (8)]));
  }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 554 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_DECLARE);
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 560 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[(1) - (1)]));
  }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 564 "parser.y"
    {
    NTYPE((yyvsp[(1) - (14)]), n_TRY);
    (yyvsp[(1) - (14)])->appendChild(NEXPAND((yyvsp[(2) - (14)]), (yyvsp[(3) - (14)]), (yyvsp[(4) - (14)])));

    NTYPE((yyvsp[(5) - (14)]), n_CATCH);
    (yyvsp[(5) - (14)])->appendChild((yyvsp[(7) - (14)]));
    (yyvsp[(5) - (14)])->appendChild(NTYPE((yyvsp[(8) - (14)]), n_VARIABLE));
    (yyvsp[(5) - (14)])->appendChild(NEXPAND((yyvsp[(10) - (14)]), (yyvsp[(11) - (14)]), (yyvsp[(12) - (14)])));

    (yyvsp[(1) - (14)])->appendChild(NNEW(n_CATCH_LIST)->appendChild((yyvsp[(5) - (14)]))->appendChildren((yyvsp[(13) - (14)])));
    (yyvsp[(1) - (14)])->appendChild((yyvsp[(14) - (14)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (14)]));
  }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 578 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_THROW);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));

  }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 586 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_GOTO);
  NTYPE((yyvsp[(2) - (3)]), n_STRING);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 598 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 604 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 607 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_FINALLY);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 617 "parser.y"
    {
    (yyval) = NNEW(n_CATCH_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 621 "parser.y"
    {
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 628 "parser.y"
    {
    NTYPE((yyvsp[(1) - (8)]), n_CATCH);
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(3) - (8)]));
    (yyvsp[(1) - (8)])->appendChild(NTYPE((yyvsp[(4) - (8)]), n_VARIABLE));
    (yyvsp[(1) - (8)])->appendChild(NEXPAND((yyvsp[(6) - (8)]), (yyvsp[(7) - (8)]), (yyvsp[(8) - (8)])));
    NMORE((yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
    (yyval) = (yyvsp[(1) - (8)]);
  }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 639 "parser.y"
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 643 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 662 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 665 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_REFERENCE);
  }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 671 "parser.y"
    {
    NSPAN((yyvsp[(1) - (9)]), n_FUNCTION_DECLARATION, (yyvsp[(9) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(2) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NTYPE((yyvsp[(3) - (9)]), n_STRING));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)])));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (9)]));
  }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 685 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (7)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (7)]), n_CLASS_NAME));
    (yyval)->appendChild((yyvsp[(3) - (7)]));
    (yyval)->appendChild((yyvsp[(4) - (7)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(5) - (7)]), (yyvsp[(6) - (7)]), (yyvsp[(7) - (7)])));
    NMORE((yyval), (yyvsp[(7) - (7)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 696 "parser.y"
    {
    (yyval) = NNEW(n_INTERFACE_DECLARATION);
    (yyval)->appendChild(NNEW(n_CLASS_ATTRIBUTES));
    NLMORE((yyval), (yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (6)]), n_CLASS_NAME));
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
    NMORE((yyval), (yyvsp[(6) - (6)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 711 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 715 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 722 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 729 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 736 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 739 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 749 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 752 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 760 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 763 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_IMPLEMENTS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 771 "parser.y"
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 774 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 780 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 783 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 790 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 799 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 808 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 817 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 825 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_STRING));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 831 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));
    (yyval) = (yyvsp[(1) - (5)]);
  }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 842 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 845 "parser.y"
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[(2) - (4)]), n_STATEMENT);
    (yyvsp[(1) - (4)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[(2) - (4)]));
    (yyval)->appendChildren((yyvsp[(3) - (4)]));
    NEXPAND((yyvsp[(1) - (4)]), (yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 855 "parser.y"
    {
    NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval) = (yyvsp[(2) - (4)]);
  }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 860 "parser.y"
    {
    NTYPE((yyvsp[(2) - (5)]), n_STATEMENT);
    (yyvsp[(1) - (5)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[(2) - (5)]));
    (yyval)->appendChildren((yyvsp[(3) - (5)]));
    NMORE((yyval), (yyvsp[(5) - (5)]));
    NLMORE((yyval), (yyvsp[(1) - (5)]));
  }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 872 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 875 "parser.y"
    {
    NTYPE((yyvsp[(2) - (5)]), n_CASE);
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
    (yyval) = (yyvsp[(1) - (5)]);
  }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 883 "parser.y"
    {
    NTYPE((yyvsp[(2) - (4)]), n_DEFAULT);
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(4) - (4)]));

    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 899 "parser.y"
    {
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 907 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 910 "parser.y"
    {
    NTYPE((yyvsp[(2) - (6)]), n_ELSEIF);
    (yyvsp[(2) - (6)])->appendChild(NSPAN((yyvsp[(3) - (6)]), n_CONTROL_CONDITION, (yyvsp[(5) - (6)]))->appendChild((yyvsp[(4) - (6)])));
    (yyvsp[(2) - (6)])->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyvsp[(2) - (6)]));
  }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 920 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 923 "parser.y"
    {
    NTYPE((yyvsp[(2) - (7)]), n_ELSEIF);
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(4) - (7)]));
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(7) - (7)]));

    (yyval) = (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
  }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 933 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 936 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_ELSE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 944 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 947 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ELSE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 956 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 962 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 970 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_VARIABLE_REFERENCE));
      (yyvsp[(2) - (3)])->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 979 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (5)]), n_VARIABLE_REFERENCE));
      (yyvsp[(2) - (5)])->appendChild(NTYPE((yyvsp[(3) - (5)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 988 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(4) - (4)]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 996 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1004 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (5)]), n_VARIABLE_REFERENCE));
      (yyvsp[(4) - (5)])->appendChild(NTYPE((yyvsp[(5) - (5)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1013 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (7)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (7)]), n_VARIABLE_REFERENCE));
      (yyvsp[(4) - (7)])->appendChild(NTYPE((yyvsp[(5) - (7)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(7) - (7)]));

    (yyval) = (yyvsp[(1) - (7)])->appendChild((yyval));
  }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1022 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (6)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1033 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1036 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1039 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_TYPE_NAME);
  }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1042 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_TYPE_NAME);
  }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1049 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1055 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 1058 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 1061 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (2)]));
  }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1066 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1069 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1072 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1078 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1082 "parser.y"
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1089 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1092 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1096 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (4)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
  }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1103 "parser.y"
    {
    NTYPE((yyvsp[(3) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1111 "parser.y"
    {
    NTYPE((yyvsp[(3) - (5)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1119 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1127 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1138 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1141 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1147 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChildren((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1155 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1159 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1162 "parser.y"
    {
    yyextra->old_expecting_xhp_class_statements = yyextra->expecting_xhp_class_statements;
    yyextra->expecting_xhp_class_statements = false;
  }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1165 "parser.y"
    {
    yyextra->expecting_xhp_class_statements = yyextra->old_expecting_xhp_class_statements;

    (yyval) = NNEW(n_METHOD_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (9)]));
    (yyval)->appendChild((yyvsp[(4) - (9)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (9)]), n_STRING));
    (yyval)->appendChild(NEXPAND((yyvsp[(6) - (9)]), (yyvsp[(7) - (9)]), (yyvsp[(8) - (9)])));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(9) - (9)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1181 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (3)]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[(2) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1189 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1192 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1198 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1201 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1207 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1210 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1216 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1220 "parser.y"
    {
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1227 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1230 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1236 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_INSTEADOF);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1244 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1248 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1255 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1259 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1265 "parser.y"
    {
    NTYPE((yyvsp[(2) - (3)]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), NTYPE((yyvsp[(3) - (3)]), n_STRING));
    (yyval) = (yyvsp[(2) - (3)]);
  }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1273 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (4)]), n_STRING));
  }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1279 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1288 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1291 "parser.y"
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1299 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1302 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1309 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1316 "parser.y"
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1319 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1326 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  }
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1330 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_STRING));
  }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1345 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1352 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1359 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1366 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1376 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));

    (yyval) = (yyvsp[(1) - (5)]);
  }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1385 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_STRING));
    (yyval)->appendChild((yyvsp[(4) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyval));

    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1397 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1400 "parser.y"
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1407 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1415 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1418 "parser.y"
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1425 "parser.y"
    {
    NTYPE((yyvsp[(1) - (6)]), n_LIST);
    (yyvsp[(1) - (6)])->appendChild(NEXPAND((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (6)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(6) - (6)]));
  }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1433 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1439 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_OPERATOR));

    NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (4)])->appendChild((yyvsp[(4) - (4)]));

    (yyval)->appendChild((yyvsp[(3) - (4)]));
  }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1449 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (6)]), n_OPERATOR));

    NTYPE((yyvsp[(4) - (6)]), n_NEW);
    (yyvsp[(4) - (6)])->appendChild((yyvsp[(5) - (6)]));
    (yyvsp[(4) - (6)])->appendChild((yyvsp[(6) - (6)]));

    NTYPE((yyvsp[(3) - (6)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (6)])->appendChild((yyvsp[(4) - (6)]));

    (yyval)->appendChild((yyvsp[(3) - (6)]));
  }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1463 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1468 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1474 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1480 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1486 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1492 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1498 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1504 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1510 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1516 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1522 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1528 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1534 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1539 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1544 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1549 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1554 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1560 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1566 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1572 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1578 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1584 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1590 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1596 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1602 "parser.y"
    {

    /* The concatenation operator generates n_CONCATENATION_LIST instead of
       n_BINARY_EXPRESSION because we tend to run into stack depth issues in a
       lot of real-world cases otherwise (e.g., in PHP and JSON decoders). */

    if ((yyvsp[(1) - (3)])->type == n_CONCATENATION_LIST && (yyvsp[(3) - (3)])->type == n_CONCATENATION_LIST) {
      (yyvsp[(1) - (3)])->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
      (yyvsp[(1) - (3)])->appendChildren((yyvsp[(3) - (3)]));
      (yyval) = (yyvsp[(1) - (3)]);
    } else if ((yyvsp[(1) - (3)])->type == n_CONCATENATION_LIST) {
      (yyvsp[(1) - (3)])->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
      (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
      (yyval) = (yyvsp[(1) - (3)]);
    } else if ((yyvsp[(3) - (3)])->type == n_CONCATENATION_LIST) {
      (yyval) = NNEW(n_CONCATENATION_LIST);
      (yyval)->appendChild((yyvsp[(1) - (3)]));
      (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
      (yyval)->appendChildren((yyvsp[(3) - (3)]));
    } else {
      (yyval) = NNEW(n_CONCATENATION_LIST);
      (yyval)->appendChild((yyvsp[(1) - (3)]));
      (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
      (yyval)->appendChild((yyvsp[(3) - (3)]));
    }
  }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 1628 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 1634 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 1640 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1646 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1652 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1658 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1664 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1670 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1675 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1680 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1685 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1690 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1696 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1702 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1708 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1714 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 1720 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 1726 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 1732 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 1738 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 1746 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));
  }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 1752 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 1759 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1764 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 1769 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1774 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1779 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1784 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1789 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 1794 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 1799 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 1804 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1811 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1816 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_YIELD);
    (yyvsp[(1) - (1)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (1)])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1822 "parser.y"
    {
    NSPAN((yyvsp[(1) - (9)]), n_FUNCTION_DECLARATION, (yyvsp[(9) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(2) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)])));
    (yyval)->appendChild((yyvsp[(6) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)])));

    (yyval) = (yyvsp[(1) - (9)]);
  }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1833 "parser.y"
    {
    NSPAN((yyvsp[(2) - (10)]), n_FUNCTION_DECLARATION, (yyvsp[(10) - (10)]));
    NLMORE((yyvsp[(2) - (10)]), (yyvsp[(1) - (10)]));

    (yyval) = NNEW(n_FUNCTION_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (10)]), n_STRING));
    (yyvsp[(2) - (10)])->appendChild((yyvsp[(1) - (10)]));

    (yyvsp[(2) - (10)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(2) - (10)])->appendChild((yyvsp[(3) - (10)]));
    (yyvsp[(2) - (10)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(2) - (10)])->appendChild(NEXPAND((yyvsp[(4) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(6) - (10)])));
    (yyvsp[(2) - (10)])->appendChild((yyvsp[(7) - (10)]));
    (yyvsp[(2) - (10)])->appendChild(NEXPAND((yyvsp[(8) - (10)]), (yyvsp[(9) - (10)]), (yyvsp[(10) - (10)])));

    (yyval) = (yyvsp[(2) - (10)]);
  }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1853 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_YIELD);
    (yyvsp[(2) - (2)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1859 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_YIELD);
    (yyvsp[(2) - (2)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1865 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_YIELD);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1871 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_YIELD);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1884 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1887 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[(1) - (4)])->appendChildren((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 1895 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
  }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 1898 "parser.y"
    {
    NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (4)])->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 1903 "parser.y"
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
  }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 1907 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
  }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1916 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1921 "parser.y"
    {
    NLMORE((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1927 "parser.y"
    {
    NLMORE((yyvsp[(2) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(2) - (5)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])));
  }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1933 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1941 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 1949 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1957 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1965 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1973 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1976 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1979 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1983 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 1990 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 1993 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  }
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 1997 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  }
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 2009 "parser.y"
    {
    (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    for (xhpast::node_list_t::iterator ii = (yyvsp[(4) - (4)])->children.begin(); ii != (yyvsp[(4) - (4)])->children.end(); ++ii) {
      (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS)->appendChild((yyval));
      (yyval)->appendChild(*ii);
    }
  }
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 2022 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 2025 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 2031 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 2037 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 2040 "parser.y"
    {
    NSPAN((yyvsp[(1) - (2)]), n_EMPTY, (yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 2044 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 2052 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 2055 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 2061 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  }
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 2064 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 2067 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_STRING_SCALAR);
  }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 2070 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 2073 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 2076 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 2079 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 2082 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 2085 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 2088 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 2091 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 2094 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_HEREDOC);
  }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 2102 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = (yyvsp[(3) - (3)]);
  }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 2106 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = (yyvsp[(2) - (2)]);
  }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 2110 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 2115 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 2120 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 2126 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 2136 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 2147 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
  }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 2150 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 2157 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 2160 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 2166 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 2173 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 2180 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 2187 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 2194 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 2221 "parser.y"
    {
    (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild((yyvsp[(3) - (5)]));

    if ((yyvsp[(4) - (5)])->type != n_EMPTY) {
      (yyval) = NNEW(n_METHOD_CALL)->appendChild((yyval));
      (yyval)->appendChild((yyvsp[(4) - (5)]));
    }

    for (xhpast::node_list_t::iterator ii = (yyvsp[(5) - (5)])->children.begin(); ii != (yyvsp[(5) - (5)])->children.end(); ++ii) {
      if ((*ii)->type == n_CALL_PARAMETER_LIST) {
        (yyval) = NNEW(n_METHOD_CALL)->appendChild((yyval));
        (yyval)->appendChild((*ii));
      } else {
        (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS)->appendChild((yyval));
        (yyval)->appendChild((*ii));
      }
    }
  }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 2245 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
  }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 2248 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 2254 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(2) - (3)]));
    if ((yyvsp[(3) - (3)])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[(3) - (3)]));
    }
  }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 2264 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 2270 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 2279 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 2287 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 2294 "parser.y"
    {
    xhpast::Node *last = (yyvsp[(1) - (2)]);
    NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      NMORE(last, (yyvsp[(2) - (2)]));
      last = last->firstChild();
    }
    last->appendChild((yyvsp[(2) - (2)]));

    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2309 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 2314 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 2326 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 2332 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2348 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2351 "parser.y"
    {
    xhpast::Node *last = (yyvsp[(1) - (2)]);
    NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      NMORE(last, (yyvsp[(2) - (2)]));
      last = last->firstChild();
    }
    last->appendChild((yyvsp[(2) - (2)]));

    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2367 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 2373 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 2383 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 2386 "parser.y"
    {
    NSPAN((yyvsp[(1) - (4)]), n_VARIABLE_EXPRESSION, (yyvsp[(4) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 2394 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 2397 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 2408 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 2414 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 2424 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_STRING);
    (yyval) = (yyvsp[(1) - (1)]);
  }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 2428 "parser.y"
    {
  (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2434 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE_VARIABLE);
  }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 2437 "parser.y"
    {
    (yyvsp[(2) - (2)]) = NTYPE((yyvsp[(2) - (2)]), n_VARIABLE_VARIABLE);

    xhpast::Node *last = (yyvsp[(1) - (2)]);
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      last = last->firstChild();
    }
    last->appendChild((yyvsp[(2) - (2)]));

    (yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2452 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2455 "parser.y"
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2463 "parser.y"
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 2468 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 2474 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 2477 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 2483 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2490 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 2497 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 2504 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 2511 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (6)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(6) - (6)])));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 2518 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 2525 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2532 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(2) - (2)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2542 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChildren((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2552 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2562 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 2565 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 2568 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 2578 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2581 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 2587 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 2591 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 2597 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 2602 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 2608 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 2614 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 2620 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (4)]), n_STRING_SCALAR));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 2629 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 2635 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2644 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_NEW);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2653 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 2658 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  }
    break;


/* Line 1787 of yacc.c  */
#line 7673 "parser.yacc.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 2665 "parser.y"


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}


/*
 * vim: tabstop=2 expandtab shiftwidth=2 softtabstop=2
 */
/* @generated */
