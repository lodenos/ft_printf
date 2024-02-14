#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_int(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[12]; // 1 + 10 + 1
  const int number = va_arg(*args, int);

  if (fmt->flag & PLUS && number > -1) {
    *token = '+';
    ft_itoa(number, token + 1, DECIMAL);
  } else
    ft_itoa(number, token, DECIMAL);
  token_decorator_number(fmt, buffer, token);
}
