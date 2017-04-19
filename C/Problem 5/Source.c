#include <stdio.h>

main()
{
	int i, j;

	for (i = 1; i <= 10; i++){
		printf("%dÀÇ ¾à¼ö : ", i);
		for (j = 1; j <= i; j++){
			if (i % j == 0)
				printf("%d ", j);
		}
		puts("");
	}
}