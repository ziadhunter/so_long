/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:34:26 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/10 21:34:29 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **str, int x, int y, t_path *check)
{
	if (x < 0 || y < 0 || !str[y] || !str[y][x])
		return ;
	if (str[y][x] == '1' || str[y][x] == '#')
		return ;
	if (str[y][x] == 'C')
		check->C++;
	else if (str[y][x] == 'E')
		check->E++;
	str[y][x] = '#';
	flood_fill(str, x + 1, y, check);
	flood_fill(str, x - 1, y, check);
	flood_fill(str, x, y + 1, check);
	flood_fill(str, x, y - 1, check);
}

void	eror_exit(int i)
{
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
