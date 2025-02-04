NAME = push_swap

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

PRINTF = ./inc/ft_printf

SRCS = src/main.c \
		src/sorting_small.c \
		src/sorting_large.c \
		src/utils.c \
		operation/push.c \
		operation/swap.c \
		operation/rotate.c \
		operation/reverse_rotate.c
		
OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF) -lftprintf -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re