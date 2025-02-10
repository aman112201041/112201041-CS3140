%{
#include "y.tab.h"
void yyerror(char* s);
%}

%%

[0-9]+     {yylval.num = atoi(yytext); return NUMBER;}
[a-zA-Z]        {yylval.id = yytext[0]; return IDENTIFIER;}
[-+*/()\n=]      {return yytext[0];}
[ \t]
.               {yyerror("invalid sytax.");}

%%

int yywrap(void){
    return 1;
}