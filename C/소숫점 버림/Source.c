#include <stdio.h> 

int main() 
{   // ���� ����
	float average;
	float num, num1, num2;
	// �Է�
	printf("input : ");
	scanf("%f%f", &num1, &num2);
	//����
	num = num1 / num2;
	average = (int)(num * 1000) / 1000.0;
	//���
	printf("%.3f\n", average);
	//����
	return 0;
}