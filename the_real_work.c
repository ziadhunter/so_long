#include "so_long.h"


void free_imgs(t_data *data)
{
    mlx_destroy_image(data->mlx->init, data->imgs->background.img);
    mlx_destroy_image(data->mlx->init, data->imgs->wall.img);
    mlx_destroy_image(data->mlx->init, data->imgs->coint.img);
    mlx_destroy_image(data->mlx->init, data->imgs->exit.img);
    mlx_destroy_image(data->mlx->init, data->imgs->pl_idle.img);
}


void free_all_data_and_exit(t_data *data, char *str)
{
    free_double_string(data->map->map);
    free(data->map->coins);
    free_imgs(data);
    free(data->map);
    free(data->imgs);
    mlx_destroy_window(data->mlx->init, data->mlx->win);
    mlx_destroy_display(data->mlx->init);
    free(data->mlx->init);
    free(data->mlx);
    free(data);
    printf("%s\n", str);
    exit(0);
}
void load_imgs(t_mlx *mlx, t_all_img *imgs)
{
    imgs->background.img = mlx_xpm_file_to_image(mlx->init, "./pictures/background_pictures/.xpm", &(imgs->background.width), &(imgs->background.height));
    imgs->background.addr = mlx_get_data_addr(imgs->background.img, &imgs->background.bpp, &imgs->background.line_length, &imgs->background.endian);
    imgs->wall.img = mlx_xpm_file_to_image(mlx->init, "./pictures/wall_pictures/wall.xpm", &imgs->wall.width, &imgs->wall.height);
    imgs->wall.addr = mlx_get_data_addr(imgs->wall.img, &imgs->wall.bpp, &imgs->wall.line_length, &imgs->wall.endian);
    imgs->coint.img = mlx_xpm_file_to_image(mlx->init, "./pictures/coint_pictures/coint.xpm", &imgs->coint.width, &imgs->coint.height);
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

    // imgs->coint_effect.img = mlx_xpm_file_to_image(data->init, "./pictures/coint_pictures/coin_effect.xpm", &imgs->coint_effect.width, &imgs->coint_effect.height);
    
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


void move_pl_left(t_data *data)
{
    int x;
    int y;
    unsigned int l = 0;
    int k;

    k = 6;
    x = data->map->p_post_x;
    y = data->map->p_post_y;
    if (x > 0 &&  data->map->map[y][x - 1] != '1' &&(data->map->map[y][x - 1] == '0' || data->map->map[y][x - 1] == 'C' || data->map->map[y][x - 1] == 'E'))
    {
        data->map->player.movement = 2;
        while ( l < 115000) 
        {
            if (l % 19000 == 0 && k > 0)
            {
                data->map->player.real_x = ((data->map->player.x - 1) * 64) + (11 * k) - 2;
                data->map->player.real_y = (data->map->player.y * 64);
                k--;
            }
            l++;
        }
    data->map->player.x = data->map->player.x - 1;
    data->map->player.movement = 0;
    }
}
    // if (data->map->player.movement == 1)
    //     put_mini_image_to_window(new_image, &data->imgs->pl_down, data->map->player.real_x, data->map->player.real_y, (c % 6) * 64);
    // if (data->map->player.movement == 2)
    //     put_mini_image_to_window(new_image, &data->imgs->pl_left, data->map->player.real_x, data->map->player.real_y, (c % 6) * 64);
    // if (data->map->player.movement == 3)
    //     put_mini_image_to_window(new_image, &data->imgs->pl_right, data->map->player.real_x, data->map->player.real_y, (c % 6) * 64);
    // else if (data->map->player.movement == 4)
    //     put_mini_image_to_window(new_image, &data->imgs->pl_up, data->map->player.real_x, data->map->player.real_y, (c % 6) * 64);
// void set_real_position(t_data data, int c)
// {
//     if (data->map->player.new_x > data->map->player.x)
//     {
//         data->map->player.real_x = ((data->map->player.x * 64) + (11 * c) - 2);
//         data->map->player.real_y = data->map->player.y * 64;
//     }
//     else if (data->map->player.new_x < data->map->player.x)
//     {
//         data->map->player.real_x = (data->map->player.new_x * 64 + (11 * c) - 2);
//         data->map->player.real_y = data->map->player.y * 64;
//     }
//     else if (data->map->player.new_y > data->map->player.y)
//     {
//         data->map->player.real_x = data->map->player.x * 64;
//         data->map->player.real_y =  ((data->map->player.y * 64) + (11 * c) - 2);
//     }
//     else if (data->map->player.new_y < data->map->player.y)
//     {
//         data->map->player.real_x = data->map->player.x * 64;
//         data->map->player.real_y = ((data->map->player.new_y * 64) + (11 * c) - 2);
//     }
//     else
//     {
//         data->map->player.real_x = data->map->player.x * 64;
//         data->map->player.real_y = data->map->player.y * 64;
//     }
// }

void print_player(t_data *data, t_img *new_image, int c, int x, int y)
{
    static int step = 0;
    if (step >= 64)
    {
        data->map->player.movement = 0;
        step = 0;
    }
    if (data->map->keys == 'l')
    {
        put_mini_image_to_window(new_image, &data->imgs->pl_idle, data->map->player.x * 64 + x * step, data->map->player.y * 64 + y * step, (c % 6) * 64);
        data->map->player.x--;
    }
    else 
    {
        put_mini_image_to_window(new_image, &data->imgs->pl_idle, data->map->player.x * 64 + x * step, data->map->player.y * 64 + y * step, (c % 6) * 64);
    }
    step++;

    // if (data->map->player.new_x > data->map->player.x)
    // {
    //     set_real_position(data, (c % 6) * 64);
    //     put_mini_image_to_window(new_image, &data->imgs->pl_right, data->map->player.real_x, data->map->player.real_y, (c % 6) * 64);
    // }
    // else if (data->map->player.new_x < data->map->player.x)
    //     put_mini_image_to_window(new_image, &data->imgs->pl_left, data->map->player.real_x, data->map->player.real_y, 0);
    // else if (data->map->player.new_y > data->map->player.y)
    //     put_mini_image_to_window(new_image, &data->imgs->pl_down, data->map->player.real_x, data->map->player.real_y, 0);
    // else if (data->map->player.new_y < data->map->player.y)
    //     put_mini_image_to_window(new_image, &data->imgs->pl_up, data->map->player.real_x, data->map->player.real_y, 0);
    // else
    //     put_mini_image_to_window(new_image, &data->imgs->pl_idle, data->map->player.real_x, data->map->player.real_y, 0);
}


void print_coint(t_data *data, t_img *new_image, int c)
{
    int i;
    int j;
    int wich;

    wich = 0;
    j = 0;
    while (data->map->map[j])
    {

        i = 0;
        while (data->map->map[j][i])
        {
            if (data->map->map[j][i] == 'C')
            {
                put_mini_image_to_window(new_image, &data->imgs->coint, 64 * i, 64 * j, (c % 6) * 64);
                wich++;
            }
            i++;
        }
        j++;
    }
}

 void put_static_map(t_data *data, t_img new_image)
{
    int i;
    int j;

    j = 0;
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
}

int the_animation(t_data *data)
{
    static int c = 0;
    static unsigned int l = 0;
    int i = 0;
    int j = 0;
    t_img new_image;

    new_image.img = mlx_new_image(data->mlx->init, 64 * data->map->width, 64 * data->map->height);
    new_image.addr = mlx_get_data_addr(new_image.img, &new_image.bpp, &new_image.line_length, &new_image.endian);
    put_static_map(data, new_image);
    if (l % 100 == 0)
    {

        while (data->map->map[i])
        {
            j = 0;
            while (data->map->map[i][j])
            {
                if (data->map->map[i][j] == 'E')
                    put_mini_image_to_window(&new_image, &data->imgs->exit, 64 * j, 64 * i, 0);
                j++;
            }
            i++;
        }
        print_coint(data, &new_image, c);
        if (data->map->keys == 'i')
            print_player(data, &new_image, c, 0, 0);
        if (data->map->keys == 'l')
            print_player(data, &new_image, c, 1, 0);
        else if (data->map->keys == 'r')
            print_player(data, &new_image, c, -1, 0);
        else if (data->map->keys == 'u')
            print_player(data, &new_image, c, 0, 1);
        else if (data->map->keys == 'd')
            print_player(data, &new_image, c, 0, -1);

        mlx_put_image_to_window(data->mlx->init, data->mlx->win, new_image.img, 0, 0);
        c++;
    }
    mlx_destroy_image(data->mlx->init, new_image.img);
    l++;
    return (0);
}
move

int key_press(int keycode, t_data *data)
{
    static int c = 0;
    if (data->map->player.movement)
        return (0);
    if ((c % 500000) == 0)
        return (0);
    if (keycode == 65307)
        free_all_data_and_exit(data, "you exit the game!!\n"); 
    if (keycode == 97)
        data->map->keys = 'l';
    else if (keycode == 100)
        data->map->keys = 'r';
    else if (keycode == 119)
        data->map->keys = 'u';
    else if (keycode == 115)
        data->map->keys = 'd';
    c++;
    return (0);
}

// int key_release(int keycode, t_data *data)
// { 
//     if (keycode == 97)  
//         data->map->keys[0] = 0;
//     else if (keycode == 100)
//         data->map->keys[1] = 0;
//     else if (keycode == 119)
//         data->map->keys[2] = 0;
//     else if (keycode == 115)
//         data->map->keys[3] = 0;

//     return (0);
// }


// int key_press(int keycode, t_data *data)
// {
//     data->map->event = 0;
//     static int c = 0;

//     if (keycode == 65307)
//         free_all_data_and_exit(data, "you exit the game!!\n"); 
//     if (c % 1 == 0)
//         {        if (keycode == 97 && !is_wall(data, data->map->player.x - 1, data->map->player.y))
//                 data->map->player.x--;
//             else if (keycode == 100 && !is_wall(data, data->map->player.x + 1, data->map->player.y))
//                 data->map->player.x++;
//             else if (keycode == 115 && !is_wall(data, data->map->player.x, data->map->player.y + 1))
//                 data->map->player.y++;
//             else if (keycode == 119 && !is_wall(data, data->map->player.x, data->map->player.y - 1))
//                 data->map->player.y--;
//                 }
    
//     c++;
//     return (0);
// }

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
   // mlx_hook(mlx->win, 3, 1L << 1, key_release, data);
    mlx_key_hook(mlx->win, key_handler, data);
    mlx_loop_hook(mlx->init, the_animation, data);
    mlx_loop(mlx->init);
}



// void move_pl_right(t_data *data)
// {
//     int x;
//     int y;
//     unsigned int l = 0;
//     int k;

//     k = 0;
//     x = data->map->p_post_x;
//     y = data->map->p_post_y;
//     if (x < data->map->width - 1 && (data->map->map[y][x + 1] == '0' || data->map->map[y][x + 1] == 'C' || data->map->map[y][x + 1] == 'E') && data->map->map[y][x + 1] != '1')
//     {
//         data->map->player.movement = 3;
//         while ( l < 115000) 
//         {
//             if (l % 19000 == 0 && k < 6)
//             {
//                 data->map->player.real_x = ((data->map->player.x + 1) * 64) - (11 * k) + 2;
//                 data->map->player.real_y = (data->map->player.y * 64);
//                 k++;
//             }
//             l++;
//         }
//         data->map->player.x = data->map->player.x + 1;
//         data->map->player.movement = 0;
//     }
// }