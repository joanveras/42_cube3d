NAME = cube3D.a


SRCS =	$(wildcard sources/*.c) \
		$(wildcard sources/utils/*.c) \
		$(wildcard sources/libft/*.c) \
		$(wildcard sources/get_next_line/*.c)


OBJS =  $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf


### Rules #############################################

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	$(CC) -g main.c $(SRCS) -L minilibx-linux -lmlx_Linux -o cube3D -lX11 -lXext -lm


all: $(NAME)


clean:
	@ $(RM) $(OBJS)


fclean: clean
	@ $(RM) $(NAME)
	@ $(RM)	cube3D
	@ $(RM) minilibx-linux


re: fclean minilibx all


minilibx:
	wget https://cdn.intra.42.fr/document/document/25875/minilibx-linux.tgz
	tar -xvzf minilibx-linux.tgz
	$(RM) minilibx-linux.tgz
	$(MAKE) -C minilibx-linux


.PHONY: all clean fclean re