/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:35:27 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/13 22:38:55 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362
# define ESC 65307

# define LOAD_XPM mlx_xpm_file_to_image
# define GET_ADDR mlx_get_data_addr

typedef struct s_coin
{
	int			x;
	int			y;
}				t_coin;

typedef struct s_player
{
	int			x;
	int			y;
	int			new_x;
	int			new_y;
	int			movement;
	int			number;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			new_x;
	int			new_y;
	int			real_x;
	int			real_y;
	int			old_x;
	char		key;
	int			c;
	int			step;
	int			one;
	int			movement;
	int			stuck_counter;
}				t_enemy;

typedef struct s_exit
{
	int			x;
	int			y;
}				t_exit;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	int			collectible;
	int			collected;
	t_coin		*coins;
	int			count_player;
	int			p_post_x;
	int			p_post_y;
	t_player	player;
	int			count_exit;
	t_exit		exit;
	int			enemy_count;
	t_enemy		*enemy;
	char		keys;
}				t_map;

typedef struct mlx
{
	void		*init;
	void		*win;
}				t_mlx;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_allimg
{
	t_img		bg;
	t_img		wall;
	t_img		pl_i;
	t_img		pl_d;
	t_img		pl_u;
	t_img		pl_l;
	t_img		pl_r;
	t_img		en_l;
	t_img		en_r;
	t_img		exit;
	t_img		exit2;
	t_img		coint;
	t_img		co_eff;
}				t_all_img;

typedef struct s_data
{
	t_mlx		*mlx;
	t_img		new_image;
	t_map		*map;
	t_all_img	*imgs;
}				t_data;

typedef struct s_path
{
	int			c;
	int			e;
}				t_path;

/* FUNCTIONS */
char			*ft_itoa(int n);
void			render_moves(t_data *data);
void			fix_the_bug(t_data *data);
int				close_window(t_data *data);
void			free_imgs(t_mlx *mlx, t_all_img *imgs);
void			free_all_data_and_exit(t_data *data, char *str);
int				pick_pixel(t_img *data, int x, int y);
void			put_pixel(t_img *data, int x, int y, int color);
void			put_mini_image_to_window(t_img *dst, t_img *src, int x_dst,
					int y_dst, int x_src);
void			reset_en_cord(t_data *data, int count, int *one, int *c);
void			reset(t_data *data, int count);
void			increment_variable(int *step, int *c);
void			move_en_left(t_data *data, int count);
void			move_en_right(t_data *data, int count);
int				check_place(t_data *data, int count, int i);
int				enemy_number(char **map);
void			enemy(t_data *data, int count);
void			render_enemy(t_data *data);
int				is_enemy(t_data *data);
void			check_position(t_data *data);
void			reset_cordonites(t_data *data);
void			move_pl_left(t_data *data);
void			move_pl_right(t_data *data);
void			move_pl_up(t_data *data);
void			move_pl_down(t_data *data);
void			render_player(t_data *data);
void			render_effect(t_data *data);
void			render_coint(t_data *data);
void			render_exit(t_data *data);
void			render_static_map(t_data *data);
int				the_animation(t_data *data);
bool			is_wall(t_data *data, int x, int y);
void			next_move(t_data *data, char c, int x, int y);
int				key_press(int keycode, t_data *data);
void			xpm_to_image(t_mlx *mlx, t_all_img *imgs);
void			check_all_imgs(t_all_img *imgs, t_data *data);
void			get_addres(t_all_img *imgs);
void			load_imgs(t_mlx *mlx, t_all_img *imgs, t_data *data);
void			init_all(t_map *map_info, t_data *data, t_all_img *imgs,
					t_mlx *mlx);
void			the_real_work(t_map *map_info);
void			initializ_all(t_map *map_info, int count, int i, int j);
void			initialize_player(t_map *map_info);
void			initialize_exit(t_map *map_info);
void			initialize_enemy(t_map *map_info);
void			initialize_coins(t_map *map_info);
void			get_info(t_map *map_info);
void			the_size_of_map(t_map **map_info);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			**free_array(char **ptr, int i);
char			**allocation(char **p, char *s, char c, int size);
char			**ft_split(char *s, char c);
void			empty_line(char *s, char *text);
int				count_word(char const *s, char c, int *size);
void			flood_fill(char **str, int x, int y, t_path *check,
					t_map *map_info);
void			free_double_string(char **lines);
void			check_components(char *str, char **lines);
void			all_walls(char *str, char **lines);
void			check_walls(char **lines);
void			eror_exit(int i);
int				ft_strcmp(char *str, char *cmp, int len);
void			valide_name(char *file_name);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			**is_rectangular(char *name, int i);
void			take_position(char c, int x, int y, t_map **map_info);
void			invalid_path(char **lines, char **lines2, t_path *check,
					t_map *map_info);
void			map_component(char **lines, t_map **map_info);
char			*ft_strdup(char *s1);
char			**duplicate(char **lines);
void			check_map(char *file_name, t_map **map_info);
int				main(int ac, char **av);

#endif
