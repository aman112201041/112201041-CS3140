

%{	
	
	int yylex();
	void yyerror( char* );

	#include <bits/stdc++.h>
	#include <iostream>
	using namespace std;
	#include "../include/dataTypes.hpp"
	#include "../include/printTree.hpp"

	map<string, pair<string, int> > symbol_table;
	string var_type = "NULL";
	struct node* tempNode;
%}

%union{
	int num;
	char* id;
	struct node* tree;
}

%token BEG END
%token T_INT T_BOOL
%token READ WRITE
%token DECL ENDDECL

%token IF THEN ELSE ENDIF
%token LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token WHILE DO ENDWHILE FOR 
%token T F 
%token MAIN RETURN


%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left '+' '-'
%left '*' '/'
%left '%'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT

%start LAB1
%type <id> str_expr 
%token <num> NUM
%token <id> VAR 

%type <tree> Ldecl_sec Ldecl_list Ldecl Lid_list Lid
%type <tree> var_expr expr assign_stmt statement stmt_list write_stmt

%%

	LAB1:	Ldecl_sec stmt_list				{
												print_Decl($1);
												print_stmt_list($2);
											}
			
	
		
	Ldecl_sec:	DECL Ldecl_list ENDDECL		{
												tempNode = createDecl();
												pushChildNode(tempNode, $2);
												$$ = tempNode;
											}
		;

	Ldecl_list:		Ldecl							{$$ = $1;}
				|	Ldecl Ldecl_list				{pushNextNode($1, $2); $$ = $1; }
		;

	Ldecl	:	type Lid_list ';'			{ $$=createLdecl_list(); pushChildNode($$, $2); }
		;

	type	:	T_INT						{ var_type = "int"; }
			|	T_BOOL						{ var_type = "bool"; }
		;

	Lid_list:	Lid							{$$ = $1;}
		|	Lid ',' Lid_list				{pushNextNode($1, $3); $$ = $1;}
		;
		
	Lid	:	VAR								{ 
												symbol_table[$1].first=var_type; 
												symbol_table[$1].second=0;
												$$ = createVar($1, 0);
											}
		;

	stmt_list:	/* NULL */					{$$ = NULL;}
		|	statement stmt_list				{$$ = createStatement(); pushNextNode($$, $2); pushChildNode($$, $1);}
		|	error ';' 						{$$ = NULL;}
		;

	statement:	assign_stmt  ';'			{ $$ = $1; }
		|	read_stmt ';'					{ }
		|	write_stmt ';'					{ $$ = $1; }
		|	cond_stmt 						{ }
		|	func_stmt ';'					{ }
		;

	read_stmt:	READ '(' var_expr ')' 					{  }
		;

	write_stmt:		WRITE '(' expr ')' 					{ $$=createFunc("WRITE"); pushNextNode($$, $3); }
				| 	WRITE '(''"' str_expr '"'')'      	{ printf("%s \n", $4);}

		;
	
	assign_stmt:	var_expr '=' expr 	{ symbol_table[$1->name].second=evaluate($3); $$=createAssign($1, $3);}
		;

	cond_stmt:	IF expr THEN stmt_list ENDIF 	{ 						}
		|	IF expr THEN stmt_list ELSE stmt_list ENDIF 	{ 						}
	        |    FOR '(' assign_stmt  ';'  expr ';'  assign_stmt ')' '{' stmt_list '}'                                             {                                                 }
		;
	
	func_stmt:	func_call 		{ 						}
		;
		
	func_call:	VAR '(' param_list ')'	{ 						   }
		;
		
	param_list:				
		|	param_list1		
		;
		
	param_list1:	para			
		|	para ',' param_list1	
		;

	para	:	expr			{ 						}
		;

	expr	:	NUM 						{ $$ = createNum($1); }
		|	'-' expr						{  $$ = createOp("-", NULL, $2); }
		|	var_expr						{ $$ = $1; }
		|	T								{ $$ = createNum(1); }
		|	F								{ $$ = createNum(0); }
		|	'(' expr ')'					{ $$ = $2; }

		|	expr '+' expr 					{ $$ = createOp("+", $1, $3); }
		|	expr '-' expr	 				{ $$ = createOp("-", $1, $3); }
		|	expr '*' expr 					{ $$ = createOp("*", $1, $3); }
		|	expr '/' expr 					{ $$ = createOp("/", $1, $3); }
		|	expr '%' expr 					{ 						}
		|	expr '<' expr					{ 						}
		|	expr '>' expr					{ 						}
		|	expr GREATERTHANOREQUAL expr				{ 						}
		|	expr LESSTHANOREQUAL expr	{  						}
		|	expr NOTEQUAL expr			{ 						}
		|	expr EQUALEQUAL expr	{ 						}
		|	LOGICAL_NOT expr	{ 						}
		|	expr LOGICAL_AND expr	{ 						}
		|	expr LOGICAL_OR expr	{ 						}
		|	func_call		{  }

		;
	str_expr :  VAR                   	{$$ = $1;}
                  | str_expr VAR   		{}
                ;
	
	var_expr:	VAR					{$$ = createVar($1, symbol_table[$1].second);}
		|	var_expr '[' expr ']'	{                                                 }
		;
%%
void yyerror ( char  *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(){
	return yyparse();
}
