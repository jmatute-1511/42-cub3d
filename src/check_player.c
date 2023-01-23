/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:27:34 by alsanche          #+#    #+#             */
/*   Updated: 2023/01/23 18:27:01 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	check_p_position(char **map, int y, int x, t_env *env)
{
	if (map[y][x + 1] != '0' && map[y][x + 1] != '1')
		print_error_map(y, x, 5, env);
	if (map[y][x - 1] && map[y][x - 1] != '0' && map[y][x - 1] != '1')
		print_error_map(y, x, 5, env);
	else if ((map[y + 1] && map[y + 1][x] != '0' && map[y + 1][x] != '1'))
		print_error_map(y, x, 5, env);
	else if ((map[y - 1] && map[y - 1][x] != '0' && map[y - 1][x] != '1'))
		print_error_map(y, x, 5, env);
}

void	format_check(t_env *env)
{
	if ((env->tex->f && env->tex->f[0] == '\0') || env->tex->f == NULL)
	{
		printf("Error\nF not found\n");
		exit_free(env, 1);
	}
	if ((env->tex->c && env->tex->c[0] == '\0') || env->tex->c == NULL)
	{
		printf("Error\nC not found\n");
		exit_free(env, 1);
	}
	not_error(env, 'F', env->tex->f);
	not_error(env, 'C', env->tex->c);
}
