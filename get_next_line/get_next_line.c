/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:12:49 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/10/01 22:07:31 by rdaltio-         ###   ########.fr       */
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
	s = NULL;
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
	s1 = NULL;
	return (str);
}

char	*ft_is_end_file(ssize_t	bytes_to_read, char *line)
{
	if (!bytes_to_read && line[bytes_to_read] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*ft_reading(int fd, char *line, char **leak)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_to_read;

	bytes_to_read = 1;
	while (bytes_to_read)
	{
		bytes_to_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_to_read < 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		buffer[bytes_to_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			*leak = ft_strdup(ft_strchr(line, '\n') + 1);
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(*leak));
			break ;
		}
	}
	return (ft_is_end_file(bytes_to_read, line));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leak;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	if (!leak)
		leak = ft_strdup("");
	line = ft_strdup(leak);
	free(leak);
	leak = NULL;
	line = ft_reading(fd, line, &leak);
	return (line);
}
