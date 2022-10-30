/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/10/28 12:19:22 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../MLX42/include/MLX42/MLX42.h"

#define PI 3.1415926535

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>

typedef struct s_dcords
{
	double	dx;
	double	dy;
	double	incx;
	double	incy;
	double	x;
	double	y;
	double	p;
}			t_dcords;

typedef struct	s_env
{
	mlx_t		*mlx;
	mlx_image_t	*found;
	mlx_image_t	*player;
	float dx;
	float dy;
	float pa;
	int x;
	int y;

}				t_env;


#endif