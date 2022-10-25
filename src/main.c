/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/10/24 22:40:09 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>
#define PI 3.14159265358979323846


float dx, dy, pa;
int x = 0;
int y = 0;

#define WIDTH 1220
#define HEIGHT 305

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)){
		pa+= 0.1;
		if (pa > 2 *PI){
			pa-=2 *PI;
		}
		dx = cos(pa) *5;
		dy = sin(pa) *5;
		g_img->instances[0].x += 5;
		
	}
}

int32_t	main(void)
{
	mlx_t	*mlx;
	mlx_texture_t *texture;
	mlx_image_t *yellow;
	int worldMap [5][20]=
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 10, 10);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	texture = mlx_load_png("./images/yellow.png");
	yellow = mlx_texture_to_image(mlx, texture);
	while (y  * 60 < HEIGHT)
	{
		while (x  * 60 < WIDTH)
		{
			if (worldMap[y][x] == 1)
				mlx_image_to_window(mlx ,yellow, x * 60 + x, y *60 + y);
			x++;				
		}
		x = 0;
		y++;
		
	}
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}