/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:13:39 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/17 22:59:47 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pointer;
	size_t			count;

	pointer = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (pointer[count] == (unsigned char)c)
			return (&pointer[count]);
		count++;
	}
	return (0);
}
