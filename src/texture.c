/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:08 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/20 17:01:34 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


double start_step(mlx_texture_t *texture, int height, double line_height)
{
	double start;

	start = 0;
	if (height > 1079)
		start = ((double)height - 1079) * line_height / 2;
	return(start);
}

mlx_texture_t* get_column(mlx_texture_t *texture, int column, int height)
{
	mlx_texture_t	*tex;
	double			step;		
	int				pos_pixel;		
	int				it;
	double			c_step;
	int				end;

	it = 0;
	c_step =  (double)texture->height / height;
	tex = malloc(sizeof(mlx_texture_t));
	tex->pixels = malloc(sizeof(uint8_t) * (height * 4));
	step = start_step(texture, height, c_step);
	if (height > 1079)
		height = 1079;
	tex->bytes_per_pixel = 4;
	tex->height = height;
	tex->width = 1;
	while(it < (height * 4))
	{
		tex->pixels[it] = texture->pixels[(int)(step) * (texture->width* 4) + (column * 4)];
		tex->pixels[it + 1] =texture->pixels[(int)(step) *(texture->width * 4) + 1 + (column * 4)];
		tex->pixels[it + 2] =texture->pixels[(int)(step) *(texture->width * 4) + 2 + (column * 4)];
		tex->pixels[it + 3] =texture->pixels[(int)(step) *(texture->width * 4) + 3 + (column * 4)];
		step += c_step;
		it += 4;
	}
	return (tex);
}


int get_number_column(int cord, mlx_texture_t *texture)
{
	int result;

	result = ((cord % 256) * texture->width) >> 7;
	return(result);
}
