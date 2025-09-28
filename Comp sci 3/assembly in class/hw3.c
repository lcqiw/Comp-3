#include <stdio.h>
/* REGISTER MAPPING
    reg0,reg1 -> RETURN VALUES*/
int x[] = {1, 3, 5, 7, 9, 0};
int search(int key);
int main()
{
    int index;
    int key = 7;
    index = search(key);
    printf("%d", index);

}

int search(int key) 
{
    int reg0 = 0; //int i = 0
    int reg1 = 0;// int found = 0;


/*LOOP: 
if(!found && x[i] != 0)
{
    if(x[i] != key) goto ELSE;
    if(x[i] == key) goto FOUND_KEY;
}
goto DONE;
*/
LOOP: 
if(!reg1 && x[reg0] != 0)
{
    if(x[reg0] != key) goto ELSE;
    if(x[reg0] == key) goto FOUND_KEY;
}
goto DONE;

ELSE:
{
    reg0++;
    goto LOOP;
}

FOUND_KEY:
 reg1 = 1;
 goto FOUND;

FOUND:
if(reg1) 
goto RETURN1;
if(!reg1)
 goto RETURN2;

RETURN1:
return reg0;

RETURN2:
return -1;

DONE:
return -1;
}

///found_msg:  .asciiz "Index: "        # Message for found key
//not_found_msg: .asciiz "Key not found" # Message for not found key