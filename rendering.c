/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 06:11:14 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/08 01:10:59 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_coint(t_data *data)
{
	int			i;
	int			j;
	static int	c = 0;
	static int	one = 0;

	if (one % 35 == 0)
	{
		c++;
		one = 0;
	}
	j = 0;
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->map->map[j][i] == 'C')
				put_mini_image_to_window(&data->new_image, &data->imgs->coint, 64 * i,
					64 * j, (c % 6) * 64);
			i++;
		}
		j++;
	}
	one++;
}

void	render_static_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->map->map[j][i] == '1')
				put_mini_image_to_window(&data->new_image, &data->imgs->wall, 64
					* i, 64 * j, 0);
			else
				put_mini_image_to_window(&data->new_image,
					&data->imgs->background, 64 * i, 64 * j, 0);
			i++;
		}
		j++;
	}
}

void	render_effect(t_data *data)
{
	int					i;
	int					j;
	static int			c = 0;
	static unsigned int	one = 0;

	if (one % 100 == 0)
		c++;
	j = 0;
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->map->map[j][i] == 'F' && data->map->player.x == i
				&& data->map->player.y == j)
				put_mini_image_to_window(&data->new_image, &data->imgs->coint_effect,
					64 * i, 64 * j, (c % 6) * 64);
			else if (data->map->map[j][i] == 'F' && (data->map->player.x != i
					|| data->map->player.y != j))
				data->map->map[j][i] = '0';
			i++;
		}
		j++;
	}
	one++;
}

void	render_exit(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->map->map[j][i] == 'E'
				&& data->map->collected == data->map->collectible)
				put_mini_image_to_window(&data->new_image, &data->imgs->exit, 64 * i,
					64 * j, 0); // 7ta tbdkha mn ba3d
			else if (data->map->map[j][i] == 'E')
				put_mini_image_to_window(&data->new_image, &data->imgs->exit, 64 * i,
					64 * j, 0);
			if (data->map->map[j][i] == 'E')
				return ;
			i++;
		}
		j++;
	}
}

int	the_animation(t_data *data)
{
	static unsigned int	l = 0;
	int					i;
	int					j;
	t_img				new_image;

	i = 0;
	j = 0;
	new_image.img = mlx_new_image(data->mlx->init, 64 * data->map->width, 64
			* data->map->height);
	new_image.addr = mlx_get_data_addr(new_image.img, &new_image.bpp,
			&new_image.line_length, &new_image.endian);
	data->new_image = new_image;
	render_static_map(data);
	render_exit(data);
	render_coint(data);
	render_effect(data);
	render_player(data);
	render_enemy(data);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, new_image.img, 0,
		0);
	mlx_destroy_image(data->mlx->init, data->new_image.img);
	l++;
	return (0);
}
