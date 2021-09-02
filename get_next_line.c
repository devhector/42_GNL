/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:08 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/02 17:34:57 by hectfern         ###   ########.fr       */
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
	char	*tmp2;
	char	buffer[BUFFER_SIZE + 1];

	tmp2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp2)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		*line = ft_strjoin(*line, buffer);
		if (!*line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ft_strchr(buffer, '\n'))
	{
		ft_strncpy(tmp2, *line, ft_strchr(*line, '\n') - *line);
		tmp2[ft_strchr(*line, '\n') - *line] = '\0';
		ft_strcpy(*line, ft_strchr(*line, '\n') + 1);
		return (tmp2);
	}
	free(tmp2);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	return (read_line(fd, &line));
}
