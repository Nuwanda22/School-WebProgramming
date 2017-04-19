#include <stdio.h>

main()
{
	int num;
	do
	{
		scanf("%d", &num);
		if (num > 0)
			if (num % 2 == 1)
				puts("È¦¼ö");
			else
				puts("Â¦¼ö");
	} while (num > 0);
}