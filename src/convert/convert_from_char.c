#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_from_char(t_fmt *fmt, t_list *buffer, va_list *args) {
  char *data;

  (void)fmt;
  data = (char *)malloc(5);
  if (!data)
    return ;
  ft_itoa((char)va_arg(*args, int), data, DECIMAL);
  list_push(buffer, list_new_node(data, 5));
}
