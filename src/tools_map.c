/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by jmatute-          #+#    #+#             */
/*   Updated: 2023/02/01 15:30:32 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*save_trim(char *str, int num)
{
	char	*aux;
	char	*temp;

	temp = ft_substr(str, num, ft_strlen(str));
	aux = ft_strtrim(temp, " ");
	free(temp);
	return (aux);
}

void	init_env(char *path, t_env *env)
{
	env->height = 0;
	env->width = 0;
	take_h_w(path, env);
	if (env->height < 3 || env->width == 0)
	{
		printf("Error\nNot Map in the file\n");
		exit (1);
	}
	env->tex->no = NULL;
	env->tex->so = NULL;
	env->tex->ea = NULL;
	env->tex->we = NULL;
	env->tex->f = NULL;
	env->tex->c = NULL;
	env->play = 0;
}

void	set_view(char dir, t_env *env)
{
	if (dir == 'N')
		env->pa = P2;
	else if (dir == 'S')
		env->pa = P3;
	else if (dir == 'W')
		env->pa = PI;
	else if (dir == 'E')
		env->pa = 0;
}

void	sub_while(char **map, t_env *env, int y)
{
	int	x;

	x = -1;
	while (map[y][++x])
	{
		if (map[y][x] == ' ' && check_space(map, y, x) == -1)
			print_error_map(y, x, 2, env);
		else if (map[y][x] == '0' && check_cero(map, y, x) == -1)
			print_error_map(y, x, 2, env);
		else if (map[y][x] == '1' && check_one(map, y, x) == -1)
			print_error_map(y, x, 2, env);
		else if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'W')
		{
			check_p_position(map, y, x, env);
			env->x = x * env->hpb + 5;
			env->y = y * env->hpb + 5;
			set_view(map[y][x], env);
		}
	}
}

void	check_map(char **map, t_env *env)
{
	int	y;

	y = 0;
	if (env->play == 0)
		print_error_map(y, 0, 5, env);
	y = -1;
	while (map[++y])
	{
		sub_while(map, env, y);
	}
}
