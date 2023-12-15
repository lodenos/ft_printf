NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror #-Weverything -std=gnu18 \
#  -Wno-poison-system-directories -Wno-cast-qual

LIBFT_PATH = ./libft

INCLUDE_DIR = ./inc
INCLUDES = -I $(INCLUDE_DIR) -I $(LIBFT_PATH)/inc

SOURCE_DIR = src

SOURCES = ft_printf.c \
  convert/convert_to_char.c \
  convert/convert_to_char_ptr.c \
  convert/convert_to_character.c \
  convert/convert_to_double.c \
  convert/convert_to_int.c \
  convert/convert_to_long.c \
  convert/convert_to_long_double.c \
  convert/convert_to_long_long.c \
  convert/convert_to_short.c \
  convert/convert_to_string.c \
  convert/convert_to_u_char.c \
  convert/convert_to_u_int.c \
  convert/convert_to_u_long.c \
  convert/convert_to_u_long_long.c \
  convert/convert_to_u_short.c \
  convert/convert_to_void_ptr.c \
  \
  format_specifier/format_specifier.c \
  format_specifier/format_specifier_flag.c \
  format_specifier/format_specifier_length.c \
  format_specifier/format_specifier_parameter.c \
  format_specifier/format_specifier_precision.c \
  format_specifier/format_specifier_type.c \
  format_specifier/format_specifier_width.c

OBJ_DIR = obj
OBJS = $(patsubst %.c, %.o, $(addprefix $(SOURCE_DIR)/, $(SOURCES)))


all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re:
	make re -C $(LIBFT_PATH)
	make

.PHONY: all clean fclean re
