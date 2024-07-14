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
#line 5 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include "parser.h"


int yylex(void);
void yyerror(const char *s);
extern int yylineno;

#line 83 "parser.c"

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
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_CHAR = 35,                      /* CHAR  */
  YYSYMBOL_CONTINUE = 36,                  /* CONTINUE  */
  YYSYMBOL_DOUBLE = 37,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_FLOAT = 39,                     /* FLOAT  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_IF = 41,                        /* IF  */
  YYSYMBOL_INT = 42,                       /* INT  */
  YYSYMBOL_RETURN = 43,                    /* RETURN  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRING = 45,                    /* STRING  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INT_NUMBER = 47,                /* INT_NUMBER  */
  YYSYMBOL_REAL_NUMBER = 48,               /* REAL_NUMBER  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_primary_expression = 50,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 51,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 52,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 53,          /* unary_expression  */
  YYSYMBOL_unary_operator = 54,            /* unary_operator  */
  YYSYMBOL_cast_expression = 55,           /* cast_expression  */
  YYSYMBOL_logical_or_expression = 56,     /* logical_or_expression  */
  YYSYMBOL_assignment_expression = 57,     /* assignment_expression  */
  YYSYMBOL_assignment_operator = 58,       /* assignment_operator  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_constant_expression = 60,       /* constant_expression  */
  YYSYMBOL_declaration = 61,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 62,    /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 63,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 64,           /* init_declarator  */
  YYSYMBOL_type_specifier = 65,            /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 66,  /* specifier_qualifier_list  */
  YYSYMBOL_declarator = 67,                /* declarator  */
  YYSYMBOL_direct_declarator = 68,         /* direct_declarator  */
  YYSYMBOL_pointer = 69,                   /* pointer  */
  YYSYMBOL_parameter_type_list = 70,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 71,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 72,     /* parameter_declaration  */
  YYSYMBOL_identifier_list = 73,           /* identifier_list  */
  YYSYMBOL_type_name = 74,                 /* type_name  */
  YYSYMBOL_abstract_declarator = 75,       /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 76, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 77,               /* initializer  */
  YYSYMBOL_initializer_list = 78,          /* initializer_list  */
  YYSYMBOL_designation = 79,               /* designation  */
  YYSYMBOL_designator_list = 80,           /* designator_list  */
  YYSYMBOL_designator = 81,                /* designator  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_compound_statement = 83,        /* compound_statement  */
  YYSYMBOL_block_item_list = 84,           /* block_item_list  */
  YYSYMBOL_block_item = 85,                /* block_item  */
  YYSYMBOL_expression_statement = 86,      /* expression_statement  */
  YYSYMBOL_selection_statement = 87,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 88,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 89,            /* jump_statement  */
  YYSYMBOL_translation_unit = 90,          /* translation_unit  */
  YYSYMBOL_external_declaration = 91,      /* external_declaration  */
  YYSYMBOL_function_definition = 92,       /* function_definition  */
  YYSYMBOL_declaration_list = 93           /* declaration_list  */
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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   637

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    42,    43,    44,    45,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    61,    62,    66,    67,
      68,    69,    73,    74,    75,    76,    77,    81,    82,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   104,   105,   109,   110,   111,   112,
     113,   114,   118,   119,   123,   127,   128,   132,   133,   137,
     138,   142,   143,   147,   148,   149,   150,   151,   155,   156,
     160,   161,   165,   166,   167,   168,   169,   170,   171,   172,
     176,   177,   181,   185,   186,   190,   191,   192,   196,   197,
     201,   202,   206,   207,   208,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   226,   227,   228,   232,
     233,   234,   235,   239,   243,   244,   248,   249,   253,   254,
     255,   256,   257,   261,   262,   266,   267,   271,   272,   276,
     277,   281,   282,   286,   290,   291,   292,   296,   297,   301,
     302,   306,   307,   311,   312
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
  "CLOSE_BRACKET", "OPEN_KEYS", "CLOSE_KEYS", "DOT", "SEMICOLON", "COMMA",
  "CHAR", "CONTINUE", "DOUBLE", "ELSE", "FLOAT", "WHILE", "IF", "INT",
  "RETURN", "VOID", "STRING", "ID", "INT_NUMBER", "REAL_NUMBER", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "logical_or_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "specifier_qualifier_list", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     157,  -182,  -182,  -182,  -182,  -182,  -182,     8,   157,   129,
    -182,  -182,    11,     3,  -182,  -182,    47,  -182,   520,   152,
       4,  -182,  -182,  -182,  -182,    32,  -182,     3,   239,   115,
    -182,     8,  -182,   593,    89,   392,   152,  -182,  -182,    44,
     500,   500,  -182,  -182,  -182,  -182,  -182,   276,   362,  -182,
    -182,  -182,  -182,  -182,    35,   231,   526,  -182,   584,  -182,
    -182,  -182,  -182,    43,    60,    97,   397,  -182,   141,  -182,
    -182,  -182,   184,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,     9,    80,    77,  -182,    24,   114,  -182,   124,
     276,  -182,  -182,    78,   157,    19,   142,   526,   133,  -182,
     108,   239,    85,  -182,  -182,  -182,   428,   526,   162,  -182,
    -182,  -182,  -182,  -182,  -182,   526,  -182,  -182,   526,   526,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     526,   526,  -182,   526,   526,  -182,   224,  -182,   526,  -182,
    -182,   158,   443,  -182,    38,  -182,   185,  -182,   157,  -182,
     166,  -182,  -182,   171,  -182,  -182,   347,   190,  -182,   454,
     584,   174,  -182,  -182,   302,  -182,  -182,  -182,  -182,    81,
    -182,    14,  -182,  -182,   602,   602,  -182,  -182,  -182,   228,
     228,   228,   228,   330,   330,   281,   281,   281,    98,   143,
    -182,  -182,  -182,   195,   227,   232,  -182,   238,   185,   592,
     489,  -182,  -182,   229,   362,  -182,  -182,  -182,  -182,   239,
    -182,   526,  -182,   230,   230,  -182,  -182,  -182,  -182,  -182,
     241,   243,  -182,   245,   113,  -182,  -182,  -182,   259,  -182,
    -182,  -182,  -182,   332,   230,  -182,  -182
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    64,    67,    66,    65,    63,   140,     0,    57,     0,
     137,   139,    80,     0,    55,    72,     0,    59,    61,    71,
       0,    58,     1,   138,    81,     0,    56,     0,     0,     0,
     143,     0,   142,     0,     0,     0,    70,    73,    60,    61,
       0,     0,    24,    25,    23,    22,    26,     0,     0,     5,
       2,     3,     4,     7,    18,    27,     0,    29,    44,   106,
      62,   123,   129,     0,     0,     0,     0,    52,     0,   127,
     128,   118,     0,   125,   119,   120,   121,   122,   144,   141,
      79,    88,    87,     0,    82,    83,     0,    23,    76,     0,
       0,    19,    20,     0,    69,    90,     0,     0,     0,   109,
       0,     0,     0,   114,    12,    13,     0,     0,     0,    50,
      51,    47,    48,    49,    46,     0,    27,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,   135,     0,   130,     0,   124,
     126,     0,     0,    85,    92,    86,    93,    77,     0,    78,
       0,    75,    74,     0,     6,    68,     0,    92,    91,     0,
      54,     0,   117,   107,     0,   110,   113,   115,     9,     0,
      16,     0,    11,    45,    33,    34,    30,    31,    32,    36,
      35,    38,    37,    39,    40,    42,    41,    43,     0,     0,
     136,    53,   102,     0,     0,    23,    96,     0,    94,     0,
       0,    84,    89,     0,     0,    28,   116,   108,   111,     0,
      10,     0,     8,     0,     0,   103,    95,   100,    97,   104,
       0,    23,    98,     0,     0,   112,    17,   133,   131,   105,
     101,    99,    14,     0,     0,    15,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,  -182,  -182,   -29,  -182,   -50,   457,   -28,  -182,
     -30,  -182,   -10,    13,  -182,   271,   -38,   206,    -3,   -17,
      -7,   -32,  -182,   155,  -182,   214,   -13,  -100,   -27,   106,
    -150,  -182,   210,  -181,     7,  -182,   242,  -182,  -182,  -182,
    -182,  -182,   307,  -182,  -182
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    53,    54,   169,    55,    56,    57,    58,    67,   115,
      68,   161,     6,    82,    16,    17,     8,    95,    25,    19,
      20,   193,    84,    85,    86,    96,   194,   146,    99,   100,
     101,   102,   103,    70,    71,    72,    73,    74,    75,    76,
      77,     9,    10,    11,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    60,    83,    36,    18,    24,   117,    89,    30,    94,
      12,    91,    92,     7,   209,    12,    12,    93,    12,    69,
      59,    21,     7,    78,    39,    32,    12,   116,    39,    13,
      13,    31,   227,   228,    13,   141,   136,   142,   104,   105,
      79,    14,    31,   212,   198,   156,    31,   142,   138,    15,
      15,   149,    94,   236,    15,    15,    94,   198,   150,    37,
      93,   106,    69,   107,   141,    28,   142,   108,   116,   145,
     176,   177,   178,    59,   165,   144,   132,   171,   170,   143,
      26,    27,   158,   209,    15,    31,   133,   173,   157,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   188,   189,   154,   166,   147,   210,   205,
     191,   148,   138,    97,   197,   211,    80,    98,    40,    41,
      42,    43,    44,   134,     1,   213,     2,    36,     3,    22,
     116,     4,   138,     5,   144,    81,    59,   208,    45,   163,
      46,    47,   164,   151,   232,    29,    61,   233,    62,   157,
       1,    63,     2,   152,     3,    64,    65,     4,    66,     5,
      49,    50,    51,    52,     1,    12,     2,   220,     3,   159,
     214,     4,   223,     5,   137,   138,    59,   138,    34,   162,
      35,    59,   225,   226,   141,   192,   142,    40,    41,    42,
      43,    44,     1,     1,     2,     2,     3,     3,   203,     4,
       4,     5,     5,   206,    15,    59,   208,    45,   172,    46,
      47,   199,   202,   200,    29,   139,   156,    62,   142,     1,
      63,     2,   215,     3,    64,    65,     4,    66,     5,    49,
      50,    51,    52,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,   109,   110,   111,
     112,   113,   114,    45,   216,    46,    47,   190,   138,   204,
      29,   217,    45,    62,    46,    47,    63,   218,   229,    48,
      64,    65,   230,    66,   231,    49,    50,    51,    52,    40,
      41,    42,    43,    44,    49,    50,    51,    52,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   234,    38,    45,
     155,    46,    47,   201,   153,    40,    41,    42,    43,    44,
     224,     1,   167,     2,   140,     3,    23,     0,     4,     0,
       5,    49,    50,    51,    52,    45,     0,    46,    47,     0,
      97,     0,    48,   207,    98,    40,    41,    42,    43,    44,
     123,   124,   125,   126,    -1,    -1,     0,    49,    50,    51,
      52,     0,     0,     0,    12,    45,     0,    46,    47,     0,
      97,     0,    48,   235,    98,    40,    41,    42,    43,    44,
       0,     0,     0,   156,   192,   142,     0,    49,    50,    51,
      52,     0,     1,     0,     2,    45,     3,    46,    47,     4,
      97,     5,    48,     0,    98,    40,    41,    42,    43,    87,
      40,    41,    42,    43,    44,     0,     0,    49,    50,    51,
      52,     0,     0,     0,     0,    45,     0,    46,    47,     0,
      45,    88,    46,    47,     0,     0,     0,     0,     0,     0,
     135,    40,    41,    42,    43,    44,     0,    49,    50,    51,
      52,     0,    49,    50,    51,    52,    40,    41,    42,    43,
     195,    45,     0,    46,    47,   168,     0,    40,    41,    42,
      43,    44,     0,     0,     0,     0,    45,     0,    46,    47,
       0,     0,   196,    49,    50,    51,    52,    45,     0,    46,
      47,     0,     0,     0,   204,     0,     0,     0,    49,    50,
      51,    52,    40,    41,    42,    43,   221,     0,     0,    49,
      50,    51,    52,    40,    41,    42,    43,    44,     0,     0,
       0,     0,    45,     0,    46,    47,     0,     0,   222,     0,
       0,     0,     0,    45,     0,    46,    90,     0,     0,    40,
      41,    42,    43,    44,    49,    50,    51,    52,     0,     0,
       0,    28,     0,     0,     0,    49,    50,    51,    52,    45,
      29,    46,    47,     0,   160,     1,     0,     2,     0,     3,
       0,     0,     4,     0,     5,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,   174,   175,     0,     0,     0,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,   219,
       0,     0,     0,    29,   129,   130,   131,     1,     1,     2,
       2,     3,     3,     0,     4,     4,     5,     5
};

static const yytype_int16 yycheck[] =
{
      28,    28,    34,    20,     7,    12,    56,    35,    18,    47,
       7,    40,    41,     0,   164,     7,     7,    47,     7,    29,
      48,     8,     9,    33,    27,    18,     7,    56,    31,    26,
      26,    18,   213,   214,    26,    26,    66,    28,     3,     4,
      33,    33,    29,    29,   144,    26,    33,    28,    34,    46,
      46,    27,    90,   234,    46,    46,    94,   157,    34,    27,
      90,    26,    72,    28,    26,    21,    28,    32,    97,    82,
     120,   121,   122,   101,   101,    82,    33,   107,   106,    82,
      33,    34,    95,   233,    46,    72,    26,   115,    95,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   133,   134,    27,    21,    27,    27,   159,
     138,    34,    34,    28,   142,    34,    27,    32,     3,     4,
       5,     6,     7,    26,    35,    27,    37,   144,    39,     0,
     159,    42,    34,    44,   141,    46,   164,   164,    23,    31,
      25,    26,    34,    29,    31,    30,    31,    34,    33,   156,
      35,    36,    37,    29,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    35,     7,    37,   199,    39,    27,
      27,    42,   200,    44,    33,    34,   204,    34,    26,    46,
      28,   209,   209,   211,    26,    27,    28,     3,     4,     5,
       6,     7,    35,    35,    37,    37,    39,    39,    27,    42,
      42,    44,    44,    29,    46,   233,   233,    23,    46,    25,
      26,    26,    46,    28,    30,    31,    26,    33,    28,    35,
      36,    37,    27,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     3,     4,     5,     6,     7,    10,    11,
      12,    13,     3,     4,     5,     6,     7,    16,    17,    18,
      19,    20,    21,    23,    27,    25,    26,    33,    34,    30,
      30,    29,    23,    33,    25,    26,    36,    29,    27,    30,
      40,    41,    29,    43,    29,    45,    46,    47,    48,     3,
       4,     5,     6,     7,    45,    46,    47,    48,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    38,    27,    23,
      94,    25,    26,   148,    90,     3,     4,     5,     6,     7,
     204,    35,   102,    37,    72,    39,     9,    -1,    42,    -1,
      44,    45,    46,    47,    48,    23,    -1,    25,    26,    -1,
      28,    -1,    30,    31,    32,     3,     4,     5,     6,     7,
      10,    11,    12,    13,    14,    15,    -1,    45,    46,    47,
      48,    -1,    -1,    -1,     7,    23,    -1,    25,    26,    -1,
      28,    -1,    30,    31,    32,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    26,    27,    28,    -1,    45,    46,    47,
      48,    -1,    35,    -1,    37,    23,    39,    25,    26,    42,
      28,    44,    30,    -1,    32,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    -1,    -1,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,    -1,
      23,    29,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,     3,     4,     5,     6,     7,    -1,    45,    46,    47,
      48,    -1,    45,    46,    47,    48,     3,     4,     5,     6,
       7,    23,    -1,    25,    26,    27,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    23,    -1,    25,    26,
      -1,    -1,    29,    45,    46,    47,    48,    23,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    45,    46,
      47,    48,     3,     4,     5,     6,     7,    -1,    -1,    45,
      46,    47,    48,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,     3,
       4,     5,     6,     7,    45,    46,    47,    48,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    45,    46,    47,    48,    23,
      30,    25,    26,    -1,    97,    35,    -1,    37,    -1,    39,
      -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,   118,   119,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    27,
      -1,    -1,    -1,    30,    22,    23,    24,    35,    35,    37,
      37,    39,    39,    -1,    42,    42,    44,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    37,    39,    42,    44,    61,    62,    65,    90,
      91,    92,     7,    26,    33,    46,    63,    64,    67,    68,
      69,    62,     0,    91,    69,    67,    33,    34,    21,    30,
      61,    62,    83,    93,    26,    28,    68,    27,    64,    67,
       3,     4,     5,     6,     7,    23,    25,    26,    30,    45,
      46,    47,    48,    50,    51,    53,    54,    55,    56,    57,
      77,    31,    33,    36,    40,    41,    43,    57,    59,    61,
      82,    83,    84,    85,    86,    87,    88,    89,    61,    83,
      27,    46,    62,    70,    71,    72,    73,     7,    29,    57,
      26,    53,    53,    59,    65,    66,    74,    28,    32,    77,
      78,    79,    80,    81,     3,     4,    26,    28,    32,    16,
      17,    18,    19,    20,    21,    58,    53,    55,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    22,
      23,    24,    33,    26,    26,    33,    59,    33,    34,    31,
      85,    26,    28,    67,    69,    75,    76,    27,    34,    27,
      34,    29,    29,    74,    27,    66,    26,    69,    75,    27,
      56,    60,    46,    31,    34,    77,    21,    81,    27,    52,
      57,    59,    46,    57,    56,    56,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    59,    59,
      33,    57,    27,    70,    75,     7,    29,    57,    76,    26,
      28,    72,    46,    27,    30,    55,    29,    31,    77,    79,
      27,    34,    29,    27,    27,    27,    27,    29,    29,    27,
      70,     7,    29,    57,    78,    77,    57,    82,    82,    27,
      29,    29,    31,    34,    38,    31,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    78,
      78,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     3,     4,     4,     3,     4,     4,     3,
       1,     2,     1,     1,     3,     2,     2,     1,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       3,     4,     2,     3,     3,     4,     1,     3,     4,     1,
       2,     3,     4,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     2,     3,     1,     2,     1,     1,     1,
       2,     5,     7,     5,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     1,     2
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

#line 1925 "parser.c"

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

#line 315 "parser.y"


int main(void) {
    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
    } else {
        printf("PARSE FAILED!\n");
    }
    return 0;
}

void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}
