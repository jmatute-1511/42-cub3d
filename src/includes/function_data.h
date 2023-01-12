/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:54:31 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/12 16:56:15 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_DATA_H
# define FUNCTION_DATA_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_data_tex
{
	double			step;		
	double			c_step;
	int				top_tex;
	int				pos_pixel;			
}				t_data_tex;
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


#endif