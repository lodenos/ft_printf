#include "ft_printf.h"
#include "ft_string.h"

#define STR_NULL "(null)"

#include <stdio.h>

void convert_to_string(t_fmt *fmt, t_list *buffer, va_list *args) {
  char *str;

  (void)fmt;
  str = va_arg(*args, char *);
  if (str)
    list_push(buffer, list_new_node(ft_strdup(str), ft_strlen(str)));
  else
    list_push(buffer, list_new_node(ft_strdup(STR_NULL), ft_strlen(STR_NULL)));
}
