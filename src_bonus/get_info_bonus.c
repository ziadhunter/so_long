/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 06:26:09 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 20:03:49 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_player(t_map *map_info)
{
	int	i;
	int	j;

	j = 0;
	while (map_info->map[j])
	{
		i = 0;
		while (map_info->map[j][i])
		{
			if (map_info->map[j][i] == 'P')
			{
				map_info->player.x = i;
				map_info->player.y = j;
				map_info->player.new_x = i;
				map_info->player.new_y = j;
			}
			i++;
		}
		j++;
	}
	map_info->player.number = 0;
	map_info->keys = 'i';
	map_info->player.movement = 0;
}

void	initialize_exit(t_map *map_info)
{
	int	i;
	int	j;

	j = 0;
	while (map_info->map[j])
	{
		i = 0;
		while (map_info->map[j][i])
		{
			if (map_info->map[j][i] == 'E')
			{
				map_info->exit.x = i;
				map_info->exit.y = j;
			}
			i++;
		}
		j++;
	}
}

void	initialize_enemy(t_map *map_info)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	map_info->enemy_count = enemy_number(map_info->map);
	map_info->enemy = malloc(sizeof(t_enemy) * map_info->enemy_count);
	j = 0;
	while (map_info->map[j])
	{
		i = 0;
		while (map_info->map[j][i])
		{
			if (map_info->map[j][i] == 'X')
			{
				initializ_all(map_info, count, i, j);
				count++;
			}
			i++;
		}
		j++;
	}
}

void	initialize_coins(t_map *map_info)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	map_info->coins = malloc(sizeof(t_coin) * map_info->collectible);
	if (!map_info->coins)
		return ;
	while (map_info->map[j])
	{
		i = 0;
		while (map_info->map[j][i])
		{
			if (map_info->map[j][i] == 'C' && count < map_info->collectible)
			{
				map_info->coins[count].x = i;
				map_info->coins[count].y = j;
				count++;
			}
			i++;
		}
		j++;
	}
}

void	get_info(t_map *map_info)
{
	map_info->collected = 0;
	initialize_player(map_info);
	initialize_exit(map_info);
	initialize_enemy(map_info);
	initialize_coins(map_info);
}
