/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bolean_strstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:48:17 by jmatute-          #+#    #+#             */
/*   Updated: 2022/05/04 18:02:05 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bolean_strstr(char *str, char *find)
{
	int	after;
	int	begin;

	after = 0;
	begin = 0;
	while (str[after])
	{
		while (str[after] == find[begin])
		{
			after++;
			begin++;
			if (begin == ft_strlen(find))
				return (after);
		}
		begin = 0;
		after++;
	}
	return (0);
}
