#include <stdio.h>
#include "functions.h"
#include<stdlib.h>

#define ESCAPE 27
#define ASCII_MAX 255
#define BIG_A 65
#define BIG_T 84

static void DisableTerminalBuffringAndEcho(void)
{
		system ("/bin/stty raw");
}

static void EnableTerminalBuffringAndEcho(void)
{
		system ("/bin/stty cooked");
}

static void SpecialLetterPressed(char letter)
{
	printf("%c - Pressed\n",letter);
}

void PrintAtIf()
{
	char c;
	
	printf("Implementation using else if:\n");
	printf("-----------------------------\n");
	DisableTerminalBuffringAndEcho();
	
	do
	{
		c = getchar();
		
		if(c == 'T' || c == 'A')
		{
			printf("%c-pressed\n",c);
		}
	}
	
	while(c != ESCAPE);
	

	EnableTerminalBuffringAndEcho();
}


void PrintAtSwitch()
{

	char c = '\0';
	printf("Implementation using switch case:\n");
	printf("-----------------------------\n");
	
	DisableTerminalBuffringAndEcho();

	while(c != ESCAPE)
	{
	
	c = getchar();
		
	 switch(c)
    {
       		case 'A':
    		case 'T':
				SpecialLetterPressed(c);
      		break;
   
    		default:
				printf("try again");
    }
	
	}
	
	EnableTerminalBuffringAndEcho();
}



void EmptyFunc(void){}

void PrintAPressed(void)
{
	printf("A-pressed\n");
}

void PrintTPressed(void)
{
	printf("T-pressed\n");
}

void PrintAtLut(void)
{
		
		int i = 0;
		char c = '\0';
		void (*ptr_messages[ASCII_MAX])(void) = { 0 };
		
		typedef void (*ptr_to_void_func) (void);
		ptr_to_void_func ptr_to_empty_func  = EmptyFunc;
		ptr_to_void_func ptr_to_print_a = PrintAPressed;
		ptr_to_void_func ptr_to_print_t = PrintTPressed;
		
		for( i = 0; i < ASCII_MAX; i++ )
		{
			ptr_messages[i] = ptr_to_empty_func;
		}
		
		ptr_messages[BIG_A] = ptr_to_print_a;
		ptr_messages[BIG_T] = ptr_to_print_t;
	
		DisableTerminalBuffringAndEcho();
		
		
		while(c != ESCAPE)
		{
			c = getchar();
			ptr_messages[(unsigned char)c]();
		}	
		
 		EnableTerminalBuffringAndEcho();
}




/*
#include <stdio.h>
#include "functions.h"
#include<stdlib.h>



void PrintAtIf()
{
	char c;
	
	printf("Implementation using else if:\n");
	printf("-----------------------------\n");
	system ("/bin/stty raw");
	
	do
	{
		c = getchar();
		
		if(c == 'T' || c == 'A')
		{
			printf("%c-pressed\n",c);
		}
	}
	
	while(c != 27);
	

	system ("/bin/stty cooked");
}


void PrintAtSwitch()
{

	char c = '\0';
	printf("Implementation using switch case:\n");
	printf("-----------------------------\n");
	
	system ("/bin/stty raw");

	while(c != 27)
	{
		c = getchar();
		
	 switch(c)
    {
       	case 'A':
				printf("A-pressed\n");
      		break;

    		case 'T':
				printf("T-pressed\n");
      		break;
   
    		default:
				printf("try again");
    }
	
	}
	
	system ("/bin/stty cooked");
}



void EmptyFunc(void){}

void PrintAPressed(void)
{
	printf("A-pressed\n");
}

void PrintTPressed(void)
{
	printf("T-pressed\n");
}

void PrintAtLut(void)
{
		
		int i = 0;
		char c = '\0';
		void (*ptr_messages[256])(void) = { 0 };
		
		typedef void (*ptr_to_void_func) (void);
		ptr_to_void_func ptr_to_empty_func  = EmptyFunc;
		ptr_to_void_func ptr_to_print_a = PrintAPressed;
		ptr_to_void_func ptr_to_print_t = PrintTPressed;
		
		for( i = 0; i < 255; i++ )
		{
			ptr_messages[i] = ptr_to_empty_func;
		}
		
		ptr_messages[65] = ptr_to_print_a;
		ptr_messages[84] = ptr_to_print_t;
	
		system ("/bin/stty raw");
		
		
		while(c != 27)
		{
			c = getchar();
			ptr_messages[(unsigned char)c]();
		}	
		
		system ("/bin/stty cooked");
}

*/














