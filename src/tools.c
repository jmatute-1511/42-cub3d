/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:50:21 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/18 11:44:22 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

uint32_t	rgb_to_int(int red, int green, int blue, int transparency)
{
	int	color;

	color = 0;
	red <<= 24;
	green <<= 16;
	blue <<= 8;
	return (color | red | green | blue | transparency);
}

double	fix_angle(double angle)
{
	if (angle > 2 * PI)
		angle -= (2 * PI);
	if (angle < 0)
		angle += (2 * PI);
	return (angle);
}
