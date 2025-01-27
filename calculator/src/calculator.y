%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
int variables[56];
int getVariable(char variable);
void setVariable(char variable, int value);
int yylex();
%}


%union {
    char variable;
    int number;
}
%start list
%token <number> NUMBER
%token <variable> IDENTIFIER
//%token '\n'
%type <number> list expr
%type <number> assignment
// %define parse.error verbose
%%

list:	  /* nothing */
    | list assignment '\n' {printf("%d\n", $2);}
	| list expr '\n'    {printf("%d\n", $2);}
    | assignment '\n' { printf("%d\n", $1); }
	| expr '\n' { printf("%d\n", $1); }
    
	;

assignment: IDENTIFIER '=' expr {setVariable($1, $3); $$ = $3;} ;

expr:	  NUMBER	{ $$ = $1; }
    |    IDENTIFIER	{ $$ = getVariable($1); }
	| expr '+' expr	{ $$ = $1 + $3; }
	| expr '-' expr	{ $$ = $1 - $3; }
	| expr '*' expr	{ $$ = $1 * $3; }
	| expr '/' expr	{ $$ = $1 / $3; }
	| '(' expr ')'	{ $$ = $2; }
	;

%%


int calculateVariableId(char variable){
    if('a' <= variable && variable <= 'z'){
        return 26 + (variable - 'a');
    }
    else if('A' <= variable && variable <= 'Z'){
        return variable - 'A';
    }
    return -1;
}

int getVariable(char variable){
    int id = calculateVariableId(variable);
    return variables[id];
}

void setVariable(char variable, int value){
    int id = calculateVariableId(variable);
    variables[id] = value;
}


int main(){
    for(int i=0; i<56; i++){
        variables[i] = 0;
    }

    return yyparse();
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 