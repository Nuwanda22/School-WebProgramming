#include <stdio.h>

main()
{
	int i, j, k;
	int l = 0;
	for (i = 1; i <= 4; i++){
		for (j = 3; j >= i; j--)
			printf(" ");
		for (k = 1; k <= (i + l); k++)
			printf("*");
		l++;
		puts("");
	}
	l = 4;
	for (i = 1; i <= 3; i++){
		for (j = 1; j <= i; j++)
			printf(" ");
		for (k = 1; k <= (i + l); k++)
			printf("*");
		l -= 3;
		puts("");
	}
}