#include <stdlib.h>
#include "ft_printf.h"

void token_decorator_character(t_fmt *fmt, t_list *buffer, t_string *string) {
  t_string chunk;

  chunk = (t_string){0};
  if (fmt->width != UNDEFINED) {
    if ((size_t)fmt->width > string->data_size) {
      chunk.data_size = fmt->width;
    } else {
      chunk.data_size = 1;
    }
  } else {
    chunk.data_size = 1;
  }
  chunk.ptr_size = chunk.data_size + 1; 
  chunk.data = (char *)malloc(chunk.ptr_size);
  if (!chunk.data)
    return ;
  ft_memset(chunk.data, ' ', chunk.data_size);
  *chunk.data = *string->data;
  list_push(buffer, list_new_node(chunk.data, chunk.ptr_size));
}
