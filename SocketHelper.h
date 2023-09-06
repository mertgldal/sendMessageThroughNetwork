//
// Created by mg on 9/5/23.
//

#ifndef SMTN_SOCKETHELPER_H
#define SMTN_SOCKETHELPER_H

// Function declarations
int createSocket();
bool bindSocket(int sockfd, int port);
bool listenOnSocket(int sockfd, int backlog);
int acceptConnection(int sockfd, struct sockaddr_in& clientAddress);

#endif //SMTN_SOCKETHELPER_H
