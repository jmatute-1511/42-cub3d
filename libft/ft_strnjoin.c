/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:08:04 by jmatute-          #+#    #+#             */
/*   Updated: 2022/10/30 19:23:55 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(int nstrings, ...)
{
	char	*cat_string;
	char	*aux;
	char	*str;
	va_list	strings;

	va_start(strings, nstrings);
	str = va_arg(strings, char *);
	aux = va_arg(strings, char *);
	cat_string = ft_strjoin(str, aux);
	nstrings -= 1;
	while (nstrings > 1)
	{
		aux = va_arg (strings, char *);
		str = ft_strdup(cat_string);
		free(cat_string);
		cat_string = ft_strjoin(str, aux);
		free(str);
		nstrings--;
	}
	va_end(strings);
	return (cat_string);
}