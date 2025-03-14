/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 06:31:38 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 01:51:35 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	increment_variable(int *step, int *c)
{
	*step += 16;
	(*c)++;
}

void	reset(t_data *data, int count)
{
	data->map->enemy[count].real_x = data->map->enemy[count].new_x;
	data->map->enemy[count].real_y = data->map->enemy[count].new_y;
}

int	enemy_number(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'X')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

void	initializ_all(t_map *map_info, int count, int i, int j)
{
	map_info->enemy[count].x = i;
	map_info->enemy[count].y = j;
	map_info->enemy[count].old_x = i;
	map_info->enemy[count].new_x = i;
	map_info->enemy[count].new_y = j;
	map_info->enemy[count].real_x = i;
	map_info->enemy[count].real_y = j;
	map_info->map[j][i] = '0';
	map_info->enemy[count].key = 'l';
	map_info->enemy[count].movement = 0;
	map_info->enemy[count].one = 0;
	map_info->enemy[count].step = 0;
	map_info->enemy[count].c = 0;
	map_info->enemy[count].stuck_counter = 0;
}

void	the_size_of_map(t_map **map_info)
{
	(*map_info)->width = 0;
	(*map_info)->height = 0;
	while (((*map_info)->map)[(*map_info)->height])
		((*map_info)->height)++;
	while (((*map_info)->map)[0][(*map_info)->width])
		((*map_info)->width)++;
}
