#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  s21_size_t length_src = (src == S21_NULL) ? 0 : s21_strlen(src);
  s21_size_t length_str = (str == S21_NULL) ? 0 : s21_strlen(str);
  s21_size_t length_final = length_src + length_str;

  // если указанная позиция меньше длине указанной строки
  if (start_index <= length_src) {
    // выделаяем память на обьем суммы строк
    result = (char *)calloc(length_src + length_str + 1, sizeof(char));
  }

  if (result) {
    for (s21_size_t counter = 0; counter < length_final; counter++) {
      if (counter < start_index) {
        result[counter] = src[counter];
      } else if (counter < length_str + start_index) {
        result[counter] = str[counter - start_index];
      } else {
        result[counter] = src[counter - length_str];
      }
    }
  }

  return result;
}

// void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
//   char *result = S21_NULL;
//   s21_size_t length_src = s21_strlen(src);
//   s21_size_t length_str = s21_strlen(str);
//   s21_size_t length_final = start_index + length_str;
//   s21_size_t line = (length_final > length_src ? length_final : length_src);
//   if (start_index <= length_src) {
//     // выделаяем память на обьем суммы строк
//     result = (char *)calloc(line + 1, sizeof(char));
//     if (result) {
//       s21_memcpy(result, src, start_index);
//       if (length_str) s21_strncat (result, str, s21_strlen(str));
//       s21_strncat(result, src + start_index, s21_strlen(src) - start_index);
//     }
//   }
//   return (void *)result;
// }