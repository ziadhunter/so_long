#include "so_long.h"

int main(int ac, char **av)
{
    t_map *map_info;

    if (ac == 2)
    {
        check_map(av[1], &map_info);
        the_size_of_map(&map_info);
        the_real_work(map_info);
    }
    return (0);
}