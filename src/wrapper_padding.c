#include <stdlib.h>
#include "ft_printf.h"
#include "ft_string.h"
#include "list.h"
#include "ft_ctype.h"

void wrapper_padding(t_fmt *fmt, t_list *buffer, char const *str, int type) {
  int str_len;
  int chunk_len;
  char *padding;
  size_t padding_len;
  char *chunk;

  str_len = ft_strlen(str);
  padding = NULL;
  padding_len = 0;
  chunk = NULL;
  chunk_len = 0;

  switch (type) {
  case CHARACTER:
  case STRING:
    if (fmt->precision == UNDEFINED) {
      if (type == CHARACTER) {
        chunk = malloc(2);
        ft_memcpy(chunk, str, 2);
        chunk_len = 1;
      } else {
        chunk = ft_strdup(str);
        chunk_len = ft_strlen(chunk);
      }
    } else {
      if (fmt->precision == 0) {
        if (type == CHARACTER) {
          chunk = ft_strdup(str);
          chunk_len = ft_strlen(chunk);
        } else {
          chunk = ft_strdup("");
          chunk_len = 0;
        }
      } else {
        if (fmt->precision > str_len) {
          chunk = ft_strdup(str);
          chunk_len = ft_strlen(chunk);
        } else {
          chunk_len = fmt->precision;
          chunk = (char *)malloc(chunk_len + 1);
          chunk[chunk_len] = 0;
          ft_memcpy(chunk, str, chunk_len);
        }
      }
    }
    if (fmt->width == UNDEFINED) {
      list_push(buffer, list_new_node(chunk, chunk_len + 1));
    } else {
      if (fmt->width > chunk_len) {
        padding_len = fmt->width - chunk_len;
        padding = (char *)malloc(padding_len + 1);
        padding[padding_len] = 0;
        ft_memset(padding, ' ', padding_len);
        if (fmt->flag == '-') {
          list_push(buffer, list_new_node(chunk, chunk_len + 1));
          list_push(buffer, list_new_node(padding, padding_len + 1));
        } else {
          list_push(buffer, list_new_node(padding, padding_len + 1));
          list_push(buffer, list_new_node(chunk, chunk_len + 1));
        }
      } else {
        list_push(buffer, list_new_node(chunk, chunk_len + 1));
      }
    }
    break ;
  case NUMBER:
    if (fmt->precision == UNDEFINED) { 
      chunk = ft_strdup(str);
      chunk_len = ft_strlen(chunk);
    } else if (fmt->precision == 0) {
      if (str_len == 1 && *str == '0') {
        chunk = ft_strdup("");
        chunk_len = 0;
      } else {
        chunk = ft_strdup(str);
        chunk_len = ft_strlen(chunk);
      }
    } else {
      int shift = (*str == '-') ? 1 : 0;

      if (fmt->precision > (str_len - shift)) {
        chunk_len = fmt->precision + shift;
        chunk = (char *)calloc(chunk_len + 1, 1); // malloc
        chunk[chunk_len] = 0;
        if (shift)
          *chunk = '-';
        ft_memset(chunk + shift, '0', fmt->precision - (str_len - shift));
        ft_memcpy(chunk + shift + fmt->precision - (str_len - shift),
          str + shift, str_len - shift);
      } else {
        chunk = ft_strdup(str);
        chunk_len = ft_strlen(chunk);
      }
    }
    if (fmt->width == UNDEFINED) {
      if (fmt->precision == UNDEFINED) {
        if (fmt->flag == ' ' && *chunk != '-')
          list_push(buffer, list_new_node(ft_strdup(" "), 2));
        list_push(buffer, list_new_node(chunk, chunk_len + 1));
      } else {
        list_push(buffer, list_new_node(chunk, chunk_len + 1));
      }
    } else {
      if (fmt->width > chunk_len) {
        padding_len = fmt->width - chunk_len;
        padding = (char *)malloc(padding_len + 1);
        padding[padding_len] = 0;
        if (fmt->flag == '0' && fmt->precision == UNDEFINED)
          ft_memset(padding, '0', padding_len);
        else
          ft_memset(padding, ' ', padding_len);
        if (fmt->flag == '-') {
          list_push(buffer, list_new_node(chunk, chunk_len + 1));
          list_push(buffer, list_new_node(padding, padding_len + 1));
        } else {
          if (fmt->flag == '0' && *chunk == '-') {
            if (fmt->precision == UNDEFINED) {
              *padding ^= *chunk;
              *chunk ^= *padding;
              *padding ^= *chunk;
            }
          }
          list_push(buffer, list_new_node(padding, padding_len + 1));
          list_push(buffer, list_new_node(chunk, chunk_len + 1));
        }
      } else {
        list_push(buffer, list_new_node(chunk, chunk_len + 1));
      }
    }
    break;
  }
}
