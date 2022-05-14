/* Show sizes of built-in C types */
#include <stdio.h>

int main()
{
    printf("Built-in C type|bytes\n");
    printf("---------------+-----\n");
    printf("char\t\t%2ld\n",     sizeof(char));
    printf("short\t\t%2ld\n",    sizeof(short));
    printf("int\t\t%2ld\n",      sizeof(int));
    printf("long\t\t%2ld\n",     sizeof(long));
    printf("long long\t%2ld\n",  sizeof(long long));
    printf("float\t\t%2ld\n",    sizeof(float));
    printf("double\t\t%2ld\n",   sizeof(double));  
    printf("long double\t%2ld\n",sizeof(long double));

    return 0;
}