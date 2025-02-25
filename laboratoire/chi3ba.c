#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int key_handler(int keycode, void *param)
{
    (void)param; // Avoids unused parameter warning

    printf("Key pressed: %d\n", keycode);
    if (keycode == 65307) // 53 is the ESC key on macOS
    {
        printf("ESC pressed, exiting program...\n");
        exit(0);
    }
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "mlx_key_hook Example");

    // Register key press handler
    mlx_key_hook(win, key_handler, NULL);

    mlx_loop(mlx);
    return (0);
}
