#include <stdlib.h>
#include "ft_printf.h"
#include "ft_string.h"
#include <stdio.h>

void token_decorator_character(t_fmt *fmt, t_string_build *buffer,
    char *token) {
  (void)fmt;
  (void)buffer;
  (void)token;

  string_build_append_str(buffer, token, 1);

  /*  t_string chunk;

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
  string_build_append(buffer, chunk);
*/
}
