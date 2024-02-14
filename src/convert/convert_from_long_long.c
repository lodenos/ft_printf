#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_long_long(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[21]; // 1 + 19 + 1
  const long long number = va_arg(*args, long long);

  if (fmt->flag & PLUS && number > -1) {
    *token = '+';
    ft_lltoa(number, token + 1, DECIMAL);
  } else
    ft_lltoa(number, token, DECIMAL);
  token_decorator_number(fmt, buffer, token);
}
