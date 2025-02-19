#include "so_long.h"



void the_size_of_map(t_map **map_info)
{
    (*map_info)->x = 0;
    (*map_info)->y = 0;

    while(((*map_info)->map)[(*map_info)->y])
        ((*map_info)->y)++;
    while(((*map_info)->map)[0][(*map_info)->x])
        ((*map_info)->x)++;
}