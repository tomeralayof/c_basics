#ifndef __WS1__H_ /*prevent of doing double include*/
#define __WS1__H_
 
char *StrCpy(char *dest, const char *src);
char *StrnCpy(char *dest, char *src,size_t n);
int StrCasecmp(char *s1, char *s2);
char *StrChr(const char *s, int c);
char *StrDup(const char *s);
char *StrCat(char *dest, const char *src);
char *StrnCat(char *dest, const char *src, size_t n);
char *StrStr(const char *haystack, const char *needle);
size_t StrSpn(const char *s, const char *accept);
int isPalindrom(char s[]);

#endif	/*__WS1__H_*/
