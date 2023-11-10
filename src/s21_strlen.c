#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int count_char = 0;

  while (str[count_char] != '\0') {
    count_char++;
  }

  return count_char;
}