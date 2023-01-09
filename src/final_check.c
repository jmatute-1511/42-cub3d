/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:27:34 by alsanche          #+#    #+#             */
/*   Updated: 2023/01/07 20:02:21 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	exit_free(t_env *env, int check)
{
	if (env->tex->no)
		free(env->tex->no);
	if (env->value_n >= 1)
		free(env->tex->so);
	if (env->value_n >= 2)
		free(env->tex->ea);
	if (env->value_n >= 3)
		free(env->tex->we);
	if (env->value_n >= 4)
		free(env->tex->f);
	if (env->value_n >= 5)
		free(env->tex->c);
	free(env->tex);
	if (check == 1)
		free_matrix(env->map);
	exit (1);
}
