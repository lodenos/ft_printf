#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"
#include "libft.h"

static char *__handler_format(t_list *buffer, char *format, char *head,
    va_list *args) {
  t_fmt fmt;
  size_t size;

  fmt = (t_fmt){ 0 };
  size = (size_t)(format - head - 1);
  list_push(buffer, list_new_node(ft_strndup(head, size), size + 1));
  format = format_specifier(&fmt, format);
  format_specifier_to_string(&fmt, buffer, args);
  return format;
}

static int __print_buffer(t_list *buffer) {
  int num;
  t_string *string;

  string = list_to_string(buffer);
  num = (int)write(1, string->data, string->data_size);
  ft_string_free(&string);
  return num;
}

int ft_printf(char const *format, ...) {
  va_list args;
  t_list buffer;
  char *head;
  int num;
  size_t size;

  buffer = (t_list){ 0 };
  head = (char *)format;
  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format = __handler_format(&buffer, (char *)++format, head, &args);
      head = (char *)format;
      continue ;
    }
    ++format;
  }
  va_end(args);
  size = (size_t)(format - head);
  list_push(&buffer, list_new_node(ft_strndup(head, size), size + 1));
  num = __print_buffer(&buffer); 
  list_clear(&buffer, NULL);
  return num;
}
