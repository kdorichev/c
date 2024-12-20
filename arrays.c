/* Arrays: static and variable-length ones */
#include <stdio.h>
#define ARRAY_SIZE 10
#define MAX_ARRAY_SIZE 2048

int main(void)
{
	char carr[ARRAY_SIZE];
	int	 iarr[ARRAY_SIZE] = {10, 20, -10, -20}; // Initialize some elements; the rest will be 0
	printf("Address of static array: %p\n", iarr);

	// write at most size bytes (including the terminating null byte ('\0')) to str
	snprintf(carr, sizeof(carr), "0123456789012345");
	printf("%s\n", carr);

	int num = 54;
	printf("%6d\n", num); // padding from the left

	// Enumeration constants are also ways to declare constants
	enum days {MON=1, TUE, WED, THU, FRI, SAT, SUN}; // 
	printf("Monday is %d, Wednesday is %d\n", MON, WED);

	printf("%s\t%lu\n", carr, sizeof(carr));

	for (int i=0; i<ARRAY_SIZE; i++){
		printf("%d\t%d\n", i, iarr[i]);
	}

	// In C99 (and as an optional feature in C11), variable-length arrays (VLAs)
	// can be declared as well. The size of such an array need not be a compile
	// time constant:
	printf("Enter the array size: 0...%d elements\n", MAX_ARRAY_SIZE);
	int array_size;
	fscanf(stdin, "%u", &array_size);

	if (array_size > MAX_ARRAY_SIZE){
		printf("Entered array size %d > %d", array_size, MAX_ARRAY_SIZE);
		return 1;
	}

	int var_length_array[array_size];
	printf("sizeof array = %zu bytes\n", sizeof var_length_array);
	printf("Address of VLA: %p\n", var_length_array);
	return 0;
}
