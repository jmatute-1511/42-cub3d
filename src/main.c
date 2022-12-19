/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/12/19 16:45:13 by jmatute-         ###   ########.fr       */
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

mlx_texture_t* ret_column(mlx_image_t *img, mlx_texture_t * texture,uint32_t fil)
{
	uint32_t *arr_image;
	mlx_texture_t *new_texture;
	
	// if(column * texture->height > texture->height * 4)
	// 	return NULL;
	new_texture = malloc(sizeof(mlx_texture_t));
	new_texture->pixels = malloc(sizeof(uint8_t) * (texture->width * 4));
	new_texture->bytes_per_pixel = 4;
	new_texture->height = 1;
	new_texture->width = texture->width;
	for(int p = 0; p < texture->width * 4; p++)
		new_texture->pixels[p] = texture->pixels[((fil * texture->width * 4)) + p];
	return(new_texture);
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
	image = mlx_new_image(mlx,1280,1000);//mlx_texture_area_to_image(mlx, texture, xy, wh);
	//mlx_draw_texture(image,texture, 100, 0);
	if (image)
	{
		for (size_t i = 0; i < texture->height; i++)
		{
			mlx_draw_texture(image,ret_column(image, texture,i), 0, i);
		}
		mlx_image_to_window(mlx, image, 0, 0);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}