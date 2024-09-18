/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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
                   Unif (*unify)(Type,Type)) ;
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

#line 130 "parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INCREMENT = 258,
    DECREMENT = 259,
    PLUS = 260,
    MINUS = 261,
    TIMES = 262,
    OVER = 263,
    PERCENT = 264,
    GREATER_THAN = 265,
    LESS_THAN = 266,
    GREATER_THAN_OR_EQUAL = 267,
    LESS_THAN_OR_EQUAL = 268,
    EQUALS = 269,
    NOT_EQUALS = 270,
    ADD_ASSIGN = 271,
    SUB_ASSIGN = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ASSIGNMENT = 276,
    LOGICAL_AND = 277,
    ADDRESS = 278,
    LOGICAL_OR = 279,
    LOGICAL_NOT = 280,
    OPEN_PARENTHESES = 281,
    CLOSE_PARENTHESES = 282,
    OPEN_BRACKET = 283,
    CLOSE_BRACKET = 284,
    OPEN_KEYS = 285,
    CLOSE_KEYS = 286,
    SEMICOLON = 287,
    COMMA = 288,
    CHAR = 289,
    CONTINUE = 290,
    ELSE = 291,
    FLOAT = 292,
    WHILE = 293,
    IF = 294,
    INT = 295,
    RETURN = 296,
    VOID = 297,
    STRING = 298,
    ID = 299,
    INT_NUMBER = 300,
    REAL_NUMBER = 301,
    CHAR_ASCII = 302,
    SCANF = 303,
    PRINTF = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef AST* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#endif


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
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
     243,   248,   252,   252,   253,   257,   258,   259,   260,   261,
     262,   266,   268,   270,   272,   274,   276,   278,   280,   282,
     284,   286,   288,   290,   292,   296,   297,   298,   299,   303,
     304,   305,   307,   313,   314,   318,   319,   319,   323,   323,
     325,   325,   327,   327,   333,   337,   337,   340,   344,   344,
     348,   353,   354,   355,   356,   357,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCREMENT", "DECREMENT", "PLUS",
  "MINUS", "TIMES", "OVER", "PERCENT", "GREATER_THAN", "LESS_THAN",
  "GREATER_THAN_OR_EQUAL", "LESS_THAN_OR_EQUAL", "EQUALS", "NOT_EQUALS",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ASSIGNMENT", "LOGICAL_AND", "ADDRESS", "LOGICAL_OR", "LOGICAL_NOT",
  "OPEN_PARENTHESES", "CLOSE_PARENTHESES", "OPEN_BRACKET", "CLOSE_BRACKET",
  "OPEN_KEYS", "CLOSE_KEYS", "SEMICOLON", "COMMA", "CHAR", "CONTINUE",
  "ELSE", "FLOAT", "WHILE", "IF", "INT", "RETURN", "VOID", "STRING", "ID",
  "INT_NUMBER", "REAL_NUMBER", "CHAR_ASCII", "SCANF", "PRINTF", "$accept",
  "program", "global_declarations", "global_declaration",
  "function_declaration", "$@1", "parameter_list", "parameter",
  "variable_declaration", "init_declarator_list", "init_declarator", "$@2",
  "$@3", "array_initialization", "initializer_list", "initializer",
  "type_specifier", "compound_statement", "statement_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "return_statement", "expression", "assignment_expression", "$@4",
  "assignment_operator", "binary_expression", "unary_operator",
  "unary_expression", "cast_expression", "postfix_expression", "$@5",
  "$@6", "$@7", "$@8", "argument_expression_list", "$@9", "read-stmt",
  "$@10", "write-stmt", "primary_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,  -119,  -119,  -119,  -119,    34,   -17,  -119,  -119,  -119,
     -38,  -119,  -119,     0,   -14,  -119,    15,    30,    36,  -119,
      22,  -119,   -17,   253,    12,  -119,    38,   -11,  -119,    25,
      43,    44,  -119,  -119,  -119,  -119,   202,  -119,    55,  -119,
    -119,  -119,  -119,  -119,   160,   258,  -119,  -119,  -119,  -119,
      56,    48,   -17,  -119,  -119,  -119,    52,    53,   103,    69,
      82,   112,   121,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,    11,  -119,    86,  -119,
      59,  -119,  -119,   258,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,   253,   253,   253,  -119,  -119,   299,   299,   255,   255,
     255,    33,    33,    33,    33,   275,   275,   209,   209,     6,
    -119,  -119,   104,   109,   115,   208,   118,   136,  -119,    22,
    -119,   108,  -119,  -119,  -119,  -119,  -119,   131,   132,   144,
    -119,  -119,  -119,     3,   148,  -119,   -26,  -119,  -119,  -119,
     253,   253,  -119,   147,   139,    83,  -119,  -119,  -119,  -119,
    -119,  -119,   253,  -119,  -119,     6,   159,   161,  -119,  -119,
     253,  -119,   164,  -119,  -119,   155,   155,   182,  -119,  -119,
    -119,   174,  -119,   155,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    29,    28,    27,    30,     0,     2,     4,     5,     6,
       0,     1,     3,    16,     0,    14,     0,     0,     0,    13,
       0,    19,    11,     0,    16,    15,     0,     0,    10,     0,
       0,     0,    75,    76,    77,    78,     0,   106,   101,   102,
     103,   104,    18,    51,    54,     0,    83,    74,    79,    85,
      22,     0,     0,    12,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,    80,     0,    20,
       0,     8,     9,     0,   105,    56,    57,    58,    59,    60,
      55,     0,    97,     0,    91,    93,    61,    62,    63,    64,
      65,    67,    66,    69,    68,    70,    71,    72,    73,    22,
      32,    45,     0,     0,     0,     0,     0,     0,    40,     0,
      36,     0,    34,    35,    37,    38,    39,     0,     0,     0,
      84,    53,    94,     0,     0,    26,     0,    23,    25,    43,
       0,     0,    50,     0,     0,     0,    31,    33,    44,    41,
      42,    87,     0,    89,    21,    22,     0,     0,    49,    98,
       0,   101,     0,    95,    24,     0,     0,     0,   100,    96,
      48,    46,    99,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   220,  -119,  -119,  -119,   163,    35,  -119,
     210,  -119,  -119,   179,  -119,    77,     2,   184,  -119,  -118,
    -119,  -119,  -119,  -119,   -23,   -91,  -119,  -119,   261,  -119,
    -119,   -41,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,    92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    17,    27,    28,   118,    14,
      15,    18,    26,   135,   136,   137,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    43,    58,    91,    44,    45,
      46,    47,    48,    59,    60,    61,    62,   133,   169,   128,
     167,   129,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   132,    10,   147,    77,   154,    13,   155,    10,    30,
      31,    32,    33,    57,   -90,   -92,    51,     1,    19,    20,
       2,   -17,    52,     3,    29,     4,    -7,    78,    16,    34,
     151,    35,    36,   -17,    11,     9,   152,   -86,    56,   -88,
      16,     9,   130,   -93,   -93,   -93,   -93,   170,   171,    37,
      38,    39,    40,    41,    29,   174,    22,    23,   -90,   -92,
      21,   163,    30,    31,    32,    33,    24,    50,   131,    53,
     134,   -52,   -52,   -52,   -52,   -52,   -52,    78,    80,    83,
      84,   -86,    34,   -88,    35,    36,   138,    54,    55,    80,
     110,   111,   143,     1,   112,    92,     2,   113,   114,     3,
     115,     4,    37,    38,    39,    40,    41,   116,   117,   160,
      93,    30,    31,    32,    33,    94,   109,   156,   157,    85,
      86,    87,    88,    89,    90,    95,    37,   161,    39,    40,
      41,    34,   138,    35,    36,   140,   139,    57,    80,   146,
     111,   141,     1,   112,   144,     2,   113,   114,     3,   115,
       4,    37,    38,    39,    40,    41,   116,   117,    30,    31,
      32,    33,   145,   148,   149,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,   150,   153,    34,   158,
      35,    36,    74,   159,    75,    80,   165,   111,   166,     1,
     112,   168,     2,   113,   114,     3,   115,     4,    37,    38,
      39,    40,    41,   116,   117,    30,    31,    32,    33,   172,
     173,    30,    31,    32,    33,    82,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    34,    12,    35,    36,    79,
      25,    34,   164,    35,    36,    81,     1,   162,     0,     2,
     142,     0,     3,     0,     4,    37,    38,    39,    40,    41,
       0,    37,    38,    39,    40,    41,    30,    31,    32,    33,
       0,    30,    31,    32,    33,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,    34,     0,    35,    36,
       0,    34,     0,    35,    36,    68,    69,    70,    71,   -93,
     -93,     0,     0,     0,     0,     0,    37,    38,    39,    40,
      41,    37,    76,    39,    40,    41,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
       0,    74,     0,    75,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
      23,    92,     0,   121,    45,    31,    44,    33,     6,     3,
       4,     5,     6,    36,     3,     4,    27,    34,    32,    33,
      37,    21,    33,    40,    22,    42,    26,    21,    28,    23,
      27,    25,    26,    21,     0,     0,    33,    26,    36,    28,
      28,     6,    83,    10,    11,    12,    13,   165,   166,    43,
      44,    45,    46,    47,    52,   173,    26,    21,     3,     4,
      45,   152,     3,     4,     5,     6,    44,    29,    91,    44,
      93,    16,    17,    18,    19,    20,    21,    21,    30,    27,
      27,    26,    23,    28,    25,    26,   109,    44,    44,    30,
      31,    32,   115,    34,    35,    26,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    26,
      28,     3,     4,     5,     6,     3,    30,   140,   141,    16,
      17,    18,    19,    20,    21,     4,    43,    44,    45,    46,
      47,    23,   155,    25,    26,    26,    32,   160,    30,    31,
      32,    26,    34,    35,    26,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     3,     4,
       5,     6,    26,    32,    32,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    32,    29,    23,    32,
      25,    26,    22,    44,    24,    30,    27,    32,    27,    34,
      35,    27,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     3,     4,     5,     6,    27,
      36,     3,     4,     5,     6,    52,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    23,     6,    25,    26,    50,
      20,    23,   155,    25,    26,    51,    34,   145,    -1,    37,
      32,    -1,    40,    -1,    42,    43,    44,    45,    46,    47,
      -1,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      -1,     3,     4,     5,     6,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    23,    -1,    25,    26,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    43,    44,    45,    46,    47,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    24,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    37,    40,    42,    51,    52,    53,    54,    58,
      66,     0,    53,    44,    59,    60,    28,    55,    61,    32,
      33,    45,    26,    21,    44,    60,    62,    56,    57,    66,
       3,     4,     5,     6,    23,    25,    26,    43,    44,    45,
      46,    47,    74,    75,    78,    79,    80,    81,    82,    92,
      29,    27,    33,    44,    44,    44,    66,    74,    76,    83,
      84,    85,    86,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    22,    24,    44,    81,    21,    63,
      30,    67,    57,    27,    27,    16,    17,    18,    19,    20,
      21,    77,    26,    28,     3,     4,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    30,
      31,    32,    35,    38,    39,    41,    48,    49,    58,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    89,    91,
      81,    74,    75,    87,    74,    63,    64,    65,    74,    32,
      26,    26,    32,    74,    26,    26,    31,    69,    32,    32,
      32,    27,    33,    29,    31,    33,    74,    74,    32,    44,
      26,    44,    92,    75,    65,    27,    27,    90,    27,    88,
      69,    69,    27,    36,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    55,    54,    56,
      56,    56,    57,    58,    59,    59,    60,    61,    60,    62,
      60,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    73,
      73,    74,    76,    75,    75,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    83,    82,    84,    82,
      85,    82,    86,    82,    87,    88,    87,    87,    90,    89,
      91,    92,    92,    92,    92,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     7,     3,
       1,     0,     2,     3,     1,     3,     1,     0,     4,     0,
       6,     4,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     5,     7,     5,     3,
       2,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     4,     1,     0,     5,     0,     5,
       0,     3,     0,     3,     1,     0,     4,     0,     0,     5,
       4,     1,     1,     1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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
   required.  Return 1 if memory is exhausted.  */
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
          return 1;
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
          return 1;
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
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
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
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
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
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
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
      {
        YYPTRDIFF_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
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
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
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
                return 2;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyesa, yy_state_t **yyes,
                YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

    yy_state_t yyesa[20];
    yy_state_t *yyes;
    YYPTRDIFF_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = 20;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  case 2:
#line 95 "parser.y"
                          {root = yyvsp[0] ; }
#line 1808 "parser.c"
    break;

  case 3:
#line 100 "parser.y"
                                             { 
          add_child(yyvsp[-1], yyvsp[0]); 
            yyval = yyvsp[-1]; 
      }
#line 1817 "parser.c"
    break;

  case 4:
#line 104 "parser.y"
                         { 
          yyval = new_subtree(PROGRAM_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 1825 "parser.c"
    break;

  case 5:
#line 110 "parser.y"
                           { yyval = yyvsp[0]; }
#line 1831 "parser.c"
    break;

  case 6:
#line 111 "parser.y"
                           { yyval = yyvsp[0]; }
#line 1837 "parser.c"
    break;

  case 7:
#line 115 "parser.y"
                        {
         strcpy(last_func_decl,VarSave); yyvsp[0]=new_fun(); 
         }
#line 1845 "parser.c"
    break;

  case 8:
#line 118 "parser.y"
                                                                           {
        add_child(yyvsp[-5], yyvsp[-2]);
        add_child(yyvsp[-5], yyvsp[0]);
        yyval=yyvsp[-5];
      }
#line 1855 "parser.c"
    break;

  case 9:
#line 126 "parser.y"
                                     { SomaQtdParam(last_func_decl, ft);add_child(yyvsp[-2], yyvsp[0]); yyval = yyvsp[-2];  }
#line 1861 "parser.c"
    break;

  case 10:
#line 127 "parser.y"
                { SomaQtdParam(last_func_decl, ft); 
         yyval = new_subtree(PARAM_LIST_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 1869 "parser.c"
    break;

  case 11:
#line 130 "parser.y"
                 {yyval = new_subtree(PARAM_LIST_NODE, NO_TYPE, 0, 0);}
#line 1875 "parser.c"
    break;

  case 12:
#line 134 "parser.y"
                        { yyval=new_var(); }
#line 1881 "parser.c"
    break;

  case 13:
#line 138 "parser.y"
                                                   {
        yyval = yyvsp[-1];
    }
#line 1889 "parser.c"
    break;

  case 14:
#line 145 "parser.y"
                     { 
          yyval = new_subtree(VAR_LIST_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 1897 "parser.c"
    break;

  case 15:
#line 148 "parser.y"
                                                { 
          add_child(yyvsp[-2], yyvsp[0]); 
          yyval = yyvsp[-2]; 
      }
#line 1906 "parser.c"
    break;

  case 16:
#line 155 "parser.y"
         { yyval= new_var(); }
#line 1912 "parser.c"
    break;

  case 17:
#line 156 "parser.y"
         { yyvsp[0]=new_var(); }
#line 1918 "parser.c"
    break;

  case 18:
#line 156 "parser.y"
                                                 {
        yyval = new_subtree(ASSIGN_NODE, get_node_type(yyvsp[-3]), 0, 2, yyvsp[-3], yyvsp[0]); 
    }
#line 1926 "parser.c"
    break;

  case 19:
#line 159 "parser.y"
                                { ArraySize=atoi(yytext); yyvsp[-2]=new_var(); }
#line 1932 "parser.c"
    break;

  case 20:
#line 159 "parser.y"
                                                                                                             {
        yyval = new_subtree(ARRAY_DECL_NODE, get_node_type(yyvsp[-5]), get_node_size(yyvsp[-5]), 2, yyvsp[-5], yyvsp[0]); 
    }
#line 1940 "parser.c"
    break;

  case 21:
#line 165 "parser.y"
                                                      {
        yyval = yyvsp[-1];
    }
#line 1948 "parser.c"
    break;

  case 22:
#line 168 "parser.y"
                      {yyval=new_subtree(INIT_LIST_NODE, NO_TYPE, 0, 0); }
#line 1954 "parser.c"
    break;

  case 23:
#line 172 "parser.y"
                 { 
          yyval = new_subtree(INIT_LIST_NODE, NO_TYPE, 0, 1, yyvsp[0]); 
      }
#line 1962 "parser.c"
    break;

  case 24:
#line 175 "parser.y"
                                        {
          add_child(yyvsp[-2], yyvsp[0]); 
          yyval = yyvsp[-2]; 
      }
#line 1971 "parser.c"
    break;

  case 25:
#line 182 "parser.y"
                 { yyval=yyvsp[0]; }
#line 1977 "parser.c"
    break;

  case 26:
#line 183 "parser.y"
                           { yyval=yyvsp[0]; }
#line 1983 "parser.c"
    break;

  case 27:
#line 186 "parser.y"
          { last_decl_type = INT_TYPE; }
#line 1989 "parser.c"
    break;

  case 28:
#line 187 "parser.y"
            { last_decl_type = FLOAT_TYPE; }
#line 1995 "parser.c"
    break;

  case 29:
#line 188 "parser.y"
           { last_decl_type = CHAR_TYPE; }
#line 2001 "parser.c"
    break;

  case 30:
#line 189 "parser.y"
           { last_decl_type = VOID_TYPE; }
#line 2007 "parser.c"
    break;

  case 31:
#line 194 "parser.y"
                                         { 
          yyval = yyvsp[-1];
      }
#line 2015 "parser.c"
    break;

  case 32:
#line 198 "parser.y"
        { yyval = new_subtree(BLOCK_NODE, NO_TYPE, 0, 0); }
#line 2021 "parser.c"
    break;

  case 33:
#line 202 "parser.y"
                               { 
          add_child(yyvsp[-1], yyvsp[0]); 
          yyval = yyvsp[-1]; 
      }
#line 2030 "parser.c"
    break;

  case 34:
#line 206 "parser.y"
               {
        yyval=new_subtree(BLOCK_NODE, NO_TYPE, 0, 1, yyvsp[0]); 

    }
#line 2039 "parser.c"
    break;

  case 35:
#line 213 "parser.y"
                           { yyval = yyvsp[0]; }
#line 2045 "parser.c"
    break;

  case 36:
#line 214 "parser.y"
                         { yyval = yyvsp[0]; }
#line 2051 "parser.c"
    break;

  case 37:
#line 215 "parser.y"
                          { yyval = yyvsp[0]; }
#line 2057 "parser.c"
    break;

  case 38:
#line 216 "parser.y"
                          { yyval = yyvsp[0]; }
#line 2063 "parser.c"
    break;

  case 39:
#line 217 "parser.y"
                       { yyval = yyvsp[0]; }
#line 2069 "parser.c"
    break;

  case 40:
#line 218 "parser.y"
                           { yyval = yyvsp[0]; }
#line 2075 "parser.c"
    break;

  case 41:
#line 219 "parser.y"
                          { yyval =yyvsp[-1]; }
#line 2081 "parser.c"
    break;

  case 42:
#line 220 "parser.y"
                           { yyval = yyvsp[-1]; }
#line 2087 "parser.c"
    break;

  case 43:
#line 221 "parser.y"
                         { yyval = new_node(CONTINUE_NODE, 0, 0,NO_TYPE, 0);  }
#line 2093 "parser.c"
    break;

  case 44:
#line 225 "parser.y"
                           { yyval = yyvsp[-1]; }
#line 2099 "parser.c"
    break;

  case 46:
#line 230 "parser.y"
                                                                 { yyval = check_if_then(yyvsp[-2], yyvsp[0]) ;}
#line 2105 "parser.c"
    break;

  case 47:
#line 231 "parser.y"
                                                                                { yyval = check_if_then_else(yyvsp[-4], yyvsp[-2] , yyvsp[0]); }
#line 2111 "parser.c"
    break;

  case 48:
#line 235 "parser.y"
                                                                    { yyval = check_repeat(yyvsp[0], yyvsp[-2]); }
#line 2117 "parser.c"
    break;

  case 49:
#line 239 "parser.y"
                                  { 
                                    check_return_types(get_node_type(yyvsp[-1]));
                                    yyval = new_subtree(RETURN_NODE, get_node_type(yyvsp[-1]), 0, 1, yyvsp[-1]);
                                  }
#line 2126 "parser.c"
    break;

  case 50:
#line 243 "parser.y"
                       { check_return_types(VOID_TYPE); 
                         yyval = new_node(RETURN_NODE, 0, 0,VOID_TYPE, 0); }
#line 2133 "parser.c"
    break;

  case 51:
#line 248 "parser.y"
                           {yyval=yyvsp[0];}
#line 2139 "parser.c"
    break;

  case 52:
#line 252 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2145 "parser.c"
    break;

  case 53:
#line 252 "parser.y"
                                                            { yyval=check_assign(yyvsp[-3], yyvsp[0], unify_assign); }
#line 2151 "parser.c"
    break;

  case 54:
#line 253 "parser.y"
                        { yyval=yyvsp[0]; }
#line 2157 "parser.c"
    break;

  case 61:
#line 266 "parser.y"
                                               { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], PLUS_NODE, "+", unify_arith_op);
                                                 check_size_bin_node(yyvsp[-2], yyvsp[0], "+");/*se saiu é igual*/ set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2164 "parser.c"
    break;

  case 62:
#line 268 "parser.y"
                                                { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], MINUS_NODE, "-", unify_arith_op); 
                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"-"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2171 "parser.c"
    break;

  case 63:
#line 270 "parser.y"
                                                { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], TIMES_NODE, "*", unify_arith_op); 
                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"*"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2178 "parser.c"
    break;

  case 64:
#line 272 "parser.y"
                                               { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], OVER_NODE, "/", unify_arith_op); 
                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"/"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2185 "parser.c"
    break;

  case 65:
#line 274 "parser.y"
                                                  { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], PERCENT_NODE, "%", unify_arith_percent); 
                                                    check_size_bin_node(yyvsp[-2], yyvsp[0],"%"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2192 "parser.c"
    break;

  case 66:
#line 276 "parser.y"
                                                    { yyval= unify_bin_node(yyvsp[-2], yyvsp[0], LESS_THAN_NODE, "<", unify_relational); 
                                                    check_size_bin_node(yyvsp[-2], yyvsp[0],"<"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2199 "parser.c"
    break;

  case 67:
#line 278 "parser.y"
                                                       { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], GREATER_THAN_NODE, ">", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],">"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2206 "parser.c"
    break;

  case 68:
#line 280 "parser.y"
                                                             { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], LESS_THAN_OR_EQUAL_NODE, "<=", unify_relational); 
                                                                check_size_bin_node(yyvsp[-2], yyvsp[0],"<="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2213 "parser.c"
    break;

  case 69:
#line 282 "parser.y"
                                                                { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], GREATER_THAN_OR_EQUAL_NODE, ">=", unify_relational); 
                                                                check_size_bin_node(yyvsp[-2], yyvsp[0],">="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2220 "parser.c"
    break;

  case 70:
#line 284 "parser.y"
                                                 { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], EQUALS_NODE, "==", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"=="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2227 "parser.c"
    break;

  case 71:
#line 286 "parser.y"
                                                     { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], NOT_EQUALS_NODE, "!=", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"!="); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2234 "parser.c"
    break;

  case 72:
#line 288 "parser.y"
                                                      { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], LOGICAL_AND_NODE, "&&", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"&&"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2241 "parser.c"
    break;

  case 73:
#line 290 "parser.y"
                                                     { yyval = unify_bin_node(yyvsp[-2], yyvsp[0], LOGICAL_OR_NODE, "||", unify_relational); 
                                                        check_size_bin_node(yyvsp[-2], yyvsp[0],"||"); set_node_size(yyval, get_node_size(yyvsp[-2])); }
#line 2248 "parser.c"
    break;

  case 74:
#line 292 "parser.y"
                      { yyval= yyvsp[0]; }
#line 2254 "parser.c"
    break;

  case 79:
#line 303 "parser.y"
                         { yyval=yyvsp[0]; }
#line 2260 "parser.c"
    break;

  case 80:
#line 304 "parser.y"
                                     { yyval=yyvsp[0]; }
#line 2266 "parser.c"
    break;

  case 81:
#line 305 "parser.y"
                   { yyvsp[0]=check_var();
                     yyval = new_subtree(INCREMENT_NODE, get_node_type(yyvsp[0]), 0, 1, yyvsp[0]);}
#line 2273 "parser.c"
    break;

  case 82:
#line 307 "parser.y"
                   { yyvsp[0]=check_var();
                     yyval = new_subtree(DECREMENT_NODE, get_node_type(yyvsp[0]), 0, 1, yyvsp[0]);}
#line 2280 "parser.c"
    break;

  case 83:
#line 313 "parser.y"
                       { yyval=yyvsp[0]; }
#line 2286 "parser.c"
    break;

  case 84:
#line 314 "parser.y"
                                                                        { yyval=yyvsp[0]; }
#line 2292 "parser.c"
    break;

  case 85:
#line 318 "parser.y"
                         { yyval=yyvsp[0]; }
#line 2298 "parser.c"
    break;

  case 86:
#line 319 "parser.y"
             { yyvsp[0]=check_fun(); strcpy(last_func_call,VarSave); }
#line 2304 "parser.c"
    break;

  case 87:
#line 319 "parser.y"
                                                                                                                             {
          check_params();
          yyval = yyvsp[-4];
          QtdParam=0; }
#line 2313 "parser.c"
    break;

  case 88:
#line 323 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2319 "parser.c"
    break;

  case 89:
#line 324 "parser.y"
         { yyval = new_subtree(ARRAY_ACCESS_NODE, get_node_type(yyvsp[-4]), 0, 2, yyvsp[-4], yyvsp[-1]);}
#line 2325 "parser.c"
    break;

  case 90:
#line 325 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2331 "parser.c"
    break;

  case 91:
#line 326 "parser.y"
         { yyval = new_subtree(INCREMENT_NODE, get_node_type(yyvsp[-2]), 0, 1, yyvsp[-2]); }
#line 2337 "parser.c"
    break;

  case 92:
#line 327 "parser.y"
         { yyvsp[0]=check_var(); }
#line 2343 "parser.c"
    break;

  case 93:
#line 328 "parser.y"
         { yyval = new_subtree(DECREMENT_NODE, get_node_type(yyvsp[-2]), 0, 1, yyvsp[-2]);}
#line 2349 "parser.c"
    break;

  case 94:
#line 333 "parser.y"
                            { check_params_types_sizes(get_node_type(yyvsp[0]), get_node_size(yyvsp[0]));
                              QtdParam=1;
                              yyval=yyvsp[0]; 
                            }
#line 2358 "parser.c"
    break;

  case 95:
#line 337 "parser.y"
                                                           { 
                              check_params_types_sizes(get_node_type(yyvsp[-2]), get_node_size(yyvsp[-2])); }
#line 2365 "parser.c"
    break;

  case 96:
#line 339 "parser.y"
                              { QtdParam++; }
#line 2371 "parser.c"
    break;

  case 97:
#line 340 "parser.y"
                      { QtdParam=0; }
#line 2377 "parser.c"
    break;

  case 98:
#line 344 "parser.y"
                               { yyvsp[0] = check_var(); }
#line 2383 "parser.c"
    break;

  case 99:
#line 344 "parser.y"
                                                                      { yyval = new_subtree(READ_NODE, NO_TYPE, 0, 1, yyvsp[-2]); }
#line 2389 "parser.c"
    break;

  case 100:
#line 348 "parser.y"
                                                                 { yyval = new_subtree(WRITE_NODE, NO_TYPE, 0, 1, yyvsp[-1]); }
#line 2395 "parser.c"
    break;

  case 101:
#line 353 "parser.y"
         { yyval = check_var(); }
#line 2401 "parser.c"
    break;

  case 102:
#line 354 "parser.y"
                 { yyval = yyvsp[0]; }
#line 2407 "parser.c"
    break;

  case 103:
#line 355 "parser.y"
                  { yyval = yyvsp[0]; }
#line 2413 "parser.c"
    break;

  case 104:
#line 356 "parser.y"
                 { yyval = yyvsp[0] ;}
#line 2419 "parser.c"
    break;

  case 105:
#line 357 "parser.y"
                                                    { yyval= yyvsp[-1]; }
#line 2425 "parser.c"
    break;

  case 106:
#line 358 "parser.y"
             { yyval = yyvsp[0]; }
#line 2431 "parser.c"
    break;


#line 2435 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 361 "parser.y"


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
                   Unif (*unify)(Type,Type)) {
    Type lt = get_node_type(l);
    Type rt = get_node_type(r);
    
    int lt_size=get_node_size(l);
    int rt_size=get_node_size(r);
    Unif unif = unify(lt, rt);
    if (unif.type == NO_TYPE) {
        type_error("=", lt, rt);
    }
    if(lt_size!=rt_size){
        assign_size_error(lt_size,rt_size);
    }

    l = create_conv_node(unif.lc, l);
    r = create_conv_node(unif.rc, r);
    return new_subtree(ASSIGN_NODE, NO_TYPE, 0, 2, l, r);
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
