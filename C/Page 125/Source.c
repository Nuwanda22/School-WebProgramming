#include <stdio.h>

int main()
{
	int A[4][2], sum, i, j;
	for (i = 0; i < 4; i++){
		printf("%d�� �л��� ����, ���� ������ �Է��Ͻÿ� : ", i + 1);
		for (j = 0; j < 2; j++)
			scanf("%d", &A[i][j]);
	}
	for (i = 0; i < 4; i++){
		sum = 0;
		printf("%d���� �л� ���� : ", i + 1);
		for (j = 0; j < 2; j++)
			sum += A[i][j];
		printf("%d\n", sum);
	}
}