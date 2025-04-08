CC = cc
CFLAGS = -Wall -Werror -Wextra
CMLX = -lmlx -lXext -lX11 -lm
SRC = src/side_function.c      src/free_function.c     src/player_mouvement.c  src/so_long.c\
		src/check_map.c        src/get_info.c          src/put_the_image.c     src/split.c\
		src/enemy_mouvement.c  src/load_imgs.c         src/rendering.c         src/the_real_work.c\
		src/flood_fill.c       src/map_check_outils.c  src/side_outils.c       src/update_positions.c\
		src/enemy_outils.c     get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c

SRC_BONUS = src_bonus/check_map_bonus.c        src_bonus/load_imgs_bonus.c         src_bonus/side_outils_bonus.c\
			src_bonus/enemy_mouvement_bonus.c  src_bonus/map_check_outils_bonus.c  src_bonus/so_long_bonus.c\
			src_bonus/enemy_outils_bonus.c     src_bonus/player_mouvement_bonus.c\
			src_bonus/flood_fill_bonus.c       src_bonus/put_the_image_bonus.c     src_bonus/split_bonus.c\
			src_bonus/free_function_bonus.c    src_bonus/rendering_bonus.c         src_bonus/the_real_work_bonus.c\
			src_bonus/get_info_bonus.c         src_bonus/side_function_bonus.c     src_bonus/update_positions_bonus.c\
			get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c

NAME = so_long
NAME_BONUS = so_long_bonus
OBJECT = $(SRC:%.c=%.o)
OBJECT_BONUS = $(SRC_BONUS:%.c=%.o )

all:  $(NAME)

$(PRINTF) :
	make -C printf

$(NAME): $(OBJECT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC) printf/libftprintf.a $(CMLX) -o $(NAME) 


bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJECT_BONUS) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC_BONUS) printf/libftprintf.a $(CMLX) -o $(NAME_BONUS)

clean:
	rm -f $(OBJECT) $(OBJECT_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus
