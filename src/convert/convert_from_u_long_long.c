#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_u_long_long(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[23]; // 23 + 1
  t_string string;
  const unsigned int number = va_arg(*args, unsigned int);

  if (fmt->type == 'X')
    ft_ulltoa(number, tmp, HEX);
  else if (fmt->type == 'o')
    ft_ulltoa(number, tmp, OCTAL);
  else if (fmt->type == 'u')
    ft_ulltoa(number, tmp, DECIMAL);
  else if (fmt->type == 'x')
    ft_strlwr(ft_ulltoa(number, tmp, HEX));
  string = (t_string) {
    .data = tmp,
    .data_size = ft_strlen(tmp),
    .ptr_size = 23
  };
  token_decorator_number(fmt, buffer, &string);
}
