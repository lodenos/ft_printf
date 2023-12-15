#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_to_short(t_fmt *fmt, t_list *buffer, va_list *args) {
  char *data;

  (void)fmt;
  data = (char *)malloc(7);
  if (!data)
    return ;
  ft_itoa((short)va_arg(*args, int), data, DECIMAL);
  list_push(buffer, list_new_node(data, 7));
}
