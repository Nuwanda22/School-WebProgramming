#include <stdio.h>

int main()
{
	char str[5] = "Love";
	char *ptStr = "Love";

	printf("%s\n", str);
	printf("%s\n", ptStr);

	str[0] = 'R';

	printf("%s\n", str);
	printf("%s\n", ptStr);
}