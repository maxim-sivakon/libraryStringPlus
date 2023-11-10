#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

void srunner_set_fork_status(SRunner *sr, enum fork_status fstat);

//---------- memchr_test ----------
START_TEST(s21_memchr_test_1) {
  ck_assert_pstr_eq(s21_memchr("qwerty", 'e', 5), memchr("qwerty", 'e', 5));
}
END_TEST

START_TEST(s21_memchr_test_2) {
  ck_assert_pstr_eq(s21_memchr("Black team\n\0", ' ', 6),
                    memchr("Black team\n\0", ' ', 6));
}
END_TEST

START_TEST(s21_memchr_test_3) {
  ck_assert_pstr_eq(s21_memchr("a\n\0", 'g', 6), memchr("a\n\0", 'g', 6));
}
END_TEST

START_TEST(s21_memchr_test_4) {
  ck_assert_pstr_eq(s21_memchr(" \n\0", ' ', 6), memchr(" \n\0", ' ', 6));
}
END_TEST

START_TEST(s21_memchr_test_5) {
  ck_assert_pstr_eq(s21_memchr("\n\0", '\n', 6), memchr("\n\0", '\n', 6));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_memchr_test_1);
  tcase_add_test(tc_core, s21_memchr_test_2);
  tcase_add_test(tc_core, s21_memchr_test_3);
  tcase_add_test(tc_core, s21_memchr_test_4);
  tcase_add_test(tc_core, s21_memchr_test_5);

  suite_add_tcase(s, tc_core);

  return s;
}

//---------- memcmp_test ----------

START_TEST(s21_memcmp_test_1) {
  ck_assert_int_eq(s21_memcmp("Black team\n\0", "Black ", 6),
                   memcmp("Black team\n\0", "Black ", 6));
}
END_TEST

START_TEST(s21_memcmp_test_2) {
  ck_assert_int_eq(s21_memcmp("", "Black ", 10), memcmp("", "Black ", 10));
}
END_TEST

START_TEST(s21_memcmp_test_3) {
  ck_assert_int_eq(s21_memcmp("Black team\n\0", "Black team\n\0", 13),
                   memcmp("Black team\n\0", "Black team\n\0", 13));
}
END_TEST

START_TEST(s21_memcmp_test_4) {
  ck_assert_int_eq(s21_memcmp("a\n\0", "a", 1), memcmp("a\n\0", "a", 1));
}
END_TEST

START_TEST(s21_memcmp_test_5) {
  ck_assert_int_eq(s21_memcmp("", "", 1), memcmp("", "", 1));
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_memcmp_test_1);
  tcase_add_test(tc_core, s21_memcmp_test_2);
  tcase_add_test(tc_core, s21_memcmp_test_3);
  tcase_add_test(tc_core, s21_memcmp_test_4);
  tcase_add_test(tc_core, s21_memcmp_test_5);

  suite_add_tcase(s, tc_core);

  return s;
}

//---------- memcpy_test ----------

START_TEST(s21_memcpy_test_1) {
  s21_size_t num = 2;
  char text1[1024] = "Black team";
  char text2[1024] = "  ";
  ck_assert_pstr_eq((char *)s21_memcpy(text1, text2, num),
                    (char *)memcpy(text1, text2, num));
}
END_TEST

START_TEST(s21_memcpy_test_2) {
  s21_size_t num = 6;
  char text1[1024] = "/]/Black";
  char text2[1024] = "   team////";
  ck_assert_pstr_eq((char *)s21_memcpy(text1, text2, num),
                    (char *)memcpy(text1, text2, num));
}
END_TEST

START_TEST(s21_memcpy_test_3) {
  s21_size_t num = 4;
  char text1[1024] = "";
  char text2[1024] = "1234567890";
  ck_assert_pstr_eq((char *)s21_memcpy(text1, text2, num),
                    (char *)memcpy(text1, text2, num));
}
END_TEST

START_TEST(s21_memcpy_test_4) {
  s21_size_t num = 4;
  char text1[1024] = "1234567890";
  char text2[1024] = "09876\0 54321";
  ck_assert_pstr_eq((char *)s21_memcpy(text1, text2, num),
                    (char *)memcpy(text1, text2, num));
}
END_TEST

START_TEST(s21_memcpy_test_5) {
  s21_size_t num = 1;
  char text1[1024] = "";
  char text2[1024] = "";
  ck_assert_pstr_eq((char *)s21_memcpy(text1, text2, num),
                    (char *)memcpy(text1, text2, num));
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_memcpy_test_1);
  tcase_add_test(tc_core, s21_memcpy_test_2);
  tcase_add_test(tc_core, s21_memcpy_test_3);
  tcase_add_test(tc_core, s21_memcpy_test_4);
  tcase_add_test(tc_core, s21_memcpy_test_5);

  suite_add_tcase(s, tc_core);

  return s;
}

//---------- memset_test ----------

START_TEST(s21_memset_test_1) {
  s21_size_t num = 7;
  char text1[1024] = "Black team";
  ck_assert_str_eq(s21_memset(text1, 't', num), memset(text1, 't', num));
}
END_TEST

START_TEST(s21_memset_test_2) {
  s21_size_t num = 0;
  char text1[1024] = "Black team";
  ck_assert_str_eq(s21_memset(text1, 't', num), memset(text1, 't', num));
}
END_TEST

START_TEST(s21_memset_test_3) {
  s21_size_t num = 0;
  char text1[1024] = "";
  ck_assert_str_eq(s21_memset(text1, '\0', num), memset(text1, '\0', num));
}
END_TEST

START_TEST(s21_memset_test_4) {
  s21_size_t num = 3;
  char text1[1024] = "team";
  ck_assert_str_eq(s21_memset(text1, '3', num), memset(text1, '3', num));
}
END_TEST

START_TEST(s21_memset_test_5) {
  s21_size_t num = 1;
  char text1[1024] = "black";
  ck_assert_str_eq(s21_memset(text1, 'B', num), memset(text1, 'B', num));
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memset");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_memset_test_1);
  tcase_add_test(tc_core, s21_memset_test_2);
  tcase_add_test(tc_core, s21_memset_test_3);
  tcase_add_test(tc_core, s21_memset_test_4);
  tcase_add_test(tc_core, s21_memset_test_5);

  suite_add_tcase(s, tc_core);

  return s;
}

//---------- strlen_test ----------

START_TEST(s21_strlen_test_1) {
  char text1[1024] = "Black";
  ck_assert_int_eq(s21_strlen(text1), strlen(text1));
}
END_TEST

START_TEST(s21_strlen_test_2) {
  char text1[1024] = "Black team";
  ck_assert_int_eq(s21_strlen(text1), strlen(text1));
}
END_TEST

START_TEST(s21_strlen_test_3) {
  char text1[1024] = "";
  ck_assert_int_eq(s21_strlen(text1), strlen(text1));
}
END_TEST

START_TEST(s21_strlen_test_4) {
  char text1[1024] = "k";
  ck_assert_int_eq(s21_strlen(text1), strlen(text1));
}
END_TEST

START_TEST(s21_strlen_test_5) {
  char text1[1024] = "1234567890";
  ck_assert_int_eq(s21_strlen(text1), strlen(text1));
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strlen");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strlen_test_1);
  tcase_add_test(tc_core, s21_strlen_test_2);
  tcase_add_test(tc_core, s21_strlen_test_3);
  tcase_add_test(tc_core, s21_strlen_test_4);
  tcase_add_test(tc_core, s21_strlen_test_5);

  suite_add_tcase(s, tc_core);

  return s;
}

//---------- strpbrk_test ----------

START_TEST(s21_strpbrk_test_1) {
  char text1[1024] = "";
  char text2[1024] = "Black team";
  ck_assert_pstr_eq(s21_strpbrk(text1, text2), strpbrk(text1, text2));
}
END_TEST

START_TEST(s21_strpbrk_test_2) {
  char text1[1024] = "Black team";
  char text2[1024] = "te";
  ck_assert_pstr_eq(s21_strpbrk(text1, text2), strpbrk(text1, text2));
}
END_TEST

START_TEST(s21_strpbrk_test_3) {
  char text1[1024] = "";
  char text2[1024] = "";
  ck_assert_pstr_eq(s21_strpbrk(text1, text2), strpbrk(text1, text2));
}
END_TEST

START_TEST(s21_strpbrk_test_4) {
  char text1[1024] = "Black team";
  char text2[1024] = "";
  ck_assert_pstr_eq(s21_strpbrk(text1, text2), strpbrk(text1, text2));
}
END_TEST

START_TEST(s21_strpbrk_test_5) {
  char text1[1024] = "Black team";
  char text2[1024] = "team";
  ck_assert_pstr_eq(s21_strpbrk(text1, text2), strpbrk(text1, text2));
}
END_TEST

START_TEST(s21_strpbrk_test_6) {
  char text1[1024] = "Black team";
  char text2[1024] = "squad";
  ck_assert_pstr_eq(s21_strpbrk(text1, text2), strpbrk(text1, text2));
}
END_TEST

START_TEST(s21_strpbrk_test_7) {
  char text1[1024] = "One";
  char text2[1024] = "n";
  ck_assert_pstr_eq(s21_strpbrk(text1, text2), strpbrk(text1, text2));
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strpbrk");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strpbrk_test_1);
  tcase_add_test(tc_core, s21_strpbrk_test_2);
  tcase_add_test(tc_core, s21_strpbrk_test_3);
  tcase_add_test(tc_core, s21_strpbrk_test_4);
  tcase_add_test(tc_core, s21_strpbrk_test_5);
  tcase_add_test(tc_core, s21_strpbrk_test_6);
  tcase_add_test(tc_core, s21_strpbrk_test_7);
  suite_add_tcase(s, tc_core);

  return s;
}

//---------- strcspn_test ----------

START_TEST(s21_strcspn_test_1) {
  char text1[1024] = "Black";
  char text2[1024] = "Black team";
  ck_assert_int_eq(s21_strcspn(text1, text2), strcspn(text1, text2));
}
END_TEST

START_TEST(s21_strcspn_test_2) {
  char text1[1024] = "\n";
  char text2[1024] = "\n";
  ck_assert_int_eq(s21_strcspn(text1, text2), strcspn(text1, text2));
}
END_TEST

START_TEST(s21_strcspn_test_3) {
  char text1[1024] = "\t";
  char text2[1024] = "\t";
  ck_assert_int_eq(s21_strcspn(text1, text2), strcspn(text1, text2));
}
END_TEST

START_TEST(s21_strcspn_test_4) {
  char text1[1024] = " \t";
  char text2[1024] = "\t";
  ck_assert_int_eq(s21_strcspn(text1, text2), strcspn(text1, text2));
}
END_TEST

START_TEST(s21_strcspn_test_5) {
  char text1[1024] = "\0";
  char text2[1024] = " \0";
  ck_assert_int_eq(s21_strcspn(text1, text2), strcspn(text1, text2));
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strcspn_test_1);
  tcase_add_test(tc_core, s21_strcspn_test_2);
  tcase_add_test(tc_core, s21_strcspn_test_3);
  tcase_add_test(tc_core, s21_strcspn_test_4);
  tcase_add_test(tc_core, s21_strcspn_test_5);
  suite_add_tcase(s, tc_core);

  return s;
}

//---------- strncat_test ----------

START_TEST(s21_strncat_test_1) {
  char text1[1024] = "Test string";
  char text2[1024] = "Black team";
  ck_assert_str_eq(s21_strncat(text1, text2, 7), strncat(text1, text2, 7));
}
END_TEST

START_TEST(s21_strncat_test_2) {
  char text1[1024] = "Test string";
  char text2[1024] = "Black team";
  ck_assert_str_eq(s21_strncat(text1, text2, 2), strncat(text1, text2, 2));
}
END_TEST

START_TEST(s21_strncat_test_3) {
  char text1[1024] = "Black team";
  char text2[1024] = "\n";
  ck_assert_str_eq(s21_strncat(text1, text2, 3), strncat(text1, text2, 3));
}
END_TEST

START_TEST(s21_strncat_test_4) {
  char text1[1024] = "Black\nteam";
  char text2[1024] = "\n";
  ck_assert_str_eq(s21_strncat(text1, text2, 1), strncat(text1, text2, 1));
}
END_TEST

START_TEST(s21_strncat_test_5) {
  char text1[1024] = "Black team";
  char text2[1024] = "";
  ck_assert_str_eq(s21_strncat(text1, text2, 7), strncat(text1, text2, 7));
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strncat_test_1);
  tcase_add_test(tc_core, s21_strncat_test_2);
  tcase_add_test(tc_core, s21_strncat_test_3);
  tcase_add_test(tc_core, s21_strncat_test_4);
  tcase_add_test(tc_core, s21_strncat_test_5);
  suite_add_tcase(s, tc_core);

  return s;
}

//---------- strncmp_test ----------

START_TEST(s21_strncmp_test_1) {
  char text1[1024] = "";
  char text2[1024] = "";
  s21_size_t num = 1;
  ck_assert_int_eq(s21_strncmp(text1, text2, num), strncmp(text1, text2, num));
}
END_TEST

START_TEST(s21_strncmp_test_2) {
  char text1[1024] = "";
  char text2[1024] = "123";
  s21_size_t num = 1;
  ck_assert_int_eq(s21_strncmp(text1, text2, num), strncmp(text1, text2, num));
}
END_TEST

START_TEST(s21_strncmp_test_3) {
  char text1[1024] = "123";
  char text2[1024] = "";
  s21_size_t num = 1;
  ck_assert_int_eq(s21_strncmp(text1, text2, num), strncmp(text1, text2, num));
}
END_TEST

START_TEST(s21_strncmp_test_4) {
  char text1[1024] = "123abc";
  char text2[1024] = "1a3bc";
  s21_size_t num = 1;
  ck_assert_int_eq(s21_strncmp(text1, text2, num), strncmp(text1, text2, num));
}
END_TEST

START_TEST(s21_strncmp_test_5) {
  char text1[1024] = "1a3bc";
  char text2[1024] = "123abc";
  s21_size_t num = 1;
  ck_assert_int_eq(s21_strncmp(text1, text2, num), strncmp(text1, text2, num));
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strncmp_test_1);
  tcase_add_test(tc_core, s21_strncmp_test_2);
  tcase_add_test(tc_core, s21_strncmp_test_3);
  tcase_add_test(tc_core, s21_strncmp_test_4);
  tcase_add_test(tc_core, s21_strncmp_test_5);
  suite_add_tcase(s, tc_core);

  return s;
}

//---------- strncpy_test ----------

START_TEST(s21_strncpy_test_1) {
  char text1[1024] = "";
  char text2[1024] = "";
  s21_size_t num = 0;
  ck_assert_str_eq(s21_strncpy(text1, text2, num), strncpy(text1, text2, num));
}
END_TEST

START_TEST(s21_strncpy_test_2) {
  char text1[1024] = "Black";
  char text2[1024] = "team";
  s21_size_t num = 0;
  ck_assert_str_eq(s21_strncpy(text1, text2, num), strncpy(text1, text2, num));
}
END_TEST

START_TEST(s21_strncpy_test_3) {
  char text1[1024] = "";
  char text2[1024] = "Black team";
  s21_size_t num = 2;
  ck_assert_str_eq(s21_strncpy(text1, text2, num), strncpy(text1, text2, num));
}
END_TEST

START_TEST(s21_strncpy_test_4) {
  char text1[1024] = "Black team";
  char text2[1024] = "Black team squad";
  s21_size_t num = 1;
  ck_assert_str_eq(s21_strncpy(text1, text2, num), strncpy(text1, text2, num));
}
END_TEST

START_TEST(s21_strncpy_test_5) {
  char text1[1024] = "Black team";
  char text2[1024] = "Black team squad";
  s21_size_t num = 16;
  ck_assert_str_eq(s21_strncpy(text1, text2, num), strncpy(text1, text2, num));
}
END_TEST

START_TEST(s21_strncpy_test_6) {
  char text1[1024] = "Black team squad";
  char text2[1024] = "Black team";
  s21_size_t num = 16;
  ck_assert_str_eq(s21_strncpy(text1, text2, num), strncpy(text1, text2, num));
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strncpy_test_1);
  tcase_add_test(tc_core, s21_strncpy_test_2);
  tcase_add_test(tc_core, s21_strncpy_test_3);
  tcase_add_test(tc_core, s21_strncpy_test_4);
  tcase_add_test(tc_core, s21_strncpy_test_5);
  tcase_add_test(tc_core, s21_strncpy_test_6);
  suite_add_tcase(s, tc_core);

  return s;
}

//---------- strstr_test ----------

START_TEST(s21_strstr_test_1) {
  char text1[1024] = "";
  char text2[1024] = "Black team";

  ck_assert_pstr_eq(s21_strstr(text1, text2), strstr(text1, text2));
}
END_TEST

START_TEST(s21_strstr_test_2) {
  char text1[1024] = "Black team";
  char text2[1024] = "Bl";

  ck_assert_pstr_eq(s21_strstr(text1, text2), strstr(text1, text2));
}
END_TEST

START_TEST(s21_strstr_test_3) {
  char text1[1024] = "";
  char text2[1024] = "";

  ck_assert_pstr_eq(s21_strstr(text1, text2), strstr(text1, text2));
}
END_TEST

START_TEST(s21_strstr_test_4) {
  char text1[1024] = "Black team";
  char text2[1024] = "";

  ck_assert_pstr_eq(s21_strstr(text1, text2), strstr(text1, text2));
}
END_TEST

START_TEST(s21_strstr_test_5) {
  char text1[1024] = "Black team";
  char text2[1024] = "team";

  ck_assert_pstr_eq(s21_strstr(text1, text2), strstr(text1, text2));
}
END_TEST

START_TEST(s21_strstr_test_6) {
  char text1[1024] = "Black team";
  char text2[1024] = "squad";

  ck_assert_pstr_eq(s21_strstr(text1, text2), strstr(text1, text2));
}
END_TEST

START_TEST(s21_strstr_test_7) {
  char text1[1024] = "Black team";
  char text2[1024] = "l";

  ck_assert_pstr_eq(s21_strstr(text1, text2), strstr(text1, text2));
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strstr_test_1);
  tcase_add_test(tc_core, s21_strstr_test_2);
  tcase_add_test(tc_core, s21_strstr_test_3);
  tcase_add_test(tc_core, s21_strstr_test_4);
  tcase_add_test(tc_core, s21_strstr_test_5);
  tcase_add_test(tc_core, s21_strstr_test_6);
  tcase_add_test(tc_core, s21_strstr_test_7);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(s21_strtok_test_1) {
  char str_original[] = "allo";
  char str_our[] = "allo";
  char delim[] = "-=/,";
  char *str_strtok = strtok(str_original, delim);
  char *str_s21_strtok = s21_strtok(str_our, delim);
  ck_assert_uint_eq(s21_strlen(str_strtok), s21_strlen(str_s21_strtok));
  ck_assert_str_eq(str_strtok, str_s21_strtok);
}
END_TEST

START_TEST(s21_strtok_test_2) {
  char str_original[] = "Black, team/squad";
  char str_our[] = "Black, team/squad";
  char delim[] = "-=/,";
  char *str_strtok = strtok(str_original, delim);
  char *str_s21_strtok = s21_strtok(str_our, delim);
  ck_assert_uint_eq(s21_strlen(str_strtok), s21_strlen(str_s21_strtok));
  ck_assert_str_eq(str_strtok, str_s21_strtok);
  while (str_strtok && str_s21_strtok) {
    str_strtok = strtok(s21_NULL, delim);
    str_s21_strtok = s21_strtok(s21_NULL, delim);
    if (str_strtok || str_s21_strtok) {
      ck_assert_str_eq(str_strtok, str_s21_strtok);
    } else {
      ck_assert_ptr_null(str_strtok);
      ck_assert_ptr_null(str_s21_strtok);
    }
  }
}
END_TEST

START_TEST(s21_strtok_test_3) {
  char str_original[] = "Black,////// team/squ///ad";
  char str_our[] = "Black,////// team/squ///ad";
  char delim[] = "-=/,";
  char *str_strtok = strtok(str_original, delim);
  char *str_s21_strtok = s21_strtok(str_our, delim);
  ck_assert_uint_eq(s21_strlen(str_strtok), s21_strlen(str_s21_strtok));
  ck_assert_str_eq(str_strtok, str_s21_strtok);
  while (str_strtok && str_s21_strtok) {
    str_strtok = strtok(s21_NULL, delim);
    str_s21_strtok = s21_strtok(s21_NULL, delim);
    if (str_strtok || str_s21_strtok) {
      ck_assert_str_eq(str_strtok, str_s21_strtok);
    } else {
      ck_assert_ptr_null(str_strtok);
      ck_assert_ptr_null(str_s21_strtok);
    }
  }
}
END_TEST

START_TEST(s21_strtok_test_4) {
  char str_original[] = "Black,//  /  /// team/squ///ad";
  char str_our[] = "Black,//  /  /// team/squ///ad";
  char delim[] = "-=/,";
  char *str_strtok = strtok(str_original, delim);
  char *str_s21_strtok = s21_strtok(str_our, delim);
  ck_assert_uint_eq(s21_strlen(str_strtok), s21_strlen(str_s21_strtok));
  ck_assert_str_eq(str_strtok, str_s21_strtok);
  while (str_strtok && str_s21_strtok) {
    str_strtok = strtok(s21_NULL, delim);
    str_s21_strtok = s21_strtok(s21_NULL, delim);
    if (str_strtok || str_s21_strtok) {
      ck_assert_str_eq(str_strtok, str_s21_strtok);
    } else {
      ck_assert_ptr_null(str_strtok);
      ck_assert_ptr_null(str_s21_strtok);
    }
  }
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strtok");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_strtok_test_1);
  tcase_add_test(tc_core, s21_strtok_test_2);
  tcase_add_test(tc_core, s21_strtok_test_3);
  tcase_add_test(tc_core, s21_strtok_test_4);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(sprintf_c_modifier) {
  char str[510];
  char str2[510];

  sprintf(str, "%%c", 'v');
  s21_sprintf(str2, "%%c", 'v');
  ck_assert_str_eq(str, str2);

  sprintf(str, "%c", 'O');
  s21_sprintf(str2, "%c", 'O');
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_c_width) {
  char str[510];
  char str2[510];

  sprintf(str, "%12c %97c%9c", 'n', 'j', 'i');
  s21_sprintf(str2, "%12c %97c%9c", 'n', 'j', 'i');
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_c_flags) {
  char str[510];
  char str2[510];

  sprintf(str, "% c", 'A');
  s21_sprintf(str2, "% c", 'A');
  ck_assert_str_eq(str, str2);

  sprintf(str, "%- c", '\0');
  s21_sprintf(str2, "%- c", '\0');
  ck_assert_str_eq(str, str2);

  sprintf(str, "%-c %-c%c % c%c%c", 'j', 'z', 'z', 'z', 'z', 'z');
  s21_sprintf(str2, "%-c %-c%c % c%c%c", 'j', 'z', 'z', 'z', 'z', 'z');
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_c_combinations) {
  char str[510];
  char str2[510];

  sprintf(str, "%-2c %-c%c", 'v', 'j', 'z');
  s21_sprintf(str2, "%-2c %-c%c", 'v', 'j', 'z');
  ck_assert_str_eq(str, str2);
}
END_TEST

// спецификатор s
START_TEST(sprintf_s_modifier) {
  char str[510];
  char str2[510];

  sprintf(str, "%%s", "vim");
  s21_sprintf(str2, "%%s", "vim");
  ck_assert_str_eq(str, str2);

  sprintf(str, "%s", "OLLA");
  s21_sprintf(str2, "%s", "OLLA");
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_s_width) {
  char str[510];
  char str2[510];
  sprintf(str, "%45s %-97s %2s", "Rick", "and", "Morty");
  s21_sprintf(str2, "%45s %-97s %2s", "Rick", "and", "Morty");
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_s_flags) {
  char str[510];
  char str2[510];

  sprintf(str, "%s %-s", "OPA", "Help");
  s21_sprintf(str2, "%s %-s", "OPA", "Help");
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_s_combinations) {
  char str[510];
  char str2[510];

  sprintf(str, "%10s%-10s %-10s", "OLLA", "Black", "ABOBA");
  s21_sprintf(str2, "%10s%-10s %-10s", "OLLA", "Black", "ABOBA");
  ck_assert_str_eq(str, str2);
}
END_TEST

// спецификатор d
START_TEST(sprintf_d_modifier) {
  char str[510];
  char str2[510];

  sprintf(str, "%d%d %d", 16, 190, 507);
  s21_sprintf(str2, "%d%d %d", 16, 190, 507);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%ld", 1234567890);
  s21_sprintf(str2, "%ld", 1234567890);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_width) {
  char str[510];
  char str2[510];

  sprintf(str, "%-10d %1d %99d %203d", 4, 80, 15, 16);
  s21_sprintf(str2, "%-10d %1d %99d %203d", 4, 80, 15, 16);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_flags) {
  char str[510];
  char str2[510];

  sprintf(str, "%+-d %-d %+d %d % d", 69, 3, -80, 19, 190);
  s21_sprintf(str2, "%+-d %-d %+d %d % d", 69, 3, -80, 19, 190);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_accuracy) {
  char str[510];
  char str2[510];

  sprintf(str, "%.1d %.12d %.13d", 3, 6, 314);
  s21_sprintf(str2, "%.1d %.12d %.13d", 3, 6, 314);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_combinations) {
  char str[510];
  char str2[510];

  sprintf(str, "% -12.1d %+10d %+- .4d", 3, -27, -1);
  s21_sprintf(str2, "% -12.1d %+10d %+- .4d", 3, -27, -1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+15.10d", 3);
  s21_sprintf(str2, "%+15.10d", 3);
  ck_assert_str_eq(str, str2);
}
END_TEST

// спецификатор i
START_TEST(sprintf_i_modifier) {
  char str[510];
  char str2[510];

  sprintf(str, "%i", 123);
  s21_sprintf(str2, "%i", 123);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_i_width) {
  char str[510];
  char str2[510];

  sprintf(str, "%-10i %1i %99i %203i", 4, 80, 15, 16);
  s21_sprintf(str2, "%-10i %1i %99i %203i", 4, 80, 15, 16);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_i_flags) {
  char str[510];
  char str2[510];

  sprintf(str, "%-i %+i %-i %i % i", 69, -3, 80, 19, 0);
  s21_sprintf(str2, "%-i %+i %-i %i % i", 69, -3, 80, 19, 0);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_i_accuracy) {
  char str[510];
  char str2[510];

  sprintf(str, "%.10i %.13i %.12i%.1i", 3, 6, 314, 27);
  s21_sprintf(str2, "%.10i %.13i %.12i%.1i", 3, 6, 314, 27);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_i_combinations) {
  char str[510];
  char str2[510];

  sprintf(str, "%-.1i % 10.2i %+-1.4i", 3, 27, -1);
  s21_sprintf(str2, "%-.1i % 10.2i %+-1.4i", 3, 27, -1);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_modifier) {
  char str[510];
  char str2[510];

  sprintf(str, "%f", 3.784837584);
  s21_sprintf(str2, "%f", 3.784837584);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%lf", 3.784837584);
  s21_sprintf(str2, "%lf", 3.784837584);
  ck_assert_str_eq(str, str2);  //???
}
END_TEST

START_TEST(sprintf_f_width) {
  char str[510];
  char str2[510];
  sprintf(str, "%25f %2f%57f", 3.784837584, 19.4875948, 6.983984937);
  s21_sprintf(str2, "%25f %2f%57f", 3.784837584, 19.4875948, 6.983984937);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_flags) {
  char str[510];
  char str2[510];
  sprintf(str, "%f %-f%+f % -f %+-f", 3.78584, 19.487, 6.3984937, 4.90, 5.000);
  s21_sprintf(str2, "%f %-f%+f % -f %+-f", 3.78584, 19.487, 6.3984937, 4.90,
              5.000);  //???
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_accuracy) {
  char str[510];
  char str2[510];
  sprintf(str, "%.f %.6f %.13f %.12f", 3.78584, 19.487, 6.3984937, 4.90, 5.000);
  s21_sprintf(str2, "%.f %.6f %.13f %.12f", 3.78584, 19.487, 6.3984937, 4.90,
              5.000);  //???
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_combinations) {
  char str[510];
  char str2[510];
  sprintf(str, "%+ 5f %-f%+-29f %-5.11f", 3.78584, 19.487, 6.3984937, 4.90,
          5.000);
  s21_sprintf(str2, "%+ 5f %-f%+-29f %-5.11f", 3.78584, 19.487, 6.3984937, 4.90,
              5.000);  //???
  ck_assert_str_eq(str, str2);
}
END_TEST

// спецификатор u

START_TEST(sprintf_u_modifier) {
  char str[510];
  char str2[510];

  sprintf(str, "%u", 9);
  s21_sprintf(str2, "%u", 9);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%lu", 399);
  s21_sprintf(str2, "%lu", 399);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_width) {
  char str[510];
  char str2[510];

  sprintf(str, "%-10u %1u %-99u %203u", 3, 18, 58, 99);
  s21_sprintf(str2, "%-10u %1u %-99u %203u", 3, 18, 58, 99);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_flags) {
  char str[510];
  char str2[510];

  sprintf(str, "%-u %u", 5, 77);
  s21_sprintf(str2, "%-u %u", 5, 77);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_accuracy) {
  char str[510];
  char str2[510];

  sprintf(str, "%.1u %.12u %.11u", 99, 56, 3);
  s21_sprintf(str2, "%.1u %.12u %.11u", 99, 56, 3);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_combinations) {
  char str[510];
  char str2[510];
  sprintf(str, "%13u %u %-12.2u %-.2u", 137, 8, 10, 396);
  s21_sprintf(str2, "%13u %u %-12.2u %-.2u", 137, 8, 10, 396);
  ck_assert_str_eq(str, str2);
}
END_TEST

Suite *s21_sprintf_test(void) {
  Suite *s1 = suite_create("s21_sprintf");

  TCase *tc1 = tcase_create("test_d");
  tcase_add_test(tc1, sprintf_d_modifier);
  tcase_add_test(tc1, sprintf_d_width);
  tcase_add_test(tc1, sprintf_d_flags);
  tcase_add_test(tc1, sprintf_d_accuracy);
  tcase_add_test(tc1, sprintf_d_combinations);
  suite_add_tcase(s1, tc1);

  TCase *tc2 = tcase_create("test_i");
  tcase_add_test(tc2, sprintf_i_modifier);
  tcase_add_test(tc2, sprintf_i_width);
  tcase_add_test(tc2, sprintf_i_flags);
  tcase_add_test(tc2, sprintf_i_accuracy);
  tcase_add_test(tc2, sprintf_i_combinations);
  suite_add_tcase(s1, tc2);

  TCase *tc3 = tcase_create("test_c");
  tcase_add_test(tc3, sprintf_c_modifier);
  tcase_add_test(tc3, sprintf_c_width);
  tcase_add_test(tc3, sprintf_c_flags);
  tcase_add_test(tc3, sprintf_c_combinations);
  suite_add_tcase(s1, tc3);

  TCase *tc4 = tcase_create("test_s");
  tcase_add_test(tc4, sprintf_s_modifier);
  tcase_add_test(tc4, sprintf_s_width);
  tcase_add_test(tc4, sprintf_s_flags);
  tcase_add_test(tc4, sprintf_s_combinations);
  suite_add_tcase(s1, tc4);

  TCase *tc5 = tcase_create("test_f");
  tcase_add_test(tc5, sprintf_f_modifier);
  tcase_add_test(tc5, sprintf_f_width);
  tcase_add_test(tc5, sprintf_f_flags);
  tcase_add_test(tc5, sprintf_f_accuracy);
  tcase_add_test(tc5, sprintf_f_combinations);
  suite_add_tcase(s1, tc5);

  TCase *tc6 = tcase_create("test_u");
  tcase_add_test(tc6, sprintf_u_modifier);
  tcase_add_test(tc6, sprintf_u_width);
  tcase_add_test(tc6, sprintf_u_flags);
  tcase_add_test(tc6, sprintf_u_accuracy);
  tcase_add_test(tc6, sprintf_u_combinations);
  suite_add_tcase(s1, tc6);

  // TCase *tc7 = tcase_create("test_o");
  // tcase_add_test(tc7, sprintf_o_modifier);
  // tcase_add_test(tc7, sprintf_o_width);
  // tcase_add_test(tc7, sprintf_o_flags);
  // tcase_add_test(tc7, sprintf_o_accuracy);
  // tcase_add_test(tc7, sprintf_o_combinations);
  // suite_add_tcase(s1, tc7);

  return s1;
}

int test_sprintf(Suite *s1) {
  int no_failed = 0;
  SRunner *runner = srunner_create(s1);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}

int s21_string_tests(Suite *s) {
  int no_failed = 0;
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? 0 : 1;
}

START_TEST(strrchr_test1) {
  char data[128] = "imgrootlovegroot";
  ck_assert_pstr_eq(strrchr(data, 'o'), s21_strrchr(data, 'o'));
}
END_TEST

START_TEST(strrchr_test2) {
  char str[] = "89139345164";
  ck_assert_pstr_eq(strrchr(str, '9'), s21_strrchr(str, '9'));
}
END_TEST

START_TEST(strrchr_test3) {
  char orig_str[] = "yandex@a.sberkrasava";
  ck_assert_pstr_eq(strrchr(orig_str, 'a'), s21_strrchr(orig_str, 'a'));
}
END_TEST

START_TEST(strrchr_test4) {
  char str3[] = "imgroot.hategroot";
  ck_assert_pstr_eq(strrchr(str3, 't'), s21_strrchr(str3, 't'));
}
END_TEST

START_TEST(strrchr_test5) {
  char str4[] = "";
  ck_assert_pstr_eq(strrchr(str4, 'g'), s21_strrchr(str4, 'g'));
}
END_TEST

START_TEST(strrchr_test6) {
  char s21_str[] = "";
  char orig_str = '\0';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test7) {
  char s21_str[] = "iamgroot";
  char orig_str = '\0';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test8) {
  char s21_str[] = "";
  char orig_str = 'g';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test9) {
  char s21_str[] = "imgrootlovegroot";
  char orig_str = 'o';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test10) {
  char s21_str[] = "imgroot lovegroot";
  char orig_str = 'o';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test11) {
  char s21_str[] = "imgrootlovegroot";
  char orig_str = 'o';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test12) {
  char s21_str[] = "ImgrootIlovegroot";
  char orig_str = 'I';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test13) {
  char s21_str[] = "89139345164";
  char orig_str = '0';
  ck_assert_pstr_eq(s21_strrchr(s21_str, orig_str), strrchr(s21_str, orig_str));
}
END_TEST

START_TEST(strrchr_test14) {
  char src[] = "str\0str\0str";
  char find = '\0';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
// strerror
START_TEST(strerror_test) {
  for (int err = 1; err < 107; err++) {
    ck_assert_str_eq(strerror(err), s21_strerror(err));
  }
  ck_assert_pstr_eq(strerror(267), s21_strerror(267));
}
END_TEST
// insert
START_TEST(insert_test1) {
  char data[64] = "iii";
  char data1[64] = "ggg";
  char *data2 = s21_insert(data, data1, 3);
  ck_assert_str_eq("iiiggg", data2);
  free(data2);
}
END_TEST

START_TEST(insert_test2) {
  char *string = "groot";
  char *string2;
  string2 = s21_insert(string, "root", 2);
  ck_assert_pstr_eq(string2, "grrootoot");
  free(string2);
}
END_TEST

START_TEST(insert_test3) {
  char *string = "groot";
  char *string2;
  string2 = s21_insert(string, "lover", 8);
  ck_assert_pstr_eq(string2, s21_NULL);
  free(string2);
}
END_TEST

START_TEST(insert_test4) {
  char *string = s21_NULL;
  char *string2;
  string2 = s21_insert(string, "lover", 2);
  ck_assert_pstr_eq(string2, s21_NULL);
  free(string2);
}
END_TEST

START_TEST(insert_test5) {
  char str[] = "Groot";
  char src[] = "Iam . He is tree!";
  s21_size_t index = 4;
  char expected[] = "Iam Groot. He is tree!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test6) {
  char *src = s21_NULL;
  char *str = s21_NULL;
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test7) {
  char str[] = "Groot";
  char src[] = "Iam  ";
  s21_size_t index = 4;
  char expected[] = "Iam Groot ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test8) {
  char *str = s21_NULL;
  char src[] = "Groot";
  s21_size_t index = 0;
  char expected[] = "Groot";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test9) {
  char str[] = "I'm ";
  char src[] = "Groot!";
  s21_size_t index = 0;
  char expected[] = "I'm Groot!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test10) {
  char str[] = "Iam";
  char src[] = "Groot groot!";
  s21_size_t index = 0;
  char expected[] = "IamGroot groot!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
// lower
START_TEST(to_lower_test1) {
  char data1[64] = "IAMGROOT";
  char data[64] = "iamgroot";
  char *data2 = s21_to_lower(data1);
  ck_assert_str_eq(data, data2);
  free(data2);
}
END_TEST

START_TEST(to_lower_test2) {
  char s21_str[] = "Iam, Groot!";
  char *orig_str = (char *)s21_to_lower(s21_str);
  ck_assert_pstr_eq(orig_str, "iam, groot!");
  free(orig_str);
}
END_TEST

START_TEST(to_lower_test3) {
  char s21_str[] = "Iam, Groot! 777";
  char *orig_str = (char *)s21_to_lower(s21_str);
  ck_assert_pstr_eq(orig_str, "iam, groot! 777");
  free(orig_str);
}
END_TEST

START_TEST(to_lower_test4) {
  char str[] = "Iam Groot?";
  char expected[] = "iam groot?";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test5) {
  char str[] = "8913934GROOT";
  char expected[] = "8913934groot";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
// upper
START_TEST(to_upper_test1) {
  char data1[64] = "iamgroot";
  char data[64] = "IAMGROOT";
  char *data2 = s21_to_upper(data1);
  ck_assert_str_eq(data, data2);
  free(data2);
}
END_TEST

START_TEST(to_upper_test2) {
  char s21_str[] = "Iam, Groot!";
  char *orig_str = (char *)s21_to_upper(s21_str);
  ck_assert_pstr_eq(orig_str, "IAM, GROOT!");
  free(orig_str);
}
END_TEST

START_TEST(to_upper_test3) {
  char s21_str[] = "Iam, Groot! 777";
  char *orig_str = (char *)s21_to_upper(s21_str);
  ck_assert_pstr_eq(orig_str, "IAM, GROOT! 777");
  free(orig_str);
}
END_TEST

START_TEST(to_upper_test4) {
  char data1[64] = "8913934groot";
  char data[64] = "8913934GROOT";
  char *data2 = s21_to_upper(data1);
  ck_assert_str_eq(data, data2);
  free(data2);
}
END_TEST

START_TEST(to_upper_test5) {
  char s21_str[] = "Iam, Groot!";
  char *orig_str = (char *)s21_to_upper(s21_str);
  ck_assert_pstr_eq(orig_str, "IAM, GROOT!");
  free(orig_str);
}
END_TEST
// trim
START_TEST(trim_test1) {
  char data[60] = "o Iam, Groot!";
  char data1[10] = "o";
  char *data2 = s21_trim(data, data1);
  ck_assert_pstr_eq(data2, " Iam, Groot!");
  free(data2);
}
END_TEST

START_TEST(trim_test2) {
  char src1[] = "     &#@\n\n\t Iam, Groot! *&#@ \n\t   ";
  char trim_chars[] = " &#@\n\t";
  char *psrc = s21_trim(src1, trim_chars);
  ck_assert_pstr_eq(psrc, "Iam, Groot! *");
  free(psrc);
}
END_TEST

START_TEST(trim_test3) {
  char str[] = "IamGroot!";
  char trim_ch[] = "Iam";
  char expected[] = "Groot!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test4) {
  char str[] = "&* !!Iam86 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "Iam86";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test5) {
  char str[] = "        Iam         ";
  char *trim_ch = s21_NULL;
  char expected[] = "Iam";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("s21_string");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, strrchr_test1);
  tcase_add_test(tcase_core, strrchr_test2);
  tcase_add_test(tcase_core, strrchr_test3);
  tcase_add_test(tcase_core, strrchr_test4);
  tcase_add_test(tcase_core, strrchr_test5);
  tcase_add_test(tcase_core, strrchr_test6);
  tcase_add_test(tcase_core, strrchr_test7);
  tcase_add_test(tcase_core, strrchr_test8);
  tcase_add_test(tcase_core, strrchr_test9);
  tcase_add_test(tcase_core, strrchr_test10);
  tcase_add_test(tcase_core, strrchr_test11);
  tcase_add_test(tcase_core, strrchr_test12);
  tcase_add_test(tcase_core, strrchr_test13);
  tcase_add_test(tcase_core, strrchr_test14);

  tcase_add_test(tcase_core, strerror_test);

  tcase_add_test(tcase_core, insert_test1);
  tcase_add_test(tcase_core, insert_test2);
  tcase_add_test(tcase_core, insert_test3);
  tcase_add_test(tcase_core, insert_test4);
  tcase_add_test(tcase_core, insert_test5);
  tcase_add_test(tcase_core, insert_test6);
  tcase_add_test(tcase_core, insert_test7);
  tcase_add_test(tcase_core, insert_test8);
  tcase_add_test(tcase_core, insert_test9);
  tcase_add_test(tcase_core, insert_test10);

  tcase_add_test(tcase_core, to_lower_test1);
  tcase_add_test(tcase_core, to_lower_test2);
  tcase_add_test(tcase_core, to_lower_test3);
  tcase_add_test(tcase_core, to_lower_test4);
  tcase_add_test(tcase_core, to_lower_test5);

  tcase_add_test(tcase_core, to_upper_test1);
  tcase_add_test(tcase_core, to_upper_test2);
  tcase_add_test(tcase_core, to_upper_test3);
  tcase_add_test(tcase_core, to_upper_test4);
  tcase_add_test(tcase_core, to_upper_test5);

  tcase_add_test(tcase_core, trim_test1);
  tcase_add_test(tcase_core, trim_test2);
  tcase_add_test(tcase_core, trim_test3);
  tcase_add_test(tcase_core, trim_test4);
  tcase_add_test(tcase_core, trim_test5);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  s21_string_tests(s21_memchr_suite());
  s21_string_tests(s21_memcmp_suite());
  s21_string_tests(s21_memcpy_suite());
  s21_string_tests(s21_memset_suite());
  s21_string_tests(s21_strlen_suite());
  s21_string_tests(s21_strpbrk_suite());
  s21_string_tests(s21_strcspn_suite());
  s21_string_tests(s21_strncat_suite());
  s21_string_tests(s21_strncmp_suite());
  s21_string_tests(s21_strncpy_suite());
  s21_string_tests(s21_strstr_suite());
  s21_string_tests(s21_strtok_suite());
  test_sprintf(s21_sprintf_test());
  s21_string_tests(s21_string_suite());
  return 0;
}