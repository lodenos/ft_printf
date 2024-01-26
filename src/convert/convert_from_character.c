#include "ft_printf.h"

void convert_from_character(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[2];
  t_string string;

  (void)fmt;
  *tmp = (char)va_arg(*args, int);
  string = (t_string) {
    .data = tmp,
    .data_size = (*tmp) ? 1 : 0,
    .ptr_size = 2
  };
  token_decorator_character(fmt, buffer, &string);
}
