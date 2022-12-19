/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:46:20 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/17 15:46:45 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void draw_separator(t_env **d_env)
{
	t_env *env;
	int x;
	int y;
	
	env = *d_env;
	x = 0;
	y = 0;
	while ( x < env->width)
	{
		dda_line(x * WIDTH, 0 , x * WIDTH - 1, env->height * HEIGHT, env->found,16711680);	
		x++;
	}
	while (y < env->height)
	{
		dda_line(0 , y * HEIGHT, env->width * WIDTH , y * HEIGHT - 1, env->found,16711680);
		y++;
	}
}
void print_state(char *str, t_clcord *cord)
{
	dprintf(2,"%s---> abs: %f,sub_x: %f, sub_y %f, xf: %f, yf: %f\n",str,cord->abs, cord->sub_x, cord->sub_y, cord->xf, cord->yf);
}

