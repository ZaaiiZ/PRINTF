NAME = libftprintf.a
GCC = gcc -Wall -Wextra -Werror
SRCS =	ft_printf.c \
		ft_printf_putchar.c \
		ft_printf_putstr.c \
		ft_printf_putnbr.c \
		ft_printf_puthexa.c \
		ft_printf_parser.c \
		ft_printf_utils.c \
		ft_fill_struct.c \
		ft_printf_char_parser.c \
		ft_printf_string_parser.c \
		ft_printf_hexa_parser.c \
		ft_printf_uint_parser.c \
		ft_printf_ptr_parser.c \
		ft_printf_int_parser.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(GCC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) *~ *# lib

lib:
	$(GCC) $(SRCS) -L. -o lib
	clear && ./lib

re: fclean all

.PHONY: all clean fclean lib re
