/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:08:21 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/18 14:44:59 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_1;
	unsigned char	*str_2;
	size_t			count;

	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	count = 0;
	if (!s1 && !s2)
		return (0);
	while (count < n)
	{
		if (str_1[count] != str_2[count])
			return (str_1[count] - str_2[count]);
		count++;
	}
	return (0);
}
