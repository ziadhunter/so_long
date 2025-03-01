#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIN_WIDTH 500
#define WIN_HEIGHT 500
#define PLAYER_SIZE 50
#define MOVE_SPEED 5

// Key codes for movement
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define ESC 65307

typedef struct s_game
{
    void *mlx;
    void *win;
    int player_x;
    int player_y;
    int key_states[256]; // Stores key states
} t_game;

// Function to draw the player (a square)
void draw_player(t_game *game)
{
    int i, j;

    mlx_clear_window(game->mlx, game->win);
    i = game->player_x;
    while (i < game->player_x + PLAYER_SIZE)
    {
        j = game->player_y;
        while (j < game->player_y + PLAYER_SIZE)
        {
            mlx_pixel_put(game->mlx, game->win, i, j, 0xFFFFFF); // White square
            j++;
        }
        i++;
    }
}

// Key press event handler
int key_press(int keycode, t_game *game)
{
    if (keycode == ESC)
        exit(0);
    if (keycode >= 0 && keycode < 256)
        game->key_states[keycode] = 1; // Mark key as pressed
    return (0);
}

// Key release event handler
int key_release(int keycode, t_game *game)
{
    if (keycode >= 0 && keycode < 256)
        game->key_states[keycode] = 0; // Mark key as released
    return (0);
}

// Move the player while keys are held down
int move_player(t_game *game)
{
    static int frame_count = 0;

    frame_count++;
    if (frame_count < 10000) // Adjust this value to control speed
        return (0);
    frame_count = 0;

    if (game->key_states[KEY_W] && game->player_y > 0)
        game->player_y -= MOVE_SPEED;
    if (game->key_states[KEY_A] && game->player_x > 0)
        game->player_x -= MOVE_SPEED;
    if (game->key_states[KEY_S] && game->player_y < WIN_HEIGHT - PLAYER_SIZE)
        game->player_y += MOVE_SPEED;
    if (game->key_states[KEY_D] && game->player_x < WIN_WIDTH - PLAYER_SIZE)
        game->player_x += MOVE_SPEED;

    draw_player(game);
    return (0);
}

// Main function
int main()
{
    t_game game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Moving Square");
    game.player_x = WIN_WIDTH / 2 - PLAYER_SIZE / 2;
    game.player_y = WIN_HEIGHT / 2 - PLAYER_SIZE / 2;

    // Initialize key states
    for (int i = 0; i < 256; i++)
        game.key_states[i] = 0;

    // Hook events
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 3, 1L << 1, key_release, &game);
    mlx_loop_hook(game.mlx, move_player, &game);

    mlx_loop(game.mlx);
    return (0);
}
