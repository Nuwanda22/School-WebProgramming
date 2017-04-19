#include <stdio.h>

typedef union {
	unsigned char c;
	unsigned int i;
	unsigned char sa[10];
} UN;

typedef union {
	unsigned char c;
	unsigned int i;
	unsigned char sa[10];
} __attribute__((packed)) PACKED_UN;

#define BYTE unsigned char

void printMem(char *title, char *p,  int len)
{
	int i;
	printf("\n %s : ", title);
	for(i = 0; i < len; i++)
		printf(" %2x", (unsigned char)p[i]);
	printf("\n\n");
}

int main()
{
	UN varUnion;
	PACKED_UN varPUnion;

	printf("\n sizeof BYTE = %d\n", sizeof(BYTE));
	printf("\n sizeof varUnion = %d\n", sizeof(UN));
	printf("\n sizeof varPUnion = %d\n", sizeof(PACKED_UN));

	memset(varUnion.sa, 0x00, sizeof(varUnion));
	printMem("after memset 0x00", varUnion.sa, sizeof(varUnion));

	varUnion.c = 0xAA;
	printMem("after c = 0xAA", varUnion.sa, sizeof(varUnion));

	varUnion.i = 0x30;
	printMem("after i = 0x30", varUnion.sa, sizeof(varUnion));

	memset(varUnion.sa, 0x55, sizeof(varUnion));
	printMem("after memset 0x55", varUnion.sa, sizeof(varUnion));

	return 0;
}
