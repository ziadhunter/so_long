#include "so_long.h"

void reset_en_cord(t_data *data, int count, int *one, int *c)
{
    *one = 0;
    int x;
    int y;

    *c = 0;
    x = data->map->player.x;
    y = data->map->player.y;
    data->map->enemy[count].x =  data->map->enemy[count].new_x;
    if (data->map->enemy[count].x == x && data->map->enemy[count].y == y)
        free_all_data_and_exit(data, "malek 7mar???");
    data->map->enemy[count].movement = 0;
}

int is_enemy(t_data *data)
{
    int count;
    int x;
    int y;

    x = data->map->player.x;
    y = data->map->player.y;
    count = 0;
    while (count < data->map->enemy_count)
    {
        if (x == data->map->enemy[count].x && y == data->map->enemy[count].y)
            return (1);
        count++;
    }
    return (0);
}

void check_position(t_data *data)
{
    if (data->map->map[data->map->player.y][data->map->player.x] == 'E' && data->map->collectible == data->map->collected)
        free_all_data_and_exit(data, "You win\n");
    else if (data->map->map[data->map->player.y][data->map->player.x] == 'C')
    {
        data->map->collected++;
        data->map->map[data->map->player.y][data->map->player.x] = 'F';
    }
    else if (is_enemy(data))
        free_all_data_and_exit(data, "fucking loser hahahahahahahaha");
}

void reset_cordonites(t_data *data)
{
    if (data->map->keys == 'l' && !is_wall(data, data->map->player.x - 1, data->map->player.y))
        data->map->player.x--;
    else if (data->map->keys == 'r' && !is_wall(data, data->map->player.x + 1, data->map->player.y))
        data->map->player.x++;
    else if (data->map->keys == 'u' && !is_wall(data, data->map->player.x, data->map->player.y - 1))
        data->map->player.y--;
    else if (data->map->keys == 'd' && !is_wall(data, data->map->player.x, data->map->player.y + 1))
        data->map->player.y++;
    check_position(data);
    data->map->player.movement = 0;
    data->map->keys = 'i';
}