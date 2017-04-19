#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT 7777		// 포트 번호
#define MAXPENDING 5	// 클라
#define BUFSIZE 1024

int main(int argc, char **argv)
{
	int server_sockfd;	// 서버 소켓 파일 디스크립터
	int client_sockfd;	// 클라 소켓 파일 디스크립터
	
	struct sockaddr_in clientaddr;	// 클라 주소
	struct sockaddr_in serveraddr;	// 서버 주소
	
	char recvBuf[BUFSIZE];	// 버퍼
	
	int client_len; // 클라 길이
	int recv_len;
	
	pid_t pid;

	// 서버 소켓 만들고 저장 오류나면 종료
	if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket error");
		exit(1);
	}
	
	// serveraddr 초기화
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(argv[1]));
	
	// 바인드
	if(bind(server_sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1){
		perror("bind error");
		exit(1);
	}
	
	// 리슨
	if(listen(server_sockfd, MAXPENDING) == -1){
		perror("listen error");
		exit(1);
	}
	
	while(1){
		client_len = sizeof(clientaddr);
		// 클라 소켓 받아옴
		if((client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr, &client_len)) == -1){
			perror("accept error");
			exit(1);
		}
		printf("\n  port =  %d  %s\n", clientaddr.sin_port, inet_ntoa(clientaddr.sin_addr));
		
		if((pid = fork()) == -1){
			perror("fork error");
			exit(1);
		}
		else if(pid == 0){
			int mypid = getpid();
			close(server_sockfd);
			printf("mypid[%d] \n", mypid);
			
			while(1){
				if((recv_len = recv(client_sockfd, recvBuf, BUFSIZE, 0)) == -1){
					perror("recv error");
					exit(1);
				}
				
				if(recv_len == 0){
					break;
				}
				
				recvBuf[recv_len] = '\0';
				printf("mypid[%d] \n", mypid);
				printf("Recevied from %d: %s\n", client_sockfd, recvBuf);
				
				if(send(client_sockfd, recvBuf, recv_len, 0) != recv_len){
					perror("send error");
					exit(1);
				}
			}
			close(client_sockfd);
			exit(0);
		}
		close(client_sockfd);
	}
	return 0;
}