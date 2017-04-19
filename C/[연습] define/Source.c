#include <stdio.h>
#define DOUBLE(x) x + x

#define VER 7
#define BIT16 

int main()
{
	// 매크로 함수
	int iVAL;
	double fVAL;

	printf("정수를 입력하세요 : ");
	scanf("%d", &iVAL);
	printf("결과는 %d입니다.\n", DOUBLE(iVAL));

	printf("실수를 입력하세요 : ");
	scanf("%lf", &fVAL);
	printf("결과는 %lf입니다.\n", DOUBLE(fVAL));
	printf("");
	
	puts("");
	
	//조건부 컴파일 지시자
	int max;

#if VER >= 6
	printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16
	max = 32767;
#else
	max = 2147483647;
#endif

	printf("int형 변수의 최댓값 : %d\n", max);
	return 0;
}