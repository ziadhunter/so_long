CC = cc
CFLAGS = -Wall -Werror -Wextra
CMLX = -lmlx -lXext -lX11 -lm
SRC = so_long.c split.c check_map.c map_check_outils.c flood_fill.c the_real_work.c rendering.c update_positions.c side_outils.c get_info.c enemy_mouvement.c player_mouvement.c achi_l3ibat.c put_the_image.c
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