#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

char *format_specifier_type(char const *, va_list *);

int ft_printf(char const *, ...);

#endif
