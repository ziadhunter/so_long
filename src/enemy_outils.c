/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:30:02 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 17:46:57 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_time(t_data *data)
{
	if (data->map->height < 5)
		return (30);
	else if (data->map->height <= 10)
		return (6);
	else if (data->map->height <= 20)
		return (3);
	return (1);
}

int	is_time_en(t_data *data)
{
	if (data->map->height <= 10)
		return (15);
	else if (data->map->height <= 20)
		return (7);
	return (4);
}

void	render_moves(t_data *data)
{
	char	*moves_str;
	char	*message;

	moves_str = ft_itoa(data->map->player.number);
	message = ft_strjoin(ft_strdup("Moves: "), moves_str);
	mlx_string_put(data->mlx->init, data->mlx->win, 64, data->map->height * 64,
		0xFFFFFF, message);
	free(message);
}
