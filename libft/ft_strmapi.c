/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:59:48 by jmatute-          #+#    #+#             */
/*   Updated: 2021/05/29 14:14:05 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*cpy_modified;
	size_t				len;
	unsigned int		i;

	i = 0 ;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	cpy_modified = malloc(len + 1);
	if (!cpy_modified)
		return (NULL);
	while (s[i])
	{
		cpy_modified[i] = (*f)(i, s[i]);
		i++;
	}
	cpy_modified[i] = '\0';
	return (cpy_modified);
}
