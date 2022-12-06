/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/03 19:20:35 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	save_texture(char *str, t_env *env, int line)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		env->tex->no = ft_substr(str, 3, ft_strlen(str));
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		env->tex->so = ft_substr(str, 3, ft_strlen(str));
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		env->tex->ea = ft_substr(str, 3, ft_strlen(str));
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		env->tex->we = ft_substr(str, 3, ft_strlen(str));
	else if (str[0] == 'F' && str[1] == ' ')
		env->tex->f = ft_substr(str, 2, ft_strlen(str));
	else if (str[0] == 'C' && str[1] == ' ')
		env->tex->c = ft_substr(str, 2, ft_strlen(str));
	if (str[0] == '\0' && line >= 0)
		print_error_map(line + 1, 0, 6);
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
				print_error_map(check, read.i, 0);
			read.i++;
		}
	}
	else
	{
		midel_line(str, check, env);
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
	char	*name;
	char	*aux_map;

	if (check_name(path) == 1)
	{	
		aux_map = ft_calloc(1, sizeof(char *));
		env->tex = ft_calloc(1, sizeof(t_textures));
		name = ft_strjoin("./", path);
		take_h_w(name, env);
		fd = open(name, O_RDONLY);
		if (fd == -1)
			exit (1);
		fill_map(&aux_map, fd, env);
		env->map = ft_split(aux_map, '\n');
		free(aux_map);
		close(fd);
		check_map(env->map, env);
	}
	else
	{
		ft_putstr_fd("Bad type of map\n", 2);
		exit (127);
	}
}
