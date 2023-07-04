#include "include/execute.h"

void execute(ast head) {
  symbol_table st = init_symbol_table();
  st = populate_symbol_table(head, st);
}
