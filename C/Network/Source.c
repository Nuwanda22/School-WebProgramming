#include <stdio.h>
#include <winsock.h>

#pragma pack (1)

struct typeData{
	char length;
	int values[5];
};

int main()
{
	int ivar = 3;
	char *p = &ivar;

	printf("\n Size : %d\n", sizeof(struct typeData));

	printf("\n Before htonl : ");
	for (int i = 0; i < sizeof(int); i++)
		printf(" %x", *(p + i));

	ivar = htonl(ivar);
	
	printf("\n After htonl : ");
	for (int i = 0; i < sizeof(int); i++)
		printf(" %x", *(p + i));

	return 0;
}