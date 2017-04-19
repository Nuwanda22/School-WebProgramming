#include <stdio.h>

int main()
{
	char c1;
	char c2[80] = "네 다음 브론즈 ";
	int num;

	scanf_s("%c", &c1);

	if (c1 == '\n')
		num = 1;
	else
		num = 0;
		printf("엔터를 입력해주세요\n");
	while (num){
		printf("%s%s%s%s%s\n", c2, c2, c2, c2, c2);
	}

	return 0;
}