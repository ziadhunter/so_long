#include <mlx.h>
#include <stdlib.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     size_line;
    int     endian;
} t_data;

void put_pixel(t_data *data, int x, int y, int color)
{
    int pixel_index;

    pixel_index = (y * data->size_line) + (x * (data->bpp / 8));
    *(unsigned int *)(data->addr + pixel_index) = color;
}

void draw_rectangle(t_data *data, int x, int y, int width, int height, int color)
{
    int i, j;

    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            put_pixel(data, x + i, y + j, color);
        }
    }
}

int main()
{
    t_data  data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 500, 500, "Rectangle");
    data.img = mlx_new_image(data.mlx, 500, 500);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.size_line, &data.endian);

    // Draw a red rectangle at (50,50) with width 100 and height 50
    draw_rectangle(&data, 50, 50, 100, 50, 0x00FF0000);

    // Display the image in the window
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    mlx_loop(data.mlx);
    return (0);
}
