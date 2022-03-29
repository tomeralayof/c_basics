#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	FILE *file_pointer;
	int length = 0;
	int i = 0;
	char message[100];
	
	printf("Please enter how many lines you want your file to include:");
	scanf("%d",&length);
	getchar();
	
	for (i = 0; i < length ; ++i )
	{
		file_pointer = fopen(argv[1],"a");
		printf("Enter sentence number %d of %d",i,length);
		fgets(message,sizeof(message),stdin); /*take stdin*/
		fputs(message,file_pointer); /*write to the file*/
		/*fwrite(*messages,sizeof(char *),length,file_pointer);write the all file*/
		fclose(file_pointer);
	}
	
	return 0;
}

