#include <stdio.h>
#include "pseudo.c assembly.h"
int grades[] = { 35, 37, 85,15, 90, 100, 20, -1 };

/cc
    reg2-> reg5 -> ARGUMENTS to functions
    reg6+       -> TEMPORARY variables
*/

void get_avg(void);// always pass and return void everything i shandled with registers

void main(void)
{
    get_avg();  //reg0 will hold 'avg' value
    printf("%d\n", reg0);  //printf out average
}

/*
input: NA
output:  reg0 (avg)
modified: reg6, reg7, reg8
*/
void get_avg(void)
{
    reg6 = 0; //total = 0
    reg7 = 0; // i = 0

LOOP:
    reg8 = grades[reg7]; //grades[i]
    comp(reg8, -1);   //if (grade[i] == -1) LEAVE LOOP
    if(EQ) goto LOOP_DONE;
    reg6 = reg6 + reg8;    //total += grades[i]
    reg7 = reg7 + 1; //i++
    goto LOOP;


LOOP_DONE:
    reg0 = reg6 / reg7; //return_value = total / i;
    return;

}
/*int get_avg(void);
void main(void)
{
    int avg = get_avg();
    printf("%d\n", avg);

}

int get_avg(void)
{
    int total = 0;
    int i;
    for (i = 0; grades[i] != -1; i++)
    {
        total += grades[i];
    }
    return(total / i);
}*/