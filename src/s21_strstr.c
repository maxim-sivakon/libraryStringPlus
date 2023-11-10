#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t i = 0, j = 0, count = 0;
  char *flag = s21_NULL;

  if (s21_strlen(needle) == 0) {
    if (s21_strlen(haystack) == 0) {
      flag = "";
    } else {
      flag = (char *)&haystack[0];
    }
  } else {
    for (; haystack[i] != '\0'; i++) {
      if (haystack[i] == needle[0]) {
        flag = (char *)&haystack[i];
        for (; needle[j] != '\0'; j++) {
          if (haystack[i + j] != needle[j]) {
            flag = s21_NULL;
            break;
          } else {
            count++;
          }
        }
        if (count == s21_strlen(needle)) {
          break;
        }
      }
    }
  }
  return flag;
}