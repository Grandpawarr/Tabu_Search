// hello
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <errno.h>

#include "deceptionProblem.h"

deception_t *D_new(const char *const str)
{
    /**
     * str check
     * confirm whether the entered str is legal
     * 1.determines whether the number of characters in a string is within the specified limit
     * 2.determine whether the number of characters in the string is 0/1 or not
     */
    int len = strlen(str);
    if (len != MaxBit * sizeof(char))
    {
        printf("!!Error:enter number must be match %d bits!!\n", (int)MaxBit);
        return 0;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (*(str + i) != '0' && *(str + i) != '1')
            {
                printf("!!Error:enter char must be 0 or 1!!\n");
                return 0;
            }
        }
    }

    /** Initial Deception Problem
     * 1.allocation memory
     * 2.initializing interface for access to functions
     */
    deception_t *new = (deception_t *)malloc(sizeof(deception_t));
    if (!new)
    {
        perror("message:");
        return 0;
    }

    new->Delete = D_delete;
    new->Function = D_function;
    new->Display = D_display;

    /*
     * Dbinary setting
     * copy str to Dbinary
     */
    new->Dbinary = (char *)calloc(len + 1, sizeof(char));
    if (!new->Dbinary)
    {
        perror("message:");
        return 0;
    }
    strncpy(new->Dbinary, str, len);

    /*
     * setting Dvalue
     * calculation Deception Problem value
     */
    new->Dvalue = malloc(sizeof(int));
    if (!new->Dbinary)
    {
        perror("message:");
        return 0;
    }
    D_function(new);

    return new;
}

void D_delete(deception_t *const D)
{
    free(D->Dbinary);
    free(D->Dvalue);
}

void D_function(deception_t *const D)
{
    /**
     * calculation the binary number length
     * len : D.Dbinary number length
     * bitLen : actual D.Dbinary number length
     *
     * Query from the beginning to the end of the string.
     * If the beginning is 0, then bitLen-1 until 1 is encountered
     *
     */
    int len = strlen(D->Dbinary);
    int bitLen = len;
    for (int i = 0; i < len; i++)
    {
        if (D->Dbinary[i] == '1')
        {
            i = len + 1;
        }
        bitLen--;
    }
    bitLen++;

    /**
     * Calculation the Decetion Problem value here
     * 1.convery binary to decimal
     * 2.function calculation
     */
    long long sum = D_coveryDinaryToDecimal(D->Dbinary, &bitLen);

    sum = (long long)abs(sum - (long long)pow(2, len - 2));

    *D->Dvalue = sum;
}

int D_display(deception_t *const D)
{
    if (!D)
    {
        perror("message:");
        return 1;
    }

    printf("input:%s, Dvalue:%lld\n", D->Dbinary, *(D->Dvalue));
    return 0;
}

long long D_coveryDinaryToDecimal(const char *const bit, const int *const length)
{
    /**
     * result : The becimal number(will be return)
     * base : base of binary numbers
     *
     * Traverse from the highest bit to the lowest bit of the binary array
     * If the current bit is '1', base is added to result
     * Multiply the base number by 2
     */
    long long result = 0;
    long long base = 1;
    for (int i = (*length) - 1; i >= 0; i--)
    {
        if (bit[i] == '1')
            result += base;
        base *= 2;
    }

    return result;
}