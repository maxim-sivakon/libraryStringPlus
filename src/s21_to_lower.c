#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в нижний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
  char *result = S21_NULL;

  if (str) {
    s21_size_t length_str = s21_strlen(str);
    // выделяем память для результата равную размеру str
    result = (char *)calloc(length_str + 1, sizeof(char));

    if (result != S21_NULL) {
      for (s21_size_t counter = 0; counter < length_str; counter++) {
        // пробегаемся по симовлам и по совпадению переводим в нижний регистр
        result[counter] = (str[counter] >= 'A' && str[counter] <= 'Z')
                              ? str[counter] + 32
                              : str[counter];
      }
    }
  }

  return result;
}