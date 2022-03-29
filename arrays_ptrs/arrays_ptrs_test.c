#include <stddef.h>
#include <stdio.h>
#include "arrays_ptrs.h"

int main(int argc, char *argv[],char *envp[])
{
 	
	/*way 1*/
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result[3];
    int rows = 3, cols = 3;
    int length = 100;
    int soldiers[100]={0};
    int res1 = 0; 
    
    int environment_length =0;
    char **environment_copy = '\0';
    
    print1((int *)arr, rows, cols);
    
 	/*way 2*/
	print2(arr); 	
	
	/*way 3*/
	print3(arr);
		 	 	
	/*ex 1 part 2*/
	CalcSumR(arr,result);
	
	/*ex 2*/
    res1 = JosephusProblem(soldiers,100);
    printf("the winning index is: %d",res1);
	
	DataType();
	
	/*ex 4*/
	environment_length = LowerAndReturnLen(envp);
	environment_copy = AllocateMemoryAndCopy(environment_length,envp);
	PrintCopyAndFree(environment_copy,environment_length);
		 	 	
	return 0;	
}	




