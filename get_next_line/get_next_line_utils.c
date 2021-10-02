/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:12:49 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/10/01 19:36:17 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		count;

	count = ft_strlen(s1);
	pointer = malloc(sizeof(char) * (count + 1));
	if (!pointer)
		return (0);
	count = 0;
	while (s1[count])
	{
		pointer[count] = s1[count];
		count++;
	}
	pointer[count] = '\0';
	return (pointer);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	start;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	start = dest_len;
	count = 0;
	if (dest_len < (dstsize - 1) && dstsize > 0)
	{
		while (src[count] && (dest_len + count) < (dstsize - 1))
		{
			dst[start] = src[count];
			start++;
			count++;
		}
		dst[start] = 0;
	}
	if (dest_len >= dstsize)
		dest_len = dstsize;
	return (dest_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[count] && count < (dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
