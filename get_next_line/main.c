/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:12:49 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/09/28 19:43:34 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		count;
	char	*line;
	int		fd;

	count = 1;
	fd = open("wtf.txt", O_RDONLY);
	line = get_next_line(fd);
	while (1)
	{
		printf("Reading Line %d: %s", count, line);
		count++;
		line = get_next_line(fd);
		if (line == '\0')
		{
			printf("Reading Line %d: %s", count, line);
			break ;
		}
	}
	free (line);
	close(fd);
}

// #include <fcntl.h>
// #include "get_next_line.h"
// #include	<stdio.h>

// int main (void)
// {
//     int fd = open("text.txt", O_RDONLY);
// 	int count = 0;
//     char *line;

// 	while (count < 10)
// 	{
// 		line = get_next_line(fd);
// 		printf("bytes: %s\n", line);
// 		count++;
// 	}
//     close(fd);
// 	return (0);
// }
