%{
#include "../include/y.tab.h"

int yylex();
%}
%%
[a-zA-Z]			   {yylval.variable = yytext[0]; return IDENTIFIER;}
[0-9]+                 {yylval.number = atoi(yytext); return NUMBER;}
[ \t]                ;
[-+=;\n()*/]           	   {return yytext[0];}
.                      {printf("unexpected character");}

%%
int yywrap (void) {return 1;}