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
#define MAXTHREAD 5

typedef struct thread_data{
	int client;
	Data *buf;
}ThreadData;

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

void *func(ThreadData td)
{
	int client_sockfd = td.client;
	Data *buf = td.buf;

    int recv_len;
    pthread_t thread_id = pthread_self();
	printf("new tid: %d\n", (int)thread_id);
			
	while(1){
		if((recv_len = recv(client_sockfd, buf, sizeof(Data), 0)) == -1){
			perror("recv error");
			break;
		}
				
		if(recv_len == 0){
			break;
		}
		
		calculate(buf);
				
		printf("\ntid[%d] \n", (int)thread_id);
		printf("Recevied from %d: %c operate \n", client_sockfd, buf->op);
		
		if(send(client_sockfd, buf, recv_len, 0) == -1){
			perror("send error");
			break;
		}
				
		if(send(client_sockfd, buf, recv_len, 0) == -1){
			perror("send error");
			break;
		}
	}
	close(client_sockfd);
    return;
}

int main(int argc, char **argv)
{
	int i = 0;
	int server_sockfd;	// 서버 소켓 파일 디스크립터
	int client_sockfd;	// 클라 소켓 파일 디스크립터
	
	struct sockaddr_in clientaddr;	// 클라 주소
	struct sockaddr_in serveraddr;	// 서버 주소
	
	int client_len; // 클라 길이
	
    pthread_t thread_id[MAXTHREAD];
	
	int optval;
	Data data;
	ThreadData td;

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
		
		// 쓰레드 만듬
		td.client = client_sockfd;
		td.buf = (Data *)&data.op;
		if(pthread_create(&thread_id[i++], NULL, func, td)!=0){
			perror("\npthread");
			exit(1);
		}
		close(client_sockfd);
	}
	return 0;
}