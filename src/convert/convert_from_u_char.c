#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_u_char(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[4]; // 3 + 1
  t_string string;
  const unsigned char number = (unsigned char)va_arg(*args, unsigned int);

  if (fmt->type == 'X')
    ft_utoa(number, tmp, HEX);
  else if (fmt->type == 'o')
    ft_utoa(number, tmp, OCTAL);
  else if (fmt->type == 'u')
    ft_utoa(number, tmp, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_utoa(number, tmp, HEX));
  string = (t_string) {
    .data = tmp,
    .data_size = ft_strlen(tmp),
    .ptr_size = 4
  };
  token_decorator_number(fmt, buffer, &string);
}
