#include <stdlib.h>
#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

void convert_to_u_char(t_fmt *fmt, t_list *buffer, va_list *args) {
  char *data;

  data = (char *)malloc(5);
  if (!data)
    return ;
  if (fmt->type == 'X')
    ft_utoa((unsigned char)va_arg(*args, unsigned int), data, HEX);
  else if (fmt->type == 'o')
    ft_utoa((unsigned char)va_arg(*args, unsigned int), data, OCTAL);
  else if (fmt->type == 'u')
    ft_utoa((unsigned char)va_arg(*args, unsigned int), data, DECIMAL);
  else if (fmt->type == 'x') {
    ft_utoa((unsigned char)va_arg(*args, unsigned int), data, HEX);
    ft_strlwr(data);
  }
  list_push(buffer, list_new_node(data, 5));
}
