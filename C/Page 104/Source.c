#include <stdio.h>

main()
{
	int i, sum = 0;
	for ( i = 1; i <= 100; i++)
	{
		printf("%d ", i);
		sum += 1;
	}
	printf("\n1~100������ ���� %d�Դϴ�.\n", sum);
}