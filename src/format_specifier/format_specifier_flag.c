#include "ft_printf.h"

char *format_specifier_flag(t_fmt *fmt, char *format) {
  if (*format == '-') {
    fmt->flag = '-';
    return ++format;
  } else if (*format == '+') {
    fmt->flag = '+';
    return ++format;
  } else if (*format == ' ') {
    fmt->flag = ' ';
    return ++format;
  } else if (*format == '#') {
    fmt->flag = '#';
    return ++format;
  } else if (*format == '0') {
    fmt->flag = '0';
    return ++format;
  } else if (*format == '(') {
    fmt->flag = '(';
    return ++format;
  } else if (*format == ',') {
    fmt->flag = ',';
    return ++format;
  } else if (*format == '$') {
    fmt->flag = '$';
    return ++format;
  } else if (*format == '<') {
    fmt->flag = '<';
    return ++format;
  }
  return format;
}
