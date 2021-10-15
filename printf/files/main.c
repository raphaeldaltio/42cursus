/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:12:02 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/10/15 02:48:47 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// int	main(void)
// {
// 	printf("   %d\n", printf("   printf - %c lalalala %s oi %d sim %i %%\n", 'a', "string", 123, 99999999));
// 	ft_printf("   %d\n", ft_printf("ft_printf - %c lalalala %s oi %d sim %i %%\n", 'a', "string", 123, 99999999));
// }


int main( void )
{
int *ptr; /* declara ponteiro para int */
int x = 12345; /* inicializa int x */
int y = 0; /* declara int y */

ptr = &x; /* atribui endereço de x a ptr */
printf( "O valor de ptr é %p\n", ptr );
printf( "O endereço de x é %p\n\n", &x );

printf("%d\n\n", y );

y = printf("Essa linha tem 29 caracteres\n");
printf( "%d caracteres foram impressos\n\n", y );

printf( "Imprimindo um %% em uma string de controle de formato\n" );
return 0;
}
