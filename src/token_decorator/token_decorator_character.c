#include <stdlib.h>
#include "ft_printf.h"

void token_decorator_character(t_fmt *fmt, t_list *buffer, t_string *string) {
  char *chunk;

  (void)fmt;
  chunk = (char *)malloc(2);
  if (!chunk)
    return ;
  *chunk = *string->data;
  chunk[1] = 0;

  list_push(buffer, list_new_node(chunk, 2));
}
