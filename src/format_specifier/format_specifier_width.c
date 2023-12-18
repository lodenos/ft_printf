#include <stdlib.h>

#include "ft_printf.h"

#include "ft_string.h"
#include "ft_stdlib.h"

char *format_specifier_width(t_fmt *fmt, char *format) {
  (void)fmt;
  if (*format == '*') {
    // TODO: add code
    return ++format;
  } else if (*format >= '0' && *format <= '9') {
    char *start = format;
    while (*format >= '0' && *format <= '9')
      ++format;
    char *number = ft_strndup(start, format - start);
    fmt->width = ft_atoi(number);
    free(number);
  }
  return format;
}
