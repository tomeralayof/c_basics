#include <stdio.h>
#include "wbo.h"


#define CASTING(type, var) (*(type*)&(var))
#define ALGNMENT_SIZE (7)
#define WORD_SIZE (sizeof(size_t))


void *Memset(void *s, int c, size_t n)
{	

	void *start = s;
	size_t w = (size_t) c;

	w = w | (w << WORD_SIZE);
	w = w | (w << WORD_SIZE*2);
	w = w | (w << WORD_SIZE*4);
	
	while((0 != (CASTING(size_t,s) & ALGNMENT_SIZE) && n > WORD_SIZE) || n > 0) 
	{
		*CASTING(char *, s) = (char) c;
		++(CASTING(char *,s));
		--n;
	}	
	
	while(n > sizeof(size_t)) 
	{
		*(CASTING(size_t *,s)) = w;
		++(CASTING(size_t *,s));
		n -= WORD_SIZE;
	}
	
	return start;			
}




void *Memcpy(void *dest, const void *src, size_t n)
{

	void * start = CASTING(char *,dest);
	
	while(n > sizeof(size_t) -1)
	{
		*(CASTING(size_t *,dest)) = *CASTING(size_t *,src); 
		++(CASTING(size_t *,dest));
		++(CASTING(size_t *,src));
		n -= sizeof(size_t);
	}
	
	while(n > 0 )
	{

		*(CASTING(char *,dest)) = *(CASTING(char *,src));
		++(CASTING(char *,dest));
		++(CASTING(char *,src));
		--n;

	}	
	
	return start;
	
}


void *Memmove(void *dest, const void *src, size_t n)
{

	if((CASTING(char *,src)) <  (CASTING(char *, dest)))
	{
		void *new_src = (CASTING(char *,src)) + n -1;
		void *new_dest = (CASTING(char *,dest)) + n -1;
		
		while(n > 0)
		{
			*CASTING(char *,new_dest) = *CASTING(char *,new_src);
			--(CASTING(char *,new_dest));
			--(CASTING(char *,new_src));
			--n;
		}
		
		return new_dest;
	}
	
	else 
	{
		return Memcpy(dest,src,n);
	}
}








