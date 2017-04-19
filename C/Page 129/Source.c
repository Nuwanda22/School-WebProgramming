#include <stdio.h>

int main()
{
	int i;
	char ch[22];

	printf("input : ");
	scanf("%s", ch);

	printf("output 1 : ");
	for (i = 0; ch[i] != '\0'; i++)
		printf("%c", ch[i] + 2);
	puts("");

	printf("output 2 : ");
	for (i = 0; ch[i] != '\0'; i++)
		printf("%c", ch[i] * 7 % 80 + 48);
	puts("");

	return 0;
}