/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:35:40 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/19 23:55:02 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		len = 0;
		start = s_len;
	}
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
