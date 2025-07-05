#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <stdlib.h>
#include "types.h"

/* Forward declarations */
typedef struct Table Table;

/* InputBuffer structure for user input */
typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

/* InputBuffer functions */
InputBuffer* new_input_buffer();
void read_input(InputBuffer* input_buffer, int client_socket);
void close_input_buffer(InputBuffer* input_buffer);
MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);

#endif /* INPUT_BUFFER_H */
