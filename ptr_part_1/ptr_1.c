#include <stdio.h>
#include "ptr_1.h"
/*
The stdlib.h header defines four variable types: size_t,wchar_t,div_t,ldiv_t
 , several macros, and various functions for performing general functions. 
*/
#include <stdlib.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void CopyArry(int arr[], int size)
{

	int arr2[size];
	
	for(int i=0; i<size; i++) 
	{
		arr2[i] = arr[i];
	}
	
	for(int i=0; i<size;i++) 
	{
		printf("arr2[%d]=%d\n",i,arr2[i]);
	}
}



int Adress()
{
    static int s_i = 7;
    int i = 7;
    int *ptr = &i;
    int *ptr2 = (int*) malloc( sizeof(int));

    if(ptr)
    {
        	int **ptr3 = &ptr;
      		printf("The adress of ptr3 inside the RAM is:%p\n", (void *)&ptr3);
      		printf("the adress which ptr 3 is pointing is: %p\n",(void *) ptr3);
    }

    printf("The adress of s_i inside the RAM is:= %p\n",(void *) &s_i); 
    printf("The adress of i inside the RAM is: %p\n", (void *) &i);
    printf("The adress which ptr is pointing to is: %p\n",(void *)ptr);
    printf("The adress of ptr inside the RAM is:%p\n",(void *)&ptr);
    printf("The adress which ptr2 pointing to inside the heap is => ptr2 value:%p\n",(void *)ptr2); /*malloc function alocate memory inside the heap, so ptr2 is pointing to an adress which can be initialize later on*/
    printf("The adress of ptr2 inside the RAM is:%p\n",(void *)&ptr2);
    free (ptr2);
    
    return 0;
}

void SwapTwoSize(size_t *a,size_t *b)
{
	size_t temp = *a;
	*a = *b;
	*b = temp;
}



/*we make casting in order to pass the pointers into the function swap, so it will change the pointers*/
void SwapTwoPointers(size_t **a,size_t **b)
{
	SwapTwoSize((size_t *)a,(size_t *)b);
}

















