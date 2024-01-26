#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_void_ptr(t_fmt *fmt, t_list *buffer, va_list *args) {
  t_string string;
  char number[19]; // 2 + 16 + 1;

  number[0] = '0';
  number[1] = 'x';
  ft_ulltoa((unsigned long long)va_arg(*args, void *), number + 2, HEX);
  string = (t_string) {
    .data = ft_strlwr(number),
    .data_size = ft_strlen(number),
    .ptr_size = 19
  };
  token_decorator_string(fmt, buffer,  &string);
}
