#include <stdlib.h>
#include "ft_printf.h"
#include "ft_string.h"
#include "ft_stdlib.h"

char *format_specifier_width(t_fmt *fmt, char *format) {
  char *start;
  char *number;;

  fmt->width = UNDEFINED;
  if (*format == '*') {
    fmt->width = -1;
    return ++format;
  } else if (*format >= '0' && *format <= '9') {
    start = format;
    while (*format >= '0' && *format <= '9')
      ++format;
    number = ft_strndup(start, (size_t)(format - start));
    fmt->width = ft_atoi(number);
    free(number);
  }
  return format;
}
