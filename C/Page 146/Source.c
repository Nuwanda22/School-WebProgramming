/*
#include <stdio.h>

int main()
{
	int year, input;

	printf("input : ");
	scanf("%d", &year);

	if (year % 4 == 0)
		puts("����");
	else
		puts("���");
}
*/

#include <stdio.h>

int year_check(int year)
{
	if (year % 4 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int year;
	
	printf("input : ");
	scanf("%d", &year);

	if (year_check(year) == 1)
		puts("����");
	else
		puts("���");
	
	return 0;
}