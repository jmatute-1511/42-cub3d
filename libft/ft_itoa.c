/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bremesar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:46:22 by bremesar          #+#    #+#             */
/*   Updated: 2019/11/20 12:46:24 by bremesar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static int	numl(long int n)
{
	int	leng;

	leng = 0;
	if (n < 0)
	{
		leng++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		leng++;
	}
	return (leng);
}

static char	*int_char(long int n, char *num, int leng)
{
	num[leng--] = '\0';
	if (n == 0)
		num[0] = 48;
	if (n < 0)
	{
		num[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		num[leng--] = 48 + (n % 10);
		n = n / 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		leng;

	leng = numl((long int)n);
	if (!n)
		leng = 1;
	num = (char *)malloc(sizeof(char) * (leng + 1));
	if (!num)
		return (0);
	return (num = int_char((long int)n, num, leng));
}
