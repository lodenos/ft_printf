#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_short(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[7]; // 1 + 5 + 1
  const short number = (short)va_arg(*args, int);

  if (fmt->flag & PLUS && number > -1) {
    *token = '+';
    ft_itoa(number, token + 1, DECIMAL);
  } else
    ft_itoa(number, token, DECIMAL);
  token_decorator_number(fmt, buffer, token);
}
