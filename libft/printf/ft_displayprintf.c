/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:50:28 by omougel           #+#    #+#             */
/*   Updated: 2024/02/14 17:33:30 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == 1)
		return (1);
	return (0);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	if (write(1, str, ft_strlen(str)) == -1)
		return (0);
	return (ft_strlen(str));
}

void	ft_putaddress_base(unsigned long address, char *base, int *len)
{
	if (address >= 16)
	{
		ft_putaddress_base(address / 16, base, len);
		ft_putaddress_base(address % 16, base, len);
	}
	if (address < 16)
		*len += ft_putchar(base[address]);
}

int	ft_putaddress(void *ptr)
{
	int	return_len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	return_len = ft_putstr("0x");
	ft_putaddress_base((unsigned long)ptr, "0123456789abcdef", &return_len);
	return (return_len);
}
