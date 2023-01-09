/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/09 16:35:08 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	key_down(int y, int x, t_env **d_env)
{	
	t_env	*env;

	env = *d_env;
	if (env->map[y][((int)(env->x + round(env->dx))) / env->hpb] != '1')
		env->x = env->x + env->dx;
	if (env->map[((int)(env->y - round(env->dy))) / env->hpb][x] != '1')
		env->y = env->y - env->dy;
	if (env->map[(int)(env->y / env->hpb)][(int)(env->x / env->hpb)] == '1')
	{
		env->y = env->y + env->dy;
		env->x = env->x - env->dx;
	}
}

void	chek_colision_up_or_down(t_env **d_env)
{
	t_env	*env;
	int		x;
	int		y;

	env = *d_env;
	x = (int)env->x / env->hpb;
	y = (int)env->y / env->hpb;
	if (mlx_is_key_down(env->mlx, MLX_KEY_W))
		key_down(y, x, d_env);
	if (mlx_is_key_down(env->mlx, MLX_KEY_S))
	{
		if (env->map[((int)(env->y + env->dy)) / env->hpb][x] != '1')
			env->y = env->y + env->dy;
		if (env->map[y][((int)(env->x - env->dx)) / env->hpb] != '1')
			env->x = env->x - env->dx;
	}
}

void	chek_colision_left_or_right(t_env **d_env)
{
	t_env	*env;
	int		x;
	int		y;

	env = *d_env;
	x = (int)env->x / env->hpb;
	y = (int)env->y / env->hpb;
	if (mlx_is_key_down(env->mlx, MLX_KEY_A))
	{
		if (env->map[((int)(env->y + env->plane_y * 3)) / env->hpb][x] != '1')
			env->y = round(env->y + env->plane_y);
		if (env->map[y][((int)(env->x + env->plane_x * 3)) / env->hpb] != '1')
			env->x = round(env->x + env->plane_x);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_D))
	{
		if (env->map[((int)(env->y - env->plane_y * 3)) / env->hpb][x] != '1')
			env->y = (int)(env->y - env->plane_y);
		if (env->map[y][((int)(env->x - env->plane_x * 3)) / env->hpb] != '1')
			env->x = (int)(env->x - env->plane_x);
	}
}

void	hook(void *param)
{
	t_env	*env;

	env = param;
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		env->pa += 0.02;
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		env->pa -= 0.02;
	change_angles(&env);
	chek_colision_up_or_down(&env);
	chek_colision_left_or_right(&env);
	draw_fov(&env);
}

int	main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
		return (0);
	env.hpb = 256;
	env.win_height = 720;
	env.win_width = 1280;
	read_map(argv[1], &env);
	get_rgb(&env);
	env.mlx = mlx_init((int)env.win_width, (int)env.win_height, "MLX42", true);
	env.inc = (RADIAN * 60) / env.win_width;
	env.top_x = env.width * env.hpb;
	env.top_y = env.height * env.hpb;
	env.dplane = env.hpb / tan(0.523599);
	mlx_loop_hook(env.mlx, &hook, &env);
	mlx_loop(env.mlx);
	close_cub(&env);
	return (0);
}
