#include "ft_printf.h"

void convert_to_string(t_fmt *fmt, t_list *buffer, va_list *args) {
  char const *str = va_arg(*args, char *);

  if (!str) {
    wrapper_padding(fmt, buffer, "(null)");
    return ;
  }
  wrapper_padding(fmt, buffer, str);
}
