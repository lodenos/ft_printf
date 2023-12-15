#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_to_void_ptr(t_fmt *fmt, t_list *buffer, va_list *args) {
  char *data = (char *)malloc(17);

  (void)fmt;
  if (!data)
    return ;
  ft_ulltoa((unsigned long long)va_arg(*args, void *), data, HEX);
  list_push(buffer, list_new_node(ft_strdup("0x"), 3));
  list_push(buffer, list_new_node(ft_strlwr(data), 17));
}
