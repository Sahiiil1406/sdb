#ifndef PAGER_H
#define PAGER_H

#include <stdint.h>
#include "types.h"

/* Pager structure to manage database pages */
typedef struct {
  int file_descriptor;
  uint32_t file_length;
  uint32_t num_pages;
  void* pages[TABLE_MAX_PAGES];
} Pager;

/* Pager functions */
Pager* pager_open(const char* filename);
void pager_flush(Pager* pager, uint32_t page_num);
void* get_page(Pager* pager, uint32_t page_num);
uint32_t get_unused_page_num(Pager* pager);

#endif /* PAGER_H */
