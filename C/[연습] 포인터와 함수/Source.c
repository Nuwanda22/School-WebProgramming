#include <stdio.h>

int Maximum(int arr[], int size)
{
	int i, max = 0;
	for (i = 0; i < size; i++){
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int main()
{
	int i, arr[6] = { 5, 3, 4, 9, 6, 2 };
	
	i = Maximum(arr, sizeof(arr)/sizeof(arr[0]));
	
	printf("Maximum Value : %d\n", i);
	return 0;
}