

%{
	
	#include <stdlib.h>

	int 	Lineno;
	int     wflag;

	#include<string.h>
	#include "../include/y.tab.h"
	void yyerror(char* s);
%}

%option noyywrap
digit	[0-9]
letter	[a-zA-Z]

%%
main	            			{}
					
return 							{}
begin							{;}
end								{;}

read							{return READ;}

write							{return WRITE;}	

integer							{return T_INT;}

boolean							{return T_BOOL;}

begindecl						{return DECL;}

enddecl							{return ENDDECL;}

{digit}+						{ yylval.num=atoi(yytext); return NUM; }

{letter}({letter}|{digit})*		{ yylval.id=strdup(yytext); return VAR; }

[-+*/=()><;,\{\}\[\]\%]         {return yytext[0];}
			
["]                             { return yytext[0];}

"\\n"                           {;}
\n								{;}

[ \t]							{;}

.								{yyerror("ERROR_: invalid input\n");}

%%

