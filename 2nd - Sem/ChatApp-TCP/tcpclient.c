// TCP-CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9999

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);//creating a socket..
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Connected to Server.\n");

	char name[20];
	printf("What should I call you :");
	fgets(name,20,stdin);
	send(clientSocket, name, strlen(name), 0);

	while(1){
		printf("Client: \t");
		fgets(buffer, sizeof(buffer), stdin);
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strncmp(buffer, ":exit", strlen(buffer)-1) == 0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}
 
		if(recv(clientSocket, buffer, 1024, 0) < 0){
			printf("[-]Error in receiving data.\n");
		}else{
			printf("Server: \t");
			puts(buffer);
		}
	}
	return 0;
}