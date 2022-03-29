#include <stdio.h>
#include "ilrd_string.h"
#include <stdlib.h>


int main()
{
	char *character = "hello world";
	int length = 0;
	char *ch1 = "";
	char *ch2 = "";
	int result =0;
 	
 	/*Ex. 1*/
	length = Strlen(character);
	printf("The string length is:%d\n",length);
	
	/*Ex. 2*/
	ch1 ="tomer";
	ch2 ="tomer";
	result = Strcmp(ch1,ch2);
	
	if(result == 0 ) 
	{
		printf("Strings are equal\n");
	}
	else 
	{	
		printf("Strings are not equal\n");
	}

		
	return 0;	
}
