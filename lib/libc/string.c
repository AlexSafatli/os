#include "string.h"

void *memset(void *ptr, int c, size_t n) {
  int *temp = (int*)ptr;
  for ( ; n != 0; n--) *temp++ = c;
  return ptr;
}

size_t strlen(const char *str) {
  int i;
  i = 0;
  while (str[i] != '\0') ++i;
  return i+1; 
}