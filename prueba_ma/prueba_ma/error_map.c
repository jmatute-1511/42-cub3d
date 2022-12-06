/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:59:28 by alsanche          #+#    #+#             */
/*   Updated: 2022/12/03 19:15:15 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_map(int line, int i, int check)
{
	{
		if (check == 0 && line == 0)
			ft_putstr_fd("Error\nUnclosed Top Wall\n", 2);
		else if (check == 0)
			ft_putstr_fd("Error\nUnclosed Bot Wall\n", 2);
		else if (check == 2)
			dprintf(2, "Error\nline: %d, char: %d, Unclosed Wall\n", line + 1, i);
		else if (check == 3)
			dprintf(2, "Error\nline: %d, char: %d, Not allowed\n", line + 1, i);
		else if (check == 4)
			ft_putstr_fd("Error\ntwo or more Players on the map\n", 2);
		else if (check == 5)
			ft_putstr_fd("Error\nNot Player on the map\n", 2);
		else if (check == 6)
			dprintf(2, "Error\nline: %d, It's empty\n", line);
		exit (1);
	}
}

int	check_name(char *path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		if (!ft_strncmp(&path[i], ".cub\n", 5))
			return (1);
	}
	return (0);
}

void	take_h_w(char *name, t_env *env)
{
	int			fd;
	char		*line;

	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		if (line[0] != '\n' && line[0] != '1' && line[0] != ' ')
			free(line);
		else if (line[0] != '\n')
		{
			if (ft_strlen(line) > env->width)
				env->width = ft_strlen(line);
			env->height += 1;
			free(line);
		}
	}
	if (line)
	{
		if (ft_strlen(line) > env->width)
			env->width = ft_strlen(line);
		env->height += 1;
		free(line);
	}
	close(fd);
}

void	midel_line(char *str, int check, t_env *env)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			add_player(str[i], env);
		else if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			print_error_map(check, i, 3);
	}
}

void	add_player(char c, t_env *env)
{
	if (env->player == 0)
	{
		env->player = 1;
		env->view = c;
	}
	else
		print_error_map(0, 0, 4);
}
