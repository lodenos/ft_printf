#include "ft_printf.h"
#include "ft_string.h"

void token_decorator_number(t_fmt *fmt, t_string_build *buffer, char *str) {
  (void)fmt;

  string_build_append_str(buffer, str, ft_strlen(str));

/*  t_string chunk;
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

  // this is a shit fix
  if (fmt->precision != UNDEFINED && string->data_size == 1
      && precision == 0 && *string->data == '0') {
    if (fmt->width != UNDEFINED) {
      free(chunk.data);
      chunk.data = (char *)malloc(fmt->width + 1);
      chunk.data[fmt->width] = 0;
      ft_memset(chunk.data, ' ', fmt->width);
      list_push(buffer, list_new_node(chunk.data, chunk.ptr_size));
      return ;
    }
    free(chunk.data);
    return ;
  }

//  printf("|%s|\n", chunk.data);

  //------>

  if (head > string->data_size - (sign % 1)) {
    size_t diff = 0;

    if (precision >= string->data_size)
      diff = precision - string->data_size;

    if (diff > head) {
      head = 0;
    } else {
      if (fmt->precision == UNDEFINED)
        head -= string->data_size + diff;
      else
        head -= string->data_size + diff + (sign & 1);
    }

  } else
    head = 0;

//  printf("> head: %zu\n", head);
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

//  printf("|%s|\n", chunk.data);
  //------> Left or Right

//  printf("> head: %zu\n", head);

   if (head) {
    ft_memset(data, ' ', head);
    data += head;
  }

//  printf("|%s|\n", chunk.data);
  //------> Sign

  if (sign & 1) {
    *data = *string->data;
    ++data;
  }

//  printf("|%s|\n", chunk.data);

  if ((sign & 2) && *string->data != '0') {
    if (fmt->type == 'X') {
      ft_memcpy(data, "0X", 2);
      data += 2;
    } else if (fmt->type == 'x') {
      ft_memcpy(data, "0x", 2);
      data += 2;
    }
  }

//  printf("|%s|\n", chunk.data);
  //------> Zero & Precision

  if (zero) {
    ft_memset(data, '0', zero);
    data += zero;
  }

//  printf("|%s|\n", chunk.data);
  //------> Number

  ft_memcpy(data, string->data + (sign & 1), string->data_size - (sign & 1));

//  printf("|%s|\n", chunk.data);
  data += string->data_size - (sign & 1);

//  printf("|%s|\n", chunk.data);
  if (tail)
    ft_memset(data, ' ', tail);

  //------> Token Pushing

//  printf("|%s|\n", chunk.data);
  list_push(buffer, list_new_node(chunk.data, chunk.ptr_size));
*/
}
