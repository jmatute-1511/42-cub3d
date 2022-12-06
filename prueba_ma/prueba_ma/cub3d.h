/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:59:36 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/03 19:15:32 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//#include "../../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# define PI 3.1415926535
# define P2 PI/2
# define P3 3 * PI /2
# define HEIGHT 64
# define WIDTH 64

typedef struct s_dcords
{
	double			dx;
	double			dy;
	double			incx;
	double			incy;
	double			x;
	double			y;
	double			p;
}			t_dcords;

typedef struct s_read_map
{
	int		frist_wall;
	int		last_wall;
	int		check_f;
	int		check_l;
	int		i;
}	t_read_map;

typedef struct s_textures
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*f;
	char			*c;
	//mlx_texture_t	*texture;
	//mlx_image_t		*found;
	//mlx_image_t		*floor;
	//mlx_image_t		*walls;
	//mlx_image_t		*player;
}	t_textures;

typedef struct s_env
{
	unsigned int	height;
	unsigned int	width;
	//mlx_t			*mlx;
	t_textures		*tex;
	char			**map;
	int				player;
	char			view;
	float			dx;
	float			dy;
	float			pa;
	int				x;
	int				y;
	int				z;

}				t_env;

void	read_map(char *path, t_env *env);

//		Error.c		//

void	print_error_map(int line, int i, int check);
int		check_name(char *path);
void	take_h_w(char *name, t_env *env);
void	midel_line(char *str, int check, t_env *env);
void	add_player(char c, t_env *env);

//		Map.c		//

//		check_map.c		//

void	check_map(char **map, t_env *env);

#endif