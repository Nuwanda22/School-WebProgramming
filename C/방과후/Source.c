#include <stdio.h>

/*
int main()
{   // ���� ����

	// �Է�
	printf("input : ");
	scanf("%d", &);
	// ����

	// ���

	// ����
	return 0;
}
*/
/*

int main()
{   // ���� ����
	int N;
	int hole = 0, jack = 0;
	// �Է�

	// ����
	while (1){
		scanf("%d", &N);
		if (N != 0)
			if (N % 2 == 1)
				hole++;
			else
				jack++;
		else
			break;
	}
	//���
	printf("Ȧ�� : %d\n¦�� : %d\n", hole, jack);
	//����
	return 0;
}
*/
/*
#include <stdio.h> 

int main()
{   // ���� ����
	int N, i=1;
	int sum = 0;
	float avg = 0;
	// �Է�
	
	//�Է� �� ����
	while (1) {
		scanf("%d", &N);
		if (N >= 0 && N <= 100){
			sum += N;
			avg = (float)sum / i;
			i++;
		}
		else
			break;
	}

	//���
	printf("\n�հ� : %d��\n��� : %.1f��\n", sum, avg);
	//����
	return 0;
}
*/
/*
#include <stdio.h> 

int main()
{   // ���� ����
	int N, baesu = 0;
	// �Է�
	
	// ����
	while (1){
		scanf("%d", &N);
		if (N != 0){
			if (N % 3 == 0 || N % 5 == 0)
				baesu++;
		}
		else
			break;
	}
	//���
	printf("%d\n", baesu);
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int under, high;
	float neolbi;
	char one_more;
	// �Է�

	// ����
	while (1){
		printf("�غ� : ");
		scanf("%d", &under);
		printf("���� : ");
		scanf("%d", &high);

		neolbi = 1 / 2.0 * under * high;

		printf("�Է��� �ﰢ���� ���̴� %.1f�Դϴ�. \n", neolbi);
		printf("����Ͻðڽ��ϱ�? : ");
		scanf(" %c", &one_more);

		if (one_more == 'Y' || one_more == 'y')
			continue;
		else
			break;
	}
	//���

	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int i, n;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����
	for (i = 0; i < n; i++)
		puts("ȫ�浿");
	//���

	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int i, tmp;
	int num1, num2;
	// �Է�
	printf("input : ");
	scanf("%d%d", &num1, &num2);
	// ����
	if (num1 > num2){
		tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	for (; num1 <= num2; num1++)
		printf("%d ", num1);
	//���

	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int N, i;
	int sum = 0;
	// �Է�
	printf("input : ");
	scanf("%d", &N);
	// ����
	for (i = 1; i <= N; i++){
		if (i % 5 == 0)
			sum += i;
	}
	//���
	printf("%d\n", sum);
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int n, m, i, sum = 0;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����
	for (i = 1; i <= n; i++){
		scanf("%d", &m);
		sum += m;
	}
	//���
	printf("%.2f", (float)sum / n);
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int n, i;
	int hole = 0, jack = 0;
	// �Է�
	printf("input : ");
	// ����
	for (i = 1; i <= 10; i++){
		scanf("%d", &n);
		if (n % 2 == 0)
			jack++;
		else
			hole++;
	}
	//���
	printf("¦�� : %d\nȦ�� : %d\n", jack, hole);
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int n1, n2, i;
	int m = 0, tmp, sum = 0;
	// �Է�
	printf("input : ");
	scanf("%d %d", &n1, &n2);
	// ����
	if (n1 > n2){
		tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	for (i = n1; i <= n2; i++){
		if (i % 3 == 0 || i % 5 == 0){
			sum += i;
			m++;
		}
	}
	//���
	printf("�հ� : %d\n��� : %.1f\n", sum, (float)sum / m);
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int n, i;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����
	for (i = 1; i <= 10; i++)
		printf("%d ", n * i);
	//���
	
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int i = 0;
	char a[] = "I Love You";
	char b[11];
	// �Է�
	
	// ����
	while (a[i] != '\0'){
		b[i] = a[9 - i];
		i++;
	}
	b[10] = '\0';
	//���
	printf("%s�� �Ųٷ� ������ %s�Դϴ�.\n", a, b);
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	char a[100];
	// �Է�
	printf("input : ");
	gets(a);
	// ����

	//���
	printf("%s", a);
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int n, i;
	int arr[80][100];
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����
	for (i = 0; i < n; i++){
		scanf("%s", str[i]);
		printf("%s\n", str[i]);
	}
	//���
	
	//����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	int n, a, b, i, sum = 0;
	int arr[100];
	// �Է�
	printf("input : ");
	scanf("%d %d %d", &n, &a, &b);
	// ����
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if (i >= a && i <= b){
			sum += arr[i - 1];
		}
	}
	//���
	printf("output : %d\n", sum);
	//����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int i, tmp;
	char str[11];
	// �Է�
	printf("input : ");
	scanf("%s", str);
	// ����
	for (i = 0; i <= 4; i++){
		tmp = str[i];
		str[i] = str[9 - i];
		str[9 - i] = tmp;
	}
	str[10] = '\0';
	//���
	printf("%s", str);
	//����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int arr[5], i, sum;
	// �Է�
	printf("input : ");
	for (i = 0; i <= 4; i++)
		scanf("%d", &arr[i]);
	// ����
	sum = arr[0] + arr[2] + arr[4];
	// ���
	printf("%d", sum);
	// ����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int arr[10], i;
	int hole = 0, jack = 0;
	// �Է�
	printf("input : ");
	for (i = 0; i <= 9; i++)
		scanf("%d", &arr[i]);
	// ����
	for (i = 0; i <= 9; i += 2)
		hole = hole + arr[i];
	for (i = 1; i <= 10; i += 2)
		jack = jack + arr[i];
	// ���
	printf("%d %d", hole, jack);
	// ����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int arr[100], i;
	// �Է�
	printf("input : ");
	for (i = 0; i <= 99; i++){
		scanf("%d", &arr[i]);
		if (arr[i] == -1)
			break;
	}
	// ����
	
	// ���
	printf("%d %d %d", arr[i - 3], arr[i - 2], arr[i - 1]);
	// ����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int i;
	float arr[6], sum = 0;
	// �Է�
	printf("input : ");
	for (i = 0; i <= 5; i++)
		scanf("%f", &arr[i]);
	// ����
	for (i = 0; i <= 5; i++)
		sum += arr[i];
	// ���
	printf("%.1f", sum / 6);
	// ����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int i, input;
	int sum[6] = { 0 };
	// �Է�
	printf("input : ");
	for (i = 1; i <= 10; i++){
		scanf("%d", &input);
		sum[input - 1]++;
	}
	// ����

	// ���
	for (i = 0; i <= 5; i++)
		printf("%d�� : %d\n", i + 1, sum[i]);
	// ����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int n, i, j;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����
	for (i = 1; i <= n; i++){
		for (j = 1; j <= i; j++)
			printf("*");
		puts("");
	}
	// ���

	// ����
	return 0;
}
*/
/*
int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int main()
{   // ���� ����
	int a, b;
	// �Է�
	printf("input : ");
	scanf("%d %d", &a, &b);
	// ����

	// ���
	printf("Add : %d\nSub = %d", add(a, b), sub(a, b));
	// ����
	return 0;
}
*/
/*
double average(int a, int b, int c)
{
	return (a + b + c) / 3.0;
}

int main()
{   // ���� ����
	int kor, eng, mat;
	double avg;
	// �Է�
	printf("input : ");
	scanf("%d %d %d", &kor, &eng, &mat);
	// ����
	avg = average(kor, eng, mat);
	// ���
	printf("��� = %.2lf", avg);
	// ����
	return 0;
}
*/
/*
void swapvalue(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;

	printf("First ������ x = %d, y = %d\n", x, y);
}

void swapreference(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;

	printf("Second ������ x = %d, y = %d\n", x, y);
}

int main()
{   // ���� ����
	int a, b;
	// �Է�
	printf("input : ");
	scanf("%d %d", &a, &b);
	// ����
	swapvalue(a, b);
	printf("First ������ a = %d, b = %d\n", a, b);

	swapreference(a, b);
	printf("Second ������ a = %d, b = %d\n", a, b);
	// ���

	// ����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int real_n, n, cnt = 1;
	// �Է�
	scanf("%d", &real_n);
	// ����
	n = real_n;
	while (n != 1)
	{
		cnt++;
		if (n % 2 == 1)
			n = 3 * n + 1;
		else
			n = n / 2;
	}
	n = real_n;
	printf("%d\n%d ", cnt, n);
	while (n != 1)
	{
		if (n % 2 == 1)
			n = 3 * n + 1;
		else
			n = n / 2;
		printf("%d ", n);
	}
	// ���
	puts("");
	// ����
	return 0;
}
*/
/*
void emo(int a)
{
	int i;

	for (i = 1; i <= a; i++)
		puts("~!@#$^&*()_+|");
}

int main()
{   // ���� ����
	int n;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����
	emo(n);
	// ���

	// ����
	return 0;
}
*/
/*
void circle(int r)
{
	float area;

	area = r * r * 3.14;

	printf("%.2f", area);
}

int main()
{   // ���� ����
	int r;
	// �Է�
	printf("input : ");
	scanf("%d", &r);
	// ����
	circle(r);
	// ���

	// ����
	return 0;
}
*/
/*
int num_squ(int a)
{
	int i, j;

	for (i = 1; i <= a * a; i++){
		printf("%d ", i);
		if (i % a == 0)
			puts("");
	}
}

int main()
{   // ���� ����
	int n;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����
	num_squ(n);
	// ���

	// ����
	return 0;
}
*/
/*
int maximum(int a, int b, int c)
{
	int max = 0, i, arr[3];
	
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	

	for (i = 0; i <= 2; i++){
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

int main()
{   // ���� ����
	int a, b, c;
	// �Է�
	printf("input : ");
	scanf("%d %d %d", &a, &b, &c);
	// ����
	
	// ���
	printf("output : %d", maximum(a, b, c));
	// ����
	return 0;
}
*/
/*
int squ(int m, int n)
{
	int tmp = 1, i;

	for (i = 1; i <= n; i++){
		tmp *= m;
	}

	return tmp;
}

int main()
{   // ���� ����
	int m, n;
	// �Է�
	printf("input : ");
	scanf("%d %d", &m, &n);
	// ����

	// ���
	printf("output : %d", squ(m, n));
	// ����
	return 0;
}*/
/*
int gesan(int x, int y, char buho)
{
	if (buho == '+')
		return x + y;
	else if (buho == '-')
		return x - y;
	else if (buho == '*')
		return x * y;
	else if (buho == '/')
		return x / y;

	return 0;
}

int main()
{   // ���� ����
	int a, b;
	char c;
	// �Է�
	printf("input : ");
	scanf("%d %c %d", &a, &c, &b);
	// ����

	// ���
	printf("%d %c %d = %d", a, c, b, gesan(a, b, c));

	return 0;
	// ����
	return 0;
}
*/
/*
//.cpp
void f(int &a, int &b)
{
	if (a >= b){
		a /= 2;
		b *= 2;
	}
	else{
		a *= 2;
		b /= 2;
	}
}

int main()
{   // ���� ����
	int n1, n2;
	// �Է�
	printf("input : ");
	scanf("%d %d", &n1, &n2);
	// ����
	f(n1, n2);
	// ���
	printf("%d %d", n1, n2);
	// ����
	return 0;
}
*/
/*
int n1, n2;

void input()
{
	printf("input : ");
	scanf("%d %d", &n1, &n2);
}

void process()
{
	int i, j;

	for (i = n1; i <= n2; i++){
		printf("== %d�� ==\n", i);
		for (j = 1; j <= 9; j++){
			printf("%d * %d = %d\n", i, j, i * j);
		}
		puts("");
	}
}

int main()
{   // ���� ����

	// �Է�
	input();
	// ����
	process();
	// ���

	// ����
	return 0;
	}
	*/
/*
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

void sort(int arr[], int cnt)
{
int i, j;
for (i = 0; i < cnt - 1; i++){
for (j = i + 1; j < cnt; j++){
if (arr[i] > arr[j])
swap(&arr[i], &arr[j]);
}
}

}

int main()
{   // ���� ����
int i, arr[6];
// �Է�
for (i = 0; i < 6; i++)
scanf("%d", &arr[i]);
// ����
sort(arr, 6);
// ���
for (i = 0; i < 6; i++)
printf("%d ", arr[i]);
// ����
return 0;
}
*/
/*
void input(int a[], int cnt)
{
int i;

printf("%d������ ������ �Է��ϼ��� : ", cnt);
for (i = 0; i < cnt; i++) scanf("%d", &a[i]);
}

int pass(int a[], int cnt)
{
int i, sum = 0, avg;

for (i = 0; i < cnt; i++){
if (a[i] < 40) return 0;
sum += a[i];
}

avg = sum / cnt;

if (avg < 60) return 0;
return 1;
}

int main()
{   // ���� ����
int score[3];
// �Է�
input(score, 3);
// ����
if (pass(score, 3)) printf("�����մϴ�. �հ��Դϴ�. ");
else printf("�˼��մϴ�. ���հ��Դϴ�. ");
// ���

// ����
return 0;
}*/
/*
#include <math.h>
#define PIE 3.14

int main()
{   // ���� ����
double radius, area;
// �Է�
printf("������ : ");
scanf("%lf", &radius);
// ����
area = pow(radius, 2) * PIE;
// ���
printf("���� ����\n");
printf("���� : %.0f\n", floor(area));
printf("�ݿø� : %.0f\n", area);
printf("�ø� : %.0f\n", ceil(area));
// ����
return 0;
}
*/
/*
#define N 5

void sort(int a[], int cnt)
{
	int i, j;
	for (i = cnt - 1; i > 0; i--){
		for (j = 0; j < i; j++){
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{   // ���� ����
	int arr[N], i;
	// �Է�
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	// ����
	sort(arr, N);
	// ���
	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	// ����
	return 0;
}
*/
/*
#include <stdlib.h>

int main()
{   // ���� ����
	int i, a, sum = 0;
	// �Է�
	printf("input : ");
	
	// ����
	for (i = 0; i < 5; i++){
		scanf("%d", &a);
		sum += abs(a);
	}
	// ���
	printf("%d", sum);
	// ����
	return 0;
}
*/
/*
int fac(int n)
{
	if (n <= 1) return 1;
	return n * fac(n - 1);
}

int main()
{   // ���� ����
	int n;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����

	// ���
	printf("output : %d\n", fac(n));
	// ����
	return 0;
}
*/
/*
int sum(int n)
{
	if (n <= 1) return 1;
	return n + sum(n - 1);
}

int main()
{   // ���� ����
	int n;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	// ����

	// ���
	printf("output : %d\n", sum(n));
	// ����
	return 0;
}
*/
/*
int main()
{   // ���� ����
	int std[30], ans[30], n, i, sum = 0;
	// �Է�
	printf("input : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &std[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &ans[i]);
	// ����
	for (i = 0; i < n; i++){
		if (std[i] == ans[i]) sum++;
	}
	// ���
	printf("output : %d\n", sum);
	// ����
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // ���� ����
	char str[80];
	int n;
	// �Է�
	printf("input : ");
	scanf("%s %d", str, &n);
	// ����

	// ���
	for (int i = 0; i < n; i++)
		printf("%c", str[strlen(str)-1-i]);
	// ����
	return 0;
}
*/
/*
#include <ctype.h>
#include <conio.h>

int main()
{   // ���� ����
	char ch;
	while (1){
		// �Է�
		ch = getch();
		// ����
		if (isupper(ch)) printf("large\n");
		else if (islower(ch)) printf("small\n");
		else if (isdigit(ch)) printf("number\n");
		else { printf("noting"); break; }
		// ���
	}
	// ����
	return 0;
}
*/
/*
#include <string.h>

struct score
{
	char name[20];
	int kor, eng;
};

int main()
{   // ���� ����
	struct score a, b, sum;
	// �Է�
	scanf("%s %d %d", a.name, &a.kor, &a.eng);
	scanf("%s %d %d", b.name, &b.kor, &b.eng);
	
	strcpy(sum.name, "�հ�");
	sum.kor = a.kor + b.kor;
	sum.eng = a.eng + b.eng;
	// ����
	
	// ���
	puts("");
	printf("%s %d %d\n", a.name, a.kor, a.eng);
	printf("%s %d %d\n", b.name, b.kor, b.eng);
	printf("%s %d %d\n", sum.name, sum.kor, sum.eng);
	// ����
	return 0;
}
*/
/*
#include <string.h>

struct point
{
	double x, y;
}p1, p2, p3;

struct point center(struct point a, struct point b)
{
	struct point c;
	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;
	return c;
}

int main()
{
	printf("���� ��ǥ�� �Է��Ͻÿ� : ");
	scanf("%lf %lf", &p1.x, &p1.y);
	printf("���� ��ǥ�� �Է��Ͻÿ� : ");
	scanf("%lf %lf", &p2.x, &p2.y);
	p3 = center(p1, p2);
	printf("�߽����� ��ġ�� (%.1lf,%.1lf)�Դϴ�.\n", p3.x, p3.y);
	return 0;
}
*/
/*
struct point
{
	double x, y;
}p1, p2, p3, cp;

struct point center(struct point a, struct point b, struct point c)
{
	struct point d;
	d.x = (a.x + b.x + c.x) / 3;
	d.y = (a.y + b.y + c.y) / 3;
	return d;
}

int main()
{
	printf("���� ��ǥ�� �Է��Ͻÿ� : ");
	scanf("%lf %lf", &p1.x, &p1.y);
	printf("���� ��ǥ�� �Է��Ͻÿ� : ");
	scanf("%lf %lf", &p2.x, &p2.y);
	printf("���� ��ǥ�� �Է��Ͻÿ� : ");
	scanf("%lf %lf", &p3.x, &p3.y);
	cp = center(p1, p2, p3);
	printf("�����߽��� ��ġ�� (%.1lf,%.1lf)�Դϴ�.\n", cp.x, cp.y);
	return 0;
}
*/

#include <string.h>
struct student
{
	char name[20];
	int height;
	double weight;
};

void swap(struct student *a, struct student *b)
{
	struct student temp = *a;
	*a = *b;
	*b = temp;
}

void sort(struct student arr[])
{
	for (int i = 0; i < 4; i++){
		for (int j = i + 1; j < 5; j++){
			if (arr[i].height > arr[j].height)
				swap(&arr[i], &arr[j]);
		}
	}
}

int main()
{
	struct student people[5];
	printf("input\n");
	for (int i = 0; i < 5; i++) scanf("%s %d %lf", people[i].name, &people[i].height, &people[i].weight);

	sort(people);

	printf("output\n");
	for (int i = 0; i < 5; i++) printf("%s %d %.1lf\n", people[i].name, people[i].height, people[i].weight);
}