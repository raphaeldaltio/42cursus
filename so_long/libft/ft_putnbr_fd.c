/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:31:42 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/16 17:02:49 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		if (n > 0 && n < 10)
			ft_putchar_fd(n + 48, fd);
		else if (n > 0)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + 48, fd);
		}
	}
}
