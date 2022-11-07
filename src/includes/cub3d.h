/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/11/06 22:11:05 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../get_next_line/get_next_line.h"
#include "../../libft/libft.h"
#define PI 3.1415926535
#define P2 PI/2
#define P3 3*PI/2 
#define HEIGHT 64
#define WIDTH 64

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>


typedef struct s_dcords
{
	double			dx;
	double		dy;
	double		incx;
	double		incy;
	double		x;
	double		y;
	double		p;
}			t_dcords;

typedef struct	s_env
{
	unsigned int	height;
	unsigned int	width;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*found;
	mlx_image_t		*floor;
	mlx_image_t		*walls;
	mlx_image_t		*player;
	char			**map;
	float 			dx;
	float 			dy;
	float 			pa;
	int 			x;
	int 			y;
	int 			z;

}				t_env;
void dda_line(int xi, int yi, int xf, int yf, mlx_image_t *flor, uint32_t color);
char **read_map(char *path, unsigned int *widht, unsigned int *height);
#endif