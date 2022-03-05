/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:11:46 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/19 21:07:13 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
