/* printf1.c*/
#include <stdio.h>

//int main(void)
//{
//	printf("Hello Everybody \n");
//	printf("%d \n", 1234);
//	printf("%d %d \n", 10, 20);
//	return 0;
//}

//int main(void)
//{
//	printf("my age : %d \n", 15);
//	printf("%d is my point \n", 100);
//	printf("good \nmornig \neverybody\n");
//	return 0;
//}

//int main(void)
//{
//	int a, b;
//	int c = 30, d = 40;
//
//	a = 10;
//	b = 20;
//
//	printf("%d %d \n", a, b);
//	printf("%d %d \n", c, d);
//	return 0;
//}

//int main(void)
//{
//	
//	int result;
//	result = 3 + 4;
//
//	printf("���� ��� ; %d \n", result);
//	printf("%d ���ϱ� %d�� %d �Դϴ�.\n", 3, 4, result);
//	printf("���� result�� ����� ��: %d \n", result);
//
//	return 0;
//}

//int main()
//{
//	int val = 10;
//
//	printf("%d\n", sizeof val);
//	printf("%d\n", sizeof (char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(long double));
//
//	int i;
//	int a = 10, b = 20, c = 0;
//
//	printf("%d\n", (a != b) && c);
//	
//	return 0;
//}
//main()
//{
//	int a = 30, x;
//
//	x = (0 <= a && a <= 100) ? a: 0;
//	printf("%d\n", x);
//}

//int main()
//{
//	float f = 0.0000000000001;
//	double d = 0.0000000000001;
//
//	printf("%.15f %.15lf\n", f, d);
//	return 0;
//}
//int main()
//{
//	int a = 10, b = 30;
//	printf("a>b %d\n", a>b);
//	printf("a<b %d\n", a<b);
//	printf("a==b %d\n", a==b);
//	printf("a>=b %d\n", a>=b);
//}

//int main()
//{
//	//printf("%c", 84);
//	float f = 3.14;
//	return 0;
//}

//#define b 50
//
//int main()
//{
//	const int a = 10;
//
//	printf("%d %d\n", a, b);
//	
//	int n = 5.25;
//	double d = 3;
//	char c = 129;
//
//	printf("%d %lf %c\n", n, d, c);
//
//	return 0;
//}

//int main()
//{
//	int i;
//
//	float num = 0.0;
//	for (i = 0; i < 100; i++)
//		num += 0.1; //num = num + 0.1;
//	printf("%f", num);
//}

//int main(void)
//{
//	int a = 15;   //00001111
//	int b = 20;   //00010100
//	int c = a^b;  //00011011
//
//	printf("XOR= %d\n", c);
//
//	int i = 15;  //00001111
//	                     //00000011
//	printf("15 >> 2 = %d", i >> 2);
//}

//int main(void)
//{
//	int var = 50;
//
//	printf("%d\n", sizeof var);
//	printf("%d\n", sizeof (int));
//	printf("%d\n", sizeof (char));
//	printf("%d\n", sizeof (long));
//	printf("%d\n", sizeof (double));
//	printf("%d\n", sizeof(double long));
//
//}

//void main()
//{
//	printf("%-8s %14s %5s \n", "�̸�", "�����а�", "�г�"); 
//	printf("%-8s %14s %5d \n", "�赿��", "���ڰ���", 3);
//	printf("%-8s %14s %5d \n", "������", "��ǻ�Ͱ���", 2);
//	printf("%-8s %14s %5d \n", "�Ѽ���", "�̼�������", 4);
//}

void main()
{
	int a,b;
	char c;

	scanf("%d %c %d", &a,&c ,&b);

	switch (c)
	{
	case '+':
		printf("%d\n", a+b);
		break;
	case '-':
		printf("%d\n", a-b);
		break;
	case '*':
		printf("%d!\n", a*b);
		break;
	case '/':
		printf("%f\n", (float)a / b);
		break;
	default:
		break;
	}
}