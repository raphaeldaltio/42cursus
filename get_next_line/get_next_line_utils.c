/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:48:20 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/09/21 20:05:56 by rdaltio-         ###   ########.fr       */
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
	while (s1[count] && s1[count] != '\n')
	{
		pointer[count] = s1[count];
		count++;
	}
	pointer[count] = '\0';
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	dstsize;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(dstsize * sizeof(*str));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, dstsize);
	return (str);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		len = 0;
		start = s_len;
	}
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	total;

	total = count * size;
	pointer = malloc(total);
	if (!pointer)
		return (0);
	ft_bzero(pointer, total);
	return (pointer);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*memory;
	size_t			count;

	memory = s;
	count = 0;
	while (count < n)
	{
		memory[count] = '\0';
		count++;
	}
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	valid_n;

	sign = 1;
	valid_n = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		valid_n = valid_n * 10 + (*str - '0');
		str++;
		if (valid_n > 2147483647 && sign == 1)
			return (-1);
		if (valid_n > 2147483648 && sign == -1)
			return (0);
	}
	return ((int)valid_n * sign);
}
