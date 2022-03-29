#include <stdio.h>
#include "g.h"


int main()
{
	printf("g_s = %d\n",g_s);
	printf("%ld\n",(long)&g_s);
	foo();
	printf("g_s = %d\n",g_s);
 
 	return 0;
}
