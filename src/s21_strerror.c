#include "s21_strerror.h"

#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char error[128];
  if ((errnum < 0) || (errnum > ERROR_COUNT)) {
#ifdef __APPLE__
    s21_sprintf(error, "Unknown error: %d", errnum);
#elif __linux__
    s21_sprintf(error, "Unknown error %d", errnum);
#endif
  } else {
    s21_sprintf(error, "%s", errlist[errnum]);
  }
  return error;
}