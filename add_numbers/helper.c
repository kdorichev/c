/**
 * Helper function
 */
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "helper.h"

#ifndef MAX_NUMBER_LEN
#include "add-two-numbers.h"
#endif

int is_all_digits(char* string)
/* Check if all chars in a `string` are digits
 * Return 1 if true, 0 if false.
 */
{
	for (unsigned i = 0; i<strlen(string); i++)
	{
		if (! isdigit(string[i])){
#ifdef DEBUG
		printf("Error: not all digits: %s\n", string); 		
#endif
			return 0;
		}
	}
	return 1;
}

/* Check input data validity:
 * - all digits;
 * - not more than MAX_NUMBER_LEN
 * Return 1 if OK, 0 if NOK.
 */
int check_inputs(char *str1, char *str2)
{
	if (strlen(str1) > MAX_NUMBER_LEN || strlen(str2) > MAX_NUMBER_LEN)
	{
#ifdef DEBUG
		printf("input(s) longer than %d", MAX_NUMBER_LEN); 		
#endif
		return 0;
	}  
	if ( !is_all_digits(str1) || !is_all_digits(str2))
	{
		return 0;
	}
	return 1;
}

