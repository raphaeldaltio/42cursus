/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:42:00 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/17 10:23:55 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*memory;
	unsigned char	value;
	unsigned int	count;

	memory = b;
	value = c;
	count = 0;
	while (count < len)
	{
		memory[count] = value;
		count++;
	}
	return (memory);
}
