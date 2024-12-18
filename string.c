/* 
	Simple output to console with check of the result.
	Difference bw sizeof() and strlen()
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	int x = 0;
	char str[] = "12345";

	x = printf("%s", str);
	printf("\nPrinted %d chars\n", x);

	printf("Length of String is %lu\n", strlen(str));
	printf("Size of String is %lu (including trailing \\0)\n", sizeof(str));	

	return 0;
}
