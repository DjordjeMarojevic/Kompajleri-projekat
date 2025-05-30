%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char* msg);
    int yylex();
    
%}



%token QUERY RESULT_OF_QUERY EXEC IF TOKEN_BEGIN END FOR IN
%token EMPTY NOT_EMPTY URL_EXISTS
%token UNION DIFFERENCE INTERSECTION
%token OR PLUS MINUS STAR
%token ASSIGN SEMICOLON COMMA COLON
%token LANGLE RANGLE LBRACKET RBRACKET LPAREN RPAREN
%token STRING WORD
%token UNKNOWN


%start program

%type declarations
%type commands

%union {
    char* str;
    // Add more fields for AST nodes later
}

%%

program: declarations commands       {}
declarations: declaration | declarations declaration    {}
declaration: QUERY WORD ASSIGN query {}
query: LANGLE terms RANGLE {}
terms: term | terms term {}
term: TERM | directive | operator term | term OR term   {}
%%



void yyerror(const char* msg){
    printf("%s\n", msg);
}

int main(){



    int res = yyparse();
    if(res == 0){
        printf("Ulaz je ispravan\n");
    }
    else{
        printf("Ulaz nije ispravan\n");
    }

    return 0;
}
