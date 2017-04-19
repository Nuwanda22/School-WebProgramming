#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main()
{
	char buff[100] = "[(«Ô∑Œ)] [(«œ¿Ã)] [(æ»≥Á)].";
	char *seps = "[]() .";
	char *token;
	char str[20] = "";

	token = strtok(buff, seps);
	while (token)
	{
		//puts(token);
		strcat(str, token);
		strcat(str, " ");
		token = strtok(NULL, seps);
	}
	puts(str);
	//puts(strrev("love"));
	//printf("%s", strrev("love"));
	printf("%d ", atoi("-256") + 256);
	return 0;
}