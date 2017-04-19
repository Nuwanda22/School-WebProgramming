#include <stdio.h>

main()
{
	int i, j;
	for (i = 1; i <= 9; i++){
		if (i == 1) puts(" 1단");
		else if (i == 2) puts(" 2단");
		else if (i == 3) puts(" 3단");
		else if (i == 4) puts(" 4단");
		else if (i == 5) puts(" 5단");
		else if (i == 6) puts(" 6단");
		else if (i == 7) puts(" 7단");
		else if (i == 8) puts(" 8단");
		else puts(" 9단");
		for ( j = 1; j <= 9; j++)
			printf(" %d X %d = %d\n", i, j, i*j);
		puts("");
	}
}