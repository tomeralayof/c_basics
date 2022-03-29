#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#include "ptr_2.h"

int main()
{

	
	/*variables:*/	
	char c1[] = "tomer alayof";
	char c2[100];	
	
	char ch_StrCasecmp1[] = "HellO";
	char ch_StrCasecmp2[] = "Helln";
	int str_case_c =0; 
	
	char ch1_ex_2[] = "hello";
	char ch2_ex_2[100];
	size_t n = 2;
	 	
	char ch1_ex_3[] = "tomer";	
	char ch2_ex_3[] = "toMer";
	int result =0;
	
	char ch1_ex_4[] = "abcdefghijklmnopqrstuvwxyz";	 
	
	char *p;
	char *p_strdup;
	char ch_ex_5[] = "hello";
	
	char *p_StrCat;
	char ch1_ex_6[6] = "hello";
	char ch2_ex_6[14] = "world";
	
	char ch1_ex_7[] = "infinity";
	char ch2_ex_7[] = "labs";
	size_t num_ex_7 = 2;
	char *StrnCat_ex_7;
	

	
	char palindrom[] = "@amanaplanacanalpanama@";
	int isPal =0;
	
	size_t count_to_return;
	char s[] = "12w34";
	char *accept = "0123456789"; 
	
	
	
	char ch_haystack[]="tuturialPoint";
	char ch_needle[]="Point";
	char *haystack_promotion;
	
	size_t test =0;
	
	
	
	
	/*func number 1*/
	StrCpy(c2,c1);
	printf("%s\n",c2);
	
	/*str compare case*/
	str_case_c = StrCasecmp(ch_StrCasecmp1,ch_StrCasecmp2);
	
	if(str_case_c == 0)
	{
		printf("strings are equal, result is:%d\n",str_case_c);
	}
	else 
	{
		printf("strings are not equal, result is:%d\n",str_case_c);
	}

	/*func number 2*/
	StrnCpy(ch2_ex_2, ch1_ex_2, n);
	printf("%s\n",ch2_ex_2);
	
	/*func number 3*/
	 result = StrCasecmp(ch1_ex_3,ch2_ex_3);
	 
	 if(result)
	 {
	 	printf("The strings are not eqal\n");
	 }
	 else 
	 {
		printf("The strings are eqal\n");
	 }
	 
	 /*func number 4*/
	 p = StrChr(ch1_ex_4,'g');
	 printf("%s\n",p);
	 
	 /*func number 5*/
	 p_strdup = StrDup(ch_ex_5);
	 printf("%s\n",p_strdup);
	 free(p_strdup);
	
	 /*func number 6*/
	 p_StrCat = StrCat(ch1_ex_6,ch2_ex_6);
	 printf("fixed: %s\n",p_StrCat);
	 
	 /*func number 7*/
	 StrnCat_ex_7 = StrnCat(ch1_ex_7,ch2_ex_7,num_ex_7);
	 printf("%s\n",StrnCat_ex_7);
	 
	
	 
	 count_to_return = StrSpn(accept,s);
	 printf("s is found in accept:%ld times\n",count_to_return);
	 
	 isPal = isPalindrom(palindrom);
	 if(isPal == 0)
	 {
	 	printf("the sentence is palindrom\n");
	 }
	 else 
	 {
	 	printf("the sentence is not palindrom\n");
	 }
	 
	haystack_promotion = StrStr(ch_haystack,ch_needle);
	printf("%s\n",haystack_promotion);
	
	test = StrSpn("abcdefg0123456789","abcd");
	printf("s is found in accept:%ld times\n",test);
	
		 	 	

	return 0;	
}	






