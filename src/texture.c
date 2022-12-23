/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:08 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/23 11:42:14 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


double start_step(mlx_texture_t *texture, int height, double line_height, t_env * env)
{
	double start;

	start = 0;
	if (height >= env->win_height)
		start = ((double)height - env->win_height - 1) * line_height / 2;
	return(start);
}

mlx_texture_t* get_text_column(mlx_texture_t *texture, int column, int height, t_env *env)
{
	mlx_texture_t	*tex;
	double			step;		
	int				pos_pixel;		
	int				it;
	double			c_step;
	int				width;

	it = 0;
	c_step =  (double)texture->height / height;
	tex = malloc(sizeof(mlx_texture_t));
	tex->pixels = malloc(sizeof(uint8_t) * (height << 2));
	step = start_step(texture, height, c_step, env);
	if (height >= env->win_height)
		height = env->win_height - 1;
	tex->bytes_per_pixel = 4;
	tex->height = height;
	tex->width = 1;
	column <<= 2;
	height <<= 2;
	width = (texture->width << 2);
	while(it < height)
	{
		pos_pixel = (int)(step) * width + column;
		tex->pixels[it] = texture->pixels[pos_pixel];
		tex->pixels[it + 1] = texture->pixels[pos_pixel + 1];
		tex->pixels[it + 2] =texture->pixels[pos_pixel + 2];
		tex->pixels[it + 3] =texture->pixels[pos_pixel + 3];
		step += c_step;
		it += 4;
	}
	return (tex);
}


int get_number_column(int cord, mlx_texture_t *texture)
{
	int result;

	result = ((cord % 256) * texture->width) >> 8;
	return(result);
}
