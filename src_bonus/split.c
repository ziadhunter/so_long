/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:46:21 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/09 16:46:23 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_word(char const *s, char c, int *size)
{
	size_t	i;
	size_t	word;
	int		count;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		if (s[i] == c && word == 1)
			word = 0;
		i++;
	}
	*size = i;
	return (count);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*p;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

char	**allocation(char **p, char *s, char c, int size)
{
	int (j), (i), (word), (l);
	j = 0;
	i = 0;
	word = 0;
	l = 0;
	while (i <= size)
	{
		if ((s[i] != c && s[i] != 0) && word == 0)
		{
			l = i;
			word = 1;
		}
		if ((s[i] == c || s[i] == '\0') && word == 1)
		{
			p[j] = ft_substr(s, (unsigned int)l, (size_t)(i - l));
			if (!p[j])
				return (free_array(p, j));
			j++;
			word = 0;
		}
		i++;
	}
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;
	int		size_s;

	if (!s)
		return (NULL);
	i = count_word(s, c, &size_s);
	p = malloc((i + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	p = allocation(p, s, c, size_s);
	if (!p)
		return (NULL);
	p[i] = NULL;
	free(s);
	return (p);
}
