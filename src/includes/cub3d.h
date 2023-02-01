/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2023/02/01 15:32:15 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define PI 3.1415926535
# define RADIAN 0.0174533
# define P2 1.5707963267
# define P3 4.7123889803

# include "function_data.h"
# include	<stdlib.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<memory.h>
# include	<math.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<float.h>

void			get_rgb(t_env *env);
int				is_fillspace(char *str);
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
char			*save_trim(char *str, int num);
void			init_env(char *path, t_env *env);
void			exit_free(t_env *env, int check);
void			load_texture(t_env *env);
void			close_cub(t_env *d_env);
void			draw_column(t_env **d_env, double abs, double cord, int x);
void			select_texture(double angle, char axis, t_env **d_env);
void			y_colision(t_clcord *cord, double angle, t_env *env);
void			x_colision(t_clcord *cord, double angle, t_env *env);
void			resized_map(t_env **d_env);
void			check_p_position(char **map, int y, int x, t_env *env);
void			format_check(t_env *env);
void			not_error(t_env *env, char f, char	*str);
#endif