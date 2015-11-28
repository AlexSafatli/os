#include "string.h"

size_t strlen(const char *str) {
  const char *ptr;
  for (ptr = str; *ptr != '\0'; ++ptr) ;
  return ptr - str;
}

int strcmp(const char *a, const char *b) {
  while (1) {
    if (*a < *b) return   -1;
    if (*a > *b) return    1;
    if (*a == '\0') return 0;
    ++a; ++b;
  }
}

void *memset(void *ptr, int c, size_t n) {
  int *temp = (int*)ptr;
  for ( ; n != 0; n--) *temp++ = c;
  return ptr;
}