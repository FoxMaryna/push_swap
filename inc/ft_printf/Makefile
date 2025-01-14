NAME 		= libftprintf.a

CC		 	= gcc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_SRCS 	= ./libft
LIBFT 		= $(LIBFT_SRCS)/libft.a
CONV		= ./conversions

SRCS 		=	ft_printf.c \
				$(CONV)/res_character.c \
				$(CONV)/res_string.c \
				$(CONV)/res_decimal.c \
				$(CONV)/res_unsigned.c \
				$(CONV)/res_hexadecimal.c \
				$(CONV)/res_pointer.c

OBJS		= $(SRCS:.c=.o)

HEADER 		= ft_printf.h

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_SRCS) all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_SRCS) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_SRCS) fclean

re: fclean all

.PHONY: all clean fclean re