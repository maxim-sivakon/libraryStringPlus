#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *_str = (unsigned char *)str;
  void *result = S21_NULL;
  s21_size_t i = 0;
  while (i < n) {
    if (*((char *)str + i) == c) {
      result = _str + i;
      break;
    }
    i++;
  }
  return result;
}