#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_u_long(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[14]; // 13 + 1
  const unsigned int number = va_arg(*args, unsigned int);

  if (fmt->type == 'X')
    ft_ultoa(number, token, HEX);
  else if (fmt->type == 'o')
    ft_ultoa(number, token, OCTAL);
  else if (fmt->type == 'u')
    ft_ultoa(number, token, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_ultoa(number, token, HEX));
  token_decorator_number(fmt, buffer, token);
}
