#ifndef TABLE_H
#define TABLE_H

#include "pager.h"
#include "row.h"

/* Table structure */
typedef struct Table {
  Pager* pager;
  uint32_t root_page_num;
} Table;

/* Table functions */
Table* db_open(const char* filename);
void db_close(Table* table);

#endif /* TABLE_H */
