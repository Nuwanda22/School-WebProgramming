#include <stdio.h>

int main(int argc, char *argv[])
{
	char c;			// 읽어지고 출력되는 문자
	FILE *input;		// 입력되는 윈도우 파일
	FILE *output;		// 출력되는 리눅스 파일
	
	input = fopen(argv[1], "r");	// 입력 파일을 읽기 모드로 연다.
	if(input == NULL){		// 만약 입력 파일을 못 읽으면
		perror(argv[1]);	// 에러 메시지 출력 후
		return -1;		// 종료한다.
	}
	output = fopen(argv[2], "w");	// 출력 파일을 쓰기 모드로 연다.
	if(output == NULL){		// 만약 출력 파일을 못 만드면
		perror(argv[2]);	// 에러 메시지 출력 후
		return -1;		// 종료한다.
	}

	c = fgetc(input);				// 일단 한 글자 읽고
	while(c != EOF){				// 파일의 끝까지
		if(c == '\r') c = fgetc(input);		// (만약  그 글자가 \r이면 바로 다음 글자를 읽음, 이렇게 되면 \r\n -> \n이 됨) 
		fputc(c, output);			// 출력 파일에 한 글자씩 출력한다.
		c = fgetc(input);			// 그리고 다시 한 글자 읽는다.
	}
	fcloseall();		// 마지막으로 모든 스트림을 닫고
	return 0;		// 종료한다.
}

