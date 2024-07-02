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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    INCREMENT = 258,               /* INCREMENT  */
    DECREMENT = 259,               /* DECREMENT  */
    PLUS = 260,                    /* PLUS  */
    MINUS = 261,                   /* MINUS  */
    TIMES = 262,                   /* TIMES  */
    OVER = 263,                    /* OVER  */
    GREATER_THAN = 264,            /* GREATER_THAN  */
    LESS_THAN = 265,               /* LESS_THAN  */
    GREATER_THAN_OR_EQUAL = 266,   /* GREATER_THAN_OR_EQUAL  */
    LESS_THAN_OR_EQUAL = 267,      /* LESS_THAN_OR_EQUAL  */
    EQUALS = 268,                  /* EQUALS  */
    NOT_EQUALS = 269,              /* NOT_EQUALS  */
    ADD_ASSIGN = 270,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 271,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 272,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 273,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 274,              /* MOD_ASSIGN  */
    ASSIGNMENT = 275,              /* ASSIGNMENT  */
    LOGICAL_AND = 276,             /* LOGICAL_AND  */
    ADDRESS = 277,                 /* ADDRESS  */
    LOGICAL_OR = 278,              /* LOGICAL_OR  */
    LOGICAL_NOT = 279,             /* LOGICAL_NOT  */
    OPEN_PARENTHESES = 280,        /* OPEN_PARENTHESES  */
    CLOSE_PARENTHESES = 281,       /* CLOSE_PARENTHESES  */
    OPEN_BRACKET = 282,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 283,           /* CLOSE_BRACKET  */
    OPEN_KEYS = 284,               /* OPEN_KEYS  */
    CLOSE_KEYS = 285,              /* CLOSE_KEYS  */
    DOT = 286,                     /* DOT  */
    SEMICOLON = 287,               /* SEMICOLON  */
    COMMA = 288,                   /* COMMA  */
    AUTO = 289,                    /* AUTO  */
    BREAK = 290,                   /* BREAK  */
    CHAR = 291,                    /* CHAR  */
    CONST = 292,                   /* CONST  */
    CONTINUE = 293,                /* CONTINUE  */
    DOUBLE = 294,                  /* DOUBLE  */
    ELSE = 295,                    /* ELSE  */
    ENUM = 296,                    /* ENUM  */
    EXTERN = 297,                  /* EXTERN  */
    FLOAT = 298,                   /* FLOAT  */
    WHILE = 299,                   /* WHILE  */
    IF = 300,                      /* IF  */
    INT = 301,                     /* INT  */
    LONG = 302,                    /* LONG  */
    REGISTER = 303,                /* REGISTER  */
    RETURN = 304,                  /* RETURN  */
    SHORT = 305,                   /* SHORT  */
    SIGNED = 306,                  /* SIGNED  */
    SIZEOF = 307,                  /* SIZEOF  */
    STATIC = 308,                  /* STATIC  */
    STRUCT = 309,                  /* STRUCT  */
    TYPEDEF = 310,                 /* TYPEDEF  */
    UNION = 311,                   /* UNION  */
    UNSIGNED = 312,                /* UNSIGNED  */
    VOID = 313,                    /* VOID  */
    VOLATILE = 314,                /* VOLATILE  */
    STRING = 315,                  /* STRING  */
    ID = 316,                      /* ID  */
    INT_NUMBER = 317,              /* INT_NUMBER  */
    REAL_NUMBER = 318              /* REAL_NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
