/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:26:59 by jmatute-          #+#    #+#             */
/*   Updated: 2021/06/01 11:59:11 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *orig, int c, size_t n)
{
	size_t			count;
	unsigned char	*cpy_dst;
	unsigned char	*cpy_orig;

	count = 0;
	cpy_orig = (unsigned char *)orig;
	cpy_dst = (unsigned char *)dst;
	while (count < n)
	{
		cpy_dst[count] = cpy_orig[count];
		if (cpy_orig[count] == (unsigned char)c)
			return (dst + (count + 1));
		count++;
	}
	return (NULL);
}
