#include <stdio.h>

int main()
{
	int*	pt1 = 0;
	char*	pt2 = 0;
	double* pt3 = 0;

	printf("%d번지, %d번지. %d번지 \n", pt1++, pt2++, pt3++);
	printf("%d번지, %d번지. %d번지 \n", pt1, pt2, pt3);
	printf("%d번지, %d번지. %d번지 \n", pt1--, pt2--, pt3--);
	printf("%d번지, %d번지. %d번지 \n", pt1, pt2, pt3);
	
	//return 0;

	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptArr = arr;

	printf("%d\n", *ptArr);
	printf("%d\n", *(++ptArr));
	printf("%d\n", *(++ptArr));

	printf("%d\n", *(ptArr + 1));
	printf("%d\n", *(ptArr + 2));

	return 0;
}