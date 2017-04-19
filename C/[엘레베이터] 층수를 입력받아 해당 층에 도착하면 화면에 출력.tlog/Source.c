#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

#define SLEEPTIME 1000

// ¼±»ý´Ô........
// ¾ÆÁ÷ ´Ù ¿Ï¼º ¸øÇß½À´Ï´Ù.....¤Ì¤Ð
// ÀÏ´Ü ÇÑ¹ø Å¸°í ³¡³ª°í¿ä... È¦ Â¦ ±¸ºÐÀÌ ¾ÈµÇ¿ä....
// ¼±»ý´Ô »ç¶ûÇØ¿ä....¢¾¢¾¢¾

void printFloor(int floor);
void leftBox(char str[]);

int main()
{
	int loop;
	int inputFloor, inputOddEven;
	int firstFloor = 1, firstOddEven, elevatorOddEven;
	char OddEven[5];

	printFloor(firstFloor);
	while (1){
		printf("¿¤¸®º£ÀÌÅÍ Á¾·ù ÀÔ·Â (È¦¼ö´Â 1, Â¦¼ö´Â 0): ");
		scanf("%s", OddEven); fflush(stdin);
		if (strcmp(OddEven, "È¦¼ö") == 0 || strcmp(OddEven, "1") == 0) { inputOddEven = 1;  break; }
		else if (strcmp(OddEven, "È¦¼ö") == 0 || strcmp(OddEven, "0") == 0) { inputOddEven = 0; break; }
		else leftBox("¿ÇÁö ¾ÊÀº ÀÔ·ÂÀÔ´Ï´Ù.");
	}
portal:	
	while (1){ 
		printf("°¥ Ãþ ÀÔ·Â : "); 
		scanf("%d", &inputFloor); fflush(stdin); 
		if (inputFloor >= -4  && inputFloor <= 16 && inputFloor != 0) break; //|| inputFloor == -3 || inputFloor == -2 || inputFloor == -1 || inputFloor == 1 || inputFloor == 2 || inputFloor == 3 || inputFloor == 4 || inputFloor == 5 || inputFloor == 6 || inputFloor == 7 || inputFloor == 8 || inputFloor == 9 || inputFloor == 10 || inputFloor == 11 || inputFloor == 12 || inputFloor == 13 || inputFloor == 14 || inputFloor == 15 ||
		else leftBox("¿ÇÁö ¾ÊÀº ÀÔ·ÂÀÔ´Ï´Ù.");
	}

	inputOddEven = abs(inputFloor) % 2; // 0ÀÌ¸é Â¦
	firstOddEven = abs(firstFloor) % 2; // 1ÀÌ¸é È¦

	if (inputOddEven == 0 && firstOddEven == 0) { elevatorOddEven = 0; printf("Â¦¼ö Ãþ ¿¤¸®º£ÀÌÅÍÀÔ´Ï´Ù.\n"); }
	else if (inputOddEven == 1 && firstOddEven == 1) { elevatorOddEven = 0; printf("È¦¼ö Ãþ ¿¤¸®º£ÀÌÅÍÀÔ´Ï´Ù.\n"); }
	else { leftBox("È¦Â¦ ±¸º°Á».... ¤´?"); goto portal; }

	loop = 0;
	if (firstFloor < inputFloor){
		for (int i = 0; i < inputFloor - firstFloor; i+=2){
			Sleep(SLEEPTIME); 
			if (firstFloor + loop + 2 == 0) { loop -= 2; i += 2; };
			printFloor(firstFloor + loop + 2);			
			loop += 2;
		}
	}
	else if (firstFloor > inputFloor){
		for (int i = 0; i < firstFloor - inputFloor; i+=2){
			Sleep(SLEEPTIME); 
			if (firstFloor + loop - 2 == 0) { loop -= 2; i += 2; };
			printFloor(firstFloor + loop - 2);
			loop -= 2;
		}
	}
	printf("µµÂøÇß½À´Ï´Ù!\n");
	return 0;
}

void printFloor(int floor)
{
	if (floor <= 0) printf("ÇöÀç Ãþ : B%dÃþ\n", abs(floor));
	else printf("ÇöÀç Ãþ : %dÃþ\n", floor);
}

void leftBox(char str[])
{
	int i, length, realen;

	realen = strlen(str);

	if (str[0] == 7)
		realen--;
	if (realen % 2 == 0)
		length = realen / 2;
	else
		length = (realen + 1) / 2;

	printf(" ¦£");
	for (i = 1; i <= length; i++)
		printf("¦¡");
	printf("¦¤");

	puts("");

	printf(" ¦¢");
	if (realen % 2 == 1)
		printf(" ");
	printf("%s", str);
	printf("¦¢");

	puts("");

	printf(" ¦¦");
	for (i = 1; i <= length; i++)
		printf("¦¡");
	printf("¦¥");

	puts("");
}