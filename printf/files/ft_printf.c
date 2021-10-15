/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:08:47 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/10/15 02:48:06 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include "../libft/libft.h" // remover no final

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		size;
	char	*temp;

	va_start(args, format);
	len = 0;
	size = 0;
	while (format[len])
	{
		if (format[len] == '%' && ft_strchr("cspduixX%", format[len + 1]))
		{
			//size += função que vai tratar todas as conversões, return int
			if(format[len + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, char), 1);
				size++;
			}
			if(format[len + 1] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if(ft_strchr("di", format[len + 1]))
				ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
			if(format[len + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				size++;
			}
			if(format[len + 1] == 'p')
			{
				temp = ft_strdup(va_arg(args, char));
				size = ft_strlen(temp);
			}
			len++;
		}
		else
		{
			ft_putchar_fd(format[len], 1);
			size++;
		}
		len++;
	}
	va_end(args);
	return (size);
}
