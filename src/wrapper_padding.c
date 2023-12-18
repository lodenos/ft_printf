#include <stdlib.h>
#include "ft_printf.h"
#include "ft_string.h"
#include "list.h"

void wrapper_padding(t_fmt *fmt, t_list *buffer, char const *str) {
  size_t const str_len = ft_strlen(str);
  char *padding;
  size_t padding_len;
  char *tmp;

  tmp = ft_strdup(str);
  if (!tmp)
    return ;

  if (fmt->width < str_len) {
    list_push(buffer, list_new_node(tmp, str_len + 1));
    return ;
  }

  padding_len = fmt->width - str_len;
  padding = (char *)malloc(padding_len + 1);
  if (!padding) {
    free(tmp);
    return ;
  }
  padding[padding_len] = 0;

  if (fmt->flag == '0') {
    ft_memset(padding, '0', padding_len);
    list_push(buffer, list_new_node(padding, padding_len + 1));
    list_push(buffer, list_new_node(tmp, str_len + 1));
    return ;
  } 

  ft_memset(padding, ' ', padding_len);
  list_push(buffer, list_new_node(tmp, str_len + 1));
  list_push(buffer, list_new_node(padding, padding_len + 1));
}
