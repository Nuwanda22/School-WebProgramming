#include <stdio.h>
#include <Windows.h>

int main()
{
	char name[80], code;
	int age, i;
	float key;

	printf("�̸��� ����, �μ��ڵ�, ����Ű�� ���ʴ�� �Է��ϼ��� : ");
	scanf("%s %d %c %f", &name, &age, &code, &key);
	
	system("CLS");
	printf("*********************************\n");
	printf("�̸� : %s\n", name);
	printf("���� : %d\n", age);
	printf("�μ��ڵ� : %c\n", code);
	printf("����Ű : %.3f\n", key);
	printf("*********************************\n");
	
	return 0;
}