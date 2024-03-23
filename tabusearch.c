#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "tabusearch.h"

tabu_t *T_initial()
{
    /** Initial TabuSearch
     *  1.Allocation memory
     *  2.Initializing tabuSearch value
     *  3.Initializing interface for access to functions
     */
    tabu_t *Tnew = (tabu_t *)malloc(sizeof(tabu_t));
    if (!Tnew)
    {
        perror("message:");
        return 0;
    }

    Tnew->listsize = 0;
    Tnew->showsize = 0;

    Tnew->Move = TabuSearch_Move;
    Tnew->Algo = TabuSearch_Algo;
    Tnew->Addlist = TabuSearch_AddHistoryList;
    Tnew->Display = TabuSearch_Display;

    /** Generate the first Deception Problem
     *  1.allocation memory
     *  2.generate the bit contant
     */
    char *Dstr = (char *)calloc((int)(MaxBit) + 1, sizeof(char));
    if (!Dstr)
    {
        free(Tnew);
        perror("message:");
        return 0;
    }

    for (int i = 0; i < MaxBit; i++)
        Dstr[i] = getRandom(0, 1) + '0';

    /**
     * Add Deception Problem to the history list and the best value
     */
    deception_t *Dnew = D_new(Dstr);
    if (!Dnew)
    {
        free(Tnew);
        free(Dstr);
        perror("message:");
        return 0;
    }
    Tnew->histoylist[0] = *Dnew;

    Tnew->Best = Tnew->histoylist[0];

    /**
     * Print initial value
     */
    printf("The Initial value:\n");
    if (Tnew->histoylist[0].Display(&Tnew->histoylist[0]))
    {
        printf("!!Display!!\n");
    }
    Tnew->showsize++;

    free(Dstr);

    return Tnew;
}

void TabuSearch_Move(tabu_t *head)
{
    /** Generate next Deception Problem via preview
     *
     * str : Next Deception Problem bit
     * isLoop : Break while loop condition
     * isFind : Used to determine whether a is in the Tabu list
     *
     * Generate next Deception Problem via TabuSearch algorithm and
     * confirm whether it is in the Tabu list
     * If in the Tabu list,regerenate
     *
     */
    char *str;
    int isLoop = 1;
    while (isLoop)
    {
        str = head->Algo(head->histoylist[head->listsize].Dbinary);

        int isFound = 0;
        for (int i = 0; i < head->showsize; i++)
        {
            if (strcmp(str, head->histoylist[i].Dbinary) == 0)
            {
                isFound = 1;
                break;
            }
        }
        if (!isFound)
            isLoop = 0;
    }

    /**
     * Create Deception Problem
     * Add Deception Problem to the Tabu list
     */
    deception_t *Dnew = D_new(str);
    if (!Dnew)
    {
        perror("message:");
        return;
    }

    head->Addlist(head, Dnew);
}

char *TabuSearch_Algo(char *Dstr)
{
    /**
     * Allocate memory
     */
    char *str = (char *)calloc((int)MaxBit, sizeof(char));
    if (!str)
    {
        perror("message:");
        return 0;
    }

    /** Generate next Deception Problem via preview
     *
     *  1.Copy the previous value
     *  2.Randomly generate two position 
     *   if the bits in both position are the same,do it again
     *  3.Swap two charactor
     * 
     */

    strncpy(str, Dstr, MaxBit);

    int pos1, pos2;
    do
    {
        pos1 = getRandom(0, MaxBit - 1);
        pos2 = getRandom(0, MaxBit - 1);
    } while ((str[pos1] == str[pos2]));

    cSwap(&str[pos1], &str[pos2]);

    return str;
}

void TabuSearch_AddHistoryList(tabu_t *head, deception_t *D)
{
    /** Add new Deception Problem to Tabu history
     * 
     * 1.Determine the Tabu history is full,
     * if fully,update the listsize to -1
     * 2.Add Deception Problem to the Tabu history
     * 3.Update showsize
     * 
    */
    if (head->listsize + 1 > HistoryListSize - 1)
        head->listsize = -1;

    head->histoylist[++head->listsize] = *D;

    if (head->showsize < HistoryListSize)
        head->showsize++;

    /**
     * Judgment Best value
    */
    if (*D->Dvalue > *head->Best.Dvalue)
        head->Best = *D;
}

int TabuSearch_Display(tabu_t *head)
{
    /**
     * Show history list
     */
    for (int i = 0; i < head->showsize; i++)
    {
        printf("[%2d] ", i);
        if (head->histoylist[i].Display(&head->histoylist[i]))
        {
            printf("!!ERROR:Display!!\n");
            return 1;
        }
    }

    /**
     *  Show Best solution
     */
    printf("Best:");
    if (head->Best.Display(&head->Best))
    {
        printf("!!ERROR:Display!!\n");
        return 1;
    }

    return 0;
}
