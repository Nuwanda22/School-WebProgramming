#include <stdio.h>

int a = 5, b = 6, c = 5, d = 1;
int x;

main()
{
	x = a < b || a < c && c < d;
	printf("°ıÈ£°¡ ¾øÀ»¶© %d\n", x);
	
	x = (a < b || a < c) && c < d;
	printf("°ıÈ£°¡ ÀÖÀ»¶© %d\n", x);
	return 0;
}