#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>

#include "deceptionProblem.h"

deception_t *D_new(const char* const str)
{
    /*Dbinary input check*/
    if(strlen(str)>MaxBit*sizeof(char)){
        printf("Enter number must be less %d bits\n",MaxBit);
        exit(EXIT_FAILURE);
    }else{
        for(int i=0;i<strlen(str);i++){
            if(*(str+i)!='0'&& *(str+i)!='1'){
                printf("Enter number error:%c\n",*(str+i));
                exit(EXIT_FAILURE);
            }
        }
    }

    /*Initial Deception Problem*/
    //allocating memory
    deception_t* new=(deception_t*)malloc(sizeof(deception_t));
    assert(new);

    //Initializing interface for access to functions
    new->Delete=D_delete;
    new->Function=D_function;
    new->Display=D_display;

    //Dbinary setting
    new->Dbinary=(char*)malloc(sizeof(char)*(strlen(str)+1));
    assert(new->Dbinary);
    strcpy(new->Dbinary,str);

    //Calculation Deception Problem value
    new->Dvalue=malloc(sizeof(int));
    assert(new->Dvalue);
    D_function(new);

    return new;
}

void D_delete(deception_t* const D)
{
    free(D->Dbinary);
    free(D->Dvalue);
}

void D_function(deception_t* const D)
{
    //calculation the binary number length
    int len=strlen(D->Dbinary);
    for(int i=0;i<strlen(D->Dbinary);i++){
        if(D->Dbinary[i]=='1'){
            i=strlen(D->Dbinary)+1;
        }
        len--;
    }
    len++;

    //convery binary to decimal
    long long sum=0;
    long long base=1;

    for(int i=strlen(D->Dbinary)-1;i>=0;i--){
        if(D->Dbinary[i]=='1')
            sum +=base;
        base *=2;
    }
    //printf("**(binary)%lld,(pow)%ld**\n",sum,(long)pow(2,len-2));
    //function calculation
    sum = (long long)abs(sum - (long long)pow(2,len-2));
    //allocating memory
    *D->Dvalue = sum;
}

void D_display(deception_t* const D)
{
    assert(D);
    printf("input:%s, Dvalue:%lld\n",D->Dbinary,*(D->Dvalue));
}
