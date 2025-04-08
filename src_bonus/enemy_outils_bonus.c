/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_outils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:30:02 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 20:04:05 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_time(t_data *data)
{
	if (data->map->height <= 10)
		return (10);
	else if (data->map->height <= 20)
		return (3);
	else
		return (1);
}

int	is_time_en(t_data *data)
{
	if (data->map->height <= 10)
		return (20);
	else if (data->map->height <= 20)
		return (7);
	else
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
