#ifndef __WS1__H_ /*prevent of doing double include*/
#define __WS1__H_
#include <stddef.h>
void print1(int *arr, int rows, int cols);
void print2(int arr[3][3]);
void print3(int arr[3][3]);
void CalcSumR(int arr[3][3],int result[3]);
int JosephusProblem(int soldires_arr[], int length);
void DataType();
/*reverse*/
int LowerAndReturnLen(char **array);
char **AllocateMemoryAndCopy(int environment_length, char **envp);
void PrintCopyAndFree(char ** environment_copy, int environment_length);

#endif	/*__WS1__H_*/
