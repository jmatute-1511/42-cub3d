/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:25:39 by jmatute-          #+#    #+#             */
/*   Updated: 2021/05/19 10:25:43 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char			*dst_str1;
	const unsigned char		*src_str2;

	dst_str1 = (unsigned char *)str1;
	src_str2 = (const unsigned char *)str2;
	if (str1 == str2)
		return (str1);
	while (n > 0 && dst_str1 > src_str2)
	{
		dst_str1[n - 1] = src_str2[n - 1];
		n--;
	}
	if (dst_str1 < src_str2)
		return (ft_memcpy(str1, str2, n));
	return (str1);
}
