#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_from_u_long_long(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[23];
  const unsigned long long number = va_arg(*args, unsigned long long);

  if (fmt->type == 'X')
    ft_ulltoa(number, str, HEX);
  else if (fmt->type == 'o')
    ft_ulltoa(number, str, OCTAL);
  else if (fmt->type == 'u')
    ft_ulltoa(number, str, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_ulltoa(number, str, HEX));
  wrapper_decorator(fmt, buffer, str, NUMBER);
}
