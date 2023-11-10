#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i = 0;
  char *dest1 = (char *)dest;
  char *src1 = (char *)src;
  for (; i < n; i++) {
    *dest1 = *src1;
    dest1++;
    src1++;
  }
  return (void *)dest;
}