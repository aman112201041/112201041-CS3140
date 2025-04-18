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
     BEG = 258,
     END = 259,
     T_INT = 260,
     T_BOOL = 261,
     READ = 262,
     WRITE = 263,
     DECL = 264,
     ENDDECL = 265,
     IF = 266,
     THEN = 267,
     ELSE = 268,
     ENDIF = 269,
     LOGICAL_AND = 270,
     LOGICAL_NOT = 271,
     LOGICAL_OR = 272,
     EQUALEQUAL = 273,
     LESSTHANOREQUAL = 274,
     GREATERTHANOREQUAL = 275,
     NOTEQUAL = 276,
     WHILE = 277,
     DO = 278,
     ENDWHILE = 279,
     FOR = 280,
     T = 281,
     F = 282,
     MAIN = 283,
     RETURN = 284,
     NUM = 285,
     VAR = 286
   };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define READ 262
#define WRITE 263
#define DECL 264
#define ENDDECL 265
#define IF 266
#define THEN 267
#define ELSE 268
#define ENDIF 269
#define LOGICAL_AND 270
#define LOGICAL_NOT 271
#define LOGICAL_OR 272
#define EQUALEQUAL 273
#define LESSTHANOREQUAL 274
#define GREATERTHANOREQUAL 275
#define NOTEQUAL 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define FOR 280
#define T 281
#define F 282
#define MAIN 283
#define RETURN 284
#define NUM 285
#define VAR 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "./src/compiler.y"
{
	int num;
	char* id;
	struct node* tree;
}
/* Line 1529 of yacc.c.  */
#line 117 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

