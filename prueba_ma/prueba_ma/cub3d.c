/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/03 19:12:46 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info(t_env *env)
{
	int	i;

	printf("medidas----%d %d\n", env->width, env->height);
	printf("Player ===== %d \n", env->player);
	printf("Player view ===== %c \n", env->view);
	printf("NO------ %s \n", env->tex->no);
	printf("SO------ %s \n", env->tex->so);
	printf("WE------ %s \n", env->tex->we);
	printf("EA------ %s \n", env->tex->ea);
	printf("F------ %s \n", env->tex->f);
	printf("C------ %s \n", env->tex->c);
	i = -1;
	printf("\n-----------    MAP   ------------\n");
	while (env->map[++i])
	{
		printf("%s\n", env->map[i]);
	}
}

int	main(int argc, char **argv)
{
	t_env			env;

	if (argc == 1)
		return (0);
	else
	{
		env.player = 0;
		env.width = 0;
		env.height = 0;
		env.pa = PI;
		env.dx = 5;
		env.dy = 5;
		read_map(argv[1], &env);
		print_info(&env);
	}
	return (0);
}
