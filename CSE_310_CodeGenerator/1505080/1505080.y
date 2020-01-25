%{
//Bison offline by 1505080
#include "1505080_SymbolTable.h"
#include <vector>

//#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

SymbolTable* symbolTable;

extern int line_count;
extern int lex_error;
int sem_error = 0;

char* varType = new char[20];

int argNo = 0;
int parNo = 0;
int fParNo = 0;
SymbolInfo** parList;
SymbolInfo** argList;

class ArrayType{
public:
    char* arrName;
    int arrSize;

    ArrayType(){
        arrName = new char[20];
        arrSize = 0;
    }

 };
vector<ArrayType*> arrays;

vector<char*> variables;

int labelCount=0;
int tempCount=0;

char *newLabel()
{
	char *lb= new char[10];
	sprintf(lb,"LB%d", labelCount);
	labelCount++;
	return lb;
}

char *newTempVar()
{
	char *tv= new char[10];
	sprintf(tv,"TV%d", tempCount);
	tempCount++;

	variables.push_back(tv);

	return tv;
}



FILE *parseout;
FILE *logout;
FILE *errorout;
FILE *codeout;
FILE *codeLog;


void yyerror(const char *s)
{
	//write your code
	printf("Syntex error at Line %d : %s\n", line_count, s);
	fprintf(logout, "Syntex error at Line %d : %s\n", line_count, s);

}


%}

%union{
	SymbolInfo *symbolInfoVar;
}

%token <symbolInfoVar> MULOP
%token <symbolInfoVar> BITOP
%token <symbolInfoVar> RELOP
%token <symbolInfoVar> ADDOP
%token <symbolInfoVar> LOGICOP
%token <symbolInfoVar> CONST_CHAR
%token <symbolInfoVar> ID
%token <symbolInfoVar> CONST_INT
%token <symbolInfoVar> CONST_FLOAT
%token <symbolInfoVar> STRING



%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON INCOP DECOP ASSIGNOP NOT PRINTLN

%type <symbolInfoVar> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor  argument_list arguments



%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%error-verbose

%%

start 	: program
		{	     			          
			//write your code in this block in all the similar blocks below
			fprintf(parseout, "start : program\n");
			fprintf(logout, "Line No %d -> start : program\n", line_count);
			fprintf(codeLog, "Line No %d -> start : program\n", line_count);

			$$ = $1;
			$$->setType("start");
			fprintf(logout, "%s\n\n", $$->getKey());

			char *tempVar = newTempVar();
			char* returnAddress = newTempVar();

			fprintf(codeout, ".MODEL SMALL\n\n");
			fprintf(codeout, ".STACK 100h\n\n");

			fprintf(codeout, ".DATA\n");

			for(int i=0; i<variables.size(); i++){
				fprintf(codeout, "%s DW 0\n", variables[i]);
			}

			for(int i=0; i<arrays.size(); i++){
				fprintf(codeout, "%s DW %d DUP (0)\n", arrays[i]->arrName, arrays[i]->arrSize);
			}

			fprintf(codeout, "\n.CODE\n\n");


			fprintf(codeout, "ASMOUT PROC \nPOP %s\nPOP %s \nPUSH AX \nPUSH BX \nPUSH CX \nPUSH DX \nPUSH SP \nPUSH BP \nPUSH SI \nPUSH DI \
			 \nPUSHF \nCMP %s, 0 \nJGE NOT_NEG3 \nMOV AH, 2 \nMOV DL, '-' \nINT 21h \nNEG %s \nNOT_NEG3: \nCMP %s , 0 \nJNE NOT_ZERO \
			  \nMOV AH, 2 \nMOV DL, '0' \nINT 21h \nNOT_ZERO: \nMOV AX, '#' \nPUSH AX \nOUTPUT_LOOP1: \nCMP %s , 0 \
			   \nJE END_OUTPUT_LOOP1 \nMOV BX, 10 \nMOV DX, 0 \nMOV AX, %s  \nIDIV BX \nPUSH DX \nMOV %s , AX \nJMP OUTPUT_LOOP1 \
			    \nEND_OUTPUT_LOOP1: \nOUTPUT_LOOP2: \nPOP BX \nCMP BX, '#' \nJE END_OUTPUT_LOOP2 \nADD BX, '0' \nMOV AH, 2 \
			     \nMOV DL, BL \nINT 21h \nJMP OUTPUT_LOOP2 \nEND_OUTPUT_LOOP2: \nMOV AH, 2 \nMOV DL, 0Dh \nINT 21h \nMOV DL, 0Ah \
			      \nINT 21h \n\nPOPF \nPOP DI \nPOP SI \nPOP BP \nPOP SP \nPOP DX \nPOP CX \nPOP BX \nPOP AX \nPUSH %s \nRET \nASMOUT ENDP \n", 
			       returnAddress, tempVar, tempVar, tempVar, tempVar, tempVar, tempVar, tempVar, returnAddress);

			fprintf(codeout, "\n%s\n\n", $1->getCode());

			fprintf(codeout, "END MAIN\n");

				fprintf(codeLog, "%s\n\n", $$->getCode());

	
		}
		;

program	: program unit 	
		{	    		//done	           
			fprintf(parseout, "program : program unit\n");
			fprintf(logout, "Line No %d -> program : program unit\n", line_count);
			fprintf(codeLog, "Line No %d -> program : program unit\n", line_count);

			char* str = new char[strlen($1->getKey()) + strlen($2->getKey()) + 200];
			sprintf(str, "%s%s", $1->getKey(), $2->getKey());


			$$ = new SymbolInfo(str, "program");

			char *tempCode = new char[strlen($1->getCode()) + strlen($2->getCode()) + 100];
			sprintf(tempCode, "%s \n%s \n", $1->getCode(), $2->getCode());
			$$->setCode(tempCode);         
			delete[] tempCode;

			fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

			delete[] str;

		}
		| unit 				
		{	   //done 			//NOTHING TO DO	
			fprintf(parseout, "program : unit\n");
			fprintf(logout, "Line No %d -> program : unit\n", line_count);
			fprintf(codeLog, "Line No %d -> program : unit\n", line_count);
			

			
			$$ = $1;
			$$->setType("program");
			fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		}
		;
	
unit 	: var_declaration	
		{	    //done 				//ALL DONE
			fprintf(parseout, "unit : var_declaration\n");
			fprintf(logout, "Line No %d -> unit : var_declaration\n", line_count);
			fprintf(codeLog, "Line No %d -> unit : var_declaration\n", line_count);
			
			$$ = $1;
			$$->setType("unit");
			fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());


		}
	    | func_declaration 
	    {	    //done
			fprintf(parseout, "unit : func_declaration\n");
			fprintf(logout, "Line No %d -> unit : func_declaration\n", line_count);
			fprintf(codeLog, "Line No %d -> unit : func_declaration\n", line_count);
			
			$$ = $1;
			$$->setType("unit");
			fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		}
     	| func_definition	
     	{	    //done
			fprintf(parseout, "unit : func_definition\n");
			fprintf(logout, "Line No %d -> unit : func_definition\n", line_count);
			fprintf(codeLog, "Line No %d -> unit : func_definition\n", line_count);
			
			$$ = $1;
			$$->setType("unit");

			fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());
		
		}
     	;
     
func_declaration	: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	
					{	   //done  			 //NOTING TO DO         
						fprintf(parseout, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
						fprintf(logout, "Line No %d -> func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n", line_count);
						fprintf(codeLog, "Line No %d -> func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n", line_count);

						char* str = new char[strlen($2->getKey())+strlen($4->getKey())+200];
						char* retType = $1->getKey();

										
						sprintf(str, "%s %s(%s);\n",retType, $2->getKey(), $4->getKey());

						$$ = new SymbolInfo(str, "func_declaration");

						fprintf(logout, "%s\n\n", $$->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = $2->getKey();

						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}

						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);
						if(sInfo!=NULL){
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else{
							bool flag = symbolTable->insert(key, "ID");
							if(flag){
								sInfo = symbolTable->lookUp(key);

								sInfo->setIDType("FUNC");
								sInfo->setFuncRetType(retType);
								sInfo->setFuncIsDefined(false);

								sInfo->setParamNo(fParNo);

								for(int i=0; i<parNo; i++){
									sInfo->paramList[i] = parList[i];
								}

								parNo = 0;

								//sInfo = symbolTable->lookUp(key);
								//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

							}
							//symbolTable->printAllScopeTable(logout);
						}

						fprintf(codeLog, "%s\n\n", $$->getCode());

					}
					| type_specifier ID LPAREN RPAREN SEMICOLON
					{	    //done  			 //NOTING TO DO   
						fprintf(parseout, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
						fprintf(logout, "Line No %d -> func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n", line_count);
						fprintf(codeLog, "Line No %d -> func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n", line_count);

						char* str = new char[strlen($2->getKey())+200];
						char* retType = $1->getKey();

										
						sprintf(str, "%s %s();\n",retType, $2->getKey() );

						$$ = new SymbolInfo(str, "func_declaration");

						fprintf(logout, "%s\n\n", $$->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = $2->getKey();
						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}

						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);
						if(sInfo!=NULL){
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else{
							bool flag = symbolTable->insert(key, "ID");
							if(flag){
								sInfo = symbolTable->lookUp(key);
								
								sInfo->setIDType("FUNC");
								sInfo->setFuncRetType(retType);
								sInfo->setFuncIsDefined(false);

								sInfo->setParamNo(0);

								//sInfo = symbolTable->lookUp(key);
								//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

							}
							//symbolTable->printAllScopeTable(logout);
						}

						fprintf(codeLog, "%s\n\n", $$->getCode());

					}
					;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
				{	     		//done 	          
					fprintf(parseout, "func_definition : type_specifier ID LPAREN parameter_list RPAREN\n");
					fprintf(logout, "Line No %d -> func_definition : type_specifier ID LPAREN parameter_list RPAREN\n", line_count);
					fprintf(codeLog, "Line No %d -> func_definition : type_specifier ID LPAREN parameter_list RPAREN\n", line_count);
		
						char* str = new char[strlen($2->getKey())+strlen($4->getKey())+strlen($6->getKey())+200];
						char* retType = $1->getKey();

						sprintf(str, "%s %s(%s)%s",retType, $2->getKey(), $4->getKey(), $6->getKey());

						$$ = new SymbolInfo(str, "func_definition");

						fprintf(logout, "%s\n\n", $$->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = $2->getKey();
						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}
						
						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

						if(sInfo!=NULL && strcmp(sInfo->getIDType(), "FUNC")!=0){	//variable or array already declared
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getFuncIsDefined()){	//function already defined
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() already defined in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && strcmp(sInfo->getFuncRetType(), retType)!=0){	//return type mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() return type mismatch\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getParamNo()!=fParNo){	//parameter number mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number mismatch\n", line_count, key);
							sem_error++;
						}
						else{
							//fprintf(errorout, "HERE\n");
							bool flag = true;
							if(sInfo!=NULL && sInfo->paramList!=NULL && fParNo>0){	//parameter type mismatch check
								for(int i=0; i<fParNo; i++){
									SymbolInfo *temp = sInfo->paramList[i];
									SymbolInfo *temp2 = parList[i];
									if(temp==NULL || temp2==NULL){
										fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter type mismatch\n", line_count, key);
										sem_error++;
										flag = false;
										break;
									}
									else if(strcmp(temp->getVarType(), temp2->getVarType() ) ){
										fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter type mismatch\n", line_count, key);
										sem_error++;
										flag = false;
										break;
									}
								}
							}
							if(flag){
								flag = symbolTable->insert(key, "ID");
								sInfo = symbolTable->lookUp(key);

								sInfo->setIDType("FUNC");
								sInfo->setFuncRetType(retType);
								sInfo->setFuncIsDefined(true);

								sInfo->setParamNo(fParNo);

								for(int i=0; i<parNo; i++){
									sInfo->paramList[i] = parList[i];
								}

								parNo = 0;

								sInfo->setScopeNo(symbolTable->getNumberOfScopes());

								char* tempCode = new char[strlen($6->getCode())+500];

								if(strcmp(key, "MAIN")==0){
									sprintf(tempCode, "MAIN PROC \nMOV DX, @DATA \nMOV DS, DX \n%s \nMOV AH, 4Ch \nINT 21h \nMAIN ENDP ", $6->getCode());
								}
								else{
									int np = sInfo->getParamNo();

									char *popParam = new char[200];
									sprintf(popParam, "");

									for(int i=np-1; i>=0; i--){
											char* varName  = new char[25];
											sprintf(varName, "%s%d", parList[i]->getKey(), sInfo->getScopeNo());
											sprintf(popParam, "%sPOP %s\n", popParam, varName);
									}						

									char *returnAddress = newTempVar();
									char *dummy = newTempVar();

									//DX is used for returning values
									
									sprintf(tempCode, "%s PROC \nPOP %s \n%s \nPUSH AX \nPUSH BX \nPUSH CX \nPUSH DX \nPUSH SP \nPUSH BP \
										\nPUSH SI \nPUSH DI \nPUSHF \nPUSH %s \n%s \nRET \n%s ENDP", 
										 key, returnAddress, popParam, returnAddress, $6->getCode(), key);


								}

								$$->setCode(tempCode);         
								delete[] tempCode;



								//sInfo = symbolTable->lookUp(key);
								//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

								//symbolTable->printAllScopeTable(logout);
							}

							fprintf(codeLog, "%s\n\n", $$->getCode());
							
						}

				}
				| type_specifier ID LPAREN RPAREN compound_statement
				{	     //done
					fprintf(parseout, "func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
					fprintf(logout, "Line No %d -> func_definition : type_specifier ID LPAREN RPAREN compound_statement\n", line_count);
					fprintf(codeLog, "Line No %d -> func_definition : type_specifier ID LPAREN RPAREN compound_statement\n", line_count);


					char* str = new char[strlen($2->getKey())+strlen($5->getKey())+200];
						char* retType = $1->getKey();

										
						sprintf(str, "%s %s()%s",retType, $2->getKey(), $5->getKey());

						$$ = new SymbolInfo(str, "func_definition");

						fprintf(logout, "%s\n\n", $$->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = $2->getKey();
						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}
						
						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

						if(sInfo!=NULL && strcmp(sInfo->getIDType(), "FUNC")!=0){	//variable or array already declared
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getFuncIsDefined()){	//function already defined
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() already defined in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && strcmp(sInfo->getFuncRetType(), retType)!=0){	//return type mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() return type mismatch\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getParamNo()!=0){	//parameter number mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number mismatch\n", line_count, key);
							sem_error++;
						}
						else{
							bool flag = symbolTable->insert(key, "ID");
							sInfo = symbolTable->lookUp(key);
								
							sInfo->setIDType("FUNC");
							sInfo->setFuncRetType(retType);
							sInfo->setFuncIsDefined(true);

							sInfo->setParamNo(0);

							sInfo->setScopeNo(symbolTable->getNumberOfScopes());

								char* tempCode = new char[strlen($5->getCode())+300];

								if(strcmp(key, "MAIN")==0){
									sprintf(tempCode, "MAIN PROC \nMOV DX, @DATA \nMOV DS, DX \n%s \nMOV AH, 4Ch \nINT 21h \nMAIN ENDP ", $5->getCode());
								}
								else{
									char *returnAddress = newTempVar();
									//DX is used for returning values
									sprintf(tempCode, "%s PROC \nPOP %s \nPUSH AX \nPUSH BX \nPUSH CX \nPUSH DX \
										\nPUSH SP \nPUSH BP \nPUSH SI \nPUSH DI \nPUSHF \nPUSH %s \n%s \nRET \n%s ENDP", 
										 key, returnAddress, returnAddress, $5->getCode(), key);
								}

								$$->setCode(tempCode);         
								delete[] tempCode;

							//sInfo = symbolTable->lookUp(key);
							//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

							//symbolTable->printAllScopeTable(logout);
						}
				fprintf(codeLog, "%s\n\n", $$->getCode());


				}
 				;				


parameter_list  : parameter_list COMMA type_specifier ID
				{	     			          //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : parameter_list COMMA type_specifier ID\n");
					fprintf(logout, "Line No %d -> parameter_list : parameter_list COMMA type_specifier ID\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : parameter_list COMMA type_specifier ID\n", line_count);

					parList[parNo] = new SymbolInfo($4->getKey(),"PARAMETER");
					
					char* str = new char[strlen($1->getKey()) + strlen($4->getKey()) +200];			
						
					if(strcmp($3->getKey(),"int")==0){
						sprintf(str, "%s, int %s", $1->getKey(), $4->getKey());
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp($3->getKey(),"float")==0){
						sprintf(str, "%s, float %s", $1->getKey(), $4->getKey());
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp($3->getKey(),"void")==0){
						sprintf(str, "%s, void %s", $1->getKey(), $4->getKey());
						parList[parNo]->setVarType("VOID");
					}

					parNo++;
					fParNo = parNo;

					$$ = new SymbolInfo(str, "parameter_list");
						
					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

					delete[] str;


				}
				| parameter_list COMMA type_specifier
		 		{	    //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : parameter_list COMMA type_specifier\n");
					fprintf(logout, "Line No %d -> parameter_list : parameter_list COMMA type_specifier\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : parameter_list COMMA type_specifier\n", line_count);

					parList[parNo] = new SymbolInfo("","PARAMETER");

					char* str = new char[strlen($1->getKey())+200];			
						
					if(strcmp($3->getKey(),"int")==0){
						sprintf(str, "%s, int", $1->getKey());
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp($3->getKey(),"float")==0){
						sprintf(str, "%s, float", $1->getKey());
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp($3->getKey(),"void")==0){
						sprintf(str, "%s, void", $1->getKey());
						parList[parNo]->setVarType("VOID");
					}
					
					parNo++;
					fParNo = parNo;

					$$ = new SymbolInfo(str, "parameter_list");
						
					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());


					delete[] str;

		 		}
		 		| type_specifier ID
				{	    //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : type_specifier ID\n");
					fprintf(logout, "Line No %d -> parameter_list : type_specifier ID\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : type_specifier ID\n", line_count);

					parNo=0;
					parList[parNo] = new SymbolInfo($2->getKey(),"PARAMETER");

					char* str = new char[strlen($2->getKey())+200];			
						
					if(strcmp($1->getKey(),"int")==0){
						sprintf(str, "int %s", $2->getKey());
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp($1->getKey(),"float")==0){
						sprintf(str, "float %s", $2->getKey());
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp($1->getKey(),"void")==0){
						fprintf(errorout, "Semantic Error : Line No %d -> Parameter type cannot be VOID\n", line_count);
						sem_error++;
						sprintf(str, "void %s", $2->getKey());
					}

					parNo++;
					fParNo = parNo;

					$$ = new SymbolInfo(str, "parameter_list");
						
					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());


					delete[] str;


				}
				| type_specifier
		 		{	    //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : type_specifier\n");
					fprintf(logout, "Line No %d -> parameter_list : type_specifier\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : type_specifier\n", line_count);

					parNo=0;
					parList[parNo] = new SymbolInfo("","PARAMETER");

					if(strcmp($1->getKey(),"int")==0){
						$$ = new SymbolInfo("int", "parameter_list");
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp($1->getKey(),"float")==0){
						$$ = new SymbolInfo("float", "parameter_list");
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp($1->getKey(),"void")==0){
						$$ = new SymbolInfo("void", "parameter_list");
						parList[parNo]->setVarType("VOID");
					} 
					parNo++;
					fParNo = parNo;

					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		 		}
		 		
		 		;

 		
compound_statement	: LCURL{	 //done 	//ALL DONE        
								symbolTable->enterScope();
								fprintf(logout, "Line No %d -> ENTERED NEW SCOPE NO : %d\n", line_count, symbolTable->getScopeNum());
								for(int i=0; i<parNo; i++){
									SymbolInfo* temp = parList[i];
									if(temp!=NULL){
										symbolTable->insert(temp->getKey(), "ID");	
										SymbolInfo* temp2 = symbolTable->lookUpCurrent(temp->getKey());
										if(temp2!=NULL){
											temp2->setIDType("VAR");
											temp2->setVarType(temp->getVarType());
											temp2->setScopeNo(symbolTable->getScopeNum());

											char* varName  = new char[25];
											sprintf(varName, "%s%d", temp2->getKey(), symbolTable->getScopeNum());

											variables.push_back(varName);


										}
									}
									

								}
								parNo = 0;
							} 
							statements RCURL		
		 		    {
						fprintf(parseout, "compound_statement : LCURL statements RCURL\n");
						fprintf(logout, "Line No %d -> compound_statement : LCURL statements RCURL\n", line_count);
						fprintf(codeLog, "Line No %d -> compound_statement : LCURL statements RCURL\n", line_count);

						char* str = new char[strlen($3->getKey())+200];
						sprintf(str, "{\n%s}\n", $3->getKey());

						$$ = new SymbolInfo(str, "compound_statement");

						$$->setCode($3->getCode());

						fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						symbolTable->printAllScopeTable(logout);
						symbolTable->exitScope();

		 		    }
		 		    | LCURL RCURL	
		 		    {	    //done
						fprintf(parseout, "compound_statement : LCURL RCURL\n");
						fprintf(logout, "Line No %d -> compound_statement : LCURL RCURL\n", line_count);
						fprintf(codeLog, "Line No %d -> compound_statement : LCURL RCURL\n", line_count);


						$$ = new SymbolInfo("{}\n", "compound_statement");
						fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());
									
						//symbolTable->printAllScopeTable(logout);

		 		    }
		 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
				{	     			         //done  			 //NOTING TO DO   //ALL DONE
					fprintf(parseout, "var_declaration : type_specifier declaration_list SEMICOLON\n");
					fprintf(logout, "Line No %d -> var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);
					fprintf(codeLog, "Line No %d -> var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);

					char* str = new char[strlen($2->getKey())+200];
					sprintf(str, "%s %s;\n", $1->getKey(), $2->getKey() );

					$$ = new SymbolInfo(str, "var_declaration");
					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());
								
					//symbolTable->printAllScopeTable(logout);

					delete[] str;


				}
 		 		;
 		 
type_specifier	: INT
				{		//done  			 //NOTING TO DO        //ALL DONE   
					fprintf(parseout, "type_specifier : INT\n");
					fprintf(logout, "Line No %d -> type_specifier : INT\n", line_count);
					fprintf(codeLog, "Line No %d -> type_specifier : INT\n", line_count);

					strcpy(varType, "INT");
					$$ = new SymbolInfo("int", "type_specifier");

					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());



				}
 				| FLOAT
		 		{	    //done  			 //NOTING TO DO   
					fprintf(parseout, "type_specifier : FLOAT\n");
					fprintf(logout, "Line No %d -> type_specifier : FLOAT\n", line_count);
					fprintf(codeLog, "Line No %d -> type_specifier : FLOAT\n", line_count);

					strcpy(varType, "FLOAT");
					$$ = new SymbolInfo("float", "type_specifier");

					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		 		}
		 		| VOID
		 		{	    //done  			 //NOTING TO DO   
					fprintf(parseout, "type_specifier : VOID\n");
					fprintf(logout, "Line No %d -> type_specifier : VOID\n", line_count);
					fprintf(codeLog, "Line No %d -> type_specifier : VOID\n", line_count);

					strcpy(varType, "VOID");
					$$ = new SymbolInfo("void", "type_specifier");

					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		 		}
		 		;
 		
declaration_list	: declaration_list COMMA ID
 		  			{	     	//DONE 			//ALL DONE	          
						fprintf(parseout, "declaration_list : declaration_list COMMA ID\n");
						fprintf(logout, "Line No %d -> declaration_list : declaration_list COMMA ID\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : declaration_list COMMA ID\n", line_count);

						char* s1 = $1->getKey();
						char* s2 = $3->getKey();

						strcat(s1,",");
						strcat(s1,s2);

						$$->setKey(s1);

						fprintf(logout, "%s\n\n", $$->getKey());

						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = s2;
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n",line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("VAR");
									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* varName  = new char[25];
									sprintf(varName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									variables.push_back(varName);

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

								}
								//symbolTable->printAllScopeTable(logout);

							}

						}
				fprintf(codeLog, "%s\n\n", $$->getCode());




 		  			}
 		  			| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
			 		{	    //done
						fprintf(parseout, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
						fprintf(logout, "Line No %d -> declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n", line_count);

			 		
						char* s = $3->getKey();
						char* size = $5->getKey();

						
						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = s;
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("ARR");
									
									int arrSize = atoi(size);
									$5->intVal = arrSize;
									sInfo->setArrSize(arrSize);
									//fprintf(logout, "%s %d %d\n", key, arrSize, sInfo->getArrSize());	

									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* arrName  = new char[25];
									sprintf(arrName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									ArrayType* arrT = new ArrayType();

									arrT->arrName = arrName;
									arrT->arrSize = arrSize;

									arrays.push_back(arrT);
									

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, "%s %s %s %s %d\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType(), sInfo->getArrSize());	

								}
								//symbolTable->printAllScopeTable(logout);

							}

						}

						char *str = new char[strlen(s)+200];

						sprintf(str, "%s,%s[%s]",$1->getKey(), s ,size);

						$$->setKey(str);
						fprintf(logout, "%s\n\n", $$->getKey());
						fprintf(codeLog, "%s\n\n", $$->getCode());

						delete[] str;

			 		}
			 		| ID
			 		{	    //done
						fprintf(parseout, "declaration_list : ID\n");
						fprintf(logout, "Line No %d -> declaration_list : ID\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : ID\n", line_count);

						char* s = $1->getKey();
						//fprintf(logout, "%s\n\n", s);
						$$->setKey(s);

						fprintf(logout, "%s\n\n", $$->getKey());


						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = $1->getKey();
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("VAR");
									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* varName  = new char[25];
									sprintf(varName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									variables.push_back(varName);

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	


								}
								//symbolTable->printAllScopeTable(logout);

							}

						}


				fprintf(codeLog, "%s\n\n", $$->getCode());



			 		}
			 		| ID LTHIRD CONST_INT RTHIRD
			 		{	    //done
						fprintf(parseout, "declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
						fprintf(logout, "Line No %d -> declaration_list : ID LTHIRD CONST_INT RTHIRD\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : ID LTHIRD CONST_INT RTHIRD\n", line_count);

						char* s = $1->getKey();
						char* size = $3->getKey();

						
						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = s;
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("ARR");
									
									int arrSize = atoi(size);
									$3->intVal = arrSize;
									sInfo->setArrSize(arrSize);
									//fprintf(logout, "%s %d %d\n", key, arrSize, sInfo->getArrSize());	

									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* arrName  = new char[25];
									sprintf(arrName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									ArrayType* arrT = new ArrayType();

									arrT->arrName = arrName;
									arrT->arrSize = arrSize;

									arrays.push_back(arrT);

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, " %s %s %s %s %d\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType(), sInfo->getArrSize());	

								}
								//symbolTable->printAllScopeTable(logout);

							}

						}

						char *str = new char[strlen(s)+200];

						sprintf(str, "%s[%s]",s ,size);

						$$->setKey(str);
						fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

						delete[] str;


			 		}
			 		;
 		  
statements 	: statement
		   	{	     		//done	          
				fprintf(parseout, "statements : statement\n");
				fprintf(logout, "Line No %d -> statements : statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statements : statement\n", line_count);


				$$ = $1;
				$$->setType("statements");
				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		   	}
		   	| statements statement
		   	{	    //done
				fprintf(parseout, "statements : statements statement\n");
				fprintf(logout, "Line No %d -> statements : statements statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statements : statements statement\n", line_count);

				char* str = new char[strlen($1->getKey())+strlen($2->getKey())+200];
				sprintf(str, "%s%s", $1->getKey(), $2->getKey());

				$$ = new SymbolInfo(str, "statements");
				fprintf(logout, "%s\n\n", $$->getKey());


				char *tempCode = new char[strlen($1->getCode()) + strlen($2->getCode()) + 200];
				sprintf(tempCode, "%s \n%s \n", $1->getCode(), $2->getCode());

				$$->setCode(tempCode);         
				delete[] tempCode;


				fprintf(codeLog, "%s\n\n", $$->getCode());
										
				delete[] str;

		   	}
		   	;
	   
statement 	: var_declaration
		  	{	    		//done
				fprintf(parseout, "statement : var_declaration\n");
				fprintf(logout, "Line No %d -> statement : var_declaration\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : var_declaration\n", line_count);

				$$ = $1;
				$$->setType("statement");
				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		  	}
		  	| expression_statement
		  	{	    //done
				fprintf(parseout, "statement : expression_statement\n");
				fprintf(logout, "Line No %d -> statement : expression_statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : expression_statement\n", line_count);

				$$ = $1;
				$$->setType("statement");
				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		  	}
		  	| compound_statement
		  	{	    //done
				fprintf(parseout, "statement : compound_statement\n");
				fprintf(logout, "Line No %d -> statement : compound_statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : compound_statement\n", line_count);

				$$ = $1;
				$$->setType("statement");
				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

		  	}
		  	| FOR LPAREN expression_statement expression_statement expression RPAREN statement
		  	{	    //done
				fprintf(parseout, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
				fprintf(logout, "Line No %d -> statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n", line_count);

				if( strcmp($4->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

		  		char* str = new char[strlen($3->getKey()) + strlen($4->getKey()) + strlen($5->getKey()) + strlen($7->getKey()) + 200];
				sprintf(str, "for(%s;%s;%s)%s", $3->getKey(), $4->getKey(), $5->getKey(), $7->getKey());

				$$ = new SymbolInfo(str, "statement");


				char *tempCode = new char[strlen($3->getCode()) + strlen($4->getCode()) + strlen($5->getCode()) + strlen($7->getCode()) + 200];

				char *startLabel = newLabel();
				char *endLabel = newLabel();

				sprintf(tempCode, "%s \n%s: \n%s \nCMP %s, 0 \nJZ %s \n%s \n%s \nJMP %s \n%s: \n",
					$3->getCode(), startLabel, $4->getCode(), $4->getTempVar(), endLabel, $7->getCode(), $5->getCode(),startLabel, endLabel);

				$$->setCode(tempCode);
				delete[] tempCode;


				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				delete[] str;

		  	}
		  	| IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
		  	{	    //done
				fprintf(parseout, "statement : IF LPAREN expression RPAREN statement\n");
				fprintf(logout, "Line No %d -> statement : IF LPAREN expression RPAREN statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : IF LPAREN expression RPAREN statement\n", line_count);

				if( strcmp($3->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen($3->getKey()) + strlen($5->getKey()) + 200];
				sprintf(str, "if(%s)%s", $3->getKey(), $5->getKey());


				char *tempCode = new char[strlen($3->getCode())+strlen($5->getCode())+200];
				char *endLabel = newLabel();

				sprintf(tempCode, "%s \nCMP %s, 0 \nJE %s \n%s \n%s: \n", 
				 		$3->getCode(), $3->getTempVar(), endLabel, $5->getCode(), endLabel);




				$$ = new SymbolInfo(str, "statement");
				$$->setCode(tempCode);

				delete[] tempCode;

				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				delete[] str;

		  	}
		  	| IF LPAREN expression RPAREN statement ELSE statement 
		  	{	    //done
				fprintf(parseout, "statement : IF LPAREN expression RPAREN statement ELSE statement\n");
				fprintf(logout, "Line No %d -> statement : IF LPAREN expression RPAREN statement ELSE statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : IF LPAREN expression RPAREN statement ELSE statement\n", line_count);

				if( strcmp($3->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen($3->getKey()) + strlen($5->getKey()) + strlen($7->getKey()) + 200];
				sprintf(str, "if(%s)%selse%s", $3->getKey(), $5->getKey(), $7->getKey());


				char *tempCode = new char[strlen($3->getCode())+strlen($5->getCode())+strlen($7->getCode())+200];
				char *elseLabel = newLabel();
				char *endLabel = newLabel();


				sprintf(tempCode, "%s \nCMP %s, 0 \nJE %s \n%s \n JMP %s \n%s: \n%s \n %s: \n", 
				 		$3->getCode(), $3->getTempVar(), elseLabel, $5->getCode(), endLabel, elseLabel, $7->getCode(), endLabel);

				$$ = new SymbolInfo(str, "statement");
				
				$$->setCode(tempCode);
				delete[] tempCode;

				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				delete[] str;


		  	}
		  	| WHILE LPAREN expression RPAREN statement
		  	{	    //done
				fprintf(parseout, "statement : WHILE LPAREN expression RPAREN statement\n");
				fprintf(logout, "Line No %d -> statement : WHILE LPAREN expression RPAREN statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : WHILE LPAREN expression RPAREN statement\n", line_count);

				if( strcmp($3->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen($3->getKey()) + strlen($5->getKey()) + 200];
				sprintf(str, "while(%s)%s", $3->getKey(), $5->getKey());

				$$ = new SymbolInfo(str, "statement");


				char *tempCode = new char[strlen($3->getCode()) + strlen($5->getCode()) + 200];

				char *startLabel = newLabel();
				char *endLabel = newLabel();

				sprintf(tempCode, "%s: \n%s \nCMP %s, 0 \nJZ %s \n%s \nJMP %s \n%s: \n",
					startLabel, $3->getCode(), $3->getTempVar(), endLabel, $5->getCode(), startLabel, endLabel);

				$$->setCode(tempCode);
				delete[] tempCode;


				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				delete[] str;

		  	}
		  	| PRINTLN LPAREN expression RPAREN SEMICOLON
		  	{	    //done
				fprintf(parseout, "statement : PRINTLN LPAREN expression RPAREN SEMICOLON\n");
				fprintf(logout, "Line No %d -> statement : PRINTLN LPAREN expression RPAREN SEMICOLON\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : PRINTLN LPAREN expression RPAREN SEMICOLON\n", line_count);

				char* str = new char[strlen($3->getKey()) + 200];
				sprintf(str, "println(%s);\n", $3->getKey());

				$$ = new SymbolInfo(str, "statement");

				char *tempCode = new char[strlen($3->getCode()) +200];
				sprintf(tempCode, "%s \nPUSH %s \ncall ASMOUT \n", 
					$3->getCode(), $3->getTempVar());

				$$->setCode(tempCode);
				$$->setTempVar($3->getTempVar());

				delete[] tempCode; 



				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				delete[] str;

		  	}
		  	| RETURN expression SEMICOLON
		  	{	    //done?
				fprintf(parseout, "statement : RETURN expression SEMICOLON\n");
				fprintf(logout, "Line No %d -> statement : RETURN expression SEMICOLON\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : RETURN expression SEMICOLON\n", line_count);

				if( strcmp($2->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen($2->getKey()) + 200];
				sprintf(str, "return %s;\n", $2->getKey());

				$$ = $2;
				$$->setKey(str);
				$$->setType("statement");

				char *tempCode = new char[strlen($2->getCode()) + 200];

				sprintf(tempCode, "%s \nMOV DX, %s \nRET \n", 
					$2->getCode(), $2->getTempVar());

				$$->setCode(tempCode);
				delete[] tempCode;

				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				delete[] str;


		  	}
		  	;
	  
expression_statement 	: SEMICOLON			
						{	     	//done	 	//ALL DONE	          
							fprintf(parseout, "expression_statement : SEMICOLON\n");
							fprintf(logout, "Line No %d -> expression_statement : SEMICOLON\n", line_count);
							fprintf(codeLog, "Line No %d -> expression_statement : SEMICOLON\n", line_count);

							$$ = new SymbolInfo(";\n", "expression_statement");
							fprintf(logout, "%s\n\n", $$->getKey());
							fprintf(codeLog, "%s\n\n", $$->getCode());


						}
						| expression SEMICOLON 
						{	    //done
							fprintf(parseout, "expression_statement : expression SEMICOLON\n");
							fprintf(logout, "Line No %d -> expression_statement : expression SEMICOLON\n", line_count);
							fprintf(codeLog, "Line No %d -> expression_statement : expression SEMICOLON\n", line_count);

							char* str = new char[strlen($1->getKey())+200];
							sprintf(str, "%s;\n", $1->getKey());

							$$ = $1;
							$$->setKey(str);
							$$->setType("expression_statement");
							fprintf(logout, "%s\n\n", $$->getKey());
							fprintf(codeLog, "%s\n\n", $$->getCode());
										
							delete[] str;

						}
						;
	  
variable 	: ID 		
			{	     //done         ///ALL DONE
				fprintf(parseout, "variable : ID\n");
				fprintf(logout, "Line No %d -> variable : ID\n", line_count);
				fprintf(codeLog, "Line No %d -> variable : ID\n", line_count);


				SymbolInfo *temp = symbolTable->lookUp($1->getKey());

				if(temp==NULL){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not declared in this scope\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;

				}
				else if(strcmp (temp->getIDType(),"VAR")!=0){
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not a variable\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;
				}
				else{
					$$ = new SymbolInfo();
					temp->copyInfoTo($$);

					char* varName  = new char[25];
					//sprintf(varName, "%s%d", temp->getKey(), symbolTable->lookUpNo(temp->getKey()));
					sprintf(varName, "%s%d", temp->getKey(), temp->getScopeNo());

					$$->setTempVar(varName);


					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), temp->getArrIdx(), temp->intVal, temp->floatVal);	
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

				}

				$$->setType("variable");
				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());
				
				//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	


			}
			| ID LTHIRD expression RTHIRD 
			{	    						//done
				fprintf(parseout, "variable : ID LTHIRD expression RTHIRD\n");
				fprintf(logout, "Line No %d -> variable : ID LTHIRD expression RTHIRD\n", line_count);
				fprintf(codeLog, "Line No %d -> variable : ID LTHIRD expression RTHIRD\n", line_count);

				if( strcmp( $3->getVarType(),"INT")!=0 ){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Array index must be integer\n", line_count);
					sem_error++;

				}	


				int arrIdx = $3->intVal;

				SymbolInfo *temp = symbolTable->lookUp($1->getKey());

				if(temp==NULL){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;

				}
				else if(strcmp (temp->getIDType(),"ARR")!=0){
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not an array\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;
				}
				else if(temp->getArrSize() <= arrIdx){
					fprintf(errorout, "Warning : Line No %d -> array index out of bound\n", line_count);
					//sem_error++;

					$$=$1;
				}
				else{
					$$ = new SymbolInfo();
					temp->copyInfoTo($$);
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), temp->getArrIdx(), temp->intVal, temp->floatVal);	
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

					char* varName  = new char[25];
					//sprintf(varName, "%s%d", temp->getKey(), symbolTable->lookUpNo(temp->getKey()));
					sprintf(varName, "%s%d", temp->getKey(), temp->getScopeNo());

					$$->setTempVar(varName);

				}

				char* str = new char[200];
				sprintf(str, "%s[%s]", $$->getKey(), $3->getKey());

				$$->setType("variable");
				$$->setArrIdx(arrIdx);
				$$->setKey(str);



				delete[] str;

				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

			}
			;
	 
 expression : logic_expression	
	   		{	     	//done		         //ALL DONE 
				fprintf(parseout, "expression : logic_expression\n");
				fprintf(logout, "Line No %d -> expression : logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> expression : logic_expression\n", line_count);

				$$ = $1;
				$$->setType("expression");
				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

	   		}
	   		| variable ASSIGNOP logic_expression 	
	   		{	    //done
				fprintf(parseout, "expression : variable ASSIGNOP logic_expression\n");
				fprintf(logout, "Line No %d -> expression : variable ASSIGNOP logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> expression : variable ASSIGNOP logic_expression\n", line_count);

				if( strcmp($1->getVarType(), "VOID")==0 || strcmp($3->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				if(strcmp($1->getVarType(), $3->getVarType())==0){
					$1->intVal = $3->intVal;
					$1->floatVal = $3->floatVal;
				}
				else if(strcmp($1->getVarType(), "INT")==0){
					fprintf(errorout, "Warning : Line No %d -> FLOAT assigned to INT\n", line_count);
					$1->intVal = $3->floatVal;
				}
				else{
					fprintf(errorout, "Warning : Line No %d -> INT assigned to FLOAT\n", line_count);
					$1->floatVal = $3->intVal;
				}


				char *tempCode = new char[strlen($3->getCode()) + 200];
				//assigning value into symbolTable
				if(strcmp($1->getIDType(),"VAR")==0 ){
					//fprintf(logout, "Here\n");

					SymbolInfo *temp = symbolTable->lookUp($1->getKey());
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, $1->getKey());
						sem_error++;

						$$=$1;

					}
					else{
						temp->intVal = $1->intVal;
						temp->floatVal = $1->floatVal;

						
						sprintf(tempCode, "%s \nMOV AX, %s \nMOV %s, AX \n", 
								$3->getCode(),  $3->getTempVar(), $1->getTempVar());
					}

					/*temp = symbolTable->lookUp($1->getKey());
					if (temp!=NULL){
						fprintf(logout, "Here3\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					}*/


				}
				else if(strcmp($1->getIDType(),"ARR")==0 ){
					//dont know yet

					//fprintf(logout, "HERE2\n");

					char *newKey = new char[200];
					strcpy(newKey, $1->getKey());

					for(int i = strlen(newKey)-1; i>=0; i--){
						if(newKey[i]=='['){
							newKey[i]=0;
							break;
						}
					}

					SymbolInfo *temp = symbolTable->lookUp(newKey);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, $1->getKey());
						sem_error++;

						$$=$1;

					}
					else{
						temp->intVal = $1->intVal;
						temp->floatVal = $1->floatVal;

						temp->setArrIdx($1->getArrIdx());

						if(strcmp(temp->getVarType(), "INT")==0){
							temp->setIntListVal($1->getArrIdx(), $3->intVal);	
						}
						else if(strcmp(temp->getVarType(), "FLOAT")==0){
							temp->setFloatListVal($1->getArrIdx(), $3->floatVal);	
						}

						sprintf(tempCode, "%s \nLEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, %s \nMOV SI[BX], CX\n", 
											$3->getCode(), $1->getTempVar(), $1->getArrIdx(), $1->getArrIdx(), $3->getTempVar());
						


					}

					/*temp = symbolTable->lookUp(newKey);
					
					if (temp!=NULL){
						fprintf(logout, "Here4\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					
						fprintf(logout, "%d\n", temp->getIntListVal($1->getArrIdx()) );	
						
					}*/

				}


				$$ = $1;
				$$->setType("expression");
				$$->intVal = $1->intVal;
				$$->floatVal = $1->floatVal;

				char *str = new char[strlen($1->getKey()) + strlen($3->getKey()) + 50];
				sprintf(str, "%s=%s", $1->getKey(), $3->getKey());

				$$->setKey(str);
				$$->setCode(tempCode);         
				delete[] tempCode;

				delete[] str;

				fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(logout, "Assigned values : %s %d %f\n\n", $$->getVarType(), $$->intVal, $$->floatVal);
				fprintf(codeLog, "%s\n\n", $$->getCode());
			

	   		}
	   		;
			
logic_expression	: rel_expression 	
					{	     	//done		          
						fprintf(parseout, "logic_expression : rel_expression\n");
						fprintf(logout, "Line No %d -> logic_expression : rel_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> logic_expression : rel_expression\n", line_count);

						$$ = $1;
						$$->setType("logic_expression");
						fprintf(logout, "%s\n\n", $$->getKey());
						fprintf(codeLog, "%s\n\n", $$->getCode());

					}
					| rel_expression LOGICOP rel_expression 	
					{	    //done
						fprintf(parseout, "logic_expression : rel_expression LOGICOP rel_expression\n");
						fprintf(logout, "Line No %d -> logic_expression : rel_expression LOGICOP rel_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> logic_expression : rel_expression LOGICOP rel_expression\n", line_count);

						if( strcmp($1->getVarType(), "VOID")==0 || strcmp($3->getVarType(), "VOID")==0 ){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}

						float val1, val2;			
						if(strcmp($1->getVarType(), "FLOAT")==0 ){
							val1 = $1->floatVal;
						}
						else{
							val1 = $1->intVal;
						}

						if(strcmp($3->getVarType(), "FLOAT")==0 ){
							val2 = $3->floatVal;
						}
						else{
							val2 = $3->intVal;	
						}


						char* str = new char[strlen($1->getKey())+strlen($3->getKey())+200];
						$$ = new SymbolInfo();

						char *tempCode = new char[strlen($1->getCode())+strlen($3->getCode())+200];
						char *tempVar = newTempVar();

						char *zeroLabel = newLabel();
						char *oneLabel = newLabel();
						char *endLabel = newLabel();
						
						if(strcmp($2->getKey(), "&&")==0){
							sprintf(str, "%s&&%s", $1->getKey(), $3->getKey() );
							if(val1 && val2){$$->intVal = 1;}
							else{$$->intVal = 0;}

							sprintf(tempCode, "%s \n%s \nMOV AX, %s \nCMP AX, 0 \n JE %s \nMOV AX, %s \nCMP AX, 0 \n JE %s \nMOV AX, 1 \nJMP %s \n%s: \nMOV AX, 0 \n%s: \nMOV %s, AX \n",
								$1->getCode(), $3->getCode(), $1->getTempVar(), zeroLabel, $3->getTempVar(), zeroLabel, endLabel, zeroLabel, endLabel, tempVar);

						}
						else if(strcmp($2->getKey(), "||")==0){
							sprintf(str, "%s||%s", $1->getKey(), $3->getKey() );
							if(val1 || val2){$$->intVal = 1;}
							else{$$->intVal = 0;}

							sprintf(tempCode, "%s \n%s \nMOV AX, %s \nCMP AX, 0 \n JNE %s \nMOV AX, %s \nCMP AX, 0 \n JNE %s \nMOV AX, 0 \nJMP %s \n%s: \nMOV AX, 1 \n%s: \nMOV %s, AX \n",
								$1->getCode(), $3->getCode(), $1->getTempVar(), oneLabel, $3->getTempVar(), oneLabel, endLabel, oneLabel, endLabel, tempVar);

						}

						$$->setKey(str);
						$$->setType("logic_expression");
						$$->setVarType("INT");

						$$->setCode(tempCode);

						$$->setTempVar(tempVar);

						fprintf(logout, "%s\n\n", $$->getKey());
						fprintf(codeLog, "%s\n\n", $$->getCode());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						delete[] tempCode;


					}
					;
			
rel_expression	: simple_expression 
				{	     	//done		          //ALL DONE
					fprintf(parseout, "rel_expression : simple_expression\n");
					fprintf(logout, "Line No %d -> rel_expression : simple_expression\n", line_count);
					fprintf(codeLog, "Line No %d -> rel_expression : simple_expression\n", line_count);

					$$ = $1;
					$$->setType("rel_expression");
					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

				}
				| simple_expression RELOP simple_expression	
				{	    //done 
					fprintf(parseout, "rel_expression : simple_expression RELOP simple_expression\n");
					fprintf(logout, "Line No %d -> rel_expression : simple_expression RELOP simple_expression\n", line_count);
					fprintf(codeLog, "Line No %d -> rel_expression : simple_expression RELOP simple_expression\n", line_count);
					
					if( strcmp($1->getVarType(), "VOID")==0 || strcmp($3->getVarType(), "VOID")==0 ){
						fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

						sem_error++;
					}

					float val1, val2;			
					if(strcmp($1->getVarType(), "FLOAT")==0 ){
						val1 = $1->floatVal;
					}
					else{
						val1 = $1->intVal;
					}

					if(strcmp($3->getVarType(), "FLOAT")==0 ){
						val2 = $3->floatVal;
					}
					else{
						val2 = $3->intVal;	
					}


					char* str = new char[strlen($1->getKey())+strlen($3->getKey())+200];
					$$ = new SymbolInfo();

					
					char* condition = new char[10];
					
					if(strcmp($2->getKey(), "<=")==0){
						sprintf(str, "%s<=%s", $1->getKey(), $3->getKey() );
						if(val1 <= val2){$$->intVal = 1;}
						else{$$->intVal = 0;}

						sprintf(condition, "JLE");

					}
					else if(strcmp($2->getKey(), "<")==0){
						sprintf(str, "%s<%s", $1->getKey(), $3->getKey() );
						if(val1 < val2){$$->intVal = 1;}
						else{$$->intVal = 0;}
						sprintf(condition, "JL");
					}
					else if(strcmp($2->getKey(), ">=")==0){
						sprintf(str, "%s>=%s", $1->getKey(), $3->getKey() );
						if(val1 >= val2){$$->intVal = 1;}
						else{$$->intVal = 0;}
						sprintf(condition, "JGE");
					}
					else if(strcmp($2->getKey(), ">")==0){
						sprintf(str, "%s>%s", $1->getKey(), $3->getKey() );
						if(val1 > val2){$$->intVal = 1;}
						else{$$->intVal = 0;}
						sprintf(condition, "JG");
					}
					else if(strcmp($2->getKey(), "==")==0){
						sprintf(str, "%s==%s", $1->getKey(), $3->getKey() );
						if(val1 == val2){$$->intVal = 1;}
						else{$$->intVal = 0;}
						sprintf(condition, "JE");
					}
					else if(strcmp($2->getKey(), "!=")==0){
						sprintf(str, "%s!=%s", $1->getKey(), $3->getKey() );
						if(val1 != val2){$$->intVal = 1;}
						else{$$->intVal = 0;}
						sprintf(condition, "JNE");
					}

					char *tempCode = new char[strlen($1->getCode())+strlen($3->getCode())+200];
					char *tempVar = newTempVar();
					char *ifLabel = newLabel(); 
					char *endLabel = newLabel();

					sprintf(tempCode, "%s \n%s \nMOV AX, %s \nCMP AX, %s \n%s %s \nMOV AX, 0 \nJMP %s\n%s: \nMOV AX, 1 \n%s: \nMOV %s, AX \n", 
							$1->getCode(), $3->getCode(), $1->getTempVar(), $3->getTempVar(), condition, ifLabel, endLabel, ifLabel, endLabel, tempVar);

					$$->setKey(str);
					$$->setType("rel_expression");
					$$->setVarType("INT");

					$$->setCode(tempCode);
					$$->setTempVar(tempVar);

					delete[] tempCode;

					fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());
								
					//symbolTable->printAllScopeTable(logout);

					delete[] str;
						

				}
				;
				
simple_expression 	: term 
		  			{	     //done				//ALL DONE          
						fprintf(parseout, "simple_expression : term\n");
						fprintf(logout, "Line No %d -> simple_expression : term\n", line_count);
						fprintf(codeLog, "Line No %d -> simple_expression : term\n", line_count);

						$$ = $1;
						$$->setType("simple_expression");
						
						fprintf(logout, "%s\n\n", $$->getKey());
						fprintf(codeLog, "%s\n\n", $$->getCode());

		  			}
		  			| simple_expression ADDOP term 
		  			{	    //done
						fprintf(parseout, "simple_expression : simple_expression ADDOP term\n");
						fprintf(logout, "Line No %d -> simple_expression : simple_expression ADDOP term\n", line_count);
						fprintf(codeLog, "Line No %d -> simple_expression : simple_expression ADDOP term\n", line_count);

						if( strcmp($1->getVarType(), "VOID")==0 || strcmp($3->getVarType(), "VOID")==0 ){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}
									
						if(strcmp($1->getVarType(), "FLOAT")==0 || strcmp($3->getVarType(), "FLOAT")==0 ){
							if( strcmp($1->getVarType(), "INT")==0 ){
								//fprintf(logout, "HERE1\n");
								$1->setFloatVal($1->intVal);
								$1->setVarType("FLOAT");
							} 

							if( strcmp($3->getVarType(), "INT")==0 ){
								//fprintf(logout, "HERE3\n");
								$3->setFloatVal($3->intVal);
								$3->setVarType("FLOAT");

							} 							

						}
						
						char *str = new char[strlen($1->getKey()) + strlen($3->getKey()) + 50];
						$$ = $1;
						
						char *tempCode = new char[strlen($1->getCode()) + strlen($3->getCode()) + 200];
						char *tempVar = newTempVar();
						

						if(strcmp($2->getKey(),"+")==0){
							//fprintf(logout, "PLUS\n");
							sprintf(str, "%s+%s", $1->getKey(), $3->getKey());
							$$->intVal = $1->intVal + $3->intVal;
							$$->floatVal = $1->floatVal + $3->floatVal;

							sprintf(tempCode, "%s \n%s \nMOV BX, %s \nADD BX, %s \nMOV %s, BX \n",
								$1->getCode(), $3->getCode(), $1->getTempVar(), $3->getTempVar(), tempVar);

							//printf("%s\n", tempCode);


						}
						else{
							//fprintf(logout, "MINUS\n");
							sprintf(str, "%s-%s", $1->getKey(), $3->getKey());
							$$->intVal = $1->intVal - $3->intVal;
							$$->floatVal = $1->floatVal - $3->floatVal;

							sprintf(tempCode, "%s \n%s \nMOV BX, %s \nSUB BX, %s \nMOV %s, BX \n",
								$1->getCode(), $3->getCode(), $1->getTempVar(), $3->getTempVar(), tempVar);
						}
						
						

						$$->setKey(str);

						$$->setCode(tempCode);
						$$->setTempVar(tempVar);

						delete[] tempCode;

						fprintf(logout, "%s\n\n", $$->getKey());
						fprintf(logout, "Calculated values: %s %d %f\n\n", $$->getVarType(), $$->intVal, $$->floatVal);
						fprintf(codeLog, "%s\n\n", $$->getCode());


		  			}
		  			;
					
term 	:	unary_expression
     	{	    //done 				       //ALL DONE   
			fprintf(parseout, "term : unary_expression\n");
			fprintf(logout, "Line No %d -> term : unary_expression\n", line_count);
			fprintf(codeLog, "Line No %d -> term : unary_expression\n", line_count);

			$$ = $1;
			$$->setType("term");
			fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

     	}
     	|  term MULOP unary_expression
     	{	    //done
			fprintf(parseout, "term : term MULOP unary_expression\n");
			fprintf(logout, "Line No %d -> term : term MULOP unary_expression\n", line_count);
			fprintf(codeLog, "Line No %d -> term : term MULOP unary_expression\n", line_count);

			if( strcmp($1->getVarType(), "VOID")==0 || strcmp($3->getVarType(), "VOID")==0 ){
				fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

				sem_error++;
			}


			if( strcmp($1->getVarType(), "FLOAT")==0 || strcmp($3->getVarType(), "FLOAT")==0 ){
				if( strcmp($1->getVarType(), "INT")==0 ){
					//fprintf(logout, "HERE1\n");
					$1->setFloatVal($1->intVal);
					$1->setVarType("FLOAT");
				} 

				if( strcmp($3->getVarType(), "INT")==0 ){
					//fprintf(logout, "HERE3\n");
					$3->setFloatVal($3->intVal);
					$3->setVarType("FLOAT");

				} 							

			}
						
			char *str = new char[strlen($1->getKey()) + strlen($3->getKey()) + 50];
			$$ = $1;

			char *tempCode = new char[strlen($1->getCode()) + strlen($3->getCode()) + 100];
			char *tempVar = newTempVar();

			if(strcmp($2->getKey(),"*")==0){	//done
				
				sprintf(str, "%s*%s", $1->getKey(), $3->getKey());
				$$->intVal = $1->intVal * $3->intVal;
				$$->floatVal = $1->floatVal * $3->floatVal;

				sprintf(tempCode, "%s \n%s \nMOV AX, %s \nMUL %s\nMOV %s, AX \n",
					$1->getCode(), $3->getCode(), $1->getTempVar(), $3->getTempVar(), tempVar);

			}
			else if(strcmp($2->getKey(),"/")==0){	//done
				
				sprintf(str, "%s/%s", $1->getKey(), $3->getKey());
				if($3->intVal)
					$$->intVal = $1->intVal / $3->intVal;
				if($3->floatVal)
					$$->floatVal = $1->floatVal / $3->floatVal;

				sprintf(tempCode, "%s \n%s \nMOV AX, %s \nMOV BX, %s \nDIV BL\nXOR AH, AH \nMOV %s, AX \n",
					$1->getCode(), $3->getCode(), $1->getTempVar(), $3->getTempVar(), tempVar);

			}
			else{	//done
				
				sprintf(str, "%s\%%%s", $1->getKey(), $3->getKey());
				if($3->intVal)
					$$->intVal = $1->intVal % $3->intVal;
				//$$->floatVal = $1->floatVal - $3->floatVal;
				
				if( strcmp($$->getVarType(), "FLOAT")==0){
					fprintf(errorout, "Semantic Error : Line No %d -> FLOAT MODULUS NOT COMPATIBLE\n", line_count);
					sem_error++;
				}

				sprintf(tempCode, "%s \n%s \nMOV AX, %s \nMOV BX, %s \nDIV BL\nMOV AL, AH \nXOR AH, AH \nMOV %s, AX \n",
					$1->getCode(), $3->getCode(), $1->getTempVar(), $3->getTempVar(), tempVar);

			}
				
			
			$$->setKey(str);

			$$->setCode(tempCode);
			$$->setTempVar(tempVar);

			delete[] tempCode;

			fprintf(logout, "%s\n\n", $$->getKey());
			fprintf(logout, "Calculated values: %s %d %f\n\n", $$->getVarType(), $$->intVal, $$->floatVal);
				fprintf(codeLog, "%s\n\n", $$->getCode());



     	}
     	;

unary_expression	: ADDOP unary_expression  
					{	     //done 		//ALL DONE          
						fprintf(parseout, "unary_expression : ADDOP unary_expression\n");
						fprintf(logout, "Line No %d -> unary_expression : ADDOP unary_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> unary_expression : ADDOP unary_expression\n", line_count);

						if( strcmp($2->getVarType(), "VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}
						
						$$ = $2;
						char* str = new char[strlen($2->getKey())+ 200];

						if( strcmp ($1->getKey(), "+")==0 ){
							sprintf(str, "+%s", $2->getKey());
						}
						else{
							sprintf(str, "-%s", $2->getKey());
							
							$$->intVal = -($$->intVal);
							$$->floatVal = -($$->floatVal);

							char *tempCode = new char[strlen($2->getCode())+200];
							char *tempVar = newTempVar();

							sprintf(tempCode, "%s \nMOV AX, %s \nNEG AX \nMOV %s, AX \n", 
											$2->getCode(), $2->getTempVar(), tempVar);
							$$->setCode(tempCode);         

							delete[] tempCode;
							$$->setTempVar(tempVar);
						}
						
						$$->setKey(str);
						$$->setType("unary_expression");


						fprintf(logout, "%s\n\n", $$->getKey());
						fprintf(codeLog, "%s\n\n", $$->getCode());

						delete[] str;


					}
					| NOT unary_expression 
				 	{	    //done
						fprintf(parseout, "unary_expression : NOT unary_expression\n");
						fprintf(logout, "Line No %d -> unary_expression : NOT unary_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> unary_expression : NOT unary_expression\n", line_count);

						if( strcmp($2->getVarType(), "VOID")==0 ){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}

						$$ = $2;
						char* str = new char[strlen($2->getKey())+ 200];

						sprintf(str, "!%s", $2->getKey());
						
						$$->setKey(str);
						$$->setType("unary_expression");

						char *tempCode = new char[strlen($2->getCode())+200];

						char *elseLabel = newLabel();
						char *endLabel = newLabel();

						char *tempVar = newTempVar();

						sprintf(tempCode, "%s\nCMP %s, 0 \nJNZ %s \nMOV %s, 1 \nJMP %s \n%s: \nMOV %s, 0 \n%s: \n", 
									$2->getCode(), $2->getTempVar(), elseLabel, tempVar , endLabel, elseLabel, tempVar, endLabel);

						$$->setCode(tempCode);         
						delete[] tempCode;
						$$->setTempVar(tempVar);

						if($$->intVal==0){
							$$->intVal=1;
						}
						else{
							$$->intVal = 0;
						}

						if($$->floatVal==0){
							$$->floatVal=1;
						}
						else{
							$$->floatVal = 0;
						}
						
						fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());

						delete[] str;

				 	}
				 	| factor 
					{	    //done
						fprintf(parseout, "unary_expression : factor\n");
						fprintf(logout, "Line No %d -> unary_expression : factor\n", line_count);
						fprintf(codeLog, "Line No %d -> unary_expression : factor\n", line_count);

						$$ = $1;
						$$->setType("unary_expression");
						fprintf(logout, "%s\n\n", $$->getKey());
				fprintf(codeLog, "%s\n\n", $$->getCode());


					}
					;
	
factor	: variable 
		{	 //done  		//ALL DONE
			fprintf(parseout, "factor : variable\n");
			fprintf(logout, "Line No %d -> factor : variable\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : variable\n", line_count);

			$$ = $1;
			$$->setType("variable");

			char *tempCode = new char[200];
			char *tempVar = newTempVar();

			if(strcmp($1->getIDType(),"VAR")==0 ){
				sprintf(tempCode, "MOV AX, %s \nMOV %s, AX \n", $1->getTempVar(), tempVar);
			}
			else{
				sprintf(tempCode, "LEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, SI[BX] \nMOV %s, CX\n", 
										$1->getTempVar(), $1->getArrIdx(), $1->getArrIdx(), tempVar);
			}

			$$->setCode(tempCode);         
			$$->setTempVar(tempVar);
			delete[] tempCode;
			

			fprintf(logout, "%s\n\n", $$->getKey());
			fprintf(codeLog, "%s\n\n", $$->getCode());





		}
		| ID LPAREN argument_list RPAREN
		{	//function call 			//DONE
			fprintf(parseout, "factor : ID LPAREN argument_list RPAREN\n");
			fprintf(logout, "Line No %d -> factor : ID LPAREN argument_list RPAREN\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : ID LPAREN argument_list RPAREN\n", line_count);


			char* str = new char[strlen($1->getKey())+strlen($3->getKey())+ 200];
			sprintf(str, "%s(%s)", $1->getKey(), $3->getKey());

			

				SymbolInfo *temp = symbolTable->lookUp($1->getKey());

				char *tempCode = new char[strlen($3->getCode()) + 200];
				tempCode[0]=0;
				char *tempVar = newTempVar();


				if(temp==NULL){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Function %s() not declared in this scope\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;

				}
				else if(strcmp (temp->getIDType(),"FUNC")!=0){
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not a function\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;
				}
				// else if(!temp->getFuncIsDefined()){
				// 	fprintf(errorout, "Semantic Error : Line No %d -> Function %s() is not defined\n", line_count, $1->getKey());
				// 	sem_error++;

				// 	$$=$1;
				// }
				else if(temp->getParamNo() != argNo){
					fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number and argument number mismatch\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;
				}
				else if(temp->getParamNo() != argNo){
					fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number and argument number mismatch\n", line_count, $1->getKey());
					sem_error++;

					$$=$1;
				}
				else{
					// SymbolInfo* sInfo = temp;
					// if(sInfo!=NULL && sInfo->paramList!=NULL && argNo>0){	//parameter type mismatch check
					// 	for(int i=0; i<argNo; i++){
					// 		SymbolInfo *t = sInfo->paramList[i];
					// 		SymbolInfo *t2 = argList[i];
					// 		if(t==NULL || t2==NULL){
					// 			fprintf(errorout, "Warning : Line No %d -> Function %s() parameter and argument type mismatch\n", line_count, sInfo->getKey());
								
					// 		}
					// 		else if(strcmp(t->getVarType(), t2->getVarType())!=0 ){
					// 			fprintf(errorout, "Warning : Line No %d -> Function %s() parameter and argument  type mismatch\n", line_count, sInfo->getKey());
								
					// 		}
					// 	}
					// }

					int curSc = symbolTable->getScopeNum();

					symbolTable->setScope(temp->getScopeNo());

					sprintf(tempCode, "%s \ncall %s \nMOV %s, DX \nPOPF \nPOP DI \nPOP SI \nPOP BP \nPOP SP \nPOP DX \nPOP CX \nPOP BX \nPOP AX", 
										$3->getCode(), temp->getKey(), tempVar);

					symbolTable->setScope(curSc);

					$$ = new SymbolInfo();

					

					temp->copyInfoTo($$);
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), temp->getArrIdx(), temp->intVal, temp->floatVal);	
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

				}

				$$->setKey(str);
				$$->setType("factor");
				
				$$->setCode(tempCode);
				$$->setTempVar(tempVar);

				delete[] tempCode;

				fprintf(codeLog, "%s\n\n", $$->getCode());
				fprintf(logout, "%s\n\n", $$->getKey());
				
				//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

				delete[] str;


			

		}
		| LPAREN expression RPAREN
		{	    //done
			fprintf(parseout, "factor : LPAREN expression RPAREN\n");
			fprintf(logout, "Line No %d -> factor : LPAREN expression RPAREN\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : LPAREN expression RPAREN\n", line_count);

			char* str = new char[strlen($2->getKey())+ 200];
			sprintf(str, "(%s)", $2->getKey());

			$$ = $2;

			$$->setKey(str);
			$$->setType("factor");

			fprintf(logout, "%s\n\n", $$->getKey());
			fprintf(codeLog, "%s\n\n", $$->getCode());

			delete[] str;

		}
		| CONST_INT 
		{	    //done
			fprintf(parseout, "factor : CONST_INT\n");
			fprintf(logout, "Line No %d -> factor : CONST_INT\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : CONST_INT\n", line_count);

			$$ = $1;
			$$->intVal = atoi($$->getKey());
			$$->setVarType("INT");

			char* tempVar = newTempVar();
			$$->setTempVar(tempVar); 

			char* tempCode = new char[200];
			sprintf(tempCode, "MOV %s, %d\n", tempVar, $$->intVal);

			$$->setCode(tempCode);        
			 delete[] tempCode;

			fprintf(logout, "%s\n\n", $$->getKey());	
					fprintf(codeLog, "%s\n\n", $$->getCode());		

		}
		| CONST_FLOAT
		{	    //done
			fprintf(parseout, "factor : CONST_FLOAT\n");
			fprintf(logout, "Line No %d -> factor : CONST_FLOAT\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : CONST_FLOAT\n", line_count);

			$$ = $1;
			$$->floatVal = atof($$->getKey());
			$$->setVarType("FLOAT");

			char* tempVar = newTempVar();
			$$->setTempVar(tempVar); 

			char* tempCode = new char[200];
			sprintf(tempCode, "MOV %s, %d\n", tempVar, (int)$$->floatVal);

			$$->setCode(tempCode);         
			delete[] tempCode;

			fprintf(logout, "%s\n\n", $$->getKey());	
					fprintf(codeLog, "%s\n\n", $$->getCode());

		}
		| variable INCOP 
		{	    //done
			fprintf(parseout, "factor : variable INCOP\n");
			fprintf(logout, "Line No %d -> factor : variable INCOP\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : variable INCOP\n", line_count);

			char* key = new char[strlen($1->getKey())+ 200];
			strcpy(key, $1->getKey());
			
			char* str = new char[strlen($1->getKey())+ 200];
			sprintf(str, "%s++", $1->getKey());

			$$ = $1;

			$$->setKey(str);
			$$->setType("factor");

			$$->intVal = $$->intVal+1;
			$$->floatVal = $$->floatVal+1;


				//assigning value into symbolTable
				if(strcmp($1->getIDType(),"VAR")==0 ){
					//fprintf(logout, "Here\n");

					SymbolInfo *temp = symbolTable->lookUp(key);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, $1->getKey());
						sem_error++;

					}
					else{
						temp->intVal = $$->intVal;
						temp->floatVal = $$->floatVal;

						char *tempCode = new char[200];
						char *tempVar = newTempVar();

						sprintf(tempCode, "MOV AX, %s \nMOV %s, AX \nINC %s \n", $1->getTempVar(), tempVar, $1->getTempVar());
						
						$$->setCode(tempCode);
						$$->setTempVar(tempVar);         
						delete[] tempCode;

					}

					/*temp = symbolTable->lookUp($1->getKey());
					if (temp!=NULL){
						fprintf(logout, "Here3\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					}*/


				}
				else if( strcmp($1->getIDType(),"ARR")==0 ){
					//dont know yet

					//fprintf(logout, "HERE2\n");

					char *newKey = key;

					for(int i = strlen(newKey)-1; i>=0; i--){
						if(newKey[i]=='['){
							newKey[i]=0;
							break;
						}
					}

					SymbolInfo *temp = symbolTable->lookUp(newKey);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, $1->getKey());
						sem_error++;

					}
					else{
						temp->intVal = $$->intVal;
						temp->floatVal = $$->floatVal;

						temp->setArrIdx($1->getArrIdx());

						if(strcmp(temp->getVarType(), "INT")==0){
							temp->setIntListVal($$->getArrIdx(), $$->intVal);	
						}
						else if(strcmp(temp->getVarType(), "FLOAT")==0){
							temp->setFloatListVal($$->getArrIdx(), $$->floatVal);	
						}

						char *tempCode = new char[200];
						char *tempVar = newTempVar();
						sprintf(tempCode, "LEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, SI[BX] \nMOV %s, CX \nINC CX \nMOV SI[BX], CX \n", 
												$1->getTempVar(), $1->getArrIdx(), $1->getArrIdx(), tempVar);
						
						$$->setCode(tempCode);         
						$$->setTempVar(tempVar);         
						delete[] tempCode;


					}

					/*temp = symbolTable->lookUp(newKey);
					
					if (temp!=NULL){
						fprintf(logout, "Here4\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					
						fprintf(logout, "%d\n", temp->getIntListVal($1->getArrIdx()) );	
						
					}*/

				}


			fprintf(logout, "%s\n\n", $$->getKey());
					fprintf(codeLog, "%s\n\n", $$->getCode());

			delete[] str;

		}
		| variable DECOP
		{	    //done
			fprintf(parseout, "factor : variable DECOP\n");
			fprintf(logout, "Line No %d -> factor : variable DECOP\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : variable DECOP\n", line_count);
			
			char* key = new char[strlen($1->getKey())+ 200];
			strcpy(key, $1->getKey());

			char* str = new char[strlen($1->getKey())+ 200];
			sprintf(str, "%s--", $1->getKey());

			$$ = $1;
			$$->setKey(str);
			$$->setType("factor");

			$$->intVal = $$->intVal-1;
			$$->floatVal = $$->floatVal-1;


				//assigning value into symbolTable
				if(strcmp($1->getIDType(),"VAR")==0 ){
					//fprintf(logout, "Here\n");

					SymbolInfo *temp = symbolTable->lookUp(key);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, $1->getKey());
						sem_error++;

					}
					else{
						temp->intVal = $$->intVal;
						temp->floatVal = $$->floatVal;

						char *tempCode = new char[200];
						char *tempVar = newTempVar();

						sprintf(tempCode, "MOV AX, %s \nMOV %s, AX \nDEC %s \n", $1->getTempVar(), tempVar, $1->getTempVar());
						
						$$->setCode(tempCode);
						$$->setTempVar(tempVar);         
						delete[] tempCode;

					}

					/*temp = symbolTable->lookUp($1->getKey());
					if (temp!=NULL){
						fprintf(logout, "Here3\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					}*/


				}
				else if( strcmp($1->getIDType(),"ARR")==0 ){
					//dont know yet

					//fprintf(logout, "HERE2\n");

					char *newKey = key;

					for(int i = strlen(newKey)-1; i>=0; i--){
						if(newKey[i]=='['){
							newKey[i]=0;
							break;
						}
					}

					SymbolInfo *temp = symbolTable->lookUp(newKey);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, $1->getKey());
						sem_error++;

					}
					else{
						temp->intVal = $$->intVal;
						temp->floatVal = $$->floatVal;

						temp->setArrIdx($1->getArrIdx());

						if(strcmp(temp->getVarType(), "INT")==0){
							temp->setIntListVal($$->getArrIdx(), $$->intVal);	
						}
						else if(strcmp(temp->getVarType(), "FLOAT")==0){
							temp->setFloatListVal($$->getArrIdx(), $$->floatVal);	
						}

						char *tempCode = new char[200];
						char *tempVar = newTempVar();
						sprintf(tempCode, "LEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, SI[BX] \nMOV %s, CX \nDEC CX \nMOV SI[BX], CX\n", 
												$1->getTempVar(), $1->getArrIdx(), $1->getArrIdx(), tempVar);
						
						$$->setCode(tempCode);         
						$$->setTempVar(tempVar);         
						delete[] tempCode;


						


					}

					/*temp = symbolTable->lookUp(newKey);
					
					if (temp!=NULL){
						fprintf(logout, "Here4\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					
						fprintf(logout, "%d\n", temp->getIntListVal($1->getArrIdx()) );	
						
					}*/

				}

			fprintf(logout, "%s\n\n", $$->getKey());
					fprintf(codeLog, "%s\n\n", $$->getCode());

			delete[] str;

		}
		;
	
argument_list 	: arguments
			  	{	//done 			//NOTHING TO DO
					fprintf(parseout, "argument_list : arguments\n");
					fprintf(logout, "Line No %d -> argument_list : arguments\n", line_count);
					fprintf(codeLog, "Line No %d -> argument_list : arguments\n", line_count);

					$$ = $1;
					$$->setType("argument_list");
					fprintf(logout, "%s\n\n", $$->getKey());
					fprintf(codeLog, "%s\n\n", $$->getCode());

			  	}
			  	|
			  	{	//done
					fprintf(parseout, "argument_list : <empty>\n");
					fprintf(logout, "Line No %d -> argument_list : <empty>\n", line_count);
					fprintf(codeLog, "Line No %d -> argument_list : <empty>\n", line_count);

					argNo=0;

					$$ = new SymbolInfo("","argument_list");
					fprintf(logout, "%s\n\n", $$->getKey());
					fprintf(codeLog, "%s\n\n", $$->getCode());

			  	}
			  	;
	
arguments 	: arguments COMMA logic_expression
	      	{	//done
				fprintf(parseout, "arguments : arguments COMMA logic_expression\n");
				fprintf(logout, "Line No %d -> arguments : arguments COMMA logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> arguments : arguments COMMA logic_expression\n", line_count);

				$$ = $1;

				char *str = new char[strlen($1->getKey()) + strlen($3->getKey()) + 50];
				sprintf(str, "%s,%s", $1->getKey(), $3->getKey());

				$$->setKey(str);
				$$->setType("arguments");
	
				fprintf(logout, "%s\n\n", $$->getKey());

				delete[] str;

				SymbolInfo* temp = new SymbolInfo();
				
				$3->copyInfoTo(temp);
				temp->setType("arguments");

				argList[argNo] = temp;

				argNo++;

				char *tempCode = new char[strlen($1->getCode())+strlen($3->getCode())+200];

				sprintf(tempCode, "%s \n%s \nPUSH %s \n", $1->getCode(), $3->getCode(), $3->getTempVar());


				$$->setCode(tempCode);

				delete[] tempCode;

					fprintf(logout, "%s\n\n", $$->getKey());
					fprintf(codeLog, "%s\n\n", $$->getCode());
				

	      	}
	      	| logic_expression
	      	{		//done
				fprintf(parseout, "arguments : logic_expression\n");
				fprintf(logout, "Line No %d -> arguments : logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> arguments : logic_expression\n", line_count);

				$$ = $1;
				$$->setType("arguments");
				fprintf(logout, "%s\n\n", $$->getKey());

				argNo = 0;

				SymbolInfo* temp = new SymbolInfo();

				char *tempCode = new char[strlen($1->getCode())+200];

				sprintf(tempCode, "%s \nPUSH %s \n",$1->getCode(), $1->getTempVar());
				
				$1->copyInfoTo(temp);

				$$->setCode(tempCode);
				delete[] tempCode;

				temp->setType("arguments");

				argList[argNo] = temp;

				argNo++;

					fprintf(logout, "%s\n\n", $$->getKey());
					fprintf(codeLog, "%s\n\n", $$->getCode());

	      	}
	      	;
 

%%
int main(int argc,char *argv[])
{	FILE *fp;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	parseout = fopen("1505080_parse.txt","w");
	logout= fopen("1505080_log.txt","w");
	errorout = fopen("1505080_error.txt","w");
	codeout = fopen("1505080_code.asm","w");
	codeLog = fopen("1505080_codeLog.txt","w");
	
	if(parseout==NULL || logout==NULL || errorout==NULL || codeout==NULL || codeLog==NULL){
		printf("Cannot Open Output File.\n");
		exit(1);

	}

	symbolTable = new SymbolTable(13);
	symbolTable->enterScope();

	parList = new SymbolInfo*[20];
	argList = new SymbolInfo*[20];

	yyin=fp;
	yyparse();

	symbolTable->printAllScopeTable(logout);


	fprintf(logout, "\n\nLine count = %d\n", line_count);
	fprintf(logout, "Lexical error count = %d\n", lex_error);	
	fprintf(logout, "Semantic error count = %d\n", sem_error);		
	fprintf(errorout, "\nSemantic error count = %d\n", sem_error);
	
	if(lex_error+sem_error)
		printf("Errors = %d\n", lex_error+sem_error);

	fclose(parseout);
	fclose(logout);
	fclose(errorout);
	fclose(codeout);
	fclose(codeLog);
	fclose(yyin);


	//code optimization

	FILE *optCode = fopen("1505080_OptCode.asm","w");
	codeout = fopen("1505080_code.asm","r");

	if(codeout==NULL || optCode==NULL){
		printf("Cannot Open Output File.\n");
		exit(1);

	}

	char *str1 = new char[100];
	char *str2 = new char[200];

	char *dst1 = new char[20];
	char *dst2 = new char[20];
	char *src1 = new char[20];
	char *src2 = new char[20];

	char *dummy = new char[20];

	fgets(str1, 100, codeout);
	//fprintf(optCode, "%s\n", str1);

	while(fgets(str2, 100, codeout)!=NULL){	
		if(strcmp(str2, "")==0 || strcmp(str2, " ")==0 || strcmp(str2, " \n")==0 || str2[0]==0 || str2[0]=='\n'){
			//printf("NEW LINE\n");
			continue;
		}
		else{
			fprintf(optCode, "%s", str1);
	
		}

		if(str1[0]=='M' && str2[0]=='M' && str1[1]=='O' && str2[1]=='O' && str1[2]=='V' && str2[2]=='V'){
			sscanf(str1, "%s %s %s", dummy, dst1, src1);
			sscanf(str2, "%s %s %s", dummy, dst2, src2);

			dst1[strlen(dst1)-1]=0;
			dst2[strlen(dst2)-1]=0;
			//printf("%s, %s \t%s, %s\n", dst1, src1, dst2, src2);
			if(strcmp(dst1, src2)==0 && strcmp(dst2, src1)==0){
				printf("OPTIMIZATION : MOV %s, %s \tMOV %s, %s\n", dst1, src1, dst2, src2);
				//sprintf(str1, ";%s", str2);
				strcpy(str1,  ";");
				strcat(str1, str2);

			}
			else{
				strcpy(str1, str2);
			}


		}
		else{
			strcpy(str1, str2);	
		}

		
		
	}

	fprintf(optCode, "%s", str1);

	fclose(optCode);
	fclose(codeout);


	
	return 0;
}

