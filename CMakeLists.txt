cmake_minimum_required(VERSION 3.26)
project(smtn)

set(CMAKE_CXX_STANDARD 20)

# Create the server executable
add_executable(server
        SocketHelper.h
        SocketHelper.cpp
        server/main_server.cpp)

# Create the client executable
add_executable(client
        SocketHelper.h
        SocketHelper.cpp
        client/main_client.cpp)