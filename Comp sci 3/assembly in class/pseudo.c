#include <stdio.h>
#include "pseudo.c assembly.h"

void main(void)
{
//Intialize
    reg0 = 1; //int result = 1;
    reg1 = 5; //int count = 5;
    reg2 = 1; // keep 1 handy in reg 2

LOOP:
    comp(reg1, reg2); //compare: count vs 1

    if(LTE)// if(count <=1) LEAVE LOOP
        goto DONE;
    reg0 = reg0 * reg1; //result = result *count;
    reg1 = reg1 -1; // count --
    goto LOOP;



DONE:
    printf("RESULT: %d\n", reg0);  //printf("RESULT: %d\n", result);


    /*int result = 1;
    int count;
    for( count = 5; count > 1; count--)
    {
        result = result * count;
    }
    printf("RESULT: %d\n", result);*/
}