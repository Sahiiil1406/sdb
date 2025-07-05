#ifndef TCP_SERVER_H
#define TCP_SERVER_H

/* TCP server functions */
int create_tcp_server(int port);
void send_to_client(int client_socket, const char* message);

/* Global variable for client socket */
extern int client_socket;

#endif /* TCP_SERVER_H */
