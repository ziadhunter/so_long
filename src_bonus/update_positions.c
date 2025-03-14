/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:00:41 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 15:32:33 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_en_cord(t_data *data, int count, int *one, int *c)
{
	int	x;
	int	y;

	*one = 0;
	*c = 0;
	x = data->map->player.x;
	y = data->map->player.y;
	data->map->enemy[count].old_x = data->map->enemy[count].x;
	data->map->enemy[count].x = data->map->enemy[count].new_x;
	if (data->map->enemy[count].new_x == x
		&& data->map->enemy[count].new_y == y)
		free_all_data_and_exit(data, "you lose :( GOOD LUCK NEXT TIME !!");
	data->map->enemy[count].movement = 0;
}

void	fix_the_bug(t_data *data)
{
	int	count;
	int	x;
	int	y;
	int	new_x;
	int	new_y;

	x = data->map->player.x;
	y = data->map->player.y;
	new_x = data->map->player.new_x;
	new_y = data->map->player.new_y;
	count = 0;
	while (count < data->map->enemy_count)
	{
		if ((new_x == data->map->enemy[count].x
				&& new_y == data->map->enemy[count].y)
			&& (x == data->map->enemy[count].new_x
				&& y == data->map->enemy[count].y))
			free_all_data_and_exit(data, "you lose :(, GOOD LUCK NEXT TIME !!");
		count++;
	}
}

int	is_enemy(t_data *data)
{
	int	count;
	int	x;
	int	y;

	x = data->map->player.x;
	y = data->map->player.y;
	count = 0;
	while (count < data->map->enemy_count)
	{
		if (x == data->map->enemy[count].real_x
			&& y == data->map->enemy[count].real_y)
			return (1);
		count++;
	}
	return (0);
}

void	check_position(t_data *data)
{
	if (data->map->map[data->map->player.y][data->map->player.x] == 'E'
		&& data->map->collectible == data->map->collected)
		free_all_data_and_exit(data, "You win\n");
	else if (data->map->map[data->map->player.y][data->map->player.x] == 'C')
	{
		data->map->collected++;
		data->map->map[data->map->player.y][data->map->player.x] = 'F';
	}
	else if (is_enemy(data))
		free_all_data_and_exit(data, "you lose :(, GOOD LUCK NEXT TIME !!");
}

void	reset_cordonites(t_data *data)
{
	fix_the_bug(data);
	if (data->map->keys == 'l' && !is_wall(data, data->map->player.x - 1,
			data->map->player.y))
		data->map->player.x--;
	else if (data->map->keys == 'r' && !is_wall(data, data->map->player.x + 1,
			data->map->player.y))
		data->map->player.x++;
	else if (data->map->keys == 'u' && !is_wall(data, data->map->player.x,
			data->map->player.y - 1))
		data->map->player.y--;
	else if (data->map->keys == 'd' && !is_wall(data, data->map->player.x,
			data->map->player.y + 1))
		data->map->player.y++;
	data->map->player.number++;
	check_position(data);
	data->map->player.movement = 0;
	data->map->keys = 'i';
}
