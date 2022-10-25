/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/10/25 20:05:58 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>
#define PI 3.14159265358979323846


float dx, dy, pa;
int x = 0;
int y = 0;

#define WIDTH (1200 * 2) 
#define HEIGHT (300 * 2)
#define X 600
#define Y 150

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
void plotLine(int x0, int y0, int x1, int y1, mlx_image_t *floor, uint32_t color)
{
   int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
   int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1; 
   int err = dx+dy, e2; /* error value e_xy */
	
   for(int i = 0; i < 500; i++ ){  /* loop */
      mlx_put_pixel(floor, x0, y0, color);
      if (x0==x1 && y0==y1) break;
      e2 = 2*err;
      if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
      if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
   }
}

int32_t	main(void)
{
	mlx_t	*mlx;
	mlx_texture_t *texture;
	mlx_image_t *yellow;
	mlx_image_t *floor;
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
	floor = mlx_new_image(mlx, 1220 * 2, 305 * 2);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	memset(floor->pixels, 200, floor->width * floor->height * sizeof(int));
	mlx_image_to_window(mlx, floor, 0, 0);
	texture = mlx_load_png("./images/yellow.png");
	yellow = mlx_texture_to_image(mlx, texture);
	while (y  < 5)
	{
		while (x < 20)
		{
			if (worldMap[y][x] == 1)
				mlx_image_to_window(mlx ,yellow, X + (x * 60) + x, Y + (y * 60 )+ y);
			x++;				
		}
		x = 0;
		y++;
		
	}
	mlx_image_to_window(mlx, g_img, 100, 100);
	int x = 500;
	for (int i = 250; i < 500; i++){
		plotLine(100, 100,i,  x--, floor, 14149279);
		
	}
	plotLine(100, 100,500, 500, floor, 16711680);
	plotLine(100, 100,250, 500, floor, 16711680);
	plotLine(100, 100,500, 250, floor, 16711680);
	plotLine(100, 100 ,500 ,250, floor, 16711680);
	// // for(int i = 100; i < 500; i++)
	// // 	mlx_put_pixel(floor, i, i, 14149279);
	// for(int i = 500; i < 600; i++)
	// 	mlx_put_pixel(floor, round(cos(i)), i, 14149279);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}