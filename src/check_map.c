/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatute- <jmatute-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by alsanche          #+#    #+#             */
/*   Updated: 2022/12/27 09:11:42 by jmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	is_valid(char c)
{
	if (c != '0' && c != '1' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

static int	corner_checker(char **map, int y, int x)
{
	if (map[y - 1][x] == '1' && map[y][x + 1] == '1'
		&& is_valid(map[y - 1][x + 1]) == 1)
		return (1);
	if (map[y - 1][x] == '1' && map[y][x - 1] == '1'
		&& is_valid(map[y - 1][x - 1]) == 1)
		return (1);
	if (map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& is_valid(map[y + 1][x - 1]) == 1)
		return (1);
	if (map[y + 1][x] == '1' && map[y][x + 1] == '1'
		&& is_valid(map[y + 1][x + 1]) == 1)
		return (1);
	return (0);
}

static int	check_space(char **map, int y, int x)
{
	if (map[y][x + 1] == ' ')
		return (1);
	else if (map[y][x + 1] == '1')
		return (1);
	else if (map[y][x + 1] == '0')
		return (-1);
	return (1);
}

static int	check_cero(char **map, int y, int x)
{
	if (y == 0 && x == 0)
		return (-1);
	else if (x == 0 || x == ft_strlen(map[y]))
		return (-1);
	else if (corner_checker(map, y, x) == 1)
		return (-1);
	else if (map[y][x + 1] == ' ')
		return (-1);
	else if (map[y + 1][x] == ' ' || map[y + 1][x] == '\0')
		return (-1);
	else if (map[y][x + 1] == '1')
		return (1);
	else if (map[y][x + 1] == '0')
		return (1);
	return (1);
}

static int	check_one(char **map, int y, int x)
{
	if (map[y][x - 1] != '1' && map[y][x + 1] == '\0' && map[y - 1][x] != '1')
		return (-1);
	if (map[y][x + 1] == ' ' && map[y + 1][x] == '0')
		return (-1);
	if (map[y][x + 1] == ' ' && map[y + 1][x] == '1')
		return (1);
	else if (map[y][x + 1] == '1')
		return (1);
	else if (map[y][x + 1] == '0' && y == 0)
		return (-1);
	return (1);
}

void    set_view(char dir, t_env *env)
{
    if (dir == 'N')
        env->pa = P2;
    else if (dir == 'S')
        env->pa = P3;
    else if (dir == 'W')
        env->pa = PI;
    else if (dir == 'E')
        env->pa = 0; 
}

void	check_map(char **map, t_env *env)
{
	int	y;
	int	x;

	if (env->play == 0)
		print_error_map(y, x, 5);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == ' ' && check_space(map, y, x) == -1)
				print_error_map(y, x, 2);
			else if (map[y][x] == '0' && check_cero(map, y, x) == -1)
				print_error_map(y, x, 2);
			else if (map[y][x] == '1' && check_one(map, y, x) == -1)
				print_error_map(y, x, 2);
			else if (map[y][x] == 'N' ||map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'O')
			{
				env->x = x * env->hpb + 5;
				env->y = y * env->hpb + 5;
				set_view(map[y][x], env);
			}
		}
	}
}
