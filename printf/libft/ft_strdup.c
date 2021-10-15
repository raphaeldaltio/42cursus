/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:02:52 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/17 10:25:23 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		count;

	count = ft_strlen(s1);
	pointer = malloc(sizeof(char) * (count + 1));
	if (!pointer)
		return (0);
	count = 0;
	while (s1[count])
	{
		pointer[count] = s1[count];
		count++;
	}
	pointer[count] = '\0';
	return (pointer);
}
