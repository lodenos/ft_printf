#include "ft_printf.h"

static void length_int(t_fmt *fmt, t_list *buffer, va_list *args) {
  if (fmt->length == NONE)
    convert_from_int(fmt, buffer, args);
  else if (fmt->length == CHAR)
    convert_from_char(fmt, buffer, args);
  else if (fmt->length == SHORT)
    convert_from_short(fmt, buffer, args);
  else if (fmt->length == LONG)
   convert_from_long(fmt, buffer, args);
  else if (fmt->length == LONG_LONG)
    convert_from_long_long(fmt, buffer, args);
  else if (fmt->length == LONG_DOUBLE)
    ;
  else if (fmt->length == SIZE) 
    convert_from_long_long(fmt, buffer, args);
  else
    ;
}

static void length_u_int(t_fmt *fmt, t_list *buffer, va_list *args) {
  if (fmt->length == NONE)
    convert_from_u_int(fmt, buffer, args);
  else if (fmt->length == CHAR)
    convert_from_u_char(fmt, buffer, args);
  else if (fmt->length == SHORT)
    convert_from_u_short(fmt, buffer, args);
  else if (fmt->length == LONG)
   convert_from_u_long(fmt, buffer, args);
  else if (fmt->length == LONG_LONG)
    convert_from_u_long_long(fmt, buffer, args);
  else if (fmt->length == LONG_DOUBLE)
    ;
  else if (fmt->length == SIZE) 
    convert_from_u_long_long(fmt, buffer, args);
  else
    ;
}

void format_specifier_to_string(t_fmt *fmt, t_list *buffer, va_list *args) {
  if (fmt->type == 'X')
    length_u_int(fmt, buffer, args);
  else if (fmt->type == 'c')
    convert_from_character(fmt, buffer, args);
  else if (fmt->type == 'd')
    length_int(fmt, buffer, args);
  else if (fmt->type == 'i')
    length_int(fmt, buffer, args);
  else if (fmt->type == 'o')
    length_u_int(fmt, buffer, args);
  else if (fmt->type == 'p')
    convert_from_void_ptr(fmt, buffer, args);
  else if (fmt->type == 's')
    convert_from_string(fmt, buffer, args);
  else if (fmt->type == 'u')
    length_u_int(fmt, buffer, args);
  else if (fmt->type == 'x')
    length_u_int(fmt, buffer, args);
  else if (fmt->type == '%') {
    if (fmt->flag == '0') {
      list_push(buffer, list_new_node(ft_strdup("%"), 2));
      if (fmt->width > 0)
        fmt->width -= 1;
      wrapper_decorator(fmt, buffer, "", STRING);
    } else
      wrapper_decorator(fmt, buffer, "%", STRING);
  }
}
