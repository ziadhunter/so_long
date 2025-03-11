/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:25 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:31:27 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_char(va_list args, t_flags found)
{
	char	c;

	(void)found;
	c = va_arg(args, int);
	return (write(1, &c, 1));
}
