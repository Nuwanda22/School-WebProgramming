#include <stdio.h>
#include <string.h>

typedef struct{
	char name[20];
	int price;
}coffee;

void print(coffee *a);

int main()
{
	coffee a;

	printf("�̸� : ");
	gets(a.name);

	printf("���� : ");
	scanf("%d", &a.price);

	print(&a);

	return 0;
}

void print(coffee *a)
{
	puts(a->name);
	printf("%d\n", a->price);
}