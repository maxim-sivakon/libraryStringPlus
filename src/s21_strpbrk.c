#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *_str = (char *)str1;
  int flag = 1;
  s21_size_t i = 0;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);
  for (; i < len_str1 && flag; i++) {
    for (s21_size_t j = 0; j < len_str2; j++) {
      if (str1[i] == str2[j]) flag = 0;
    }
  }
  return flag ? S21_NULL : _str + i - 1;
}
