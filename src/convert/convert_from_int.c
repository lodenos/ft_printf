#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_from_int(t_fmt *fmt, t_list *buffer, va_list *args) {
  char str[12];
  int number = va_arg(*args, int);

  if (fmt->flag == '+' && number > -1) {
    ft_itoa(number, str + 1, DECIMAL);
    *str = '+';
  } else
    ft_itoa(number, str, DECIMAL);
  wrapper_padding(fmt, buffer, str, NUMBER);
}
