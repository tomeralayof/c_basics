#include <stdio.h>
#include <stdlib.h>
#include "ptr_1.h"
#include <stdlib.h>

int main()
{
	/*Ex. 1:*/
	int x = 10;
	int y = 15;
	size_t z =0;
	size_t k = 0;
	size_t *zp = NULL;
	size_t *kp=NULL;
	
	Swap(&x,&y);
	printf("x=%d,y=%d\n",x,y);
	
	
	/*Ex. 2*/
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr) / sizeof(int);
	CopyArry(arr,size);
	
	/*Ex. 3*/
	Adress();
	
	/*Ex. 4*/
	z = 10;
	k = 15;
	printf("Before swapping the values:\n");
	printf("z=%zu,k=%zu\n",z,k);
	SwapTwoSize(&z,&k);
	printf("After swapping the values:\n");
	printf("z=%zu,k=%zu\n",z,k);
	
	
	zp = &z;
	kp = &k;
	
	SwapTwoPointers(&zp,&kp);
	printf("After swapping the pointers:\n");
	printf("z=%zu,k=%zu\n",z,k);
	
	return 0;
	
	
}







