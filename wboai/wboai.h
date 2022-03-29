#ifndef __WBOAI_H___
#define __WBOAI_H___

#include <stddef.h> /* size_t */

int IsAtoiEqual( const char *  param_1_ex_2);
/*
void CheckConditions(const char *str);
int ReturnZero();
*/




/* DESCRIPTION: 
 * Construct a string representation of an integar	
 *
 * PARAMS: 
 * int      Value to be converted
 * char*    Pointer to string to be returned. String should have enough length to match the converted value and NULL terminator character. Insufficient string size will cause undefined behavior.
 *
 * RETURN:
 * Pointer to string we received 
 */
char *ItoaIntToStr(int value, char *str);

/*  DESCRIPTION: 
 *  Convert the inital portion of the string pointed to by char* to int, The string to be converted consists of optional leading white space, an optional sign and a series of contiguous digits, Otherwise it will be undefined behavior.
 *
 *  PARAMS:
 *  const char*  Pointer to string to be converted to int. 
 *
 *  RETURN:
 *  int value of the convert string portion
 */
int AtoiStrToInt(const char *str);

/* DESCRIPTION: 
 * Construct a string representation of an integar. 
 *
 * PARAMS: 
 * int                Value to be converted, must be 0 or positive
 * char*    Pointer to string to be returned. String should have enough length to match the converted value and NULL terminator character. Insufficient string size will cause undefined behavior.
 * unsigned int       conversion base of the int
 *
 * RETURN: 
 * char*
 */
char *ItoaIntToStrBase(int value, char *str, unsigned int base);




/*  DESCRIPTION:
 *  Convert the inital portion of the string pointed to by str to int. Convert the inital portion of the string pointed to by char* to int, The string to be converted consists of optional leading white space, an optional sign and a series of contiguous digits, Otherwise it will be undefined behavior.
 *
 *  PARAMS:
 *  char*             Pointer to string to be converted to an int
 *  unsigned int      Base for conversion
 *
 *  RETURN:
 *  int 
 */

int AtoiStrToIntBase(const char *str, unsigned int base);

/* DESCRIPTION:
 * Function receive 3 arrays of chars, prints letters only that  are in both first 2 and not in third
 * 
 * PARAMS:
 * 3 char*      Arrays of characters
 * 3 size_t     Sizes of the arrays
 *
 * RETURN: 
 * None
 */

void PrintFromArrays(char *first_array, char *second_array, char *third_array, size_t sizeof_array1, size_t sizeof_array2, size_t sizeof_array3);

/* DESCRIPTION:
 * Function checks whever the system is Little Endian
 *
 * PARAMS:
 * None
 *
 * RETURN: 
 * Returns 0 if found to be Little Endian, and 1 if not found to be little endian
 */

int IsLittleEndian(void);

#endif /*__WBOAI_H___*/





