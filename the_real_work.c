#include "so_long.h"

void free_imgs(t_data *data)
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

void free_all_data_and_exit(t_data *data, char *str)
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


void init_all(t_map *map_info, t_data *data, t_all_img *imgs, t_mlx *mlx)
{
    data->map = map_info;
    data->imgs = imgs;
    data->mlx = mlx;
}

bool is_wall(t_data *data, int x, int y)
{
    if (data->map->map[y][x] == '1')
        return (true);
    return (false);
}

int key_press(int keycode, t_data *data)
{
    if (data->map->player.movement == 1)
        return (0);
    if (keycode == 65307)
        free_all_data_and_exit(data, "you exit the game!!\n");
    if (keycode == 97 && !is_wall(data, data->map->player.x - 1, data->map->player.y))
    {
        data->map->keys = 'l';
        data->map->player.new_x = data->map->player.x - 1;
        data->map->player.movement = 1;
    }
    else if (keycode == 100 && !is_wall(data, data->map->player.x + 1, data->map->player.y))
    {
        data->map->keys = 'r';
        data->map->player.new_x = data->map->player.x + 1;
        data->map->player.movement = 1;
    }
    else if (keycode == 115 && !is_wall(data, data->map->player.x, data->map->player.y + 1))
    {
        data->map->player.new_x = data->map->player.y + 1;
        data->map->keys = 'd';
        data->map->player.movement = 1;
    }
    else if (keycode == 119 && !is_wall(data, data->map->player.x, data->map->player.y - 1))
    {
        data->map->player.new_x = data->map->player.x - 1;
        data->map->keys = 'u';
        data->map->player.movement = 1;
    }
    return (0);
}

void the_real_work(t_map *map_info)
{
    t_data *data;
    t_mlx *mlx;
    t_all_img *imgs;
    t_img *new_image;

    data = malloc(sizeof(t_data));
    imgs = malloc(sizeof(t_all_img));
    mlx = malloc(sizeof(t_mlx));
    mlx->init = mlx_init();
    mlx->win = mlx_new_window(mlx->init, 64 * map_info->width, 64 * map_info->height, "my game");
    load_imgs(mlx, imgs);
    init_all(map_info, data, imgs, mlx);
    mlx_hook(mlx->win, 2, 1L << 0, key_press, data);
    mlx_loop_hook(mlx->init, the_animation, data);
    mlx_loop(mlx->init);
}
