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
#line 6 "parser.y"

//#define DEBUG_MODE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "ast.h"
#include "types.h"
#include "parser.h"
#include "tables.h"


#ifdef DEBUG_MODE
        #define DEBUG_PRINT(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
    #else
        #define DEBUG_PRINT(fmt, ...)
    #endif

int yylex(void);
void yyerror(const char *s);

int yylex_destroy(void);
AST* check_var();
int check_size();
AST* new_var();
AST* new_fun();
AST* check_fun();
void check_params();

AST* unify_bin_node(AST* l, AST* r,
                    NodeKind kind, const char* op, Unif (*unify)(Type,Type));

//void check_assign(Type l, Type r);
void check_size_bin_op(int size1, int size2, const char* op);
void check_size_bin_node(AST* l, AST* r, const char* op);
void check_bool_expr(const char* cmd, Type t);
AST* check_if_then(AST *e, AST *b);
AST* check_if_then_else(AST *e, AST *b1, AST *b2);
AST* check_repeat(AST *b, AST *e);
void check_params_types_sizes(Type type, int size);
void assign_size_error(int size1, int size2);
void check_return_types(Type type);
AST* check_assign(AST* l, AST* r,
                   Unif (*unify)(Type,Type), const char* op, NodeKind kind) ;
extern int yylineno;
extern char *yytext;
char *VarSave;
char last_func_decl[128];
char last_func_call[128];

int ArraySize=0;
int QtdParam=0;

StrTable *st;
VarTable *vt;
FuncTable *ft;
Type last_decl_type;
AST *root;

#line 131 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INCREMENT = 3,                  /* INCREMENT  */
  YYSYMBOL_DECREMENT = 4,                  /* DECREMENT  */
  YYSYMBOL_PLUS = 5,                       /* PLUS  */
  YYSYMBOL_MINUS = 6,                      /* MINUS  */
  YYSYMBOL_TIMES = 7,                      /* TIMES  */
  YYSYMBOL_OVER = 8,                       /* OVER  */
  YYSYMBOL_PERCENT = 9,                    /* PERCENT  */
  YYSYMBOL_GREATER_THAN = 10,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 11,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN_OR_EQUAL = 12,     /* GREATER_THAN_OR_EQUAL  */
  YYSYMBOL_LESS_THAN_OR_EQUAL = 13,        /* LESS_THAN_OR_EQUAL  */
  YYSYMBOL_EQUALS = 14,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 15,                /* NOT_EQUALS  */
  YYSYMBOL_ADD_ASSIGN = 16,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 17,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ASSIGNMENT = 21,                /* ASSIGNMENT  */
  YYSYMBOL_LOGICAL_AND = 22,               /* LOGICAL_AND  */
  YYSYMBOL_ADDRESS = 23,                   /* ADDRESS  */
  YYSYMBOL_LOGICAL_OR = 24,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 25,               /* LOGICAL_NOT  */
  YYSYMBOL_OPEN_PARENTHESES = 26,          /* OPEN_PARENTHESES  */
  YYSYMBOL_CLOSE_PARENTHESES = 27,         /* CLOSE_PARENTHESES  */
  YYSYMBOL_OPEN_BRACKET = 28,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 29,             /* CLOSE_BRACKET  */
  YYSYMBOL_OPEN_KEYS = 30,                 /* OPEN_KEYS  */
  YYSYMBOL_CLOSE_KEYS = 31,                /* CLOSE_KEYS  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 33,                     /* COMMA  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_FLOAT = 37,                     /* FLOAT  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_IF = 39,                        /* IF  */
  YYSYMBOL_INT = 40,                       /* INT  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_VOID = 42,                      /* VOID  */
  YYSYMBOL_STRING = 43,                    /* STRING  */
  YYSYMBOL_ID = 44,                        /* ID  */
  YYSYMBOL_INT_NUMBER = 45,                /* INT_NUMBER  */
  YYSYMBOL_REAL_NUMBER = 46,               /* REAL_NUMBER  */
  YYSYMBOL_CHAR_ASCII = 47,                /* CHAR_ASCII  */
  YYSYMBOL_SCANF = 48,                     /* SCANF  */
  YYSYMBOL_PRINTF = 49,                    /* PRINTF  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_global_declarations = 52,       /* global_declarations  */
  YYSYMBOL_global_declaration = 53,        /* global_declaration  */
  YYSYMBOL_function_declaration = 54,      /* function_declaration  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_parameter_list = 56,            /* parameter_list  */
  YYSYMBOL_parameter = 57,                 /* parameter  */
  YYSYMBOL_variable_declaration = 58,      /* variable_declaration  */
  YYSYMBOL_init_declarator_list = 59,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 60,           /* init_declarator  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_array_initialization = 63,      /* array_initialization  */
  YYSYMBOL_initializer_list = 64,          /* initializer_list  */
  YYSYMBOL_initializer = 65,               /* initializer  */
  YYSYMBOL_type_specifier = 66,            /* type_specifier  */
  YYSYMBOL_compound_statement = 67,        /* compound_statement  */
  YYSYMBOL_statement_list = 68,            /* statement_list  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_expression_statement = 70,      /* expression_statement  */
  YYSYMBOL_selection_statement = 71,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 72,       /* iteration_statement  */
  YYSYMBOL_return_statement = 73,          /* return_statement  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_assignment_expression = 75,     /* assignment_expression  */
  YYSYMBOL_76_4 = 76,                      /* $@4  */
  YYSYMBOL_77_5 = 77,                      /* $@5  */
  YYSYMBOL_78_6 = 78,                      /* $@6  */
  YYSYMBOL_79_7 = 79,                      /* $@7  */
  YYSYMBOL_80_8 = 80,                      /* $@8  */
  YYSYMBOL_81_9 = 81,                      /* $@9  */
  YYSYMBOL_binary_expression = 82,         /* binary_expression  */
  YYSYMBOL_unary_operator = 83,            /* unary_operator  */
  YYSYMBOL_unary_expression = 84,          /* unary_expression  */
  YYSYMBOL_cast_expression = 85,           /* cast_expression  */
  YYSYMBOL_postfix_expression = 86,        /* postfix_expression  */
  YYSYMBOL_87_10 = 87,                     /* $@10  */
  YYSYMBOL_88_11 = 88,                     /* $@11  */
  YYSYMBOL_89_12 = 89,                     /* $@12  */
  YYSYMBOL_90_13 = 90,                     /* $@13  */
  YYSYMBOL_argument_expression_list = 91,  /* argument_expression_list  */
  YYSYMBOL_92_14 = 92,                     /* $@14  */
  YYSYMBOL_93_read_stmt = 93,              /* read-stmt  */
  YYSYMBOL_94_15 = 94,                     /* $@15  */
  YYSYMBOL_95_write_stmt = 95,             /* write-stmt  */
  YYSYMBOL_primary_expression = 96         /* primary_expression  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   317

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,   100,   104,   110,   111,   115,   115,   126,
     127,   130,   134,   138,   145,   148,   155,   156,   156,   159,
     159,   165,   168,   172,   175,   182,   183,   186,   187,   188,
     189,   194,   197,   202,   206,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   225,   226,   230,   231,   235,   239,
     243,   248,   252,   252,   253,   253,   254,   254,   255,   255,
     256,   256,   257,   257,   258,   263,   265,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   285,   287,   289,   293,
     294,   295,   296,   300,   301,   302,   304,   310,   311,   315,
     316,   316,   320,   320,   322,   322,   324,   324,   330,   334,
     334,   337,   341,   341,   345,   350,   351,   352,   353,   354,
     355
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INCREMENT",
  "DECREMENT", "PLUS", "MINUS", "TIMES", "OVER", "PERCENT", "GREATER_THAN",
  "LESS_THAN", "GREATER_THAN_OR_EQUAL", "LESS_THAN_OR_EQUAL", "EQUALS",
  "NOT_EQUALS", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ASSIGNMENT", "LOGICAL_AND", "ADDRESS", "LOGICAL_OR",
  "LOGICAL_NOT", "OPEN_PARENTHESES", "CLOSE_PARENTHESES", "OPEN_BRACKET",
  "CLOSE_BRACKET", "OPEN_KEYS", "CLOSE_KEYS", "SEMICOLON", "COMMA", "CHAR",
  "CONTINUE", "ELSE", "FLOAT", "WHILE", "IF", "INT", "RETURN", "VOID",
  "STRING", "ID", "INT_NUMBER", "REAL_NUMBER", "CHAR_ASCII", "SCANF",
  "PRINTF", "$accept", "program", "global_declarations",
  "global_declaration", "function_declaration", "$@1", "parameter_list",
  "parameter", "variable_declaration", "init_declarator_list",
  "init_declarator", "$@2", "$@3", "array_initialization",
  "initializer_list", "initializer", "type_specifier",
  "compound_statement", "statement_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "return_statement", "expression", "assignment_expression", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "binary_expression", "unary_operator",
  "unary_expression", "cast_expression", "postfix_expression", "$@10",
  "$@11", "$@12", "$@13", "argument_expression_list", "$@14", "read-stmt",
  "$@15", "write-stmt", "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,  -124,  -124,  -124,  -124,    32,    23,  -124,  -124,  -124,
     -36,  -124,  -124,     2,    67,  -124,    -8,    16,    28,  -124,
      10,  -124,    23,   223,    12,  -124,    44,    31,  -124,    17,
      40,    49,  -124,  -124,  -124,  -124,     1,  -124,   280,  -124,
    -124,  -124,  -124,  -124,   171,   248,  -124,  -124,  -124,  -124,
      80,    75,    23,  -124,  -124,  -124,    81,   116,   126,   132,
     135,   137,   154,   155,   148,   159,   185,   186,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,     8,  -124,   164,  -124,    72,  -124,  -124,   248,  -124,
     223,   223,   223,   223,   223,   223,   223,   223,  -124,  -124,
       7,     7,   265,   265,   265,    76,    76,    76,    76,   275,
     275,   302,   302,   213,  -124,  -124,   165,   173,   176,   218,
     194,   199,  -124,    10,  -124,   119,  -124,  -124,  -124,  -124,
    -124,   198,   200,   201,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,    58,   202,  -124,    61,  -124,  -124,  -124,   223,
     223,  -124,   203,   193,    36,  -124,  -124,  -124,  -124,  -124,
    -124,   223,  -124,  -124,   213,   215,   220,  -124,  -124,   223,
    -124,   228,  -124,  -124,   166,   166,   245,  -124,  -124,  -124,
     204,  -124,   166,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    29,    28,    27,    30,     0,     2,     4,     5,     6,
       0,     1,     3,    16,     0,    14,     0,     0,     0,    13,
       0,    19,    11,     0,    16,    15,     0,     0,    10,     0,
       0,     0,    79,    80,    81,    82,     0,   110,   105,   106,
     107,   108,    18,    51,    64,     0,    87,    78,    83,    89,
      22,     0,     0,    12,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,    84,     0,    20,     0,     8,     9,     0,   109,
       0,     0,     0,     0,     0,     0,   101,     0,    95,    97,
      65,    66,    67,    68,    69,    71,    70,    73,    72,    74,
      75,    76,    77,    22,    32,    45,     0,     0,     0,     0,
       0,     0,    40,     0,    36,     0,    34,    35,    37,    38,
      39,     0,     0,     0,    88,    53,    55,    57,    59,    61,
      63,    98,     0,     0,    26,     0,    23,    25,    43,     0,
       0,    50,     0,     0,     0,    31,    33,    44,    41,    42,
      91,     0,    93,    21,    22,     0,     0,    49,   102,     0,
     105,     0,    99,    24,     0,     0,     0,   104,   100,    48,
      46,   103,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,   239,  -124,  -124,  -124,   229,    50,  -124,
     262,  -124,  -124,   252,  -124,   139,     3,   253,  -124,  -123,
    -124,  -124,  -124,  -124,   -23,   -95,  -124,  -124,  -124,  -124,
    -124,  -124,    60,  -124,  -124,   -35,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,   151
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    17,    27,    28,   122,    14,
      15,    18,    26,   144,   145,   146,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    43,    58,    59,    60,    61,
      62,    63,    44,    45,    46,    47,    48,    64,    65,    66,
      67,   142,   178,   132,   176,   133,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   141,   156,    10,    30,    31,    32,    33,    13,    10,
      82,   -94,   -96,    57,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   -17,    34,    29,    35,    36,    -7,    79,
      16,    80,    11,   -17,   -90,     1,   -92,    21,     2,    56,
      16,     3,    22,     4,    37,    38,    39,    40,    41,    23,
       9,   179,   180,   134,    24,    29,     9,     1,    51,   183,
       2,    53,   169,     3,    52,     4,   172,   135,   136,   137,
     138,   139,   140,    50,   143,    30,    31,    32,    33,    37,
     170,    39,    40,    41,    54,   160,   -97,   -97,   -97,   -97,
     147,   161,   163,    55,   164,    34,   152,    35,    36,    19,
      20,    83,    85,   114,   115,    85,     1,   116,    88,     2,
     117,   118,     3,   119,     4,    37,    38,    39,    40,    41,
     120,   121,    30,    31,    32,    33,   165,   166,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   147,    34,    89,    35,    36,    57,    90,    91,    85,
     155,   115,    92,     1,   116,    93,     2,   117,   118,     3,
     119,     4,    37,    38,    39,    40,    41,   120,   121,    30,
      31,    32,    33,    94,    96,    95,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    97,    98,    34,
      99,    35,    36,    79,   113,    80,    85,   148,   115,   149,
       1,   116,   150,     2,   117,   118,     3,   119,     4,    37,
      38,    39,    40,    41,   120,   121,    30,    31,    32,    33,
     153,    30,    31,    32,    33,   154,    30,    31,    32,    33,
     157,   162,   158,   159,    83,   167,    34,   168,    35,    36,
     182,    34,   174,    35,    36,    12,    34,   175,    35,    36,
     151,    30,    31,    32,    33,   177,    37,    38,    39,    40,
      41,    37,    38,    39,    40,    41,    37,    38,    39,    40,
      41,    34,   181,    35,    36,    73,    74,    75,    76,    77,
      78,    87,    25,   -94,   -96,    73,    74,    75,    76,   -97,
     -97,    37,    81,    39,    40,    41,   -54,   -56,   -58,   -60,
     -62,   -52,    84,   173,    86,   171,   -90,     0,   -92,    70,
      71,    72,    73,    74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
      23,    96,   125,     0,     3,     4,     5,     6,    44,     6,
      45,     3,     4,    36,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    21,    23,    22,    25,    26,    26,    22,
      28,    24,     0,    21,    26,    34,    28,    45,    37,    36,
      28,    40,    26,    42,    43,    44,    45,    46,    47,    21,
       0,   174,   175,    88,    44,    52,     6,    34,    27,   182,
      37,    44,    26,    40,    33,    42,   161,    90,    91,    92,
      93,    94,    95,    29,    97,     3,     4,     5,     6,    43,
      44,    45,    46,    47,    44,    27,    10,    11,    12,    13,
     113,    33,    31,    44,    33,    23,   119,    25,    26,    32,
      33,    21,    30,    31,    32,    30,    34,    35,    27,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     3,     4,     5,     6,   149,   150,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   164,    23,    27,    25,    26,   169,    21,    16,    30,
      31,    32,    17,    34,    35,    18,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     3,
       4,     5,     6,    19,    26,    20,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    28,     3,    23,
       4,    25,    26,    22,    30,    24,    30,    32,    32,    26,
      34,    35,    26,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     3,     4,     5,     6,
      26,     3,     4,     5,     6,    26,     3,     4,     5,     6,
      32,    29,    32,    32,    21,    32,    23,    44,    25,    26,
      36,    23,    27,    25,    26,     6,    23,    27,    25,    26,
      32,     3,     4,     5,     6,    27,    43,    44,    45,    46,
      47,    43,    44,    45,    46,    47,    43,    44,    45,    46,
      47,    23,    27,    25,    26,    10,    11,    12,    13,    14,
      15,    52,    20,     3,     4,    10,    11,    12,    13,    14,
      15,    43,    44,    45,    46,    47,    16,    17,    18,    19,
      20,    21,    50,   164,    51,   154,    26,    -1,    28,     7,
       8,     9,    10,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    37,    40,    42,    51,    52,    53,    54,    58,
      66,     0,    53,    44,    59,    60,    28,    55,    61,    32,
      33,    45,    26,    21,    44,    60,    62,    56,    57,    66,
       3,     4,     5,     6,    23,    25,    26,    43,    44,    45,
      46,    47,    74,    75,    82,    83,    84,    85,    86,    96,
      29,    27,    33,    44,    44,    44,    66,    74,    76,    77,
      78,    79,    80,    81,    87,    88,    89,    90,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    22,
      24,    44,    85,    21,    63,    30,    67,    57,    27,    27,
      21,    16,    17,    18,    19,    20,    26,    28,     3,     4,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    30,    31,    32,    35,    38,    39,    41,
      48,    49,    58,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    93,    95,    85,    74,    74,    74,    74,    74,
      74,    75,    91,    74,    63,    64,    65,    74,    32,    26,
      26,    32,    74,    26,    26,    31,    69,    32,    32,    32,
      27,    33,    29,    31,    33,    74,    74,    32,    44,    26,
      44,    96,    75,    65,    27,    27,    94,    27,    92,    69,
      69,    27,    36,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    55,    54,    56,
      56,    56,    57,    58,    59,    59,    60,    61,    60,    62,
      60,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    73,
      73,    74,    76,    75,    77,    75,    78,    75,    79,    75,
      80,    75,    81,    75,    75,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    84,    84,    84,    84,    85,    85,    86,
      87,    86,    88,    86,    89,    86,    90,    86,    91,    92,
      91,    91,    94,    93,    95,    96,    96,    96,    96,    96,
      96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     7,     3,
       1,     0,     2,     3,     1,     3,     1,     0,     4,     0,
       6,     4,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     5,     7,     5,     3,
       2,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     4,     1,
       0,     5,     0,     5,     0,     3,     0,     3,     1,     0,
       4,     0,     0,     5,     4,     1,     1,     1,     1,     3,
       1
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
        YY_LAC_DISCARD ("YYBACKUP");                              \
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* program: global_declarations  */
#line 95 "parser.y"
                          {root = yyvsp[0] ; }
#line 1888 "parser.c"
    break;

  case 3: /* global_declarations: global_declarations global_declaration  */
#line 100 "parser.y"
                                             { 
          add_child(yyvsp[-1], yyvsp[0]); 
            yyval = yyvsp[-1]; 
      }
#line 1897 "parser.c"
    break;

  case 4: /* global_declarations: global_declaration  */
#line 104 "parser.y"
                         { 
          yyval = new_subtree(PROGRAM_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 1905 "parser.c"
    break;

  case 5: /* global_declaration: function_declaration  */
#line 110 "parser.y"
                           { yyval = yyvsp[0]; }
#line 1911 "parser.c"
    break;

  case 6: /* global_declaration: variable_declaration  */
#line 111 "parser.y"
                           { yyval = yyvsp[0]; }
#line 1917 "parser.c"
    break;

  case 7: /* $@1: %empty  */
#line 115 "parser.y"
                        {
         strcpy(last_func_decl,VarSave); yyvsp[0]=new_fun(); 
         }
#line 1925 "parser.c"
    break;

  case 8: /* function_declaration: type_specifier ID $@1 OPEN_PARENTHESES parameter_list CLOSE_PARENTHESES compound_statement  */
#line 118 "parser.y"
                                                                           {
        add_child(yyvsp[-5], yyvsp[-2]);
        add_child(yyvsp[-5], yyvsp[0]);
        yyval=yyvsp[-5];
      }
#line 1935 "parser.c"
    break;

  case 9: /* parameter_list: parameter_list COMMA parameter  */
#line 126 "parser.y"
                                     { SomaQtdParam(last_func_decl, ft);add_child(yyvsp[-2], yyvsp[0]); yyval = yyvsp[-2];  }
#line 1941 "parser.c"
    break;

  case 10: /* parameter_list: parameter  */
#line 127 "parser.y"
                { SomaQtdParam(last_func_decl, ft); 
         yyval = new_subtree(PARAM_LIST_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 1949 "parser.c"
    break;

  case 11: /* parameter_list: %empty  */
#line 130 "parser.y"
                 {yyval = new_subtree(PARAM_LIST_NODE, NO_TYPE, 0, 0);}
#line 1955 "parser.c"
    break;

  case 12: /* parameter: type_specifier ID  */
#line 134 "parser.y"
                        { yyval=new_var(); }
#line 1961 "parser.c"
    break;

  case 13: /* variable_declaration: type_specifier init_declarator_list SEMICOLON  */
#line 138 "parser.y"
                                                   {
        yyval = yyvsp[-1];
    }
#line 1969 "parser.c"
    break;

  case 14: /* init_declarator_list: init_declarator  */
#line 145 "parser.y"
                     { 
          yyval = new_subtree(VAR_LIST_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 1977 "parser.c"
    break;

  case 15: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 148 "parser.y"
                                                { 
          add_child(yyvsp[-2], yyvsp[0]); 
          yyval = yyvsp[-2]; 
      }
#line 1986 "parser.c"
    break;

  case 16: /* init_declarator: ID  */
#line 155 "parser.y"
         { yyval= new_var(); }
#line 1992 "parser.c"
    break;

  case 17: /* $@2: %empty  */
#line 156 "parser.y"
         { yyvsp[0]=new_var(); }
#line 1998 "parser.c"
    break;

  case 18: /* init_declarator: ID $@2 ASSIGNMENT expression  */
#line 156 "parser.y"
                                                 {
        yyval = new_subtree(ASSIGN_NODE, get_node_type(yyvsp[-3]), 0, 2, yyvsp[-3], yyvsp[0]); 
    }
#line 2006 "parser.c"
    break;

  case 19: /* $@3: %empty  */
#line 159 "parser.y"
                                { ArraySize=atoi(yytext); yyvsp[-2]=new_var(); }
#line 2012 "parser.c"
    break;

  case 20: /* init_declarator: ID OPEN_BRACKET INT_NUMBER $@3 CLOSE_BRACKET array_initialization  */
#line 159 "parser.y"
                                                                                                             {
        yyval = new_subtree(ARRAY_DECL_NODE, get_node_type(yyvsp[-5]), get_node_size(yyvsp[-5]), 2, yyvsp[-5], yyvsp[0]); 
    }
#line 2020 "parser.c"
    break;

  case 21: /* array_initialization: ASSIGNMENT OPEN_KEYS initializer_list CLOSE_KEYS  */
#line 165 "parser.y"
                                                      {
        yyval = yyvsp[-1];
    }
#line 2028 "parser.c"
    break;

  case 22: /* array_initialization: %empty  */
#line 168 "parser.y"
                      {yyval=new_subtree(INIT_LIST_NODE, NO_TYPE, 0, 0); }
#line 2034 "parser.c"
    break;

  case 23: /* initializer_list: initializer  */
#line 172 "parser.y"
                 { 
          yyval = new_subtree(INIT_LIST_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 2042 "parser.c"
    break;

  case 24: /* initializer_list: initializer_list COMMA initializer  */
#line 175 "parser.y"
                                        {
          add_child(yyvsp[-2], yyvsp[0]); 
          yyval = yyvsp[-2]; 
      }
#line 2051 "parser.c"
    break;

  case 25: /* initializer: expression  */
#line 182 "parser.y"
                 { yyval=yyvsp[0]; }
#line 2057 "parser.c"
    break;

  case 26: /* initializer: array_initialization  */
#line 183 "parser.y"
                           { yyval=yyvsp[0]; }
#line 2063 "parser.c"
    break;

  case 27: /* type_specifier: INT  */
#line 186 "parser.y"
          { last_decl_type = INT_TYPE; }
#line 2069 "parser.c"
    break;

  case 28: /* type_specifier: FLOAT  */
#line 187 "parser.y"
            { last_decl_type = FLOAT_TYPE; }
#line 2075 "parser.c"
    break;

  case 29: /* type_specifier: CHAR  */
#line 188 "parser.y"
           { last_decl_type = CHAR_TYPE; }
#line 2081 "parser.c"
    break;

  case 30: /* type_specifier: VOID  */
#line 189 "parser.y"
           { last_decl_type = VOID_TYPE; }
#line 2087 "parser.c"
    break;

  case 31: /* compound_statement: OPEN_KEYS statement_list CLOSE_KEYS  */
#line 194 "parser.y"
                                         { 
          yyval = yyvsp[-1];
      }
#line 2095 "parser.c"
    break;

  case 32: /* compound_statement: OPEN_KEYS CLOSE_KEYS  */
#line 198 "parser.y"
        { yyval = new_subtree(BLOCK_NODE, NO_TYPE, 0, 0); }
#line 2101 "parser.c"
    break;

  case 33: /* statement_list: statement_list statement  */
#line 202 "parser.y"
                               { 
          add_child(yyvsp[-1], yyvsp[0]); 
          yyval = yyvsp[-1]; 
      }
#line 2110 "parser.c"
    break;

  case 34: /* statement_list: statement  */
#line 206 "parser.y"
               {
        yyval=new_subtree(BLOCK_NODE, NO_TYPE, 0, 1, yyvsp[0]); 

    }
#line 2119 "parser.c"
    break;

  case 35: /* statement: expression_statement  */
#line 213 "parser.y"
                           { yyval = yyvsp[0]; }
#line 2125 "parser.c"
    break;

  case 36: /* statement: compound_statement  */
#line 214 "parser.y"
                         { yyval = yyvsp[0]; }
#line 2131 "parser.c"
    break;

  case 37: /* statement: selection_statement  */
#line 215 "parser.y"
                          { yyval = yyvsp[0]; }
#line 2137 "parser.c"
    break;

  case 38: /* statement: iteration_statement  */
#line 216 "parser.y"
                          { yyval = yyvsp[0]; }
#line 2143 "parser.c"
    break;

  case 39: /* statement: return_statement  */
#line 217 "parser.y"
                       { yyval = yyvsp[0]; }
#line 2149 "parser.c"
    break;

  case 40: /* statement: variable_declaration  */
#line 218 "parser.y"
                           { yyval = yyvsp[0]; }
#line 2155 "parser.c"
    break;

  case 41: /* statement: read-stmt SEMICOLON  */
#line 219 "parser.y"
                          { yyval =yyvsp[-1]; }
#line 2161 "parser.c"
    break;

  case 42: /* statement: write-stmt SEMICOLON  */
#line 220 "parser.y"
                           { yyval = yyvsp[-1]; }
#line 2167 "parser.c"
    break;

  case 43: /* statement: CONTINUE SEMICOLON  */
#line 221 "parser.y"
                         { yyval = new_node(CONTINUE_NODE, 0, 0,NO_TYPE, 0);  }
#line 2173 "parser.c"
    break;

  case 44: /* expression_statement: expression SEMICOLON  */
#line 225 "parser.y"
                           { yyval = yyvsp[-1]; }
#line 2179 "parser.c"
    break;

  case 46: /* selection_statement: IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement  */
#line 230 "parser.y"
                                                                 { yyval = check_if_then(yyvsp[-2], yyvsp[0]) ;}
#line 2185 "parser.c"
    break;

  case 47: /* selection_statement: IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement  */
#line 231 "parser.y"
                                                                                { yyval = check_if_then_else(yyvsp[-4], yyvsp[-2] , yyvsp[0]); }
#line 2191 "parser.c"
    break;

  case 48: /* iteration_statement: WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement  */
#line 235 "parser.y"
                                                                    { yyval = check_repeat(yyvsp[0], yyvsp[-2]); }
#line 2197 "parser.c"
    break;

  case 49: /* return_statement: RETURN expression SEMICOLON  */
#line 239 "parser.y"
                                  { 
                                    check_return_types(get_node_type(yyvsp[-1]));
                                    yyval = new_subtree(RETURN_NODE, get_node_type(yyvsp[-1]), 0, 1, yyvsp[-1]);
                                  }
#line 2206 "parser.c"
    break;

  case 50: /* return_statement: RETURN SEMICOLON  */
#line 243 "parser.y"
                       { check_return_types(VOID_TYPE); 
                         yyval = new_node(RETURN_NODE, 0, 0,VOID_TYPE, 0); }
#line 2213 "parser.c"
    break;

  case 51: /* expression: assignment_expression  */
#line 248 "parser.y"
                           {yyval=yyvsp[0];}
#line 2219 "parser.c"
    break;

  case 52: /* $@4: %empty  */
#line 252 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2225 "parser.c"
    break;

  case 53: /* assignment_expression: ID $@4 ASSIGNMENT expression  */
#line 252 "parser.y"
                                                   { yyval=check_assign(yyvsp[-3], yyvsp[0], unify_assign, "=", ASSIGN_NODE); }
#line 2231 "parser.c"
    break;

  case 54: /* $@5: %empty  */
#line 253 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2237 "parser.c"
    break;

  case 55: /* assignment_expression: ID $@5 ADD_ASSIGN expression  */
#line 253 "parser.y"
                                                   { yyval=check_assign(yyvsp[-3], yyvsp[0], unify_assign, "+=", ADD_ASSIGN_NODE); }
#line 2243 "parser.c"
    break;

  case 56: /* $@6: %empty  */
#line 254 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2249 "parser.c"
    break;

  case 57: /* assignment_expression: ID $@6 SUB_ASSIGN expression  */
#line 254 "parser.y"
                                                   { yyval=check_assign(yyvsp[-3], yyvsp[0], unify_assign, "-=", SUB_ASSIGN_NODE); }
#line 2255 "parser.c"
    break;

  case 58: /* $@7: %empty  */
#line 255 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2261 "parser.c"
    break;

  case 59: /* assignment_expression: ID $@7 MUL_ASSIGN expression  */
#line 255 "parser.y"
                                                   { yyval=check_assign(yyvsp[-3], yyvsp[0], unify_assign,"*=", MUL_ASSIGN_NODE); }
#line 2267 "parser.c"
    break;

  case 60: /* $@8: %empty  */
#line 256 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2273 "parser.c"
    break;

  case 61: /* assignment_expression: ID $@8 DIV_ASSIGN expression  */
#line 256 "parser.y"
                                                   { yyval=check_assign(yyvsp[-3], yyvsp[0], unify_assign, "/=", DIV_ASSIGN_NODE); }
#line 2279 "parser.c"
    break;

  case 62: /* $@9: %empty  */
#line 257 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2285 "parser.c"
    break;

  case 63: /* assignment_expression: ID $@9 MOD_ASSIGN expression  */
#line 257 "parser.y"
                                                   { yyval=check_assign(yyvsp[-3], yyvsp[0], unify_assign, "%=", MOD_ASSIGN_NODE); }
#line 2291 "parser.c"
    break;

  case 64: /* assignment_expression: binary_expression  */
#line 258 "parser.y"
                        { yyval=yyvsp[0]; }
#line 2297 "parser.c"
    break;

  case 65: /* binary_expression: binary_expression PLUS binary_expression  */
#line 263 "parser.y"
                                               { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], PLUS_NODE, "+", unify_arith_op);
                                                 check_size_bin_node(yyvsp[-2], yyvsp[0], "+");/*se saiu é igual*/ set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2304 "parser.c"
    break;

  case 66: /* binary_expression: binary_expression MINUS binary_expression  */
#line 265 "parser.y"
                                                { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], MINUS_NODE, "-", unify_arith_op); 
                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"-"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2311 "parser.c"
    break;

  case 67: /* binary_expression: binary_expression TIMES binary_expression  */
#line 267 "parser.y"
                                                { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], TIMES_NODE, "*", unify_arith_op); 
                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"*"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2318 "parser.c"
    break;

  case 68: /* binary_expression: binary_expression OVER binary_expression  */
#line 269 "parser.y"
                                               { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], OVER_NODE, "/", unify_arith_op); 
                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"/"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2325 "parser.c"
    break;

  case 69: /* binary_expression: binary_expression PERCENT binary_expression  */
#line 271 "parser.y"
                                                  { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], PERCENT_NODE, "%", unify_arith_percent); 
                                                    check_size_bin_node(yyvsp[-2], yyvsp[0],"%"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2332 "parser.c"
    break;

  case 70: /* binary_expression: binary_expression LESS_THAN binary_expression  */
#line 273 "parser.y"
                                                    { yyval= unify_bin_node(yyvsp[-2], yyvsp[0], LESS_THAN_NODE, "<", unify_relational); 
                                                    check_size_bin_node(yyvsp[-2], yyvsp[0],"<"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2339 "parser.c"
    break;

  case 71: /* binary_expression: binary_expression GREATER_THAN binary_expression  */
#line 275 "parser.y"
                                                       { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], GREATER_THAN_NODE, ">", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],">"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2346 "parser.c"
    break;

  case 72: /* binary_expression: binary_expression LESS_THAN_OR_EQUAL binary_expression  */
#line 277 "parser.y"
                                                             { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], LESS_THAN_OR_EQUAL_NODE, "<=", unify_relational); 
                                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"<="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2353 "parser.c"
    break;

  case 73: /* binary_expression: binary_expression GREATER_THAN_OR_EQUAL binary_expression  */
#line 279 "parser.y"
                                                                { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], GREATER_THAN_OR_EQUAL_NODE, ">=", unify_relational); 
                                                                check_size_bin_node(yyvsp[-2], yyvsp[0],">="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2360 "parser.c"
    break;

  case 74: /* binary_expression: binary_expression EQUALS binary_expression  */
#line 281 "parser.y"
                                                 { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], EQUALS_NODE, "==", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"=="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2367 "parser.c"
    break;

  case 75: /* binary_expression: binary_expression NOT_EQUALS binary_expression  */
#line 283 "parser.y"
                                                     { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], NOT_EQUALS_NODE, "!=", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"!="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2374 "parser.c"
    break;

  case 76: /* binary_expression: binary_expression LOGICAL_AND binary_expression  */
#line 285 "parser.y"
                                                      { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], LOGICAL_AND_NODE, "&&", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"&&"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2381 "parser.c"
    break;

  case 77: /* binary_expression: binary_expression LOGICAL_OR binary_expression  */
#line 287 "parser.y"
                                                     { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], LOGICAL_OR_NODE, "||", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"||"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2388 "parser.c"
    break;

  case 78: /* binary_expression: cast_expression  */
#line 289 "parser.y"
                      { yyval= yyvsp[0]; }
#line 2394 "parser.c"
    break;

  case 83: /* unary_expression: postfix_expression  */
#line 300 "parser.y"
                         { yyval=yyvsp[0]; }
#line 2400 "parser.c"
    break;

  case 84: /* unary_expression: unary_operator cast_expression  */
#line 301 "parser.y"
                                     { yyval=yyvsp[0]; }
#line 2406 "parser.c"
    break;

  case 85: /* unary_expression: INCREMENT ID  */
#line 302 "parser.y"
                   { yyvsp[0]=check_var();
                     yyval = new_subtree(INCREMENT_NODE, get_node_type(yyvsp[0]), 0, 1, yyvsp[0]);}
#line 2413 "parser.c"
    break;

  case 86: /* unary_expression: DECREMENT ID  */
#line 304 "parser.y"
                   { yyvsp[0]=check_var();
                     yyval = new_subtree(DECREMENT_NODE, get_node_type(yyvsp[0]), 0, 1, yyvsp[0]);}
#line 2420 "parser.c"
    break;

  case 87: /* cast_expression: unary_expression  */
#line 310 "parser.y"
                       { yyval=yyvsp[0]; }
#line 2426 "parser.c"
    break;

  case 88: /* cast_expression: OPEN_PARENTHESES type_specifier CLOSE_PARENTHESES cast_expression  */
#line 311 "parser.y"
                                                                        { yyval=yyvsp[0]; }
#line 2432 "parser.c"
    break;

  case 89: /* postfix_expression: primary_expression  */
#line 315 "parser.y"
                         { yyval=yyvsp[0]; }
#line 2438 "parser.c"
    break;

  case 90: /* $@10: %empty  */
#line 316 "parser.y"
             { yyvsp[0]=check_fun(); strcpy(last_func_call,VarSave); }
#line 2444 "parser.c"
    break;

  case 91: /* postfix_expression: ID $@10 OPEN_PARENTHESES argument_expression_list CLOSE_PARENTHESES  */
#line 316 "parser.y"
                                                                                                                             {
          check_params();
          yyval = yyvsp[-4];
          QtdParam=0; }
#line 2453 "parser.c"
    break;

  case 92: /* $@11: %empty  */
#line 320 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2459 "parser.c"
    break;

  case 93: /* postfix_expression: ID $@11 OPEN_BRACKET expression CLOSE_BRACKET  */
#line 321 "parser.y"
         { yyval = new_subtree(ARRAY_ACCESS_NODE, get_node_type(yyvsp[-4]), 0, 2, yyvsp[-4], yyvsp[-1]);}
#line 2465 "parser.c"
    break;

  case 94: /* $@12: %empty  */
#line 322 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2471 "parser.c"
    break;

  case 95: /* postfix_expression: ID $@12 INCREMENT  */
#line 323 "parser.y"
         { yyval = new_subtree(INCREMENT_NODE, get_node_type(yyvsp[-2]), 0, 1, yyvsp[-2]); }
#line 2477 "parser.c"
    break;

  case 96: /* $@13: %empty  */
#line 324 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2483 "parser.c"
    break;

  case 97: /* postfix_expression: ID $@13 DECREMENT  */
#line 325 "parser.y"
         { yyval = new_subtree(DECREMENT_NODE, get_node_type(yyvsp[-2]), 0, 1, yyvsp[-2]);}
#line 2489 "parser.c"
    break;

  case 98: /* argument_expression_list: assignment_expression  */
#line 330 "parser.y"
                            { check_params_types_sizes(get_node_type(yyvsp[0]), get_node_size(yyvsp[0]));
                              QtdParam=1;
                              yyval=yyvsp[0]; 
                            }
#line 2498 "parser.c"
    break;

  case 99: /* $@14: %empty  */
#line 334 "parser.y"
                                                           { 
                              check_params_types_sizes(get_node_type(yyvsp[-2]), get_node_size(yyvsp[-2])); }
#line 2505 "parser.c"
    break;

  case 100: /* argument_expression_list: argument_expression_list COMMA assignment_expression $@14  */
#line 336 "parser.y"
                              { QtdParam++; }
#line 2511 "parser.c"
    break;

  case 101: /* argument_expression_list: %empty  */
#line 337 "parser.y"
                      { QtdParam=0; }
#line 2517 "parser.c"
    break;

  case 102: /* $@15: %empty  */
#line 341 "parser.y"
                               { yyvsp[0] = check_var(); }
#line 2523 "parser.c"
    break;

  case 103: /* read-stmt: SCANF OPEN_PARENTHESES ID $@15 CLOSE_PARENTHESES  */
#line 341 "parser.y"
                                                                      { yyval = new_subtree(READ_NODE, NO_TYPE, 0, 1, yyvsp[-2]); }
#line 2529 "parser.c"
    break;

  case 104: /* write-stmt: PRINTF OPEN_PARENTHESES primary_expression CLOSE_PARENTHESES  */
#line 345 "parser.y"
                                                                 { yyval = new_subtree(WRITE_NODE, NO_TYPE, 0, 1, yyvsp[-1]); }
#line 2535 "parser.c"
    break;

  case 105: /* primary_expression: ID  */
#line 350 "parser.y"
         { yyval = check_var(); }
#line 2541 "parser.c"
    break;

  case 106: /* primary_expression: INT_NUMBER  */
#line 351 "parser.y"
                 { yyval = yyvsp[0]; }
#line 2547 "parser.c"
    break;

  case 107: /* primary_expression: REAL_NUMBER  */
#line 352 "parser.y"
                  { yyval = yyvsp[0]; }
#line 2553 "parser.c"
    break;

  case 108: /* primary_expression: CHAR_ASCII  */
#line 353 "parser.y"
                 { yyval = yyvsp[0] ;}
#line 2559 "parser.c"
    break;

  case 109: /* primary_expression: OPEN_PARENTHESES expression CLOSE_PARENTHESES  */
#line 354 "parser.y"
                                                    { yyval= yyvsp[-1]; }
#line 2565 "parser.c"
    break;

  case 110: /* primary_expression: STRING  */
#line 355 "parser.y"
             { yyval = yyvsp[0]; }
#line 2571 "parser.c"
    break;


#line 2575 "parser.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 358 "parser.y"


int main(void) {
    st = create_str_table();
    DEBUG_PRINT("Criado str table\n");

    ft = create_func_table();
    DEBUG_PRINT("Criado func table\n");


    VarSave = malloc(sizeof(char) * 128);
    DEBUG_PRINT("Alocada memória para VarSave\n");

    DEBUG_PRINT("Início da análise\n");
    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
    } else {
        printf("PARSE FAILED!\n");
    }
    printf("\n\n");
    print_str_table(st); printf("\n\n");
    print_table(ft); printf("\n\n");
    print_dot(root);

    //print_tree_names(root, 2);

    stdin = fopen(ctermid(NULL), "r");
    run_ast(root);
    fclose(stdin);

    free_str_table(st);
    free_table(ft);
    free(VarSave);
    free_tree(root);
    yylex_destroy();
    return 0;
}


void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

AST* check_var() {
    int lookup= lookup_func(ft, last_func_decl);
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, VarSave);
        exit(EXIT_FAILURE);
    }
    return new_node(VAR_USE_NODE,idx,lookup,get_typevar_in_func(ft, idx, lookup),
                    get_sizevar_in_func(ft, idx, lookup));
}

int check_size(){
    int lookup= lookup_func(ft, last_func_decl);
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    return get_sizevar_in_func(ft, idx, lookup);
    
}

AST* new_var() {
    int lookup = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (lookup != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, VarSave, get_linevar_in_func(ft,last_func_decl, lookup));
        exit(EXIT_FAILURE);
    }
    int idx=add_var_in_func(ft, VarSave, last_func_decl, yylineno, last_decl_type, ArraySize);
    lookup=lookup_func(ft, last_func_decl);
    AST*aux= new_node(VAR_DECL_NODE, idx,lookup, last_decl_type,ArraySize);


    
    ArraySize=0;
    return aux;
}



AST* new_fun(){
	int idx = lookup_func(ft, last_func_decl);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): Function '%s' already declared at line %d.\n",
                yylineno, last_func_decl, get_line_func(ft, idx));
        exit(EXIT_FAILURE);
    }
    idx=add_func(ft, last_func_decl, yylineno, last_decl_type);
    return new_node(FUN_DECL_NODE, idx,0, last_decl_type,0);
}

AST* check_fun(){
	int idx = lookup_func(ft, VarSave);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): Function '%s' was not declared.\n",
                yylineno, VarSave);
        exit(EXIT_FAILURE);
    }
    return new_node(FUN_USE_NODE, idx,0, last_decl_type,0);
    
}

void check_params(){
    int idx = lookup_func(ft, last_func_call);
    if(!VerificaQtdParam(last_func_call, ft,  QtdParam)){
        printf("SEMANTIC ERROR (%d): Function '%s' was declared with %d params in (%d), but the function call has %d params\n",
                yylineno, last_func_call, get_qtdparams(ft, idx), get_line_func(ft, idx), QtdParam);
        exit(EXIT_FAILURE);
    }
}



// ----------------------------------------------------------------------------

// Type checking and inference.

void type_error(const char* op, Type t1, Type t2) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(t2));
    exit(EXIT_FAILURE);
}

void type_warning(const char* op, Type t1, Type t2) {
    printf("WARNING (%d): possible loss of precision or unexpected behavior for operator '%s'. LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(t2));
}

AST* create_conv_node(Conv conv, AST *n) {
    switch(conv) {
        case C2I:  return new_subtree(C2I_NODE, INT_TYPE, 0 ,1, n);  // char -> int
        case C2F:  return new_subtree(C2F_NODE, FLOAT_TYPE, 0, 1, n);  // char -> float
        case I2F:  return new_subtree(I2F_NODE, FLOAT_TYPE, 0, 1, n);  // int -> float
        case I2C:  return new_subtree(I2C_NODE, CHAR_TYPE, 0, 1, n);  // int -> char
        case I2B:  return new_subtree(I2B_NODE, BOOL_TYPE, 0, 1, n);  // int -> bool
        case F2B:  return new_subtree(F2B_NODE, BOOL_TYPE, 0, 1, n);  // float -> bool
        case C2B:  return new_subtree(C2B_NODE, BOOL_TYPE, 0, 1, n);  // char -> bool
        case F2I:  return new_subtree(F2I_NODE, INT_TYPE, 0, 1, n);  // float -> int
        case NONE: return n;  // Nenhuma conversão necessária
        default:
            printf("INTERNAL ERROR: invalid conversion of types!%d\n", conv);
            exit(EXIT_FAILURE);
    }
}

AST* unify_bin_node(AST* l, AST* r,NodeKind kind,
                  const char* op, Unif (*unify)(Type,Type)) {

    Type lt = get_node_type(l);
    Type rt = get_node_type(r);
    Unif unif = unify(lt, rt);
    
    if (unif.type == NO_TYPE) {
        type_error(op, lt, rt);
    }

    l = create_conv_node(unif.lc, l);
    r = create_conv_node(unif.rc, r);
    return new_subtree(kind, unif.type, 0, 2, l, r);
}

/*
void check_size_bin_op(int size1, int size2,const char* op){
    if(size1!=size2){
        printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%d' and RHS is '%d'.\n",
           yylineno, op, size1, size2 );
        exit(EXIT_FAILURE);
    }

}
*/

void check_size_bin_node(AST* l, AST* r, const char* op){
    int size1 = get_node_size(l);
    int size2 = get_node_size(r);
    
    if(size1!=size2){
        printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%d' and RHS is '%d'.\n",
           yylineno, op, size1, size2 );
        exit(EXIT_FAILURE);
    }
    
}

AST* check_assign(AST* l, AST* r,
                   Unif (*unify)(Type,Type), const char* op, NodeKind kind) {
    Type lt = get_node_type(l);
    Type rt = get_node_type(r);
    
    int lt_size=get_node_size(l);
    int rt_size=get_node_size(r);
    Unif unif = unify(lt, rt);
    if (unif.type == NO_TYPE) {
        type_error(op, lt, rt);
    }
    if(lt_size!=rt_size){
        assign_size_error(lt_size,rt_size);
    }

    l = create_conv_node(unif.lc, l);
    r = create_conv_node(unif.rc, r);
    return new_subtree(kind, NO_TYPE, 0, 2, l, r);
}

void assign_size_error(int size1, int size2){
    if(size1!=size2){
        printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%d' and RHS is '%d'.\n",
           yylineno, "=", size1, size2 );
        exit(EXIT_FAILURE);
    }
}




void check_bool_expr(const char* cmd, Type t) {
    if (t != BOOL_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(t), get_text(BOOL_TYPE));
        exit(EXIT_FAILURE);
    }
}

AST* check_if_then(AST *e, AST *b) {
    check_bool_expr("if", get_node_type(e));
    return new_subtree(IF_NODE, NO_TYPE, 0, 2, e, b);
}

AST* check_if_then_else(AST *e, AST *b1, AST *b2) {
    check_bool_expr("if", get_node_type(e));
    return new_subtree(IF_NODE, NO_TYPE, 0, 3, e, b1, b2);
}

AST* check_repeat(AST *b, AST *e) {
    check_bool_expr("repeat", get_node_type(e));
    return new_subtree(REPEAT_NODE, NO_TYPE, 0, 2, b, e);
}


void check_params_types_sizes(Type type, int size)
    {
    int idx = lookup_func(ft, last_func_call);
    int aux=QtdParam+1;
    if(type!=get_typevar_in_func(ft, QtdParam,idx)){
        printf("SEMANTIC ERROR (%d): The parameter %d of '%s' call is %s, but at the function declarator(%d) is %s\n",
                yylineno,aux, last_func_call,get_text(get_typevar_in_func(ft, QtdParam, idx)), get_line_func(ft, idx),get_text(type));
        exit(EXIT_FAILURE);
    }
    if(size!=get_sizevar_in_func(ft, QtdParam,idx)){
        printf("SEMANTIC ERROR (%d): The size of parameter %d of '%s' call is %d , but at the function declarator(%d) is %d\n",
                yylineno,aux, last_func_call,get_sizevar_in_func(ft, QtdParam, idx), get_line_func(ft, idx),size);
        exit(EXIT_FAILURE);
    }
}

void check_return_types(Type type){
    int idx = lookup_func(ft, last_func_decl);
    if(type!=get_typertn(ft, idx)){
        printf("SEMANTIC ERROR (%d): The return type of %s is %s, but the function is returning %s\n",
                yylineno, last_func_decl,get_text(get_typertn(ft, idx)),get_text(type));
        exit(EXIT_FAILURE);
    }
}
