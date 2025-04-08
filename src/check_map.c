/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:41:07 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 22:30:34 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valide_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		if (file_name[i] == '/')
		{
			file_name = &file_name[i];
			i = 0;
		}
		i++;
	}
	file_name++;
	if (ft_strlen(file_name) <= 4)
		eror_exit(1);
	while (*file_name)
	{
		if (*file_name == '.')
		{
			if ((ft_strcmp(file_name, ".ber", 4)) == 0)
				return ;
		}
		file_name++;
	}
	eror_exit(1);
}

char	**is_rectangular(char *name, int i)
{
	char	*text;
	char	*line;
	int		fd;
	char	**lines;

	text = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		eror_exit(5);
	line = get_next_line(fd);
	while (line != NULL)
	{
		empty_line(line, text);
		text = ft_strjoin(text, line);
		line = get_next_line(fd);
	}
	lines = ft_split(text, '\n');
	if (lines)
	{
		fd = ft_strlen((lines)[i]);
		while (lines[i])
			if (ft_strlen((lines)[i++]) != fd)
				return (free_double_string(lines), eror_exit(6), NULL);
	}
	return (lines);
}

void	take_position(char c, int x, int y, t_map **map_info)
{
	if (c == 'E')
		(*map_info)->count_exit++;
	else if (c == 'P')
	{
		(*map_info)->p_post_x = x;
		(*map_info)->p_post_y = y;
		(*map_info)->count_player++;
	}
}

void	map_component(char **lines, t_map **map_info)
{
	int (x), (y);
	(*map_info)->count_exit = 0;
	(*map_info)->count_player = 0;
	(*map_info)->collectible = 0;
	y = 0;
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			if (lines[y][x] == 'C')
				((*map_info)->collectible)++;
			else if (lines[y][x] == 'E' || lines[y][x] == 'P')
				take_position(lines[y][x], x, y, map_info);
			x++;
		}
		y++;
	}
	if ((*map_info)->count_player != 1 || (*map_info)->count_exit != 1
		|| (*map_info)->collectible == 0)
	{
		free_double_string(lines);
		free(*map_info);
		eror_exit(4);
	}
}

void	check_map(char *file_name, t_map **map_info)
{
	char	**lines;
	char	**lines2;
	t_path	*check;

	if (!file_name)
		eror_exit(0);
	valide_name(file_name);
	lines = is_rectangular(file_name, 0);
	if (lines == NULL)
		eror_exit(2);
	check_walls(lines);
	*map_info = malloc(sizeof(t_map));
	map_component(lines, map_info);
	lines2 = duplicate(lines, map_info);
	check = malloc(sizeof(t_path));
	check->c = 0;
	check->e = 0;
	flood_fill(lines2, (t_coord){(*map_info)->p_post_x, (*map_info)->p_post_y},
		check, *map_info);
	if (check->c != (*map_info)->collectible || check->e != 1)
		invalid_path(lines, lines2, check, *map_info);
	free(check);
	free_double_string(lines2);
	(*map_info)->map = lines;
}
