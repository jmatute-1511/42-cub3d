/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/12/14 18:00:20 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define LENGHT_RAY 15

uint32_t rgb_to_int(int red, int green, int blue, int transparency)
{
	int color;

	color = 0;
	red <<= 24;
	green <<= 16;
	blue <<= 8;
	return (color | red | green | blue | transparency); 
}

mlx_texture_t* draw_column(mlx_image_t *image, mlx_texture_t * texture)
{
	double poss = 0;
	double step = texture->height / 500;
	for(int i = 0; i < texture->widht * 4; i+= texture->height)
	{
		for(int p = 0; p < texture->height; p+=4)
		{
			int color = rgb_to_int(texture->pixels[i+p+(int)poss],texture->pixels[i+p+(int)poss +1],texture->pixels[i+p+(int)poss +2],texture->pixels[i+p+(int)poss +3]);
			poss += step;
			mlx_put_pixel(image, i,)
		}
	}
	
}

int main(void){
	
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	uint32_t xy[2] = {0, 0};
	uint32_t wh[2] = {64, 64};

	mlx = mlx_init(1280, 1000, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	texture = mlx_load_png("./images/jmatute-.png");
	dprintf(2, "widht :%d,  height: %d\n", texture->width, texture->height);
	image = mlx_texture_area_to_image(mlx, texture, xy, wh);
	if (image)
		mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}