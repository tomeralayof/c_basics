#include <stdlib.h>/* malloc(), realloc() */
#include <string.h> /*strlen()*/
#include <stdio.h> /*printf()*/
#include <assert.h> /*assert()*/

/*reviewed by gal*/
#define TYPES_NUM (3)
#define CASTING(type, var)(*(type*)&(var))
#define MAX_NUMBERS (12)
#define MAX2(a,b) ((a)>(b)?(a):(b))
#define MAX3(a,b,c) (MAX2((c),MAX2((a),(b))))
#define SIZEOF_VAR( var ) ((size_t)(&(var)+1)-(size_t)(&(var))) 
#define SIZEOF_TYPE(type) (size_t)( (type *)0+1)

typedef int (*add_t)(int num, void *element);
typedef int (*print_t)(void *element);
typedef int (*clean_up_t)(void *element);

typedef struct operations
{
	add_t add_func;
	print_t print_func;
	clean_up_t clean_up_func;
} operations_t;

typedef struct gen_element
{
	void *element;
	operations_t *func_operations;
}gen_element_t;


enum exit_code {PRINT_ERROR = -1, SUCCESS, MEMORY_ALLOCATION_ERROR};
enum arr_idxs {INT,FLOAT,STRING,OPTION_LENGTH};

static int AddInt(int num, void *element);
static int AddFloat(int num, void *element);
static int AddString(int num, void *element);

static int PrintInt(void *element);
static int PrintFloat(void *element);
static int PrintString(void *element);

static int Nothing(void *element);
static int CleanUpArray(void *element);

static int AddStringToTesterArray(gen_element_t *input);

static void InvokeTester(gen_element_t *input);
static size_t SizeToAllocate(int num);
static void PrintMacros();

operations_t function_bank[TYPES_NUM]  =
{
	{&AddInt,&PrintInt,&Nothing},/* int */
	{&AddFloat,&PrintFloat,&Nothing},/* float */	
	{&AddString,&PrintString,&CleanUpArray}/* string */
};


int main()
{

	int num = 5;
	float num_float = 5.54;

	gen_element_t input[OPTION_LENGTH];

	CASTING(int, input[INT].element) = num; /*5*/
 	input[INT].func_operations = &function_bank[INT];
 	
 	CASTING(float, input[FLOAT].element ) = num_float; /*5*/
 	input[FLOAT].func_operations = &function_bank[FLOAT];
 	
 	
 	CASTING(char *, input[STRING].element ) = ""; 
 	input[STRING].func_operations = &function_bank[STRING];
 	
 	AddStringToTesterArray(input);
 	
 	InvokeTester(input);
 	
	PrintMacros();


	return SUCCESS;
}

static void PrintMacros()
{
	int x = 10;
	printf("The max value between 10 and 200 is: %d\n",MAX2(10,200));
	printf("The max value between 10,200 and 300 is: %d\n",MAX3(10,200,300));
	printf("The size of int x is: %ld bytes\n",SIZEOF_VAR(x));
	printf("The size of int is: %ld bytes\n",SIZEOF_TYPE(int));
}
		
static void InvokeTester(gen_element_t *input)
{
	int i = 0;

	assert(NULL != input);

	for(i = 0; i < OPTION_LENGTH; ++i )
	{
		input[i].func_operations -> add_func(5,&input[i].element);
		input[i].func_operations -> print_func(input[i].element);
		input[i].func_operations -> clean_up_func(input[i].element);	
	}
}

static int AddInt(int num, void *element)
{
	assert(NULL != element);
	*CASTING(int *,element) += num;
	
	return SUCCESS;
}

static int AddFloat(int num, void *element)
{
	*CASTING(float *,element) += num;
	assert(NULL != element);
	return SUCCESS;
}

/*element is pointer to a pointer of string*/
static int AddString(int num, void *element)
{

	size_t size_runner = 0;
	char str[MAX_NUMBERS] = {'\0'};	
	size_t total_str_len = 0;
	size_runner = SizeToAllocate(num);
	
	total_str_len = strlen(*CASTING(char **,element)) + 1 + size_runner;
	
	*CASTING(char **, element) = (char *)realloc(*CASTING(char **,element),total_str_len);
	
	if(NULL == element)
	{
		return MEMORY_ALLOCATION_ERROR;
	}

	sprintf(str, "%d", num);
	strcat(*CASTING(char **,element), str);
	
	return SUCCESS;
}


static int PrintInt(void *element)
{
	 
	printf("The value is: %d\n", CASTING(int ,element));
	return SUCCESS;
}


static int PrintFloat(void *element)
{
	
	printf("%.2f\n",CASTING(float ,element));
	return SUCCESS;
}

static int PrintString(void *element)
{
	
	if(NULL == element)
	{
		return PRINT_ERROR;
	}

	printf("%s\n", (char *)element);
	return SUCCESS;
}

static int Nothing(void *element)
{
	(void)element;
	return SUCCESS;
}

static int CleanUpArray(void *element)
{
	free(element);
	element = NULL;
	return SUCCESS;	
}


static int AddStringToTesterArray(gen_element_t *input)
{	
	
	char *str1 = "tomer";
	size_t str_len = strlen(str1);
	
	CASTING(char *, input[STRING].element) = (char*)malloc(sizeof(char) * str_len +1);

	if( NULL == input[STRING].element )
	{
		return MEMORY_ALLOCATION_ERROR;
	}
	
	strcpy(input[STRING].element, str1);
	return SUCCESS;
}


static size_t SizeToAllocate(int num)
{
	int temp = num;
	size_t size_runner = 0;
	
	while (temp > 0)
	{
		temp = temp / 10; 
		++size_runner;
	}

	return size_runner;
}


