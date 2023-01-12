
#include "./includes/cub3d.h"

int	draw_colision(t_env **d_env, double angle, int x)
{
	t_env		*env;
	t_clcord	absc;
	t_clcord	ord;

	env = (*d_env);
	x_colision(&absc, angle, env);
	y_colision(&ord, angle, env);
	if (ord.abs < absc.abs)
	{
		select_texture(angle, 'y', d_env);
		draw_column(d_env, ord.abs, ord.yf, x);
	}
	else
	{
		select_texture(angle, 'x', d_env);
		draw_column(d_env, absc.abs, absc.xf, x);
	}
	return (0);
}

void	draw_fov(t_env **d_env)
{
	t_env	*env;
	double	angle;
	int		i;

	i = 0;
	env = *d_env;
	angle = env->pa - (RADIAN * 30);
	if (env->found)
		mlx_delete_image(env->mlx, env->found);
	env->found = mlx_new_image(env->mlx, env->win_width, env->win_height);
	mlx_image_to_window(env->mlx, env->found, 0, 0);
	while (i < env->win_width)
	{
		angle = fix_angle(angle);
		draw_colision(d_env, angle, i);
		angle += env->inc;
		i++;
	}
}
