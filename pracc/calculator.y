%{
#include <stdio.h>
#include <stdlib.h>
#include "dataTypes.h"

int yylex();
void yyerror(char* s);

int getVar(char var);
void setVar(char var, int val);

int variable_values[53];
%}

%union{
    int num;
    char id;
    struct node* ast;
}

%start line

%token <num> NUMBER
%token <id> IDENTIFIER

%left '+' '-'
%left '*' '/'
%right UMINUS
%nonassoc '(' ')'

%type <num> line 
%type <ast> expr assgnmnt

%%
line:    expr '\n'   {evaluateTree($1);}
    |   line expr '\n'  {evaluateTree($2);}
    |   assgnmnt '\n'  {printAssgn($1);}
    |   line assgnmnt '\n'  {printAssgn($2);}
    ;

assgnmnt: IDENTIFIER '=' expr   {setVar($1, eval($3)); $$ = createAssgn($1, $3);}

expr:   NUMBER  {$$ = createNum($1);}
    |   IDENTIFIER  {$$ = createVar($1, getVar($1));}
    |   expr '+' expr   {$$ = createOp('+', $1, $3);}
    |   expr '-' expr   {$$ = createOp('-', $1, $3);}
    |   expr '*' expr   {$$ = createOp('*', $1, $3);}
    |   expr '/' expr   {
            if($3 == 0){
                yyerror("DIVIDING BY ZERO.");
                $$ = NULL;
            }
            else {$$ = createOp('/', $1, $3);}
        }
    |   '(' expr ')'    {$$ = $2;}
    |   '-' expr %prec UMINUS   {$$ = createOp('-', NULL, $2);}

%%

int main(void){
    for(int i=0; i<53; i++){
        variable_values[i] = 0;
    }

    return yyparse();
}

int getVarId(char var){
    if('a'<=var && var<='z') return var-'a'+26;
    else if('A'<=var && var<='Z') return var-'A';
    return -1;
}

int getVar(char var){
    int id = getVarId(var);
    return variable_values[id];
}

void setVar(char var, int val){
    int id = getVarId(var);
    variable_values[id] = val;
}

void yyerror(char* s){
    fprintf(stderr, "ERROR: %s\n", s);
}