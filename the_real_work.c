/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_real_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:53:18 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/08 00:53:20 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_all(t_map *map_info, t_data *data, t_all_img *imgs, t_mlx *mlx)
{
	data->map = map_info;
	data->imgs = imgs;
	data->mlx = mlx;
}

bool	is_wall(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == '1')
		return (true);
	return (false);
}

void	next_move(t_data *data, char c, int x, int y)
{
	data->map->keys = c;
	data->map->player.new_x = data->map->player.x + x;
	data->map->player.new_x = data->map->player.y + y;
	data->map->player.movement = 1;
}

int	key_press(int keycode, t_data *data)
{
	if (data->map->player.movement == 1)
		return (0);
	if (keycode == 65307)
		free_all_data_and_exit(data, "you exit the game!!\n");
	if (keycode == 97 && !is_wall(data, data->map->player.x - 1,
			data->map->player.y))
		next_move(data, 'l', -1, 0);
	else if (keycode == 100 && !is_wall(data, data->map->player.x + 1,
			data->map->player.y))
		next_move(data, 'r', 1, 0);
	else if (keycode == 115 && !is_wall(data, data->map->player.x,
			data->map->player.y + 1))
		next_move(data, 'd', 0, 1);
	else if (keycode == 119 && !is_wall(data, data->map->player.x,
			data->map->player.y - 1))
		next_move(data, 'u', 0, -1);
	return (0);
}

void	the_real_work(t_map *map_info)
{
	t_data		*data;
	t_mlx		*mlx;
	t_all_img	*imgs;
	t_img		*new_image;

	data = malloc(sizeof(t_data));
	imgs = malloc(sizeof(t_all_img));
	mlx = malloc(sizeof(t_mlx));
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, 64 * map_info->width, 64
			* map_info->height, "my game");
	load_imgs(mlx, imgs);
	init_all(map_info, data, imgs, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(mlx->init, the_animation, data);
	mlx_loop(mlx->init);
}
