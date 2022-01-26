/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_wo_nl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:50:46 by vheran            #+#    #+#             */
/*   Updated: 2021/12/18 10:50:46 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

static char	*get_line(char *data)
{
	char	*line;
	int		len;

	len = 0;
	while (data[len] != '\n' && data[len])
		len++;
	if (!len)
		return (0);
	if (!data)
		return (0);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (0);
	ft_memmove(line, data, len);
	line[len] = '\0';
	return (line);
}

static char	*del_line(char *data)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	while (data[i] != '\n' && data[i])
		i++;
	if (data[i] == '\n')
		i++;
	if (!data[i])
	{
		free(data);
		return (NULL);
	}
	len = ft_strlen(data) - i;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	ft_memmove(tmp, &data[i], len);
	tmp[len] = '\0';
	free(data);
	return (tmp);
}

static char	*get_data(int fd, char *sdata)
{
	char	*buffer;
	char	*tmp;
	int		len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	len = 1;
	while (len > 0 && !ft_strchr(sdata, '\n'))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[len] = '\0';
		tmp = ft_strjoin(sdata, buffer);
		if (!tmp)
			return (0);
		free (sdata);
		sdata = tmp;
	}
	free(buffer);
	return (sdata);
}

char	*gnl_wo_nl(int fd)
{
	static char	*sdata;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sdata = get_data(fd, sdata);
	if (!sdata)
		return (0);
	line = get_line(sdata);
	sdata = del_line(sdata);
	return (line);
}
