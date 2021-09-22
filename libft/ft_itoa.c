/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:53:13 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/16 23:52:52 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		count = 1;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	char		c_nb;
	size_t		count;
	long int	nb;

	nb = n;
	str = ft_calloc(ft_count(nb) + 1, sizeof(*str));
	count = ft_count(nb) - 1;
	if (!str)
		return (0);
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		c_nb = nb % 10 + 48;
		str[count] = c_nb;
		nb = nb / 10;
		count--;
	}
	return (str);
}
