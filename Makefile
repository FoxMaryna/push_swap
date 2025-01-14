NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./inc/libft
PRINTF = ./inc/ft_printf

SRCS = src/push_swap.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re