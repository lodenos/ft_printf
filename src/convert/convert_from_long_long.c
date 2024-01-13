#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"

void convert_to_long_long(t_fmt *fmt, t_list *buffer, va_list *args) {
  char *data;

  (void)fmt;
  data = (char *)malloc(21);
  if (!data)
    return ;
  ft_lltoa(va_arg(*args, long long), data, DECIMAL);
  list_push(buffer, list_new_node(data, 21));
}
