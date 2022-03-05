/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 03:38:17 by rdaltio-          #+#    #+#             */
/*   Updated: 2022/03/02 02:09:56 by rdaltio-         ###   ########.fr       */
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
	static int x;
	static int y;

	if (!x)
		x = 32;
	if (!y)
		y = 32;
	if (key == LEFT && x > 32)
		x -= 32;
	if (key == RIGHT && x < 23*IMG)
		x += 32;
	if (key == UP && y > 32)
		y -= 32;
	if (key == DOWN && y < 8*IMG)
		y += 32;

	//Destroy imagem atual
	//mlx_clear_window(game->mlx_ptr, game->win_ptr);

	//Renderiza mapa novamente
	//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, x, y);
	//Printa player na nova posição
	//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img_ptr, x, y);
	return (0);
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
	int		count;
	t_game 	game;
	
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 25*IMG, 10*IMG, "./so_long");
	game.img.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr,
			"sprites/wall_left.xpm", &game.img.x, &game.img.y);
	count = 0;
	while (count < 10*IMG)
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 0, count);
		count += 32;
	}
	game.img.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr,
			"sprites/wall_right.xpm", &game.img.x, &game.img.y);
	count = 0;
	while (count < 10*IMG)
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 24*IMG, count);
		count += 32;
	}
	game.img.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr,
			"sprites/wall_top.xpm", &game.img.x, &game.img.y);
	count = 32;
	while (count < 24*IMG)
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, count, 0);
		count += 32;
	}
	game.img.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr,
			"sprites/wall_bottom.xpm", &game.img.x, &game.img.y);
	count = 32;
	while (count < 24*IMG)
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, count, 9*IMG);
		count += 32;
	}
	game.img.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr,
			"sprites/player_1.xpm", &game.img.x, &game.img.y);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img_ptr, 32, 32);
	mlx_hook(game.win_ptr, 3, 1L<<1, key_input, &game);
	mlx_hook(game.win_ptr, 17, 0L, game_close, &game);
	mlx_loop(game.mlx_ptr);
	return 0;
}