/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/10/26 16:59:49 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../MLX42/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

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

typedef struct	s_player
{
	mlx_image_t	*img_p;
	
}				t_player;

typedef struct	s_env
{
	mlx_t		*mlx;
	mlx_image_t	*found;
	t_player	*player;

}				t_env;


#endif