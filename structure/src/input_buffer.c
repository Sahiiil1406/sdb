#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../include/input_buffer.h"
#include "../include/table.h"
#include "../include/btree.h"
#include "../include/tcp_server.h"

extern int client_socket;

InputBuffer* new_input_buffer() {
  InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}

void read_input(InputBuffer* input_buffer, int client_socket) {
    ssize_t bytes_read = recv(client_socket, input_buffer->buffer, 
                             input_buffer->buffer_length - 1, 0);
    
    if (bytes_read <= 0) {
        printf("Client disconnected\n");
        close(client_socket);
        exit(EXIT_SUCCESS);
    }
    
    input_buffer->input_length = bytes_read;
    input_buffer->buffer[bytes_read] = '\0';
    
    // Remove trailing newline if present
    if (input_buffer->buffer[bytes_read-1] == '\n') {
        input_buffer->buffer[bytes_read-1] = '\0';
        input_buffer->input_length--;
    }
}

void close_input_buffer(InputBuffer* input_buffer) {
  free(input_buffer->buffer);
  free(input_buffer);
}

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table) {
  if (strncmp(input_buffer->buffer, ".exit", 5) == 0) {
    close_input_buffer(input_buffer);
    db_close(table);
    printf("Exiting...\n");
    exit(EXIT_SUCCESS);
  } else if (strncmp(input_buffer->buffer, ".btree",6) == 0) {
    printf("Tree:\n");
    print_tree(table->pager, 0, 0);
    return META_COMMAND_SUCCESS;
  } else if (strncmp(input_buffer->buffer, ".constants", 10) == 0) {
    printf("Constants:\n");
    print_constants();
    return META_COMMAND_SUCCESS;
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}
