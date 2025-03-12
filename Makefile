CC = cc -g3
CFLAGS = -Wall -Werror -Wextra 
CMLX = -lmlx -lXext -lX11 -lm
SRC = src/side_function.c      src/free_function.c     src/player_mouvement.c  src/so_long.c\
		src/check_map.c        src/get_info.c          src/put_the_image.c     src/split.c\
		src/enemy_mouvement.c  src/load_imgs.c         src/rendering.c         src/the_real_work.c\
		src/flood_fill.c       src/map_check_outils.c  src/side_outils.c       src/update_positions.c\
		get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c

NAME = so_long
OBJECT = $(SRC:%.c=%.o)
# //OBJECT = $(SRC_BONUS:%.c=%.o )

all:  $(NAME)

$(PRINTF) :
	make -C printf

$(NAME): $(OBJECT) $(PRINTF)
	$(CC) $(SRC) printf/libftprintf.a $(CMLX)  -o $(NAME) 
# -lftprintf -L./printf
# bonus: $(SRC_BONUS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) $(CMLX) -o $(NAME)


clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
