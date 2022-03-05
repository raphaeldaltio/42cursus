/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:21:42 by rdaltio-          #+#    #+#             */
/*   Updated: 2022/02/03 03:11:09 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_close(t_game *game)
{
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(EXIT_SUCCESS);
	return 0;
}

int main(void)
{
	t_game	game;
	int		logo;
	
	logo = 15;
	game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, 20*IMG, 10*IMG, "Pixel");
	while (logo < 150)
	{
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 15, logo, 0x26FFFF);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 16, logo, 0x26FFFF);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 17, logo, 0x000000);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 18, logo, 0x000000);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 19, logo, 0xFED327);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 20, logo, 0xFED327);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 21, logo, 0x000000);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 22, logo, 0x000000);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 23, logo, 0xFF26EA);
		mlx_pixel_put(game.mlx_ptr, game.win_ptr, 24, logo, 0xFF26EA);
		logo++;
	}	
	mlx_hook(game.win_ptr, 17, 0L, game_close, &game);
    mlx_loop(game.mlx_ptr);
	return 0;
}