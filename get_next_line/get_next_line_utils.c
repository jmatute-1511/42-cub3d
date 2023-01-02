/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:01:53 by jmatute-          #+#    #+#             */
/*   Updated: 2021/06/16 12:27:32 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int long	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*str;
	char	*str_src;

	str = dst;
	str_src = (char *)src;
	count = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (count < n)
	{
		str[count] = str_src[count];
		count++;
	}
	return (dst);
}

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
		(p[count] = s1[count]) && (count++);
	while (s2[count2])
		(p[count] = s2[count2]) && (count += 1) && (count2 += 1);
	p[len] = '\0';
	return (p);
}

char 	*ft_strdup(const char *s)
{
	unsigned long int	len;
	char				*cpy;

	len = ft_strlen(s);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s, len + 1);
	return (cpy);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		count;
	char		*cpy_s;
	size_t		len;

	cpy_s = (char *)s;
	count = 0;
	len = ft_strlen(s);
	while (count <= len)
	{
		if (cpy_s[count] == (char)c)
			return ((char *)s + (count));
		count++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
