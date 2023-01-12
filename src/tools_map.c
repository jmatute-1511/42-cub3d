/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/12 17:17:42 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*save_trim(char *str, int num, t_env *env, char t)
{
	char	*aux;
	char	*temp;

	if (t == 's' && env->value_n != 1)
		exit_free(env, 2);
	else if (t == 'e' && env->value_n != 2)
		exit_free(env, 2);
	else if (t == 'w' && env->value_n != 3)
		exit_free(env, 2);
	else if (t == 'f' && env->value_n != 4)
		exit_free(env, 2);
	else if (t == 'c' && env->value_n != 5)
		exit_free(env, 2);
	env->value_n += 1;
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
	env->tex->no = NULL;
	env->tex->so = NULL;
	env->tex->ea = NULL;
	env->tex->we = NULL;
	env->tex->f = NULL;
	env->tex->c = NULL;
	env->play = 0;
	env->value_n = 0;
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
