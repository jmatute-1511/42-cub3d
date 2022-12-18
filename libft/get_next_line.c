/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:35:50 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/18 11:47:21 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*save_text(char *cpy, char c)
{
	char	*text;
	int		len;

	len = 0;
	while (cpy[len] && cpy[len] != c)
		len++;
	text = malloc(len + 1);
	if (!text)
		return (NULL);
	ft_memcpy(text, cpy, len);
	text[len] = '\0';
	return (text);
}

static void	cat_static(char **save, char **line, char *cpy)
{
	if (!*save)
		*save = ft_strdup(cpy);
	else
	{
		*line = ft_strjoin (*save, cpy);
		free (*save);
		*save = *line;
	}
}

static int	save_line(char **save, char **line)
{
	char	*eol;

	if (ft_strchr(*save, '\n'))
	{
		eol = ft_strdup(ft_strchr(*save, '\n') + 1);
		*line = save_text (*save, '\n');
		free(*save);
		*save = ft_strdup(eol);
		free(eol);
		return (1);
	}
	*line = save_text (*save, '\0');
	free(*save);
	*save = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[FD_SETSIZE];
	char		cpy[BUFFER_SIZE + 1];
	ssize_t		n_bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	n_bytes = read(fd, cpy, BUFFER_SIZE);
	if (n_bytes < 0)
		return (-1);
	if (!save[fd] && !n_bytes)
	{
		*line = ft_strdup("");
		return (0);
	}
	while (n_bytes > 0)
	{
		cpy[n_bytes] = '\0';
		cat_static(&save[fd], &*line, cpy);
		if (ft_strchr(save[fd], '\n'))
			break ;
		n_bytes = read(fd, cpy, BUFFER_SIZE);
	}
	return (save_line(&save[fd], &*line));
}
