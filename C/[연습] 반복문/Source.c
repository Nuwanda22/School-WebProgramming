#include <stdio.h>

int main()
{
	char a[80] = "HELLO";
	int b = 0, i;

	while (b < 5){
		printf("%c", '\n');
		b++;
	}

	for (i = 0; i < 5; i++)
		printf("%10c ", a[i]);


	printf("\n");

	return 0;
}