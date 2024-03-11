/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:17 by omougel           #+#    #+#             */
/*   Updated: 2024/02/14 17:57:27 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**ft_free_tab(char **tab, int itab)
{
	if (tab)
	{
		while (itab > 0)
			free(tab[--itab]);
		free(tab);
	}
	return (NULL);
}

static size_t	ft_strlen_till_c_with_i(char const *str, char c, size_t i)
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

static size_t	ft_count_strs(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	if (!c && *str)
		return (1);
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		if (str[i] == c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	lenstr;
	size_t	itab;
	size_t	istr;

	istr = 0;
	itab = 0;
	lenstr = ft_strlen_till_c_with_i(s, c, istr);
	tab = ft_calloc(sizeof(char *), (ft_count_strs(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (itab < ft_count_strs(s, c))
	{
		while (ft_strlen_till_c_with_i(s, c, istr) == 0)
			lenstr = ft_strlen_till_c_with_i(s, c, ++istr);
		tab[itab] = ft_substr(s, istr, lenstr);
		if (!tab[itab])
			return (ft_free_tab(tab, itab));
		itab++;
		istr += lenstr;
	}
	return (tab);
}
