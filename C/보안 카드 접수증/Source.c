#include <stdio.h>
#include <Windows.h>

int main()
{
	char name[80], code;
	int age, i;
	float key;

	printf("이름과 나이, 부서코드, 보안키를 차례대로 입력하세요 : ");
	scanf("%s %d %c %f", &name, &age, &code, &key);
	
	system("CLS");
	printf("*********************************\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d\n", age);
	printf("부서코드 : %c\n", code);
	printf("보안키 : %.3f\n", key);
	printf("*********************************\n");
	
	return 0;
}