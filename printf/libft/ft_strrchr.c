/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:30:43 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/19 12:08:17 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = c;
	len = ft_strlen(s);
	while (len > 0 && str[len] != ch)
		len--;
	if (str[len] == ch)
		return (&str[len]);
	return (0);
}
