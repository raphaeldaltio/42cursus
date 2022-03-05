/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_newwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:21:42 by rdaltio-          #+#    #+#             */
/*   Updated: 2022/02/03 00:58:55 by rdaltio-         ###   ########.fr       */
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
	t_game game;
	
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 25*IMG, 10*IMG, "./so_long");
	mlx_hook(game.win_ptr, 17, 0L, game_close, &game);
	mlx_loop(game.mlx_ptr);
	return 0;
}