#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

#include "list.h"

char *format_specifier_type(t_list *, char const *, va_list *);

int ft_printf(char const *, ...);

#endif
