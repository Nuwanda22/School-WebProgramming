#include <stdio.h>

void f(int a, int b)
{
	int t;

	t = a;
	a = b;
	b = t;
	printf("a = %d, b = %d in f\n", a, b);
}
main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	f(a, b);
	printf("a = %d, b = %d in main\n", a, b);
}