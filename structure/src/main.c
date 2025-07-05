#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/db.h"

void print_prompt() { printf("db > "); }

int main(int argc, char* argv[]) {
  if (argc < 3) {
        printf("Usage: %s <database_filename> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

  // Initialize constants that can't be initialized at compile time
  init_constants();

  char* filename = argv[1];
  int port = atoi(argv[2]);
    
  Table* table = db_open(filename);
  int server_fd = create_tcp_server(port);
    
  printf("Server listening on port %d\n", port);

  while (true) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    printf("Client connected\n");
        
    InputBuffer* input_buffer = new_input_buffer();
    input_buffer->buffer = malloc(1024);
    input_buffer->buffer_length = 1024;
    
    while (true) {
      // send_to_client(client_socket, "db > ");
      read_input(input_buffer, client_socket);

      if (input_buffer->buffer[0] == '.') {
        switch (do_meta_command(input_buffer, table)) {
          case (META_COMMAND_SUCCESS):
            continue;
          case (META_COMMAND_UNRECOGNIZED_COMMAND):
            printf("Unrecognized command '%s'\n", input_buffer->buffer);
            continue;
        }
      }

      Statement statement;
      switch (prepare_statement(input_buffer, &statement)) {
        case (PREPARE_SUCCESS):
          break;
        case (PREPARE_NEGATIVE_ID):
          printf("ID must be positive.\n");
          continue;
        case (PREPARE_STRING_TOO_LONG):
          printf("String is too long.\n");
          continue;
        case (PREPARE_SYNTAX_ERROR):
          printf("Syntax error. Could not parse statement.\n");
          continue;
        case (PREPARE_UNRECOGNIZED_STATEMENT):
          printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
          continue;
      }

      switch (execute_statement(&statement, table)) {
        case (EXECUTE_SUCCESS):
          printf("Executed.\n");
          break;
        case (EXECUTE_DUPLICATE_KEY):
          printf("Error: Duplicate key.\n");
          break;
      }
    }
  }
}
