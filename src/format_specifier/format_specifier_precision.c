#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

char *format_specifier_precision(t_fmt *fmt, char *format) {
  char *start;
  char *number;

  fmt->precision = UNDEFINED;
  if (*format == '.') {
    ++format;
    if (*format == '*') {
      fmt->precision = -1;
      return ++format;
    }
    start = format;
    while (*format >= '0' && *format <= '9')
      ++format;
    number = ft_strndup(start, (size_t)(format - start));
    fmt->precision = ft_atoi(number);
    free(number);
  }
  return format;
}
