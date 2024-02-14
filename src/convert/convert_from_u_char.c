#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_u_char(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[4]; // 3 + 1
  const unsigned char number = (unsigned char)va_arg(*args, unsigned int);

  if (fmt->type == 'X')
    ft_utoa(number, token, HEX);
  else if (fmt->type == 'o')
    ft_utoa(number, token, OCTAL);
  else if (fmt->type == 'u')
    ft_utoa(number, token, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_utoa(number, token, HEX));
  token_decorator_number(fmt, buffer, token);
}
