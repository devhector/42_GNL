/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:08 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/03 12:50:18 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*check_eof(int bytes_read, char *line)
{
	if (!bytes_read && line[bytes_read] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);

}

static char	*get_line(int fd, char *line, char **buffer)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int  	bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		if (ft_strchr(line, '\n'))
		{
			tmp = *buffer;
			*buffer = ft_strdup(ft_strchr(line, '\n') + 1);
			free(tmp);
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(*buffer));
			break ;
		}
	}
	return (check_eof(bytes_read, line));
}


char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	line = ft_strdup(buff);
	free(buff);
	buff = NULL;
	line = get_line(fd, line, &buff);
	return (line);
}
