#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_printf(char const *format, ...) {
  va_list args;
  t_string *string;
  t_string_build *buffer;
  char *head;
  int num;
  t_fmt fmt;

  (void)head;
  va_start(args, format);
  head =
    (char *)format;
  buffer = string_build_new();
  if (!buffer)
    return -1;
  while (*format) {
    if (*format == '%') {
      fmt = (t_fmt){0};
      string_build_append_str(buffer, head, format++ - head);
      format = format_specifier(&fmt, (char *)format);
      format_specifier_to_string(&fmt, buffer, &args);
      head = (char *)format;
      continue ;
    }
    ++format;
  }
  string_build_append_str(buffer, head, (size_t)(format - head)); 
  string = string_build_yield(buffer);
  if (!string) {
    string_build_delete(&buffer);
    return -1;
  }
  num = (int)write(1, string->data->ptr, string->size);
  string_delete(&string);
  string_build_delete(&buffer);

  if (list_register()->fn) {
    free(list_register()->fn);
    list_register()->size_max = 0;
    list_register()->size = 0;
  }
  va_end(args);
  return num;
}
