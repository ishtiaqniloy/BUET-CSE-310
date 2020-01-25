///Symbol Table Implementation of 1505080

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#define MAXKEYSIZE 200
#define MAXARRSIZE 200
#define largePrime 67280421310721


class SymbolInfo{
    char* key;
    char* type;
    char* code;
    char* tempVar;

    char* IDType;   //VAR, ARR, FUNC

    char* varType;  //INT, FLOAT, VOID

    int arrSize;    //integer value
    int arrIdx;

    char* funcRetType;  //int, float, void for FUNC
    bool funcIsDefined;   //true, false  for FUNC

    int paramNo;

    int scopeNo;

public:

    int* intList;   //for ARR
    float* floatList;

    int intVal;
    float floatVal;

    SymbolInfo** paramList;   // for FUNC

    char *getCode(){
        if(code==NULL){
            code = new char[10];
            code[0] = 0;
        }
        return code;
    }

    void setCode(char *cd) {
        if(code==NULL){
            code = new char[strlen(cd)+20];
        }
        else{
            delete[] code;
            code = new char[strlen(cd)+20];
        }

        strcpy(code, cd);
        //sprintf(code, "%s", cd);
    }

    int getScopeNo() const {
        return scopeNo;
    }

    void setScopeNo(int scopeNo) {
        SymbolInfo::scopeNo = scopeNo;
    }

    char *getTempVar(){
        if(tempVar==NULL){
            tempVar = new char[20];
            tempVar[0] = 0;
        }
        return tempVar;
    }

    void setTempVar(char *tv) {
        if(tempVar==NULL || strlen(tv)>=20){
            tempVar = new char[strlen(tv)+20];
        }
        strcpy(tempVar, tv);
    }


    char *getKey() {  return key; }
    void setKey(char *newKey) {
        if(strlen(newKey)>=MAXKEYSIZE-5){
            delete[] key;
            key = new char[strlen(newKey)+100];
        }
        strcpy(key, newKey);
    }

    char *getType() { return type; }
    void setType(char *newType) { strcpy(type, newType); }

    char *getIDType() {
        if(IDType==NULL){
            IDType = new char[20];
            IDType[0] = 0;
        }
        return IDType;
    }
    void setIDType(char *newIDType) {
        IDType = new char[20];
        strcpy(IDType, newIDType);

        if(IDType!=NULL && strcmp(IDType, "FUNC")==0){
            paramNo = 0;
            paramList = new SymbolInfo*[20];
        }

    }

    char * getVarType() {
        if(varType==NULL){
            varType = new char[20];
            varType[0]=0;
        }
        return varType;
    }
    void setVarType(char *newVarType) {
        varType = new char[20];

        strcpy(varType, newVarType);

        if(IDType!=NULL && strcmp(IDType, "ARR")==0){
            if (strcmp(varType, "INT")==0){
                intList  = new int[arrSize];
                for(int i=0; i<arrSize; i++){
                    intList[i]=-99;
                }
            }
            else if (strcmp(varType, "FLOAT")==0){
                floatList = new float[arrSize];
                for(int i=0; i<arrSize; i++){
                    floatList[i]=-100;
                }
            }

        }

    }

    int getArrSize() {return arrSize; }
    void setArrSize(int newArrSize) { arrSize = newArrSize;  }

    int getArrIdx() { return arrIdx;}
    void setArrIdx(int newArrIdx) {
        arrIdx = newArrIdx;

        if(getVarType()!=NULL && strcmp(getVarType(), "INT")==0){
            setIntVal(getIntListVal(arrIdx) );
        }
        else if(getVarType()!=NULL && strcmp(getVarType(), "FLOAT")==0){
            setFloatVal(getFloatListVal(arrIdx));
        }

    }

    char *getFuncRetType() {
        if(funcRetType==NULL){
            funcRetType = new char[20];
            funcRetType[0]=0;
        }
        return funcRetType;
    }
    void setFuncRetType(char *newFuncRetType) {
        funcRetType = new char[20];
        strcpy(funcRetType, newFuncRetType);

        if(strcmp(funcRetType,"int")==0){
            setVarType("INT");
        }
        else if(strcmp(funcRetType,"float")==0){
            setVarType("FLOAT");
        }
        else{
            setVarType("VOID");
        }


    }

    bool getFuncIsDefined() {return funcIsDefined; }
    void setFuncIsDefined(bool newFuncIsDefined) {funcIsDefined = newFuncIsDefined; }

    int getParamNo() { return paramNo; }
    void setParamNo(int newParamNo) { paramNo = newParamNo; }

    int getIntVal() { return intVal; }
    void setIntVal(int newIntVal) { intVal = newIntVal; }

    float getFloatVal() { return floatVal; }
    void setFloatVal(float newFloatVal) { floatVal = newFloatVal; }


    SymbolInfo *nextData;   ///for implementing separate chaining

    void copyInfoTo(SymbolInfo* newInfo){
        newInfo->setKey(this->getKey());
        newInfo->setType(this->getType());
        newInfo->setCode(this->code);
        newInfo->setTempVar(this->tempVar);

        newInfo->setArrSize(this->arrSize);
        newInfo->setArrIdx(this->arrIdx);
        newInfo->setParamNo(this->paramNo);

        newInfo->intVal = this->intVal;
        newInfo->floatVal = this->floatVal;

        newInfo->setFuncIsDefined(this->funcIsDefined);



        if(IDType!=NULL){
            newInfo->setIDType(IDType);
        }
        if(varType!=NULL){
            newInfo->setVarType(varType);
        }
        if(funcRetType!=NULL){
            newInfo->setFuncRetType(funcRetType);
        }

        if(intList!=NULL){
            for(int i=0; i<arrSize; i++){
                newInfo->intList[i] = this->intList[i];
            }

        }
        if(floatList!=NULL){
            for(int i=0; i<arrSize; i++){
                newInfo->floatList[i] = this->floatList[i];
            }
        }

        if(paramList!=NULL){
            for(int i=0; i<20; i++){
                newInfo->paramList[i] = this->paramList[i];
            }

        }




    }

    int getIntListVal(int idx){
        if(intList==NULL)
            return -1;

        return intList[idx];
    }

    float getFloatListVal(int idx){
        if(floatList==NULL)
            return -1;

        return floatList[idx];
    }

    int setIntListVal(int idx, int newVal){
        if(intList==NULL)
            return -1;

        return intList[idx] = newVal;
    }

    float setFloatListVal(int idx, float newVal){
        if(floatList==NULL)
            return -1;

        return floatList[idx] = newVal;
    }


    SymbolInfo(char * strKey, char* strType, SymbolInfo *next = NULL){

        key = new char[MAXKEYSIZE];
        if(strlen(strKey)>=MAXKEYSIZE-5){
            delete[] key;
            key = new char[strlen(strKey)+100];
        }
        strcpy(key, strKey);

        type = new char[MAXKEYSIZE];
        strcpy(type, strType);

        code = new char[MAXKEYSIZE];
        code[0]=0;

        tempVar = new char[20];
        tempVar[0]=0;

        nextData = next;
        //delete []str;

        IDType = NULL;   //VAR, ARR, FUNC

        varType = NULL;  //INT, FLOAT, CHAR

        arrSize = 0;    //CONST_INT
        arrIdx = 0;

        funcRetType = NULL;  //INT, FLOAT, VOID
        funcIsDefined = false;   //true, false


        intList = NULL;
        floatList = NULL;

        paramNo = 0;
        paramList = NULL;


    }

    SymbolInfo(){

        key = new char[MAXKEYSIZE];

        type = new char[MAXKEYSIZE];

        code = new char[MAXKEYSIZE];
        code[0]=0;

        tempVar = new char[20];
        tempVar[0]=0;

        nextData = NULL;
        //delete []str;

        IDType = NULL;   //VAR, ARR, FUNC

        varType = NULL;  //INT, FLOAT, CHAR

        arrSize = 0;    //CONST_INT
        arrIdx = 0;

        funcRetType = NULL;  //INT, FLOAT, VOID
        funcIsDefined = false;   //true, false


        intList = NULL;
        floatList = NULL;

        paramNo = 0;
        paramList = NULL;


    }

    ~SymbolInfo(){
        ////printf("Destroying Symbol Info...\n");
        delete[] key;
        key = NULL;
        delete[] type;
        type = NULL;
        delete nextData;
        nextData = NULL;
    }

};


class ScopeTable{
    SymbolInfo **arr;
    int tableSize;
    int tableNumber;

    ScopeTable *parentScope;

    unsigned long long hFunction(char *str){
        unsigned long long hashVal = 5381;

        for (int i = 0; str[i]!=0; i++) {
            hashVal = ( (((hashVal << 5 ) + hashVal) %largePrime ) ^ (unsigned long long) str[i] ) %largePrime ;
        }

        return hashVal;
    }

public:
    ScopeTable(int size, int number, ScopeTable *parent = NULL){
        tableSize = size;
        tableNumber = number;
        parentScope = parent;

        arr = new SymbolInfo*[tableSize+5];
        for(int i=0; i<tableSize; i++){
            arr[i] = NULL;
        }

        //printf("New Scope Table with ID # %d created\n", tableNumber);
        //fprintf(outputFP, "New Scope Table with ID # %d created\n", tableNumber);

    }

    ~ScopeTable(){
        //printf("Destroying Scope Table No: %d...\n", tableNumber);
        //fprintf(outputFP, "Destroying Scope Table No: %d...\n", tableNumber);

        for(int i=0; i<tableSize; i++){
            if(arr[i]!=NULL){
                delete arr[i];
                arr[i] = NULL;
            }
        }
        delete []arr;

        parentScope = NULL;

    }

    SymbolInfo* lookUp(char *str){
        int idx = (int) (hFunction(str) % tableSize);

        if(arr[idx] == NULL){
            //printf("%s not found in Scope Table # %d\n", str, tableNumber);
            return NULL;
        }


        SymbolInfo *temp = arr[idx];

        int i=0;
        while(temp!=NULL){
            if(strcmp(temp->getKey(), str) == 0){
                //printf("Found in ScopeTable# %d at position %d, %d\n", tableNumber, idx, i);
                return temp;

            }
            i++;
            temp = temp->nextData;

        }

        //printf("%s not found in Scope Table # %d\n", str, tableNumber);
        return NULL;

    }

    int lookUpNo(char *str){
        int idx = (int) (hFunction(str) % tableSize);

        if(arr[idx] == NULL){
            //printf("%s not found in Scope Table # %d\n", str, tableNumber);
            return -1;
        }


        SymbolInfo *temp = arr[idx];

        int i=0;
        while(temp!=NULL){
            if(strcmp(temp->getKey(), str) == 0){
                //printf("Found in ScopeTable# %d at position %d, %d\n", tableNumber, idx, i);
                return getTableNumber();

            }
            i++;
            temp = temp->nextData;

        }

        //printf("%s not found in Scope Table # %d\n", str, tableNumber);
        return -1;

    }

    bool deleteData(char *str){
        int idx = (int) (hFunction(str) % tableSize);

        if(arr[idx] == NULL){
            //printf("%s Not found to be deleted from scope # %d\n", str, tableNumber);
            //fprintf(outputFP, "%s Not found to be deleted from scope # %d\n", str, tableNumber);
            return false;
        }


        SymbolInfo *temp = arr[idx];
        SymbolInfo *par = NULL;

        int i = 0;

        if(strcmp(arr[idx]->getKey(), str)==0 ){    ///data in head
            arr[idx] = arr[idx]->nextData;
            temp->nextData = NULL;
            delete temp;

            //printf("Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
            //fprintf(outputFP, "Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
            return true;
        }

        par = temp;
        temp = par->nextData;
        i=1;
        while(temp!=NULL){
            if(strcmp(temp->getKey(), str) == 0){
                par->nextData = temp->nextData;
                temp->nextData = NULL;
                delete temp;

                //printf("Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
                //fprintf(outputFP, "Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
                return true;
            }
            par = temp;
            temp = par->nextData;
            i++;

        }

        //printf("%s Not found to be deleted from scope # %d\n", str, tableNumber);
        //fprintf(outputFP, "%s Not found to be deleted from scope # %d\n", str, tableNumber);
        return false;
    }

    bool insertData(char *str, char* type){
        if(lookUp(str)!=NULL){
            //printf("< %s  , %s > already exists in current ScopeTable\n", str, type);
            //fprintf(outputFP, "< %s  , %s > already exists in current ScopeTable\n", str, type);
            return false;
        }
        int idx = (int) (hFunction(str) % tableSize);
        SymbolInfo *temp = new SymbolInfo(str, type);

        if(arr[idx]==NULL){ ///head is null
            arr[idx] = temp;
            //printf("Inserted in ScopeTable# %d at position %d, 0\n", tableNumber, idx);
            //fprintf(outputFP, "Inserted in ScopeTable# %d at position %d, 0\n", tableNumber, idx);
            return true;
        }

        else{           ///head is not null

            ///inserting at tail
            SymbolInfo *iter = arr[idx];
            int i = 1;

            while(iter->nextData!=NULL){
                i++;
                iter=iter->nextData;
            }
            iter->nextData = temp;

            //printf("Inserted in ScopeTable# %d at position %d, %d\n", tableNumber, idx, i);
            //fprintf(outputFP, "Inserted in ScopeTable# %d at position %d, %d\n", tableNumber, idx, i);

            return true;

            ///inserting at head
//            temp->nextData = arr[idx];
//            arr[idx] = temp;
//            return true;



        }

    }

    int getTableNumber(){
        return tableNumber;
    }

    ScopeTable* getParentScope(){
        return parentScope;
    }

    void printScopeTable(FILE *outputFP){
        //printf("\nScope Table # %d\n", getTableNumber());
        fprintf(outputFP, "\nScope Table # %d", getTableNumber());
        SymbolInfo *temp = NULL;

        for(int i=0; i<tableSize; i++){
            if(arr[i]!=NULL){
                //printf("\n%d --> ", i);
                fprintf(outputFP, "\n%d --> ", i);

            }
            temp = arr[i];

            while(temp!=NULL){
                //printf("< %s : %s > ", temp->getKey(), temp->getType());
                fprintf(outputFP, "< %s : %s,%s > ", temp->getKey(), temp->getIDType(), temp->getVarType());

                temp = temp->nextData;
            }



        }
        //printf("\n\n");
        fprintf(outputFP, "\n\n");

    }


};

class SymbolTable{
    ScopeTable** listOfTables;
    int numberOfScopes;

    int numberOfBuckets;

    ScopeTable *currentScope;

public:

    SymbolTable(int n){
        numberOfBuckets = n;
        numberOfScopes = 0;
        currentScope = NULL;

        listOfTables = new ScopeTable*[100];

        //listOfTables.resize(numberOfScopes+5);
        //ScopeTable *temp = new ScopeTable(numberOfBuckets, numberOfScopes, NULL);
        //listOfTables.at(numberOfScopes) = temp;
        //currentScope = temp;


    }

    ~SymbolTable(){
        //printf("Deleting Symbol Table...\n");
        //fprintf(outputFP, "Deleting Symbol Table...\n");

        currentScope = NULL;
        for(int i=0; i<=numberOfScopes; i++){
            if(listOfTables[i]!=NULL){
                delete listOfTables[i];
                listOfTables[i] = NULL;
            }
        }

        numberOfScopes = 0;

    }

    bool enterScope(){
        numberOfScopes++;

        ScopeTable *temp = new ScopeTable(numberOfBuckets, numberOfScopes, currentScope);
        listOfTables[numberOfScopes] = temp;
        currentScope = temp;

        //printf("Entering new Scope No = %d\n", numberOfScopes);

        return true;
    }

    bool exitScope(){
        if(currentScope==NULL){
            //printf("NO SCOPE\n");
            //fprintf(outputFP, "NO SCOPE\n");
            return false;
        }

        ScopeTable *temp = currentScope;
        currentScope = temp->getParentScope();

        listOfTables[temp->getTableNumber()] = NULL;

        //printf("ScopeTable with id %d removed\n", temp->getTableNumber());
        //fprintf(outputFP, "ScopeTable with id %d removed\n", temp->getTableNumber());
        delete temp;
        temp = NULL;

        return true;

    }

    bool insert(char* key, char* type){
        if(currentScope==NULL) {
            printf("NO SCOPE\n");
            //fprintf(outputFP, "NO SCOPE\n");
            enterScope();
            //return false;
        }

        return currentScope->insertData(key, type);

    }

    bool remove(char *key){
        if(currentScope==NULL) {
            //printf("NO SCOPE\n");
            //fprintf(outputFP, "NO SCOPE\n");
            return false;
        }

        return currentScope->deleteData(key);
    }

    SymbolInfo* lookUp(char *key){
        ScopeTable *temp = currentScope;

        while (temp!=NULL){
            SymbolInfo *tempItem = temp->lookUp(key);

            if(tempItem!=NULL){
                return tempItem;
            }
            temp = temp->getParentScope();

        }

        //printf("%s not found\n", key);
        //fprintf(outputFP, "%s not found\n", key);

        return NULL;

    }

    int lookUpNo(char *key){
        ScopeTable *temp = currentScope;

        while (temp!=NULL){
            int num = temp->lookUpNo(key);

            if(num!=-1){
                return num;
            }
            temp = temp->getParentScope();

        }

        //printf("%s not found\n", key);
        //fprintf(outputFP, "%s not found\n", key);

        return -1;

    }

    SymbolInfo* lookUpCurrent(char *key){

        if (currentScope!=NULL){
            SymbolInfo *tempItem = currentScope->lookUp(key);
            return tempItem;
        }

        //printf("%s not found\n", key);
        //fprintf(outputFP, "%s not found\n", key);
        else
            return NULL;

    }

    void printCurrentScopeTable(FILE *outputFP){
        if(currentScope==NULL) {
            //printf("NO SCOPE\n");
            fprintf(outputFP, "NO SCOPE\n");
            return;
        }
        currentScope->printScopeTable(outputFP);
    }

    void printAllScopeTable(FILE *outputFP){
        fprintf(outputFP, "***PRINTING SYMBOL TABLE***\n");
        //if(listOfTables.size()==0)  return;
        for(int i=0; i<= numberOfScopes; i++){
            if(listOfTables[i]!=NULL){
                listOfTables[i]->printScopeTable(outputFP);
            }
        }
    }

    int getScopeNum(){
        return currentScope->getTableNumber();
    }

    bool setScope(int n){
        if(listOfTables[n]!=NULL){
            currentScope = listOfTables[n];
            return true;

        }

        return false;
    }

    int getNumberOfScopes() const {
        return numberOfScopes;
    }


};
