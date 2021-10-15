/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:44:31 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/17 10:26:58 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	count;

	if (!s)
		return (0);
	str = ft_strdup(s);
	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		str[count] = f(count, str[count]);
		count++;
	}
	return (str);
}
