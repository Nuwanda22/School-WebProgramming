#include <stdio.h>

main()
{
	int one, two, i, tmp;

	//�� Ǯ��
	one = 1, two = 1;

	printf("%d %d ", one, two);
	
	for (i = 3; i <= 20; i++){
		two = one + two;
		printf("%d ", two);

		tmp = one;
		one = two;
		two = tmp;
	}
	puts("\n");
	//������
	one = 1, two = 1;

	printf("%d %d ", one, two);

	for (i = 3; i <= 20; i++){
		tmp = one + two;
		printf("%d ", tmp);

		one = two;
		two = tmp;
	}
	puts("\n");
	//����� Ǯ��
	one = 1, two = 1;

	printf("%d %d ", one, two);

	for (i = 3; i <= 20; i++){
		two += one;
		one = two - one;
		printf("%d ", two);
	}
	puts("\n");
}