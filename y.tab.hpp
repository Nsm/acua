
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER = 259,
     SUM = 260,
     SUBSTRACTION = 261,
     MULTIPLICATION = 262,
     DIVISION = 263,
     AUTOSUM = 264,
     AUTOSUBSTRACTION = 265,
     AUTOMULTIPLICATION = 266,
     AUTODIVISION = 267,
     ASIGNATION = 268,
     NEGATION = 269,
     AND = 270,
     OR = 271,
     STRING = 272,
     SEMICOLON = 273,
     COMMA = 274,
     SEPARATOR = 275,
     LOWER = 276,
     UPPER = 277,
     BRACKET = 278,
     RIGHTBRACKET = 279,
     BRACE = 280,
     RIGHTBRACE = 281,
     EQUAL = 282,
     EQUALLOWER = 283,
     EQUALUPPER = 284,
     NOTEQUAL = 285,
     COMMENT = 286,
     IF = 287,
     ELSE = 288,
     WHILE = 289,
     DEFINE = 290,
     DISPLAY = 291,
     TYPEFLOAT = 292,
     TYPESTRING = 293,
     REPEAT = 294,
     UNTIL = 295
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER 259
#define SUM 260
#define SUBSTRACTION 261
#define MULTIPLICATION 262
#define DIVISION 263
#define AUTOSUM 264
#define AUTOSUBSTRACTION 265
#define AUTOMULTIPLICATION 266
#define AUTODIVISION 267
#define ASIGNATION 268
#define NEGATION 269
#define AND 270
#define OR 271
#define STRING 272
#define SEMICOLON 273
#define COMMA 274
#define SEPARATOR 275
#define LOWER 276
#define UPPER 277
#define BRACKET 278
#define RIGHTBRACKET 279
#define BRACE 280
#define RIGHTBRACE 281
#define EQUAL 282
#define EQUALLOWER 283
#define EQUALUPPER 284
#define NOTEQUAL 285
#define COMMENT 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define DEFINE 290
#define DISPLAY 291
#define TYPEFLOAT 292
#define TYPESTRING 293
#define REPEAT 294
#define UNTIL 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


