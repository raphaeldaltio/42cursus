/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:48:22 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/09/28 19:46:01 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char *s, unsigned int start, size_t len)
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
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	free(s);
	return (str);
}

static char	*ft_strjoin(char *s1, char const *s2)
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
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*leak;
	size_t		bytes_to_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(buffer));
	if (!buffer)
		return (NULL);
	if (!leak)
		leak = ft_strdup("");
	line = ft_strdup(leak);
	free(leak);
	bytes_to_read = 1;
	while (bytes_to_read)
	{
		bytes_to_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_to_read] = '\0';
		if (bytes_to_read < 0)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line = ft_strjoin(line, buffer);
		free(buffer);
		if (ft_strchr(line, '\n'))
		{
			leak = ft_strdup(ft_strchr(line, '\n') + 1);
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(leak));
			break ;
		}
	}
	if (!bytes_to_read && line[bytes_to_read] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
