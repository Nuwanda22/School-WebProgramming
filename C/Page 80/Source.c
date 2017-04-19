#include <stdio.h>

main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("Ãâ·Â = %d", (++a << b) >> c);
}