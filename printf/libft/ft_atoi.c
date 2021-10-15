/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:30:36 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/17 16:03:46 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	valid_n;

	sign = 1;
	valid_n = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		valid_n = valid_n * 10 + (*str - '0');
		str++;
		if (valid_n > 2147483647 && sign == 1)
			return (-1);
		if (valid_n > 2147483648 && sign == -1)
			return (0);
	}
	return ((int)valid_n * sign);
}
