#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_u_long_long(t_fmt *fmt, t_string_build *buffer,
    va_list *args) {
  char token[23]; // 23 + 1;
  const unsigned long long number = va_arg(*args, unsigned long long);

  if (fmt->type == 'X')
    ft_ulltoa(number, token, HEX);
  else if (fmt->type == 'o')
    ft_ulltoa(number, token, OCTAL);
  else if (fmt->type == 'u')
    ft_ulltoa(number, token, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_ulltoa(number, token, HEX));
  token_decorator_number(fmt, buffer, token);
}
