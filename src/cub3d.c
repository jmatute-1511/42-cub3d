/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/08 15:19:46 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

#define LENGHT_RAY 15

void	dda_line(int xi, int yi, int xf, int yf, mlx_image_t *flor, uint32_t color)
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
	while (i < dcords.p)
	{
		mlx_put_pixel(flor, dcords.x, dcords.y, color);
		dcords.x += dcords.incx;
		dcords.y += dcords.incy;
		i++;
	}
}

int	fill_window(int l_image, t_env *env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < env->height)
	{
		while (x < env->width)
		{
			if (env->map[y][x] == '1')
				;//mlx_image_to_window(env->mlx, env->walls, x * l_image, y * l_image);
			else if (env->map[y][x] == 'P')
			{
				//mlx_image_to_window(env->mlx, env->player ,x *l_image ,y * l_image);
				env->x = x * l_image + 5;
				env->y = y * l_image + 5;
			}
			x++;
		}
		x = 0;
		y ++;
	}
	//draw_separator(&env);
	return (0);
}

void	vortice_hook(void *param)
{
	t_env	*env;

	env = param;
	if (env->pa > 2 * PI)
		env->pa -= (2 * PI);
	if (env->pa < 0)
		env->pa += (2 * PI);
	if (mlx_is_key_down(env->mlx, MLX_KEY_D))
	{
		env->pa += 0.015;
		draw_fov(&env);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_A))
	{
		env->pa -= 0.015;
		draw_fov(&env);
	}	
}

void	change_angles(t_env **d_env)
{
	t_env	*env;
	double	a_x;
	double	a_y;

	env = *d_env;
	env->pa = fix_angle(env->pa);
	env->dx = cos(env->pa) * 4;
	env->dy = sin(env->pa) * 4;
	a_x = fix_angle(env->pa - 1.5708);
	a_y = fix_angle(env->pa + 1.5708);
	env->plane_x = cos(a_x) * 2;
	env->plane_y = sin(a_y) * 2;
}

void	hook(void *param)
{
	t_env	*env;

	env = param;
	if (mlx_is_key_down(env->mlx, MLX_KEY_D))
		env->pa += 0.015;
	if (mlx_is_key_down(env->mlx, MLX_KEY_A))
		env->pa -= 0.015;
	change_angles(&env);
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP))
	{
		if (env->map[((int)(env->y - env->dy * 3)) / 64][(int)env->x / 64] != '1')
			env->y = env->y - env->dy;
		if (env->map[(int)env->y / 64][((int)(env->x + env->dx * 3)) / 64] != '1')
			env->x = env->x + env->dx;
		//dprintf(2, " <<<  Y  >>: %d\n <<  X  >>: %d\n",(int) env->y, (int)env->x);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
	{
		if (env->map[((int)(env->y + env->dy * 3)) / 64][(int)env->x / 64] != '1')
			env->y = env->y + env->dy;
		if (env->map[(int)env->y / 64][((int)(env->x - env->dx * 3)) / 64] != '1')
			env->x = env->x - env->dx;
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
	{
		if (env->map[((int)(env->y + env->plane_y * 3)) / 64][(int)env->x / 64] != '1')
			env->y = env->y + env->plane_y ;
		if (env->map[(int)env->y / 64][((int)(env->x + env->plane_x * 3)) / 64] != '1')
			env->x = env->x + env->plane_x ;
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
	{
		if (env->map[((int)(env->y - env->plane_y * 3)) / 64][(int)env->x / 64] != '1')
			env->y = env->y - env->plane_y;
		if (env->map[(int)env->y / 64][((int)(env->x - env->plane_x * 3)) / 64] != '1')
			env->x = env->x - env->plane_x;
	}
	draw_fov(&env);
}

int	main(int argc, char **argv)
{
	t_env			env;
	mlx_texture_t	*texture;
	mlx_image_t		*yellow;

	if (argc == 1)
		return (0);
	env.pa = PI ;
	env.dx = cos(env.pa);
	env.dy = sin(env.pa);
	read_map(argv[1], &env);
	env.top_x = env.width * 64;
	env.top_y = env.height * 64;
	env.dplane = 320 / tan(0.523599);
	printf("%i %i\n", env.width, env.height);
	env.mlx = mlx_init(1280, 1000, "MLX42", true);
	env.texture = mlx_load_png("./images/wall_640.png");
	env.walls = mlx_texture_to_image(env.mlx, env.texture);
	env.found = mlx_new_image(env.mlx, 1280, 1000);
	//env.player = mlx_new_image(env.mlx, 10, 10);
	//memset(env.player->pixels, 255, env.player->width * env.player->height * sizeof(int));
	//memset(env.found->pixels, 100, env.found->width * env.found->height * sizeof(int));
	mlx_image_to_window(env.mlx, env.found, 0, 0);
	fill_window(64, &env);
	mlx_loop_hook(env.mlx, &hook, &env);
	//mlx_loop_hook(env.mlx, &vortice_hook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
	return (0);
}
