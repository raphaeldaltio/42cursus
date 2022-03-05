/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:00:37 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/11/02 02:06:04 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	return (count);
}
