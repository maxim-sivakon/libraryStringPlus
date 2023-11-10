#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в верхний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str) {
  char *result = S21_NULL;

  if (str) {
    s21_size_t length_str = s21_strlen(str);
    // выделяем память для результата равную размеру str
    result = (char *)calloc(length_str + 1, sizeof(char));

    if (result != S21_NULL) {
      for (s21_size_t counter = 0; counter < length_str; counter++) {
        // пробегаемся по симовлам и по совпадению переводим в верхний регистр
        result[counter] = (str[counter] >= 'a' && str[counter] <= 'z')
                              ? str[counter] - 32
                              : str[counter];
      }
    }
  }

  return result;
}