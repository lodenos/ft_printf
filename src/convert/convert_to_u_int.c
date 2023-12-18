#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_to_u_int(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[14];

  if (fmt->type == 'X') {
    if (fmt->flag == '#') {
      str[0] = '0';
      str[1] = 'X';
      ft_utoa((unsigned int)va_arg(*args, unsigned int), str + 2, HEX);
    } else
      ft_utoa((unsigned int)va_arg(*args, unsigned int), str, HEX);
  } else if (fmt->type == 'o')
    ft_utoa((unsigned int)va_arg(*args, unsigned int), str, OCTAL);
  else if (fmt->type == 'u')
    ft_utoa((unsigned int)va_arg(*args, unsigned int), str, DECIMAL);
  else if (fmt->type == 'x') {
    if (fmt->flag == '#') {
      str[0] = '0';
      str[1] = 'x';
      ft_utoa((unsigned int)va_arg(*args, unsigned int), str + 2, HEX);
    } else
      ft_utoa((unsigned int)va_arg(*args, unsigned int), str, HEX);
    ft_strlwr(str);
  }
  wrapper_padding(fmt, buffer, str);
}
