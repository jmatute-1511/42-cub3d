/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2023/01/02 13:05:02 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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
	while(i < dcords.p){
		 mlx_put_pixel(flor, dcords.x, dcords.y, color);
		 dcords.x += dcords.incx;
		 dcords.y += dcords.incy;
		 i++;
	}
}

int fill_window(int l_image, t_env *env)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y  < env->height)
	{
		while (x < env->width){
			if (env->map[y][x] == 'P')
			{
				env->x = x * l_image + 5;
				env->y = y * l_image + 5;
			}
			x++;
		}
		x = 0;
		y ++;
	}
	return (0);
}

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

void get_rgb(t_env *env)
{
	char **m_floor;
	char **m_roof;
	uint8_t floor[3];
	uint8_t roof[3];
	int it;

	it = 0;
	m_floor = ft_split(env->tex->f, ',');
	m_roof = ft_split(env->tex->c, ',');
	while (it < 3)
	{
		floor[it] = ft_atoi(m_floor[it]);
		roof[it] = ft_atoi(m_roof[it]);
		it++;
	}
	env->floor = rgb_to_int(floor[0], floor[1], floor[2], 255);
	env->roof = rgb_to_int(roof[0], roof[1], roof[2], 255);
	free(m_floor);
	free(m_roof);
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