#include "ft_printf.h"

void convert_from_string(t_fmt *fmt, t_list *buffer, va_list *args) {
  char const *str = va_arg(*args, char *);

  if (!str)
    return wrapper_padding(fmt, buffer, "(null)", STRING);
  wrapper_padding(fmt, buffer, str, STRING);
}
