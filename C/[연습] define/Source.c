#include <stdio.h>
#define DOUBLE(x) x + x

#define VER 7
#define BIT16 

int main()
{
	// ��ũ�� �Լ�
	int iVAL;
	double fVAL;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &iVAL);
	printf("����� %d�Դϴ�.\n", DOUBLE(iVAL));

	printf("�Ǽ��� �Է��ϼ��� : ");
	scanf("%lf", &fVAL);
	printf("����� %lf�Դϴ�.\n", DOUBLE(fVAL));
	printf("");
	
	puts("");
	
	//���Ǻ� ������ ������
	int max;

#if VER >= 6
	printf("���� %d�Դϴ�.\n", VER);
#endif

#ifdef BIT16
	max = 32767;
#else
	max = 2147483647;
#endif

	printf("int�� ������ �ִ� : %d\n", max);
	return 0;
}