#include <stdio.h>
#include <string.h>

void stringSelectionSort(char *p[], int n);
void temp(int a, int b);

int main()
{
	char *str[5] = { "black", "outback", "vips", "fisher", "ashully" };
	
	stringSelectionSort(str, 5);

	printf("���ڿ� ����\n");
	for (int i = 0; i < 5; i++){
		printf("%s\n", str[i]);
	}
}

void stringSelectionSort(char *p[], int n)
{
	int temp; // ���ڿ� �ּҸ� �ٲ�
	//char *temp;���� ���� �� ���ڿ� ��ü�� �ٲ�

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