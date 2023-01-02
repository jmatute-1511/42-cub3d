/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:50:21 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/02 16:31:27 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/cub3d.h"

void get_rgb(t_env *env)
{
	char **m_floor;
	char **m_roof;
	uint8_t floor[3];
	uint8_t roof[3];
	int it;

	it = 0;
	m_floor = ft_split(env->tex->f, ',');
	m_roof = ft_split(env->tex->c, ',');
	while (it < 3)
	{
		floor[it] = ft_atoi(m_floor[it]);
		roof[it] = ft_atoi(m_roof[it]);
		it++;
	}
	env->floor = rgb_to_int(floor[0], floor[1], floor[2], 255);
	env->roof = rgb_to_int(roof[0], roof[1], roof[2], 255);
	free(m_floor);
	free(m_roof);
}

uint32_t rgb_to_int(int red, int green, int blue, int transparency)
{
	int color;

	color = 0;
	red <<= 24;
	green <<= 16;
	blue <<= 8;
	return (color | red | green | blue | transparency); 
}

double fix_angle(double  angle)
{
	if ( angle > 2 *PI)
		 angle -= (2 * PI);
	if ( angle < 0)
		 angle += (2 * PI);
	return (angle);
}
