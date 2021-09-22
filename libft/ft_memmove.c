/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:16:05 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/08 11:03:44 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					count;
	const unsigned char	*mem_src;
	unsigned char		*mem_dst;

	mem_dst = dst;
	mem_src = src;
	if (src < dst)
	{
		count = (int)len - 1;
		while (count >= 0)
		{
			mem_dst[count] = mem_src[count];
			count--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
