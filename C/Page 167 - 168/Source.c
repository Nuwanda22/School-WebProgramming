#include <stdio.h>

#define WIDHT  1024
#define HEIGHT 768
#define HEADER 54

unsigned char R[HEIGHT][WIDHT], G[HEIGHT][WIDHT], B[HEIGHT][WIDHT];

int main()
{
	FILE *fp1 = fopen("1024_768.bmp", "rb");
	FILE *fp2 = fopen("1024_768_2.bmp", "wb");

	FILE *fp3 = fopen("1024_768.bmp", "rb");
	FILE *fp4 = fopen("1024_768_3.bmp", "wb");

	int i, j;

	for (i = 0; i < HEADER; i++)
		putc(getc(fp1), fp2);

	for (i = 0; i < HEIGHT; i++){
		for (j = 0; j < WIDHT; j++){
			B[i][j] = getc(fp1);
			G[i][j] = getc(fp1);
			R[i][j] = getc(fp1);
		}
	}

	for (i = 0; i < HEIGHT; i++){
		for (j = 0; j < WIDHT; j++){
			putc(B[i][j], fp2);
			putc(G[i][j], fp2);
			putc(R[i][j], fp2);
		}
	}

	for (i = 0; i < HEADER; i++)
		putc(getc(fp3), fp4);

	for (i = 0; i < HEIGHT; i++){
		for (j = 0; j < WIDHT; j++){
			putc((B[i][j] + G[i][j] + R[i][j]) / 3, fp4);
			putc((B[i][j] + G[i][j] + R[i][j]) / 3, fp4);
			putc((B[i][j] + G[i][j] + R[i][j]) / 3, fp4);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);

	return 0;
}