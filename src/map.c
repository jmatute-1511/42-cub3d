/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by jmatute-          #+#    #+#             */
/*   Updated: 2022/10/30 19:48:40 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		free(line);
		if (ft_strlen(line) > *widht)
			*widht = ft_strlen(line);
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

char *read_map(char *path, unsigned int *widht, unsigned int *height)
{
	int fd;
	char *map;
	
	map = NULL;
	fd = open(ft_strjoin("./", path), O_RDONLY);
	if (fd == -1)
		return (NULL);
	fill_map(&map, fd, widht, height);
	return (map);
}