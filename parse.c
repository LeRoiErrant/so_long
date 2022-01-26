/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:50:17 by vheran            #+#    #+#             */
/*   Updated: 2022/01/11 13:05:20 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	open_n_countl(char *path)
{
	int		fd;
	char	*gnl;
	int		loop;
	int		count;

	loop = 1;
	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (loop)
	{
		gnl = gnl_wo_nl(fd);
		if (gnl)
		{
			count++;
			free(gnl);
		}
		else
			loop = 0;
	}
	close(fd);
	return (count);
}

char	**parse_map(char *path, t_game *g)
{
	int		fd;
	char	*gnl;
	int		i;

	g->msize.y = open_n_countl(path);
	if (!g->msize.y)
		return (0);
	g->map = malloc((g->msize.y + 1) * sizeof(char *));
	if (!g->map)
		return (0);
	i = 0;
	fd = open(path, O_RDONLY);
	while (i < g->msize.y)
	{
		gnl = gnl_wo_nl(fd);
		if (gnl)
		{
			g->map[i++] = ft_strdup(gnl);
			free(gnl);
		}
	}
	g->map[i] = NULL;
	close(fd);
	g->msize.x = ft_strlen(g->map[0]);
	return (g->map);
}
