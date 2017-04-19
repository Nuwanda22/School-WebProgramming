#include <stdio.h>
#pragma warning (disable:4996)
main()
{
	float a;
	char b;
	char c[10];
	scanf("%f %c %s", &a, &b, &c);
	printf("%f %c %s", a, b, c);
}