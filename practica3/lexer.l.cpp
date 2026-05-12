%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%%

[0-9]+"."[0-9]+ { yylval.val = atof(yytext); return NUM; }
[0-9]+          { yylval.val = atof(yytext); return NUM; }
[a-zA-Z]+       { yylval.id = strdup(yytext); return ID; }

"+"      { return MAS; }
"-"      { return MENOS; }
"*"      { return MULT; }
"/"      { return DIV; }
"%"      { return MOD; }
"("      { return PARI; }
")"      { return PARD; }
"="      { return ASIG; }
"\n"     { return '\n'; }

[ \t]    ; /* Ignorar espacios */

.        { printf("Caracter invalido: %s\n", yytext); }

%%

int yywrap() { return 1; }
