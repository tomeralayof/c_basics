#include <stdio.h> /*printf()*/
#include <assert.h> /*assert()*/
#include <string.h>

#define  TESTER_LEN 5
#define CHARACTERS_CORDINATE 1
#define MAX_ASCII_TABLE 255

FILE *ptr_to_file_name;
FILE *pointer_to_temp_file;

enum test
{
 EXIT_CODE = -1,
 SUCCESS,
 COUNT_PRESSED,
 FOPEN_ERROR,
 FCLOSE_ERROR,
 FGETS_ERROR,
 FPUTC_ERROR,
 REMOVE_ERROR,
 FPUTS_ERROR,
 RENAME_ERROR
};


struct tester {

	char *line;
	int (*ptr_to_compare_function)(char *dest, char *src);		
	int (*oparate)(char *filename,char *add_line);		
};

int IsValid( char *filename);
int ExitProgram(char *filename,char *add_line);
int Compare(char *dest,char *src);
int Append(char *filename,char *add_line);
int ReturnSuccess( char *str1, char *str2);
int RemoveFile(char *filename,char *line);
int CompareChr(char *dest,char *src);
int InsertUp(char *filename,char *add_line);
int CountLines(char *filename,char *add_line);



struct tester arr[TESTER_LEN] =
 {
	 {"-remove",&Compare,&RemoveFile},
	 {"-count",&Compare,&CountLines},
	 {"-exit",&Compare,&ExitProgram},
	 {"<",&CompareChr,&InsertUp},
	 {NULL,ReturnSuccess,&Append}
};


int main(int argc, char *argv[])
{
	(void)argc;

	IsValid(argv[1]);
	
	return SUCCESS;
}
	
	
int IsValid( char *filename)	
{
	int i = 0;
	char line[MAX_ASCII_TABLE];

	int status = SUCCESS;
	
	while (status == SUCCESS)	
	{	
		
		printf("enter a line :" );	
		scanf("%s%*c",line);
		 
		for( i = 0; i < TESTER_LEN ; i++ )
		{
		
			if( SUCCESS == arr[i].ptr_to_compare_function(arr[i].line,line))
			{		
				status = arr[i].oparate(filename,line);
				
				if(status == COUNT_PRESSED)
				{
					continue;
				}
				
				
				if(status != SUCCESS)
				{
					break;
				}
				
			}			
		}
	}
	
	return SUCCESS;
}




int ExitProgram(char *filename,char *add_line)
{
	(void)filename;
	(void)add_line;
	return EXIT_CODE;
}



int Compare(char *dest,char *src)
{

	if(NULL == dest)
	{
		return EXIT_CODE;
	}	
		
	return strcmp(dest,src);
}


int Append(char *filename,char *add_line)
{
	
	ptr_to_file_name = fopen(filename,"a");
	
	if(NULL == ptr_to_file_name	)
	{
		return 	FOPEN_ERROR;
	}
		
	if(EOF == fputs(add_line,ptr_to_file_name))
	{
		return FPUTS_ERROR;
	}
	
	if (EOF == fputc('\n',ptr_to_file_name))
	{
		return FPUTC_ERROR;
	}
	
	if (EOF == fclose(ptr_to_file_name))
	{
		return FCLOSE_ERROR;
	}
	
	return SUCCESS;		
}

int ReturnSuccess(char *str1,char *str2)
{
	(void)str1;
    (void)str2;
    
    return SUCCESS;
}

int RemoveFile(char *filename,char *line)
{

	assert( NULL != filename);
	
	(void)line;
	
	if(	remove(filename) == -1)
	{
		return REMOVE_ERROR;
	}
	
	return EXIT_CODE;
}



int CompareChr(char *dest,char *src)
{
	return dest[0] != src[0];
}


int InsertUp(char *filename,char *add_line)
{
		
	char line[MAX_ASCII_TABLE];
	char *file_name = "temp.txt";
	
	Append(file_name,(add_line+1));
	
	ptr_to_file_name = fopen(filename,"r");
	
	if(NULL == ptr_to_file_name	)
	{
		return 	FOPEN_ERROR;
	}
	
	
	while(fgets(line,255,ptr_to_file_name))
	{	
		pointer_to_temp_file = fopen(file_name,"a");
		
		if( EOF == fputs(line,pointer_to_temp_file))
		{
			return FPUTC_ERROR;
		}
		
		if( EOF == fclose(pointer_to_temp_file))
		{
			return FCLOSE_ERROR;
		}	
	}	
	
	fclose(ptr_to_file_name);
	
	RemoveFile(filename,line);
	rename(file_name,filename);
	
	return SUCCESS;
}


int CountLines(char *filename,char *add_line)
{

	char c[MAX_ASCII_TABLE];	
	int counter = 0;
	ptr_to_file_name = fopen(filename,"r");
	
	if(NULL == ptr_to_file_name)
	{
		return 	FOPEN_ERROR;
	}
	
	(void)add_line;

	
	while(fgets(c,255,ptr_to_file_name))
	{
		++counter;
	}	
	
	if (EOF == fclose(ptr_to_file_name))
	{
		return FCLOSE_ERROR;
	}
	
	
	
	printf("Your file consist of %d lines\n",counter);		
	
	return COUNT_PRESSED;
}



