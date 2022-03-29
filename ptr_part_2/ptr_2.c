#include <stdio.h>
#include <string.h> /*The string.h header defines one variable type, one macro, and various functions for manipulating arrays of characters.*/
#include "ptr_2.h"
#include <assert.h>
#include <stdlib.h>
#include <ctype.h> 

  
char *StrCpy(char *dest, const char *src)
{
	assert( NULL != dest);
	assert( NULL != src);
	
	while ('\0'!= *src)
	{
		*dest = *src;
		++src;
		++dest;
	}
	
	*dest = '\0'; 
	return dest;
}

char *StrnCpy(char *dest, char *src, size_t n)
{

	assert( NULL != src);	
	assert( NULL != dest);

	while (n > 0)
	{
		*dest = *src;
		++src;
		++dest;
		--n;
	}
	
	*dest = '\0'; 
	
	return dest;
}


int StrCasecmp( char *s1, char *s2)
{	

	assert( NULL != s1);
	assert( NULL != s2);

	while(('\0'!= *s1) && (0 == tolower(*s1) - tolower(*s2)))
	{
		++s1;
		++s2;
	}

	return (*s1 - *s2);
}


char *StrChr(char const *s, int c)
{

	assert(NULL != s);
	
	while ('\0' != *s)
	{
		if(*s == c)
		{
			return (char *)s;
		}	
		++s;
	}
	
	return NULL;
}


char *StrDup(const char *s)
{
	int length = strlen(s);
	char *str2 = (char *)malloc(sizeof(char) * length + 1);
	assert(NULL != s);
	
	StrCpy(str2, (char *)s);
	return str2;		
}


char *StrCat(char *dest, const char *src)
{

	assert(NULL != dest);
	assert(NULL != src);
	
	StrCpy(dest + strlen(dest),src);

	return 	dest;	
}	


char *StrnCat(char *dest, const char *src, size_t n)
{
	char *result = dest;
	dest = dest + strlen(dest); /*1000 + 6 for example*/
	assert(NULL!=dest);
	assert(NULL!=src);
	StrnCpy(dest,(char *)src,n); /*suppose to be const char * upstair*/
	return result;	
}


char *StrStr(const char *haystack, const char *needle)
{
	size_t needle_length = strlen(needle);
	
	assert(NULL != haystack);
	assert(NULL != needle);
	 
	 while (NULL != (haystack = StrChr(haystack,*needle)))
	 { 	
	 	if( 0 == strncmp(haystack, needle, needle_length))
	 	{
	 		break;
	 	} 
	 	
	 	++haystack;
	 }                                                                                                                                                                                                                   
	
	return (char *)haystack;
}


size_t StrSpn(const char *s, const char *accept)
{

	char *temp_s = (char*)s; 
	
	assert(NULL != s);
	assert(NULL != accept);
	
	while('\0'!=*s && NULL!=StrChr(accept,*s))
	{	
		s++;	
	}
	
	return (s - temp_s);
}


int isPalindrom(char s[])
{	
	int length = strlen(s);
	char *last = s + length -1;
	
	assert(NULL != s);
	
	while((s < last) && (tolower(*s) - tolower(*last) == 0))
	{
		s++;
		last--;
	}
	
	return (*s - *last);
}






/*********************Algoritems first try*************************/
/*
char *StrChr(const char *s, int c)
{
	int sign =0;
	static char result[100];
	int result_index = 0;
	
	while(*s)
	{
		if(*s == c)
		{
			sign=1;
			return (char *)s;
		}	
				
		if(sign == 1)
		{
			result[result_index]=*s;
			result_index++;	
		}
		s++;
	}	
	
	return result;
}
*/

/*
int StrCasecmp( char *s1, char *s2)
{
	assert( NULL != s1);	
	assert( NULL != s2);
	
	while(*s1) 
	{
		if( (*s1>='A')&& (*s1<='Z'))
		{
			*s1=*s1+32;
		}
		
		else if((*s2>='A')&&(*s2<='Z'))
		{
			*s2=*s2+ 32;
		}
		
		else if (*s1!=*s2)
		{
			return 1;
		}
		s1++;
		s2++;
	}
	
	return 0;	
}
*/


/*
char *StrCat(char *dest, const char *src)
{
	char *dest_cpy = dest;
	dest =  dest + strlen(dest); 
	assert(NULL!=dest);
	assert(NULL!=src);

	while('\0'!= *src)
	{
		*dest=*src;
		src++;
		dest++;
	}
	
	*dest_cpy = '\0'; 
	
	return dest_cpy;
}

*/


/*
char *StrStr(const char *haystack, const char *needle)
{	

	int length_n = strlen(needle);
	int count = 0;
	char *temp=(char *) needle;;

	assert(NULL!=haystack);
	assert(NULL!=needle);

	while('\0'!=*haystack)
	{
		
		if(*haystack == *needle)
		{
			++needle;
			++count;
		}
		else if(*haystack!=*needle)
		{
			needle = temp;
			count=0;
		}
		
		else if(count==length_n)
		{
			return (char *) haystack;
		}
		
		++haystack;				
	}

	return NULL;
}
*/

/*
int Strcmp(const char *s1, const char *s2)
{
	
	assert(NULL!=s1);
	assert(NULL!=s2);

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
char *StrStr(const char *haystack, const char *needle)
{	

	int length_n = strlen(needle);
	int count = 0;
	char *temp=(char *) needle;;

	assert(NULL!=haystack);
	assert(NULL!=needle);

	while('\0'!=*haystack)
	{
		
		if(*haystack == *needle)
		{
			++needle;
			++count;
		}
		else if(*haystack!=*needle)
		{
			needle = temp;
			count=0;
		}
		
		else if(count==length_n)
		{
			return (char *) haystack;
		}
		
		++haystack;				
	}

	return NULL;
}
*/


