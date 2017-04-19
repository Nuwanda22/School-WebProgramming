#include <stdio.h>

int main()
{
	int i;

	i = 1;
	while (i * 3 <= 100){
		printf("%d ", i * 3);
		i++;
	}
	puts("");
	for (i = 1; i * 3 <= 100; i++)
		printf("%d ", i * 3);
}