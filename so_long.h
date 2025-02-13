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

typedef struct s_map
{
    int collectible;
    int c_collected;
    int exit;
    int e_position_x;
    int e_position_y;
    int player;
    int p_position_x;
    int p_position_y;
    char **map;
} t_map;

typedef struct s_path
{
    int C;
    int E;
} t_path;






/* FUNCTIONS */
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
 
