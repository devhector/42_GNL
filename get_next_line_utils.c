/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:02 by hectfern          #+#    #+#             */
/*   Updated: 2021/09/03 20:29:30 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*cp_str;

	size = (ft_strlen(s) + 1);
	cp_str = (char *)malloc(size * sizeof(char));
	if (!cp_str)
		return (NULL);
	ft_strlcpy(cp_str, s, size);
	return (cp_str);
}


char	*ft_strjoin(char	*s1, char const	*s2)
{
	char	*join;
	size_t	i;
	size_t	r;
	size_t	tl;

	tl = ft_strlen(s1) + ft_strlen(s2);
	if (tl < 1)
		return (0);
	join = (char *)malloc((tl + 1) * sizeof(char));
	if (!join)
		return (0);
	i = 0;
	r = 0;
	if (s1)
	{
		while ((i < tl) && s1[i])
			join[i++] = s1[r++];
	}
	r = 0;
	while ((i < tl) && s2[r])
		join[i++] = s2[r++];
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_substr(char	*s, unsigned int	start, size_t	len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	else if (start + len > s_len)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (i < (size - 1) && i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
