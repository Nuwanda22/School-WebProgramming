#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define DO    327 //��
#define DO$    346 //��#
#define RE    367 //��
#define RE$    388 //��#
#define MI    412 //��
#define PA    436 //��
#define PA$    462 //��#
#define SOL   489 //��
#define SOL$    519 //��#
#define RA    550 //��
#define RA$    582 //��#
#define SI    617 //��
#define _DO    654 //��
#define TIME 100 //���ӽð�

int main()
{
	printf("��=a, ��#=w\n��=s, ��#=e\n��=d\n��=f, ��#=t\n��=g, ��#=y\n��=h, ��#=u\n��=j\n_��=k\n");
	printf("\"�����\" : gghhggd ggdds gghhggd gdsda\n");
	while (1)
		
		switch (getch()) //��
	{
		case 'a':
			Beep(DO, TIME);
			break;
		case 'w':
			Beep(DO$, TIME);
			break;
		case 's':
			Beep(RE, TIME);
			break;
		case 'e':
			Beep(RE$, TIME);
			break;
		case 'd':
			Beep(MI, TIME);
			break;
		case 'f':
			Beep(PA, TIME);
			break;
		case 't':
			Beep(PA$, TIME);
			break;
		case 'g':
			Beep(SOL, TIME);
			break;
		case 'y':
			Beep(SOL$, TIME);
			break;
		case 'h':
			Beep(RA, TIME);
			break;
		case 'u':
			Beep(RA$, TIME);
			break;
		case 'j':
			Beep(SI, TIME);
			break;
		case 'k':
			Beep(_DO, TIME);
			break;
		case 'M':
			Beep(0, TIME);
			break;
	}
}