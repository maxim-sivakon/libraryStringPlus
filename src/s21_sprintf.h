#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <math.h>
#include <stdarg.h>
#define BUFF_SIZE 8000

// init functions
typedef struct instructions {
  int integer;
  int unsigned_integer;
  int float_instruction;
  int char_instruction;
  int percent_instruction;
  int string_instruction;
} instructions;

typedef struct flags {
  int minus;
  int plus;
  int enter;
  int short_int;
  int long_int;
} flags;

int s21_sprintf(char *str, const char *format, ...);
char write(int jitaya, char simvol, char *str);
void simple_parser(const char *format, int *itaya, instructions *instruction);
void arg_printer(char *str, int *jitaya, instructions instruction,
                 va_list *input, int width, flags myflags, int accuracy);
void print_int(char *str, int *jitaya, va_list *input, int width, flags myflags,
               int accuracy);
void reverse(char str[], int length);
int parse_width(const char *format, int *itaya);
int parse_accuracy(const char *format, int *itaya);
int s21_atoi(char *str);
int itoa(long long int n, char str[]);
int integer_count(long int integer);
void read_flags(flags *myflags, const char *format, int *itaya);
void width_print(int width, int arg_symbols_count, int *jitaya, char *str,
                 int accuracy);
void print_accuracy_int(char *str, int *jitaya, int accuracy, int int_count);
void lenght_reader(const char *format, int *itaya, flags *myflags);
void clear_flag(flags *myflags, instructions *instruction);
void print_float(char *str, int *jitaya, va_list *input, int width,
                 flags myflags, int accuracy);
void width_print_for_floats(int width, int result_long, int *jitaya, char *str);
void ifi_i_fori_dlya_floata(flags myflags, int result_long, int width,
                            char *str, int *jitaya, int sign, int accuracy,
                            char str_whole_part[], char str_fraction_part[],
                            int whole_part_count);
void print_unsigned(char *str, int *jitaya, va_list *input, int width,
                    flags myflags, int accuracy);
void print_char(char *str, int *jitaya, va_list *input, int width,
                flags myflags);
void print_percent(char *str, int *jitaya, int width, flags myflags);
void print_string(char *str, int *jitaya, va_list *input, int width,
                  flags myflags);
#endif