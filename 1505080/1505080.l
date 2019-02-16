%option noyywrap

%{

#include "1505080_SymbolTable.h"

#include "y.tab.h"

using namespace std;

extern YYSTYPE yylval;
extern SymbolTable *table;
void yyerror(char *);

int line_count = 1;
int lex_error = 0;


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

"if"		{return IF;}
		
"else"		{return ELSE;}

"while"		{return WHILE;}

"for"		{return FOR;}

"do"		{return DO;}

"break"		{return BREAK;}

"int"		{return INT;}

"char"		{return CHAR;}

"float"		{return FLOAT;}

"double"		{return DOUBLE;}

"void"		{return VOID;}

"return"	{return RETURN;}

"switch"		{return SWITCH;}

"case"		{return CASE;}

"default"	{return DEFAULT;}

"continue"	{return CONTINUE;}

"++"		{return INCOP;}

"--"	{return DECOP;}


[*/%]		{
			string str = "MULOP";
			char *strp = new char[100];
			strcpy(strp, str.c_str());

			SymbolInfo *s = new SymbolInfo(yytext, strp);
			yylval.symbolInfoVar = s;			
			delete []strp;		
			return MULOP;
		}

[&|^]	|
"<<"	|
">>"		{
				string str = "BITOP";
				char *strp = new char[100];
				strcpy(strp, str.c_str());

				SymbolInfo *s = new SymbolInfo(yytext, strp);
				yylval.symbolInfoVar = s;			
				delete []strp;		
				return BITOP;

		}

"<="	|
"<"	|
">="	|
">"	|
"=="	|
"!="		{
				string str = "RELOP";
				char *strp = new char[100];
				strcpy(strp, str.c_str());

				SymbolInfo *s = new SymbolInfo(yytext, strp);
				yylval.symbolInfoVar = s;		
				delete []strp;			
				return RELOP;

		}

"="		{return ASSIGNOP;}


"+"		|

"-"		{
			string str = "ADDOP";
			char *strp = new char[100];
			strcpy(strp, str.c_str());

			SymbolInfo *s = new SymbolInfo(yytext, strp);
			yylval.symbolInfoVar = s;		
			delete []strp;			
			return ADDOP;

		}

"&&"	|
"||"		{
				string str = "LOGICOP";
				char *strp = new char[100];
				strcpy(strp, str.c_str());

				SymbolInfo *s = new SymbolInfo(yytext, strp);
				yylval.symbolInfoVar = s;		
				delete []strp;			
				return LOGICOP;

		}

"!"		{return NOT;}

"("		{return LPAREN;}

")"		{return RPAREN;}

"{"		{return LCURL;}

"}"		{return RCURL;}

"["		{return LTHIRD;}

"]"		{return RTHIRD;}

","		{return COMMA;}

";"		{return SEMICOLON;}

\'.\'  {	
			yytext[0] = yytext[1];
			yytext[1] = 0;

			string str = "CONST_CHAR";
			char *strp = new char[100];
			strcpy(strp, str.c_str());

			SymbolInfo *s = new SymbolInfo(yytext, strp);
			yylval.symbolInfoVar = s;		
			delete []strp;		
			return CONST_CHAR;


			
			
		}

\'\\(n|t|\\|\'|a|f|r|b|v|0|\")\'	{	

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

						string str = "CONST_CHAR";
						char *strp = new char[100];
						strcpy(strp, str.c_str());

						SymbolInfo *s = new SymbolInfo(yytext, strp);
						yylval.symbolInfoVar = s;	
						delete []strp;			
						return CONST_CHAR;
				
						
				}

\'\'		{lex_error++;}


\'[^\'][^\']+\'	{	lex_error++;
					for(int i=0; i<yyleng; i++){
						if(yytext[i]=='\n') line_count++;
					}
				}


({LETTER}|_)({ALPHANUMERIC}|_)*	{
					
					string str = "ID";
					char *strp = new char[100];
					strcpy(strp, str.c_str());

					SymbolInfo *s = new SymbolInfo(yytext, strp);
					yylval.symbolInfoVar = s;	
					delete []strp;			
					return ID;

				}

{DIGIT}+\.	{
			
				yytext[yyleng-1] = 0;

				string str = "CONST_INT";
				char *strp = new char[100];
				strcpy(strp, str.c_str());

				SymbolInfo *s = new SymbolInfo(yytext, strp);
				yylval.symbolInfoVar = s;	
				delete []strp;			
				return CONST_INT;
				
				
		}

		
{DIGIT}+ 	{

				string str = "CONST_INT";
				char *strp = new char[100];
				strcpy(strp, str.c_str());

				SymbolInfo *s = new SymbolInfo(yytext, strp);
				yylval.symbolInfoVar = s;	
				delete []strp;			
				return CONST_INT;				
				
		}

{DIGIT}*\.{DIGIT}+	|
{DIGIT}+\.{DIGIT}+(E[+-]?{DIGIT}+) |
\.{DIGIT}+(E[+-]?{DIGIT}+)?	|
{DIGIT}+(E[+-]?{DIGIT}+)	{

								string str = "CONST_FLOAT";
								char *strp = new char[100];
								strcpy(strp, str.c_str());

								SymbolInfo *s = new SymbolInfo(yytext, strp);
								yylval.symbolInfoVar = s;	
								delete []strp;			
								return CONST_FLOAT;
			
							}

{DIGIT}+({ALPHANUMERIC}|_)+	{lex_error++;}


{DIGIT}*\.{DIGIT}+(E[+-]?{DIGIT}*\.{DIGIT}*)	|
{DIGIT}*(E[+-]?{DIGIT}*\.{DIGIT}*)	|
\.{DIGIT}*(E[+-]?{DIGIT}*\.{DIGIT}*)	{	lex_error++;}

{DIGIT}*(\.{DIGIT}*)+(E[+-]?{DIGIT}+)?	|	
{DIGIT}*(\.{DIGIT}*)+(E[+-]?{DIGIT}*\.{DIGIT}*)	{	lex_error++;}

\"([^\"\n]|"\\\""|\\\n)*	{	lex_error++;
								for(int i=0; i<yyleng; i++){
									if(yytext[i]=='\n') line_count++;
								}
				
							}

\"([^\"\n]|"\\\""|\\\n)*\"	{		//done
					int line = line_count;
					bool flag = true;
					char *str = new char[yyleng+20];
					int j=0;
					
					
					/*for(int i=1; i<yyleng-1; i++){
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
					str[j] = 0;*/
					
					if(flag){
						//fprintf(logout,"\nLine no %d: TOKEN <STRING> Lexeme %s found\n",line_count,yytext);
						//fprintf(tokenout,"<STRING, \"%s\"> ",str);

								string str = "STRING";
								char *strp = new char[100];
								strcpy(strp, str.c_str());

								SymbolInfo *s = new SymbolInfo(yytext, strp);
								yylval.symbolInfoVar = s;	
								delete []strp;			
								return STRING;;

						

					}
					else{
						lex_error++;
						//fprintf(logout,"\nERROR at Line no %d: ILL_FORMED_STRING Lexeme %s found\n",line_count,yytext);
									
					}
					line_count=line;			

					
				}

		

"//"([^\n]*(\\[\n])*)*	{	//comment
							for(int i=0; i<yyleng; i++){
								if(yytext[i]=='\n') line_count++;
							}
			
						}

("/*")[^(*/")]*("*/")	{	// cannot handle * or / within comment
							for(int i=0; i<yyleng; i++){
								if(yytext[i]=='\n') line_count++;
							}
			
						}

("/*")[^("*/")]*	{	lex_error++;
						for(int i=0; i<yyleng; i++){
							if(yytext[i]=='\n') line_count++;
						}
					
					}

.	{	lex_error++;}		

%%
/*
int yywrap(void)
{
	return 1;
}
*/
