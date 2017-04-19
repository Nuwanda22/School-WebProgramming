#include <stdio.h>

int main()
{
	int *p, i;
	int a[5] = { 100, 78, 95, 66, 96 };
	p = a;
	for (i = 0; i < 5; i++)
		printf("%d ", a[i]);
	puts("");
	for (i = 0; i < 5; i++)
		printf("%d ", *(p + i));
	puts("");
}