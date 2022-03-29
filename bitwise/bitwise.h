#ifndef __BITWISE_H__
#define __BITWISE_H__
#include <stddef.h>

/*********ex.1*********/
/* DESCRIPTION:
 * Recieves two unsigned ints and returns the power of x by (2^y).
 *
 * PARAMS:
 * two unsigned ints 
 * 
 * RETURN:
 * long 
 */
long Pow2 (unsigned int, unsigned int);


/*********ex.2*********/
/* DESCRIPTION:
 * The function recieves unsigned int and return 1 is it is the power of two
 * or 0 if it isn't.
 *
 * PARAMS:
 * unsigned int 
 * 
 * RETURN:
 * int (0 or 1)
 */
int IsPowOf2Loop (unsigned int);


/* DESCRIPTION:
 * The function recieves unsigned int and return 1 is it is the power of two
 * or 0 if it isn't.
 *
 * PARAMS:
 * unsigned int 
 * 
 * RETURN:
 * int (0 or 1)
 */
int IsPowOf2 (unsigned int);


/*********ex.3*********/
/* DESCRIPTION:
 * The function recieves a int to int and add 1 to his value. 
 *
 * PARAMS:
 * int *
 * 
 * RETURN:
 * int
 */
int AddOne (int);


/*********ex.4********/
/* DESCRIPTION:
 * Prints only the ints that have exactly 3 bits on.
 *
 * PARAMS:
 * unsigned int array, size_t array_size
 * 
 * RETURN:
 * None
*/
void PrintThreeBitsOnElements(unsigned int *arr, size_t arr_size);



/*********ex.5*********/
/* DESCRIPTION:
 * Reverses num
 *
 * PARAMS:
 * unsigned int 
 * 
 * RETURN:
 * unsigned int 
 */ 
unsigned int ByteMirrorLoop(unsigned int num);
 
 
 /* DESCRIPTION:
 * Reverses num.
 * The function is not using any loop
 *
 * PARAMS:
 * unsigned int number
 * 
 * RETURN:
 * unsigned int number
 */
unsigned int ByteMirrorWithoutLoop(unsigned int num);


/*********ex.6*********/
/* DESCRIPTION:
 * Returns "true" if both givven indexes are "on" and "false" otherwise
 *
 * PARAMS:
 * unsigned char
 * 
 * RETURN:
 * True/False
 */
int IsBothIdxOn(unsigned char);




/* DESCRIPTION:
 * Returns "true" if one of the givven indexes is "on" and "false" otherwise
 *
 * PARAMS:
 * unsigned char
 * 
 * RETURN:
 * True/False
 */
int IsOneOfIdxOn(unsigned char);





/* DESCRIPTION:
 * Swaps between the 3rd and the 5th bits out of a givven unsigned char
 *
 * PARAMS:
 * unsigned char
 * 
 * RETURN:
 * Outcome number
 */
unsigned char BitSwapByIdx(unsigned char);


/*********ex.7*********/
/* DESCRIPTION:
 * Returns the largest number within a givven number that is divisible by 16
 *
 * PARAMS:
 * Unsgined int
 * 
 * RETURN:
 * Unsgined int
 */
unsigned int ClosestDividedByHex(unsigned int);


/*********ex.8*********/
/* DESCRIPTION:
 * Swaps between 2 givvem variables without using a third (temp) one
 *
 * PARAMS:
 * int, int
 * 
 * RETURN:
 * None
 */
void BitwiseSwap(int *, int *);
#include <stddef.h>


/*********ex.9*********/
/* DESCRIPTION:
 * Counts the number of set bits.
 *
 * PARAMS:
 * integer for bit count.
 * 
 * RETURN:
 * number of set bits.
 */
size_t CountSetBitsLoop(unsigned int);


/* DESCRIPTION:
 * Counts the number of set bits.
 *
 * PARAMS:
 * integer for bit count.
 * 
 * RETURN:
 * number of set bits.
 */
size_t CountSetBitsNoLoop(unsigned int);

/*********ex.10*********/
/* DESCRIPTION:
 * prints the bits of a float variable.
 *
 *
 * PARAMS:
 * float variable.
 * 
 * RETURN:
 * none.
 */
void FloatPrintBits(float);


#endif /*__BITWISE_H__*/





