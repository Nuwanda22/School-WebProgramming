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
	
	puts("1. ��й�ȣ(���� 4�ڸ�)");
	puts("2. ��ȭ��ȣ\n");
	puts("���ϴ� �Է� ����� �Է��Ͻÿ�.\n");

	choice = getch();
	switch (choice)
	{
	case number:
		printf("��й�ȣ �Է� : ");
		scanf("%d", &pw.num);
		break;
	case phone_number:
		printf("��ȭ��ȣ �Է� : ");
		scanf("%s", pw.phone);
		break;
	default:
		printf("�߸� �Է���\n");
		break;
	}

	switch (choice)
	{
	case number:
		printf("�Է��� ��й�ȣ�� : %d\n", pw.num);
		break;
	case phone_number:
		printf("�Է��� ��ȭ��ȣ�� : %s\n", pw.phone);
		break;
	default:
		printf("�߸� �Է���\n");
		break;
	}
	return 0;
}