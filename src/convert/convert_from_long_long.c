#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_long_long(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[21];
  const long long number = va_arg(*args, long long);

  if (fmt->flag & PLUS && number > -1) {
    ft_lltoa(number, str + 1, DECIMAL);
    *str = '+';
  } else
    ft_lltoa(number, str, DECIMAL);
  wrapper_decorator(fmt, buffer, str, NUMBER);
}
