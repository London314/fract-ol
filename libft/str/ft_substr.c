/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:25 by omougel           #+#    #+#             */
/*   Updated: 2024/02/14 18:06:03 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!len || start > ft_strlen(s) || !s)
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
		return (dest);
	}
	dest = ft_calloc(sizeof(char), ft_min(ft_strlen(s) - start, len) + 1);
	if (!dest)
		return (NULL);
	while (i < len && s[start])
		dest[i++] = s[start++];
	return (dest);
}
