#include "ft_printf.h"

char *format_specifier_length(t_fmt *fmt, char *format) {
  if (*format == 'L') {
    fmt->length = LONG_DOUBLE;
    return ++format;
  } else if (*format == 'h') {
    if (format[1] == 'h') {
      fmt->length = CHAR;
      return format + 2;
    }
    fmt->length = SHORT;
    return ++format;
  } else if (*format == 'j') {
    fmt->length = LONG_LONG; // INTMAX
    return ++format;
  } else if (*format == 'l') {
    if (format[1] == 'l') {
      fmt->length = LONG_LONG;
      return format + 2;
    }
    fmt->length = LONG;
    return ++format;
//  } else if (*format == 't') {
//    fmt->length = UNSUPPORTED;
//    return ++format;
  } else if (*format == 'z') {
    fmt->length = SIZE;
    return ++format;
  } else
    fmt->length = NONE;
  return format;
}
