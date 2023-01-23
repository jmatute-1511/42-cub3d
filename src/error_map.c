/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:59:28 by alsanche          #+#    #+#             */
/*   Updated: 2023/01/23 17:17:49 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	print_error_map(int line, int i, int check, t_env *env)
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
	else if (check == 7)
		dprintf(2, "Error\nBad value\n");
	exit_free(env, 1);
}

int	check_name(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 4] == '.' && path[i - 3] == 'c'
		&& path[i - 2] == 'u' && path[i - 1] == 'b')
		return (0);
	ft_putstr_fd("Bad type of map\n", 2);
	return (1);
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

void	add_player(char c, t_env *env)
{
	if (env->play == 0)
	{
		env->play++;
		env->view = c;
	}
	else
		print_error_map(0, 0, 4, env);
}

void	midle_line(char *str, int check, t_env *env)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			add_player(str[i], env);
		else if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			print_error_map(check, i, 3, env);
	}
}
