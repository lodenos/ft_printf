#include "ft_printf.h"
#include "ft_string.h"

void convert_to_character(t_fmt *fmt, t_list *buffer, va_list *args) {
  char tmp[2] = { 0 };

  (void)fmt;
  tmp[0] = (char)va_arg(*args, int);
  if (tmp[0] == 0)
    tmp[0] = -1;
  list_push(buffer, list_new_node(ft_strdup(tmp), 2));
}
