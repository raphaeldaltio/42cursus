/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 03:38:17 by rdaltio-          #+#    #+#             */
/*   Updated: 2022/02/27 00:16:39 by rdaltio-         ###   ########.fr       */
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

int	key_input(int key, t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (key == LEFT)
		x -= 32;
	else if (key == RIGHT)
		x += 32;

	//Destroy imagem atual
	mlx_clear_window(game->mlx_ptr, game->win_ptr);

	//Renderiza mapa novamente
	while (y < 10)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, (32 * x), 0);
		y++;
	}
	//Printa player na nova posição
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, x, 0);
}

int	key_press(int key, t_game *game)
{
	if(key == UP)
	{
		printf("press\n");
	}
	return 0;
}

int main(void)
{
	t_game game;
	
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 25*IMG, 10*IMG, "./so_long");
	game.img.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr,
			"sprites/player_1.xpm", &game.img.x, &game.img.y);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 10, 10);
	mlx_hook(game.win_ptr, 3, 1L<<1, key_input, &game);
	mlx_hook(game.win_ptr, 17, 0L, game_close, &game);
	mlx_loop(game.mlx_ptr);
	return 0;
}