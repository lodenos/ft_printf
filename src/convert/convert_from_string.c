#include "ft_printf.h"

#define STRING_NULL "(null)"

void convert_from_string(t_fmt *fmt, t_string_build *buffer, va_list *args) {
  char const *str = va_arg(*args, char *);

  if (!str)
    token_decorator_string(fmt, buffer, STRING_NULL);
  else
    token_decorator_string(fmt, buffer, (char *)str);
}
