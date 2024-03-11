/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:28 by omougel           #+#    #+#             */
/*   Updated: 2023/11/16 16:18:32 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;
	size_t				i;

	ptr1 = (unsigned const char *)s1;
	ptr2 = (unsigned const char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] == ptr2[i] && (ptr1[i] || ptr2[i]) && i + 1 < n)
		i++;
	return (ptr1[i] - ptr2[i]);
}
