#include "so_long.h"

// void player_state_left(t_data *data)
// {
//     if (data->map->player.movement == 0)
//         data->map->player.movement = 4;
//     else
//         data->map->player.movement = 0;
// }

// void player_state_right(t_data *data)
// {
//     if (data->map->player.movement == 0)
//         data->map->player.movement = 3;
//     else
//         data->map->player.movement = 0;
// }

// void player_state_down(t_data *data)
// {
//     if (data->map->player.movement == 0)
//         data->map->player.movement = 2;
//     else
//         data->map->player.movement = 0;
// }

// void player_state_up(t_data *data)
// {
//     if (data->map->player.movement == 0)
//         data->map->player.movement = 1;
//     else
//         data->map->player.movement = 0;
// }

// int key_handler(int keycode, t_data *data)
// {
//     if (keycode == 65307)
//         exit(0);
//     if (keycode == 97)
//         player_state_left(data);
//     if (keycode == 100)
//         player_state_right(data);
//     if (keycode == 115)
//         player_state_down(data);
//     if (keycode == 119)
//         player_state_up(data);
//     return (0);
// }




int key_handler(int keycode, t_data *data)
{
    if (keycode == 65307)
        free_all_data_and_exit(data, "you exit the game!!\n");
    if (keycode == 97 && !is_wall(data, data->map->player.x - 1, data->map->player.y))
        data->map->player.x--;
    if (keycode == 100 && !is_wall(data, data->map->player.x + 1, data->map->player.y))
        data->map->player.x++;
    if (keycode == 115 && !is_wall(data, data->map->player.x, data->map->player.y + 1))
        data->map->player.y++;
    if (keycode == 119 && !is_wall(data, data->map->player.x, data->map->player.y - 1))
        data->map->player.y--;
    return (0);
}