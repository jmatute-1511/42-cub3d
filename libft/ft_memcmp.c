/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:40:15 by jmatute-          #+#    #+#             */
/*   Updated: 2021/06/01 11:08:04 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				count;
	int					diff;
	unsigned char		*cpy_str1;
	unsigned char		*cpy_str2;

	count = 0;
	diff = 0;
	cpy_str1 = (unsigned char *) str1;
	cpy_str2 = (unsigned char *) str2;
	while (count < n)
	{
		if (cpy_str1[count] != cpy_str2[count])
		{
			diff = cpy_str1[count] - cpy_str2[count];
			return (diff);
		}
		count++;
	}
	return (0);
}
