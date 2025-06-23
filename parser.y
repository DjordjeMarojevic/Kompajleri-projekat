%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cvor.h"
#include "red.h"

void yyerror(const char* msg);
int yylex();
int postoji(char* id);
void dodaj_u_tabelu(char* id, int tip, char* value);
extern int yylineno;
extern char* yytext;
Cvor* korijen;

enum TipPromenljive { QUERY_TYPE = 0, RESULT_TYPE = 1 };

struct Promenljiva {
    char* id;
    int tip;
    char* value;
};

struct Promenljiva tabela_simbola[50];
int brPromjenljivih = 0;
%}

%union {
    struct Cvor* CvorPokazivac;
}

%token <CvorPokazivac> WORD STRING
%token <CvorPokazivac> QUERY RESULT_OF_QUERY EXEC IF TOKEN_BEGIN END FOR IN
%token <CvorPokazivac> EMPTY NOT_EMPTY URL_EXISTS
%token <CvorPokazivac> UNION DIFFERENCE INTERSECTION
%token <CvorPokazivac> OR PLUS MINUS STAR
%token <CvorPokazivac> ASSIGN SEMICOLON COMMA COLON
%token <CvorPokazivac> LANGLE RANGLE LBRACKET RBRACKET LPAREN RPAREN
%token <CvorPokazivac> UNKNOWN

%type <CvorPokazivac> identifier query_name KEY VALUE TERM term terms query directive operator set_operator assign_command
%type <CvorPokazivac> declarations commands declaration command query_list list_of_queries condition


%start program

%left OR

%%

program:
    declarations commands
    {
        dodajSina(korijen,$1);
        dodajSina(korijen,$2);
    }
;

declarations:
      declaration {$$ = kreirajCvor("Declarations"); dodajSina($$,$1);}
    | declarations declaration {$$ = $1; dodajSina($$,$2);}
;

declaration:
      QUERY query_name ASSIGN query SEMICOLON
      {

          int len = strlen("QueryDeclaration") + strlen($2->vrijednost) + 4;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "QueryDeclaration(%s)", $2->vrijednost);
          
          Cvor* temp = kreirajCvor(tekst);

            
          $$ = temp;
          dodajSina(temp,$1);
          dodajSina($1,$4);
           
          
          free(tekst);
          
          dodaj_u_tabelu($2->vrijednost, QUERY_TYPE, $4->vrijednost);
      }
    | QUERY query_name ASSIGN list_of_queries SEMICOLON
      {
          int len = strlen("QueryDeclaration") + strlen($2->vrijednost) + 4;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "QueryDeclaration(%s)", $2->vrijednost);
          
          Cvor* temp = kreirajCvor(tekst);


          $$ = temp;
          dodajSina(temp,$4);

          dodaj_u_tabelu($2->vrijednost, QUERY_TYPE, strdup("LIST"));

      }
    | RESULT_OF_QUERY identifier SEMICOLON
      {
          int len = strlen("ResultOfQueryDeclaration") + strlen($2->vrijednost) + 4;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "ResultOfQueryDeclaration(%s)", $2->vrijednost);

          Cvor* temp = kreirajCvor(tekst);

          $$ = temp;
          dodaj_u_tabelu($2->vrijednost, RESULT_TYPE, strdup(""));
      }
;

commands:
      command {$$ = kreirajCvor("Commands"); dodajSina($$,$1);}
    | commands command {$$ = $1; dodajSina($1,$2);}
;

command:
      EXEC query_name SEMICOLON {
        int len = strlen("ExecCommand()") + strlen($2->vrijednost) + 2;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "ExecCommand(%s)", $2->vrijednost);

        Cvor* temp = kreirajCvor(tekst);
        $$ = temp;
        free(tekst); 
    }
    | IF condition TOKEN_BEGIN commands END{

        /*int len = strlen("If(condition:)") + strlen($2->vrijednost) + 2;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "ForCommand(iteroator:%s)", $2->vrijednost);

        Cvor* temp = kreirajCvor(tekst);*/

        if($2 != NULL){
            dodajSina($1,$2);
            dodajSina($1,$4);
        }

        $$ = $1;

    }
    | FOR identifier IN list_of_queries TOKEN_BEGIN commands END
      {
          int len = strlen("ForCommand(iterator:)") + strlen($2->vrijednost) + 2;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "ForCommand(iteroator:%s)", $2->vrijednost);

          Cvor* temp = kreirajCvor(tekst);

          $$ = temp;
          Cvor* iterable = kreirajCvor("iterable");
          Cvor* body = kreirajCvor("Body");
          dodajSina(temp,iterable);
          dodajSina(body, $6);
          dodajSina(temp,body);
          
          dodajSina(iterable,$4);  
          

          dodaj_u_tabelu($2->vrijednost, RESULT_TYPE, strdup(""));
      }
    | assign_command SEMICOLON
;

assign_command:
      identifier ASSIGN EXEC query_name {



        $$ = kreirajCvor("AsssignCommand");
        
        
        int len = strlen($1->vrijednost) + strlen("Target:")+ 3;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "Target:%s", $1->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        dodajSina($$,temp); 
        free(tekst);

        
        int len1 = strlen($4->vrijednost) + strlen("ExecCommand") + 4;
        char* tekst1 = (char*)malloc(len1);
        snprintf(tekst1, len1, "ExecCommand(%s)", $4->vrijednost);

        Cvor* temp1 = kreirajCvor(tekst1);
        dodajSina($$,temp1);
        free(tekst1);
    }
    | identifier ASSIGN identifier set_operator identifier{

        $$ = kreirajCvor("AsssignCommand");
        int len = strlen($1->vrijednost) + strlen("Target:")+ 3;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "Target:%s", $1->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        dodajSina($$,temp); 
        free(tekst);

        int len1 = strlen($4->vrijednost) + strlen("SetOperation") + 4;
        char* tekst1 = (char*)malloc(len1);
        snprintf(tekst1, len1, "SetOperation(%s)", $4->vrijednost);

        Cvor* temp1 = kreirajCvor(tekst1);
        dodajSina($$,temp1);
        free(tekst1);
    }
;

condition:
      EMPTY LPAREN identifier RPAREN{
        
        int len = strlen($1->vrijednost) + strlen($3->vrijednost)+4;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "%s(%s)", $1->vrijednost, $3->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        
        if (postoji($3->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
            $$ = NULL;
        }
        else{
            int id = postoji($3->vrijednost);
            if (strcmp(tabela_simbola[id].value,"") == 0){
                $$ = temp;
            }
            else{
                $$ = NULL;
            }
        }
        

        free(tekst);
        
      }
    | NOT_EMPTY LPAREN identifier RPAREN{
        int len = strlen($1->vrijednost) + strlen($3->vrijednost)+ 4;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "%s(%s)", $1->vrijednost, $3->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        
        if (postoji($3->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
            $$ = NULL;
        }
        else{
            int id = postoji($3->vrijednost);
            if (strcmp(tabela_simbola[id].value,"") == 0){
                $$ = NULL;
            }
            else{
                $$ = temp;
            }
        }

        free(tekst);
    }
    | URL_EXISTS LPAREN identifier COMMA STRING RPAREN{

        int len = strlen($1->vrijednost) + strlen($3->vrijednost)+ strlen($5->vrijednost)+ 4;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "%s(%s,%s)", $1->vrijednost, $3->vrijednost, $5->vrijednost);
        Cvor* temp = kreirajCvor(tekst);

        
        
        $$ = temp;

        free(tekst);
    }
;

list_of_queries:
    LBRACKET query_list RBRACKET{
        $$ = $2;
    }
;

query_list:
      query_name{
        $$ = kreirajCvor($1->vrijednost);
      }
    | query_list COMMA query_name{
        
        int len = strlen($1->vrijednost) + strlen($3->vrijednost) + 5;
        char* combined = (char*)malloc(len);
        snprintf(combined, len, "[%s, %s]", $1->vrijednost, $3->vrijednost);

        $$ = kreirajCvor(combined);
        free(combined);
    }
;

query:
    LANGLE terms RANGLE
    {
        $$ = $2;
    }
    | query_name
    {
        if (postoji($1->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }
        $$ = kreirajCvor($1->vrijednost);
    }
;

terms:
      term
      {
          $$ = kreirajCvor($1->vrijednost);
      }
    | terms term{

        $$ = kreirajCvor("Juxtaposition");
        dodajSina($$,$1);
        dodajSina($$,$2);
        
}
    | terms OR terms
{
        $$ = kreirajCvor("Or");
        dodajSina($$, $1);  
        dodajSina($$, $3);  
}
;

term:
      TERM
      {
          $$ = $1;
      }
    | directive
      {
          $$ = $1;
      }
    | operator term
      {
          int len = strlen($1->vrijednost) + strlen($2->vrijednost) + 2;
          char* combined = (char*)malloc(len);
          snprintf(combined, len, "%s%s", $1->vrijednost, $2->vrijednost);
          $$ = kreirajCvor(combined);
      }
;

directive:
    KEY COLON VALUE
    {
        int len = strlen("Directive") +  strlen($1->vrijednost) + strlen($3->vrijednost) + 4;
        char* combined = (char*)malloc(len + 1);
        snprintf(combined, len + 1, "Directive(%s:%s)", $1->vrijednost, $3->vrijednost);
        $$ = kreirajCvor(combined);
        free(combined);
    }
;

//ne moram nista dolje

operator:
      PLUS     { $$ = $1;}
    | MINUS    { $$ = $1;}
    | STAR     { $$ = $1;}
;

set_operator:
      UNION         { $$ = $1;}
    | DIFFERENCE    { $$ = $1;}
    | INTERSECTION  { $$ = $1;}
;



identifier:
    WORD { $$ = $1; }
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

int postoji(char* id) {
    for (int i = 0; i < brPromjenljivih; i++) {
        if (strcmp(tabela_simbola[i].id, id) == 0)
            return i;
    }
    return -1;
}

void dodaj_u_tabelu(char* id, int tip, char* value) {
    int idx = postoji(id);
    if (idx != -1) {
        tabela_simbola[idx].tip = tip;
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

int main() {
    korijen = kreirajCvor("Program");
    int res = yyparse();
    if (res == 0) {
        printf("Ulaz je ispravan\n");
        ispisi_tabelu();
    } else {
        printf("Ulaz nije ispravan\n");
    }

    int cnt = 0;

    bool kraj = false;


    struct Red* red = malloc(sizeof(struct Red));
    int nivo = 0;

    inicijalizujRed(red);

    dodajURed(red,korijen);

    printf("Prvi nivo:\n");
   

    while(true) {
        if(red->glava == 0) {
            break;
        }
        struct Cvor* tmp = ukloniSPocetka(red);
        
        if(tmp->nivo > nivo) {
            printf("\n\n%d-ti Nivo:",tmp->nivo+1);
            printf("\n%s ",tmp->vrijednost);
            nivo++;
            
        }
        else {
            printf("%s ",tmp->vrijednost);
        }
    


        int cnt = 0;
        while(cnt < tmp->broj_sinova) {
            tmp->sinovi[cnt]->nivo = tmp->nivo + 1;
            dodajURed(red,tmp->sinovi[cnt]);
            cnt++;
        }
    }

    printf("\n");

    return 0;
}
