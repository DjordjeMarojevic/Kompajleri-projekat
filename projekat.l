%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"
    #include "cvor.h"

    extern int yylineno;
%}

%x LINE_COMMENT
%x MULTILINE_COMMENT

%%


[ \t\r]+                      { }

\n                              { yylineno++; }


"QUERY"                         {  Cvor* t = (Cvor*) kreirajCvor("QUERY"); yylval.CvorPokazivac = t;  return QUERY; }
"RESULT_OF_QUERY"               {  Cvor* t = (Cvor*) kreirajCvor("RESULT_OF_QUERY"); yylval.CvorPokazivac = t; return RESULT_OF_QUERY; }
"EXEC"                          {  Cvor* t = (Cvor*) kreirajCvor("EXEC"); yylval.CvorPokazivac = t; return EXEC; }
"IF"                            { Cvor* t = (Cvor*) kreirajCvor("IF"); yylval.CvorPokazivac = t; return IF; }
"BEGIN"                         { Cvor* t = (Cvor*) kreirajCvor("BEGIN");yylval.CvorPokazivac = t; return TOKEN_BEGIN; }
"END"                           { Cvor* t = (Cvor*) kreirajCvor("END"); yylval.CvorPokazivac = t;return END; }
"FOR"                           { Cvor* t = (Cvor*) kreirajCvor("FOR"); yylval.CvorPokazivac = t; return FOR; }
"IN"                            { Cvor* t = (Cvor*) kreirajCvor("IN"); yylval.CvorPokazivac = t; return IN; }
"EMPTY"                         { Cvor* t = (Cvor*) kreirajCvor("EMPTY"); yylval.CvorPokazivac = t; return EMPTY; }
"NOT_EMPTY"                     { Cvor* t = (Cvor*) kreirajCvor("NOT_EMPTY"); yylval.CvorPokazivac = t; return NOT_EMPTY; }
"URL_EXISTS"                    { Cvor* t = (Cvor*) kreirajCvor("URL_EXISTS"); yylval.CvorPokazivac = t; return URL_EXISTS; }

"++"                            { Cvor* t = (Cvor*) kreirajCvor("++"); yylval.CvorPokazivac = t; return UNION; }
"--"                            { Cvor* t = (Cvor*) kreirajCvor("--"); yylval.CvorPokazivac = t; return DIFFERENCE; }
"**"                            { Cvor* t = (Cvor*) kreirajCvor("**"); yylval.CvorPokazivac = t; return INTERSECTION; }

"|"                             { Cvor* t = (Cvor*) kreirajCvor("|"); yylval.CvorPokazivac = t; return OR; }
"+"                             { Cvor* t = (Cvor*) kreirajCvor("+"); yylval.CvorPokazivac = t; return PLUS; }
"-"                             { Cvor* t = (Cvor*) kreirajCvor("-"); yylval.CvorPokazivac = t; return MINUS; }
"*"                             { Cvor* t = (Cvor*) kreirajCvor("*"); yylval.CvorPokazivac = t; return STAR; }

"="                             { Cvor* t = (Cvor*) kreirajCvor("="); yylval.CvorPokazivac = t; return ASSIGN; }
";"                             { Cvor* t = (Cvor*) kreirajCvor(";"); yylval.CvorPokazivac = t; return SEMICOLON; }
","                             { Cvor* t = (Cvor*) kreirajCvor(","); yylval.CvorPokazivac = t; return COMMA; }
":"                             { Cvor* t = (Cvor*) kreirajCvor(":"); yylval.CvorPokazivac = t; return COLON; }

"<"                             { Cvor* t = (Cvor*) kreirajCvor("<"); yylval.CvorPokazivac = t; return LANGLE; }
">"                             { Cvor* t = (Cvor*) kreirajCvor(">"); yylval.CvorPokazivac = t; return RANGLE; }
"["                             { Cvor* t = (Cvor*) kreirajCvor("["); yylval.CvorPokazivac = t; return LBRACKET; }
"]"                             { Cvor* t = (Cvor*) kreirajCvor("]"); yylval.CvorPokazivac = t; return RBRACKET; }
"("                             { Cvor* t = (Cvor*) kreirajCvor("("); yylval.CvorPokazivac = t; return LPAREN; }
")"                             { Cvor* t = (Cvor*) kreirajCvor(")"); yylval.CvorPokazivac = t; return RPAREN; }

\"([^\"\\]|\\.)*\"              {
                                    Cvor* t = (Cvor*) kreirajCvor(yytext);  yylval.CvorPokazivac = t; 
                                    return STRING;
                                }

[a-zA-Z_][a-zA-Z0-9_]*          {
                                    Cvor* t = (Cvor*) kreirajCvor(yytext);  yylval.CvorPokazivac = t; 
                                    return WORD;
                                }

"//"                 { BEGIN(LINE_COMMENT); }
"/*"                 { BEGIN(MULTILINE_COMMENT); }

<LINE_COMMENT>\n      { yylineno++; BEGIN(INITIAL); }
<LINE_COMMENT>.       {}

<MULTILINE_COMMENT>"*/" { BEGIN(INITIAL); }
<MULTILINE_COMMENT>\n  { yylineno++; }
<MULTILINE_COMMENT>.   {}


.                               { return UNKNOWN; }
%%

int yywrap(void) {
    return 1;
}
