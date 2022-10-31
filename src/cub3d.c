/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:32:27 by jmatute-          #+#    #+#             */
/*   Updated: 2022/10/31 22:29:26 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

#define LENGHT_RAY 15

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
	while(i <= dcords.p){
		 mlx_put_pixel(flor, dcords.x, dcords.y, color);
		 dcords.x += dcords.incx;
		 dcords.y += dcords.incy;
		 i++;
	}
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
		dda_line(x * WIDTH, 0 , x * WIDTH, env->height * HEIGHT - 1 , env->found,16711680);	
		x++;
	}
	while (y < env->height)
	{
		dda_line(0 , y * HEIGHT, env->width * WIDTH  - 1 , y *HEIGHT, env->found,16711680);
		y++;
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
			if (env->map[y][x] == '1')
				mlx_image_to_window(env->mlx, env->walls, x * l_image + 1 , y * l_image + 1);
			else if (env->map[y][x] == 'P'){
				mlx_image_to_window(env->mlx, env->player ,x *l_image ,y * l_image);
				env->x = x * l_image;
				env->y = y * l_image;
			}
			x++;
		}
		x = 0;
		y ++;
	}
	draw_separator(&env);
	return (0);
}
void player_frames(t_env **d_env){
	t_env	*env;
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
	
	env = (*d_env);
	ra = env->pa;
	r = 0;
	mlx_delete_image(env->mlx, env->found);
	env->found = mlx_new_image(env->mlx, env->width * WIDTH, env->height * HEIGHT);
	memset(env->found->pixels, 100, env->found->width * env->found->height * sizeof(int));
	mlx_image_to_window(env->mlx, env->found, 0, 0);
	draw_separator(&env);
	env->found->instances->z = env->walls->instances[0].z - 1;
	while(r <  10){
		
		dof = 0;
		float aTan = -1 /tan(ra);
		if (ra > PI){ry = ((env->y >> 6) << 6) - 0.0001; rx = (env->y - ry) * aTan + env->x; yo = - 64; xo =- yo * aTan;}
		if (ra < PI){ry = ((env->y >> 6) << 6) + 64; rx = (env->y - ry) * aTan + env->x; yo = 64; xo =- yo * aTan;}
		if (ra == 0 || ra == PI){rx = env->x; ry = env->y; dof = 8;}
		while(dof < 8){
			mx = (int)(rx) >> 6  ;my = (int) (ry) >> 6; mp = my * env->width + mx;
			int x = 0;
			int y = 0;
			while ( mp >= env->width)
			{
				mp -= env->width;
				y++;
				x = mp;
		
			}	
			if(mp < env->width * env->height && env->map[y][x] == 1){dof = 8;}
			else{rx += xo; ry +=yo; dof+=1;}
		}
		dda_line(env->x + 5, env->y + 5, (rx) , (ry), env->found, 116711872);
		r++;
	}
}
void vortice_hook(void *param){
	t_env *env;
	env = param;
	
	if (mlx_is_key_down(env->mlx, MLX_KEY_A)){
		env->pa -= 0.1;
		if (env->pa < 0)
			env->pa += 2 *PI;
		env->dx = cos(env->pa) * 5;
		env->dy = sin(env->pa) * 5;
		player_frames(&env);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_D)){
		env->pa += 0.1;
		if (env->pa > 2 *PI)
			env->pa -= 2 *PI;
		env->dx = cos(env->pa) * 5;
		env->dy = sin(env->pa) * 5;
		player_frames(&env);
	}	
}

void	hook(void *param)
{
	t_env *env;
	env = param;
	
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP)){
		env->player->instances[0].y -= 5;
		env->y -= 5;
		player_frames(&env);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN)){
		
		env->player->instances[0].y += 5;
		env->y += 5;
		player_frames(&env);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT)){
		env->player->instances[0].x -= 5;
		env->x -= 5;
		player_frames(&env);
	}
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT)){
		env->player->instances[0].x += 5;
		env->x += 5;
		player_frames(&env);
	}
	
}

int main(int argc, char **argv)
{
	t_env env;
	mlx_texture_t *texture;
	mlx_image_t *yellow;
	
	if (argc == 1)
		return (0);
	env.width = 0;
	env.height = 0;
	env.dx = cos(env.pa) * 5;
	env.dy = sin(env.pa) * 5;
	env.map = read_map(argv[1], &env.width, &env.height);
	printf("%d %d\n", env.width, env.height);
	env.mlx = mlx_init(env.width * WIDTH , env.height * HEIGHT , "MLX42", true);
	env.texture = mlx_load_png("./images/yellow.png");
	env.walls = mlx_texture_to_image(env.mlx, env.texture);
	env.found = mlx_new_image(env.mlx, env.width * WIDTH, env.height * HEIGHT);
	env.player = mlx_new_image(env.mlx, 10, 10);
	memset(env.player->pixels, 255, env.player->width * env.player->height * sizeof(int));
	memset(env.found->pixels, 100, env.found->width * env.found->height * sizeof(int));
	mlx_image_to_window(env.mlx, env.found, 0, 0);
	fill_window(64, &env);
	mlx_loop_hook(env.mlx, &hook, &env);
	mlx_loop_hook(env.mlx, &vortice_hook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
	return 0;
}	