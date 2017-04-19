#include <stdio.h>
#include <Windows.h>

#define SLEEPTIME 1000

int main()
{
	puts("1. Print Hello World");
	puts("2. Print Hello World (1 sec)");
	puts("3. Print Hello World (1 sec, 10 times)");
	puts("\n(If you want to exit, press ctrl + c)");

	switch (getch())
	{
	case '1':
		while (1)
			puts("Hello World");
		
	case '2':
		while (1){
			puts("Hello World");
			Sleep(SLEEPTIME);
		}
	case '3':
		for (int i = 0; i < 10; i++){
			puts("Hello World");
			Sleep(SLEEPTIME);
		}
	default:
		break;
	}
}