#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "list.h"

typedef struct s_fmt t_fmt;

struct s_fmt {
  // parameter
  char flag;
  // width
  // precision
  char length[2];
  char type;
};

void convert_to_char(t_fmt *, t_list *, va_list *);
void convert_to_char_ptr(t_fmt *, t_list *, va_list *);
void convert_to_character(t_fmt *, t_list *, va_list *);
void convert_to_double(t_fmt *, t_list *, va_list *);
void convert_to_int(t_fmt *, t_list *, va_list *);
void convert_to_long(t_fmt *, t_list *, va_list *);
void convert_to_long_double(t_fmt *, t_list *, va_list *);
void convert_to_long_long(t_fmt *, t_list *, va_list *);
void convert_to_short(t_fmt *, t_list *, va_list *);
void convert_to_string(t_fmt *, t_list *, va_list *);
void convert_to_u_char(t_fmt *, t_list *, va_list *);
void convert_to_u_int(t_fmt *, t_list *, va_list *);
void convert_to_u_long(t_fmt *, t_list *, va_list *);
void convert_to_u_long_long(t_fmt *, t_list *, va_list *);
void convert_to_u_short(t_fmt *, t_list *, va_list *);
void convert_to_void_ptr(t_fmt *, t_list *, va_list *);

char *format_specifier(t_fmt *, char *);
char *format_specifier_flag(t_fmt *, char *);
char *format_specifier_length(t_fmt *, char *);
char *format_specifier_parameter(t_fmt *, char *);
char *format_specifier_precision(t_fmt *, char *);
char *format_specifier_type(t_fmt *, char *);
char *format_specifier_width(t_fmt *, char *);

int ft_printf(char const *, ...);

#endif
