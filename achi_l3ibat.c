/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   achi_l3ibat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 06:31:38 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/07 06:31:40 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	intialize_all(t_map *map_info, int count, int i, int j)
{
	map_info->enemy[count].x = i;
	map_info->enemy[count].y = j;
	map_info->enemy[count].new_x = i;
	map_info->enemy[count].new_y = j;
	map_info->map[j][i] = '0';
	map_info->enemy[count].key = 'l';
	map_info->enemy[count].movement = 0;
	map_info->enemy[count].one = 0;
	map_info->enemy[count].step = 0;
	map_info->enemy[count].c = 0;
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
