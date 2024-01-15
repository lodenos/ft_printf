#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_from_u_short(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[8];
  const unsigned short number = va_arg(*args, unsigned int);

  if (fmt->type == 'X')
    ft_utoa(number, str, HEX);
  else if (fmt->type == 'o')
    ft_utoa(number, str, OCTAL);
  else if (fmt->type == 'u')
    ft_utoa(number, str, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_utoa(number, str, HEX));
  wrapper_decorator(fmt, buffer, str, NUMBER);
}
