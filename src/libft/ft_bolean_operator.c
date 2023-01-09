/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bolean_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:54:16 by jmatute-          #+#    #+#             */
/*   Updated: 2022/05/11 15:37:24 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bolean_operator( char diff, char *str)
{
	int	count;

	while (str[count])
	{
		if (str[count] == diff)
			return (1);
	}
	return (0);
}
