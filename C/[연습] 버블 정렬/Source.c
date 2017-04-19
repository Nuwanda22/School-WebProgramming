#include <stdio.h>

//void BubbleSort(int arr[], int n)
//{
//	int a, b, tmp;
//
//	for (a = 0; a < n - 1; a++){
//		for (b = 0; b < (n - a) - 1; b++){
//			if (arr[b] > arr[b + 1]){
//				tmp = arr[b];
//				arr[b] = arr[b+1];
//				arr[b+1] = tmp;
//			}
//		}
//	}
//}

void BubbleSort(int *p, int n)
{
	int a, b, tmp;

	for (a = 0; a < n - 1; a++){
		for (b = 0; b < (n - a) - 1; b++){
			if (*(p + b) > *(p + b + 1)){
				tmp = *(p + b);
				*(p + b) = *(p + b + 1);
				*(p + b + 1) = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 35, 3, 12, 9, 1, 20, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, n);

	printf("버블정렬결과\n");

	for (int i = 0; i < n; i++)
		printf("\t%d", arr[i]);

	return 0;
}