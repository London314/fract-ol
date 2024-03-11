/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:00:31 by omougel           #+#    #+#             */
/*   Updated: 2023/11/24 18:12:11 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	unsigned const char	*ptrsrc;

	ptrdest = dest;
	ptrsrc = src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			ptrdest[n] = ptrsrc[n];
		}
	}
	return (dest);
}
