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
     T_YIELD = 263,
     T_LOGICAL_OR = 264,
     T_LOGICAL_XOR = 265,
     T_LOGICAL_AND = 266,
     T_PRINT = 267,
     T_SR_EQUAL = 268,
     T_SL_EQUAL = 269,
     T_XOR_EQUAL = 270,
     T_OR_EQUAL = 271,
     T_AND_EQUAL = 272,
     T_MOD_EQUAL = 273,
     T_CONCAT_EQUAL = 274,
     T_DIV_EQUAL = 275,
     T_MUL_EQUAL = 276,
     T_MINUS_EQUAL = 277,
     T_PLUS_EQUAL = 278,
     T_BOOLEAN_OR = 279,
     T_BOOLEAN_AND = 280,
     T_IS_NOT_IDENTICAL = 281,
     T_IS_IDENTICAL = 282,
     T_IS_NOT_EQUAL = 283,
     T_IS_EQUAL = 284,
     T_IS_GREATER_OR_EQUAL = 285,
     T_IS_SMALLER_OR_EQUAL = 286,
     T_SR = 287,
     T_SL = 288,
     T_INSTANCEOF = 289,
     T_UNSET_CAST = 290,
     T_BOOL_CAST = 291,
     T_OBJECT_CAST = 292,
     T_ARRAY_CAST = 293,
     T_BINARY_CAST = 294,
     T_UNICODE_CAST = 295,
     T_STRING_CAST = 296,
     T_DOUBLE_CAST = 297,
     T_INT_CAST = 298,
     T_DEC = 299,
     T_INC = 300,
     T_CLONE = 301,
     T_NEW = 302,
     T_EXIT = 303,
     T_IF = 304,
     T_ELSEIF = 305,
     T_ELSE = 306,
     T_ENDIF = 307,
     T_LNUMBER = 308,
     T_DNUMBER = 309,
     T_STRING = 310,
     T_STRING_VARNAME = 311,
     T_VARIABLE = 312,
     T_NUM_STRING = 313,
     T_INLINE_HTML = 314,
     T_CHARACTER = 315,
     T_BAD_CHARACTER = 316,
     T_ENCAPSED_AND_WHITESPACE = 317,
     T_CONSTANT_ENCAPSED_STRING = 318,
     T_BACKTICKS_EXPR = 319,
     T_ECHO = 320,
     T_DO = 321,
     T_WHILE = 322,
     T_ENDWHILE = 323,
     T_FOR = 324,
     T_ENDFOR = 325,
     T_FOREACH = 326,
     T_ENDFOREACH = 327,
     T_DECLARE = 328,
     T_ENDDECLARE = 329,
     T_AS = 330,
     T_SWITCH = 331,
     T_ENDSWITCH = 332,
     T_CASE = 333,
     T_DEFAULT = 334,
     T_BREAK = 335,
     T_CONTINUE = 336,
     T_GOTO = 337,
     T_FUNCTION = 338,
     T_CONST = 339,
     T_RETURN = 340,
     T_TRY = 341,
     T_CATCH = 342,
     T_THROW = 343,
     T_USE = 344,
     T_GLOBAL = 345,
     T_PUBLIC = 346,
     T_PROTECTED = 347,
     T_PRIVATE = 348,
     T_FINAL = 349,
     T_ABSTRACT = 350,
     T_STATIC = 351,
     T_VAR = 352,
     T_UNSET = 353,
     T_ISSET = 354,
     T_EMPTY = 355,
     T_HALT_COMPILER = 356,
     T_CLASS = 357,
     T_INTERFACE = 358,
     T_EXTENDS = 359,
     T_IMPLEMENTS = 360,
     T_OBJECT_OPERATOR = 361,
     T_DOUBLE_ARROW = 362,
     T_LIST = 363,
     T_ARRAY = 364,
     T_CLASS_C = 365,
     T_METHOD_C = 366,
     T_FUNC_C = 367,
     T_LINE = 368,
     T_FILE = 369,
     T_COMMENT = 370,
     T_DOC_COMMENT = 371,
     T_OPEN_TAG = 372,
     T_OPEN_TAG_WITH_ECHO = 373,
     T_OPEN_TAG_FAKE = 374,
     T_CLOSE_TAG = 375,
     T_WHITESPACE = 376,
     T_START_HEREDOC = 377,
     T_END_HEREDOC = 378,
     T_HEREDOC = 379,
     T_DOLLAR_OPEN_CURLY_BRACES = 380,
     T_CURLY_OPEN = 381,
     T_PAAMAYIM_NEKUDOTAYIM = 382,
     T_BINARY_DOUBLE = 383,
     T_BINARY_HEREDOC = 384,
     T_NAMESPACE = 385,
     T_NS_C = 386,
     T_DIR = 387,
     T_NS_SEPARATOR = 388,
     T_XHP_WHITESPACE = 389,
     T_XHP_TEXT = 390,
     T_XHP_LT_DIV = 391,
     T_XHP_LT_DIV_GT = 392,
     T_XHP_ATTRIBUTE = 393,
     T_XHP_CATEGORY = 394,
     T_XHP_CHILDREN = 395,
     T_XHP_ANY = 396,
     T_XHP_EMPTY = 397,
     T_XHP_PCDATA = 398,
     T_XHP_COLON = 399,
     T_XHP_HYPHEN = 400,
     T_XHP_BOOLEAN = 401,
     T_XHP_NUMBER = 402,
     T_XHP_ARRAY = 403,
     T_XHP_STRING = 404,
     T_XHP_ENUM = 405,
     T_XHP_FLOAT = 406,
     T_XHP_REQUIRED = 407,
     T_XHP_ENTITY = 408
   };
#endif
/* Tokens.  */
#define T_REQUIRE_ONCE 258
#define T_REQUIRE 259
#define T_EVAL 260
#define T_INCLUDE_ONCE 261
#define T_INCLUDE 262
#define T_YIELD 263
#define T_LOGICAL_OR 264
#define T_LOGICAL_XOR 265
#define T_LOGICAL_AND 266
#define T_PRINT 267
#define T_SR_EQUAL 268
#define T_SL_EQUAL 269
#define T_XOR_EQUAL 270
#define T_OR_EQUAL 271
#define T_AND_EQUAL 272
#define T_MOD_EQUAL 273
#define T_CONCAT_EQUAL 274
#define T_DIV_EQUAL 275
#define T_MUL_EQUAL 276
#define T_MINUS_EQUAL 277
#define T_PLUS_EQUAL 278
#define T_BOOLEAN_OR 279
#define T_BOOLEAN_AND 280
#define T_IS_NOT_IDENTICAL 281
#define T_IS_IDENTICAL 282
#define T_IS_NOT_EQUAL 283
#define T_IS_EQUAL 284
#define T_IS_GREATER_OR_EQUAL 285
#define T_IS_SMALLER_OR_EQUAL 286
#define T_SR 287
#define T_SL 288
#define T_INSTANCEOF 289
#define T_UNSET_CAST 290
#define T_BOOL_CAST 291
#define T_OBJECT_CAST 292
#define T_ARRAY_CAST 293
#define T_BINARY_CAST 294
#define T_UNICODE_CAST 295
#define T_STRING_CAST 296
#define T_DOUBLE_CAST 297
#define T_INT_CAST 298
#define T_DEC 299
#define T_INC 300
#define T_CLONE 301
#define T_NEW 302
#define T_EXIT 303
#define T_IF 304
#define T_ELSEIF 305
#define T_ELSE 306
#define T_ENDIF 307
#define T_LNUMBER 308
#define T_DNUMBER 309
#define T_STRING 310
#define T_STRING_VARNAME 311
#define T_VARIABLE 312
#define T_NUM_STRING 313
#define T_INLINE_HTML 314
#define T_CHARACTER 315
#define T_BAD_CHARACTER 316
#define T_ENCAPSED_AND_WHITESPACE 317
#define T_CONSTANT_ENCAPSED_STRING 318
#define T_BACKTICKS_EXPR 319
#define T_ECHO 320
#define T_DO 321
#define T_WHILE 322
#define T_ENDWHILE 323
#define T_FOR 324
#define T_ENDFOR 325
#define T_FOREACH 326
#define T_ENDFOREACH 327
#define T_DECLARE 328
#define T_ENDDECLARE 329
#define T_AS 330
#define T_SWITCH 331
#define T_ENDSWITCH 332
#define T_CASE 333
#define T_DEFAULT 334
#define T_BREAK 335
#define T_CONTINUE 336
#define T_GOTO 337
#define T_FUNCTION 338
#define T_CONST 339
#define T_RETURN 340
#define T_TRY 341
#define T_CATCH 342
#define T_THROW 343
#define T_USE 344
#define T_GLOBAL 345
#define T_PUBLIC 346
#define T_PROTECTED 347
#define T_PRIVATE 348
#define T_FINAL 349
#define T_ABSTRACT 350
#define T_STATIC 351
#define T_VAR 352
#define T_UNSET 353
#define T_ISSET 354
#define T_EMPTY 355
#define T_HALT_COMPILER 356
#define T_CLASS 357
#define T_INTERFACE 358
#define T_EXTENDS 359
#define T_IMPLEMENTS 360
#define T_OBJECT_OPERATOR 361
#define T_DOUBLE_ARROW 362
#define T_LIST 363
#define T_ARRAY 364
#define T_CLASS_C 365
#define T_METHOD_C 366
#define T_FUNC_C 367
#define T_LINE 368
#define T_FILE 369
#define T_COMMENT 370
#define T_DOC_COMMENT 371
#define T_OPEN_TAG 372
#define T_OPEN_TAG_WITH_ECHO 373
#define T_OPEN_TAG_FAKE 374
#define T_CLOSE_TAG 375
#define T_WHITESPACE 376
#define T_START_HEREDOC 377
#define T_END_HEREDOC 378
#define T_HEREDOC 379
#define T_DOLLAR_OPEN_CURLY_BRACES 380
#define T_CURLY_OPEN 381
#define T_PAAMAYIM_NEKUDOTAYIM 382
#define T_BINARY_DOUBLE 383
#define T_BINARY_HEREDOC 384
#define T_NAMESPACE 385
#define T_NS_C 386
#define T_DIR 387
#define T_NS_SEPARATOR 388
#define T_XHP_WHITESPACE 389
#define T_XHP_TEXT 390
#define T_XHP_LT_DIV 391
#define T_XHP_LT_DIV_GT 392
#define T_XHP_ATTRIBUTE 393
#define T_XHP_CATEGORY 394
#define T_XHP_CHILDREN 395
#define T_XHP_ANY 396
#define T_XHP_EMPTY 397
#define T_XHP_PCDATA 398
#define T_XHP_COLON 399
#define T_XHP_HYPHEN 400
#define T_XHP_BOOLEAN 401
#define T_XHP_NUMBER 402
#define T_XHP_ARRAY 403
#define T_XHP_STRING 404
#define T_XHP_ENUM 405
#define T_XHP_FLOAT 406
#define T_XHP_REQUIRED 407
#define T_XHP_ENTITY 408




/* Copy the first part of user declarations.  */
#line 17 "parser.y"

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
#line 37 "parser.y"

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
#line 490 "parser.yacc.cpp"

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
#define YYLAST   7890

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  181
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  158
/* YYNRULES -- Number of rules.  */
#define YYNRULES  486
/* YYNRULES -- Number of states.  */
#define YYNSTATES  961

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   408

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,   180,     2,   178,    48,    32,     2,
     173,   174,    46,    43,     8,    44,    45,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,   175,
      37,    14,    38,    26,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,   179,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   176,    30,   177,    51,     2,     2,     2,
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
       5,     6,     7,     9,    10,    11,    12,    13,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    28,
      29,    33,    34,    35,    36,    39,    40,    41,    42,    50,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172
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
     876,   879,   882,   885,   888,   891,   894,   897,   902,   904,
     906,   909,   919,   930,   933,   936,   938,   939,   944,   948,
     953,   955,   958,   963,   970,   976,   983,   990,   997,  1004,
    1009,  1011,  1013,  1017,  1020,  1022,  1026,  1029,  1031,  1033,
    1038,  1040,  1043,  1044,  1047,  1048,  1051,  1055,  1056,  1060,
    1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,
    1082,  1084,  1086,  1090,  1093,  1096,  1099,  1104,  1106,  1110,
    1112,  1114,  1116,  1120,  1123,  1125,  1126,  1129,  1130,  1132,
    1138,  1142,  1146,  1148,  1150,  1152,  1154,  1156,  1158,  1164,
    1166,  1169,  1170,  1174,  1178,  1179,  1181,  1184,  1188,  1192,
    1194,  1196,  1198,  1200,  1203,  1205,  1210,  1215,  1217,  1219,
    1224,  1225,  1227,  1229,  1231,  1236,  1241,  1243,  1245,  1249,
    1251,  1254,  1258,  1260,  1262,  1267,  1268,  1269,  1272,  1278,
    1282,  1286,  1288,  1295,  1300,  1305,  1308,  1313,  1318,  1321,
    1324,  1329,  1332,  1335,  1337,  1341,  1345,  1349,  1351,  1353,
    1357,  1362,  1366,  1370,  1372,  1375,  1377,  1379,  1382,  1385,
    1386,  1388,  1391,  1395,  1397,  1398,  1399,  1405,  1406,  1409,
    1413,  1414,  1419,  1420,  1421,  1427,  1428,  1430,  1431,  1435,
    1436,  1439,  1440,  1444,  1445,  1449,  1450,  1454,  1456,  1460,
    1464,  1466,  1470,  1474,  1476,  1477,  1478,  1479,  1490,  1491,
    1496,  1498,  1502,  1507,  1510,  1512,  1514,  1516,  1518,  1520,
    1522,  1523,  1524,  1531,  1533,  1535,  1539,  1542,  1543,  1545,
    1546,  1547,  1552,  1555,  1560,  1561,  1566,  1568,  1570,  1572,
    1576,  1581,  1586,  1591,  1593,  1595,  1598,  1601,  1604,  1608,
    1612,  1614,  1616,  1619,  1622,  1625,  1628
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     182,     0,    -1,   183,    -1,   183,   185,    -1,    -1,    74,
      -1,   184,   152,    74,    -1,   191,    -1,   198,    -1,   199,
      -1,   120,   173,   174,   175,    -1,   149,   184,   175,    -1,
     149,   184,   176,   183,   177,    -1,   149,   176,   183,   177,
      -1,   108,   186,   175,    -1,   188,   175,    -1,   186,     8,
     187,    -1,   187,    -1,   184,    -1,   184,    94,    74,    -1,
     152,   184,    -1,   152,   184,    94,    74,    -1,   188,     8,
      74,    14,   258,    -1,   103,    74,    14,   258,    -1,   189,
     190,    -1,    -1,   191,    -1,   198,    -1,   199,    -1,   120,
     173,   174,   175,    -1,   192,    -1,    74,    27,    -1,   136,
      -1,   137,    -1,   139,    -1,   176,   189,   177,    -1,    68,
     173,   264,   174,   191,   219,   221,    -1,    68,   173,   264,
     174,    27,   189,   220,   222,    71,   175,    -1,    86,   173,
     264,   174,   218,    -1,    85,   191,    86,   173,   264,   174,
     175,    -1,    88,   173,   242,   175,   242,   175,   242,   174,
     211,    -1,    95,   173,   264,   174,   215,    -1,    99,   175,
      -1,    99,   264,   175,    -1,   100,   175,    -1,   100,   264,
     175,    -1,   104,   175,    -1,   104,   244,   175,    -1,   104,
     268,   175,    -1,   109,   228,   175,    -1,   115,   230,   175,
      -1,    84,   241,   175,    -1,    78,    -1,   264,   175,    -1,
     117,   173,   196,   174,   175,    -1,    90,   173,   268,    94,
     210,   209,   174,   212,    -1,    90,   173,   244,    94,   268,
     209,   174,   212,    -1,    92,   173,   214,   174,   213,    -1,
     175,    -1,   105,   176,   189,   177,   106,   173,   250,    76,
     174,   176,   189,   177,   193,    -1,   107,   264,   175,    -1,
     101,    74,   175,    -1,   194,    -1,    -1,   195,    -1,   194,
     195,    -1,   106,   173,   250,    76,   174,   176,   189,   177,
      -1,   197,    -1,   196,     8,   197,    -1,   268,    -1,   201,
      -1,   202,    -1,    -1,    32,    -1,   245,   200,    74,   173,
     223,   174,   176,   189,   177,    -1,   203,    74,   204,   207,
     176,   231,   177,    -1,   205,    74,   206,   176,   231,   177,
      -1,   121,    -1,   114,   121,    -1,   113,   121,    -1,    -1,
     123,   250,    -1,   122,    -1,    -1,   123,   208,    -1,    -1,
     124,   208,    -1,   250,    -1,   208,     8,   250,    -1,    -1,
     126,   210,    -1,   268,    -1,    32,   268,    -1,   191,    -1,
      27,   189,    89,   175,    -1,   191,    -1,    27,   189,    91,
     175,    -1,   191,    -1,    27,   189,    93,   175,    -1,    74,
      14,   258,    -1,   214,     8,    74,    14,   258,    -1,   176,
     216,   177,    -1,   176,   175,   216,   177,    -1,    27,   216,
      96,   175,    -1,    27,   175,   216,    96,   175,    -1,    -1,
     216,    97,   264,   217,   189,    -1,   216,    98,   217,   189,
      -1,    27,    -1,   175,    -1,   191,    -1,    27,   189,    87,
     175,    -1,    -1,   219,    69,   173,   264,   174,   191,    -1,
      -1,   220,    69,   173,   264,   174,    27,   189,    -1,    -1,
      70,   191,    -1,    -1,    70,    27,   189,    -1,   224,    -1,
      -1,   225,    76,    -1,   225,    32,    76,    -1,   225,    32,
      76,    14,   258,    -1,   225,    76,    14,   258,    -1,   224,
       8,   225,    76,    -1,   224,     8,   225,    32,    76,    -1,
     224,     8,   225,    32,    76,    14,   258,    -1,   224,     8,
     225,    76,    14,   258,    -1,    -1,   250,    -1,   128,    -1,
     227,    -1,    -1,   244,    -1,   268,    -1,    32,   266,    -1,
     227,     8,   244,    -1,   227,     8,   268,    -1,   227,     8,
      32,   266,    -1,   228,     8,   229,    -1,   229,    -1,    76,
      -1,   178,   265,    -1,   178,   176,   264,   177,    -1,   230,
       8,    76,    -1,   230,     8,    76,    14,   258,    -1,    76,
      -1,    76,    14,   258,    -1,   231,   232,    -1,    -1,   235,
     239,   175,    -1,   240,   175,    -1,    -1,   236,   245,   233,
     200,    74,   173,   223,   174,   234,    -1,   175,    -1,   176,
     189,   177,    -1,   237,    -1,   116,    -1,    -1,   237,    -1,
     238,    -1,   237,   238,    -1,   110,    -1,   111,    -1,   112,
      -1,   115,    -1,   114,    -1,   113,    -1,   239,     8,    76,
      -1,   239,     8,    76,    14,   258,    -1,    76,    -1,    76,
      14,   258,    -1,   240,     8,    74,    14,   258,    -1,   103,
      74,    14,   258,    -1,   241,     8,   264,    -1,   264,    -1,
      -1,   243,    -1,   243,     8,   264,    -1,   264,    -1,   127,
     173,   284,   174,    14,   264,    -1,   268,    14,   264,    -1,
     268,    14,    32,   268,    -1,   268,    14,    32,    66,   251,
     256,    -1,    66,   251,   256,    -1,    65,   264,    -1,   268,
      25,   264,    -1,   268,    24,   264,    -1,   268,    23,   264,
      -1,   268,    22,   264,    -1,   268,    21,   264,    -1,   268,
      20,   264,    -1,   268,    19,   264,    -1,   268,    18,   264,
      -1,   268,    17,   264,    -1,   268,    16,   264,    -1,   268,
      15,   264,    -1,   267,    63,    -1,    63,   267,    -1,   267,
      62,    -1,    62,   267,    -1,   264,    28,   264,    -1,   264,
      29,   264,    -1,   264,    10,   264,    -1,   264,    12,   264,
      -1,   264,    11,   264,    -1,   264,    30,   264,    -1,   264,
      32,   264,    -1,   264,    31,   264,    -1,   264,    45,   264,
      -1,   264,    43,   264,    -1,   264,    44,   264,    -1,   264,
      46,   264,    -1,   264,    47,   264,    -1,   264,    48,   264,
      -1,   264,    42,   264,    -1,   264,    41,   264,    -1,    43,
     264,    -1,    44,   264,    -1,    49,   264,    -1,    51,   264,
      -1,   264,    34,   264,    -1,   264,    33,   264,    -1,   264,
      36,   264,    -1,   264,    35,   264,    -1,   264,    37,   264,
      -1,   264,    40,   264,    -1,   264,    38,   264,    -1,   264,
      39,   264,    -1,   264,    50,   251,    -1,   173,   264,   174,
      -1,   264,    26,   264,    27,   264,    -1,   264,    26,    27,
     264,    -1,   288,    -1,    61,   264,    -1,    60,   264,    -1,
      59,   264,    -1,    58,   264,    -1,    57,   264,    -1,    56,
     264,    -1,    55,   264,    -1,    54,   264,    -1,    53,   264,
      -1,    67,   255,    -1,    52,   264,    -1,   128,   173,   286,
     174,    -1,    83,    -1,   260,    -1,    13,   264,    -1,   245,
     200,   173,   223,   174,   246,   176,   189,   177,    -1,   115,
     245,   200,   173,   223,   174,   246,   176,   189,   177,    -1,
       9,    99,    -1,     9,   264,    -1,   102,    -1,    -1,   108,
     173,   247,   174,    -1,   247,     8,    76,    -1,   247,     8,
      32,    76,    -1,    76,    -1,    32,    76,    -1,   184,   173,
     226,   174,    -1,   149,   152,   184,   173,   226,   174,    -1,
     152,   184,   173,   226,   174,    -1,   249,   146,    74,   173,
     226,   174,    -1,   274,   146,    74,   173,   226,   174,    -1,
     274,   146,   272,   173,   226,   174,    -1,   249,   146,   272,
     173,   226,   174,    -1,   272,   173,   226,   174,    -1,   115,
      -1,   184,    -1,   149,   152,   184,    -1,   152,   184,    -1,
     184,    -1,   149,   152,   184,    -1,   152,   184,    -1,   249,
      -1,   252,    -1,   276,   125,   280,   253,    -1,   276,    -1,
     253,   254,    -1,    -1,   125,   280,    -1,    -1,   173,   174,
      -1,   173,   264,   174,    -1,    -1,   173,   226,   174,    -1,
      72,    -1,    73,    -1,    82,    -1,   132,    -1,   133,    -1,
     151,    -1,   129,    -1,   130,    -1,   131,    -1,   150,    -1,
     143,    -1,   257,    -1,   184,    -1,   149,   152,   184,    -1,
     152,   184,    -1,    43,   258,    -1,    44,   258,    -1,   128,
     173,   261,   174,    -1,   259,    -1,   249,   146,    74,    -1,
      75,    -1,   290,    -1,   184,    -1,   149,   152,   184,    -1,
     152,   184,    -1,   257,    -1,    -1,   263,   262,    -1,    -1,
       8,    -1,   263,     8,   258,   126,   258,    -1,   263,     8,
     258,    -1,   258,   126,   258,    -1,   258,    -1,   265,    -1,
     244,    -1,   268,    -1,   268,    -1,   268,    -1,   275,   125,
     280,   271,   269,    -1,   275,    -1,   269,   270,    -1,    -1,
     125,   280,   271,    -1,   173,   226,   174,    -1,    -1,   277,
      -1,   283,   277,    -1,   249,   146,   272,    -1,   274,   146,
     272,    -1,   277,    -1,   276,    -1,   248,    -1,   277,    -1,
     283,   277,    -1,   273,    -1,   277,    64,   279,   179,    -1,
     277,   176,   264,   177,    -1,   278,    -1,    76,    -1,   178,
     176,   264,   177,    -1,    -1,   264,    -1,   281,    -1,   272,
      -1,   281,    64,   279,   179,    -1,   281,   176,   264,   177,
      -1,   282,    -1,    74,    -1,   176,   264,   177,    -1,   178,
      -1,   283,   178,    -1,   284,     8,   285,    -1,   285,    -1,
     268,    -1,   127,   173,   284,   174,    -1,    -1,    -1,   287,
     262,    -1,   287,     8,   264,   126,   264,    -1,   287,     8,
     264,    -1,   264,   126,   264,    -1,   264,    -1,   287,     8,
     264,   126,    32,   266,    -1,   287,     8,    32,   266,    -1,
     264,   126,    32,   266,    -1,    32,   266,    -1,   118,   173,
     289,   174,    -1,   119,   173,   268,   174,    -1,     7,   264,
      -1,     6,   264,    -1,     5,   173,   264,   174,    -1,     4,
     264,    -1,     3,   264,    -1,   268,    -1,   289,     8,   268,
      -1,   249,   146,    74,    -1,   274,   146,    74,    -1,   291,
      -1,   292,    -1,   293,   297,   294,    -1,   295,   301,    47,
      38,    -1,   295,   301,    38,    -1,   155,   310,    38,    -1,
     156,    -1,    37,   308,    -1,   154,    -1,   172,    -1,   296,
     154,    -1,   296,   172,    -1,    -1,   296,    -1,   297,   298,
      -1,   297,   298,   296,    -1,   291,    -1,    -1,    -1,   176,
     299,   264,   177,   300,    -1,    -1,   301,   302,    -1,   312,
      14,   303,    -1,    -1,   180,   304,   307,   180,    -1,    -1,
      -1,   176,   305,   264,   306,   177,    -1,    -1,   296,    -1,
      -1,   309,   318,   320,    -1,    -1,   311,   318,    -1,    -1,
     313,   319,   320,    -1,    -1,   315,   319,   320,    -1,    -1,
     317,   318,   320,    -1,    74,    -1,   318,   163,    74,    -1,
     318,   164,    74,    -1,    74,    -1,   319,   163,    74,    -1,
     319,   164,    74,    -1,   153,    -1,    -1,    -1,    -1,   203,
      27,   308,   204,   207,   176,   321,   231,   322,   177,    -1,
      -1,   157,   323,   324,   175,    -1,   325,    -1,   324,     8,
     325,    -1,   326,   312,   330,   331,    -1,   163,   308,    -1,
     168,    -1,   165,    -1,   166,    -1,   167,    -1,   249,    -1,
     116,    -1,    -1,    -1,   169,   176,   327,   329,   328,   177,
      -1,   170,    -1,   257,    -1,   329,     8,   257,    -1,    14,
     258,    -1,    -1,   171,    -1,    -1,    -1,   158,   332,   333,
     175,    -1,    48,   314,    -1,   333,     8,    48,   314,    -1,
      -1,   159,   334,   335,   175,    -1,   336,    -1,   160,    -1,
     161,    -1,   173,   337,   174,    -1,   173,   337,   174,    46,
      -1,   173,   337,   174,    26,    -1,   173,   337,   174,    43,
      -1,   336,    -1,   338,    -1,   338,    46,    -1,   338,    26,
      -1,   338,    43,    -1,   337,     8,   337,    -1,   337,    30,
     337,    -1,   160,    -1,   162,    -1,   163,   316,    -1,    48,
     316,    -1,   163,   308,    -1,   163,   308,    -1,   264,    64,
     279,   179,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   230,   230,   236,   239,   245,   248,   254,   255,   256,
     257,   262,   269,   277,   285,   291,   298,   301,   308,   313,
     319,   325,   335,   342,   352,   355,   361,   362,   363,   364,
     372,   373,   379,   382,   385,   391,   396,   426,   441,   448,
     456,   469,   476,   483,   490,   497,   504,   511,   518,   525,
     530,   535,   540,   544,   548,   554,   571,   587,   593,   597,
     610,   618,   629,   630,   636,   640,   647,   658,   662,   669,
     673,   677,   681,   684,   690,   704,   715,   730,   735,   742,
     752,   755,   761,   765,   768,   776,   779,   787,   790,   796,
     799,   805,   806,   814,   815,   823,   824,   832,   833,   841,
     847,   858,   863,   874,   879,   891,   894,   902,   912,   913,
     917,   918,   926,   929,   939,   942,   952,   955,   963,   966,
     974,   975,   981,   989,   998,  1007,  1015,  1023,  1032,  1041,
    1052,  1055,  1058,  1064,  1065,  1071,  1074,  1077,  1082,  1085,
    1088,  1094,  1098,  1105,  1108,  1112,  1119,  1127,  1135,  1143,
    1154,  1157,  1163,  1171,  1175,  1175,  1194,  1197,  1205,  1206,
    1213,  1216,  1223,  1227,  1233,  1234,  1235,  1236,  1237,  1238,
    1242,  1249,  1256,  1263,  1273,  1282,  1294,  1297,  1304,  1307,
    1312,  1315,  1322,  1330,  1336,  1346,  1360,  1366,  1371,  1377,
    1383,  1389,  1395,  1401,  1407,  1413,  1419,  1425,  1431,  1437,
    1442,  1447,  1452,  1457,  1463,  1469,  1475,  1481,  1487,  1493,
    1499,  1505,  1531,  1537,  1543,  1549,  1555,  1561,  1567,  1573,
    1578,  1583,  1588,  1593,  1599,  1605,  1611,  1617,  1623,  1629,
    1635,  1641,  1647,  1652,  1658,  1664,  1665,  1670,  1675,  1680,
    1685,  1690,  1695,  1700,  1705,  1710,  1715,  1720,  1726,  1730,
    1731,  1736,  1747,  1764,  1769,  1777,  1781,  1784,  1792,  1795,
    1800,  1804,  1813,  1818,  1824,  1830,  1838,  1846,  1854,  1862,
    1870,  1873,  1876,  1880,  1887,  1890,  1894,  1901,  1902,  1906,
    1915,  1919,  1922,  1928,  1934,  1937,  1941,  1949,  1952,  1958,
    1961,  1964,  1967,  1970,  1973,  1976,  1979,  1982,  1985,  1988,
    1994,  1995,  1996,  2000,  2004,  2009,  2014,  2020,  2024,  2032,
    2033,  2034,  2035,  2038,  2041,  2045,  2048,  2054,  2057,  2061,
    2068,  2075,  2082,  2092,  2093,  2097,  2101,  2105,  2109,  2129,
    2133,  2136,  2142,  2152,  2155,  2161,  2162,  2177,  2182,  2190,
    2194,  2195,  2199,  2200,  2212,  2216,  2222,  2228,  2232,  2235,
    2243,  2246,  2252,  2253,  2257,  2263,  2269,  2273,  2277,  2283,
    2286,  2301,  2304,  2311,  2312,  2317,  2323,  2326,  2332,  2339,
    2346,  2353,  2360,  2367,  2374,  2381,  2391,  2401,  2411,  2414,
    2417,  2427,  2430,  2436,  2440,  2446,  2451,  2463,  2470,  2471,
    2480,  2493,  2507,  2529,  2541,  2549,  2552,  2555,  2558,  2564,
    2567,  2571,  2575,  2582,  2583,  2586,  2583,  2599,  2603,  2609,
    2617,  2617,  2621,  2621,  2621,  2628,  2631,  2638,  2638,  2645,
    2645,  2652,  2652,  2659,  2659,  2666,  2666,  2673,  2678,  2681,
    2687,  2692,  2695,  2701,  2702,  2707,  2710,  2707,  2744,  2744,
    2753,  2754,  2758,  2763,  2771,  2774,  2777,  2780,  2783,  2786,
    2789,  2789,  2789,  2792,  2798,  2802,  2809,  2813,  2819,  2822,
    2829,  2829,  2841,  2844,  2851,  2851,  2859,  2862,  2865,  2871,
    2874,  2877,  2880,  2886,  2887,  2890,  2893,  2896,  2899,  2902,
    2908,  2911,  2914,  2917,  2924,  2935,  2951
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_REQUIRE_ONCE", "T_REQUIRE", "T_EVAL",
  "T_INCLUDE_ONCE", "T_INCLUDE", "','", "T_YIELD", "T_LOGICAL_OR",
  "T_LOGICAL_XOR", "T_LOGICAL_AND", "T_PRINT", "'='", "T_SR_EQUAL",
  "T_SL_EQUAL", "T_XOR_EQUAL", "T_OR_EQUAL", "T_AND_EQUAL", "T_MOD_EQUAL",
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
  "T_NAMESPACE", "T_NS_C", "T_DIR", "T_NS_SEPARATOR", "T_XHP_WHITESPACE",
  "T_XHP_TEXT", "T_XHP_LT_DIV", "T_XHP_LT_DIV_GT", "T_XHP_ATTRIBUTE",
  "T_XHP_CATEGORY", "T_XHP_CHILDREN", "T_XHP_ANY", "T_XHP_EMPTY",
  "T_XHP_PCDATA", "T_XHP_COLON", "T_XHP_HYPHEN", "T_XHP_BOOLEAN",
  "T_XHP_NUMBER", "T_XHP_ARRAY", "T_XHP_STRING", "T_XHP_ENUM",
  "T_XHP_FLOAT", "T_XHP_REQUIRED", "T_XHP_ENTITY", "'('", "')'", "';'",
  "'{'", "'}'", "'$'", "']'", "'\"'", "$accept", "start",
  "top_statement_list", "namespace_name", "top_statement",
  "use_declarations", "use_declaration", "constant_declaration",
  "inner_statement_list", "inner_statement", "statement",
  "unticked_statement", "additional_catches",
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
  "isset_variables", "class_constant", "xhp_tag_expression",
  "xhp_singleton", "xhp_tag_open", "xhp_tag_close", "xhp_tag_start",
  "xhp_literal_text", "xhp_children", "xhp_child", "@2", "@3",
  "xhp_attributes", "xhp_attribute", "xhp_attribute_value", "@4", "@5",
  "@6", "xhp_attribute_quoted_value", "xhp_label_immediate", "@7",
  "xhp_label_no_space", "@8", "xhp_label_pass", "@9",
  "xhp_label_pass_immediate", "@10", "xhp_label", "@11", "xhp_label_",
  "xhp_label_pass_", "xhp_whitespace_hack", "@12", "@13", "@14",
  "xhp_attribute_decls", "xhp_attribute_decl", "xhp_attribute_decl_type",
  "@15", "@16", "xhp_attribute_enum", "xhp_attribute_default",
  "xhp_attribute_is_required", "@17", "xhp_category_list", "@18",
  "xhp_children_decl", "xhp_children_paren_expr", "xhp_children_decl_expr",
  "xhp_children_decl_tag", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    44,   263,
     264,   265,   266,   267,    61,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,    63,    58,   279,   280,
     124,    94,    38,   281,   282,   283,   284,    60,    62,   285,
     286,   287,   288,    43,    45,    46,    42,    47,    37,    33,
     289,   126,    64,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    91,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,    40,    41,    59,   123,   125,    36,    93,
      34
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   181,   182,   183,   183,   184,   184,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   186,   186,   187,   187,
     187,   187,   188,   188,   189,   189,   190,   190,   190,   190,
     191,   191,   191,   191,   191,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   193,   193,   194,   194,   195,   196,   196,   197,
     198,   199,   200,   200,   201,   202,   202,   203,   203,   203,
     204,   204,   205,   206,   206,   207,   207,   208,   208,   209,
     209,   210,   210,   211,   211,   212,   212,   213,   213,   214,
     214,   215,   215,   215,   215,   216,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   222,   222,
     223,   223,   224,   224,   224,   224,   224,   224,   224,   224,
     225,   225,   225,   226,   226,   227,   227,   227,   227,   227,
     227,   228,   228,   229,   229,   229,   230,   230,   230,   230,
     231,   231,   232,   232,   233,   232,   234,   234,   235,   235,
     236,   236,   237,   237,   238,   238,   238,   238,   238,   238,
     239,   239,   239,   239,   240,   240,   241,   241,   242,   242,
     243,   243,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   245,   246,   246,   247,   247,
     247,   247,   248,   248,   248,   248,   248,   248,   248,   248,
     249,   249,   249,   249,   250,   250,   250,   251,   251,   252,
     252,   253,   253,   254,   255,   255,   255,   256,   256,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   260,
     260,   260,   260,   260,   260,   261,   261,   262,   262,   263,
     263,   263,   263,   264,   264,   265,   266,   267,   268,   268,
     269,   269,   270,   271,   271,   272,   272,   273,   273,   274,
     275,   275,   276,   276,   276,   277,   277,   277,   278,   278,
     279,   279,   280,   280,   281,   281,   281,   282,   282,   283,
     283,   284,   284,   285,   285,   285,   286,   286,   287,   287,
     287,   287,   287,   287,   287,   287,   288,   288,   288,   288,
     288,   288,   288,   289,   289,   290,   290,   244,   291,   291,
     292,   293,   294,   294,   295,   296,   296,   296,   296,   297,
     297,   297,   297,   298,   299,   300,   298,   301,   301,   302,
     304,   303,   305,   306,   303,   307,   307,   309,   308,   311,
     310,   313,   312,   315,   314,   317,   316,   318,   318,   318,
     319,   319,   319,   320,   320,   321,   322,   199,   323,   232,
     324,   324,   325,   325,   326,   326,   326,   326,   326,   326,
     327,   328,   326,   326,   329,   329,   330,   330,   331,   331,
     332,   232,   333,   333,   334,   232,   335,   335,   335,   336,
     336,   336,   336,   337,   337,   337,   337,   337,   337,   337,
     338,   338,   338,   338,   249,   250,   244
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
       2,     2,     2,     2,     2,     2,     2,     4,     1,     1,
       2,     9,    10,     2,     2,     1,     0,     4,     3,     4,
       1,     2,     4,     6,     5,     6,     6,     6,     6,     4,
       1,     1,     3,     2,     1,     3,     2,     1,     1,     4,
       1,     2,     0,     2,     0,     2,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     2,     4,     1,     3,     1,
       1,     1,     3,     2,     1,     0,     2,     0,     1,     5,
       3,     3,     1,     1,     1,     1,     1,     1,     5,     1,
       2,     0,     3,     3,     0,     1,     2,     3,     3,     1,
       1,     1,     1,     2,     1,     4,     4,     1,     1,     4,
       0,     1,     1,     1,     4,     4,     1,     1,     3,     1,
       2,     3,     1,     1,     4,     0,     0,     2,     5,     3,
       3,     1,     6,     4,     4,     2,     4,     4,     2,     2,
       4,     2,     2,     1,     3,     3,     3,     1,     1,     3,
       4,     3,     3,     1,     2,     1,     1,     2,     2,     0,
       1,     2,     3,     1,     0,     0,     5,     0,     2,     3,
       0,     4,     0,     0,     5,     0,     1,     0,     3,     0,
       2,     0,     3,     0,     3,     0,     3,     1,     3,     3,
       1,     3,     3,     1,     0,     0,     0,    10,     0,     4,
       1,     3,     4,     2,     1,     1,     1,     1,     1,     1,
       0,     0,     6,     1,     1,     3,     2,     0,     1,     0,
       0,     4,     2,     4,     0,     4,     1,     1,     1,     3,
       4,     4,     4,     1,     1,     2,     2,     2,     3,     3,
       1,     1,     2,     2,     2,     2,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,     0,   289,   290,     5,   309,   348,    52,   291,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,     0,     0,     0,     0,     0,     0,   270,
       0,     0,     0,     0,    77,    82,     0,     0,   295,   296,
     297,   292,   293,    32,    33,    34,   299,     0,   298,   294,
       0,   417,     0,    58,    25,   359,   311,     3,     0,     7,
      30,     8,     9,    70,    71,     0,     0,   324,    72,   341,
       0,   314,   249,     0,   323,     0,   325,     0,   344,     0,
     329,   340,   342,   347,     0,   235,   310,   387,   388,   399,
     407,     5,   270,     0,    72,   382,   381,     0,   379,   378,
     253,   254,   250,   394,     0,   219,   220,   221,   222,   246,
     244,   243,   242,   241,   240,   239,   238,   237,   236,   270,
       0,     0,   271,     0,   202,   327,     0,   200,   187,     0,
       0,   271,   277,   287,   278,     0,   280,   342,     0,     0,
     245,     0,    31,     0,   177,     0,     0,   178,     0,     0,
       0,    42,     0,    44,     0,     0,     0,    46,   324,     0,
     325,    25,     0,     0,    18,     0,    17,   143,     0,     0,
     142,    79,    78,   148,     0,    72,     0,     0,     0,     0,
     365,   366,     0,     4,     0,   313,   484,     0,     0,     0,
       0,   134,     0,    15,   417,    80,    83,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   350,    53,   201,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,   350,     0,   360,   343,   395,
     396,   400,     0,   421,     0,     0,   427,   434,     0,   273,
       0,     0,     0,   273,     0,   134,   186,     0,     0,   343,
     285,     0,     0,     0,    51,     0,     0,     0,   179,   181,
     324,   325,     0,     0,     0,    43,    45,    61,     0,    47,
      48,     0,    60,    20,     0,     0,    14,     0,   144,   325,
       0,    49,     0,     0,    50,     0,     0,    67,    69,   383,
       0,     0,     0,     0,   363,     0,   362,     0,   371,     0,
     317,   312,     0,    11,     4,   134,   232,     0,    35,    24,
      26,    27,    28,     0,     6,     0,     0,   133,   324,   325,
       0,    80,     0,    85,     0,     0,     0,   130,   385,   337,
     335,     0,   205,   207,   206,     0,     0,   203,   204,   208,
     210,   209,   224,   223,   226,   225,   227,   229,   230,   228,
     218,   217,   212,   213,   211,   214,   215,   216,   231,   351,
       0,     0,   183,   198,   197,   196,   195,   194,   193,   192,
     191,   190,   189,   188,     0,   386,   338,   357,     0,   353,
     334,   352,   356,     0,     0,   397,   398,   419,   393,   404,
     403,   389,   401,   391,     0,   408,     0,     0,   380,   433,
       0,     0,   418,   272,     0,     0,   272,   337,     0,   338,
     282,   286,     0,   176,     0,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
       0,   300,    23,   307,     0,     0,    19,    16,     0,   141,
     149,   146,   130,     0,     0,     0,   376,   377,    10,   365,
     365,     0,   375,   326,     0,   247,   318,   367,   134,    13,
       0,     0,     0,   349,   137,   262,     0,     0,    85,     0,
       0,   417,   274,    81,     0,     0,    84,    87,   151,   130,
     132,     0,   120,     0,   131,   134,   134,   336,   234,     0,
     486,     0,   184,   269,   134,   134,     0,   134,   331,   350,
       0,   345,   346,     0,     0,     0,   402,   390,     0,   430,
     434,   428,   429,   288,   279,    25,   112,     0,    25,   110,
      38,     0,   180,    89,     0,    89,    91,    99,     0,    25,
      97,    57,   105,   105,    41,   304,   305,   315,     0,   303,
       0,     0,    21,   145,     0,     0,    68,    54,   384,     0,
     361,     0,     0,   370,     0,   369,     0,    12,   264,     0,
       0,   324,   325,    22,     0,     0,   276,   485,    86,   151,
       0,   160,     0,   256,   130,     0,   122,     0,     0,   233,
     287,     0,     0,   358,     0,   328,     0,     0,   392,   420,
       0,   412,   410,   409,     0,     0,   422,     0,   281,   114,
     116,     0,     0,   178,     0,     0,    92,     0,     0,     0,
     105,     0,   105,     0,   322,     0,   317,   302,   308,     0,
     147,   256,   364,   182,   374,   373,     0,   263,    29,   140,
     435,   275,   160,    88,     0,   164,   165,   166,   169,   168,
     167,   159,   438,   460,   464,    76,   150,     0,     0,   158,
     162,     0,     0,     0,     0,     0,   123,     0,   265,   268,
     185,   266,   267,   333,     0,   330,   354,   355,   405,     0,
     415,   431,   432,   283,   118,     0,     0,    36,    39,     0,
       0,    90,     0,     0,   100,     0,     0,     0,     0,     0,
       0,   101,     0,   306,   318,   316,     0,     0,     0,   368,
     151,    75,     0,     0,     0,     0,   172,     0,   154,   163,
       0,   153,    25,     0,    25,     0,   126,     0,   125,   334,
     406,   413,   416,     0,     0,     0,     0,     0,   117,   111,
       0,    25,    95,    56,    55,    98,     0,   103,     0,   108,
     109,    25,   102,   321,   320,     0,    25,   372,   160,     0,
     449,   417,   445,   446,   447,   444,     0,   453,   448,     0,
     440,   421,   423,     0,   467,   468,     0,     0,   466,     0,
       0,   152,    72,     0,     0,     0,   260,     0,     0,   127,
       0,   124,   332,     0,   411,     0,    25,     0,     0,    25,
      93,    40,     0,   104,    25,   107,     0,     0,     0,     0,
     175,   443,   450,     0,   439,   457,   462,     0,     0,   461,
     425,   480,   481,   425,   473,     0,   474,   465,   173,   170,
       0,     0,    74,   261,     0,   257,   251,     0,   129,   414,
       0,   119,    37,     0,     0,     0,   106,   319,    25,   252,
     437,     0,   441,     0,   459,   434,   423,   483,     0,   482,
       0,     0,   469,   476,   477,   475,     0,     0,   174,     0,
     258,   128,     0,   113,     0,    96,     0,   454,   451,   456,
     458,   442,   424,   463,   434,   478,   479,   471,   472,   470,
     171,   130,   259,    25,    94,    63,     0,     0,   426,     0,
     115,     0,    59,    62,    64,   455,   452,     0,     0,    65,
     156,    25,   155,     0,     0,     0,   157,     0,    25,     0,
      66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    86,    87,   195,   196,    88,   218,   359,
     360,    90,   942,   943,   944,   336,   337,   361,   362,   228,
      93,    94,    95,   373,    96,   375,   525,   526,   655,   575,
     841,   783,   581,   313,   584,   661,   791,   570,   650,   724,
     727,   776,   531,   532,   533,   366,   367,   199,   200,   204,
     621,   696,   822,   952,   697,   698,   699,   700,   757,   701,
     173,   307,   308,    97,   124,   704,   827,    99,   100,   534,
     163,   164,   564,   648,   170,   296,   101,   482,   483,   102,
     665,   507,   666,   103,   104,   502,   105,   106,   635,   715,
     548,   107,   108,   109,   110,   111,   112,   113,   410,   430,
     431,   432,   114,   345,   346,   349,   350,   115,   340,   116,
     117,   118,   119,   441,   120,   281,   282,   442,   555,   770,
     283,   445,   643,   720,   719,   833,   773,   133,   134,   553,
     554,   446,   447,   856,   857,   897,   898,   287,   560,   452,
     750,   849,   753,   809,   810,   811,   891,   937,   918,   894,
     921,   754,   813,   755,   817,   864,   865,   866
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -593
static const yytype_int16 yypact[] =
{
    -593,    67,  1847,  -593,  6588,  6588,   -73,  6588,  6588,  4872,
    6588,  -593,  6588,  6588,  6588,  6588,  6588,  6588,  6588,  6588,
    6588,  6588,  6588,  6588,  6588,  6588,   527,   527,  6588,   579,
     -71,   -59,  -593,  -593,   113,  -593,  -593,  -593,  -593,  -593,
    6588,  4721,   -20,    85,   102,   109,   140,  5003,  5136,   100,
    -593,   246,  5269,   160,  6588,    -3,    29,    64,   231,   167,
     192,   208,   214,   225,  -593,  -593,   234,   249,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,    -4,  -593,  -593,
     349,  -593,  6588,  -593,  -593,   248,   110,  -593,    16,  -593,
    -593,  -593,  -593,  -593,  -593,    36,   352,  -593,   398,  -593,
     288,  -593,  -593,  1506,  -593,   286,  1305,   259,  -593,   291,
     313,  -593,    -8,  -593,    41,  -593,  -593,  -593,  -593,    68,
    -593,  -593,   337,   292,   398,  7677,  7677,  6588,  7677,  7677,
    -593,  7677,  7754,  -593,   366,   379,   379,    48,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,  -593,
     294,   349,   -74,   299,  -593,  -593,   302,  -593,  -593,   297,
     349,   306,   308,   289,  -593,   318,   334,     0,    41,  5402,
    -593,  6588,  -593,    18,  7677,   380,  6588,  6588,  6588,   393,
    6588,  -593,  7029,  -593,  7070,   303,   454,  -593,   304,  7677,
     353,  -593,  7111,   349,    -9,    20,  -593,  -593,   236,    21,
    -593,  -593,  -593,   458,    22,   398,   527,   527,   527,   309,
     395,  5534,   349,  -593,  -102,   172,  -593,  7155,  1998,  6588,
     416,  5666,   417,  -593,  -593,   371,   372,  -593,   -13,    42,
    6588,  6588,  6588,  5797,  6588,  6588,  6588,  6588,  6588,  6588,
    6588,  6588,  6588,  6588,  6588,  6588,  6588,  6588,  6588,  6588,
    6588,  6588,  6588,  6588,  6588,   579,  6588,  -593,  -593,  -593,
    5929,  6588,  6588,  6588,  6588,  6588,  6588,  6588,  6588,  6588,
    6588,  6588,  5666,    63,     3,  6588,  6588,   248,   -22,  -593,
    -593,   101,     7,   239,   323,  7196,  -593,   145,   349,    90,
      71,    76,   349,   306,    60,  5666,  -593,    60,     3,     1,
    -593,  7237,  7278,  6588,  -593,   327,  7321,   326,   490,  7677,
     413,  1217,   489,    31,  7362,  -593,  -593,  -593,  1011,  -593,
    -593,  2149,  -593,    12,   435,    -3,  -593,  6588,  -593,  -593,
      29,  -593,  1011,   436,  -593,   340,    32,  -593,  -593,  -593,
      35,   345,   339,   354,  -593,    37,  -593,   527,  7528,   355,
     518,   188,  1520,  -593,  -593,  5666,  -593,   358,  -593,  -593,
    -593,  -593,  -593,  6742,  -593,   527,   361,   524,    38,    72,
     523,   371,    81,   415,    81,   364,   369,   183,   370,   375,
       1,    41,  7717,  1682,  7754,  6588,  7636,  1369,  7826,  5056,
    5189,  1438,  5322,  5322,  5322,  5322,  1314,  1314,  1314,  1314,
     823,   823,   363,   363,   363,    48,    48,    48,  -593,  7677,
     376,   483,  7754,  7754,  7754,  7754,  7754,  7754,  7754,  7754,
    7754,  7754,  7754,  7754,   387,   381,   392,  -593,  6588,  -593,
     399,     2,  -593,   383,  6783,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,    68,  -593,   515,  -593,   550,   492,  -593,  -593,
     494,   497,  -593,   133,   370,   381,   306,  -593,   404,  -593,
    -593,  -593,  3962,  7677,  6588,  4114,  6588,  6588,   527,   389,
    1011,   505,  4266,    -5,  1011,  1011,   410,   433,   349,   -39,
     442,  -593,  -593,  -593,   484,   517,  -593,  -593,  6824,  -593,
    -593,   575,   183,   527,   418,   527,  -593,  -593,  -593,   395,
     395,   580,  -593,  -593,  6061,  -593,  6193,  -593,  5666,  -593,
    1696,   421,   422,  -593,  -593,  -593,  6325,  1011,   415,   447,
     349,  -593,   306,  -593,    81,   424,   596,  -593,  -593,   183,
    -593,   431,   600,   125,  -593,  5666,  5666,     1,  7791,  6588,
    -593,   579,  -593,  -593,  5666,  5666,  6865,  5666,  -593,  6588,
    6588,  -593,  -593,   572,   366,  6588,   101,  -593,   111,  -593,
     163,  -593,  -593,  -593,   486,  -593,  -593,  7403,  -593,  -593,
    -593,   437,  7677,   487,   527,   487,  -593,  -593,   604,  -593,
    -593,  -593,   439,   445,  -593,  -593,  -593,  1011,   349,    93,
     548,   451,  -593,  -593,  1011,   452,  -593,  -593,  -593,    39,
    -593,  6588,   527,  7677,   527,  7569,   455,  -593,  -593,   453,
     527,    40,   107,  -593,   457,   349,   306,  -593,   596,  -593,
      81,   919,   460,   529,   176,   555,   624,   465,   467,  7791,
     289,   469,   471,  -593,   474,   533,   470,  6906,  -593,   220,
    6947,  -593,  -593,  -593,   586,   588,  -593,     3,  -593,  3810,
     325,   488,  2300,  6588,   389,   491,  -593,   495,  1011,  2451,
    -593,   245,  -593,    89,   538,   496,   663,   171,  -593,    81,
    -593,   529,  -593,  7754,  -593,  -593,  6457,  -593,  -593,  -593,
    -593,   306,  1140,  -593,   601,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,   598,   337,   374,
    -593,    23,   501,   507,   502,   150,   668,  1011,  -593,  -593,
    -593,  -593,  -593,  -593,     3,  -593,  -593,  -593,  -593,  6588,
      68,  -593,  -593,  -593,   331,   510,  4721,  -593,  -593,   512,
     511,  -593,  4418,  4418,  -593,   520,   293,   526,  6588,     9,
     138,  -593,  1011,  -593,  1011,  -593,   627,   530,   527,  7677,
    -593,  -593,   694,   695,   661,   219,   696,    24,  -593,  -593,
     637,  -593,  -593,   191,  -593,   638,   699,  1011,  -593,   399,
    -593,  7677,   101,   540,   545,   698,   651,  6588,  -593,  -593,
    4570,  -593,  -593,  -593,  -593,  -593,   552,  -593,  6988,  -593,
    -593,  -593,  -593,  -593,   597,   558,  -593,  -593,  1156,  1011,
    -593,  -593,  -593,  -593,  -593,  -593,   553,  -593,  -593,    25,
    -593,  -593,  -593,    27,  -593,  -593,    55,   562,  -593,  1011,
     657,  -593,   398,   724,  2602,   667,  -593,    47,  2753,   730,
    1011,  -593,  -593,   568,  -593,  6588,  -593,   571,  7444,  -593,
    -593,  -593,  2904,  -593,  -593,  3810,  1011,   574,  3055,   570,
    -593,   674,  -593,   695,  -593,   738,  -593,   492,   705,  -593,
    -593,  -593,  -593,  -593,  -593,    30,    58,  -593,  -593,   740,
     681,  1011,  -593,  -593,   200,  -593,  -593,  1011,  -593,  -593,
    7487,  3810,  -593,  4721,  3206,   583,  3810,  -593,  -593,  -593,
    -593,   916,  -593,  1011,   589,   163,  -593,  -593,   366,  -593,
      55,    55,   312,  -593,  -593,  -593,  1011,   590,  -593,   685,
    -593,  -593,   735,  -593,   591,  -593,  3357,  -593,   757,  -593,
    -593,  -593,  -593,  -593,   145,   737,  -593,  -593,  -593,  -593,
    -593,   183,  -593,  -593,  -593,   662,   916,   593,  -593,   599,
    3810,   602,  -593,   662,  -593,  -593,  -593,   227,    81,  -593,
    -593,  -593,  -593,   700,  3508,   603,  -593,   595,  -593,  3659,
    -593
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -593,  -593,  -188,   -18,  -593,  -593,   459,  -593,  -137,  -593,
       8,  -593,  -593,  -593,  -165,  -593,   287,    10,    11,  -122,
    -593,  -593,  -593,   408,  -593,  -593,   264,   262,   212,   129,
    -593,    56,  -593,  -593,  -593,  -501,     6,  -593,  -593,  -593,
    -593,  -593,  -476,  -593,   166,  -214,  -593,  -593,   461,  -593,
    -592,  -593,  -593,  -593,  -593,  -593,  -593,    94,  -593,  -593,
    -593,  -445,  -593,   -11,    -2,   124,  -593,  -593,   198,  -368,
    -236,  -593,  -593,  -593,  -593,   168,   242,   551,  -593,  -593,
    -593,   131,  -593,   954,   605,  -351,   391,   409,  -593,  -593,
      44,  -222,  -593,    82,  -593,   -24,     5,  -593,  -252,  -281,
    -593,  -593,   -26,   300,   305,  -593,  -593,  -593,  -593,  -593,
     522,  -593,  -593,  -593,  -593,  -427,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,   -80,  -593,  -593,
    -593,     4,  -593,   -90,  -593,   -56,  -593,  -534,   -48,  -542,
    -593,  -593,  -593,  -593,   -37,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,    62,  -481,  -593
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -485
static const yytype_int16 yytable[] =
{
      98,   216,   284,   168,   523,   166,   527,   379,   152,   152,
      89,   161,    91,    92,   514,   556,   595,   460,   646,   408,
     639,   571,   582,   433,   222,   352,   303,   682,   325,   330,
     333,   760,   820,   853,   167,   858,   789,   194,   900,   471,
     493,   188,   275,   495,    11,   500,  -135,   500,  -138,   175,
     220,   426,   429,   622,   321,   874,   275,   205,   424,   214,
     901,   376,   215,   224,   275,   275,   549,     3,   379,   426,
     121,   121,   457,   353,   354,   459,   429,   427,   220,    36,
    -136,   458,   663,   335,   903,   324,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   255,   221,
     127,   904,   169,   860,   905,   197,   485,  -271,   156,   156,
     225,   165,   256,   220,   171,  -139,   378,    36,    36,   278,
     205,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   289,  -327,  -327,    36,   425,  -339,    36,
     172,   511,   293,   220,   371,   454,  -339,    36,   212,   193,
     455,  -336,    36,   176,   276,   121,   527,   625,   798,   736,
     377,   740,   437,   438,   220,  -335,   510,   310,   276,  -327,
    -327,   583,   213,   299,   185,   323,   276,   276,   550,   428,
     152,    85,   765,   439,   790,   201,   738,   739,   152,   152,
     152,   223,   152,   304,   351,   326,   331,   334,   761,   821,
     854,   626,   859,   381,   902,   472,   494,   198,   730,   496,
     368,   501,  -135,   672,  -138,   861,    98,   862,   863,   277,
      85,   875,   279,   825,   153,   153,   766,   162,   816,   168,
     519,   166,   909,   520,   380,   738,   739,   161,    85,  -273,
     280,    85,   220,   203,   521,   220,  -136,   381,   381,    85,
     121,   674,   683,   675,    85,   435,  -271,   121,   177,   679,
     167,   368,   220,   355,   381,   381,   741,   826,   381,    50,
     453,   381,   381,   436,   456,   178,   910,   443,   380,   380,
     156,  -139,   179,   221,   368,   220,   444,   641,   156,   156,
     156,   642,   156,   772,   606,   380,   380,   636,   449,   380,
     479,   746,   380,   380,   530,   630,   508,   194,   450,   451,
     121,   530,    36,   180,   479,   792,   449,  -272,  -273,    98,
     186,   627,   628,   220,   220,   519,   644,   645,   520,   152,
     631,   632,   519,   634,  -272,   520,   191,   165,   927,   521,
     220,   737,   738,   739,   368,   355,   521,   152,   258,   259,
      98,   149,   202,   922,   522,   928,   522,  -121,   929,   522,
      89,   508,    91,    92,   924,   206,   723,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   814,
     815,   207,   938,   450,   451,   150,   537,   208,   151,   786,
     738,   739,   816,   152,   725,   726,   153,   797,   209,    81,
     774,   775,   950,   951,   153,   153,   153,   210,   153,   252,
     253,   254,   327,   255,    85,  -327,  -327,   154,   157,   925,
     926,   574,   211,   121,   219,   429,   226,   256,   649,   156,
     227,   652,   272,   769,   229,   155,   155,   273,   274,    50,
     286,   617,   659,   256,   212,   290,   288,   156,   291,   292,
     152,   152,   479,   162,   294,   939,   479,   479,   220,   298,
     589,   190,   295,   121,   297,    36,   305,   312,   318,   121,
     566,    36,   332,   569,   522,   152,  -161,   152,   317,   319,
     580,   152,   152,   342,   685,   686,   687,   688,   689,   690,
     364,   370,   429,   156,   372,   374,   377,   368,   467,   479,
     464,   466,   616,   470,   149,   611,   522,   468,    98,   486,
     149,   522,   491,   492,   498,   168,   480,   166,    89,   497,
      91,    92,   343,   161,   368,   368,   506,   499,   320,   505,
     480,   512,   516,   368,   368,   515,   368,   517,   150,   524,
     528,   151,   529,   535,   150,   153,   167,   151,   536,   541,
     156,   156,    81,   557,   544,   540,   152,   121,    81,    36,
     481,   543,   551,   153,   558,   545,   559,    85,   561,   479,
     667,   562,   547,    85,   481,   156,   479,   156,   563,   578,
     953,   156,   156,   587,   152,   588,   152,   311,   590,   594,
     591,   592,   152,   597,   601,   608,   609,   681,   149,   615,
     619,   121,   522,    36,   620,   623,   522,   329,   624,   153,
     638,   647,   653,   654,   660,   338,   339,   341,   658,   344,
     662,   381,   668,   165,   669,   824,   671,   828,   678,   677,
     369,   706,   150,   680,   702,   151,   152,   703,   707,   708,
     479,   709,   149,   711,   842,   712,    81,    98,   713,   716,
      98,   522,   380,   121,   845,    36,   156,    98,   714,   848,
     721,    85,   722,   728,   742,   732,   153,   153,   480,   733,
     743,   744,   480,   480,   756,   752,   150,   762,   764,   151,
     763,   369,   767,   777,   156,   780,   156,   779,   381,   479,
      81,   153,   156,   153,   149,   785,   758,   153,   153,   881,
     870,   787,   884,   795,   369,    85,   796,   886,   799,   812,
     819,   823,   481,   830,   829,   480,   481,   481,   835,   380,
     834,   851,   837,   846,   479,   836,   479,   843,   159,   852,
     152,   160,   847,   869,   778,   161,   156,   867,   871,   162,
     782,   782,    81,   873,   877,   879,   882,   890,  -484,   479,
     888,   916,   893,   896,   906,   907,   503,    85,   915,   481,
     920,   932,   933,   931,   369,   936,   934,   901,   941,   121,
     946,   958,   153,   947,   503,   948,   955,   957,   949,   518,
     596,   479,   614,   731,   487,   480,   618,   657,   840,   784,
     705,   489,   480,   759,   844,   747,   940,   745,   710,   599,
     153,   479,   153,   328,   440,   600,   923,   899,   153,   895,
     149,   800,   479,   832,   954,   855,   892,   818,     0,     0,
     542,   959,    98,     0,     0,     0,    98,     0,   479,   481,
     156,     0,     0,     0,     0,   161,   481,     0,     0,     0,
      98,     0,     0,    98,   159,     0,    98,   160,     0,     0,
       0,     0,   153,   479,     0,     0,   480,     0,   801,   479,
     802,   803,   804,   805,   806,   807,   249,   250,   251,   252,
     253,   254,     0,   255,     0,   479,     0,   573,   576,    98,
       0,     0,    98,   490,    98,     0,     0,   256,   479,     0,
       0,   913,     0,     0,     0,     0,     0,     0,     0,     0,
     481,     0,   338,     0,   598,   480,     0,     0,   344,   344,
       0,     0,     0,   522,    98,     0,     0,   369,     0,     0,
       0,     0,     0,     0,     0,   612,     0,     0,     0,     0,
     522,     0,     0,     0,     0,     0,     0,     0,    98,     0,
     480,     0,   480,     0,   369,   369,   153,     0,     0,   481,
       0,   808,    98,   369,   369,     0,   369,    98,   125,   126,
       0,   128,   129,   131,   132,   480,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   158,   656,   481,     0,   481,     0,    32,    33,
       0,     0,     0,     0,   174,     0,     0,   480,    38,     0,
       0,   182,   184,     0,     0,     0,   189,     0,   192,   481,
       0,   503,     0,   503,     0,     0,     0,   480,     0,   503,
       0,   577,   684,     0,     0,   585,   586,     0,   480,   685,
     686,   687,   688,   689,   690,   691,   217,     0,     0,     0,
       0,   481,     0,     0,   480,    68,    69,    70,    71,    72,
       0,   808,     0,     0,   474,   475,     0,     0,     0,    76,
       0,   481,     0,   576,     0,     0,    78,    79,   613,   480,
       0,     0,   481,     0,     0,   480,   692,   693,   694,     0,
       0,   285,     0,    32,    33,   121,     0,     0,   481,     0,
       0,   480,     0,    38,     0,     0,   695,     0,     0,     0,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,     0,     0,   481,     0,     0,     0,     0,     0,   481,
       0,     0,     0,   301,     0,   302,   149,     0,     0,     0,
     306,   309,   189,   917,   314,   481,     0,     0,   664,   476,
      68,    69,    70,    71,    72,   670,     0,     0,   481,     0,
       0,     0,     0,     0,    76,     0,     0,   503,     0,     0,
     477,    78,    79,   478,     0,   348,     0,     0,     0,     0,
       0,     0,     0,   363,    81,   189,     0,     0,   945,     0,
       0,     0,     0,     0,   382,   383,   384,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   734,
     409,     0,     0,     0,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   189,     0,     0,   409,
     434,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   684,     0,     0,     0,     0,     0,   189,
     685,   686,   687,   688,   689,   690,   691,   463,   768,   684,
       0,     0,     0,     0,     0,     0,   685,   686,   687,   688,
     689,   690,   691,     0,     0,     0,     0,     0,     0,  -327,
    -327,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   793,     0,   794,     0,   692,   693,   694,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
       0,   469,     0,   692,   693,   694,     0,   751,   831,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,     0,     0,  -436,     0,     0,     0,     0,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     850,  -485,  -485,  -485,  -485,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,     0,     0,  -327,  -327,     0,
     868,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,   878,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   887,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   567,   255,
     309,   572,   908,     0,     0,     0,     0,     0,   911,     0,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   919,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   930,   603,     0,
     605,     0,   189,     0,     0,     0,     0,     0,     0,     0,
     189,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,   189,
     189,     0,     0,   629,     0,     0,     0,     0,   189,   189,
       0,   189,   256,   409,   637,     0,     0,     0,     0,   640,
       0,     0,     0,     0,     0,     0,   230,   231,   232,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     0,     9,
       0,     0,   233,    10,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   673,   255,    11,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
     256,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
       0,     0,    32,    33,    34,    35,    36,     0,    37,     0,
       0,     0,    38,    39,    40,    41,    42,   309,    43,     0,
      44,     0,    45,     0,     0,    46,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,     0,    54,    55,    56,
     749,     0,     0,    57,    58,    59,     0,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,    75,
       0,     0,     0,    76,     0,     0,     0,     0,     0,    77,
      78,    79,    80,   771,     0,     0,     0,     0,     0,     0,
       0,   257,     0,    81,     0,     0,     0,     0,     0,     0,
       0,     0,   788,    82,   232,    83,    84,   509,    85,     4,
       5,     6,     7,     8,     0,     9,     0,     0,   233,    10,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   838,   255,    11,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,    14,   256,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,     0,     0,    32,    33,
      34,    35,    36,     0,    37,     0,     0,     0,    38,    39,
      40,    41,    42,     0,    43,     0,    44,     0,    45,   880,
       0,    46,     0,     0,     0,    47,    48,    49,    50,    51,
      52,    53,     0,    54,    55,    56,     0,     0,     0,    57,
      58,    59,     0,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,    75,     0,     0,     0,    76,
       0,     0,     0,     0,     0,    77,    78,    79,    80,     0,
       4,     5,     6,     7,     8,     0,     9,     0,     0,    81,
      10,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,    83,    84,   607,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,     0,     0,    32,
      33,    34,    35,    36,     0,    37,     0,     0,     0,    38,
      39,    40,    41,    42,     0,    43,     0,    44,     0,    45,
       0,     0,    46,     0,     0,     0,    47,    48,    49,    50,
      51,    52,    53,     0,    54,    55,    56,     0,     0,     0,
      57,    58,    59,     0,    60,    61,    62,    63,    64,    65,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,    75,     0,     0,     0,
      76,     0,     0,     0,     0,     0,    77,    78,    79,    80,
       0,     4,     5,     6,     7,     8,     0,     9,     0,     0,
      81,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,    83,    84,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,     0,     0,
      32,    33,    34,    35,    36,     0,    37,     0,     0,     0,
      38,    39,    40,    41,    42,     0,    43,     0,    44,     0,
      45,     0,     0,    46,     0,     0,     0,    47,    48,    49,
      50,     0,    52,    53,     0,    54,     0,    56,     0,     0,
       0,    57,    58,    59,     0,    60,    61,    62,   357,    64,
      65,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,    75,     0,     0,
       0,    76,     0,     0,     0,     0,     0,   123,    78,    79,
      80,     0,     4,     5,     6,     7,     8,     0,     9,     0,
       0,    81,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,    83,    84,   358,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,     0,
       0,    32,    33,    34,    35,    36,     0,    37,     0,     0,
       0,    38,    39,    40,    41,    42,     0,    43,     0,    44,
       0,    45,     0,     0,    46,     0,     0,     0,    47,    48,
      49,    50,     0,    52,    53,     0,    54,     0,    56,     0,
       0,     0,    57,    58,    59,     0,    60,    61,    62,   357,
      64,    65,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,    75,     0,
       0,     0,    76,     0,     0,     0,     0,     0,   123,    78,
      79,    80,     0,     4,     5,     6,     7,     8,     0,     9,
       0,     0,    81,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,    83,    84,   484,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
       0,     0,    32,    33,    34,    35,    36,     0,    37,     0,
       0,     0,    38,    39,    40,    41,    42,   729,    43,     0,
      44,     0,    45,     0,     0,    46,     0,     0,     0,    47,
      48,    49,    50,     0,    52,    53,     0,    54,     0,    56,
       0,     0,     0,    57,    58,    59,     0,    60,    61,    62,
     357,    64,    65,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,    75,
       0,     0,     0,    76,     0,     0,     0,     0,     0,   123,
      78,    79,    80,     0,     4,     5,     6,     7,     8,     0,
       9,     0,     0,    81,    10,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,    83,    84,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,    12,    13,     0,     0,     0,     0,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,     0,     0,    32,    33,    34,    35,    36,     0,    37,
       0,     0,     0,    38,    39,    40,    41,    42,     0,    43,
       0,    44,     0,    45,   735,     0,    46,     0,     0,     0,
      47,    48,    49,    50,     0,    52,    53,     0,    54,     0,
      56,     0,     0,     0,    57,    58,    59,     0,    60,    61,
      62,   357,    64,    65,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
      75,     0,     0,     0,    76,     0,     0,     0,     0,     0,
     123,    78,    79,    80,     0,     4,     5,     6,     7,     8,
       0,     9,     0,     0,    81,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,    83,    84,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,     0,     0,    32,    33,    34,    35,    36,     0,
      37,     0,     0,     0,    38,    39,    40,    41,    42,     0,
      43,     0,    44,     0,    45,     0,     0,    46,     0,     0,
       0,    47,    48,    49,    50,     0,    52,    53,     0,    54,
       0,    56,     0,     0,     0,    57,    58,    59,     0,    60,
      61,    62,   357,    64,    65,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,    75,     0,     0,     0,    76,     0,     0,     0,     0,
       0,   123,    78,    79,    80,     0,     4,     5,     6,     7,
       8,     0,     9,     0,     0,    81,    10,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,    83,    84,   872,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,     0,     0,     0,    32,    33,    34,    35,    36,
       0,    37,     0,     0,     0,    38,    39,    40,    41,    42,
       0,    43,     0,    44,     0,    45,     0,     0,    46,     0,
       0,     0,    47,    48,    49,    50,     0,    52,    53,     0,
      54,     0,    56,     0,     0,     0,    57,    58,    59,     0,
      60,    61,    62,   357,    64,    65,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,    75,     0,     0,     0,    76,     0,     0,     0,
       0,     0,   123,    78,    79,    80,     0,     4,     5,     6,
       7,     8,     0,     9,     0,     0,    81,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,    83,    84,
     876,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    12,    13,     0,
       0,     0,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,     0,     0,    32,    33,    34,    35,
      36,     0,    37,     0,     0,     0,    38,    39,    40,    41,
      42,     0,    43,     0,    44,   885,    45,     0,     0,    46,
       0,     0,     0,    47,    48,    49,    50,     0,    52,    53,
       0,    54,     0,    56,     0,     0,     0,    57,    58,    59,
       0,    60,    61,    62,   357,    64,    65,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,    75,     0,     0,     0,    76,     0,     0,
       0,     0,     0,   123,    78,    79,    80,     0,     4,     5,
       6,     7,     8,     0,     9,     0,     0,    81,    10,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    83,
      84,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,    12,    13,
       0,     0,     0,     0,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,     0,     0,     0,    32,    33,    34,
      35,    36,     0,    37,     0,     0,     0,    38,    39,    40,
      41,    42,     0,    43,     0,    44,     0,    45,     0,     0,
      46,     0,     0,     0,    47,    48,    49,    50,     0,    52,
      53,     0,    54,     0,    56,     0,     0,     0,    57,    58,
      59,     0,    60,    61,    62,   357,    64,    65,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,    75,     0,     0,     0,    76,     0,
       0,     0,     0,     0,   123,    78,    79,    80,     0,     4,
       5,     6,     7,     8,     0,     9,     0,     0,    81,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
      83,    84,   889,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,     0,     0,    32,    33,
      34,    35,    36,     0,    37,     0,     0,     0,    38,    39,
      40,    41,    42,     0,    43,   914,    44,     0,    45,     0,
       0,    46,     0,     0,     0,    47,    48,    49,    50,     0,
      52,    53,     0,    54,     0,    56,     0,     0,     0,    57,
      58,    59,     0,    60,    61,    62,   357,    64,    65,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,    75,     0,     0,     0,    76,
       0,     0,     0,     0,     0,   123,    78,    79,    80,     0,
       4,     5,     6,     7,     8,     0,     9,     0,     0,    81,
      10,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,    83,    84,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,     0,     0,     0,    32,
      33,    34,    35,    36,     0,    37,     0,     0,     0,    38,
      39,    40,    41,    42,     0,    43,     0,    44,     0,    45,
       0,     0,    46,     0,     0,     0,    47,    48,    49,    50,
       0,    52,    53,     0,    54,     0,    56,     0,     0,     0,
      57,    58,    59,     0,    60,    61,    62,   357,    64,    65,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,    75,     0,     0,     0,
      76,     0,     0,     0,     0,     0,   123,    78,    79,    80,
       0,     4,     5,     6,     7,     8,     0,     9,     0,     0,
      81,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,    83,    84,   935,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,     0,     0,
      32,    33,    34,    35,    36,     0,    37,     0,     0,     0,
      38,    39,    40,    41,    42,     0,    43,     0,    44,     0,
      45,     0,     0,    46,     0,     0,     0,    47,    48,    49,
      50,     0,    52,    53,     0,    54,     0,    56,     0,     0,
       0,    57,    58,    59,     0,    60,    61,    62,   357,    64,
      65,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,    75,     0,     0,
       0,    76,     0,     0,     0,     0,     0,   123,    78,    79,
      80,     0,     4,     5,     6,     7,     8,     0,     9,     0,
       0,    81,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,    83,    84,   956,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,     0,     0,
       0,    32,    33,    34,    35,    36,     0,    37,     0,     0,
       0,    38,    39,    40,    41,    42,     0,    43,     0,    44,
       0,    45,     0,     0,    46,     0,     0,     0,    47,    48,
      49,    50,     0,    52,    53,     0,    54,     0,    56,     0,
       0,     0,    57,    58,    59,     0,    60,    61,    62,   357,
      64,    65,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,    75,     0,
       0,     0,    76,     0,     0,     0,     0,     0,   123,    78,
      79,    80,     0,     4,     5,     6,     7,     8,     0,     9,
       0,     0,    81,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,    83,    84,   960,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
       0,     0,    32,    33,    34,    35,    36,     0,    37,     0,
       0,     0,    38,    39,    40,    41,    42,     0,    43,     0,
      44,     0,    45,     0,     0,    46,     0,     0,     0,    47,
      48,    49,    50,     0,    52,    53,     0,    54,     0,    56,
       0,     0,     0,    57,    58,    59,     0,    60,    61,    62,
     357,    64,    65,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,    75,
       0,     0,     0,    76,     0,     0,     0,     0,     0,   123,
      78,    79,    80,     0,     0,     4,     5,     6,     7,     8,
       0,     9,     0,    81,     0,    10,     0,     0,     0,     0,
       0,     0,     0,    82,     0,    83,    84,     0,    85,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,     0,     0,     0,    32,    33,    34,    35,    36,     0,
      37,     0,     0,     0,    38,    39,    40,    41,    42,     0,
      43,     0,    44,     0,    45,     0,     0,    46,     0,     0,
       0,    47,    48,    49,    50,     0,    52,    53,     0,    54,
       0,    56,     0,     0,     0,     0,     0,    59,     0,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,    75,     0,     0,     0,    76,     0,     0,     0,     0,
       0,   123,    78,    79,    80,     0,     0,     4,     5,     6,
       7,     8,     0,     9,     0,    81,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    82,     0,    83,    84,     0,
      85,   568,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    12,    13,     0,
       0,     0,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,     0,     0,     0,    32,    33,    34,    35,
      36,     0,    37,     0,     0,     0,    38,    39,    40,    41,
      42,     0,    43,     0,    44,     0,    45,     0,     0,    46,
       0,     0,     0,    47,    48,    49,    50,     0,    52,    53,
       0,    54,     0,    56,     0,     0,     0,     0,     0,    59,
       0,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,    75,     0,     0,     0,    76,     0,     0,
       0,     0,     0,   123,    78,    79,    80,     0,     0,     4,
       5,     6,     7,     8,     0,     9,     0,    81,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    83,
      84,     0,    85,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,     0,     0,     0,    32,    33,
      34,    35,    36,     0,    37,     0,     0,     0,    38,    39,
      40,    41,    42,     0,    43,     0,    44,     0,    45,     0,
       0,    46,     0,     0,     0,    47,    48,    49,    50,     0,
      52,    53,     0,    54,     0,    56,     0,     0,     0,     0,
       0,    59,     0,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,    75,     0,     0,     0,    76,
       0,     0,     0,     0,     0,   123,    78,    79,    80,     0,
       0,     4,     5,     6,     7,     8,     0,     9,     0,    81,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    82,
       0,    83,    84,     0,    85,   781,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,     0,     0,     0,
      32,    33,    34,    35,    36,     0,    37,     0,     0,     0,
      38,    39,    40,    41,    42,     0,    43,     0,    44,     0,
      45,     0,     0,    46,     0,     0,     0,    47,    48,    49,
      50,     0,    52,    53,     0,    54,     0,    56,     0,     0,
       0,     0,     0,    59,     0,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,    75,     0,     0,
       0,    76,     0,     0,     0,     0,     0,   123,    78,    79,
      80,     0,     0,     4,     5,     6,     7,     8,     0,     9,
       0,    81,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    82,     0,    83,    84,     0,    85,   839,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,     0,
       0,     0,    32,    33,    34,    35,    36,     0,    37,     0,
       0,     0,    38,    39,    40,    41,    42,     0,    43,     0,
      44,     0,    45,     0,     0,    46,     0,     0,     0,    47,
      48,    49,    50,     0,    52,    53,     0,    54,     0,    56,
       0,     0,     0,     0,     0,    59,     0,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,    75,
       0,     0,     0,    76,     0,     0,     0,     0,     0,   123,
      78,    79,    80,     0,     4,     5,     6,     7,     8,     0,
       9,     0,     0,    81,    10,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,    83,    84,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,    12,    13,     0,     0,     0,     0,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
       0,     0,     0,    32,    33,    34,    35,    36,     0,    37,
       0,     0,     0,    38,    39,    40,    41,    42,     0,    43,
       0,    44,     0,    45,     0,     0,    46,     0,     0,     0,
      47,    48,    49,    50,     0,    52,    53,     0,    54,     0,
      56,     0,     0,     0,     0,     0,    59,     0,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
      75,     0,     0,     0,    76,     0,     0,     0,     0,     0,
     123,    78,    79,    80,     0,     4,     5,     6,     7,     8,
       0,     9,     0,     0,    81,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,    83,    84,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
       0,     0,     0,     0,    32,    33,   121,    35,    36,     0,
       0,     0,     0,     0,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,     4,     5,     6,     7,
       8,     0,     9,     0,     0,    76,    10,     0,     0,     0,
       0,   123,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    82,    12,    13,     0,     0,
      85,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,     0,     0,     0,     0,    32,    33,   121,    35,    36,
       0,     0,     0,     0,     0,    38,    39,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    50,   255,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     256,    61,    62,     0,     0,     0,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,     0,     0,     4,
       5,     6,     7,     8,     0,     9,    76,     0,     0,    10,
       0,     0,   123,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,     0,    11,     0,     0,    82,     0,   181,    12,
      13,    85,     0,     0,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,     0,     0,     0,     0,    32,    33,
     121,    35,    36,     0,     0,     0,     0,     0,    38,    39,
       0,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    50,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,   256,    61,    62,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     4,     5,     6,     7,     8,     0,     9,    76,
       0,     0,    10,     0,     0,   123,    78,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,    11,     0,     0,    82,
       0,   183,    12,    13,    85,     0,     0,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,     0,     0,     0,
       0,    32,    33,   121,    35,    36,     0,     0,     0,     0,
       0,    38,    39,     0,     0,  -485,  -485,  -485,  -485,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    50,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,   256,    61,    62,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,     0,     0,     4,     5,     6,     7,     8,
       0,     9,    76,     0,     0,    10,     0,     0,   123,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    82,     0,   187,    12,    13,    85,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
       0,     0,     0,     0,    32,    33,   121,    35,    36,     0,
       0,     0,     0,     0,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,     0,     4,     5,     6,
       7,     8,     0,     9,     0,    76,     0,    10,     0,     0,
       0,   123,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,   347,     0,     0,     0,
       0,    11,     0,     0,     0,    82,   300,    12,    13,     0,
      85,     0,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,     0,     0,     0,     0,    32,    33,   121,    35,
      36,     0,     0,     0,     0,     0,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,    61,    62,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,     0,     4,
       5,     6,     7,     8,     0,     9,     0,    76,     0,    10,
       0,     0,     0,   123,    78,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,   365,     0,
       0,     0,     0,    11,     0,     0,     0,    82,     0,    12,
      13,     0,    85,     0,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,     0,     0,     0,     0,    32,    33,
     121,    35,    36,     0,     0,     0,     0,     0,    38,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
       4,     5,     6,     7,     8,     0,     9,     0,     0,    76,
      10,     0,     0,     0,     0,   123,    78,    79,    80,     0,
       0,     0,     0,     0,   385,     0,     0,     0,     0,    81,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    82,
      12,    13,     0,     0,    85,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,     0,     0,     0,     0,    32,
      33,   121,    35,    36,     0,     0,     0,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,    61,    62,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,     0,     4,     5,     6,     7,     8,     0,     9,     0,
      76,     0,    10,     0,     0,     0,   123,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,   411,     0,     0,     0,     0,    11,     0,     0,     0,
      82,     0,    12,    13,     0,    85,     0,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,     0,     0,     0,
       0,    32,    33,   121,    35,    36,     0,     0,     0,     0,
       0,    38,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,    61,    62,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,     0,     4,     5,     6,     7,     8,     0,
       9,     0,    76,     0,    10,     0,     0,     0,   123,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,   602,     0,     0,     0,     0,    11,     0,
       0,     0,    82,     0,    12,    13,     0,    85,     0,     0,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,     0,
       0,     0,     0,    32,    33,   121,    35,    36,     0,     0,
       0,     0,     0,    38,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,     0,     4,     5,     6,     7,
       8,     0,     9,     0,    76,     0,    10,     0,     0,     0,
     123,    78,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,   604,     0,     0,     0,     0,
      11,     0,     0,     0,    82,     0,    12,    13,     0,    85,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,     0,     0,     0,     0,    32,    33,   121,    35,    36,
       0,     0,     0,     0,     0,    38,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,     0,     4,     5,
       6,     7,     8,     0,     9,     0,    76,     0,    10,     0,
       0,     0,   123,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,   610,     0,     0,
       0,     0,    11,     0,     0,     0,    82,     0,    12,    13,
       0,    85,     0,     0,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,     0,     0,     0,     0,    32,    33,   121,
      35,    36,     0,     0,     0,     0,     0,    38,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,     0,
       4,     5,     6,     7,     8,     0,     9,     0,    76,     0,
      10,     0,     0,     0,   123,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,   748,
       0,     0,     0,     0,    11,     0,     0,     0,    82,     0,
      12,    13,     0,    85,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,     0,     0,     0,     0,    32,
      33,   121,    35,    36,     0,     0,     0,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,    61,    62,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,     4,     5,     6,     7,     8,     0,     9,     0,     0,
      76,    10,     0,     0,     0,     0,   123,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      82,    12,    13,     0,     0,    85,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,     0,     0,     0,     0,
      32,    33,   121,    35,    36,     0,     0,     0,     0,     0,
      38,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,     0,    61,    62,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,   123,    78,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,   230,   231,   232,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,    85,     0,   233,     0,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,   255,   230,   231,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,   233,
       0,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,     0,   255,   230,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,     0,     0,
     233,     0,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,   230,   231,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,   233,     0,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,   255,   230,   231,   232,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
       0,     0,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,   255,   230,   231,   232,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,   255,   230,   231,
     232,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,     0,   233,   789,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,   230,
     231,   232,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,   233,     0,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,   255,
     230,   231,   232,   717,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,     0,     0,   233,     0,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
     255,   230,   231,   232,   718,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,     0,     0,   233,     0,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
       0,   255,     0,   790,     0,   230,   231,   232,     0,     0,
       0,     0,     0,     0,     0,   256,     0,     0,     0,     0,
       0,   233,     0,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   315,   255,   230,   231,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
       0,     0,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   316,   255,   230,   231,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   322,   255,   230,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,     0,   233,     0,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,   356,
       0,   230,   231,   232,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,   233,     0,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     448,   255,   230,   231,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,     0,     0,   233,     0,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   461,   255,   230,   231,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,   233,
       0,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   462,   255,   230,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,     0,     0,
     233,     0,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,   465,     0,   230,   231,   232,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   473,   255,   230,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,     0,   233,     0,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   651,   255,   230,
     231,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,   233,     0,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   883,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,   232,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,   912,   233,   539,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,   255,   230,   231,   232,
       0,     0,     0,     0,     0,   676,     0,     0,     0,     0,
     256,     0,     0,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,   255,   231,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,   255,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   256,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
       0,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,   255,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256
};

static const yytype_int16 yycheck[] =
{
       2,    81,   124,    29,   372,    29,   374,   229,    26,    27,
       2,    29,     2,     2,   365,   442,   492,   298,   560,   255,
     554,   466,    27,   275,     8,   213,     8,   619,     8,     8,
       8,     8,     8,     8,    29,     8,    27,    55,     8,     8,
       8,    52,    64,     8,    37,     8,     8,     8,     8,    41,
     152,   273,   274,   529,   191,     8,    64,    59,   272,    77,
      30,    74,    80,    27,    64,    64,    64,     0,   290,   291,
      74,    74,   294,   175,   176,   297,   298,    74,   152,    76,
       8,   295,   583,   205,    26,    94,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    50,   173,
     173,    43,   173,    48,    46,    76,    94,   146,    26,    27,
      74,    29,    64,   152,   173,     8,    74,    76,    76,   114,
     122,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   151,    62,    63,    76,    74,   146,    76,
      27,   355,   160,   152,   224,    74,   146,    76,   152,   152,
      74,   173,    76,   173,   176,    74,   524,    32,   750,   660,
     173,   662,   155,   156,   152,   173,   354,   178,   176,    62,
      63,   176,   176,   168,    74,   193,   176,   176,   176,   176,
     198,   178,    32,   176,   175,   121,    97,    98,   206,   207,
     208,   175,   210,   175,   212,   175,   175,   175,   175,   175,
     175,    76,   175,   229,   174,   174,   174,   178,   653,   174,
     221,   174,   174,   174,   174,   160,   218,   162,   163,   178,
     178,   174,   154,    32,    26,    27,    76,    29,   173,   255,
     149,   255,    32,   152,   229,    97,    98,   255,   178,   146,
     172,   178,   152,    76,   163,   152,   174,   273,   274,   178,
      74,   602,   620,   604,   178,   154,   146,    74,   173,   610,
     255,   272,   152,   173,   290,   291,   177,    76,   294,   102,
     288,   297,   298,   172,   292,   173,    76,    38,   273,   274,
     198,   174,   173,   173,   295,   152,    47,   176,   206,   207,
     208,   180,   210,   720,   508,   290,   291,   549,   153,   294,
     318,   669,   297,   298,   128,   541,   173,   325,   163,   164,
      74,   128,    76,   173,   332,   177,   153,   146,   146,   321,
      74,   535,   536,   152,   152,   149,   163,   164,   152,   347,
     544,   545,   149,   547,   146,   152,   176,   255,    26,   163,
     152,    96,    97,    98,   355,   173,   163,   365,    62,    63,
     352,   115,   121,   895,   372,    43,   374,   174,    46,   377,
     352,   173,   352,   352,   898,   173,   647,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   160,
     161,   173,   924,   163,   164,   149,   381,   173,   152,    96,
      97,    98,   173,   411,    69,    70,   198,   748,   173,   163,
      69,    70,   175,   176,   206,   207,   208,   173,   210,    46,
      47,    48,   176,    50,   178,    62,    63,    26,    27,   900,
     901,    32,   173,    74,   176,   647,    74,    64,   565,   347,
      32,   568,   173,   714,   146,    26,    27,   146,   125,   102,
      74,   521,   579,    64,   152,   146,   152,   365,   146,   152,
     468,   469,   470,   255,   146,   931,   474,   475,   152,   125,
     478,    52,   173,    74,   146,    76,    86,    74,    14,    74,
     462,    76,    14,   465,   492,   493,   102,   495,   175,   175,
     472,   499,   500,   174,   110,   111,   112,   113,   114,   115,
      74,    74,   714,   411,   123,   123,   173,   508,     8,   517,
     173,   175,   520,    14,   115,   516,   524,    94,   510,    74,
     115,   529,    76,   173,   175,   541,   318,   541,   510,   174,
     510,   510,   127,   541,   535,   536,     8,   173,   175,   174,
     332,   173,     8,   544,   545,   174,   547,    14,   149,   124,
     176,   152,   173,   173,   149,   347,   541,   152,   173,    66,
     468,   469,   163,    38,   173,   179,   574,    74,   163,    76,
     318,   174,   179,   365,    14,   173,    74,   178,    74,   587,
     588,    74,   173,   178,   332,   493,   594,   495,   174,    74,
     948,   499,   500,   173,   602,   152,   604,   178,   146,    14,
     106,    74,   610,   175,    14,   174,   174,   615,   115,   152,
     176,    74,   620,    76,     8,   174,   624,   198,     8,   411,
      38,   125,   175,   126,   175,   206,   207,   208,    14,   210,
     175,   647,    74,   541,   173,   762,   174,   764,   175,   174,
     221,    76,   149,   176,   174,   152,   654,   108,    14,   174,
     658,   174,   115,   174,   781,   174,   163,   649,   174,   179,
     652,   669,   647,    74,   791,    76,   574,   659,   125,   796,
      74,   178,    74,   175,   126,   174,   468,   469,   470,   174,
     174,     8,   474,   475,    76,    74,   149,   176,   176,   152,
     173,   272,    14,   173,   602,   174,   604,   175,   714,   707,
     163,   493,   610,   495,   115,   175,   698,   499,   500,   836,
     822,   175,   839,    76,   295,   178,   176,   844,    14,    48,
      14,    74,   470,    14,    76,   517,   474,   475,   173,   714,
     180,   801,    71,   126,   742,    27,   744,   175,   149,   176,
     748,   152,   174,    76,   726,   753,   654,   175,    14,   541,
     732,   733,   163,    76,    14,   177,   175,   177,    74,   767,
     176,   888,    14,    48,    14,    74,   347,   178,   175,   517,
     171,    76,    27,   173,   355,     8,   175,    30,   106,    74,
     177,   176,   574,   174,   365,   173,    76,   174,   943,   371,
     493,   799,   518,   654,   325,   587,   524,   575,   780,   733,
     624,   330,   594,   699,   788,   671,   933,   666,   630,   499,
     602,   819,   604,   198,   282,   500,   896,   863,   610,   857,
     115,   116,   830,   769,   951,   811,   853,   755,    -1,    -1,
     411,   958,   824,    -1,    -1,    -1,   828,    -1,   846,   587,
     748,    -1,    -1,    -1,    -1,   853,   594,    -1,    -1,    -1,
     842,    -1,    -1,   845,   149,    -1,   848,   152,    -1,    -1,
      -1,    -1,   654,   871,    -1,    -1,   658,    -1,   163,   877,
     165,   166,   167,   168,   169,   170,    43,    44,    45,    46,
      47,    48,    -1,    50,    -1,   893,    -1,   468,   469,   881,
      -1,    -1,   884,   332,   886,    -1,    -1,    64,   906,    -1,
      -1,   883,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     658,    -1,   493,    -1,   495,   707,    -1,    -1,   499,   500,
      -1,    -1,    -1,   931,   916,    -1,    -1,   508,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
     948,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,
     742,    -1,   744,    -1,   535,   536,   748,    -1,    -1,   707,
      -1,   753,   954,   544,   545,    -1,   547,   959,     4,     5,
      -1,     7,     8,     9,    10,   767,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,   574,   742,    -1,   744,    -1,    72,    73,
      -1,    -1,    -1,    -1,    40,    -1,    -1,   799,    82,    -1,
      -1,    47,    48,    -1,    -1,    -1,    52,    -1,    54,   767,
      -1,   602,    -1,   604,    -1,    -1,    -1,   819,    -1,   610,
      -1,   470,   103,    -1,    -1,   474,   475,    -1,   830,   110,
     111,   112,   113,   114,   115,   116,    82,    -1,    -1,    -1,
      -1,   799,    -1,    -1,   846,   129,   130,   131,   132,   133,
      -1,   853,    -1,    -1,    43,    44,    -1,    -1,    -1,   143,
      -1,   819,    -1,   654,    -1,    -1,   150,   151,   517,   871,
      -1,    -1,   830,    -1,    -1,   877,   157,   158,   159,    -1,
      -1,   127,    -1,    72,    73,    74,    -1,    -1,   846,    -1,
      -1,   893,    -1,    82,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   906,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   871,    -1,    -1,    -1,    -1,    -1,   877,
      -1,    -1,    -1,   169,    -1,   171,   115,    -1,    -1,    -1,
     176,   177,   178,   891,   180,   893,    -1,    -1,   587,   128,
     129,   130,   131,   132,   133,   594,    -1,    -1,   906,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,   748,    -1,    -1,
     149,   150,   151,   152,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   163,   221,    -1,    -1,   936,    -1,
      -1,    -1,    -1,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   658,
     256,    -1,    -1,    -1,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,    -1,    -1,   275,
     276,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   103,    -1,    -1,    -1,    -1,    -1,   295,
     110,   111,   112,   113,   114,   115,   116,   303,   707,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   742,    -1,   744,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   355,
      -1,    94,    -1,   157,   158,   159,    -1,   177,   767,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,   385,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     799,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    -1,    -1,    62,    63,    -1,
     819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,   830,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   846,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   464,    50,
     466,   467,   871,    -1,    -1,    -1,    -1,    -1,   877,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   893,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   906,   504,    -1,
     506,    -1,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     516,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,   535,
     536,    -1,    -1,   539,    -1,    -1,    -1,    -1,   544,   545,
      -1,   547,    64,   549,   550,    -1,    -1,    -1,    -1,   555,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      -1,    -1,    26,    13,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   601,    50,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      64,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    78,    -1,
      -1,    -1,    82,    83,    84,    85,    86,   653,    88,    -1,
      90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,   105,    -1,   107,   108,   109,
     676,    -1,    -1,   113,   114,   115,    -1,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,    -1,   139,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   719,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   738,   173,    12,   175,   176,   177,   178,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    26,    13,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   777,    50,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    64,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    -1,    78,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    -1,    88,    -1,    90,    -1,    92,   835,
      -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,   103,
     104,   105,    -1,   107,   108,   109,    -1,    -1,    -1,   113,
     114,   115,    -1,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,    -1,   139,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,
       3,     4,     5,     6,     7,    -1,     9,    -1,    -1,   163,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   176,   177,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    -1,    88,    -1,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,   105,    -1,   107,   108,   109,    -1,    -1,    -1,
     113,   114,   115,    -1,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,    -1,   139,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
      -1,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
     163,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   176,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    88,    -1,    90,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,   101,
     102,    -1,   104,   105,    -1,   107,    -1,   109,    -1,    -1,
      -1,   113,   114,   115,    -1,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,    -1,   139,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,    -1,     3,     4,     5,     6,     7,    -1,     9,    -1,
      -1,   163,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   176,   177,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    78,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    -1,    88,    -1,    90,
      -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,   104,   105,    -1,   107,    -1,   109,    -1,
      -1,    -1,   113,   114,   115,    -1,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,    -1,   139,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,    -1,     3,     4,     5,     6,     7,    -1,     9,
      -1,    -1,   163,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   176,   177,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    78,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,   104,   105,    -1,   107,    -1,   109,
      -1,    -1,    -1,   113,   114,   115,    -1,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,    -1,   139,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,    -1,     3,     4,     5,     6,     7,    -1,
       9,    -1,    -1,   163,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   176,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    88,
      -1,    90,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,   104,   105,    -1,   107,    -1,
     109,    -1,    -1,    -1,   113,   114,   115,    -1,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,    -1,
     139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,    -1,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,   163,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   176,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,
      78,    -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,
      88,    -1,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,   104,   105,    -1,   107,
      -1,   109,    -1,    -1,    -1,   113,   114,   115,    -1,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
      -1,   139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,    -1,     3,     4,     5,     6,
       7,    -1,     9,    -1,    -1,   163,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   176,   177,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      -1,    78,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    88,    -1,    90,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,   100,   101,   102,    -1,   104,   105,    -1,
     107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,    -1,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,    -1,   139,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,    -1,     3,     4,     5,
       6,     7,    -1,     9,    -1,    -1,   163,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   176,
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    -1,    78,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    -1,    88,    -1,    90,    91,    92,    -1,    -1,    95,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,   105,
      -1,   107,    -1,   109,    -1,    -1,    -1,   113,   114,   115,
      -1,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,    -1,   139,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,    -1,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,   163,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    78,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    88,    -1,    90,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,
     105,    -1,   107,    -1,   109,    -1,    -1,    -1,   113,   114,
     115,    -1,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,    -1,   139,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,   163,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,   176,   177,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    -1,    78,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    -1,    92,    -1,
      -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,    -1,
     104,   105,    -1,   107,    -1,   109,    -1,    -1,    -1,   113,
     114,   115,    -1,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,    -1,   139,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,
       3,     4,     5,     6,     7,    -1,     9,    -1,    -1,   163,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    -1,    88,    -1,    90,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,   104,   105,    -1,   107,    -1,   109,    -1,    -1,    -1,
     113,   114,   115,    -1,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,    -1,   139,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
      -1,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
     163,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   176,   177,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    88,    -1,    90,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,   101,
     102,    -1,   104,   105,    -1,   107,    -1,   109,    -1,    -1,
      -1,   113,   114,   115,    -1,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,    -1,   139,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,    -1,     3,     4,     5,     6,     7,    -1,     9,    -1,
      -1,   163,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   176,   177,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    78,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    -1,    88,    -1,    90,
      -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,
     101,   102,    -1,   104,   105,    -1,   107,    -1,   109,    -1,
      -1,    -1,   113,   114,   115,    -1,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,    -1,   139,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,    -1,     3,     4,     5,     6,     7,    -1,     9,
      -1,    -1,   163,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   176,   177,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    78,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    -1,    88,    -1,
      90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,   104,   105,    -1,   107,    -1,   109,
      -1,    -1,    -1,   113,   114,   115,    -1,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,    -1,   139,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    -1,   163,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   176,    -1,   178,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,
      78,    -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,
      88,    -1,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,   104,   105,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,   115,    -1,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
      -1,   139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,    -1,    -1,     3,     4,     5,
       6,     7,    -1,     9,    -1,   163,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,   176,    -1,
     178,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    -1,    78,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    -1,    88,    -1,    90,    -1,    92,    -1,    -1,    95,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,   104,   105,
      -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,   115,
      -1,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,    -1,   139,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    -1,   163,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     176,    -1,   178,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    -1,    78,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    -1,    88,    -1,    90,    -1,    92,    -1,
      -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,    -1,
     104,   105,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,   115,    -1,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,    -1,   139,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,
      -1,     3,     4,     5,     6,     7,    -1,     9,    -1,   163,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,   176,    -1,   178,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    88,    -1,    90,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,   101,
     102,    -1,   104,   105,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,   115,    -1,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,    -1,   139,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      -1,   163,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   176,    -1,   178,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    78,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    -1,    88,    -1,
      90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,   104,   105,    -1,   107,    -1,   109,
      -1,    -1,    -1,    -1,    -1,   115,    -1,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,    -1,   139,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,    -1,     3,     4,     5,     6,     7,    -1,
       9,    -1,    -1,   163,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,    -1,   175,   176,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    88,
      -1,    90,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
      99,   100,   101,   102,    -1,   104,   105,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,   115,    -1,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,    -1,
     139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,    -1,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,   163,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,    -1,   175,   176,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,   133,     3,     4,     5,     6,
       7,    -1,     9,    -1,    -1,   143,    13,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,   173,    43,    44,    -1,    -1,
     178,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   102,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      64,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,   143,    -1,    -1,    13,
      -1,    -1,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,   173,    -1,   175,    43,
      44,   178,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   102,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    64,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,     3,     4,     5,     6,     7,    -1,     9,   143,
      -1,    -1,    13,    -1,    -1,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,   173,
      -1,   175,    43,    44,   178,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   102,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    64,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,   143,    -1,    -1,    13,    -1,    -1,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,   173,    -1,   175,    43,    44,   178,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,     3,     4,     5,
       6,     7,    -1,     9,    -1,   143,    -1,    13,    -1,    -1,
      -1,   149,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    32,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,   173,   174,    43,    44,    -1,
     178,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,     3,
       4,     5,     6,     7,    -1,     9,    -1,   143,    -1,    13,
      -1,    -1,    -1,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    32,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,   173,    -1,    43,
      44,    -1,   178,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,   132,   133,
       3,     4,     5,     6,     7,    -1,     9,    -1,    -1,   143,
      13,    -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,   173,
      43,    44,    -1,    -1,   178,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,     3,     4,     5,     6,     7,    -1,     9,    -1,
     143,    -1,    13,    -1,    -1,    -1,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
     173,    -1,    43,    44,    -1,   178,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,     3,     4,     5,     6,     7,    -1,
       9,    -1,   143,    -1,    13,    -1,    -1,    -1,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    32,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,   173,    -1,    43,    44,    -1,   178,    -1,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    67,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,     3,     4,     5,     6,
       7,    -1,     9,    -1,   143,    -1,    13,    -1,    -1,    -1,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    32,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,   173,    -1,    43,    44,    -1,   178,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      67,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,     3,     4,
       5,     6,     7,    -1,     9,    -1,   143,    -1,    13,    -1,
      -1,    -1,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,   173,    -1,    43,    44,
      -1,   178,    -1,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
       3,     4,     5,     6,     7,    -1,     9,    -1,   143,    -1,
      13,    -1,    -1,    -1,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    32,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,   173,    -1,
      43,    44,    -1,   178,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,   132,
     133,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
     143,    13,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
     173,    43,    44,    -1,    -1,   178,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   178,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    10,    11,    12,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    10,    11,    12,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    10,    11,
      12,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    10,
      11,    12,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      10,    11,    12,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    10,    11,    12,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    -1,   175,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   175,    50,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   175,    50,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   175,    50,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,   174,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     174,    50,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   174,    50,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   174,    50,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,   174,    -1,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   174,    50,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   174,    50,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   174,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,   174,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    64,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   182,   183,     0,     3,     4,     5,     6,     7,     9,
      13,    37,    43,    44,    49,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    65,    66,
      67,    68,    72,    73,    74,    75,    76,    78,    82,    83,
      84,    85,    86,    88,    90,    92,    95,    99,   100,   101,
     102,   103,   104,   105,   107,   108,   109,   113,   114,   115,
     117,   118,   119,   120,   121,   122,   127,   128,   129,   130,
     131,   132,   133,   136,   137,   139,   143,   149,   150,   151,
     152,   163,   173,   175,   176,   178,   184,   185,   188,   191,
     192,   198,   199,   201,   202,   203,   205,   244,   245,   248,
     249,   257,   260,   264,   265,   267,   268,   272,   273,   274,
     275,   276,   277,   278,   283,   288,   290,   291,   292,   293,
     295,    74,   115,   149,   245,   264,   264,   173,   264,   264,
      99,   264,   264,   308,   309,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   115,
     149,   152,   184,   249,   267,   268,   274,   267,   264,   149,
     152,   184,   249,   251,   252,   274,   276,   277,   283,   173,
     255,   173,    27,   241,   264,   191,   173,   173,   173,   173,
     173,   175,   264,   175,   264,    74,    74,   175,   244,   264,
     268,   176,   264,   152,   184,   186,   187,    76,   178,   228,
     229,   121,   121,    76,   230,   245,   173,   173,   173,   173,
     173,   173,   152,   176,   184,   184,   308,   264,   189,   176,
     152,   173,     8,   175,    27,    74,    74,    32,   200,   146,
      10,    11,    12,    26,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    50,    64,   175,    62,    63,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   173,   146,   125,    64,   176,   178,   277,   154,
     172,   296,   297,   301,   200,   264,    74,   318,   152,   184,
     146,   146,   152,   184,   146,   173,   256,   146,   125,   277,
     174,   264,   264,     8,   175,    86,   264,   242,   243,   264,
     244,   268,    74,   214,   264,   175,   175,   175,    14,   175,
     175,   189,   175,   184,    94,     8,   175,   176,   265,   268,
       8,   175,    14,     8,   175,   200,   196,   197,   268,   268,
     289,   268,   174,   127,   268,   284,   285,    32,   264,   286,
     287,   184,   183,   175,   176,   173,   174,   120,   177,   190,
     191,   198,   199,   264,    74,    32,   226,   227,   244,   268,
      74,   308,   123,   204,   123,   206,    74,   173,    74,   272,
     277,   283,   264,   264,   264,    27,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   251,   264,
     279,    32,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   226,    74,   272,    74,   176,   272,
     280,   281,   282,   279,   264,   154,   172,   155,   156,   176,
     291,   294,   298,    38,    47,   302,   312,   313,   174,   153,
     163,   164,   320,   184,    74,    74,   184,   272,   226,   272,
     280,   174,   174,   264,   173,   174,   175,     8,    94,    94,
      14,     8,   174,   174,    43,    44,   128,   149,   152,   184,
     249,   257,   258,   259,   177,    94,    74,   187,   264,   229,
     258,    76,   173,     8,   174,     8,   174,   174,   175,   173,
       8,   174,   266,   268,   126,   174,     8,   262,   173,   177,
     183,   226,   173,   177,   266,   174,     8,    14,   204,   149,
     152,   163,   184,   250,   124,   207,   208,   250,   176,   173,
     128,   223,   224,   225,   250,   173,   173,   277,   264,    27,
     179,    66,   268,   174,   173,   173,   264,   173,   271,    64,
     176,   179,   177,   310,   311,   299,   296,    38,    14,    74,
     319,    74,    74,   174,   253,    27,   191,   264,    27,   191,
     218,   242,   264,   268,    32,   210,   268,   258,    74,    27,
     191,   213,    27,   176,   215,   258,   258,   173,   152,   184,
     146,   106,    74,   177,    14,   223,   197,   175,   268,   284,
     285,    14,    32,   264,    32,   264,   226,   177,   174,   174,
      32,   244,   268,   258,   207,   152,   184,   308,   208,   176,
       8,   231,   223,   174,     8,    32,    76,   226,   226,   264,
     251,   226,   226,   177,   226,   269,   279,   264,    38,   318,
     264,   176,   180,   303,   163,   164,   320,   125,   254,   189,
     219,   174,   189,   175,   126,   209,   268,   209,    14,   189,
     175,   216,   175,   216,   258,   261,   263,   184,    74,   173,
     258,   174,   174,   264,   266,   266,   126,   174,   175,   266,
     176,   184,   231,   250,   103,   110,   111,   112,   113,   114,
     115,   116,   157,   158,   159,   177,   232,   235,   236,   237,
     238,   240,   174,   108,   246,   225,    76,    14,   174,   174,
     256,   174,   174,   174,   125,   270,   179,   177,   177,   305,
     304,    74,    74,   280,   220,    69,    70,   221,   175,    87,
     242,   210,   174,   174,   258,    93,   216,    96,    97,    98,
     216,   177,   126,   174,     8,   262,   250,   246,    32,   264,
     321,   177,    74,   323,   332,   334,    76,   239,   245,   238,
       8,   175,   176,   173,   176,    32,    76,    14,   258,   280,
     300,   264,   296,   307,    69,    70,   222,   173,   191,   175,
     174,    27,   191,   212,   212,   175,    96,   175,   264,    27,
     175,   217,   177,   258,   258,    76,   176,   266,   231,    14,
     116,   163,   165,   166,   167,   168,   169,   170,   249,   324,
     325,   326,    48,   333,   160,   161,   173,   335,   336,    14,
       8,   175,   233,    74,   189,    32,    76,   247,   189,    76,
      14,   258,   271,   306,   180,   173,    27,    71,   264,    27,
     191,   211,   189,   175,   217,   189,   126,   174,   189,   322,
     258,   308,   176,     8,   175,   312,   314,   315,     8,   175,
      48,   160,   162,   163,   336,   337,   338,   175,   258,    76,
     200,    14,   177,    76,     8,   174,   177,    14,   258,   177,
     264,   189,   175,   174,   189,    91,   189,   258,   176,   177,
     177,   327,   325,    14,   330,   319,    48,   316,   317,   316,
       8,    30,   174,    26,    43,    46,    14,    74,   258,    32,
      76,   258,   174,   191,    89,   175,   189,   257,   329,   258,
     171,   331,   320,   314,   318,   337,   337,    26,    43,    46,
     258,   173,    76,    27,   175,   177,     8,   328,   320,   223,
     189,   106,   193,   194,   195,   257,   177,   174,   173,   195,
     175,   176,   234,   250,   189,    76,   177,   174,   176,   189,
     177
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
#line 230 "parser.y"
    {
    *root = NNEW(n_PROGRAM)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 3:
#line 236 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 4:
#line 239 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 5:
#line 245 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_SYMBOL_NAME);
  ;}
    break;

  case 6:
#line 248 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 10:
#line 257 "parser.y"
    {
    (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 11:
#line 262 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_NAMESPACE, (yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild(NNEW(n_EMPTY));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 12:
#line 269 "parser.y"
    {
  NSPAN((yyvsp[(1) - (5)]), n_NAMESPACE, (yyvsp[(5) - (5)]));
  (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
  NMORE((yyvsp[(4) - (5)]), (yyvsp[(5) - (5)]));
  NLMORE((yyvsp[(4) - (5)]), (yyvsp[(3) - (5)]));
  (yyvsp[(1) - (5)])->appendChild((yyvsp[(4) - (5)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 13:
#line 277 "parser.y"
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
#line 285 "parser.y"
    {
  NSPAN((yyvsp[(1) - (3)]), n_USE, (yyvsp[(2) - (3)]));
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 15:
#line 291 "parser.y"
    {
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
  NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 16:
#line 298 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 17:
#line 301 "parser.y"
    {
    (yyval) = NNEW(n_USE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 18:
#line 308 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 19:
#line 313 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    NTYPE((yyvsp[(3) - (3)]), n_STRING);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 20:
#line 319 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 21:
#line 325 "parser.y"
    {
    (yyval) = NNEW(n_USE);
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
    NTYPE((yyvsp[(4) - (4)]), n_STRING);
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  ;}
    break;

  case 22:
#line 335 "parser.y"
    {
    NMORE((yyval), (yyvsp[(5) - (5)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING))
        ->appendChild((yyvsp[(5) - (5)])));
  ;}
    break;

  case 23:
#line 342 "parser.y"
    {
    NSPAN((yyval), n_CONSTANT_DECLARATION_LIST, (yyvsp[(4) - (4)]));
    (yyval)->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE((yyvsp[(2) - (4)]), n_STRING))
        ->appendChild((yyvsp[(4) - (4)])));
  ;}
    break;

  case 24:
#line 352 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 25:
#line 355 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 29:
#line 364 "parser.y"
    {
  (yyvsp[(1) - (4)]) = NSPAN((yyvsp[(1) - (4)]), n_HALT_COMPILER, (yyvsp[(3) - (4)]));
  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (4)]));
  NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 31:
#line 373 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_STRING);
    (yyval) = NNEW(n_LABEL);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 32:
#line 379 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  ;}
    break;

  case 33:
#line 382 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_OPEN_TAG);
  ;}
    break;

  case 34:
#line 385 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLOSE_TAG);
  ;}
    break;

  case 35:
#line 391 "parser.y"
    {
    NMORE((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 36:
#line 396 "parser.y"
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
#line 426 "parser.y"
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
#line 441 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_WHILE);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 39:
#line 448 "parser.y"
    {
    NTYPE((yyvsp[(1) - (7)]), n_DO_WHILE);
    (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
    (yyvsp[(1) - (7)])->appendChild(NSPAN((yyvsp[(4) - (7)]), n_CONTROL_CONDITION, (yyvsp[(6) - (7)]))->appendChild((yyvsp[(5) - (7)])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (7)]));
    NMORE((yyval), (yyvsp[(7) - (7)]));
  ;}
    break;

  case 40:
#line 456 "parser.y"
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
#line 469 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_SWITCH);
    (yyvsp[(1) - (5)])->appendChild(NSPAN((yyvsp[(2) - (5)]), n_CONTROL_CONDITION, (yyvsp[(4) - (5)]))->appendChild((yyvsp[(3) - (5)])));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 42:
#line 476 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_BREAK);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 43:
#line 483 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_BREAK);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 44:
#line 490 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_CONTINUE);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 45:
#line 497 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_CONTINUE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 46:
#line 504 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_RETURN);
    (yyvsp[(1) - (2)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 47:
#line 511 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 48:
#line 518 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_RETURN);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 49:
#line 525 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 50:
#line 530 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 51:
#line 535 "parser.y"
    {
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 52:
#line 540 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_INLINE_HTML);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 53:
#line 544 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 54:
#line 548 "parser.y"
    {
    NMORE((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]));
    NLMORE((yyvsp[(3) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(3) - (5)]));
    NMORE((yyval), (yyvsp[(5) - (5)]));
  ;}
    break;

  case 55:
#line 554 "parser.y"
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
#line 571 "parser.y"
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
#line 587 "parser.y"
    {
    NTYPE((yyvsp[(1) - (5)]), n_DECLARE);
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(1) - (5)])->appendChild((yyvsp[(5) - (5)]));
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (5)]));
  ;}
    break;

  case 58:
#line 593 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE((yyval), (yyvsp[(1) - (1)]));
  ;}
    break;

  case 59:
#line 597 "parser.y"
    {
    NTYPE((yyvsp[(1) - (13)]), n_TRY);
    (yyvsp[(1) - (13)])->appendChild((yyvsp[(3) - (13)]));

    NTYPE((yyvsp[(5) - (13)]), n_CATCH);
    (yyvsp[(5) - (13)])->appendChild((yyvsp[(7) - (13)]));
    (yyvsp[(5) - (13)])->appendChild(NTYPE((yyvsp[(8) - (13)]), n_VARIABLE));
    (yyvsp[(5) - (13)])->appendChild((yyvsp[(11) - (13)]));

    (yyvsp[(1) - (13)])->appendChild(NNEW(n_CATCH_LIST)->appendChild((yyvsp[(5) - (13)]))->appendChildren((yyvsp[(13) - (13)])));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (13)]));
  ;}
    break;

  case 60:
#line 610 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_THROW);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));

  ;}
    break;

  case 61:
#line 618 "parser.y"
    {
  NTYPE((yyvsp[(1) - (3)]), n_GOTO);
  NTYPE((yyvsp[(2) - (3)]), n_STRING);
  (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));

  (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (3)]));
  NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 63:
#line 630 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 64:
#line 636 "parser.y"
    {
    (yyval) = NNEW(n_CATCH_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 65:
#line 640 "parser.y"
    {
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 66:
#line 647 "parser.y"
    {
    NTYPE((yyvsp[(1) - (8)]), n_CATCH);
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(3) - (8)]));
    (yyvsp[(1) - (8)])->appendChild(NTYPE((yyvsp[(4) - (8)]), n_VARIABLE));
    (yyvsp[(1) - (8)])->appendChild((yyvsp[(7) - (8)]));
    NMORE((yyvsp[(1) - (8)]), (yyvsp[(8) - (8)]));
    (yyval) = (yyvsp[(1) - (8)]);
  ;}
    break;

  case 67:
#line 658 "parser.y"
    {
    (yyval) = NNEW(n_UNSET_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 68:
#line 662 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 72:
#line 681 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 73:
#line 684 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_REFERENCE);
  ;}
    break;

  case 74:
#line 690 "parser.y"
    {
    NSPAN((yyvsp[(1) - (9)]), n_FUNCTION_DECLARATION, (yyvsp[(9) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(2) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NTYPE((yyvsp[(3) - (9)]), n_STRING));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(6) - (9)])));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(8) - (9)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (9)]));
  ;}
    break;

  case 75:
#line 704 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (7)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (7)]), n_CLASS_NAME));
    (yyval)->appendChild((yyvsp[(3) - (7)]));
    (yyval)->appendChild((yyvsp[(4) - (7)]));
    (yyval)->appendChild((yyvsp[(6) - (7)]));
    NMORE((yyval), (yyvsp[(7) - (7)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  ;}
    break;

  case 76:
#line 715 "parser.y"
    {
    (yyval) = NNEW(n_INTERFACE_DECLARATION);
    (yyval)->appendChild(NNEW(n_EMPTY));
    NLMORE((yyval), (yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (6)]), n_CLASS_NAME));
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(5) - (6)]));
    NMORE((yyval), (yyvsp[(6) - (6)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
  ;}
    break;

  case 77:
#line 730 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_CLASS_ATTRIBUTES);
    (yyvsp[(1) - (1)])->appendChild(NNEW(n_EMPTY));
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 78:
#line 735 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 79:
#line 742 "parser.y"
    {
    NTYPE((yyvsp[(2) - (2)]), n_CLASS_ATTRIBUTES);
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyvsp[(2) - (2)])->appendChild(NTYPE((yyvsp[(1) - (2)]), n_STRING));

    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 80:
#line 752 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 81:
#line 755 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 83:
#line 765 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 84:
#line 768 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_EXTENDS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 85:
#line 776 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 86:
#line 779 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_IMPLEMENTS_LIST);
    (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 87:
#line 787 "parser.y"
    {
    (yyval) = NNEW(n_IMPLEMENTS_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 88:
#line 790 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 89:
#line 796 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 90:
#line 799 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 92:
#line 806 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 94:
#line 815 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 96:
#line 824 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 98:
#line 833 "parser.y"
    {
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 99:
#line 841 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_STRING));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval) = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 100:
#line 847 "parser.y"
    {
    (yyval) = NNEW(n_DECLARE_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));
    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 101:
#line 858 "parser.y"
    {
    NMORE((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 102:
#line 863 "parser.y"
    {
    // ...why does this rule exist?

    NTYPE((yyvsp[(2) - (4)]), n_STATEMENT);
    (yyvsp[(1) - (4)])->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATEMENT_LIST)->appendChild((yyvsp[(2) - (4)]));
    (yyval)->appendChildren((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
    NLMORE((yyval), (yyvsp[(1) - (4)]));
  ;}
    break;

  case 103:
#line 874 "parser.y"
    {
    NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
    NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
    (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 104:
#line 879 "parser.y"
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
#line 891 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 106:
#line 894 "parser.y"
    {
    NTYPE((yyvsp[(2) - (5)]), n_CASE);
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(3) - (5)]));
    (yyvsp[(2) - (5)])->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyvsp[(2) - (5)]));
    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 107:
#line 902 "parser.y"
    {
    NTYPE((yyvsp[(2) - (4)]), n_DEFAULT);
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(4) - (4)]));

    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 111:
#line 918 "parser.y"
    {
  NMORE((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
  NLMORE((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]));
  (yyval) = (yyvsp[(2) - (4)]);
  ;}
    break;

  case 112:
#line 926 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  ;}
    break;

  case 113:
#line 929 "parser.y"
    {
    NTYPE((yyvsp[(2) - (6)]), n_ELSEIF);
    (yyvsp[(2) - (6)])->appendChild(NSPAN((yyvsp[(3) - (6)]), n_CONTROL_CONDITION, (yyvsp[(5) - (6)]))->appendChild((yyvsp[(4) - (6)])));
    (yyvsp[(2) - (6)])->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyvsp[(2) - (6)]));
  ;}
    break;

  case 114:
#line 939 "parser.y"
    {
    (yyval) = NNEW(n_CONDITION_LIST);
  ;}
    break;

  case 115:
#line 942 "parser.y"
    {
    NTYPE((yyvsp[(2) - (7)]), n_ELSEIF);
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(4) - (7)]));
    (yyvsp[(2) - (7)])->appendChild((yyvsp[(7) - (7)]));

    (yyval) = (yyvsp[(1) - (7)])->appendChild((yyvsp[(2) - (7)]));
  ;}
    break;

  case 116:
#line 952 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 117:
#line 955 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_ELSE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 118:
#line 963 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 119:
#line 966 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_ELSE);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 121:
#line 975 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST);
  ;}
    break;

  case 122:
#line 981 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 123:
#line 989 "parser.y"
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
#line 998 "parser.y"
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
#line 1007 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (4)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(4) - (4)]));

    (yyval) = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild((yyval));
  ;}
    break;

  case 126:
#line 1015 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  ;}
    break;

  case 127:
#line 1023 "parser.y"
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
#line 1032 "parser.y"
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
#line 1041 "parser.y"
    {
    (yyval) = NNEW(n_DECLARATION_PARAMETER);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(4) - (6)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(6) - (6)]));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  ;}
    break;

  case 130:
#line 1052 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 131:
#line 1055 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 132:
#line 1058 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_TYPE_NAME);
  ;}
    break;

  case 134:
#line 1065 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST);
  ;}
    break;

  case 135:
#line 1071 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 136:
#line 1074 "parser.y"
    {
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 137:
#line 1077 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
    (yyval) = NNEW(n_CALL_PARAMETER_LIST)->appendChild((yyvsp[(1) - (2)]));
  ;}
    break;

  case 138:
#line 1082 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 139:
#line 1085 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 140:
#line 1088 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 141:
#line 1094 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 142:
#line 1098 "parser.y"
    {
    (yyval) = NNEW(n_GLOBAL_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 143:
#line 1105 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  ;}
    break;

  case 144:
#line 1108 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 145:
#line 1112 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (4)]), n_VARIABLE_VARIABLE);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 146:
#line 1119 "parser.y"
    {
    NTYPE((yyvsp[(3) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (3)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 147:
#line 1127 "parser.y"
    {
    NTYPE((yyvsp[(3) - (5)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 148:
#line 1135 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 149:
#line 1143 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_VARIABLE);
    (yyval) = NNEW(n_STATIC_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_STATIC_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 150:
#line 1154 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 151:
#line 1157 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT_LIST);
  ;}
    break;

  case 152:
#line 1163 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChildren((yyvsp[(2) - (3)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));
    NMORE((yyval), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 153:
#line 1171 "parser.y"
    {
    (yyval) = NNEW(n_STATEMENT)->appendChild((yyvsp[(1) - (2)]));
    NMORE((yyval), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 154:
#line 1175 "parser.y"
    {
    yyextra->old_expecting_xhp_class_statements = yyextra->expecting_xhp_class_statements;
    yyextra->expecting_xhp_class_statements = false;
  ;}
    break;

  case 155:
#line 1178 "parser.y"
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
#line 1194 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 157:
#line 1197 "parser.y"
    {
    NMORE((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
    NLMORE((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 159:
#line 1206 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 160:
#line 1213 "parser.y"
    {
    (yyval) = NNEW(n_METHOD_MODIFIER_LIST);
  ;}
    break;

  case 161:
#line 1216 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_METHOD_MODIFIER_LIST);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 162:
#line 1223 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_STRING));
  ;}
    break;

  case 163:
#line 1227 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_STRING));
  ;}
    break;

  case 170:
#line 1242 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 171:
#line 1249 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 172:
#line 1256 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
    (yyval)->appendChild(NNEW(n_EMPTY));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 173:
#line 1263 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (3)]), n_VARIABLE));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild((yyval));
  ;}
    break;

  case 174:
#line 1273 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_CONSTANT_DECLARATION);
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (5)]), n_STRING));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyvsp[(1) - (5)])->appendChild((yyval));

    (yyval) = (yyvsp[(1) - (5)]);
  ;}
    break;

  case 175:
#line 1282 "parser.y"
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
#line 1294 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 177:
#line 1297 "parser.y"
    {
    (yyval) = NNEW(n_ECHO_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 178:
#line 1304 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 180:
#line 1312 "parser.y"
    {
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 181:
#line 1315 "parser.y"
    {
    (yyval) = NNEW(n_EXPRESSION_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 182:
#line 1322 "parser.y"
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
#line 1330 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 184:
#line 1336 "parser.y"
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
#line 1346 "parser.y"
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
#line 1360 "parser.y"
    {
    NTYPE((yyvsp[(1) - (3)]), n_NEW);
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 187:
#line 1366 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 188:
#line 1371 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 189:
#line 1377 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 190:
#line 1383 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 191:
#line 1389 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 192:
#line 1395 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 193:
#line 1401 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 194:
#line 1407 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 195:
#line 1413 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 196:
#line 1419 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 197:
#line 1425 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 198:
#line 1431 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 199:
#line 1437 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  ;}
    break;

  case 200:
#line 1442 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 201:
#line 1447 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_OPERATOR));
  ;}
    break;

  case 202:
#line 1452 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 203:
#line 1457 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 204:
#line 1463 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 205:
#line 1469 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 206:
#line 1475 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 207:
#line 1481 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 208:
#line 1487 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 209:
#line 1493 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 210:
#line 1499 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 211:
#line 1505 "parser.y"
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
#line 1531 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 213:
#line 1537 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 214:
#line 1543 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 215:
#line 1549 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 216:
#line 1555 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 217:
#line 1561 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 218:
#line 1567 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 219:
#line 1573 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 220:
#line 1578 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 221:
#line 1583 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 222:
#line 1588 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 223:
#line 1593 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 224:
#line 1599 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 225:
#line 1605 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 226:
#line 1611 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 227:
#line 1617 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 228:
#line 1623 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 229:
#line 1629 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 230:
#line 1635 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 231:
#line 1641 "parser.y"
    {
    (yyval) = NNEW(n_BINARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (3)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 232:
#line 1647 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 233:
#line 1652 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (5)]));
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));
  ;}
    break;

  case 234:
#line 1658 "parser.y"
    {
    (yyval) = NNEW(n_TERNARY_EXPRESSION);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(4) - (4)]));
  ;}
    break;

  case 236:
#line 1665 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 237:
#line 1670 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 238:
#line 1675 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 239:
#line 1680 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 240:
#line 1685 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 241:
#line 1690 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 242:
#line 1695 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 243:
#line 1700 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 244:
#line 1705 "parser.y"
    {
    (yyval) = NNEW(n_CAST_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_CAST));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 245:
#line 1710 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 246:
#line 1715 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 247:
#line 1720 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 248:
#line 1726 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_BACKTICKS_EXPRESSION);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 250:
#line 1731 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 251:
#line 1736 "parser.y"
    {
    NSPAN((yyvsp[(1) - (9)]), n_FUNCTION_DECLARATION, (yyvsp[(9) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(2) - (9)]));
    (yyvsp[(1) - (9)])->appendChild(NNEW(n_EMPTY));
    (yyvsp[(1) - (9)])->appendChild(NEXPAND((yyvsp[(3) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)])));
    (yyval)->appendChild((yyvsp[(6) - (9)]));
    (yyvsp[(1) - (9)])->appendChild((yyvsp[(8) - (9)]));

    (yyval) = (yyvsp[(1) - (9)]);
  ;}
    break;

  case 252:
#line 1747 "parser.y"
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
    (yyvsp[(2) - (10)])->appendChild((yyvsp[(9) - (10)]));

    (yyval) = (yyvsp[(2) - (10)]);
  ;}
    break;

  case 253:
#line 1764 "parser.y"
    {
    (yyval) = NNEW(n_YIELD_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_YIELD));
    (yyval)->appendChild(NTYPE((yyvsp[(2) - (2)]), n_BREAK));
  ;}
    break;

  case 254:
#line 1769 "parser.y"
    {
    (yyval) = NNEW(n_YIELD_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_YIELD));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 256:
#line 1781 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 257:
#line 1784 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_LEXICAL_VARIABLE_LIST);
    (yyvsp[(1) - (4)])->appendChildren((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 258:
#line 1792 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild(NTYPE((yyvsp[(3) - (3)]), n_VARIABLE));
  ;}
    break;

  case 259:
#line 1795 "parser.y"
    {
    NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE);
    (yyvsp[(3) - (4)])->appendChild(NTYPE((yyvsp[(4) - (4)]), n_VARIABLE));
    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 260:
#line 1800 "parser.y"
    {
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (1)]), n_VARIABLE));
  ;}
    break;

  case 261:
#line 1804 "parser.y"
    {
    NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE);
    (yyvsp[(1) - (2)])->appendChild(NTYPE((yyvsp[(2) - (2)]), n_VARIABLE));
    (yyval) = NNEW(n_LEXICAL_VARIABLE_LIST);
    (yyval)->appendChild((yyvsp[(1) - (2)]));
  ;}
    break;

  case 262:
#line 1813 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  ;}
    break;

  case 263:
#line 1818 "parser.y"
    {
    NLMORE((yyvsp[(3) - (6)]), (yyvsp[(1) - (6)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 264:
#line 1824 "parser.y"
    {
    NLMORE((yyvsp[(2) - (5)]), (yyvsp[(1) - (5)]));
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(2) - (5)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(3) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])));
  ;}
    break;

  case 265:
#line 1830 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 266:
#line 1838 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 267:
#line 1846 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 268:
#line 1854 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (6)]), n_STRING));

    (yyval) = NNEW(n_FUNCTION_CALL)->appendChild((yyval));
    (yyval)->appendChild(NEXPAND((yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])));
  ;}
    break;

  case 269:
#line 1862 "parser.y"
    {
    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NEXPAND((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])));
  ;}
    break;

  case 270:
#line 1870 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 271:
#line 1873 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 272:
#line 1876 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  ;}
    break;

  case 273:
#line 1880 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  ;}
    break;

  case 274:
#line 1887 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_CLASS_NAME);
  ;}
    break;

  case 275:
#line 1890 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = NTYPE((yyvsp[(3) - (3)]), n_CLASS_NAME);
  ;}
    break;

  case 276:
#line 1894 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = NTYPE((yyvsp[(2) - (2)]), n_CLASS_NAME);
  ;}
    break;

  case 279:
#line 1906 "parser.y"
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

  case 281:
#line 1919 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 282:
#line 1922 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 283:
#line 1928 "parser.y"
    {
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 284:
#line 1934 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 285:
#line 1937 "parser.y"
    {
    NSPAN((yyvsp[(1) - (2)]), n_EMPTY, (yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 286:
#line 1941 "parser.y"
    {
    NSPAN((yyvsp[(1) - (3)]), n_PARENTHETICAL_EXPRESSION, (yyvsp[(3) - (3)]));
    (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    (yyval) = (yyvsp[(1) - (3)]);
  ;}
    break;

  case 287:
#line 1949 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 288:
#line 1952 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 289:
#line 1958 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  ;}
    break;

  case 290:
#line 1961 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_NUMERIC_SCALAR);
  ;}
    break;

  case 291:
#line 1964 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_STRING_SCALAR);
  ;}
    break;

  case 292:
#line 1967 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 293:
#line 1970 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 294:
#line 1973 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 295:
#line 1976 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 296:
#line 1979 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 297:
#line 1982 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 298:
#line 1985 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_MAGIC_SCALAR);
  ;}
    break;

  case 299:
#line 1988 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_HEREDOC);
  ;}
    break;

  case 302:
#line 1996 "parser.y"
    {
    NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
    (yyval) = (yyvsp[(3) - (3)]);
  ;}
    break;

  case 303:
#line 2000 "parser.y"
    {
    NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 304:
#line 2004 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 305:
#line 2009 "parser.y"
    {
    (yyval) = NNEW(n_UNARY_PREFIX_EXPRESSION);
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_OPERATOR));
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 306:
#line 2014 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_ARRAY_LITERAL);
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 308:
#line 2024 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 312:
#line 2035 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));
  ;}
    break;

  case 313:
#line 2038 "parser.y"
    {
    (yyval) = NLMORE((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
  ;}
    break;

  case 315:
#line 2045 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  ;}
    break;

  case 316:
#line 2048 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 317:
#line 2054 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 319:
#line 2061 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 320:
#line 2068 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 321:
#line 2075 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 322:
#line 2082 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 328:
#line 2109 "parser.y"
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

  case 330:
#line 2133 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChildren((yyvsp[(2) - (2)]));
  ;}
    break;

  case 331:
#line 2136 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 332:
#line 2142 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(2) - (3)]));
    if ((yyvsp[(3) - (3)])->type != n_EMPTY) {
      (yyval)->appendChild((yyvsp[(3) - (3)]));
    }
  ;}
    break;

  case 333:
#line 2152 "parser.y"
    {
    (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 334:
#line 2155 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 336:
#line 2162 "parser.y"
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

  case 337:
#line 2177 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 338:
#line 2182 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 343:
#line 2200 "parser.y"
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

  case 345:
#line 2216 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 346:
#line 2222 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 348:
#line 2232 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_VARIABLE);
  ;}
    break;

  case 349:
#line 2235 "parser.y"
    {
    NSPAN((yyvsp[(1) - (4)]), n_VARIABLE_EXPRESSION, (yyvsp[(4) - (4)]));
    (yyvsp[(1) - (4)])->appendChild((yyvsp[(3) - (4)]));
    (yyval) = (yyvsp[(1) - (4)]);
  ;}
    break;

  case 350:
#line 2243 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 351:
#line 2246 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 354:
#line 2257 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]))
  ;}
    break;

  case 355:
#line 2263 "parser.y"
    {
    (yyval) = NNEW(n_INDEX_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 357:
#line 2273 "parser.y"
    {
    NTYPE((yyvsp[(1) - (1)]), n_STRING);
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 358:
#line 2277 "parser.y"
    {
  (yyval) = NEXPAND((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 359:
#line 2283 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_VARIABLE_VARIABLE);
  ;}
    break;

  case 360:
#line 2286 "parser.y"
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

  case 361:
#line 2301 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 362:
#line 2304 "parser.y"
    {
    (yyval) = NNEW(n_ASSIGNMENT_LIST);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 364:
#line 2312 "parser.y"
    {
    (yyval) = NNEW(n_LIST);
    (yyval)->appendChild((yyvsp[(3) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));
  ;}
    break;

  case 365:
#line 2317 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 366:
#line 2323 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE_LIST);
  ;}
    break;

  case 367:
#line 2326 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 368:
#line 2332 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    (yyval)->appendChild((yyvsp[(5) - (5)]));

    (yyval) = (yyvsp[(1) - (5)])->appendChild((yyval));
  ;}
    break;

  case 369:
#line 2339 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyval));
  ;}
    break;

  case 370:
#line 2346 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 371:
#line 2353 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild((yyvsp[(1) - (1)]));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 372:
#line 2360 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(3) - (6)]));
    (yyval)->appendChild(NTYPE((yyvsp[(5) - (6)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(6) - (6)])));

    (yyval) = (yyvsp[(1) - (6)])->appendChild((yyval));
  ;}
    break;

  case 373:
#line 2367 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = (yyvsp[(1) - (4)])->appendChild((yyval));
  ;}
    break;

  case 374:
#line 2374 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (4)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(4) - (4)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 375:
#line 2381 "parser.y"
    {
    (yyval) = NNEW(n_ARRAY_VALUE);
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NTYPE((yyvsp[(1) - (2)]), n_VARIABLE_REFERENCE)->appendChild((yyvsp[(2) - (2)])));

    (yyval) = NNEW(n_ARRAY_VALUE_LIST)->appendChild((yyval));
  ;}
    break;

  case 376:
#line 2391 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChildren((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 377:
#line 2401 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 378:
#line 2411 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 379:
#line 2414 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 380:
#line 2417 "parser.y"
    {
    NTYPE((yyvsp[(1) - (4)]), n_SYMBOL_NAME);

    NSPAN((yyvsp[(2) - (4)]), n_CALL_PARAMETER_LIST, (yyvsp[(4) - (4)]));
    (yyvsp[(2) - (4)])->appendChild((yyvsp[(3) - (4)]));

    (yyval) = NNEW(n_FUNCTION_CALL);
    (yyval)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild((yyvsp[(2) - (4)]));
  ;}
    break;

  case 381:
#line 2427 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 382:
#line 2430 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_INCLUDE_FILE)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 383:
#line 2436 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
    (yyval)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 384:
#line 2440 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 385:
#line 2446 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 386:
#line 2451 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_STATIC_ACCESS);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild(NTYPE((yyvsp[(3) - (3)]), n_STRING));
  ;}
    break;

  case 387:
#line 2463 "parser.y"
    {
    yyextra->used = true;
    (yyval) = (yyvsp[(1) - (1)]);
  ;}
    break;

  case 389:
#line 2471 "parser.y"
    {
    (yyval) = NNEW(n_XHP_TAG);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(2) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 390:
#line 2480 "parser.y"
    {
    pop_state(); // XHP_ATTRS

    (yyvsp[(1) - (4)])->appendChild((yyvsp[(2) - (4)]));
    NMORE((yyval), (yyvsp[(4) - (4)]));

    (yyval) = NNEW(n_XHP_TAG)->appendChild((yyvsp[(1) - (4)]));
    (yyval)->appendChild(NNEW(n_EMPTY));
    (yyval)->appendChild(NNEW(n_EMPTY));
  ;}
    break;

  case 391:
#line 2493 "parser.y"
    {
    pop_state(); // XHP_ATTRS
    push_state(XHP_CHILD_START);
/* TODO: RESTORE THIS
    yyextra->pushTag((*($1->l_tok))->value.c_str());
*/
    yyextra->pushTag("TODO");

    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]));
    NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 392:
#line 2507 "parser.y"
    {
    pop_state(); // XHP_CHILD_START
/* TOOD: RESTORE THIS
    if (yyextra->peekTag() != (*($2->l_tok))->value.c_str()) {
      string e1 = (*($2->l_tok))->value.c_str();
      string e2 = yyextra->peekTag();
      replacestr(e1, "__", ":");
      replacestr(e1, "_", "-");
      replacestr(e2, "__", ":");
      replacestr(e2, "_", "-");
      string e = "syntax error, mismatched tag </" + e1 + ">, expecting </" + e2 +">";
      yyerror(yyscanner, NULL, e.c_str());
      yyextra->terminated = true;
    }
*/
    yyextra->popTag();
    if (yyextra->haveTag()) {
      set_state(XHP_CHILD_START);
    }

    (yyval) = NSPAN((yyvsp[(1) - (3)]), n_XHP_TAG_CLOSE, (yyvsp[(3) - (3)]));
  ;}
    break;

  case 393:
#line 2529 "parser.y"
    {
    // empty end tag -- SGML SHORTTAG
    pop_state(); // XHP_CHILD_START
    yyextra->popTag();
    if (yyextra->haveTag()) {
      set_state(XHP_CHILD_START);
    }
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_XHP_TAG_CLOSE);
  ;}
    break;

  case 394:
#line 2541 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (2)]), n_XHP_TAG_OPEN);
    (yyval)->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 395:
#line 2549 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_XHP_TEXT);
  ;}
    break;

  case 396:
#line 2552 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_XHP_TEXT);
  ;}
    break;

  case 397:
#line 2555 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 398:
#line 2558 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
  ;}
    break;

  case 399:
#line 2564 "parser.y"
    {
    (yyval) = NNEW(n_XHP_NODE_LIST);
  ;}
    break;

  case 400:
#line 2567 "parser.y"
    {
    set_state(XHP_CHILD_START);
    (yyval) = NNEW(n_XHP_NODE_LIST)->appendChild((yyvsp[(1) - (1)]));
  ;}
    break;

  case 401:
#line 2571 "parser.y"
    {
    set_state(XHP_CHILD_START);
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 402:
#line 2575 "parser.y"
    {
    set_state(XHP_CHILD_START);
    (yyval) = (yyvsp[(1) - (3)])->appendChild((yyvsp[(2) - (3)]))->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 404:
#line 2583 "parser.y"
    {
    push_state(PHP);
    yyextra->pushStack();
  ;}
    break;

  case 405:
#line 2586 "parser.y"
    {
    pop_state();
    yyextra->popStack();
  ;}
    break;

  case 406:
#line 2589 "parser.y"
    {
    set_state(XHP_CHILD_START);
    (yyval) = NNEW(n_XHP_EXPRESSION);
    (yyval)->appendChild((yyvsp[(3) - (5)]));
    NEXPAND((yyvsp[(1) - (5)]), (yyval), (yyvsp[(4) - (5)]));
  ;}
    break;

  case 407:
#line 2599 "parser.y"
    {
    push_state(XHP_ATTRS);
    (yyval) = NNEW(n_XHP_ATTRIBUTE_LIST);
  ;}
    break;

  case 408:
#line 2603 "parser.y"
    {
    (yyval) = (yyvsp[(1) - (2)])->appendChild((yyvsp[(2) - (2)]));
  ;}
    break;

  case 409:
#line 2609 "parser.y"
    {
    (yyval) = NNEW(n_XHP_ATTRIBUTE);
    (yyval)->appendChild((yyvsp[(1) - (3)]));
    (yyval)->appendChild((yyvsp[(3) - (3)]));
  ;}
    break;

  case 410:
#line 2617 "parser.y"
    { push_state(XHP_ATTR_VAL); ;}
    break;

  case 411:
#line 2617 "parser.y"
    {
    (yyval) = NSPAN((yyvsp[(1) - (4)]), n_XHP_ATTRIBUTE_LITERAL, (yyvsp[(4) - (4)]));
    (yyval)->appendChild((yyvsp[(3) - (4)]));
  ;}
    break;

  case 412:
#line 2621 "parser.y"
    { push_state(PHP); ;}
    break;

  case 413:
#line 2621 "parser.y"
    { pop_state(); ;}
    break;

  case 414:
#line 2621 "parser.y"
    {
    (yyval) = NSPAN((yyvsp[(1) - (5)]), n_XHP_ATTRIBUTE_EXPRESSION, (yyvsp[(5) - (5)]));
    (yyval)->appendChild((yyvsp[(3) - (5)]));
  ;}
    break;

  case 415:
#line 2628 "parser.y"
    {
    (yyval) = NNEW(n_EMPTY);
  ;}
    break;

  case 416:
#line 2631 "parser.y"
    {
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_XHP_LITERAL);
  ;}
    break;

  case 417:
#line 2638 "parser.y"
    { push_state(XHP_LABEL); ;}
    break;

  case 418:
#line 2638 "parser.y"
    {
    pop_state();
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 419:
#line 2645 "parser.y"
    { push_state(XHP_LABEL); ;}
    break;

  case 420:
#line 2645 "parser.y"
    {
    pop_state();
    (yyval) = (yyvsp[(2) - (2)]);
  ;}
    break;

  case 421:
#line 2652 "parser.y"
    { push_state(XHP_LABEL_WHITESPACE); ;}
    break;

  case 422:
#line 2652 "parser.y"
    {
    pop_state();
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 423:
#line 2659 "parser.y"
    { push_state(XHP_LABEL); ;}
    break;

  case 424:
#line 2659 "parser.y"
    {
    pop_state();
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 425:
#line 2666 "parser.y"
    { push_state(XHP_LABEL_WHITESPACE); ;}
    break;

  case 426:
#line 2666 "parser.y"
    {
    pop_state();
    (yyval) = (yyvsp[(2) - (3)]);
  ;}
    break;

  case 427:
#line 2673 "parser.y"
    {
    // XHP_LABEL is popped in the scanner on " ", ">", "/", or "="
    push_state(XHP_LABEL);
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_XHP_LITERAL);
  ;}
    break;

  case 428:
#line 2678 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 429:
#line 2681 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 430:
#line 2687 "parser.y"
    {
    // XHP_LABEL is popped in the scanner on " ", ">", "/", or "="
    push_state(XHP_LABEL);
    (yyval) = NTYPE((yyvsp[(1) - (1)]), n_XHP_LITERAL);
  ;}
    break;

  case 431:
#line 2692 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 432:
#line 2695 "parser.y"
    {
    (yyval) = NMORE((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  ;}
    break;

  case 435:
#line 2707 "parser.y"
    {
    yyextra->expecting_xhp_class_statements = true;
    yyextra->used_attributes = false;
  ;}
    break;

  case 436:
#line 2710 "parser.y"
    {
    yyextra->expecting_xhp_class_statements = false;
  ;}
    break;

  case 437:
#line 2712 "parser.y"
    {
    (yyval) = NNEW(n_CLASS_DECLARATION);
    (yyval)->appendChild((yyvsp[(1) - (10)]));
    (yyval)->appendChild(NSPAN((yyvsp[(2) - (10)]), n_STRING, (yyvsp[(3) - (10)])));
    (yyval)->appendChild((yyvsp[(4) - (10)]));
    (yyval)->appendChild((yyvsp[(5) - (10)]));
    (yyval)->appendChild((yyvsp[(8) - (10)]));
    NMORE((yyval), (yyvsp[(10) - (10)]));

    (yyval) = NNEW(n_STATEMENT)->appendChild((yyval));


//!    $$ = $1 + " xhp_" + $3 + $4 + $5 + $6 + $8;
//!    if (yyextra->used_attributes) {
//!      $$ = $$ +
//!        "protected static function &__xhpAttributeDeclaration() {" +
//!          "static $_ = -1;" +
//!          "if ($_ === -1) {" +
//!            "$_ = array_merge(parent::__xhpAttributeDeclaration(), " +
//!              yyextra->attribute_inherit +
//!              "array(" + yyextra->attribute_decls + "));" +
//!          "}" +
//!          "return $_;"
//!        "}";
//!    }
//!    $$ = $$ + $10;
    yyextra->used = true;
  ;}
    break;

  case 438:
#line 2744 "parser.y"
    { push_state(XHP_ATTR_TYPE_DECL); ;}
    break;

  case 439:
#line 2744 "parser.y"
    {
    pop_state();
    yyextra->used = true;
    yyextra->used_attributes = true;
//!    $$ = ""; // this will be injected when the class closes
  ;}
    break;

  case 440:
#line 2753 "parser.y"
    {;}
    break;

  case 441:
#line 2754 "parser.y"
    {;}
    break;

  case 442:
#line 2758 "parser.y"
    {
//!    $2.strip_lines();
//!    yyextra->attribute_decls = yyextra->attribute_decls +
//!      "'" + $2 + "'=>array(" + $1 + "," + $3 + ", " + $4 + "),"
  ;}
    break;

  case 443:
#line 2763 "parser.y"
    {
//!    $2.strip_lines();
//!    yyextra->attribute_inherit = yyextra->attribute_inherit +
//!      "xhp_" + $2 + "::__xhpAttributeDeclaration(),";
  ;}
    break;

  case 444:
#line 2771 "parser.y"
    {
//!    $$ = "1, null";
  ;}
    break;

  case 445:
#line 2774 "parser.y"
    {
//!    $$ = "2, null";
  ;}
    break;

  case 446:
#line 2777 "parser.y"
    {
//!    $$ = "3, null";
  ;}
    break;

  case 447:
#line 2780 "parser.y"
    {
//!    $$ = "4, null";
  ;}
    break;

  case 448:
#line 2783 "parser.y"
    {
//!    $$ = "5, '" + $1 + "'";
  ;}
    break;

  case 449:
#line 2786 "parser.y"
    {
//!    $$ = "6, null";
  ;}
    break;

  case 450:
#line 2789 "parser.y"
    { push_state(PHP); ;}
    break;

  case 451:
#line 2789 "parser.y"
    { pop_state(); ;}
    break;

  case 452:
#line 2789 "parser.y"
    {
//!    $$ = "7, array(" + $4 + ")";
  ;}
    break;

  case 453:
#line 2792 "parser.y"
    {
//! ...
;}
    break;

  case 454:
#line 2798 "parser.y"
    {
//!    $1.strip_lines();
//!    $$ = $1;
  ;}
    break;

  case 455:
#line 2802 "parser.y"
    {
//!    $3.strip_lines();
//!    $$ = $1 + ", " + $3;
  ;}
    break;

  case 456:
#line 2809 "parser.y"
    {
//!    $2.strip_lines();
//!    $$ = $2;
  ;}
    break;

  case 457:
#line 2813 "parser.y"
    {
//!    $$ = "null";
  ;}
    break;

  case 458:
#line 2819 "parser.y"
    {
//!    $$ = "1";
  ;}
    break;

  case 459:
#line 2822 "parser.y"
    {
//!    $$ = "0";
  ;}
    break;

  case 460:
#line 2829 "parser.y"
    { push_state(PHP_NO_RESERVED_WORDS_PERSIST); ;}
    break;

  case 461:
#line 2829 "parser.y"
    {
    pop_state();
    yyextra->used = true;
//!    $$ =
//!      "protected function &__xhpCategoryDeclaration() { \  !!!
//!         static $_ = array(" + $3 + ");" +
//!        "return $_;" +
//!      "}";
  ;}
    break;

  case 462:
#line 2841 "parser.y"
    {
//!    $$ = "'" + $2 + "' => 1";
  ;}
    break;

  case 463:
#line 2844 "parser.y"
    {
//!    $$ = $1 + ",'" + $4 + "' => 1";
  ;}
    break;

  case 464:
#line 2851 "parser.y"
    { push_state(XHP_CHILDREN_DECL); ;}
    break;

  case 465:
#line 2851 "parser.y"
    {
    // XHP_CHILDREN_DECL is popped in the scanner on ';'
    yyextra->used = true;
//!    $$ = "protected function &__xhpChildrenDeclaration() {" + $3 + "}";
  ;}
    break;

  case 466:
#line 2859 "parser.y"
    {
//!    $$ = "static $_ = " + $1 + "; return $_;";
  ;}
    break;

  case 467:
#line 2862 "parser.y"
    {
//!    $$ = "static $_ = 1; return $_;";
  ;}
    break;

  case 468:
#line 2865 "parser.y"
    {
//!    $$ = "static $_ = 0; return $_;";
  ;}
    break;

  case 469:
#line 2871 "parser.y"
    {
//!    $$ = "array(0, 5, " + $2 + ")";
  ;}
    break;

  case 470:
#line 2874 "parser.y"
    {
//!    $$ = "array(1, 5, " + $2 + ")";
  ;}
    break;

  case 471:
#line 2877 "parser.y"
    {
//!    $$ = "array(2, 5, " + $2 + ")";
  ;}
    break;

  case 472:
#line 2880 "parser.y"
    {
//!    $$ = "array(3, 5, " + $2 + ")";
  ;}
    break;

  case 474:
#line 2887 "parser.y"
    {
//!    $$ = "array(0, " + $1 + ")";
  ;}
    break;

  case 475:
#line 2890 "parser.y"
    {
//!    $$ = "array(1, " + $1 + ")";
  ;}
    break;

  case 476:
#line 2893 "parser.y"
    {
//!    $$ = "array(2, " + $1 + ")";
  ;}
    break;

  case 477:
#line 2896 "parser.y"
    {
//!    $$ = "array(3, " + $1 + ")";
  ;}
    break;

  case 478:
#line 2899 "parser.y"
    {
//!    $$ = "array(4, " + $1 + "," + $3 + ")"
  ;}
    break;

  case 479:
#line 2902 "parser.y"
    {
//!    $$ = "array(5, " + $1 + "," + $3 + ")"
  ;}
    break;

  case 480:
#line 2908 "parser.y"
    {
//!    $$ = "1, null";
  ;}
    break;

  case 481:
#line 2911 "parser.y"
    {
//!    $$ = "2, null";
  ;}
    break;

  case 482:
#line 2914 "parser.y"
    {
//!    $$ = "3, \'xhp_" + $2 + "\'";
  ;}
    break;

  case 483:
#line 2917 "parser.y"
    {
//!    $$ = "4, \'" + $2 + "\'";
  ;}
    break;

  case 484:
#line 2924 "parser.y"
    {
    pop_state();
    push_state(PHP);
    yyextra->used = true;
    NTYPE((yyvsp[(1) - (2)]), n_CLASS_NAME);
    NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 485:
#line 2935 "parser.y"
    {
    pop_state();
    push_state(PHP);
    yyextra->used = true;
    NTYPE((yyvsp[(1) - (2)]), n_CLASS_NAME);
    NMORE((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
    (yyval) = (yyvsp[(1) - (2)]);
  ;}
    break;

  case 486:
#line 2951 "parser.y"
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
#line 7959 "parser.yacc.cpp"
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


#line 2963 "parser.y"


const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}

/* @generated */
