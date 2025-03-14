/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 06:20:38 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 01:31:08 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_en_left(t_data *data, int count)
{
	int	*c;
	int	*step;
	int	*one;
	int	x;
	int	y;

	c = &data->map->enemy[count].c;
	step = &data->map->enemy[count].step;
	one = &data->map->enemy[count].one;
	if (*step >= 64)
	{
		*step = 0;
		reset_en_cord(data, count, one, c);
		return ;
	}
	y = data->map->enemy[count].y;
	x = data->map->enemy[count].x;
	put_mini_image_to_window(&data->new_image, &data->imgs->en_l, (x * 64)
		- *step, y * 64, (*c % 4) * 60);
	if (*one % is_time_en(data) == 0)
		increment_variable(step, c);
	if (*step >= 30)
		reset(data, count);
	(*one)++;
}

void	move_en_right(t_data *data, int count)
{
	int	*c;
	int	*step;
	int	*one;
	int	x;
	int	y;

	c = &data->map->enemy[count].c;
	step = &data->map->enemy[count].step;
	one = &data->map->enemy[count].one;
	if (*step >= 64)
	{
		*step = 0;
		reset_en_cord(data, count, one, c);
		return ;
	}
	y = data->map->enemy[count].y;
	x = data->map->enemy[count].x;
	put_mini_image_to_window(&data->new_image, &data->imgs->en_r, (x * 64)
		+ *step, y * 64, (*c % 4) * 60);
	if (*one % is_time_en(data) == 0)
		increment_variable(step, c);
	if (*step >= 30)
		reset(data, count);
	(*one)++;
}

int	check_place(t_data *data, int count, int i)
{
	int	x;
	int	y;
	int	j;
	int	there_is_enemy;

	j = 0;
	there_is_enemy = 0;
	x = data->map->enemy[count].x + i;
	y = data->map->enemy[count].y;
	while (j < data->map->enemy_count)
	{
		if (data->map->enemy[j].new_x == x && data->map->enemy[j].new_y == y)
		{
			there_is_enemy = 1;
			break ;
		}
		j++;
	}
	if (data->map->map[y][x] != '1' && data->map->map[y][x] != 'C'
		&& data->map->map[y][x] != 'E' && !there_is_enemy)
		return (1);
	return (0);
}

void	enemy(t_data *data, int count)
{
	if (data->map->enemy[count].movement)
		return ;
	if (data->map->enemy[count].key == 'l' && check_place(data, count, -1))
	{
		data->map->enemy[count].movement = 1;
		data->map->enemy[count].new_x = data->map->enemy[count].x - 1;
	}
	else if (data->map->enemy[count].key == 'r' && check_place(data, count, 1))
	{
		data->map->enemy[count].movement = 1;
		data->map->enemy[count].new_x = data->map->enemy[count].x + 1;
	}
	else
	{
		if (data->map->enemy[count].stuck_counter >= 100)
		{
			if (data->map->enemy[count].key == 'l')
				data->map->enemy[count].key = 'r';
			else
				data->map->enemy[count].key = 'l';
			data->map->enemy[count].stuck_counter = 0;
		}
		data->map->enemy[count].stuck_counter++;
	}
}

void	render_enemy(t_data *data)
{
	int			count;
	int static	c;
	int			x;
	int			y;

	count = 0;
	while (count < data->map->enemy_count)
	{
		x = data->map->enemy[count].x;
		y = data->map->enemy[count].y;
		enemy(data, count);
		if (data->map->enemy[count].new_x > data->map->enemy[count].x)
			move_en_right(data, count);
		else if (data->map->enemy[count].new_x < data->map->enemy[count].x)
			move_en_left(data, count);
		else if (data->map->enemy[count].key == 'r')
			put_mini_image_to_window(&data->new_image, &data->imgs->en_r, x
				* 64, y * 64, 60);
		else
			put_mini_image_to_window(&data->new_image, &data->imgs->en_l, x
				* 64, y * 64, 60);
		count++;
	}
	c++;
}
