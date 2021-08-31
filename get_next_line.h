/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:17 by hectfern          #+#    #+#             */
/*   Updated: 2021/08/31 20:34:32 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


size_t	ft_strlen(const char	*s);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t	size);

char	*get_next_line(int fd);
char	*ft_strchr(const char	*s, int	c);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*line_finder(char	**buf, char	**buffer, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s);
void	*ft_memcpy(void	*s1, const void	*s2, size_t	n);

void	*ft_calloc(size_t n, size_t size);

#endif