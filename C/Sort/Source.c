#include "Header.h"

#define arraySize(x) sizeof(x) / sizeof(*x)

int main()
{
	int arr[5] = { 8, 4, 2, 6, 1 };
	int shellArray[8] = { 16, 8, 30, 2, 69, 10, 31, 22 };
	int radixArray[10] = { 35, 102, 352, 89, 25, 78, 523, 630, 9, 91 };

	printf("������ : ");
	printArray(radixArray, arraySize(radixArray)); // 5�� sizeof(arr)/sizeof(*arr)�� �ᵵ ��
	
	puts("������ �����Ͻÿ�! \n| 1. ���� | 2. ���� | 3. ���� | 4. �� | 5. �� | 6. ���� | 7. ��� |");
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

	printf("������ : ");
	printArray(radixArray, arraySize(radixArray));
	printf("�� Ƚ�� : %d ��ȯ Ƚ�� : %d\n", compareNum, swapNum);



	return 0;
}