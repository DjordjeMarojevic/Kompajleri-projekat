%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char* msg);
    int yylex();
    extern int yylineno;
    extern char* yytext;
%}

%union {
    char* str;
}

%token <str> WORD STRING
%token QUERY RESULT_OF_QUERY EXEC IF TOKEN_BEGIN END FOR IN
%token EMPTY NOT_EMPTY URL_EXISTS
%token UNION DIFFERENCE INTERSECTION
%token OR PLUS MINUS STAR
%token ASSIGN SEMICOLON COMMA COLON
%token LANGLE RANGLE LBRACKET RBRACKET LPAREN RPAREN
%token UNKNOWN

%type <str> identifier
%type <str> query_name
%type <str> KEY VALUE
%type <str> TERM
%type <str> term
%type <str> terms
%type <str> query
%type <str> directive
%type <str> operator

%start program

%left OR

%%

program:
    declarations commands
    {
        
    }
;

declarations:
      declaration
    | declarations declaration
;

declaration:
      QUERY query_name ASSIGN query SEMICOLON
    | QUERY query_name ASSIGN list_of_queries SEMICOLON
    | RESULT_OF_QUERY identifier SEMICOLON
;

commands:
      command
    | commands command
;

command:
      EXEC query_name SEMICOLON
    | IF condition TOKEN_BEGIN commands END
    | FOR identifier IN list_of_queries TOKEN_BEGIN commands END {}
    | assign_command SEMICOLON
;

assign_command:
      identifier ASSIGN EXEC query_name
    | identifier ASSIGN identifier set_operator identifier
;

condition:
      EMPTY LPAREN identifier RPAREN
    | NOT_EMPTY LPAREN identifier RPAREN
    | URL_EXISTS LPAREN identifier COMMA STRING RPAREN
;

list_of_queries:
    LBRACKET query_list RBRACKET
;

query_list:
      query
    | query_list COMMA query
;

query:
    LANGLE terms RANGLE
    {
        /* $2 is a <str> returned by terms */
        $$ = $2;
    }
    | identifier {/* ako je identifier u tabeli simbola i identifier je query, onda je ovo ok, u suprotnom nije ok*/}
;

terms:
      term
        { 
            /* Single term */ 
            $$ = $1; 
        }
    | terms term
        {
            /* Juxtaposition: higher precedence than OR
               e.g. "<a b | c>" → "(a b) | c" */
            char *buf = malloc(strlen($1) + strlen($2) + 2);
            sprintf(buf, "%s %s", $1, $2);
            $$ = buf;
        }
    | terms OR terms
        {
            /* OR is lower‐precedence */
            char *buf = malloc(strlen($1) + strlen($3) + 4);
            sprintf(buf, "%s | %s", $1, $3);
            $$ = buf;
        }
;

term:
      TERM
        {
            /* TERM token’s yylval.str (WORD or STRING) */
            $$ = $1;
        }
    | directive
        {
            /* directive already returned char* */
            $$ = $1;
        }
    | operator term
        {
            /* Unary operator, e.g. "+term" */
            char *buf = malloc(strlen($1) + strlen($2) + 1);
            sprintf(buf, "%s%s", $1, $2);
            $$ = buf;
        }
;

directive:
    KEY COLON VALUE
    {
        /* Build "KEY:VALUE" string */
        char *buf = malloc(strlen($1) + strlen($3) + 2);
        sprintf(buf, "%s:%s", $1, $3);
        $$ = buf;
    }
;

operator:
      PLUS     { $$ = strdup("+"); }
    | MINUS    { $$ = strdup("-"); }
    | STAR     { $$ = strdup("*"); }
;

set_operator:
      UNION         { /* “++” semantics, no $$ needed here */ }
    | DIFFERENCE    { /* “--” semantics */ }
    | INTERSECTION  { /* “**” semantics */ }
;

identifier:
    WORD { $$ = $1; printf("%s\n",$1);}
;

query_name:
    WORD { $$ = $1; }
;

KEY:
    WORD { $$ = $1; }
;

VALUE:
      WORD   { $$ = $1; }
    | STRING { $$ = $1; }
;

TERM:
      WORD   { $$ = $1; }
    | STRING { $$ = $1; }
;

%%

void yyerror(const char* msg) {
    fprintf(stderr, "Syntax error at line %d near '%s': %s\n", yylineno, yytext, msg);
}

int main(){
    int res = yyparse();
    if(res == 0) {
        printf("Ulaz je ispravan\n");
    } else {
        printf("Ulaz nije ispravan\n");
    }
    return 0;
}
