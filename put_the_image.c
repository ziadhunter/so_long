/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_the_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 07:01:24 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/07 07:01:31 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pick_pixel(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_mini_image_to_window(t_img *dst, t_img *src, int x_dst, int y_dst,
		int x_src)
{
	int				y;
	int				x;
	int				i;
	int				j;
	unsigned int	color;

	y = 0;
	j = 0;
	while (y < 64)
	{
		x = x_src;
		i = 0;
		while (x < 64 + x_src)
		{
			color = pick_pixel(src, x, y);
			if (color != 0xFF000000)
				put_pixel(dst, x_dst + i, y_dst + j, color);
			x++;
			i++;
		}
		j++;
		y++;
	}
}
