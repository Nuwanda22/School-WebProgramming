#include <stdio.h>
#include "header.h"

int main() 
{
	char str[100];
	scanf("%s", str);

	wprintf(L(str));
	return 0;
}