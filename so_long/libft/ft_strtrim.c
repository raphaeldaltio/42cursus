/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:38:24 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/16 17:04:56 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_check(char check, char const *set)
{
	size_t	count;

	count = 0;
	while (set[count] != '\0')
	{
		if (set[count] == check)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	count;
	size_t	first_s;
	size_t	last_s;

	first_s = 0;
	if (!s1)
		return (0);
	last_s = ft_strlen(s1);
	count = 0;
	while (s1[first_s] && ft_char_check(s1[first_s], set) != 0)
		first_s++;
	while (last_s > first_s && ft_char_check(s1[last_s - 1], set) != 0)
		last_s--;
	str = malloc((last_s - first_s + 1) * sizeof(*s1));
	if (!str)
		return (0);
	while (first_s < last_s)
	{
		str[count] = s1[first_s];
		count++;
		first_s++;
	}
	str[count] = 0;
	return (str);
}
