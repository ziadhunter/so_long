/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:35:27 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/10 22:09:51 by zfarouk          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define  SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"
// #include <X11/Xlib.h>
// #include <mlx.h>

typedef struct s_player
{
    void *add_pl;
    int x_pl;
    int y_pl;
}t_player;

typedef struct s_map
{
    int collectible;
    int c_collected;
    int exit;
    int e_post_x;
    int e_post_y;
    t_player *player;
    int count_player;
    int p_post_x;
    int p_post_y;
    char **map;
    int y;
    int x;
} t_map;

typedef struct s_enemy
{
    
} t_enemy;



typedef struct mlx
{
    void *mlx;
    void *win;
}   t_mlx;

typedef struct	s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     width;
    int     height;
}	t_img;

typedef struct s_allimg
{
    t_img background;
    t_img wall;
    t_img pl_idl_img;
    t_img pl_down_img;
    t_img pl_up_img;
    t_img pl_left_img;
    t_img pl_right_img;
    t_img en_down_img;
    t_img en_up_img;
    t_img en_left_img;
    t_img en_right_img;
    t_img exit;
    t_img coint;
    t_img coint_effect;
} t_all_img;

typedef struct s_path
{
    int C;
    int E;
} t_path;

/* FUNCTIONS */
void the_real_work(t_map *map_info);
void the_size_of_map(t_map **map_info);

int	count_word(char const *s, char c, int *size);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**free_array(char **ptr, int i);
char	**allocation(char **p, char *s, char c, int size);
char	**ft_split(char *s, char c);
void	empty_line(char *s, char *text);
char	*ft_substr(char *s, unsigned int start, size_t len);
int	count_word(char const *s, char c, int *size);
char	**free_array(char **ptr, int i);
char	**allocation(char **p, char *s, char c, int size);
char	**ft_split(char *s, char c);
void flood_fill(char **str, int x, int y, t_path *check);
void free_double_string(char **lines);
void check_components(char *str, char **lines);
void all_walls(char *str, char **lines);
void check_walls(char **lines);
void eror_exit(int i);
int ft_strcmp(char *str, char *cmp, int len);
void valide_name(char *file_name);
int ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char **is_rectangular(char *name, int i);
void take_position(char c, int x, int y, t_map **map_info);
void invalid_path(char **lines, char **lines2, t_path *check, t_map *map_info);
void map_component(char **lines, t_map **map_info);
char	*ft_strdup(char *s1);
char **duplicate(char **lines);
void check_map(char *file_name, t_map **map_info);
int main(int ac, char **av);


#endif
 
