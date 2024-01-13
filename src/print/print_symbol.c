#include "ft_printf.h"

void print_symbol(t_fmt *fmt, t_list *buffer, va_list *args) {
  (void)fmt;
  (void)args;
  list_push(buffer, list_new_node("%", 2));
}
