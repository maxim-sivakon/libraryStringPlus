#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  unsigned const char *strr1 = (unsigned const char *)str1;
  unsigned const char *strr2 = (unsigned const char *)str2;
  while (n-- > 0) {
    if (*strr1 != *strr2) {
      result = *strr1 - *strr2;
      break;
    }
    strr1++;
    strr2++;
  }
  return result;
}