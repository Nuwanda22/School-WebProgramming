#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "calc.h"

#define PORT 7777

void input(Data *buf)
{
	fflush(stdin);
	scanf("%lf %c %lf", &buf->operand[0], &buf->op, &buf->operand[1]);
}

int main(int argc, char **argv)
{
	struct sockaddr_in serveraddr;	// 서버 주소
	int server_sockfd;	// 서버 소켓 파일 디스크립터
	int client_len;		// 클라 길이
	Data buf;			// 버퍼

	// 인자 부족하면 종료
	if(argc < 2){
		printf("Help: client ipaddr protno\n");
		return 1;
	}
	if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("error");
		return 1;
	}

	// 초기화
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);// 127.0.0.1
	serveraddr.sin_port = htons(PORT);
	client_len = sizeof(serveraddr);
	
	// 연결
	if(connect(server_sockfd, (struct sockaddr *)&serveraddr, client_len) == -1){
		perror("connet error");
		return 1;
	}
	
	while(1){
		// 버퍼 초기화
		memset(&buf.op, 0, sizeof(Data));
		// 입력 받고
		input((Data *)&buf.op);
		//input(&buf);

		// 서버에 쓰기
		if(send(server_sockfd, &buf.op, sizeof(Data), 0) == -1){
			perror("write error");
			return 1;
		}
		if(buf.op == 'q'){	// 종료
			break;
		}
		if(recv(server_sockfd, &buf.op, sizeof(Data), 0) == -1){
			perror("recv error");
			return 1;
		}
		if(buf.error == 0){
			printf("result = %lf\n", buf.result);
		}
		else if(buf.error == -1){
			puts("calculate: wrong operator");
		}
		else {
			puts("asddfgasd");
		}
	}
	close(server_sockfd);
	return 0;
}