/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
/* @generated */
