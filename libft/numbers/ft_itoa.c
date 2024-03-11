/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:26:06 by omougel           #+#    #+#             */
/*   Updated: 2023/11/27 10:28:19 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_put_in_ascii(int n, char *ascii, int *i)
{
	if (n < 0)
	{
		ascii[*i] = '-';
		*i += 1;
		n = -n;
	}
	if (n >= 10)
	{
		ft_put_in_ascii(n / 10, ascii, i);
		ft_put_in_ascii(n % 10, ascii, i);
	}
	if (n < 10)
	{
		n += 48;
		ascii[*i] = n;
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*ascii;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		ascii = ft_strdup("-2147483648");
		if (!ascii)
			return (NULL);
		return (ascii);
	}
	ascii = ft_calloc(ft_intlen(n) + 1, sizeof(char));
	if (!ascii)
		return (NULL);
	ft_put_in_ascii(n, ascii, &i);
	return (ascii);
}
