

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
begin							{return BEG;}
end								{return END;}

read							{return READ;}

write							{return WRITE;}	

if								{return IF;}	

then							{return THEN;}	

else							{return ELSE;}	

endif							{return ENDIF;}	

for								{return FOR;}	

integer							{return T_INT;}

boolean							{return T_BOOL;}

decl							{return DECL;}

enddecl							{return ENDDECL;}

break 							{ return BREAK; }

continue						{return CONTINUE;}

[-+*/=()><;,\{\}\[\]\%]         {return yytext[0];}

">="							{ return GREATERTHANOREQUAL; }
"<="							{ return LESSTHANOREQUAL; }
"=="							{ return EQUALEQUAL; }
"!="							{ return NOTEQUAL; }

{digit}+						{ yylval.num=atoi(yytext); return NUM; }

{letter}({letter}|{digit})*		{ yylval.id=strdup(yytext); return VAR; }
			
["]                             { return yytext[0];}


"\\n"                           {;}
\n								{;}

[ \t]							{;}

.								{yyerror("ERROR_: invalid input\n");}

%%

