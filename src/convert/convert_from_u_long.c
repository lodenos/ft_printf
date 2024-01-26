#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_u_long(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[14]; // 13 + 1
  t_string string;
  const unsigned int number = va_arg(*args, unsigned int);

  if (fmt->type == 'X')
    ft_ultoa(number, tmp, HEX);
  else if (fmt->type == 'o')
    ft_ultoa(number, tmp, OCTAL);
  else if (fmt->type == 'u')
    ft_ultoa(number, tmp, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_ultoa(number, tmp, HEX));
  string = (t_string) {
    .data = tmp,
    .data_size = ft_strlen(tmp),
    .ptr_size = 14
  };
  token_decorator_number(fmt, buffer, &string);
}
