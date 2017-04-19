#include <stdio.h>

main()
{
	int arr[50], i, cnt = 0, input;

	scanf("%d", &input);

	for (i = 0; input != 0; i++){
		arr[i] = input % 2;
		input = input / 2;
	}
	for (; i > 0; i--)
		printf("%d", arr[i-1]);
}