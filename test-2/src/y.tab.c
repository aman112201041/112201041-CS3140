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
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 3 "./src/compiler.y"
	
	
	int yylex();
	void yyerror( char* );

	#include <bits/stdc++.h>
	#include <iostream>
	using namespace std;
	#include "../include/dataTypes.hpp"
	#include "../include/printTree2.hpp"
	#include "../include/executeTree.hpp"

	
	//string var_type = "NULL";
	enum _DATA_TYPES_ var_type;
	struct node* tempNode;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "./src/compiler.y"
{
	int num;
	char* id;
	struct node* tree;

	float fnum;
}
/* Line 193 of yacc.c.  */
#line 194 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
      48,    49,    38,    36,    45,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      34,    50,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    41,
      42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    14,    16,    19,    23,    25,
      27,    29,    31,    35,    37,    42,    50,    53,    54,    57,
      60,    63,    65,    68,    71,    76,    81,    85,    88,    89,
      95,   103,   115,   126,   136,   138,   140,   143,   145,   147,
     149,   153,   157,   161,   165,   169,   173,   177,   181,   185,
     189,   193,   196,   198,   203
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    56,    55,    -1,     3,    62,     4,    -1,
      10,    57,    11,    -1,    58,    -1,    58,    57,    -1,    59,
      60,    44,    -1,     5,    -1,     6,    -1,     7,    -1,    61,
      -1,    61,    45,    60,    -1,    42,    -1,    61,    46,    41,
      47,    -1,    61,    46,    41,    47,    46,    41,    47,    -1,
      63,    62,    -1,    -1,    66,    44,    -1,    64,    44,    -1,
      65,    44,    -1,    67,    -1,    31,    44,    -1,    32,    44,
      -1,     8,    48,    69,    49,    -1,     9,    48,    68,    49,
      -1,    69,    50,    68,    -1,    69,    33,    -1,    -1,    12,
      68,    13,    62,    15,    -1,    12,    68,    13,    62,    14,
      62,    15,    -1,    26,    48,    66,    44,    68,    44,    66,
      49,    51,    62,    52,    -1,    26,    48,    66,    44,    44,
      66,    49,    51,    62,    52,    -1,    24,    51,    62,    52,
      23,    48,    68,    49,    44,    -1,    41,    -1,    43,    -1,
      37,    68,    -1,    69,    -1,    27,    -1,    28,    -1,    48,
      68,    49,    -1,    68,    36,    68,    -1,    68,    37,    68,
      -1,    68,    38,    68,    -1,    68,    39,    68,    -1,    68,
      35,    68,    -1,    68,    34,    68,    -1,    68,    19,    68,
      -1,    68,    20,    68,    -1,    68,    21,    68,    -1,    68,
      22,    68,    -1,    69,    33,    -1,    42,    -1,    69,    46,
      68,    47,    -1,    69,    46,    68,    47,    46,    68,    47,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    79,    85,    92,    93,    96,   103,   104,
     105,   108,   109,   112,   115,   119,   126,   127,   130,   131,
     132,   133,   134,   135,   138,   141,   151,   155,   159,   162,
     170,   182,   193,   206,   219,   220,   221,   222,   223,   224,
     225,   227,   228,   229,   230,   232,   233,   234,   235,   236,
     237,   239,   245,   246,   250
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "END", "T_INT", "T_BOOL",
  "T_FLOAT", "READ", "WRITE", "DECL", "ENDDECL", "IF", "THEN", "ELSE",
  "ENDIF", "LOGICAL_AND", "LOGICAL_NOT", "LOGICAL_OR", "EQUALEQUAL",
  "LESSTHANOREQUAL", "GREATERTHANOREQUAL", "NOTEQUAL", "WHILE", "DO",
  "ENDWHILE", "FOR", "T", "F", "MAIN", "RETURN", "BREAK", "CONTINUE",
  "INCREMENT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "NUM",
  "VAR", "FLOAT_NUM", "';'", "','", "'['", "']'", "'('", "')'", "'='",
  "'{'", "'}'", "$accept", "START", "Statement_Sec", "Ldecl_sec",
  "Ldecl_list", "Ldecl", "type", "Lid_list", "Lid", "stmt_list",
  "statement", "read_stmt", "write_stmt", "assign_stmt", "cond_stmt",
  "expr", "var_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    60,    62,    43,    45,    42,    47,
      37,   289,   290,   291,    59,    44,    91,    93,    40,    41,
      61,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    56,    57,    57,    58,    59,    59,
      59,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    64,    65,    66,    66,    66,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     3,     1,     2,     3,     1,     1,
       1,     1,     3,     1,     4,     7,     2,     0,     2,     2,
       2,     1,     2,     2,     4,     4,     3,     2,     0,     5,
       7,    11,    10,     9,     1,     1,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     4,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     8,     9,    10,     0,     5,     0,
       1,    17,     2,     4,     6,    13,     0,    11,     0,     0,
       0,     0,     0,     0,     0,    52,     0,    17,     0,     0,
       0,    21,     0,     7,     0,     0,     0,     0,    38,    39,
       0,    34,    35,     0,     0,    37,    17,    28,    22,    23,
       3,    16,    19,    20,    18,    27,     0,     0,    12,     0,
       0,     0,    36,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,    26,
      14,    24,    25,    40,     0,    47,    48,    49,    50,    46,
      45,    41,    42,    43,    44,     0,     0,    53,     0,    17,
      29,     0,    28,     0,     0,     0,     0,     0,     0,    28,
       0,    15,    30,     0,     0,     0,    54,     0,    17,     0,
      33,     0,    17,    32,     0,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    12,     3,     7,     8,     9,    16,    17,    26,
      27,    28,    29,    30,    31,    44,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int16 yypact[] =
{
      -4,    49,    10,    14,   -46,   -46,   -46,    12,    49,     8,
     -46,    -5,   -46,   -46,   -46,   -46,    15,   -32,    21,    22,
     181,     7,    30,    16,    18,   -46,    59,    -5,    36,    37,
      39,   -46,   -22,   -46,     8,    48,    51,   181,   -46,   -46,
     181,   -46,   -46,   181,   162,   -24,    -5,    51,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   181,   181,   -46,    43,
     -41,    65,    -9,    96,    -5,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   -46,    42,    53,   127,   206,
      60,   -46,   -46,   -46,    19,    38,    38,    38,    38,   194,
     194,    -9,    -9,   -46,   -46,    72,    24,    62,    64,    -5,
     -46,    61,    51,   168,   181,    63,    97,   181,    70,    51,
     133,   -46,   -46,   102,    69,    76,   -46,    82,    -5,    77,
     -46,    75,    -5,   -46,    90,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -46,   105,   -46,   -46,    95,   -46,   -26,
     -46,   -46,   -46,   -45,   -46,   -25,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int8 yytable[] =
{
      32,    51,    77,    18,    19,    56,     1,    20,    81,    75,
      10,    55,    61,    34,    35,    62,    32,    11,    63,    21,
      76,    22,    56,    13,    56,    60,    23,    24,    57,    73,
      74,    78,    79,    99,   100,    32,    32,    25,    84,   -28,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      15,    38,    39,    32,     4,     5,     6,   108,    46,    33,
      48,    40,    49,    50,   115,    41,    25,    42,   102,    36,
      37,   103,    43,   106,    71,    72,    73,    74,    47,   110,
      52,    53,   113,    54,    65,    66,    67,    68,    32,    59,
      80,    32,   121,    25,    95,   101,   124,    96,    32,    69,
      70,    71,    72,    73,    74,   105,    98,    32,   104,   107,
     111,    32,   112,    14,    82,    65,    66,    67,    68,   114,
     118,    65,    66,    67,    68,   119,   120,   123,   122,    58,
      69,    70,    71,    72,    73,    74,    69,    70,    71,    72,
      73,    74,   125,     0,     0,    83,    65,    66,    67,    68,
       0,   117,    65,    66,    67,    68,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    69,    70,    71,
      72,    73,    74,     0,    97,    64,     0,     0,     0,     0,
     116,    65,    66,    67,    68,     0,     0,    65,    66,    67,
      68,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    69,    70,    71,    72,    73,    74,    38,    39,
       0,     0,   109,    65,    66,    67,    68,     0,    40,     0,
       0,     0,    41,    25,    42,    65,    66,    67,    68,    43,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,    74
};

static const yytype_int8 yycheck[] =
{
      11,    27,    47,     8,     9,    46,    10,    12,    49,    33,
       0,    33,    37,    45,    46,    40,    27,     3,    43,    24,
      46,    26,    46,    11,    46,    36,    31,    32,    50,    38,
      39,    56,    57,    14,    15,    46,    47,    42,    64,    44,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      42,    27,    28,    64,     5,     6,     7,   102,    51,    44,
      44,    37,    44,     4,   109,    41,    42,    43,    44,    48,
      48,    96,    48,    99,    36,    37,    38,    39,    48,   104,
      44,    44,   107,    44,    19,    20,    21,    22,    99,    41,
      47,   102,   118,    42,    52,    23,   122,    44,   109,    34,
      35,    36,    37,    38,    39,    41,    46,   118,    46,    48,
      47,   122,    15,     8,    49,    19,    20,    21,    22,    49,
      51,    19,    20,    21,    22,    49,    44,    52,    51,    34,
      34,    35,    36,    37,    38,    39,    34,    35,    36,    37,
      38,    39,    52,    -1,    -1,    49,    19,    20,    21,    22,
      -1,    49,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    34,    35,    36,
      37,    38,    39,    -1,    47,    13,    -1,    -1,    -1,    -1,
      47,    19,    20,    21,    22,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    34,    35,    36,    37,    38,    39,    27,    28,
      -1,    -1,    44,    19,    20,    21,    22,    -1,    37,    -1,
      -1,    -1,    41,    42,    43,    19,    20,    21,    22,    48,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    54,    56,     5,     6,     7,    57,    58,    59,
       0,     3,    55,    11,    57,    42,    60,    61,     8,     9,
      12,    24,    26,    31,    32,    42,    62,    63,    64,    65,
      66,    67,    69,    44,    45,    46,    48,    48,    27,    28,
      37,    41,    43,    48,    68,    69,    51,    48,    44,    44,
       4,    62,    44,    44,    44,    33,    46,    50,    60,    41,
      69,    68,    68,    68,    13,    19,    20,    21,    22,    34,
      35,    36,    37,    38,    39,    33,    62,    66,    68,    68,
      47,    49,    49,    49,    62,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    52,    44,    47,    46,    14,
      15,    23,    44,    68,    46,    41,    62,    48,    66,    44,
      68,    47,    15,    68,    49,    66,    47,    49,    51,    49,
      44,    62,    51,    52,    62,    52
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
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
#line 65 "./src/compiler.y"
    {
												node* codeTree = createTop();

												pushChildNode(codeTree, (yyvsp[(1) - (2)].tree));
												
												node* StmntList = (yyvsp[(2) - (2)].tree);
												pushChildNode(codeTree, StmntList);

												print_tree(codeTree);

												execute_tree(codeTree);
											}
    break;

  case 3:
#line 79 "./src/compiler.y"
    {
												node* StmntList = createStmntList();
												pushChildNode(StmntList, (yyvsp[(2) - (3)].tree));
												(yyval.tree) = StmntList;
											}
    break;

  case 4:
#line 85 "./src/compiler.y"
    {
												tempNode = createDecl();
												pushChildNode(tempNode, (yyvsp[(2) - (3)].tree));
												(yyval.tree) = tempNode;
											}
    break;

  case 5:
#line 92 "./src/compiler.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 6:
#line 93 "./src/compiler.y"
    {pushNextNode((yyvsp[(1) - (2)].tree), (yyvsp[(2) - (2)].tree)); (yyval.tree) = (yyvsp[(1) - (2)].tree); }
    break;

  case 7:
#line 96 "./src/compiler.y"
    { 
												(yyval.tree)=createLdecl_list();
												pushChildNode((yyval.tree), createKeyword("dataType", var_type));
												pushChildNode((yyval.tree), (yyvsp[(2) - (3)].tree));
											}
    break;

  case 8:
#line 103 "./src/compiler.y"
    { var_type = _INT_; }
    break;

  case 9:
#line 104 "./src/compiler.y"
    { var_type = _BOOLEAN_; }
    break;

  case 10:
#line 105 "./src/compiler.y"
    { var_type = _FLOAT_; }
    break;

  case 11:
#line 108 "./src/compiler.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 12:
#line 109 "./src/compiler.y"
    {pushNextNode((yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); (yyval.tree) = (yyvsp[(1) - (3)].tree);}
    break;

  case 13:
#line 112 "./src/compiler.y"
    { 
												(yyval.tree) = createVar((yyvsp[(1) - (1)].id));
											}
    break;

  case 14:
#line 115 "./src/compiler.y"
    {
												(yyval.tree) = (yyvsp[(1) - (4)].tree);
												pushChildNode((yyval.tree), createNum((yyvsp[(3) - (4)].num)));
											}
    break;

  case 15:
#line 119 "./src/compiler.y"
    {
												(yyval.tree) = (yyvsp[(1) - (7)].tree);
												pushChildNode((yyval.tree), createNum((yyvsp[(3) - (7)].num)));
												pushChildNode((yyval.tree), createNum((yyvsp[(6) - (7)].num)));
											}
    break;

  case 16:
#line 126 "./src/compiler.y"
    {(yyval.tree) = createStatement(); pushNextNode((yyval.tree), (yyvsp[(2) - (2)].tree)); pushChildNode((yyval.tree), (yyvsp[(1) - (2)].tree));}
    break;

  case 17:
#line 127 "./src/compiler.y"
    {(yyval.tree) = NULL;}
    break;

  case 18:
#line 130 "./src/compiler.y"
    { (yyval.tree) = (yyvsp[(1) - (2)].tree); }
    break;

  case 19:
#line 131 "./src/compiler.y"
    { }
    break;

  case 20:
#line 132 "./src/compiler.y"
    { (yyval.tree) = (yyvsp[(1) - (2)].tree); }
    break;

  case 21:
#line 133 "./src/compiler.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 22:
#line 134 "./src/compiler.y"
    { (yyval.tree) = createBreak(); }
    break;

  case 23:
#line 135 "./src/compiler.y"
    { (yyval.tree) = createContinue(); }
    break;

  case 24:
#line 138 "./src/compiler.y"
    {  }
    break;

  case 25:
#line 141 "./src/compiler.y"
    { 
															(yyval.tree)=createFunc("WRITE"); 
															// pushNextNode($$, $3);
															pushChildNode((yyval.tree), createFunctionArgument());
															pushChildNode((yyval.tree)->child, (yyvsp[(3) - (4)].tree));
														}
    break;

  case 26:
#line 151 "./src/compiler.y"
    { 
												//symbol_table[$1->name].second=evaluate($3); 
												(yyval.tree)=createAssign((yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree));
											}
    break;

  case 27:
#line 155 "./src/compiler.y"
    { 
												(yyval.tree)=createAssign((yyvsp[(1) - (2)].tree), createOp("+", createCopyNode((yyvsp[(1) - (2)].tree)), createNum(1))); 
												
											}
    break;

  case 28:
#line 159 "./src/compiler.y"
    { (yyval.tree)=createAssign(NULL, NULL); }
    break;

  case 29:
#line 162 "./src/compiler.y"
    { 
																										(yyval.tree) = createIfStmnt();
																										pushChildNode((yyval.tree), (yyvsp[(2) - (5)].tree));
																										
																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, (yyvsp[(4) - (5)].tree));
																										pushChildNode((yyval.tree), StmntList);
																									}
    break;

  case 30:
#line 170 "./src/compiler.y"
    { 
																										(yyval.tree) = createIfStmnt();
																										pushChildNode((yyval.tree), (yyvsp[(2) - (7)].tree));
																										
																										node* StmntList1 = createStmntList();
																										pushChildNode(StmntList1, (yyvsp[(4) - (7)].tree));
																										pushChildNode((yyval.tree), StmntList1);

																										node* StmntList2 = createStmntList();
																										pushChildNode(StmntList2, (yyvsp[(6) - (7)].tree));
																										pushChildNode((yyval.tree), StmntList2);
																									}
    break;

  case 31:
#line 182 "./src/compiler.y"
    { 
																										(yyval.tree) = createForStmnt();
																										pushChildNode((yyval.tree), (yyvsp[(3) - (11)].tree));
																										pushChildNode((yyval.tree), (yyvsp[(5) - (11)].tree));
																										pushChildNode((yyval.tree), (yyvsp[(7) - (11)].tree));

																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, (yyvsp[(10) - (11)].tree));

																										pushChildNode((yyval.tree), StmntList);
																									}
    break;

  case 32:
#line 193 "./src/compiler.y"
    { 
																										(yyval.tree) = createForStmnt();
																										pushChildNode((yyval.tree), (yyvsp[(3) - (10)].tree));
																										
																										pushChildNode((yyval.tree), createNum(1)); //for the empty expr. assuming true.

																										pushChildNode((yyval.tree), (yyvsp[(6) - (10)].tree));

																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, (yyvsp[(9) - (10)].tree));

																										pushChildNode((yyval.tree), StmntList);
																									}
    break;

  case 33:
#line 206 "./src/compiler.y"
    { 
																										(yyval.tree) = createWhileStmnt();
																										
																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, (yyvsp[(3) - (9)].tree));

																										pushChildNode((yyval.tree), StmntList);

																										pushChildNode((yyval.tree), (yyvsp[(7) - (9)].tree));
																									}
    break;

  case 34:
#line 219 "./src/compiler.y"
    { (yyval.tree) = createNum((yyvsp[(1) - (1)].num)); }
    break;

  case 35:
#line 220 "./src/compiler.y"
    { (yyval.tree) = createFloat((yyvsp[(1) - (1)].fnum)); }
    break;

  case 36:
#line 221 "./src/compiler.y"
    {  (yyval.tree) = createOp("-", (yyvsp[(2) - (2)].tree), NULL); }
    break;

  case 37:
#line 222 "./src/compiler.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 38:
#line 223 "./src/compiler.y"
    { (yyval.tree) = createNum(1); }
    break;

  case 39:
#line 224 "./src/compiler.y"
    { (yyval.tree) = createNum(0); }
    break;

  case 40:
#line 225 "./src/compiler.y"
    { (yyval.tree) = (yyvsp[(2) - (3)].tree); }
    break;

  case 41:
#line 227 "./src/compiler.y"
    { (yyval.tree) = createOp("+", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 42:
#line 228 "./src/compiler.y"
    { (yyval.tree) = createOp("-", (yyvsp[(3) - (3)].tree), (yyvsp[(1) - (3)].tree)); }
    break;

  case 43:
#line 229 "./src/compiler.y"
    { (yyval.tree) = createOp("*", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 44:
#line 230 "./src/compiler.y"
    { (yyval.tree) = createOp("/", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 45:
#line 232 "./src/compiler.y"
    { (yyval.tree) = createOp(">", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 46:
#line 233 "./src/compiler.y"
    { (yyval.tree) = createOp("<", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 47:
#line 234 "./src/compiler.y"
    { (yyval.tree) = createOp("==", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 48:
#line 235 "./src/compiler.y"
    { (yyval.tree) = createOp("<=", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 49:
#line 236 "./src/compiler.y"
    { (yyval.tree) = createOp(">=", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 50:
#line 237 "./src/compiler.y"
    { (yyval.tree) = createOp("!=", (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 51:
#line 239 "./src/compiler.y"
    { (yyval.tree) = createOp("++", (yyvsp[(1) - (2)].tree), NULL); }
    break;

  case 52:
#line 245 "./src/compiler.y"
    { (yyval.tree) = createVar((yyvsp[(1) - (1)].id)); }
    break;

  case 53:
#line 246 "./src/compiler.y"
    {
														(yyval.tree) = (yyvsp[(1) - (4)].tree);
														pushChildNode((yyval.tree), (yyvsp[(3) - (4)].tree));
													}
    break;

  case 54:
#line 250 "./src/compiler.y"
    {
														(yyval.tree) = (yyvsp[(1) - (7)].tree);
														pushChildNode((yyval.tree), (yyvsp[(3) - (7)].tree));
														pushChildNode((yyval.tree), (yyvsp[(6) - (7)].tree));
													}
    break;


/* Line 1267 of yacc.c.  */
#line 1895 "y.tab.c"
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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
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
		      yytoken, &yylval);
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
		  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 258 "./src/compiler.y"

void yyerror ( char  *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(){
	return yyparse();
}

