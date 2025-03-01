#include "so_long.h"

void initialize_player(t_map *map_info)
{
    int i;
    int j;

    j = 0;
    while(map_info->map[j])
    {
        i = 0;
        while (map_info->map[j][i])
        {
            if (map_info->map[j][i] == 'P')
            {
                map_info->player.x = i;
                map_info->player.y = j;
                map_info->player.real_x = i * 64;
                map_info->player.real_y = j * 64;
                map_info->player.new_x = i;
                map_info->player.new_y = j;
            }
            i++;
        }
        j++;
    }
    map_info->keys = 'i';
    map_info->player.movement = 0;
    map_info->player.wich_picture = 0;
}
void initialize_exit(t_map *map_info)
{
    int i;
    int j;

    j = 0;
    while(map_info->map[j])
    {
        i = 0;
        while (map_info->map[j][i])
        {
            if (map_info->map[j][i] == 'E')
            {
                map_info->exit.x = i;
                map_info->exit.y = j;
            }
            i++;
        }
        j++;
    } 
}
void initialize_enemy(t_map *map_info)
{
    int i;
    int j;
    int count;

    count = 0;
    j = 0;
    while(map_info->map[j])
    {
        i = 0;
        while (map_info->map[j][i])
        {
            if (map_info->map[j][i] == 'C')
            {
                map_info->enemy[count].x = i;
                map_info->enemy[count].y = j;
                map_info->enemy[count].new_x = i;
                map_info->enemy[count].new_y = j;
                count++;
            }
            i++;
        }
        j++;
    }
}

void initialize_coins(t_map *map_info)
{
    int i;
    int j;
    int count;

    count = 0;
    j = 0;
    map_info->coins = malloc(sizeof(t_coin) * map_info->collectible);
    if (!map_info->coins)
        return;
    while (map_info->map[j])
    {
        i = 0;
        while (map_info->map[j][i])
        {
            if (map_info->map[j][i] == 'C' && count < map_info->collectible)
            {

                    map_info->coins[count].x = i;
                    map_info->coins[count].y = j;
                    count++;
            }
            i++;
        }
        j++;
    }
}



void get_info(t_map *map_info)
{
    map_info->collected = 0;
    initialize_player(map_info);
    initialize_exit(map_info);
    // initialize_enemy(map_info);
    initialize_coins(map_info);
}