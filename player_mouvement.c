/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 06:11:26 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/07 06:11:33 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pl_left(t_data *data)
{
	int			x;
	int			y;
	static int	c = 0;
	static int	step;
	static int	one = 0;

	if (step >= 64)
	{
		step = 0;
		c = 0;
		reset_cordonites(data);
	}
	x = data->map->player.x;
	y = data->map->player.y;
	put_mini_image_to_window(&data->new_image, &data->imgs->pl_left, x * 64
		- step, y * 64, (c % 6) * 60);
	if (one % 20 == 0)
	{
		step += 10;
		c++;
	}
	one++;
}

void	move_pl_right(t_data *data)
{
	int			x;
	int			y;
	static int	c = 0;
	static int	step;
	static int	one = 0;

	if (step >= 64)
	{
		step = 0;
		c = 0;
		reset_cordonites(data);
	}
	x = data->map->player.x;
	y = data->map->player.y;
	put_mini_image_to_window(&data->new_image, &data->imgs->pl_right, x * 64
		+ step, y * 64, (c % 6) * 60);
	if (one % 20 == 0)
	{
		step += 10;
		c++;
	}
	one++;
}

void	move_pl_up(t_data *data)
{
	int			x;
	int			y;
	static int	c = 0;
	static int	step;
	static int	one = 0;

	if (step >= 64)
	{
		step = 0;
		c = 0;
		reset_cordonites(data);
	}
	x = data->map->player.x;
	y = data->map->player.y;
	put_mini_image_to_window(&data->new_image, &data->imgs->pl_up, x * 64, y
		* 64 - step, (c % 6) * 60);
	if (one % 20 == 0)
	{
		step += 10;
		c++;
	}
	one++;
}

void	move_pl_down(t_data *data)
{
	int			x;
	int			y;
	static int	c = 0;
	static int	step;
	static int	one = 0;

	if (step >= 64)
	{
		step = 0;
		c = 0;
		reset_cordonites(data);
	}
	x = data->map->player.x;
	y = data->map->player.y;
	put_mini_image_to_window(&data->new_image, &data->imgs->pl_down, x * 64, (y
			* 64) + step, (c % 6) * 60);
	if (one % 20 == 0)
	{
		step += 10;
		c++;
	}
	one++;
}

void	render_player(t_data *data)
{
	static int	c = 0;
	static int	one = 0;

	if (data->map->keys == 'l')
		move_pl_left(data);
	else if (data->map->keys == 'r')
		move_pl_right(data);
	else if (data->map->keys == 'u')
		move_pl_up(data);
	else if (data->map->keys == 'd')
		move_pl_down(data);
	else
		put_mini_image_to_window(&data->new_image, &data->imgs->pl_idle,
			data->map->player.x * 64, data->map->player.y * 64, (c % 6) * 64);
	if (one % 20 == 0)
	{
		c++;
		one = 0;
	}
	one++;
}
