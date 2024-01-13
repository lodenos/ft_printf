#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_from_u_int(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[14];
  unsigned int number = va_arg(*args, unsigned int);

  if (fmt->type == 'X') {
    if (fmt->flag == '#' && number) {
      str[0] = '0';
      str[1] = 'X';
      ft_utoa(number, str + 2, HEX);
    } else
      ft_utoa(number, str, HEX);
  } else if (fmt->type == 'o')
    ft_utoa(number, str, OCTAL);
  else if (fmt->type == 'u')
    ft_utoa(number, str, DECIMAL);
  else if (fmt->type == 'x') {
    if (fmt->flag == '#' && number) {
      str[0] = '0';
      str[1] = 'x';
      ft_strlwr(ft_utoa(number, str + 2, HEX));
    } else
      ft_strlwr(ft_utoa(number, str, HEX));
  }
  wrapper_padding(fmt, buffer, str, NUMBER);
}
