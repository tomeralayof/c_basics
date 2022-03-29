#include "ilrd_string.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/*re - implemantation after writing psudo code*/
size_t Strlen(const char *s)
{
	char *temp = (char *)s;
	
	assert(NULL!=s);
	
	while('\0'!= *s)
	{
		++s;
	}
	
	return s-temp+1; 
}

/*re - implemantation after writing psudo code*/
int Strcmp(const char *s1, const char *s2)
{
	assert(NULL!=s1);
	assert(NULL!=s2);
	
	while('\0'!= *s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	
	return *s1 - *s2;
}



/*
int Strcmp(const char *s1, const char *s2)
{
	
	assert(NULL!=s1 && NULL!=s2);

	while(*s1 && *s2) 
	{	
	
		if(s1!=s2 && s1 > s2)
		{			
			return 1;	
		} 
		else if(s1 !=s2 && s1 < s2)
		{
			return -1;
		}
		
		s1++;
		s2++;
	}
	
	return 0;
}
*/


/*
size_t Strlen(const char *s)
{
	int length = 0;
	assert(NULL!=s);
	
	while(*s)
	{
		s++;
		length++;
	}
	
	return length;
}
*/












