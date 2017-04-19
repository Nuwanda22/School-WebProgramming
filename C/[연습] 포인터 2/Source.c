#include <stdio.h>

int main()
{
	int a = 5, b = 10, *p1 = &a, *p2 = &b;
	double c = 3.14, *p3 = NULL;

	p3 = &c;

	printf("*p1 : %d a : %d\n", *p1, a);
	printf("**p1 : %d\n", **&p1);
	printf("*p3 : %lf\n", *p3);
	printf("*(p3 = &b) : %d\n", *(p3 = &b));
}