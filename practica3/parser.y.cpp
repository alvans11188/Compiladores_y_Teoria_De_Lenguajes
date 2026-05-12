%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void yyerror(const char *s);
int yylex();

/* Estructura simple para variables */
struct var {
    char* nombre;
    double valor;
} tabla[100];

int cuenta_vars = 0;

double obtener_valor(char* id) {
    for(int i=0; i<cuenta_vars; i++) {
        if(strcmp(tabla[i].nombre, id) == 0) return tabla[i].valor;
    }
    printf("Variable '%s' no definida. ", id);
    return 0;
}

void guardar_valor(char* id, double v) {
    for(int i=0; i<cuenta_vars; i++) {
        if(strcmp(tabla[i].nombre, id) == 0) {
            tabla[i].valor = v;
            return;
        }
    }
    tabla[cuenta_vars].nombre = id;
    tabla[cuenta_vars].valor = v;
    cuenta_vars++;
}
%}

%union {
    double val;
    char* id;
}

%token <val> NUM
%token <id> ID
%token MAS MENOS MULT DIV MOD PARI PARD ASIG
%type <val> expresion

%left MAS MENOS
%left MULT DIV MOD

%%

input:
    | input linea
;

linea:
    '\n'
    | expresion '\n' { printf("Resultado: %.2f\n", $1); }
    | ID ASIG expresion '\n' { guardar_valor($1, $3); printf("%s = %.2f\n", $1, $3); }
    | error '\n' { yyerrok; }
;

expresion:
    NUM                 { $$ = $1; }
    | ID                { $$ = obtener_valor($1); }
    | expresion MAS expresion   { $$ = $1 + $3; }
    | expresion MENOS expresion { $$ = $1 - $3; }
    | expresion MULT expresion  { $$ = $1 * $3; }
    | expresion DIV expresion   { 
        if($3 == 0) { yyerror("Division por cero"); $$ = 0; }
        else { $$ = $1 / $3; }
    }
    | expresion MOD expresion   { $$ = fmod($1, $3); }
    | PARI expresion PARD       { $$ = $2; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error sintactico\n");
}

int main() {
    printf("Calculadora Completa (Soporta variables, decimales y %%)\n");
    yyparse();
    return 0;
}
