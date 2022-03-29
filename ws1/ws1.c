/*
# The stdio.h header defines theree variable types, several macros and various functions for performing input and output.
# The include header "ws1.h" using the function sign in order to execute it.
*/
#include <stdio.h>
#include "ws1.h"

/*Ex. number 5*/
void HelloWorld()
{		
	printf("\x22\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x22\n");
}

/*Ex. number 6*/
double Pow(int n) 
{
	double result = 1;
  	double ten = 10;
 
  	if(n < 0 ) 
  	{
  		n = n*(-1);
  		ten =  1 / ten;
  	}
		  
  	for(int i = 0; i < n ; i++ )
  	{
		result *= ten;
  	}
  	
  	return result;	
}

/*ex. number 6*/
int FlipOrder(int x)
{

  	int result = 0;
  	int sign = 1;
  	
  	if(x < 0)
  	{
  		sign = -1;
  	}
  	
  	while(x)
  	{
	    	result = (result *10) + (x % 10);
	    	x = x / 10;
  	}
  	
  	return (result*sign);
}

/*ex. number 7*/
void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}










