// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com/
#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "levels.h"

#define MAX 80
#define PORT 8080
#define MAX_LEVEL 12
#define SA struct sockaddr

static int (*levels[MAX_LEVEL])(FILE * socket_file, char ** response, size_t size);
static void loadLevels();

void func(int sockfd)
{
	int level = 0,aux=0;
	FILE * socket_file = fdopen(sockfd,"r");
	char * response = malloc(sizeof(char) * MAX);
	loadLevels();
	while (level < MAX_LEVEL && aux != -1){
		printf("\033[1;1H\033[2J");
		memset(response, 0, MAX);
		if( (aux = levels[level](socket_file,&response,MAX)) == 1){
			level++;
		}else{
			printf("Respuesta incorrecta: %s\n", response);
			sleep(1);
		}
	}
	free(response);
	if(aux == -1){ //salio por un error
		return; 
	}
	printf("\033[1;1H\033[2J");
	printf("\033[1;1H\033[2J");
	printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n");
}
static void loadLevels(){
	levels[0] = level0;
	levels[1] = level1;
	levels[2] = level2;
	levels[3] = level3;
	levels[4] = level4;
	levels[5] = level5;
	levels[6] = level6;
	levels[7] = level7;
	levels[8] = level8;
	levels[9] = level9;
	levels[10] = level10;
	levels[11] = level11;
}

// Driver function
int main()
{
	int sockfd, connfd,opt=1;
	struct sockaddr_in servaddr, cli;
	socklen_t addrlen;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("socket options settings failed\n");
        exit(0);
    }
	printf("Socket successfully created..\n");
	memset(&servaddr, 0, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");

	addrlen = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &addrlen);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);
}
