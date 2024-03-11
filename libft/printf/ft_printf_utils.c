/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:00:19 by omougel           #+#    #+#             */
/*   Updated: 2024/02/14 17:33:55 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen_from_i_till_c(const char *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i + len] && str[i + len] != c)
		len++;
	return (len);
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		*len += ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		(*len) += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	if (nb < 10)
		*len += ft_putchar(nb + 48);
}

void	ft_putnbr_blen(unsigned int nb, unsigned int b, char *base, int *len)
{
	if (nb >= b)
	{
		ft_putnbr_blen(nb / b, b, base, len);
		ft_putnbr_blen(nb % b, b, base, len);
	}
	if (nb < b)
		*len += ft_putchar(base[nb]);
}
