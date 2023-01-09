/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:17:35 by jmatute-          #+#    #+#             */
/*   Updated: 2022/07/04 18:24:56 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(char *str, size_t len)
{
	int		count;
	char	*aux;

	count = 0;
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	aux = (char *)malloc(sizeof(char) * len + 1);
	if (!aux)
		return (NULL);
	while (count < len)
	{
		aux[count] = str[count];
		count++;
	}
	aux[count] = '\0';
	return (aux);
}
