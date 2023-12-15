#include "ft_printf.h"

char *format_specifier(t_fmt *fmt, char *format) {
  format = format_specifier_parameter(fmt, format);
  format = format_specifier_flag(fmt, format);
  format = format_specifier_width(fmt, format);
  format = format_specifier_precision(fmt, format);
  format = format_specifier_length(fmt, format);
  format = format_specifier_type(fmt, format);
  return format;
}
