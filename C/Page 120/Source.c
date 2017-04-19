#include <stdio.h>

main()
{
	int score[5];
	int i, sum = 0;
	for (i = 0; i < 5; i++){
		printf("%d번의 학생의 프로그래밍 성적을 입력하세요. : ", i + 1);
		scanf("%d", &score[i]);
	}
	for (i = 0; i < 5; i++)
		sum += score[i];
	printf("합계 : %d\n", sum);
	printf("평균 : %.2f\n", sum / 5.0);
}