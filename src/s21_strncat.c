#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len = s21_strlen(dest);
  s21_size_t i = 0;
  for (i = 0; i < n; i++) dest[len + i] = src[i];
  dest[len + i] = '\0';
  return dest;
}