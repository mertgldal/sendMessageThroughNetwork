//
// Created by mg on 9/5/23.
//

#include "SocketHelper.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int createSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
    }
    return sockfd;
}

bool bindSocket(int sockfd, int port) {
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr =INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Bind failed");
        close(sockfd);
        return false;
    }
    return true;
}

bool listenOnSocket(int sockfd, int backlog) {
    if (listen(sockfd, backlog) == -1) {
        perror("Listen failed");
        close(sockfd);
        return false;
    }
    return true;
}

int acceptConnection(int sockfd, struct sockaddr_in& clientAddress) {
    socklen_t clientAddrLen = sizeof(clientAddress);
    int clientSocket = accept(sockfd, (struct sockaddr*)&clientAddress, &clientAddrLen);
    if (clientSocket == -1) {
        perror("Accept failed");
        close(sockfd);
        return -1;
    }
    return clientSocket;
}