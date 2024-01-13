#include "ft_printf.h"
#include "ft_string.h"

void convert_from_character(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[2] = { 0 };

  (void)fmt;
  tmp[0] = (char)va_arg(*args, int);
  wrapper_padding(fmt, buffer, tmp, CHARACTER);
}
