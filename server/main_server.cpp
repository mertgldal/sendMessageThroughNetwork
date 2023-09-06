//
// Created by mg on 9/5/23.
//
#include <iostream>
#include "/home/mg/NetworkProgramming/smtn/SocketHelper.h"
#include <netinet/in.h>
#include <unistd.h>

const int port = 8080;

int main() {
    int sockfd = createSocket();
    if (sockfd == -1) {
        exit(EXIT_FAILURE);
    }

    if (!bindSocket(sockfd, port)) {
        exit(EXIT_FAILURE);
    }

    if (!listenOnSocket(sockfd, 5)) {
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in clientAddress;
    int clientSocket = acceptConnection(sockfd, clientAddress);
    if (clientSocket == -1) {
        exit(EXIT_FAILURE);
    }

    // Receive data from client
    char buffer[1024]; // Assuming a maximum message size of 1024 bytes
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        perror("Receive failed");
        close(clientSocket);
        close(sockfd);
        exit(EXIT_FAILURE);
    } else if (bytesRead == 0) {
        // Connection closed by client
        close(clientSocket);
        close(sockfd);
        exit(EXIT_SUCCESS);
    } else {
        // Null-terminate the received data to treat it as a C string
        buffer[bytesRead] = '\0';
        std::cout << "Received message from client: " << buffer << std::endl;
    }

    // Close sockets when done
    close(clientSocket);
    close(sockfd);

    return 0;
}
