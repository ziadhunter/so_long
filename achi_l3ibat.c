#include "so_long.h"



void the_size_of_map(t_map **map_info)
{
    (*map_info)->width = 0;
    (*map_info)->height = 0;

    while(((*map_info)->map)[(*map_info)->height])
        ((*map_info)->height)++;
    while(((*map_info)->map)[0][(*map_info)->width])
        ((*map_info)->width)++;
}