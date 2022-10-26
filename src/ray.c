/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:45:20 by jmatute-          #+#    #+#             */
/*   Updated: 2022/10/26 16:59:23 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

void dda_line(int xi, int yi, int xf, int yf, mlx_image_t *floor, uint32_t color)
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
		 mlx_put_pixel(floor, dcords.x, dcords.y, color);
		 dcords.x += dcords.incx;
		 dcords.y += dcords.incy;
		 i++;
	}
}

void rtx(t_env **env){

	mlx_image_t *aux;

	aux = ((*env)->player->img_p); 
	if (mlx_is_key_down((*env)->mlx), MLX_KEY_UP) 
		dda_line(aux->instances->x, aux->instances->y, x++,  y--, (*env)->found, 14149279);
}

void ray_hook(void *param){
	t_env  *env = (t_env *)param;

	
}
