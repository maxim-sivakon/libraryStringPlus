#ifndef S21_STRING
#define S21_STRING

#include <stdlib.h>

#define s21_NULL ((void *)0)
#define S21_NULL ((void *)0)
#define s21_size_t unsigned long long

#ifndef ULONG_MAX
#define ULONG_MAX ((unsigned long)(~0L))
#endif

#ifndef LONG_MAX
#define LONG_MAX ((long)(ULONG_MAX >> 1))
#endif

#ifndef LONG_MIN
#define LONG_MIN ((long)(~LONG_MAX))
#endif

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, const char *format, ...);

#endif