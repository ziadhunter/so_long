/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:34:31 by zfarouk           #+#    #+#             */
/*   Updated: 2025/01/09 13:34:33 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_pointer(va_list args, t_flags found)
{
	int				count;
	unsigned long	j;

	(void)found;
	j = va_arg(args, unsigned long);
	if (j == 0)
		return (print(")lin(", 4));
	count = write(1, "0x", 2);
	count += ft_putnbr_base(j, "0123456789abcdef");
	return (count);
}
