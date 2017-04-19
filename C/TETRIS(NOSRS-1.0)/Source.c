#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//설명
//빈공간(0) 벽(1) I(2) T(3) O(4) L(5) J(6) S(7) Z(8) 
//변수
int matrix[26][12]={
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};
int w, x, y, z, p, q, r, s;//블록 위치 
int a, b, c, d; //고스트 위치 

double score; //점수
int harddrop; //하드드롭시 점수 
int level; //레벨
double blocknum; //총 블록 갯수 
double linesclrd; //총 지운 줄 갯수 

int rotation; //블록 회전 

int keyboard; //키보드 입력 

int next1, next2, next3, now; //넥스트창 

double times; //블록당 시간경과 
double totimes; //총 시간경과
double blocktouch; //블럭이 바닥에 닿은 경우 시간 경과시 하드드롭 
int floorkick; //플로어킥은 세번까지만 허용할 것임 

double whenTSpin; //티스핀 글자지우기용
double IsTspin, Turns, TTurns, moves; //T스핀 여부 
int useskick; //T-스핀시 Kick을 사용 하느냐의 여부 

int delay; //블록 내려오는 속도 

int holding; //처음에 홀드되어 있는 것 : 없음 
int justhold;
double firsthold;

int blocktype; //블록모양(색깔) 
int row, height; //매트릭스 그릴 때 사용
int clrdheight; //줄 지워질 때 사용 
int repeatclr; //한번에 네줄까지 지워지게
int howmanyclr; //한번에 몇줄 지워지나? 
double whenclr; //언제 지워졌나? 

int BTB; //백투백
int combo; //컴보 

int GOx, GOy; //게임오버시 이펙트 좌표 
int GOkey; //게임오버시 입력 받는곳 
int restart; //0일시 일반적인, 1일시 재시작
int resX, resY; //재시작시 매트릭스 초기화 

int pfcX, pfcY; //퍼펙트클리어 X,Y좌표 

int whethercolor;
int whatcolor;


 
//커서감추는함수 
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c)
{
     CONSOLE_CURSOR_INFO CurInfo;
     switch (c) {
     case NOCURSOR:
          CurInfo.dwSize=1;
          CurInfo.bVisible=FALSE;
          break;
     case SOLIDCURSOR:
          CurInfo.dwSize=100;
          CurInfo.bVisible=TRUE;
          break;
     case NORMALCURSOR:
          CurInfo.dwSize=20;
          CurInfo.bVisible=TRUE;
          break;
     }
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);}
     
//커서이동함수 
void gotoxy(int x, int y)
{
     COORD Cur;
     Cur.X=x;
     Cur.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

//그리는 함수 
void draw(void)
{
	if(whatcolor==1 && blocktype==2)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b);
	else if(whatcolor==1 && blocktype==3)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d);
	else if(whatcolor==1 && blocktype==4)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e);
	else if(whatcolor==1 && blocktype==5)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04);
	else if(whatcolor==1 && blocktype==6)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09);
	else if(whatcolor==1 && blocktype==7)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a);
	else if(whatcolor==1 && blocktype==8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c);
	else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);}

	gotoxy(2*w+10,p-3);
	if(p-3>0)printf("▣");
	gotoxy(2*x+10,q-3);
	if(q-3>0)printf("▣");
	gotoxy(2*y+10,r-3);
	if(r-3>0)printf("▣");
	gotoxy(2*z+10,s-3);
	if(s-3>0)printf("▣");
}

//바닥에 놓는 함수 
void putdraw(void)
{
	matrix[p][w]=blocktype; 
	matrix[q][x]=blocktype; 
	matrix[r][y]=blocktype; 
	matrix[s][z]=blocktype;
}
 
//지우는 함수 
void erase(void)
{
	gotoxy(2*w+10,p-3);
	if(p-3>0)printf(" ");
	gotoxy(2*x+10,q-3);
	if(q-3>0)printf(" ");
	gotoxy(2*y+10,r-3);
	if(r-3>0)printf(" ");
	gotoxy(2*z+10,s-3);
	if(s-3>0)printf(" ");
}
 
//고스트 함수
void ghost(void)
{
	a=p; b=q; c=r; d=s;
	while(1){
		if(matrix[a+1][w]!=0 || matrix[b+1][x]!=0 || matrix[c+1][y]!=0 || matrix[d+1][z]!=0) 
			break;
			a++; b++; c++; d++;
	}
	if(whatcolor==1 && blocktype==2)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b);
	else if(whatcolor==1 && blocktype==3)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d);
	else if(whatcolor==1 && blocktype==4)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e);
	else if(whatcolor==1 && blocktype==5)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04);
	else if(whatcolor==1 && blocktype==6)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09);
	else if(whatcolor==1 && blocktype==7)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a);
	else if(whatcolor==1 && blocktype==8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c);
	else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);}
	gotoxy(2*w+10,a-3);
	if(a-4>0)printf("□");
	gotoxy(2*x+10,b-3);
	if(b-4>0)printf("□");
	gotoxy(2*y+10,c-3);
	if(c-4>0)printf("□");
	gotoxy(2*z+10,d-3);
	if(d-4>0)printf("□");
}
 
//고스트 지우기함수
void eraseghost(void)
{
	gotoxy(2*w+10,a-3);
	if(a-4>0)printf(" ");
	gotoxy(2*x+10,b-3);
	if(b-4>0)printf(" ");
	gotoxy(2*y+10,c-3);
	if(c-4>0)printf(" ");
	gotoxy(2*z+10,d-3);
	if(d-4>0)printf(" ");
}

//함수원형선언
void Ttet(void);
void Otet(void);
void Itet(void);
void Ltet(void);
void Jtet(void);
void Stet(void);
void Ztet(void);
void gameover(void);

//홀드 함수 
void hold(void)
{
 if(holding==0){holding=now; justhold=1; firsthold=blocknum; if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                             else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                             else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                             else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                             else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                             else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                             else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");}}
 else if(holding==2){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");} Itet();}
 else if(holding==3){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");} Ttet();}
 else if(holding==4){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");} Otet();}
 else if(holding==5){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");} Ltet();}
 else if(holding==6){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");} Jtet();}
 else if(holding==7){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");} Stet();}
 else if(holding==8){holding=now; justhold=1; gotoxy(1,2); printf("          "); gotoxy(1,3); printf("          "); if(holding==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(2,3); printf("■■■■");}
                                                                                                                    else if(holding==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==4){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(4,2); printf("■■"); gotoxy(4,3); printf("■■");}
                                                                                                                    else if(holding==5){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(7,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==6){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■"); gotoxy(3,3); printf("■■■");}
                                                                                                                    else if(holding==7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(5,2); printf("■■"); gotoxy(3,3); printf("■■");}
                                                                                                                    else if(holding==8){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(3,2); printf("■■"); gotoxy(5,3); printf("■■");} Ztet();}
}

int main(void)
{   //커서감춤 & 창크기고정 
	setcursortype(NOCURSOR);
	system("mode con:lines=23");
	
	//타이틀 스크린 
	int titleloop=0;
	gotoxy(6,3);
	printf("■■■■■");
	while(titleloop<6){
		gotoxy(10,titleloop+4);
		printf("■");
		titleloop++;
	}
	titleloop=0;
	gotoxy(18,3);
	printf("■■■■■");
	gotoxy(20,6);
	printf("■■■");
	gotoxy(20,9);
	printf("■■■■");
	while(titleloop<6){
		gotoxy(18,titleloop+4);
		printf("■");
		titleloop++;
	}
	titleloop=0;
	gotoxy(30,3);
	printf("■■■■■");
	while(titleloop<6){
		gotoxy(34,titleloop+4);
		printf("■");
		titleloop++;
	}
	titleloop=0;
	gotoxy(42,3);
	printf("■■■■");
	while(titleloop<6){
		gotoxy(42,titleloop+4);
		printf("■");
		titleloop++;
	}
	gotoxy(50,4);
	printf("■");
	gotoxy(50,5);
	printf("■");
	gotoxy(44,6);
	printf("■■■");
	gotoxy(46,7);
	printf("■");
	gotoxy(48,8);
	printf("■");
	gotoxy(50,9);
	printf("■");
	titleloop=0;
	while(titleloop<7){
		gotoxy(54,titleloop+3);
		printf("■");
		titleloop++;
	}
	titleloop=0;
	gotoxy(60,3);
	printf("■■■■");
	gotoxy(58,4);
	printf("■");
	gotoxy(58,5);
	printf("■");
	gotoxy(60,6);
	printf("■■■");
	gotoxy(66,7);
	printf("■");
	gotoxy(66,8);
	printf("■");
	gotoxy(58,9);
	printf("■■■■");
	gotoxy(6,2);
	printf("cih0921's");
	gotoxy(23,10);
	printf("http://blog.naver.com/cih0921");
	gotoxy(30,11);
	printf("VER. NOSRS-1.0");

	while(!kbhit()){
		gotoxy(6,3);
		printf("  ■■■  ");
		gotoxy(24,5);
		printf("■");
		gotoxy(24,6);
		printf("  ");
		gotoxy(34,5);
		printf(" ■");
		gotoxy(34,6);
		printf(" ■");
		gotoxy(34,7);
		printf(" ■");
		gotoxy(50,9);
		printf(" ");
		gotoxy(50,8);
		printf("■");
		gotoxy(54,6);
		printf(" ■");
		gotoxy(58,4);
		printf(" ■");
		gotoxy(58,5);
		printf(" ■");
		gotoxy(65,7);
		printf("■");
		gotoxy(65,8);
		printf("■");
    
		gotoxy(30,15);
		printf("press any key!");
		Sleep(500);
		gotoxy(6,3);
		printf("    ■    ");
		gotoxy(24,5);
		printf("  ");
		gotoxy(24,6);
		printf("■");
		printf("  ");
		gotoxy(34,5);
		printf(" ■");
		gotoxy(34,6);
		printf("  ■");
		gotoxy(34,7);
		printf(" ■");
		gotoxy(50,9);
		printf("■");
		gotoxy(50,8);
		printf(" ");
		gotoxy(54,6);
		printf("■");
		gotoxy(58,4);
		printf("■");
		gotoxy(58,5);
		printf("■");
		gotoxy(66,7);
		printf("■");
		gotoxy(66,8);
		printf("■");
  
		gotoxy(30,15);
		printf("press any key!");
		Sleep(500);
		gotoxy(6,3);
		printf("  ■■■  ");
		gotoxy(24,6);
		printf("  ");
		gotoxy(24,7);
		printf("■");
		printf("  ");
		gotoxy(34,5);
		printf(" ■");
		gotoxy(34,6);
		printf(" ■");
		gotoxy(34,7);
		printf(" ■");
		gotoxy(48,9);
		printf("■");
		gotoxy(50,9);
		printf(" ");
		gotoxy(53,6);
		printf("■");
		gotoxy(58,4);
		printf(" ■");
		gotoxy(58,5);
		printf(" ■");
		gotoxy(65,7);
		printf("■");
		gotoxy(65,8);
		printf("■");
  
		gotoxy(30,15);
		printf("              ");
		Sleep(500);
		gotoxy(6,3);
		printf("■■■■■");
		gotoxy(24,6);
		printf("■");
		gotoxy(24,7);
		printf("  ");
		printf("  ");
		gotoxy(34,5);
		printf("■");
		gotoxy(34,6);
		printf("■");
		gotoxy(34,7);
		printf("■");
		gotoxy(50,9);
		printf("■");
		gotoxy(48,9);
		printf(" ");
		gotoxy(54,6);
		printf("■");
		gotoxy(58,4);
		printf("■");
		gotoxy(58,5);
		printf("■");
		gotoxy(66,7);
		printf("■");
		gotoxy(66,8);
		printf("■");
  
  
		gotoxy(30,15);
		printf("              ");
		Sleep(500);
	}
	getch();
  
	//흑백 / 컬러 
	system("cls");
	gotoxy(10,4);
	printf("흑백(B)/색깔(C)?");
	while(1){
		whethercolor=getch();
		if(whethercolor==66 || whethercolor==98){whatcolor=0; break;}
		else if(whethercolor==67 || whethercolor==99){whatcolor=1; break;}
	}
  
	//재시작 위치 
	restarting:
	system("cls");
	resX = 1; resY = 1;
	while(resY<25){
		while(resX<11){
			matrix[resY][resX]=0; resX++;
		}
		resX=1; resY++;
	}

    
	//게임판 
	int boundy;
	boundy = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
	printf("****HOLD****************************NEXT****");
	while(boundy<5){
		gotoxy(0,boundy);
	printf("*");
	boundy++;
	}
	boundy = 1;
	while(boundy<22){
		gotoxy(11,boundy);
		printf("*");
		gotoxy(32,boundy);
		printf("*");
		boundy++;
	}
	gotoxy(11,22);
	printf("**********************");
	gotoxy(0,5);
	printf("***********");
	gotoxy(0,7);
	printf("  키셋팅:\n\n   ← →\n 좌우 이동\n    ↓\n소프트드랍\n   SPACE\n 하드드랍\n   ↑,X\n정방향회전\n     Z\n반방향회전\n     C\n   홀 드");
	boundy=1;
	while(boundy<13){
		gotoxy(43,boundy);
		printf("*"); boundy++;
	}
	gotoxy(33,13);
	printf("***********");
	gotoxy(35,15);
	printf("점  수");
	gotoxy(34,17);
	printf("지운 줄수");
	gotoxy(35,19);
	printf("레  벨");
    
	//랜더마이저 & game
	srand((unsigned)time(NULL));
	int random;
	int randm[7]={10,11,12,13,14,15,16};
	blocknum=0;
	score=0;
	combo=0;
	justhold=0;
	holding=0;  
	delay=1000;
	level = 1;
	linesclrd=0;
	IsTspin = 0;
	whenclr = 0;
	BTB = 0;
	useskick = 0;
	harddrop=0;
	totimes=0;
	restart=0;
	firsthold=-2;
	 while(1){
		if(justhold==1)justhold=0;
		height=4;
		row=1;
		if(whatcolor==0){
			while(height<25){
				row=1;
				while(row<11){
					if(matrix[height][row]==0){
						gotoxy(2*row+10,height-3); printf(" ");
					}
					else{gotoxy(2*row+10,height-3); 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); 
					printf("■");
					}
					row++;
				}
			height++;
			}
		}
		else if(whatcolor==1){
			while(height<25){
				row=1;
				while(row<11){
					if(matrix[height][row]==0){gotoxy(2*row+10,height-3); printf(" ");}
					else if(matrix[height][row]==2){gotoxy(2*row+10,height-3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); printf("■");}
					else if (matrix[height][row] == 3){ gotoxy(2 * row + 10, height - 3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0d); printf("■"); }
					else if (matrix[height][row] == 4){ gotoxy(2 * row + 10, height - 3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e); printf("■"); }
					else if (matrix[height][row] == 5){ gotoxy(2 * row + 10, height - 3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04); printf("■"); }
					else if (matrix[height][row] == 6){ gotoxy(2 * row + 10, height - 3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09); printf("■"); }
					else if (matrix[height][row] == 7){ gotoxy(2 * row + 10, height - 3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0a); printf("■"); }
					else if (matrix[height][row] == 8){ gotoxy(2 * row + 10, height - 3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c); printf("■"); }
					row++;
				}
				height++;
			}
		}
  
		if(combo>1){
			gotoxy(45,4);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e);
			printf("% 2dcombo",combo-1);
		}
		if(score<10000000){
			gotoxy(34,16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
			printf("%7.0lf",score);
		}
		else if(score>9999999 && score<100000000){
			gotoxy(34,16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
			printf("%8.0lf",score);
		}
		else if(score>99999999 && score<1000000000){
			gotoxy(34,16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
			printf("%9.0lf",score);
		}
		else if(score>999999999){
			gotoxy(34,16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
			printf("999999999+");
		}
		gotoxy(36,18);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
		printf("%4.0lf",linesclrd);
		gotoxy(37,20);
		if(level<16){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); printf("% 2d", level);}
		else if(level>15){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); printf("15+");}
		if(-1<linesclrd && linesclrd<10)level=1;
		else if(9<linesclrd && linesclrd<20){level=2; delay=900;}
		else if(19<linesclrd && linesclrd<30){level=3; delay=800;}
		else if(29<linesclrd && linesclrd<40){level=4; delay=700;}
		else if(39<linesclrd && linesclrd<50){level=5; delay=600;}
		else if(49<linesclrd && linesclrd<60){level=6; delay=500;}
		else if(59<linesclrd && linesclrd<70){level=7; delay=400;}
		else if(69<linesclrd && linesclrd<80){level=8; delay=300;}
		else if(79<linesclrd && linesclrd<90){level=9; delay=200;}
		else if(89<linesclrd && linesclrd<100){level=10; delay=150;}
		else if(99<linesclrd && linesclrd<110){level=11; delay=100;}
		else if(109<linesclrd && linesclrd<120){level=12; delay=80;}
		else if(119<linesclrd && linesclrd<130){level=13; delay=60;}
		else if(129<linesclrd && linesclrd<140){level=14; delay=40;}
		else if(139<linesclrd && linesclrd<150){level=15; delay=20;}
		else if(linesclrd>149){level=20; delay=1;}
  
		random=rand();
		randm[(int)blocknum%7]=random%7;
		if((int)blocknum%7==1){if(randm[0]==randm[(int)blocknum%7])continue;}
		if((int)blocknum%7==2){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7])continue;}
		if((int)blocknum%7==3){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7])continue;}
		if((int)blocknum%7==4){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7] || randm[3]==randm[(int)blocknum%7])continue;}
		if((int)blocknum%7==5){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7] || randm[3]==randm[(int)blocknum%7] || randm[4]==randm[(int)blocknum%7])continue;}
		if((int)blocknum%7==6){if(randm[0]==randm[(int)blocknum%7] || randm[1]==randm[(int)blocknum%7] || randm[2]==randm[(int)blocknum%7] || randm[3]==randm[(int)blocknum%7] || randm[4]==randm[(int)blocknum%7] || randm[5]==randm[(int)blocknum%7])continue;}
  
		if(blocknum>2){now=randm[(int)(blocknum-3)%7]+2; next1=randm[(int)(blocknum-2)%7]+2; next2=randm[(int)(blocknum-1)%7]+2; next3=randm[(int)(blocknum)%7]+2;
  
  if(next1==2){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(34,3); printf("■■■■");}
  else if(next1==3){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,2); printf("■"); gotoxy(35,3); printf("■■■");}
  else if(next1==4){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(36,2); printf("■■"); gotoxy(36,3); printf("■■");}
  else if(next1==5){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(39,2); printf("■"); gotoxy(35,3); printf("■■■");}
  else if(next1==6){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,2); printf("■"); gotoxy(35,3); printf("■■■");}
  else if(next1==7){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,2); printf("■■"); gotoxy(35,3); printf("■■");}
  else if(next1==8){gotoxy(33,2); printf("          "); gotoxy(33,3); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,2); printf("■■"); gotoxy(37,3); printf("■■");}
  
  if(next2==2){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(34,7); printf("■■■■");}
  else if(next2==3){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,6); printf("■"); gotoxy(35,7); printf("■■■");}
  else if(next2==4){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(36,6); printf("■■"); gotoxy(36,7); printf("■■");}
  else if(next2==5){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(39,6); printf("■"); gotoxy(35,7); printf("■■■");}
  else if(next2==6){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,6); printf("■"); gotoxy(35,7); printf("■■■");}
  else if(next2==7){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,6); printf("■■"); gotoxy(35,7); printf("■■");}
  else if(next2==8){gotoxy(33,6); printf("          "); gotoxy(33,7); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,6); printf("■■"); gotoxy(37,7); printf("■■");}
  
  if(next3==2){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0b); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(34,11); printf("■■■■");}
  else if(next3==3){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0d); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,10); printf("■"); gotoxy(35,11); printf("■■■");}
  else if(next3==4){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0e); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(36,10); printf("■■"); gotoxy(36,11); printf("■■");}
  else if(next3==5){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(39,10); printf("■"); gotoxy(35,11); printf("■■■");}
  else if(next3==6){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,10); printf("■"); gotoxy(35,11); printf("■■■");}
  else if(next3==7){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0a); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(37,10); printf("■■"); gotoxy(35,11); printf("■■");}
  else if(next3==8){gotoxy(33,10); printf("          "); gotoxy(33,11); printf("          "); if(whatcolor==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c); else if(whatcolor==0)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(35,10); printf("■■"); gotoxy(37,11); printf("■■");}
  
  if(now==2)Itet();
  else if(now==3)Ttet();
  else if(now==4)Otet();
  else if(now==5)Ltet();
  else if(now==6)Jtet();
  else if(now==7)Stet();
  else if(now==8)Ztet();
  
  //재시작 
  if(restart==1)goto restarting;
  
  //줄지우기 
  repeatclr=1;
  howmanyclr=0;
  while(repeatclr<5)
  {height=24;
  row=1;
  clrdheight=-1;
  while(height>1)
  {if(matrix[height][1]!=0 && matrix[height][2]!=0 && matrix[height][3]!=0 && matrix[height][4]!=0 && matrix[height][5]!=0 && matrix[height][6]!=0 && matrix[height][7]!=0 && matrix[height][8]!=0 && matrix[height][9]!=0 && matrix[height][10]!=0)
  {clrdheight=height; linesclrd++; howmanyclr++;
  while(clrdheight>0)
  {while(row<11)
  {if(matrix[clrdheight-1][row]!=1)matrix[clrdheight][row]=matrix[clrdheight-1][row];
  row++;}
  row=1; clrdheight--;}}
  height--;}
  repeatclr++;}}
  
  //점수 
  if(justhold!=2){
  if(howmanyclr==1 && IsTspin==0){score=score+100*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=0; combo++;}
  else if(howmanyclr==2 && IsTspin==0){score=score+300*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Double"); whenclr=totimes; BTB=0; combo++;}
  else if(howmanyclr==3 && IsTspin==0){score=score+500*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Triple"); whenclr=totimes; BTB=0; combo++;}
  else if(howmanyclr==4 && BTB==0){score=score+800*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Tetris"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==4 && BTB==1){score=score+1200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Tetris"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==0 && IsTspin==0){combo=0;}
  else if(howmanyclr==0 && IsTspin==1 && useskick==0){score=score+400*level; combo=0;}
  else if(howmanyclr==0 && IsTspin==1 && useskick==1){score=score+100*level; combo=0;}
  else if(howmanyclr==1 && IsTspin==1 && useskick==0 && BTB==0){score=score+800*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==1 && IsTspin==1 && useskick==1 && BTB==0){score=score+200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==1 && IsTspin==1 && useskick==0 && BTB==1){score=score+1200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==1 && IsTspin==1 && useskick==1 && BTB==1){score=score+300*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Single"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==2 && IsTspin==1 && BTB==0){score=score+1200*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Double"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==2 && IsTspin==1 && BTB==1){score=score+1800*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Double"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==3 && IsTspin==1 && BTB==0){score=score+1600*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,3); printf("Triple"); whenclr=totimes; BTB=1; combo++;}
  else if(howmanyclr==3 && IsTspin==1 && BTB==1){score=score+2400*level; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(47,1); printf("B2B"); gotoxy(46,3); printf("Triple"); whenclr=totimes; BTB=1; combo++;}}
  score=score+50*combo*level;
  
  //퍼펙트 클리어
  pfcX=0; pfcY=0;
  pfcYPLUS:
  pfcY++;
  if(pfcY==25)goto perfectclear;
  pfcXPLUS:
  pfcX++;
  if(pfcX==11){pfcX=0; goto pfcYPLUS;}
  if(matrix[pfcY][pfcX]==0 && blocknum>3)goto pfcXPLUS;
  else goto notpfc;
  
  perfectclear:
  score=score+5000*level;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0c);
  gotoxy(46,5);
  printf("Perfect");
  gotoxy(47,6);
  printf("Clear");
  
  notpfc:
  blocknum++;}
  
  return 0;
  system("PAUSE");
}



//I테트리미노 
void Itet(void)
{blocktype=2;
 rotation=1;
 keyboard=0;
 times=0;
 blocktouch=0;
 IsTspin=0;
 floorkick=0;
 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0 || matrix[4][7]!=0){gameover();}
 if(restart==1)return;
 w=4; x=5; y=6; z=7;
 p=4; q=4; r=4; s=4;
   while(1)
 {ghost();
 draw();
 
 //냅둘때
 while(!kbhit())
 {//블록이 바닥에 닿았을 때 
 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;
 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;
 //딜레이마다 한번씩 블록 내려오는 
 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}
 //T스핀 글자 뜬 지 1초 후에 사라지게 하는 
 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}
 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}
 //블록이 바닥에 닿은지 1초가 지났을 때
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 Sleep(1);
 totimes++;
 times++;} 
 
 //블록이 바닥에 닿은지 1초가 지났을 때 드롭 
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 
 //키보드 입력을 받음
 keyboard=getch();

 
 //F9키 눌렀을때 : 홀드 안하고 무시 
 if(keyboard==0)
 {keyboard=getch(); 
 if(keyboard==67)continue;}
 
 //c버튼 눌렀을때
 else if(keyboard==67 || keyboard==99)
  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}

 //스페이스 눌렀을때
 else if(keyboard==32)
  {erase(); eraseghost();
  harddrop=p;
   while(1)
   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;
   p++; q++; r++; s++; moves++;}
   score=score+2*(p-harddrop);
   break;}
 
 
 
 //방향키 눌렀을때 
 else if(keyboard==224)
 {keyboard=getch();
 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)
 {erase(); eraseghost();}
 if(keyboard==72)
 {//SRS 미적용 
  if(rotation==1){if(matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0 && matrix[p+2][y]==0){w=w+2; x++; z--; p--; r++; s=s+2; rotation++; moves++;}}
  else if(rotation==2){if(matrix[r][w-2]==0 && matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0){w++; y--; z=z-2; p=p+2; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[p-2][y]==0 && matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0){w=w-2; x--; z++; p++; r--; s=s-2; rotation++; moves++;}}
  else if(rotation==4){if(matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0 && matrix[r][w+2]==0){w--; y++; z=z+2; p=p-2; q--; s++; rotation=1; moves++;}}
 }
 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;
 if(score<10000000)
 {gotoxy(34,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%7.0lf",score);}
 else if(score>9999999 && score<100000000)
 {gotoxy(35,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%8.0lf",score);}
 else if(score>99999999 && score<1000000000)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%9.0lf",score);}
 else if(score>999999999)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("999999999+");}}
 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}
 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}
 }
 
 //x버튼 눌렀을때 : SRS미적용
 else if(keyboard==88 || keyboard==120)
 {erase(); eraseghost();
  if(rotation==1){if(matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0 && matrix[p+2][y]==0){w=w+2; x++; z--; p--; r++; s=s+2; rotation++; moves++;}}
  else if(rotation==2){if(matrix[r][w-2]==0 && matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0){w++; y--; z=z-2; p=p+2; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[p-2][y]==0 && matrix[p-1][y]==0 && matrix[p][y]==0 && matrix[p+1][y]==0){w=w-2; x--; z++; p++; r--; s=s-2; rotation++; moves++;}}
  else if(rotation==4){if(matrix[r][w-1]==0 && matrix[r][w]==0 && matrix[r][w+1]==0 && matrix[r][w+2]==0){w--; y++; z=z+2; p=p-2; q--; s++; rotation=1; moves++;}}
  }
 
 
 //z버튼 눌렀을때 (역방향회전) : SRS미적용 
 else if(keyboard==90 || keyboard==122)
 {erase(); eraseghost();
 if(rotation==1){if(matrix[p-1][x]==0 && matrix[p][x]==0 && matrix[p+1][x]==0 && matrix[p+2][x]==0){w++; y--; z=z-2; p=p+2; q++; s--; rotation=4; moves++;}}
 else if(rotation==2){if(matrix[q][w-1]==0 && matrix[q][w]==0 && matrix[q][w+1]==0 && matrix[q][w+2]==0){w=w-2; x--; z++; p++; r--; s=s-2; rotation--; moves++;}}
 else if(rotation==3){if(matrix[p-2][x]==0 && matrix[p][x]==0 && matrix[p+1][x]==0 && matrix[p-1][x]==0){w--; y++; z=z+2; p=p-2; q--; s++; rotation--; moves++;}}
 else if(rotation==4){if(matrix[q][w-2]==0 && matrix[q][w-1]==0 && matrix[q][w]==0 && matrix[q][w+1]==0){w=w+2; x++; z--; p--; r++; s=s+2; rotation--; moves++;}}}
 
}//while(1)

//C버튼 눌렀을 때 안그리고 무시 
 if(keyboard==67 || keyboard==99)hold();
 else{putdraw();}}


 //T테트리미노 
void Ttet(void)
{blocktype=3;
 moves=0;
 TTurns=-1;
 rotation=1;
 keyboard=0;
 times=0;
 blocktouch=0;
 IsTspin=0;
 floorkick=0;
 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}
 if(restart==1)return;
 w=5; x=4; y=5; z=6;  
 p=3; q=4; r=4; s=4;
  while(1)
 {ghost();
 draw();
 
 //냅둘때
 while(!kbhit())
 {//블록이 바닥에 닿았을 때 
 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;
 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;
 //딜레이마다 한번씩 블록 내려오는 
 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}
 //T스핀 글자 뜬 지 1초 후에 사라지게 하는 
 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}
 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}
 //블록이 바닥에 닿은지 1초가 지났을 때
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 Sleep(1);
 totimes++;
 times++;} 
 
 //블록이 바닥에 닿은지 1초가 지났을 때 드롭 
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 
 //키보드 입력을 받음
 keyboard=getch();

 
 //F9키 눌렀을때 : 홀드 안하고 무시 
 if(keyboard==0)
 {keyboard=getch(); 
 if(keyboard==67)continue;}
 
 //c버튼 눌렀을때
 else if(keyboard==67 || keyboard==99)
  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}

 //스페이스 눌렀을때
 else if(keyboard==32)
  {erase(); eraseghost();
  harddrop=p;
   while(1)
   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;
   p++; q++; r++; s++; moves++;}
   score=score+2*(p-harddrop);
   break;}
 
 
 
 //방향키 눌렀을때 
 else if(keyboard==224)
 {keyboard=getch();
 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)
 {erase(); eraseghost();}
 if(keyboard==72)
 {//SRS 미적용 
  if(rotation==1){if(matrix[r+1][w]==0){w++; x++; z--; p++; q--; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[r][x-1]==0){w--; x++; z--; p++; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[q-1][y]==0){w--; x--; z++; p--; q++; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[p][y+1]==0){w++; x--; z++; p--; q--; s++; rotation=1; moves++;}}
 }
 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;
 if(score<10000000)
 {gotoxy(34,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%7.0lf",score);}
 else if(score>9999999 && score<100000000)
 {gotoxy(35,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%8.0lf",score);}
 else if(score>99999999 && score<1000000000)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%9.0lf",score);}
 else if(score>999999999)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("999999999+");}}
 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}
 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}
 }
 
 //x버튼 눌렀을때 : SRS미적용
 else if(keyboard==88 || keyboard==120)
 {erase(); eraseghost();
  if(rotation==1){if(matrix[r+1][w]==0){w++; x++; z--; p++; q--; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[r][x-1]==0){w--; x++; z--; p++; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[q-1][y]==0){w--; x--; z++; p--; q++; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[p][y+1]==0){w++; x--; z++; p--; q--; s++; rotation=1; moves++;}}}
 
 
 //z버튼 눌렀을때 (역방향회전) : SRS적용 
 else if(keyboard==90 || keyboard==122)
 {erase(); eraseghost();
 if(rotation==1){if(matrix[r+1][y]==0){w--; x++; z--; p++; q++; s--; rotation=4; moves++;}}
 else if(rotation==2){if(matrix[r][y-1]==0){w--; x--; z++; p--; q++; s--; rotation--; moves++;}
                      else if(matrix[q][w]==0 && matrix[r][w+1]==0){y++; z=z+2; p--; q++; s--; rotation--; moves++;}}
 else if(rotation==3){if(matrix[q-1][y]==0){w++; x--; z++; p--; q--; s++; rotation--; moves++;}
                      else if(matrix[q-1][z]==0 && matrix[p][z]==0){x=x-2; y--; p--; q--; s++; rotation--; moves++;}}
 else if(rotation==4){if(matrix[r][y+1]==0){w++; x++; z--; p++; q--; s++; rotation--; moves++;}
                      else if(matrix[r][w-1]==0 && matrix[q][w]==0){y--; z=z-2; p++; q--; s++; rotation--; moves++;}}}
 
}//while(1)

//C버튼 눌렀을 때 안그리고 무시 
 if(keyboard==67 || keyboard==99)hold();
 else{putdraw();
 if(rotation==3 && matrix[s+1][z]!=0 && matrix[s+1][x]!=0 && (matrix[s-1][z]!=0 || matrix[s-1][x]!=0)){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,2); printf("T-spin"); whenTSpin=totimes; IsTspin=1; useskick=0;}
 else if(rotation==2 && matrix[q][w]!=0 && matrix[s][w]!=0 && matrix[s][z-1]!=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,2); printf("T-spin"); whenTSpin=totimes; IsTspin=1; useskick=0;}
 else if(TTurns==moves){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f); gotoxy(46,2); printf("T-spin"); whenTSpin=totimes; IsTspin=1; useskick=1;}}}



//O테트리미노 (돌아갈 필요 없으므로 x,z,위화살표 불필요) 
void Otet(void)
{blocktype=4;
 rotation=1;
 keyboard=0;
 times=0;
 blocktouch=0;
 IsTspin=0;
 floorkick=0;
 if(matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}
 if(restart==1)return;
 w=5; x=6; y=5; z=6; //1~10
 p=3; q=3; r=4; s=4; //0~20 
 while(1)
 {ghost();
  draw();
 
 //냅둘때
 while(!kbhit())
 {if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;
 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;
 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw(); times++; totimes++;}
 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}
 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 Sleep(1);
 totimes++;
 times++;} 
 
 //바닥에 닿은지 1초후에 다음블록 
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
  
 //키보드 입력을 받음
 keyboard=getch();
 
 //F9키 눌렀을때 : 홀드 안하고 무시 
 if(keyboard==0)
 {keyboard=getch(); 
 if(keyboard==67)continue;}
 
 //방향키 눌렀을때 
 if(keyboard==224)
 {keyboard=getch();
 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)
 {erase(); eraseghost();}
 if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; score=score+1;
  if(score<10000000)
  {gotoxy(34,16);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
  printf("%7.0lf",score);}
  else if(score>9999999 && score<100000000)
  {gotoxy(35,16);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
  printf("%8.0lf",score);}
  else if(score>99999999 && score<1000000000)
  {gotoxy(36,16);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
  printf("%9.0lf",score);}
  else if(score>999999999)
  {gotoxy(36,16);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
  printf("999999999+");}}
 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--;}
 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++;}
 }
    
 //스페이스 눌렀을때 
 else if(keyboard==32)
  {erase(); eraseghost();
  harddrop=p;
   while(1){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;
   p++; q++; r++; s++;}
   score=score+2*(p-harddrop);
   break;}
      
 //c버튼 눌렀을때
 else if(keyboard==67 || keyboard==99)
  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}
 
}//while(1)
 if(keyboard==67 || keyboard==99)hold();
 else putdraw();}


//L테트리미노 
void Ltet(void)
{blocktype=5;
 rotation=1;
 keyboard=0;
 times=0;
 blocktouch=0;
 IsTspin=0;
 floorkick=0;
 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}
 if(restart==1)return;
 w=6; x=4; y=5; z=6;
 p=3; q=4; r=4; s=4;
   while(1)
 {ghost();
 draw();
 
 //냅둘때
 while(!kbhit())
 {//블록이 바닥에 닿았을 때 
 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;
 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;
 //딜레이마다 한번씩 블록 내려오는 
 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}
 //T스핀 글자 뜬 지 1초 후에 사라지게 하는 
 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}
 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}
 //블록이 바닥에 닿은지 1초가 지났을 때
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 Sleep(1);
 totimes++;
 times++;} 
 
 //블록이 바닥에 닿은지 1초가 지났을 때 드롭 
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 
 //키보드 입력을 받음
 keyboard=getch();

 
 //F9키 눌렀을때 : 홀드 안하고 무시 
 if(keyboard==0)
 {keyboard=getch(); 
 if(keyboard==67)continue;}
 
 //c버튼 눌렀을때
 else if(keyboard==67 || keyboard==99)
  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}

 //스페이스 눌렀을때
 else if(keyboard==32)
  {erase(); eraseghost();
  harddrop=p;
   while(1)
   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;
   p++; q++; r++; s++; moves++;}
   score=score+2*(p-harddrop);
   break;}
 
 
 
 //방향키 눌렀을때 
 else if(keyboard==224)
 {keyboard=getch();
 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)
 {erase(); eraseghost();}
 if(keyboard==72)
 {//SRS 미적용 
  if(rotation==1){if(matrix[s+1][w]==0 && matrix[s+1][y]==0 && matrix[p][y]==0){x++; z--; p=p+2; q--; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[s][z-1]==0 && matrix[r][z-1]==0 && matrix[r][w]==0){w=w-2; x++; z--; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[s-1][w]==0 && matrix[s-1][y]==0 && matrix[p][y]==0){x--; z++; p=p-2; q++; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[p][z+1]==0 && matrix[r][z+1]==0 && matrix[r][w]==0){w=w+2; x--; z++; q--; s++; rotation=1; moves++;}}
 }
 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;
 if(score<10000000)
 {gotoxy(34,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%7.0lf",score);}
 else if(score>9999999 && score<100000000)
 {gotoxy(35,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%8.0lf",score);}
 else if(score>99999999 && score<1000000000)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%9.0lf",score);}
 else if(score>999999999)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("999999999+");}}
 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}
 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}
 }
 
 //x버튼 눌렀을때 : SRS미적용
 else if(keyboard==88 || keyboard==120)
 {erase(); eraseghost();
  if(rotation==1){if(matrix[s+1][w]==0 && matrix[s+1][y]==0 && matrix[p][y]==0){x++; z--; p=p+2; q--; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[s][z-1]==0 && matrix[r][z-1]==0 && matrix[r][w]==0){w=w-2; x++; z--; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[s-1][w]==0 && matrix[s-1][y]==0 && matrix[p][y]==0){x--; z++; p=p-2; q++; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[p][z+1]==0 && matrix[r][z+1]==0 && matrix[r][w]==0){w=w+2; x--; z++; q--; s++; rotation=1; moves++;}}
  }
 
 
 //z버튼 눌렀을때 (역방향회전) : SRS미적용 
 else if(keyboard==90 || keyboard==122)
 {erase(); eraseghost();
 if(rotation==1){if(matrix[p][x]==0 && matrix[p][y]==0 && matrix[q+1][y]==0){w=w-2; x++; z--; q++; s--; rotation=4; moves++;}}
 else if(rotation==2){if(matrix[q][w]==0 && matrix[r][w]==0 && matrix[r][x-1]==0){x--; z++; p=p-2; q++; s--; rotation--; moves++;}}
 else if(rotation==3){if(matrix[q-1][y]==0 && matrix[p][y]==0 && matrix[p][x]==0){w=w+2; x--; z++; q--; s++; rotation--; moves++;}}
 else if(rotation==4){if(matrix[q][w]==0 && matrix[r][w]==0 && matrix[r][x+1]==0){x++; z--; p=p+2; q--; s++; rotation--; moves++;}}}
 
}//while(1)

//C버튼 눌렀을 때 안그리고 무시 
 if(keyboard==67 || keyboard==99)hold();
 else{putdraw();}}


//J테트리미노 
void Jtet(void)
{blocktype=6;
 rotation=1;
 keyboard=0;
 times=0;
 blocktouch=0;
 IsTspin=0;
 floorkick=0;
 if(matrix[4][4]!=0 || matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}
 if(restart==1)return;
 w=4; x=4; y=5; z=6;
 p=3; q=4; r=4; s=4;
  while(1)
 {ghost();
 draw();
 
 //냅둘때
 while(!kbhit())
 {//블록이 바닥에 닿았을 때 
 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;
 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;
 //딜레이마다 한번씩 블록 내려오는 
 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}
 //T스핀 글자 뜬 지 1초 후에 사라지게 하는 
 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}
 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}
 //블록이 바닥에 닿은지 1초가 지났을 때
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 Sleep(1);
 totimes++;
 times++;} 
 
 //블록이 바닥에 닿은지 1초가 지났을 때 드롭 
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 
 //키보드 입력을 받음
 keyboard=getch();

 
 //F9키 눌렀을때 : 홀드 안하고 무시 
 if(keyboard==0)
 {keyboard=getch(); 
 if(keyboard==67)continue;}
 
 //c버튼 눌렀을때
 else if(keyboard==67 || keyboard==99)
  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}

 //스페이스 눌렀을때
 else if(keyboard==32)
  {erase(); eraseghost();
  harddrop=p;
   while(1)
   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;
   p++; q++; r++; s++; moves++;}
   score=score+2*(p-harddrop);
   break;}
 
 
 
 //방향키 눌렀을때 
 else if(keyboard==224)
 {keyboard=getch();
 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)
 {erase(); eraseghost();}
 if(keyboard==72)
 {//SRS 미적용 
  if(rotation==1){if(matrix[p][y]==0 && matrix[q+1][y]==0 && matrix[p][w]==0){w=w+2; x++; z--; q--; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[r][x-1]==0 && matrix[r][w]==0 && matrix[s][w]==0){x++; z--; p=p+2; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[q-1][y]==0 && matrix[p][z]==0 && matrix[p][y]==0){w=w-2; x--; z++; q++; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[s][w]==0 && matrix[r][w]==0 && matrix[r][x+1]==0){x--; z++; p=p-2; q--; s++; rotation=1; moves++;}}
 }
 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;
 if(score<10000000)
 {gotoxy(34,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%7.0lf",score);}
 else if(score>9999999 && score<100000000)
 {gotoxy(35,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%8.0lf",score);}
 else if(score>99999999 && score<1000000000)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%9.0lf",score);}
 else if(score>999999999)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("999999999+");}}
 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}
 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}
 }
 
 //x버튼 눌렀을때 : SRS미적용
 else if(keyboard==88 || keyboard==120)
 {erase(); eraseghost();
  if(rotation==1){if(matrix[p][y]==0 && matrix[q+1][y]==0 && matrix[p][w]==0){w=w+2; x++; z--; q--; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[r][x-1]==0 && matrix[r][w]==0 && matrix[s][w]==0){x++; z--; p=p+2; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[q-1][y]==0 && matrix[p][z]==0 && matrix[p][y]==0){w=w-2; x--; z++; q++; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[s][w]==0 && matrix[r][w]==0 && matrix[r][x+1]==0){x--; z++; p=p-2; q--; s++; rotation=1; moves++;}}
  }
 
 
 //z버튼 눌렀을때 (역방향회전) : SRS미적용 
 else if(keyboard==90 || keyboard==122)
 {erase(); eraseghost();
 if(rotation==1){if(matrix[p][y]==0 && matrix[q+1][w]==0 && matrix[q+1][y]==0){x++; z--; p=p+2; q++; s--; rotation=4; moves++;}}
 else if(rotation==2){if(matrix[r][w]==0 && matrix[r][x-1]==0 && matrix[p][x-1]==0){w=w-2; x--; z++; q++; s--; rotation--; moves++;}}
 else if(rotation==3){if(matrix[q-1][y]==0 && matrix[q-1][w]==0 && matrix[p][y]==0){x--; z++; p=p-2; q--; s++; rotation--; moves++;}}
 else if(rotation==4){if(matrix[p][x+1]==0 && matrix[r][x+1]==0 && matrix[r][w]==0){w=w+2; x++; z--; q--; s++; rotation--; moves++;}}}
 
}//while(1)

//C버튼 눌렀을 때 안그리고 무시 
 if(keyboard==67 || keyboard==99)hold();
 else{putdraw();}}


//S테트리미노 
void Stet(void)
{blocktype=7;
 rotation=1;
 keyboard=0;
 times=0;
 blocktouch=0;
 IsTspin=0;
 floorkick=0;
 if(matrix[4][4]!=0 || matrix[4][5]!=0){gameover();}
 if(restart==1)return;
 w=5; x=6; y=4; z=5;
 p=3; q=3; r=4; s=4;
  while(1)
 {ghost();
 draw();
 
 //냅둘때
 while(!kbhit())
 {//블록이 바닥에 닿았을 때 
 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;
 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;
 //딜레이마다 한번씩 블록 내려오는 
 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}
 //T스핀 글자 뜬 지 1초 후에 사라지게 하는 
 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}
 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}
 //블록이 바닥에 닿은지 1초가 지났을 때
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 Sleep(1);
 totimes++;
 times++;} 
 
 //블록이 바닥에 닿은지 1초가 지났을 때 드롭 
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 
 //키보드 입력을 받음
 keyboard=getch();

 
 //F9키 눌렀을때 : 홀드 안하고 무시 
 if(keyboard==0)
 {keyboard=getch(); 
 if(keyboard==67)continue;}
 
 //c버튼 눌렀을때
 else if(keyboard==67 || keyboard==99)
  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}

 //스페이스 눌렀을때
 else if(keyboard==32)
  {erase(); eraseghost();
  harddrop=p;
   while(1)
   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;
   p++; q++; r++; s++; moves++;}
   score=score+2*(p-harddrop);
   break;}
 
 
 
 //방향키 눌렀을때 
 else if(keyboard==224)
 {keyboard=getch();
 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)
 {erase(); eraseghost();}
 if(keyboard==72)
 {//SRS 미적용 
  if(rotation==1){if(matrix[p][w]==0 && matrix[r][x]==0 && matrix[r+1][x]==0){w++; y++; p++; q=q+2; r--; rotation++; moves++;}}
  else if(rotation==2){if(matrix[p][w]==0 && matrix[q][y-1]==0 && matrix[q][y]==0){w--; x=x-2; y++; p++; r++; rotation++; moves++;}}
  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][x]==0 && matrix[p][w]==0){w--; y--; p--; q=q-2; r++; rotation++; moves++;}}
  else if(rotation==4){if(matrix[q][y]==0 && matrix[q][y+1]==0 && matrix[p][w]==0){w++; x=x+2; y--; p--; r--; rotation=1; moves++;}}
 }
 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;
 if(score<10000000)
 {gotoxy(34,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%7.0lf",score);}
 else if(score>9999999 && score<100000000)
 {gotoxy(35,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%8.0lf",score);}
 else if(score>99999999 && score<1000000000)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%9.0lf",score);}
 else if(score>999999999)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("999999999+");}}
 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}
 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}
 }
 
 //x버튼 눌렀을때 : SRS미적용
 else if(keyboard==88 || keyboard==120)
 {erase(); eraseghost();
  if(rotation==1){if(matrix[p][w]==0 && matrix[r][x]==0 && matrix[r+1][x]==0){w++; y++; p++; q=q+2; r--; rotation++; moves++;}}
  else if(rotation==2){if(matrix[p][w]==0 && matrix[q][y-1]==0 && matrix[q][y]==0){w--; x=x-2; y++; p++; r++; rotation++; moves++;}}
  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][x]==0 && matrix[p][w]==0){w--; y--; p--; q=q-2; r++; rotation++; moves++;}}
  else if(rotation==4){if(matrix[q][y]==0 && matrix[q][y+1]==0 && matrix[p][w]==0){w++; x=x+2; y--; p--; r--; rotation=1; moves++;}}
  }
 
 
 //z버튼 눌렀을때 (역방향회전) : SRS미적용 
 else if(keyboard==90 || keyboard==122)
 {erase(); eraseghost();
 if(rotation==1){if(matrix[p][y]==0 && matrix[r][y]==0 && matrix[r+1][w]==0){w--; x=x-2; y++; p++; r++; rotation=4; moves++;}}
 else if(rotation==2){if(matrix[r][y]==0 && matrix[r][w]==0 && matrix[p][y-1]==0){w--; y--; p--; q=q-2; r++; rotation--; moves++;}}
 else if(rotation==3){if(matrix[r-1][w]==0 && matrix[r][y]==0 && matrix[p][y]==0){w++; x=x+2; y--; p--; r--; rotation--; moves++;}}
 else if(rotation==4){if(matrix[q][y+1]==0 && matrix[r][w]==0 && matrix[r][y]==0){w++; y++; p++; q=q+2; r--; rotation--; moves++;}}}
 
}//while(1)

//C버튼 눌렀을 때 안그리고 무시 
 if(keyboard==67 || keyboard==99)hold();
 else{putdraw();}}


//Z테트리미노 
void Ztet(void)
{blocktype=8;
 rotation=1;
 keyboard=0;
 times=0;
 blocktouch=0;
 IsTspin=0;
 floorkick=0;
 if(matrix[4][5]!=0 || matrix[4][6]!=0){gameover();}
 if(restart==1)return;
 w=4; x=5; y=5; z=6;
 p=3; q=3; r=4; s=4;
  while(1)
 {ghost();
 draw();
 
 //냅둘때
 while(!kbhit())
 {//블록이 바닥에 닿았을 때 
 if((matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0) && blocktouch==0)blocktouch=totimes;
 else if(matrix[p+1][w]==0 && matrix[q+1][x]==0 && matrix[r+1][y]==0 && matrix[s+1][z]==0)blocktouch=0;
 //딜레이마다 한번씩 블록 내려오는 
 if((int)times % (int)delay==(int)delay-1 && !(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)){erase(); eraseghost(); p++; q++; r++; s++; moves++; ghost(); draw();}
 //T스핀 글자 뜬 지 1초 후에 사라지게 하는 
 if(whenTSpin==totimes-1000){gotoxy(46,2); printf("      ");}
 if(whenclr==totimes-1000){gotoxy(46,3); printf("      "); gotoxy(47,1); printf("   "); gotoxy(45,4); printf("         "); gotoxy(46,5); printf("       "); gotoxy(47,6); printf("     ");}
 //블록이 바닥에 닿은지 1초가 지났을 때
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 Sleep(1);
 totimes++;
 times++;} 
 
 //블록이 바닥에 닿은지 1초가 지났을 때 드롭 
 if(blocktouch!=0 && blocktouch==totimes-1000)break;
 
 //키보드 입력을 받음
 keyboard=getch();

 
 //F9키 눌렀을때 : 홀드 안하고 무시 
 if(keyboard==0)
 {keyboard=getch(); 
 if(keyboard==67)continue;}
 
 //c버튼 눌렀을때
 else if(keyboard==67 || keyboard==99)
  {if(justhold==0 && blocknum-1!=firsthold){erase(); eraseghost(); moves++; break;}}

 //스페이스 눌렀을때
 else if(keyboard==32)
  {erase(); eraseghost();
  harddrop=p;
   while(1)
   {if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)break;
   p++; q++; r++; s++; moves++;}
   score=score+2*(p-harddrop);
   break;}
 
 
 
 //방향키 눌렀을때 
 else if(keyboard==224)
 {keyboard=getch();
 if(keyboard==72 || keyboard==80 || keyboard==75 || keyboard==77)
 {erase(); eraseghost();}
 if(keyboard==72)
 {//SRS 미적용 
  if(rotation==1){if(matrix[p][z]==0 && matrix[r][z]==0 && matrix[r+1][x]==0){w=w+2; x++; z--; q++; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[q][y-1]==0 && matrix[s][y]==0 && matrix[s][w]==0){x--; z--; p=p+2; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][z]==0 && matrix[p][z]==0){w=w-2; x--; z++; q--; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[s][w]==0 && matrix[s][y]==0 && matrix[q][y+1]==0){x++; z++; p=p-2; q--; s++; rotation=1; moves++;}}
 }
 else if(keyboard==80){if(matrix[p+1][w]!=0 || matrix[q+1][x]!=0 || matrix[r+1][y]!=0 || matrix[s+1][z]!=0)continue; p++; q++; r++; s++; moves++; score=score+1;
 if(score<10000000)
 {gotoxy(34,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%7.0lf",score);}
 else if(score>9999999 && score<100000000)
 {gotoxy(35,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%8.0lf",score);}
 else if(score>99999999 && score<1000000000)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("%9.0lf",score);}
 else if(score>999999999)
 {gotoxy(36,16);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
 printf("999999999+");}}
 else if(keyboard==75){if(matrix[p][w-1]!=0 || matrix[q][x-1]!=0 || matrix[r][y-1]!=0 || matrix[s][z-1]!=0)continue; w--; x--; y--; z--; moves++;}
 else if(keyboard==77){if(matrix[p][w+1]!=0 || matrix[q][x+1]!=0 || matrix[r][y+1]!=0 || matrix[s][z+1]!=0)continue; w++; x++; y++; z++; moves++;}
 }
 
 //x버튼 눌렀을때 : SRS미적용
 else if(keyboard==88 || keyboard==120)
 {erase(); eraseghost();
  if(rotation==1){if(matrix[p][z]==0 && matrix[r][z]==0 && matrix[r+1][x]==0){w=w+2; x++; z--; q++; s++; rotation++; moves++;}}
  else if(rotation==2){if(matrix[q][y-1]==0 && matrix[s][y]==0 && matrix[s][w]==0){x--; z--; p=p+2; q++; s--; rotation++; moves++;}}
  else if(rotation==3){if(matrix[r-1][x]==0 && matrix[r][z]==0 && matrix[p][z]==0){w=w-2; x--; z++; q--; s--; rotation++; moves++;}}
  else if(rotation==4){if(matrix[s][w]==0 && matrix[s][y]==0 && matrix[q][y+1]==0){x++; z++; p=p-2; q--; s++; rotation=1; moves++;}}
  }
 
 
 //z버튼 눌렀을때 (역방향회전) : SRS미적용 
 else if(keyboard==90 || keyboard==122)
 {erase(); eraseghost();
 if(rotation==1){if(matrix[p][x]==0 && matrix[r][w]==0 && matrix[r+1][w]==0){x--; z--; p=p+2; q++; s--; rotation=4; moves++;}}
 else if(rotation==2){if(matrix[p][y-1]==0 && matrix[p][y]==0 && matrix[q][w]==0){w=w-2; x--; z++; q--; s--; rotation--; moves++;}}
 else if(rotation==3){if(matrix[r-1][w]==0 && matrix[r][w]==0 && matrix[p][x]==0){x++; z++; p=p-2; q--; s++; rotation--; moves++;}}
 else if(rotation==4){if(matrix[q][w]==0 && matrix[p][y]==0 && matrix[p][y+1]==0){w=w+2; x++; z--; q++; s++; rotation--; moves++;}}}
 
}//while(1)

//C버튼 눌렀을 때 안그리고 무시 
 if(keyboard==67 || keyboard==99)hold();
 else{putdraw();}}




 //게임오버
void gameover(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
	GOx=12; GOy=21;
	while(GOy>0){
		while(GOx<31){
			gotoxy(GOx,GOy);
			printf("■"); 
			GOx=GOx+2;
		}
	GOx=12; GOy--; 
	Sleep(100);
	}
	Sleep(1000); system("cls");
	gotoxy(10,10); printf("다시 플레이하시겠습니까? Y/N");
	while(1){
		GOkey=getch();
		if(GOkey==89 || GOkey==121){
			restart=1; 
			break;
		}
		else if(GOkey==78 || GOkey==110){
			exit(0);
		}
	}
} 