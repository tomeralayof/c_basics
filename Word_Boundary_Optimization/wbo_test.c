#include <stdio.h>
#include <string.h>
#include "wbo.h"

/*reviwed by gal tsaig*/
int main ()
{
	
	char param_1_ex_1[100] = "tomeralayofsdfghjktfhfhgnvnhgvnghnghnghnvfnb";

	char param_1_ex_2[100] = "i wanna live in gaza";
	char param_2_ex_2[100] = {'\0'};

	
	char param_1_ex_3[100] = "tomeralayof";
	char *param_2_ex_3 = param_1_ex_3+3;

	Memset(param_1_ex_1,'$',17);
	Memcpy(param_2_ex_2, param_1_ex_2, 11);	
	Memmove(param_2_ex_3,param_1_ex_3,5);

	printf("%s\n",param_1_ex_1);
	printf("%s\n",param_2_ex_2);
	printf("%s\n",param_2_ex_3);
	
	
	return 0;
}
