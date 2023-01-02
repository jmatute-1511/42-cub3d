/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:14:51 by jmatute-          #+#    #+#             */
/*   Updated: 2022/05/13 20:47:51 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	d;

	a = 0;
	d = 0;
	if (needle[d] == '\0')
		return ((char *)haystack);
	else if (haystack[d] == '\0')
		return (0);
	while (haystack[a] && a < len)
	{
		while (haystack[a + d] == needle[d] && needle[d] && a + d < len)
		{
			if (d + 1 == ft_strlen(needle))
				return ((char *)haystack + a + d + 1);
			d++;
		}
		d = 0;
		a++;
	}
	return (NULL);
}
