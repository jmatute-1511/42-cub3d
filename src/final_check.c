/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:27:34 by alsanche          #+#    #+#             */
/*   Updated: 2023/01/20 11:02:48 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	exit_free(t_env *env, int check)
{
	if (env->tex->no != NULL)
		free(env->tex->no);
	if (env->tex->so != NULL)
		free(env->tex->so);
	if (env->tex->ea != NULL)
		free(env->tex->ea);
	if (env->tex->we != NULL)
		free(env->tex->we);
	if (env->tex->f != NULL)
		free(env->tex->f);
	if (env->tex->c != NULL)
		free(env->tex->c);
	free(env->tex);
	if (check == 1)
		free_matrix(env->map);
	exit (1);
}

void	not_error(t_env *env, char f, char	*str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ',')
		{
			i++;
			count++;
		}
		if (ft_isdigit(str[i]) == 0)
		{
			printf("Error\nNot number char on %c\n", f);
			exit_free(env, 1);
		}
	}
	if (count != 2)
	{
		printf("Error\nIt is not RGB format on %c\n", f);
		exit_free(env, 1);
	}
}

void	check_nums(t_env *env)
{
	char	**temp;
	int		aux;
	int		i;

	not_error(env, 'F', env->tex->f);
	not_error(env, 'C', env->tex->c);
	temp = ft_split(env->tex->f, ',');
	i = -1;
	while (temp[++i])
	{
		aux = ft_atoi(temp[i]);
		if (aux > 255 || aux < 0)
			print_error_map(0, 0, 7, env);
	}
	free_matrix(temp);
	temp = ft_split(env->tex->c, ',');
	i = -1;
	while (temp[++i])
	{
		aux = ft_atoi(temp[i]);
		if (aux > 255 || aux < 0)
			print_error_map(0, 0, 7, env);
	}
	free_matrix(temp);
}

void	load_texture(t_env *env)
{
	env->tex->t_no = mlx_load_png(env->tex->no);
	if (env->tex->t_no == NULL)
	{
		printf("Error\nNORTH image read\n");
		exit_free(env, 1);
	}
	env->tex->t_so = mlx_load_png(env->tex->so);
	if (env->tex->t_so == NULL)
	{
		printf("Error\nSOUTH image read\n");
		exit_free(env, 1);
	}
	env->tex->t_ea = mlx_load_png(env->tex->ea);
	if (env->tex->t_ea == NULL)
	{
		printf("Error\nEAST image read\n");
		exit_free(env, 1);
	}
	env->tex->t_we = mlx_load_png(env->tex->we);
	if (env->tex->t_we == NULL)
	{
		printf("Error\nWEST image read\n");
		exit_free(env, 1);
	}
	check_nums(env);
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
