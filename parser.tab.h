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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    WORD = 258,                    /* WORD  */
    STRING = 259,                  /* STRING  */
    QUERY = 260,                   /* QUERY  */
    RESULT_OF_QUERY = 261,         /* RESULT_OF_QUERY  */
    EXEC = 262,                    /* EXEC  */
    IF = 263,                      /* IF  */
    TOKEN_BEGIN = 264,             /* TOKEN_BEGIN  */
    END = 265,                     /* END  */
    FOR = 266,                     /* FOR  */
    IN = 267,                      /* IN  */
    EMPTY = 268,                   /* EMPTY  */
    NOT_EMPTY = 269,               /* NOT_EMPTY  */
    URL_EXISTS = 270,              /* URL_EXISTS  */
    UNION = 271,                   /* UNION  */
    DIFFERENCE = 272,              /* DIFFERENCE  */
    INTERSECTION = 273,            /* INTERSECTION  */
    OR = 274,                      /* OR  */
    PLUS = 275,                    /* PLUS  */
    MINUS = 276,                   /* MINUS  */
    STAR = 277,                    /* STAR  */
    ASSIGN = 278,                  /* ASSIGN  */
    SEMICOLON = 279,               /* SEMICOLON  */
    COMMA = 280,                   /* COMMA  */
    COLON = 281,                   /* COLON  */
    LANGLE = 282,                  /* LANGLE  */
    RANGLE = 283,                  /* RANGLE  */
    LBRACKET = 284,                /* LBRACKET  */
    RBRACKET = 285,                /* RBRACKET  */
    LPAREN = 286,                  /* LPAREN  */
    RPAREN = 287,                  /* RPAREN  */
    TO = 288,                      /* TO  */
    UNKNOWN = 289                  /* UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "parser.y"

    struct Cvor* CvorPokazivac;

#line 102 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
