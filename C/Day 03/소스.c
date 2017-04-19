#include <stdio.h>

int main() 
{
	int a;
	int b;

	scanf("%d %d", &a, &b);
	printf("%-10.2f", (float)a / b);
	return 0;
}