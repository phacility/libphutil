/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse xhpastparse
#define yylex   xhpastlex
#define yyerror xhpasterror
#define yylval  xhpastlval
#define yychar  xhpastchar
#define yydebug xhpastdebug
#define yynerrs xhpastnerrs


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
/* Tokens.  */
#define T_REQUIRE_ONCE 258
#define T_REQUIRE 259
#define T_EVAL 260
#define T_INCLUDE_ONCE 261
#define T_INCLUDE 262
#define T_LOGICAL_OR 263
#define T_LOGICAL_XOR 264
#define T_LOGICAL_AND 265
#define T_PRINT 266
#define T_SR_EQUAL 267
#define T_SL_EQUAL 268
#define T_XOR_EQUAL 269
#define T_OR_EQUAL 270
#define T_AND_EQUAL 271
#define T_MOD_EQUAL 272
#define T_CONCAT_EQUAL 273
#define T_DIV_EQUAL 274
#define T_MUL_EQUAL 275
#define T_MINUS_EQUAL 276
#define T_PLUS_EQUAL 277
#define T_BOOLEAN_OR 278
#define T_BOOLEAN_AND 279
#define T_IS_NOT_IDENTICAL 280
#define T_IS_IDENTICAL 281
#define T_IS_NOT_EQUAL 282
#define T_IS_EQUAL 283
#define T_IS_GREATER_OR_EQUAL 284
#define T_IS_SMALLER_OR_EQUAL 285
#define T_SR 286
#define T_SL 287
#define T_INSTANCEOF 288
#define T_UNSET_CAST 289
#define T_BOOL_CAST 290
#define T_OBJECT_CAST 291
#define T_ARRAY_CAST 292
#define T_BINARY_CAST 293
#define T_UNICODE_CAST 294
#define T_STRING_CAST 295
#define T_DOUBLE_CAST 296
#define T_INT_CAST 297
#define T_DEC 298
#define T_INC 299
#define T_CLONE 300
#define T_NEW 301
#define T_EXIT 302
#define T_IF 303
#define T_ELSEIF 304
#define T_ELSE 305
#define T_ENDIF 306
#define T_LNUMBER 307
#define T_DNUMBER 308
#define T_STRING 309
#define T_STRING_VARNAME 310
#define T_VARIABLE 311
#define T_NUM_STRING 312
#define T_INLINE_HTML 313
#define T_CHARACTER 314
#define T_BAD_CHARACTER 315
#define T_ENCAPSED_AND_WHITESPACE 316
#define T_CONSTANT_ENCAPSED_STRING 317
#define T_BACKTICKS_EXPR 318
#define T_ECHO 319
#define T_DO 320
#define T_WHILE 321
#define T_ENDWHILE 322
#define T_FOR 323
#define T_ENDFOR 324
#define T_FOREACH 325
#define T_ENDFOREACH 326
#define T_DECLARE 327
#define T_ENDDECLARE 328
#define T_AS 329
#define T_SWITCH 330
#define T_ENDSWITCH 331
#define T_CASE 332
#define T_DEFAULT 333
#define T_BREAK 334
#define T_CONTINUE 335
#define T_GOTO 336
#define T_FUNCTION 337
#define T_CONST 338
#define T_RETURN 339
#define T_TRY 340
#define T_CATCH 341
#define T_THROW 342
#define T_USE 343
#define T_GLOBAL 344
#define T_PUBLIC 345
#define T_PROTECTED 346
#define T_PRIVATE 347
#define T_FINAL 348
#define T_ABSTRACT 349
#define T_STATIC 350
#define T_VAR 351
#define T_UNSET 352
#define T_ISSET 353
#define T_EMPTY 354
#define T_HALT_COMPILER 355
#define T_CLASS 356
#define T_INTERFACE 357
#define T_EXTENDS 358
#define T_IMPLEMENTS 359
#define T_OBJECT_OPERATOR 360
#define T_DOUBLE_ARROW 361
#define T_LIST 362
#define T_ARRAY 363
#define T_CLASS_C 364
#define T_METHOD_C 365
#define T_FUNC_C 366
#define T_LINE 367
#define T_FILE 368
#define T_COMMENT 369
#define T_DOC_COMMENT 370
#define T_OPEN_TAG 371
#define T_OPEN_TAG_WITH_ECHO 372
#define T_OPEN_TAG_FAKE 373
#define T_CLOSE_TAG 374
#define T_WHITESPACE 375
#define T_START_HEREDOC 376
#define T_END_HEREDOC 377
#define T_HEREDOC 378
#define T_DOLLAR_OPEN_CURLY_BRACES 379
#define T_CURLY_OPEN 380
#define T_PAAMAYIM_NEKUDOTAYIM 381
#define T_BINARY_DOUBLE 382
#define T_BINARY_HEREDOC 383
#define T_NAMESPACE 384
#define T_NS_C 385
#define T_DIR 386
#define T_NS_SEPARATOR 387
#define T_INSTEADOF 388
#define T_CALLABLE 389
#define T_TRAIT 390
#define T_TRAIT_C 391
#define T_YIELD 392
#define T_FINALLY 393




/* Copy the first part of user declarations.  */
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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 460 "parser.yacc.cpp"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7892

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  419
/* YYNRULES -- Number of states.  */
#define YYNSTATES  863

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
     732,   736,   741,   748,   752,   755,   759,   763,   767,   771,
     775,   779,   783,   787,   791,   795,   799,   802,   805,   808,
     811,   815,   819,   823,   827,   831,   835,   839,   843,   847,
     851,   855,   859,   863,   867,   871,   875,   878,   881,   884,
     887,   891,   895,   899,   903,   907,   911,   915,   919,   923,
     927,   933,   938,   940,   943,   946,   949,   952,   955,   958,
     961,   964,   967,   972,   976,   978,   980,   983,   985,   989,
     999,  1010,  1013,  1016,  1021,  1026,  1028,  1029,  1034,  1038,
    1043,  1045,  1048,  1053,  1060,  1066,  1073,  1080,  1087,  1094,
    1099,  1101,  1103,  1107,  1110,  1112,  1116,  1119,  1121,  1123,
    1128,  1130,  1133,  1134,  1137,  1138,  1141,  1145,  1146,  1150,
    1152,  1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1176,  1178,  1182,  1185,  1188,  1191,  1196,  1200,
    1202,  1206,  1208,  1210,  1212,  1216,  1219,  1221,  1222,  1225,
    1226,  1228,  1234,  1238,  1242,  1244,  1246,  1248,  1250,  1252,
    1254,  1260,  1262,  1265,  1266,  1270,  1274,  1275,  1277,  1280,
    1284,  1288,  1290,  1292,  1294,  1296,  1299,  1301,  1306,  1311,
    1313,  1315,  1320,  1321,  1323,  1325,  1327,  1332,  1337,  1339,
    1341,  1345,  1347,  1350,  1354,  1356,  1358,  1363,  1364,  1365,
    1368,  1374,  1378,  1382,  1384,  1391,  1396,  1401,  1404,  1409,
    1414,  1417,  1420,  1425,  1428,  1431,  1433,  1437,  1441,  1445
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
       8,   262,    -1,   262,    -1,   126,   158,   282,   159,    13,
     262,    -1,   266,    13,   262,    -1,   266,    13,    31,   266,
      -1,   266,    13,    31,    65,   249,   254,    -1,    65,   249,
     254,    -1,    64,   262,    -1,   266,    24,   262,    -1,   266,
      23,   262,    -1,   266,    22,   262,    -1,   266,    21,   262,
      -1,   266,    20,   262,    -1,   266,    19,   262,    -1,   266,
      18,   262,    -1,   266,    17,   262,    -1,   266,    16,   262,
      -1,   266,    15,   262,    -1,   266,    14,   262,    -1,   265,
      62,    -1,    62,   265,    -1,   265,    61,    -1,    61,   265,
      -1,   262,    27,   262,    -1,   262,    28,   262,    -1,   262,
       9,   262,    -1,   262,    11,   262,    -1,   262,    10,   262,
      -1,   262,    29,   262,    -1,   262,    31,   262,    -1,   262,
      30,   262,    -1,   262,    44,   262,    -1,   262,    42,   262,
      -1,   262,    43,   262,    -1,   262,    45,   262,    -1,   262,
      46,   262,    -1,   262,    47,   262,    -1,   262,    41,   262,
      -1,   262,    40,   262,    -1,    42,   262,    -1,    43,   262,
      -1,    48,   262,    -1,    50,   262,    -1,   262,    33,   262,
      -1,   262,    32,   262,    -1,   262,    35,   262,    -1,   262,
      34,   262,    -1,   262,    36,   262,    -1,   262,    39,   262,
      -1,   262,    37,   262,    -1,   262,    38,   262,    -1,   262,
      49,   249,    -1,   158,   262,   159,    -1,   262,    25,   262,
      26,   262,    -1,   262,    25,    26,   262,    -1,   286,    -1,
      60,   262,    -1,    59,   262,    -1,    58,   262,    -1,    55,
     262,    -1,    54,   262,    -1,    53,   262,    -1,    52,   262,
      -1,    66,   253,    -1,    51,   262,    -1,   127,   158,   284,
     159,    -1,    63,   284,   164,    -1,    82,    -1,   258,    -1,
      12,   262,    -1,   156,    -1,   158,   242,   159,    -1,   243,
     185,   158,   208,   159,   244,   161,   173,   162,    -1,   114,
     243,   185,   158,   208,   159,   244,   161,   173,   162,    -1,
     156,   241,    -1,   156,   266,    -1,   156,   262,   125,   241,
      -1,   156,   262,   125,   266,    -1,   101,    -1,    -1,   107,
     158,   245,   159,    -1,   245,     8,    75,    -1,   245,     8,
      31,    75,    -1,    75,    -1,    31,    75,    -1,   168,   158,
     211,   159,    -1,   148,   151,   168,   158,   211,   159,    -1,
     151,   168,   158,   211,   159,    -1,   247,   145,    73,   158,
     211,   159,    -1,   272,   145,    73,   158,   211,   159,    -1,
     272,   145,   270,   158,   211,   159,    -1,   247,   145,   270,
     158,   211,   159,    -1,   270,   158,   211,   159,    -1,   114,
      -1,   168,    -1,   148,   151,   168,    -1,   151,   168,    -1,
     168,    -1,   148,   151,   168,    -1,   151,   168,    -1,   247,
      -1,   250,    -1,   274,   124,   278,   251,    -1,   274,    -1,
     251,   252,    -1,    -1,   124,   278,    -1,    -1,   158,   159,
      -1,   158,   262,   159,    -1,    -1,   158,   211,   159,    -1,
      71,    -1,    72,    -1,    81,    -1,   131,    -1,   132,    -1,
     150,    -1,   128,    -1,   129,    -1,   155,    -1,   130,    -1,
     149,    -1,   142,    -1,   255,    -1,   168,    -1,   148,   151,
     168,    -1,   151,   168,    -1,    42,   256,    -1,    43,   256,
      -1,   127,   158,   259,   159,    -1,    63,   259,   164,    -1,
     257,    -1,   247,   145,    73,    -1,    74,    -1,   288,    -1,
     168,    -1,   148,   151,   168,    -1,   151,   168,    -1,   255,
      -1,    -1,   261,   260,    -1,    -1,     8,    -1,   261,     8,
     256,   125,   256,    -1,   261,     8,   256,    -1,   256,   125,
     256,    -1,   256,    -1,   263,    -1,   241,    -1,   266,    -1,
     266,    -1,   266,    -1,   273,   124,   278,   269,   267,    -1,
     273,    -1,   267,   268,    -1,    -1,   124,   278,   269,    -1,
     158,   211,   159,    -1,    -1,   275,    -1,   281,   275,    -1,
     247,   145,   270,    -1,   272,   145,   270,    -1,   275,    -1,
     274,    -1,   246,    -1,   275,    -1,   281,   275,    -1,   271,
      -1,   275,    63,   277,   164,    -1,   275,   161,   262,   162,
      -1,   276,    -1,    75,    -1,   163,   161,   262,   162,    -1,
      -1,   262,    -1,   279,    -1,   270,    -1,   279,    63,   277,
     164,    -1,   279,   161,   262,   162,    -1,   280,    -1,    73,
      -1,   161,   262,   162,    -1,   163,    -1,   281,   163,    -1,
     282,     8,   283,    -1,   283,    -1,   266,    -1,   126,   158,
     282,   159,    -1,    -1,    -1,   285,   260,    -1,   285,     8,
     262,   125,   262,    -1,   285,     8,   262,    -1,   262,   125,
     262,    -1,   262,    -1,   285,     8,   262,   125,    31,   264,
      -1,   285,     8,    31,   264,    -1,   262,   125,    31,   264,
      -1,    31,   264,    -1,   117,   158,   287,   159,    -1,   118,
     158,   266,   159,    -1,     7,   262,    -1,     6,   262,    -1,
       5,   158,   262,   159,    -1,     4,   262,    -1,     3,   262,
      -1,   266,    -1,   287,     8,   266,    -1,   247,   145,    73,
      -1,   272,   145,    73,    -1,   262,    63,   277,   164,    -1
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
    1433,  1439,  1449,  1463,  1469,  1474,  1480,  1486,  1492,  1498,
    1504,  1510,  1516,  1522,  1528,  1534,  1540,  1545,  1550,  1555,
    1560,  1566,  1572,  1578,  1584,  1590,  1596,  1602,  1608,  1634,
    1640,  1646,  1652,  1658,  1664,  1670,  1676,  1681,  1686,  1691,
    1696,  1702,  1708,  1714,  1720,  1726,  1732,  1738,  1744,  1750,
    1755,  1761,  1767,  1768,  1773,  1778,  1783,  1788,  1793,  1798,
    1803,  1808,  1813,  1819,  1825,  1829,  1830,  1835,  1841,  1844,
    1855,  1875,  1881,  1887,  1893,  1902,  1906,  1909,  1917,  1920,
    1925,  1929,  1938,  1943,  1949,  1955,  1963,  1971,  1979,  1987,
    1995,  1998,  2001,  2005,  2012,  2015,  2019,  2026,  2027,  2031,
    2040,  2044,  2047,  2053,  2059,  2062,  2066,  2074,  2077,  2083,
    2086,  2089,  2092,  2095,  2098,  2101,  2104,  2107,  2110,  2113,
    2116,  2122,  2123,  2124,  2128,  2132,  2137,  2142,  2148,  2154,
    2158,  2166,  2167,  2168,  2169,  2172,  2175,  2179,  2182,  2188,
    2191,  2195,  2202,  2209,  2216,  2226,  2227,  2231,  2235,  2239,
    2243,  2263,  2267,  2270,  2276,  2286,  2289,  2295,  2296,  2311,
    2316,  2324,  2328,  2329,  2333,  2334,  2346,  2350,  2356,  2362,
    2366,  2369,  2377,  2380,  2386,  2387,  2391,  2397,  2403,  2407,
    2411,  2417,  2420,  2435,  2438,  2445,  2446,  2451,  2457,  2460,
    2466,  2473,  2480,  2487,  2494,  2501,  2508,  2515,  2525,  2535,
    2545,  2548,  2551,  2561,  2564,  2570,  2574,  2580,  2585,  2598
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "class_statement_list", "class_statement", "@1", "trait_use_statement",
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
  "method_or_not", "variable_without_objects", "static_member",
  "variable_class_name", "base_variable_with_function_calls",
  "base_variable", "reference_variable", "compound_variable", "dim_offset",
  "object_property", "object_dim_list", "variable_name",
  "simple_indirect_reference", "assignment_list",
  "assignment_list_element", "array_pair_list",
  "non_empty_array_pair_list", "internal_functions_in_yacc",
  "isset_variables", "class_constant", 0
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
     241,   242,   242,   242,   242,   243,   244,   244,   245,   245,
     245,   245,   246,   246,   246,   246,   246,   246,   246,   246,
     247,   247,   247,   247,   248,   248,   248,   249,   249,   250,
     250,   251,   251,   252,   253,   253,   253,   254,   254,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     257,   258,   258,   258,   258,   258,   258,   259,   259,   260,
     260,   261,   261,   261,   261,   262,   262,   263,   264,   265,
     266,   266,   267,   267,   268,   269,   269,   270,   270,   271,
     271,   272,   273,   273,   274,   274,   274,   275,   275,   275,
     276,   276,   277,   277,   278,   278,   279,   279,   279,   280,
     280,   281,   281,   282,   282,   283,   283,   283,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   287,   287,   288,   288,   241
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
       3,     4,     6,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     3,     1,     1,     2,     1,     3,     9,
      10,     2,     2,     4,     4,     1,     0,     4,     3,     4,
       1,     2,     4,     6,     5,     6,     6,     6,     6,     4,
       1,     1,     3,     2,     1,     3,     2,     1,     1,     4,
       1,     2,     0,     2,     0,     2,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     4,     3,     1,
       3,     1,     1,     1,     3,     2,     1,     0,     2,     0,
       1,     5,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     1,     2,     0,     3,     3,     0,     1,     2,     3,
       3,     1,     1,     1,     1,     2,     1,     4,     4,     1,
       1,     4,     0,     1,     1,     1,     4,     4,     1,     1,
       3,     1,     2,     3,     1,     1,     4,     0,     0,     2,
       5,     3,     3,     1,     6,     4,     4,     2,     4,     4,
       2,     2,     4,     2,     2,     1,     3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,     0,     0,   314,     0,   319,
     320,     5,   341,   380,    52,   321,   274,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,     0,     0,
       0,     0,     0,     0,     0,     0,   300,     0,     0,     0,
       0,    80,    86,     0,     0,   325,   326,   328,   322,   323,
      32,    33,    34,   330,     0,   329,   324,     0,    83,   327,
     277,     0,    59,    25,   391,   343,     3,     0,     7,    30,
       8,     9,    73,    74,     0,     0,   356,     0,    75,   373,
       0,   346,   275,     0,   355,     0,   357,     0,   376,     0,
     361,   372,   374,   379,     0,   262,   342,     5,   300,     0,
     277,    75,   414,   413,     0,   411,   410,   276,   246,   247,
     248,   249,   271,   269,   268,   267,   266,   265,   264,   263,
     300,     0,     0,   301,     0,   229,   359,     0,   227,     0,
     403,     0,   349,   214,     0,     0,   301,   307,   317,   308,
       0,   310,   374,     0,     0,   270,     0,    31,     0,   204,
       0,     0,   205,     0,     0,     0,    42,     0,    44,     0,
       0,     0,    46,   356,     0,   357,    25,     0,     0,    18,
       0,    17,   148,     0,     0,   147,    82,    81,   153,     0,
      75,     0,     0,     0,     0,   397,   398,     0,     4,     0,
     345,   356,     0,   357,     0,     0,     0,     0,     0,   139,
       0,    15,    84,    87,    54,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,    53,   228,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,     0,     0,   382,     0,   392,   375,     0,     0,     0,
     303,     0,     0,   407,   358,     0,   273,   350,   399,     0,
     303,     0,   139,   213,     0,     0,   375,   315,     0,     0,
       0,    51,     0,     0,     0,   206,   208,   356,   357,     0,
       0,     0,    43,    45,    62,     0,    47,    48,     0,    61,
      20,     0,     0,    14,     0,   149,   357,     0,    49,     0,
       0,    50,     0,     0,    70,    72,   415,     0,     0,     0,
       0,   395,     0,   394,     0,   344,     0,    11,     4,   139,
       0,   278,   259,     0,    35,    24,    26,    27,    28,     0,
       6,     0,     0,   138,   356,   357,     0,     0,    89,     0,
       0,     0,   134,   417,   369,   367,     0,   232,   234,   233,
       0,     0,   230,   231,   235,   237,   236,   251,   250,   253,
     252,   254,   256,   257,   255,   245,   244,   239,   240,   238,
     241,   242,   243,   258,   383,     0,     0,   210,   225,   224,
     223,   222,   221,   220,   219,   218,   217,   216,   215,     0,
     418,   370,   389,     0,   385,   366,   384,   388,     0,     0,
     412,   302,     0,     0,     0,   402,     0,   401,   302,   369,
       0,   370,   312,   316,     0,   203,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
       0,     0,   332,     0,   331,    23,   339,     0,     0,    19,
      16,     0,   146,   154,   151,   134,     0,     0,     0,   408,
     409,    10,   397,   397,     0,   272,   139,    13,     0,     0,
     356,   357,     0,   381,   142,   292,     0,     0,     0,     0,
     304,    85,     0,     0,    88,    91,   156,   134,   136,   137,
       0,   124,     0,   135,   139,   139,   368,   261,     0,   419,
       0,   211,   299,   139,   139,     0,   139,   363,   382,     0,
     377,   378,   406,   405,     0,   318,   309,    25,   116,     0,
      25,   114,    38,     0,   207,    93,     0,    93,    95,   103,
       0,    25,   101,    58,   109,   109,    41,   335,   336,   354,
       0,   349,   347,     0,   334,     0,     0,    21,   150,     0,
       0,    71,    55,   416,     0,   393,     0,     0,    12,   294,
       0,     0,   356,   357,    22,     0,   306,    90,   156,     0,
     187,     0,   286,   134,     0,   126,     0,     0,   260,   317,
       0,     0,   390,     0,   360,     0,     0,     0,   400,     0,
     311,   118,   120,     0,     0,   205,     0,     0,    96,     0,
       0,     0,   109,     0,   109,     0,     0,   338,   350,   348,
       0,   333,   340,     0,   152,   286,   396,   209,   293,    29,
     145,   305,   187,    92,     0,     0,   191,   192,   193,   196,
     195,   194,   186,    79,   155,   159,     0,     0,   185,   189,
       0,     0,     0,     0,     0,   127,     0,   295,   298,   212,
     296,   297,   365,     0,   362,   386,   387,   404,   313,   122,
       0,     0,    36,    39,     0,     0,    94,     0,     0,   104,
       0,     0,     0,     0,     0,     0,   105,   353,   352,   337,
       0,     0,    78,     0,     0,   163,   199,     0,   160,   190,
       0,   158,    25,     0,    25,     0,   130,     0,   129,   366,
       0,     0,     0,     0,   121,   115,     0,    25,    99,    57,
      56,   102,     0,   107,     0,   112,   113,    25,   106,     0,
       0,    25,     0,     0,   165,   167,   162,     0,     0,   157,
      75,     0,     0,     0,   290,     0,     0,   131,     0,   128,
     364,     0,    25,     0,     0,    25,    97,    40,     0,   108,
      25,   111,   351,     0,     0,   202,   164,     5,     0,   168,
     169,     0,     0,   177,     0,     0,   200,   197,     0,     0,
      77,   291,     0,   287,   279,     0,   133,     0,   123,    37,
       0,     0,     0,   110,    25,   280,   166,   170,   171,   181,
       0,   172,     0,     0,     0,   201,     0,   288,   132,     0,
     117,     0,   100,     0,     0,   180,   173,   174,   178,   198,
     134,   289,    25,    98,    64,   179,     0,     0,   119,     0,
      65,    63,    67,   175,     0,     0,     0,    60,    68,   183,
      25,   161,     0,    25,     0,     0,     0,   184,     0,    66,
      25,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    85,    86,   190,   191,    87,   216,   355,
     356,    89,   840,   847,   841,   842,   333,   334,   357,   358,
     226,    92,    93,    94,   368,    95,   370,   503,   504,   617,
     547,   767,   729,   553,   310,   556,   623,   737,   542,   612,
     679,   682,   722,   510,   511,   512,   362,   363,   194,   195,
     199,   590,   654,   750,   655,   704,   746,   778,   779,   780,
     781,   826,   782,   783,   784,   824,   851,   656,   657,   658,
     659,   707,   660,   168,   304,   305,    96,    97,   121,   663,
     755,    99,   100,   513,   158,   159,   536,   610,   165,   293,
     101,   559,   466,   102,   560,   288,   561,   103,   104,   283,
     105,   106,   604,   674,   527,   107,   108,   109,   110,   111,
     112,   113,   405,   425,   426,   427,   114,   342,   343,   151,
     152,   115,   337,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -632
static const yytype_int16 yypact[] =
{
    -632,    53,  1771,  -632,  6283,  6283,   -65,  6283,  6283,  6283,
    6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,
    6283,  6283,   463,   463,  4711,  6283,   499,   -63,   -41,  -632,
    -632,   124,  -632,  -632,  -632,  -632,  -632,  6283,  4571,   -38,
      32,    63,    86,    92,  4842,  4973,   129,  -632,   156,  5104,
      91,  6283,    10,   -35,   138,   165,    -7,   118,   135,   137,
     144,  -632,  -632,   152,   157,  -632,  -632,  -632,  -632,  -632,
    -632,  -632,  -632,  -632,    -6,  -632,  -632,   248,  -632,  -632,
    6283,  6414,  -632,  -632,   167,    67,  -632,    14,  -632,  -632,
    -632,  -632,  -632,  -632,   272,   274,  -632,   188,   319,  -632,
     207,  -632,  -632,  6833,  -632,    29,  1226,   195,  -632,   210,
     234,  -632,   -26,  -632,   -30,  -632,  -632,  -632,   260,   216,
    -632,   319,  7644,  7644,  6283,  7644,  7644,  1617,   311,   311,
      24,   311,   311,   311,   311,   311,   311,   311,   311,   311,
    -632,   222,   248,   -88,   231,  -632,  -632,   232,  -632,   463,
    7408,   214,   371,  -632,   229,   248,   239,   237,   233,  -632,
     247,   269,   -27,   -30,  5235,  -632,  6283,  -632,    16,  7644,
     313,  6283,  6283,  6283,   327,  6283,  -632,  6875,  -632,  6916,
     241,   402,  -632,   257,  7644,   390,  -632,  6967,   248,    -4,
      20,  -632,  -632,   407,    21,  -632,  -632,  -632,   406,    22,
     319,   463,   463,   463,   261,   322,  4711,   248,  -632,   158,
     117,   -81,  7449,   985,   262,  7009,  1911,  6283,   349,  5366,
     364,  -632,   320,   324,  -632,  -632,   -16,    -9,  6283,  6283,
    6283,  5497,  6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,
    6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,
    6283,  6283,  6283,   499,  6283,  -632,  -632,  -632,  5628,  6283,
    6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,  6283,
    5366,     2,     1,  6283,  6283,   167,   -31,   283,  7050,   248,
     -36,    48,    68,  -632,  -632,  5759,  -632,  5890,  -632,   248,
     239,   -15,  5366,  -632,   -15,     1,   -32,  -632,  7101,  7142,
    6283,  -632,   291,  7183,   290,   447,  7644,   363,   931,   446,
      27,  7234,  -632,  -632,  -632,  7515,  -632,  -632,  2051,  -632,
      56,   389,    10,  -632,  6283,  -632,  -632,   -35,  -632,  7515,
     391,  -632,   309,    38,  -632,  -632,  -632,    40,   312,   308,
     314,  -632,    41,  -632,   315,   136,  1470,  -632,  -632,  5366,
    6283,  -632,  -632,   318,  -632,  -632,  -632,  -632,  -632,  6557,
    -632,   463,   331,   469,    42,    90,   478,     9,   369,     9,
     332,   337,    71,   340,   341,   -32,   -30,  7684,  7721,  1617,
    6283,  7572,  7794,  7829,  4764,  4895,  5026,  5157,  5157,  5157,
    5157,  1375,  1375,  1375,  1375,   382,   382,   323,   323,   323,
      24,    24,    24,  -632,  7644,   336,   172,  1617,  1617,  1617,
    1617,  1617,  1617,  1617,  1617,  1617,  1617,  1617,  1617,   347,
     351,   352,  -632,  6283,  -632,   360,   -22,  -632,   355,  6598,
    -632,   115,   340,   351,   463,  7644,   463,  7507,   239,  -632,
     365,  -632,  -632,  -632,  3871,  7644,  6283,  4011,  6283,  6283,
     463,    65,  7515,   449,  4151,    -3,  7515,  7515,  7515,   368,
     372,   248,    72,   384,  -632,  -632,  -632,   422,   457,  -632,
    -632,  6639,  -632,  -632,   520,    71,   463,   375,   463,  -632,
    -632,  -632,   322,   322,   524,  -632,  5366,  -632,  1631,   380,
      12,  1176,   381,  -632,  -632,  -632,  6021,  7515,   395,   248,
     239,  -632,     9,   387,   533,  -632,  -632,    71,  -632,  -632,
     393,   545,    11,  -632,  5366,  5366,   -32,  7758,  6283,  -632,
     499,  -632,  -632,  5366,  5366,  6695,  5366,  -632,  6283,  6283,
    -632,  -632,  -632,  -632,  6152,  -632,   430,  -632,  -632,  7275,
    -632,  -632,  -632,   396,  7644,   434,   463,   434,  -632,  -632,
     547,  -632,  -632,  -632,   404,   405,  -632,  -632,  -632,   437,
     409,   558,  7515,   248,    75,   496,   418,  -632,  -632,  7515,
     419,  -632,  -632,  -632,    44,  -632,  6283,   420,  -632,  -632,
     421,   463,    47,   696,  -632,   248,   239,   533,  -632,     9,
     227,   424,   473,   100,   509,   573,   428,   432,  7758,   233,
     435,   436,  -632,   442,   472,   429,  6736,   463,  7644,     1,
    -632,  3731,   238,   443,  2191,  6283,    65,   445,  -632,   448,
    7515,  2331,  -632,   193,  -632,   146,  7515,  -632,  7515,  -632,
     458,    87,  -632,     9,  -632,   473,  -632,  1617,  -632,  -632,
    -632,   239,   583,  -632,   548,     9,  -632,  -632,  -632,  -632,
    -632,  -632,  -632,  -632,  -632,  -632,   530,   260,   403,  -632,
      31,   459,   464,   462,    61,   593,  7515,  -632,  -632,  -632,
    -632,  -632,  -632,     1,  -632,  -632,  -632,  -632,  -632,   256,
     467,  4571,  -632,  -632,   468,   470,  -632,  4291,  4291,  -632,
     471,   217,   475,  6283,    -1,   160,  -632,  -632,   511,  -632,
     562,   488,  -632,   638,     7,  -632,   640,    36,  -632,  -632,
     581,  -632,  -632,    94,  -632,   582,   646,  7515,  -632,   360,
     505,   641,   596,  6283,  -632,  -632,  4431,  -632,  -632,  -632,
    -632,  -632,   508,  -632,  6777,  -632,  -632,  -632,  -632,  7515,
     510,  -632,  7515,     9,  -632,    15,  -632,  7515,   597,  -632,
     319,   658,  2471,   599,  -632,    50,  2611,   662,  7515,  -632,
    -632,  6283,  -632,   516,  7316,  -632,  -632,  -632,  2751,  -632,
    -632,  3731,  -632,   517,  2891,  -632,  -632,   584,   521,    15,
    -632,   522,   591,   534,   529,   546,  -632,   687,   628,  7515,
    -632,  -632,   164,  -632,  -632,  7515,  -632,  7367,  3731,  -632,
    4571,  3031,   543,  3731,  -632,  -632,  -632,  -632,  -632,   532,
       9,  -632,   632,  7515,   549,  -632,   631,  -632,  -632,   682,
    -632,   563,  -632,  3171,   649,   657,   723,  -632,  -632,  -632,
      71,  -632,  -632,  -632,   627,  -632,     9,   574,  3731,   576,
     578,   627,  -632,  -632,   166,     9,   577,  -632,  -632,  -632,
    -632,  -632,   664,  -632,  3311,   588,  3451,  -632,   580,  -632,
    -632,  3591,  -632
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -632,  -632,  -192,   -18,  -632,  -632,   415,  -632,  -180,  -632,
       0,  -632,  -632,  -632,  -632,   -99,  -632,   267,    17,    19,
    -120,  -632,  -632,  -632,  -632,  -632,  -632,  -632,   246,   202,
     139,  -632,    64,  -632,  -632,  -632,  -522,    25,  -632,  -632,
    -632,  -632,  -632,  -464,  -632,   163,  -223,  -632,  -632,   426,
    -632,   174,  -632,  -632,  -632,  -632,  -632,  -632,  -632,   -11,
    -632,  -632,  -632,  -632,  -632,  -632,  -632,  -632,  -632,  -632,
    -631,  -632,  -632,  -632,  -438,  -632,   250,   679,    -2,   132,
    -632,  -632,   182,  -349,  -240,  -632,  -632,  -632,  -632,   171,
    -264,   706,  -632,  -632,   213,   218,  -632,   856,   585,  -335,
     310,   863,  -632,  -632,    62,  -210,  -632,   781,  -632,   -19,
     -17,  -632,  -261,  -292,  -632,  -632,   -12,   298,   299,   579,
    -632,  -632,  -632,  -632
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -372
static const yytype_int16 yytable[] =
{
      98,   277,    88,   442,   143,   143,   318,   161,   156,   162,
     543,   570,   428,   403,   163,   743,   346,   374,   501,    90,
     505,    91,   220,   554,   300,   735,   494,   709,   322,   327,
     330,   273,   273,   625,   189,   453,   273,   273,   170,   710,
     192,   528,   594,   591,   748,    33,   476,   419,   478,   483,
    -140,   464,   483,     3,   200,  -143,   209,   371,   792,   210,
      33,   421,   424,   218,   373,   464,    33,   117,   198,   440,
     219,   374,   421,   253,   422,   420,    33,    33,  -281,  -281,
     332,   439,   117,   117,   441,   424,   595,   254,   777,   321,
     256,   257,   715,   124,    47,   164,   546,   276,  -141,   532,
     691,   533,   695,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   218,   200,   166,  -371,  -371,
     171,   432,   349,    33,   280,   753,   489,  -368,   193,   274,
     274,   143,  -367,   275,   274,   274,   716,   290,   117,   529,
      33,   433,   372,    33,   117,   207,   296,   218,    84,   468,
     167,  -359,  -359,   505,    84,   208,   488,   498,   555,   736,
     499,   188,   423,   498,    84,    84,   499,   744,   745,   754,
     320,  -283,  -283,   117,   221,   143,   301,   685,   825,   140,
     323,   328,   331,   143,   143,   143,   454,   143,   464,   345,
     172,   711,   464,   464,   464,   816,   749,   477,   508,   479,
     484,  -140,   180,   636,   144,   144,  -143,   218,   157,   793,
     375,    84,  -301,   141,    98,   376,   142,  -301,   218,   498,
    -303,   173,   499,   218,   509,   219,   218,   508,    84,   181,
    -125,    84,  -302,   464,   161,   156,   162,   520,   218,   817,
     643,   163,   693,   694,   174,   117,   640,    33,   498,  -141,
     175,   499,   186,   509,   375,   375,   693,   694,   196,   376,
     376,   431,  -303,   577,   375,   375,   218,   605,   218,   376,
     376,   438,   677,   486,   375,   349,   201,   375,   375,   376,
     599,  -302,   376,   376,   700,   197,   140,   218,   692,   693,
     694,   596,   597,   202,   486,   203,   705,   462,   464,   183,
     600,   601,   204,   603,   189,   464,   680,   681,   696,   218,
     205,   462,   732,   693,   694,   206,    98,   678,   347,   348,
     141,   117,   738,   142,   720,   721,   849,   850,   217,   644,
     211,   144,   145,   148,   645,    84,   646,   647,   648,   649,
     650,   651,   652,   143,    98,   222,    88,   223,   224,   500,
     225,   500,   227,   270,   500,   271,   464,   611,   272,   516,
     614,    47,   464,    90,   464,    91,   837,   207,   250,   251,
     252,   621,   253,   279,   254,   144,   281,   282,   286,   287,
     289,   719,   291,   144,   144,   144,   254,   144,   143,   653,
     218,   292,   294,   295,   776,   117,   785,    33,   302,   424,
     309,   314,   464,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   315,   143,   316,   143,   329,
     339,   351,   360,   307,   247,   248,   249,   250,   251,   252,
     785,   253,   143,   143,   462,   157,   140,   366,   462,   462,
     462,   372,   367,   564,   538,   254,   369,   541,   340,   446,
     448,  -359,  -359,   464,   552,   449,   450,   500,   143,   452,
     143,   827,   469,   424,   143,   143,   474,   475,   481,   364,
     141,   480,   482,   142,   485,   464,   492,   496,   464,   462,
     117,   586,    33,   464,   500,    84,    98,   843,    88,   500,
     495,   497,   502,   506,   464,   507,   852,   463,   514,   515,
     519,   161,   156,   162,  -188,    90,   522,    91,   163,   523,
     524,   463,   646,   647,   648,   649,   650,   651,   526,   530,
     364,   140,   550,   563,   535,   464,   562,   566,   143,   565,
     567,   464,   752,   569,   756,   572,   117,   576,    33,   579,
     580,   589,   364,   144,   462,   631,   585,   768,   588,   464,
     317,   462,   592,   593,   609,   141,   615,   771,   142,   616,
     620,   774,   626,   143,   622,   624,   628,   641,   324,   632,
      84,   500,   117,   627,    33,   500,   633,   140,   635,   638,
     662,   639,   798,   661,   665,   801,   666,   667,   144,   143,
     803,   668,   375,   675,   670,   671,   673,   376,   143,   364,
     490,   672,   462,   683,   687,   706,   717,   688,   462,    98,
     462,   141,    98,   140,   142,   500,   144,   699,   144,    98,
     712,   703,   713,   714,   823,   723,    84,   500,   725,   726,
     788,   731,   144,   144,   463,   733,   739,   740,   463,   463,
     463,   646,   647,   648,   649,   650,   651,   154,   462,   741,
     155,   742,   838,   747,   751,   708,   375,   757,   144,   758,
     144,   376,    84,   761,   144,   144,   763,   762,   769,   773,
     854,   789,   787,   856,   791,   795,   799,  -176,   804,   463,
     861,   724,   808,   806,   809,   644,   810,   728,   728,   811,
     645,   812,   646,   647,   648,   649,   650,   651,   652,   462,
     813,   814,   157,   822,  -144,   828,   831,   830,   832,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   462,   835,   833,   462,   500,   766,   500,   144,   462,
    -182,   836,   839,   844,   845,   846,   364,   470,   853,   855,
     462,   860,   848,   571,   463,   702,   582,   858,   587,   619,
      98,   463,   730,   472,    98,   686,   664,  -359,  -359,   770,
     214,   500,   642,   144,   364,   364,    98,   701,   807,    98,
     669,   462,    98,   364,   364,   630,   364,   462,   325,   629,
     574,   760,   575,     0,     0,   344,     0,     0,     0,   144,
       0,     0,   500,     0,     0,   462,    98,     0,   144,    98,
     820,    98,   463,   147,   147,     0,     0,   160,   463,     0,
     463,     0,   500,     0,     0,     0,     0,     0,   500,     0,
       0,    98,     0,     0,     0,     0,     0,   500,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,     0,    98,     0,    98,  -144,     0,     0,     0,    98,
     122,   123,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
     150,   153,     0,     0,     0,   146,   146,     0,     0,     0,
       0,     0,     0,   169,     0,     0,     0,     0,     0,   463,
     177,   179,     0,     0,     0,   184,     0,   187,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,     0,     0,
       0,   463,     0,     0,   463,     0,     0,     0,     0,   463,
     147,     0,     0,     0,     0,     0,   212,   215,     0,     0,
     463,     0,     0,   213,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   463,     0,     0,   147,     0,     0,   463,     0,     0,
     278,     0,   147,   147,   147,     0,   147,     0,     0,     0,
       0,     0,  -359,  -359,     0,   463,     0,     0,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
       0,     0,   284,     0,     0,     0,     0,     0,     0,     0,
     298,   465,   299,     0,   451,     0,     0,   303,   306,   184,
       0,   311,     0,     0,   160,   473,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -359,  -359,     0,     0,
       0,     0,     0,     0,     0,     0,   326,     0,     0,     0,
       0,     0,   150,     0,   335,   336,   338,     0,   341,     0,
       0,     0,     0,   359,     0,   184,     0,     0,     0,     0,
       0,     0,   365,     0,   377,   378,   379,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,     0,
     404,     0,     0,     0,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   184,     0,     0,   404,
     429,     0,     0,   365,     0,     0,     0,     0,     0,     0,
       0,   435,   147,   437,  -282,  -282,     0,     0,   184,     0,
       0,     0,     0,     0,     0,   365,   445,     0,   549,     0,
       0,     0,   557,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,     0,     0,     0,     0,     0,     0,   147,     0,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,     0,     0,   584,     0,   184,   184,     0,     0,     0,
       0,     0,   365,   491,     0,   147,     0,   147,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,   147,   147,     0,     0,     0,   517,  -359,  -359,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,     0,     0,     0,     0,     0,     0,   147,     0,   147,
       0,     0,     0,   147,   147,     0,     0,     0,     0,   521,
       0,     0,     0,     0,     0,   634,     0,     0,     0,   525,
       0,     0,     0,     0,     0,     0,     0,  -359,  -359,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,   284,
       0,   160,   539,     0,   306,   544,     0,     0,     0,     0,
       0,     0,     0,   545,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,   147,     0,     0,
       0,     0,   697,     0,   698,  -284,  -284,     0,     0,   335,
       0,   573,   184,     0,     0,   341,   341,     0,     0,   365,
       0,     0,   184,     0,     0,     0,     0,     0,     0,   583,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
     184,   184,   718,     0,   598,     0,     0,   365,   365,   184,
     184,     0,   184,     0,   404,   606,   365,   365,   147,   365,
     608,     0,     0,     0,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   618,
       0,  -372,  -372,  -372,  -372,   245,   246,   247,   248,   249,
     250,   251,   252,   759,   253,     0,     0,     0,     0,     0,
       0,     0,   637,     0,     0,     0,     0,     0,   254,     0,
       0,     0,     0,     0,   284,   772,     0,     0,   775,     0,
       0,     0,     0,   786,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   796,     0,     0,     0,     0,     0,
     284,   306,     0,     4,     5,     6,     7,     8,     0,   548,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   815,     0,     0,     0,     0,
       0,   818,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,   829,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,   734,
       0,    35,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,   764,
       0,     0,    54,    55,    56,     0,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,    70,    71,     0,    72,     0,
       0,     0,    73,     0,     0,     0,     0,   797,    74,    75,
      76,    77,     0,     0,    78,    79,    80,     0,    81,     0,
      82,    83,   487,    84,     4,     5,     6,     7,     8,     0,
       0,     0,   231,     9,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
     254,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,    74,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   578,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,    74,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   354,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   467,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,   684,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,   690,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   790,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   794,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,   802,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   805,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,   821,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   834,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   857,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   859,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,   862,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
     353,    61,    62,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,    78,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,   537,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,     0,     0,    56,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,     0,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,     0,     0,    56,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,     0,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,   551,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,     0,     0,    56,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,     0,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,   727,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,     0,     0,    56,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,     0,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,   765,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,     0,     0,    56,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,     0,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,    39,     0,    40,     0,
      41,     0,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,    49,    50,     0,    51,     0,    53,
       0,     0,     0,     0,     0,    56,     0,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    70,    71,     0,    72,
       0,     0,     0,    73,     4,     5,     6,     7,     8,   119,
      75,    76,    77,     9,     0,     0,    79,    80,     0,    81,
       0,    82,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,    29,    30,   117,    32,    33,     0,     0,     0,
       0,     0,    35,    36,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    47,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   254,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     4,     5,     6,     7,     8,
       0,     0,     0,    73,     9,     0,     0,     0,     0,   119,
      75,    76,    77,     0,     0,     0,    79,   120,     0,    81,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    29,    30,   117,    32,    33,     0,     0,
       0,     0,     0,    35,    36,     0,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    47,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,   254,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    73,     9,     0,     0,     0,     0,
     119,    75,    76,    77,     0,     0,     0,    79,   120,     0,
      81,     0,   176,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,    29,    30,   117,    32,    33,     0,
       0,     0,     0,     0,    35,    36,     0,     0,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    47,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,   254,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    73,     9,     0,     0,     0,
       0,   119,    75,    76,    77,     0,     0,     0,    79,   120,
       0,    81,     0,   178,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    29,    30,   117,    32,    33,
       0,     0,     0,     0,     0,    35,    36,     0,     0,  -372,
    -372,  -372,  -372,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    47,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     254,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     4,     5,
       6,     7,     8,     0,     0,     0,    73,     9,     0,     0,
       0,     0,   119,    75,    76,    77,     0,     0,     0,    79,
     120,     0,    81,     0,   182,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,    29,    30,   117,    32,
      33,     0,     0,     0,     0,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     4,
       5,     6,     7,     8,     0,     0,     0,    73,     9,     0,
       0,     0,     0,   119,    75,    76,    77,     0,     0,     0,
      79,   120,     0,    81,   297,     0,     0,   361,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    29,    30,   117,
      32,    33,     0,     0,     0,     0,     0,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       4,     5,     6,     7,     8,     0,     0,     0,    73,     9,
       0,     0,     0,     0,   119,    75,    76,    77,     0,     0,
       0,    79,   120,   380,    81,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,    29,    30,
     117,    32,    33,     0,     0,     0,     0,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    73,
       9,     0,     0,     0,     0,   119,    75,    76,    77,     0,
       0,     0,    79,   120,     0,    81,     0,     0,     0,   406,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,    29,
      30,   117,    32,    33,     0,     0,     0,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      73,     9,     0,     0,     0,     0,   119,    75,    76,    77,
       0,     0,     0,    79,   120,     0,    81,     0,     0,     0,
     434,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      29,    30,   117,    32,    33,     0,     0,     0,     0,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     4,     5,     6,     7,     8,     0,     0,
       0,    73,     9,     0,     0,     0,     0,   119,    75,    76,
      77,     0,     0,     0,    79,   120,     0,    81,     0,     0,
       0,   436,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,     0,     0,
       0,    29,    30,   117,    32,    33,     0,     0,     0,     0,
       0,    35,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     4,     5,     6,     7,     8,     0,
       0,     0,    73,     9,     0,     0,     0,     0,   119,    75,
      76,    77,     0,     0,     0,    79,   120,     0,    81,     0,
       0,     0,   581,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,    29,    30,   117,    32,    33,     0,     0,     0,
       0,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,     4,     5,     6,     7,     8,
       0,     0,     0,    73,     9,     0,     0,     0,     0,   119,
      75,    76,    77,     0,     0,     0,    79,   120,     0,    81,
       0,     0,     0,   607,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    29,    30,   117,    32,    33,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,     0,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    73,     9,     0,     0,     0,     0,
     119,    75,    76,    77,     0,     0,     0,    79,   120,     0,
      81,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,    29,    30,   117,    32,    33,     0,
       0,     0,     0,     0,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    73,     9,     0,     0,     0,
       0,   119,    75,    76,    77,     0,     0,     0,    79,   120,
       0,    81,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,    29,    30,   117,    32,    33,
       0,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     0,     0,     0,
       0,     0,   119,    75,    76,    77,   228,   229,   230,    79,
      80,     0,    81,     0,     0,     0,     0,    84,     0,     0,
       0,     0,   231,     0,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,   228,   229,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,     0,     0,   231,     0,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,   231,     0,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,   228,   229,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
     231,     0,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,   228,   229,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,     0,
     531,   231,     0,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,   228,   229,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
       0,   568,   231,   735,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,     0,   228,   229,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602,   231,     0,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   228,   229,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,     0,   676,     0,
     231,     0,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,   228,   229,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,   254,     0,
       0,   231,     0,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   229,   230,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   255,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,     0,     0,     0,   231,   312,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,   228,
     229,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,   231,   313,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   230,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   231,   319,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,   228,   229,   230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,     0,     0,   231,   352,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,   228,   229,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,     0,     0,   231,   430,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   230,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
     443,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,   228,   229,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
     231,   444,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,   228,   229,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,     0,
       0,   231,   447,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   229,   230,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   455,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,   228,   229,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,     0,     0,   231,   613,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,   231,   800,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,   228,   229,   230,     0,
       0,     0,     0,     0,     0,     0,   819,     0,     0,     0,
       0,     0,   231,   285,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,   456,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,     0,     0,     0,   350,     0,     0,     0,   458,     0,
       0,   228,   229,   230,     0,     0,    29,    30,   117,     0,
       0,     0,     0,     0,     0,     0,    35,   231,   518,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,   534,     0,     0,   254,     0,     0,     0,     0,
       0,     0,   459,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,   228,   229,   230,     0,    73,     0,     0,
       0,     0,     0,   460,    75,    76,   461,     0,     0,   231,
      79,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,   229,   230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,     0,   231,
       0,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   230,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   231,   254,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254
};

static const yytype_int16 yycheck[] =
{
       2,   121,     2,   295,    22,    23,   186,    26,    26,    26,
     448,   475,   273,   253,    26,     8,   208,   227,   367,     2,
     369,     2,     8,    26,     8,    26,   361,   658,     8,     8,
       8,    63,    63,   555,    52,     8,    63,    63,    38,     8,
      75,    63,    31,   507,     8,    75,     8,   270,     8,     8,
       8,   315,     8,     0,    56,     8,    74,    73,     8,    77,
      75,   271,   272,   151,    73,   329,    75,    73,    75,   292,
     158,   281,   282,    49,    73,    73,    75,    75,   159,   160,
     200,   291,    73,    73,   294,   295,    75,    63,    73,    93,
      61,    62,    31,   158,   101,   158,    31,   114,     8,   434,
     622,   436,   624,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   151,   118,   158,   145,   145,
     158,    73,   158,    75,   142,    31,   349,   158,   163,   161,
     161,   149,   158,   163,   161,   161,    75,   155,    73,   161,
      75,    73,   158,    75,    73,   151,   163,   151,   163,    93,
      26,    61,    62,   502,   163,   161,   348,   148,   161,   160,
     151,   151,   161,   148,   163,   163,   151,   160,   161,    75,
     188,   159,   160,    73,   160,   193,   160,   615,   809,   114,
     160,   160,   160,   201,   202,   203,   159,   205,   452,   207,
     158,   160,   456,   457,   458,    31,   160,   159,   127,   159,
     159,   159,    73,   159,    22,    23,   159,   151,    26,   159,
     227,   163,   145,   148,   216,   227,   151,   145,   151,   148,
     145,   158,   151,   151,   153,   158,   151,   127,   163,    73,
     159,   163,   145,   497,   253,   253,   253,    65,   151,    75,
     589,   253,    96,    97,   158,    73,   581,    75,   148,   159,
     158,   151,   161,   153,   271,   272,    96,    97,   120,   271,
     272,   279,   145,   486,   281,   282,   151,   528,   151,   281,
     282,   289,   607,   158,   291,   158,   158,   294,   295,   291,
     520,   145,   294,   295,   633,   120,   114,   151,    95,    96,
      97,   514,   515,   158,   158,   158,   645,   315,   562,    49,
     523,   524,   158,   526,   322,   569,    68,    69,   162,   151,
     158,   329,    95,    96,    97,   158,   318,   609,   160,   161,
     148,    73,   162,   151,    68,    69,   160,   161,   161,   102,
      80,   149,    22,    23,   107,   163,   109,   110,   111,   112,
     113,   114,   115,   361,   346,    73,   346,    73,   160,   367,
      31,   369,   145,   158,   372,   145,   620,   537,   124,   376,
     540,   101,   626,   346,   628,   346,   830,   151,    45,    46,
      47,   551,    49,   151,    63,   193,   145,   145,   164,     8,
     151,   673,   145,   201,   202,   203,    63,   205,   406,   162,
     151,   158,   145,   124,   743,    73,   745,    75,    85,   609,
      73,   160,   666,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    13,   434,   160,   436,    13,
     159,   159,    73,   173,    42,    43,    44,    45,    46,    47,
     779,    49,   450,   451,   452,   253,   114,    73,   456,   457,
     458,   158,   122,   461,   444,    63,   122,   447,   126,   158,
     160,    61,    62,   717,   454,     8,    93,   475,   476,    13,
     478,   810,    73,   673,   482,   483,    75,   158,   160,   219,
     148,   159,   158,   151,   159,   739,   158,     8,   742,   497,
      73,   499,    75,   747,   502,   163,   488,   836,   488,   507,
     159,    13,   123,   161,   758,   158,   845,   315,   158,   158,
     164,   520,   520,   520,   101,   488,   159,   488,   520,   158,
     158,   329,   109,   110,   111,   112,   113,   114,   158,   164,
     270,   114,    73,   151,   159,   789,   158,   105,   546,   145,
      73,   795,   712,    13,   714,   160,    73,    13,    75,   159,
     159,     8,   292,   361,   562,   563,   151,   727,   161,   813,
     160,   569,   159,     8,   124,   148,   160,   737,   151,   125,
      13,   741,   125,   581,   160,   160,     8,   585,   161,    73,
     163,   589,    73,   164,    75,   593,   158,   114,   159,   159,
     107,   160,   762,   159,    75,   765,    13,   159,   406,   607,
     770,   159,   609,   164,   159,   159,   124,   609,   616,   349,
     350,   159,   620,   160,   159,    75,    13,   159,   626,   611,
     628,   148,   614,   114,   151,   633,   434,   159,   436,   621,
     161,    73,   158,   161,   804,   158,   163,   645,   160,   159,
     750,   160,   450,   451,   452,   160,   125,    75,   456,   457,
     458,   109,   110,   111,   112,   113,   114,   148,   666,   161,
     151,    13,   832,    13,    73,   657,   673,    75,   476,    13,
     478,   673,   163,   158,   482,   483,    70,    26,   160,   159,
     850,    13,    75,   853,    75,    13,   160,    93,   161,   497,
     860,   681,   160,   162,    93,   102,   152,   687,   688,   160,
     107,   145,   109,   110,   111,   112,   113,   114,   115,   717,
      13,    73,   520,   160,     8,    73,    75,   158,    26,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   739,    73,   160,   742,   743,   726,   745,   546,   747,
      73,     8,   105,   159,   158,   157,   486,   322,   161,    75,
     758,   161,   841,   476,   562,   162,   496,   159,   502,   547,
     752,   569,   688,   327,   756,   616,   593,    61,    62,   734,
      81,   779,   588,   581,   514,   515,   768,   635,   779,   771,
     599,   789,   774,   523,   524,   562,   526,   795,   193,   561,
     482,   719,   483,    -1,    -1,   206,    -1,    -1,    -1,   607,
      -1,    -1,   810,    -1,    -1,   813,   798,    -1,   616,   801,
     800,   803,   620,    22,    23,    -1,    -1,    26,   626,    -1,
     628,    -1,   830,    -1,    -1,    -1,    -1,    -1,   836,    -1,
      -1,   823,    -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,
      -1,    -1,   854,    -1,   856,   159,    -1,    -1,    -1,   861,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,   717,
      44,    45,    -1,    -1,    -1,    49,    -1,    51,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   739,    -1,    -1,   742,    -1,    -1,    -1,    -1,   747,
     149,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
     758,    -1,    -1,    80,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   789,    -1,    -1,   193,    -1,    -1,   795,    -1,    -1,
     124,    -1,   201,   202,   203,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,   813,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   315,   166,    -1,    93,    -1,    -1,   171,   172,   173,
      -1,   175,    -1,    -1,   253,   329,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,   206,    -1,   201,   202,   203,    -1,   205,    -1,
      -1,    -1,    -1,   217,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,   219,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,    -1,    -1,    -1,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,    -1,    -1,   273,
     274,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   285,   361,   287,   159,   160,    -1,    -1,   292,    -1,
      -1,    -1,    -1,    -1,    -1,   292,   300,    -1,   452,    -1,
      -1,    -1,   456,   457,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,   497,    -1,   349,   350,    -1,    -1,    -1,
      -1,    -1,   349,   350,    -1,   434,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,    -1,
      -1,   450,   451,    -1,    -1,    -1,   380,    61,    62,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,   478,
      -1,    -1,    -1,   482,   483,    -1,    -1,    -1,    -1,   406,
      -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,    -1,   423,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,   436,
      -1,   520,   446,    -1,   448,   449,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   450,   451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   620,   546,    -1,    -1,
      -1,    -1,   626,    -1,   628,   159,   160,    -1,    -1,   476,
      -1,   478,   486,    -1,    -1,   482,   483,    -1,    -1,   486,
      -1,    -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,   496,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     514,   515,   666,    -1,   518,    -1,    -1,   514,   515,   523,
     524,    -1,   526,    -1,   528,   529,   523,   524,   607,   526,
     534,    -1,    -1,    -1,    -1,    -1,    -1,   616,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   717,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   576,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,   581,   739,    -1,    -1,   742,    -1,
      -1,    -1,    -1,   747,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   758,    -1,    -1,    -1,    -1,    -1,
     607,   615,    -1,     3,     4,     5,     6,     7,    -1,   616,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,
      -1,   795,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,   813,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    77,    -1,   693,
      -1,    81,    82,    83,    84,    85,    -1,    87,    -1,    89,
      -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,   106,   107,   108,   723,
      -1,    -1,   112,   113,   114,    -1,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,   761,   148,   149,
     150,   151,    -1,    -1,   154,   155,   156,    -1,   158,    -1,
     160,   161,   162,   163,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    25,    12,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      63,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,   107,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,   107,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    92,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    90,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,   154,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    87,    -1,
      89,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      99,   100,   101,    -1,   103,   104,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,    -1,   138,
      -1,    -1,    -1,   142,     3,     4,     5,     6,     7,   148,
     149,   150,   151,    12,    -1,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   101,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    63,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   142,    12,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,   158,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   101,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    63,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   142,    12,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,
     158,    -1,   160,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   101,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    63,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   142,    12,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
      -1,   158,    -1,   160,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   101,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      63,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   142,    12,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,
     155,   156,    -1,   158,   159,    -1,    -1,    31,   163,    -1,
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
      -1,   155,   156,    26,   158,    -1,    -1,    -1,    -1,   163,
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
      -1,    31,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    31,   163,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    31,   163,    -1,    -1,    -1,    -1,    -1,
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
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
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
      -1,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,     9,    10,    11,   155,
     156,    -1,   158,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
     162,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,   162,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,   162,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    63,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   160,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    25,   160,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    25,   160,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   160,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    25,   159,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    25,   159,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     159,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      25,   159,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    25,   159,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   159,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    25,   159,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    25,   159,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    25,   125,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,   125,    -1,    -1,    -1,    63,    -1,
      -1,     9,    10,    11,    -1,    -1,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   125,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,   142,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,    25,
     155,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    11,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    63,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63
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
     247,   255,   258,   262,   263,   265,   266,   270,   271,   272,
     273,   274,   275,   276,   281,   286,   288,    73,   114,   148,
     156,   243,   262,   262,   158,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     114,   148,   151,   168,   247,   265,   266,   272,   265,    31,
     262,   284,   285,   262,   148,   151,   168,   247,   249,   250,
     272,   274,   275,   281,   158,   253,   158,    26,   238,   262,
     175,   158,   158,   158,   158,   158,   160,   262,   160,   262,
      73,    73,   160,   241,   262,   266,   161,   262,   151,   168,
     170,   171,    75,   163,   213,   214,   120,   120,    75,   215,
     243,   158,   158,   158,   158,   158,   158,   151,   161,   168,
     168,   241,   262,   266,   242,   262,   173,   161,   151,   158,
       8,   160,    73,    73,   160,    31,   185,   145,     9,    10,
      11,    25,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    49,    63,   160,    61,    62,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     158,   145,   124,    63,   161,   163,   275,   185,   262,   151,
     168,   145,   145,   264,   266,   125,   164,     8,   260,   151,
     168,   145,   158,   254,   145,   124,   275,   159,   262,   262,
       8,   160,    85,   262,   239,   240,   262,   241,   266,    73,
     199,   262,   160,   160,   160,    13,   160,   160,   173,   160,
     168,    93,     8,   160,   161,   263,   266,     8,   160,    13,
       8,   160,   185,   181,   182,   266,   266,   287,   266,   159,
     126,   266,   282,   283,   284,   168,   167,   160,   161,   158,
     125,   159,   159,   119,   162,   174,   175,   183,   184,   262,
      73,    31,   211,   212,   241,   266,    73,   122,   189,   122,
     191,    73,   158,    73,   270,   275,   281,   262,   262,   262,
      26,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   249,   262,   277,    31,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   211,
      73,   270,    73,   161,   270,   278,   279,   280,   277,   262,
     159,   168,    73,    73,    31,   262,    31,   262,   168,   270,
     211,   270,   278,   159,   159,   262,   158,   159,   160,     8,
      93,    93,    13,     8,   159,   159,    42,    43,    63,   127,
     148,   151,   168,   247,   255,   256,   257,   162,    93,    73,
     171,   262,   214,   256,    75,   158,     8,   159,     8,   159,
     159,   160,   158,     8,   159,   159,   158,   162,   167,   211,
     241,   266,   158,   162,   264,   159,     8,    13,   148,   151,
     168,   248,   123,   192,   193,   248,   161,   158,   127,   153,
     208,   209,   210,   248,   158,   158,   275,   262,    26,   164,
      65,   266,   159,   158,   158,   262,   158,   269,    63,   161,
     164,   162,   264,   264,   125,   159,   251,    26,   175,   262,
      26,   175,   203,   239,   262,   266,    31,   195,   266,   256,
      73,    26,   175,   198,    26,   161,   200,   256,   256,   256,
     259,   261,   158,   151,   168,   145,   105,    73,   162,    13,
     208,   182,   160,   266,   282,   283,    13,   211,   162,   159,
     159,    31,   241,   266,   256,   151,   168,   193,   161,     8,
     216,   208,   159,     8,    31,    75,   211,   211,   262,   249,
     211,   211,   162,   211,   267,   277,   262,    31,   262,   124,
     252,   173,   204,   159,   173,   160,   125,   194,   266,   194,
      13,   173,   160,   201,   160,   201,   125,   164,     8,   260,
     259,   168,    73,   158,   256,   159,   159,   262,   159,   160,
     264,   168,   216,   248,   102,   107,   109,   110,   111,   112,
     113,   114,   115,   162,   217,   219,   232,   233,   234,   235,
     237,   159,   107,   244,   210,    75,    13,   159,   159,   254,
     159,   159,   159,   124,   268,   164,   162,   264,   278,   205,
      68,    69,   206,   160,    86,   239,   195,   159,   159,   256,
      92,   201,    95,    96,    97,   201,   162,   256,   256,   159,
     248,   244,   162,    73,   220,   248,    75,   236,   243,   235,
       8,   160,   161,   158,   161,    31,    75,    13,   256,   278,
      68,    69,   207,   158,   175,   160,   159,    26,   175,   197,
     197,   160,    95,   160,   262,    26,   160,   202,   162,   125,
      75,   161,    13,     8,   160,   161,   221,    13,     8,   160,
     218,    73,   173,    31,    75,   245,   173,    75,    13,   256,
     269,   158,    26,    70,   262,    26,   175,   196,   173,   160,
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (yyscanner, root, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  switch (yytype)
    {
      default:
	break;
    }
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , yyscanner, root);
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void* yyscanner, xhpast::Node** root);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 197 "parser.y"
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 3:
#line 203 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 4:
#line 206 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 5:
#line 212 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_SYMBOL_NAME);
  ;}
    break;

  case 6:
#line 215 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 10:
#line 224 "parser.y"
    {
    (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 11:
#line 229 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_NAMESPACE, (yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 12:
#line 236 "parser.y"
    {
  NSPAN((yyvsp[(1) - (5)]), n_NAMESPACE, (yyvsp[(5) - (5)]));
  (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
  (yyvsp[(1) - (5)])->appendChild(NEXPAND((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 13:
#line 242 "parser.y"
    {
  NSPAN((yyvsp[(1) - (4)]), n_NAMESPACE, (yyvsp[(4) - (4)]));
  (yyvsp[(1) - (4)])->appendChild(NNEW(n_EMPTY));
  NMORE((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
  NLMORE((yyvsp[(3) - (4)]), (yyvsp[(2) - (4)]));
  (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
  ;}
    break;

  case 14:
#line 250 "parser.y"
    {
  NSPAN((yyvsp[(1) - (3)]), n_USE, (yyvsp[(2) - (3)]));
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 15:
#line 256 "parser.y"
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
  NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 16:
#line 263 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 17:
#line 266 "parser.y"
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 18:
#line 273 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 19:
#line 278 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    NTYPE((yyvsp[(3) - (3)]), n_STRING);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 20:
#line 284 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 21:
#line 290 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
    NTYPE((yyvsp[(4) - (4)]), n_STRING);
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  ;}
    break;

  case 22:
#line 300 "parser.y"
    {
    NMORE((yyval), (yyvsp[(5) - (5)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING))
        ->appendChild((yyvsp[(5) - (5)])));
  ;}
    break;

  case 23:
#line 307 "parser.y"
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[(4) - (4)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(2) - (4)]), n_STRING))
        ->appendChild((yyvsp[(4) - (4)])));
  ;}
    break;

  case 24:
#line 317 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 25:
#line 320 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 29:
#line 329 "parser.y"
    {
  (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
  NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 31:
#line 338 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 32:
#line 344 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  ;}
    break;

  case 33:
#line 347 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  ;}
    break;

  case 34:
#line 350 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLOSE_TAG);
  ;}
    break;

  case 35:
#line 356 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 36:
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
  ;}
    break;

  case 37:
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
  ;}
    break;

  case 38:
#line 404 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_WHILE);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 39:
#line 411 "parser.y"
    {
    NTYPE((yyvsp[(1) - (7)]), n_DO_WHILE);
    (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
    (yyvsp[(1) - (7)])->appendChild(NSPAN((yyvsp[(4) - (7)]), n_CONTROL_CONDITION, (yyvsp[(6) - (7)]))->appendChild((yyvsp[(5) - (7)])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (7)]));
    NMORE((yyval), (yyvsp[(7) - (7)]));
  ;}
    break;

  case 40:
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
  ;}
    break;

  case 41:
#line 432 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_SWITCH);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 42:
#line 439 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_BREAK);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 43:
#line 446 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_BREAK);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 44:
#line 453 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_CONTINUE);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 45:
#line 460 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_CONTINUE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 46:
#line 467 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_RETURN);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 47:
#line 474 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 48:
#line 481 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 49:
#line 488 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 50:
#line 493 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 51:
#line 498 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 52:
#line 503 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_INLINE_HTML);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 53:
#line 507 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 54:
#line 511 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 55:
#line 515 "parser.y"
    {
    NMORE((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
    NLMORE((yyvsp[(3) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(3) - (5)]));
    NMORE((yyval), (yyvsp[(5) - (5)]));
  ;}
    break;

  case 56:
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
  ;}
    break;

  case 57:
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
  ;}
    break;

  case 58:
#line 554 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_DECLARE);
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 59:
#line 560 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 60:
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
  ;}
    break;

  case 61:
#line 578 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_THROW);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));

  ;}
    break;

  case 62:
#line 586 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_GOTO);
  NTYPE((yyvsp[(2) - (3)]), n_STRING);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 64:
#line 598 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 65:
#line 604 "parser.y"
    {
	  (yyval) = NNEW(n_EMPTY);
	;}
    break;

  case 66:
#line 607 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_FINALLY);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 67:
#line 617 "parser.y"
    {
    (yyval) = NNEW(n_CATCH_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 68:
#line 621 "parser.y"
    {
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 69:
#line 628 "parser.y"
    {
    NTYPE((yyvsp[(1) - (8)]), n_CATCH);
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(3) - (8)]));
    (yyvsp[(1) - (8)])->appendChild(NTYPE((yyvsp[(4) - (8)]), n_VARIABLE));
    (yyvsp[(1) - (8)])->appendChild(NEXPAND((yyvsp[(6) - (8)]), (yyvsp[(7) - (8)]), (yyvsp[(8) - (8)])));
    NMORE((yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
    (yyval) = (yyvsp[(1) - (8)]);
  ;}
    break;

  case 70:
#line 639 "parser.y"
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 71:
#line 643 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 75:
#line 662 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 76:
#line 665 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_REFERENCE);
  ;}
    break;

  case 77:
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
  ;}
    break;

  case 78:
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
  ;}
    break;

  case 79:
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
  ;}
    break;

  case 80:
#line 711 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 81:
#line 715 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 82:
#line 722 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 83:
#line 729 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_ATTRIBUTES);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 84:
#line 736 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 85:
#line 739 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 87:
#line 749 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 88:
#line 752 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 89:
#line 760 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 90:
#line 763 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_IMPLEMENTS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 91:
#line 771 "parser.y"
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 92:
#line 774 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 93:
#line 780 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 94:
#line 783 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 96:
#line 790 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 98:
#line 799 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 100:
#line 808 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 102:
#line 817 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 103:
#line 825 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_STRING));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 104:
#line 831 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));
    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 105:
#line 842 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 106:
#line 845 "parser.y"
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[(2) - (4)]), n_STATEMENT);
    (yyvsp[(1) - (4)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[(2) - (4)]));
    (yyval)->appendChildren((yyvsp[(3) - (4)]));
    NEXPAND((yyvsp[(1) - (4)]), (yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 107:
#line 855 "parser.y"
    {
    NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 108:
#line 860 "parser.y"
    {
    NTYPE((yyvsp[(2) - (5)]), n_STATEMENT);
    (yyvsp[(1) - (5)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[(2) - (5)]));
    (yyval)->appendChildren((yyvsp[(3) - (5)]));
    NMORE((yyval), (yyvsp[(5) - (5)]));
    NLMORE((yyval), (yyvsp[(1) - (5)]));
  ;}
    break;

  case 109:
#line 872 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 110:
#line 875 "parser.y"
    {
    NTYPE((yyvsp[(2) - (5)]), n_CASE);
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 111:
#line 883 "parser.y"
    {
    NTYPE((yyvsp[(2) - (4)]), n_DEFAULT);
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(4) - (4)]));

    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 115:
#line 899 "parser.y"
    {
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 116:
#line 907 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  ;}
    break;

  case 117:
#line 910 "parser.y"
    {
    NTYPE((yyvsp[(2) - (6)]), n_ELSEIF);
    (yyvsp[(2) - (6)])->appendChild(NSPAN((yyvsp[(3) - (6)]), n_CONTROL_CONDITION, (yyvsp[(5) - (6)]))->appendChild((yyvsp[(4) - (6)])));
    (yyvsp[(2) - (6)])->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyvsp[(2) - (6)]));
  ;}
    break;

  case 118:
#line 920 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  ;}
    break;

  case 119:
#line 923 "parser.y"
    {
    NTYPE((yyvsp[(2) - (7)]), n_ELSEIF);
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(4) - (7)]));
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(7) - (7)]));

    (yyval) = (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
  ;}
    break;

  case 120:
#line 933 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 121:
#line 936 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_ELSE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 122:
#line 944 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 123:
#line 947 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ELSE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 125:
#line 956 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  ;}
    break;

  case 126:
#line 962 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 127:
#line 970 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_VARIABLE_REFERENCE));
      (yyvsp[(2) - (3)])->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 128:
#line 979 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (5)]), n_VARIABLE_REFERENCE));
      (yyvsp[(2) - (5)])->appendChild(NTYPE((yyvsp[(3) - (5)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 129:
#line 988 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(4) - (4)]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 130:
#line 996 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  ;}
    break;

  case 131:
#line 1004 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (5)]), n_VARIABLE_REFERENCE));
      (yyvsp[(4) - (5)])->appendChild(NTYPE((yyvsp[(5) - (5)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 132:
#line 1013 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (7)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (7)]), n_VARIABLE_REFERENCE));
      (yyvsp[(4) - (7)])->appendChild(NTYPE((yyvsp[(5) - (7)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(7) - (7)]));

    (yyval) = (yyvsp[(1) - (7)])->appendChild((yyval));
  ;}
    break;

  case 133:
#line 1022 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (6)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  ;}
    break;

  case 134:
#line 1033 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 135:
#line 1036 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 136:
#line 1039 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_TYPE_NAME);
  ;}
    break;

  case 137:
#line 1042 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_TYPE_NAME);
  ;}
    break;

  case 139:
#line 1049 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  ;}
    break;

  case 140:
#line 1055 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 141:
#line 1058 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 142:
#line 1061 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (2)]));
  ;}
    break;

  case 143:
#line 1066 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 144:
#line 1069 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 145:
#line 1072 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 146:
#line 1078 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 147:
#line 1082 "parser.y"
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 148:
#line 1089 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  ;}
    break;

  case 149:
#line 1092 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 150:
#line 1096 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (4)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 151:
#line 1103 "parser.y"
    {
    NTYPE((yyvsp[(3) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 152:
#line 1111 "parser.y"
    {
    NTYPE((yyvsp[(3) - (5)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 153:
#line 1119 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 154:
#line 1127 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 155:
#line 1138 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 156:
#line 1141 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 157:
#line 1147 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChildren((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 158:
#line 1155 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 159:
#line 1159 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 160:
#line 1162 "parser.y"
    {
    yyextra->old_expecting_xhp_class_statements = yyextra->expecting_xhp_class_statements;
    yyextra->expecting_xhp_class_statements = false;
  ;}
    break;

  case 161:
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
  ;}
    break;

  case 162:
#line 1181 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (3)]), n_TRAIT_USE);
    (yyval)->appendChildren((yyvsp[(2) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 163:
#line 1189 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_USE_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 164:
#line 1192 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 165:
#line 1198 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 166:
#line 1201 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 167:
#line 1207 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
  ;}
    break;

  case 168:
#line 1210 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 169:
#line 1216 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_ADAPTATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 170:
#line 1220 "parser.y"
    {
	  (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
	  (yyval) = (yyvsp[(1) - (2)]);
	;}
    break;

  case 171:
#line 1227 "parser.y"
    {
		(yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	;}
    break;

  case 172:
#line 1230 "parser.y"
    {
	  (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
	;}
    break;

  case 173:
#line 1236 "parser.y"
    {
	  (yyval) = NNEW(n_TRAIT_INSTEADOF);
	  (yyval)->appendChild((yyvsp[(1) - (3)]));
	  (yyval)->appendChild((yyvsp[(3) - (3)]));
	;}
    break;

  case 174:
#line 1244 "parser.y"
    {
		(yyval) = NNEW(n_TRAIT_REFERENCE_LIST);
		(yyval)->appendChild((yyvsp[(1) - (1)]));
	;}
    break;

  case 175:
#line 1248 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 176:
#line 1255 "parser.y"
    {
	  (yyval) = NNEW(n_TRAIT_METHOD_REFERENCE);
	  (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 177:
#line 1259 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 178:
#line 1265 "parser.y"
    {
    NTYPE((yyvsp[(2) - (3)]), n_TRAIT_METHOD_REFERENCE);
    NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), NTYPE((yyvsp[(3) - (3)]), n_STRING));
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 179:
#line 1273 "parser.y"
    {
	  (yyval) = NNEW(n_TRAIT_AS);
	  (yyval)->appendChild((yyvsp[(1) - (4)]));
	  (yyval)->appendChild((yyvsp[(3) - (4)]));
	  (yyval)->appendChild(NTYPE((yyvsp[(4) - (4)]), n_STRING));
	;}
    break;

  case 180:
#line 1279 "parser.y"
    {
    (yyval) = NNEW(n_TRAIT_AS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 181:
#line 1288 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
	;}
    break;

  case 182:
#line 1291 "parser.y"
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 183:
#line 1299 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 184:
#line 1302 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 186:
#line 1309 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 187:
#line 1316 "parser.y"
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  ;}
    break;

  case 188:
#line 1319 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 189:
#line 1326 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 190:
#line 1330 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_STRING));
  ;}
    break;

  case 197:
#line 1345 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 198:
#line 1352 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 199:
#line 1359 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 200:
#line 1366 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 201:
#line 1376 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));

    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 202:
#line 1385 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_STRING));
    (yyval)->appendChild((yyvsp[(4) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyval));

    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 203:
#line 1397 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 204:
#line 1400 "parser.y"
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 205:
#line 1407 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 207:
#line 1415 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 208:
#line 1418 "parser.y"
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 209:
#line 1425 "parser.y"
    {
    NTYPE((yyvsp[(1) - (6)]), n_LIST);
    (yyvsp[(1) - (6)])->appendChild(NEXPAND((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (6)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(6) - (6)]));
  ;}
    break;

  case 210:
#line 1433 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 211:
#line 1439 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_OPERATOR));

    NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (4)])->appendChild((yyvsp[(4) - (4)]));

    (yyval)->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 212:
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
  ;}
    break;

  case 213:
#line 1463 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_NEW);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 214:
#line 1469 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 215:
#line 1474 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 216:
#line 1480 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 217:
#line 1486 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 218:
#line 1492 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 219:
#line 1498 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 220:
#line 1504 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 221:
#line 1510 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 222:
#line 1516 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 223:
#line 1522 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 224:
#line 1528 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 225:
#line 1534 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 226:
#line 1540 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  ;}
    break;

  case 227:
#line 1545 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 228:
#line 1550 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  ;}
    break;

  case 229:
#line 1555 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 230:
#line 1560 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 231:
#line 1566 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 232:
#line 1572 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 233:
#line 1578 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 234:
#line 1584 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 235:
#line 1590 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 236:
#line 1596 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 237:
#line 1602 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 238:
#line 1608 "parser.y"
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
  ;}
    break;

  case 239:
#line 1634 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 240:
#line 1640 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 241:
#line 1646 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 242:
#line 1652 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 243:
#line 1658 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 244:
#line 1664 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 245:
#line 1670 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 246:
#line 1676 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 247:
#line 1681 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 248:
#line 1686 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 249:
#line 1691 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 250:
#line 1696 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 251:
#line 1702 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 252:
#line 1708 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 253:
#line 1714 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 254:
#line 1720 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 255:
#line 1726 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 256:
#line 1732 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 257:
#line 1738 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 258:
#line 1744 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 259:
#line 1750 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 260:
#line 1755 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));
  ;}
    break;

  case 261:
#line 1761 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  ;}
    break;

  case 263:
#line 1768 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 264:
#line 1773 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 265:
#line 1778 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 266:
#line 1783 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 267:
#line 1788 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 268:
#line 1793 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 269:
#line 1798 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 270:
#line 1803 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 271:
#line 1808 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 272:
#line 1813 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 273:
#line 1819 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 274:
#line 1825 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 276:
#line 1830 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 277:
#line 1835 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_YIELD);
    (yyvsp[(1) - (1)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (1)])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 278:
#line 1841 "parser.y"
    {
  (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 279:
#line 1844 "parser.y"
    {
    NSPAN((yyvsp[(1) - (9)]), n_FUNCTION_DECLARATION, (yyvsp[(9) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(2) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)])));
    (yyval)->appendChild((yyvsp[(6) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(7) - (9)]), (yyvsp[(8) - (9)]), (yyvsp[(9) - (9)])));

    (yyval) = (yyvsp[(1) - (9)]);
  ;}
    break;

  case 280:
#line 1855 "parser.y"
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
  ;}
    break;

  case 281:
#line 1875 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_YIELD);
    (yyvsp[(2) - (2)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 282:
#line 1881 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_YIELD);
    (yyvsp[(2) - (2)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 283:
#line 1887 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_YIELD);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 284:
#line 1893 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_YIELD);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 286:
#line 1906 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 287:
#line 1909 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[(1) - (4)])->appendChildren((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 288:
#line 1917 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
  ;}
    break;

  case 289:
#line 1920 "parser.y"
    {
    NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (4)])->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 290:
#line 1925 "parser.y"
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
  ;}
    break;

  case 291:
#line 1929 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
  ;}
    break;

  case 292:
#line 1938 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  ;}
    break;

  case 293:
#line 1943 "parser.y"
    {
    NLMORE((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 294:
#line 1949 "parser.y"
    {
    NLMORE((yyvsp[(2) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(2) - (5)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])));
  ;}
    break;

  case 295:
#line 1955 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 296:
#line 1963 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 297:
#line 1971 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 298:
#line 1979 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 299:
#line 1987 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  ;}
    break;

  case 300:
#line 1995 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 301:
#line 1998 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 302:
#line 2001 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  ;}
    break;

  case 303:
#line 2005 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  ;}
    break;

  case 304:
#line 2012 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 305:
#line 2015 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  ;}
    break;

  case 306:
#line 2019 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  ;}
    break;

  case 309:
#line 2031 "parser.y"
    {
    (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    for (xhpast::node_list_t::iterator ii = (yyvsp[(4) - (4)])->children.begin(); ii != (yyvsp[(4) - (4)])->children.end(); ++ii) {
      (yyval) = NNEW(n_OBJECT_PROPERTY_ACCESS)->appendChild((yyval));
      (yyval)->appendChild(*ii);
    }
  ;}
    break;

  case 311:
#line 2044 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 312:
#line 2047 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 313:
#line 2053 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 314:
#line 2059 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 315:
#line 2062 "parser.y"
    {
    NSPAN((yyvsp[(1) - (2)]), n_EMPTY, (yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 316:
#line 2066 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 317:
#line 2074 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 318:
#line 2077 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 319:
#line 2083 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  ;}
    break;

  case 320:
#line 2086 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  ;}
    break;

  case 321:
#line 2089 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_STRING_SCALAR);
  ;}
    break;

  case 322:
#line 2092 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 323:
#line 2095 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 324:
#line 2098 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 325:
#line 2101 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 326:
#line 2104 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 327:
#line 2107 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 328:
#line 2110 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 329:
#line 2113 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 330:
#line 2116 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_HEREDOC);
  ;}
    break;

  case 333:
#line 2124 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 334:
#line 2128 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 335:
#line 2132 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 336:
#line 2137 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 337:
#line 2142 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 338:
#line 2148 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 340:
#line 2158 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 344:
#line 2169 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
  ;}
    break;

  case 345:
#line 2172 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 347:
#line 2179 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  ;}
    break;

  case 348:
#line 2182 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 349:
#line 2188 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 351:
#line 2195 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 352:
#line 2202 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 353:
#line 2209 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 354:
#line 2216 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 360:
#line 2243 "parser.y"
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
  ;}
    break;

  case 362:
#line 2267 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
  ;}
    break;

  case 363:
#line 2270 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 364:
#line 2276 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(2) - (3)]));
    if ((yyvsp[(3) - (3)])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[(3) - (3)]));
    }
  ;}
    break;

  case 365:
#line 2286 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 366:
#line 2289 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 368:
#line 2296 "parser.y"
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
  ;}
    break;

  case 369:
#line 2311 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 370:
#line 2316 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 375:
#line 2334 "parser.y"
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
  ;}
    break;

  case 377:
#line 2350 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 378:
#line 2356 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 380:
#line 2366 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  ;}
    break;

  case 381:
#line 2369 "parser.y"
    {
    NSPAN((yyvsp[(1) - (4)]), n_VARIABLE_EXPRESSION, (yyvsp[(4) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 382:
#line 2377 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 383:
#line 2380 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 386:
#line 2391 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]))
  ;}
    break;

  case 387:
#line 2397 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 389:
#line 2407 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_STRING);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 390:
#line 2411 "parser.y"
    {
  (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 391:
#line 2417 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE_VARIABLE);
  ;}
    break;

  case 392:
#line 2420 "parser.y"
    {
    (yyvsp[(2) - (2)]) = NTYPE((yyvsp[(2) - (2)]), n_VARIABLE_VARIABLE);

    xhpast::Node *last = (yyvsp[(1) - (2)]);
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      last = last->firstChild();
    }
    last->appendChild((yyvsp[(2) - (2)]));

    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 393:
#line 2435 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 394:
#line 2438 "parser.y"
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 396:
#line 2446 "parser.y"
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 397:
#line 2451 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 398:
#line 2457 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  ;}
    break;

  case 399:
#line 2460 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 400:
#line 2466 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 401:
#line 2473 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 402:
#line 2480 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 403:
#line 2487 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 404:
#line 2494 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (6)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(6) - (6)])));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  ;}
    break;

  case 405:
#line 2501 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  ;}
    break;

  case 406:
#line 2508 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 407:
#line 2515 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(2) - (2)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 408:
#line 2525 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChildren((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 409:
#line 2535 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 410:
#line 2545 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 411:
#line 2548 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 412:
#line 2551 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 413:
#line 2561 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 414:
#line 2564 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 415:
#line 2570 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 416:
#line 2574 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 417:
#line 2580 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 418:
#line 2585 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 419:
#line 2598 "parser.y"
    {
    if (yyextra->idx_expr) {
      yyextra->used = true;
    }
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;


/* Line 1267 of yacc.c.  */
#line 7334 "parser.yacc.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (yyscanner, root, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yyscanner, root, yymsg);
	  }
	else
	  {
	    yyerror (yyscanner, root, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (yyscanner, root, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, yyscanner, root);
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


#line 2610 "parser.y"


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}

/* @generated */
