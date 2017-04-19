#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 3){
		printf("test: 인자가 부족합니다.");
		return -1;
	}

	FILE *input;
	FILE *output;
	char ch[2];

	input = fopen(argv[1], "r");
	if(input == NULL){
		perror(argv[1]);
		return -1;
	}

	output = fopen(argv[2], "w");
	if(input == NULL){
		perror(argv[1]);
		return -1;
	}

	while(1){
		ch[0] = fgetc(input);
		if(ch[0] == EOF) break;
		
		ch[1] = fgetc(input);
		if(ch[1] == EOF){
			fputc(ch[0], output);
			break;
		}
		else if(ch[0] == '\r' && ch[1] == '\n')	
			fputc(ch[1], output);
		else{
			fputc(ch[0], output);
			ungetc(ch[1], input);
		}
        }
	fcloseall();
	return 0;
}
