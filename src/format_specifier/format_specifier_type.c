#include "ft_printf.h"
#include "ft_string.h"

char *format_specifier_type(t_fmt *fmt, char *format) {
  if (*format == 'A') {
    fmt->type = *format++;
  } else if (*format == 'C') {
    fmt->type = *format++;
  } else if (*format == 'D') {
    fmt->type = *format++;
  } else if (*format == 'E') {
    fmt->type = *format++;
  } else if (*format == 'F') {
    fmt->type = *format++;
  } else if (*format == 'G') {
    fmt->type = *format++;
  } else if (*format == 'O') {
    fmt->type = *format++;
  } else if (*format == 'S') {
    fmt->type = *format++;
  } else if (*format == 'U') {
    fmt->type = *format++;
  } else if (*format == 'X') {
    fmt->type = *format++;
  } else if (*format == 'a') {
    fmt->type = *format++;
  } else if (*format == 'c') {
    fmt->type = *format++;
  } else if (*format == 'd') {
    fmt->type = *format++;
  } else if (*format == 'e') {
    fmt->type = *format++;
  } else if (*format == 'f') {
    fmt->type = *format++;
  } else if (*format == 'g') {
    fmt->type = *format++;
  } else if (*format == 'i') {
    fmt->type = *format++;
  } else if (*format == 'n') {
    fmt->type = *format++;
  } else if (*format == 'o') {
    fmt->type = *format++;
  } else if (*format == 'p') {
    fmt->type = *format++;
  } else if (*format == 's') {
    fmt->type = *format++;
  } else if (*format == 'u') {
    fmt->type = *format++;
  } else if (*format == 'x') {
    fmt->type = *format++;
  } else if (*format == '%') {
    fmt->type = *format++;
  }
  return format;
}
