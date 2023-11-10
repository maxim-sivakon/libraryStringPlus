#ifndef S21_SPRINTF_C_HELP_FUNC
#define S21_SPRINTF_C_HELP_FUNC

#include "s21_sprintf.h"

#include "s21_string.h"

// work functions for sprintf

int s21_sprintf(char *str, const char *format, ...) {
  va_list(input);
  va_start(input, format);
  instructions instruction = {0};
  flags myflags = {0};
  int format_count = s21_strlen(format);
  int itaya = 0, jitaya = 0;
  char simvol = 'l';
  while (itaya < format_count) {
    simvol = format[itaya];
    if (simvol == '%') {
      while (simvol == '%' && itaya < format_count) {
        itaya++;
        read_flags(&myflags, format, &itaya);     // парсим флаги
        int width = parse_width(format, &itaya);  // парсим ширину
        int accuracy = parse_accuracy(format, &itaya);  // парсим точность
        lenght_reader(format, &itaya, &myflags);  // длинна, если есть
        simple_parser(format, &itaya, &instruction);  // парсим инструкции
        arg_printer(str, &jitaya, instruction, &input, width, myflags,
                    accuracy);  // принтим аргумент
        if (itaya <= format_count && format[itaya] != '\0') {
          simvol = format[itaya];
        }
        clear_flag(&myflags, &instruction);
      }
    }
    itaya++;
    if (itaya <= format_count && simvol != '\0') {
      write(jitaya, simvol, str);
      jitaya++;
    }
  }
  str[jitaya] = '\0';
  int allo = s21_strlen(str);
  va_end(input);
  return allo;
}

// записываем символ в итоговую строку
char write(int jitaya, char simvol, char *str) {
  char tmp = simvol;
  str[jitaya] = simvol;
  return tmp;
}

// парсер, епта
void simple_parser(const char *format, int *itaya, instructions *instruction) {
  switch (format[*itaya]) {
    case 'd':
      instruction->integer = 1;
      *itaya = *itaya + 1;
      break;
    case 'i':
      instruction->integer = 1;
      *itaya = *itaya + 1;
      break;
    case 'o':
      instruction->unsigned_integer = 1;
      *itaya = *itaya + 1;
      break;
    case 'f':
      instruction->float_instruction = 1;
      *itaya = *itaya + 1;
      break;
    case 'u':
      instruction->unsigned_integer = 1;
      *itaya = *itaya + 1;
      break;
    case 'c':
      instruction->char_instruction = 1;
      *itaya = *itaya + 1;
      break;
    case '%':
      instruction->percent_instruction = 1;
      *itaya = *itaya + 1;
      break;
    case 's':
      instruction->string_instruction = 1;
      *itaya = *itaya + 1;
      break;
    default:
      break;
  }
}
// тут будем принтить аргументы, каждый принт = отдельная функция
void arg_printer(char *str, int *jitaya, instructions instruction,
                 va_list *input, int width, flags myflags, int accuracy) {
  if (instruction.integer == 1) {
    print_int(str, jitaya, input, width, myflags, accuracy);
  }
  if (instruction.float_instruction == 1) {
    print_float(str, jitaya, input, width, myflags, accuracy);
  }
  if (instruction.unsigned_integer == 1) {
    print_unsigned(str, jitaya, input, width, myflags, accuracy);
  }
  if (instruction.char_instruction == 1) {
    print_char(str, jitaya, input, width, myflags);
  }
  if (instruction.percent_instruction == 1) {
    print_percent(str, jitaya, width, myflags);
  }
  if (instruction.string_instruction == 1) {
    print_string(str, jitaya, input, width, myflags);
  }
}

// принтуем аргументы типа инт
void print_int(char *str, int *jitaya, va_list *input, int width, flags myflags,
               int accuracy) {
  long int printed_int = 0;
  if (myflags.long_int == 1) {
    printed_int = (long int)va_arg(*input, long int);  // костыли для длинны
  } else if (myflags.short_int == 1) {
    printed_int = (short int)va_arg(*input, int);
  } else
    printed_int = (int)va_arg(*input, int);
  int arg_symbols_count = integer_count(printed_int);
  if (printed_int < 0 && !myflags.plus) width--;  // костыли для плюса))
  if (myflags.plus == 1) width--;
  if (myflags.minus != 1) {
    width_print(width, arg_symbols_count, jitaya, str, accuracy);
  }
  if (myflags.plus == 1) {  // добавляем плюс/минус если есть флаг
    if (printed_int > 0) str[*jitaya] = '+';
    if (printed_int < 0) {
      str[*jitaya] = '-';
      printed_int = printed_int * -1;
    }
    *jitaya = *jitaya + 1;
  }
  char integer_characters[BUFF_SIZE] = {
      0};  // буффер для перевода инта в строку
  int int_count =
      itoa(printed_int, integer_characters);  // переводим инт в строку
  print_accuracy_int(str, jitaya, accuracy, int_count);
  if (myflags.enter == 1 && myflags.plus != 1) {
    if (myflags.minus == 1) {
      if (myflags.plus != 1 && printed_int > 0) {
        str[*jitaya] = ' ';  // костыль для флага пробел
        *jitaya = *jitaya + 1;
        width--;
      }
    } else if (width <= arg_symbols_count &&
               (str[*jitaya - 1] != '-' || str[*jitaya - 1] != '+')) {
      str[*jitaya] = ' ';  // костыль для флага пробел
      *jitaya = *jitaya + 1;
    }
  }
  for (int i = 0; i < int_count; i++) {
    str[*jitaya] = integer_characters[i];  // принт непосредственно числа
    *jitaya = *jitaya + 1;
  }
  if (myflags.minus == 1) {
    width_print(width, arg_symbols_count, jitaya, str, accuracy);
  }
}

// принт ширины для интов
void width_print(int width, int arg_symbols_count, int *jitaya, char *str,
                 int accuracy) {
  if (width > 0 && arg_symbols_count < width && accuracy > arg_symbols_count) {
    for (int i = 0;
         i < width - arg_symbols_count - (accuracy - arg_symbols_count); i++) {
      str[*jitaya] = ' ';
      *jitaya = *jitaya + 1;  // принтим пробелы ширины если точность больше
                              // количества символов аргумента
    }
  } else if (width > 0 && arg_symbols_count < width) {
    for (int i = 0; i < width - arg_symbols_count; i++) {
      str[*jitaya] = ' ';
      *jitaya = *jitaya + 1;  // принтим пробелы ширины
    }
  }
}

// разворачиваем строку с интом
void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

// переводим инт в строку
int itoa(long long int n, char str[]) {
  int i = 0;
  int sign = 0;

  if (n == 0) {  // чекаем не является ли нулем
    str[i++] = '0';
    str[i] = '\0';
  } else {
    if (n < 0) {  // чекаем не отрицательное ли
      sign = 1;
      n = -n;
    }

    while (n != 0) {  // переписываем в строку
      int digit = n % 10;
      str[i++] = digit + '0';
      n = n / 10;
    }

    if (sign) {  // возвращаем минус если нужно
      str[i++] = '-';
    }

    str[i] = '\0';

    reverse(str, i);  // переворачиваем конечную строку  в нормальное положение
  }
  return i;
}

// парсим ширину
int parse_width(const char *format, int *itaya) {
  int width = 0;
  char str_width[BUFF_SIZE] = {'\0'};
  while (format[*itaya] != '.' && (int)format[*itaya] > 47 &&
         (int)format[*itaya] < 58) {
    str_width[width] = format[*itaya];
    width++;
    *itaya = *itaya + 1;
  }
  return s21_atoi(str_width);
}

// переводим строку в инт
int s21_atoi(char *str) {
  int res = 0;  // начальное значение результата
  int sign = 1;
  // определяем знак числа
  if (*str == '-' || *str == '+') {
    if (*str == '-') sign = -1;
    str++;
  }
  // преобразуем цифры строки в целое число
  while (*str >= '0' && *str <= '9') {
    res = res * 10 + (*str - '0');
    str++;
  }
  return res * sign;
}

// считаем количество символов
int integer_count(long int integer) {
  int count = 0;
  while (integer != 0) {
    integer /= 10;
    count++;
  }
  return count;
}

// парсим флаги
void read_flags(flags *myflags, const char *format, int *itaya) {
  while (format[*itaya] == '0' || format[*itaya] == '#' ||
         format[*itaya] == '-' || format[*itaya] == '+' ||
         format[*itaya] == ' ') {
    switch (format[*itaya]) {
      case '0':
        *itaya = *itaya + 1;
        break;
      case '#':
        *itaya = *itaya + 1;
        break;
      case '-':
        myflags->minus = 1;
        *itaya = *itaya + 1;
        break;
      case '+':
        myflags->plus = 1;
        *itaya = *itaya + 1;
        break;
      case ' ':
        myflags->enter = 1;
        *itaya = *itaya + 1;
        break;

      default:
        break;
    }
  }
}

// парсим точность
int parse_accuracy(const char *format, int *itaya) {
  int accuracy = 0;
  char str_accuracy[BUFF_SIZE] = {'\0'};
  str_accuracy[0] = '0';
  if (format[*itaya] == '.') {
    *itaya = *itaya + 1;
    while ((int)format[*itaya] > 47 && (int)format[*itaya] < 58) {
      str_accuracy[accuracy] = format[*itaya];
      accuracy++;
      *itaya = *itaya + 1;
    }
  } else {
    str_accuracy[0] = '-';
    str_accuracy[1] = '1';
  }
  return s21_atoi(str_accuracy);
}

// принт точности для интовых значений
void print_accuracy_int(char *str, int *jitaya, int accuracy, int int_count) {
  if (accuracy > int_count) {
    while (accuracy > int_count) {
      str[*jitaya] = '0';
      *jitaya = *jitaya + 1;
      accuracy--;
    }
  }
}

// парсим длину
void lenght_reader(const char *format, int *itaya, flags *myflags) {
  if (format[*itaya] == 'h' || format[*itaya] == 'l') {
    switch (format[*itaya]) {
      case 'h':
        myflags->short_int = 1;
        *itaya = *itaya + 1;
        break;
      case 'l':
        myflags->long_int = 1;
        *itaya = *itaya + 1;
        break;
      default:
        break;
    }
  }
}

// чистим флаги
void clear_flag(flags *myflags, instructions *instruction) {
  myflags->enter = 0;
  myflags->plus = 0;
  myflags->minus = 0;
  myflags->long_int = 0;
  myflags->short_int = 0;
  instruction->float_instruction = 0;
  instruction->integer = 0;
  instruction->unsigned_integer = 0;
  instruction->char_instruction = 0;
  instruction->string_instruction = 0;
  instruction->percent_instruction = 0;
}
// принтим флоат
void print_float(char *str, int *jitaya, va_list *input, int width,
                 flags myflags, int accuracy) {
  if (accuracy == -1) {
    accuracy = 6;
  }
  int sign = 0, result_long = 0;
  double printed_double = (double)va_arg(*input, double);
  if (printed_double < 0.0) {
    printed_double = printed_double * -1;
    sign = 1;
  }
  if (myflags.plus) sign = 1;
  double whole_part = 0, fraction_part = 0;
  long int whole_part_int = 0, fraction_part_int = 0;
  if (accuracy == 0) {
    whole_part_int = roundl(printed_double);
  } else {
    fraction_part =
        modf(printed_double, &whole_part);  // отделяет целую часть от дробной
    whole_part_int = whole_part;
    for (int i = 0; i < accuracy; i++) {  // переводим дробную часть в целую,
      fraction_part = fraction_part * 10;  // относительно точности
    }
  }
  fraction_part_int = roundl(fraction_part);  // округляем
  char str_whole_part[BUFF_SIZE] = {0};
  char str_fraction_part[BUFF_SIZE] = {0};
  int whole_part_count = integer_count(whole_part_int);
  itoa(whole_part_int, str_whole_part);
  itoa(fraction_part_int, str_fraction_part);
  if (fraction_part_int == 0.0 && accuracy) {
    for (int i = 0; i < accuracy; ++i) {
      str_fraction_part[i] = '0';
    }
  }

  result_long = whole_part_count + accuracy + sign;
  if (accuracy) result_long++;
  ifi_i_fori_dlya_floata(myflags, result_long, width, str, jitaya, sign,
                         accuracy, str_whole_part, str_fraction_part,
                         whole_part_count);
}

// принтим ширину для флоатов))
void width_print_for_floats(int width, int result_long, int *jitaya,
                            char *str) {
  if (width > 0 && result_long < width) {
    for (int i = 0; i < width - result_long; i++) {
      str[*jitaya] = ' ';
      *jitaya = *jitaya + 1;  // принтим пробелы ширины
    }
  }
}
// помогаем флоат принт стать меньше))
void ifi_i_fori_dlya_floata(flags myflags, int result_long, int width,
                            char *str, int *jitaya, int sign, int accuracy,
                            char str_whole_part[], char str_fraction_part[],
                            int whole_part_count) {
  if (!myflags.minus && result_long < width) {
    width_print_for_floats(width, result_long, jitaya, str);
  }
  if (width < result_long && myflags.enter && !myflags.plus) {
    str[*jitaya] = ' ';
    *jitaya = *jitaya + 1;
  }
  if (sign == 1) {
    if (!myflags.plus)
      str[*jitaya] = '-';  // принт знака
    else
      str[*jitaya] = '+';
    *jitaya = *jitaya + 1;
  }
  for (int i = 0; i < whole_part_count; i++) {
    str[*jitaya] = str_whole_part[i];  // принт целой части
    *jitaya = *jitaya + 1;
  }
  if (accuracy) {
    str[*jitaya] = '.';  // точечка епта,если точность не равна нулю
    *jitaya = *jitaya + 1;
  }
  for (int i = 0; i < accuracy; i++) {
    str[*jitaya] = str_fraction_part[i];  // принт дробной части
    *jitaya = *jitaya + 1;
  }
  if (myflags.minus && result_long < width) {
    width_print_for_floats(width, result_long, jitaya, str);
  }
}
// принт беззнакового числа
void print_unsigned(char *str, int *jitaya, va_list *input, int width,
                    flags myflags, int accuracy) {
  long unsigned int printed_int = 0;
  if (myflags.long_int == 1) {  // костыли для длинны
    printed_int = (long unsigned int)va_arg(*input, long int);
  } else if (myflags.short_int == 1) {
    printed_int = (short unsigned int)va_arg(*input, int);
  } else
    printed_int = (int)va_arg(*input, int);

  long long int arg_symbols_count = integer_count(printed_int);
  if (myflags.minus != 1) {
    width_print(width, arg_symbols_count, jitaya, str, accuracy);
  }
  char integer_characters[BUFF_SIZE];  // буффер для перевода инта в строку
  long long int int_count =
      itoa(printed_int, integer_characters);  // переводим инт в строку
  print_accuracy_int(str, jitaya, accuracy, int_count);
  for (int i = 0; i < int_count; i++) {
    str[*jitaya] = integer_characters[i];  // принт непосредственно числа
    *jitaya = *jitaya + 1;
  }
  if (myflags.minus == 1) {
    width_print(width, arg_symbols_count, jitaya, str, accuracy);
  }
}
// принтим чар
void print_char(char *str, int *jitaya, va_list *input, int width,
                flags myflags) {
  char printed_char = (char)va_arg(*input, int);
  if (myflags.minus != 1 && width > 1) {
    width_print(width, 1, jitaya, str, 0);
  }
  str[*jitaya] = printed_char;
  *jitaya = *jitaya + 1;
  if (myflags.minus == 1 && width > 1) {
    width_print(width, 1, jitaya, str, 0);
  }
}
// принтим процент
void print_percent(char *str, int *jitaya, int width, flags myflags) {
  if (myflags.minus != 1) {
    width_print(width, 1, jitaya, str, 0);
  }
  str[*jitaya] = '%';
  *jitaya = *jitaya + 1;
  if (myflags.minus == 1) {
    width_print(width, 1, jitaya, str, 0);
  }
}
// принтим стринг
void print_string(char *str, int *jitaya, va_list *input, int width,
                  flags myflags) {
  char *variable_str = va_arg(*input, char *);
  int var_lenght = s21_strlen(variable_str);
  if (width > var_lenght && !myflags.minus) {
    width_print(width, var_lenght, jitaya, str, 0);
  }
  for (int i = 0; i < var_lenght; i++) {
    str[*jitaya] = variable_str[i];
    *jitaya = *jitaya + 1;
  }
  if (width > var_lenght && myflags.minus) {
    width_print(width, var_lenght, jitaya, str, 0);
  }
}
#endif
