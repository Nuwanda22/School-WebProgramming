#include <stdio.h>

main()
{
	int i, j;
	for (i = 1; i <= 9; i++){
		if (i == 1) puts(" 1��");
		else if (i == 2) puts(" 2��");
		else if (i == 3) puts(" 3��");
		else if (i == 4) puts(" 4��");
		else if (i == 5) puts(" 5��");
		else if (i == 6) puts(" 6��");
		else if (i == 7) puts(" 7��");
		else if (i == 8) puts(" 8��");
		else puts(" 9��");
		for ( j = 1; j <= 9; j++)
			printf(" %d X %d = %d\n", i, j, i*j);
		puts("");
	}
}