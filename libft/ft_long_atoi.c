/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:34:02 by jmatute-          #+#    #+#             */
/*   Updated: 2021/12/11 14:14:53 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_long_atoi(const char *str)
{
	long	count;
	long	save;
	long	sign;
	int		neg;

	count = 0;
	save = 0;
	sign = 0;
	neg = 1;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	while ((str[count] == '-' || str[count] == '+'))
	{
		if (str[count] == '-')
			neg = -1;
		sign++;
		count++;
	}
	while (ft_isdigit(str[count]) && sign <= 1)
		save = save * 10 + (str[count++] - 48);
	save = save * neg;
	return (save);
}
