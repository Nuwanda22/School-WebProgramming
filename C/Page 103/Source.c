#include <stdio.h>

main()
{
	int num;
	do
	{
		scanf("%d", &num);
		if (num > 0)
			if (num % 2 == 1)
				puts("Ȧ��");
			else
				puts("¦��");
	} while (num > 0);
}