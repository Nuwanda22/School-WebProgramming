#include <stdio.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
	FILE *fp1 = fopen("csv_file.csv", "w");

	int i, j, n = 1;

	for (i = 1; i <= HEIGHT; i++){
		for (j = 1; j <= WIDTH; j++){
			fprintf(fp1, "%d", n++);
			if (j != WIDTH)
				fprintf(fp1, ",");
		}
		fprintf(fp1, "\n");
	}
	fclose(fp1);
	return 0;
}