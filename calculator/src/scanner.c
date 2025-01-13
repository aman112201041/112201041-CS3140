#include <stdio.h>
#include <stdlib.h>
#include "../include/calculator.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
char ops[] = {'_', '+', '-', '*', '/', 'n', ' '};

int main(void){
	int token_num;
	int a, b, op;
	op = 0;

	int ans = 0;
	while(1){
		// printf("%d\n", token_num);
		token_num = yylex();
		// printf("%d\n", token_num);
		if(token_num == 0) {
			printf("ANS=%d", ans);
			printf("\nEND\n");
			return 0;
		}
		if(token_num == 5){
			if(op){
				
				b=atoi(yytext);
				switch(op){
					case ADD:
						ans = a+b;
						break;
					case SUB:
						ans = a-b;
						break;
					case MUL:
						ans = a*b;
						break;
					case DIV:
						ans = a/b;
						break;
					default:
						printf("INVALID INPUT!!!");
						return 1;
						break;
				}
				a = ans;
			}
			else a=atoi(yytext);
		}
		else{
			op = token_num;			
		}
		// printf("%d %c %d = %d\n\n", a, ops[op], b, ans);
	}
	
}
