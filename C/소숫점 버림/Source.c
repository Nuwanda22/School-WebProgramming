#include <stdio.h> 

int main() 
{   // 변수 선언
	float average;
	float num, num1, num2;
	// 입력
	printf("input : ");
	scanf("%f%f", &num1, &num2);
	//연산
	num = num1 / num2;
	average = (int)(num * 1000) / 1000.0;
	//출력
	printf("%.3f\n", average);
	//종료
	return 0;
}