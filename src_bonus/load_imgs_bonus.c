/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:01:36 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 20:03:47 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_pictures(t_all_img *imgs)
{
	imgs->bg.img = NULL;
	imgs->wall.img = NULL;
	imgs->coint.img = NULL;
	imgs->co_eff.img = NULL;
	imgs->exit.img = NULL;
	imgs->exit2.img = NULL;
	imgs->en_r.img = NULL;
	imgs->pl_i.img = NULL;
	imgs->pl_d.img = NULL;
	imgs->pl_l.img = NULL;
	imgs->pl_u.img = NULL;
	imgs->pl_r.img = NULL;
}

void	xpm_to_image(t_mlx *mlx, t_all_img *imgs)
{
	imgs->bg.img = LOAD_XPM(mlx->init, "./textures/background/bg.xpm",
			&imgs->bg.width, &imgs->bg.height);
	imgs->wall.img = LOAD_XPM(mlx->init, "./textures/wall/wall.xpm",
			&imgs->wall.width, &imgs->wall.height);
	imgs->coint.img = LOAD_XPM(mlx->init, "./textures/coins/diamond.xpm",
			&imgs->coint.width, &imgs->coint.height);
	imgs->co_eff.img = LOAD_XPM(mlx->init, "./textures/coins/coins_eff.xpm",
			&imgs->co_eff.width, &imgs->co_eff.height);
	imgs->exit.img = LOAD_XPM(mlx->init, "./textures/exit/ex.xpm",
			&imgs->exit.width, &imgs->exit.height);
	imgs->en_l.img = LOAD_XPM(mlx->init, "./textures/enemy/left.xpm",
			&imgs->en_l.width, &imgs->en_l.height);
	imgs->en_r.img = LOAD_XPM(mlx->init, "./textures/enemy/right.xpm",
			&imgs->en_r.width, &imgs->en_r.height);
	imgs->pl_i.img = LOAD_XPM(mlx->init, "./textures/player/idle.xpm",
			&imgs->pl_i.width, &imgs->pl_i.height);
	imgs->pl_d.img = LOAD_XPM(mlx->init, "./textures/player/down.xpm",
			&imgs->pl_d.width, &imgs->pl_d.height);
	imgs->pl_l.img = LOAD_XPM(mlx->init, "./textures/player/left.xpm",
			&imgs->pl_l.width, &imgs->pl_l.height);
	imgs->pl_u.img = LOAD_XPM(mlx->init, "./textures/player/up.xpm",
			&imgs->pl_u.width, &imgs->pl_u.height);
	imgs->pl_r.img = LOAD_XPM(mlx->init, "./textures/player/right.xpm",
			&imgs->pl_r.width, &imgs->pl_r.height);
}

void	check_all_imgs(t_all_img *imgs, t_data *data)
{
	if (!imgs->bg.img || !imgs->wall.img || !imgs->coint.img
		|| !imgs->co_eff.img || !imgs->exit.img || !imgs->en_l.img
		|| !imgs->en_r.img || !imgs->pl_i.img || !imgs->pl_d.img
		|| !imgs->pl_u.img || !imgs->pl_l.img || !imgs->pl_r.img)
		free_all_data_and_exit(data, "failed to load the images");
}

void	get_addres(t_all_img *imgs)
{
	imgs->bg.addr = GET_ADDR(imgs->bg.img, &imgs->bg.bpp, &imgs->bg.line_length,
			&imgs->bg.endian);
	imgs->wall.addr = GET_ADDR(imgs->wall.img, &imgs->wall.bpp,
			&imgs->wall.line_length, &imgs->wall.endian);
	imgs->coint.addr = GET_ADDR(imgs->coint.img, &imgs->coint.bpp,
			&imgs->coint.line_length, &imgs->coint.endian);
	imgs->co_eff.addr = GET_ADDR(imgs->co_eff.img, &imgs->co_eff.bpp,
			&imgs->co_eff.line_length, &imgs->co_eff.endian);
	imgs->exit.addr = GET_ADDR(imgs->exit.img, &imgs->exit.bpp,
			&imgs->exit.line_length, &imgs->exit.endian);
	imgs->en_l.addr = GET_ADDR(imgs->en_l.img, &imgs->en_l.bpp,
			&imgs->en_l.line_length, &imgs->en_l.endian);
	imgs->en_r.addr = GET_ADDR(imgs->en_r.img, &imgs->en_r.bpp,
			&imgs->en_r.line_length, &imgs->en_r.endian);
	imgs->pl_i.addr = GET_ADDR(imgs->pl_i.img, &imgs->pl_i.bpp,
			&imgs->pl_i.line_length, &imgs->pl_i.endian);
	imgs->pl_d.addr = GET_ADDR(imgs->pl_d.img, &imgs->pl_d.bpp,
			&imgs->pl_d.line_length, &imgs->pl_d.endian);
	imgs->pl_l.addr = GET_ADDR(imgs->pl_l.img, &imgs->pl_l.bpp,
			&imgs->pl_l.line_length, &imgs->pl_l.endian);
	imgs->pl_u.addr = GET_ADDR(imgs->pl_u.img, &imgs->pl_u.bpp,
			&imgs->pl_u.line_length, &imgs->pl_u.endian);
	imgs->pl_r.addr = GET_ADDR(imgs->pl_r.img, &imgs->pl_r.bpp,
			&imgs->pl_r.line_length, &imgs->pl_r.endian);
}

void	load_imgs(t_mlx *mlx, t_all_img *imgs, t_data *data)
{
	initialize_pictures(imgs);
	xpm_to_image(mlx, imgs);
	check_all_imgs(imgs, data);
	get_addres(imgs);
}
