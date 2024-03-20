#include "deceptionProblem.h"

#define HistoryListSize 20 //tabu list size
#define NumberOfIteration 1000 //1000
typedef struct TabuSearch tabu_t;

typedef void (*fptrMove)(tabu_t*);
typedef char* (*fptrAlgo)(char*);
typedef void (*fptrAddHistoryList)(tabu_t*,deception_t*);
typedef void (*fptrDisplay)(tabu_t*);


typedef struct TabuSearch 
{
    int listsize;//tabu list current length
    int showsize;//the value of How large an array needs to be displayed
    deception_t histoylist[HistoryListSize];//tabu list
    deception_t Best;//the Best solution
    fptrMove Move;
    fptrAlgo Algo;
    fptrAddHistoryList Addlist;
    fptrDisplay Display;

}tabu_t;

/*Initioal fisrt problem */
tabu_t* T_initial();

/*use for iteration*/
void TabuSearch_Move(tabu_t* head);

/*Algorithm for generating next solution*/
char* TabuSearch_Algo(char* Dstr);

/*Add deception problem to history list*/
void TabuSearch_AddHistoryList(tabu_t* head,deception_t* D);

/*show history list*/
void TabuSearch_Display(tabu_t* head);




