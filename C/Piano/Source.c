#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define DO    327 //도
#define DO$    346 //도#
#define RE    367 //레
#define RE$    388 //레#
#define MI    412 //미
#define PA    436 //파
#define PA$    462 //파#
#define SOL   489 //솔
#define SOL$    519 //솔#
#define RA    550 //라
#define RA$    582 //라#
#define SI    617 //시
#define _DO    654 //도
#define TIME 100 //지속시간

int main()
{
	printf("도=a, 도#=w\n레=s, 레#=e\n미=d\n파=f, 파#=t\n솔=g, 솔#=y\n라=h, 라#=u\n시=j\n_도=k\n");
	printf("\"비행기\" : gghhggd ggdds gghhggd gdsda\n");
	while (1)
		
		switch (getch()) //음
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