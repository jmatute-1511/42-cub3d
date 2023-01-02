/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:19:18 by jmatute-          #+#    #+#             */
/*   Updated: 2022/07/01 13:38:13 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*str;
	char	*str_src;

	str = dst;
	str_src = (char *)src;
	count = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (count < n)
	{
		str[count] = str_src[count];
		count++;
	}
	return (dst);
}
