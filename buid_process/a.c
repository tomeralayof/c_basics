#include <stdio.h>
#include "g.h"


void foo()
{
	g_s++;
	printf("%d\n",g_s);
	printf("%ld\n",(long)&g_s);
}

