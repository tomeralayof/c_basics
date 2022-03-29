#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "bitwise.h"

int main()
{
	
	/*test ex 1*/
	unsigned int param_1_ex_1 = 10;
	unsigned int param_2_ex_1 = 2;
	long result_ex_1 = 0;
	
	/*test ex 2*/
	unsigned int param_1_ex_2 = 16;
	int result_ex_2 = 0;
	
	/*test ex 3*/
	int param_1_ex_3 = 5;
	int result_ex_3 = 0;
	
	/*test ex 4*/
	unsigned int param_1_ex_4 [] = {1,2,131,37};
	size_t param_2_ex_4 = sizeof(param_1_ex_4) / sizeof(int);
	
	/*ex 5*/
	unsigned int param_1_ex_5_a = 1;
	unsigned int result_ex_5_a = 0;
	
	unsigned int param_1_ex_5_b = 1;
	unsigned int result_ex_5_b = 0;
	
	
	/*ex 6*/
	unsigned char param_1_ex_6_a = 34;
	int result_ex_6_a = 0;
	
	unsigned char param_1_ex_6_b = 32;
	int result_ex_6_b = 0;
	
	unsigned char param_1_ex_6_c = 30;
	int result_ex_6_c = 0;
	
	/*ex 7*/
	unsigned int param_1_ex_7 = 18;
	unsigned int result_ex_7 = 0;

	/*ex 8*/
	int param_1_ex_8 = 5;
	int param_2_ex_8 = 10;
	
	/*ex 9*/
	unsigned int param_1_ex_9_a = 7;
	size_t result_ex_9_a = 0;
	
	unsigned int param_1_ex_9_b = 3;
	size_t result_ex_9_b = 0;
	
	/*ex 10*/
	float param_1_ex_10 = 3.456;

	
	/*invoke functions*/		
	result_ex_1 = Pow2(param_1_ex_1,param_2_ex_1);	
	printf("%ld\n",result_ex_1);
	
	result_ex_2 = IsPowOf2Loop(param_1_ex_2);
	printf("%d\n",result_ex_2);
	
	result_ex_2 = IsPowOf2(param_1_ex_2);
	printf("%d\n",result_ex_2);
	
	result_ex_3 = AddOne(param_1_ex_3);
	printf("%d\n",result_ex_3);
	
	PrintThreeBitsOnElements(param_1_ex_4,param_2_ex_4);
	printf("\n");
	
	result_ex_5_a = ByteMirrorLoop(param_1_ex_5_a);
	printf("result of mirror%u\n",result_ex_5_a);
	
	result_ex_5_b = ByteMirrorWithoutLoop(param_1_ex_5_b);
	printf("result 5b: %u\n",result_ex_5_b);
	
	result_ex_6_a = IsBothIdxOn(param_1_ex_6_a);
	printf("%d\n",result_ex_6_a);
	
	result_ex_6_b = IsOneOfIdxOn(param_1_ex_6_b);
	printf("%d\n",result_ex_6_b);
	
	result_ex_6_c = BitSwapByIdx(param_1_ex_6_c);
	printf("%d\n",result_ex_6_c);
	
	result_ex_7 = ClosestDividedByHex(param_1_ex_7);
	printf("%d\n",result_ex_7);
	
	BitwiseSwap(&param_1_ex_8, &param_2_ex_8);
	printf("x = %d, y = %d\n",param_1_ex_8,param_2_ex_8);
	
	result_ex_9_a = CountSetBitsLoop(param_1_ex_9_a);
	printf("%ld\n",result_ex_9_a);
	
	result_ex_9_b = CountSetBitsNoLoop(param_1_ex_9_b);
	printf("%ld\n",result_ex_9_b);
	
	FloatPrintBits(param_1_ex_10);
	
	
	
	
	return 0;
}







