/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:08 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/03 10:04:04 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Function: get_next_line
Description: Reads a line from a file descriptor.
Parameters:
	fd: The file descriptor.
Return:
	The line read from the file descriptor.
*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count < n && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	while (count < n)
	{
		dest[count] = '\0';
		count++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_line(int	fd, char	**line)
{
	char	*tmp;
	char	*tmp2;
	char	buffer[BUFFER_SIZE + 1];

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer[BUFFER_SIZE] = '\0';
		tmp2 = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp2);
		if (!*line)
			return (NULL);
	}
	if (read(fd, buffer, 1) < 0)
	{
		free(tmp);
		return (NULL);
	}
	if (ft_strchr(buffer, '\n'))
	{
		ft_strncpy(tmp, *line, ft_strchr(*line, '\n') - *line);
		tmp[ft_strchr(*line, '\n') - *line] = '\0';
		ft_strcpy(*line, ft_strchr(*line, '\n') + 1);
		return (tmp);
	}
	if(!ft_strchr(*line, '\n'))
	{
		free(tmp);
		return (NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	if (read_line(fd, &line))
		return (read_line(fd, &line));
	else
	{
		if(*line)
		{
			free(line);
			line = NULL;
		}
		return (NULL);
	}
}
