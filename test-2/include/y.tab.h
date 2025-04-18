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
     T_FLOAT = 262,
     READ = 263,
     WRITE = 264,
     DECL = 265,
     ENDDECL = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     ENDIF = 270,
     LOGICAL_AND = 271,
     LOGICAL_NOT = 272,
     LOGICAL_OR = 273,
     EQUALEQUAL = 274,
     LESSTHANOREQUAL = 275,
     GREATERTHANOREQUAL = 276,
     NOTEQUAL = 277,
     WHILE = 278,
     DO = 279,
     ENDWHILE = 280,
     FOR = 281,
     T = 282,
     F = 283,
     MAIN = 284,
     RETURN = 285,
     BREAK = 286,
     CONTINUE = 287,
     INCREMENT = 288,
     NUM = 289,
     VAR = 290,
     FLOAT_NUM = 291
   };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define T_FLOAT 262
#define READ 263
#define WRITE 264
#define DECL 265
#define ENDDECL 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define LOGICAL_AND 271
#define LOGICAL_NOT 272
#define LOGICAL_OR 273
#define EQUALEQUAL 274
#define LESSTHANOREQUAL 275
#define GREATERTHANOREQUAL 276
#define NOTEQUAL 277
#define WHILE 278
#define DO 279
#define ENDWHILE 280
#define FOR 281
#define T 282
#define F 283
#define MAIN 284
#define RETURN 285
#define BREAK 286
#define CONTINUE 287
#define INCREMENT 288
#define NUM 289
#define VAR 290
#define FLOAT_NUM 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "./src/compiler.y"
{
	int num;
	char* id;
	struct node* tree;

	float fnum;
}
/* Line 1529 of yacc.c.  */
#line 129 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

