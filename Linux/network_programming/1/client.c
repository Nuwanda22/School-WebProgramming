#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 1024

void check(char *str, int size)
{
	int i;
	for(i = 0; i < size; i++){
		if(str[i] == '\n'){
			str[i] = '\0';
		}
	}
}

int main(int argc, char **argv)
{
	struct sockaddr_in serveraddr;	// 서버 주소
	int server_sockfd;	// 서버 소켓 파일 디스크립터
	int client_len;		// 클라 길이
	char buf[MAXLINE];	// 버퍼

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
	int portno = atoi(argv[2]);
	serveraddr.sin_port = htons(portno);			// 3500
	client_len = sizeof(serveraddr);
	
	// 연결
	if(connect(server_sockfd, (struct sockaddr *)&serveraddr, client_len) == -1){
		perror("connet error");
		return 1;
	}
	
	while(1){
		// 버퍼 초기화
		memset(buf, 0, MAXLINE);
		// 입력 받고
		fflush(stdin);
		fgets(buf, MAXLINE, stdin);
		check(buf, strlen(buf));
		// 서버에 쓰기
		if(write(server_sockfd, buf, MAXLINE) <= 0){
			perror("write error");
			return 1;
		}
		if(strcmp(buf, "Bye")==0){
			break;
		}
	}
	close(server_sockfd);
	return 0;
}