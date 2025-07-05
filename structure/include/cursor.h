#ifndef CURSOR_H
#define CURSOR_H

#include <stdbool.h>
#include "table.h"

/* Cursor structure for navigating the table */
typedef struct {
  Table* table;
  uint32_t page_num;
  uint32_t cell_num;
  bool end_of_table;  // Indicates a position one past the last element
} Cursor;

/* Cursor functions */
Cursor* table_find(Table* table, uint32_t key);
Cursor* table_start(Table* table);
void* cursor_value(Cursor* cursor);
void cursor_advance(Cursor* cursor);
Cursor* leaf_node_find(Table* table, uint32_t page_num, uint32_t key);
Cursor* internal_node_find(Table* table, uint32_t page_num, uint32_t key);

#endif /* CURSOR_H */
