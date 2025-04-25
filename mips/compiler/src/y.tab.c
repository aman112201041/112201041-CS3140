/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "./src/compiler.y"
	
	
	int yylex();
	void yyerror( char* );

	#include <bits/stdc++.h>
	#include <iostream>

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	using namespace std;
	#include "../include/dataTypes.hpp"
	#include "../include/printTree2.hpp"
	#include "../include/executeTree.hpp"

	#include "../include/code_to_mips.hpp"

	
	//string var_type = "NULL";
	enum _DATA_TYPES_ var_type;
	struct node* tempNode;

#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 223 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BEG = 3,                        /* BEG  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_T_INT = 5,                      /* T_INT  */
  YYSYMBOL_T_BOOL = 6,                     /* T_BOOL  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_DECL = 9,                       /* DECL  */
  YYSYMBOL_ENDDECL = 10,                   /* ENDDECL  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_ENDIF = 14,                     /* ENDIF  */
  YYSYMBOL_LOGICAL_AND = 15,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_NOT = 16,               /* LOGICAL_NOT  */
  YYSYMBOL_LOGICAL_OR = 17,                /* LOGICAL_OR  */
  YYSYMBOL_EQUALEQUAL = 18,                /* EQUALEQUAL  */
  YYSYMBOL_LESSTHANOREQUAL = 19,           /* LESSTHANOREQUAL  */
  YYSYMBOL_GREATERTHANOREQUAL = 20,        /* GREATERTHANOREQUAL  */
  YYSYMBOL_NOTEQUAL = 21,                  /* NOTEQUAL  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_ENDWHILE = 24,                  /* ENDWHILE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_T = 26,                         /* T  */
  YYSYMBOL_F = 27,                         /* F  */
  YYSYMBOL_MAIN = 28,                      /* MAIN  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 31,                  /* CONTINUE  */
  YYSYMBOL_INCREMENT = 32,                 /* INCREMENT  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_NUM = 40,                       /* NUM  */
  YYSYMBOL_VAR = 41,                       /* VAR  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_START = 52,                     /* START  */
  YYSYMBOL_Statement_Sec = 53,             /* Statement_Sec  */
  YYSYMBOL_Ldecl_sec = 54,                 /* Ldecl_sec  */
  YYSYMBOL_Ldecl_list = 55,                /* Ldecl_list  */
  YYSYMBOL_Ldecl = 56,                     /* Ldecl  */
  YYSYMBOL_type = 57,                      /* type  */
  YYSYMBOL_Lid_list = 58,                  /* Lid_list  */
  YYSYMBOL_Lid = 59,                       /* Lid  */
  YYSYMBOL_stmt_list = 60,                 /* stmt_list  */
  YYSYMBOL_statement = 61,                 /* statement  */
  YYSYMBOL_read_stmt = 62,                 /* read_stmt  */
  YYSYMBOL_write_stmt = 63,                /* write_stmt  */
  YYSYMBOL_assign_stmt = 64,               /* assign_stmt  */
  YYSYMBOL_cond_stmt = 65,                 /* cond_stmt  */
  YYSYMBOL_expr_list = 66,                 /* expr_list  */
  YYSYMBOL_var_expr_list = 67,             /* var_expr_list  */
  YYSYMBOL_expr = 68,                      /* expr  */
  YYSYMBOL_var_expr = 69                   /* var_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      46,    47,    37,    35,    43,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      33,    48,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    88,    94,   101,   102,   105,   112,   113,
     116,   117,   120,   123,   129,   130,   133,   134,   135,   136,
     137,   138,   154,   161,   168,   172,   176,   179,   187,   199,
     210,   225,   226,   229,   230,   233,   234,   235,   236,   237,
     238,   240,   241,   242,   243,   245,   246,   247,   248,   249,
     250,   252,   258,   259
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BEG", "END", "T_INT",
  "T_BOOL", "READ", "WRITE", "DECL", "ENDDECL", "IF", "THEN", "ELSE",
  "ENDIF", "LOGICAL_AND", "LOGICAL_NOT", "LOGICAL_OR", "EQUALEQUAL",
  "LESSTHANOREQUAL", "GREATERTHANOREQUAL", "NOTEQUAL", "WHILE", "DO",
  "ENDWHILE", "FOR", "T", "F", "MAIN", "RETURN", "BREAK", "CONTINUE",
  "INCREMENT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "NUM",
  "VAR", "';'", "','", "'['", "']'", "'('", "')'", "'='", "'{'", "'}'",
  "$accept", "START", "Statement_Sec", "Ldecl_sec", "Ldecl_list", "Ldecl",
  "type", "Lid_list", "Lid", "stmt_list", "statement", "read_stmt",
  "write_stmt", "assign_stmt", "cond_stmt", "expr_list", "var_expr_list",
  "expr", "var_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-27)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,     6,    27,    29,   -37,   -37,    20,     6,     8,   -37,
      -5,   -37,   -37,   -37,   -37,     9,   -30,     7,    19,   -18,
      24,    30,    31,   -37,    46,    -5,    33,    35,    36,   -37,
     -27,   -37,     8,    39,    42,   -18,   -37,   -37,   -18,   -37,
     -18,   118,   -28,    42,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -18,   -18,   -37,    26,    44,     2,    45,   124,
      -3,    84,    -5,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -37,    47,    90,   155,   -37,   -37,    42,
     -37,   -18,   -37,    34,     4,     4,     4,     4,   176,   176,
      -3,    -3,   -37,   -37,    40,   -37,   -37,   -37,    -5,   -37,
      42,   145,    79,    48,    42,   -37,    50,    49,    -5,    51,
      56,    -5,   -37,    57,   -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     8,     9,     0,     5,     0,     1,
      15,     2,     4,     6,    12,     0,    10,     0,     0,     0,
       0,     0,     0,    52,     0,    15,     0,     0,     0,    19,
       0,     7,     0,     0,     0,     0,    38,    39,     0,    35,
       0,     0,    37,    26,    20,    21,     3,    14,    17,    18,
      16,    25,     0,     0,    11,     0,     0,    33,     0,    31,
      36,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    24,    13,    22,     0,
      23,     0,    40,     0,    47,    48,    49,    50,    46,    45,
      41,    42,    43,    44,     0,    53,    34,    32,    15,    27,
      26,     0,     0,     0,    26,    28,     0,     0,    15,     0,
       0,    15,    30,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,   -37,   105,   -37,   -37,    65,   -37,   -24,
     -37,   -37,   -37,   -36,   -37,    32,    37,    -9,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    11,     3,     6,     7,     8,    15,    16,    24,
      25,    26,    27,    28,    29,    58,    56,    59,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    47,    17,    18,    73,    51,    19,    74,    36,    37,
      41,     4,     5,    32,    33,    30,    52,    52,    38,     1,
      20,    53,    39,    23,    57,    21,    22,     9,    40,    60,
      12,    61,    10,    30,    71,    72,    23,   -26,    83,    69,
      70,    71,    72,    75,    76,    79,    52,    98,    99,    14,
      46,    31,    30,    34,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   103,    35,    36,    37,   107,    57,
      43,    77,    44,    45,   102,    48,    38,    49,    50,    55,
      39,    23,   100,    23,   110,   101,    40,   113,    30,    94,
      30,    78,    80,   105,    30,   106,   109,    54,    30,   108,
     111,    30,    63,    64,    65,    66,   112,   114,    63,    64,
      65,    66,    13,    97,     0,     0,    96,    67,    68,    69,
      70,    71,    72,    67,    68,    69,    70,    71,    72,     0,
      62,    82,     0,     0,     0,    95,    63,    64,    65,    66,
       0,     0,    63,    64,    65,    66,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,    72,    67,    68,    69,
      70,    71,    72,    63,    64,    65,    66,    81,     0,     0,
       0,     0,     0,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,     0,     0,     0,   104,    67,    68,
      69,    70,    71,    72,    63,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72
};

static const yytype_int8 yycheck[] =
{
      10,    25,     7,     8,    32,    32,    11,    43,    26,    27,
      19,     5,     6,    43,    44,    25,    44,    44,    36,     9,
      25,    48,    40,    41,    34,    30,    31,     0,    46,    38,
      10,    40,     3,    43,    37,    38,    41,    42,    62,    35,
      36,    37,    38,    52,    53,    43,    44,    13,    14,    41,
       4,    42,    62,    46,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   100,    46,    26,    27,   104,    79,
      46,    45,    42,    42,    98,    42,    36,    42,    42,    40,
      40,    41,    42,    41,   108,    94,    46,   111,    98,    42,
     100,    47,    47,    14,   104,    47,    47,    32,   108,    49,
      49,   111,    18,    19,    20,    21,    50,    50,    18,    19,
      20,    21,     7,    81,    -1,    -1,    79,    33,    34,    35,
      36,    37,    38,    33,    34,    35,    36,    37,    38,    -1,
      12,    47,    -1,    -1,    -1,    45,    18,    19,    20,    21,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    33,    34,    35,
      36,    37,    38,    18,    19,    20,    21,    43,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    -1,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    33,    34,
      35,    36,    37,    38,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    52,    54,     5,     6,    55,    56,    57,     0,
       3,    53,    10,    55,    41,    58,    59,     7,     8,    11,
      25,    30,    31,    41,    60,    61,    62,    63,    64,    65,
      69,    42,    43,    44,    46,    46,    26,    27,    36,    40,
      46,    68,    69,    46,    42,    42,     4,    60,    42,    42,
      42,    32,    44,    48,    58,    40,    67,    69,    66,    68,
      68,    68,    12,    18,    19,    20,    21,    33,    34,    35,
      36,    37,    38,    32,    64,    68,    68,    45,    47,    43,
      47,    43,    47,    60,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    42,    45,    67,    66,    13,    14,
      42,    68,    60,    64,    42,    14,    47,    64,    49,    47,
      60,    49,    50,    60,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    55,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    63,    64,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     1,     2,     3,     1,     1,
       1,     3,     1,     4,     2,     0,     2,     2,     2,     1,
       2,     2,     4,     4,     3,     2,     0,     5,     7,    11,
      10,     1,     3,     1,     3,     1,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* START: Ldecl_sec Statement_Sec  */
#line 70 "./src/compiler.y"
                                                                {
												node* codeTree = createTop();

												pushChildNode(codeTree, (yyvsp[-1].tree));
												
												node* StmntList = (yyvsp[0].tree);
												pushChildNode(codeTree, StmntList);

												//print_tree(codeTree);

												compile_tree(codeTree);

												// execute_tree(codeTree);

												// print_symbol_table();
											}
#line 1376 "y.tab.c"
    break;

  case 3: /* Statement_Sec: BEG stmt_list END  */
#line 88 "./src/compiler.y"
                                                        {
												node* StmntList = createStmntList();
												pushChildNode(StmntList, (yyvsp[-1].tree));
												(yyval.tree) = StmntList;
											}
#line 1386 "y.tab.c"
    break;

  case 4: /* Ldecl_sec: DECL Ldecl_list ENDDECL  */
#line 94 "./src/compiler.y"
                                                        {
												tempNode = createDecl();
												pushChildNode(tempNode, (yyvsp[-1].tree));
												(yyval.tree) = tempNode;
											}
#line 1396 "y.tab.c"
    break;

  case 5: /* Ldecl_list: Ldecl  */
#line 101 "./src/compiler.y"
                                                                        {(yyval.tree) = (yyvsp[0].tree);}
#line 1402 "y.tab.c"
    break;

  case 6: /* Ldecl_list: Ldecl Ldecl_list  */
#line 102 "./src/compiler.y"
                                                                        {pushNextNode((yyvsp[-1].tree), (yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree); }
#line 1408 "y.tab.c"
    break;

  case 7: /* Ldecl: type Lid_list ';'  */
#line 105 "./src/compiler.y"
                                                                { 
												(yyval.tree)=createLdecl_list();
												pushChildNode((yyval.tree), createKeyword("dataType", var_type));
												pushChildNode((yyval.tree), (yyvsp[-1].tree));
											}
#line 1418 "y.tab.c"
    break;

  case 8: /* type: T_INT  */
#line 112 "./src/compiler.y"
                                                                        { var_type = _INT_; }
#line 1424 "y.tab.c"
    break;

  case 9: /* type: T_BOOL  */
#line 113 "./src/compiler.y"
                                                                                { var_type = _BOOLEAN_; }
#line 1430 "y.tab.c"
    break;

  case 10: /* Lid_list: Lid  */
#line 116 "./src/compiler.y"
                                                                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1436 "y.tab.c"
    break;

  case 11: /* Lid_list: Lid ',' Lid_list  */
#line 117 "./src/compiler.y"
                                                                        {pushNextNode((yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);}
#line 1442 "y.tab.c"
    break;

  case 12: /* Lid: VAR  */
#line 120 "./src/compiler.y"
                                                                                        { 
												(yyval.tree) = createVar((yyvsp[0].id));
											}
#line 1450 "y.tab.c"
    break;

  case 13: /* Lid: Lid '[' NUM ']'  */
#line 123 "./src/compiler.y"
                                                                        {
												(yyval.tree) = (yyvsp[-3].tree);
												pushChildNode((yyval.tree), createNum((yyvsp[-1].num)));
											}
#line 1459 "y.tab.c"
    break;

  case 14: /* stmt_list: statement stmt_list  */
#line 129 "./src/compiler.y"
                                                                        {(yyval.tree) = createStatement(); pushNextNode((yyval.tree), (yyvsp[0].tree)); pushChildNode((yyval.tree), (yyvsp[-1].tree));}
#line 1465 "y.tab.c"
    break;

  case 15: /* stmt_list: %empty  */
#line 130 "./src/compiler.y"
                                                                                        {(yyval.tree) = NULL;}
#line 1471 "y.tab.c"
    break;

  case 16: /* statement: assign_stmt ';'  */
#line 133 "./src/compiler.y"
                                                                        { (yyval.tree) = (yyvsp[-1].tree); }
#line 1477 "y.tab.c"
    break;

  case 17: /* statement: read_stmt ';'  */
#line 134 "./src/compiler.y"
                                                                                { }
#line 1483 "y.tab.c"
    break;

  case 18: /* statement: write_stmt ';'  */
#line 135 "./src/compiler.y"
                                                                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 1489 "y.tab.c"
    break;

  case 19: /* statement: cond_stmt  */
#line 136 "./src/compiler.y"
                                                                                        { (yyval.tree) = (yyvsp[0].tree); }
#line 1495 "y.tab.c"
    break;

  case 20: /* statement: BREAK ';'  */
#line 137 "./src/compiler.y"
                                                                                        { (yyval.tree) = createBreak(); }
#line 1501 "y.tab.c"
    break;

  case 21: /* statement: CONTINUE ';'  */
#line 138 "./src/compiler.y"
                                                                                { (yyval.tree) = createContinue(); }
#line 1507 "y.tab.c"
    break;

  case 22: /* read_stmt: READ '(' var_expr_list ')'  */
#line 154 "./src/compiler.y"
                                                                                        { 
																(yyval.tree)=createFunc("READ");
																pushChildNode((yyval.tree), createFunctionArgument());
																pushChildNode((yyval.tree)->child, (yyvsp[-1].tree));
															}
#line 1517 "y.tab.c"
    break;

  case 23: /* write_stmt: WRITE '(' expr_list ')'  */
#line 161 "./src/compiler.y"
                                                                                { 
															(yyval.tree)=createFunc("WRITE");
															pushChildNode((yyval.tree), createFunctionArgument());
															pushChildNode((yyval.tree)->child, (yyvsp[-1].tree));
														}
#line 1527 "y.tab.c"
    break;

  case 24: /* assign_stmt: var_expr '=' expr  */
#line 168 "./src/compiler.y"
                                                        { 
												//symbol_table[$1->name].second=evaluate($3); 
												(yyval.tree)=createAssign((yyvsp[-2].tree), (yyvsp[0].tree));
											}
#line 1536 "y.tab.c"
    break;

  case 25: /* assign_stmt: var_expr INCREMENT  */
#line 172 "./src/compiler.y"
                                                                        { 
												(yyval.tree)=createAssign((yyvsp[-1].tree), createOp("+", createCopyNode((yyvsp[-1].tree)), createNum(1))); 
												
											}
#line 1545 "y.tab.c"
    break;

  case 26: /* assign_stmt: %empty  */
#line 176 "./src/compiler.y"
                                                                                { (yyval.tree)=createAssign(NULL, NULL); }
#line 1551 "y.tab.c"
    break;

  case 27: /* cond_stmt: IF expr THEN stmt_list ENDIF  */
#line 179 "./src/compiler.y"
                                                                                                                                                                { 
																										(yyval.tree) = createIfStmnt();
																										pushChildNode((yyval.tree), (yyvsp[-3].tree));
																										
																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, (yyvsp[-1].tree));
																										pushChildNode((yyval.tree), StmntList);
																									}
#line 1564 "y.tab.c"
    break;

  case 28: /* cond_stmt: IF expr THEN stmt_list ELSE stmt_list ENDIF  */
#line 187 "./src/compiler.y"
                                                                                                                                                        { 
																										(yyval.tree) = createIfStmnt();
																										pushChildNode((yyval.tree), (yyvsp[-5].tree));
																										
																										node* StmntList1 = createStmntList();
																										pushChildNode(StmntList1, (yyvsp[-3].tree));
																										pushChildNode((yyval.tree), StmntList1);

																										node* StmntList2 = createStmntList();
																										pushChildNode(StmntList2, (yyvsp[-1].tree));
																										pushChildNode((yyval.tree), StmntList2);
																									}
#line 1581 "y.tab.c"
    break;

  case 29: /* cond_stmt: FOR '(' assign_stmt ';' expr ';' assign_stmt ')' '{' stmt_list '}'  */
#line 199 "./src/compiler.y"
                                                                                                                    { 
																										(yyval.tree) = createForStmnt();
																										pushChildNode((yyval.tree), (yyvsp[-8].tree));
																										pushChildNode((yyval.tree), (yyvsp[-6].tree));
																										pushChildNode((yyval.tree), (yyvsp[-4].tree));

																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, (yyvsp[-1].tree));

																										pushChildNode((yyval.tree), StmntList);
																									}
#line 1597 "y.tab.c"
    break;

  case 30: /* cond_stmt: FOR '(' assign_stmt ';' ';' assign_stmt ')' '{' stmt_list '}'  */
#line 210 "./src/compiler.y"
                                                                                                                                { 
																										(yyval.tree) = createForStmnt();
																										pushChildNode((yyval.tree), (yyvsp[-7].tree));
																										
																										pushChildNode((yyval.tree), createNum(1)); //for the empty expr. assuming true.

																										pushChildNode((yyval.tree), (yyvsp[-4].tree));

																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, (yyvsp[-1].tree));

																										pushChildNode((yyval.tree), StmntList);
																									}
#line 1615 "y.tab.c"
    break;

  case 31: /* expr_list: expr  */
#line 225 "./src/compiler.y"
                                                                        {(yyval.tree) = (yyvsp[0].tree);}
#line 1621 "y.tab.c"
    break;

  case 32: /* expr_list: expr ',' expr_list  */
#line 226 "./src/compiler.y"
                                                                        {pushNextNode((yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);}
#line 1627 "y.tab.c"
    break;

  case 33: /* var_expr_list: var_expr  */
#line 229 "./src/compiler.y"
                                                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1633 "y.tab.c"
    break;

  case 34: /* var_expr_list: var_expr ',' var_expr_list  */
#line 230 "./src/compiler.y"
                                                                        {pushNextNode((yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);}
#line 1639 "y.tab.c"
    break;

  case 35: /* expr: NUM  */
#line 233 "./src/compiler.y"
                                                                        { (yyval.tree) = createNum((yyvsp[0].num)); }
#line 1645 "y.tab.c"
    break;

  case 36: /* expr: '-' expr  */
#line 234 "./src/compiler.y"
                                                                                {  (yyval.tree) = createOp("-", (yyvsp[0].tree), NULL); }
#line 1651 "y.tab.c"
    break;

  case 37: /* expr: var_expr  */
#line 235 "./src/compiler.y"
                                                                                { (yyval.tree) = (yyvsp[0].tree); }
#line 1657 "y.tab.c"
    break;

  case 38: /* expr: T  */
#line 236 "./src/compiler.y"
                                                                                        { (yyval.tree) = createNum(1); }
#line 1663 "y.tab.c"
    break;

  case 39: /* expr: F  */
#line 237 "./src/compiler.y"
                                                                                        { (yyval.tree) = createNum(0); }
#line 1669 "y.tab.c"
    break;

  case 40: /* expr: '(' expr ')'  */
#line 238 "./src/compiler.y"
                                                                        { (yyval.tree) = (yyvsp[-1].tree); }
#line 1675 "y.tab.c"
    break;

  case 41: /* expr: expr '+' expr  */
#line 240 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp("+", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1681 "y.tab.c"
    break;

  case 42: /* expr: expr '-' expr  */
#line 241 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp("-", (yyvsp[0].tree), (yyvsp[-2].tree)); }
#line 1687 "y.tab.c"
    break;

  case 43: /* expr: expr '*' expr  */
#line 242 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp("*", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1693 "y.tab.c"
    break;

  case 44: /* expr: expr '/' expr  */
#line 243 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp("/", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1699 "y.tab.c"
    break;

  case 45: /* expr: expr '>' expr  */
#line 245 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp(">", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1705 "y.tab.c"
    break;

  case 46: /* expr: expr '<' expr  */
#line 246 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp("<", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1711 "y.tab.c"
    break;

  case 47: /* expr: expr EQUALEQUAL expr  */
#line 247 "./src/compiler.y"
                                                                { (yyval.tree) = createOp("==", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1717 "y.tab.c"
    break;

  case 48: /* expr: expr LESSTHANOREQUAL expr  */
#line 248 "./src/compiler.y"
                                                                { (yyval.tree) = createOp("<=", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1723 "y.tab.c"
    break;

  case 49: /* expr: expr GREATERTHANOREQUAL expr  */
#line 249 "./src/compiler.y"
                                                        { (yyval.tree) = createOp(">=", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1729 "y.tab.c"
    break;

  case 50: /* expr: expr NOTEQUAL expr  */
#line 250 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp("!=", (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1735 "y.tab.c"
    break;

  case 51: /* expr: var_expr INCREMENT  */
#line 252 "./src/compiler.y"
                                                                        { (yyval.tree) = createOp("++", (yyvsp[-1].tree), NULL); }
#line 1741 "y.tab.c"
    break;

  case 52: /* var_expr: VAR  */
#line 258 "./src/compiler.y"
                                                                                { (yyval.tree) = createVar((yyvsp[0].id)); }
#line 1747 "y.tab.c"
    break;

  case 53: /* var_expr: var_expr '[' expr ']'  */
#line 259 "./src/compiler.y"
                                                                {
												(yyval.tree) = (yyvsp[-3].tree);
												pushChildNode((yyval.tree), (yyvsp[-1].tree));
											}
#line 1756 "y.tab.c"
    break;


#line 1760 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 266 "./src/compiler.y"


void yyerror ( char  *s) {
	fprintf (stderr, "%s\n", s);
}

extern FILE *yyin;
extern FILE *yyout;

void create_output_filename(const char *input, char *output) {
    const char *dot = strrchr(input, '.');
    if (dot) {
        size_t base_len = dot - input;
        strncpy(output, input, base_len);
        output[base_len] = '\0';
        strcat(output, ".s");
    } else {
        strcpy(output, input);
        strcat(output, ".s");
    }
}

int main(int argc, char *argv[]){
	if (argc < 2) {
        fprintf(stderr, "Usage: %s <sourcefile>\n", argv[0]);
        return 1;
    }

    // Open input file
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }

    // Create and open output file
    char output_file[256];
    create_output_filename(argv[1], output_file);
    yyout = fopen(output_file, "w");
    if (!yyout) {
        perror("Error opening output file");
        fclose(yyin);
        return 1;
    }

	
	
	printf("Compiling %s -> %s\n", argv[1], output_file);
    


	int result = yyparse();

    fclose(yyin);
    fclose(yyout);

    return result;
}
