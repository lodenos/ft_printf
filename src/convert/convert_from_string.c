#include "ft_printf.h"

#define STRING_NULL "(null)"

void convert_from_string(t_fmt *fmt, t_list *buffer, va_list *args) {
  t_string string;
  char const *str = va_arg(*args, char *);

  if (!str) {
    string = (t_string) { STRING_NULL, 6, 7 };
  }
  else {
    string = (t_string) {
      .data = (char *)str,
      .data_size = ft_strlen(str),
    };
    string.ptr_size = string.data_size + 1;
  }
  token_decorator_string(fmt, buffer, &string);
}
