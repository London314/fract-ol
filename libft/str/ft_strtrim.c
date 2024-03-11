/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:47:50 by omougel           #+#    #+#             */
/*   Updated: 2024/02/14 18:04:54 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_isinset(char s1, char const *set)
{
	size_t	iset;

	iset = 0;
	while (set[iset])
	{
		if (s1 == set[iset])
			return (1);
		iset++;
	}
	return (0);
}

size_t	ft_indfirstset(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	if (!*set)
		return (0);
	while (ft_isinset(s1[i], set) && s1[i])
		i++;
	return (i);
}

size_t	ft_indlastset(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	if (!*set)
		return (ft_strlen(s1));
	while (ft_isinset(s1[i], set) && i != 0)
		i--;
	if (ft_isinset(s1[i], set))
		return (i);
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	ifset;
	size_t	ilset;

	ifset = ft_indfirstset(s1, set);
	ilset = ft_indlastset(s1, set);
	if (!*s1 || ifset >= ilset)
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
		return (dest);
	}
	dest = ft_substr(s1, ifset, ilset - ifset);
	if (!dest)
		return (NULL);
	return (dest);
}
