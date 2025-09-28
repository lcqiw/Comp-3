#include <stdio.h>
#include <math.h>

union combined
{
	unsigned int i;
	float f;
};
typedef union combined Combined;

// Provided for you:
int test_num(Combined c);

// You write:
int is_Inf(Combined c);
int is_NaN(Combined c);
int is_Normal(Combined c);
void print_Float32(Combined c);

int main(int argc, char* argv[])
{
	unsigned int max_32_int = -1;	// Bits are all set to 1s
	unsigned long long i = 0;
	unsigned long long num_tests = max_32_int + (unsigned long long)1;

	// Check the simple cases first	
	Combined inf;
	inf.i = 0x7F800000;
	if (is_Inf(inf) == 0)
	{
		printf("Failed preliminary infinity test");
		return 1;
	}
	printf("Test for infinity: ");
	print_Float32(inf);

	Combined nan;
	nan.i = 0x7FFFFFFF;
	if (is_NaN(nan) == 0)
	{
		printf("Failed preliminary NaN test");
		return 2;
	}
	printf("Test for Not A Number: ");
	print_Float32(nan);

	Combined denorm;
	denorm.i = 0x00000001;
	if (is_Normal(denorm) == 1)
	{
		printf("Failed preliminary Denormalized test");
		return 3;
	}
	printf("Test for denormalized: ");
	print_Float32(denorm);

	Combined norm;
	norm.i = 0xbf800001;
	if (is_Normal(norm) == 0)
	{
		printf("Failed preliminary Normalized test");
		return 4;
	}
	printf("Test for normalized: ");
	print_Float32(norm);

	printf("Checking All 32-bit floats...\n");
	printf("Working: 0.00%% done");
	Combined c;
	while (i < num_tests)
	{
		c.i = i;
		if (!test_num(c))
		{
			return 5;
		}
		i++;

		// Print the progress every so often...
		if (i % 1000000 == 0)
		{
			printf("\rWorking: %.2f%% done", 100.0 * (double)i / num_tests);
		}
	}

	printf("\rSuccessfully matched all 32-bit float numbers! Congrats!\n");
	getchar();
	return 0;
}

int test_num(Combined c)
{
	if (isnormal(c.f) != is_Normal(c))
	{
		printf("\rNORMAL error: got: %d, needed: %d for float %f, hex: %x\n",
				isnormal(c.f), 
				is_Normal(c), 
				c.f, 
				c.i);
		return 0;
	}
if ((isinf(c.f) && is_Inf(c) == 0) || (!isinf(c.f) && is_Inf(c) != 0))
	{
		printf("\rINF error: got: %d, needed: %d for float %f, hex: %x\n",
			isinf(c.f),
			is_Inf(c),
			c.f,
			c.i);
		return 0;
	}
	if (isnan(c.f) != is_NaN(c))
	{
		printf("\rNAN error: got: %d, needed: %d for float %f, hex: %x\n",
			isnan(c.f),
			is_NaN(c),
			c.f,
			c.i);
		return 0;
	}

	return 1;
}
// Check if the float is infinity 
int is_Inf(Combined c)
{
    unsigned int exponent = (c.i >> 23) & 0xFF;      // Extract exponent bits
    unsigned int mantissa = c.i & 0x7FFFFF;          // Extract mantissa bits

    // Infinity: exponent is all 1s, mantissa is 0
    if (exponent == 0xFF && mantissa == 0)
        return 1;

    return 0;
}

// Check if the float is NaN 
int is_NaN(Combined c)
{
    unsigned int exponent = (c.i >> 23) & 0xFF;
    unsigned int mantissa = c.i & 0x7FFFFF;

    // NaN: exponent is all 1s, mantissa is non-zero
    return (exponent == 0xFF && mantissa != 0);
}

// Check if the float is a normalized number
int is_Normal(Combined c)
{
    unsigned int exponent = (c.i >> 23) & 0xFF;

    // Normalized: exponent is between 1 and 254
    return (exponent >= 1 && exponent <= 254);
}

// Print the float in binary scientific notation
void print_Float32(Combined c)
{
    if (is_Inf(c))
     {
       
        printf("INF\n");
        return;
    }

    if (is_NaN(c))
     {
        printf("NaN\n");
        return;
    }

    unsigned int sign = (c.i >> 31) & 1;             // 1 if negative
    unsigned int exponent = (c.i >> 23) & 0xFF;
    unsigned int mantissa = c.i & 0x7FFFFF;

    // Print the sign
    if (sign)
        printf("-");

    if (exponent == 0) 
    {
        // Denormalized- no  leading 1
        printf("0.");
        for (int i = 22; i >= 0; --i)
            printf("%d", (mantissa >> i) & 1);
        printf(" * 2^(-126)\n");  
    } 
    else 
    {
        // Normalized- leading 1
        printf("1."); 
        for (int i = 22; i >= 0; --i)
            printf("%d", (mantissa >> i) & 1);
        printf(" * 2^%d\n", (int)exponent - 127);
    }
}