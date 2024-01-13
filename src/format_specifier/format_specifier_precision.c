#include "ft_printf.h"

#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdlib.h>

char *format_specifier_precision(t_fmt *fmt, char *format) {

  fmt->precision = UNDEFINED;

  if (*format == '.') {
    ++format;
    if (*format == '*') {
      fmt->precision = -1;
      return ++format;
    }
    char *start = format;
    while (*format >= '0' && *format <= '9')
      ++format;
    char *number = ft_strndup(start, format - start);
    fmt->precision = ft_atoi(number);
    free(number);
  }
  return format;
}
