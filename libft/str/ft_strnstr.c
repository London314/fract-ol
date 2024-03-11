/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:32:10 by omougel           #+#    #+#             */
/*   Updated: 2023/11/16 17:01:34 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	while (*big && len > 0 && len >= ft_strlen(little))
	{
		if (!ft_strncmp(big, little, ft_strlen(little)))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
