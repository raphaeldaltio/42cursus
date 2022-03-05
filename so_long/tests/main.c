#include <mlx.h>

typedef struct	s_data {
	void	*wall;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char	*relative_path = "../sprites/wall_left.xpm";
	int		wall_width;
	int		wall_height;
	int		count;
	t_data	wall;

	mlx = mlx_init();
	count = 0;
	mlx_win = mlx_new_window(mlx, 600, 300, "Hello world!");
	wall.wall = mlx_xpm_file_to_image(mlx, relative_path, &wall_width, &wall_height);
	wall.addr = mlx_get_data_addr(wall.wall, &wall.bits_per_pixel, &wall.line_length,
								&wall.endian);
	my_mlx_pixel_put(&wall, 5, 5, 0x00FF0000);
	while (count <= 600)
	{
		mlx_put_image_to_window(mlx, mlx_win, wall.wall, count, 0);
		mlx_put_image_to_window(mlx, mlx_win, wall.wall, 0, count);
		count += 32;
	}
	mlx_loop(mlx);
}
