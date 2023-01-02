/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ignore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:53:44 by jmatute-          #+#    #+#             */
/*   Updated: 2022/06/18 15:06:41 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c, char *ign)
{
	int	count;
	int	word;
	int	flag;

	count = 0;
	word = 0;
	flag = 0;
	if (s[0] != c)
		word++;
	if (!s[count])
		return (0);
	while (s[count])
	{
		if (flag == 0 && bolean_str(s[count], ign))
			flag += 1;
		else if (flag == 1 && bolean_str(s[count], ign))
			flag -= 1;
		if (s[count] == c && s[count + 1] != c && flag != 1)
			word++;
		count++;
	}
	return (word);
}

static char	*save_memory(char const *s, char c, char *ign)
{
	char	*save_memory;
	int		len;
	int		cpy;
	int		flag;

	cpy = 0;
	flag = 0;
	len = len_word(s, c, ign);
	save_memory = (char *)malloc(sizeof(char) * (len + 1));
	if (!save_memory)
		return (NULL);
	while (s[cpy])
	{
		if (flag == 0 && bolean_str(s[cpy], ign))
			flag += 1;
		else if (flag == 1 && bolean_str(s[cpy], ign))
			flag -= 1;
		if (s[cpy] == c && flag == 0)
			break ;
		save_memory[cpy] = s[cpy];
		cpy++;
	}
	save_memory[len] = '\0';
	return (save_memory);
}

int	return_pointer(const char *s, char c, char *ign, int count)
{
	int	flag;

	flag = 0;
	if (!s[count])
		return (count);
	while (s[count])
	{
		if (flag == 0 && bolean_str(s[count], ign))
			flag += 1;
		else if (flag == 1 && bolean_str(s[count], ign))
			flag -= 1;
		if (s[count] == c && flag == 0)
			break ;
		count++;
	}
	return (count);
}

char	**ft_split_ignore(char const *s, char c, char *ign)
{
	char	**matriz;
	int		count;
	int		count2;
	int		words;

	if (!s)
		return (NULL);
	count = 0;
	count2 = 0;
	words = ft_count_word(s, c, ign);
	matriz = (char **)malloc(sizeof(char *) * (words + 1));
	if (!matriz)
		return (NULL);
	while (count < words)
	{
		while (s[count2] == c && s[count2])
			count2++;
		matriz[count] = save_memory(&s[count2], c, ign);
		count2 = return_pointer(s, c, ign, count2);
		count++;
	}
	matriz[count] = NULL;
	return (matriz);
}
