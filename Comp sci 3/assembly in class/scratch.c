#include <stdio.h>

void main(void)
{
    int num;
    printf("how was the movie?");
    scanf("%d", &num);

if( num >= 6) goto ELSE_1;
if(num >= 4) goto BAD;//ifnot go to bad
printf("HORRENDOUS");
goto DONE;

BAD:
printf("BAD");
goto DONE;

ELSE_1:
if(num >= 8) goto YAY;
printf("MID");
goto DONE;

YAY: 
printf("Yay");
 
DONE:
        


    if(num < 6)
    {
        if(num < 4)
            printf("HORRENDOUS");
        else 
            printf(" BAD");
        
    }
    else 
    {
        if(num < 8)
            printf("MID");
        else 
            printf("Yay");
    }
}