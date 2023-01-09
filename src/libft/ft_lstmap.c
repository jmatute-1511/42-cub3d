/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:09:40 by jmatute-          #+#    #+#             */
/*   Updated: 2021/06/02 13:11:23 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux_i;
	t_list	*aux_cpy;

	if (!lst)
		return (NULL);
	aux_cpy = ft_lstnew(f(lst->content));
	if (!aux_cpy)
		return (NULL);
	aux_i = aux_cpy;
	while (lst)
	{
		if (lst->next)
		{
			aux_cpy->next = ft_lstnew(f(lst->next->content));
			if (!(aux_cpy->next))
			{
				ft_lstclear(&aux_cpy, del);
				return (NULL);
			}
			aux_cpy = aux_cpy->next;
		}
		lst = lst->next;
	}
	aux_cpy->next = NULL;
	return (aux_i);
}
