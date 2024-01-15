#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_int(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[12];
  const int number = va_arg(*args, int);

  if (fmt->flag & PLUS && number > -1) {
    ft_itoa(number, str + 1, DECIMAL);
    *str = '+';
  } else
    ft_itoa(number, str, DECIMAL);
  wrapper_decorator(fmt, buffer, str, NUMBER);
}
