/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_real_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:53:18 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/12 03:33:13 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_all(t_map *map_info, t_data *data, t_all_img *imgs, t_mlx *mlx)
{
	data->map = map_info;
	data->imgs = imgs;
	data->mlx = mlx;
}

void is_there_enemy(t_data *data, int x, int y, char c)
{
	int i;

	i = 0;
	while (i < data->map->enemy_count)
	{
		if (data->map->player.y == data->map->enemy[i].y && y == data->map->enemy[i].y)
		{
			if (data->map->enemy[i].x == x && data->map->enemy[i].y == y)
			{
				data->map->player.new_x = x;
				data->map->player.new_y = y;
				if (c == 'l')
					move_pl_left(data);
				else if (c == 'r')
					move_pl_right(data);
				else if (c == 'u')
					move_pl_up(data);
				else if (c == 'd')
					move_pl_down(data);
				printf("chi haje\n");
				free_all_data_and_exit(data, "you lose :(, GOOD LUCK NEXT TIME !!");
			}
		}
		i++;
	}
}
bool	is_wall(t_data *data, int x, int y, char c)
{
	if (data->map->map[y][x] == '1')
		return (true);
	is_there_enemy(data, x, y, c);
	return (false);
}

void	next_move(t_data *data, char c, int x, int y)
{
	data->map->keys = c;
	data->map->player.new_x = data->map->player.x + x;
	data->map->player.new_x = data->map->player.y + y;
	data->map->player.movement = 1;
}

int	key_press(int key, t_data *data)
{
	if (data->map->player.movement == 1)
		return (0);
	if (key == ESC)
		free_all_data_and_exit(data, "you exit the game!!\n");
	if ((key == 'a' || key == LEFT) && !is_wall(data, data->map->player.x - 1,
			data->map->player.y, 'l'))
		next_move(data, 'l', -1, 0);
	else if ((key == 'd' || key == RIGHT) && !is_wall(data,
			data->map->player.x + 1, data->map->player.y, 'r'))
		next_move(data, 'r', 1, 0);
	else if ((key == 's' || key == DOWN) && !is_wall(data, data->map->player.x,
			data->map->player.y + 1, 'd'))
		next_move(data, 'd', 0, 1);
	else if ((key == 'w' || key == UP) && !is_wall(data, data->map->player.x,
			data->map->player.y - 1, 'u'))
		next_move(data, 'u', 0, -1);
	return (0);
}

void	the_real_work(t_map *map_info)
{
	t_data		*data;
	t_mlx		*mlx;
	t_all_img	*imgs;

	data = malloc(sizeof(t_data));
	imgs = malloc(sizeof(t_all_img));
	mlx = malloc(sizeof(t_mlx));
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, 64 * map_info->width, 64
			* map_info->height, "my game");
	init_all(map_info, data, imgs, mlx);
	load_imgs(mlx, imgs, data);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(mlx->win, 17, 0, close_window, data);
	mlx_loop_hook(mlx->init, the_animation, data);
	mlx_loop(mlx->init);
}
