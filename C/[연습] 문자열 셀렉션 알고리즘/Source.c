#include <stdio.h>
#include <string.h>

void stringSelectionSort(char *p[], int n);
void temp(int a, int b);

int main()
{
	char *str[5] = { "black", "outback", "vips", "fisher", "ashully" };
	
	stringSelectionSort(str, 5);

	printf("문자열 정렬\n");
	for (int i = 0; i < 5; i++){
		printf("%s\n", str[i]);
	}
}

void stringSelectionSort(char *p[], int n)
{
	int temp; // 문자열 주소를 바꿈
	//char *temp;으로 선언 시 문자열 자체를 바꿈

	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (strcmp(p[i], p[j]) > 0){
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}