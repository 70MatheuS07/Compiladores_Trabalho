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
    PERCENT = 264,                 /* PERCENT  */
    GREATER_THAN = 265,            /* GREATER_THAN  */
    LESS_THAN = 266,               /* LESS_THAN  */
    GREATER_THAN_OR_EQUAL = 267,   /* GREATER_THAN_OR_EQUAL  */
    LESS_THAN_OR_EQUAL = 268,      /* LESS_THAN_OR_EQUAL  */
    EQUALS = 269,                  /* EQUALS  */
    NOT_EQUALS = 270,              /* NOT_EQUALS  */
    ADD_ASSIGN = 271,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 272,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 273,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 274,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 275,              /* MOD_ASSIGN  */
    ASSIGNMENT = 276,              /* ASSIGNMENT  */
    LOGICAL_AND = 277,             /* LOGICAL_AND  */
    ADDRESS = 278,                 /* ADDRESS  */
    LOGICAL_OR = 279,              /* LOGICAL_OR  */
    LOGICAL_NOT = 280,             /* LOGICAL_NOT  */
    OPEN_PARENTHESES = 281,        /* OPEN_PARENTHESES  */
    CLOSE_PARENTHESES = 282,       /* CLOSE_PARENTHESES  */
    OPEN_BRACKET = 283,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 284,           /* CLOSE_BRACKET  */
    OPEN_KEYS = 285,               /* OPEN_KEYS  */
    CLOSE_KEYS = 286,              /* CLOSE_KEYS  */
    SEMICOLON = 287,               /* SEMICOLON  */
    COMMA = 288,                   /* COMMA  */
    CHAR = 289,                    /* CHAR  */
    CONTINUE = 290,                /* CONTINUE  */
    DOUBLE = 291,                  /* DOUBLE  */
    ELSE = 292,                    /* ELSE  */
    FLOAT = 293,                   /* FLOAT  */
    WHILE = 294,                   /* WHILE  */
    IF = 295,                      /* IF  */
    INT = 296,                     /* INT  */
    RETURN = 297,                  /* RETURN  */
    VOID = 298,                    /* VOID  */
    STRING = 299,                  /* STRING  */
    ID = 300,                      /* ID  */
    INT_NUMBER = 301,              /* INT_NUMBER  */
    REAL_NUMBER = 302              /* REAL_NUMBER  */
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
