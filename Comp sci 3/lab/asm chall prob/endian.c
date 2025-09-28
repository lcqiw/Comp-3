#include <stdio.h>

int is_big_endian(void);

int main(int argc, char* argv[])
{
	if (is_big_endian())
	{
		printf("Big endian architecture\n");
	}
	else
	{
		printf("Little endian architecture\n");
	}
	return 0;
}

/* 
* OUTPUT:
*			1 if the architecture is big-endian
*			0 if the architecture is little-endian
* INPUT:
*			NA
*/
int is_big_endian(void)
{
    // YOUR CODE HERE...
    unsigned int num = 1;
	char *byte = (char*)&num;
	return (*byte == 0);
	// return 1; // BIG-ENDIAN
	// return 0; // LITTLE_ENDIAN
}
