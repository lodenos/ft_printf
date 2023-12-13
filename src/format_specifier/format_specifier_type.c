#include <stdarg.h>

#include "libft.h"

#include <stdlib.h>

#include <stdio.h>

char *format_specifier_type(t_list *buffer, char const *str, va_list *args) {
  if (*str == 'd') {
    int number = va_arg(*args, int);
    char *data = (char *)malloc(20);
    ft_itoa(number, data, DECIMAL);
    list_push(buffer, list_new_node(data, 20));
  } else if (*str == 'i') {
    int number = va_arg(*args, int);
    char *data = (char *)malloc(20);
    ft_itoa(number, data, DECIMAL);
    list_push(buffer, list_new_node(data, 20));
  } else if (*str == 'u') {
    unsigned int number = va_arg(*args, unsigned int);
    char *data = (char *)malloc(20);
    ft_ultoa(number, data, DECIMAL);
    list_push(buffer, list_new_node(data, 20));
  } else if (*str == 'x') {
    int number = va_arg(*args, int);
    char *data = (char *)malloc(20);
    ft_utoa(number, data, HEX);
    list_push(buffer, list_new_node(ft_strlwr(data), 20));
  } else if (*str == 'X') {
    int number = va_arg(*args, int);
    char *data = (char *)malloc(20);
    ft_utoa(number, data, HEX);
    list_push(buffer, list_new_node(data, 20));
  } else if (*str == 'c') {
    char str[] = "x";
    str[0] = va_arg(*args, int);
    list_push(buffer, list_new_node(ft_strdup(str), ft_strlen(str) + 1));
  } else if (*str == 's') {
    char *tmp = va_arg(*args, char *);
    if (!tmp) {
      list_push(buffer, list_new_node(ft_strdup("(null)"), 7));
      return (char *)++str;
    }
    list_push(buffer, list_new_node(ft_strdup(tmp), ft_strlen(tmp) + 1));
  } else if (*str == 'p') {
    void *address = va_arg(*args, void *);
    char *data = (char *)malloc(20);
    ft_ulltoa((unsigned long long)address, data, HEX);
    list_push(buffer, list_new_node(ft_strdup("0x"), 3));
    list_push(buffer, list_new_node(ft_strlwr(data), 20));
  } else if (ft_strchr("%", *str)) {
    list_push(buffer, list_new_node(ft_strdup("%"), 2));
  }
  return (char *)++str;
}
