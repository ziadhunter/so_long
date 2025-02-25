#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
    void *mlx;
    void *win;
    int x;
    int y;
} t_game;

void draw_square(t_game *game)
{
    int i, j;
    int size = 50; // Square size

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            mlx_pixel_put(game->mlx, game->win, game->x + i, game->y + j, 0xFFFFFF);
        }
    }
}

int key_handler(e, t_game *game)
{
    printf("Key pressed: %d\n", keycode);
    // if (keycode == 65293) // ESC key
    //     exit(0);
    if (keycode == 97) // Left arrow
        game->x -= 10;
    if (keycode == 100) // Right arrow
        game->x += 10;
    if (keycode == 115) // Down arrow
        game->y += 10;
    if (keycode == 119) // Up arrow
        game->y -= 10;

    return (0);
}

int game_loop(t_game *game)
{
    mlx_clear_window(game->mlx, game->win); // Clear old position
    draw_square(game); // Redraw square
    return (0);
}

int main()
{
    t_game game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 800, 600, "Move Square");
    game.x = 375; // Initial position
    game.y = 275;

    draw_square(&game);

    mlx_key_hook(game.win, key_handler, &game); // Register key press hook
    mlx_loop_hook(game.mlx, game_loop, &game);  // Register game loop hook

    mlx_loop(game.mlx); // Starts event loop
    return (0);
}
