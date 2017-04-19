#include <stdio.h>

/*
int main()
{   // 변수 선언

	// 입력
	printf("input : ");
	scanf("%d", &);
	// 연산

	// 출력

	// 종료
	return 0;
}
*/
/*

int main()
{   // 변수 선언
	int N;
	int hole = 0, jack = 0;
	// 입력

	// 연산
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
	//출력
	printf("홀수 : %d\n짝수 : %d\n", hole, jack);
	//종료
	return 0;
}
*/
/*
#include <stdio.h> 

int main()
{   // 변수 선언
	int N, i=1;
	int sum = 0;
	float avg = 0;
	// 입력
	
	//입력 및 연산
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

	//출력
	printf("\n합계 : %d개\n평균 : %.1f개\n", sum, avg);
	//종료
	return 0;
}
*/
/*
#include <stdio.h> 

int main()
{   // 변수 선언
	int N, baesu = 0;
	// 입력
	
	// 연산
	while (1){
		scanf("%d", &N);
		if (N != 0){
			if (N % 3 == 0 || N % 5 == 0)
				baesu++;
		}
		else
			break;
	}
	//출력
	printf("%d\n", baesu);
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int under, high;
	float neolbi;
	char one_more;
	// 입력

	// 연산
	while (1){
		printf("밑변 : ");
		scanf("%d", &under);
		printf("높이 : ");
		scanf("%d", &high);

		neolbi = 1 / 2.0 * under * high;

		printf("입력한 삼각형의 넓이는 %.1f입니다. \n", neolbi);
		printf("계속하시겠습니까? : ");
		scanf(" %c", &one_more);

		if (one_more == 'Y' || one_more == 'y')
			continue;
		else
			break;
	}
	//출력

	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int i, n;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산
	for (i = 0; i < n; i++)
		puts("홍길동");
	//출력

	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int i, tmp;
	int num1, num2;
	// 입력
	printf("input : ");
	scanf("%d%d", &num1, &num2);
	// 연산
	if (num1 > num2){
		tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	for (; num1 <= num2; num1++)
		printf("%d ", num1);
	//출력

	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int N, i;
	int sum = 0;
	// 입력
	printf("input : ");
	scanf("%d", &N);
	// 연산
	for (i = 1; i <= N; i++){
		if (i % 5 == 0)
			sum += i;
	}
	//출력
	printf("%d\n", sum);
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int n, m, i, sum = 0;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산
	for (i = 1; i <= n; i++){
		scanf("%d", &m);
		sum += m;
	}
	//출력
	printf("%.2f", (float)sum / n);
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int n, i;
	int hole = 0, jack = 0;
	// 입력
	printf("input : ");
	// 연산
	for (i = 1; i <= 10; i++){
		scanf("%d", &n);
		if (n % 2 == 0)
			jack++;
		else
			hole++;
	}
	//출력
	printf("짝수 : %d\n홀수 : %d\n", jack, hole);
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int n1, n2, i;
	int m = 0, tmp, sum = 0;
	// 입력
	printf("input : ");
	scanf("%d %d", &n1, &n2);
	// 연산
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
	//출력
	printf("합계 : %d\n평균 : %.1f\n", sum, (float)sum / m);
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int n, i;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산
	for (i = 1; i <= 10; i++)
		printf("%d ", n * i);
	//출력
	
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int i = 0;
	char a[] = "I Love You";
	char b[11];
	// 입력
	
	// 연산
	while (a[i] != '\0'){
		b[i] = a[9 - i];
		i++;
	}
	b[10] = '\0';
	//출력
	printf("%s는 거꾸로 읽으면 %s입니다.\n", a, b);
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	char a[100];
	// 입력
	printf("input : ");
	gets(a);
	// 연산

	//출력
	printf("%s", a);
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int n, i;
	int arr[80][100];
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산
	for (i = 0; i < n; i++){
		scanf("%s", str[i]);
		printf("%s\n", str[i]);
	}
	//출력
	
	//종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	int n, a, b, i, sum = 0;
	int arr[100];
	// 입력
	printf("input : ");
	scanf("%d %d %d", &n, &a, &b);
	// 연산
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if (i >= a && i <= b){
			sum += arr[i - 1];
		}
	}
	//출력
	printf("output : %d\n", sum);
	//종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int i, tmp;
	char str[11];
	// 입력
	printf("input : ");
	scanf("%s", str);
	// 연산
	for (i = 0; i <= 4; i++){
		tmp = str[i];
		str[i] = str[9 - i];
		str[9 - i] = tmp;
	}
	str[10] = '\0';
	//출력
	printf("%s", str);
	//종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int arr[5], i, sum;
	// 입력
	printf("input : ");
	for (i = 0; i <= 4; i++)
		scanf("%d", &arr[i]);
	// 연산
	sum = arr[0] + arr[2] + arr[4];
	// 출력
	printf("%d", sum);
	// 종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int arr[10], i;
	int hole = 0, jack = 0;
	// 입력
	printf("input : ");
	for (i = 0; i <= 9; i++)
		scanf("%d", &arr[i]);
	// 연산
	for (i = 0; i <= 9; i += 2)
		hole = hole + arr[i];
	for (i = 1; i <= 10; i += 2)
		jack = jack + arr[i];
	// 출력
	printf("%d %d", hole, jack);
	// 종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int arr[100], i;
	// 입력
	printf("input : ");
	for (i = 0; i <= 99; i++){
		scanf("%d", &arr[i]);
		if (arr[i] == -1)
			break;
	}
	// 연산
	
	// 출력
	printf("%d %d %d", arr[i - 3], arr[i - 2], arr[i - 1]);
	// 종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int i;
	float arr[6], sum = 0;
	// 입력
	printf("input : ");
	for (i = 0; i <= 5; i++)
		scanf("%f", &arr[i]);
	// 연산
	for (i = 0; i <= 5; i++)
		sum += arr[i];
	// 출력
	printf("%.1f", sum / 6);
	// 종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int i, input;
	int sum[6] = { 0 };
	// 입력
	printf("input : ");
	for (i = 1; i <= 10; i++){
		scanf("%d", &input);
		sum[input - 1]++;
	}
	// 연산

	// 출력
	for (i = 0; i <= 5; i++)
		printf("%d번 : %d\n", i + 1, sum[i]);
	// 종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int n, i, j;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산
	for (i = 1; i <= n; i++){
		for (j = 1; j <= i; j++)
			printf("*");
		puts("");
	}
	// 출력

	// 종료
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
{   // 변수 선언
	int a, b;
	// 입력
	printf("input : ");
	scanf("%d %d", &a, &b);
	// 연산

	// 출력
	printf("Add : %d\nSub = %d", add(a, b), sub(a, b));
	// 종료
	return 0;
}
*/
/*
double average(int a, int b, int c)
{
	return (a + b + c) / 3.0;
}

int main()
{   // 변수 선언
	int kor, eng, mat;
	double avg;
	// 입력
	printf("input : ");
	scanf("%d %d %d", &kor, &eng, &mat);
	// 연산
	avg = average(kor, eng, mat);
	// 출력
	printf("평균 = %.2lf", avg);
	// 종료
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

	printf("First 실행전 x = %d, y = %d\n", x, y);
}

void swapreference(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;

	printf("Second 실행전 x = %d, y = %d\n", x, y);
}

int main()
{   // 변수 선언
	int a, b;
	// 입력
	printf("input : ");
	scanf("%d %d", &a, &b);
	// 연산
	swapvalue(a, b);
	printf("First 실행후 a = %d, b = %d\n", a, b);

	swapreference(a, b);
	printf("Second 실행후 a = %d, b = %d\n", a, b);
	// 출력

	// 종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int real_n, n, cnt = 1;
	// 입력
	scanf("%d", &real_n);
	// 연산
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
	// 출력
	puts("");
	// 종료
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
{   // 변수 선언
	int n;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산
	emo(n);
	// 출력

	// 종료
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
{   // 변수 선언
	int r;
	// 입력
	printf("input : ");
	scanf("%d", &r);
	// 연산
	circle(r);
	// 출력

	// 종료
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
{   // 변수 선언
	int n;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산
	num_squ(n);
	// 출력

	// 종료
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
{   // 변수 선언
	int a, b, c;
	// 입력
	printf("input : ");
	scanf("%d %d %d", &a, &b, &c);
	// 연산
	
	// 출력
	printf("output : %d", maximum(a, b, c));
	// 종료
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
{   // 변수 선언
	int m, n;
	// 입력
	printf("input : ");
	scanf("%d %d", &m, &n);
	// 연산

	// 출력
	printf("output : %d", squ(m, n));
	// 종료
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
{   // 변수 선언
	int a, b;
	char c;
	// 입력
	printf("input : ");
	scanf("%d %c %d", &a, &c, &b);
	// 연산

	// 출력
	printf("%d %c %d = %d", a, c, b, gesan(a, b, c));

	return 0;
	// 종료
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
{   // 변수 선언
	int n1, n2;
	// 입력
	printf("input : ");
	scanf("%d %d", &n1, &n2);
	// 연산
	f(n1, n2);
	// 출력
	printf("%d %d", n1, n2);
	// 종료
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
		printf("== %d단 ==\n", i);
		for (j = 1; j <= 9; j++){
			printf("%d * %d = %d\n", i, j, i * j);
		}
		puts("");
	}
}

int main()
{   // 변수 선언

	// 입력
	input();
	// 연산
	process();
	// 출력

	// 종료
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
{   // 변수 선언
int i, arr[6];
// 입력
for (i = 0; i < 6; i++)
scanf("%d", &arr[i]);
// 연산
sort(arr, 6);
// 출력
for (i = 0; i < 6; i++)
printf("%d ", arr[i]);
// 종료
return 0;
}
*/
/*
void input(int a[], int cnt)
{
int i;

printf("%d과목의 점수를 입력하세요 : ", cnt);
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
{   // 변수 선언
int score[3];
// 입력
input(score, 3);
// 연산
if (pass(score, 3)) printf("축하합니다. 합격입니다. ");
else printf("죄송합니다. 불합격입니다. ");
// 출력

// 종료
return 0;
}*/
/*
#include <math.h>
#define PIE 3.14

int main()
{   // 변수 선언
double radius, area;
// 입력
printf("반지름 : ");
scanf("%lf", &radius);
// 연산
area = pow(radius, 2) * PIE;
// 출력
printf("원의 넓이\n");
printf("버림 : %.0f\n", floor(area));
printf("반올림 : %.0f\n", area);
printf("올림 : %.0f\n", ceil(area));
// 종료
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
{   // 변수 선언
	int arr[N], i;
	// 입력
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	// 연산
	sort(arr, N);
	// 출력
	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	// 종료
	return 0;
}
*/
/*
#include <stdlib.h>

int main()
{   // 변수 선언
	int i, a, sum = 0;
	// 입력
	printf("input : ");
	
	// 연산
	for (i = 0; i < 5; i++){
		scanf("%d", &a);
		sum += abs(a);
	}
	// 출력
	printf("%d", sum);
	// 종료
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
{   // 변수 선언
	int n;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산

	// 출력
	printf("output : %d\n", fac(n));
	// 종료
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
{   // 변수 선언
	int n;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	// 연산

	// 출력
	printf("output : %d\n", sum(n));
	// 종료
	return 0;
}
*/
/*
int main()
{   // 변수 선언
	int std[30], ans[30], n, i, sum = 0;
	// 입력
	printf("input : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &std[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &ans[i]);
	// 연산
	for (i = 0; i < n; i++){
		if (std[i] == ans[i]) sum++;
	}
	// 출력
	printf("output : %d\n", sum);
	// 종료
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{   // 변수 선언
	char str[80];
	int n;
	// 입력
	printf("input : ");
	scanf("%s %d", str, &n);
	// 연산

	// 출력
	for (int i = 0; i < n; i++)
		printf("%c", str[strlen(str)-1-i]);
	// 종료
	return 0;
}
*/
/*
#include <ctype.h>
#include <conio.h>

int main()
{   // 변수 선언
	char ch;
	while (1){
		// 입력
		ch = getch();
		// 연산
		if (isupper(ch)) printf("large\n");
		else if (islower(ch)) printf("small\n");
		else if (isdigit(ch)) printf("number\n");
		else { printf("noting"); break; }
		// 출력
	}
	// 종료
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
{   // 변수 선언
	struct score a, b, sum;
	// 입력
	scanf("%s %d %d", a.name, &a.kor, &a.eng);
	scanf("%s %d %d", b.name, &b.kor, &b.eng);
	
	strcpy(sum.name, "합계");
	sum.kor = a.kor + b.kor;
	sum.eng = a.eng + b.eng;
	// 연산
	
	// 출력
	puts("");
	printf("%s %d %d\n", a.name, a.kor, a.eng);
	printf("%s %d %d\n", b.name, b.kor, b.eng);
	printf("%s %d %d\n", sum.name, sum.kor, sum.eng);
	// 종료
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
	printf("점의 좌표를 입력하시오 : ");
	scanf("%lf %lf", &p1.x, &p1.y);
	printf("점의 좌표를 입력하시오 : ");
	scanf("%lf %lf", &p2.x, &p2.y);
	p3 = center(p1, p2);
	printf("중심점의 위치는 (%.1lf,%.1lf)입니다.\n", p3.x, p3.y);
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
	printf("점의 좌표를 입력하시오 : ");
	scanf("%lf %lf", &p1.x, &p1.y);
	printf("점의 좌표를 입력하시오 : ");
	scanf("%lf %lf", &p2.x, &p2.y);
	printf("점의 좌표를 입력하시오 : ");
	scanf("%lf %lf", &p3.x, &p3.y);
	cp = center(p1, p2, p3);
	printf("무게중심의 위치는 (%.1lf,%.1lf)입니다.\n", cp.x, cp.y);
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