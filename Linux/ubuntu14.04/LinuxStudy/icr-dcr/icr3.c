// icr program
// Linux text file to Windows text file
//
// Author 전성우
// 2015. 12. 26

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
	int ch;
	int temp;

	input = fopen(argv[1], "r"); 	// 읽기 모드
	if(input == NULL){		// 열리지 않으면 종료
		perror(argv[1]);
		return -1;
	}

	output = fopen(argv[2], "w");	// 쓰기 모드
	if(input == NULL){		// 열리지 않으면 종료
		perror(argv[2]);
		return -1;
	}

	while((ch = fgetc(input)) != EOF){
		if(ch == '\n'){				// 읽은 게 \n이라면
			fputc('\r', output);		// \r\n으로 씀
			fputc(ch, output);
		}
		else if(ch == '\r'){			// 읽은 게 \r이라면		
			temp = fgetc(input);		// 하나 더 읽고
			if(temp == EOF){		// 파일 끝이면 
				fputc(ch, output);	// 전에 읽은 거 쓰고 종료
				break;
			}
			else if(temp == '\n'){		// \n이면 그대로 \r\n 쓰고
				fputc(ch, output);
				fputc(temp, output);
			}
			else{				// 아니면 전에 읽은 거 쓰고 되돌리고
				fputc(ch, output);
				ungetc(temp, input);
			}
		}
		else{				// 위 경우가 모두 아니면
			fputc(ch, output);	// 읽은 거 출력하고
		}
        } 
	fcloseall();	// 다 닫고 종료
	return 0;
}
