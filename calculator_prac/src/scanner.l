%{
#include "../include/calculator.h"
%}

%%
"+"	return ADD;
"-"	return SUB;
"*"	return MUL;
"/"	return DIV;
[0-9]*	return NUM;
[ \n\t]	;
.	printf("invalid input");
%%

int yywrap(void){
	return 1;
}
