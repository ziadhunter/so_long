/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:41:30 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/14 01:42:04 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_string(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	invalid_path(char **lines, char **lines2, t_path *check,
		t_map *map_info)
{
	free_double_string(lines);
	free_double_string(lines2);
	free(check);
	free(map_info);
	write(1, "invalid path\n", 13);
	exit(1);
}

void	check_components(char *str, char **lines)
{
	int		i;
	char	c;

	i = 1;
	while (str[i])
	{
		c = str[i++];
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		{
			free_double_string(lines);
			eror_exit(4);
		}
	}
	if (str[0] != '1' || str[--i] != '1')
	{
		free_double_string(lines);
		eror_exit(3);
	}
}

void	all_walls(char *str, char **lines)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != '1')
		{
			free_double_string(lines);
			eror_exit(3);
		}
	}
}

void	check_walls(char **lines)
{
	int	i;

	i = 0;
	all_walls(lines[0], lines);
	while (lines[i])
		check_components(lines[i++], lines);
	all_walls(lines[--i], lines);
}
