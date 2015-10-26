#ifndef STD_LIB_C_STRING
#define STD_LIB_C_STRING

#include "stddef.h"

size_t strlen(const char *str);
int strcmp(const char *a, const char *b);

void *memset(void *ptr, int c, size_t n);
void *memcpy(void *dest, const void *source, size_t n);
void *memmove(void *dest, const void *source, size_t n);
void *memchr(void *ptr, int val, size_t n);
int memcmp(const void *a, const void *b, size_t n);

#endif