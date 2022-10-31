/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/10/31 15:36:51 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

#define WIDTH (1200 * 2) 
#define HEIGHT (300 * 2)
#define LENGHT_RAY 15


void dda_line(int xi, int yi, int xf, int yf, mlx_image_t *flor, uint32_t color)
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
		 mlx_put_pixel(flor, dcords.x, dcords.y, color);
		 dcords.x += dcords.incx;
		 dcords.y += dcords.incy;
		 i++;
	}
}

void vortice_hook(void *param){
	t_env *env;
	env = param;
	
	if (mlx_is_key_down(env->mlx, MLX_KEY_A)){
		env->pa -= 0.1;
		if (env->pa < 0)
			env->pa += 2 *PI;
		env->dx = cos(env->pa) * 5;
		env->dy = sin(env->pa) * 5;
		mlx_delete_image(env->mlx, env->found);
		env->found = mlx_new_image(env->mlx, 1220 * 2, 305 * 2);
		memset(env->found->pixels, 200, env->found->width * env->found->height * sizeof(int));
		mlx_image_to_window(env->mlx, env->found, 0, 0);
		env->found->instances->z = env->player->instances[0].z -1;
		dda_line(env->x + 5, env->y + 5,((env->x + 5) + (env->dx * LENGHT_RAY)) , (env->y +5 + (env->dy * LENGHT_RAY)), env->found, 14149279);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_D)){
		env->pa += 0.1;
		if (env->pa > 2 *PI)
			env->pa -= 2 *PI;
		env->dx = cos(env->pa) * 5;
		env->dy = sin(env->pa) * 5;
		mlx_delete_image(env->mlx, env->found);
		env->found = mlx_new_image(env->mlx, 1220 * 2, 305 * 2);
		memset(env->found->pixels, 200, env->found->width * env->found->height * sizeof(int));
		mlx_image_to_window(env->mlx, env->found, 0, 0);
		env->found->instances->z = env->player->instances[0].z -1;
		dda_line(env->x + 5, env->y + 5,((env->x + 5) + (env->dx * LENGHT_RAY)) , (env->y + 5 + (env->dy * LENGHT_RAY)), env->found, 14149279);
	}	
}

void	hook(void *param)
{
	t_env *env;
	env = param;
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP)){
		env->player->instances[0].y -= 5;
		mlx_delete_image(env->mlx, env->found);
		env->found = mlx_new_image(env->mlx, 1220 * 2, 305 * 2);
		memset(env->found->pixels, 200, env->found->width * env->found->height * sizeof(int));
		mlx_image_to_window(env->mlx, env->found, 0, 0);
		env->found->instances->z = env->player->instances[0].z -1;
		env->y -= 5;
		dda_line(env->x + 5, env->y + 5,((env->x + 5) + (env->dx * LENGHT_RAY) ), (env->y +5 + (env->dy * LENGHT_RAY)), env->found, 14149279);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN)){
		
		env->player->instances[0].y += 5;
		mlx_delete_image(env->mlx, env->found);
		env->found = mlx_new_image(env->mlx, 1220 * 2, 305 * 2);
		memset(env->found->pixels, 200, env->found->width * env->found->height * sizeof(int));
		mlx_image_to_window(env->mlx, env->found, 0, 0);
		env->found->instances->z = env->player->instances[0].z -1;
		env->y += 5;
		dda_line(env->x + 5, env->y + 5,((env->x + 5) + (env->dx * LENGHT_RAY) ), (env->y +5 + (env->dy * LENGHT_RAY)), env->found, 14149279);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT)){
		env->player->instances[0].x -= 5;
		mlx_delete_image(env->mlx, env->found);
		env->found = mlx_new_image(env->mlx, 1220 * 2, 305 * 2);
		memset(env->found->pixels, 200, env->found->width * env->found->height * sizeof(int));
		mlx_image_to_window(env->mlx, env->found, 0, 0);
		env->found->instances->z = env->player->instances[0].z -1;
		env->x -= 5;
		dda_line(env->x + 5, env->y + 5,((env->x + 5) + (env->dx * LENGHT_RAY) ), (env->y +5 + (env->dy * LENGHT_RAY)), env->found, 14149279);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT)){
		env->player->instances[0].x += 5;
		env->x += 5;
		mlx_delete_image(env->mlx, env->found);
		env->found = mlx_new_image(env->mlx, 1220 * 2, 305 * 2);
		memset(env->found->pixels, 200, env->found->width * env->found->height * sizeof(int));
		mlx_image_to_window(env->mlx, env->found, 0, 0);
		env->found->instances->z = env->player->instances[0].z -1;
		dda_line(env->x + 5, env->y + 5,((env->x + 5) + (env->dx * LENGHT_RAY) ), (env->y +5 + (env->dy * LENGHT_RAY)), env->found, 14149279);
	}
	
}

int main(void){
	
	t_env env;
	mlx_texture_t *texture;
	mlx_image_t *yellow;
	
	env.dx = cos(env.pa) * 5;
	env.dy = sin(env.pa) * 5;
	env.x = 100;
	env.y = 100;
	env.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!env.mlx)
		exit(EXIT_FAILURE);
	env.player = mlx_new_image(env.mlx, 10, 10);
	env.found = mlx_new_image(env.mlx, 1220 * 2, 305 * 2);
	memset(env.player->pixels, 255, env.player->width * env.player->height * sizeof(int));
	memset(env.found->pixels, 200, env.found->width * env.found->height * sizeof(int));
	mlx_image_to_window(env.mlx, env.found, 0, 0);
	mlx_image_to_window(env.mlx, env.player, env.x, env.y);
	texture = mlx_load_png("./images/yellow.png");
	yellow = mlx_texture_to_image(env.mlx, texture);
	mlx_loop_hook(env.mlx, &hook, &env);
	mlx_loop_hook(env.mlx, &vortice_hook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
	return (EXIT_SUCCESS);
}