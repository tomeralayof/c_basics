#include <stdio.h>
#include <stdlib.h>


void Print(int f);

 struct print_me {

	int x;
	void (*ptr_to_void_func)(int);		
	
};

struct print_me arr[10]; /*array of structs*/


int main()
{
	size_t i = 0;
	
	for(i = 0; i < 10; ++i )
	{
		arr[i].x = i;
		arr[i].ptr_to_void_func = Print;
		arr[i].ptr_to_void_func(arr[i].x);
	}
	
	/*
	arr[0].x =  1;
	arr[0].ptr_to_void_func = Print;
	arr[0].ptr_to_void_func(arr[0].x);
	*/
		
	return 0;
}



void Print(int num)
{
	printf(" the value of arr[%d] = %d\n",num,num);
}
