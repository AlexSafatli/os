#include "string.h"

void *memset(void *ptr, int c, size_t n) {
  int *temp = (int*)ptr;
  for ( ; n != 0; n--) *temp++ = c;
  return ptr;
}