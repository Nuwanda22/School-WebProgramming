#include <stdio.h>
#include <conio.h>

enum MyEnum
{
	number = '1', phone_number
};

typedef union MyUnion
{
	int num;
	char phone[20];
}password;

int main()
{
	char choice;
	password pw;
	
	puts("1. 비밀번호(숫자 4자리)");
	puts("2. 전화번호\n");
	puts("원하는 입력 방식을 입력하시오.\n");

	choice = getch();
	switch (choice)
	{
	case number:
		printf("비밀번호 입력 : ");
		scanf("%d", &pw.num);
		break;
	case phone_number:
		printf("전화번호 입력 : ");
		scanf("%s", pw.phone);
		break;
	default:
		printf("잘못 입력함\n");
		break;
	}

	switch (choice)
	{
	case number:
		printf("입력한 비밀번호는 : %d\n", pw.num);
		break;
	case phone_number:
		printf("입력한 전화번호는 : %s\n", pw.phone);
		break;
	default:
		printf("잘못 입력함\n");
		break;
	}
	return 0;
}