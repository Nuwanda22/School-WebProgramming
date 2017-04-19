#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define W arr[me.x - 1][me.y] == 1
#define A arr[me.x][me.y - 1] == 1
#define S arr[me.x + 1][me.y] == 1
#define D arr[me.x][me.y + 1] == 1
#define SEX if (input == 'w'){arr[me.x - 1][me.y] = 2;arr[me.x][me.y] = 1;me.x--;}else if (input == 'a'){arr[me.x][me.y - 1] = 2;arr[me.x][me.y] = 1;me.y--;}else if (input == 's'){arr[me.x + 1][me.y] = 2;arr[me.x][me.y] = 1;me.x++;}else if (input == 'd'){arr[me.x][me.y + 1] = 2;arr[me.x][me.y] = 1;me.y++;}

typedef struct where
{
	int x;
	int y;
}WHERE;

int main()
{
	int p, q;
	int arr[WIDTH][HEIGHT];
	WHERE me;
	srand((unsigned)time(NULL));

	for (p = 0; p < WIDTH; p++)
		for (q = 0; q < HEIGHT; q++) arr[p][q] = rand() % 2;
	
	me.x = 0, me.y = 0;
	int k = 0;
	char input;

	arr[0][0] = 2;
	arr[WIDTH - 1][HEIGHT - 1] = 1;

	while (1)
	{
		
		system("cls");
		printf("이동횟수 : %d\n", k++);
		printf("현재 위치는 [%d][%d]입니다\n", me.x, me.y);
		printf("도착점은 [%d][%d]입니다\n", WIDTH - 1, HEIGHT - 1);
		for (p = 0; p < WIDTH; p++){
			for (q = 0; q < HEIGHT; q++){
				if (arr[p][q] == 0) printf("□");
				else if (arr[p][q] == 1) printf("■");
				else if (arr[p][q] == 2) printf("●");
			}
			puts("");
		}
		if (me.x == (WIDTH - 1) && me.y == (HEIGHT - 1)) break;
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
}
/*
#define A arr[i - 1] == 1
#define D arr[i + 1] == 1

int main()
{
	int arr[5] = { 1, 1, 1, 0, 0 };
	int p, i = 0;
	char input;

	arr[0] = 2;

	while (1)
	{
		system("cls");
		for (p = 0; p < 5; p++){
			if (arr[p] == 0) printf("□");
			else if (arr[p] == 1) printf("■");
			else if (arr[p] == 2) printf("●");
		}
		if (i == 2) break;
		
		input = getch();
		if (A && D){
			while (1){ input = getch(); if (input == 'a' || input == 'd') break; }
			if (input == 'a') { arr[i] = 1; arr[i - 1] = 2;  i--; }
			else { arr[i] = 1; arr[i + 1] = 2; i++; }
		}
		else if (A){
			while (1){ input = getch(); if (input == 'a') break; }
			arr[i] = 1;
			arr[i - 1] = 2;
			i--;
		}
		else if (D){
			while (1){ input = getch(); if (input == 'd') break; }
			arr[i] = 1;
			arr[i + 1] = 2;
			i++;
		}
	}
	puts("미로탈출!");
	return 0;
}*/