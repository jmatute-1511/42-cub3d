/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:51 by alsanche          #+#    #+#             */
/*   Updated: 2023/01/23 18:23:55 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	is_valid(char c)
{
	if (c != '0' && c != '1' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

int	check_space(char **map, int y, int x)
{
	if (map[y][x + 1] == ' ')
		return (1);
	else if (map[y][x + 1] == '1')
		return (1);
	else if (map[y][x + 1] == '0')
		return (-1);
	return (1);
}

int	check_cero(char **map, int y, int x)
{
	if (y == 0 && x == 0)
		return (-1);
	else if (x == 0 || (size_t)x == ft_strlen(map[y]))
		return (-1);
	else if (map[y][x + 1] == ' ')
		return (-1);
	else if ((map[y + 1] && map[y + 1][x] == ' ')
		|| (map[y + 1] && map[y + 1][x] == '\0'))
		return (-1);
	else if (map[y][x + 1] == '1')
		return (1);
	else if (map[y][x + 1] == '0')
		return (1);
	return (1);
}

int	check_one(char **map, int y, int x)
{
	if (x > 0 && map[y][x - 1] != '1' && map[y][x + 1] == '\0'
	&& map[y - 1][x] != '1')
		return (-1);
	if (map[y][x + 1] == '1')
		return (1);
	else if (map[y][x + 1] == '0' && y == 0)
		return (-1);
	return (1);
}
