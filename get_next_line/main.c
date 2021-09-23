/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:12:49 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/09/07 18:57:46 by rdaltio-         ###   ########.fr       */
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

	while (count < 12)
	{
		printf("Reading Line %d: %s \n", count, line);

		count++;
		line = get_next_line(fd);
	}

}
