#include <stdio.h>

main()
{
	int a = 365;
	float b = 3.14;
	printf("[%5d]\t[%10d]\n", a, a);
	printf("[%5.1f]\t[%5.10f]\n", b, b);
}