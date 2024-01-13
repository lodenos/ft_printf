#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"
#include "libft.h"

void __no_name_yet(t_fmt *fmt, t_list *buffer, va_list *args)  {
  if (fmt->type == 'c')
    convert_from_character(fmt, buffer, args);
  else if (fmt->type == 's')
    convert_from_string(fmt, buffer, args);
  else if (fmt->type == 'p')
    convert_from_void_ptr(fmt, buffer, args);
  else if (fmt->type == 'd')
    convert_from_int(fmt, buffer, args);
  else if (fmt->type == 'i')
    convert_from_int(fmt, buffer, args);
  else if (fmt->type == 'u')
    convert_from_u_int(fmt, buffer, args);
  else if (fmt->type == 'x')
    convert_from_u_int(fmt, buffer, args);
  else if (fmt->type == 'X')
    convert_from_u_int(fmt, buffer, args);
  else if (fmt->type == '%') {
    if (fmt->flag == '0') {
      list_push(buffer, list_new_node(ft_strdup("%"), 2));
      if (fmt->width > 0)
        fmt->width -= 1;
      wrapper_padding(fmt, buffer, "", STRING);
    } else
      wrapper_padding(fmt, buffer, "%", STRING);
  }
}

static char *__handler_format(t_list *buffer, char *format, char *head,
    va_list *args) {
  t_fmt fmt;
  size_t size;

  fmt = (t_fmt){ 0 };
  size = format - head - 1;
  list_push(buffer, list_new_node(ft_strndup(head, size), size + 1));
  format = format_specifier(&fmt, format);

  __no_name_yet(&fmt, buffer, args);

  return format;
}

static int __print_buffer(t_list *buffer) {
  int num;
  t_string *string;

  string = list_to_string(buffer);
  num = write(1, string->data, string->size);
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
  size = format - head;
  list_push(&buffer, list_new_node(ft_strndup(head, size), size + 1));
  num = __print_buffer(&buffer); 
  list_clear(&buffer, NULL);
  return num;
}
