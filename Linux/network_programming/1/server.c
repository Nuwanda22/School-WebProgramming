#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUF 1024

int main(int argc, char **argv)
{
	int server_sockfd;	// 서버 소켓 파일 디스크립터
	int client_sockfd;	// 클라 소켓 파일 디스크립터
	
	int n;
	int loop = 0;
	char buf[MAXBUF];	// 버퍼
	
	struct sockaddr_in clientaddr;	// 클라 주소
	struct sockaddr_in serveraddr;	// 서버 주소
	
	int client_len = sizeof(clientaddr);	// 클라 길이
	
	// 인자가 모자라면 종료
	if(argc < 2){
		puts("Help: server protno");
		return 1;
	}
	// 서버 소켓 만들고 저장 오류나면 종료
	if((server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
		perror("socket error");
		exit(0);
	}
	
	// serveraddr 초기화
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(argv[1]));
	
	// 바인드하고 리슨
	bind(server_sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
	listen(server_sockfd, 5);
	
	loop = 0;
	while(loop == 0){
		// 클라 소켓 받아옴
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr, &client_len);
		printf("New Client Connet: %s\n", inet_ntoa(clientaddr.sin_addr));
	
		// 클라에서 읽어서 버퍼에 저장
		while(1){
			// 버퍼 초기화
			memset(buf, 0, MAXBUF);
			if((n = read(client_sockfd, buf, MAXBUF)) <= 0){
				close(client_sockfd);
				break;
			}
			puts(buf);
			if(strcmp(buf, "Bye") == 0){
				close(client_sockfd);
				loop = 1;
				break;
			}
		}
	}
	close(server_sockfd);
	return 0;
}