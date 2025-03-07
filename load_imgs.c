#include "so_long.h"

void check_all_imgs(t_all_img imgs)
{
    if (!)
}

void    load_player_imgs(t_mlx *mlx, t_all_img *imgs)
{
    imgs->pl_down.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/player_movement/down.xpm", &imgs->pl_down.width,
			&imgs->pl_down.height);
	imgs->pl_down.addr = mlx_get_data_addr(imgs->pl_down.img,
			&imgs->pl_down.bpp, &imgs->pl_down.line_length,
			&imgs->pl_down.endian);
	imgs->pl_up.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/player_movement/up.xpm", &imgs->pl_up.width,
			&imgs->pl_up.height);
	imgs->pl_up.addr = mlx_get_data_addr(imgs->pl_up.img, &imgs->pl_up.bpp,
			&imgs->pl_up.line_length, &imgs->pl_up.endian);
	imgs->pl_left.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/player_movement/left.xpm", &imgs->pl_left.width,
			&imgs->pl_left.height);
	imgs->pl_left.addr = mlx_get_data_addr(imgs->pl_left.img,
			&imgs->pl_left.bpp, &imgs->pl_left.line_length,
			&imgs->pl_left.endian);
	imgs->pl_right.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/player_movement/right.xpm", &imgs->pl_right.width,
			&imgs->pl_right.height);
	imgs->pl_right.addr = mlx_get_data_addr(imgs->pl_right.img,
			&imgs->pl_right.bpp, &imgs->pl_right.line_length,
			&imgs->pl_right.endian);
	imgs->pl_idle.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/player_movement/idle.xpm", &imgs->pl_idle.width,
			&imgs->pl_idle.height);
	imgs->pl_idle.addr = mlx_get_data_addr(imgs->pl_idle.img,
			&imgs->pl_idle.bpp, &imgs->pl_idle.line_length,
			&imgs->pl_idle.endian);
}

void load_imgs_three(t_mlx *mlx, t_all_img *imgs)
{
    imgs->coint_effect.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/coint_pictures/coin_effect.xpm",
			&imgs->coint_effect.width, &imgs->coint_effect.height);
	imgs->coint_effect.addr = mlx_get_data_addr(imgs->coint_effect.img,
			&imgs->coint_effect.bpp, &imgs->coint_effect.line_length,
			&imgs->coint_effect.endian);
	imgs->exit.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/exit_pictures/Heart.xpm", &imgs->exit.width,
			&imgs->exit.height);
	imgs->exit.addr = mlx_get_data_addr(imgs->exit.img, &imgs->exit.bpp,
			&imgs->exit.line_length, &imgs->exit.endian);
	imgs->en_left.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/enemy_movement/left.xpm", &imgs->en_left.width,
			&imgs->en_left.height);
	imgs->en_left.addr = mlx_get_data_addr(imgs->en_left.img,
			&imgs->en_left.bpp, &imgs->en_left.line_length,
			&imgs->en_left.endian);
	imgs->en_right.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/enemy_movement/right.xpm", &imgs->en_right.width,
			&imgs->en_right.height);
	imgs->en_right.addr = mlx_get_data_addr(imgs->en_right.img,
			&imgs->en_right.bpp, &imgs->en_right.line_length,
			&imgs->en_right.endian);
}

void	load_imgs(t_mlx *mlx, t_all_img *imgs)
{
	imgs->background.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/background_pictures/.xpm", &(imgs->background.width),
			&(imgs->background.height));
	imgs->background.addr = mlx_get_data_addr(imgs->background.img,
			&imgs->background.bpp, &imgs->background.line_length,
			&imgs->background.endian);
	imgs->wall.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/wall_pictures/wall.xpm", &imgs->wall.width,
			&imgs->wall.height);
	imgs->wall.addr = mlx_get_data_addr(imgs->wall.img, &imgs->wall.bpp,
			&imgs->wall.line_length, &imgs->wall.endian);
	imgs->coint.img = mlx_xpm_file_to_image(mlx->init,
			"./pictures/coint_pictures/mojawharat.xpm", &imgs->coint.width,
			&imgs->coint.height);
	imgs->coint.addr = mlx_get_data_addr(imgs->coint.img, &imgs->coint.bpp,
			&imgs->coint.line_length, &imgs->coint.endian);
    load_player_imgs(mlx, imgs);
    load_imgs_three(mlx, imgs);
    check_all_imgs(imgs);
}
