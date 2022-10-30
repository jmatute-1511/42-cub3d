/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2022/10/30 19:30:19 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_env env;
	
	if (argc == 1)
		return (0);
	env.width = 0;
	env.height = 0;
	env.map = read_map(argv[1], &env.width, &env.height);
	printf("%s\n",env.map);
	printf("%d\n",env.width);
	printf("%d\n",env.height);
	return 0;
}	