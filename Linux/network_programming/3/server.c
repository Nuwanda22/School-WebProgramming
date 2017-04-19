#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

#define PORT 7777		// 포트 번호
#define MAXPENDING 5	// 클라

int calculate(Data *data)
{
	if(data->op == '+' || data->op == '-' || data->op == '*' || data->op == '/'){
		data->error = 0;
		
		switch(data->op){
			case '+':
			data->result = data->operand[0] + data->operand[1];
			break;
			
			case '-':
			data->result = data->operand[0] - data->operand[1];
			break;
			
			case '*':
			data->result = data->operand[0] * data->operand[1];
			break;
			
			case '/':
			data->result = data->operand[0] / data->operand[1];
			break;
		}
		return 0;
	}
	else{
		data->error = -1;
		return -1;
	}
}

int main(int argc, char **argv)
{
	int server_sockfd;	// 서버 소켓 파일 디스크립터
	int client_sockfd;	// 클라 소켓 파일 디스크립터
	
	struct sockaddr_in clientaddr;	// 클라 주소
	struct sockaddr_in serveraddr;	// 서버 주소
	
	int client_len; // 클라 길이
	int recv_len;
	
	pid_t pid;
	int optval;
	Data data;

	// 서버 소켓 만들고 저장 오류나면 종료
	if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket error");
		exit(1);
	}
	
	setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, 0);
	
	// serveraddr 초기화
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(PORT);
	
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
		printf("\nNew Client Connect!\nport:  %d Addr: %s ", clientaddr.sin_port, inet_ntoa(clientaddr.sin_addr));
		
		// 자식 프로세스 만듬
		if((pid = fork()) == -1){
			perror("\nfork error");
			exit(1);
		}
		else if(pid == 0){
			int mypid = getpid();
			close(server_sockfd);
			printf("new pid: %d\n", mypid);
			
			while(1){
				if((recv_len = recv(client_sockfd, &data.op, sizeof(Data), 0)) == -1){
					perror("recv error");
					exit(1);
				}
				
				if(recv_len == 0){
					break;
				}
				
				calculate((Data *)&data.op);
				
				printf("\npid[%d] \n", mypid);
				printf("Recevied from %d: %c operate \n", client_sockfd, data.op);
				
				if(send(client_sockfd, &data.op, recv_len, 0) == -1){
					perror("send error");
					close(client_sockfd);
					exit(1);
				}
				
				if(send(client_sockfd, &data.op, recv_len, 0) == -1){
					perror("send error");
					close(client_sockfd);
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