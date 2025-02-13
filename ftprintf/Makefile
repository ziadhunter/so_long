NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
FILES = extra_utils.c  ft_printf.c  handle_char.c  handle_decimale.c  handle_hexadecimale.c  handle_pointer.c  handle_string.c
FILES_BNS = extra_utils_bonus.c  ft_printf_bonus.c  handle_char_bonus.c  handle_decimale_bonus.c  handle_hexadecimale_bonus.c  handle_pointer_bonus.c  handle_string_bonus.c

OBJ_BN =${FILES_BNS:%.c=%.o}
OBJ =${FILES:%.c=%.o}


all: ${NAME}


$(NAME):${OBJ}
	$(AR) $@ $^

bonus:${OBJ_BN}
	$(AR) ${NAME} $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f ${OBJ} ${OBJ_BN}

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY     : clean re all fclean bonus