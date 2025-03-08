/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:53:39 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/08 00:53:40 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx->init, data->imgs->background.img);
	mlx_destroy_image(data->mlx->init, data->imgs->wall.img);
	mlx_destroy_image(data->mlx->init, data->imgs->coint.img);
	mlx_destroy_image(data->mlx->init, data->imgs->coint_effect.img);
	mlx_destroy_image(data->mlx->init, data->imgs->exit.img);
	mlx_destroy_image(data->mlx->init, data->imgs->pl_down.img);
	mlx_destroy_image(data->mlx->init, data->imgs->pl_idle.img);
	mlx_destroy_image(data->mlx->init, data->imgs->pl_up.img);
	mlx_destroy_image(data->mlx->init, data->imgs->pl_left.img);
	mlx_destroy_image(data->mlx->init, data->imgs->pl_right.img);
	mlx_destroy_image(data->mlx->init, data->imgs->en_left.img);
	mlx_destroy_image(data->mlx->init, data->imgs->en_right.img);
}

void	free_all_data_and_exit(t_data *data, char *str)
{
	free_double_string(data->map->map);
	free(data->map->coins);
	free_imgs(data);
	free(data->map->enemy);
	free(data->map);
	free(data->imgs);
	mlx_destroy_window(data->mlx->init, data->mlx->win);
	mlx_destroy_display(data->mlx->init);
	free(data->mlx->init);
	free(data->mlx);
	free(data);
	printf("%s", str);
	exit(0);
}
