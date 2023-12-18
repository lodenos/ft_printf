#include "ft_printf.h"

char *format_specifier_precision(t_fmt *fmt, char *format) {
  (void)fmt;
  if (*format == '.') {
    ++format;
    while (*format >= '0' && *format <= '9')
      ++format;
  }
  return format;
}
