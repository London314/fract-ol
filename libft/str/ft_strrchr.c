/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:33:27 by omougel           #+#    #+#             */
/*   Updated: 2023/11/21 17:24:09 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = 0;
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (unsigned char)c)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
