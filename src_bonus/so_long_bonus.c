/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 07:00:38 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 20:03:14 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else
	{
		ft_printf("Error\ninvalid parameters\n");
		return (1);
	}
	return (0);
}
