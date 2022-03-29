#include <stdio.h> /*printf()*/
#include <stdlib.h> /*atoi()*/
#include "wboai.h"

/*reviewd by shai levi*/

#define IS_LITTLE_ENDIAN (*(short *)"\0\xff" > 0x00FF)

int IsAtoiEqual( const char *  param_1_ex_2)
{
		
		int result_1 = 0;
		int result_2 = 0;

		result_1 = atoi(param_1_ex_2);
		result_2 = AtoiStrToInt(param_1_ex_2); 
	
		return result_1 == result_2;
}


int main()
{
	
	/*ex 1*/
	int param_1_ex_1 = 56754567;
	char param_2_ex_1[8];
	
	/*ex 2*/
	const char * param_1_ex_2 = "             -12345";	
	int result_ex_2 = 0;
	
	/*ex 3*/
	char param_1_ex_3[100] = {0};
	int value = 123456;
	int base = 36;
	
	/*ex 5*/
    char *first_array = "ab!28";
    char *second_array = "!8cDe";
    char *third_array = "5678";
    
	/*ex 6*/
	int IsLittle = 0;
	
	/**************test 1*******************/
	ItoaIntToStr(param_1_ex_1,param_2_ex_1);
	printf("%s\n",param_2_ex_1);
	
	/*************test 2********************/
	result_ex_2 = AtoiStrToInt(param_1_ex_2);
	printf("%d\n",result_ex_2);
	
	/*************test 3*********************/
	ItoaIntToStrBase(value,param_1_ex_3,base);
	printf("%s\n",param_1_ex_3);
	
	/*************test 4*********************/
 	
 	printf("%d\n",IsAtoiEqual( param_1_ex_2));
 	
 	/***********************test ex 5*************/
 	PrintFromArrays(first_array, second_array, third_array, 5, 5, 4);
	
	printf("\n");
	
	
	IsLittle = IsLittleEndian();

	printf("%d\n",IsLittle);
	


	return 0;
}





