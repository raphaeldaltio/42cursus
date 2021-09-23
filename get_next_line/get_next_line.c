/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:48:22 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/09/21 21:19:59 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_count_to_end(char *line)
{
	int	count;

	count = 0;
	while (line[count] != '\n')
		count++;
	return (count);
}

static char	*ft_check_leak(char *leak, char *line)
{
	int	start;

	start = ft_count_to_end(line);
	if (start == 0)
		start = 1;
	else
		start = ft_count_to_end(line) + 1;
	leak = ft_strdup(&line[start]);
	return (leak);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*leak;
	size_t		bytes_to_read;
	size_t		count;
	size_t		start;

	bytes_to_read = 1;
	count = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*line));
	while (bytes_to_read)
	{
		bytes_to_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_to_read] = '\0';
		if (!ft_strchr(buffer, '\n'))
		{
			if (leak)
			{
				line = ft_strdup(leak);
				free(leak);
			}
			line = ft_strjoin(line, buffer);
		}
		else
		{
			bytes_to_read = ft_count_to_end(buffer);
				if (leak)
			{
				line = ft_strdup(leak);
				free(leak);
			}
			start = ft_strlen(line);
			leak = ft_check_leak(leak, buffer);
			while (bytes_to_read)
			{
				line[start] = buffer[count];
				start++;
				count++;
				bytes_to_read--;
			}
			break;
		}
	}
	// printf("Leak: %s \n", leak);
	return (line);
}
