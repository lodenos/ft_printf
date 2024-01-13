#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_from_void_ptr(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[17];

  str[0] = '0';
  str[1] = 'x';
  ft_ulltoa((unsigned long long)va_arg(*args, void *), str + 2, HEX);
  wrapper_padding(fmt, buffer, ft_strlwr(str), STRING);
}
