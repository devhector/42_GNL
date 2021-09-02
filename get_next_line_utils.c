/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:34:02 by hectfern          #+#    #+#             */
/*   Updated: 2021/08/31 20:33:45 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char	*s, int	c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	char	*aux;
	size_t	numb;

	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	ptr = malloc(n * size);
	if (ptr)
	{
		numb = size * n;
		aux = (char *)ptr;
		while (numb--)
			*aux++ = '\0';
	}
	return (ptr);
}

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		str_len;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str_len = 0;
	while (str_len < s1_len)
	{
		str[str_len] = s1[str_len];
		str_len++;
	}
	while (str_len < s1_len + s2_len)
	{
		str[str_len] = s2[str_len - s1_len];
		str_len++;
	}
	str[str_len] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*cp_str;

	size = (ft_strlen(s) + 1);
	cp_str = (char *)malloc(size * sizeof(char));
	if (!cp_str)
		return (NULL);
	ft_memcpy(cp_str, s, size);
	return (cp_str);
}

void	*ft_memcpy(void	*s1, const void	*s2, size_t	n)
{
	char		*dst;
	const char	*src;

	if (s1 == s2)
		return (s1);
	dst = (char *)s1;
	src = (const char *)s2;
	while (n--)
	{
		*dst++ = *src++;
	}
	return (s1);
}