/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, newsockfd[255], portno, clilen;
	int cli_no = 0;
	char buffer[1024];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		error("ERROR opening socket");

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
		error("ERROR on binding");

	listen(sockfd,5);
	clilen = sizeof(cli_addr);
	while(1) {
		newsockfd[cli_no] = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0) 
			error("ERROR on accept");

		if (fork() == 0) {
			printf("Connected from \033[33m%s\033[0m\n", inet_ntoa(cli_addr.sin_addr));
			while (1) {
				bzero(buffer, 1024);
				n = read(newsockfd[cli_no], buffer, 255);
				if (n < 0) error("ERROR reading from socket");
				printf("message from %s: \033[92m%s\033[0m\n", inet_ntoa(cli_addr.sin_addr), buffer);
				sprintf(buffer, "%s\tserver pid = %d", buffer, getpid());
				n = write(newsockfd[cli_no], buffer, strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
			}
			cli_no++;
		}
	}
}
