#include <stdio.h>

int main()
{
	int value1 = 10, value2 = 20;
	int *pt1 = &value1, *pt2 = &value2;

	*pt1 += 10;
	*pt2 -= 10;

	pt1 = &value2;
	pt2 = &value1;

	printf("pt1 = %d, pt2 = %d", *pt1, *pt2);
	return 0;
}