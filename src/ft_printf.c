#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

static t_list *list_merge_data(t_list *list) {
  size_t size;
  void *memory;
  t_list_node *node = list->head;

  size = 0;
  while (node) {
    size += node->size;
    node = node->next;
  }
  memory = malloc(size);
  if (!memory)
    return NULL;
  node = list->head;
  size = 0;
  while (node) {
    ft_memcpy(memory + size, node->data, node->size);
    size += node->size;
    node = node->next;
  }
  return list_new(memory, size);
}


int ft_printf(char const *format, ...) {
  va_list args;
  int num;
  t_list buffer;
  char *head;

  size_t size;

  head = (char *)format;
  va_start(args, format);
  while (*format) {

    if (*format == '%') {
      size = format - head;

      list_push(&buffer, list_new_node(ft_strndup(head, size), size));

      format = format_specifier_type(++format, &args);

      head = (char *)format;
      continue ;
    }
    ++format;
  }
  va_end(args);


  t_list *print = list_merge_data(&buffer);
  list_clear(&buffer, NULL);
  num = write(1, print->head->data, ft_strlen(print->head->data));
  list_clear(print, NULL);
  return num;
}
