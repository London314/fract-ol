/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_till_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:42:41 by omougel           #+#    #+#             */
/*   Updated: 2023/11/29 08:07:08 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen_till_c(char const *str, char c, size_t i)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}
