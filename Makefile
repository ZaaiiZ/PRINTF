NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra 
SRCS = ft_printf.c display/ft_putchar.c display/ft_puthexa.c display/ft_putnbr.c \
		display/ft_putstr.c parser/ft_char_parser.c parser/ft_int_parser.c \
		parser/ft_parser.c parser/ft_ptr_parser.c parser/ft_string_parser.c \
		parser/ft_uint_parser.c flags/ft_fill.c flags/ft_utils.c parser/ft_hexa_parser.c \
		parser/ft_percent_parser.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re