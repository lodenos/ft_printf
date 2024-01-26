#include <stdlib.h>
#include "ft_printf.h"
#include "ft_string.h"

void token_decorator_number(t_fmt *fmt, t_list *buffer, t_string *string) {
  t_string chunk;

  chunk = (t_string){0};
  if (fmt->width != UNDEFINED) {
    if ((size_t)fmt->width > string->data_size)
      chunk.data_size = fmt->width;
    else
      chunk.data_size = string->data_size;

  } else {
    chunk.data_size = string->data_size;
  }

  chunk.ptr_size = chunk.data_size + 1;
  chunk.data = (char *)malloc(chunk.ptr_size);
  if (!chunk.data)
    return ;
  chunk.data[chunk.data_size] = 0;

  ft_memset(chunk.data, ' ', chunk.data_size);
  ft_memcpy(chunk.data, string->data, string->data_size);

  list_push(buffer, list_new_node(chunk.data, chunk.ptr_size));
}
