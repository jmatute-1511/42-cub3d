/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/02 16:31:52 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void change_angles(t_env **d_env)
{
	t_env *env;
	double a_x;
	double a_y;
	
	env = *d_env;
	env->pa = fix_angle(env->pa);
	env->dx = round(cos(env->pa) * 12);
	env->dy = round(sin(env->pa) * 12);
	a_x = fix_angle(env->pa - 1.5708);
	a_y = fix_angle(env->pa + 1.5708);
	env->plane_x = round(cos(a_x) * 8);
	env->plane_y = round(sin(a_y) * 8);	
}

void chek_colision_up_or_down(t_env **d_env)
{
	t_env *env;
	int	x;
	int y;

	env = *d_env;
	x = (int)env->x / env->hpb;
	y = (int)env->y / env->hpb;
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP))
	{
		if (env->map[((int)(env->y - env->dy * 6)) / env->hpb][x] != '1')
			env->y = env->y - env->dy;
		if (env->map[y][((int)(env->x + env->dx * 6)) / env->hpb] != '1')
			env->x = env->x + env->dx;
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
	{
		if (env->map[((int)(env->y + env->dy * 6)) / env->hpb][x] != '1')
			env->y = env->y + env->dy;
		if (env->map[y][((int)(env->x - env->dx * 6)) / env->hpb] != '1')
			env->x = env->x - env->dx;
	}
}	

void chek_colision_left_or_right(t_env **d_env)
{
	t_env *env;
	int	x;
	int y;

	env = *d_env;
	x = (int)env->x / env->hpb;
	y = (int)env->y / env->hpb;
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
	{
		if (env->map[((int)(env->y + env->plane_y * 3)) / env->hpb][x] != '1')
			env->y = round(env->y + env->plane_y );
		if (env->map[y][((int)(env->x + env->plane_x * 3)) / env->hpb] != '1')
			env->x = round(env->x + env->plane_x );
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
	{
		if (env->map[((int)(env->y - env->plane_y * 3)) / env->hpb][x] != '1')
			env->y = (int)(env->y - env->plane_y);
		if (env->map[y][((int)(env->x - env->plane_x * 3)) / env->hpb] != '1')
			env->x = (int)(env->x - env->plane_x);
	}
}

void	hook(void *param)
{
	t_env *env;
	env = param;
	
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
	if (mlx_is_key_down(env->mlx, MLX_KEY_D))
		env->pa += 0.02;
	if (mlx_is_key_down(env->mlx, MLX_KEY_A))
		env->pa -= 0.02;
	change_angles(&env);
	chek_colision_up_or_down(&env);
	chek_colision_left_or_right(&env);
	draw_fov(&env);
}

int main(int argc, char **argv)
{
	t_env		env;
	
	if (argc != 2)
		return (0);
	env.hpb = 256;
	env.win_height = 720;
	env.win_width = 1280;
	env.inc = (RADIAN * 60)/ env.win_width;
	read_map(argv[1], &env);
	get_rgb(&env);
	env.mlx = mlx_init((int)env.win_width,(int)env.win_height , "MLX42", true);
	env.top_x = env.width * env.hpb;
	env.top_y = env.height * env.hpb;
	env.dplane =  env.hpb / tan(0.523599);
	env.found = mlx_new_image(env.mlx, env.win_width, env.win_height);
	mlx_image_to_window(env.mlx, env.found, 0, 0);
	mlx_loop_hook(env.mlx, &hook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
	return 0;
}	