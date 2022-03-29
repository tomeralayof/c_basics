#include <stdlib.h>
#include "bitwise.h"
#include <stdio.h>
#include <stddef.h>

/*ex to complete: 5-a*/



#define TRUE (1)
#define THREE_BITS_ON 3
#define ZERO 0
#define ONE 1
/*ex 1*/
long Pow2 (unsigned int x, unsigned int y)
{
	return x << y;
}

/*ex 2*/
int IsPowOf2Loop (unsigned int n)
{
	
	while(n && (1 != (n & 1)))
	{
		n = n >> 1;
	}
	
	return n == 1;
}

int IsPowOf2 (unsigned int n)
{	
	return ((n & (n - 1)) == ZERO);
}

/*ex 3*/
int AddOne (int num)
{
	int mask = 1;
	
	while((mask & num ) > ZERO )
	{
		num = mask ^ num;
		mask =  mask << 1;
	}	
	
	num = mask ^ num;
	
	return num;
}

/*ex 4*/
static int IsThreeBitesOn(int num)
{
	int mask = ONE;
	int count = 0;
	
	while(mask < num)
	{
		
		if((mask & num) > 0 )
		{
			++count;
		}
		
		mask = mask << 1;
	}
	
	return count == THREE_BITS_ON;
}

void PrintThreeBitsOnElements(unsigned int *arr, size_t arr_size)
{
	size_t i = 0;
	
	for(i = 0; i < arr_size; ++i)
	{
		if( TRUE ==  IsThreeBitesOn(arr[i]))
		{
			printf("%d ",arr[i]);
		}
	}
}

/*ex 5*/
/*a*/
unsigned int ByteMirrorLoop(unsigned int num)
{
	unsigned int mask = 1;
	
	unsigned int result = 0;
	int i = 0;

	for(i = 0; i < 32; ++i)
	{
		result = result << 1;
		result = num & mask;
		num = num >> 1;

	}
	
	return result;
}



/*b*/
unsigned int ByteMirrorWithoutLoop(unsigned int num)
{
	num = (num >> 16) | (num  << 16);
	num = ((num >> 8) & 0x00FF00FF) | ((num << 8) & 0xFF00FF00);
	num = ((num >> 4) & 0x0F0F0F0F) | ((num << 4) & 0xF0F0F0F0);
	num = ((num >> 2) & 0x33333333) | ((num << 2) & 0xCCCCCCCC);
	num = ((num >> 1) & 0x55555555) | ((num << 1) & 0xAAAAAAAA);
	
	return num;
}

/*ex 6*/
/*a*/
int IsBothIdxOn(unsigned char num)
{
	return ((num & 32)&&(num & 2));
}
/*b*/
int IsOneOfIdxOn(unsigned char num)
{
		return ((num & 32) || (num & 2));
}
/*c*/
unsigned char BitSwapByIdx(unsigned char num)
{
	unsigned char third = (num >> 2) & 1;
	unsigned char fivth = (num >> 4) & 1;

	unsigned char temp = third ^ fivth;
	
	temp = (temp << 2) | (temp << 4);
	
	return (num ^ temp);
}


/*ex 7*/
unsigned int ClosestDividedByHex(unsigned int num)
{
	int mask = ONE;
	
	if(num % 16 == 0)
	{
		return num;
	}
	
	while(num > ONE)
	{
		mask = mask << 1;
		num = num >> 1;
	}
	
	return mask;
}

/*ex 8*/
void BitwiseSwap(int *num_1, int *num_2)
{
	*num_2 = (*num_2 ^ *num_1);
	*num_1 = (*num_2 ^ *num_1);
	*num_2 = (*num_2 ^ *num_1);
}

/*ex 9*/
/*a*/
size_t CountSetBitsLoop(unsigned int num)
{
	int count = 0;
	unsigned int mask = 1;
	
	if(num % 2 == ZERO )
	{
		return ONE;
	}
	
	while(mask < num)
	{
		if((num & mask) > 0)
		{
			++count;
		}
		
		mask = mask << 1;
	}
	
	return count;
}

/*b*/
size_t CountSetBitsNoLoop(unsigned int num)
{   
	static int bit_lut[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
	
    int four_bits = 15;
    
    int nibble_1 = num & four_bits;
    int nibble_2 = (num >> 4) & four_bits;
    int nibble_3 = (num >> 8) & four_bits;
    int nibble_4 = (num >> 12) & four_bits;
    int nibble_5 = (num >> 16) & four_bits;
    int nibble_6 = (num >> 20) & four_bits;
    int nibble_7 = (num >> 24) & four_bits;
    int nibble_8 = (num >> 28) & four_bits;
    
    size_t result = bit_lut[nibble_1] + bit_lut[nibble_2] + bit_lut[nibble_3]
     + bit_lut[nibble_4] + bit_lut[nibble_5] + bit_lut[nibble_6] + bit_lut[nibble_7] + bit_lut[nibble_8];

    return result;
}



/*ex 10*/
void FloatPrintBits(float num)
{
	int index = ONE;
	unsigned int current_bit = 0;
	int *float_ptr = (int *)&num;
		
	for (index = 32; index > 0; --index)
	{
		current_bit = ((*float_ptr >> (index - ONE)) & ONE);
		printf("%d ", current_bit);
	}
	printf("\n");
}







