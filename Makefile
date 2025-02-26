CC = cc
CFLAGS = -Wall -Werror -Wextra
CMLX = -lmlx -lXext -lX11 -lm
SRC = so_long.c check_map.c flood_fill.c map_check_outils.c side_outils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c split.c achi_l3ibat.c the_real_work.c  get_info.c
NAME = so_long
OBJECT = $(SRC:%.c=%.o)
# //OBJECT = $(SRC_BONUS:%.c=%.o )

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(CMLX) -o $(NAME)

# bonus: $(SRC_BONUS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) $(CMLX) -o $(NAME)


clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus














# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# MLXFLAGS = -lmlx -lXext -lX11 -lm
# SRC = so_long.c check_map.c flood_fill.c map_check_outils.c side_outils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c split.c achi_l3ibat.c the_real_work.c
# #SRC_BONUS =
# NAME = so_long
# OBJECT = $(SRC:.c=.o)
# OBJECT = $(SRC_BONUS:.c=.o)

# all: $(NAME)

# @$(CC) $(CFLAGS) $(SRC_O) $(MINILBX) -lmlx -lXext -lX11 -lm  -o $(NAME)

# $(NAME): $(SRC) $(LIBFT)
# 	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC) -o $(NAME)

# #bonus: $(SRC_BONUS) $(LIBFT)
# #	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) $(CMLX) -o $(NAME)

# clean:
# 	rm -f $(OBJECT)

# fclean: clean
# 	rm -f $(NAME)
# 	make -C libft fclean

# re: fclean all











# NAME	=	so_long
# CC		=	cc
# CFLAGS	=	-Wall -Wextra -Werror

# MINILBX	=	mlx/libmlx_Linux.a
# PATH_ML	=	mlx/

# SRC		=	so_long.c check_map.c flood_fill.c map_check_outils.c side_outils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c split.c achi_l3ibat.c the_real_work.c
# SRC_O	=	$(SRC:.c=.o)

# all: $(NAME)

# $(MINILBX):
# 	@make -C $(PATH_MLX) > test
# 	@echo minilibx DONE

# $(NAME): $(MINILBX) $(SRC_O)
# 	@echo objecte DONE
# 	@$(CC) $(CFLAGS) $(SRC_O) $(MINILBX) -L$(PATH_MLX) -lmlx -lXext -lX11 -lm  -o $(NAME)
# 	@echo $(NAME) DONE
# 	@rm -f test

# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	@rm -f $(SRC_O)
# 	@echo all objecte clean
	 
# fclean: clean
# 	@rm -f $(NAME)
# 	@echo the programe clean

# re: fclean all

# .SECONDARY: $(SRC_O)

# .PHONY: all clean fclean re test