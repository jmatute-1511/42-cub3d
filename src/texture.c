/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:08 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/18 11:09:42 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

mlx_texture_t	*get_column(mlx_texture_t *textur, int column, int height)
{
	mlx_texture_t	*tex;
	double			step;		
	int				pos_pixel;		
	int				it;
	double			c_step;

	it = 0;
	c_step = (double)textur->height / (double)height;
	step = 0;
	tex = malloc(sizeof(mlx_texture_t));
	tex->pixels = malloc(sizeof(uint8_t) * (height * 4));
	tex->bytes_per_pixel = 4;
	tex->height = height;
	tex->width = 1;
	while (it < (height * 4))
	{
		tex->pixels[it] = textur->pixels[column * (textur->width * 4)];
		tex->pixels[it + 1] = textur->pixels[column * (textur->width * 4) + 1];
		tex->pixels[it + 2] = textur->pixels[column * (textur->width * 4) + 2];
		tex->pixels[it + 3] = textur->pixels[column * (textur->width * 4) + 3];
		step += c_step;
		it += 4;
	}
	//dprintf(2,"%d \n", column);
	return (tex);
}

int	get_number_column(int cord, mlx_texture_t *texture)
{
	int	result;

	result = (cord % 256);
	return (result);
}
