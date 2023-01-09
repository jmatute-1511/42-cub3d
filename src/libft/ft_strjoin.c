/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:56:30 by jmatute-          #+#    #+#             */
/*   Updated: 2021/06/04 19:10:54 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	if (!s2 || !s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s1[count])
	{
		p[count] = s1[count];
		count++;
	}
	while (s2[count2])
	{
		p[count2 + count] = s2[count2];
		count2 ++;
	}
	p[len] = '\0';
	return (p);
}
