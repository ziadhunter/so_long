/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:34:26 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/10 21:34:29 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(char **str, int x, int y, t_path *check)
{
    if (x < 0 || y < 0 || !str[y] || !str[y][x])
        return;
    if (str[y][x] == '1' || str[y][x] == '#')
        return;
    if (str[y][x] == 'C')
        check->C++;
    else if (str[y][x] == 'E')
        check->E++;
    str[y][x] = '#';
    flood_fill(str, x + 1, y, check);
    flood_fill(str, x - 1, y, check);
    flood_fill(str, x, y + 1, check);
    flood_fill(str, x, y - 1, check);
}
