/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:11:26 by jmatute-          #+#    #+#             */
/*   Updated: 2021/05/28 18:35:48 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(int nb, int fd)
{
	if (nb == -2147483648)
	{
		nb = nb * (-1) - 1;
		ft_putchar_fd('-', fd);
		ft_recursive(nb / 10, fd);
		ft_putchar_fd((nb % 10 + 1) + 48, fd);
	}
	else if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar_fd('-', fd);
		ft_recursive(nb / 10, fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
	else if (nb > 0)
	{
		ft_recursive(nb / 10, fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n != 0)
	{
		ft_recursive(n, fd);
	}
	else
	{
		ft_putchar_fd('0', fd);
	}
}
