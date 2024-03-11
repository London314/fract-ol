/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omougel <omougel@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:32:34 by omougel           #+#    #+#             */
/*   Updated: 2023/11/24 16:55:02 by omougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static t_list	*ft_clear(t_list **newlist, void (*del)(void*))
{
	ft_lstclear(newlist, (*del));
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node_tmp;

	newlist = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		node_tmp = malloc(sizeof(t_list));
		if (!node_tmp)
			return (ft_clear(&newlist, (*del)));
		node_tmp->content = (*f)(lst->content);
		if (!node_tmp->content)
		{
			free(node_tmp);
			return (ft_clear(&newlist, (*del)));
		}
		node_tmp->next = NULL;
		ft_lstadd_back(&newlist, node_tmp);
		lst = lst->next;
	}
	return (newlist);
}
