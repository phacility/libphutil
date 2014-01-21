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
     T_YIELD = 392
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
#line 458 "parser.yacc.cpp"

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
#define YYLAST   7496

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  383
/* YYNRULES -- Number of states.  */
#define YYNSTATES  804

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   392

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,   162,    47,    31,     2,
     157,   158,    45,    42,     8,    43,    44,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   159,
      36,    13,    37,    25,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,   163,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   160,    29,   161,    50,     2,     2,     2,
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
     154,   155,   156
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
     187,   191,   195,   197,   200,   206,   215,   224,   230,   232,
     246,   250,   254,   256,   257,   259,   262,   271,   273,   277,
     279,   281,   283,   284,   286,   296,   304,   311,   313,   316,
     319,   320,   323,   325,   326,   329,   330,   333,   335,   339,
     340,   343,   345,   348,   350,   355,   357,   362,   364,   369,
     373,   379,   383,   388,   393,   399,   400,   406,   411,   413,
     415,   417,   422,   423,   430,   431,   439,   440,   443,   444,
     448,   450,   451,   454,   458,   464,   469,   474,   480,   488,
     495,   496,   498,   500,   502,   503,   505,   507,   510,   514,
     518,   523,   527,   529,   531,   534,   539,   543,   549,   551,
     555,   558,   559,   563,   566,   567,   577,   579,   583,   585,
     587,   588,   590,   592,   595,   597,   599,   601,   603,   605,
     607,   611,   617,   619,   623,   629,   634,   638,   640,   641,
     643,   647,   649,   656,   660,   665,   672,   676,   679,   683,
     687,   691,   695,   699,   703,   707,   711,   715,   719,   723,
     726,   729,   732,   735,   739,   743,   747,   751,   755,   759,
     763,   767,   771,   775,   779,   783,   787,   791,   795,   799,
     802,   805,   808,   811,   815,   819,   823,   827,   831,   835,
     839,   843,   847,   851,   857,   862,   864,   867,   870,   873,
     876,   879,   882,   885,   888,   891,   896,   898,   900,   903,
     913,   924,   926,   927,   932,   936,   941,   943,   946,   951,
     958,   964,   971,   978,   985,   992,   997,   999,  1001,  1005,
    1008,  1010,  1014,  1017,  1019,  1021,  1026,  1028,  1031,  1032,
    1035,  1036,  1039,  1043,  1044,  1048,  1050,  1052,  1054,  1056,
    1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,  1078,
    1081,  1084,  1087,  1092,  1094,  1098,  1100,  1102,  1104,  1108,
    1111,  1113,  1114,  1117,  1118,  1120,  1126,  1130,  1134,  1136,
    1138,  1140,  1142,  1144,  1146,  1152,  1154,  1157,  1158,  1162,
    1166,  1167,  1169,  1172,  1176,  1180,  1182,  1184,  1186,  1188,
    1191,  1193,  1198,  1203,  1205,  1207,  1212,  1213,  1215,  1217,
    1219,  1224,  1229,  1231,  1233,  1237,  1239,  1242,  1246,  1248,
    1250,  1255,  1256,  1257,  1260,  1266,  1270,  1274,  1276,  1283,
    1288,  1293,  1296,  1301,  1306,  1309,  1312,  1317,  1320,  1323,
    1325,  1329,  1333,  1337
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     165,     0,    -1,   166,    -1,   166,   168,    -1,    -1,    73,
      -1,   167,   151,    73,    -1,   174,    -1,   181,    -1,   182,
      -1,   119,   157,   158,   159,    -1,   148,   167,   159,    -1,
     148,   167,   160,   166,   161,    -1,   148,   160,   166,   161,
      -1,   107,   169,   159,    -1,   171,   159,    -1,   169,     8,
     170,    -1,   170,    -1,   167,    -1,   167,    93,    73,    -1,
     151,   167,    -1,   151,   167,    93,    73,    -1,   171,     8,
      73,    13,   241,    -1,   102,    73,    13,   241,    -1,   172,
     173,    -1,    -1,   174,    -1,   181,    -1,   182,    -1,   119,
     157,   158,   159,    -1,   175,    -1,    73,    26,    -1,   135,
      -1,   136,    -1,   138,    -1,   160,   172,   161,    -1,    67,
     157,   247,   158,   174,   202,   204,    -1,    67,   157,   247,
     158,    26,   172,   203,   205,    70,   159,    -1,    85,   157,
     247,   158,   201,    -1,    84,   174,    85,   157,   247,   158,
     159,    -1,    87,   157,   225,   159,   225,   159,   225,   158,
     194,    -1,    94,   157,   247,   158,   198,    -1,    98,   159,
      -1,    98,   247,   159,    -1,    99,   159,    -1,    99,   247,
     159,    -1,   103,   159,    -1,   103,   227,   159,    -1,   103,
     251,   159,    -1,   108,   211,   159,    -1,   114,   213,   159,
      -1,    83,   224,   159,    -1,    77,    -1,   247,   159,    -1,
     116,   157,   179,   158,   159,    -1,    89,   157,   251,    93,
     193,   192,   158,   195,    -1,    89,   157,   227,    93,   251,
     192,   158,   195,    -1,    91,   157,   197,   158,   196,    -1,
     159,    -1,   104,   160,   172,   161,   105,   157,   233,    75,
     158,   160,   172,   161,   176,    -1,   106,   247,   159,    -1,
     100,    73,   159,    -1,   177,    -1,    -1,   178,    -1,   177,
     178,    -1,   105,   157,   233,    75,   158,   160,   172,   161,
      -1,   180,    -1,   179,     8,   180,    -1,   251,    -1,   184,
      -1,   185,    -1,    -1,    31,    -1,   228,   183,    73,   157,
     206,   158,   160,   172,   161,    -1,   186,    73,   187,   190,
     160,   214,   161,    -1,   188,    73,   189,   160,   214,   161,
      -1,   120,    -1,   113,   120,    -1,   112,   120,    -1,    -1,
     122,   233,    -1,   121,    -1,    -1,   122,   191,    -1,    -1,
     123,   191,    -1,   233,    -1,   191,     8,   233,    -1,    -1,
     125,   193,    -1,   251,    -1,    31,   251,    -1,   174,    -1,
      26,   172,    88,   159,    -1,   174,    -1,    26,   172,    90,
     159,    -1,   174,    -1,    26,   172,    92,   159,    -1,    73,
      13,   241,    -1,   197,     8,    73,    13,   241,    -1,   160,
     199,   161,    -1,   160,   159,   199,   161,    -1,    26,   199,
      95,   159,    -1,    26,   159,   199,    95,   159,    -1,    -1,
     199,    96,   247,   200,   172,    -1,   199,    97,   200,   172,
      -1,    26,    -1,   159,    -1,   174,    -1,    26,   172,    86,
     159,    -1,    -1,   202,    68,   157,   247,   158,   174,    -1,
      -1,   203,    68,   157,   247,   158,    26,   172,    -1,    -1,
      69,   174,    -1,    -1,    69,    26,   172,    -1,   207,    -1,
      -1,   208,    75,    -1,   208,    31,    75,    -1,   208,    31,
      75,    13,   241,    -1,   208,    75,    13,   241,    -1,   207,
       8,   208,    75,    -1,   207,     8,   208,    31,    75,    -1,
     207,     8,   208,    31,    75,    13,   241,    -1,   207,     8,
     208,    75,    13,   241,    -1,    -1,   233,    -1,   127,    -1,
     210,    -1,    -1,   227,    -1,   251,    -1,    31,   249,    -1,
     210,     8,   227,    -1,   210,     8,   251,    -1,   210,     8,
      31,   249,    -1,   211,     8,   212,    -1,   212,    -1,    75,
      -1,   162,   248,    -1,   162,   160,   247,   161,    -1,   213,
       8,    75,    -1,   213,     8,    75,    13,   241,    -1,    75,
      -1,    75,    13,   241,    -1,   214,   215,    -1,    -1,   218,
     222,   159,    -1,   223,   159,    -1,    -1,   219,   228,   216,
     183,    73,   157,   206,   158,   217,    -1,   159,    -1,   160,
     172,   161,    -1,   220,    -1,   115,    -1,    -1,   220,    -1,
     221,    -1,   220,   221,    -1,   109,    -1,   110,    -1,   111,
      -1,   114,    -1,   113,    -1,   112,    -1,   222,     8,    75,
      -1,   222,     8,    75,    13,   241,    -1,    75,    -1,    75,
      13,   241,    -1,   223,     8,    73,    13,   241,    -1,   102,
      73,    13,   241,    -1,   224,     8,   247,    -1,   247,    -1,
      -1,   226,    -1,   226,     8,   247,    -1,   247,    -1,   126,
     157,   267,   158,    13,   247,    -1,   251,    13,   247,    -1,
     251,    13,    31,   251,    -1,   251,    13,    31,    65,   234,
     239,    -1,    65,   234,   239,    -1,    64,   247,    -1,   251,
      24,   247,    -1,   251,    23,   247,    -1,   251,    22,   247,
      -1,   251,    21,   247,    -1,   251,    20,   247,    -1,   251,
      19,   247,    -1,   251,    18,   247,    -1,   251,    17,   247,
      -1,   251,    16,   247,    -1,   251,    15,   247,    -1,   251,
      14,   247,    -1,   250,    62,    -1,    62,   250,    -1,   250,
      61,    -1,    61,   250,    -1,   247,    27,   247,    -1,   247,
      28,   247,    -1,   247,     9,   247,    -1,   247,    11,   247,
      -1,   247,    10,   247,    -1,   247,    29,   247,    -1,   247,
      31,   247,    -1,   247,    30,   247,    -1,   247,    44,   247,
      -1,   247,    42,   247,    -1,   247,    43,   247,    -1,   247,
      45,   247,    -1,   247,    46,   247,    -1,   247,    47,   247,
      -1,   247,    41,   247,    -1,   247,    40,   247,    -1,    42,
     247,    -1,    43,   247,    -1,    48,   247,    -1,    50,   247,
      -1,   247,    33,   247,    -1,   247,    32,   247,    -1,   247,
      35,   247,    -1,   247,    34,   247,    -1,   247,    36,   247,
      -1,   247,    39,   247,    -1,   247,    37,   247,    -1,   247,
      38,   247,    -1,   247,    49,   234,    -1,   157,   247,   158,
      -1,   247,    25,   247,    26,   247,    -1,   247,    25,    26,
     247,    -1,   271,    -1,    60,   247,    -1,    59,   247,    -1,
      58,   247,    -1,    55,   247,    -1,    54,   247,    -1,    53,
     247,    -1,    52,   247,    -1,    66,   238,    -1,    51,   247,
      -1,   127,   157,   269,   158,    -1,    82,    -1,   243,    -1,
      12,   247,    -1,   228,   183,   157,   206,   158,   229,   160,
     172,   161,    -1,   114,   228,   183,   157,   206,   158,   229,
     160,   172,   161,    -1,   101,    -1,    -1,   107,   157,   230,
     158,    -1,   230,     8,    75,    -1,   230,     8,    31,    75,
      -1,    75,    -1,    31,    75,    -1,   167,   157,   209,   158,
      -1,   148,   151,   167,   157,   209,   158,    -1,   151,   167,
     157,   209,   158,    -1,   232,   145,    73,   157,   209,   158,
      -1,   257,   145,    73,   157,   209,   158,    -1,   257,   145,
     255,   157,   209,   158,    -1,   232,   145,   255,   157,   209,
     158,    -1,   255,   157,   209,   158,    -1,   114,    -1,   167,
      -1,   148,   151,   167,    -1,   151,   167,    -1,   167,    -1,
     148,   151,   167,    -1,   151,   167,    -1,   232,    -1,   235,
      -1,   259,   124,   263,   236,    -1,   259,    -1,   236,   237,
      -1,    -1,   124,   263,    -1,    -1,   157,   158,    -1,   157,
     247,   158,    -1,    -1,   157,   209,   158,    -1,    71,    -1,
      72,    -1,    81,    -1,   131,    -1,   132,    -1,   150,    -1,
     128,    -1,   129,    -1,   130,    -1,   149,    -1,   142,    -1,
     240,    -1,   167,    -1,   148,   151,   167,    -1,   151,   167,
      -1,    42,   241,    -1,    43,   241,    -1,   127,   157,   244,
     158,    -1,   242,    -1,   232,   145,    73,    -1,    74,    -1,
     273,    -1,   167,    -1,   148,   151,   167,    -1,   151,   167,
      -1,   240,    -1,    -1,   246,   245,    -1,    -1,     8,    -1,
     246,     8,   241,   125,   241,    -1,   246,     8,   241,    -1,
     241,   125,   241,    -1,   241,    -1,   248,    -1,   227,    -1,
     251,    -1,   251,    -1,   251,    -1,   258,   124,   263,   254,
     252,    -1,   258,    -1,   252,   253,    -1,    -1,   124,   263,
     254,    -1,   157,   209,   158,    -1,    -1,   260,    -1,   266,
     260,    -1,   232,   145,   255,    -1,   257,   145,   255,    -1,
     260,    -1,   259,    -1,   231,    -1,   260,    -1,   266,   260,
      -1,   256,    -1,   260,    63,   262,   163,    -1,   260,   160,
     247,   161,    -1,   261,    -1,    75,    -1,   162,   160,   247,
     161,    -1,    -1,   247,    -1,   264,    -1,   255,    -1,   264,
      63,   262,   163,    -1,   264,   160,   247,   161,    -1,   265,
      -1,    73,    -1,   160,   247,   161,    -1,   162,    -1,   266,
     162,    -1,   267,     8,   268,    -1,   268,    -1,   251,    -1,
     126,   157,   267,   158,    -1,    -1,    -1,   270,   245,    -1,
     270,     8,   247,   125,   247,    -1,   270,     8,   247,    -1,
     247,   125,   247,    -1,   247,    -1,   270,     8,   247,   125,
      31,   249,    -1,   270,     8,    31,   249,    -1,   247,   125,
      31,   249,    -1,    31,   249,    -1,   117,   157,   272,   158,
      -1,   118,   157,   251,   158,    -1,     7,   247,    -1,     6,
     247,    -1,     5,   157,   247,   158,    -1,     4,   247,    -1,
       3,   247,    -1,   251,    -1,   272,     8,   251,    -1,   232,
     145,    73,    -1,   257,   145,    73,    -1,   247,    63,   262,
     163,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   202,   205,   211,   214,   220,   221,   222,
     223,   228,   235,   241,   249,   255,   262,   265,   272,   277,
     283,   289,   299,   306,   316,   319,   325,   326,   327,   328,
     336,   337,   343,   346,   349,   355,   358,   388,   403,   410,
     418,   431,   438,   445,   452,   459,   466,   473,   480,   487,
     492,   497,   502,   506,   510,   516,   533,   549,   555,   559,
     572,   580,   591,   592,   598,   602,   609,   620,   624,   631,
     635,   639,   643,   646,   652,   666,   677,   692,   696,   703,
     713,   716,   722,   726,   729,   737,   740,   748,   751,   757,
     760,   766,   767,   775,   776,   784,   785,   793,   794,   802,
     808,   819,   822,   832,   837,   849,   852,   860,   870,   871,
     875,   876,   884,   887,   897,   900,   910,   913,   921,   924,
     932,   933,   939,   947,   956,   965,   973,   981,   990,   999,
    1010,  1013,  1016,  1022,  1023,  1029,  1032,  1035,  1040,  1043,
    1046,  1052,  1056,  1063,  1066,  1070,  1077,  1085,  1093,  1101,
    1112,  1115,  1121,  1129,  1133,  1133,  1152,  1155,  1161,  1162,
    1169,  1172,  1179,  1183,  1189,  1190,  1191,  1192,  1193,  1194,
    1198,  1205,  1212,  1219,  1229,  1238,  1250,  1253,  1260,  1263,
    1268,  1271,  1278,  1286,  1292,  1302,  1316,  1322,  1327,  1333,
    1339,  1345,  1351,  1357,  1363,  1369,  1375,  1381,  1387,  1393,
    1398,  1403,  1408,  1413,  1419,  1425,  1431,  1437,  1443,  1449,
    1455,  1461,  1487,  1493,  1499,  1505,  1511,  1517,  1523,  1529,
    1534,  1539,  1544,  1549,  1555,  1561,  1567,  1573,  1579,  1585,
    1591,  1597,  1603,  1608,  1614,  1620,  1621,  1626,  1631,  1636,
    1641,  1646,  1651,  1656,  1661,  1666,  1672,  1676,  1677,  1682,
    1693,  1713,  1717,  1720,  1728,  1731,  1736,  1740,  1749,  1754,
    1760,  1766,  1774,  1782,  1790,  1798,  1806,  1809,  1812,  1816,
    1823,  1826,  1830,  1837,  1838,  1842,  1851,  1855,  1858,  1864,
    1870,  1873,  1877,  1885,  1888,  1894,  1897,  1900,  1903,  1906,
    1909,  1912,  1915,  1918,  1921,  1924,  1930,  1931,  1932,  1936,
    1940,  1945,  1950,  1956,  1960,  1968,  1969,  1970,  1971,  1974,
    1977,  1981,  1984,  1990,  1993,  1997,  2004,  2011,  2018,  2028,
    2029,  2033,  2037,  2041,  2045,  2065,  2069,  2072,  2078,  2088,
    2091,  2097,  2098,  2113,  2118,  2126,  2130,  2131,  2135,  2136,
    2148,  2152,  2158,  2164,  2168,  2171,  2179,  2182,  2188,  2189,
    2193,  2199,  2205,  2209,  2213,  2219,  2222,  2237,  2240,  2247,
    2248,  2253,  2259,  2262,  2268,  2275,  2282,  2289,  2296,  2303,
    2310,  2317,  2327,  2337,  2347,  2350,  2353,  2363,  2366,  2372,
    2376,  2382,  2387,  2400
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
  "T_CALLABLE", "T_TRAIT", "T_TRAIT_C", "T_YIELD", "'('", "')'", "';'",
  "'{'", "'}'", "'$'", "']'", "$accept", "start", "top_statement_list",
  "namespace_name", "top_statement", "use_declarations", "use_declaration",
  "constant_declaration", "inner_statement_list", "inner_statement",
  "statement", "unticked_statement", "additional_catches",
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
  "class_statement_list", "class_statement", "@1", "method_body",
  "variable_modifiers", "method_modifiers", "non_empty_member_modifiers",
  "member_modifier", "class_variable_declaration",
  "class_constant_declaration", "echo_expr_list", "for_expr",
  "non_empty_for_expr", "expr_without_variable", "function",
  "lexical_vars", "lexical_var_list", "function_call", "class_name",
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
     386,   387,   388,   389,   390,   391,   392,    40,    41,    59,
     123,   125,    36,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   164,   165,   166,   166,   167,   167,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   169,   170,   170,
     170,   170,   171,   171,   172,   172,   173,   173,   173,   173,
     174,   174,   174,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   176,   176,   177,   177,   178,   179,   179,   180,
     181,   182,   183,   183,   184,   185,   185,   186,   186,   186,
     187,   187,   188,   189,   189,   190,   190,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195,   196,   196,   197,
     197,   198,   198,   198,   198,   199,   199,   199,   200,   200,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   207,   207,   207,   207,   207,   207,
     208,   208,   208,   209,   209,   210,   210,   210,   210,   210,
     210,   211,   211,   212,   212,   212,   213,   213,   213,   213,
     214,   214,   215,   215,   216,   215,   217,   217,   218,   218,
     219,   219,   220,   220,   221,   221,   221,   221,   221,   221,
     222,   222,   222,   222,   223,   223,   224,   224,   225,   225,
     226,   226,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   228,   229,   229,   230,   230,   230,   230,   231,   231,
     231,   231,   231,   231,   231,   231,   232,   232,   232,   232,
     233,   233,   233,   234,   234,   235,   235,   236,   236,   237,
     238,   238,   238,   239,   239,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   241,   241,   241,   241,
     241,   241,   241,   241,   242,   243,   243,   243,   243,   243,
     243,   244,   244,   245,   245,   246,   246,   246,   246,   247,
     247,   248,   249,   250,   251,   251,   252,   252,   253,   254,
     254,   255,   255,   256,   256,   257,   258,   258,   259,   259,
     259,   260,   260,   260,   261,   261,   262,   262,   263,   263,
     264,   264,   264,   265,   265,   266,   266,   267,   267,   268,
     268,   268,   269,   269,   270,   270,   270,   270,   270,   270,
     270,   270,   271,   271,   271,   271,   271,   271,   271,   272,
     272,   273,   273,   227
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     1,     1,     1,
       4,     3,     5,     4,     3,     2,     3,     1,     1,     3,
       2,     4,     5,     4,     2,     0,     1,     1,     1,     4,
       1,     2,     1,     1,     1,     3,     7,    10,     5,     7,
       9,     5,     2,     3,     2,     3,     2,     3,     3,     3,
       3,     3,     1,     2,     5,     8,     8,     5,     1,    13,
       3,     3,     1,     0,     1,     2,     8,     1,     3,     1,
       1,     1,     0,     1,     9,     7,     6,     1,     2,     2,
       0,     2,     1,     0,     2,     0,     2,     1,     3,     0,
       2,     1,     2,     1,     4,     1,     4,     1,     4,     3,
       5,     3,     4,     4,     5,     0,     5,     4,     1,     1,
       1,     4,     0,     6,     0,     7,     0,     2,     0,     3,
       1,     0,     2,     3,     5,     4,     4,     5,     7,     6,
       0,     1,     1,     1,     0,     1,     1,     2,     3,     3,
       4,     3,     1,     1,     2,     4,     3,     5,     1,     3,
       2,     0,     3,     2,     0,     9,     1,     3,     1,     1,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     5,     1,     3,     5,     4,     3,     1,     0,     1,
       3,     1,     6,     3,     4,     6,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     1,     1,     2,     9,
      10,     1,     0,     4,     3,     4,     1,     2,     4,     6,
       5,     6,     6,     6,     6,     4,     1,     1,     3,     2,
       1,     3,     2,     1,     1,     4,     1,     2,     0,     2,
       0,     2,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     2,     4,     1,     3,     1,     1,     1,     3,     2,
       1,     0,     2,     0,     1,     5,     3,     3,     1,     1,
       1,     1,     1,     1,     5,     1,     2,     0,     3,     3,
       0,     1,     2,     3,     3,     1,     1,     1,     1,     2,
       1,     4,     4,     1,     1,     4,     0,     1,     1,     1,
       4,     4,     1,     1,     3,     1,     2,     3,     1,     1,
       4,     0,     0,     2,     5,     3,     3,     1,     6,     4,
       4,     2,     4,     4,     2,     2,     4,     2,     2,     1,
       3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,     0,   285,   286,
       5,   305,   344,    52,   287,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   251,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
      77,    82,     0,     0,   291,   292,   293,   288,   289,    32,
      33,    34,   295,     0,   294,   290,     0,     0,    58,    25,
     355,   307,     3,     0,     7,    30,     8,     9,    70,    71,
       0,     0,   320,    72,   337,     0,   310,   247,     0,   319,
       0,   321,     0,   340,     0,   325,   336,   338,   343,     0,
     235,   306,     5,   266,     0,    72,   378,   377,     0,   375,
     374,   248,   219,   220,   221,   222,   244,   242,   241,   240,
     239,   238,   237,   236,   266,     0,     0,   267,     0,   202,
     323,     0,   200,   187,     0,     0,   267,   273,   283,   274,
       0,   276,   338,     0,     0,   243,     0,    31,     0,   177,
       0,     0,   178,     0,     0,     0,    42,     0,    44,     0,
       0,     0,    46,   320,     0,   321,    25,     0,     0,    18,
       0,    17,   143,     0,     0,   142,    79,    78,   148,     0,
      72,     0,     0,     0,     0,   361,   362,     0,     4,     0,
     309,     0,     0,     0,     0,   134,     0,    15,    80,    83,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   346,
      53,   201,   199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,   346,     0,
     356,   339,     0,     0,     0,   269,     0,     0,     0,   269,
       0,   134,   186,     0,     0,   339,   281,     0,     0,     0,
      51,     0,     0,     0,   179,   181,   320,   321,     0,     0,
       0,    43,    45,    61,     0,    47,    48,     0,    60,    20,
       0,     0,    14,     0,   144,   321,     0,    49,     0,     0,
      50,     0,     0,    67,    69,   379,     0,     0,     0,     0,
     359,     0,   358,     0,   367,     0,   313,   308,     0,    11,
       4,   134,   232,     0,    35,    24,    26,    27,    28,     0,
       6,     0,     0,   133,   320,   321,     0,     0,    85,     0,
       0,     0,   130,   381,   333,   331,     0,   205,   207,   206,
       0,     0,   203,   204,   208,   210,   209,   224,   223,   226,
     225,   227,   229,   230,   228,   218,   217,   212,   213,   211,
     214,   215,   216,   231,   347,     0,     0,   183,   198,   197,
     196,   195,   194,   193,   192,   191,   190,   189,   188,     0,
     382,   334,   353,     0,   349,   330,   348,   352,     0,     0,
     376,   268,     0,     0,   268,   333,     0,   334,   278,   282,
       0,   176,     0,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,   296,
      23,   303,     0,     0,    19,    16,     0,   141,   149,   146,
     130,     0,     0,     0,   372,   373,    10,   361,   361,     0,
     371,   322,     0,   245,   314,   363,   134,    13,     0,     0,
       0,   345,   137,   258,     0,     0,     0,     0,   270,    81,
       0,     0,    84,    87,   151,   130,   132,     0,   120,     0,
     131,   134,   134,   332,   234,     0,   383,     0,   184,   265,
     134,   134,     0,   134,   327,   346,     0,   341,   342,   284,
     275,    25,   112,     0,    25,   110,    38,     0,   180,    89,
       0,    89,    91,    99,     0,    25,    97,    57,   105,   105,
      41,   300,   301,   311,     0,   299,     0,     0,    21,   145,
       0,     0,    68,    54,   380,     0,   357,     0,     0,   366,
       0,   365,     0,    12,   260,     0,     0,   320,   321,    22,
       0,   272,    86,   151,     0,   160,     0,   252,   130,     0,
     122,     0,     0,   233,   283,     0,     0,   354,     0,   324,
       0,     0,     0,   277,   114,   116,     0,     0,   178,     0,
       0,    92,     0,     0,     0,   105,     0,   105,     0,   318,
       0,   313,   298,   304,     0,   147,   252,   360,   182,   370,
     369,     0,   259,    29,   140,   271,   160,    88,     0,   164,
     165,   166,   169,   168,   167,   159,    76,   150,     0,     0,
     158,   162,     0,     0,     0,     0,     0,   123,     0,   261,
     264,   185,   262,   263,   329,     0,   326,   350,   351,   279,
     118,     0,     0,    36,    39,     0,     0,    90,     0,     0,
     100,     0,     0,     0,     0,     0,     0,   101,     0,   302,
     314,   312,     0,     0,     0,   364,    75,     0,   172,     0,
     154,   163,     0,   153,    25,     0,    25,     0,   126,     0,
     125,   330,     0,     0,     0,     0,   117,   111,     0,    25,
      95,    56,    55,    98,     0,   103,     0,   108,   109,    25,
     102,   317,   316,     0,    25,   368,     0,     0,     0,   152,
      72,     0,     0,     0,   256,     0,     0,   127,     0,   124,
     328,     0,    25,     0,     0,    25,    93,    40,     0,   104,
      25,   107,     0,     0,     0,   175,   173,   170,     0,     0,
      74,   257,     0,   253,   249,     0,   129,     0,   119,    37,
       0,     0,     0,   106,   315,    25,   250,     0,     0,   174,
       0,   254,   128,     0,   113,     0,    96,     0,   171,   130,
     255,    25,    94,    63,     0,   115,     0,    59,    62,    64,
       0,     0,    65,   156,    25,   155,     0,     0,     0,   157,
       0,    25,     0,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    81,    82,   180,   181,    83,   202,   335,
     336,    85,   787,   788,   789,   312,   313,   337,   338,   211,
      88,    89,    90,   348,    91,   350,   481,   482,   590,   521,
     737,   701,   527,   289,   530,   596,   709,   516,   585,   650,
     653,   694,   487,   488,   489,   342,   343,   184,   185,   189,
     565,   627,   720,   795,   628,   629,   630,   631,   679,   632,
     158,   283,   284,    92,   115,   635,   725,    94,    95,   490,
     148,   149,   510,   583,   155,   272,    96,   440,   441,    97,
     600,   465,   601,    98,    99,   460,   100,   101,   579,   646,
     504,   102,   103,   104,   105,   106,   107,   108,   385,   405,
     406,   407,   109,   321,   322,   325,   326,   110,   316,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -448
static const yytype_int16 yypact[] =
{
    -448,    62,  1789,  -448,  6169,  6169,   -85,  6169,  6169,  6169,
    6169,  6169,  6169,  6169,  6169,  6169,  6169,  6169,  6169,  6169,
    6169,  6169,   201,   201,  6169,   339,   -71,   -66,  -448,  -448,
      67,  -448,  -448,  -448,  -448,  -448,  6169,  4449,   -44,   -35,
       3,    37,    53,  4589,  4720,   124,  -448,   141,  4851,    59,
    6169,   -16,   -25,   102,   111,    70,    76,    79,    83,   123,
    -448,  -448,   126,   128,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,   -43,  -448,  -448,   175,  6169,  -448,  -448,
     108,    66,  -448,    13,  -448,  -448,  -448,  -448,  -448,  -448,
     217,   221,  -448,   261,  -448,   158,  -448,  -448,  6579,  -448,
      44,  1477,   148,  -448,   169,   194,  -448,   -36,  -448,   -20,
    -448,  -448,  -448,   222,   174,   261,  7251,  7251,  6169,  7251,
    7251,  7325,   271,   271,    21,   271,   271,   271,   271,   271,
     271,   271,   271,   271,  -448,   200,   175,   -68,   220,  -448,
    -448,   223,  -448,  -448,   211,   175,   213,   225,   215,  -448,
     228,   264,   -30,   -20,  4982,  -448,  6169,  -448,    14,  7251,
     322,  6169,  6169,  6169,   335,  6169,  -448,  6621,  -448,  6662,
     254,   404,  -448,   259,  7251,   935,  -448,  6712,   175,   -41,
      18,  -448,  -448,    90,    20,  -448,  -448,  -448,   407,    23,
     261,   201,   201,   201,   268,   196,  5114,   175,  -448,   153,
     209,   868,  1929,  6169,   349,  5246,   354,  -448,   307,   308,
    -448,    -4,    -8,  6169,  6169,  6169,  5378,  6169,  6169,  6169,
    6169,  6169,  6169,  6169,  6169,  6169,  6169,  6169,  6169,  6169,
    6169,  6169,  6169,  6169,  6169,  6169,  6169,  6169,   339,  6169,
    -448,  -448,  -448,  5510,  6169,  6169,  6169,  6169,  6169,  6169,
    6169,  6169,  6169,  6169,  6169,  5246,    41,   -24,  6169,  6169,
     108,   -34,   275,  6754,   175,   -63,    45,    58,   175,   213,
       0,  5246,  -448,     0,   -24,   -28,  -448,  6795,  6845,  6169,
    -448,   280,  6886,   286,   438,  7251,   357,  1206,   446,    30,
    6927,  -448,  -448,  -448,  1061,  -448,  -448,  2069,  -448,   -39,
     388,   -16,  -448,  6169,  -448,  -448,   -25,  -448,  1061,   387,
    -448,   310,    31,  -448,  -448,  -448,    32,   306,   312,   315,
    -448,    33,  -448,   201,  7109,   317,   457,   210,  1509,  -448,
    -448,  5246,  -448,   321,  -448,  -448,  -448,  -448,  -448,  6305,
    -448,   201,   324,   471,    34,   363,   470,    19,   362,    19,
     328,   332,    91,   336,   340,   -28,   -20,  1408,  7288,  7325,
    6169,  7210,  7398,  7433,  4642,  4773,  4904,  5035,  5035,  5035,
    5035,  5161,  5161,  5161,  5161,   510,   510,   282,   282,   282,
      21,    21,    21,  -448,  7251,   329,    -7,  7325,  7325,  7325,
    7325,  7325,  7325,  7325,  7325,  7325,  7325,  7325,  7325,   333,
     341,   342,  -448,  6169,  -448,   343,   -26,  -448,   344,  6346,
    -448,    55,   336,   341,   213,  -448,   338,  -448,  -448,  -448,
    3749,  7251,  6169,  3889,  6169,  6169,   201,    54,  1061,   431,
    4029,    -3,  1061,  1061,   348,   355,   175,    84,   364,  -448,
    -448,  -448,   405,   440,  -448,  -448,  6387,  -448,  -448,   498,
      91,   201,   356,   201,  -448,  -448,  -448,   196,   196,   505,
    -448,  -448,  5642,  -448,  5774,  -448,  5246,  -448,  1649,   361,
     366,  -448,  -448,  -448,  5906,  1061,   371,   175,   213,  -448,
      19,   365,   518,  -448,  -448,    91,  -448,   370,   521,    29,
    -448,  5246,  5246,   -28,  7362,  6169,  -448,   339,  -448,  -448,
    5246,  5246,  6442,  5246,  -448,  6169,  6169,  -448,  -448,  -448,
     406,  -448,  -448,  6977,  -448,  -448,  -448,   373,  7251,   409,
     201,   409,  -448,  -448,   522,  -448,  -448,  -448,   377,   379,
    -448,  -448,  -448,  1061,   175,   113,   468,   389,  -448,  -448,
    1061,   386,  -448,  -448,  -448,    35,  -448,  6169,   201,  7251,
     201,  7150,   390,  -448,  -448,   399,   201,    38,   382,  -448,
     175,   213,   518,  -448,    19,   -12,   391,   454,    86,   487,
     532,   408,   416,  7362,   215,   417,   419,  -448,   422,   441,
     418,  6483,   -24,  -448,  3609,   219,   424,  2209,  6169,    54,
     426,  -448,   428,  1061,  2349,  -448,   297,  -448,   -18,   442,
     430,   581,   121,  -448,    19,  -448,   454,  -448,  7325,  -448,
    -448,  6038,  -448,  -448,  -448,   213,   187,  -448,   535,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,   516,   222,
     489,  -448,    24,   434,   453,   451,    64,   599,  1061,  -448,
    -448,  -448,  -448,  -448,  -448,   -24,  -448,  -448,  -448,  -448,
     252,   456,  4449,  -448,  -448,   455,   458,  -448,  4169,  4169,
    -448,   459,   359,   460,  6169,    -1,   112,  -448,  1061,  -448,
    1061,  -448,   540,   463,   201,  7251,  -448,   604,   607,    28,
    -448,  -448,   551,  -448,  -448,    94,  -448,   550,   613,  1061,
    -448,   343,   473,   602,   561,  6169,  -448,  -448,  4309,  -448,
    -448,  -448,  -448,  -448,   474,  -448,  6524,  -448,  -448,  -448,
    -448,  -448,   511,   477,  -448,  -448,  1061,  1061,   562,  -448,
     261,   625,  2489,   564,  -448,    40,  2629,   627,  1061,  -448,
    -448,  6169,  -448,   482,  7018,  -448,  -448,  -448,  2769,  -448,
    -448,  3609,  1061,   483,  2909,  -448,  -448,   631,   572,  1061,
    -448,  -448,   120,  -448,  -448,  1061,  -448,  7059,  3609,  -448,
    4449,  3049,   488,  3609,  -448,  -448,  -448,  1061,   491,  -448,
     571,  -448,  -448,   623,  -448,   493,  -448,  3189,  -448,    91,
    -448,  -448,  -448,   545,   496,  3609,   499,  -448,   545,  -448,
     181,    19,  -448,  -448,  -448,  -448,   583,  3329,   497,  -448,
     501,  -448,  3469,  -448
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -448,  -448,  -174,   -17,  -448,  -448,   358,  -448,  -172,  -448,
       8,  -448,  -448,  -448,  -126,  -448,   212,     5,     9,  -114,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,   184,   144,    80,
    -448,    11,  -448,  -448,  -448,  -447,   -38,  -448,  -448,  -448,
    -448,  -448,  -441,  -448,   103,  -184,  -448,  -448,   367,  -448,
     114,  -448,  -448,  -448,  -448,  -448,  -448,    46,  -448,  -448,
    -448,  -404,  -448,   104,    -2,    68,  -448,  -448,   256,  -334,
    -222,  -448,  -448,  -448,  -448,   101,  -247,   580,  -448,  -448,
    -448,    77,  -448,   814,   502,  -324,   334,   914,  -448,  -448,
     -10,  -193,  -448,   969,  -448,   -23,   -13,  -448,  -240,  -271,
    -448,  -448,   -11,   229,   232,  -448,  -448,  -448,  -448,  -448
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -336
static const yytype_int16 yytable[] =
{
      93,   262,   151,   418,   297,   137,   137,    86,   146,   541,
      84,    87,   152,   479,   153,   483,   383,   472,   408,   354,
     517,   206,   279,   528,   328,   707,   301,   258,   306,   258,
     112,   309,   682,   258,   179,   258,   718,   505,   429,   451,
     453,   458,  -135,   458,   566,   160,  -138,   439,   752,   402,
     182,    32,   300,   190,   443,    32,   199,   112,   497,   200,
     569,   439,     3,   401,   404,   353,   112,    32,    32,   351,
     238,   399,   118,   354,   401,    32,   311,   415,   664,   665,
     417,   404,   598,   204,   239,   520,   154,   416,   204,   205,
     618,   156,   112,   157,   331,   687,   261,   619,   620,   621,
     622,   623,   624,   625,   570,   241,   242,   134,   197,  -335,
     204,   190,   204,   161,   400,  -335,    32,   198,   412,   265,
      32,  -331,   162,  -332,   259,   723,   259,   112,   269,    32,
     259,   413,   259,    32,   506,   178,   403,   183,    80,   688,
     275,   135,   260,   667,   136,   188,   483,   469,   662,   626,
     666,   770,   173,   352,    80,    80,   468,   529,   708,   112,
     163,   299,    80,   112,   112,    32,   137,   476,   134,   724,
     477,    46,   207,   280,   137,   137,   137,   302,   137,   307,
     327,   439,   310,   683,   656,   439,   439,   719,   430,   452,
     454,   459,  -135,   607,   164,   771,  -138,   170,   753,   355,
      93,   356,   135,    80,   134,   136,   204,    80,   664,   665,
     165,  -267,   466,   486,   171,   151,    80,   204,   486,   176,
      80,   146,   186,   205,   609,   152,   610,   153,   439,  -267,
     617,   187,   614,   191,   476,   204,   192,   477,   135,   476,
     193,   136,   477,   355,   355,   356,   356,   411,   112,  -121,
     303,   414,    80,   355,   355,   356,   356,   355,  -269,   356,
     355,   355,   356,   356,   204,   580,  -268,   286,   203,   112,
     672,    32,   204,   710,   112,   574,    32,   437,   138,   138,
     194,   147,   552,   195,   179,   196,   439,   651,   652,   618,
     208,   437,   210,   439,   209,    93,   619,   620,   621,   622,
     623,   624,   625,   212,   204,   255,   137,   571,   572,   344,
     134,   649,   329,   330,   256,   134,   575,   576,   257,   578,
     692,   693,   319,    46,   137,   197,    93,   235,   236,   237,
     478,   238,   478,    86,   239,   478,    84,    87,   784,   584,
     793,   794,   587,   493,   135,   239,   439,   136,   676,   135,
     715,   264,   136,   594,  -269,  -268,   139,   142,    80,   344,
     204,   204,   268,    80,   204,   266,   331,   466,   267,   137,
     270,  -136,   271,   273,   691,   344,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   274,   404,
    -139,   439,   663,   664,   665,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   281,   288,   137,
     137,   437,   112,   293,    32,   437,   437,   294,   295,   535,
     308,   439,   340,   439,  -323,  -323,   318,   346,   512,   347,
     349,   515,   352,   478,   137,   344,   137,   422,   526,   138,
     137,   137,   439,  -323,  -323,   424,   425,   138,   138,   138,
     426,   138,   404,   134,   704,   664,   665,   796,   437,   428,
     561,   444,   449,   478,   455,   464,    93,   450,   478,   439,
     439,   456,   457,    86,   151,   463,    84,    87,   470,   474,
     146,   439,   473,   475,   152,   480,   153,   144,   484,   485,
     145,   499,   496,   491,   147,   439,   509,   492,   500,   501,
     503,    80,   439,   137,   524,   533,   534,   507,   439,   536,
     537,   540,   722,   538,   726,   543,   437,   602,   547,   554,
     439,  -136,   560,   437,   555,   563,   564,   738,   567,   568,
     582,   137,   588,   137,   589,   593,   595,   741,   597,   137,
    -139,   603,   744,   615,   606,   638,   604,   478,   612,   633,
     438,   478,   232,   233,   234,   235,   236,   237,   613,   238,
     758,   634,   637,   761,   438,   645,   639,   668,   763,   355,
     344,   356,   137,   239,   640,   642,   437,   643,   557,   138,
     644,   647,    93,   654,   658,    93,   659,   478,   669,   670,
    -161,   678,    93,   777,   684,   344,   344,   138,   619,   620,
     621,   622,   623,   624,   344,   344,   748,   344,   677,   785,
     685,   686,   689,   695,   697,   713,   698,   716,   703,   705,
     717,   437,   797,   714,   721,   727,   728,   680,   732,   802,
     731,   733,   355,   739,   356,   743,   742,   747,   749,   751,
     755,   759,   138,   765,   767,   768,   780,   776,   779,   781,
     786,   437,   782,   437,   790,   800,   791,   137,   798,   445,
     696,   801,   792,   542,   562,   592,   700,   700,   740,   657,
     702,   636,   437,   447,   673,   641,   681,   616,   671,     0,
       0,   730,   138,   138,   438,   304,   545,     0,   438,   438,
     546,     0,     0,     0,     0,     0,     0,     0,     0,   437,
     437,     0,     0,     0,     0,     0,   736,   138,     0,   138,
       0,   437,     0,   138,   138,     0,     0,     0,     0,     0,
      93,     0,     0,     0,    93,   437,     0,     0,     0,     0,
       0,   438,   437,     0,     0,     0,    93,     0,   437,    93,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
     437,     0,     0,   147,     0,     0,    93,     0,     0,    93,
       0,    93,   478,     0,     0,     0,     0,     0,   774,     0,
       0,     0,     0,     0,   478,    93,   138,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,   438,
       0,     0,     0,     0,     0,    93,   438,     0,     0,     0,
      93,     0,     0,     0,   138,     0,   138,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,   116,   117,
       0,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,   143,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   438,
     159,     0,     0,     0,     0,     0,     0,   167,   169,     0,
       0,     0,   174,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   214,   215,
       0,     0,     0,     0,     0,     0,     0,     0,   448,     0,
       0,   201,     0,   216,   438,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,     0,
       0,     0,     0,     0,   438,     0,   438,     0,     0,     0,
     138,   239,   263,     0,     0,     0,   140,   140,     0,     0,
       0,     0,     0,     0,     0,   438,     0,     0,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
       0,     0,   175,     0,     0,     0,     0,     0,   277,     0,
     278,     0,   438,   438,     0,   282,   285,   174,     0,   290,
       0,     0,     0,     0,   438,     0,     0,     0,     0,     0,
       0,   141,   141,     0,   150,     0,  -323,  -323,   438,     0,
       0,     0,     0,     0,     0,   438,     0,     0,   523,     0,
     324,   438,   531,   532,     0,     0,     0,   339,     0,   174,
       0,     0,     0,   438,     0,     0,   332,   357,   358,   359,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,     0,   384,     0,   559,     0,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   174,
       0,     0,   384,   409,     0,     0,     0,   287,     0,     0,
       0,     0,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,   421,   296,     0,     0,   305,     0,     0,
       0,     0,     0,   432,   433,   314,   315,   317,     0,   320,
       0,     0,     0,   599,     0,     0,     0,   446,     0,   345,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,   112,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,   174,     0,     0,     0,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,     0,
     141,   141,   141,     0,   141,     0,     0,     0,     0,   345,
       0,     0,     0,   660,   494,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   345,     0,     0,   434,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,   150,     0,   435,
      74,    75,   436,     0,     0,     0,     0,   502,   690,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,     0,     0,     0,     0,   513,   461,   285,   518,
       0,     0,     0,     0,     0,   345,     0,     0,   711,     0,
     712,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -323,  -323,   729,
       0,     0,     0,     0,     0,     0,   549,     0,   551,     0,
     174,     0,     0,     0,     0,     0,     0,     0,   174,     0,
       0,     0,   141,     0,     0,     0,   745,   746,     0,   427,
     498,     0,     0,     0,     0,   174,   174,     0,   756,   573,
     141,     0,     0,     0,   174,   174,     0,   174,     0,   384,
     581,     0,   764,     0,     0,     0,     0,     0,     0,   769,
       0,     0,     0,     0,     0,   772,     0,     0,     0,     0,
     519,   522,     0,     0,     0,     0,     0,   778,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,   608,     0,     0,     0,   314,     0,   544,     0,     0,
       0,   320,   320,     0,     0,     0,     0,     0,     0,     0,
     345,     0,     0,     0,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,     0,   141,   141,     0,     0,     0,
       0,     0,   285,     0,     0,   345,   345,     0,     0,     0,
       0,     0,     0,     0,   345,   345,     0,   345,   214,   215,
     141,     0,   141,     0,     0,   675,   141,   141,     0,     0,
       0,     0,     0,   216,   591,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,     0,
       0,     0,   461,     0,   461,     0,   150,     0,     0,     0,
     461,   239,     0,     0,     0,     0,     0,     0,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,     0,   522,     0,     0,     0,     0,     0,   734,
       0,     0,     4,     5,     6,     7,     8,   141,     0,   141,
       0,     9,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -323,  -323,
       0,     0,     0,     0,     0,   757,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,   141,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,   461,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,   141,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,    73,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     467,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,    73,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     553,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,    73,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     334,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     442,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,   655,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,   661,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     750,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     754,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,   762,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     766,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,   775,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     783,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     799,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
     803,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,   333,    60,
      61,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,     0,     0,    55,     0,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,   514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,     0,     0,    55,     0,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,   525,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,     0,     0,    55,     0,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,   699,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,     0,     0,    55,     0,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,   735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,     0,     0,    55,     0,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,     0,     0,     0,
      28,    29,    30,    31,    32,     0,    33,     0,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
      46,     0,    48,    49,     0,    50,     0,    52,     0,     0,
       0,     0,     0,    55,     0,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,    69,    70,     0,    71,     0,     0,
       0,    72,     4,     5,     6,     7,     8,   114,    74,    75,
      76,     9,     0,     0,     0,     0,    77,     0,    78,    79,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,     0,     0,     0,     0,
      28,    29,   112,    31,    32,     0,     0,     0,     0,     0,
      34,    35,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
      46,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,   239,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     4,     5,     6,     7,     8,     0,     0,
       0,    72,     9,     0,     0,     0,     0,   114,    74,    75,
      76,     0,     0,     0,     0,     0,    77,     0,   166,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,     0,    24,    25,    26,     0,     0,     0,
       0,    28,    29,   112,    31,    32,     0,     0,     0,     0,
       0,    34,    35,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    46,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,   239,    57,    58,     0,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,     0,     4,     5,     6,     7,     8,     0,
       0,     0,    72,     9,     0,     0,     0,     0,   114,    74,
      75,    76,     0,     0,     0,     0,     0,    77,     0,   168,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    21,    22,    23,     0,    24,    25,    26,     0,     0,
       0,     0,    28,    29,   112,    31,    32,     0,     0,     0,
       0,     0,    34,    35,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    46,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,   239,    57,    58,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,     0,     4,     5,     6,     7,     8,
       0,     0,     0,    72,     9,     0,     0,     0,     0,   114,
      74,    75,    76,     0,     0,     0,     0,     0,    77,     0,
     172,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,     0,    24,    25,    26,     0,
       0,     0,     0,    28,    29,   112,    31,    32,     0,     0,
       0,     0,     0,    34,    35,     0,     0,  -336,  -336,  -336,
    -336,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    46,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   239,    57,
      58,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     4,     5,     6,
       7,     8,     0,     0,    72,     0,     9,     0,     0,     0,
     114,    74,    75,    76,     0,     0,     0,     0,     0,    77,
     276,     0,     0,     0,    80,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,     0,    24,    25,
      26,     0,     0,     0,     0,    28,    29,   112,    31,    32,
       0,     0,     0,     0,     0,    34,    35,  -336,  -336,  -336,
    -336,   230,   231,   232,   233,   234,   235,   236,   237,     0,
     238,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,   113,     0,
       0,    57,    58,     0,     0,     0,     0,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,     0,     0,     4,
       5,     6,     7,     8,     0,     0,    72,     0,     9,     0,
       0,     0,   114,    74,    75,    76,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,    80,   341,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,     0,
      24,    25,    26,     0,     0,     0,     0,    28,    29,   112,
      31,    32,     0,     0,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,    57,    58,     0,     0,     0,     0,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,     0,
       0,     4,     5,     6,     7,     8,     0,     0,    72,     0,
       9,     0,     0,     0,   114,    74,    75,    76,     0,     0,
       0,     0,     0,    77,   360,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,     0,    24,    25,    26,     0,     0,     0,     0,    28,
      29,   112,    31,    32,     0,     0,     0,     0,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,    57,    58,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     4,     5,     6,     7,     8,     0,     0,
      72,     0,     9,     0,     0,     0,   114,    74,    75,    76,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
      80,   386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,     0,    24,    25,    26,     0,     0,     0,
       0,    28,    29,   112,    31,    32,     0,     0,     0,     0,
       0,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,    57,    58,     0,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,     0,     0,     4,     5,     6,     7,     8,
       0,     0,    72,     0,     9,     0,     0,     0,   114,    74,
      75,    76,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,    80,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,    23,     0,    24,    25,    26,     0,
       0,     0,     0,    28,    29,   112,    31,    32,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,    57,
      58,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     4,     5,     6,
       7,     8,     0,     0,    72,     0,     9,     0,     0,     0,
     114,    74,    75,    76,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,    80,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    21,    22,    23,     0,    24,    25,
      26,     0,     0,     0,     0,    28,    29,   112,    31,    32,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,    57,    58,     0,     0,     0,     0,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,     0,     0,     4,
       5,     6,     7,     8,     0,     0,    72,     0,     9,     0,
       0,     0,   114,    74,    75,    76,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,    80,   556,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,    21,    22,    23,     0,
      24,    25,    26,     0,     0,     0,     0,    28,    29,   112,
      31,    32,     0,     0,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,    57,    58,     0,     0,     0,     0,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,     0,
       0,     4,     5,     6,     7,     8,     0,     0,    72,     0,
       9,     0,     0,     0,   114,    74,    75,    76,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,    80,   674,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,    21,    22,
      23,     0,    24,    25,    26,     0,     0,     0,     0,    28,
      29,   112,    31,    32,     0,     0,     0,     0,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,    57,    58,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      72,     9,     0,     0,     0,     0,   114,    74,    75,    76,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,     0,     0,     0,     0,
      28,    29,   112,    31,    32,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,    57,    58,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,     0,   213,   214,   215,   114,    74,    75,
      76,     0,     0,     0,     0,     0,    77,     0,     0,     0,
     216,    80,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     0,   238,   213,   214,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,   216,     0,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,   213,   214,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,   216,     0,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   213,   214,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,   216,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,   213,   214,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,   508,   216,     0,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,   238,   213,   214,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,     0,   539,   216,
     707,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   213,   214,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   577,   216,     0,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     0,   238,     0,
     213,   214,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     0,   648,     0,   216,     0,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
     238,   213,   214,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   708,   239,     0,     0,   216,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,   214,   215,     0,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   216,   240,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   213,   214,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,     0,     0,   216,
     291,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,   213,   214,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,     0,     0,
     216,   292,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     0,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,   214,   215,     0,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   298,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     0,   238,   213,   214,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,   216,   410,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,   213,   214,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,   216,   419,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,   214,   215,     0,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   420,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     0,   238,   213,   214,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,     0,     0,   216,   423,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,   213,   214,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,   216,   431,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     0,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,   586,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     0,   238,   213,
     214,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     0,     0,   216,   760,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,     0,     0,   773,     0,   213,
     214,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   462,   216,   495,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
     213,   214,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,   611,   216,     0,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   215,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   216,   239,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   239,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     0,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239
};

static const yytype_int16 yycheck[] =
{
       2,   115,    25,   274,   176,    22,    23,     2,    25,   450,
       2,     2,    25,   347,    25,   349,   238,   341,   258,   212,
     424,     8,     8,    26,   198,    26,     8,    63,     8,    63,
      73,     8,     8,    63,    51,    63,     8,    63,     8,     8,
       8,     8,     8,     8,   485,    37,     8,   294,     8,    73,
      75,    75,    93,    55,    93,    75,    73,    73,    65,    76,
      31,   308,     0,   256,   257,    73,    73,    75,    75,    73,
      49,   255,   157,   266,   267,    75,   190,   270,    96,    97,
     273,   274,   529,   151,    63,    31,   157,   271,   151,   157,
     102,   157,    73,    26,   157,    31,   109,   109,   110,   111,
     112,   113,   114,   115,    75,    61,    62,   114,   151,   145,
     151,   113,   151,   157,    73,   145,    75,   160,    73,   136,
      75,   157,   157,   157,   160,    31,   160,    73,   145,    75,
     160,    73,   160,    75,   160,   151,   160,   162,   162,    75,
     153,   148,   162,   161,   151,    75,   480,   331,   595,   161,
     597,    31,    48,   157,   162,   162,   330,   160,   159,    73,
     157,   178,   162,    73,    73,    75,   183,   148,   114,    75,
     151,   101,   159,   159,   191,   192,   193,   159,   195,   159,
     197,   428,   159,   159,   588,   432,   433,   159,   158,   158,
     158,   158,   158,   158,   157,    75,   158,    73,   158,   212,
     202,   212,   148,   162,   114,   151,   151,   162,    96,    97,
     157,   145,   157,   127,    73,   238,   162,   151,   127,   160,
     162,   238,   120,   157,   548,   238,   550,   238,   475,   145,
     564,   120,   556,   157,   148,   151,   157,   151,   148,   148,
     157,   151,   151,   256,   257,   256,   257,   264,    73,   158,
     160,   268,   162,   266,   267,   266,   267,   270,   145,   270,
     273,   274,   273,   274,   151,   505,   145,   163,   160,    73,
     604,    75,   151,   161,    73,   497,    75,   294,    22,    23,
     157,    25,   466,   157,   301,   157,   533,    68,    69,   102,
      73,   308,    31,   540,    73,   297,   109,   110,   111,   112,
     113,   114,   115,   145,   151,   157,   323,   491,   492,   205,
     114,   582,   159,   160,   145,   114,   500,   501,   124,   503,
      68,    69,   126,   101,   341,   151,   328,    45,    46,    47,
     347,    49,   349,   328,    63,   352,   328,   328,   779,   511,
     159,   160,   514,   356,   148,    63,   593,   151,   161,   148,
     674,   151,   151,   525,   145,   145,    22,    23,   162,   255,
     151,   151,   151,   162,   151,   145,   157,   157,   145,   386,
     145,     8,   157,   145,   645,   271,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   124,   582,
       8,   638,    95,    96,    97,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    85,    73,   426,
     427,   428,    73,   159,    75,   432,   433,    13,   159,   436,
      13,   668,    73,   670,    61,    62,   158,    73,   420,   122,
     122,   423,   157,   450,   451,   331,   453,   157,   430,   183,
     457,   458,   689,    61,    62,   159,     8,   191,   192,   193,
      93,   195,   645,   114,    95,    96,    97,   791,   475,    13,
     477,    73,    75,   480,   158,     8,   468,   157,   485,   716,
     717,   159,   157,   468,   497,   158,   468,   468,   157,     8,
     497,   728,   158,    13,   497,   123,   497,   148,   160,   157,
     151,   158,   163,   157,   238,   742,   158,   157,   157,   157,
     157,   162,   749,   520,    73,   157,   151,   163,   755,   145,
     105,    13,   684,    73,   686,   159,   533,   534,    13,   158,
     767,   158,   151,   540,   158,   160,     8,   699,   158,     8,
     124,   548,   159,   550,   125,    13,   159,   709,   159,   556,
     158,    73,   714,   560,   158,    13,   157,   564,   158,   158,
     294,   568,    42,    43,    44,    45,    46,    47,   159,    49,
     732,   107,    75,   735,   308,   124,   158,   125,   740,   582,
     466,   582,   589,    63,   158,   158,   593,   158,   474,   323,
     158,   163,   584,   159,   158,   587,   158,   604,   158,     8,
     101,    75,   594,   765,   160,   491,   492,   341,   109,   110,
     111,   112,   113,   114,   500,   501,   720,   503,    73,   781,
     157,   160,    13,   157,   159,    75,   158,    13,   159,   159,
      13,   638,   794,   160,    73,    75,    13,   629,    26,   801,
     157,    70,   645,   159,   645,   158,   125,    75,    13,    75,
      13,   159,   386,   160,    13,    73,    75,   159,   157,    26,
     105,   668,   159,   670,   158,   158,   157,   674,    75,   301,
     652,   160,   788,   451,   480,   521,   658,   659,   706,   589,
     659,   568,   689,   306,   606,   574,   630,   563,   601,    -1,
      -1,   691,   426,   427,   428,   183,   457,    -1,   432,   433,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   716,
     717,    -1,    -1,    -1,    -1,    -1,   698,   451,    -1,   453,
      -1,   728,    -1,   457,   458,    -1,    -1,    -1,    -1,    -1,
     722,    -1,    -1,    -1,   726,   742,    -1,    -1,    -1,    -1,
      -1,   475,   749,    -1,    -1,    -1,   738,    -1,   755,   741,
      -1,    -1,   744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     767,    -1,    -1,   497,    -1,    -1,   758,    -1,    -1,   761,
      -1,   763,   779,    -1,    -1,    -1,    -1,    -1,   760,    -1,
      -1,    -1,    -1,    -1,   791,   777,   520,    -1,    -1,    -1,
      -1,    -1,    -1,   785,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,    -1,    -1,    -1,   797,   540,    -1,    -1,    -1,
     802,    -1,    -1,    -1,   548,    -1,   550,    -1,    -1,    -1,
      -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,   593,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    77,    -1,    25,   638,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,   668,    -1,   670,    -1,    -1,    -1,
     674,    63,   118,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   689,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,   716,   717,    -1,   161,   162,   163,    -1,   165,
      -1,    -1,    -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    25,    -1,    61,    62,   742,    -1,
      -1,    -1,    -1,    -1,    -1,   749,    -1,    -1,   428,    -1,
     196,   755,   432,   433,    -1,    -1,    -1,   203,    -1,   205,
      -1,    -1,    -1,   767,    -1,    -1,   158,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    -1,   239,    -1,   475,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,   258,   259,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   279,   159,    -1,    -1,   183,    -1,    -1,
      -1,    -1,    -1,    42,    43,   191,   192,   193,    -1,   195,
      -1,    -1,    -1,   533,    -1,    -1,    -1,   303,    -1,   205,
     540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,   331,    -1,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,    -1,   195,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,   593,   360,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,   238,    -1,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   403,   638,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,   422,   323,   424,   425,
      -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,   668,    -1,
     670,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,   689,
      -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,   464,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,   323,    -1,    -1,    -1,   716,   717,    -1,    93,
     386,    -1,    -1,    -1,    -1,   491,   492,    -1,   728,   495,
     341,    -1,    -1,    -1,   500,   501,    -1,   503,    -1,   505,
     506,    -1,   742,    -1,    -1,    -1,    -1,    -1,    -1,   749,
      -1,    -1,    -1,    -1,    -1,   755,    -1,    -1,    -1,    -1,
     426,   427,    -1,    -1,    -1,    -1,    -1,   767,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,    -1,
      -1,   547,    -1,    -1,    -1,   451,    -1,   453,    -1,    -1,
      -1,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,   426,   427,    -1,    -1,    -1,
      -1,    -1,   588,    -1,    -1,   491,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   500,   501,    -1,   503,    10,    11,
     451,    -1,   453,    -1,    -1,   611,   457,   458,    -1,    -1,
      -1,    -1,    -1,    25,   520,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,   548,    -1,   550,    -1,   497,    -1,    -1,    -1,
     556,    63,    -1,    -1,    -1,    -1,    -1,    -1,   664,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,   589,    -1,    -1,    -1,    -1,    -1,   695,
      -1,    -1,     3,     4,     5,     6,     7,   548,    -1,   550,
      -1,    12,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,   731,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,   589,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,   674,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,   674,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    92,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    90,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    -1,    89,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,   103,   104,    -1,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,    -1,   138,    -1,    -1,
      -1,   142,     3,     4,     5,     6,     7,   148,   149,   150,
     151,    12,    -1,    -1,    -1,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     101,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    63,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   101,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    63,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   142,    12,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   101,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    63,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   142,    12,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,    -1,   157,    -1,
     159,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   101,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    63,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,   142,    -1,    12,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,   157,
     158,    -1,    -1,    -1,   162,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,   114,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,   142,    -1,    12,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,   162,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,   142,    -1,
      12,    -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,   157,    26,    -1,    -1,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
     142,    -1,    12,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     162,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,   142,    -1,    12,    -1,    -1,    -1,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,    -1,   162,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,   142,    -1,    12,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,   162,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,   142,    -1,    12,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,   162,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,   142,    -1,
      12,    -1,    -1,    -1,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,   162,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     142,    12,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,    -1,     9,    10,    11,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      25,   162,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,   161,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,   161,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,   161,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    63,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   159,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    25,
     159,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      25,   159,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   159,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    25,   158,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    25,   158,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   158,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    25,   158,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    25,   158,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   158,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    25,   158,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,   158,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,   125,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    11,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    63,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    63,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   165,   166,     0,     3,     4,     5,     6,     7,    12,
      42,    43,    48,    50,    51,    52,    53,    54,    55,    58,
      59,    60,    61,    62,    64,    65,    66,    67,    71,    72,
      73,    74,    75,    77,    81,    82,    83,    84,    85,    87,
      89,    91,    94,    98,    99,   100,   101,   102,   103,   104,
     106,   107,   108,   112,   113,   114,   116,   117,   118,   119,
     120,   121,   126,   127,   128,   129,   130,   131,   132,   135,
     136,   138,   142,   148,   149,   150,   151,   157,   159,   160,
     162,   167,   168,   171,   174,   175,   181,   182,   184,   185,
     186,   188,   227,   228,   231,   232,   240,   243,   247,   248,
     250,   251,   255,   256,   257,   258,   259,   260,   261,   266,
     271,   273,    73,   114,   148,   228,   247,   247,   157,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   114,   148,   151,   167,   232,   250,
     251,   257,   250,   247,   148,   151,   167,   232,   234,   235,
     257,   259,   260,   266,   157,   238,   157,    26,   224,   247,
     174,   157,   157,   157,   157,   157,   159,   247,   159,   247,
      73,    73,   159,   227,   247,   251,   160,   247,   151,   167,
     169,   170,    75,   162,   211,   212,   120,   120,    75,   213,
     228,   157,   157,   157,   157,   157,   157,   151,   160,   167,
     167,   247,   172,   160,   151,   157,     8,   159,    73,    73,
      31,   183,   145,     9,    10,    11,    25,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    49,    63,
     159,    61,    62,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   157,   145,   124,    63,   160,
     162,   260,   183,   247,   151,   167,   145,   145,   151,   167,
     145,   157,   239,   145,   124,   260,   158,   247,   247,     8,
     159,    85,   247,   225,   226,   247,   227,   251,    73,   197,
     247,   159,   159,   159,    13,   159,   159,   172,   159,   167,
      93,     8,   159,   160,   248,   251,     8,   159,    13,     8,
     159,   183,   179,   180,   251,   251,   272,   251,   158,   126,
     251,   267,   268,    31,   247,   269,   270,   167,   166,   159,
     160,   157,   158,   119,   161,   173,   174,   181,   182,   247,
      73,    31,   209,   210,   227,   251,    73,   122,   187,   122,
     189,    73,   157,    73,   255,   260,   266,   247,   247,   247,
      26,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   234,   247,   262,    31,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   209,
      73,   255,    73,   160,   255,   263,   264,   265,   262,   247,
     158,   167,    73,    73,   167,   255,   209,   255,   263,   158,
     158,   247,   157,   158,   159,     8,    93,    93,    13,     8,
     158,   158,    42,    43,   127,   148,   151,   167,   232,   240,
     241,   242,   161,    93,    73,   170,   247,   212,   241,    75,
     157,     8,   158,     8,   158,   158,   159,   157,     8,   158,
     249,   251,   125,   158,     8,   245,   157,   161,   166,   209,
     157,   161,   249,   158,     8,    13,   148,   151,   167,   233,
     123,   190,   191,   233,   160,   157,   127,   206,   207,   208,
     233,   157,   157,   260,   247,    26,   163,    65,   251,   158,
     157,   157,   247,   157,   254,    63,   160,   163,   161,   158,
     236,    26,   174,   247,    26,   174,   201,   225,   247,   251,
      31,   193,   251,   241,    73,    26,   174,   196,    26,   160,
     198,   241,   241,   157,   151,   167,   145,   105,    73,   161,
      13,   206,   180,   159,   251,   267,   268,    13,    31,   247,
      31,   247,   209,   161,   158,   158,    31,   227,   251,   241,
     151,   167,   191,   160,     8,   214,   206,   158,     8,    31,
      75,   209,   209,   247,   234,   209,   209,   161,   209,   252,
     262,   247,   124,   237,   172,   202,   158,   172,   159,   125,
     192,   251,   192,    13,   172,   159,   199,   159,   199,   241,
     244,   246,   167,    73,   157,   241,   158,   158,   247,   249,
     249,   125,   158,   159,   249,   167,   214,   233,   102,   109,
     110,   111,   112,   113,   114,   115,   161,   215,   218,   219,
     220,   221,   223,   158,   107,   229,   208,    75,    13,   158,
     158,   239,   158,   158,   158,   124,   253,   163,   161,   263,
     203,    68,    69,   204,   159,    86,   225,   193,   158,   158,
     241,    92,   199,    95,    96,    97,   199,   161,   125,   158,
       8,   245,   233,   229,    31,   247,   161,    73,    75,   222,
     228,   221,     8,   159,   160,   157,   160,    31,    75,    13,
     241,   263,    68,    69,   205,   157,   174,   159,   158,    26,
     174,   195,   195,   159,    95,   159,   247,    26,   159,   200,
     161,   241,   241,    75,   160,   249,    13,    13,     8,   159,
     216,    73,   172,    31,    75,   230,   172,    75,    13,   241,
     254,   157,    26,    70,   247,    26,   174,   194,   172,   159,
     200,   172,   125,   158,   172,   241,   241,    75,   183,    13,
     161,    75,     8,   158,   161,    13,   241,   247,   172,   159,
     158,   172,    90,   172,   241,   160,   161,    13,    73,   241,
      31,    75,   241,   158,   174,    88,   159,   172,   241,   157,
      75,    26,   159,   161,   206,   172,   105,   176,   177,   178,
     158,   157,   178,   159,   160,   217,   233,   172,    75,   161,
     158,   160,   172,   161
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
#line 196 "parser.y"
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 3:
#line 202 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 4:
#line 205 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 5:
#line 211 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_SYMBOL_NAME);
  ;}
    break;

  case 6:
#line 214 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 10:
#line 223 "parser.y"
    {
    (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 11:
#line 228 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_NAMESPACE, (yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 12:
#line 235 "parser.y"
    {
  NSPAN((yyvsp[(1) - (5)]), n_NAMESPACE, (yyvsp[(5) - (5)]));
  (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
  (yyvsp[(1) - (5)])->appendChild(NEXPAND((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 13:
#line 241 "parser.y"
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
#line 249 "parser.y"
    {
  NSPAN((yyvsp[(1) - (3)]), n_USE, (yyvsp[(2) - (3)]));
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 15:
#line 255 "parser.y"
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
  NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 16:
#line 262 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 17:
#line 265 "parser.y"
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 18:
#line 272 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 19:
#line 277 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    NTYPE((yyvsp[(3) - (3)]), n_STRING);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 20:
#line 283 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 21:
#line 289 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
    NTYPE((yyvsp[(4) - (4)]), n_STRING);
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  ;}
    break;

  case 22:
#line 299 "parser.y"
    {
    NMORE((yyval), (yyvsp[(5) - (5)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING))
        ->appendChild((yyvsp[(5) - (5)])));
  ;}
    break;

  case 23:
#line 306 "parser.y"
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[(4) - (4)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(2) - (4)]), n_STRING))
        ->appendChild((yyvsp[(4) - (4)])));
  ;}
    break;

  case 24:
#line 316 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 25:
#line 319 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 29:
#line 328 "parser.y"
    {
  (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
  NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 31:
#line 337 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 32:
#line 343 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  ;}
    break;

  case 33:
#line 346 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  ;}
    break;

  case 34:
#line 349 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLOSE_TAG);
  ;}
    break;

  case 35:
#line 355 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 36:
#line 358 "parser.y"
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
#line 388 "parser.y"
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
#line 403 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_WHILE);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 39:
#line 410 "parser.y"
    {
    NTYPE((yyvsp[(1) - (7)]), n_DO_WHILE);
    (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
    (yyvsp[(1) - (7)])->appendChild(NSPAN((yyvsp[(4) - (7)]), n_CONTROL_CONDITION, (yyvsp[(6) - (7)]))->appendChild((yyvsp[(5) - (7)])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (7)]));
    NMORE((yyval), (yyvsp[(7) - (7)]));
  ;}
    break;

  case 40:
#line 418 "parser.y"
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
#line 431 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_SWITCH);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 42:
#line 438 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_BREAK);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 43:
#line 445 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_BREAK);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 44:
#line 452 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_CONTINUE);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 45:
#line 459 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_CONTINUE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 46:
#line 466 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_RETURN);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 47:
#line 473 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 48:
#line 480 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 49:
#line 487 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 50:
#line 492 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 51:
#line 497 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 52:
#line 502 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_INLINE_HTML);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 53:
#line 506 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 54:
#line 510 "parser.y"
    {
    NMORE((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
    NLMORE((yyvsp[(3) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(3) - (5)]));
    NMORE((yyval), (yyvsp[(5) - (5)]));
  ;}
    break;

  case 55:
#line 516 "parser.y"
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

  case 56:
#line 533 "parser.y"
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
#line 549 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_DECLARE);
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 58:
#line 555 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 59:
#line 559 "parser.y"
    {
    NTYPE((yyvsp[(1) - (13)]), n_TRY);
    (yyvsp[(1) - (13)])->appendChild(NEXPAND((yyvsp[(2) - (13)]), (yyvsp[(3) - (13)]), (yyvsp[(4) - (13)])));

    NTYPE((yyvsp[(5) - (13)]), n_CATCH);
    (yyvsp[(5) - (13)])->appendChild((yyvsp[(7) - (13)]));
    (yyvsp[(5) - (13)])->appendChild(NTYPE((yyvsp[(8) - (13)]), n_VARIABLE));
    (yyvsp[(5) - (13)])->appendChild(NEXPAND((yyvsp[(10) - (13)]), (yyvsp[(11) - (13)]), (yyvsp[(12) - (13)])));

    (yyvsp[(1) - (13)])->appendChild(NNEW(n_CATCH_LIST)->appendChild((yyvsp[(5) - (13)]))->appendChildren((yyvsp[(13) - (13)])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (13)]));
  ;}
    break;

  case 60:
#line 572 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_THROW);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));

  ;}
    break;

  case 61:
#line 580 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_GOTO);
  NTYPE((yyvsp[(2) - (3)]), n_STRING);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 63:
#line 592 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 64:
#line 598 "parser.y"
    {
    (yyval) = NNEW(n_CATCH_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 65:
#line 602 "parser.y"
    {
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 66:
#line 609 "parser.y"
    {
    NTYPE((yyvsp[(1) - (8)]), n_CATCH);
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(3) - (8)]));
    (yyvsp[(1) - (8)])->appendChild(NTYPE((yyvsp[(4) - (8)]), n_VARIABLE));
    (yyvsp[(1) - (8)])->appendChild(NEXPAND((yyvsp[(6) - (8)]), (yyvsp[(7) - (8)]), (yyvsp[(8) - (8)])));
    NMORE((yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
    (yyval) = (yyvsp[(1) - (8)]);
  ;}
    break;

  case 67:
#line 620 "parser.y"
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 68:
#line 624 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 72:
#line 643 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 73:
#line 646 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_REFERENCE);
  ;}
    break;

  case 74:
#line 652 "parser.y"
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

  case 75:
#line 666 "parser.y"
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

  case 76:
#line 677 "parser.y"
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

  case 77:
#line 692 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_CLASS_ATTRIBUTES);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 78:
#line 696 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 79:
#line 703 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 80:
#line 713 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 81:
#line 716 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 83:
#line 726 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 84:
#line 729 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 85:
#line 737 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 86:
#line 740 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_IMPLEMENTS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 87:
#line 748 "parser.y"
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 88:
#line 751 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 89:
#line 757 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 90:
#line 760 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 92:
#line 767 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 94:
#line 776 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 96:
#line 785 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 98:
#line 794 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 99:
#line 802 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_STRING));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 100:
#line 808 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));
    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 101:
#line 819 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 102:
#line 822 "parser.y"
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[(2) - (4)]), n_STATEMENT);
    (yyvsp[(1) - (4)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[(2) - (4)]));
    (yyval)->appendChildren((yyvsp[(3) - (4)]));
    NEXPAND((yyvsp[(1) - (4)]), (yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 103:
#line 832 "parser.y"
    {
    NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 104:
#line 837 "parser.y"
    {
    NTYPE((yyvsp[(2) - (5)]), n_STATEMENT);
    (yyvsp[(1) - (5)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[(2) - (5)]));
    (yyval)->appendChildren((yyvsp[(3) - (5)]));
    NMORE((yyval), (yyvsp[(5) - (5)]));
    NLMORE((yyval), (yyvsp[(1) - (5)]));
  ;}
    break;

  case 105:
#line 849 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 106:
#line 852 "parser.y"
    {
    NTYPE((yyvsp[(2) - (5)]), n_CASE);
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 107:
#line 860 "parser.y"
    {
    NTYPE((yyvsp[(2) - (4)]), n_DEFAULT);
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(4) - (4)]));

    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 111:
#line 876 "parser.y"
    {
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 112:
#line 884 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  ;}
    break;

  case 113:
#line 887 "parser.y"
    {
    NTYPE((yyvsp[(2) - (6)]), n_ELSEIF);
    (yyvsp[(2) - (6)])->appendChild(NSPAN((yyvsp[(3) - (6)]), n_CONTROL_CONDITION, (yyvsp[(5) - (6)]))->appendChild((yyvsp[(4) - (6)])));
    (yyvsp[(2) - (6)])->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyvsp[(2) - (6)]));
  ;}
    break;

  case 114:
#line 897 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  ;}
    break;

  case 115:
#line 900 "parser.y"
    {
    NTYPE((yyvsp[(2) - (7)]), n_ELSEIF);
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(4) - (7)]));
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(7) - (7)]));

    (yyval) = (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
  ;}
    break;

  case 116:
#line 910 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 117:
#line 913 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_ELSE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 118:
#line 921 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 119:
#line 924 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ELSE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 121:
#line 933 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  ;}
    break;

  case 122:
#line 939 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 123:
#line 947 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_VARIABLE_REFERENCE));
      (yyvsp[(2) - (3)])->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 124:
#line 956 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (5)]), n_VARIABLE_REFERENCE));
      (yyvsp[(2) - (5)])->appendChild(NTYPE((yyvsp[(3) - (5)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 125:
#line 965 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(4) - (4)]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 126:
#line 973 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  ;}
    break;

  case 127:
#line 981 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (5)]), n_VARIABLE_REFERENCE));
      (yyvsp[(4) - (5)])->appendChild(NTYPE((yyvsp[(5) - (5)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 128:
#line 990 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (7)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (7)]), n_VARIABLE_REFERENCE));
      (yyvsp[(4) - (7)])->appendChild(NTYPE((yyvsp[(5) - (7)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(7) - (7)]));

    (yyval) = (yyvsp[(1) - (7)])->appendChild((yyval));
  ;}
    break;

  case 129:
#line 999 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (6)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  ;}
    break;

  case 130:
#line 1010 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 131:
#line 1013 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 132:
#line 1016 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_TYPE_NAME);
  ;}
    break;

  case 134:
#line 1023 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  ;}
    break;

  case 135:
#line 1029 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 136:
#line 1032 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 137:
#line 1035 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (2)]));
  ;}
    break;

  case 138:
#line 1040 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 139:
#line 1043 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 140:
#line 1046 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 141:
#line 1052 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 142:
#line 1056 "parser.y"
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 143:
#line 1063 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  ;}
    break;

  case 144:
#line 1066 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 145:
#line 1070 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (4)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 146:
#line 1077 "parser.y"
    {
    NTYPE((yyvsp[(3) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 147:
#line 1085 "parser.y"
    {
    NTYPE((yyvsp[(3) - (5)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 148:
#line 1093 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 149:
#line 1101 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 150:
#line 1112 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 151:
#line 1115 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 152:
#line 1121 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChildren((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 153:
#line 1129 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 154:
#line 1133 "parser.y"
    {
    yyextra->old_expecting_xhp_class_statements = yyextra->expecting_xhp_class_statements;
    yyextra->expecting_xhp_class_statements = false;
  ;}
    break;

  case 155:
#line 1136 "parser.y"
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

  case 156:
#line 1152 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 157:
#line 1155 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 159:
#line 1162 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 160:
#line 1169 "parser.y"
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  ;}
    break;

  case 161:
#line 1172 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 162:
#line 1179 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 163:
#line 1183 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_STRING));
  ;}
    break;

  case 170:
#line 1198 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 171:
#line 1205 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 172:
#line 1212 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 173:
#line 1219 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 174:
#line 1229 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));

    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 175:
#line 1238 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_CLASS_CONSTANT_DECLARATION_LIST);
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_STRING));
    (yyval)->appendChild((yyvsp[(4) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyval));

    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 176:
#line 1250 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 177:
#line 1253 "parser.y"
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 178:
#line 1260 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 180:
#line 1268 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 181:
#line 1271 "parser.y"
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 182:
#line 1278 "parser.y"
    {
    NTYPE((yyvsp[(1) - (6)]), n_LIST);
    (yyvsp[(1) - (6)])->appendChild(NEXPAND((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)])));
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (6)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(6) - (6)]));
  ;}
    break;

  case 183:
#line 1286 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 184:
#line 1292 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_OPERATOR));

    NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (4)])->appendChild((yyvsp[(4) - (4)]));

    (yyval)->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 185:
#line 1302 "parser.y"
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

  case 186:
#line 1316 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_NEW);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 187:
#line 1322 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 188:
#line 1327 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 189:
#line 1333 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 190:
#line 1339 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 191:
#line 1345 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 192:
#line 1351 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 193:
#line 1357 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 194:
#line 1363 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 195:
#line 1369 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 196:
#line 1375 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 197:
#line 1381 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 198:
#line 1387 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 199:
#line 1393 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  ;}
    break;

  case 200:
#line 1398 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 201:
#line 1403 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  ;}
    break;

  case 202:
#line 1408 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 203:
#line 1413 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 204:
#line 1419 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 205:
#line 1425 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 206:
#line 1431 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 207:
#line 1437 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 208:
#line 1443 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 209:
#line 1449 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 210:
#line 1455 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 211:
#line 1461 "parser.y"
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

  case 212:
#line 1487 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 213:
#line 1493 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 214:
#line 1499 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 215:
#line 1505 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 216:
#line 1511 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 217:
#line 1517 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 218:
#line 1523 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 219:
#line 1529 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 220:
#line 1534 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 221:
#line 1539 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 222:
#line 1544 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 223:
#line 1549 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 224:
#line 1555 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 225:
#line 1561 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 226:
#line 1567 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 227:
#line 1573 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 228:
#line 1579 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 229:
#line 1585 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 230:
#line 1591 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 231:
#line 1597 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 232:
#line 1603 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 233:
#line 1608 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));
  ;}
    break;

  case 234:
#line 1614 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  ;}
    break;

  case 236:
#line 1621 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 237:
#line 1626 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 238:
#line 1631 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 239:
#line 1636 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 240:
#line 1641 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 241:
#line 1646 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 242:
#line 1651 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 243:
#line 1656 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 244:
#line 1661 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 245:
#line 1666 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 246:
#line 1672 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 248:
#line 1677 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 249:
#line 1682 "parser.y"
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

  case 250:
#line 1693 "parser.y"
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

  case 252:
#line 1717 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 253:
#line 1720 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[(1) - (4)])->appendChildren((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 254:
#line 1728 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
  ;}
    break;

  case 255:
#line 1731 "parser.y"
    {
    NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (4)])->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 256:
#line 1736 "parser.y"
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
  ;}
    break;

  case 257:
#line 1740 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
  ;}
    break;

  case 258:
#line 1749 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  ;}
    break;

  case 259:
#line 1754 "parser.y"
    {
    NLMORE((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 260:
#line 1760 "parser.y"
    {
    NLMORE((yyvsp[(2) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(2) - (5)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])));
  ;}
    break;

  case 261:
#line 1766 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 262:
#line 1774 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 263:
#line 1782 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 264:
#line 1790 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 265:
#line 1798 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  ;}
    break;

  case 266:
#line 1806 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 267:
#line 1809 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 268:
#line 1812 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  ;}
    break;

  case 269:
#line 1816 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  ;}
    break;

  case 270:
#line 1823 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 271:
#line 1826 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  ;}
    break;

  case 272:
#line 1830 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  ;}
    break;

  case 275:
#line 1842 "parser.y"
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

  case 277:
#line 1855 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 278:
#line 1858 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 279:
#line 1864 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 280:
#line 1870 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 281:
#line 1873 "parser.y"
    {
    NSPAN((yyvsp[(1) - (2)]), n_EMPTY, (yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 282:
#line 1877 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 283:
#line 1885 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 284:
#line 1888 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 285:
#line 1894 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  ;}
    break;

  case 286:
#line 1897 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  ;}
    break;

  case 287:
#line 1900 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_STRING_SCALAR);
  ;}
    break;

  case 288:
#line 1903 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 289:
#line 1906 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 290:
#line 1909 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 291:
#line 1912 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 292:
#line 1915 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 293:
#line 1918 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 294:
#line 1921 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 295:
#line 1924 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_HEREDOC);
  ;}
    break;

  case 298:
#line 1932 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 299:
#line 1936 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 300:
#line 1940 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 301:
#line 1945 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 302:
#line 1950 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 304:
#line 1960 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 308:
#line 1971 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
  ;}
    break;

  case 309:
#line 1974 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 311:
#line 1981 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  ;}
    break;

  case 312:
#line 1984 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 313:
#line 1990 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 315:
#line 1997 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 316:
#line 2004 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 317:
#line 2011 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 318:
#line 2018 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 324:
#line 2045 "parser.y"
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

  case 326:
#line 2069 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
  ;}
    break;

  case 327:
#line 2072 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 328:
#line 2078 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(2) - (3)]));
    if ((yyvsp[(3) - (3)])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[(3) - (3)]));
    }
  ;}
    break;

  case 329:
#line 2088 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 330:
#line 2091 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 332:
#line 2098 "parser.y"
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

  case 333:
#line 2113 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 334:
#line 2118 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 339:
#line 2136 "parser.y"
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

  case 341:
#line 2152 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 342:
#line 2158 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 344:
#line 2168 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  ;}
    break;

  case 345:
#line 2171 "parser.y"
    {
    NSPAN((yyvsp[(1) - (4)]), n_VARIABLE_EXPRESSION, (yyvsp[(4) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 346:
#line 2179 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 347:
#line 2182 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 350:
#line 2193 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]))
  ;}
    break;

  case 351:
#line 2199 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 353:
#line 2209 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_STRING);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 354:
#line 2213 "parser.y"
    {
  (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 355:
#line 2219 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE_VARIABLE);
  ;}
    break;

  case 356:
#line 2222 "parser.y"
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

  case 357:
#line 2237 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 358:
#line 2240 "parser.y"
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 360:
#line 2248 "parser.y"
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 361:
#line 2253 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 362:
#line 2259 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  ;}
    break;

  case 363:
#line 2262 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 364:
#line 2268 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 365:
#line 2275 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 366:
#line 2282 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 367:
#line 2289 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 368:
#line 2296 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (6)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(6) - (6)])));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  ;}
    break;

  case 369:
#line 2303 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  ;}
    break;

  case 370:
#line 2310 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 371:
#line 2317 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(2) - (2)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 372:
#line 2327 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChildren((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 373:
#line 2337 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 374:
#line 2347 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 375:
#line 2350 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 376:
#line 2353 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 377:
#line 2363 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 378:
#line 2366 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 379:
#line 2372 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 380:
#line 2376 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 381:
#line 2382 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 382:
#line 2387 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 383:
#line 2400 "parser.y"
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
#line 6905 "parser.yacc.cpp"
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


#line 2412 "parser.y"


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}

/* @generated */
