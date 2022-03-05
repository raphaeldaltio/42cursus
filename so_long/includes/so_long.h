/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:17:44 by rdaltio-          #+#    #+#             */
/*   Updated: 2022/02/27 23:55:14 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG 	32
# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_img
{ 
	int		x;
	int		y;	
	void	*img_ptr;
} 	t_img;

typedef struct	s_game
{ 
	void	*mlx_ptr;
	void	*win_ptr;	
	t_img	img;
	t_img	wall;
} 	t_game;


#endif
