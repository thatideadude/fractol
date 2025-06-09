NAME	= fractol
CFLAGS 	= -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -lX11 -lXext
SRCS	= main.c str_tools.c
OBJS	= $(SRCS:.c=.o)

all:	$(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
