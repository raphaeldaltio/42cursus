/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:54:06 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/08 15:52:36 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				count;
	const unsigned char	*mem_src;
	unsigned char		*mem_dest;

	count = 0;
	mem_dest = dst;
	mem_src = src;
	if (!mem_dest && !mem_src)
		return (0);
	while (count < n)
	{
		mem_dest[count] = mem_src[count];
		count++;
	}
	return (dst);
}
