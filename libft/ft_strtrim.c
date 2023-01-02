/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:37:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/07/16 13:49:52 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_set_i(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (set[a] && s1[b])
	{
		if (set[a] == s1[b])
		{
			b++;
			a = 0;
		}
		if (set[a] != s1[b])
			a++;
	}
	return (b);
}

static size_t	ft_set_f(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(s1) - 1;
	if (ft_set_i(s1, set) == ft_strlen(s1))
		return (a);
	while (set[a] && s1[b])
	{
		if (set[a] == s1[b])
		{
			b--;
			a = 0;
		}
		if (set[a] != s1[b])
			a++;
	}
	return (b);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	c;
	size_t	len;
	char	*cpy;

	if (!s1 || !set)
		return (NULL);
	c = ft_set_f(s1, set);
	a = ft_set_i(s1, set);
	if (c == 0)
		return (NULL);
	len = (c - a) + 1;
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1 + a, len);
	cpy[len] = '\0';
	return (cpy);
}
