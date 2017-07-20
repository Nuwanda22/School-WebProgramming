#include <stdio.h>

extern void print(char *str);
extern char *input();

int main()
{
	char *str = input();
	print(str);
	print("\n");
	return 0;
}
