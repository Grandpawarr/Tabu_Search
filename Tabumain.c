#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "tabusearch.h"

int main()
{
    //random seed
    srand(time(NULL));

    //printf("hello tabusearch.c\n");
    
    //initial Tabu
    tabu_t *head=T_initial();
    //Iteration
    for(int i=1;i<NumberOfIteration;i++){
       // printf("====================\t%d\t==================\n",i);
        head->Move(head);
       // head->Display(head);
    }

    //final the Best value
    printf("====================\tFINAL\t==================\n");
    printf("The Best vlaue is : \n");
    head->Best.Display(&head->Best);
    
    printf("Press Enter to exit...\n");
    while(getchar()!='\n'){};
    return 0;

}