#include <stdio.h>

int main()
{
	int num;
	char name[20];

	printf("ȿ������ �й�: ");
	scanf("%d", &num);
	fflush(stdin);

	printf("�̸����� �г���: ");
	fgets(name, sizeof(name), stdin);

	puts("");

	printf("ȿ������ �й� : %d\n", num);
	printf("�̸����� �г��� : %s\n", name);

	return 0;
}