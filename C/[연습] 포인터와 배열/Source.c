#include <stdio.h>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptArr = arr;
	int i;

	for (i = 0; i <= 4; i++)
		*(ptArr + i) += 2;
	for (i = 0; i <= 4; i++)
		printf("%d ", arr[i]);

	return 0;
}