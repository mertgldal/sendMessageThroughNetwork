//
// Created by mg on 9/5/23.
//

#include <iostream>
#include "/home/mg/NetworkProgramming/smtn/SocketHelper.h"
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const int port = 8080;

int main() {
    int senderSocket = createSocket();
    if (senderSocket == -1) {
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in senderAddress;
    senderAddress.sin_family = AF_INET;
    senderAddress.sin_port = htons(port);
    // Replace the following line with the actual server IP address
    inet_pton(AF_INET, "192.168.152.129", &(senderAddress.sin_addr));

    if (connect(senderSocket, (struct sockaddr*)&senderAddress, sizeof(senderAddress)) == -1){
        // Handle connection to server failure
        close(senderSocket);
        return EXIT_FAILURE;
    }

    // Send data from client (sender) to server (receiver)
    const char* message = "Hello Server!";
    send(senderSocket, message, strlen(message), 0);

    // Close the sender socket when done
    close(senderSocket);

    return 0;
}
