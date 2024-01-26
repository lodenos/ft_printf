#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_long_long(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[21]; // 1 + 19 + 1
  t_string string;
  const long long number = va_arg(*args, long long);

  if (fmt->flag & PLUS && number > -1) {
    *tmp = '+';
    ft_lltoa(number, tmp + 1, DECIMAL);
  } else
    ft_lltoa(number, tmp, DECIMAL);
  string = (t_string) {
    .data = tmp,
    .data_size = ft_strlen(tmp),
    .ptr_size = 21
  };
  token_decorator_number(fmt, buffer, &string);
}
