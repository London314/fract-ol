/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:04 by omougel           #+#    #+#             */
/*   Updated: 2023/11/27 11:22:24 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[i - ft_strlen(s1)])
	{
		dest[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	return (dest);
}
