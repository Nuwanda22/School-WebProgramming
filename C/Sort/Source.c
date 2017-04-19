#include "Header.h"

#define arraySize(x) sizeof(x) / sizeof(*x)

int main()
{
	int arr[5] = { 8, 4, 2, 6, 1 };
	int shellArray[8] = { 16, 8, 30, 2, 69, 10, 31, 22 };
	int radixArray[10] = { 35, 102, 352, 89, 25, 78, 523, 630, 9, 91 };

	printf("정렬전 : ");
	printArray(radixArray, arraySize(radixArray)); // 5는 sizeof(arr)/sizeof(*arr)로 써도 됨
	
	puts("정렬을 선택하시오! \n| 1. 삽입 | 2. 선택 | 3. 버블 | 4. 퀵 | 5. 쉘 | 6. 병합 | 7. 기수 |");
	switch (getch())
	{
	case '1':
		insertionSort(arr, 5);
		break;
	case '2':
		selectionSort(arr, 5);
		break;
	case '3':
		bubbleSort(arr, 5);
		break;
	case '4':
		quickSort(arr, 0, 4);
		break;
	case '5':
		shellSort(shellArray, arraySize(shellArray));
		break;
	case '6':
		mergeSort(arr, 0, 4);
		break;
	case '7':
		radixSort(radixArray, arraySize(radixArray));
		break;
	default:
		break;
	}

	printf("정렬후 : ");
	printArray(radixArray, arraySize(radixArray));
	printf("비교 횟수 : %d 교환 횟수 : %d\n", compareNum, swapNum);



	return 0;
}