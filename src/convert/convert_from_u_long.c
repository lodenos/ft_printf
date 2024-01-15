#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_from_u_long(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[14];
  const unsigned long number = va_arg(*args, unsigned long);

  if (fmt->type == 'X')
    ft_ultoa(number, str, HEX);
  else if (fmt->type == 'o')
    ft_ultoa(number, str, OCTAL);
  else if (fmt->type == 'u')
    ft_ultoa(number, str, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_ultoa(number, str, HEX));
  wrapper_decorator(fmt, buffer, str, NUMBER);
}
