/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:12:02 by vheran            #+#    #+#             */
/*   Updated: 2022/01/18 13:05:15 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

int	check_extension(char *path)
{
	int	i;

	i = ft_strlen(path) - 4;
	if (!ft_strnstr(&path[i], ".ber", 4))
		return (0);
	else
		return (1);
}

static int	check_elements(char **map, int chr)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (map[++i])
		if (ft_strchr(map[i], chr))
			c++;
	return (c);
}

static int	check_walls(char **map, t_coord s)
{
	int	i;
	int	x;
	int	y;

	x = s.x - 1;
	y = s.y - 1;
	i = -1;
	while (++i < x)
		if (map[0][i] != '1' || map[y][i] != '1')
			return (0);
	i = -1;
	while (++i < y)
		if (map[i][0] != '1' || map[i][x] != '1')
			return (0);
	return (1);
}

static int	check_valid(char **map)
{
	t_coord	i;
	char	c;

	i.y = -1;
	while (map[++i.y])
	{
		i.x = -1;
		while (map[i.y][++i.x])
		{
			c = map[i.y][i.x];
			if (!ft_strchr(ELEMCODES, c))
				return (0);
		}
	}
	return (1);
}

int	check_map(char **map, t_coord size)
{
	int	i;
	int	c;

	(void) size.y;
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != (size_t) size.x)
			return (5);
	}
	c = check_elements(map, 'E');
	if (!c)
		return (2);
	c = check_elements(map, 'C');
	if (!c)
		return (3);
	c = check_elements(map, 'P');
	if (!c)
		return (4);
	if (!check_walls(map, size))
		return (1);
	if (!check_valid(map))
		return (6);
	return (0);
}
