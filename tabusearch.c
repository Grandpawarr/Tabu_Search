#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tabusearch.h"

tabu_t* T_initial()
{
    /*initial TabuSearch*/
    //allocating memory
    tabu_t *Tnew=(tabu_t*)malloc(sizeof(tabu_t));

    //Initializing history list size
    Tnew->listsize=0;
    Tnew->showsize=0;

    //Initializing interface for access to functions
    Tnew->Move=TabuSearch_Move;
    Tnew->Algo=TabuSearch_Algo;
    Tnew->Addlist=TabuSearch_AddHistoryList;
    Tnew->Display=TabuSearch_Display;

    /*generate random Deception Problem*/ 
    //random cofiguration bit length
    char* Dstr=(char*)malloc(sizeof(char)*(MaxBit+1));
    assert(Dstr);

    //random cofiguration bit contant
    for(int i=0;i<MaxBit;i++)
        Dstr[i]=getRandom(0,1)+'0';
    Dstr[MaxBit]='\0';

    //add Deception Problem to history lsit
    deception_t *Dnew=D_new(Dstr);
    Tnew->histoylist[0]=*Dnew;
    Tnew->Best=Tnew->histoylist[0];

    /*print initial value*/
    printf("The Initial value:\n");
    Tnew->histoylist[0].Display(&Tnew->histoylist[0]);
     
    Tnew->showsize++;

    free(Dstr);

    return Tnew;
}

void TabuSearch_Move(tabu_t* head)
{
    /*generate next Deception Problem via preview*/
    char* str;
    //confirm whether it is in the history list
    int loop=1;
    while(loop){
        //Algo generate string
        str=head->Algo(head->histoylist[head->listsize].Dbinary);
        //determine
        int found =0;
        for(int i=0;i<head->showsize;i++){   
            if(strcmp(str,head->histoylist[i].Dbinary)==0){
                found=1;
                break;
            }
        }
        if(!found)
            loop=0;
    }

    //add Deception Problem to history lsit
    deception_t *Dnew=D_new(str);
    //Dnew->Display(Dnew);//////////////////////////test
    head->Addlist(head,Dnew);
}

char* TabuSearch_Algo(char* Dstr)
{
    /*generate next Deception Problem via preview*/
    char* str=(char*)malloc(sizeof(char)*(MaxBit+1));
    assert(str);

    //Copy the previous value
    strcpy(str,Dstr);
    //Randomly update a bit and 
    //Algo:swap two random postion
    int pos1,pos2;
    do{
        pos1=getRandom(0,MaxBit-1);
        pos2=getRandom(0,MaxBit-1);
    }while((str[pos1]==str[pos2]));

    char tmp=str[pos1];
    str[pos1]=str[pos2];
    str[pos2]=tmp;

    return str;
}

void TabuSearch_AddHistoryList(tabu_t* head,deception_t* D)
{
    //Determine the history list is full
    if(head->listsize+1>HistoryListSize-1)
        head->listsize=-1;

    //add Deception Problem to history list
    head->histoylist[++head->listsize]=*D;

    //printf("(%d)\n",head->listsize);/////////////////////test

    //update showsize;
    if(head->showsize<HistoryListSize)
        head->showsize++;

    //Judgment Best value
    if(*D->Dvalue>*head->Best.Dvalue)
        head->Best=*D;
}

void TabuSearch_Display(tabu_t* head)
{

    //show history list
    for(int i=0;i<head->showsize;i++){
        printf("[%d] ",i);
        head->histoylist[i].Display(&head->histoylist[i]);
    }

    //show Best solution
    printf("Best:");
    head->Best.Display(&head->Best);
}


