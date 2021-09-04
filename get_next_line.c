/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:08 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/03 21:02:10 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char	*s, int	c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if ((char)c == '\0')
		return (str + i);
	return (0);
}

char	*remove_line_read(char *backup)
{
	char	*tmp;

	tmp = backup;
	backup = ft_strdup(ft_strchr(backup, '\n') + 1);
	free(tmp);
	if(*backup == '\0')
	{
		free(backup);
		return (NULL);
	}
	return (backup);
}

int	check_bytes_read(int bytes_read, char *buffer)
{
	if (bytes_read == -1)
	{
		free(buffer);
		return (1);
	}
	return (0);
}

char	*get_next_line(int	fd)
{
	char	*line;
	char	*buffer;
	static char	*backup;
	int	bytes_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (check_bytes_read(bytes_read, buffer))
			return (NULL);
		if (!bytes_read)
			break ;
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	if(!backup)
		return (NULL);
	line = ft_substr(backup, 0, ft_strchr(backup, '\n') - backup + 1);
	backup = remove_line_read(backup);
	return (line);
}
