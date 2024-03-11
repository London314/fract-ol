/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:59:28 by omougel           #+#    #+#             */
/*   Updated: 2023/11/27 07:57:08 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s != (unsigned char)c && *s)
		s++;
	if (!*s)
		return (NULL);
	return ((char *)s);
}
