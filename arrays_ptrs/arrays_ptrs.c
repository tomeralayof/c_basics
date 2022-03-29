#include <stdio.h>
#include "arrays_ptrs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

/*both dimensions are available globally - either as a macro orr as a global constant*/
	
void print1(int *arr, int rows, int cols)
{
	int i, j;	
	printf("First method to print 1nd dimential array(casting to 1 dims array):\n");
	printf("-----------------------------------------\n");
	
	assert( NULL != arr);
	
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
      	{
      		/*printf("%p\n",(arr+i*n)+j);*/
      		printf(" %d",*((arr+i*cols) + j));
	  	}
	  	printf("\n");
	}
}
/*
1000 + 0* + 0 = 1000
1000 + 0 +4 = 1004
1000 + 0 + 8 = 1008
1000 + 1*4*3 + 0 =1012
1000 + 1*4*3 + 1*4 = 1016
*/

void print2(int arr[3][3])
{
	int i, j;
	printf("\n");
	
	printf("second method to print 2nd dimential array(index promotion):\n");
	printf("-----------------------------------------\n");
	assert( NULL != arr);
	
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
      	{
      		printf(" %d",arr[i][j]);
      	
	  	}
	  	printf("\n");
	}
}

void print3(int arr[3][3])
{
	int i, j;
	printf("\n");
	printf("third method to print 2nd dimential array(pointer to pointer):\n");
	printf("-----------------------------------------\n");
	assert( NULL != arr);
	
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
      	{
      		printf(" %d",*(*(arr + i)+j));
	  	}
	  	printf("\n");
	}
}

void CalcSumR(int arr[3][3],int result[3])
{
	int i =0;
	int j =0;
	int counter =0;
	int mat_len = sizeof(arr[3]) * 3 / sizeof(int); /*sizeof(arr[3]) => the bytes of 1 row multiple cols devide by matrix type*/
	printf("\n");
	printf("calculate the row sum:\n");
	printf("-----------------------------------------\n");
	printf("The size of the matrix is:%d\n",mat_len);
	assert( NULL != arr);
	assert( NULL != result);
	
	for(i=0; i<3; ++i)
	{
		counter =0;
		for(j=0;j<3;++j)
		{
			counter+=arr[i][j];
		}
		result[i] = counter;
		printf("row %d sum: %d\n",i,result[i]);
	}
}

int JosephusProblem(int soldires_arr[], int length)
{
	int i = 0;
	int next_to_kill = 0;
	
	assert(NULL!= soldires_arr );
		
	while(i < length )
	{
		soldires_arr[i] = (i + 1) % length;
		++i;
	}
	
	i=0;
	
	while(soldires_arr[i] != i)
	{
		                                 next_to_kill = soldires_arr[soldires_arr[i]];
		soldires_arr[soldires_arr[i]] = 0;  
		soldires_arr[i] = next_to_kill;
		i = next_to_kill;
	}
	
		return i;		
}


void DataType()
{
	printf("\n");
	printf("size of c data types:\n");
	printf("-----------------------------------------\n");
	printf("char:%ld bytes\n",sizeof(char));
	printf("signed char:%ld bytes\n",sizeof(signed char));
	printf("short:%ld bytes\n",sizeof(short));
	printf("signed short:%ld btyes\n",sizeof(signed short));
	printf("unsigned short:%ld bytes\n",sizeof(unsigned short));
	printf("signed int: %ld bytes\n",sizeof(signed int));
	printf("unsined int:%ld bytes\n",sizeof(unsigned int));
	printf("short int:%ld bytes\n",sizeof(short int));
	printf("signed short int:%ld bytes\n",sizeof(signed short int));
	printf("unsined short int:%ld bytes\n",sizeof(unsigned short int));
	printf("long int:%ld bytes\n",sizeof(long int));
	printf("signed long int:%ld bytes\n",sizeof(signed long int));
	printf("unsigned long int:%ld bytes\n",sizeof(unsigned long int));
	printf("float:%ld bytes\n",sizeof(float));
	printf("double:%ld bytes\n",sizeof(double));
	printf("long double:%ld bytes\n",sizeof(long double));

}
 
 /*ex 4 functions*/
 int LowerAndReturnLen(char **array)
{   
    int i = 0;
    int j = 0;
    
    assert( NULL != array);
    
    while (array[i] != NULL)
    {
		j = 0;
        while (array[i][j] != '\0') 
        {
			array[i][j] = tolower(array[i][j]);
            j++;
        }
        i++;
    }
    
    return i;
}   


char **AllocateMemoryAndCopy(int environment_length, char **envp)
{

	int i=0;
	char **copy = '\0';
	copy = (char **) malloc(sizeof(char *) * environment_length);
	
	if(NULL	== copy)
	{
		return NULL;
	}
	
	assert( NULL != envp);
	
	for(i = 0; i < environment_length; ++i)
	{
		copy[i] = (char *)malloc(strlen(envp[i])+1);
		if(NULL	== copy[i])
		{
			return NULL;
		}
		strcpy(copy[i], envp[i]);
	}
	return copy;
}	


void PrintCopyAndFree(char ** environment_copy, int environment_length)
{
	
	int i =0;	
	
	assert( NULL != environment_copy);
	
	for(i =0; i < environment_length ; ++i )
	{

		printf(" evn number %d =  %s\n",i,environment_copy[i]);
		free(environment_copy[i]);
		environment_copy[i] = NULL;
		
	}	
	
		free(environment_copy);
}








/* first try
int JosephusProblem(int soldires_arr[8])
{	
	
	int length = 8;
	int i = 0;
	int sward = 1;
	int count = 0;
	int result = 0;
	
	assert( NULL != soldires_arr);
	
	while(count < length -1)
 	{
 		
 		if(soldires_arr[i]!=0)
 		{
 			
			if( sward == 1)
			{
				sward = 0;
				result = i;
			}	
		
			else if (sward == 0)
			{
				soldires_arr[i] = 0;
				++count;
				sward = 1;
			}
		}
				 		
 		if(i == length - 1)
 		{
 			i = -1;
 		}
 		
 		++i;
 	}
 	
 	return result;
}
*/
	
