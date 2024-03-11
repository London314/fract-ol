/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:02:25 by omougel           #+#    #+#             */
/*   Updated: 2023/11/27 11:25:25 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
