#include <stdio.h>

void yut(int a, int b, int c, int d)
{
	switch (a + b + c + d)
	{
	case 1:
		puts("도");
		break;
	case 2:
		puts("개");
		break;
	case 3:
		puts("걸");
		break;
	case 4:
		puts("윷");
		break;
	case 0:
		puts("모");
		break;
	}
}

int main()
{
	int a, b, c, d;

	puts("4개의 윷의 상태를 입력하시오");
	puts("뒤집어지지 않은 상태 : 0 / 뒤집어진 상태 : 1");
	puts("예) 1 1 1 0\n");

	printf("input : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	yut(a, b, c, d);

	return 0;
}