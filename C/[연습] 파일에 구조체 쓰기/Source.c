#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[20];
	int age;
} ADDR;

int main()
{
	FILE *fp;
	ADDR addr[3];

	fp = fopen("addr.bin", "w+b");

	strcpy(addr[0].name, "전성우");
	addr[0].age = 17;
	strcpy(addr[1].name, "황수경");
	addr[1].age = 17;
	strcpy(addr[2].name, "양덕호");
	addr[2].age = 17;
	
	fwrite(addr, sizeof(ADDR), 3, fp);

	fp = fopen("addr.bin", "rb");

	fread(&addr[1], sizeof(ADDR), 1, fp);
	fread(&addr[1], sizeof(ADDR), 1, fp);
	fread(&addr[1], sizeof(ADDR), 1, fp);

	for (size_t i = 0; i < 3; i++)
	{
		printf("%s : %d\n", "", 1);
	}

	fcloseall();
	return 0;
}