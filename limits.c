#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
	printf("Type\t\tBytes\t\t\t	Range\n");
	printf("---\n");
	printf("char\t\t %2lu\t%20d ... %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("unsigned char\t %2lu\t%20d ... %d\n", sizeof(char), 0, UCHAR_MAX);
	printf("short\t\t %2lu\t%20d ... %d\n", sizeof(short int), SHRT_MIN, SHRT_MAX);
	printf("int\t\t %2lu\t%20d ... %d\n", sizeof(int), INT_MIN, INT_MAX);
	printf("unsigned int\t %2lu\t%20d ... %u\n", sizeof(int), 0, UINT_MAX);
	printf("long\t\t %2lu\t%20ld ... %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
	printf("long long\t %2lu\t%20lld ... %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
	printf("unsigned long\t %2lu\t%20u ... %lu\n", sizeof(unsigned long), 0, ULONG_MAX);
	printf("unsign. long long%2lu\t%20u ... %llu\n", sizeof(unsigned long long), 0, ULLONG_MAX);

	printf("---\n");
	printf("Double\t\t %2lu\t%20f ... %f\n", sizeof(double), DBL_MIN, DBL_MAX);
	printf("Long double\t %2lu\t%20Lf ... %Lf\n", sizeof(double), LDBL_MIN, LDBL_MAX);
	printf("---\n");

	printf("float\t\t %2lu\t EXP(%6d...%d)\n", sizeof(float), FLT_MIN_EXP, FLT_MAX_EXP);
	printf("double\t\t %2lu\t EXP(%6d...%d)\n", sizeof(float), DBL_MIN_EXP, DBL_MAX_EXP);
	printf("long double\t %2lu\t EXP(%6d...%d)\n", sizeof(float), LDBL_MIN_EXP, LDBL_MAX_EXP);
	
	printf("---\n");

//	printf("FLT_DIG\t\t%3d\nDBL_DIG\t\t%3d\nLDBL_DIG\t%3d\n", FLT_DIG, DBL_DIG, LDBL_DIG);
	printf("%lf\n", 1.5E-10);
	return 0; 
}
