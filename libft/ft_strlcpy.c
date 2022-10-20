/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:32:44 by jmatute-          #+#    #+#             */
/*   Updated: 2022/05/16 15:43:58 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const	char *src, size_t dstsize)
{
	size_t				count;
	unsigned char		*cpy_src;

	cpy_src = (unsigned char *)src;
	count = 0;
	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (cpy_src[count] && count < (dstsize - 1))
	{
		dst[count] = cpy_src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}
