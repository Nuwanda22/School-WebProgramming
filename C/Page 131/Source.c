#include <stdio.h>
#include <string.h>

int main()
{
	int i, j = 0;
	char reverse[100];

	printf("input : ");
	gets(reverse);
	
	printf("output : ");
	for (i = 0; i < strlen(reverse); i++){
		printf("%c", reverse[strlen(reverse) - 1 + j]);
		j--;
	}
	puts("");
}