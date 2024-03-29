/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:08 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/12 17:17:38 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	dda_line(t_dda *data, mlx_image_t *flor, uint32_t color)
{
	t_dcords	dcords;
	int			i;

	i = 0;
	dcords.dx = data->x_f - data->x_i;
	dcords.dy = data->y_f - data->y_i;
	if (fabs(dcords.dx) >= fabs(dcords.dy))
		dcords.p = fabs(dcords.dx);
	else
		dcords.p = fabs(dcords.dy);
	dcords.incx = dcords.dx / dcords.p;
	dcords.incy = dcords.dy / dcords.p;
	dcords.x = data->x_i;
	dcords.y = data->y_i;
	while (i < dcords.p)
	{
		mlx_put_pixel(flor, dcords.x, dcords.y, color);
		dcords.x += dcords.incx;
		dcords.y += dcords.incy;
		i++;
	}
}

double	start_step(int height, double line_height, t_env *env)
{
	double	start;

	start = 0;
	if (height > env->win_height)
		start = ((double)height - env->win_height - 1) * line_height / 2;
	return (start);
}

mlx_texture_t	*allocate_tex(int height)
{
	mlx_texture_t	*tex;

	tex = malloc(sizeof(mlx_texture_t));
	tex->pixels = malloc(sizeof(uint8_t) * (height << 2));
	tex->bytes_per_pixel = 4;
	tex->height = height;
	tex->width = 1;
	return (tex);
}

mlx_texture_t	*g_t_c(mlx_texture_t *texture, int column, int hgt, t_env *env)
{
	mlx_texture_t	*tex;
	int				it;
	t_data_tex		data;	

	it = 0;
	data.c_step = (double)texture->height / hgt;
	data.step = start_step(hgt, data.c_step, env);
	if (hgt >= env->win_height)
		hgt = env->win_height - 1;
	tex = allocate_tex(hgt);
	data.top_tex = (texture->width * 4) * texture->height;
	data.pos_pixel = data.step * (texture->width << 2) + (column << 2);
	while (it < (hgt << 2) && data.pos_pixel + 3 < data.top_tex)
	{
		tex->pixels[it] = texture->pixels[data.pos_pixel];
		tex->pixels[it + 1] = texture->pixels[data.pos_pixel + 1];
		tex->pixels[it + 2] = texture->pixels[data.pos_pixel + 2];
		tex->pixels[it + 3] = texture->pixels[data.pos_pixel + 3];
		data.step += data.c_step;
		it += 4;
		data.pos_pixel = (int)data.step * (texture->width << 2) + (column << 2);
	}
	return (tex);
}

int	get_number_column(int cord, mlx_texture_t *texture)
{
	int	result;

	result = (int)round(((cord % 256) * texture->width) / 256);
	return (result);
}
