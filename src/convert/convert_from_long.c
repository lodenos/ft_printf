#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_long(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[12]; // 1 + 10 + 1
  const long number = va_arg(*args, long);

  if (fmt->flag & PLUS && number > -1) {
    *token = '+';
    ft_ltoa(number, token + 1, DECIMAL);
  } else
    ft_ltoa(number, token, DECIMAL);
  token_decorator_number(fmt, buffer, token);
}
