#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/tcp_server.h"

// Global variable for client socket
int client_socket = -1;

int create_tcp_server(int port) {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    
    return server_fd;
}

void send_to_client(int client_socket, const char* message) {
    send(client_socket, message, strlen(message), 0);
}
