/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:53:39 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/10 21:52:54 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imgs(t_mlx *mlx, t_all_img *imgs)
{
	if (imgs->bg.img != NULL)
		mlx_destroy_image(mlx->init, imgs->bg.img);
	if (imgs->wall.img != NULL)
		mlx_destroy_image(mlx->init, imgs->wall.img);
	if (imgs->coint.img != NULL)
		mlx_destroy_image(mlx->init, imgs->coint.img);
	if (imgs->co_eff.img != NULL)
		mlx_destroy_image(mlx->init, imgs->co_eff.img);
	if (imgs->exit.img != NULL)
		mlx_destroy_image(mlx->init, imgs->exit.img);
	if (imgs->pl_d.img != NULL)
		mlx_destroy_image(mlx->init, imgs->pl_d.img);
	if (imgs->pl_i.img != NULL)
		mlx_destroy_image(mlx->init, imgs->pl_i.img);
	if (imgs->pl_u.img != NULL)
		mlx_destroy_image(mlx->init, imgs->pl_u.img);
	if (imgs->pl_l.img != NULL)
		mlx_destroy_image(mlx->init, imgs->pl_l.img);
	if (imgs->pl_r.img != NULL)
		mlx_destroy_image(mlx->init, imgs->pl_r.img);
	if (imgs->en_l.img != NULL)
		mlx_destroy_image(mlx->init, imgs->en_l.img);
	if (imgs->en_l.img != NULL)
		mlx_destroy_image(mlx->init, imgs->en_r.img);
}

void	free_all_data_and_exit(t_data *data, char *str)
{
	free_double_string(data->map->map);
	free(data->map->coins);
	free_imgs(data->mlx, data->imgs);
	free(data->map->enemy);
	free(data->map);
	free(data->imgs);
	mlx_destroy_window(data->mlx->init, data->mlx->win);
	mlx_destroy_display(data->mlx->init);
	free(data->mlx->init);
	free(data->mlx);
	free(data);
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(0);
}

int	close_window(t_data *data)
{
	free_all_data_and_exit(data, "you exit the game!");
	return (0);
}