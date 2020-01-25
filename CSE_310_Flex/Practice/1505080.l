%option noyywrap

%{
//start of c code

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "1505080_SymbolTable.h"

int line_count = 1;
int lex_error = 0;

FILE *logout;
FILE *tokenout;


SymbolTable* symbolTable;

//end of c code
%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
ALPHANUMERIC [A-Za-z0-9]
NEWLINE \n


%%
{WHITESPACE}+ 	{	//do nothing
		}

{NEWLINE} {line_count++;}

"if"		{
			fprintf(tokenout,"<IF> ");
			fprintf(logout,"\nLine no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
		}
		
"else"		{
			fprintf(tokenout,"<ELSE> ");
			fprintf(logout,"\nLine no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);
		}

"while"		{
			fprintf(tokenout,"<WHILE> ");
			fprintf(logout,"\nLine no %d: TOKEN <WHILE> Lexeme %s found\n",line_count,yytext);	
		}

"for"		{
			fprintf(tokenout,"<FOR> ");
			fprintf(logout,"\nLine no %d: TOKEN <FOR> Lexeme %s found\n",line_count,yytext);	
		}

"do"		{
			fprintf(tokenout,"<DO> ");
			fprintf(logout,"\nLine no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);	
		}

"break"		{
			fprintf(tokenout,"<BREAK> ");
			fprintf(logout,"\nLine no %d: TOKEN <BREAK> Lexeme %s found\n",line_count,yytext);	
		}

"int"		{
			fprintf(tokenout,"<INT> ");
			fprintf(logout,"\nLine no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);	
		}

"char"		{
			fprintf(tokenout,"<CHAR> ");
			fprintf(logout,"\nLine no %d: TOKEN <CHAR> Lexeme %s found\n",line_count,yytext);	
		}

"float"		{
			fprintf(tokenout,"<FLOAT> ");
			fprintf(logout,"\nLine no %d: TOKEN <FLOAT> Lexeme %s found\n",line_count,yytext);	
		}

"double"		{
			fprintf(tokenout,"<DOUBLE> ");
			fprintf(logout,"\nLine no %d: TOKEN <DOUBLE> Lexeme %s found\n",line_count,yytext);	
		}

"void"		{
			fprintf(tokenout,"<VOID> ");
			fprintf(logout,"\nLine no %d: TOKEN <VOID> Lexeme %s found\n",line_count,yytext);	
		}

"return"	{
			fprintf(tokenout,"<RETURN> ");
			fprintf(logout,"\nLine no %d: TOKEN <RETURN> Lexeme %s found\n",line_count,yytext);	
		}

"switch"		{
			fprintf(tokenout,"<SWITCH> ");
			fprintf(logout,"\nLine no %d: TOKEN <SWITCH> Lexeme %s found\n",line_count,yytext);	
		}

"case"		{
			fprintf(tokenout,"<CASE> ");
			fprintf(logout,"\nLine no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);	
		}

"default"	{
			fprintf(tokenout,"<DEFAULT> ");
			fprintf(logout,"\nLine no %d: TOKEN <DEFAULT> Lexeme %s found\n",line_count,yytext);	
		}

"continue"	{
			fprintf(tokenout,"<CONTINUE> ");
			fprintf(logout,"\nLine no %d: TOKEN <CONTINUE> Lexeme %s found\n",line_count,yytext);	
		}

"++"	|
"--"		{
			fprintf(tokenout,"<INCOP, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <INCOP> Lexeme %s found\n",line_count,yytext);
			

		}

[*/%]		{
			fprintf(tokenout,"<MULOP, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <MULOP> Lexeme %s found\n",line_count,yytext);

		}

[&|^]	|
"<<"	|
">>"		{
			fprintf(tokenout,"<BITOP, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <BITOP> Lexeme %s found\n",line_count,yytext);

		}

"<="	|
"<"	|
">="	|
">"	|
"=="	|
"!="		{
			fprintf(tokenout,"<RELOP, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RELOP> Lexeme %s found\n",line_count,yytext);

		}

"="		{
			fprintf(tokenout,"<ASSIGNOP, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <ASSIGNOP> Lexeme %s found\n",line_count,yytext);

		}


"+"		|

"-"		{
			fprintf(tokenout,"<ADDOP, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <ADDOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule

		}

"&&"	|
"||"		{
			fprintf(tokenout,"<LOGICOP, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LOGICOP> Lexeme %s found\n",line_count,yytext);

		}

"!"		{
			fprintf(tokenout,"<NOT, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <NOT> Lexeme %s found\n",line_count,yytext);
			
		}

"("		{
			fprintf(tokenout,"<LPAREN, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LPAREN> Lexeme %s found\n",line_count,yytext);
		}

")"		{
			fprintf(tokenout,"<RPAREN, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RPAREN> Lexeme %s found\n",line_count,yytext);
		}

"{"		{
			fprintf(tokenout,"<LCURL, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LCURL> Lexeme %s found\n",line_count,yytext);
		}

"}"		{
			fprintf(tokenout,"<RCURL, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RCURL> Lexeme %s found\n",line_count,yytext);
		}

"["		{
			fprintf(tokenout,"<LTHIRD, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LTHIRD> Lexeme %s found\n",line_count,yytext);
		}

"]"		{
			fprintf(tokenout,"<RTHIRD, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RTHIRD> Lexeme %s found\n",line_count,yytext);
		}

","		{
			fprintf(tokenout,"<COMMA, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <COMMA> Lexeme %s found\n",line_count,yytext);
		}

";"		{
			fprintf(tokenout,"<SEMICOLON, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <SEMICOLON> Lexeme %s found\n",line_count,yytext);
		}

\'.\'  {	fprintf(logout,"\nLine no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
			
			string str = "CONST_CHAR";
			char *strp = new char[100];
			strcpy(strp, str.c_str());
	
			bool success = symbolTable->insert(yytext, strp);
			if(success)
				symbolTable->printAllScopeTable(logout);
			else
				fprintf(logout,"%s is already in Symbol Table\n", yytext);
	
			delete []strp;	

			yytext[0] = yytext[1];
			yytext[1] = 0;
			fprintf(tokenout,"<CONST_CHAR, %s> ",yytext);
			
			for(int i=0; i<yyleng; i++){
				if(yytext[i]=='\n') line_count++;
			}

			
			
		}

\'\\(n|t|\\|\'|a|f|r|b|v|0|\")\'	{	
						fprintf(logout,"\nLine no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
						
						string str = "CONST_CHAR";
						char *strp = new char[100];
						strcpy(strp, str.c_str());
	
						bool success = symbolTable->insert(yytext, strp);
						if(success)
							symbolTable->printAllScopeTable(logout);
						else
						fprintf(logout,"%s is already in Symbol Table\n", yytext);
	
						delete []strp;

						if(yytext[2]=='n') yytext[0] = '\n';
						else if(yytext[2]=='t') yytext[0] = '\t';
						else if(yytext[2]=='\\') yytext[0] = '\\';
						else if(yytext[2]=='\'') yytext[0] = '\'';
						else if(yytext[2]=='a') yytext[0] = '\a';
						else if(yytext[2]=='f') yytext[0] = '\f';
						else if(yytext[2]=='r') yytext[0] = '\r';
						else if(yytext[2]=='b') yytext[0] = '\b';
						else if(yytext[2]=='v') yytext[0] = '\v';
						else if(yytext[2]=='0') yytext[0] = '\0';
						else if(yytext[2]=='\"') yytext[0] = '\"';
						yytext[1] = 0;
						fprintf(tokenout,"<CONST_CHAR, %s> ",yytext);
	
				
						
				}

\'[^\']*	|
\'\\(n|t|\\|\'|a|f|r|b|v|0|\")?[^\']+	{
						lex_error++;
						fprintf(logout,"\nERROR at Line no %d: UNFINISHED_CHARACTER Lexeme %s found\n",line_count,yytext);		
						for(int i=0; i<yyleng; i++){
							if(yytext[i]=='\n') line_count++;
						}
					}

\'\'		{
			lex_error++;
			fprintf(logout,"\nERROR at Line no %d: EMPTY_CHARACTER_CONSTANT Lexeme %s found\n",line_count,yytext);		

		}


\'[^\'][^\']+\'			{	lex_error++;
					fprintf(logout,"\nERROR at Line no %d: MULTI_CHARACTER_CONSTANT Lexeme %s found\n",line_count,yytext);
					for(int i=0; i<yyleng; i++){
						if(yytext[i]=='\n') line_count++;
					}
				}


({LETTER}|_)({ALPHANUMERIC}|_)*	{
					fprintf(tokenout,"<ID, %s> ",yytext);
					fprintf(logout,"\nLine no %d: TOKEN <ID> Lexeme %s found\n",line_count,yytext);

					string str = "ID";
					char *strp = new char[100];
					strcpy(strp, str.c_str());

					bool success = symbolTable->insert(yytext, strp);
					if(success)
						symbolTable->printAllScopeTable(logout);
					else
						fprintf(logout,"%s is already in Symbol Table\n", yytext);
		
					delete []strp;
				}

{DIGIT}+\.	{
			
			fprintf(logout,"\nLine no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			
			yytext[yyleng-1] = 0;			
			
			fprintf(tokenout,"<CONST_INT, %s> ",yytext);

			string str = "CONST_INT";
			char *strp = new char[100];
			strcpy(strp, str.c_str());

			bool success = symbolTable->insert(yytext, strp);
			if(success)
				symbolTable->printAllScopeTable(logout);
			else
				fprintf(logout,"%s is already in Symbol Table\n", yytext);

			delete []strp;
				
				
		}

		
{DIGIT}+ 	{
			fprintf(tokenout,"<CONST_INT, %s> ",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)

			string str = "CONST_INT";
			char *strp = new char[100];
			strcpy(strp, str.c_str());

			bool success = symbolTable->insert(yytext, strp);
			if(success)
				symbolTable->printAllScopeTable(logout);
			else
				fprintf(logout,"%s is already in Symbol Table\n", yytext);

			delete []strp;
				
				
		}

{DIGIT}*\.{DIGIT}+	|
{DIGIT}+\.{DIGIT}+(E[+-]?{DIGIT}+) |
\.{DIGIT}+(E[+-]?{DIGIT}+)?	|
{DIGIT}+(E[+-]?{DIGIT}+)	{
				fprintf(tokenout,"<CONST_FLOAT, %s> ",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);		

				string str = "CONST_FLOAT";
				char *strp = new char[100];
				strcpy(strp, str.c_str());

				bool success = symbolTable->insert(yytext, strp);
				if(success)
					symbolTable->printAllScopeTable(logout);
				else
					fprintf(logout,"%s is already in Symbol Table\n", yytext);
				
				delete []strp;	
			
				}

{DIGIT}+({ALPHANUMERIC}|_)+	{	lex_error++;
					fprintf(logout,"\nERROR at Line no %d: Invalid_prefix_on_ID_or_invalid_suffix_on_Number Lexeme %s found\n",line_count,yytext);	
				}


{DIGIT}*\.{DIGIT}+(E[+-]?{DIGIT}*\.{DIGIT}*)	|
{DIGIT}*(E[+-]?{DIGIT}*\.{DIGIT}*)	|
\.{DIGIT}*(E[+-]?{DIGIT}*\.{DIGIT}*)	{	lex_error++;
						fprintf(logout,"\nERROR at Line no %d: ILL_FORMED_NUMBER Lexeme %s found\n",line_count,yytext);
					}

{DIGIT}*(\.{DIGIT}*)+(E[+-]?{DIGIT}+)?	|	
{DIGIT}*(\.{DIGIT}*)+(E[+-]?{DIGIT}*\.{DIGIT}*)	{	lex_error++;
							fprintf(logout,"\nERROR at Line no %d: TOO_MANY_DECIMAL_POINTS Lexeme %s found\n", line_count, yytext);
						}

\"([^\"\n]|"\\\""|\\\n)*	{	lex_error++;
				fprintf(logout,"\nERROR at Line no %d: UNFINISHED_STRING Lexeme %s found\n",line_count,yytext);
				for(int i=0; i<yyleng; i++){
					if(yytext[i]=='\n') line_count++;
				}

			}
	
\"([^\"\n]|"\\\""|\\\n)*\"	{		//done
					int line = line_count;
					bool flag = true;
					char *str = new char[yyleng+5];
					int j=0;
					for(int i=1; i<yyleng-1; i++){
						if(yytext[i]=='\\'){	      		//(n|t|\\|\'|a|f|r|b|v|0|")
							if(yytext[i+1]=='\n'){
								line++;
								//str[j] = yytext[i];
								j--;
								i++;						
							}
							else if(yytext[i+1]=='n'){
								str[j] = '\n';
								i++;						
							}
							else if(yytext[i+1]=='t'){
								str[j] = '\t';
								i++;						
							}
							else if(yytext[i+1]=='\\'){
								str[j] = '\\';
								i++;						
							}
							else if(yytext[i+1]=='\''){
								str[j] = '\'';
								i++;						
							}
							else if(yytext[i+1]=='\"'){
								str[j] = '\"';
								i++;						
							}
							else if(yytext[i+1]=='a'){
								str[j] = '\a';
								i++;						
							}
							else if(yytext[i+1]=='f'){
								str[j] = '\f';
								i++;						
							}
							else if(yytext[i+1]=='r'){
								str[j] = '\r';
								i++;						
							}
							else if(yytext[i+1]=='b'){
								str[j] = '\b';
								i++;						
							}
							else if(yytext[i+1]=='v'){
								str[j] = '\v';
								i++;						
							}
							else if(yytext[i+1]=='0'){
								str[j] = '\0';
								i++;						
							}
							else{
								str[j] = yytext[i];
							}				
						}

						else if(yytext[i]!='\\' && yytext[i+1]=='\n'){
							line++;
							flag = false;
							str[j]=yytext[i];				
						}
						else{
							str[j] = yytext[i];
							
						}
						j++;
						
					}
					str[j] = 0;
					
					if(flag){
						fprintf(logout,"\nLine no %d: TOKEN <STRING> Lexeme %s found\n",line_count,yytext);
						fprintf(tokenout,"<STRING, \"%s\"> ",str);
					}
					else{
						lex_error++;
						fprintf(logout,"\nERROR at Line no %d: ILL_FORMED_STRING Lexeme %s found\n",line_count,yytext);
									
					}
					line_count=line;			

					
				}



"//"([^\n]*(\\[\n])*)*	{	//done
				fprintf(logout,"\nLine no %d: TOKEN <COMMENT> Lexeme %s found\n",line_count,yytext);
				for(int i=0; i<yyleng; i++){
					if(yytext[i]=='\n') line_count++;
				}
			}

("/*")[^(*/")]*("*/")	{	// cannot handle * or / within comment
				fprintf(logout,"\nLine no %d: TOKEN <COMMENT> Lexeme %s found\n",line_count,yytext);
				for(int i=0; i<yyleng; i++){
					if(yytext[i]=='\n') line_count++;
				}
			}

("/*")[^("*/")]*	{	
						lex_error++;
						fprintf(logout,"\nERROR at Line no %d: UNFINISHED_COMMENT Lexeme %s found\n",line_count,yytext);
						for(int i=0; i<yyleng; i++){
							if(yytext[i]=='\n') line_count++;
						}
			}

.	{	lex_error++;
		fprintf(logout,"\nERROR at Line no %d: UNRECOGNIZED_CHARACTER Lexeme %s found\n",line_count,yytext);
	
	}		

%%

//start of c code
int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}

	logout= fopen("1505080_log.txt","w");
	tokenout= fopen("1505080_token.txt","w");

	symbolTable = new SymbolTable(10);

	yyin= fin;
	yylex();
	
	symbolTable->printAllScopeTable(logout);	
	fprintf(logout,"\nTotal Lines: %d\nTotal Errors: %d\n",line_count-1,lex_error);	

	printf("***EXITING***\n");

	fclose(yyin);
	fclose(tokenout);
	fclose(logout);

	return 0;

}

//end of c code
