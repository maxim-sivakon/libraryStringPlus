#include "s21_string.h"

// возврат строки в которой удаляются все начальные вхождения заданных символов
int start_characters(const char *src, const char *to_trim, int offset) {
  int result = 0;
  int length_str = s21_strlen(to_trim);

  for (int counter = 0; counter < length_str; counter++) {
    if (src[offset] == to_trim[counter]) result = 1;
  }

  return result;
}

// возврат строки в которой удаляются все конечные вхождения заданных символов
int end_characters(const char *src, const char *to_trim, int offset) {
  int result = 0;
  int length_str = s21_strlen(to_trim);
  offset--;

  for (int counter = 0; counter < length_str; counter++) {
    if (src[offset] == to_trim[counter]) result = 1;
  }

  return result;
}

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = S21_NULL;

  if (src) {
    if (trim_chars && trim_chars[0]) {
      new_str = calloc(s21_strlen(src) + 1, 1);
      s21_size_t start = 0, end = s21_strlen(src);

      while (start_characters(src, trim_chars, start)) {
        start++;
      }

      if (start != end) {
        while (end_characters(src, trim_chars, end)) {
          end--;
        }
      } else {
        new_str[0] = '\0';
      }

      for (int counter = 0; start < end; counter++) {
        new_str[counter] = src[start];
        start++;
      }

    } else {
      new_str = s21_trim(src, "\t\n ");
    }
  }

  return new_str;
}
