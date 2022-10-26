/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/10/26 17:00:34 by jmatute-         ###   ########.fr       */
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
void dda_line(int xi, int yi, int xf, int yf, mlx_image_t *floor, uint32_t color)
{
	
	t_dcords	dcords;
	int			i;
	
	i = 0;
	dcords.dx = xf - xi;
	dcords.dy = yf - yi;
	if (fabs(dcords.dx) >= fabs(dcords.dy))
		dcords.p = fabs(dcords.dx);
	else
		dcords.p = fabs(dcords.dy);
	dcords.incx = dcords.dx / dcords.p;
	dcords.incy = dcords.dy / dcords.p;
	dcords.x = xi;
	dcords.y = yi;
	while(i <= dcords.p){
		 mlx_put_pixel(floor, dcords.x, dcords.y, color);
		 dcords.x += dcords.incx;
		 dcords.y += dcords.incy;
		 i++;
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
		dda_line(100, 100,i,  x--, floor, 14149279);
		
	}
	dda_line(100, 100,500, 500, floor, 16711680);
	dda_line(100, 100,250, 500, floor, 16711680);
	dda_line(100, 100,500, 250, floor, 16711680);
	dda_line(100, 100 ,500 ,250, floor, 16711680);
	// // for(int i = 100; i < 500; i++)
	// // 	mlx_put_pixel(floor, i, i, 14149279);
	// for(int i = 500; i < 600; i++)
	// 	mlx_put_pixel(floor, round(cos(i)), i, 14149279);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}