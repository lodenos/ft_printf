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

    if (*(char *)node->data == -1) {

      ((char *)memory)[size] = 0;
      size += 1;
      node = node->next;
      continue ;
    }

    ft_memcpy((char *)memory + size, node->data, ft_strlen(node->data));
    size += ft_strlen(node->data);
    node = node->next;
  }
  return list_new(memory, size);
}

static void add_str(t_fmt *fmt, t_list *buffer, va_list *args) {
  if (fmt->type == '%') {

    //va_arg(*args, int);
    list_push(buffer, list_new_node(ft_strdup("%"), 2));

  } else if (fmt->type == 'c')
    convert_to_character(fmt, buffer, args);
  else if (fmt->type == 'd' || fmt->type == 'i')
    convert_to_int(fmt, buffer, args);
  else if (fmt->type == 'o')
    convert_to_u_int(fmt, buffer, args);
  else if (fmt->type == 'p')
    convert_to_void_ptr(fmt, buffer, args);
  else if (fmt->type == 's')
    convert_to_string(fmt, buffer, args);
  else if (fmt->type == 'u')
    convert_to_u_int(fmt, buffer, args);
  else if (fmt->type == 'x')
    convert_to_u_int(fmt, buffer, args);
  else if (fmt->type == 'X')
    convert_to_u_int(fmt, buffer, args);
}

int ft_printf(char const *format, ...) {
  va_list args;
  ssize_t num;
  t_list buffer;
  char *head;
  size_t size;
  t_fmt fmt;
  head = (char *)format;
  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      ++format;

      fmt = (t_fmt){ 0 };
      size = format - head - 1;
      //printf("> %s\n", ft_strndup(head, size));


      list_push(&buffer, list_new_node(ft_strndup(head, size), size));
      format = format_specifier(&fmt, (char *)format);


      add_str(&fmt, &buffer, &args);
      head = (char *)format;

      continue ;
    }
    ++format;
  }
  va_end(args);
  size = format - head;
  list_push(&buffer, list_new_node(ft_strndup(head, size), size));
  t_list *print = list_merge_data(&buffer);
  list_clear(&buffer, NULL);
  num = write(1, print->head->data, print->head->size);
  list_clear(print, NULL);
  free(print);
  return num;
}
