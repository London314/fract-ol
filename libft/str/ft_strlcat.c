/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:50:32 by omougel           #+#    #+#             */
/*   Updated: 2023/11/27 08:03:33 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlast;
	size_t	i;

	if (ft_strlen(dest) < size)
	{
		destlast = ft_strlen(dest);
		i = 0;
		while (destlast + 1 < size && src[i])
			dest[destlast++] = src[i++];
		dest[destlast] = '\0';
		return (ft_strlen(src) + ft_strlen(dest) - i);
	}
	return (size + ft_strlen(src));
}
