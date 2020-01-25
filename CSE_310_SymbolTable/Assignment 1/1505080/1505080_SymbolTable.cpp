///Symbol Table Offline by 1505080

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

#define MAXKEYSIZE  20
#define largePrime 67280421310721

using namespace std;

FILE *outputFP;

unsigned long long hashFunc(char *str){
    unsigned long long hashVal = 5381;

    for (int i = 0; str[i]!=0; i++) {
        hashVal = ( (((hashVal << 5 ) + hashVal) %largePrime ) ^ (unsigned long long) str[i] ) %largePrime ;
    }

    return hashVal;
}

class SymbolInfo{
    char* key;
    char* type;

public:
    char *getKey() const {
        return key;
    }
    void setKey(char *newKey) {
        strcpy(key, newKey);
    }

    char *getType() const {
        return type;
    }
    void setType(char *newType) {
        strcpy(type, newType);
    }

    SymbolInfo *nextData;   ///for implementing separate chaining

    SymbolInfo(char * str, char* data, SymbolInfo *next = NULL){
        key = new char[MAXKEYSIZE];
        strcpy(key, str);

        type = new char[MAXKEYSIZE];
        strcpy(type, data);

        nextData = next;
        //delete []str;
    }

    ~SymbolInfo(){
        //printf("Destroying Symbol Info...\n");
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
    unsigned long long (*hFunction) (char *str);
    int tableSize;
    int tableNumber;

    ScopeTable *parentScope;


public:
    ScopeTable(int size, int number, ScopeTable *parent = NULL){
        tableSize = size;
        tableNumber = number;
        parentScope = parent;

        hFunction = hashFunc;   ///desired hash function

        arr = new SymbolInfo*[tableSize+5];
        for(int i=0; i<tableSize; i++){
            arr[i] = NULL;
        }

        printf("New Scope Table with ID # %d created\n", tableNumber);
        fprintf(outputFP, "New Scope Table with ID # %d created\n", tableNumber);

    }

    ~ScopeTable(){
        printf("Destroying Scope Table No: %d...\n", tableNumber);
        fprintf(outputFP, "Destroying Scope Table No: %d...\n", tableNumber);

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

    bool deleteData(char *str){
        int idx = (int) (hFunction(str) % tableSize);

        if(arr[idx] == NULL){
            printf("%s Not found to be deleted from scope # %d\n", str, tableNumber);
            fprintf(outputFP, "%s Not found to be deleted from scope # %d\n", str, tableNumber);
            return false;
        }


        SymbolInfo *temp = arr[idx];
        SymbolInfo *par = NULL;

        int i = 0;

        if(strcmp(arr[idx]->getKey(), str)==0 ){    ///data in head
            arr[idx] = arr[idx]->nextData;
            temp->nextData = NULL;
            delete temp;

            printf("Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
            fprintf(outputFP, "Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
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

                printf("Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
                fprintf(outputFP, "Deleted entry at %d, %d from current ScopeTable with ID # %d\n", idx, i, tableNumber);
                return true;
            }
            par = temp;
            temp = par->nextData;
            i++;

        }

        printf("%s Not found to be deleted from scope # %d\n", str, tableNumber);
        fprintf(outputFP, "%s Not found to be deleted from scope # %d\n", str, tableNumber);
        return false;
    }

    bool insertData(char *str, char* type){
        if(lookUp(str)!=NULL){
            printf("< %s  , %s > already exists in current ScopeTable\n", str, type);
            fprintf(outputFP, "< %s  , %s > already exists in current ScopeTable\n", str, type);
            return false;
        }
        int idx = (int) (hFunction(str) % tableSize);
        SymbolInfo *temp = new SymbolInfo(str, type);

        if(arr[idx]==NULL){ ///head is null
            arr[idx] = temp;
            printf("Inserted in ScopeTable# %d at position %d, 0\n", tableNumber, idx);
            fprintf(outputFP, "Inserted in ScopeTable# %d at position %d, 0\n", tableNumber, idx);
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

            printf("Inserted in ScopeTable# %d at position %d, %d\n", tableNumber, idx, i);
            fprintf(outputFP, "Inserted in ScopeTable# %d at position %d, %d\n", tableNumber, idx, i);

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

    void printScopeTable(){
        printf("\nScope Table # %d\n", getTableNumber());
        fprintf(outputFP, "\nScope Table # %d\n", getTableNumber());
        SymbolInfo *temp = NULL;

        for(int i=0; i<tableSize; i++){
            printf("%d --> ", i);
            fprintf(outputFP, "%d --> ", i);
            temp = arr[i];

            while(temp!=NULL){
                printf("< %s : %s > ", temp->getKey(), temp->getType());
                fprintf(outputFP, "< %s : %s > ", temp->getKey(), temp->getType());

                temp = temp->nextData;
            }

            printf("\n");
            fprintf(outputFP, "\n");


        }
    }


};

class SymbolTable{
    vector <ScopeTable*> listOfTables;
    int numberOfScopes;
    ScopeTable *currentScope;

    int numberOfBuckets;

public:
    SymbolTable(int n){
        numberOfBuckets = n;
        numberOfScopes = 0;
        currentScope = NULL;

        //listOfTables.resize(numberOfScopes+5);
        //ScopeTable *temp = new ScopeTable(numberOfBuckets, numberOfScopes, NULL);
        //listOfTables.at(numberOfScopes) = temp;
        //currentScope = temp;


    }

    ~SymbolTable(){
        printf("Deleting Symbol Table...\n");
        fprintf(outputFP, "Deleting Symbol Table...\n");

        currentScope = NULL;
        for(int i=0; i<=numberOfScopes; i++){
            if(listOfTables.at(i)!=NULL){
                delete listOfTables.at(i);
                listOfTables.at(i) = NULL;
            }
        }

        numberOfScopes = 0;

    }

    bool enterScope(){
        numberOfScopes++;
        listOfTables.resize(numberOfScopes+5);

        ScopeTable *temp = new ScopeTable(numberOfBuckets, numberOfScopes, currentScope);
        listOfTables.at(numberOfScopes) = temp;
        currentScope = temp;

        return true;
    }

    bool exitScope(){
        if(currentScope==NULL){
            printf("NO SCOPE\n");
            fprintf(outputFP, "NO SCOPE\n");
            return false;
        }

        ScopeTable *temp = currentScope;
        currentScope = temp->getParentScope();

        listOfTables.at(temp->getTableNumber()) = NULL;

        printf("ScopeTable with id %d removed\n", temp->getTableNumber());
        fprintf(outputFP, "ScopeTable with id %d removed\n", temp->getTableNumber());
        delete temp;
        temp = NULL;

        return true;

    }

    bool insert(char* key, char* type){
        if(currentScope==NULL) {
            //printf("NO SCOPE\n");
            //fprintf(outputFP, "NO SCOPE\n");
            enterScope();
            //return false;
        }

        return currentScope->insertData(key, type);

    }

    bool remove(char *key){
        if(currentScope==NULL) {
            printf("NO SCOPE\n");
            fprintf(outputFP, "NO SCOPE\n");
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

        printf("%s not found\n", key);
        fprintf(outputFP, "%s not found\n", key);

        return NULL;

    }

    void printCurrentScopeTable(){
        if(currentScope==NULL) {
            printf("NO SCOPE\n");
            fprintf(outputFP, "NO SCOPE\n");
            return;
        }
        currentScope->printScopeTable();
    }

    void printAllScopeTable(){
        for(int i=0; i<= numberOfScopes; i++){
            if(listOfTables.at(i)!=NULL){
                listOfTables.at(i)->printScopeTable();
            }
        }
    }




};

int main() {
    FILE *inputFP= NULL;
    inputFP= fopen("1505080_input.txt", "r");
    if(inputFP==NULL){
        printf("ERROR OPENING INPUT FILE\n");
        return 0;
    }

    outputFP = NULL;
    outputFP = fopen("1505080_output.txt", "w");
    if(outputFP==NULL){
        printf("ERROR OPENING OUTPUT FILE\n");
        return 0;
    }

    fprintf(outputFP, "***OUTPUT***\n\n");

    SymbolTable* symbolTable;

    char *inputSTR = new char[120];

    if( fgets(inputSTR, 100, inputFP) !=NULL){
        int n;
        sscanf(inputSTR, "%d", &n);

        symbolTable = new SymbolTable(n);

    }
    else{
        printf("Invalid Input\n");
        fprintf(outputFP, "Invalid Input\n");
        return  0;
    }

    char *str = new char[120];
    char *str1 = new char[120];
    char *str2 = new char[120];

    while( fgets(inputSTR, 100, inputFP)!=NULL ){
        printf("%s\n", inputSTR);
        fprintf(outputFP, "%s\n", inputSTR);

        if(inputSTR[0] == 'I'){
            sscanf(inputSTR, "%s %s %s", str, str1, str2);

            bool success = symbolTable->insert(str1, str2);

        }
        else if(inputSTR[0] == 'L'){
            sscanf(inputSTR, "%s %s", str, str1);

            SymbolInfo *symbolInfo = symbolTable->lookUp(str1);

        }
        else if(inputSTR[0] == 'D'){
            sscanf(inputSTR, "%s %s", str, str1);

            bool success = symbolTable->remove(str1);
        }
        else if(inputSTR[0] == 'P'){
            if(inputSTR[2] == 'A'){
                symbolTable->printAllScopeTable();
            }
            else if(inputSTR[2] == 'C'){
                symbolTable->printCurrentScopeTable();
            }

        }
        else if(inputSTR[0] == 'S'){
            symbolTable->enterScope();
        }
        else if(inputSTR[0] == 'E'){
            symbolTable->exitScope();
        }
        else {
            printf("Invalid Input");
            fprintf(outputFP, "Invalid Input\n");
        }

        printf("\n");
        fprintf(outputFP, "\n");

    }

    delete symbolTable;

    return 0;
}
