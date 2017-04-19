#include <stdio.h>

int main()
{
	int A[4][2], sum, i, j;
	for (i = 0; i < 4; i++){
		printf("%d번 학생의 수학, 과학 성적을 입력하시오 : ", i + 1);
		for (j = 0; j < 2; j++)
			scanf("%d", &A[i][j]);
	}
	for (i = 0; i < 4; i++){
		sum = 0;
		printf("%d번의 학생 점수 : ", i + 1);
		for (j = 0; j < 2; j++)
			sum += A[i][j];
		printf("%d\n", sum);
	}
}