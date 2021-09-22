/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:03:22 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/17 11:25:59 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
		return (0);
	count = 0;
	while (s1[count] && s2[count] && s1[count] == s2[count] && count < n - 1)
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
