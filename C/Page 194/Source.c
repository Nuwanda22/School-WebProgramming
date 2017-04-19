#include <stdio.h>

int main()
{
	puts(__DATE__);
	puts(__TIME__);
	printf("%d\n",__LINE__);
	puts(__FILE__);

	int num[5], i, j, temp;

	for (i = 0; i < 5; i++) scanf("%d", &num[i]);

	for (i = 0; i < 4; i++){
		for (j = i + 1; j < 5; j++){
			if (num[i] > num[j]){
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	for (i = 0; i < 5; i++) printf("%d ", num[i]);
	return 0;
}