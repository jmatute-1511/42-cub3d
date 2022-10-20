/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:37:21 by jmatute-          #+#    #+#             */
/*   Updated: 2021/11/12 19:15:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;
	t_list	*aux;

	len = 0;
	aux = lst;
	while (aux)
	{
		aux = aux->next;
		len++;
	}
	return (len);
}
