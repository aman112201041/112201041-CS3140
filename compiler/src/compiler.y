

%{	
	
	int yylex();
	void yyerror( char* );

	#include <bits/stdc++.h>
	#include <iostream>

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	using namespace std;
	#include "../include/dataTypes.hpp"
	#include "../include/printTree2.hpp"
	#include "../include/executeTree.hpp"

	#include "../include/code_to_mips.hpp"

	
	//string var_type = "NULL";
	enum _DATA_TYPES_ var_type;
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

%token BREAK CONTINUE
%token INCREMENT


%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left '+' '-'
%left '*' '/'
%left '%'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT

%start START

%token <num> NUM
%token <id> VAR 

%type <tree> Ldecl_sec Ldecl_list Ldecl Lid_list Lid
%type <tree> var_expr expr assign_stmt statement stmt_list write_stmt cond_stmt Statement_Sec 
%type <tree> var_expr_list expr_list read_stmt
%type <tree> START

%%

	START:	Ldecl_sec Statement_Sec				{
												node* codeTree = createTop();

												pushChildNode(codeTree, $1);
												
												node* StmntList = $2;
												pushChildNode(codeTree, StmntList);

												print_tree(codeTree);

												compile_tree(codeTree);

												execute_tree(codeTree);

												print_symbol_table();
											}
			
	
	Statement_Sec:	BEG stmt_list END		{
												node* StmntList = createStmntList();
												pushChildNode(StmntList, $2);
												$$ = StmntList;
											}

	Ldecl_sec:	DECL Ldecl_list ENDDECL		{
												tempNode = createDecl();
												pushChildNode(tempNode, $2);
												$$ = tempNode;
											}
		;

	Ldecl_list:		Ldecl					{$$ = $1;}
				|	Ldecl Ldecl_list		{pushNextNode($1, $2); $$ = $1; }
		;

	Ldecl	:	type Lid_list ';'			{ 
												$$=createLdecl_list();
												pushChildNode($$, createKeyword("dataType", var_type));
												pushChildNode($$, $2);
											}
		;

	type	:	T_INT						{ var_type = _INT_; }
			|	T_BOOL						{ var_type = _BOOLEAN_; }
		;

	Lid_list:	Lid							{$$ = $1;}
		|	Lid ',' Lid_list				{pushNextNode($1, $3); $$ = $1;}
		;
		
	Lid	:	VAR								{ 
												$$ = createVar($1);
											}
		|	Lid '[' NUM ']'					{
												$$ = $1;
												pushChildNode($$, createNum($3));
											}
		;

	stmt_list:	statement stmt_list				{$$ = createStatement(); pushNextNode($$, $2); pushChildNode($$, $1);}
		|		/* NULL */						{$$ = NULL;}
		;

	statement:	assign_stmt  ';'				{ $$ = $1; }
		|		read_stmt ';'					{ }
		|		write_stmt ';'					{ $$ = $1; }
		|		cond_stmt 						{ $$ = $1; }
		|		BREAK ';' 						{ $$ = createBreak(); }
		|		CONTINUE ';'					{ $$ = createContinue(); }
		;

/*
	read_stmt:	READ '(' var_expr ')' 					{  }
		;

	write_stmt:		WRITE '(' expr ')' 					{ 
															$$=createFunc("WRITE"); 
															// pushNextNode($$, $3);
															pushChildNode($$, createFunctionArgument());
															pushChildNode($$->child, $3);
														}
		;
*/

	read_stmt:	READ '(' var_expr_list ')' 					{ 
																$$=createFunc("READ");
																pushChildNode($$, createFunctionArgument());
																pushChildNode($$->child, $3);
															}
		;

	write_stmt:		WRITE '(' expr_list ')' 			{ 
															$$=createFunc("WRITE");
															pushChildNode($$, createFunctionArgument());
															pushChildNode($$->child, $3);
														}
		;
	
	assign_stmt:	var_expr '=' expr 		{ 
												//symbol_table[$1->name].second=evaluate($3); 
												$$=createAssign($1, $3);
											}
				|	var_expr INCREMENT		{ 
												$$=createAssign($1, createOp("+", createCopyNode($1), createNum(1))); 
												
											}
				|		/* NULL */			{ $$=createAssign(NULL, NULL); }
		;

	cond_stmt:	IF expr THEN stmt_list ENDIF 														{ 
																										$$ = createIfStmnt();
																										pushChildNode($$, $2);
																										
																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, $4);
																										pushChildNode($$, StmntList);
																									}
		|		IF expr THEN stmt_list ELSE stmt_list ENDIF 										{ 
																										$$ = createIfStmnt();
																										pushChildNode($$, $2);
																										
																										node* StmntList1 = createStmntList();
																										pushChildNode(StmntList1, $4);
																										pushChildNode($$, StmntList1);

																										node* StmntList2 = createStmntList();
																										pushChildNode(StmntList2, $6);
																										pushChildNode($$, StmntList2);
																									}
		|		FOR '(' assign_stmt  ';'  expr ';'  assign_stmt ')' '{' stmt_list '}'               { 
																										$$ = createForStmnt();
																										pushChildNode($$, $3);
																										pushChildNode($$, $5);
																										pushChildNode($$, $7);

																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, $10);

																										pushChildNode($$, StmntList);
																									}
		|		FOR '(' assign_stmt  ';'	';'	assign_stmt ')' '{' stmt_list '}'               	{ 
																										$$ = createForStmnt();
																										pushChildNode($$, $3);
																										
																										pushChildNode($$, createNum(1)); //for the empty expr. assuming true.

																										pushChildNode($$, $6);

																										node* StmntList = createStmntList();
																										pushChildNode(StmntList, $9);

																										pushChildNode($$, StmntList);
																									}
		;

	expr_list:	expr						{$$ = $1;}
		|	expr ',' expr_list				{pushNextNode($1, $3); $$ = $1;}
		;

	var_expr_list:	var_expr				{$$ = $1;}
		|	var_expr ',' var_expr_list			{pushNextNode($1, $3); $$ = $1;}
		;

	expr	:	NUM 						{ $$ = createNum($1); }
		|	'-' expr						{  $$ = createOp("-", $2, NULL); }
		|	var_expr						{ $$ = $1; }
		|	T								{ $$ = createNum(1); }
		|	F								{ $$ = createNum(0); }
		|	'(' expr ')'					{ $$ = $2; }

		|	expr '+' expr 					{ $$ = createOp("+", $1, $3); }
		|	expr '-' expr	 				{ $$ = createOp("-", $3, $1); }
		|	expr '*' expr 					{ $$ = createOp("*", $1, $3); }
		|	expr '/' expr 					{ $$ = createOp("/", $1, $3); }

		|	expr '>' expr 					{ $$ = createOp(">", $1, $3); }
		|	expr '<' expr 					{ $$ = createOp("<", $1, $3); }
		|	expr EQUALEQUAL expr 			{ $$ = createOp("==", $1, $3); }
		|	expr LESSTHANOREQUAL expr 		{ $$ = createOp("<=", $1, $3); }
		|	expr GREATERTHANOREQUAL expr 	{ $$ = createOp(">=", $1, $3); }
		|	expr NOTEQUAL expr 				{ $$ = createOp("!=", $1, $3); }
		
		|	var_expr INCREMENT				{ $$ = createOp("++", $1, NULL); }


		;
	
	
	var_expr:	VAR							{ $$ = createVar($1); }
		|	var_expr '[' expr ']'			{
												$$ = $1;
												pushChildNode($$, $3);
											}
		;


%%

void yyerror ( char  *s) {
	fprintf (stderr, "%s\n", s);
}

extern FILE *yyin;
extern FILE *yyout;

// void create_output_filename(const char *input, char *output) {
//     const char *dot = strrchr(input, '.');
//     if (dot) {
//         size_t base_len = dot - input;
//         strncpy(output, input, base_len);
//         output[base_len] = '\0';
//         strcat(output, ".s");
//     } else {
//         strcpy(output, input);
//         strcat(output, ".s");
//     }
// }

void create_output_filename(const char *input, char *output) {
    const char *slash = strrchr(input, '/');  // Find the last '/'
    const char *filename = (slash) ? slash + 1 : input; // If slash exists, move past it, else use input

    const char *dot = strrchr(filename, '.'); // Find last '.'
    if (dot) {
        size_t base_len = dot - filename;
        strncpy(output, filename, base_len);
        output[base_len] = '\0';
        strcat(output, ".s");
    } else {
        strcpy(output, filename);
        strcat(output, ".s");
    }
}

int main(int argc, char *argv[]){
	if (argc < 2) {
        fprintf(stderr, "Usage: %s <sourcefile>\n", argv[0]);
        return 1;
    }

    // Open input file
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }

    // Create and open output file
    char output_file[256];
    create_output_filename(argv[1], output_file);
    yyout = fopen(output_file, "w");
    if (!yyout) {
        perror("Error opening output file");
        fclose(yyin);
        return 1;
    }

	
	
	printf("Compiling %s -> %s\n", argv[1], output_file);
    


	int result = yyparse();

    fclose(yyin);
    fclose(yyout);

    return result;
}
