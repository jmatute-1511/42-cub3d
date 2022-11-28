/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:05:48 by jmatute-          #+#    #+#             */
/*   Updated: 2022/11/28 17:08:57 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void print_state(char *str, t_clcord *cord){
	dprintf(2,"%s---> abs: %f,sub_x: %f, sub_y %f, xf: %f, yf: %f\n",str,cord->abs, cord->sub_x, cord->sub_y, cord->xf, cord->yf);
}


void X_colision(t_clcord *cord, float angle, t_env *env)
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
	//dprintf(2, "f_xf%d,  f_yf%d\n", cord->xf, cord->yf);
	while (cord->xf < env->width * 64  && cord->yf < env->height * 64 && cord->xf  >= 0 && cord->yf >= 0)
	{
		if (env->map[(int)cord->yf / 64][(int)cord->xf / 64] == '1'){
			//dprintf(2,"block colison X : (Y %d,X %d)\n", cord->yf/64,  cord->xf/64);
			break;
		}
		cord->xf += cord->sub_x;
		cord->yf += cord->sub_y;
	}
	cord->abs = fabs((env->x - cord->xf) / cos(angle));
}

void Y_colision(t_clcord *cord, float angle, t_env *env)
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
	//dprintf(2, "f_xf%d,  f_yf%d\n", cord->xf, cord->yf);
	while(cord->xf < env->width * 64  && cord->yf < env->height * 64 && cord->xf  > 0 && cord->yf > 0)
	{
		if (env->map[(int)cord->yf / 64][(int)cord->xf / 64] == '1')
		{
		//	dprintf(2,"block colison Y : (Y %d,X %d)\n", cord->yf/64,  cord->xf/64);
			break;
		}
		cord->xf += cord->sub_x;
		cord->yf += cord->sub_y;
	}
	cord->abs = fabs((env->x - cord->xf) / cos(angle));
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
		// dprintf(2, "separador ----> %d\n", x * WIDTH - 1);
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


int draw_colision(t_env **d_env, float angle)
{
	t_env	*env;
	t_clcord absc;
	t_clcord ord;
	
	env = (*d_env);
	init_cord(&absc);
	init_cord(&ord);
	X_colision(&absc, angle, env);
	Y_colision(&ord, angle, env);
	// 	print_state("ABCISAS", &absc);
	// print_state("ORDENADAS", &ord);
	
	if ( absc.abs <= ord.abs){
		dda_line(env->x , env->y, absc.xf, absc.yf, env->found, 116711872);
	}
	else if (ord.xf >= 0 && ord.yf >= 0){
		dda_line(env->x , env->y, ord.xf, ord.yf, env->found, 116711872);
	}
	return (0);
}
void change_angle(float *angle)
{
	if (*angle > 2 *PI)
		*angle -= (2 * PI);
	if (*angle < 0)
		*angle += (2 * PI);
}

void draw_fov(t_env **d_env)
{
	float	inc;
	float	angle;
	t_env	*env;
	int i;
	
	i = 0;
	inc = 1.0472 / 320;
	env = *d_env;
	angle = env->pa - 0.523599;
	mlx_delete_image(env->mlx, env->found);
	env->found = mlx_new_image(env->mlx, env->width * WIDTH, env->height * HEIGHT);
	memset(env->found->pixels, 100, env->found->width * env->found->height * sizeof(int));
	mlx_image_to_window(env->mlx, env->found, 0, 0);
	draw_separator(&env);
	env->found->instances->z = env->player->instances[0].z;
	while(i < 320)
	{
		change_angle(&angle);
		draw_colision(d_env, angle);
		angle += inc;
		i++;
	}
}