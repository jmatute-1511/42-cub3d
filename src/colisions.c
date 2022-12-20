/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:05:48 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/20 17:01:13 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	print_state(char *str, t_clcord *cord)
{
	dprintf(2, "%s---> abs: %f,sub_x: %f, sub_y %f, xf: %f, yf: %f\n", str, cord->abs, cord->sub_x, cord->sub_y, cord->xf, cord->yf);
}

void X_colision(t_clcord *cord, float angle, t_env *env, int limit)
{
	double atan;

	atan = tan(angle);
	if (PI > angle)
	{
		cord->sub_y = - env->hpb;
		cord->yf = (((int)env->y >> 8) << 8) - 0.0000001;
	}
	else if (PI < angle)
	{
		cord->sub_y = env->hpb;
		cord->yf = (((int)env->y >> 8) << 8) + env->hpb;
	}
	cord->sub_x = - cord->sub_y / atan;
	cord->xf = env->x + ((env->y - cord->yf) / atan);
	while (cord->xf < env->top_x && cord->yf < env->top_y && cord->xf  > 0 && cord->yf > 0)
	{
		if (env->map[(int)cord->yf / env->hpb][(int)cord->xf / env->hpb] == '1')
			break;
		cord->xf += cord->sub_x;
		cord->yf += cord->sub_y;
	}
	cord->abs = round(fabs((env->x - cord->xf) / cos(angle)));
	cord->abs *= cos(angle - env->pa);
}

void Y_colision(t_clcord *cord, float angle, t_env *env, int limit)
{

	double atan;

	atan = tan(angle);
	if (angle > P2 && angle < P3)
	{
		cord->sub_x = - env->hpb;
		cord->xf = (((int)env->x >> 8) << 8) - 0.0000001;
	}
	else if (angle < P2 || angle > P3)
	{
		cord->sub_x = env->hpb;
		cord->xf = (((int)env->x >> 8) << 8) + env->hpb;
	}
	cord->sub_y = - cord->sub_x * atan;
	cord->yf = env->y + ((env->x - cord->xf) * atan);
	while(cord->xf < env->top_x  && cord->yf < env->top_y && cord->xf  > 0 && cord->yf > 0)
	{
		if (env->map[(int)cord->yf / env->hpb][(int)cord->xf / env->hpb] == '1')
			break;
		cord->xf += cord->sub_x;
		cord->yf += cord->sub_y;
	}
	cord->abs = round(fabs((env->y - cord->yf) / sin(angle)));
	cord->abs *= cos(angle - env->pa);

}



int draw_colision(t_env **d_env, float angle, int x)
{
	t_env	*env;
	t_clcord absc;
	t_clcord ord;
	mlx_texture_t *text;
	
	env = (*d_env);
	X_colision(&absc, angle, env, x);
	Y_colision(&ord, angle, env, x);
	// print_state("ABSCISAS  ",&absc);
	// print_state("ORD  ",&ord);
	int color = rgb_to_int(233, 155, 0, 255);
	if ( absc.abs <= ord.abs){
		double y = (env->hpb / absc.abs ) * env->dplane;
		int y_i = 540 - (y/2);
		if (y_i < 1080  && y_i > 0 && y_i + y < 1080)
		{
			text = get_column(env->texture, get_number_column(absc.xf, env->texture), y);
			mlx_draw_texture(env->found,text,x,y_i);
			//dda_line(x, y_i, x, y_i + floor(y), env->found, color);
		}
		else{
			text = get_column(env->texture,get_number_column(absc.xf, env->texture), y);
			mlx_draw_texture(env->found,text,x,0);
			//dda_line(x, 0, x, 999, env->found, color);
		}
	}
	else{
		color = rgb_to_int(249, 231, 141, 255);
		double y = (env->hpb / ord.abs) * env->dplane;
		int y_i = 540 - (y/2);
		if (y_i < 1080  && y_i > 0 && y_i + y < 1080 )
		{
			text = get_column(env->texture,get_number_column(ord.yf, env->texture), y);
			mlx_draw_texture(env->found,text,x,y_i);
			//dda_line(x, y_i, x, y_i + floor(y), env->found, color );
		}
		else{
			text = get_column(env->texture, get_number_column(ord.yf, env->texture), y);
			mlx_draw_texture(env->found,text,x,0);
			//dda_line(x, 0, x, 999, env->found, color);
		}
	}
	return (0);
}

void draw_fov(t_env **d_env)
{
	float	inc;
	float	angle;
	t_env	*env;
	int		i;

	i = 0;
	inc = 1.0472 / 1920;
	env = *d_env;
	angle = env->pa - 0.523599;
	mlx_delete_image(env->mlx, env->found);
	env->found = mlx_new_image(env->mlx, 1920, 1080);
	//memset(env->found->pixels, 255, env->found->width * env->found->height * sizeof(int));
	mlx_image_to_window(env->mlx, env->found, 0, 0);
	while (i < 1920)
	{
		angle = fix_angle(angle);
		draw_colision(d_env, angle, i);
		angle += inc;
		i++;
	}
}
