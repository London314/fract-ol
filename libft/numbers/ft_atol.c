/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:31:28 by omougel           #+#    #+#             */
/*   Updated: 2024/01/29 15:35:44 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long	ft_atol(const char *str)
{
	size_t		i;
	int			sign;
	long		number;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (number != (number * 10 + str[i] - 48) / 10)
			return (LONG_MAX);
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * sign);
}
