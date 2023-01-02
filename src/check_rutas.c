/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rutas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by alsanche          #+#    #+#             */
/*   Updated: 2022/12/25 13:06:17 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	valid_img(char *img)
{
	char	*aux;
	int		fd;

	aux = ft_strtrim(img, " ");
	free(img);
	img = aux;
	if (img[0] != '.' && img[1] != '/')
	{	
		aux = ft_strjoin("./", img);
		free(img);
		img = aux;
	}
	fd = open(img, O_RDONLY);
	if (fd == -1)
	{	
		ft_putstr_fd("Error reading the image, it will be", 2);
		ft_putstr_fd(" changed to the default image\n", 2);
		fd = open("./img/default_wall.png", O_RDONLY);
	}
	return (fd);
}

static int	*color_value(char *path)
{
	char	*aux;
	char	**color;
	int		i[2];
	int		value[3];

	aux = ft_strtrim(path, " ");
	free(path);
	color = ft_split(aux, ',');
	free(aux);
	i[0] = -1;
	while (color[++i[0]])
	{
		i[1] = -1;
		while (color[i[0]][++i[1]])
			if (ft_isdigit(color[i[0]][i[1]]) == 1)
				print_error(0, 0, 7);
		value[i[0]] = ft_atoi(color[i[0]])
		if (value[i[0]] > 255)
			value[i[0]] = value[i[0]] % 255;
	}
	return (value);
}

void	open_textures(t_env *env)
{
	env->tex->fd_no = valid_img(env->tex->no);
	env->tex->fd_so = valid_img(env->tex->so);
	env->tex->fd_we = valid_img(env->tex->we);
	env->tex->fd_ea = valid_img(env->tex->ea);
	env->tex->val_f = color_value(env->tex->f);
	env->tex->val_c = color_value(env->tex->c);	
}