NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
MSRC = push_swap.c split.c algo.c commands.c commands2.c utils.c utils2.c utils3.c list.c inits.c

MOBJ = $(MSRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC)	$(CFLAGS) -c $< -o $@

$(NAME): $(MOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MOBJ)

clean:
	$(RM) $(MOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all