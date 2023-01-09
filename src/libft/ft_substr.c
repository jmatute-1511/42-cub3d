/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:00:49 by jmatute-          #+#    #+#             */
/*   Updated: 2021/06/02 10:51:43 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = ft_strlen(s);
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_bzero(cpy, len);
	else if (len > 0)
		ft_memcpy(cpy, &s[start], len);
	cpy[len] = '\0';
	return (cpy);
}
