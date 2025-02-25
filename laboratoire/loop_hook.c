#include <mlx.h>
#include <stdio.h>

int game_loop(void *param)
{
    (void)param; // Avoid unused parameter warning
    if ()
    printf("Game is running...\n");
    return (0);
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "mlx_loop_hook Example");

    // Register game loop function
    mlx_loop_hook(mlx, game_loop, NULL);

    mlx_loop(mlx);
    return (0);
}
