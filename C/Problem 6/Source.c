#include <stdio.h>

main()
{
	int	i, j, chk;
	
	for (i = 2; i <= 100; i++){
		chk = 1;
		for (j = 2; j < i; j++){
			if (i % j == 0){
				chk = 0;
				break;
			}
		}
		if (chk == 1)
			printf("%d ", i);
	}
	puts("");
}