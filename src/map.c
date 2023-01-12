/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/12 17:17:32 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	save_texture(char *str, t_env *env, int line)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		env->tex->no = save_trim(str, 2, env, 'n');
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		env->tex->so = save_trim(str, 2, env, 's');
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		env->tex->ea = save_trim(str, 2, env, 'e');
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		env->tex->we = save_trim(str, 2, env, 'w');
	else if (str[0] == 'F' && str[1] == ' ')
		env->tex->f = save_trim(str, 1, env, 'f');
	else if (str[0] == 'C' && str[1] == ' ')
		env->tex->c = save_trim(str, 1, env, 'c');
	if (str[0] == '\0' && line >= 0)
		print_error_map(line + 1, 0, 6, env);
}

static void	check_walls(char *str, int check, t_env *env)
{
	t_read_map	read;

	read.i = 0;
	if (check == 0)
	{
		while (str[read.i])
		{
			if (str[read.i] != '1' && str[read.i] != ' ')
				print_error_map(check, read.i, 0, env);
			read.i++;
		}
	}
	else
	{
		midle_line(str, check, env);
	}
}

static void	last_line(char *line, char **map, int height, t_env *env)
{
	char	*aux_map;

	check_walls(line, ++height, env);
	aux_map = (*map);
	(*map) = ft_strnjoin(3, aux_map, "\n", line);
	free(aux_map);
}

void	fill_map(char **map, int fd, t_env *env)
{
	char		*aux_map;
	char		*line;
	int			height;

	height = -1;
	while (get_next_line(fd, &line) != 0)
	{
		if (line[0] != '1' && line[0] != ' ' && line[0] != '0')
			save_texture(line, env, height);
		else if (line[0] != '\n' && (*map))
		{
			check_walls(line, ++height, env);
			aux_map = (*map);
			(*map) = ft_strnjoin(3, aux_map, "\n", line);
			free(aux_map);
		}
		if ((*map) == NULL)
			(*map) = ft_strdup(line);
		free(line);
	}
	if (line)
	{
		last_line(line, map, height, env);
		free(line);
	}
}

void	read_map(char *path, t_env *env)
{
	int		fd;
	char	*aux_map;

	if (check_name(path) == 1)
		exit (127);
	aux_map = NULL;
	env->tex = malloc(sizeof(t_textures));
	init_env(path, env);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit (1);
	fill_map(&aux_map, fd, env);
	env->map = ft_split(aux_map, '\n');
	free(aux_map);
	close(fd);
	check_map(env->map, env);
	load_texture(env);
	resized_map(&env);
}
