/*
#include <stdio.h>

int main()
{
	int n, i;

	scanf("%d", &n);

	if (n == 1){
		puts("�� �� �ƴ�");
		return 0;
	}

	for (i = 2; i < n - 1; i++){
		if (n % i == 0){
			puts("�ռ�����");
			return 0;
		}
	}
	puts("�Ҽ���");
	return 0;
}
*/

#include <stdio.h>

main()
{
	int n, i;
	int tmp = 0;

	scanf("%d", &n);
	
	if (n == 1)
		goto tmp;
	
	for (i = 1; i < n; i++){
		if (n % i == 0)
			tmp++;
	}

	tmp:
	if (tmp == 2 || tmp == 0)
		puts("�Ҽ��� �ƴ�");
	else
		puts("�Ҽ���");
}