/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/09 16:30:02 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# define PI 3.1415926535
# define RADIAN 0.0174533
# define P2 1.5707963267
# define P3 4.7123889803

# include	<stdlib.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<memory.h>
# include	<math.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<float.h>

typedef struct s_dcords
{
	double		dx;
	double		dy;
	double		incx;
	double		incy;
	double		x;
	double		y;
	double		p;
}			t_dcords;

typedef struct s_dda
{
	int		x_i;
	int		y_i;
	int		x_f;
	int		y_f;
	int		y;
}			t_dda;

typedef struct s_clcord
{
	double		xf;
	double		yf;
	double		sub_x;
	double		sub_y;
	double		abs;
}				t_clcord;

typedef struct s_textures
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*f;
	char			*c;
	mlx_texture_t	*t_no;
	mlx_texture_t	*t_so;
	mlx_texture_t	*t_ea;
	mlx_texture_t	*t_we;
}	t_textures;

typedef struct s_read_map
{
	int		frist_wall;
	int		last_wall;
	int		check_f;
	int		check_l;
	int		i;
}	t_read_map;

typedef struct s_env
{
	mlx_t			*mlx;
	t_textures		*tex;
	mlx_image_t		*found;
	mlx_texture_t	*texture;
	double			text_height;
	unsigned int	height;
	unsigned int	width;
	double			win_height;
	double			win_width;
	unsigned int	top_x;
	unsigned int	top_y;
	int				floor;
	int				roof;
	int				hpb;
	int				value_n;
	double			inc;
	char			view;				
	int				*play;
	char			**map;
	double			dplane;
	double			plane_x;
	double			plane_y;
	double			dx;
	double			dy;
	double			pa;
	double			x;
	double			y;
}				t_env;

void			get_rgb(t_env *env);
void			change_angles(t_env **d_env);
void			dda_line(t_dda *data, mlx_image_t *flor, uint32_t color);
int				draw_colision(t_env **d_env, double angle, int x);
void			draw_separator(t_env **d_env);
void			draw_fov(t_env **d_env);
int				angle_colision(t_env *env, double angle, char type);
double			fix_angle(double angle);
void			read_map(char *path, t_env *env);
int				colision_is_close(t_env *env, double dir, char type);
uint32_t		rgb_to_int(int red, int green, int blue, int transparency);
mlx_texture_t	*g_t_c(mlx_texture_t *texture, int column, int hgt, t_env *env);
int				get_number_column(int cord, mlx_texture_t *texture);
void			print_error_map(int line, int i, int check, t_env *env);
void			midle_line(char *str, int check, t_env *env);
int				check_name(char *path);
void			check_map(char **map, t_env *env);
void			take_h_w(char *name, t_env *env);
int				check_one(char **map, int y, int x);
int				check_cero(char **map, int y, int x);
int				check_space(char **map, int y, int x);
int				corner_checker(char **map, int y, int x);
int				is_valid(char c);
char			*save_trim(char *str, int num, t_env *env, char t);
void			init_env(char *path, t_env *env);
void			exit_free(t_env *env, int check);
void			load_texture(t_env *env);
void			close_cub(t_env *d_env);
#endif