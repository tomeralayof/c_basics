#include <stdio.h>  /* printf(), size_t */
#include <assert.h> /* assert()*/

#include "wboai.h"

#define DECIMAL_BASE 10
#define ASCII_MAX 256
#define LETTER_CAST ('A' - 10)
#define DIGIT_CAST '0'

static int hash_table[ASCII_MAX] = {0};
static void Reverse(char *start, char *end);

enum 
{
	FALSE,
	TRUE
};



char *ItoaIntToStr(int value, char *str)
{
	return ItoaIntToStrBase(value,str,DECIMAL_BASE);
}


int AtoiStrToInt(const char *str)
{

	int temp = 0;
	int result = 0;
	int sign = 1;
	
	assert(NULL != str);
	
	while (' ' == *str)
	{
		++str;
	}
	
	if (0 ==  *str)
	{
		return 0;
	}
	
	if ('-' == *str)
	{
		++str;
		sign = -1;
	}
	
	while ('\0' != *str )
	{
		temp = *str - '0';
		result = (result * DECIMAL_BASE) + temp;
		++str;
	}
	
	return result * sign;
}


char *ItoaIntToStrBase(int value, char *str, unsigned int base)
{
	int temp = 0;
	char * runner = str;
	int is_negative = FALSE;
	
	if (0 ==  value)
	{
		*str = '0';
		*(str + 1) = '\0';
		return str;
	}
	
	if (0 > value && DECIMAL_BASE == base )
	{
		is_negative = TRUE;
		value *= (-1);
	}
	
	while (0 < value)
	{
		temp = value % base;
		*str = (temp > 9) ? temp + LETTER_CAST : temp + DIGIT_CAST;
		value /= base;
		++str;
	}
	
	if ( TRUE ==  is_negative)
	{
		*str = '-';
		++str;
	}
	
	*str = '\0';
	
	Reverse(runner, str - 1);
	
	return str;
}

static void Reverse(char *start, char *end)
{

    char temp = '\0';
    
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

void PrintFromArrays(char *first_array, char *second_array, char *third_array, 
					size_t sizeof_array1, size_t sizeof_array2, size_t sizeof_array3)
{
	size_t i = 0;
	
	assert(NULL != first_array);
	assert(NULL != second_array);
	assert(NULL != third_array);
	
	for (i = 0; i < sizeof_array1; ++i)
	{
		hash_table[(int)first_array[i]] = 1;
 	}
 	
 	for (i = 0; i < sizeof_array2; ++i)
 	{
 	
 		hash_table[(int)second_array[i]] |= 2;
 	}
 	
 	for (i = 0; i < sizeof_array3; ++i)
 	{
 			hash_table[(int)third_array[i]] = 0;
 	}
 	
 	for (i = 0; i < ASCII_MAX ; ++i)
 	{
 		if (3 == hash_table[i])
 		{
 			printf("%c ",(char)i);
 		}
 	}
	
}


int IsLittleEndian(void)
{
	int test = 1;
	
	return *(char *)&test == test;
}




