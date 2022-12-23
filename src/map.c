/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by jmatute-          #+#    #+#             */
/*   Updated: 2022/11/06 19:39:30 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void fill_map(char **map, int fd, unsigned int *widht, unsigned int *height)
{
	char *aux_map;
	char *line;

	while(get_next_line(fd, &line) != 0)
	{
		if (line[0] != '\n' && (*map))
		{
			aux_map = (*map);
			(*map) =  ft_strnjoin(3, aux_map, "\n", line);
			free(aux_map);
		}
		if ((*map) == NULL)
			(*map) = ft_strdup(line);
		if (ft_strlen(line) > *widht)
			*widht = ft_strlen(line);
		free(line);
		*height += 1;
	}
	if (line){
		aux_map = (*map);
		(*map) =  ft_strnjoin(3, aux_map, "\n", line);
		*height += 1;
		free(aux_map);
		free(line);
	}	
}

char **read_map(char *path, unsigned int *widht, unsigned int *height)
{
	int fd;
	char *aux_map;
	char **map;
	map = NULL;
	aux_map = NULL;
	fd = open(ft_strjoin("./", path), O_RDONLY);
	if (fd == -1)
		return (NULL);
	fill_map(&aux_map, fd, widht, height);
	map = ft_split(aux_map, '\n');
	free(aux_map);
	return (map);
}