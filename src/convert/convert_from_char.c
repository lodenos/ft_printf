#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_char(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[5]; // 1 + 3 + 1
  t_string string;
  const char number = (char)va_arg(*args, int);

  if (fmt->flag & PLUS && number > -1) {
    *tmp = '+';
    ft_itoa(number, tmp + 1, DECIMAL);
  } else
    ft_itoa(number, tmp, DECIMAL);
  string = (t_string) {
    .data = tmp,
    .data_size = ft_strlen(tmp),
    .ptr_size = 5
  };
  token_decorator_number(fmt, buffer, &string);
}
