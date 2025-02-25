#include "so_long.h"


void load_imgs(t_mlx *mlx, t_all_img *imgs)
{
    imgs->background.img = mlx_xpm_file_to_image(mlx->init, "./pictures/background_pictures/.xpm", &(imgs->background.width), &(imgs->background.height));
    imgs->background.addr = mlx_get_data_addr(imgs->background.img, &imgs->background.bpp, &imgs->background.line_length, &imgs->background.endian);
    imgs->wall.img = mlx_xpm_file_to_image(mlx->init, "./pictures/wall_pictures/wall.xpm", &imgs->wall.width, &imgs->wall.height);
    imgs->wall.addr = mlx_get_data_addr(imgs->wall.img, &imgs->wall.bpp, &imgs->wall.line_length, &imgs->wall.endian);
    imgs->coint.img = mlx_xpm_file_to_image(mlx->init, "pictures/coint_pictures/coint.xpm", &imgs->coint.width, &imgs->coint.height);
    imgs->coint.addr = mlx_get_data_addr(imgs->coint.img, &imgs->coint.bpp, &imgs->coint.line_length, &imgs->coint.endian);
    imgs->exit.img = mlx_xpm_file_to_image(mlx->init, "./pictures/exit_pictures/Heart.xpm", &imgs->exit.width, &imgs->exit.height);
    imgs->exit.addr = mlx_get_data_addr(imgs->exit.img, &imgs->exit.bpp, &imgs->exit.line_length, &imgs->exit.endian);
    imgs->pl_down.img = mlx_xpm_file_to_image(mlx->init, "./pictures/player_movement/down.xpm", &imgs->pl_down.width, &imgs->pl_down.height);
    imgs->pl_down.addr = mlx_get_data_addr(imgs->pl_down.img, &imgs->pl_down.bpp, &imgs->pl_down.line_length, &imgs->pl_down.endian);
    imgs->pl_up.img = mlx_xpm_file_to_image(mlx->init, "./pictures/player_movement/up.xpm", &imgs->pl_up.width, &imgs->pl_up.height);
    imgs->pl_up.addr = mlx_get_data_addr(imgs->pl_up.img, &imgs->pl_up.bpp, &imgs->pl_up.line_length, &imgs->pl_up.endian);
    imgs->pl_left.img = mlx_xpm_file_to_image(mlx->init, "./pictures/player_movement/left.xpm", &imgs->pl_left.width, &imgs->pl_left.height);
    imgs->pl_left.addr = mlx_get_data_addr(imgs->pl_left.img, &imgs->pl_left.bpp, &imgs->pl_left.line_length, &imgs->pl_left.endian);
    imgs->pl_right.img = mlx_xpm_file_to_image(mlx->init, "./pictures/player_movement/right.xpm", &imgs->pl_right.width, &imgs->pl_right.height);
    imgs->pl_right.addr = mlx_get_data_addr(imgs->pl_right.img, &imgs->pl_right.bpp, &imgs->pl_right.line_length, &imgs->pl_right.endian);
    imgs->pl_idle.img = mlx_xpm_file_to_image(mlx->init, "./pictures/player_movement/idle.xpm", &imgs->pl_idle.width, &imgs->pl_idle.height);
    imgs->pl_idle.addr = mlx_get_data_addr(imgs->pl_idle.img, &imgs->pl_idle.bpp, &imgs->pl_idle.line_length, &imgs->pl_idle.endian);
    // //imgs->en_down.img = mlx_xpm_file_to_image(mlx->init, "./pictures/exit_pictures/Heart.xpm", &imgs->exit.width, &imgs->exit.height);

    // imgs->coint_effect.img = mlx_xpm_file_to_image(data->init, "./pictures/coint_pictures/coin_effect,xpm", &imgs->coint_effect.width, &imgs->coint_effect.height);
    
}


 void put_static_map(t_mlx *data, t_all_img *imgs, t_map *map_info)
{
    int i;
    int j;

    j = 0;
    while(map_info->map[j])
    {
        i = 0;
        while (map_info->map[j][i])
        {
            if (map_info->map[j][i] == '1')
                mlx_put_image_to_window(data->init, data->win, imgs->wall.img, 64 * i, 64 * j);
            else
                mlx_put_image_to_window(data->init, data->win, imgs->background.img, 64 * i, 64 * j);
            i++;
        }
        j++;
    }
}

void init_all(t_map *map_info, t_data *data, t_all_img *imgs, t_mlx *mlx)
{
    data->map = map_info;
    data->imgs = imgs;
    data->mlx = mlx;
}


int	pick_pixel(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	return (*(unsigned int*)dst);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void put_mini_image_to_window(t_img *dst, t_img *src, int x_dst, int y_dst, int x_src)
{
    int y;
    int x;
    int i;
    int j;
    unsigned int color;

    y = 0;
    j = 0;
    while (y < 64)
    {
        x = x_src;
        i = 0;
        while (x < 64 + x_src)
        {
            color = pick_pixel(src, x, y);
            if (color != 0xFF000000)
                put_pixel(dst, x_dst + i, y_dst + j, color);
            x++;
            i++;
        }
        j++;
        y++;
    }
}

int the_animation(t_data *data)
{
    static int c = 0;
    static unsigned int l = 0;
    int i = 0;
    int j = 0;
    t_img new_image;

    if (l % 20000 == 0)
    {
        new_image.img = mlx_new_image(data->mlx->init, 64 * data->map->width, 64 * data->map->height);
        if (!new_image.img) {
            fprintf(stderr, "Failed to create new image\n");
            return (1);
        }
        new_image.addr = mlx_get_data_addr(new_image.img, &new_image.bpp, &new_image.line_length, &new_image.endian);

        while (data->map->map[j])
        {
            i = 0;
            while (data->map->map[j][i])
            {
                if (data->map->map[j][i] == '1')
                put_mini_image_to_window(&new_image, &data->imgs->wall, 64 * i, 64 * j, 0);
                else
                    put_mini_image_to_window(&new_image, &data->imgs->background, 64 * i, 64 * j, 0);
                i++;
            }
            j++;
        }
        i = j = 0;
        while (data->map->map[i])
        {
            j = 0;
            while (data->map->map[i][j])
            {
                if (data->map->map[i][j] == 'P')
                    put_mini_image_to_window(&new_image, &data->imgs->pl_idle, 64 * j, 64 * i, (c % 6) * 64);
                if (data->map->map[i][j] == 'C')
                    put_mini_image_to_window(&new_image, &data->imgs->coint, 64 * j, 64 * i, (c % 6) * 64);
                if (data->map->map[i][j] == 'E')
                    put_mini_image_to_window(&new_image, &data->imgs->exit, 64 * j, 64 * i, 0);
                j++;
            }
            i++;
        }

        mlx_put_image_to_window(data->mlx->init, data->mlx->win, new_image.img, 0, 0);
        mlx_destroy_image(data->mlx->init, new_image.img);
        c++;
    }
    l++;
    return (0);
}
// void move_pl_left(t_data *data)
// {
//     int x;
//     int y;
//     unsigned int l = 0;

//     x = data->map->p_post_x;
//     y = data->map->p_post_y;
//     if (data->map->map[y][x - 1] == '0' || data->map->map[y][x - 1] == 'C' || data->map->map[y][x - 1] == 'E')
//     {
//         while ( l < 115000) 
//         {
//             if (l % 19000 == 0)
//             {
                
//                     data->map->map[y][x] = '0';
//                     data->map->p_post_x = x + 1;
//             }
//             l++;
//         }
//     }
//     data->map->map[y][x - 1] = 'P';
// }

// int key_handler(int keycode, t_data *data)
// {
//     if (keycode == 65307)
//         exit(0);
//     if (keycode == 97)
//         move_pl_left(data);
//     if (keycode == 100)
//         move_pl_right(data);
//     if (keycode == 115)
//         move_pl_down(data);
//     if (keycode == 119)
//         move_pl_up(data);
//     return (0);
// }

void the_real_work(t_map *map_info)
{
    t_data *data;
    t_mlx *mlx;
    t_all_img *imgs;
    t_img *new_image;

    data = malloc(sizeof(t_data));
    // imgs = malloc(sizeof(t_all_img));
    // mlx = malloc(sizeof(t_mlx));
    mlx->init = mlx_init();
    mlx->win = mlx_new_window(mlx->init, 64 * map_info->width, 64 * map_info->height, "my game");
    load_imgs(mlx, imgs);
    init_all(map_info, data, imgs, mlx);
    //put_static_map(mlx, imgs, map_info);
    // mlx_key_hook(mlx->win, key_handler, data);
    mlx_loop_hook(mlx->init, the_animation, data);
    //put_var_map(data, imgs, map_info);
    // for (int i = 0; i < map_info->hight ; i++)
    //     for(int j = 0; j < map_info->width; j++)
    //         mlx_put_image_to_window(mlx->init, mlx->win, imgs->background.img, 64 * j, 64 * i);

    // int i = 0;
    // int j = 0;
    // new_image->img = mlx_new_image(data->mlx, 64 * map_info->width, 64 * map_info->hight);
    // new_image->addr = mlx_get_data_addr(new_image->img, &new_image->bpp, &new_image->line_length, &new_image->endian);
    // int c = 0;
    // while(map_info->map[j])
    // {
    //     i = 0;
    //     while (map_info->map[j][i])
    //     {
    //         if (map_info->map[j][i] == '1')
    //             mlx_put_image_to_window(data->mlx->init, new_image, imgs->wall.img, 64 * i, 64 * j);
    //         else
    //             mlx_put_image_to_window(data->mlx->init, new_image, imgs->background.img, 64 * i, 64 * j);
    //         i++;
    //     }
    //     j++;
    // }
    // i =  j = 0;
    // while (map_info->map[i])
    // {
    //     j = 0;
    //     while (map_info->map[i][j])
    //     {
    //         if (map_info->map[i][j] == 'P')
    //             put_mini_image_to_window(new_image, imgs->pl_idle.img, 64 * j, 64 * i, c * 64);
    //             //mlx_put_image_to_window(mlx->init, mlx->win, imgs->pl_idle.img, 64 * j, 64 * i);
    //         if (map_info->map[i][j] == 'C')
    //             put_mini_image_to_window(new_image, imgs->coint.img, 64 * j, 64 * i, c * 64);
    //             //mlx_put_image_to_window(mlx->init, mlx->win, imgs->coint.img, 64 * j, 64 * i);
    //         if (map_info->map[i][j] == 'E')
    //             put_mini_image_to_window(new_image, imgs->exit.img, 64 * j, 64 * i, c * 64);
    //             //mlx_put_image_to_window(mlx->init, mlx->win, imgs->exit.img, 64 * j, 64 * i);
    //         j++;
    //     }
    //     i++;
    // }
    // mlx_put_image_to_window(mlx->init, mlx->win, new_image->img, 0, 0);
    mlx_loop(mlx->init);
}


    // while (str[i])
    //     while (str[i][j])
    //         if (str[i][j] == '1')
    //             mlx_put_image_to_window(data.mlx, data.win, img.img, 64 * i, 16 * j);
    //         if ()
    // mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);


// int the_animation(t_data *data)
// {
//     static int c = 0;
//     int i = 0;
//     int j = 0;
//     t_img *new_image;

//     new_image->img = mlx_new_image(data->mlx->init, 64 * data->map->width, 64 * data->map->hight);
//     new_image->addr = mlx_get_data_addr(new_image->img, &new_image->bpp, &new_image->line_length, &new_image->endian);
    // while (data->map->map[j])
    // {
    //     i = 0;
    //     while (data->map->map[j][i])
    //     {
    //         if (data->map->map[j][i] == '1')
    //             mlx_put_image_to_window(data->mlx->init, new_image->img, data->imgs->wall.img, 64 * i, 64 * j);
    //         else
    //             mlx_put_image_to_window(data->mlx->init, new_image->img, data->imgs->background.img, 64 * i, 64 * j);
    //         i++;
    //     }
    //     j++;
    // }
    // i =  j = 0;
    // while (data->map->map[i])
    // {
    //     j = 0;
    //     while (data->map->map[i][j])
    //     {
    //         // if (data->map->map[i][j] == 'P')
    //         //     put_mini_image_to_window(new_image, data->imgs->pl_idle.img, 64 * j, 64 * i, (c % 6) * 64);
    //         if (data->map->map[i][j] == 'C')
    //             put_mini_image_to_window(new_image, data->imgs->coint.img, 64 * j, 64 * i, (c % 6) * 64);
    //         if (data->map->map[i][j] == 'E')
    //             put_mini_image_to_window(new_image, data->imgs->exit.img, 64 * j, 64 * i, (c % 6) * 64);
    //         j++;
    //     }
    //     i++;
    // }
//     mlx_put_image_to_window(data->mlx->init, data->mlx->win, new_image->img, 0, 0);
//     c++;
//     return (0);
// }