/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:53:57 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/18 14:40:13 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	dstsize;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(dstsize * sizeof(*str));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, dstsize);
	return (str);
}
