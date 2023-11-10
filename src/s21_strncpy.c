#include "s21_string.h"

// char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
//   s21_size_t len = s21_strlen(src);
//   for (long long unsigned int i = 0; i < n; i++) {
//     if (len < n && i >= n)
//       dest[i] = '\0';
//     else
//       dest[i] = src[i];
//   }
//   return dest;
// }

// with Andrew

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; ++i) {
    dest[i] = src[i];
  }
  if (src[i] == '\0' && n > 0 && n > s21_strlen(src)) {
    while (i != n) {
      dest[i] = '\0';
      i++;
    }
  }
  return dest;
}
