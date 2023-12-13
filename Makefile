NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft

INCLUDE_DIR = ./inc
INCLUDES = -I $(INCLUDE_DIR) -I $(LIBFT_PATH)/inc

SOURCE_DIR = src

SOURCES = ft_printf.c \
  format_specifier/format_specifier.c \
  format_specifier/format_specifier_flags.c \
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
