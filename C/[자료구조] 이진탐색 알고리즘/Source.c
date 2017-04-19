#include <stdio.h>
#define ARRAYSIZE 10

int linearSearch(int arr[], int n, int key);

int main()
{
	int array[ARRAYSIZE] = { 5, 7, 12, 15, 20, 22, 25, 27, 30, 45 };
	int key, find, count = sizeof(array) / sizeof(*array);

	for (int i = 0; i < ARRAYSIZE; i++){
		printf("\t%d", array[i]);
	}
	puts("");

	printf("input : ");
	scanf("%d", &key);

	find = binarySearch(array, count, key);

	if (find >= 0)
		printf("array[%d] = %d\n", find, array[find]);
	else
		printf("no data\n");

	return 0;
}

int binarySearch(int arr[], int n, int key)
{
	int left = 0, right = n - 1;
	int middle;

	while (left <= right){
		middle = (left + right) / 2;

		if (arr[middle] == key)
			return middle;
		else {
			if (arr[middle] < key)
				right = middle - 1;
			else
				left = middle + 1;
		}
	}
}