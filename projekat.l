%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"

    extern int yylineno;
%}

%%


[ \t\r]+                      { /* skip */ }

\n                              { yylineno++; }

"//".*                          { /* skip entire line */ }

"/*"([^*]|\*+[^*/])*\*+"*/"    { /* skip entire multi‐line block */ }

"QUERY"                         { return QUERY; }
"RESULT_OF_QUERY"               { return RESULT_OF_QUERY; }
"EXEC"                          { return EXEC; }
"IF"                            { return IF; }
"BEGIN"                         { return TOKEN_BEGIN; }
"END"                           { return END; }
"FOR"                           { return FOR; }
"IN"                            { return IN; }
"EMPTY"                         { return EMPTY; }
"NOT_EMPTY"                     { return NOT_EMPTY; }
"URL_EXISTS"                    { return URL_EXISTS; }

"++"                            { return UNION; }
"--"                            { return DIFFERENCE; }
"**"                            { return INTERSECTION; }

"|"                             { return OR; }
"+"                             { return PLUS; }
"-"                             { return MINUS; }
"*"                             { return STAR; }

"="                             { return ASSIGN; }
";"                             { return SEMICOLON; }
","                             { return COMMA; }
":"                             { return COLON; }

"<"                             { return LANGLE; }
">"                             { return RANGLE; }
"["                             { return LBRACKET; }
"]"                             { return RBRACKET; }
"("                             { return LPAREN; }
")"                             { return RPAREN; }

\"([^\"\\]|\\.)*\"              {
                                    yylval.str = strdup(yytext);
                                    return STRING;
                                }

[a-zA-Z_][a-zA-Z0-9_]*          {
                                    yylval.str = strdup(yytext);
                                    return WORD;
                                }

.                               { return UNKNOWN; }
%%

int yywrap(void) {
    return 1;
}
