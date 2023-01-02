/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:42:58 by jmatute-          #+#    #+#             */
/*   Updated: 2022/05/11 20:05:10 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		count;
	char		*cpy_s;
	int			len;

	cpy_s = (char *)s;
	count = 0;
	len = ft_strlen(s);
	while (count <= len)
	{
		if (cpy_s[count] == (char)c)
			return ((char *)s + count);
		count++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
