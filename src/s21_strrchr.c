#include "s21_string.h"

// char *s21_strrchr(const char *str, int c) {
//   int flag = 1, i = 0;
//   s21_size_t len_str1 = s21_strlen(str);
//   for (i = len_str1 - 1; i >= 0; i--) {
//     if (str[i] == c) flag = 0;
//   }
//   return flag ? S21_NULL : (char *)&str[i + 1];
// }

char *s21_strrchr(const char *str, int c) {
  s21_size_t i = 0, j = 0, x = 0;
  int flag = 0;
  for (; i < s21_strlen(str) + 1; i++) {
    if (str[i] == c) {
      x++;
      j = i;
    }
  }
  if (x == 0) {
    flag = 1;
  }
  return flag ? s21_NULL : (char *)&str[j];
}
