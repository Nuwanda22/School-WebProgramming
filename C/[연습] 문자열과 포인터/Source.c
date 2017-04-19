#include <stdio.h>

int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	int *p1, *p2;

	p1 = arr;
	p2 = p1 + 2;

	printf("p1 = %d p2 = %d\n", p1, p2);
	printf("p2 - p1 = %d\n", p2 - p1);
}