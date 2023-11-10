#include "s21_string.h"

// s21_size_t s21_strcspn(const char *str1, const char *str2) {
//   s21_size_t str1_len = s21_strlen(str1);
//   s21_size_t str2_len = s21_strlen(str2);
//   s21_size_t size = 0;
//   int flag = 1;
//   for (long long unsigned int i = 0; i < str1_len; i++) {
//     for (long long unsigned int j = 0; j < str2_len; j++) {
//       if (str1[i] == str2[j]) {
//         size = i;
//         flag = 0;
//         break;
//       }
//     }
//     if (flag == 0) break;
//   }
//   return size;
// }

// With Andrew

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  s21_size_t size = 0;
  int flag = 1;
  for (s21_size_t i = 0; i <= str1_len; i++) {
    for (s21_size_t j = 0; j <= str2_len; j++) {
      if (str1[i] == str2[j]) {
        flag = 0;
        break;
      }
    }
    size = i;  // приравниваем размер массива к итой
    if (flag == 0) break;
  }

  return size;
}