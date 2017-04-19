#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//#define COL        GetStdHandle(STD_OUTPUT_HANDLE)
//#define BLACK      SetConsoleTextAttribute(COL, 0x0000);
//#define DARK_BLUE  SetConsoleTextAttribute(COL, 0x0001);
//#define GREEN      SetConsoleTextAttribute(COL, 0x0002);
//#define BLUE_GREEN SetConsoleTextAttribute(COL, 0x0003);
//#define BLOOD      SetConsoleTextAttribute(COL, 0x0004);
//#define PURPLE     SetConsoleTextAttribute(COL, 0x0005);
//#define GOLD       SetConsoleTextAttribute(COL, 0x0006);
//#define ORIGINAL   SetConsoleTextAttribute(COL, 0x0007);
//#define GRAY       SetConsoleTextAttribute(COL, 0x0008);
//#define BLUE       SetConsoleTextAttribute(COL, 0x0009);
//#define HIGH_GREEN SetConsoleTextAttribute(COL, 0x000a);
//#define SKY_BLUE   SetConsoleTextAttribute(COL, 0x000b);
//#define RED        SetConsoleTextAttribute(COL, 0x000c);
//#define PLUM       SetConsoleTextAttribute(COL, 0x000d);
//#define YELLOW     SetConsoleTextAttribute(COL, 0x000e);
//
////커서감추는함수 
//typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
//void setcursortype(CURSOR_TYPE c)
//{
//	CONSOLE_CURSOR_INFO CurInfo;
//	switch (c) {
//	case NOCURSOR:
//		CurInfo.dwSize = 1;
//		CurInfo.bVisible = FALSE;
//		break;
//	case SOLIDCURSOR:
//		CurInfo.dwSize = 100;
//		CurInfo.bVisible = TRUE;
//		break;
//	case NORMALCURSOR:
//		CurInfo.dwSize = 20;
//		CurInfo.bVisible = TRUE;
//		break;
//	}
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
//}
//
//color(int i)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
//}



int main(){
	FILE *a = fopen("C:\\Users\\전성우\\Desktop\\Images\\Original.bmp", "wb");
	FILE *b = fopen("C:\\Users\\전성우\\Desktop\\Images\\OriginalWithKey.bmp", "wb");
}

/*
int main(void)  
{     
	int i, fa = 1;
	unsigned long long int input;     

	printf("Input Number: ");     
	scanf("%llu", &input); // 사용자로부터 값을 입력 받음    

	for (i = 1; i <= input; i++) // 팩토리얼 계산 및 출력     
	{
		fa = fa * i;
		printf("%d!=%d\n", i, fa);
	}
	return 0;  
} */

/*
int main()
{
	char Name[80]  = "DJ SW";
	int  Phone[80] = {010, 4842, 9365};
	char Job[80]   = "Computer Programer";
	char Email[80] = "Ko997ko@naver.com";
	char Link[80]  = "blog.naver.com/ko997ko";

	char enter;
	billy();
	enter = getch();
	printf("%d", enter);
}
*/

/*
#include <stdio.h>

int main()
{
	int i = 1;
	int input;
	printf("input : ");
	scanf("%d", &input);
	while (input * i <= 1000){
		printf("%d ", input * i);
		i++;
	}
}
*/

/*
#include <stdio.h>

void trot(int trots[], int n);

void main()
{
	int aa[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int size = sizeof(aa) / sizeof(*aa); // 전체크기 / 원소크기 = 원소개수

	printf("size of %d\n", size);
	trot(aa, size);
}

void trot(int trots[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d\n", trots[i]);
}
*/

//void say(char str[])
//{
//	int i = 0;
//
//	puts(" 　　　　　　　　　　　 　 　 　 　 　 　 _,,t------､,-----+-､");
//	puts("　　　　　　　　　　　　 　 　 　 　 三'::.............. .....::::::`ｙ,.");
//	puts("　　　　　　　　 　 　 　 　 　 　 ナ::::::::::::::::::::::::: ::::::::::::ヾ");
//	puts("　　　　　　　 　 　 　 |￣|　　 V:::::::::::::_{{ （{∫∬ﾉノｊヾ:::::{");
//	puts("　　　　　　 　 　　|￣| |￣| 　 ﾅ:::::::::::i`__,,,,,,ｧ_　 _,,,,,_ t;;:ﾇ");
//	puts("　　 　 　　　　　　| 　| |　 |　 イﾍ:::::(ヾ~!,ｬt､　!'''i ｨｔﾝ )=f }ｆ");
//	puts(" 　　　　　　 　 　　| 　| | 　| 　 i {t) テ\" ﾍ' '___, ｲ 　ヽ_＿ / 介'");
//	puts("　　　　　　　　 　 | 　| |　 |　_,rﾍ_,ｊ|!' 　 　 /ｰ---''! 　　　|'");
//	puts("　　　　　　　　 　 |,.ｨ―''''￣　　／| |　 　 　 ／二二ｸ　 　　 !");
//	puts("　　　　　　 　 　 /;;:::'';;::''::;;:／ {　!　、　 　 ヾニﾝ　　 　ﾉ＼");
//	puts(" 　 　　　 　　 　 /''':::;r|'''::;;;|　　|　!　＼　　　　　 _,,.／|:;;''＼");
//	puts(" 　　　　　　 　 /:;;／　|;;;''::;;| 　　丶＼ 　｀_＿＞-ｰ´　 　　!;;;:''::iヽ、");
//	puts(" 　　　 　 　 　 i／　　 |'::;;;;''|　　 　 　三 ―''\"　　　 　　　!''::;;;; |/");
//	puts("　　　　　　　 /⌒ヽ　 |;;''':::;|　　　　　　　＼　 　 　 　 　 !;;::''|/　 i");
//	puts("　 　 　 　 / 　 　 ＼{'';;;::''}　　　　　　　　　￣二ニ＝　 　 !::;;|　　 |");
//	puts("　　　 　 　 /ﾍ　　　　 |;;:::::;{　　　　　　　　　　　　‐-　　　 　 !/　 　|");
//	puts("　 　 　 　 /　　i　　 　 |:::;;;''!　　　　　　　　　　 　 ー　　 　 　 !　 /");
//	puts("　　　　　/　　　l　　 　 |;;'';ｲ　　　　　　　　　　　　　　　　　｝　　 {、");
//
//	puts("-------------------------------------------------------------------------------");
//	
//	printf(" <준필> \n\n ");
//	while (str[i] != '\0'){
//		if (str[i] < 0){
//			Sleep(150);
//			printf("%c%c", str[i], str[i + 1]);
//			i += 2;
//		}
//		else{
//			Sleep(150);
//			printf("%c", str[i]);
//			i++;
//		}
//	}
//	puts("");
//}
//
//// 페메 왼쪽 박스
//void Left_Box(char str[])
//{
//	int i, length, realen;
//
//	realen = strlen(str);
//
//	if (str[0] == 7)
//		realen--;
//	if (realen % 2 == 0)
//		length = realen / 2;
//	else
//		length = (realen + 1) / 2;
//
//	printf(" ┌");
//	for (i = 1; i <= length; i++)
//		printf("─");
//	printf("┐");
//
//	puts("");
//
//	printf(" │");
//	if (realen % 2 == 1)
//		printf(" ");
//	printf("%s", str);
//	printf("│");
//
//	puts("");
//
//	printf(" └");
//	for (i = 1; i <= length; i++)
//		printf("─");
//	printf("┘");
//
//	puts("");
//}
//
//// 페메 오른쪽 박스
//void Right_Box(char str[])
//{
//	int i, length, length2, realen;
//
//	realen = strlen(str);
//
//	if (str[0] == 7)
//		realen--;
//
//	if (realen % 2 == 0){
//		length = realen / 2;
//		length2 = 75 - realen;
//	}
//	else{
//		length = (realen + 1) / 2;
//		length2 = 74 - realen;
//	}
//	for (i = 1; i <= length2; i++)
//		printf(" ");
//	printf("┌");
//	for (i = 1; i <= length; i++)
//		printf("─");
//	printf("┐");
//
//	puts("");
//
//	for (i = 1; i <= length2; i++)
//		printf(" ");
//	printf("│");
//	if (realen % 2 == 1)
//		printf(" ");
//	printf("%s", str);
//	printf("│");
//
//	puts("");
//
//	for (i = 1; i <= length2; i++)
//		printf(" ");
//	printf("└");
//	for (i = 1; i <= length; i++)
//		printf("─");
//	printf("┘");
//
//	puts("");
//}

/*
int main()
{
		int random, i, loop;
	int hello, hi;
	int hello_sum = 0, hi_sum = 0;

	srand((unsigned)time(NULL));
	while (1){
		system("cls");
		hello_sum = 0, hi_sum = 0;
		for (loop = 0; loop < 100; loop++)
		{
			hello = 0, hi = 0;
			for (i = 1; i <= 100; i++){
				if (rand() % 10  + 1 > 1){
					//printf("hello\n");
					hello++;
				}
				else{
					//printf("hi\n");
					hi++;
				}
			}
			//printf("hello : %d hi : %d\n", hello, hi);
			hello_sum += hello;
			hi_sum += hi;
			//getchar();
		}
		printf("hello avg : %.1f hi avg : %.1f\n", (float)hello_sum / loop, (float)hi_sum / loop);
		getch();
	}
}
*/

//char *itos(int in)
//{
//	int i = 0;
//	char tmp[11];
//	if (in > 0){
//		for (i = 0; in; i++){
//			tmp[i] = (in % 10) + '0';
//			in /= 10;
//		}
//		tmp[i--] = '\0';
//		while (i >= 0)
//		{
//			putchar(tmp[i]);
//			i--;
//		}
//	}
//	else if (in == 0){
//		return "0";
//	}
//	else {
//		
//	}
//}
//
//int main()
//{
//	//int in; scanf("%d", &in);
//	//int i = 0;
//	//char tmp[11];
//	//
//	//while (in) //ASCII to integer
//	//{
//	//	tmp[i] = (in % 10) + '0';
//	//	in /= 10;
//	//	i++;
//	//}
//	//tmp[i--] = '\0'; //마지막 배열을 가리키도록 인덱스 값의 1을 빼줌
//	//puts(tmp);
//	puts(itos(0));
//	/*while (i >= 0)
//	{
//		putchar(tmp[i]);
//		i--;
//	}*/
//}
/*
#define WIDTH 10
#define HEIGHT 10
#define W arr[i - 1][j] = 1
#define A arr[i][j - 1] = 1
#define S arr[i + 1][j] = 1
#define D arr[i][j + 1] = 1
int main()
{
	
	int i, j, arr[WIDTH][HEIGHT], random;;
	srand((unsigned)time(NULL));

	for (i = 0; i < WIDTH; i++)
		for (j = 0; j < HEIGHT; j++)
			arr[i][j] = rand() % 2;

	arr[0][0] = 1;
	arr[WIDTH - 1][HEIGHT - 1] = 1;

	for (i = 0; i < WIDTH; i++){
		for (j = 0; j < HEIGHT; j++){
			if (arr[i][j] == 1){
				if (arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1] < 2){
					random = rand() % 6 + 1;
					if (random == 1){ W; A; }
					else if (random == 2){ arr[i - 1][j] = 1; arr[i + 1][j] = 1; }
					else if (random == 3){ arr[i - 1][j] = 1; arr[i][j + 1] = 1; }
					else if (random == 4){ arr[i][j - 1] = 1; arr[i + 1][j] = 1; }
					else if (random == 5){ arr[i][j - 1] = 1; arr[i][j + 1] = 1; }
					else if (random == 6){ arr[i + 1][j] = 1; arr[i][j + 1] = 1; }
				}
			}
		}
	}
	for (i = 0; i < WIDTH; i++){
		for (j = 0; j < HEIGHT; j++) printf("%d ", arr[i][j]);
		puts("");
	}

	return 0;
}*/
/*
#define W arr[i - 1][j] == 1
#define A arr[i][j - 1] == 1
#define S arr[i + 1][j] == 1
#define D arr[i][j + 1] == 1
#define SEX if (input == 'w'){arr[i - 1][j] = 2;arr[i][j] = 1;i--;}else if (input == 'a'){	arr[i][j - 1] = 2;	arr[i][j] = 1;	j--;}else if (input == 's'){	arr[i + 1][j] = 2;arr[i][j] = 1;i++;}else if (input == 'd'){arr[i][j + 1] = 2;arr[i][j] = 1;j++;}

int main()
{
	int arr[5][5] = { { 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 1, 1 } };

	int p, q;
	int i = 0, j = 0, k = 0;
	char input;

	arr[0][0] = 2;

	while (1)
	{

		system("cls");
		printf("이동횟수 : %d\n", k++);
		puts("도착점은 [4][4]입니다");
		for (p = 0; p < 5; p++){
			for (q = 0; q < 5; q++){
				if (arr[p][q] == 0) printf("□");
				else if (arr[p][q] == 1) printf("■");
				else if (arr[p][q] == 2) printf("●");
			}
			puts("");
		}
		if (i == 4 && j == 4) break;
		input = getch();
		if (W && A && S && D){
			while (1){ input = getch(); if (input == 'w' || input == 'a' || input == 's' || input == 'd') break; }
			SEX
		}
		else if (W&&A&&S){
			while (1){ input = getch(); if (input == 'w' || input == 'a' || input == 's') break; }
			SEX
		}
		else if (W&&S&&D){
			while (1){ input = getch(); if (input == 'w' || input == 's' || input == 'd') break; }
			SEX
		}
		else if (W&&A&&D){
			while (1){ input = getch(); if (input == 'w' || input == 'a' || input == 'd') break; }
			SEX
		}
		else if (A&&S&&D){
			while (1){ input = getch(); if (input == 'a' || input == 's' || input == 'd') break; }
			SEX
		}
		else if (W&&A){
			while (1){ input = getch(); if (input == 'w' || input == 'a') break; }
			SEX
		}
		else if (W&&S){
			while (1){ input = getch(); if (input == 'w' || input == 's') break; }
			SEX
		}
		else if (W&&D){
			while (1){ input = getch(); if (input == 'w' || input == 'd') break; }
			SEX
		}
		else if (A&&S){
			while (1){ input = getch(); if (input == 'a' || input == 's') break; }
			SEX
		}
		else if (A&&D){
			while (1){ input = getch(); if (input == 'a' || input == 'd') break; }
			SEX
		}
		else if (S&&D){
			while (1){ input = getch(); if (input == 's' || input == 'd') break; }
			SEX
		}
		else if (W){
			while (1){ input = getch(); if (input == 'w') break; }
			SEX
		}
		else if (A){
			while (1){ input = getch(); if (input == 'a') break; }
			SEX
		}
		else if (S){
			while (1){ input = getch(); if (input == 's') break; }
			SEX
		}
		else if (D){
			while (1){ input = getch(); if (input == 'd') break; }
			SEX
		}
	}

	puts("미로탈출!");
	return 0;
}*/