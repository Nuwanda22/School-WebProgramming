// icr program
// Linux text file to Windows text file
//
// Author 전성우
// 2015. 12. 17.

#include <stdio.h>

int main(int argc, char *argv[])
{
	// 인자가 부족하면 종료
	if(argc != 3){
		printf("test: 인자가 부족합니다.");
		return -1;
	}

	FILE *input;	// 리눅스 파일
	FILE *output;	// 윈도우 파일
	char ch[2];

	input = fopen(argv[1], "r");	// 읽기 모드
	if(input == NULL){		// 열리지 않으면 종료
		perror(argv[1]);
		return -1;
	}

	output = fopen(argv[2], "w");	// 쓰기 모드
	if(input == NULL){		// 열리지 않으면 종료
		perror(argv[2]);
		return -1;
	}

	while(1){
		ch[0] = fgetc(input);	// 읽고
		if(ch[0] == EOF) break;	// 파일 끝이면 종료
		
		ch[1] = fgetc(input);	// 하나 더 읽고
		if(ch[1] == EOF){	// 파일 끝이면
			fputc(ch[0], output);	// 전에 읽은 거 쓰고 종료
			break;
		}
		else if(ch[0] == '\r' && ch[1] == '\n'){ // \r\n이면 두 글자 그대로 출력
			fputc(ch[0], output);
			fputc(ch[1], output);
		}
		else{				// 위 경우가 모두 아니면
			fputc(ch[0], output);	// 읽은 거 출력하고
			ungetc(ch[1], input);	// 한 글자 읽은 거 되돌림
		}
        }
	fcloseall();	// 다 닫고 종료
	return 0;
}
