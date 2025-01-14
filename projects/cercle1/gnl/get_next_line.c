/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:55:44 by salsoysa          #+#    #+#             */
/*   Updated: 2024/12/23 16:47:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*new_line(char *buffer_line)
{
	char	*crumbs;
	ssize_t	i;

	i = 0;
	while (buffer_line[i] && buffer_line[i] != '\n')
		i++;
	if (buffer_line[i] == 0 || buffer_line[1] == 0)
		return (0);
	crumbs = ft_substr(buffer_line, i + 1, ft_strlen(buffer_line) - i);
	if (!crumbs)
		return (NULL);
	if (!*crumbs)
	{
		free(crumbs);
		crumbs = NULL;
	}
	buffer_line[i + 1] = 0;
	return (crumbs);
}

char	*line_filler(int fd, char *crumbs, char *buffer)
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
	static char	*crumbs;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(crumbs);
		crumbs = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = line_filler(fd, crumbs, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	crumbs = new_line(line);
	return (line);
}
//
//#include <fcntl.h>
//
//int	main(void)
//{
	//int		fd;
	//char	*line;
	//int		i;
//
	//fd = open("test", O_RDONLY);
	//if (fd < 0)
		//return (1);
	//i = 1;
	//while (i)
	//{
		//line = get_next_line(fd);
		//if (!line)
		//{
			//i = 0;
			//printf("NO MORE RESULT\n");
			//free(line);
			//break ;
		//}
		//printf("Line:%s", line);
		//free(line);
	//}
	//close(fd);
	//return (0);
//}
