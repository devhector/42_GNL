/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:08 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/05 14:51:44 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char	*backup);
static char	*remove_read_line(char *backup);
static char	*read_file(int fd, char *backup);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	backup = read_file(fd, backup);
	if (!backup)
		return (NULL);
	line = get_line(backup);
	backup = remove_read_line(backup);
	return (line);
}

static char	*read_file(int fd, char *backup)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(backup, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			break ;
		buffer[read_bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	if (read_bytes < 0)
		return (NULL);
	else
		return (backup);
}

static char	*get_line(char	*backup)
{
	char	*line;
	size_t	size;

	if (!*backup)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, size + 1);
	if (backup[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char	*remove_read_line(char *backup)
{
	int		i;
	int		j;
	char	*new_backup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	new_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!new_backup)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
}
