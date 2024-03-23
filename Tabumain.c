#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "tabusearch.h"

int main()
{
    // random seed
    srand(time(NULL));

    /** Tabu Search Initial
     * intial Tabu Search variable , function and
     * randomly create the first Deception Problem
     */
    tabu_t *head = T_initial();

    /** Iteration
     * Evolve the next problem by the algorithm
     * end after 1000 iteration
     * @note
     * comment at the bottom and delete it to generate the Tabu Search logs
     */
    for (int i = 1; i < NumberOfIteration; i++)
    {
        //printf("====================\t%d\t==================\n",i);

        head->Move(head);

        /*
        if (head->Display(head))
        { 
            printf("!!ERROR:Display!!\n");
        }
        */
        
    }

    /** Final
     * 1.show the best result for the ultimate Tabu Search
     * 2.pause the screen until enter is pressed
     */
    printf("====================\tFINAL\t==================\n");
    printf("The Best vlaue is : \n");
    if (head->Best.Display(&head->Best))
    {
        printf("!!Display!!\n");
    }

    printf("Press Enter to exit...\n");
    while (getchar() != '\n')
    {
    };

    return 0;
}