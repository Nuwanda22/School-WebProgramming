#include <stdio.h>

void yut(int a, int b, int c, int d)
{
	switch (a + b + c + d)
	{
	case 1:
		puts("��");
		break;
	case 2:
		puts("��");
		break;
	case 3:
		puts("��");
		break;
	case 4:
		puts("��");
		break;
	case 0:
		puts("��");
		break;
	}
}

int main()
{
	int a, b, c, d;

	puts("4���� ���� ���¸� �Է��Ͻÿ�");
	puts("���������� ���� ���� : 0 / �������� ���� : 1");
	puts("��) 1 1 1 0\n");

	printf("input : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	yut(a, b, c, d);

	return 0;
}