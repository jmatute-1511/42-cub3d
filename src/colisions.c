/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:05:48 by jmatute-          #+#    #+#             */
/*   Updated: 2022/12/13 17:37:08 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void print_state(char *str, t_clcord *cord)
{
	dprintf(2,"%s---> abs: %f,sub_x: %f, sub_y %f, xf: %f, yf: %f\n",str,cord->abs, cord->sub_x, cord->sub_y, cord->xf, cord->yf);
}


void X_colision(t_clcord *cord, float angle, t_env *env, int limit)
{
	if (PI > angle)
	{
		cord->sub_y = -64;
		cord->yf = (((int)env->y >> 6) << 6) - 0.0001;
	}
	else if (PI < angle)
	{
		cord->sub_y = 64;
		cord->yf = (((int)env->y >> 6) << 6) + 64;
	}
	cord->sub_x = -cord->sub_y / tan(angle);
	cord->xf = env->x + ((env->y - cord->yf) / tan(angle));
	while (cord->xf < env->width * 64  && cord->yf < env->height * 64 && cord->xf  >= 0 && cord->yf >= 0)
	{
		if (env->map[(int)cord->yf / 64][(int)cord->xf / 64] == '1')
			break;
		cord->xf += cord->sub_x;
		cord->yf += cord->sub_y;
	}
	cord->abs = fabs(((env->y - cord->yf) / sin(angle))) * cos(fix_angle(env->pa - angle));
}

void Y_colision(t_clcord *cord, float angle, t_env *env, int limit)
{
	if (angle > P2 && angle < P3)
	{
		cord->sub_x = - 64;
		cord->xf = (((int)env->x >> 6) << 6) - 0.0001;
	}
	else if (angle < P2 || angle > P3)
	{
		cord->sub_x = 64;
		cord->xf = (((int)env->x >>6 ) << 6) + 64;
	}
	cord->sub_y = -cord->sub_x * tan(angle);
	cord->yf = env->y + ((env->x - cord->xf) * tan(angle));
	while(cord->xf < env->width * 64  && cord->yf < env->height * 64 && cord->xf  > 0 && cord->yf > 0)
	{
		if (env->map[(int)cord->yf / 64][(int)cord->xf / 64] == '1')
			break;
		cord->xf += cord->sub_x;
		cord->yf += cord->sub_y;
	}
	cord->abs = fabs(((env->y - cord->yf) / sin(angle))) * cos(fix_angle(env->pa - angle));
}

void draw_separator(t_env **d_env)
{
	t_env *env;
	int x;
	int y;
	
	env = *d_env;
	x = 0;
	y = 0;
	while ( x < env->width)
	{
		dda_line(x * WIDTH, 0 , x * WIDTH - 1, env->height * HEIGHT, env->found,16711680);	
		x++;
	}
	while (y < env->height)
	{
		dda_line(0 , y * HEIGHT, env->width * WIDTH , y * HEIGHT - 1, env->found,16711680);
		y++;
	}
}

void init_cord(t_clcord *cord)
{
	cord->abs = 0;
	cord->sub_x = 0;
	cord->sub_y = 0;
	cord->xf = 0;
	cord->yf = 0;
}

uint32_t rgb_to_int(int red, int green, int blue, int transparency)
{
	int color;

	color = 0;
	red <<= 24;
	green <<= 16;
	blue <<= 8;
	return (color | red | green | blue | transparency); 
}

int draw_colision(t_env **d_env, float angle, int x)
{
	t_env	*env;
	t_clcord absc;
	t_clcord ord;
	
	env = (*d_env);
	init_cord(&absc);
	init_cord(&ord);
	X_colision(&absc, angle, env, x);
	Y_colision(&ord, angle, env, x);
	int color = rgb_to_int(233, 155, 0, 255);
	if ( absc.abs <= ord.abs){
		double y = (64 / absc.abs) * env->dplane;
		int y_i = 500 - (int)(y/2);
		if (y_i < 1000  && y_i > 0 && y_i + y < 1000 && (int)absc.xf % 64 != 0)
			dda_line(x, y_i, x, y_i + y, env->found, color);
		else if((int)absc.xf % 64 != 0)
			dda_line(x, 0, x, 999, env->found, color);
	}
	else if (ord.xf >= 0 && ord.yf >= 0){
		color = rgb_to_int(249, 231, 141, 255);
		double y = (64 / ord.abs) * env->dplane;
		int y_i = 500 - (int)(y/2);
		if (y_i < 1000  && y_i > 0 && y_i + y < 1000 && (int)ord.yf % 64 != 0)
			dda_line(x, y_i, x, y_i + y, env->found, color );
		else if ((int)ord.yf % 64 != 0)
			dda_line(x, 0, x, 999, env->found, color);
	}
	return (0);
}

double fix_angle(double  angle)
{
	if ( angle > 2 *PI)
		 angle -= (2 * PI);
	if ( angle < 0)
		 angle += (2 * PI);
	return (angle);
}

void draw_fov(t_env **d_env)
{
	float	inc;
	float	angle;
	t_env	*env;
	int i;
	
	i = 0;
	inc = 1.0472 / 1280;
	env = *d_env;
	angle = env->pa - 0.523599;
	mlx_delete_image(env->mlx, env->found);
	env->found = mlx_new_image(env->mlx, 1280, 1000);
	//memset(env->found->pixels, 255, env->found->width * env->found->height * sizeof(int));
	mlx_image_to_window(env->mlx, env->found, 0, 0);
	while(i < 1280)
	{
		angle = fix_angle(angle);
		draw_colision(d_env, angle, i);
		angle += inc;	
		i++;
	}
}