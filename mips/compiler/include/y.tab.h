/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BEG = 258,                     /* BEG  */
    END = 259,                     /* END  */
    T_INT = 260,                   /* T_INT  */
    T_BOOL = 261,                  /* T_BOOL  */
    READ = 262,                    /* READ  */
    WRITE = 263,                   /* WRITE  */
    DECL = 264,                    /* DECL  */
    ENDDECL = 265,                 /* ENDDECL  */
    IF = 266,                      /* IF  */
    THEN = 267,                    /* THEN  */
    ELSE = 268,                    /* ELSE  */
    ENDIF = 269,                   /* ENDIF  */
    LOGICAL_AND = 270,             /* LOGICAL_AND  */
    LOGICAL_NOT = 271,             /* LOGICAL_NOT  */
    LOGICAL_OR = 272,              /* LOGICAL_OR  */
    EQUALEQUAL = 273,              /* EQUALEQUAL  */
    LESSTHANOREQUAL = 274,         /* LESSTHANOREQUAL  */
    GREATERTHANOREQUAL = 275,      /* GREATERTHANOREQUAL  */
    NOTEQUAL = 276,                /* NOTEQUAL  */
    WHILE = 277,                   /* WHILE  */
    DO = 278,                      /* DO  */
    ENDWHILE = 279,                /* ENDWHILE  */
    FOR = 280,                     /* FOR  */
    T = 281,                       /* T  */
    F = 282,                       /* F  */
    MAIN = 283,                    /* MAIN  */
    RETURN = 284,                  /* RETURN  */
    BREAK = 285,                   /* BREAK  */
    CONTINUE = 286,                /* CONTINUE  */
    INCREMENT = 287,               /* INCREMENT  */
    NUM = 288,                     /* NUM  */
    VAR = 289                      /* VAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define BREAK 285
#define CONTINUE 286
#define INCREMENT 287
#define NUM 288
#define VAR 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "./src/compiler.y"

	int num;
	char* id;
	struct node* tree;

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
