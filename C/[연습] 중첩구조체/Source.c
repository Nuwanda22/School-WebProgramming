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

	printf("이름 : ");
	gets(a.name);

	printf("가격 : ");
	scanf("%d", &a.price);

	print(&a);

	return 0;
}

void print(coffee *a)
{
	puts(a->name);
	printf("%d\n", a->price);
}