
#include "./includes/cub3d.h"

void	x_colision(t_clcord *cord, double angle, t_env *env)
{
	double	atan;

	atan = tan(angle);
	if (PI > angle)
	{
		cord->sub_y = -env->hpb;
		cord->yf = (((int)env->y >> 8) << 8) - 0.0001;
	}
	else
	{
		cord->sub_y = env->hpb;
		cord->yf = (((int)env->y >> 8) << 8) + env->hpb;
	}
	cord->sub_x = -cord->sub_y / atan;
	cord->xf = env->x + ((env->y - cord->yf) / atan);
	while (cord->xf < env->top_x && cord->yf < env->top_y && \
	cord->xf > 0 && cord->yf > 0)
	{
		if (env->map[(int)cord->yf / env->hpb][(int)cord->xf / env->hpb] == '1')
			break ;
		cord->yf += cord->sub_y;
		cord->xf += cord->sub_x;
	}
	cord->abs = fabs((env->x - cord->xf) / cos(angle)) * cos(angle - env->pa);
}

void	y_colision(t_clcord *cord, double angle, t_env *env)
{
	double	atan;

	atan = tan(angle);
	if (angle > P2 && angle < P3)
	{
		cord->sub_x = -env->hpb;
		cord->xf = (((int)env->x >> 8) << 8) - 0.0001;
	}
	else if (angle < P2 || angle > P3)
	{
		cord->sub_x = env->hpb;
		cord->xf = (((int)env->x >> 8) << 8) + env->hpb;
	}
	cord->sub_y = -cord->sub_x * atan;
	cord->yf = env->y + ((env->x - cord->xf) * atan);
	while (cord->xf < env->top_x && cord->yf < env->top_y && \
	cord->xf > 0 && cord->yf > 0)
	{
		if (env->map[(int)cord->yf / env->hpb][(int)cord->xf / env->hpb] == '1')
			break ;
		cord->xf += cord->sub_x;
		cord->yf += cord->sub_y;
	}
	cord->abs = fabs((env->x - cord->xf) / cos(angle)) * cos(angle - env->pa);
}

void	select_texture(double angle, char axis, t_env **d_env)
{
	if (axis == 'x')
	{
		if (angle < PI)
			(*d_env)->texture = (*d_env)->tex->t_no;
		else
			(*d_env)->texture = (*d_env)->tex->t_so;
	}
	else if (axis == 'y')
	{
		if (angle > P2 && angle < P3)
			(*d_env)->texture = (*d_env)->tex->t_we;
		else
			(*d_env)->texture = (*d_env)->tex->t_ea;
	}	
}

void	dda_data(t_dda *data, t_env *env, int x, char type)
{
	if (type == 'R')
	{
		data->x_i = x;
		data->x_f = x;
		data->y_i = 0;
		data->y_f = data->y;
	}
	else if (type == 'F')
	{
		data->x_i = x;
		data->x_f = x;
		data->y_i = data->y + env->text_height;
		data->y_f = env->win_height ;
	}
}

void	draw_column(t_env **d_env, double abs, double cord, int x)
{
	t_env			*env;
	mlx_texture_t	*text;
	t_dda			data;

	env = *d_env;
	env->text_height = (env->hpb / abs) * env->dplane - 0.5;
	data.y = ((int)env->win_height >> 1) - ((int)env->text_height >> 1);
	text = g_t_c(env->texture, \
	get_number_column(cord, env->texture), env->text_height, env);
	if (data.y < env->win_height && data.y > 0 && \
	data.y + env->text_height < env->win_height)
	{
		dda_data(&data, env, x, 'R');
		dda_line(&data, env->found, env->roof);
		mlx_draw_texture(env->found, text, x, data.y);
		dda_data(&data, env, x, 'F');
		dda_line(&data, env->found, env->floor);
	}
	else
		mlx_draw_texture(env->found, text, x, 0);
	mlx_delete_texture(text);
}
