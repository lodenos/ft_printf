#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

#include "ft_string.h"
#include "list.h"

#define UNDEFINED UINT_MAX

enum e_fmt_length {
  NONE,
  CHAR,
  SHORT,
  LONG,
  LONG_LONG,
  LONG_DOUBLE,
  SIZE
};

enum e_fmt_flag {
  COMMA            = 1,
  DOLLAR           = 2,
  HASH             = 4,
  LEFT_PARENTHESIS = 8,
  LESS_THAN        = 16,
  MINUS            = 32,
  PLUS             = 64,
  SPACE            = 128,
  ZERO             = 256
};

typedef struct s_fmt t_fmt;
typedef struct s_fmt_flag t_fmt_flag;

struct s_fmt {
  // parameter
  uint32_t flag;
  uint32_t width;
  uint32_t precision;
  char length;
  char type;
};

// Convert
void convert_from_char(t_fmt *, t_string_build *, va_list *);
void convert_from_char_ptr(t_fmt *, t_string_build *, va_list *);
void convert_from_character(t_fmt *, t_string_build *, va_list *);
void convert_from_double(t_fmt *, t_string_build *, va_list *);
void convert_from_int(t_fmt *, t_string_build *, va_list *);
void convert_from_long(t_fmt *, t_string_build *, va_list *);
void convert_from_long_double(t_fmt *, t_string_build *, va_list *);
void convert_from_long_long(t_fmt *, t_string_build *, va_list *);
void convert_from_short(t_fmt *, t_string_build *, va_list *);
void convert_from_string(t_fmt *, t_string_build *, va_list *);
void convert_from_u_char(t_fmt *, t_string_build *, va_list *);
void convert_from_u_int(t_fmt *, t_string_build *, va_list *);
void convert_from_u_long(t_fmt *, t_string_build *, va_list *);
void convert_from_u_long_long(t_fmt *, t_string_build *, va_list *);
void convert_from_u_short(t_fmt *, t_string_build *, va_list *);
void convert_from_void_ptr(t_fmt *, t_string_build *, va_list *);

// Format Specifier
char *format_specifier(t_fmt *, char *);
char *format_specifier_flag(t_fmt *, char *);
char *format_specifier_length(t_fmt *, char *);
char *format_specifier_parameter(t_fmt *, char *);
char *format_specifier_precision(t_fmt *, char *);
char *format_specifier_type(t_fmt *, char *);
char *format_specifier_width(t_fmt *, char *);

// ???
void format_specifier_to_string(t_fmt *, t_string_build *, va_list *);

// Token Decorator
void token_decorator_character(t_fmt *, t_string_build *, char *);
void token_decorator_number(t_fmt *, t_string_build *, char *);
void token_decorator_string(t_fmt *, t_string_build *, char *);

// The Printf
int ft_printf(char const *, ...);

#endif
