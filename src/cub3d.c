/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/07 18:13:23 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	change_angles(t_env **d_env)
{
	t_env	*env;
	double	a_x;
	double	a_y;

	env = *d_env;
	env->pa = fix_angle(env->pa);
	env->dx = round(cos(env->pa) * 12);
	env->dy = round(sin(env->pa) * 12);
	a_x = fix_angle(env->pa - 1.5708);
	a_y = fix_angle(env->pa + 1.5708);
	env->plane_x = round(cos(a_x) * 8);
	env->plane_y = round(sin(a_y) * 8);
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
	{
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

void	close_cub(t_env *d_env)
{
	mlx_delete_image(d_env->mlx, d_env->found);
	free_matrix((d_env)->map);
	mlx_delete_texture((d_env)->tex->t_ea);
	mlx_delete_texture((d_env)->tex->t_no);
	mlx_delete_texture((d_env)->tex->t_so);
	mlx_delete_texture((d_env)->tex->t_we);
	free((d_env)->tex->c);
	free((d_env)->tex->f);
	free((d_env)->tex->ea);
	free((d_env)->tex->no);
	free((d_env)->tex->so);
	free((d_env)->tex->we);
	free(d_env->tex);
	mlx_terminate(d_env->mlx);
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

void	leaks_out()
{
	system("leaks cub3d");
}

int main(int argc, char **argv)
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
	atexit(leaks_out);
	return (0);
}
