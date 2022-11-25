/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/11/25 11:19:43 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../get_next_line/get_next_line.h"
#include "../../libft/libft.h"
#define PI 3.1415926535
#define P2 PI/2
#define P3 3 * (PI/2) 
#define HEIGHT 64
#define WIDTH 64

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <float.h>


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

typedef struct	s_clcord
{
	double		xf;
	double 		yf;
	double		sub_x;
	double		sub_y;
	double		abs;
}				t_clcord;

typedef struct	s_env
{
	unsigned int	height;
	unsigned int	width;
	unsigned int	top_x;
	unsigned int	top_y;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*found;
	mlx_image_t		*floor;
	mlx_image_t		*walls;
	mlx_image_t		*player;
	char			**map;
	float 			dx;
	float 			dy;
	double 			pa;
	double 			x;
	double 			y;
	int 			z;

}				t_env;
void dda_line(int xi, int yi, int xf, int yf, mlx_image_t *flor, uint32_t color);
int draw_colision(t_env **d_env, float angle);
void draw_separator(t_env **d_env);
void draw_fov(t_env **d_env);
char **read_map(char *path, unsigned int *widht, unsigned int *height);
#endif