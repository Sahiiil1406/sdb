#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* Result types */
typedef enum {
  EXECUTE_SUCCESS,
  EXECUTE_DUPLICATE_KEY,
} ExecuteResult;

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_NEGATIVE_ID,
  PREPARE_STRING_TOO_LONG,
  PREPARE_SYNTAX_ERROR,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

/* Constants for the table */
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

/* Node types */
typedef enum { NODE_INTERNAL, NODE_LEAF } NodeType;

/* Define the page size and table max pages */
#define PAGE_SIZE 4096
#define TABLE_MAX_PAGES 400
#define INVALID_PAGE_NUM UINT32_MAX

/* Define a macro to get the size of a struct attribute */
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#endif /* TYPES_H */
