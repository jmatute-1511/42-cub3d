/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:20:03 by jmatute-          #+#    #+#             */
/*   Updated: 2021/06/01 11:08:33 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*straux;

	straux = str;
	count = 0;
	while (count < n)
	{
		straux[count] = (unsigned char) c;
		count++;
	}
	return (str);
}
