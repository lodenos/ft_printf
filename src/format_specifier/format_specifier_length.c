#include "ft_printf.h"

char *format_specifier_length(t_fmt *fmt, char *format) {
  fmt->length[1] = 0;

  if (*format == 'L') {
    fmt->length[0] = 'L';
    return ++format;
  } else if (*format == 'h') {
    fmt->length[0] = 'h';
    // hh
    return ++format;
  } else if (*format == 'j') {
    fmt->length[0] = 'j';
    return ++format;
  } else if (*format == 'l') {
    fmt->length[0] = 'l';
    // ll
    return ++format;
  } else if (*format == 't') {
    fmt->length[0] = 't';
    return ++format;
  } else if (*format == 'z') {
    fmt->length[0] = 'z';
    return ++format;
  }
  return format;
}
