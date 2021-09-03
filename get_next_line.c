/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:08 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/03 14:30:12 by hectfern         ###   ########.fr       */
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

static char	*format_line(char *line, char **backup)
{
	char	*tmp;

	tmp = *backup;
	*backup = ft_strdup(ft_strchr(line, '\n') + 1);
	if (!*backup)
		return (NULL);
	free(tmp);
	tmp = line;
	line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(*backup));
	if (!line)
		return (NULL);
	free(tmp);
	return (line);
}

static char	*get_line(int fd, char *line, char **backup)
{
	char	*tmp;
	char	*buf;
	int		bytes_read;

	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
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
		free(buf);
		if (ft_strchr(line, '\n'))
			return (format_line(line, backup));
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
