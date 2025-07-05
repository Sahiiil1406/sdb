#ifndef STATEMENT_H
#define STATEMENT_H

#include "types.h"
#include "row.h"
#include "table.h"
#include "input_buffer.h"

/* Statement structure */
typedef struct {
  StatementType type;
  Row row_to_insert;  // only used by insert statement
} Statement;

/* Statement functions */
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
PrepareResult prepare_insert(InputBuffer* input_buffer, Statement* statement);
ExecuteResult execute_statement(Statement* statement, Table* table);
ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);

#endif /* STATEMENT_H */
