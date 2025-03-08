CC = cc
CFLAGS = -Wall -Werror -Wextra
CMLX = -lmlx -lXext -lX11 -lm
SRC = achi_l3ibat.c      free_function.c     player_mouvement.c  so_long.c\
		check_map.c        get_info.c          put_the_image.c     split.c\
		enemy_mouvement.c  load_imgs.c         rendering.c         the_real_work.c\
		flood_fill.c       map_check_outils.c  side_outils.c       update_positions.c\
		get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c

NAME = so_long
OBJECT = $(SRC:%.c=%.o)
# //OBJECT = $(SRC_BONUS:%.c=%.o )

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -g $(SRC) $(CMLX) -o $(NAME)

# bonus: $(SRC_BONUS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) $(CMLX) -o $(NAME)


clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus