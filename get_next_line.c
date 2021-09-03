/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:08 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/03 14:02:05 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_eof(int bytes_read, char *line)
{
	if (!bytes_read && line[bytes_read] == '\0')
	{
		free(line);
		return (NULL);
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
			tmp = line;
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(*buffer));
			free(tmp);
			break ;
		}
	}
	return (check_eof(bytes_read, line));
}


char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!backup)
		backup = ft_strdup("");
	line = ft_strdup(backup);
	free(backup);
	backup = NULL;
	line = get_line(fd, line, &backup);
	return (line);
}
