/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* @generated */
