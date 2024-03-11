/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:08 by omougel           #+#    #+#             */
/*   Updated: 2024/01/19 17:05:01 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_display(unsigned int u, char *base)
{
	write(1, &base[u], 1);
}

void	ft_putnbr_base(unsigned int u, char *base)
{
	unsigned int	b;

	b = ft_strlen(base);
	if (u >= b)
	{
		ft_putnbr_base(u / b, base);
		ft_putnbr_base(u % b, base);
	}
	if (u < b)
	{
		ft_display(u, base);
	}
}
