/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bremesar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:42:15 by bremesar          #+#    #+#             */
/*   Updated: 2022/07/07 17:42:17 by bremesar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bolean_str(char c, char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == c)
			return (1);
		a++;
	}
	return (0);
}

int	len_word(const char *s, char c, char *ign)
{
	int	len;
	int	flag;

	flag = 0;
	len = 0;
	while (s[len])
	{
		if (flag == 0 && bolean_str(s[len], ign))
			flag += 1;
		else if (flag == 1 && bolean_str(s[len], ign))
			flag -= 1;
		if (s[len] == c && flag == 0)
			break ;
		len++;
	}
	return (len);
}
