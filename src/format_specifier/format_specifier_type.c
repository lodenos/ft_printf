#include "ft_printf.h"
#include "ft_string.h"

#define FORMAT_TYPES "%ACDEFGOSUXacdefginop sux"

char *format_specifier_type(t_fmt *fmt, char *format) {
  if (ft_strchr(FORMAT_TYPES, *format))
    fmt->type = *format++;
  return format;
}
