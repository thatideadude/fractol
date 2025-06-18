NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = listeners.c main.c math_tools.c renderers.c renderers_extras.c starters.c str_tools.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
