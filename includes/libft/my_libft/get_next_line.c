/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:39:35 by vheran            #+#    #+#             */
/*   Updated: 2021/12/16 09:43:20 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*get_line(char *data)
{
	char	*line;
	int		len;

	len = 0;
	while (data[len] != '\n' && data[len] != '\0')
		len++;
	if (data[len] == '\n')
		len++;
	if (!len)
		return (0);
	if (!data)
		return (0);
	line = (char *)malloc((len + 1) * sizeof(*line));
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
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	if (!data[i])
	{
		free(data);
		return (NULL);
	}
	len = ft_strlen(data) - i;
	tmp = (char *)malloc((len + 1) * sizeof(*tmp));
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
			free(buffer);
			return (0);
		}
		buffer[len] = '\0';
		tmp = ft_strjoin(sdata, buffer);
		if (!tmp)
			return (0);
		free(sdata);
		sdata = tmp;
	}
	free(buffer);
	return (sdata);
}

char	*get_next_line(int fd)
{
	static char	*sdata;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sdata = get_data(fd, sdata);
	if (!sdata)
		return (0);
	line = get_line(sdata);
	sdata = del_line(sdata);
	return (line);
}
