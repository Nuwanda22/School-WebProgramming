#include <stdio.h>
#include <string.h>

int jegob(int a, int b)
{
	int i, sum = 1;

	for (i = 1; i <= b; i++){
		sum = sum * a;
	}

	return sum;
}

// 2���� 11001�� ���� ��

main()
{
	//�Լ� X
	int arr[5] = { 1, 1, 0, 0, 1 };
	int i, j, sum1 = 0, sum2;

	for (i = 0; i <= 4; i++){
		sum2 = 1;
		if (arr[i] == 1){
			for (j = 1; j <= 4 - i; j++){
				sum2 *= 2;
			}
			sum1 += sum2;
		}
	}
	printf("%d", sum1);
}


// �Լ� O
/*
main()
{
	int arr[5] = { 1, 1, 0, 0, 1 };
	int i, sum = 0;

	for (i = 0; i <= 4 ; i++){
		if (arr[i] == 1){
			sum += jegob(2, 4 - i);
		}
	}
	printf("%d", sum);
}
*/

// �Է� ���� ��
/*
int main()
{
	int i, j, sum = 0;
	char input[100];

	printf("input : ");
	scanf("%s", input);
	
	i = 0;
	for (j = strlen(input); j > 0; j--){
		if (input[i] == 49){
			sum += jegob(2, j - 1);
		}
		i++;
	}
	printf("output(use strlen()) : %d\n", sum);
	
	sum = 0;
	j = 0;
	for (i = 0; input[i] != '\0'; i++)
		j++;
	for (i = 0; input[i] != '\0'; i++){
		if (input[i] == 49)
			sum += jegob(2, j - 1);
		j--;
	}
	printf("output(don't use it) : %d\n", sum);
}
*/