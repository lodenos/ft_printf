#include <stdarg.h>

#include "libft.h"

#include <stdio.h>

char *format_specifier_type(t_list *buffer, char const *str, va_list *args) {
  (void)buffer;

  

  if (ft_strchr("di", *str))
    va_arg(*args, int);
  else if (ft_strchr("uxX", *str))
    ;
  else if (ft_strchr("c", *str))
    va_arg(*args, int);
  else if (ft_strchr("s", *str)) {
    char *tmp = va_arg(*args, char *);

//    printf("<>- \n");

    list_push(buffer, list_new_node(tmp, ft_strlen(tmp)));
  } else if (ft_strchr("p", *str))
    ;
  else if (ft_strchr("%", *str))
    ;
  return (char *)++str;
}
