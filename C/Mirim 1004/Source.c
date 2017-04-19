#include <stdio.h>

int main()
{
	int num;
	char name[20];

	printf("효진이의 학번: ");
	scanf("%d", &num);
	fflush(stdin);

	printf("미림이의 닉네임: ");
	fgets(name, sizeof(name), stdin);

	puts("");

	printf("효진이의 학번 : %d\n", num);
	printf("미림이의 닉네임 : %s\n", name);

	return 0;
}