/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:34:26 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 21:57:04 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **str, t_coord coord, t_path *check, t_map *map_info)
{
	if (coord.x < 0 || coord.y < 0 || !str[coord.y] || !str[coord.y][coord.x])
		return ;
	if (str[coord.y][coord.x] == '1' || str[coord.y][coord.x] == '#')
		return ;
	else if (str[coord.y][coord.x] == 'C')
		check->c++;
	else if (str[coord.y][coord.x] == 'E')
		check->e++;
	str[coord.y][coord.x] = '#';
	flood_fill(str, (t_coord){coord.x + 1, coord.y}, check, map_info);
	flood_fill(str, (t_coord){coord.x - 1, coord.y}, check, map_info);
	flood_fill(str, (t_coord){coord.x, coord.y + 1}, check, map_info);
	flood_fill(str, (t_coord){coord.x, coord.y - 1}, check, map_info);
}

void	eror_exit(int i)
{
	write(1, "Error\n", 6);
	if (i == 0)
		write(1, "Map not found\n", 14);
	else if (i == 1)
		write(1, "invalid extention of the file\n", 30);
	else if (i == 2)
		write(1, "empty file\n", 11);
	else if (i == 3)
		write(1, "map is not closed\n", 18);
	else if (i == 4)
		write(1, "invalid map\n", 12);
	else if (i == 5)
		write(1, "file not found\n", 15);
	else if (i == 6)
		write(1, "map is not rectangular\n", 23);
	else if (i == 7)
		write(1, "map is long\n", 12);
	exit(1);
}

void	empty_line(char *s, char *text)
{
	if (s[0] == '\n')
	{
		free(s);
		free(text);
		eror_exit(4);
	}
}
