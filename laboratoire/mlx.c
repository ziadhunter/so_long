#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int	mlx_get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_image_to_image(t_data *dest, t_data *src, int dest_x, int dest_y, int src_x, int src_y)
{
	int				y;
	int				x;
	int				i;
	int				j;
	unsigned int	color;

	y = src_y;
	j = 0;
	while (y < 64 + src_y)
	{
		x = src_x;
		i = 0;
		while (x < 64 + src_x)
		{
			color = mlx_get_pixel(src, x, y);
			if (color != 0xFF000000)
				my_mlx_pixel_put(dest, dest_x + i, dest_y + j, color);
			x++;
			i++;
		}
		j++;
		y++;
	}
}

int	game_loop(int l)
{
	t_data	img;
	t_data	wall;
	t_data	pl;
	t_data	lo7a;
	void	*mlx;
	void	*mlx_win;

	static int c = 0;
	if (c == 5)
		c = 0;
	int i , j;
	i =0;j=0;
    int xc = 5000, yc = 5000;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 64 * 9, 64 * 8, "Hello world!");
	lo7a.img = mlx_new_image(mlx, 64 * 9, 64 * 8);
	lo7a.addr = mlx_get_data_addr(lo7a.img, &lo7a.bits_per_pixel, &lo7a.line_length, &lo7a.endian);
	img.img = mlx_xpm_file_to_image(mlx, "./pictures/background_pictures/.xpm", &xc, &yc);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	wall.img = mlx_xpm_file_to_image(mlx, "./pictures/wall_pictures/wall.xpm", &xc, &yc);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length,&wall.endian);
	pl.img = mlx_xpm_file_to_image(mlx,"./pictures/player_movement/idle.xpm", &xc, &yc);
	pl.addr = mlx_get_data_addr(pl.img, &pl.bits_per_pixel, &pl.line_length,&pl.endian);

	while (i  <  9)
	{
		j = 0;
		while (j < 8)
		{
			put_image_to_image(&lo7a, &img, i * 64, j * 64, 0, 0);
			j++;
		}
		i++;
	}
	char *map[]={ "111111111",
				  "100000001",
				  "100010001",
				  "110010011",
				  "101010011",
				  "100010001",
				  "10P010001",
				  "111111111"};
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(map[i][j] == '1')
				put_image_to_image(&lo7a, &wall, j * 64, i * 64, 0, 0);
			else if(map[i][j] == 'P')
				put_image_to_image(&lo7a, &pl, j * 64, i * 64, c * 64, 0);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, lo7a.img, 0, 0);
	c++;
	return (0);
}

int	main(void)
{
	t_data	img;
	t_data	wall;
	t_data	pl;
	t_data	lo7a;
	void	*mlx;
	void	*mlx_win;

	int i , j;
	i =0;j=0;
    int xc = 5000, yc = 5000;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 64 * 9, 64 * 8, "Hello world!");
	lo7a.img = mlx_new_image(mlx, 64 * 9, 64 * 8);
	lo7a.addr = mlx_get_data_addr(lo7a.img, &lo7a.bits_per_pixel, &lo7a.line_length, &lo7a.endian);
	img.img = mlx_xpm_file_to_image(mlx,  "./pictures/background_pictures/.xpm", &xc, &yc);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	wall.img = mlx_xpm_file_to_image(mlx,  "./pictures/wall_pictures/wall.xpm", &xc, &yc);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length,&wall.endian);
	pl.img = mlx_xpm_file_to_image(mlx, "./pictures/player_movement/idle.xpm", &xc, &yc);
	pl.addr = mlx_get_data_addr(pl.img, &pl.bits_per_pixel, &pl.line_length,&pl.endian);
	
	//my_mlx_pixel_put(&img, 5, 5, 0x90f542);
	mlx_loop_hook(mlx, game_loop, 0);
	mlx_loop(mlx);
}
