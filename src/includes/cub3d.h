/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/20 15:08:36 by alsanche         ###   ########lyon.fr   */
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
	int				hpb;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*found;
	mlx_image_t		*floor;
	mlx_image_t		*walls;
	mlx_image_t		*player;
	char			**map;
	double			dplane;
	double			plane_x;
	double			plane_y;
	double			dx;
	double 			dy;
	double 			pa;
	double 			x;
	double 			y;
	int 			z;

}				t_env;
void dda_line(int xi, int yi, int xf, int yf, mlx_image_t *flor, uint32_t color);
int draw_colision(t_env **d_env, float angle, int x);
void draw_separator(t_env **d_env);
void draw_fov(t_env **d_env);
int angle_colision(t_env * env, float angle, char type);
double fix_angle(double angle);
char **read_map(char *path, unsigned int *widht, unsigned int *height);
int colision_is_close(t_env *env, double dir, char type);
uint32_t rgb_to_int(int red, int green, int blue, int transparency);
mlx_texture_t* get_column(mlx_texture_t *texture, int column, int height, double dis);
int get_number_column(int cord, mlx_texture_t *texture);

#endif