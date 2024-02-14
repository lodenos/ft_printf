#include "ft_printf.h"
#include "ft_string.h"

void token_decorator_string(t_fmt *fmt, t_string_build *buffer, char *str) {
  (void)fmt;

  string_build_append_str(buffer, str, ft_strlen(str));

 /*
 t_string chunk;

  chunk = (t_string){0};
  if (fmt->precision != UNDEFINED) {
    if ((size_t)fmt->precision > string->data_size)
      chunk.data_size = string->data_size;
    else
      chunk.data_size = (size_t)fmt->precision;
  } else
    chunk.data_size = string->data_size;
  if (fmt->width != UNDEFINED) {
    if ((size_t)fmt->width > chunk.data_size)
      chunk.data_size = (size_t)fmt->width;
  }
  if (fmt->width == UNDEFINED && fmt->precision == UNDEFINED)
    chunk.data_size = string->data_size;
  chunk.ptr_size = chunk.data_size + 1;
  chunk.data = (char *)malloc(chunk.ptr_size);
  if (!chunk.data)
    return ;
  chunk.data[chunk.data_size] = 0;
  if (fmt->width != UNDEFINED)
    ft_memset(chunk.data, ' ', chunk.data_size);
  size_t shift = 0;
  if (fmt->precision != UNDEFINED) {
    if ((size_t)fmt->precision > string->data_size) {
      if (fmt->flag & MINUS) {
        ft_memcpy(chunk.data, string->data, string->data_size);
      } else {
        shift = chunk.data_size - string->data_size;
        ft_memcpy(chunk.data + shift, string->data, string->data_size);
      }
    } else {
      if (fmt->flag & MINUS)
        ft_memcpy(chunk.data + shift, string->data, fmt->precision);
      else {
        shift = chunk.data_size - fmt->precision;;
        ft_memcpy(chunk.data + shift, string->data, fmt->precision);
      }
    }
  } else {
    if (fmt->flag & MINUS)
      ft_memcpy(chunk.data + shift, string->data, string->data_size);
    else {
      shift = chunk.data_size - string->data_size;
      ft_memcpy(chunk.data + shift, string->data, string->data_size);
    }
  }
  list_push(buffer, list_new_node(chunk.data, chunk.ptr_size));
  */
}
