/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 07:00:38 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/13 16:55:34 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map_info;

	if (ac == 2)
	{
		check_map(av[1], &map_info);
		the_size_of_map(&map_info);
		get_info(map_info);
		the_real_work(map_info);
	}
	return (0);
}
