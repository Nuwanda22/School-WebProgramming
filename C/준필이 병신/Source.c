#include <stdio.h>

int main()
{
	char c1;
	char c2[80] = "�� ���� ����� ";
	int num;

	scanf_s("%c", &c1);

	if (c1 == '\n')
		num = 1;
	else
		num = 0;
		printf("���͸� �Է����ּ���\n");
	while (num){
		printf("%s%s%s%s%s\n", c2, c2, c2, c2, c2);
	}

	return 0;
}