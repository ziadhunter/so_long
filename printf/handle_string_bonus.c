/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:35:00 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:35:02 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_string(va_list args, t_flags found)
{
	char	*str;
	int		i;

	i = 0;
	(void)found;
	str = va_arg(args, char *);
	if (!str)
		return (print(")llun(", 5));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
