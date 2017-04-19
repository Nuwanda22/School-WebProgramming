#pragma once

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define SLEEPTIME 500

void printArray(int arr[], int size);
void swap(int *a, int *b);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void quickSort(int arr[], int begin, int end);
int partiton(int arr[], int begin, int end);
void intervalSort(int arr[], int begin, int end, int interval);
void shellSort(int arr[], int size);
void mergeSort(int arr[], int m, int n);
void merge(int arr[], int m, int middle, int n);

int swapNum = 0;
int compareNum = 0;

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	puts("");
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	swapNum++;
}

void selectionSort(int arr[], int size)
{
	int i, j;        // �ݺ����� ����� ����.
	int min;        // �ּڰ��� �ε���

	for (i = 0; i < size - 1; i++) {
		// ���� ���� //
		min = i;                            // �ּڰ��� �ε��� �ʱ�ȭ�� �� ������ ù ��° ��
		for (j = i + 1; j < size; j++) {    // �� ����
			if (arr[min] > arr[j]) {
				min = j;
				compareNum++;
			}
		}									// �� ����, ���õ� �ּڰ��� �� �հ� �ڹٲٱ�
		swap(&arr[i], &arr[min]); swapNum++;
		// ���� ���� //

		// ���� ���� ��� ���� //
		printf("%d��° : ", i + 1);
		for (j = 0; j < size; j++) {
			printf("%d ", arr[j]);
		}
		puts(""); Sleep(SLEEPTIME);
	}
}

void insertionSort(int arr[], int size)
{
	int i, j;        // �ݺ����� ����� ����.
	int temp;        // ������ �����͸� ������ �ӽ� ����

	for (i = 1; i < size; i++) {
		// ���� ���� //
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (temp < arr[j]) {
				arr[j + 1] = arr[j];
				compareNum++;
			}
			else {
				break;
			}
		}
		arr[j + 1] = temp; swapNum++;
		// ���� ���� //

		// ���� ���� ��� ���� //
		printf("%d��° : ", i);
		for (j = 0; j < size; j++) {
			printf("%d ", arr[j]);
		}
		puts(""); Sleep(SLEEPTIME);
		// ���� ���� ��� ���� //
	}
}

void bubbleSort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--) {
		// ���� ���� //
		for (int j = 0; j < i; j++) {       
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j + 1], &arr[j]);
				compareNum++;
			}								
		}
		// ���� ���� //

		// ���� ���� ��� ���� //
		printf("%d��° : ", 5 - i);			
		for (int j = 0; j < size; j++) {
			printf("%d ", arr[j]);
		}
		puts(""); Sleep(SLEEPTIME);
		// ���� ���� ��� ���� //
	}
}

// �� ������ �������� �˰����� �����Ͽ����� ���� �ʽ��ϴ�...
void quickSort(int arr[], int begin, int end)
{
	if (begin < 5){ //5�� �ڷ� ����
		//����
		int pivot = partiton(arr, begin, end);
		
		quickSort(arr, begin, pivot - 1);

		quickSort(arr, pivot + 1, end);
	}
}

int partiton(int arr[], int begin, int end)
{
	int pivot = (begin + end) / 2;
	int left = begin;
	int right = end;

	while (left < right){
		while (arr[left] <= arr[pivot] && left < right)
			left++;
		while (arr[right] >= arr[pivot] && left < right)
			right--;
		if (left < right)
			swap(&arr[left], &arr[right]);
	}
	swap(&arr[pivot], &arr[left]);
	return left;
}

void intervalSort(int arr[], int begin, int end, int interval)
{
	int i, j, item;

	for (i = begin + interval; i <= end - 1; i += interval){
		item = arr[i];

		for (j = i - interval; j >= begin && item < arr[j]; j -= interval)
			arr[j + interval] = arr[j];

		arr[j + interval] = item;
	}
}

void shellSort(int arr[], int size)
{
	int interval = size;

	puts("********** �� ���� ���� **********"); // ����� ����
	while (interval > 1){
		interval = interval / 2;
		printf("interval = %d\t", interval); // ����� ����

		for (int i = 0; i < interval; i++)
			intervalSort(arr, i, size, interval);
		printArray(arr, size); // ����� ����
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (arr[left]){
		//mergeSort(arr,left,middle)
	}
}

void merge(int arr[], int left, int middle, int right)
{
	
}

void radixSort(int arr[], int size)
{
	int radix[10][10];
	int newArr[10];
	int index[10] = { 0 };
	for (int i = 0; i < size; i++){
		int item = arr[i];

		if (item % 10 == 0) radix[0][index[0]++] = item;
		else if (item % 10 == 1) radix[1][index[1]++] = item;
		else if (item % 10 == 2) radix[2][index[2]++] = item;
		else if (item % 10 == 3) radix[3][index[3]++] = item;
		else if (item % 10 == 4) radix[4][index[4]++] = item;
		else if (item % 10 == 5) radix[5][index[5]++] = item;
		else if (item % 10 == 6) radix[6][index[6]++] = item;
		else if (item % 10 == 7) radix[7][index[7]++] = item;
		else if (item % 10 == 8) radix[8][index[8]++] = item;
		else if (item % 10 == 9) radix[9][index[9]++] = item;
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < index[i]; j++){
			newArr[j] = radix[i][j];
		}
	}

	for (int i = 0; i < size; i++){
		int item = newArr[i];

		if (item % 100 >= 0 && item % 100 < 10) radix[1][0] = item;
		else if (item % 100 >= 10 && item % 100 < 20) radix[1][1] = item;
		else if (item % 100 >= 20 && item % 100 < 30) radix[1][2] = item;
		else if (item % 100 >= 30 && item % 100 < 40) radix[1][3] = item;
		else if (item % 100 >= 40 && item % 100 < 50) radix[1][4] = item;
		else if (item % 100 >= 50 && item % 100 < 60) radix[1][5] = item;
		else if (item % 100 >= 60 && item % 100 < 70) radix[1][6] = item;
		else if (item % 100 >= 70 && item % 100 < 80) radix[1][7] = item;
		else if (item % 100 >= 80 && item % 100 < 90) radix[1][8] = item;
		else if (item % 100 >= 90 && item % 100 < 100) radix[1][9] = item;
	}
	for (int i = 0; i < size; i++){
		int item = radix[1][i];

		if (item % 1000 >= 0 && item % 1000 < 100) radix[2][0] = item;
		else if (item % 1000 >= 100 && item % 1000 < 200) radix[2][1] = item;
		else if (item % 1000 >= 200 && item % 1000 < 300) radix[2][2] = item;
		else if (item % 1000 >= 300 && item % 1000 < 400) radix[2][3] = item;
		else if (item % 1000 >= 400 && item % 1000 < 500) radix[2][4] = item;
		else if (item % 1000 >= 500 && item % 1000 < 600) radix[2][5] = item;
		else if (item % 1000 >= 600 && item % 1000 < 700) radix[2][6] = item;
		else if (item % 1000 >= 700 && item % 1000 < 800) radix[2][7] = item;
		else if (item % 1000 >= 800 && item % 1000 < 900) radix[2][8] = item;
		else if (item % 1000 >= 900 && item % 1000 < 1000) radix[2][9] = item;
	}
}