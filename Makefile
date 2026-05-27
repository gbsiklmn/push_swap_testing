NAME 	= push_swap
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= main.c parsing.c stack.c push.c swap.c rotate.c reverse_rotate \
			sort_simple.c sort_medium.c sort_complex.c sort_adaptive.c \
			utils.c ft_split.c disorder.c output_utils.c 

OBJS	= $(SRCS:.c=.o)
HDR		= push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re