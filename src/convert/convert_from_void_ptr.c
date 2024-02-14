#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_void_ptr(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char token[19]; // 2 + 16 + 1;

  token[0] = '0';
  token[1] = 'x';
  ft_ulltoa((unsigned long long)va_arg(*args, void *), token + 2, HEX);
  token_decorator_string(fmt, buffer, ft_strlwr(token));
}
