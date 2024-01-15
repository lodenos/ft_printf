#include "ft_printf.h"

char *format_specifier_flag(t_fmt *fmt, char *format) {
  if (*format == ',') {
    fmt->flag |= COMMA;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == '$') {
    fmt->flag |= DOLLAR;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == '#') {
    fmt->flag |= HASH;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == '(') {
    fmt->flag |= LEFT_PARENTHESIS;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == '<') {
    fmt->flag |= LESS_THAN;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == '-') {
    fmt->flag |= MINUS;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == '+') {
    fmt->flag |= PLUS;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == ' ') {
    fmt->flag |= SPACE;
    return format_specifier_flag(fmt, ++format);
  } else if (*format == '0') {
    fmt->flag |= ZERO;
    return format_specifier_flag(fmt, ++format);
  }
  return format;
}
