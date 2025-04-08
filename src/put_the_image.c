/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_the_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 07:01:24 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 23:25:21 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	info_num(int n, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	if (n < 0)
	{
		i++;
		*sign = -1;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*p;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = info_num(n, &sign);
	if (n < 0)
		n *= -1;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	p[i] = '\0';
	while (n != 0)
	{
		p[--i] = ((n % 10) + 48);
		n /= 10;
	}
	if (sign == -1)
		p[--i] = '-';
	return (p);
}

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

void	put_mini_image_to_window(t_img *dst, t_img *src, t_coord coord,
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
			if (color != 0xFF000000 && color != 0x00FFFFFF)
				put_pixel(dst, coord.x + i, coord.y + j, color);
			x++;
			i++;
		}
		j++;
		y++;
	}
}
