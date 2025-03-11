/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:40:41 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/11 00:51:30 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *str, char *cmp, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i] && str[i] == cmp[i])
		i++;
	return (str[i] - cmp[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;

	int (i), (j);
	i = 0;
	j = 0;
	if (!s1)
	{
		new = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!new)
			return (NULL);
		while (s2[j])
			new[i++] = s2[j++];
		return (new[i] = '\0', free(s2), new);
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (free(s1), free(s2), NULL);
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (free(s1), free(s2), new);
}

char	*ft_strdup(char *s1)
{
	int		j;
	int		i;
	char	*p;

	i = ft_strlen(s1);
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	**duplicate(char **lines)
{
	int		i;
	int		j;
	char	**lines2;

	i = 0;
	while (lines[i])
		i++;
	j = 0;
	while (lines[0][j])
		j++;
	if (i > 60 || j > 60)
	{
		eror_exit(5);
	}
	lines2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (lines[i])
	{
		lines2[i] = ft_strdup(lines[i]);
		i++;
	}
	lines2[i] = NULL;
	return (lines2);
}
