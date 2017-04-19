#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include "contact.h"

#define PORT 7777
#define CHOP(x) x[strlen(x) - 1] = ' '

void input(Contact *buf)
{
	buf->command = 1;
	printf("Name : "); fgets(buf->name, 12, stdin); CHOP(buf->name);
        printf("Addrese : "); fgets(buf->addr, 30, stdin); CHOP(buf->addr);
        printf("Tel : "); fgets(buf->tel, 12, stdin); CHOP(buf->tel);
}

void delete(Contact *buf)
{
	buf->command = 2;
}

void print(Contact *buf)
{
	buf->command = 3;
}

int main(int argc, char **argv)
{
	int loop = 0;
	int command;
	struct sockaddr_in serveraddr;	// 서버 주소
	int server_sockfd;	// 서버 소켓 파일 디스크립터
	int client_len;		// 클라 길이
	Contact buf;	// 버퍼

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
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = htons(PORT);
	client_len = sizeof(serveraddr);
	
	// 연결
	if(connect(server_sockfd, (struct sockaddr *)&serveraddr, client_len) == -1){
		perror("connet error");
		return 1;
	}
	
	while(1){
		// 버퍼 초기화
		memset(&buf.command, 0, sizeof(Contact));
		// 명령 선택
		printf("1. input  2. remove  3. print  4. exit : ");
		scanf("%d", &command); getchar();
		while(1){
			if(command == 1){
				input((Contact *)&buf.command);
				break;
			}
			else if(command == 2){
				delete((Contact *)&buf.command);
				break;
			}
			else if(command == 3){
				print((Contact *)&buf.command);
				break;
			}
			else if(command == 4){
				loop = 1;
				break;	
			}
		}
		if(loop == 1){
			break;
		}
		// 서버에 쓰기
		if(send(server_sockfd, (Contact *)&buf.command, sizeof(Contact), 0) == -1){
			perror("write error");
			return 1;
		}
		if(recv(server_sockfd, (Contact *)&buf.command, sizeof(Contact), 0) == -1){
			perror("recv error");
			return 1;
		}
		if(buf.error == 0){
			if(buf.command == 1){
				puts("input success");
			}
			else if(buf.command = 2){
				puts("remove success");
			}
			else if(buf.command = 3){
				puts(buf.name);
				puts(buf.addr);
				puts(buf.tel);
			}
		}
		else if(buf.error == -1){
			puts("error");
		}
	}
	close(server_sockfd);
	return 0;
}
