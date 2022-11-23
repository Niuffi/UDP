//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/types.h>
//
//#ifdef __linux__
//#include <unistd.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <netinet/in.h>
//#elif _WIN32 //unistd.h
//#include <io.h>
//#include<winsock2.h>
//#include<Ws2tcpip.h>
//#endif
//
//#define PORT 80
//
//int main(int argc, char* argv[])
//{
//
//	int sock;
//	char buffer[1024];
//	const char* hello = "hello";
//	struct sockaddr_in servaddr, cliaddr;
//
//	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
//		perror("socket creation failed");
//		exit(EXIT_FAILURE);
//	}
//
//	servaddr.sin_family = AF_INET;
//	servaddr.sin_port = htons(PORT);
//	servaddr.sin_addr.s_addr = INADDR_ANY;
//
//	if (bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
//		perror("bind failed");
//		exit(EXIT_FAILURE);
//	}
//
//	int len, n;
//
//	len = sizeof(cliaddr);  //len is value/result 
//
//	n = recvfrom(sock, (char*)buffer, 1024,
//		MSG_WAITALL, (struct sockaddr*)&cliaddr,
//		&len);
//	buffer[n] = '\0';
//	printf("Client : %s\n", buffer);
//	sendto(sock, (const char*)hello, strlen(hello), 0, (const struct sockaddr*)&cliaddr,
//		len);
//	printf("Hello message sent.\n");
//
//	return 0;
//}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#ifdef __linux__
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#elif _WIN32 
#include <io.h>
#include<winsock2.h>
#include<Ws2tcpip.h>
#endif


#define PORT 80



int main(int agrc, char* argv[]) {
    int sockfd;
    char buffer[1024];

    char* hello = "Hello from client"; //file

    struct sockaddr_in servaddr;

    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information 
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n, len;

    sendto(sockfd, (const char*)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr*)&servaddr, sizeof(servaddr));
    printf("Hello message sent.\n");

    close(sockfd);
    return 0;
}
