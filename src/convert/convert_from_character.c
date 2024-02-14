#include "ft_printf.h"

void convert_from_character(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[2];

  *token = (char)va_arg(*args, int);
  token_decorator_character(fmt, buffer, token);
}
