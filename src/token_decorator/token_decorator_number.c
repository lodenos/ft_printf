#include <stdlib.h>
#include "ft_printf.h"
#include "ft_string.h"

#include <stdio.h>

size_t __token_size(t_fmt *fmt, t_string *string, unsigned int *sign) {
  size_t size;

  size = 0;
  *sign = 0;
  if (*string->data == '-' || *string->data == '+')
    *sign = 1;
  if ((fmt->flag & HASH) && *string->data != '0')
    *sign += 2;
  size = string->data_size - (*sign & 1);
  if (fmt->width != UNDEFINED && (size_t)fmt->width > size)
    size = fmt->width - *sign;
  if (fmt->precision != UNDEFINED && (size_t)fmt->precision > size)
    size = fmt->precision;
  if (string->data_size - (*sign & 1) > size)
    size = string->data_size - (*sign & 1);

  if ((fmt->flag & SPACE) && !(*sign & 1))
    size += 1;

  return size + *sign;
}

void token_decorator_number(t_fmt *fmt, t_list *buffer, t_string *string) {
  t_string chunk;
  unsigned int sign;

  //---------- Find the size

  chunk.data_size = __token_size(fmt, string, &sign);
  chunk.ptr_size = chunk.data_size + 1;

  //---------- Alloc the Memory

  chunk.data = (char *)malloc(chunk.ptr_size);
  if (!chunk.data)
    return ;
  chunk.data[chunk.data_size] = 0;

  //------>

  char *data = chunk.data;
  size_t head = 0;
  size_t tail = 0;
  size_t zero = 0;

  size_t width = 0;
  size_t precision = 0;

  (void)width;

  if (fmt->width != UNDEFINED) {
    head = fmt->width;
    width = fmt->width;
  }
  if (fmt->precision != UNDEFINED) {
    zero = fmt->precision;
    precision = fmt->precision;
  }

  if (fmt->precision != UNDEFINED && string->data_size == 1 && precision == 0 && *string->data == '0') {
    free(chunk.data);
    return;
  }


  //------>

  if (head > string->data_size) {
    size_t diff = 0;
    if (precision > string->data_size)
      diff = precision - string->data_size + (sign & 1);
    head -= string->data_size + diff;
  } else
    head = 0;

  if (fmt->flag & MINUS) {
    tail = head;
    head = 0;
  }


  if (zero > string->data_size - (sign & 1))
    zero -= string->data_size - (sign & 1);
  else
    zero = 0;

  if (fmt->flag & ZERO) {
    if (!zero && !precision) {
      zero = head;
      head = 0;
    }

  }

  //------> Space

  if (fmt->flag & SPACE) {
    *data = ' ';
    ++data;
  }

  //------> Left or Right

   if (head) {
    ft_memset(data, ' ', head);
    data += head;
  }

  //------> Sign

  if (sign & 1) {
    *data = *string->data;
    ++data;
  }
  if ((sign & 2) && *string->data != '0') {
    if (fmt->type == 'X') {
      ft_memcpy(data, "0X", 2);
      data += 2;
    } else if (fmt->type == 'x') {
      ft_memcpy(data, "0x", 2);
      data += 2;
    }
  }

  //------> Zero & Precision

  if (zero) {
    ft_memset(data, '0', zero);
    data += zero;
  }

  //------> Number

  ft_memcpy(data, string->data + (sign & 1), string->data_size - (sign & 1));

  data += string->data_size - (sign & 1);

  if (tail)
    ft_memset(data, ' ', tail);

  //------> Token Pushing

  list_push(buffer, list_new_node(chunk.data, chunk.ptr_size));
}
