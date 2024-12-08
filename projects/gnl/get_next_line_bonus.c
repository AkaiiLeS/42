/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:26:23 by salsoysa          #+#    #+#             */
/*   Updated: 2024/12/06 18:51:03 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*new_line(char *buffer_line)
{
	char	*crumbs;
	ssize_t	i;

	i = 0;
	while (buffer_line[i] && buffer_line[i] != '\n')
		i++;
	if (buffer_line[i] == 0)
		return (0);
	crumbs = ft_substr(buffer_line, i + 1, ft_strlen(buffer_line) - i);
	if (*crumbs == 0)
	{
		free(crumbs);
		crumbs = NULL;
	}
	buffer_line[i + 1] = 0;
	return (crumbs);
}

static char	*line_filler(int fd, char *crumbs, char *buffer)
{
	char	*line;
	ssize_t	buffer_index;

	buffer_index = 1;
	while (buffer_index > 0)
	{
		buffer_index = read(fd, buffer, BUFFER_SIZE);
		if (buffer_index == -1)
		{
			free(crumbs);
			return (0);
		}
		else if (buffer_index == 0)
			break ;
		buffer[buffer_index] = 0;
		if (!crumbs)
			crumbs = ft_strdup("");
		line = crumbs;
		crumbs = ft_strjoin(line, buffer);
		free(line);
		line = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (crumbs);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*crumbs[MAX_FD];

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(crumbs[fd]);
		crumbs[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = line_filler(fd, crumbs[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	crumbs[fd] = new_line(line);
	return (line);
}
