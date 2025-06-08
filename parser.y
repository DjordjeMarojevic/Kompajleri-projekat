%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char* msg);
    int yylex();
    int postoji(char* id);
    void dodaj_u_tabelu(char* id, int tip, char* value);
    extern int yylineno;
    extern char* yytext;
    enum TipPromenljive { QUERY_TYPE = 0, RESULT_TYPE = 1 };

    struct Promenljiva {
    char* id;       // Variable/query name
    int tip;        // Optional: e.g., 0 = query, 1 = result, etc.
    char* value;    // Optional: string content or parsed result
};

    struct Promenljiva tabela_simbola[50];
    int brPromjenljivih = 0;


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
%type <str> set_operator

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
      QUERY query_name ASSIGN query SEMICOLON{

        dodaj_u_tabelu($2, QUERY_TYPE, $4);
      }
    | QUERY query_name ASSIGN list_of_queries SEMICOLON{
        dodaj_u_tabelu($2, QUERY_TYPE, strdup("LIST"));
    }
    | RESULT_OF_QUERY identifier SEMICOLON{
        dodaj_u_tabelu($2, RESULT_TYPE, strdup(""));
    }
;

commands:
      command
    | commands command
;

command:
      EXEC query_name SEMICOLON
    | IF condition TOKEN_BEGIN commands END
    | FOR identifier IN list_of_queries TOKEN_BEGIN commands END {
        dodaj_u_tabelu($2, RESULT_TYPE, strdup(""));    
    }
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
      UNION         { $$ = strdup("++"); }
    | DIFFERENCE    { $$ = strdup("--"); }
    | INTERSECTION  { $$ = strdup("**"); }
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

int postoji(char* id){
    int i = 0;

    for(i=0; i< brPromjenljivih; i++){
        struct Promenljiva trenutno = tabela_simbola[i];
        if(strcmp(trenutno.id,id) == 0){
            return i;
        }
    }

    return -1;
}   

void dodaj_u_tabelu(char* id, int tip, char* value) {
    int idx = postoji(id);
    if (idx != -1) {
        tabela_simbola[idx].tip = tip;
        if (tabela_simbola[idx].value)
            free(tabela_simbola[idx].value);
        tabela_simbola[idx].value = strdup(value);
        return;
    }

    if (brPromjenljivih >= 50) {
        fprintf(stderr, "Previše promenljivih!\n");
        exit(1);
    }

    tabela_simbola[brPromjenljivih].id = strdup(id);
    tabela_simbola[brPromjenljivih].tip = tip;
    tabela_simbola[brPromjenljivih].value = strdup(value);
    brPromjenljivih++;
}

void ispisi_tabelu() {
    printf("\nTABELA PROMENLJIVIH:\n");
    for (int i = 0; i < brPromjenljivih; i++) {
        printf("  %s (tip %d): %s\n", tabela_simbola[i].id, tabela_simbola[i].tip, tabela_simbola[i].value);
    }
}


int main(){
    int res = yyparse();
    if(res == 0) {
        printf("Ulaz je ispravan\n");
        ispisi_tabelu();
    } else {
        printf("Ulaz nije ispravan\n");
    }
    return 0;
}
