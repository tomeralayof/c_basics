#include <stdio.h>
#include "ws1.h"

int main()
{
	HelloWorld();
	
	int a;
	printf("choose a number to calculate the pow \n");
	scanf("%d",&a);
	printf("The result is: %.2lf\n",Pow(a));
		
	int x;
	printf("Choose a number to flip: ");
	scanf("%d",&x);
	printf("The fliped number is: %d\n",FlipOrder(x));
	
	int z = 5;
	int k = 10;
	Swap(&z,&k);
	printf("new x result is : %d\nnew y result is: %d\n",z,k);
	
	return 0;
}
