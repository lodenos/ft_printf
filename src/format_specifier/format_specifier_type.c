#include "ft_printf.h"

char *format_specifier_type(t_fmt *fmt, char *format) {
  if (*format == '%') {
    fmt->type = '%';
    return ++format;
  } else if (*format == 'A') {
    fmt->type = 'A';
    return ++format;
  } else if (*format == 'E') {
    fmt->type = 'E';
    return ++format;
  } else if (*format == 'F') {
    fmt->type = 'F';
    return ++format;
  } else if (*format == 'G') {
    fmt->type = 'G';
    return ++format;
  } else if (*format == 'X') {
    fmt->type = 'X';
    return ++format;
  } else if (*format == 'a') {
    fmt->type = 'a';
    return ++format;
  } else if (*format == 'c') {
    fmt->type = 'c';
    return ++format;
  } else if (*format == 'd') {
    fmt->type = 'd';
    return ++format;
  } else if (*format == 'e') {
    fmt->type = 'e';
    return ++format;
  } else if (*format == 'f') {
    fmt->type = 'f';
    return ++format;
  } else if (*format == 'g') {
    fmt->type = 'g';
    return ++format;
  } else if (*format == 'i') {
    fmt->type = 'i';
    return ++format;
  } else if (*format == 'n') {
    fmt->type = 'n';
    return ++format;
  } else if (*format == 'o') {
    fmt->type = 'o';
    return ++format;
  } else if (*format == 'p') {
    fmt->type = 'p';
    return ++format;
  } else if (*format == 's') {
    fmt->type = 's';
    return ++format;
  } else if (*format == 'u') {
    fmt->type = 'u';
    return ++format;
  } else if (*format == 'x') {
    fmt->type = 'x';
    return ++format;
  }
  return format;
}
