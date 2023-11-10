#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *buf = s21_NULL;
  char *res = s21_NULL;
  if (str) buf = str;
  if ((buf != s21_NULL) && (*buf != 0)) {
    char *c = buf;
    while (s21_strchr(delim, *c)) c++;
    if (*c != 0) {
      res = c;
      while (*c && (s21_strchr(delim, *c) == 0)) c++;
      if (*c) {
        *c = 0;
        buf = c + 1;
      } else {
        buf = c;
      }
    }
  }
  return res;
}